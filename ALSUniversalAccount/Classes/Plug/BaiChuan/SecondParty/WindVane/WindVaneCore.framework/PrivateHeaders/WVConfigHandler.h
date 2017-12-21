/*
 * WVConfigHandler.h
 *
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVUserConfig.h>

@protocol WVConfigHandler;

/**
 * WindVane 配置更新完毕的回调。
 */
typedef void (^WVConfigUpdateFinishedBlock)(id<WVConfigHandler> _Nonnull handler, NSUInteger updateCount, NSError * _Nullable error);

/**
 * WindVane 配置 Handler。
 */
@protocol WVConfigHandler <NSObject>

@required

/**
 * 返回当前配置的名称。
 */
- (NSString * _Nonnull)configName;

/**
 * 返回当前配置的版本，格式为 version[.target]。
 */
- (NSString * _Nullable)configVersion;

/**
 * 返回当前配置的环境。
 */
- (WVEnvironment)configEnv;

/**
 * 使用指定的下一版本号更新配置。
 *
 * @param nextVersion 总控中给出的当前配置下一版本号，nil 表示下一版本号未知。
 * @param callback    更新完毕的回调。
 */
- (void)updateWithNextVersion:(NSString * _Nullable)nextVersion withCallback:(WVConfigUpdateFinishedBlock _Nullable)callback;

/**
 * 从指定的 URL 更新配置。
 *
 * @param url 配置的 URL。
 * @param callback 更新完毕的回调。
 */
- (void)updateWithURL:(NSString * _Nonnull)url withCallback:(WVConfigUpdateFinishedBlock _Nullable)callback;

/**
 * 重置当前配置到默认状态。
 */
- (void)reset;

@end
