/*
 * WVPackageMonitorService.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WindVaneCorePrivate.h>

#pragma mark - 主线监控

/**
 * 表示预加载下载队列的监控信息。
 */
@interface WVPackageQueueMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [指标]清理任务个数。
 */
@property (nonatomic, assign, readonly) NSUInteger cleanCount;

/**
 * [指标]清理成功任务个数。
 */
@property (nonatomic, assign, readonly) NSUInteger successCleanCount;

/**
 * [指标]删除任务个数。
 */
@property (nonatomic, assign, readonly) NSUInteger deleteCount;

/**
 * [指标]删除成功任务个数。
 */
@property (nonatomic, assign, readonly) NSUInteger successDeleteCount;

/**
 * [指标]预加载 App 更新次数。
 */
@property (nonatomic, assign, readonly) NSUInteger updateCount;

/**
 * [指标]预加载 App 更新成功次数。
 */
@property (nonatomic, assign, readonly) NSUInteger successCount;

/**
 * 累加清理次数。
 */
- (void)accumulateClean:(BOOL)isSuccess;

/**
 * 累加删除次数。
 */
- (void)accumulateDelete:(BOOL)isSuccess;

/**
 * 累加更新次数。
 */
- (void)accumulateUpdate:(BOOL)isSuccess;

/**
 * 重置更新次数。
 */
- (void)reset;

@end

/**
 * 表示预加载 App 更新的监控信息。
 */
@interface WVPackageAppMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]App 的名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * appName;

/**
 * [维度]App 的版本。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * version;

/**
 * [维度]App 的 SEQ。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * seq;

/**
 * [维度]App 是否支持发布时长。
 */
@property (nonatomic, assign, readonly) BOOL hasPublishTime;

/**
 * [维度]App 更新时是否在线。
 */
@property (nonatomic, assign) BOOL online;

/**
 * [维度]App 更新时网络是否支持。
 */
@property (nonatomic, assign) BOOL networkSupport;

/**
 * [维度]是否是增量更新。
 */
@property (nonatomic, assign) BOOL isIncr;

/**
 * [指标]App 下载时长。
 */
@property (nonatomic, assign) double downloadTime;

/**
 * [指标]App 解压时长。
 */
@property (nonatomic, assign) double unzipTime;

/**
 * [指标]App 校验时长。
 */
@property (nonatomic, assign) double verifyTime;

/**
 * [指标]App 读写磁盘时长。
 */
@property (nonatomic, assign) double diskTime;

/**
 * [指标]App 更新时长。
 */
@property (nonatomic, assign) double updateTime;

/**
 * [指标]服务端发布到客户端收到更新消息时长。
 */
@property (nonatomic, assign) double notificationTime;

/**
 * [指标]服务端发布到安装完毕时长。
 */
@property (nonatomic, assign) double publishTime;

/**
 * [告警]预加载 App 的访问失败信息。
 */
@property (nonatomic, strong, nullable) NSError * error;

/**
 * 使用 App 的名称、版本和 SEQ 初始化。
 */
- (instancetype _Nonnull)initWithAppName:(NSString * _Nonnull)name withVersion:(NSString * _Nonnull)version withSeq:(u_int64_t)seq;

@end

/**
 * 预加载访问监控信息。
 */
@interface WVPackageVisitMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]预加载 App 名称。
 */
@property (nonatomic, copy, nonnull) NSString * pkgName;

/**
 * [维度]是否读取了 app-res.wvc 文件。
 */
@property (nonatomic, assign, readonly) BOOL hasReadAppResTime;

/**
 * [维度]是否包含校验耗时。
 */
@property (nonatomic, assign, readonly) BOOL hasVerifyTime;

/**
 * [指标]预加载 App 访问耗时。
 */
@property (nonatomic, assign) double time;

/**
 * [指标]预加载 App 命中耗时。
 */
@property (nonatomic, assign) double matchTime;

/**
 * [指标]预加载 App 读取本地文件耗时。
 */
@property (nonatomic, assign) double readTime;

/**
 * [指标]预加载 App 读取 app-res.wvc 文件耗时。
 */
@property (nonatomic, assign) double readAppResTime;

/**
 * [指标]预加载 App 校验耗时。
 */
@property (nonatomic, assign) double verifyTime;

@end

#pragma mark - 支线监控

/**
 * 表示预加载资源校验缓存的监控信息。
 */
@interface WVPackageVerifyCacheMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 * [指标]校验缓存的最大大小。
 */
@property (nonatomic, assign) NSInteger maxCacheSize;

/**
 * [指标]校验缓存的大小总和。
 */
@property (nonatomic, assign) NSInteger sumCacheSize;

/**
 * 使用校验缓存的最大大小和总和初始化。
 */
- (instancetype _Nonnull)initWithMaxSize:(NSInteger)maxSize sumSize:(NSInteger)sumSize;

@end

/**
 * 表示预加载 App 首次下载的性能监控信息。
 */
@interface WVPackageUpdateStartMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [指标]App 开始下载时间。
 */
@property (nonatomic, assign) double startTime;

/**
 * [指标]App 安装结束时间。
 */
@property (nonatomic, assign) double endTime;

