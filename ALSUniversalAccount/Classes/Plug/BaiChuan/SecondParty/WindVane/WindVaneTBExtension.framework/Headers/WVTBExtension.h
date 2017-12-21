/*
 * WVTBExtension.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 初始化 WindVane TBExtension 模块。
 * 基于阿里系服务的默认扩展包，目前 TBExtension 包含的服务有：
 *   基于 ARUP 的照片上传接口。
 *   预加载的 Orange 推送接口。
 *   手淘下载库接口。
 *   WindVane 日志输出到 TLog。
 *   通过 TBCrashReporter 上报 Crash 相关 URL。
 *   A/B Test 接口。
 */
@interface WVTBExtension : NSObject

/**
 * 初始化 WindVane TBExtension 模块。
 */
+ (void)setup;

@end
