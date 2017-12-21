/*
 * WVRuleWebViewController.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVURLInterceptorCallbackProtocol.h"
#import "WVWebViewControllerBasicProtocol.h"
#import "WVWebViewDelegate.h"
#import "WVWebViewProtocol.h"
#import <UIKit/UIKit.h>

@class WKWebViewConfiguration;

/**
 * 提供了 WindVane WebView 基础功能的 ViewController。
 */
@interface WVRuleWebViewController : UIViewController <WVWebViewControllerBasicProtocol, WVWebViewDelegate, WVURLInterceptorCallbackProtocol>

/**
 * 是否使用 WKWebView，默认为 WVUseWKWebViewNever。
 */
@property (nonatomic, assign, getter=isUseWKWebView) WVUseWKWebView useWKWebView;

/**
 是否复用 UIWebView，默认为 YES。
 */
@property (nonatomic, assign) BOOL recycleWebView;

#pragma mark - WebView

/**
 * 当前 ViewController 包含的 WebView，不存在时会自动创建。
 */
@property (nonatomic, strong, readonly, nonnull) UIView<WVWebViewProtocol> * webView;

/**
 * 当前 ViewController 包含的 WebView，不存在时会返回 nil，而不是自动创建。
 */
@property (nonatomic, strong, readonly, nullable) UIView<WVWebViewProtocol> * internalWebView;

/**
 * WebView 的 UIScrollView 对象。
 */
@property (nonatomic, weak, readonly, nullable) UIScrollView * webViewScrollView;

/**
 * WebView 的内容是否允许拖拽超过边缘再回弹，默认为 YES。
 * 需要禁止拖拽效果时，请使用本属性，不要对 ScrollView 的 bounces 属性进行设置。
 * 与 forbiddenPullScroll 属性作用相同，但值恰好相反。
 */
@property (nonatomic, assign) BOOL bounces;

/**
 WKWebView 的配置，在创建 WKWebView 时，会将此对象传入 WKWebView 的构造函数中。
 注意 ViewController 的 allowsInlineMediaPlayback 和 mediaPlaybackRequiresUserAction 属性会覆盖 WKWebViewConfiguration 的相应配置。
 如果创建了 UIWebView，此属性不生效。
 */
@property (nonatomic, strong, nullable) WKWebViewConfiguration * WKWebViewConfiguration;

#pragma mark - WebView Content

/**
 * WebView 是否正在加载内容。
 */
@property (nonatomic, assign, readonly, getter=isWebViewLoading) BOOL webViewLoading;

/**
 * WebView 当前加载的请求，是主页面的请求，而非 iframe。
 */
@property (nonatomic, copy, readonly, nullable) NSURLRequest * webViewRequest;

/**
 * WebView 当前加载的 URL，是主页面的 URL，而非 iframe。
 */
@property (nonatomic, copy, readonly, nullable) NSURL * webViewURL;

/**
 * 关联的自定义内容控制器。
 */
@property (nonatomic, strong, readonly, nonnull) WVUserContentController * userContentController;

/**
 * 是否允许 WebKit 长按事件（选择、弹出菜单），默认为 NO。
 */
@property (nonatomic, assign, getter=isOpenWebKitLongPress) BOOL openWebKitLongPress;

/**
 * 是否开启长按保存图片，默认为 YES
 */
@property (nonatomic, assign, getter=isOpenLongPressSaveImage) BOOL openLongPressSaveImage;

/**
 * 是否允许内联播放媒体，默认为 YES。
 *
 * @discussion 对于 WKWebView，WebView 初始化之后再设置可能无法生效。
 */
@property (nonatomic, assign) BOOL allowsInlineMediaPlayback;

/**
 * 媒体是否需要用户交互才能自动播放，默认为 NO。
 *
 * @discussion 对于 WKWebView，WebView 初始化之后再设置可能无法生效。
 */
@property (nonatomic, assign) BOOL mediaPlaybackRequiresUserAction;

/**
 * 获取 WebView 是否可以回退。
 */
@property (nonatomic, assign, readonly) BOOL webViewCanGoBack;

/**
 * 获取 WebView 是否可以前进。
 */
@property (nonatomic, assign, readonly) BOOL webViewCanGoForward;

#pragma mark - WVWebViewDelegate

/**
 * 在加载指定页面之前执行的行为。
 * 会在 webView:shouldStartLoadWithRequest:navigationType: 方法中调用，根据子类具体实现的不同，可能不会调用此 Block。
 */
@property (nonatomic, copy, nullable) BOOL (^souldStartLoadAction)(UIView<WVWebViewProtocol> * _Nonnull, NSURLRequest * _Nonnull, UIWebViewNavigationType);

/**
 * 在开始加载新页面前执行的行为。
 * 会在 webViewDidStartLoad: 方法中调用，根据子类具体实现的不同，可能不会调用此 Block。
 */
@property (nonatomic, copy, nullable) void (^didStartLoadAction)(UIView<WVWebViewProtocol> * _Nonnull);

