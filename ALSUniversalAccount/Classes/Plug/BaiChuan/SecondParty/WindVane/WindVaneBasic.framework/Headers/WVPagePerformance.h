/*
 * WVPagePerformance.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVResPerformance.h"

@class WVResPerformance;

/**
 * 页面的性能信息。
 */
@interface WVPagePerformance : NSObject

/**
 * 全局唯一的页面标识符，一般供输出日志使用。
 */
@property (nonatomic, copy, readonly) NSString * identifier;

/**
 * 页面的业务标识符。
 */
@property (nonatomic, copy, readonly) NSString * bizCode;

/**
 * 不包含 fragment 的页面 URL，用于匹配。
 */
@property (nonatomic, copy, readonly) NSString * matchUrl;

#pragma mark - 维度/指标

/**
 * [维度]页面 URL。
 */
@property (nonatomic, copy, readonly) NSString * url;

/**
 * [维度]是否包含 WebView 初始化时长。
 */
@property (nonatomic, assign, readonly) BOOL hasInit;

/**
 * [指标]WebView 的初始化时长。
 */
@property (nonatomic, assign, readonly) double initTime;

/**
 * [维度]页面是否正常完成加载。
 */
@property (nonatomic, assign, readonly) BOOL isFinished;

/**
 * [维度]资源的来源。
 * 1  - 走网络。
 * 22 - 走内存缓存。
 * 23 - 走磁盘缓存。
 * 3  - 走 PackageApp。
 * 4  - 走 ZCache。
 * 8  - 走解 Combo。
 */
@property (nonatomic, copy, readonly) NSString * fromType;

/**
 * [维度]资源的状态码。
 */
@property (nonatomic, copy, readonly) NSString * statusCode;

/**
 * [维度]资源的来源。
 */
@property (nonatomic, copy, readonly) NSString * via;

/**
 * [维度]资源的协议类型。
 */
@property (nonatomic, copy, readonly) NSString * protocolType;

/**
 * [维度]Package App 应用名称。
 */
@property (nonatomic, copy, readonly) NSString * pkgName;

/**
 * [维度]Package App 应用版本。
 */
@property (nonatomic, copy, readonly) NSString * pkgVersion;

/**
 * [维度]Package App 应用 seq。
 */
@property (nonatomic, copy, readonly) NSString * pkgSeq;

/**
 * [指标]页面的 DOMContentLoaded 时长。
 */
@property (nonatomic, assign, readonly) double domLoad;

/**
 * [指标]页面加载时间。
 */
@property (nonatomic, assign, readonly) double pageLoad;

/**
 * [指标]资源校验总耗时。
 */
@property (nonatomic, assign, readonly) double allVerifyTime;

/**
 * [维度]是否包含 window.performance.timing 数据。
 */
@property (nonatomic, assign, readonly) BOOL containsTiming;

/**
 * [指标]请求开始时间，window.performance.timing requestStart - navigationStart。
 */
@property (nonatomic, assign, readonly) double req;

/**
 * [指标]响应开始时间，window.performance.timing responseStart - navigationStart。
 */
@property (nonatomic, assign, readonly) double rps;

/**
 * [指标]响应结束时间，window.performance.timing responseEnd - navigationStart。
 */
@property (nonatomic, assign, readonly) double rpe;

/**
 * [指标]DomLoading 时间，window.performance.timing domLoading - navigationStart。
 */
@property (nonatomic, assign, readonly) double dl;

/**
 * [指标]DomContentLoaded 时间，window.performance timing.domContentLoadedEventStart - navigationStart。
 */
@property (nonatomic, assign, readonly) double dcl;

/**
 * [指标]DomContentLoaded 时间，window.performance timing.domContentLoadedEventEnd - navigationStart。
 */
@property (nonatomic, assign, readonly) double dce;

/**
 * [指标]LoadEventStart 时间，window.performance timing.loadEventStart - navigationStart。
 */
@property (nonatomic, assign, readonly) double les;

/**
 * [指标]LoadEventEnd 时间，window.performance timing.loadEventEnd - navigationStart。
 */
@property (nonatomic, assign, readonly) double lee;

#pragma mark - 其它属性

/**
 * 页面埋点的采样信息。
 */
@property (nonatomic, assign, readonly) NSUInteger appMonitor;

/**
 * 页面的状态码值。
 */
@property (nonatomic, assign, readonly) NSInteger statusCodeInteger;

/**
 * 页面中加载的资源列表。
 */
@property (nonatomic, copy, readonly) NSArray<WVResPerformance *> * resources;

#pragma mark - DEBUG 模式属性

/**
 * 应用的 CPU 使用情况。
 */
@property (nonatomic, assign, readonly) float appCPU;

/**
 * 应用的内存使用情况。
 */
@property (nonatomic, assign, readonly) float appMemory;

/**
 * WebView 的 CPU 使用情况。
 */
@property (nonatomic, assign, readonly) float webViewCPU;

/**
 * WebView 的内存使用情况。
 */
@property (nonatomic, assign, readonly) float webViewMemory;

/**
 * 返回当前状态码是否表示页面成功加载。
 */
- (BOOL)isStatusSuccess;

@end
