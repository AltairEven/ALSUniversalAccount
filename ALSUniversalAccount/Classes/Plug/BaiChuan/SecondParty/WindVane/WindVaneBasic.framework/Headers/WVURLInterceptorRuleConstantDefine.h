/*
 * WVURLInterceptorRuleConstantDefine.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 */

#define WVURLInterceptorRuleKey WV_P_UK_RULES
#define WVURLInterceptorRuleKeyTarget WV_P_UK_TARGET
#define WVURLInterceptorRuleKeyPattern WV_P_UK_PATTERN
#define WVURLInterceptorRuleKeyRuleType WV_P_UK_RULETYPE
#define WVURLInterceptorRuleKeyTotalCount WV_P_UK_TOTALCOUNT
#define WVURLInterceptorRuleKeyIndexOfPattern WV_P_UK_INDEXOFPATTERN
#define WVURLInterceptorRuleKeyNameInRequest WV_P_UK_NAMEOFPARAM
#define WVURLInterceptorRuleKeyIsNeedDecode WV_P_UK_ISNEED_DECODE
#define WVURLInterceptorRuleTargetValueOther 0
#define WVURLInterceptorRuleTargetValueOutside -1
#define WVURLInterceptorRuleTargetValueUnknown -2
#define WVURLInterceptorRuleTypeValuePattern 0
#define WVURLInterceptorRuleTypeValueRequest 1

@protocol WVURLInterceptorRuleConstantDefine
@end
