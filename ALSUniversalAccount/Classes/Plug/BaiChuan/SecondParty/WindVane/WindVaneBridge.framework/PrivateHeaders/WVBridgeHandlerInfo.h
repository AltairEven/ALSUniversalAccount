//
//  WVBridgeHandlerInfo.h
//  Core
//
//  Created by lianyu.ysj on 16/10/19.
//  Copyright © 2016年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVBridgeProtocol.h>
#import <WindVaneCore/WVJSONKit.h>

#pragma mark - WVBridgeHandlerInfo

/**
 * WVBridge 的 Handler 信息。
 */
@interface WVBridgeHandlerInfo : NSObject

/**
 * 是否对旧的字符串参数进行兼容。
 */
@property (nonatomic, assign) WVTristate stringParamsCompatible;

/**
 * 当前 Handler 是否是安全的（无需安全校验）。
 */
@property (nonatomic, assign, getter=isSecure) BOOL secure;

@end

#pragma mark - WVBridgeSimpleHandlerInfo

/**
 * WVBridge 的简单 Handler 信息（直接调用）。
 */
@interface WVBridgeSimpleHandlerInfo : WVBridgeHandlerInfo

/**
 * 使用指定的 block 初始化。
 */
- (instancetype _Nonnull)initWithBlock:(WVBridgeHandler _Nonnull)block;

/**
 * 调用当前 Handler。
 *
 * @param params  WVBridge 调用方传入的参数对象。
 * @param context WVBridge 的调用上下文。
 */
- (void)invoke:(NSDictionary * _Nullable)params withContext:(id<WVBridgeCallbackContext> _Nonnull)context;

@end

#pragma mark - WVBridgeComplexHandlerInfo

/**
 * WVBridge 的复杂 Handler 信息（需要创建实例）。
 */
@interface WVBridgeComplexHandlerInfo : WVBridgeHandlerInfo

/**
 * Handler 的类名。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * className;

/**
 * WVBridge API 实例的作用域。
 */
@property (nonatomic, assign, readonly) WVBridgeScope instanceScope;

/**
 * 创建当前 API 的实例。
 */
- (id _Nonnull)createInstance;

/**
 * 调用指定实例的 Handler。
 *
 * @param instance        WVBridge 的实例。
 * @param params          WVBridge 调用方传入的参数对象。
 * @param callbackContext WVBridge 的回调上下文。
 * @param context         WVBridge 的上下文。
 */
- (void)invoke:(id _Nonnull)instance withParams:(NSDictionary * _Nullable)params
    withCallbackContext:(id<WVBridgeCallbackContext> _Nonnull)callbackContext
            withContext:(id<WVBridgeContext> _Nullable)context;

@end

#pragma mark - WVBridgeComplexBlockHandlerInfo

/**
 * WVBridge 的带有清理功能的 WVBridgeHandler 信息。
 */
@interface WVBridgeComplexBlockHandlerInfo : WVBridgeComplexHandlerInfo

/**
 * 使用指定的 block 初始化。
 */
- (instancetype _Nonnull)initWithBlock:(WVBridgeHandler _Nonnull)block withResetBlock:(WVBridgeResetHandler _Nonnull)resetBlock;

@end
