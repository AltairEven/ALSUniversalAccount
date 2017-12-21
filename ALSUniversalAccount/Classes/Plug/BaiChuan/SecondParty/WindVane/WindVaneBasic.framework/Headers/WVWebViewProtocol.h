/*
 * WVWebViewProtocol.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVNavigation.h"
#import "WindVaneJSBridgeCore.h"
#import <Foundation/Foundation.h>
#import <WindVaneBridge/WindVaneBridge.h>

@class WVPageMeta;
@class WVPagePerformance;
@class WVUserContentController;
@protocol WVWebViewDelegate;

// WebView 的 viewport-fit 设置。
typedef NS_ENUM(NSInteger, WVWebViewViewportFit) {
	WVWebViewViewportFitAuto,    // 自动设置 Viewport。
	WVWebViewViewportFitContain, // 保证 Viewport 完整可见。
	WVWebViewViewportFitCover,   // 覆盖到物理屏幕的矩形之上。
};

// WebView 可见性。
typedef NS_ENUM(NSInteger, WVWebViewVisiblity) {
	WVWebViewVisiblilityUnknown = 0, // 可见性未知。
	WVWebViewInvisible = 1,          // 不可见。
	WVWebViewVisible = 2,            // 可见。
};

/**
 * 包含了 WindVane WebView 功能的协议。
 */
@protocol WVWebViewProtocol <NSObject, WVWebViewBasicProtocol>

@required

#pragma mark - Configuration

/**
 * 挂载的归属源 UIViewController。
 */
@property (nonatomic, weak, nullable) UIViewController * sourceViewController;

/**
 * [仅限 DEBUG 包]JavaScript 日志的级别，默认为 WVLogLevelOff。
 * 请在 WebView 初始化时就设置好，后期再修改不一定能生效。
 */
@property (nonatomic, assign) WVLogLevel JSLogLevel;

/**
 * WebView 在所属 ViewController 中的可见性。
 */
@property (nonatomic, assign) WVWebViewVisiblity visibleInViewController;

/**
 * WebView 的内容是否允许拖拽超过边缘再回弹，默认为 YES。
 * 需要禁止拖拽效果时，请使用本属性，不要对 ScrollView 的 bounces 属性进行设置。
 * 与 forbiddenPullScroll 属性作用相同，但值恰好相反。
 */
@property (nonatomic, assign) BOOL bounces;

/**
 * 是否启用下拉刷新，默认为 NO。
 * 启用下拉刷新之后，才允许自定义下拉刷新的视图样式。
 */
@property (nonatomic, assign, getter=isUsePullToRefresh) BOOL usePullToRefresh;

/**
 * 是否启用上拉加载，默认为 NO。
 * 启用上拉加载之后，才允许自定义上拉加载的视图样式。
 */
@property (nonatomic, assign, getter=isUseInfiniteScrolling) BOOL useInfiniteScrolling;

/**
 * 是否使用自定义的下拉刷新组件（仅支持 SVPullToRefresh 开源库），默认为 NO，会使用 WVPullToRefresh 和 WVInfiniteScrolling。
 * 请在使用任何下拉刷新或上拉加载前设置，并且不要在中途修改，否则会发生错误。
 */
@property (nonatomic, assign, getter=isUseCustomPullToRefresh) BOOL useCustomPullToRefresh;

/**
 * WebView 的业务代码。
 */
@property (nonatomic, strong, nullable) NSString * bizCode;

/**
 * 是否响应点击 status bar 自动滚动到顶端。
 */
@property (nonatomic, assign) BOOL scrollsToTop;

/**
 * 是否允许 WebKit 长按事件（选择、弹出菜单），默认为 YES。
 */
@property (nonatomic, assign, getter=isOpenWebKitLongPress) BOOL openWebKitLongPress;

/**
 * 是否开启长按保存图片，默认为 YES
 */
@property (nonatomic, assign, getter=isOpenLongPressSaveImage) BOOL openLongPressSaveImage;

/**
 * 是否允许内联播放媒体，默认为 YES。
 * 
 * @discussion 对于 WKWebView，必须在 initWithFrame:configuration: 的 configuration 中设置 allowsInlineMediaPlayback，初始化之后再设置可能无法生效。
 */
@property (nonatomic, assign) BOOL allowsInlineMediaPlayback;

/**
 * 媒体是否需要用户交互才能自动播放，默认为 NO。
 * 
 * @discussion 对于 WKWebView，必须在 initWithFrame:configuration: 的 configuration 中设置 mediaPlaybackRequiresUserAction，初始化之后再设置可能无法生效。
 */
@property (nonatomic, assign) BOOL mediaPlaybackRequiresUserAction;

/**
 * 是否允许 Air Play，默认为 YES。
 */
@property (nonatomic, assign) BOOL mediaPlaybackAllowsAirPlay;

#pragma mark - Request

/**
 * 当前加载的请求，是主页面的请求，而非 iframe。
 * WKWebView 中只提供了 URL 属性，因此请优先使用 URL 属性，并总是以 URL 属性为准，request 有时可能并不完全准确（例如服务端 302 时）。
 */
@property (nonatomic, readonly, copy, nullable) NSURLRequest * request;

/**
 * 估计的加载进度。
 *
 * @discussion 该属性支持 KVO。
 */
@property (nonatomic, assign, readonly) double estimatedProgress;

#pragma mark - Content

/**
 * 当前 WebView 加载页面的 title。
 *
 * @discussion 该属性支持 KVO。
 */
@property (nonatomic, copy, readonly, nullable) NSString * title;

/**
 * 当前导航信息，仅在 WVWebViewDelegate 的回调中生效。
 */
@property (nonatomic, strong, readonly, nullable) WVNavigation * navigation;

