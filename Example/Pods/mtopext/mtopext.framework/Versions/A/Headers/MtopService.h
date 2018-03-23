//
//  MtopService.h
//  mtopext
//
//  mtop api 调用统一入口
//
//  Created by sihai on 4/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MtopSDK/TBSDKRequestDelegate.h>
#import "MtopExtRequest.h"
#import "MtopExtResponse.h"
#import "LoginProtocol.h"
#import "MtopExtRequestDelegate.h"
#import "FloodProtectionDelegate.h"
#import "FloodProtectionHandler.h"


@interface MtopService : NSObject<TBSDKRequestDelegate>

/*!
 * 获取单例
 */
+ (MtopService*) getInstance;

/*!
 * 安装一个自定义的登录模块
 * 在请求API时, 判断本地无session时, 会调用该模块进行登录, 或者服务端返回session效时会调用该模块进行登录, 登录成功后重放失败请求。
 * 在登录的过程中, 有需要登录请求的API的请求会被 pending 到队列, 然后在登录成功后重放, 会登录失败后直接失败
 *
 */
- (id<LoginProtocol>) installCustomLoginModule: (id<LoginProtocol>) loginHandler;

/*!
 * 安装防刷delegate
 * @param delegate
 */
- (id<FloodProtectionDelegate>) installFloodProtectionDelegate: (id<FloodProtectionDelegate>) delegate;

/**
 * 同步调用API
 *
 * @param request
 * @return
 *             MtopExtResponse API响应
 */
- (MtopExtResponse*) sync_call: (MtopExtRequest*) request;

/**
 * 异步调用API
 *
 * @param request
 * @param delegate
 *
 */
- (void) async_call: (MtopExtRequest*) request delegate: (id<MtopExtRequestDelegate>) delegate;

/**
 * 异步调用API, 跳过startFilter之前的filter
 *
 * @param request
 * @param delegate
 * @param startFilter
 *
 */
- (void) async_call: (MtopExtRequest*) request delegate: (id<MtopExtRequestDelegate>) delegate startFilter: (NSString*) startFilter;

/**
 * 提供一个便捷的方法, 同步调用没有参数的API
 * 
 * @param apiName       API名称
 * @param apiVersion    API版本
 * @return
 *             MtopExtResponse API响应
 *
 */
- (MtopExtResponse*) sync_call: (NSString*) apiName apiVersion: (NSString*) apiVersion;

/**
 * 提供一个便捷的方法, 同步调用API
 *
 * @param apiName       API名称
 * @param apiVersion    API版本
 * @param bizParameters API业务参数
 * @return
 *             MtopExtResponse API响应
 *
 */
- (MtopExtResponse*) sync_call: (NSString*) apiName apiVersion: (NSString*) apiVersion bizParameters: (NSDictionary*) bizParameters;

@end
