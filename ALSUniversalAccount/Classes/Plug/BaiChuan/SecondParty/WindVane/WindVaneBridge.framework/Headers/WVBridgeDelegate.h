/*
 * WVBridgeDelegate.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVBridgeProtocol.h"
#import <Foundation/Foundation.h>

/**
 * WVBridge 调用方需要实现的 Protocol，一般利用 Category 对现有环境进行扩展。
 * 需要做好非主线程调用的保护。
 */
@protocol WVBridgeDelegate <NSObject>

@required

/**
 * WVBridge 调用方的当前来源 URL。
 * 可能在任意线程调用。
 */
- (NSURL * _Nullable)wvBridgeReferrer;

/**
 * WVBridge 的成功回调。
 * 可能在任意线程调用。
 *
 * @param reqId     请求 ID。
 * @param ret       回调返回值。
 * @param result    回调结果。
 * @param keepAlive 是否需要保持回调不销毁，可以持续性调用。
 */
- (void)wvBridgeOnSuccess:(NSString * _Nonnull)reqId withRet:(NSString * _Nonnull)ret withResult:(NSDictionary * _Nullable)result keepAlive:(BOOL)keepAlive;

/**
 * WVBridge 的失败回调。
 * 可能在任意线程调用。
 *
 * @param reqId  请求 ID。
 * @param ret    回调返回值。
 * @param result 回调结果。
 */
- (void)wvBridgeOnFailure:(NSString * _Nonnull)reqId withRet:(NSString * _Nonnull)ret withResult:(NSDictionary * _Nullable)result;

@optional

#pragma mark KeepAlive

/**
 * 表示 WVBridge 的持续回调已结束，可以回收。
 * 可能在任意线程调用。
 *
 * @param reqId 请求 ID。
 */
- (void)wvBridgeDisposeCallback:(NSString * _Nonnull)reqId;

#pragma mark NotifyEvent

/**
 * WVBridge 发送事件的接口。
 * 可能在任意线程调用。
 *
 * @param eventName 要发送的事件名称。
 * @param param     事件参数。
 * @param callback  事件结果的回调。
 */
- (void)wvBridgeDispatchEvent:(NSString * _Nonnull)eventName withParam:(NSDictionary * _Nullable)param withCallback:(WVEventCallback _Nullable)callback;

@end
