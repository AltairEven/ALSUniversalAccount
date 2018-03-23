/*
 * WVCoreMonitorService.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVMonitorProtocol.h>

#pragma mark - WindVane 配置监控

/**
 * 表示 WindVane 配置更新完毕的监控信息。
 */
@interface WVConfigMonitorInfo : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]配置的名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * name;

/**
 * [维度]配置的来源。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * from;

/**
 * [指标]配置的更新时长。
 */
@property (nonatomic, assign, readonly) double updateTime;

/**
 * [指标]配置的更新数量。
 */
@property (nonatomic, assign, readonly) NSUInteger updateCount;

/**
 * [告警]配置的更新失败信息。
 */
@property (nonatomic, strong, readonly, nullable) NSError * error;

/**
 * 使用配置的名称、来源、更新时长、个数和错误信息初始化。
 */
- (instancetype _Nonnull)initWithName:(NSString * _Nonnull)name from:(NSString * _Nonnull)from time:(double)time count:(NSUInteger)count error:(NSError * _Nullable)error;

@end

/**
 * 表示需要监控 WindVane 配置更新情况时可以选择实现的方法。
 */
@protocol WVConfigMonitorProtocol <NSObject>

@required

/**
 * 在配置更新完毕时调用。
 *
 * @param info 监控信息。
 */
- (void)configUpdateFinished:(WVConfigMonitorInfo * _Nonnull)info;

@end

#pragma mark - 注册监控

@interface WVCoreMonitorService : NSObject

/**
 * 注册一个配置监控 Protocol。
 */
+ (void)registerConfigMonitorHandler:(id<WVConfigMonitorProtocol> _Nonnull)handler;

/**
 * 返回已注册的配置监控 Protocol。
 */
+ (id<WVConfigMonitorProtocol> _Nullable)registeredConfigMonitorHandler;

@end
