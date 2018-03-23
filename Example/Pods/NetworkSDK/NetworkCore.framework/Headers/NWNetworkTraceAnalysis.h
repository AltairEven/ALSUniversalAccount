//
//  NWNetworkTraceAnalysis.h
//  ALINetworkSDK
//
//  Created by zhishui.lcq on 16/4/28.
//  Copyright © 2016年 zhishui.lcq. All rights reserved.
//  说明：网络行为分析

#import <Foundation/Foundation.h>

#pragma mark -
#pragma mark 请求耗时分析

@protocol NWRequestCostProtocol <NSObject>

@required

/**
 *  请求开始
 *  @param request 请求对象
 *  @param extDict 扩展参数
 *
 */
- (void)requestDidStart:(NSURLRequest *)request ext:(NSDictionary *)extDict;

/**
 *  请求结束
 *  @param request 请求对象
 *  @param ext 扩展参数
 *
 */
- (void)requestDidFinish:(NSURLRequest *)request ext:(NSDictionary *)ext;

@optional
/**
 *  请求开始
 *  @param url 请求的url
 *  @param exitDict 扩展参数
 *
 */
- (void)requestDidStart:(NSURL *)url exitDict:(NSDictionary *)exitDict DEPRECATED_MSG_ATTRIBUTE("使用[requestDidStart:ext:] 代替.");;

/**
 *  请求结束
 *  @param url 请求的url
 *  @param exitDict 扩展参数
 *
 */
- (void)requestDidFinish:(NSURL *)url exitDict:(NSDictionary *)exitDict DEPRECATED_MSG_ATTRIBUTE("使用[requestDidFinish:ext:] 代替.");;

@end

#pragma mark -
#pragma mark 请求流量分析

extern NSString* const NW_FLOW_KEY_REFER;
extern NSString* const NW_FLOW_KEY_BIZ;
extern NSString* const NW_FLOW_KEY_PROTOCOL;
extern NSString* const NW_FLOW_KEY_REQIDENTIFIER;
extern NSString* const NW_FLOW_KEY_ACTIVITYNAME;
extern NSString* const NW_FLOW_KEY_WEBPAGEURL;
extern NSString* const NW_FLOW_KEY_ISBACKGROUND;
extern NSString* const NW_FLOW_KEY_UPSTREAM;
extern NSString* const NW_FLOW_KEY_DOWNSTREAM;

@protocol NWRequestFlowProtocol <NSObject>

@required

/**
 *  流量
 */
- (void)recordRequestFlow:(NSURLRequest *)request info:(NSDictionary *)info;

@end
