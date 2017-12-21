//
//  WVBridge+Advance.h
//  Bridge
//
//  Created by lianyu.ysj on 2017/7/15.
//  Copyright © 2017年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WindVaneBridge.h>

/**
 * [慎用]对于实现 WVBridgeProtocol 的动态 WVBridge，会通过以下方法判断指定 API 是否是安全的，不会对返回 YES 的 API 做安全校验，需要自行承担安全风险。
 *
 * @param methodName 要检查的方法名称。
 *
 * (BOOL)isMethodSecure:(NSString * _Nonnull)methodName;
 */

/**
 * WVBridge 的同步处理器，无法保证同步处理器的线程，请自行做好线程安全的保护。
 *
 * @param params  WVBridge 调用方传入的参数对象。
 * @param context WVBridge 的调用上下文。
 * @return 要同步返回的值。
 */
typedef NSDictionary * _Nullable (^WVBridgeSyncHandler)(NSDictionary * _Nonnull params, id<WVBridgeContext> _Nonnull context);

/**
 * 【慎用】包含高级的 WVBridge 功能。
 */
@interface WVBridge (Advance)

/**
 * 【慎用】注册同步全局 WVBridge 处理器，允许同步返回内容给 JS。
 *
 * @param name       处理器的名称，格式为 @"类名.方法名"。
 * @param block      处理器的执行 Block。
 */
+ (void)registerSyncHandler:(NSString * _Nonnull)name withBlock:(WVBridgeSyncHandler _Nonnull)block;

/**
 * 【慎用】注册安全的全局 WVBridge 处理器，不会对此 API 做安全校验，需要自行承担安全风险。
 *
 * @param name       处理器的名称，格式为 @"类名.方法名"。
 * @param block      处理器的执行 Block。
 * @param resetBlock 处理器的重置 Block，用于在页面切换时做清理操作。
 */
+ (void)registerSecureHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block withResetBlock:(WVBridgeResetHandler _Nullable)resetBlock;

/**
 * 【慎用】注册安全的私有 WVBridge 处理器，不会对此 API 做安全校验，需要自行承担安全风险。
 *
 * @param name       处理器的名称，格式为 @"类名.方法名"。
 * @param block      处理器的执行 Block。
 * @param resetBlock 处理器的重置 Block，用于在页面切换时做清理操作。
 */
- (void)registerSecureHandler:(NSString * _Nonnull)name withBlock:(WVBridgeHandler _Nonnull)block withResetBlock:(WVBridgeResetHandler _Nullable)resetBlock;

/**
 * 调用同步 WVBridge。
 *
 * @param name   要执行的 WVBridge 名称，格式为 @"类名.方法名"。
 * @param params 要执行的 WVBridge 字符串参数。
 * @param reqId  此次 WVBridge 调用的唯一标识。
 *
 * @return 同步 WVBridge 的执行结果。
 */
- (NSDictionary * _Nullable)callSyncHandler:(NSString * _Nonnull)name withParams:(NSDictionary * _Nullable)params withReqId:(NSString * _Nullable)reqId;

@end
