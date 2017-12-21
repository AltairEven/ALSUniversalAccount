//
//  NWAtsHelper.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 16/11/24.
//  Copyright © 2016年 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>


#define ATS_PROXY_HOST          @"proxy.ats.taobao.com"
#define ATS_PROXY_BUILTIN_IP    @"140.205.218.13"

/**
 * 处理方式
 */
typedef enum {
    kAtsIgnore                      = 0,    // 忽略不处理，直接放过
    kAtsForceHttps                  = 1,    // 强制HTTPS处理
    kAtsCfNetwork                   = 2,    // 使用 CFNetwork 下发 HTTP 请求
    kAtsProxy                       = 3,    // 代理转发
    kAtsForbidden                   = 4     // 禁止请求
} AtsProcessType;



/**
 * ATS proxy 返回结果
 */
typedef enum {
    kAtsProxyReturnSuccess          = 0,
    kAtsProxyReturnInvalidAppkey    = -1,
    kAtsProxyReturnInvalidDomain    = -2,
    kAtsProxyReturnTimeout          = -3,
    kAtsProxyReturnOtherError       = -4
} AtsProxyReturnType;



/**
 * ATS 主要处理逻辑封装类
 */
@interface NWAtsHelper : NSObject
@property (nonatomic, assign)   AtsProcessType      processType;
@property (nonatomic, assign)   AtsProxyReturnType  proxyReturnType;

+ (void)setIgnoreHosts:(NSArray *)hosts;

+ (void)setLowTLSVersionHosts:(NSArray *)hosts;

+ (void)commitUTHttpRequest:(NSURL *)url;

+ (void)commitUTHttpsProxyRequest:(NSURL *)url withReturnType:(AtsProxyReturnType)type;

- (void)commitUT:(NSError *)error;

+ (void)addAtsProxyHeadForRequest:(NSMutableURLRequest *)request;

+ (BOOL)isIngoreRequest:(NSURLRequest *)request;

+ (BOOL)isAtsProxyHost:(NSString *)host;

+ (BOOL)isLowTLSVersionHost:(NSString *)host;

+ (BOOL)isCfNetworkDisabled;

+ (void)disableCfNetwork;

- (BOOL)isAtsProxyBlocked;

- (void)detectProcessType:(NSURLRequest *)request;

- (void)onReceiveProxyResponse:(NSHTTPURLResponse *)response;

- (void)updateHttpsWhitelist:(NSString *)host;

- (BOOL)isHttpsWhitelistHost:(NSString *)host;

- (NSHTTPURLResponse *)convertProxyResponseURL:(NSHTTPURLResponse *)response;

- (void)setProxyResponseURL:(NSURL *)url isForce:(BOOL)force;

@end
