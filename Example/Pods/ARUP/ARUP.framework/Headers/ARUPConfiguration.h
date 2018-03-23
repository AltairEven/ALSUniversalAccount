//
//  ARUPConfiguration.h
//  ARUP
//
//  Created by 亿刀 on 16/1/26.
//  Copyright © 2016年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  日志打印
 *
 *  @param level        日志级别
 *  @param file         文件名
 *  @param func         函数名
 *  @param line         文件行数
 *  @param extDict      扩展参数
 *  @param fullmsg      日志信息
 *
 */
@protocol ARUPLogProtocol <NSObject>
@optional
- (void)log:(NSInteger)level
    extDict:(NSDictionary *_Nullable)extDict
    fullmsg:(NSString *_Nullable)fullmsg;
@end

/**
 *  埋点上报
 *
 *  @param command      命令字，api接口或者上传接口
 *  @param biz          业务标示
 *  @param ip           ip
 *  @param port         端口
 *  @param ret          1表示成功，0表示失败
 *  @param size         上传大小，包含文件大小+协议大小，单位为字节
 *  @param costTime     花费时间，单位为毫秒
 *  @param fileID       文件ID
 *  @param fileMD5      文件md5
 *  @param errorCode    错误码，详见错误码描述
 *  @param errorMsg     错误描述
 *  @param retryTimes   重试次数
 *  @param conntime     连接时间，单位为毫秒
 *  @param md5time      文件md5时间，单位为毫秒
 *  @param encrypted    是否使用加密通道传输，0表示没有加密，1表示是ssl
 *  @param exitDict     扩展参数
 *
 */
@protocol ARUPStatisticsProtocol <NSObject>
@optional
- (void)report:(NSString *_Nonnull)command
           biz:(NSString *_Nonnull)biz
            ip:(NSString *_Nonnull)ip
          port:(int)port
           ret:(int)ret
          size:(float)size
      costTime:(float)costTime
        fileID:(NSString *_Nonnull)fileID
         token:(NSString *_Nonnull)token
     errorCode:(int)errorCode
       subcode:(int)subcode
      errorMsg:(NSString *_Nonnull)errorMsg
    retryTimes:(int)retryTimes
connectiontime:(float)conntime
   fileMD5Time:(float)filemd5Time
     encrypted:(NSString *_Nonnull)encrypted
      exitDict:(NSDictionary *_Nullable)exitDict;
@end

@interface ARUPConfiguration : NSObject

@property (nonnull, strong) id<ARUPLogProtocol> loger;

@property (nonnull, strong) id<ARUPStatisticsProtocol> statistics;

@end