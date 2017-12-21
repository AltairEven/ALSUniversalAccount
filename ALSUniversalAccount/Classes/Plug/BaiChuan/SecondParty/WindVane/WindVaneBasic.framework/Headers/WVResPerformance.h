/*
 * WVResPerformance.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class WVPagePerformance;

/**
 * 资源的性能信息。
 */
@interface WVResPerformance : NSObject

#pragma mark - 维度/指标

/**
 * [维度]资源 URL，包含参数，不包含 fragment。
 */
@property (nonatomic, copy, readonly) NSString * url;

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

#pragma mark - 其它数据

/**
 * 收到的数据大小。
 */
@property (nonatomic, assign, readonly) NSUInteger dataSize;

/**
 * 资源开始加载的时间（以页面开始加载为基准，单位：毫秒）。
 */
@property (nonatomic, assign, readonly) double start;

/**
 * 资源结束加载的时间（以页面开始加载为基准，单位：毫秒）。
 */
@property (nonatomic, assign, readonly) double end;

/**
 * 资源的状态码值。
 */
@property (nonatomic, assign, readonly) NSInteger statusCodeInteger;

/**
 * 资源的加载来源。
 */
@property (nonatomic, copy, readonly) NSString * referrer;

/**
 * 是否是 HTML 资源。
 */
@property (nonatomic, assign, readonly) BOOL isHTML;

/**
 * 当前资源所属页面。
 */
@property (nonatomic, weak, readonly) WVPagePerformance * page;

#pragma mark - 计算数据。

/**
 * 获取资源加载时间。
 */
- (double)loadTime;

/**
 * 获取资源加载来源是否是网络。
 */
- (BOOL)isFromNetwork;

/**
 * 返回当前状态码是否表示资源成功加载。
 */
- (BOOL)isStatusSuccess;

@end
