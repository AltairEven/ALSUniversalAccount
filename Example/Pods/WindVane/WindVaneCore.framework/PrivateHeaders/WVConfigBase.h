//
//  WVConfigBase.h
//  WindVaneCore
//
//  Created by lianyu.ysj on 15/7/9.
//  Copyright (c) 2015年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVConfigHandler.h>
#import <WindVaneCore/WVConfigModel.h>
#import <WindVaneCore/WVConfigUtil.h>

/**
 * WindVane 配置解析完毕的回调。
 */
typedef void (^WVConfigParseFinishedBlock)(WVConfigModel * _Nullable config, NSUInteger updateCount, NSError * _Nullable error);

/**
 * WindVane 配置的基类。
 */
@interface WVConfigBase <ConfigType : WVConfigModel *> : NSObject<WVConfigHandler>

/**
 * 默认配置。
 */
@property (nonatomic, strong, readonly, nonnull) ConfigType defaultConfig;

/**
 * 当前配置，设置为 atomic 防止更新时出现多线程野指针。
 */
@property (atomic, strong, nonnull) ConfigType config;

#pragma mark - Initialize config

/**
 * 使用指定的配置名称和类型初始化 WVConfigBase 类的新实例。
 */
- (instancetype _Nonnull)initWithConfigName:(NSString * _Nonnull)configName withClass:(Class _Nonnull)configClass withType:(WVConfigType)configType;

/**
 * 初始化配置。
 */
- (void)setupConfig;

#pragma mark - Update config

/**
 * 返回是否允许更新配置，允许由子类重写以自定义开关。
 */
- (BOOL)canUpdateConfig;

/**
 * 从指定的 JSON 数据中解析得到配置，如果不需要更新则返回 nil。
 * 允许由子类重写以自定义配置解析逻辑。
 */
- (void)getConfigFromJSON:(NSDictionary * _Nonnull)jsonData withCallback:(WVConfigParseFinishedBlock _Nonnull)callback;

/**
 * 指定的配置更新完毕，保存配置并发送事件。
 *
 * @param config 更新完毕的配置。
 */
- (void)configUpdateFinished:(WVConfigModel * _Nullable)config;

/**
 * 在配置被更新后调用。
 * 允许由子类重写以执行额外操作。
 *
 * @param isSetup 是否是首次安装。
 */
- (void)configUpdated:(BOOL)isSetup;

/**
 * 读取当前配置文件的内容。
 * 允许由子类重写以读取自定义路径。
 */
- (NSDictionary * _Nullable)readConfigFile;

/**
 * 写入当前配置文件的内容。
 * 允许由子类重写以写入自定义路径。
 */
- (void)writeConfigFile:(NSDictionary * _Nonnull)dict;

@end
