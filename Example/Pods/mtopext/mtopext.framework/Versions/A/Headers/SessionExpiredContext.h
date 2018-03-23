//
//  SessionExpiredContext.h
//  mtopext
//
//  session 失效上下文
//
//  Created by sihai on 18/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SessionExpiredContext : NSObject<NSCopying>

@property(strong, nonatomic) NSString* nick;                 //
@property(strong, nonatomic) NSString* msgCode;              //
@property(strong, nonatomic) NSString* reason;               // 服务端返回sessin失效的原因, 取自http header: <code>HEADER_SESSION_EXPIRED_REASON</code>
@property(strong, nonatomic) NSString* apiName;              // 返回session失效的API名称
@property(strong, nonatomic) NSString* apiVersion;           // 返回session失效的API版本
@property(strong, nonatomic) NSString* timestamp;            // session失效是的时间戳

/*!
 * 初始化
 * @param nick
 * @param msgCode
 * @param reason        失效原因
 * @param apiName       失效时请求的API的名称
 * @param apiVersion    失效时请求的API的版本
 */
- (SessionExpiredContext*) initWithNick: (NSString*) nick msgCode: (NSString*) msgCode reason: (NSString*) reason apiName: (NSString*) apiName apiVersion: (NSString*) apiVersion;

/*!
 * 转换成Dictionary
 */
- (NSDictionary*) asDictionary;
@end
