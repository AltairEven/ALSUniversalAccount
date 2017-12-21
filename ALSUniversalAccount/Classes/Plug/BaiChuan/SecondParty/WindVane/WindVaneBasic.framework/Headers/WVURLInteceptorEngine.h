/*
 * WVURLInteceptorEngine.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVRuleResult.h"
#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVWebViewBasicProtocol.h>

/**
 * 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 */
@interface WVURLInteceptorEngine : NSObject

/*!
 * 初始化
 */
+ (void)initRuleEngine;

/*!
 * 更新
 */
+ (void)updateRuleEngine;

/*!
 * 开关
 */
+ (BOOL)isOpenURLInterceptor;

/*!
 * 执行规则拦截匹配
 */
+ (BOOL)interrunptedFromCurrentRule:(NSURLRequest *)_request
                        withWebView:(UIView<WVWebViewBasicProtocol> *)webView
                     navigationType:(UIWebViewNavigationType)navigationType
                 withViewController:(UIViewController *)viewController;

/*!
 * 请求分发
 */
+ (BOOL)dispatch:(WVRuleResult *)type
              withRequestUrl:(NSURLRequest *)request
    withSourceViewController:(UIViewController *)sourceViewController;

/*!
 * 请求规则匹配
 */
+ (WVRuleResult *)analyzerRequest:(NSURLRequest *)request
                   navigationType:(UIWebViewNavigationType)navigationType
                      withWebView:(UIView<WVWebViewBasicProtocol> *)webView;

/*!
 * 读取POST请求中的参数
 */
+ (NSString *)getRequestBodyForPost:(NSURLRequest *)request;

/*!
 * 判断是否是POST请求
 */
+ (BOOL)isPostRequest:(NSURLRequest *)request;

@end
