/*
 * WVJSBridgeService.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVApiAuthCheckResult.h"
#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVWebViewBasicProtocol.h>

#pragma mark - 已废弃，预计于 2018.8.1 删除

DEPRECATED_MSG_ATTRIBUTE("请使用 WVBridgeCheckerProtocol 和 WVBridgeChecker")
@protocol WindVaneAPIAuthCheckProtocol <NSObject>

@optional

/**
 * 鉴权 AOP 方法。
 *
 * @param className      调用的 JSBridge 类名。
 * @param method         调用的 JSBridge 方法名。
 * @param data           调用的 JSBridge 参数。
 * @param webView        调用 JSBridge 的 WebView。
 * @param viewController 调用 JSBridge 的 ViewController。
 *
 * @return 鉴权的结果，返回 WVApiAuthCheckResultNULL 表示不做处理。
 */
- (WVApiAuthCheckResult *)apiAuthCheck:(NSString *)className withMethod:(NSString *)method withParam:(NSString *)data withWebView:(UIView<WVWebViewBasicProtocol> *)webView withViewController:(UIViewController *)viewController;

@end

DEPRECATED_MSG_ATTRIBUTE("请使用 WVBridgeChecker")
@interface WVJSBridgeService : NSObject

/**
 * 注册 JSBridge 的 AOP 鉴权处理器。
 */
+ (void)registerWVJSBridgeAuthAopHandler:(id<WindVaneAPIAuthCheckProtocol>)handler DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgeChecker registerChecker:] 方法");

/**
 * 返回已注册 JSBridge 的 AOP 鉴权处理器。
 */
+ (id<WindVaneAPIAuthCheckProtocol>)registeredWVJSBridgeAuthAopHandler DEPRECATED_MSG_ATTRIBUTE("现在已支持同时注册多个 checker，不再需要此方法");

+ (id<WindVaneAPIAuthCheckProtocol>)registedWVJSBridgeAuthAopHandler DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgeChecker registerChecker:] 方法");

@end