/**
 * 在页面加载完毕后执行的行为。
 * 会在 webViewDidStartLoad: 方法中调用，根据子类具体实现的不同，可能不会调用此 Block。
 */
@property (nonatomic, copy, nullable) void (^didFinishLoadAction)(UIView<WVWebViewProtocol> * _Nonnull);

/**
 * 在页面加载失败时执行的行为。
 * 会在 webView:didFailLoadWithError: 方法中调用，根据子类具体实现的不同，可能不会调用此 Block。
 */
@property (nonatomic, copy, nullable) void (^didFailLoadAction)(UIView<WVWebViewProtocol> * _Nonnull, NSError * _Nonnull);

/**
 * 在接收到 JS 的 console 日志或错误信息时的行为。
 * 会在 webView:didReceiveJSLog:level: 方法中调用，根据子类具体实现的不同，可能不会调用此 Block。
 * 需要 WebView 主动开启 JSLog 级别，才能接收 console 日志。
 */
@property (nonatomic, copy, nullable) void (^didReceiveJSLogAction)(UIView<WVWebViewProtocol> * _Nonnull, NSString * _Nonnull, WVLogLevel);

#pragma mark - LoadPage

/**
 * 加载指定的请求
 *
 * @param request 要加载的请求。
 */
- (void)loadPageByRequest:(NSURLRequest * _Nonnull)request;

/**
 * 加载指定的 URL。
 *
 * @param url 要加载的 URL。
 */
- (void)loadPageByUrl:(NSString * _Nonnull)url;

/**
 * 使用 POST 请求加载指定的 URL。
 *
 * @param url      要加载的 URL。
 * @param postBody POST 请求内容。
 */
- (void)loadPageByUrl:(NSString * _Nonnull)url postBody:(NSString * _Nullable)postBody;

/**
 * 在 isUseWKWebView 为 WVUseWKWebViewCustom 时，决定是否使用 WKWebView。
 */
- (BOOL)decideIsUseWKWebView;

/**
 * WebView 回退历史记录。
 */
- (void)webViewGoBack;

/**
 * WebView 前进历史记录。
 */
- (void)webViewGoForward;

/**
 * WebView 停止加载。
 */
- (void)webViewStopLoading;

/**
 * WebView 刷新页面。
 */
- (void)webViewReload;

#pragma mark - JSBridge

/**
 * 是否开启 JSBridge 服务，默认为 YES。
 */
@property (nonatomic, assign, getter=isOpenLocalService) BOOL openLocalService;

/**
 * 注册私有 WVBridge 处理器，仅能在当前 WebView 中调用。
 *
 * @param name  处理器的名称，格式为 @"类名.方法名"。
 * @param block 处理器的执行 Block。
 */
- (void)registerHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block;

/**
 * 获取当前的 JSBridge 的上下文。
 */
- (WVBridge * _Nonnull)webviewJSBContext;

#pragma mark - WVWebViewDelegate

/**
 * 在加载指定请求之前调用。
 *
 * @return 如果要加载指定的请求，则返回 YES；否则返回 NO。
 */
- (BOOL)webView:(UIView<WVWebViewProtocol> * _Nonnull)webView shouldStartLoadWithRequest:(NSURLRequest * _Nonnull)request navigationType:(UIWebViewNavigationType)navigationType;

/**
 * 在开始加载新页面前调用。
 */
- (void)webViewDidStartLoad:(UIView<WVWebViewProtocol> * _Nonnull)webView;

/**
 * 在页面加载完毕后调用。
 */
- (void)webViewDidFinishLoad:(UIView<WVWebViewProtocol> * _Nonnull)webView;

/**
 * 在页面加载失败时调用。
 */
- (void)webView:(UIView<WVWebViewProtocol> * _Nonnull)webView didFailLoadWithError:(NSError * _Nonnull)error;

/**
 * 在接收到 JS 的 console 日志或错误信息时调用。
 * 需要 WebView 主动开启 JSLog 级别，才能接收 console 日志。
 */
- (void)webView:(UIView<WVWebViewProtocol> * _Nonnull)webView didReceiveJSLog:(NSString * _Nonnull)log level:(WVLogLevel)level;

#pragma mark - 下拉刷新 & 上拉加载

/**
 * 是否启用下拉刷新，默认为 YES。
 * 启用下拉刷新之后，才允许自定义下拉刷新的视图样式。
 * @discussion
 * 由于 iOS7 支持透明导航栏，需要在 viewDidLayoutSubviews 中配置下拉刷新，才可以正确处理 UIScrollView 的 contentInset。
 * 因此对于透明导航栏，下拉刷新会延迟到 viewDidLayoutSubviews 中初始化。
 * 对于不透明导航，下拉刷新仍然会在 loadView 中初始化。
 * 为了统一这一点，我们额外提供了 configPullToRefreshStyle 方法，供子方法重写下拉刷新的样式配置。
 */
@property (nonatomic, assign, getter=isUsePullToRefresh) BOOL usePullToRefresh;

