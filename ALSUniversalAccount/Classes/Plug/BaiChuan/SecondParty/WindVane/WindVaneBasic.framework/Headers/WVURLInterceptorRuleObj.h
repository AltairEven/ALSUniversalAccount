/*
 * WVURLInterceptorRuleObj.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVURLInterceptorRuleConstantDefine.h"
#import <Foundation/Foundation.h>

/**
 * 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - enum

/*!
 * 请求的参数解析方式，正则匹配 or 参数提取
 */
typedef NS_ENUM(int, WVRuleParamFetchType) {
	T_IR_REG = WVURLInterceptorRuleTypeValuePattern,  // 正则表达式方式提取
	T_IR_PARAM = WVURLInterceptorRuleTypeValueRequest // 参数中提取方式
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - WVURLInterceptorRuleParamObj

/*!
 * URL 拦截规则请求参数提取方式设置对象
 */
@interface WVURLInterceptorRuleParamObj : NSObject

/*
 * 该参数在 URL 拦截规则通过正则匹配到的参数数组中的下标值
 */
@property (nonatomic, assign) int indexInParamArray;

/*
 * 该参数在 URL 请求中的参数名
 */
@property (nonatomic, copy) NSString * nameInRequest;

/*
 * 该参数提供给URL 拦截后 Native 业务模块使用的标准名称
 */
@property (nonatomic, copy) NSString * standardName;

@end

//////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - WVURLInterceptorRuleObj

/*!
 * URL 拦截规则对象
 */
@interface WVURLInterceptorRuleObj : NSObject

/*
 * URL 拦截规则正则表达式
 */
@property (nonatomic, strong) NSRegularExpression * pattern;

/*
 * URL 拦截规则匹配的目标业务代码
 */
@property (nonatomic, assign) int target;

/*
 * URL 拦截规则参数提取类型
 */
@property (nonatomic, assign) WVRuleParamFetchType ruleType;

/*
 * URL 拦截规则正则表达式能匹配到的截取片段的最小个数
 */
@property (nonatomic, assign) int totalCount;

/*
 * URL 拦截规则的提取参数的时候具体参数在正则表达式截取片段数组中对应的下标 - see @WVURLInterceptorRuleParamObj
 */
@property (nonatomic, copy) NSArray * indexInPattern;

/*
 * URL 拦截规则提取参数的时候具体业务参数在请求中的参数名 - see @WVURLInterceptorRuleParamObj
 */
@property (nonatomic, copy) NSArray * nameInRequest;

/*
 * URL 拦截规则提取出来的参数是否需要主动Decode
 */
@property (nonatomic, assign) BOOL needDecode;

#pragma mark - Function

/*
 * 判断规则数据是否合法
 */
- (BOOL)isValidate;

@end
