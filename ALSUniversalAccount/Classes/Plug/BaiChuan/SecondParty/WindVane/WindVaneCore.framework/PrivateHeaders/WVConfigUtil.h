//
//  WVConfigUtil.h
//  WindVaneCore
//
//  Created by lianyu.ysj on 15/9/2.
//  Copyright (c) 2015年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVDownloadTask.h>

// WindVane 配置类型。
typedef NS_ENUM(NSInteger, WVConfigType) {
	WVConfigTypeEntry = 0,         // 总控配置。
	WVConfigTypeCommon = 1,        // 公共配置。
	WVConfigTypeDomain = 2,        // 安全域名配置。
	WVConfigTypeMonitor = 3,       // 监控配置。
	WVConfigTypeOldPackageApp = 4, // 旧版的 PackageApp 配置，不再使用。
	WVConfigTypePackageApp = 5,    // PackageApp 配置。
	WVConfigTypeCustoms = 6,       // 个性化 PackageApp 配置。
	WVConfigTypePrefixes = 7,      // PackageApp 前缀配置。
	WVConfigTypeOldURLRule = 9,    // 旧的 URL 拦截配置，不再使用。
};

/**
 * WindVane 配置的实用程序。
 */
@interface WVConfigUtil : NSObject

/**
 * 比较当前配置版本号与原始版本号。
 *
 * @return 若当前版本号高于原始版本号，则为 YES；否则为 NO。
 */
+ (BOOL)compareVersion:(NSString * _Nullable)version withOriginal:(NSString * _Nullable)origVersion ignoreTarget:(BOOL)ignoreTarget;

/**
 * 返回指定版本号与前一版本号的时间间隔。
 *
 * @param version     要比较的版本号。
 * @param lastVersion 前一版本号。
 */
+ (NSTimeInterval)getVersionInteval:(NSString * _Nullable)version withLastVersion:(NSString * _Nullable)lastVersion;

#pragma mark - File Operation

/**
 * 读取指定配置文件的内容。
 */
+ (NSDictionary * _Nullable)readConfigFile:(NSString * _Nonnull)configName;

/**
 * 写入指定配置文件的内容。
 */
+ (void)writeConfigFile:(NSString * _Nonnull)configName dict:(NSDictionary * _Nullable)dict;

#pragma mark - Download Config

/**
 * 返回当前环境对应的 https://h5.(m|wapa|waptest).taobao.com/path URL。
 */
+ (NSString * _Nonnull)configURLWithPath:(NSString * _Nullable)path;

/**
 * 返回指定的配置文件类型、version 和 nextVersion 的配置 URL。
 *
 * @param configType  配置类型，必须是 Entry、Common、Domain、Monitor 或 PackageApp 之一。
 * @param version     当前配置版本。
 * @param nextVersion 下一配置版本。
 */
+ (NSString * _Nonnull)getConfigURL:(WVConfigType)configType withVersion:(NSString * _Nullable)version withNextVersion:(NSString * _Nullable)nextVersion;

/**
 * 获取配置的 target（灰度）。
 */
+ (NSString * _Nonnull)getConfigTarget;

/**
 * 下载指定的配置文件。
 */
+ (void)downloadConfig:(NSString * _Nonnull)url withConfigName:(NSString * _Nonnull)configName withCallback:(void (^_Nonnull)(NSDictionary * _Nullable, NSError * _Nullable))callback inQueue:(dispatch_queue_t _Nullable)queue;

@end