/**
 * 是否启用上拉加载，默认为 YES。
 * 启用上拉加载之后，才允许自定义上拉加载的视图样式。
 */
@property (nonatomic, assign, getter=isUseInfiniteScrolling) BOOL useInfiniteScrolling;

/**
 * 是否使用自定义的下拉刷新组件（仅支持 SVPullToRefresh 开源库），默认为 NO，会使用 WVPullToRefresh 和 WVInfiniteScrolling。
 * 请在使用任何下拉刷新或上拉加载前设置，并且不要在中途修改，否则会发生错误。
 */
@property (nonatomic, assign, getter=isUseCustomPullToRefresh) BOOL useCustomPullToRefresh;

/**
 * 配置下拉刷新的样式。
 * @discussion
 * 由于 iOS7 支持透明导航栏，需要在 viewDidLayoutSubviews 中配置下拉刷新，才可以正确处理 UIScrollView 的 contentInset。
 * 因此对于透明导航栏，下拉刷新会延迟到 viewDidLayoutSubviews 中初始化。
 * 对于不透明导航，下拉刷新仍然会在 loadView 中初始化。
 * 为了统一这一点，我们额外提供了 configPullToRefreshStyle 方法，供子方法重写下拉刷新的样式配置。
 */
- (void)configPullToRefreshStyle;

#pragma mark - 已废弃

/**
 * 【不建议使用】请使用 self.webViewURL.absoluteString
 */
- (NSString * _Nullable)getCurrentUrl;

/**
 * 【不建议使用】URL 拦截的回调会在 shouldStartLoadWithRequest 回调返回 YES 之后调用。
 * 实际使用中与 shouldStartLoadWithRequest 比较容易混淆，因此建议在 shouldStartLoadWithRequest 回调中增加自己的逻辑，而不是这里。
 */
- (BOOL)interruptJumpToLocalPage:(NSInteger)target withParam:(NSDictionary * _Nullable)params withRequest:(NSURLRequest * _Nonnull)request;

#pragma mark - 已废弃，预计于 2018.8.1 删除

@property (nonatomic, readonly, getter=isLoading) BOOL loading DEPRECATED_MSG_ATTRIBUTE("请使用 webViewLoading 属性");
- (void)webViewRefresh DEPRECATED_MSG_ATTRIBUTE("请使用 webViewReload 方法");
/**
 * [不建议使用]请使用 bounces 属性。
 * 是否禁止拖拽效果，默认为 NO。
 * 与 bounces 属性作用相同，但值恰好相反。
 */
@property (nonatomic, assign, getter=isForbiddenPullScroll) BOOL forbiddenPullScroll DEPRECATED_MSG_ATTRIBUTE("请使用 bounces 属性");

- (void)registerHandler:(NSString * _Nonnull)name withClassName:(NSString * _Nonnull)className withHandler:(WVPrivateJSBridgeHandler _Nullable)handler DEPRECATED_MSG_ATTRIBUTE("请使用 registerHandler:withBlock: 方法");
- (void)registeHandler:(NSString * _Nullable)name withClassName:(NSString * _Nullable)className handler:(WVPrivateJSBHandler _Nullable)handler DEPRECATED_MSG_ATTRIBUTE("请使用 registerHandler:withBlock: 方法");
/**
 * 是否开启自动播放视频，默认为 YES。
 * 等价于 allowsInlineMediaPlayback = YES && mediaPlaybackRequiresUserAction = NO。
 */
@property (nonatomic, assign, getter=isAutoPlayAudio) BOOL autoPlayAudio DEPRECATED_MSG_ATTRIBUTE("请直接设置 allowsInlineMediaPlayback 和 mediaPlaybackRequiresUserAction 属性");

- (void)callRegistedHandler:(NSString * _Nullable)className
                 withMethod:(NSString * _Nullable)method
                   withData:(NSString * _Nullable)data
            withFatherClass:(NSString * _Nullable)fClassName
           withFatherMethod:(NSString * _Nullable)fMethod DEPRECATED_MSG_ATTRIBUTE("请直接调用 API id<WVBridgeCallbackContext> 参数提供的 redirect:withParams: 方法");
- (void)callRegistedHandler:(NSString * _Nullable)className
                 withMethod:(NSString * _Nullable)method
                   withData:(NSString * _Nullable)data
            withFatherClass:(NSString * _Nullable)fClassName
           withFatherMethod:(NSString * _Nullable)fMethod
         withResultCallback:(void (^_Nullable)(NSString * _Nonnull code, NSDictionary * _Nullable data))resultCallback DEPRECATED_MSG_ATTRIBUTE("请直接调用 API id<WVBridgeCallbackContext> 参数提供的 redirect:withParams:withResultCallback: 方法");

- (WVBridge * _Nonnull)currentJSBContext DEPRECATED_MSG_ATTRIBUTE("请使用 webviewJSBContext 属性");
- (void)autoWiredJSBridgeWithTargetJSFile:(NSString * _Nullable)jsFile DEPRECATED_MSG_ATTRIBUTE("不再提供");

@end
