/*
 * WVProtocolConstant.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 */

#define WV_LOCK @"lock"
#define WV_P_UK_RULES @"rules"
#define WV_P_UK_TARGET @"target"
#define WV_P_UK_PATTERN @"pattern"
#define WV_P_UK_RULETYPE @"rutype"
#define WV_P_UK_TOTALCOUNT @"totalc"
#define WV_P_UK_INDEXOFPATTERN @"indexp"
#define WV_P_UK_NAMEOFPARAM @"namep"
#define WV_P_UK_ISNEED_DECODE @"nde"
