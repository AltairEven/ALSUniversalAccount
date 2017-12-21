/*
 * WVBridgeProtocol.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <UIKit/UIKit.h>

/**
 * WVBridge 提供了 WebView/Weex/Native 通用的 Bridge 协议。
 * 具体的教程可以参考 WindVane 的版本正式文档 http://h5.alibaba-inc.com/windvane/JSBridge.html，此处作为快捷上手帮助。
 *
 * 提供动态 WVBridge（对类名有要求，但无需注册，会自动反射查找）：
 * [STEP 1] 令你要输出为服务的类实现 WVBridgeProtocol（引入头文件 <WindVane/WVBridgeProtocol.h>）。
 * [STEP 2] [可选]根据需要重写 instanceScope 方法，设置实例的作用域，具体的定义参见 WVBridgeScope 枚举。
 * [STEP 3] 你要输出的方法的命名需要遵循规范：
 *            -/+ (void)handlerName:(NSDictionary *)params withWVBridgeContext:(id<WVBridgeCallbackContext>)context
 *            其中 handlerName 即为你提供给 WVBridge 调用方的方法名称。
 *          · 第一个参数为 NSDictionary *，是 WVBridge 调用方传入的参数对象。
 *          · 第二个参数为 id<WVBridgeCallbackContext>，是 WVBridge 的调用上下文。
 * [STEP 4] 在你的方法中，使用 [context callbackSuccess:RESULT]/[context callbackFailure:RET withResult:RESULT] 
 *          来输出执行成功/失败的结果返回给 WVBridge 调用方。
 * [STEP 5] 当你的 WVBridge API 逻辑执行完毕，可以主动调用 [context releaseHandler:self] 方法来主动释放内存，否则就只能等到页面销毁的时候才会释放。
 *          注意在 dealloc 中调用 [context releaseHandler:self] 是没有意义的，因此此时对象已经被释放了。
 *
 * 提供普通 WVBridge（需要注册才能够使用）：
 * · 使用 WVRegisterBridge 宏注册全局 WVBridge 处理器；
 * · 使用 WVRegisterBridgeAlias 宏注册全局 WVBridge 别名；
 * · 使用 WVRegisterBridgeClass 宏注册全局 WVBridge 类；
 *
 * [注意] 1. WVBridge 总是在主线程调用，如果有耗时操作，请务必自行切换线程。
 *       2. 可能你提供的服务带有多个阶段输出性，请使用 [context dispatchEvent:eventName withParam:param] 将结果通过事件的方式输出给 WVBridge 调用方。
 */

/**
 * WVBridge 发送事件的回调，用于了解事件的默认行为是否被阻止。
 *
 * @param eventName      发送的事件名称。
 * @param preventDefault 事件的默认行为是否被阻止。
 */
typedef void (^WVEventCallback)(NSString * _Nonnull eventName, BOOL preventDefault);

#pragma mark - WVBridge Context

@protocol WVWebViewBasicProtocol;
@class WXSDKInstance;

/**
 * 动态 WVBridge API 上下文的 Protocol。
 * 所有方法都是线程安全的。
 */
@protocol WVBridgeContext <NSObject>

@required

#pragma mark Environment

/**
 * 当前 WVBridge API 的来源 URL。
 */
@property (nonatomic, strong, readonly, nullable) NSURL * referrer;

/**
 * 当前 WVBridge API 绑定到的 UIView。
 */
@property (nonatomic, weak, readonly, nullable) UIView * view;

/**
 * 当前 WVBridge API 绑定到的 UIViewController。
 */
@property (nonatomic, weak, readonly, nullable) UIViewController * viewController;

/**
 * 当前 WVBridge API 绑定到的环境，不同环境下会返回不同的值。
 * WebView 环境下为 UIView<WVWebViewBasicProtocol> *；Weex 环境下为 WXSDKInstance。
 */
@property (nonatomic, weak, readonly, nullable) id env;

/**
 * 当前 WVBridge API 绑定到的 WebView 环境，如果不是 WebView 环境则为 nil。
 */
@property (nonatomic, weak, readonly, nullable) UIView<WVWebViewBasicProtocol> * webViewEnv;

/**
 * 当前 WVBridge API 绑定到的 Weex 环境，如果不是 Weex 环境则为 nil。
 */
@property (nonatomic, weak, readonly, nullable) WXSDKInstance * weexEnv;

#pragma mark Event

/**
 * 通过事件的方式通知所属 WVBridge 调用方，调用方可能不支持此功能。
 *
 * @param eventName 要发送的事件名称。
 * @param param     要发送的事件参数。
 *
 * @return 事件是否发送成功。
 */
