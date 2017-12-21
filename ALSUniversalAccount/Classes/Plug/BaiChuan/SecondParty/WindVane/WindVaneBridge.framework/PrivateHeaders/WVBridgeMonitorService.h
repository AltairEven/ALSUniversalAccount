//
//  WVBridgeMonitorService.h
//  Bridge
//
//  Created by lianyu.ysj on 17/1/5.
//  Copyright © 2017年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneCore/WindVaneCorePrivate.h>

/**
 * 表示 WVBridge 调用情况的性能监控信息。
 */
@interface WVBridgeMonitorStat : NSObject <WVMonitorInfoProtocol>

/**
 * [维度]WVBridge 的名称。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * name;

/**
 * [维度]WVBridge 的返回码。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * ret;

/**
 * [维度]WVBridge 的消息。
 */
@property (nonatomic, copy, nullable) NSString * message;

/**
 * [维度]调用 WVBridge 的 URL。
 */
@property (nonatomic, copy, nullable) NSString * url;

/**
 * 使用 WVBridge 的名称和结果初始化。
 */
- (instancetype _Nonnull)initWithName:(NSString * _Nonnull)name withRet:(NSString * _Nonnull)ret;

@end

/**
 * 表示需要监控 WVBridge 性能、报错时可以选择实现的方法。
 */
@protocol WVBridgeMonitorProtocol <NSObject>

/**
 * 在 WVBridge 调用完毕时调用。
 *
 * @param stat 性能监控信息。
 */
- (void)bridgeInvoke:(WVBridgeMonitorStat * _Nonnull)stat;

/**
 * 在 WVBridge 调用错误时调用。
 *
 * @param name WVBridge 的名称。
 * @param url  WVBridge 的 URL。
 * @param code 错误代码。
 */
- (void)bridgeInvokeError:(NSString * _Nonnull)name withURL:(NSURL * _Nullable)url code:(NSUInteger)code;

@end

#pragma mark - 注册监控

/**
 * WindVaneBridge 模块的监控服务。
 */
@interface WVBridgeMonitorService : NSObject

/**
 * 注册一个 WVBridge 监控 Protocol。
 */
+ (void)registerBridgeMonitorHandler:(id<WVBridgeMonitorProtocol> _Nonnull)handler;

/**
 * 返回已注册的 WVBridge 监控 Protocol。
 */
+ (id<WVBridgeMonitorProtocol> _Nullable)registeredBridgeMonitorHandler;

@end
