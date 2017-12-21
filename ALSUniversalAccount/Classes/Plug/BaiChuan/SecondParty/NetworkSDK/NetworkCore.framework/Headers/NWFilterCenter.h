//
//  NWFilterCenter.h
//  ALINetworkSDK
//
//  Created by jiangpan on 16/12/15.
//  Copyright © 2016年 jiangpan. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NWResponseFilterProtocol;
@protocol NWRequestFilterProtocol;

@interface NWFilterCenter : NSObject

/**
 获取filterCenter单例
 
 @return fileterCenter单例
 */
+ (instancetype)sharedInstance;

/**
 注册添加扩展请求头filter
 */
- (void)addExtRequestHeaderFilter:(id<NWRequestFilterProtocol>)filter;

/**
 注册添加请求响应filter
 */
- (void)addResponseFilter:(id<NWResponseFilterProtocol>)filter;

/**
 移除请扩展请求头filter

 @param filterName filter名称
 */
- (void)removeRequestHeaderFilter:(NSString *)filterName;

/**
 移除请求响应filter

 @param filterName filter名称
 */
- (void)removeResponseFilter:(NSString *)filterName;

/**
 执行所有注册的请求头扩展filter
 
 @param request 需扩展header字段的request
 @return 需扩展的header字段
 */
- (NSDictionary *)runExtRequestHeaderFilters:(NSURLRequest *)request;

/**
 执行指定名称,指定request的请求头扩展filter
 
 @param request 需扩展header字段的request
 @param filter 指定执行filter的名称
 @return 需扩展的header字段
 */
- (NSDictionary *)runExtRequestHeaderFilter:(NSURLRequest *)request andFilter:(NSString *)filter;

/**
 执行请求响应filter
 */
- (void)runResponseFilter:(NSURLResponse *)response andHost:(NSString *)urlHost;

@end