- (BOOL)dispatchEvent:(NSString * _Nonnull)eventName withParam:(NSDictionary * _Nullable)param;

/**
 * 通过事件的方式通知所属 WVBridge 调用方，调用方可能不支持此功能。
 *
 * @param eventName 要发送的事件名称。
 * @param param     要发送的事件参数。
 * @param callback  要获取事件是否被取消默认行为的回调。仅当事件被成功发送才会调用。
 *
 * @return 事件是否发送成功。
 */
- (BOOL)dispatchEvent:(NSString * _Nonnull)eventName withParam:(NSDictionary * _Nullable)param withCallback:(WVEventCallback _Nullable)callback;

#pragma mark Function

/**
 * 添加尾部调用，会在页面切换或关闭时自动执行。
 *
 * @param name   要在页面切换或关闭时执行的 WVBridge 名称。
 * @param params 要执行的 WVBridge 参数。
 *
 * @return 添加尾调用的错误信息。
 */
- (NSError * _Nullable)addTailInvocation:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params;

/**
 * 移除动态 WVBridge API 的实例，仅在动态 WVBridge 将要销毁当前实例时使用。
 */
- (void)releaseHandler:(id _Nonnull)instance;

@end

#pragma mark - WVBridge Callback Context

// clang-format off

/**
 * WVBridge API 执行结果的回调。
 *
 * @param ret    执行结果。
 * @param result 执行结果的数据。
 */
typedef void (^WVBridgeCallback)(NSString * _Nonnull ret, NSDictionary * _Nullable result);

/**
 * 表示 WVBridge API 执行成功（不允许设置为失败回调的返回值）。
 */
#define MSG_RET_SUCCESS       @"HY_SUCCESS"

/**
 * 表示 WVBridge API 传入参数错误。
 */
#define MSG_RET_PARAM_ERR     @"HY_PARAM_ERR"

/**
 * 表示 WVBridge API 执行失败。
 */
#define MSG_RET_FAILED        @"HY_FAILED"

/**
 * 表示 WVBridge API 执行出现异常。
 */
#define MSG_RET_EXCEPTION     @"HY_EXCEPTION"

/**
 * 表示 WVBridge API 功能不被支持。
 */
#define MSG_RET_NOT_SUPPORTED @"HY_NOT_SUPPORTED"

/**
 * 表示 WVBridge API 缺少用户权限。
 */
#define MSG_RET_USER_DENIED   @"HY_USER_DENIED"

/**
 * 表示 WVBridge API 的执行被用户取消。
 */
#define MSG_RET_USER_CANCELED @"HY_USER_CANCELLED"

#pragma mark WVBridge Result Key Constants

/**
 * 标准返回数据：状态码。
 */
#define MSG_RESULT_CODE_NAME @"ret"

/**
 * 标准返回数据：消息。
 */
#define MSG_RESULT_MSG_NAME  @"msg"

/**
 * 动态 WVBridge API 回调上下文的 Protocol。
 * 所有方法都是线程安全的。
 */
@protocol WVBridgeCallbackContext <WVBridgeContext>

@required

/**
 * 此次调用使用的参数。
 */
@property (nonatomic, copy, readonly, nullable) NSDictionary * params;

/**
 * 此次调用是否有效，如果需要停止此次调用（例如上下文被回收），就会为 NO。
 */
@property (nonatomic, assign, readonly, getter=isEnabled) BOOL enabled;

/**
 * 调用是否需要持续性调用。
 * 允许多次调用成功回调，但不保证调用方会处理。不再需要持续性调用时，请设置为 NO 以便及时回收内存。
 */
@property (nonatomic, assign, getter=isKeepAlive) BOOL keepAlive;

/**
 * 可用作回调的 block。
 */
@property (nonatomic, copy, readonly, nonnull) WVBridgeCallback callbackBlock;

#pragma mark Callback

/**
 * 将成功信息和指定数据回调给 WVBridge 调用方。
 *
 * @param result 执行的结果数据。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过（未设置 keepAlive），则为 NO。
 */
- (BOOL)callbackSuccess:(NSDictionary * _Nullable)result;

/**
 * 将指定失败返回代码和数据回调给 WVBridge 调用方。
 *
 * @param ret    WVBridge 的执行结果，请使用上面定义的 MSG_RET_XXXX 宏。
 * @param result 执行的结果数据。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过，则为 NO。
 */
- (BOOL)callbackFailure:(NSString * _Nonnull)ret withResult:(NSDictionary * _Nullable)result;

/**
 * 将指定失败返回代码和消息回调给 WVBridge 调用方。
 * 是 [callbackFailure:ret withResult:@{ @"msg": message }] 的快捷包装。
 *
 * @param ret     WVBridge 的执行结果，请使用上面定义的 MSG_RET_XXXX 宏。
 * @param message 执行的结果消息。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过，则为 NO。
 */
