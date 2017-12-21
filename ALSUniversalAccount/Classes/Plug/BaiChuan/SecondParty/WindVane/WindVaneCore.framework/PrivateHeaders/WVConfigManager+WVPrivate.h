/*
 * WVConfigManager+WVPrivate.h
 *
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVConfigHandler.h>
#import <WindVaneCore/WVConfigManager.h>

/**
 * WindVane 配置管理器的私有接口。
 */
@interface WVConfigManager (WVPrivate)

#pragma mark - Update config

/**
 * 立刻使用指定 URL 更新指定名称的配置，供测试配置使用。
 */
+ (void)updateConfig:(NSString * _Nonnull)configName withURL:(NSString * _Nonnull)url withCallback:(WVConfigUpdateFinishedBlock _Nullable)callback;

/**
 * 重置测试配置为当前最新配置。
 * 供测试配置使用。
 */
+ (void)resetConfig;

#pragma mark - Handler

/**
 * 注册 WindVane 配置 Handler。
 */
+ (void)registerHandler:(id<WVConfigHandler> _Nonnull)handler;

/**
 * 获取具有指定名称的 WindVane 配置 Handler。
 */
+ (id<WVConfigHandler> _Nullable)registeredHandler:(NSString * _Nonnull)configName;

/**
 * 获取已注册的 Handler 及其总控版本。
 */
+ (NSDictionary * _Nonnull)getHandlerVersions;

#pragma mark - 其它

/**
 * 返回应用启动或最近一次从后台切换到前台的时间。
 *
 * @return 返回应用启动或最近一次从后台切换到前台的时间。
 */
+ (NSTimeInterval)foregroundTime;

@end
