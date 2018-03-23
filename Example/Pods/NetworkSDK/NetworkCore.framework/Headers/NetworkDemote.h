//
//  NetworkDemote.h
//  TBSDKNetworkSDK
//
//  Created by Roger.Mu on 8/1/14.
//  Copyright (c) 2014 taobao.com. All rights reserved.
//
// 开发开关,主要是方便抓包使用

#import <Foundation/Foundation.h>

@interface NetworkDemote : NSObject

@property (nonatomic) int spdyLinkHoldTimeRate;
@property (nonatomic) int spdyCreateConnectionTimeout;

/**
 * 是否接管 NSURLConnection/NSURLSession的请求，默认为接管：YES (如果注册了话)
 * 若需要关闭该接管，设置为: NO
 */
@property (nonatomic) BOOL canInitWithRequest;

/**
 * 仅针对白名单域名接管 NSURLConnection/NSURLSession的请求后
 * 若需要针对白名单域名接管接管，设置为: YES
 * 需要跟whiteHosts一起配合使用
 */
@property (nonatomic) BOOL canInitWithWhiteHostsRequest;

/**
 * 接管白名单域名字典，字典判断效率高
 * key:域名,value:空字符串即可
 * 需要跟canInitWithWhiteHostsRequest一起配合使用
 */
@property (strong) NSDictionary *whiteHosts;


/**
 * 预建连接降级开关, 默认为YES。
 * SDK 内部目前残留一些淘系域名连接，若接入方不需要连接此类域名，可以设置为 NO
 */
@property (nonatomic) BOOL canPrebuiltConnections;


/**
 * 随机建连accs白名单开关, 默认为NO，与白名单域名layzStartWhiteHosts配合使用。
 * SDK 内部目前残留淘系逻辑，accs连接被关闭时10s内随机取一个值重新建连，若接入方需要控制白名单，可以设置为 YES.
 */
@property (nonatomic) BOOL canLazyStartWhiteACCSConnection;


/**
 * 随机建连accs域名白名单, 当canLazyStartWhiteACCSConnection为YES时生效。
 */
@property (strong) NSArray *layzStartWhiteHosts;


/**
 * 接管域名黑名单，按前缀过滤
 * 比如，http://www.abc.com, 所有 http://www.abc.com/xxx 的请求都不接管
 */
@property (nonatomic, strong) NSMutableArray<NSString *> *URLPrefixBlackList;


+ (NetworkDemote *)shareInstance;

/* 是否已经降级了SPDY */
- (BOOL)isDemoteSPDY;

/* 不降级SPDY，默认 */
- (void)unDemoteSPDY;

/* 降级SPDY,功能一旦开启，那么所有的请求都会以HTTP短连接方式发起! */
- (void)networkDemoteSPDY;

/* 是否禁用了HTTPDNS功能,host传nil即可 */
- (BOOL)isDNSDemote:(NSString *)host;

/* 禁用HTTPDNS */
- (void)dnsDemote;

/* 不禁用HTTPDNS */
- (void)unDNSDemote;

/* 是否禁用了HTTPS功能 */
- (BOOL)isHTTPSDemote;

/* 禁用HTTPS */
- (void)httpsDemote;

/* 不禁用HTTPS */
- (void)unHTTPSDemote;

// -----------------------------------------------------------------------------
// *****已经废弃不用的接口*****

//所有请求降级到http
- (void)demote2HTTP DEPRECATED_MSG_ATTRIBUTE("使用networkDemoteSPDY代替.");

//还原降级到http
- (void)unDemote2HTTP DEPRECATED_MSG_ATTRIBUTE("使用unDemoteSPDY代替.");

//是否降级到http
- (BOOL)isDemote2HTTP DEPRECATED_MSG_ATTRIBUTE("使用isDemoteSPDY代替.");

// 向老版本降级接口兼容，已经废弃不用的接口
- (void)alwaysSpdyDemote DEPRECATED_MSG_ATTRIBUTE("废弃的接口.");

// 向老版本降级接口兼容，已经废弃不用的接口
- (void)unAlwaysSpdyDemote DEPRECATED_MSG_ATTRIBUTE("废弃的接口.");

@end