- (BOOL)callbackFailure:(NSString * _Nonnull)ret withMessage:(NSString * _Nullable)message, ... NS_FORMAT_FUNCTION(2,3);

/**
 * 将指定失败返回代码和错误信息回调给 WVBridge 调用方。
 *
 * @param ret   WVBridge 的执行结果，请使用上面定义的 MSG_RET_XXXX 宏。
 * @param error 错误信息。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过，则为 NO。
 */
- (BOOL)callbackFailure:(NSString * _Nonnull)ret withError:(NSError * _Nullable)error;

/**
 * 将指定无效参数的代码和消息回调给 WVBridge 调用方。
 * 是 [callbackFailure:HY_PARAM_ERR withResult:@{ @"msg": @"Invalid parameter {name}: {message}" }] 的快捷包装。
 *
 * @param name    无效的参数。
 * @param message 参数无效的其它消息。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过，则为 NO。
 */
- (BOOL)callbackInvalidParameter:(NSString * _Nullable)name withMessage:(NSString * _Nullable)message, ... NS_FORMAT_FUNCTION(2,3);

/**
 * 将功能不被支持的的代码和消息回调给 WVBridge 调用方。
 * 是 [callbackFailure:MSG_RET_NOT_SUPPORTED withResult:@{ @"msg": @"{className}.{methodName} not supported: {message}" }] 的快捷包装。
 *
 * @param message 功能不被支持的其它消息。
 *
 * @return 如果可以回调，则为 YES；若此时页面已关闭，或已经回调过，则为 NO。
 */
- (BOOL)callbackNotSupported:(NSString * _Nullable)message, ... NS_FORMAT_FUNCTION(1,2);

#pragma mark Function

/**
 * 重定向到其它 WVBridge，用于在当前 WVBridge 中转为调用其它 WVBridge，重定向后的结果会直接回调到调用方。
 *
 * @param name           要重定向的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params         要重定向的 WVBridge 参数。
 *
 * @return 如果可以重定向，则为 YES；若此时页面已关闭、已经回调过或已经重定向过，则为 NO。
 */
- (BOOL)redirect:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params;

/**
 * 重定向到其它 WVBridge，用于在当前 WVBridge 中转为调用其它 WVBridge，重定向后的结果会直接回调到调用方。
 *
 * @param name             要重定向的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params           要重定向的 WVBridge 参数。
 * @param resultCallback   重定向后 WVBridge 的执行结果回调，仅作结果通知，无法对返回值做修改。
 * @param ignorePermission 是否忽略对其它 WVBridge 的权限校验，如果忽略的话请保证非安全页面不会调用到 WVBridge。
 *
 * @return 如果可以重定向，则为 YES；若此时页面已关闭、已经回调过或已经重定向过，则为 NO。
 */
- (BOOL)redirect:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params withResultCallback:(WVBridgeCallback _Nullable)resultCallback isIgnorePermission:(BOOL)ignorePermission;

@end

#pragma mark - WVBridgeProtocol

/**
 * 动态 WVBridge 的实例作用域。
 */
typedef NS_ENUM(NSUInteger, WVBridgeScope) {
	/**
	 * 调用级作用域，每次 WVBridge 调用都使用不同的实例。
	 */
	WVBridgeScopeInvocation,
	/**
	 * 页面作用域，同一个页面中的 WVBridge 调用都使用同一个实例。
	 */
	WVBridgeScopePage,
	/**
	 * View 作用域，同一个 View 中的 WVBridge 调用都使用同一个实例，如果同一个 View 中可能切换多个页面，它们也将共用实例。
	 */
	WVBridgeScopeView,
	/**
	 * 全局作用域，所有 WVBridge 调用都使用同一个实例。
	 */
	WVBridgeScopeStatic,
};

/**
 * 动态 WVBridge API 需要实现的 Protocol。
 */
@protocol WVBridgeProtocol <NSObject>

@optional

/**
 * WVBridge API 实例的作用域，默认为 WVBridgeScopeInvocation。
 */
+ (WVBridgeScope)instanceScope;

/**
 * WVBridge 的执行上下文，会自动设置进去。
 */
@property (nonatomic, weak, nullable) id<WVBridgeContext> context;

/**
 * 重置处理器 - 该方法将会在加载新页面时调用，可以做一些清理工作。
 *
 * @param context WVBridge 被重置时的上下文。
 * @param request 要加载的新页面。
 */
- (void)resetWithContext:(id<WVBridgeContext> _Nonnull)context withNextRequest:(NSURLRequest * _Nullable)request;

