/*
 * WVBasicMonitorService.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBasic/WVWebViewProtocol.h>
#import <WindVaneCore/WVMonitorProtocol.h>

/**
 表示 WebView 统计监控信息。
 */
@interface WVWebViewStatisticsMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 [指标]UIWebView 的打开个数。
 */
@property (atomic, assign) NSUInteger UIWebViewCount;

/**
 [指标]WKWebView 的打开个数。
 */
@property (atomic, assign) NSUInteger WKWebViewCount;

/**
 返回当前类型的共享实例。
 */
+ (WVWebViewStatisticsMonitorInfo * _Nonnull)sharedInstance;

/**
 上传之前的统计信息。
 */
+ (void)upload;

/**
 保存当前统计信息。
 */
- (void)save;

@end

#pragma mark - H5 监控

/**
 * 表示 WebView 首次访问的性能监控信息。
 */
@interface WVWebViewStartMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [指标]WebView 首次访问的 URL。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * url;

/**
 * [指标]从应用启动到首次访问的时长。
 */
@property (nonatomic, assign, readonly) double time;

/**
 * 使用首次访问的 URL 和时长初始化。
 */
- (instancetype _Nonnull)initWithURL:(NSString * _Nonnull)url withTime:(double)time;

@end

/**
 表示 POST 请求的监控信息。
 */
@interface WVPostRequestInfo : NSObject <WVMonitorInfoProtocol>

/**
 [维度]资源的 URL。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * url;

/**
 [维度]资源的 Referrer。
 */
@property (nonatomic, copy, readonly, nullable) NSString * referrer;

/**
 使用页面/资源的 URL 和 Referrer 初始化。
 */
- (instancetype _Nonnull)initWithURL:(NSString * _Nonnull)url withReferrer:(NSString * _Nullable)referrer;

@end

/**
 * 表示状态码的性能监控信息。
 */
@interface WVStatusCodeStat : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]资源的 URL。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * url;

/**
 * [维度]资源是否是 HTML 资源。
 */
@property (nonatomic, assign, readonly) BOOL isHTML;

/**
 * [维度]资源的状态码。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * statusCode;

/**
 * [维度]资源的 Referrer。
 */
@property (nonatomic, copy, readonly, nullable) NSString * referrer;

/**
 * [维度]资源的业务标识。
 */
@property (nonatomic, copy, nonnull) NSString * bizCode;

/**
 * 使用页面/资源的 URL、Referrer 和业务代码初始化。
 */
- (instancetype _Nonnull)initWithURL:(NSString * _Nonnull)url isHTML:(BOOL)isHTML statusCode:(NSString * _Nonnull)statusCode withReferrer:(NSString * _Nullable)referrer withBizCode:(NSString * _Nullable)bizCode;

@end

/**
 * 表示 JavaScript 错误的埋点信息。
 */
@interface WVJavaScriptErrorStat : NSObject <WVMonitorInfoProtocol>

// [维度]出现错误的 URL。
@property (nonatomic, copy, readonly, nonnull) NSString * referrer;
// [维度]出现错误的源 URL。
@property (nonatomic, copy, readonly, nonnull) NSString * source;
// [维度]错误信息。
@property (nonatomic, copy, readonly, nullable) NSString * message;
// [维度]错误堆栈。
@property (nonatomic, copy, readonly, nullable) NSString * stack;
// [维度]错误来源。
@property (nonatomic, copy, readonly, nullable) NSString * from;

/**
 * 使用错误信息初始化。
 */
- (instancetype _Nonnull)initWithReferrer:(NSString * _Nonnull)referrer withSource:(NSString * _Nullable)source withMessage:(NSString * _Nullable)message withLineNo:(NSString * _Nullable)lineNo withColNo:(NSString * _Nullable)colNo withStack:(NSString * _Nullable)stack from:(NSString * _Nullable)from;

@end

/**
 * 表示需要监控 H5 性能、报错时可以选择实现的方法。
 */
@protocol WVH5MonitorProtocol <NSObject>

/**
 上报 WebView 的统计信息。
 
 @param info 性能监控信息。
 */
- (void)reportWebViewStatistics:(WVWebViewStatisticsMonitorInfo * _Nonnull)info;

/**
 * 在获取 WebView 首次访问时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)webViewStart:(WVWebViewStartMonitorStat * _Nonnull)stat;

/**
 * 接收到页面/资源状态码时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)receiveStatusCode:(WVStatusCodeStat * _Nonnull)stat;

/**
 报告页面发送了 POST 请求。

 @param info POST 请求监控信息。
 */
- (void)reportPostRequest:(WVPostRequestInfo * _Nonnull)info;

/**
 * 在页面发生 Native 错误时调用。
 *
 * @param error 相关 Native 错误信息。
 * @param arg   Native 错误的额外信息。
 */
- (void)pageOccurNativeError:(NSError * _Nullable)error arg:(NSString * _Nullable)arg;

/**
 * 页面加载完毕时调用。
 *
 * @param pagePerf 页面的性能信息。
 */
- (void)pageFinishLoad:(WVPagePerformance * _Nonnull)pagePerf;

/**
 * 发现页面内容为空时调用。
 *
 * @param error 相关错误信息。
 * @param arg   错误的额外信息。
 */
- (void)pageEmpty:(NSError * _Nullable)error arg:(NSString * _Nullable)arg;

/**
 * 不安全域名埋点。
 *
 * @param error 相关错误信息。
 * @param arg   错误的额外信息。
 */
- (void)insecurityHost:(NSError * _Nullable)error arg:(NSString * _Nullable)arg;

/**
 * 接收到 JS 错误。
 *
 * @param stat 错误信息。
 */
- (void)receiveJavsScriptError:(WVJavaScriptErrorStat * _Nonnull)stat;

/**
 报告 WKWebView 的进程被终止。

 @param error 相关错误信息。
 @param arg   错误的额外信息。
 */
- (void)reportWebProcessTerminated:(NSError * _Nonnull)error arg:(NSString * _Nullable)arg;

@end

#pragma mark - 注册监控

/**
 * WindVaneBasic 模块的监控服务。
 */
@interface WVBasicMonitorService : NSObject

/**
 * 注册一个页面监控 Protocol。
 */
+ (void)registerH5MonitorHandler:(id<WVH5MonitorProtocol> _Nonnull)handler;

/**
 * 返回已注册的页面监控 Protocol。
 */
+ (id<WVH5MonitorProtocol> _Nullable)registeredH5MonitorHandler;

@end
