//
//  NWSessionConfiguration.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 2017/7/13.
//  Copyright © 2017年 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Session 的鉴权协议
 */
@protocol NWSessionAuthenticationProtocol <NSObject>

- (NSString *)host;

- (NSString *)scheme;


/**
 * 发送鉴权请求
 */
- (BOOL)sendAuthRequest:(NSURLRequest *)request;


/**
 * 鉴权请求发送错误
 */
- (void)onAuthRequestError:(NSError *)error;


/**
 * 鉴权请求响应错误，例如返回403
 */
- (void)onAuthResponseError;


/**
 * 鉴权成功
 */
- (void)onAuthSuccess;

@end


/**
 * Session 的鉴权回调
 */
@protocol NWSessionAuthenticationDelegate <NSObject>

@required;

- (void)nwsessionWillSendRequestForAuthentication:(id<NWSessionAuthenticationProtocol>)session;
- (void)nwsession:(id<NWSessionAuthenticationProtocol>)session didAuthReceiveResponse:(NSHTTPURLResponse *)response;
- (void)nwsession:(id<NWSessionAuthenticationProtocol>)session didAuthFailWithError:(NSError *)error;
- (void)nwsession:(id<NWSessionAuthenticationProtocol>)session didAuthReceiveData:(NSData *)data;
- (void)nwsessionDidAuthFinishLoading:(id<NWSessionAuthenticationProtocol>)session;
@end


/**
 * 长连 Session 的配置
 */
@interface NWSessionConfiguration : NSObject

/**
 * 该配置针对的host
 */
@property (nonatomic, strong)   NSString                            *host;

/**
 * 是否要保活，默认为NO
 */
@property (nonatomic, assign)   BOOL                                keepAlive;


/**
 * 当没有策略的时候，是否支持Local DNS, 默认为NO
 */
@property (nonatomic, assign)   BOOL                                supportLocalDnsWhenNoPolicy;

/**
 * 鉴权回调，如果需要鉴权，则需要设置该参数，如不需要鉴权，则不用设置
 */
@property (nonatomic, weak)     id<NWSessionAuthenticationDelegate> authDelegate;


/**
 * 一个工具函数，构建默认鉴权请求，若业务对鉴权有自定义，则需要自己构建请求对象。
 */
+ (NSURLRequest *)buildDefaultAuthenticationRequestWithHost:(NSString *)host
                                                 withScheme:(NSString *)scheme
                                          withURLParameters:(NSDictionary *)parameters;

@end


