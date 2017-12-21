/*
 * WVApiAuthCheckResult.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WindVaneBridge.h>

#pragma mark - 已废弃，预计于 2018.8.1 删除

@interface WVApiAuthCheckResult : WVBridgePermission

/**
 * 返回鉴权成功结果。
 */
+ (WVApiAuthCheckResult *)WVApiAuthCheckResultSuccess DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgePermission permissionAllowed] 方法");

/**
 * 返回鉴权失败结果。
 */
+ (WVApiAuthCheckResult *)WVApiAuthCheckResultAuthFailed:(NSDictionary *)errorInfo DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgePermission permissionDenied:] 方法");

/**
 * 返回无鉴权结果，表示不以此次鉴权结果作为判断依据。
 */
+ (WVApiAuthCheckResult *)WVApiAuthCheckResultNULL DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgePermission permissionNotSure] 方法");

/**
 * 检查指定的鉴权结果是否表示无效。
 */
+ (BOOL)isEqualsWVApiAuthCheckResultNULL:(WVApiAuthCheckResult *)wvApiAuthCheckResult DEPRECATED_MSG_ATTRIBUTE("请使用 [WVBridgePermission permitted] 属性");

@end
