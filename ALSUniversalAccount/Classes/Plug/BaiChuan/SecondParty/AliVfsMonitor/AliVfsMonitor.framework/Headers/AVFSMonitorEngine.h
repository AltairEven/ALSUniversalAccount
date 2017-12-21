//
//  AVFSMonitorEngine.h
//  AliVfsMonitor
//
//  Created by huangjy on 16/3/1.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import "AVFSMonitorConstant.h"

@interface AVFSMonitorEngine : NSObject

/**
 *  初始化
 */
+ (void)setup;

/**
 * 通知模块配置变更
 * @param config    :   配置信息
 **/
+ (void)notifyConfig:(NSDictionary *)config;

/**
 * 命令处理函数
 **/
+ (void)resolverCommands:(NSDictionary *)commands;

/**
 * 开启定时任务
 **/
+ (void)startCronTask;

@end
