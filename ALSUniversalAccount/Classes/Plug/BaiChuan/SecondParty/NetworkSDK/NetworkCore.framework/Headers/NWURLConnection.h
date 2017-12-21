//
//  NWURLConnection.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 3/31/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NWURLConnection;

NS_ASSUME_NONNULL_BEGIN

/**
 * 请求类型
 */
typedef enum {
    kNWHttp,                                                                // 强制短连
    kNWTnet,                                                                // 强制长连
    kNWTnetWithDegradable,                                                  // 强制长连，若失败自动降级到短连重试
    kNWAutoWithHttpFirst,                                                   // 当有长连策略但长连不存在的时候，直接使用HTTP发送
    kNWAuto                                                                 // 网络库自己判断，默认选项
} NWConnectionType;



/**
 * HTTP短连类型，默认使用NSURLSession
 */
typedef enum {
    kNSURLSession,                                                          // 使用 NSURLSession， 默认值
    kNSURLConnection                                                        // 使用 NSURLConnection
} NWHttpFrameworkType;



/**
 * 请求的控制参数
 */
@interface NWConnectionOption : NSObject
@property (nonatomic, assign)   NWConnectionType        connectionType;      // 默认 kNWAuto
@property (nonatomic, assign)   NWHttpFrameworkType     httpFrameworkType;   // 默认 kNSURLSession
@property (nonatomic, assign)   BOOL                    isForceLocalDNS;     // 默认 NO
@property (nonatomic, assign)   BOOL                    isAutoRetry;         // 默认 YES
@property (nonatomic, strong)   id                      userInfo;            // 打点的时候会带回去
@end



/**
 * NWConnectionProtocol 的回调
 */
@protocol NWURLConnectionDelegate <NSObject>

@optional

- (void)nwconnection:(nullable NWURLConnection *)connection
  didReceiveResponse:(nullable NSURLResponse *)response;

- (void)nwconnection:(nullable NWURLConnection *)connection
      didReceiveData:(nullable NSData *)data;

- (void)nwconnection:(nullable NWURLConnection *)connection
    didFailWithError:(nullable NSError *)error;

- (void)nwconnection:(nullable NWURLConnection *)connection
     didSendBodyData:(NSInteger)bytesWritten
   totalBytesWritten:(NSInteger)totalBytesWritten
totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;

- (void)nwconnection:(nullable NWURLConnection *)connection
wasRedirectedToRequest:(nullable NSURLRequest *)redirectRequest
    redirectResponse:(nullable NSURLResponse *)response;

- (BOOL)nwconnection:(nullable NWURLConnection *)connection
        nsurlSession:(nullable NSURLSession *)nsurlSession
                task:(nullable NSURLSessionTask *)task
 didReceiveChallenge:(nullable NSURLAuthenticationChallenge *)challenge
   completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential *))completionHandler;

- (BOOL)nwconnection:(nullable NWURLConnection *)connection
     nsurlConnection:(nullable NSURLConnection *)nsurlConnection
willSendRequestForAuthenticationChallenge:(nullable NSURLAuthenticationChallenge *)challenge;

- (void)nwconnectionDidFinishLoading:(nullable NWURLConnection *)connection;

- (void)nwconnection:(nullable NWURLConnection *)connection
          statistics:(nullable NSDictionary *)info;

@end




/**
 * 网络库的请求的显式调用接口。
 */
@interface NWURLConnection : NSObject
@property (nonatomic, strong, readonly) NSURLRequest                *request;
@property (nonatomic, weak, readonly) id<NWURLConnectionDelegate>   delegate;

+ (BOOL)existAccelerateConnection:(nonnull NSString *)host withScheme:(nonnull NSString *)scheme;

- (nullable instancetype)initWithRequest:(nonnull NSURLRequest *)request
                                delegate:(nullable id<NWURLConnectionDelegate>)delegate;

- (void)setDelegateQueue:(nullable NSOperationQueue*)queue;

- (BOOL)isAccelerated;

- (void)startWithOption:(nullable NWConnectionOption *)option;

- (void)start;

- (void)retry;

- (void)cancel;

@end

NS_ASSUME_NONNULL_END
