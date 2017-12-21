/*
 * WVBasic.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WindVaneCore.h>

/**
 * 初始化 WindVane Basic 模块。
 * WindVane 基础 WebView 库，提供了一些 WebView 相关基础功能，包括 WebView、JSBridge、URLInterceptor、ViewController、StandardEventModal 模块。
 */
@interface WVBasic : NSObject

/**
 * 初始化 WindVane Basic 模块，会自动初始化 WindVane Core 模块。
 */
+ (void)setup;

#pragma mark - UserAgent

/**
 * 要求不主动按照 Ali UserAgent 规范修改 UserAgent。
 */
+ (void)doNotChangeUserAgent;

/**
 * 返回浏览器的默认 UserAgent。
 * 由于第一次调用时内部会创建一个 UIWebView 来获取默认 UserAgent，因此在应用初始化过程中调用可能会产生异常。
 * 
 * @return 该方法第一次调用时的 UserAgent。
 */
+ (NSString *)defaultUserAgent;

/**
 * 返回 WindVane 的 UserAgent。
 * 由于第一次调用时内部会创建一个 UIWebView 来获取默认 UserAgent，因此在应用初始化过程中调用可能会产生异常。
 * 
 * @return WindVane 的 UserAgent。
 */
+ (NSString *)userAgent;

/**
 * 按照 Ali UserAgent 规范修改全局 UserAgent，多次调用只有第一次生效。
 * 由于第一次调用时内部会创建一个 UIWebView 来获取默认 UserAgent，因此在应用初始化过程中调用可能会产生异常。
 * 没有特殊必要请不要调用此方法来修改全局 UserAgent，WindVane 会优先使用 WebView 级别的 UserAgent，避免对非 WindVane 的 WebView 产生影响。
 */
+ (void)changeUserAgent;

#pragma mark - ScrollIndicator

/**
 * 获取默认是否显示垂直滚动条指示器。
 */
+ (BOOL)showsVerticalScrollIndicator;

/**
 * 设置默认是否显示垂直滚动条指示器，默认为 YES。
 */
+ (void)setShowsVerticalScrollIndicator:(BOOL)showsVerticalScrollIndicator;

#pragma mark - Sync WKWebView Cookie

/**
 获取是否尝试同步 WKWebView 的 Cookie，默认为 YES。
 */
+ (BOOL)syncWKWebViewCookie;

/**
 设置是否尝试同步 WKWebView 的 Cookie。
 */
+ (void)setSyncWKWebViewCookie:(BOOL)syncWKWebViewCookie;

#pragma mark - JavaScript Log

/**
 * 获取 JavaScript 日志的级别，默认为 WVLogLevelOff。
 */
+ (WVLogLevel)JSLogLevel;

/**
 * [仅限 DEBUG 包]设置 JavaScript 日志的级别。
 * 设置后，只会在新创建的 WebView 生效。
 */
+ (void)setJSLogLevel:(WVLogLevel)logLevel;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (void)init DEPRECATED_MSG_ATTRIBUTE("init 会与 Swift 关键词冲突，因此改用 setup 方法");
+ (void)doNotFixIOS7ProtocolBug DEPRECATED_MSG_ATTRIBUTE("WindVane 不再支持 iOS7 以下的系统，无需再做 Protocol BUG 修复");

@end
