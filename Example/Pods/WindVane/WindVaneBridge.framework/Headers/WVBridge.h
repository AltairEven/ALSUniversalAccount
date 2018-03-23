/*
 * WVBridge.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVBridgeDelegate.h"
#import "WVBridgeProtocol.h"
#import <Foundation/Foundation.h>

/**
 * WVBridge 入口。
 */
@interface WVBridge : NSObject

/**
 * 绑定到的环境。
 * WebView 环境下为 UIView<WVWebViewBasicProtocol> *；Weex 环境下为 WXSDKInstance。
 */
@property (nonatomic, weak, nullable, readonly) id env;

/**
 * 绑定到的 UIView。
 */
@property (nonatomic, weak, nullable) UIView * view;

/**
 * 绑定到的 UIViewController。
 */
@property (nonatomic, weak, nullable) UIViewController * viewController;

/**
 * 当前页面的 ID，用于跟踪 WVBridge 调用情况。
 * 不要为不同的页面指定相同的 ID，如果不主动设置一个 ID，就会自动生成一个。
 * 也不要为同一个页面指定不同的 ID。
 */
@property (nonatomic, copy, nonnull) NSString * pageId;

/**
 * 是否启用 WVBridge，默认为 YES。
 */
@property (nonatomic, assign, getter=isOpen) BOOL open;

/**
 * 是否支持添加尾调用，默认为 YES。
 */
@property (nonatomic, assign) BOOL supportsTailInvocation;

/**
 * 使用 WVBridge 调用环境和委托初始化。
 * 会对 delegate 做强引用。
 */
- (instancetype _Nonnull)initWithEnv:(id _Nullable)env withDelegate:(id<WVBridgeDelegate> _Nullable)delegate NS_DESIGNATED_INITIALIZER;

/**
 * 检查指定 URL 是否是 WVBridge 的协议。
 *
 * @param url 要检查的 URL。
 */
+ (BOOL)isBridgeProtocol:(NSURL * _Nullable)url;

#pragma mark - 注册全局 WVBridge

/**
 * 注册全局 WVBridge 处理器。
 *
 * @param name  处理器的名称，格式为 @"类名.方法名"。
 * @param block 处理器的执行 Block。
 */
