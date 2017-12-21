/*
 * WVConfigManager.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "WVCommonConfigModel.h"
#import "WVDomainConfigModel.h"

/**
 * WindVane 配置管理器。
 */
@interface WVConfigManager : NSObject

// 临时开关
+ (void)setUseTimer:(BOOL)useTimer;

#pragma mark- Update config

/**
 * 更新配置，如果未达到更新配置的时间间隔，则不会更新配置。
 */
+ (void)update;

/**
 * 立刻更新指定名称的配置。
 */
+ (void)updateConfig:(NSString *)configName version:(NSString *)version;

/**
 * 使用指定的消息更新配置。
 *
 * @param message AWP 平台提供的配置消息。
 */
+ (void)updateWithMessage:(NSString *)message;

#pragma mark- Config

/**
 * 获取 WindVane 公共配置，从服务端拉取的新配置会覆盖默认公共配置。
 */
+ (WVCommonConfigModel *)commonConfig;

/**
 * 获取 WindVane 默认公共配置。
 */
+ (WVCommonConfigModel *)defaultCommonConfig;

/**
 * 获取 WindVane 域名配置，从服务端拉取的新配置会覆盖默认域名配置。
 */
+ (WVDomainConfigModel *)domainConfig;

/**
 * 获取 WindVane 默认域名配置。
 */
+ (WVDomainConfigModel *)defaultDomainConfig;

@end
