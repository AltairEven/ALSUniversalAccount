//
//  AppMonitorOffLineCounter.h
//  AppMonitor
//
//  Created by junzhan on 14-10-14.
//  Copyright (c) 2014年 君展. All rights reserved.
//

#import "AppMonitorCounter.h"

@interface AppMonitorOffLineCounter : AppMonitorCounter

/**
 *  离线计数接口.（每次commit会累加一次count，value也会累加）可用于服务端离线计算数据量较大的总次数或求平均值
 *
 *  @param page         操作发生所在的页面
 *  @param monitorPoint 监控点名称
 *  @param value        数值
 */
+ (void)commitWithPage:(NSString *)page monitorPoint:(NSString *)monitorPoint value:(double)value;

@end
