/*
 * WVURLInterceptorRuleEngine.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 预计与 2019.1.1 删除
 */
DEPRECATED_ATTRIBUTE
@interface WVURLInterceptorRuleEngine : NSObject

/*!
 * 单例
 */
+ (instancetype)instance DEPRECATED_ATTRIBUTE;

/*!
 * 初始化
 */
- (void)initRuleEngine DEPRECATED_ATTRIBUTE;

/*!
 * 更新
 */
- (void)updateRuleEngine DEPRECATED_ATTRIBUTE;

/*!
 * 开关
 */
- (BOOL)isOpenURLInterceptor DEPRECATED_ATTRIBUTE;

/**
 * 现有规则。
 */
- (NSArray *)rule DEPRECATED_ATTRIBUTE;

/*!
 * 将 WindVane 可接受的拦截规则内存运行格式 转换为  URL 拦截规则数组
 */
+ (NSArray *)convertURLInterceptorRuleFromDictionaryToArray:(NSDictionary *)ruleContentDic DEPRECATED_ATTRIBUTE;

@end
