/*
 ZCache.h
 
 Created by WindVane.
 Copyright (c) 2018年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "NSObject+ZCKVO.h"
#import "ZCacheCommonConfig.h"
#import "ZCacheConfig.h"
#import "ZCOperation.h"
#import <Foundation/Foundation.h>

/**
 ZCache SDK 的版本。
 */
#define ZCACHE_VERSION @"10.0.3"

/**
 预加载环境设置。
 */
typedef NS_ENUM(NSUInteger, ZCEnvironment) {
	ZCEnvironmentDebug = 0,  // 预发环境。
	ZCEnvironmentDaily = 1,  // 日常环境。
	ZCEnvironmentRelease = 2 // 线上环境。
};

/**
 预加载功能设置，使用不同标识位区分不同的功能。
 */
typedef NS_OPTIONS(NSInteger, ZCacheStatus) {
	ZCacheStatusHitAll = 3,            // 允许命中预加载资源。
	ZCacheStatusHitMask = 0x3,         // 预加载的资源命中掩码。
	ZCacheStatusUpdateConfig = 1 << 2, // 允许更新预加载配置。
	ZCacheStatusConfigMask = 0x4,      // 预加载的配置更新掩码。
	ZCacheStatusDownloadZip = 1 << 3,  // 允许下载预加载资源包。
	ZCacheStatusZipMask = 0x8,         // 预加载的 ZIP 下载掩码。
	ZCacheStatusAllEnabled = 0xF,     // 开启全部预加载功能。
};

/**
 包含了预加载的相关接口。
 预加载可以让前端在 AWP/EMAX 平台将 html、js、css、Weex JS 等资源打包成一个 zip 包，客户端可以采用启动后下载或者直接预置的方式将 zip 包解压到本地，使得用户在浏览时不需要再去下载资源，提升用户体验。
 */
@interface ZCache : NSObject

/**
 初始化预加载功能，会通过 HTTP 接口请求预加载配置，请务必与服务端做好确认。
 
 @param appKey     客户端的 AppKey，是一串数字，可以在应用中心 http://mappcenter.alibaba-inc.com/ 申请。
 @param appVersion 客户端的版本号。
 */
+ (void)setupWithAppKey:(NSString * _Nonnull)appKey appVersion:(NSString * _Nonnull)appVersion;

/**
 初始化预加载功能，会通过 Mtop 接口请求预加载配置，请务必与服务端做好确认。
 */
+ (void)setupWithMtop;

/**
 设置预加载环境类型，请与客户端当前环境保持一致。
 */
+ (void)setEnvironment:(ZCEnvironment)environment;

/**
 获取预加载环境类型，默认为线上环境。
 */
+ (ZCEnvironment)environment;

#pragma mark - 调试配置，建议在 DEBUG 模式下打开

/**
 设置是否为调试模式，会开启额外的日志、检查和提示。
 */
+ (void)setDebugMode:(BOOL)isDebugMode;

/**
 获取是否为调试模式，默认为 NO。
 */
+ (BOOL)isDebugMode;

#pragma mark - 高级配置

/**
 设置预加载的功能状态。
 */
+ (void)setStatus:(ZCacheStatus)status;

/**
 获取是否预加载的功能状态，默认为 ZCacheStatusAllEnabled。
 */
+ (ZCacheStatus)status;

/**
 设置预加载的 HTTP 配置接口基础 URL，需要与服务端保持一致。
 */
+ (void)setConfigBaseURL:(NSString * _Nonnull)baseURL;

/**
 获取预加载的 HTTP 配置接口基础 URL。
 */
+ (NSString * _Nonnull)configBaseURL;

/**
 设置预加载的语言。
 */
+ (void)setLocale:(NSString * _Nullable)locale;

/**
 获取预加载的语言，默认为 nil。
 */
+ (NSString * _Nullable)locale;

/**
 获取预加载的默认公共配置，可以根据需要调整。
 */