+ (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block;

/**
 * 注册全局 WVBridge 处理器。
 * 可以在页面切换时做清理操作，仅会在调用了 handler 的页面调用，且只会调用一次。
 *
 * @param name       处理器的名称，格式为 @"类名.方法名"。
 * @param block      处理器的执行 Block。
 * @param resetBlock 处理器的重置 Block，用于在页面切换时做清理操作。
 */
+ (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block withResetBlock:(WVBridgeResetHandler _Nullable)resetBlock;

/**
 * 注册全局 WVBridge 类，类必须实现 WVBridgeProtocol。
 *
 * @param className   要注册到的类名。
 * @param bridgeClass 提供 WVBridge 实现的 Class，会根据 handlerName 反射调用其中的方法。
 */
+ (void)registerClassName:(NSString * _Nonnull)className withClass:(Class _Nonnull)bridgeClass;

/**
 * 注册全局 WVBridge 别名 @{ "类别名.方法别名" : "类名.方法名" }。
 * 注意别名为键，原始名为值。
 *
 * @code
 * NSDictionary * alias = @{
 *   @"类别名.方法别名": @"类名.方法名",
 *   @"aliasClassName.aliasHandlerName": @"className.handlerName"
 * };
 * [WVBridge registerAlias:alias];
 * @endcode
 */
+ (void)registerAlias:(NSDictionary<NSString *, NSString *> * _Nonnull)alias;

#pragma mark - 注册私有 WVBridge

/**
 * 注册私有 WVBridge 处理器。
 *
 * @param name  处理器的名称，格式为 @"类名.方法名"。
 * @param block 处理器的执行 Block。
 */
- (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block;

/**
 * 注册私有 WVBridge 处理器。
 * 可以在页面切换时做清理操作，仅会在调用了 handler 的页面调用，且只会调用一次。
 *
 * @param name       处理器的名称，格式为 @"类名.方法名"。
 * @param block      处理器的执行 Block。
 * @param resetBlock 处理器的重置 Block，用于在页面切换时做清理操作。
 */
- (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block withResetBlock:(WVBridgeResetHandler _Nullable)resetBlock;

/**
 * 注册私有 WVBridge 别名 @{ "类别名.方法别名" : "类名.方法名" }。
 * 注意别名为键，原始名为值。
 *
 * @code
 * NSDictionary * alias = @{
 *   @"类别名.方法别名": @"类名.方法名",
 *   @"aliasClassName.aliasHandlerName": @"className.handlerName"
 * };
 * [myBridge registerAlias:alias];
 * @endcode
 */
- (void)registerAlias:(NSDictionary<NSString *, NSString *> * _Nonnull)alias;

#pragma mark - 调用 WVBridge

/**
 * 返回指定 WVBridge 是否已注册。
 *
 * @param name 要判断的 WVBridge 名称，格式为 @"类名.方法名"。
 */
- (BOOL)isHandlerRegistered:(NSString * _Nonnull)name;

/**
 * 根据指定 URL 执行 WVBridge。
 *
 * @param url 符合 WVBridge 调用协议的 URL，格式为：hybrid://className:reqId/handlerName?params
 *
 * @return 如果 url 符合 WVBridge 协议，则返回 YES；否则返回 NO。
 */
- (BOOL)callHandlerWithURL:(NSURL * _Nonnull)url;

/**
 * 调用 WVBridge。
 *
 * @param name   要执行的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params 要执行的 WVBridge 参数。
 * @param reqId  此次 WVBridge 调用的唯一标识，如果为 nil 则认为此次调用不需要回调。
 */
- (void)callHandler:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params withReqId:(NSString * _Nullable)reqId;

/**
 * 调用 WVBridge。
 *
 * @param name     要执行的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params   要执行的 WVBridge 参数。
 * @param callback 此次 WVBridge 调用的回调，会取代 delegate 的回调方法。可能在任意线程调用。
 */
- (void)callHandler:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params withCallback:(WVBridgeCallback _Nullable)callback;

#pragma mark 直接调用 WVBridge

/**
 * 直接调用 WVBridge。
 * 一般用于 Native 直接调用 UI 无关的 WVBridge，不适合调用持续性的 JSBridge，很容易相互影响。
 *
 * @param name     要执行的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params   要执行的 WVBridge 参数。
 * @param callback 此次 WVBridge 调用的回调，可能在任意线程调用。
 */
+ (void)callHandler:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params withCallback:(WVBridgeCallback _Nullable)callback;

#pragma mark - WVBridge 生命周期

/**
 * 暂停 WVBridge Handler，一般在 UIViewController viewWillDisappear 时调用，用于降低 WVBridge API 的性能消耗，例如暂停播放音乐和持续性监听器等。
 */
- (void)pause;

/**
 * 恢复 WVBridge Handler，一般在 UIViewController viewWillAppear 时调用，用于恢复 WVBridge API 的性能，例如恢复播放音乐和持续性监听器等。
 */
- (void)resume;

/**
 * 重置 WVBridge Handler，一般在 View 被重置（例如 WebView 加载新页面）时调用，可以做一些清理工作。
 *
 * @param request View 重置后将要展示的请求。
 */
- (void)resetWithRequest:(NSURLRequest * _Nullable)request;

#pragma mark - Event

/**
 * 通过事件的方式通知所属 WVBridge 调用方，调用方可能不支持此功能。
 * 允许在任意线程调用。
 *
 * @param eventName 要发送的事件名称。
 * @param param     要发送的事件参数。
 *
 * @return 事件是否发送成功。
 */
- (BOOL)dispatchEvent:(NSString * _Nonnull)eventName withParam:(NSDictionary * _Nullable)param;

/**
 * 通过事件的方式通知所属 WVBridge 调用方，调用方可能不支持此功能。
 * 允许在任意线程调用。
 *
 * @param eventName 要发送的事件名称。
 * @param param     要发送的事件参数。
 * @param callback  要获取事件是否被取消默认行为的回调。仅当事件被成功发送才会调用。
 *
 * @return 事件是否发送成功。
 */
- (BOOL)dispatchEvent:(NSString * _Nonnull)eventName withParam:(NSDictionary * _Nullable)param withCallback:(WVEventCallback _Nullable)callback;

#pragma mark - 其它功能

/**
 * 返回当前生命周期内的 WVBridge 调用历史。
 * 允许在任意线程调用。
 */
- (NSDictionary<NSString *, NSNumber *> * _Nonnull)callHistory;

/**
 * 添加尾部调用，会在页面切换或关闭时自动执行。
 * 允许在任意线程调用。
 *
 * @param name   要在页面切换或关闭时执行的 WVBridge 名称。
 * @param params 要执行的 WVBridge 参数。
 *
 * @return 添加尾调用的错误信息。
 */
- (NSError * _Nullable)addTailInvocation:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (void)setLoadDynamicFramework:(BOOL)loadDynamicFramework DEPRECATED_MSG_ATTRIBUTE("现在总是自动唤起动态库，不再提供开关");

@end
