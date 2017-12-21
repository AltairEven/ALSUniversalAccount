/*
 * WVNavigation.h
 *
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WindVaneCore.h>

/**
 * 表示当前导航的信息，用于在 WVWebViewDelegate 的回调中获取或设置相关信息。
 */
@interface WVNavigation : NSObject

/**
 * 当前导航的请求。
 */
@property (nonatomic, copy, readonly) NSURLRequest * request;

/**
 * 是否希望在新窗口中打开页面，例如设置有 target="_blank"。
 */
@property (nonatomic, assign, readonly) BOOL newWindow;

/**
 * 当前导航是否是主页面，仅供参考。
 * 对于 WVWebView 来说，由于无法准确获取 iframe 信息，该值在不同的回调中可能会发生变化。
 * 例如，在 shouldStartLoadWithRequest 回调中，是通过 request.URL 和 request.mainDocumentURL 是否相同（移除 fragment）实现的，容易存在误判。
 */
@property (nonatomic, assign, readonly) BOOL mainFrame;

/**
 * 当前导航的类型。
 */
@property (nonatomic, assign, readonly) UIWebViewNavigationType navigationType;

/**
 * 当前导航的 URL 内容类型。
 */
@property (nonatomic, assign) WVURLContentType contentType;

@end
