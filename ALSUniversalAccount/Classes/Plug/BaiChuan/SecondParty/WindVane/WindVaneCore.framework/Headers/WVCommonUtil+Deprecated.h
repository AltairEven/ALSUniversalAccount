/*
 * WVCommonUtil+Deprecated.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVCommonUtil.h"
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

// 已废弃的 WVCommonUtil 方法。

@interface WVCommonUtil (Deprecated)

/**
 * 请替换为 [NSString wvIsBlank:] 方法。
 */
+ (BOOL)isBlank:(NSString *)str;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (NSString *)getCameraStr:(NSString *)str DEPRECATED_ATTRIBUTE;
+ (NSMutableDictionary *)getParamFromRequestQuery:(NSString *)query DEPRECATED_ATTRIBUTE;
+ (NSMutableDictionary *)getParamFromRequestQuery:(NSString *)query withStopWord:(NSString *)stopPre DEPRECATED_ATTRIBUTE;
+ (NSString *)configURLWithPath:(NSString *)path DEPRECATED_ATTRIBUTE;
+ (NSURL *)completionUrlScheme:(NSURL *)url DEPRECATED_ATTRIBUTE;
+ (void)completeScheme:(NSMutableURLRequest *)request DEPRECATED_ATTRIBUTE;
+ (NSString *)addDefaultParamForURL:(NSString *)url DEPRECATED_ATTRIBUTE;

@end
