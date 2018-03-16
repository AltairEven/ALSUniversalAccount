/*
 ZCacheCommonConfig.h
 
 Created by WindVane.
 Copyright (c) 2018年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "ZCacheConfig.h"
#import <Foundation/Foundation.h>

/**
 表示 ZCache 的通用配置。
 */
@interface ZCacheCommonConfig : ZCacheConfig

/**
 在加载服务端发布的新配置之前的默认配置。
 */
+ (ZCacheCommonConfig * _Nonnull)defaultConfig;

/**
 当前配置。
 */
+ (ZCacheCommonConfig * _Nonnull)currentConfig;

#pragma mark - URL 配置

/**
 个性化预加载的配置前缀。
 */
@property (nonatomic, copy, nullable) NSString * customsConfigPrefix;

/**
 预加载的预览 zip 前缀。
 */
@property (nonatomic, copy, nullable) NSString * packageZipPreviewPrefix;

/**
 预加载的 zip 前缀。
 */
@property (nonatomic, copy, nullable) NSString * packageZipPrefix;

#pragma mark - 时间配置

/**
 配置更新的时间间隔（毫秒），默认为 5 分钟。
 */
@property (nonatomic, assign) NSInteger configUpdateInterval;

/**
 预加载统计的间隔（毫秒），默认为 3 秒。
 */
@property (nonatomic, assign) NSInteger packageAccessInterval;

/**
 预加载执行清理的间隔（毫秒），默认为 5 天。
 */
@property (nonatomic, assign) NSInteger packageRemoveInterval;

/**
 执行异常恢复的间隔（毫秒），默认为 5 天。
 */
@property (nonatomic, assign) NSInteger recoveryInterval;

#pragma mark - 开关配置

/**
 个性化预加载包直接查询更新的个数限制，默认为 10。
 */
@property (nonatomic, assign) NSUInteger customsDirectQueryLimit;

/**
 是否自动注册个性化预加载包，默认为 YES。
 */
@property (nonatomic, assign) BOOL isAutoRegisterApp;

/**
 是否检查淘汰，默认为 YES。
 */
@property (nonatomic, assign) BOOL isCheckCleanup;

/**
 是否开启预加载解 Combo 功能，默认为 YES。
 */
@property (nonatomic, assign) BOOL isOpenCombo;

/**
 预加载单次下载个数限制，默认为 30。
 */
@property (nonatomic, assign) NSInteger packageDownloadLimit;

/**
 预加载本地最多个数限制，默认为 100。
 */
@property (nonatomic, assign) NSUInteger packageMaxAppCount;

/**
 预加载 App 优先级的权重，默认为 0.1。
 */
@property (nonatomic, assign) double packagePriorityWeight;

/**
 是否支持 ZCache App 解密功能，默认为 YES。
 */
@property (nonatomic, assign) BOOL supportAppDecryption;

/**
 预加载的安全校验率，键为 AppName，值为安全校验率（double [0 - 1]）。
 */
@property (nonatomic, copy, nullable) NSDictionary * verifySampleRate;

@end
