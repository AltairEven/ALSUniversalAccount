/*
 * WVCore.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 初始化 WindVane Core 模块。
 * WindVane 核心库，定义了模块间的接口和约束，以及公共工具类，所有模块都必须依赖它。
 */
@interface WVCore : NSObject

/**
 * 初始化 WindVane Core 模块。
 * 无需主动调用，会被 WindVaneBasic 或 WindVanePackageApp 模块自动初始化。
 */
+ (void)setup;

/**
 * WindVane 的初始化时间。
 */
+ (NSTimeInterval)initTime;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (void)init DEPRECATED_MSG_ATTRIBUTE("init 会与 Swift 关键词冲突，因此改用 setup 方法");
+ (void)doNotFixIOS7ProtocolBug DEPRECATED_MSG_ATTRIBUTE("WindVane 不再支持 iOS7 以下的系统，无需再做 Protocol BUG 修复");

@end