/**
 * 使用开始和结束时间初始化。
 */
- (instancetype _Nonnull)initWithStart:(double)startTime end:(double)endTime;

@end

#pragma mark - 预加载访问监控

/**
 * 预加载首次命中耗时。
 */
@interface WVPackageVisitStartMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]预加载 App 名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * pkgName;

/**
 * [指标]预加载 App 访问距启动时长。
 */
@property (nonatomic, assign, readonly) double time;

/**
 * 使用指定的 AppName 和时长初始化。
 */
- (instancetype _Nonnull)initWithAppName:(NSString * _Nonnull)appName time:(double)time;

@end

#pragma mark - 预加载淘汰监控

/**
 * 表示预加载淘汰算法的监控信息。
 */
@interface WVPackageCleanUpMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]清理的原因。到达清理的周期触发的，为 0；p>=9 的 App 需要安装导致的，为 1。
 */
@property (nonatomic, copy, nonnull) NSString * cleanCause;

/**
 * [维度]理论安装数。
 */
@property (nonatomic, copy, nonnull) NSString * expectedApps;

/**
 * [指标]清理前的剩余磁盘空间（MB）。
 */
@property (nonatomic, assign) NSUInteger freeDiskSpace;

/**
 * [指标]清理前的已安装 App 数。
 */
@property (nonatomic, assign) NSUInteger installedApps;

/**
 * [指标]要删除到的目标 App 个数。
 */
@property (nonatomic, assign) NSUInteger targetApps;

/**
 * [指标]被保留 App 的命中次数。
 */
@property (nonatomic, assign) double accessCount;

/**
 * [指标]被访问过的 App 个数。
 */
@property (nonatomic, assign) NSUInteger accessedAppCount;

/**
 * [指标]被清理 App 的命中次数。
 */
@property (nonatomic, assign) double ignoredAccessCount;

@end

#pragma mark - 预加载恢复监控

/**
 * 表示预加载异常恢复的性能监控信息。
 */
@interface WVPackageRecoveryMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [指标]重装的 App 个数。
 */
@property (nonatomic, assign, readonly) NSUInteger reinstallCount;

/**
 * [指标]清理遗留文件 App 个数。
 */
@property (nonatomic, assign, readonly) NSUInteger cleanCount;

/**
 * 使用重装和清理的 App 个数初始化。
 */
- (instancetype _Nonnull)initWithReinstall:(NSUInteger)reinstallCount clean:(NSUInteger)cleanCount;

@end

/**
 * 表示需要监控预加载情况时可以选择实现的方法。
 */
@protocol WVPackageMonitorProtocol <NSObject>

@required

#pragma mark 主线监控

/**
 * 在预加载下载队列完成一次更新时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)packageQueueFinished:(WVPackageQueueMonitorStat * _Nonnull)stat;

/**
 * 在预加载 App 更新完毕时调用。
 *
 * @param info 监控信息。
 */
- (void)packageUpdateFinished:(WVPackageAppMonitorInfo * _Nonnull)info;

/**
 * 在预加载资源被访问时调用。
 *
 * @param info 监控信息。
 */
- (void)packageAppVisit:(WVPackageVisitMonitorInfo * _Nonnull)info;

/**
 * 在预加载资源访问成功或失败时调用。
 *
 * @param pkgName 预加载资源名称。
 * @param seq     预加载资源 seq。
 * @param error   预加载资源加载错误信息。
 */
- (void)packageAppVisit:(NSString * _Nonnull)pkgName withSep:(u_int64_t)seq withError:(NSError * _Nullable)error;

/**
 * 在预加载资源警告时调用。
 *
 * @param pkgName 预加载名称。
 * @param error   预加载警告信息。
 */
- (void)packageWarning:(NSString * _Nonnull)pkgName withError:(NSError * _Nullable)error;

#pragma mark 支线监控

/**
 * 在提取预加载校验缓存信息时调用。
 *
 * @param info 监控信息。
 */
- (void)packageVerifyCache:(WVPackageVerifyCacheMonitorInfo * _Nonnull)info;

/**
 * 在预加载 App 首次更新完毕时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)packageUpdateStart:(WVPackageUpdateStartMonitorStat * _Nonnull)stat;

/**
 * 在预加载资源首次访问时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)packageVisitStart:(WVPackageVisitStartMonitorStat * _Nonnull)stat;

/**
 * 在完成一次预加载淘汰时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)packageCleanUp:(WVPackageCleanUpMonitorInfo * _Nonnull)stat;

/**
 * 完成一次预加载异常恢复时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)packageRecovery:(WVPackageRecoveryMonitorStat * _Nonnull)stat;

@end

#pragma mark - 注册监控

/**
 * WindVanePackageApp 模块的监控服务。
 */
@interface WVPackageMonitorService : NSObject

/**
 * 注册一个预加载监控 Protocol。
 */
+ (void)registerPackageMonitorHandler:(id<WVPackageMonitorProtocol> _Nonnull)handler;

/**
 * 返回已注册的预加载监控 Protocol。
 */
+ (id<WVPackageMonitorProtocol> _Nullable)registeredPackageMonitorHandler;

@end
