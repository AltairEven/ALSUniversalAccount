/*
 * WVBasicUserConfig.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVUserConfig.h"

// WVBasicUserConfig 已与 WVUserConfig 合并，请直接使用 WVUserConfig 类，这里的方法会逐渐废弃掉。
@interface WVBasicUserConfig : NSObject

#pragma mark - 设置方法

+ (void)setAppKey:(NSString *)appKey;
+ (void)setAppName:(NSString *)appName;
+ (void)setAppVersion:(NSString *)appVersion;
+ (void)setEnvironment:(WVEnvironment)environment;
+ (void)setDebugMode:(BOOL)isDebugMode;
+ (BOOL)isDebugMode;
+ (void)openWindVaneLog;
+ (void)setLogLevel:(WVLogLevel)logLevel;
+ (void)setAppUA:(NSString *)appUA;
+ (void)setDefaultParamForFirstLoad:(NSString *)defaultParam;
+ (void)setConfigAutoUpdate:(BOOL)autoUpdate;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (NSString *)appKey DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (BOOL)isValidAppKey DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (NSString *)appName DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (NSString *)appVersion DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (WVEnvironment)environment DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (WVLogLevel)logLevel DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (NSString *)appUA DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (BOOL)configAutoUpdate DEPRECATED_MSG_ATTRIBUTE("请使用 WVUserConfig 类的同名方法");
+ (NSString *)getDefaultParamForFistLoad DEPRECATED_MSG_ATTRIBUTE("请使用 [WVUserConfig defaultParamForFistLoad]");
+ (BOOL)isOpenWindVaneLog DEPRECATED_MSG_ATTRIBUTE("请自行判断 [WVUserConfig logLevel]");
// 已废弃，请使用 [WVConfigManager defaultDomainConfig] 来获取默认域名配置。
+ (void)setSecurityDomainPattern:(NSString *)pattern DEPRECATED_ATTRIBUTE;
// 已废弃，请使用 [WVConfigManager defaultDomainConfig] 来获取默认域名配置。
+ (NSString *)securityDomainPattern DEPRECATED_ATTRIBUTE;
// 已废弃，请使用 [WVConfigManager defaultCommonConfig] 来获取默认公共配置。
+ (NSString *)defaultUrlScheme DEPRECATED_ATTRIBUTE;
// 已废弃，请使用 [WVConfigManager defaultCommonConfig] 来获取默认公共配置。
+ (void)setDefaultUrlScheme:(NSString *)scheme DEPRECATED_ATTRIBUTE;
+ (void)useDefaultURLCacheRule DEPRECATED_ATTRIBUTE;
+ (BOOL)isUseDefaultURLCacheRule DEPRECATED_ATTRIBUTE;
+ (void)setDefaultURLCacheRule:(NSString *)urlCacheRule DEPRECATED_ATTRIBUTE;
+ (NSString *)getDefaultURLCacheRule DEPRECATED_ATTRIBUTE;

@end