+ (ZCacheCommonConfig * _Nonnull)defaultCommonConfig;

/**
 接收到服务端的配置推送消息，需要与服务端配合使用。
 */
+ (void)receiveConfigPushMessage:(NSString * _Nonnull)message;

#pragma mark - 预置包

/**
 设置预置包的文件名称。
 */
+ (void)setPreloadFileName:(NSString * _Nonnull)fileName;

/**
 触发预置包的安装，在用户主动清除磁盘文件后可以主动触发预置包的重新安装。
 会同步做很多磁盘 IO 操作，建议在非主线程执行。
 */
+ (void)installPreload;

#pragma mark - 预加载功能

/**
 清理所有预加载文件。
 */
+ (void)clean;

/**
 触发预加载的更新。
 */
+ (void)update;

/**
 返回预加载所占用的磁盘空间，会同步计算磁盘空间。
 */
+ (unsigned long long)diskSize;

/**
 注册指定的个性化 App，App 会在之后被安装和更新。
 */
+ (void)registerApp:(NSString * _Nonnull)appName;

#pragma mark - 更新

/**
 预加载 App 更新完毕的监听器。
 
 @param appName 更新完毕的 App 名称。
 */
typedef void (^ZCacheAppUpdateListener)(NSString * _Nonnull appName);

/**
 注册指定的预加载 App 更新监听器，在 App 更新成功后自动调用。
 */
+ (void)registerUpdateListener:(ZCacheAppUpdateListener _Nonnull)listener withAppName:(NSString * _Nonnull)appName;

/**
 立刻更新指定 ZCache App。
 
 @param appName 要更新的应用名称。
 
 @return 如果指定的 App 存在，则为返回更新 App 的 ZCOperation *；若 App 不存在，则返回 nil。
 */
+ (ZCOperation * _Nullable)updateApp:(NSString * _Nonnull)appName;

#pragma mark - 预加载资源

/**
 返回所有已安装的预加载 App 名称。
 
 @return 一个数组，数组里包含所有已安装的预加载 App 名称。
 */
+ (NSArray<NSString *> * _Nonnull)installedApps;

/**
 返回某个 URL 对应资源是否已经安装到本地。

 @param url 要检测的 URL。

 @return 如果已经安装，则为 YES；否则为 NO。如果预加载包为强制更新，且本地资源不是最新的，也会返回 NO。
 */
+ (BOOL)isResourceInstalled:(NSString * _Nonnull)url;

/**
 返回某个 URL 对应资源是否已经安装到本地，并给出文件的 MD5。

 @param url 要检测的 URL。
 @param md5 返回文件的 MD5，如果为 ""，表示 MD5 读取失败，但文件仍然存在，可以自行计算 MD5。

 @return 如果已经安装，则为 YES；否则为 NO。如果预加载包为强制更新，且本地资源不是最新的，也会返回 NO。
 */
+ (BOOL)isResourceInstalled:(NSString * _Nonnull)url md5:(NSString * _Nullable * _Nullable)md5;

/**
 返回指定 URL 对应的本地资源内容。

 @param url 要检测的 URL。

 @return URL 对应的本地资源内容，如果不存在则为 nil。如果预加载包为强制更新，且本地资源不是最新的，也会返回 nil。
 */
+ (NSData * _Nullable)resourceContentForURL:(NSString * _Nonnull)url;

/**
 返回指定 URL 对应的本地资源内容。

 @param url    要检测的 URL。
 @param header URL 的自定义 Header。
 @param error  如果 URL 对应的资源不存在，则返回相关的错误信息。

 @return URL 对应的本地资源内容，如果不存在则为 nil。如果预加载包为强制更新，且本地资源不是最新的，也会返回 nil。
 */
+ (NSData * _Nullable)resourceContentForURL:(NSString * _Nonnull)url withHeader:(NSDictionary * _Nullable * _Nullable)header error:(NSError * _Nullable * _Nullable)error;

@end
