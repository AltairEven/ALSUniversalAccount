/*
 * WVRuleWebViewController.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVViewController.h"
#import "WVURLInterceptorCallbackProtocol.h"

/**
 这个类已将主要功能迁移到 WVViewController。
 */
@interface WVRuleWebViewController : WVViewController <WVURLInterceptorCallbackProtocol>

/**
 是否复用 UIWebView，默认为 YES。
 */
@property (nonatomic, assign) BOOL recycleWebView DEPRECATED_MSG_ATTRIBUTE("复用并没有带来明显的卡顿降低效果，不如直接切换 WKWebView");

#pragma mark - 已废弃

/**
 【不建议使用】URL 拦截的回调会在 shouldStartLoadWithRequest 回调返回 YES 之后调用。
 实际使用中与 shouldStartLoadWithRequest 比较容易混淆，因此建议在 shouldStartLoadWithRequest 回调中增加自己的逻辑，而不是这里。
 */
- (BOOL)interruptJumpToLocalPage:(NSInteger)target withParam:(NSDictionary * _Nullable)params withRequest:(NSURLRequest * _Nonnull)request;

#pragma mark - 已废弃，预计于 2019.1.1 删除

@property (nonatomic, copy, nullable) BOOL (^souldStartLoadAction)(UIView<WVWebViewProtocol> * _Nonnull, NSURLRequest * _Nonnull, UIWebViewNavigationType) DEPRECATED_MSG_ATTRIBUTE("拼写错误，请使用 shouldStartLoadAction 属性");
- (NSString * _Nullable)getCurrentUrl DEPRECATED_MSG_ATTRIBUTE("请使用 self.webViewURL.absoluteString");

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
- (WVBridge * _Nonnull)currentJSBContext DEPRECATED_MSG_ATTRIBUTE("请使用 webviewJSBContext 属性");
- (void)autoWiredJSBridgeWithTargetJSFile:(NSString * _Nullable)jsFile DEPRECATED_MSG_ATTRIBUTE("不再提供");

@end
