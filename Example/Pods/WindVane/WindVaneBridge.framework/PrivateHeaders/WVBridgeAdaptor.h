//
//  WVBridgeAdaptor.h
//  Core
//
//  Created by lianyu.ysj on 16/10/23.
//  Copyright © 2016年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVBridgeHandlerInfo.h>

/**
 * 动态 WVBridge 的适配器协议，用于适配自定义的动态 WVBridge 协议。
 */
@protocol WVBridgeAdaptorProtocol <NSObject>

@required

/**
 * 寻找指定类名、方法明对应的 Handler 信息。
 *
 * @param className   要寻找的类名。
 * @param handlerName 要寻找的方法名。
 *
 * @return Handler 信息。
 */
- (WVBridgeHandlerInfo * _Nullable)findClassName:(NSString * _Nonnull)className withHandlerName:(NSString * _Nonnull)handlerName;

@end

/**
 * 动态 WVBridge 适配器的服务。
 */
@interface WVBridgeAdaptor : NSObject

/**
 * 注册指定的 WVBridge 适配器。
 */
+ (void)registerBridgeAdaptor:(id<WVBridgeAdaptorProtocol> _Nonnull)adaptor;

/**
 * 寻找指定类名、方法明对应的 Handler 信息。
 *
 * @param className   要寻找的类名。
 * @param handlerName 要寻找的方法名。
 *
 * @return Handler 信息。
 */
+ (WVBridgeHandlerInfo * _Nullable)findClassName:(NSString * _Nonnull)className withHandlerName:(NSString * _Nonnull)handlerName;

@end
