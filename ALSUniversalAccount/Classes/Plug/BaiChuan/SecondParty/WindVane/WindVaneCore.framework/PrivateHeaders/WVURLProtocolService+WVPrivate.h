/*
 * WVURLProtocolService.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVURLProtocolInterface.h>
#import <WindVaneCore/WVURLProtocolService.h>

/**
 * WVURLProtocolService 的私有方法。
 */
@interface WVURLProtocolService (WVPrivate)

#pragma mark - URL Protocol

/**
 * 注册一个 URL 拦截 Protocol。
 *
 * @param protocolClass 一个遵守 <WVURLProtocolInterface> 协议的 class。
 */
+ (void)registerURLProtocol:(Class)protocolClass;

/**
 * 按注册的逆序枚举所有注册的 WVURLProtocolInterface。
 *
 * @return 是否存在可以响应此请求的 ProtocolInterface，如果存在则为 YES；否则为 NO。
 */
+ (BOOL)enumerateProtocolsUsingBlock:(void (^)(Class protocolClass, BOOL * canResponse))block;

#pragma mark - Scheme

/**
 * 注册会被拦截的 Scheme。
 *
 * @param scheme 会被拦截的 Scheme。
 */
+ (void)registerScheme:(NSString *)scheme;

/**
 * 返回指定请求的 Scheme 是否会被拦截。
 */
+ (BOOL)containsScheme:(NSURLRequest *)request;

#pragma mark - Rewriter

/**
 * 重写指定的请求，后注册的重写器会先被调用。
 */
+ (BOOL)rewrite:(NSMutableURLRequest *)request phase:(WVRequestPhase)phase;

#pragma mark - UserAgent

/**
 * 返回指定请求是否包含 UserAgent 标记。
 *
 * @param request     要检查的请求。
 * @param checkCustom 是否检查自定义 UserAgent 标记。
 */
+ (BOOL)containsUserAgentMark:(NSURLRequest *)request checkCustom:(BOOL)checkCustom;

#pragma mark - PageRequest

/**
* 将指定请求标记为页面 URL。
*/
+ (void)markAsPageURL:(NSString *)urlString;

/**
 * 返回指定的 URL 是否表示页面 URL。
 * 如果返回了 YES，就会移除此页面的标记。
 */
+ (BOOL)isPageURL:(NSString *)urlString;

#pragma mark - WVURLMonitorProtocol

/**
 * 注册指定的 WVURlProtocol 资源加载情况监控。
 */
+ (void)registerWVURLMonitorHandler:(id<WVURLMonitorProtocol>)handler;

/**
 * 返回已注册的 WVURlProtocol 资源加载情况监控。
 */
+ (id<WVURLMonitorProtocol>)registeredWVURLMonitorHandler;

/**
 * 报告资源开始加载。
 *
 * @param request 资源请求。
 * @param time    资源开始加载时间，为 1970 年 1 月 1 日至今的秒数。
 */
+ (void)reportResourceStart:(NSURLRequest *)request atTime:(NSTimeInterval)time;

/**
 * 报告资源或页面获得状态码等信息。
 *
 * @param request    资源请求。
 * @param response   资源响应。
 * @param fromType   自定义页面来源，如缓存、线上等。
 */
+ (void)reportResource:(NSURLRequest *)request withResponse:(NSURLResponse *)response withExternalHeaders:(NSDictionary *)externalHeaders withFromType:(WVURLProtocolReadFromType)fromType;

/**
 * 报告资源结束加载。
 *
 * @param request  资源请求。
 * @param time     资源结束加载时间，为 1970 年 1 月 1 日至今的秒数。
 * @param dataSize 资源大小。
 */
+ (void)reportResourceFinish:(NSURLRequest *)request atTime:(NSTimeInterval)time dataSize:(NSUInteger)dataSize;

@end
