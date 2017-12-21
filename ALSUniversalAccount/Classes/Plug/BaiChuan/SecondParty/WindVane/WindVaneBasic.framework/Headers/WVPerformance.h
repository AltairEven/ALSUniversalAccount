/*
 * WVPerformance.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface WVPerformance : NSObject

/**
 * 当前的 CPU 使用率。
 */
+ (float)cpuUsage;

/**
 * 当前的内存使用率。
 */
+ (float)memoryUsage;

/**
 * 当前的总内存大小（byte）。
 */
+ (uint64_t)totalMemory;

/**
 * 当前已使用的内存大小（byte）。
 */
+ (uint64_t)usedMemory;

/**
 * 更新系统性能数据。
 */
+ (void)update;

@end
