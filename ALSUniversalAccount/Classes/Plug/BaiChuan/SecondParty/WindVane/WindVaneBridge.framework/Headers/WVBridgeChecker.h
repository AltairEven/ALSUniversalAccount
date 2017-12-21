/*
 * WVBridgeChecker.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVBridgeProtocol.h"
#import <Foundation/Foundation.h>
#import <WindVaneCore/WindVaneCore.h>

#pragma mark - WVBridgePermission

/**
 * WVBridge 的权限。
 */
@interface WVBridgePermission : NSObject

/**
 * WVBridge 是否具有执行权限。
 */
@property (nonatomic, assign, readonly, getter=isPermitted) WVTristate permitted;

/**
 * 要返回给调用方的权限错误信息。
 */
@property (nonatomic, copy, readonly, nullable) NSDictionary * errorInfo;

/**
 * 返回允许执行的结果。
 */
+ (instancetype _Nonnull)permissionAllowed;

/**
 * 返回拒绝执行的结果。
 */
+ (instancetype _Nonnull)permissionDenied:(NSDictionary * _Nullable)result;

/**
 * 返回无法确认是否具有权限。
 */
+ (instancetype _Nonnull)permissionNotSure;

@end

#pragma mark - WVBridgeCheckerProtocol

/**
 * WVBridge 的检查器协议。
 */
@protocol WVBridgeCheckerProtocol <NSObject>

@required

/**
 * 检查指定 WVBridge 是否具有执行权限。
 * 总是在后台线程调用。
 *
 * @param apiName WVBridge 的名称，格式为 "类名.方法名"。
 * @param params  WVBridge 的调用参数。
 * @param context WVBridge 的执行上下文。
 *
 * @return 权限检查结果。
 */
- (WVBridgePermission * _Nonnull)checkPermission:(NSString * _Nonnull)apiName withParams:(NSDictionary * _Nullable)params
                                     withContext:(id<WVBridgeContext> _Nonnull)context;

@end

#pragma mark - WVBridgeChecker

/**
 * WVBridge 的检查器。
 */
@interface WVBridgeChecker : NSObject

/**
 * 注册指定的权限校验器。
 */
+ (void)registerChecker:(id<WVBridgeCheckerProtocol> _Nonnull)checker;

/**
 * 取消注册指定的权限校验器。
 */
+ (void)unregisterChecker:(id<WVBridgeCheckerProtocol> _Nonnull)checker;

/**
 * 检查指定 WVBridge 是否具有执行权限。
 *
 * @param apiName WVBridge 的名称，格式为 "类名.方法名"。
 * @param params  WVBridge 的调用参数。
 * @param context WVBridge 的执行上下文。
 *
 * @return 权限检查结果。
 */
+ (WVBridgePermission * _Nonnull)checkPermission:(NSString * _Nonnull)apiName withParams:(NSDictionary * _Nullable)params
                                     withContext:(id<WVBridgeContext> _Nonnull)context;

@end