/**
 * 暂停处理器 - 该方法将会在 UIViewController viewWillDisappear 时调用，用于降低 WVBridge API 的性能消耗，例如暂停播放音乐和持续性监听器等。
 * 不会对 WVBridgeScopeStatic 作用域的 WVBridge 调用。
 *
 * @param context WVBridge 被暂停时的上下文。
 */
- (void)pauseWithContext:(id<WVBridgeContext> _Nonnull)context;

/**
 * 恢复处理器 - 该方法将会在 UIViewController viewWillAppear 时调用，用于恢复 WVBridge API 的性能，例如恢复播放音乐和持续性监听器等。
 * 不会对 WVBridgeScopeStatic 作用域的 WVBridge 调用。
 *
 * @param context WVBridge 被恢复时的上下文。
 */
- (void)resumeWithContext:(id<WVBridgeContext> _Nonnull)context;

@end

#pragma mark - WVBridgeHandler

/**
 * WVBridge 的处理器。
 *
 * @param params  WVBridge 调用方传入的参数对象。
 * @param context WVBridge 的调用上下文。
 */
typedef void (^WVBridgeHandler)(NSDictionary * _Nullable params, id<WVBridgeCallbackContext> _Nonnull context);

/**
 * WVBridge 的重置处理器。
 * 用于在页面切换时做清理操作，仅会在调用了 handler 的页面调用，且只会调用一次。
 *
 * @param context WVBridge 的调用上下文。
 */
typedef void (^WVBridgeResetHandler)(id<WVBridgeCallbackContext> _Nonnull context);

// 根据是否依赖 WindVane，决定是直接调用还是反射调用，可以单独引入 WVBridgeProtocol.h 而不直接依赖 WindVane。
#if __has_include(<WindVaneBridge/WVBridge.h>)

#import <WindVaneBridge/WVBridge.h>

/**
 * 注册全局 WVBridge 处理器。
 *
 * @param NAME  处理器的名称，格式为 @"类名.方法名"。
 * @param BLOCK 处理器的执行 Block。
 */
#define WVBridgeRegisterHandler(NAME, BLOCK) [WVBridge registerHandler:(NAME) withBlock:(BLOCK)]

/**
 * 注册全局 WVBridge 别名 @{ "类别名.方法别名" : "类名.方法名" }。
 * 注意别名为键，原始名为值。
 */
#define WVBridgeRegisterAlias(ALIAS) [WVBridge registerAlias:(ALIAS)]

/**
 * 注册全局 WVBridge 类。
 *
 * @param NAME  要注册到的类名。
 * @param CLASS 提供 WVBridge 实现的 Class，会根据 handlerName 反射调用其中的方法。
 */
#define WVBridgeRegisterClass(NAME, CLASS) [WVBridge registerClassName:(NAME) withClass:(CLASS)]

#else

/**
 * 注册全局 WVBridge 处理器。
 *
 * @param NAME  处理器的名称，格式为 @"类名.方法名"。
 * @param BLOCK 处理器的执行 Block。
 */
#define WVBridgeRegisterHandler(NAME, BLOCK)                                                                \
	_Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")    \
	if (NSClassFromString(@"WVBridge")) {                                                                   \
		[NSClassFromString(@"WVBridge") performSelector:NSSelectorFromString(@"registerHandler:withBlock:") \
		                                     withObject:(NAME)                                              \
		                                     withObject:(BLOCK)];                                           \
	}                                                                                                       \
	_Pragma("clang diagnostic pop")

/**
 * 注册全局 WVBridge 别名 @{ "类别名.方法别名" : "类名.方法名" }。
 * 注意别名为键，原始名为值。
 */
#define WVBridgeRegisterAlias(ALIAS)                                                                                 \
	_Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")             \
	if (NSClassFromString(@"WVBridge")) {                                                                            \
		[NSClassFromString(@"WVBridge") performSelector:NSSelectorFromString(@"registerAlias:") withObject:(ALIAS)]; \
	}                                                                                                                \
	_Pragma("clang diagnostic pop")

/**
 * 注册全局 WVBridge 类。
 *
 * @param NAME  要注册到的类名。
 * @param CLASS 提供 WVBridge 实现的 Class，会根据 handlerName 反射调用其中的方法。
 */
#define WVBridgeRegisterClass(NAME, CLASS)                                                                    \
	_Pragma("clang diagnostic push") _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")      \
	if (NSClassFromString(@"WVBridge")) {                                                                     \
		[NSClassFromString(@"WVBridge") performSelector:NSSelectorFromString(@"registerClassName:withClass:") \
											 withObject:(NAME)                                                \
											 withObject:(CLASS)];                                             \
	}                                                                                                         \
	_Pragma("clang diagnostic pop")

#endif

// clang-format on
