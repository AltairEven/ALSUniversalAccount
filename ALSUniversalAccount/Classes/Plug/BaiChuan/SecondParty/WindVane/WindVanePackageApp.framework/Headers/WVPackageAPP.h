/*
 * WVPackageAPP.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 初始化 WindVane PackageApp 模块。
 * 预加载独立模块包，预加载可以让前端在 AWP 平台将 html、js、css 等资源打包成一个 zip 包，客户端可以采用启动后下载或者直接预置的方式将 zip 包解压到本地，使得用户在浏览网页的时候不需要再去下载资源，提升用户体验。
 */
@interface WVPackageApp : NSObject

/**
 * 初始化 WindVane PackageApp 模块。
 */
+ (void)setup;

#pragma mark - 全局

/**
 * 设置预置名称，默认为 "preload_packageapp.zip"。
 */
+ (void)setPreloadPackageName:(NSString * _Nonnull)packageName;

/**
 * 触发预置包的安装，在用户主动清除磁盘文件后可以主动触发预置包的重新安装。
 * 会同步做很多磁盘 IO 操作，建议在非主线程执行。
 */
+ (void)setupPreloadPackage;

/**
 * 清理所有本地的 Package。
 */
+ (void)cleanApps;

/**
 * 强制所有 App 更新一次。
 */
+ (void)forceUpdate;

/**
 * 强制所有 App 走线上，不走本地（仅本次启动有效）。
 */
+ (void)forceOnline;

/**
 * 注册指定的个性化 App，App 会在之后被安装和更新。
 */
+ (void)registerApp:(NSString * _Nonnull)appName;

/**
 * 返回所有已安装的 App 名称。
 *
 * @return 一个数组，数组里包含所有已安装的 App 名称（包括 PackageApp 和 ZCache）。
 */
+ (NSArray<NSString *> * _Nonnull)intalledApps;

/**
 * 返回预加载所占用的磁盘空间，会同步计算磁盘空间。
 */
+ (u_int64_t)packageSize;

#pragma mark - 本地资源

/**
 * 判断某个 URL 对应资源是否已经安装到本地。
 *
 * @param resourceURL 要检测的 URL。
 *
 * @return 如果已经安装，则为 YES；否则为 NO。如果预加载包为强制更新，且本地资源不是最新的，也会返回 NO。
 */
+ (BOOL)isResourceInstalled:(NSString * _Nonnull)resourceURL;

/**
 * 判断某个 URL 对应资源是否已经安装到本地，并返回文件的 MD5。
 *
 * @param resourceURL 要检测的 URL。
 * @param md5         返回文件的 MD5，如果为 ""，表示 MD5 读取失败，但文件仍然存在，可以自行计算 MD5。
 *
 * @return 如果已经安装，则为 YES；否则为 NO。如果预加载包为强制更新，且本地资源不是最新的，也会返回 NO。
 */
+ (BOOL)isResourceInstalled:(NSString * _Nonnull)resourceURL md5:(NSString * _Nullable * _Nullable)md5;

/**
 * 返回指定 URL 对应的本地资源内容。
 *
 * @param resourceURL 要检测的 URL。
 *
 * @return URL 对应的本地资源内容，如果不存在则为 nil。如果预加载包为强制更新，且本地资源不是最新的，也会返回 nil。
 */
+ (NSData * _Nullable)resourceContentForURL:(NSString * _Nonnull)resourceURL;

/**
 * 返回指定 URL 对应的本地资源内容。
 *
 * @param resourceURL 要检测的 URL。
 * @param header      URL 的自定义 Header。
 * @param error       如果 URL 对应的资源不存在，则返回相关的错误信息。
 *
 * @return URL 对应的本地资源内容，如果不存在则为 nil。如果预加载包为强制更新，且本地资源不是最新的，也会返回 nil。
 */
+ (NSData * _Nullable)resourceContentForURL:(NSString * _Nonnull)resourceURL withHeader:(NSDictionary * _Nullable * _Nullable)header error:(NSError * _Nullable * _Nullable)error;

#pragma mark - 更新监听

/**
 * Package App 更新完毕的监听器。
 *
 * @param appName 更新完毕的 App 名称。
 */
typedef void (^WVPackageUpdateListener)(NSString * _Nonnull appName);

/**
 * 注册指定的 App 更新监听器，在 App 更新成功后自动调用。
 */
+ (void)registerUpdateListener:(WVPackageUpdateListener _Nonnull)listener withAppName:(NSString * _Nonnull)appName;

/**
 * 立刻更新指定应用。
 *
 * @param appName       要更新的应用名称。
 * @param callback      更新完毕的回调。
 * @param progressBlock 更新进度回调。
 *
 * @return 如果指定的 App 存在，则为 YES；若 App 不存在，则返回 NO。
 */
+ (BOOL)updateApp:(NSString * _Nonnull)appName withCallback:(void (^_Nullable)(NSString * _Nonnull appName, NSError * _Nullable error))callback withProgress:(void (^_Nullable)(NSString * _Nonnull appName, double percentage))progressBlock;

#pragma mark - 已废弃，预计于 2018.1.1 删除

+ (void)setPreunzipPackageName:(NSString * _Nonnull)packageName DEPRECATED_MSG_ATTRIBUTE("请使用 [WVPackageApp setPreloadPackageName:] 方法");
+ (NSString * _Nullable)resourcePathForURL:(NSString * _Nonnull)resourceURL DEPRECATED_MSG_ATTRIBUTE("请使用 [WVPackageApp resourceContentForURL:] 方法");
+ (NSString * _Nullable)resourcePathForURL:(NSString * _Nonnull)resourceURL isNewest:(BOOL * _Nullable)isNewest DEPRECATED_MSG_ATTRIBUTE("请使用 [WVPackageApp resourceContentForURL:] 方法");

@end