/**
 * WebView 的可见性，会由 ViewController 的可见性和 WebView 在 ViewController 中的可见性综合计算得到。
 *
 * @discussion 该属性支持 KVO。
 */
@property (nonatomic, assign, readonly) WVWebViewVisiblity visiblity;

/**
 * WebView 的主页面内容类型，会忽略 iframe 内容的类型。
 */
@property (nonatomic, assign, readonly) WVURLContentType contentType;

/**
 * 关联的自定义内容控制器。
 */
@property (nonatomic, strong, readonly, nonnull) WVUserContentController * userContentController;

/**
 * 当前页面的性能信息。
 */
@property (nonatomic, strong, readonly, nullable) WVPagePerformance * pagePerformance;

/**
 * WebView 当前页面内容是否为空，该属性并不会实时反应页面的白屏状况，实时信息请使用 [WebView isPageEmpty:] 方法。
 */
@property (nonatomic, assign, getter=isPageEmpty, readonly) BOOL pageEmpty;

/**
 * 检查 WebView 的页面是否为空。
 *
 * @param callback 检查结果的回调。
 */
- (void)isPageEmpty:(void (^_Nonnull)(BOOL isPageEmpty))callback;

/**
 * 当前页面的元数据。
 */
@property (nonatomic, strong, readonly, nonnull) WVPageMeta * pageMeta;

/**
 当前页面的 viewport-fit 设置。
 */
@property (nonatomic, assign, readonly) WVWebViewViewportFit viewportFit;

#pragma mark - Delegate

/**
 * 当前 WebView 的委托。
 */
@property (nonatomic, weak, nullable) id<WVWebViewDelegate> windVaneDelegate;

#pragma mark - Life cycle

/**
 * [注意：必须在 ViewController 的 viewWillDisappear 中调用!!!] 释放 WebView 的服务。
 */
- (void)releaseWebViewService;

/**
 * [注意：必须在 ViewController 的 viewWillAppear 中调用!!!] 重新绑定 WebView 的服务。
 */
- (void)bindingWebViewService;

#pragma mark - JSBridge

/**
 * 当前 WebView 的 JSBridge 的上下文。
 */
@property (nonatomic, strong, readonly, nonnull) WVBridge * webviewJSBContext;

/**
 * 是否开启 JSBridge 服务，默认为 NO。
 */
@property (nonatomic, assign, getter=isOpenLocalService) BOOL openLocalService;

/**
 * 当前页面的 JSBridge 调用历史。
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary * jsBridgeCallHistory;

/**
 * 注册私有 WVBridge 处理器，仅能在当前 WebView 中调用。
 *
 * @param name  处理器的名称，格式为 @"类名.方法名"。
 * @param block 处理器的执行 Block。
 */
- (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block;

#pragma mark - 已废弃，预计于 2018.8.1 删除

/**
 * [不建议使用]请使用 bounces 属性。
 * 是否禁止拖拽效果，默认为 NO。
 * 与 bounces 属性作用相同，但值恰好相反。
 */
@property (nonatomic, assign, getter=isForbiddenPullScroll) BOOL forbiddenPullScroll DEPRECATED_MSG_ATTRIBUTE("请使用 bounces 属性");
@property (nonatomic, assign, readonly, getter=isMainFrame) BOOL mainFrame DEPRECATED_MSG_ATTRIBUTE("请使用 navigation 属性的 mainFrame 属性");
- (void)registerHandler:(NSString * _Nonnull)name withClassName:(NSString * _Nonnull)className withHandler:(WVPrivateJSBridgeHandler _Nonnull)handler DEPRECATED_MSG_ATTRIBUTE("请使用 registerHandler:withBlock: 方法");
- (void)registeHandler:(NSString * _Nonnull)name withClassName:(NSString * _Nonnull)className handler:(WVPrivateJSBHandler _Nonnull)_Nonnullhandler DEPRECATED_MSG_ATTRIBUTE("请使用 registerHandler:withBlock: 方法");

- (void)fetchElementValue:(NSArray * _Nonnull)elementIds completionHandler:(void (^_Nonnull)(NSDictionary * _Nonnull))completionHandler DEPRECATED_MSG_ATTRIBUTE("请使用 pageMeta 属性");

@property (nonatomic, assign, getter=isAutoPlayAudio) BOOL autoPlayAudio DEPRECATED_MSG_ATTRIBUTE("请直接设置 allowsInlineMediaPlayback 和 mediaPlaybackRequiresUserAction 属性");
@property (nonatomic, assign) BOOL isOpenAutoPlayAudio DEPRECATED_MSG_ATTRIBUTE("请直接设置 allowsInlineMediaPlayback 和 mediaPlaybackRequiresUserAction 属性");

- (void)callRegistedHandler:(NSString * _Nonnull)className
                 withMethod:(NSString * _Nonnull)method
                   withData:(NSString * _Nullable)data
            withFatherClass:(NSString * _Nonnull)fClassName
           withFatherMethod:(NSString * _Nonnull)fMethod DEPRECATED_MSG_ATTRIBUTE("请直接调用 API id<WVBridgeCallbackContext> 参数提供的 redirect:withParams: 方法");
- (void)callRegistedHandler:(NSString * _Nonnull)className
                 withMethod:(NSString * _Nonnull)method
                   withData:(NSString * _Nullable)data
            withFatherClass:(NSString * _Nonnull)fClassName
           withFatherMethod:(NSString * _Nonnull)fMethod
         withResultCallback:(void (^_Nullable)(NSString * _Nonnull code, NSDictionary * _Nullable data))resultCallback DEPRECATED_MSG_ATTRIBUTE("请直接调用 API id<WVBridgeCallbackContext> 参数提供的 redirect:withParams:withResultCallback: 方法");

@end
