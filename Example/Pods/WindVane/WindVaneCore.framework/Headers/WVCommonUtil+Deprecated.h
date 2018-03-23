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

#pragma mark - 已废弃，预计于 2019.1.1 删除

+ (BOOL)isBlank:(NSString *)str DEPRECATED_MSG_ATTRIBUTE("请替换为 [NSString wvIsBlank:] 方法");
+ (BOOL)testSampleRate:(double)sampleRate DEPRECATED_ATTRIBUTE;
+ (long long)serverIntervalToLocal:(long long)interval DEPRECATED_ATTRIBUTE;
+ (NSUInteger)processorCount DEPRECATED_ATTRIBUTE;
+ (NSTimeInterval)foregroundTime DEPRECATED_ATTRIBUTE;

#pragma mark - 已废弃，预计于 2018.8.1 删除

+ (NSString *)getCameraStr:(NSString *)str DEPRECATED_ATTRIBUTE;
+ (NSMutableDictionary *)getParamFromRequestQuery:(NSString *)query DEPRECATED_ATTRIBUTE;
+ (NSMutableDictionary *)getParamFromRequestQuery:(NSString *)query withStopWord:(NSString *)stopPre DEPRECATED_ATTRIBUTE;
+ (NSString *)configURLWithPath:(NSString *)path DEPRECATED_ATTRIBUTE;
+ (NSURL *)completionUrlScheme:(NSURL *)url DEPRECATED_ATTRIBUTE;
+ (void)completeScheme:(NSMutableURLRequest *)request DEPRECATED_ATTRIBUTE;
+ (NSString *)addDefaultParamForURL:(NSString *)url DEPRECATED_ATTRIBUTE;

@end
