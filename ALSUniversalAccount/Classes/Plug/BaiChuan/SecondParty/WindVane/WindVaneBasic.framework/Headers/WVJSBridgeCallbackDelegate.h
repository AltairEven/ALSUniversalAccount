/*
 * WVJSBridgeCallbackDelegate.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * JSBridge 的回调委托。
 */
@protocol WVJSBridgeCallbackDelegate <NSObject>

@required

/**
 * 调用 JSBridge 的 URL。
 */
- (NSURL *)URL;

/**
 * JSBridge 的成功回调。
 */
- (void)onSuccess:(NSString *)ifid withRet:(NSString *)ret withResult:(NSDictionary *)result;

/**
 * JSBridge 的失败回调。
 */
- (void)onFailure:(NSString *)ifid withRet:(NSString *)ret withResult:(NSDictionary *)result;

/**
 * 发送事件的回调。
 */
- (void)onFireEvent:(NSString *)eventName withParam:(NSDictionary *)param;

@end
