/*
 * WVConfigModel.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVModelObject.h"
#import "WVUserConfig.h"
#import <Foundation/Foundation.h>

// 配置的版本字段名。
FOUNDATION_EXTERN NSString * _Nonnull const WVConfigModelVersionKey;
// 配置的版本字段的默认值。
FOUNDATION_EXTERN NSString * _Nonnull const WVConfigModelDefaultVersion;

/**
 * WindVane 配置模型的基类。
 */
@interface WVConfigModel : WVModelObject

/**
 * 配置的版本。
 */
@property (nonatomic, copy, readonly, nullable) NSString * version;

/**
 * 配置的环境。
 */
@property (nonatomic, assign, readonly) WVEnvironment env;

/**
 * 使用指定的配置版本和类型初始化。
 *
 * @pram version 用于初始化的配置版本。
 */
- (instancetype _Nonnull)initWithVersion:(NSString * _Nullable)version;

@end
