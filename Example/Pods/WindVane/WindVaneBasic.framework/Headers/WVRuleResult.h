/*
 * WVRuleResult.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVRuleCoreData.h"
#import <Foundation/Foundation.h>

/**
 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 预计与 2019.1.1 删除
 */

@interface WVRuleResult : NSObject

// 目标
@property NSInteger target DEPRECATED_ATTRIBUTE;
// 参数
@property (copy, nonatomic) NSDictionary * param DEPRECATED_ATTRIBUTE;

@end
