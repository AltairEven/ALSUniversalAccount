//
//  AppMonitorBase.h
//  AppMonitor
//
//  Created by junzhan on 14-10-14.
//  Copyright (c) 2014年 君展. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppMonitorBase : NSObject
/**
 *  日志写入UT间隔时间(单位秒).默认300秒, -1代表关闭. 会监听配置中心做变化
 */
+ (void)setWriteLogInterval:(NSInteger)writeLogInterval;

+ (NSInteger)writeLogInterval;

@end
