/*
 * WVJavascriptApplication.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVJSBridgeCallbackDelegate.h"
#import "WindVaneJSBridgeCore.h"
#import <WindVaneBridge/WindVaneBridge.h>

/**
 * 表示与 WebView 关联的 JSBridge，核心功能已迁移到 WVBridge 类中，这里主要为了做旧版本兼容，旧接口均已废弃。
 */
@interface WVJavascriptApplication : WVBridge

/**
 * 使用指定的 WebView 初始化。
 */
- (instancetype)initWithWebView:(UIView<WVWebViewBasicProtocol> *)webView NS_DESIGNATED_INITIALIZER;

#pragma mark - 已废弃，删除时间未定

/**
 * [不建议使用]通过事件的方式通知 WebView。
 *
 * 如果希望在 JSBridge 中发送事件，请使用 JSBridge context 的 dispatchEvent 方法来发送事件，对多种容器（WebView/Weex）提供了兼容。
 * http://h5.alibaba-inc.com/windvane/JSBridge.html#2-1-3-发送事件
 *
 * 如果在非 JSBridge 环境中发送事件，请统一使用 [WVStandardEventCenter postNotificationToJS:withEventData:] 方法。
 */
+ (void)notifyByEventForWebView:(UIView<WVWebViewBasicProtocol> *)webview withEventName:(NSString *)eventName withResult:(NSDictionary *)eventResult;

#pragma mark - 已废弃，预计于 2019.1.1 删除

/**
 [不建议使用]请替换为 [WVBridge registerHandler:withBlock:] 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge。
 */
+ (void)registerAppHandler:(NSString *)name withClassName:(NSString *)className withHandler:(WVJSBridgeHandler)handler DEPRECATED_MSG_ATTRIBUTE("请替换为 [WVBridge registerHandler:withBlock:] 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge");

/**
 [不建议使用]请替换为 [WVBridge registerHandler:withBlock:] 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge。
 */
+ (void)registerAppHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler DEPRECATED_MSG_ATTRIBUTE("请替换为 [WVBridge registerHandler:withBlock:] 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge");

/**
 [不建议使用]请替换为 registerHandler:withBlock: 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge。
 */
- (void)registerHandler:(NSString *)name withClassName:(NSString *)className withHandler:(WVPrivateJSBridgeHandler)handler DEPRECATED_MSG_ATTRIBUTE("请替换为 registerHandler:withBlock: 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge");

/**
 [不建议使用]请替换为 registerHandler:withBlock: 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge。
 */
- (void)registeHandler:(NSString *)name withClassName:(NSString *)className handler:(WVPrivateJSBHandler)handler DEPRECATED_MSG_ATTRIBUTE("请替换为 registerHandler:withBlock: 方法，用法请参考 http://h5.alibaba-inc.com/windvane/JSBridge.html#2-2-iOS-静态注册-JSBridge");

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (void)registerAppHandlerAlias:(NSDictionary *)alias DEPRECATED_MSG_ATTRIBUTE("请替换为 [WVBridge registerAlias:] 方法");
- (void)registerHandlerAlias:(NSDictionary<NSString *, NSString *> *)alias DEPRECATED_MSG_ATTRIBUTE("请替换为 registerAlias: 方法");

+ (void)notifyByEventForWebView:(UIView<WVWebViewBasicProtocol> *)webview withEventName:(NSString *)eventName withResult:(NSDictionary *)eventResult withCallback:(WVEventCallback)callback DEPRECATED_ATTRIBUTE;
+ (BOOL)isJSBridgeProtocol:(NSString *)url DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridge isBridgeProtocol:] 方法");
// 现在可以在页面切换或销毁时做清理操作，仅会在调用了 handler 的页面调用，且只会调用一次。旧的方法已不支持。
+ (void)registerAppHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler)resetHandler DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridge registerHandler:withBlock:withResetBlock:] 方法");
+ (void)registerAppHandler:(NSString *)name withClassName:(NSString *)className handler:(WVJSBHandler)handler withResetHandler:(WVJSBResetHandler)resetHandler withDeallocHandler:(WVJSBDeallocHandler)deallocHandler DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridge registerHandler:withBlock:withResetBlock:] 方法");
// 建议使用 [WVBridge registerClassName:withClass:] 方法或 WVBridgeRegisterClass 宏。
+ (void)registerClass:(Class)jsbClass withClassName:(NSString *)className DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridge registerClassName:withClass:] 方法");
- (BOOL)isAlreadyRegisteredHandler:(NSString *)handlerName withClassName:(NSString *)className DEPRECATED_MSG_ATTRIBUTE("请使用 isHandlerRegistered: 方法");
- (BOOL)isAlreadyRegisteHandler:(NSString *)handlerName withClassName:(NSString *)className DEPRECATED_MSG_ATTRIBUTE("请使用 isHandlerRegistered: 方法");
- (void)executeScript:(NSString *)script DEPRECATED_MSG_ATTRIBUTE("请使用 [WebView evaluateJavaScript:completionHandler:] 方法");
+ (void)executeJs:(NSString *)script withWebView:(UIView<WVWebViewBasicProtocol> *)webView DEPRECATED_MSG_ATTRIBUTE("请使用 [WebView evaluateJavaScript:completionHandler:] 方法");
- (BOOL)execute:(NSURLRequest *)request withViewController:(UIViewController *)viewController DEPRECATED_MSG_ATTRIBUTE("请使用 callHandlerWithRequest: 方法");
+ (void)notifyByEventForWebView:(UIView<WVWebViewBasicProtocol> *)webview withEventName:(NSString *)eventName withResult:(NSDictionary *)eventResult syncOnMain:(BOOL)isSyncOnMain DEPRECATED_MSG_ATTRIBUTE("请使用 [WVStandardEventCenter postNotificationToJS:withEventData:withWebView:] 方法");
// 拼写错误。
- (void)registeHandler:(NSString *)name withClassName:(NSString *)className withHandler:(WVPrivateJSBridgeHandler)handler DEPRECATED_MSG_ATTRIBUTE("请使用 registerHandler:withBlock: 方法");
- (void)registeHandlerAlias:(NSDictionary *)alias DEPRECATED_MSG_ATTRIBUTE("请使用 registerAlias: 方法");
- (void)notifyEvent:(NSString *)eventName withResult:(NSDictionary *)eventResult DEPRECATED_MSG_ATTRIBUTE("请使用 dispatchEvent:withParam: 方法");
- (void)notifyEvent:(NSString *)eventName withResult:(NSDictionary *)eventResult withCallback:(WVEventCallback)callback DEPRECATED_MSG_ATTRIBUTE("请使用 dispatchEvent:withParam:withCallback: 方法");
// 不要再使用全局的 JSBridge 通道，会存在调用混乱的问题。
+ (id<WVJSBridgeCallbackDelegate>)callbackDelegate DEPRECATED_ATTRIBUTE;
+ (void)setCallbackDelegate:(id<WVJSBridgeCallbackDelegate>)delegate DEPRECATED_ATTRIBUTE;
+ (WVJavascriptApplication *)appWindVaneJSBContext DEPRECATED_ATTRIBUTE;
// 别名不再直接开放。
- (NSDictionary *)registedAlias DEPRECATED_ATTRIBUTE;
// 请总是由 H5 自行引入 windvane.js，不要使用自动注入功能。
+ (BOOL)autoWiredJSBridgeIntoWebView:(UIView<WVWebViewBasicProtocol> *)webView withJSBridgeFileName:(NSString *)jsFile DEPRECATED_ATTRIBUTE;

@end
