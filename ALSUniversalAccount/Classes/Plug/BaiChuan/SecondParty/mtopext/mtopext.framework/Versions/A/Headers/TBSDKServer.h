//
//  TBSDKServer.h
//  mtopext
//
//  Created by sihai on 12/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TBSDKErrorHandleDelegate;
@protocol TBSDKServerDelegate;
@protocol TBSDKErrorRule;
@protocol TBSDKNetworkProgressProtocol;

@class TBSDKRequest;
@class TBSDKRequestDataSource;
@class TBSDKErrorResponse;
@class TBSDKServer;

typedef void (^StartBlock)(TBSDKServer      *server);
typedef void (^ReciveResponseHeadersBlock)(NSDictionary *responseHeaders);
typedef void (^FinishedBlock)(TBSDKServer   *server);
typedef void (^FailBlock)(TBSDKServer       *server);
typedef void (^DidLoadCache)(TBSDKServer    *server, NSDictionary *responseHeaders, NSString *responseString);
typedef NSArray* (^RequestCache)(TBSDKServer    *server, NSDictionary *responseHeaders, NSString *responseString);

#define MTOP_REQUEST_DATA_KEY               @"data"

/** TBSDKMTOPServer和TBSDKTOPServer的父类
 *
 * 定义了一些抽象方法和虚函数（本身没有任何实现，需要子类重载），这些方法和属性不和具体的业务联系
 * 定义虚函数的原因：因为TBSDKMTOPServer和TBSDKTOPServer都有类似的方法（实现不同），
 * 同时都需要放到请求池中，所以就需要定义虚函数。
 *
 */
@interface TBSDKServer : NSObject

/*!
 * API请求delegate
 */
@property (nonatomic, weak) id <TBSDKServerDelegate>                          delegate;     // 用户设置的回调

@property(weak, nonatomic) id context;                                                      // 用户可以设置使用的上下文, weak引用

#pragma mark - 错误处理

/*! 
 * TBSDK业务错误处理类
 *
 *  默认情况下errorHandle为nil，缺省的会根据TOP/MTOP“标准”返回数据格式，来处理业务错误。
 *
 *  用户设置errorHandle后，当TOP/MTOP服务器返回数据后，TBSDKServer会调用errorHandle处理返回数据的业务错误。
 *
 *  判断本次网络返回的数据是否成功很困难，因为TOP/MTOP一些接口返回的数据不标准（有的返回 "::SUCCESS" 表示成功，有的返回 "::成功" 表示成功），
 *  所以很多时候需要TBSDKServer的调用者自己判断调用是否成功。
 *
 *  errorHandle要实现 “- (id<TBSDKErrorRule>)tbsdkErrorHandleWithServer:(TBSDKServer *)server”代理方法。返回值会保存在“tbsdkError”中。
 *  如果返回nil表示服务器成功返回业务数据，TBSDKServer将要调用delegate的 “- (void)requestFinished:(TBSDKServer *)server”方法
 *  如果返回TBSDKError对象，TBSDKServer将要调用delegate的 “- (void)requestFailed:(TBSDKServer *)server”方法。
 *
 */
@property (nonatomic, weak) id<TBSDKErrorHandleDelegate>           errorHandle;

/** 本次请求的错误描述对象.
 *
 *  如果没有错误此对象为nil，反之将不为nil。
 *  如果tbsdkError.errorCode = TBSDK_REQUEST_NOT_NETWORK，表示无网络。
 *  如果tbsdkError.errorCode = TBSDK_REQUEST_TIME_OUT，表示请求超时。
 *
 */
@property (nonatomic, strong) id<TBSDKErrorRule>                                tbsdkError;

#pragma mark - 回调方法

/** 请求开始时的 selector，默认为 - (void)requestStarted:(TBSDKServer *)server; */
@property (nonatomic, unsafe_unretained) SEL                                    requestDidStartSelector;

/** 请求成功时的 selector，默认为 - (void)requestSuccess:(TBSDKServer *)server; */
@property (nonatomic, unsafe_unretained) SEL                                    requestDidFinishSelector;

/** 请求失败时的 selector，默认为 - (void)requestFailed:(TBSDKServer *)server; */
@property (nonatomic, unsafe_unretained) SEL                                    requestDidFailedSelector;

@property (nonatomic, unsafe_unretained) SEL                                    requestReciveResponseHeaders;

#pragma mark - 回调块

@property (nonatomic, copy) StartBlock                                          onStartBlock;
@property (nonatomic, copy) FinishedBlock                                       onFinishedBlock;
@property (nonatomic, copy) FailBlock                                           onFailBlock;
@property (nonatomic, copy) ReciveResponseHeadersBlock                          reciveResponseHeadersBlock;
@property (nonatomic, copy) DidLoadCache                                        didLoadCache;
@property (nonatomic, copy) RequestCache                                        requestCache;

#pragma mark -

//! 发送请求对象。
@property (nonatomic, strong) TBSDKRequest                                      *tbsdkRequest;

//! url组装器
@property (nonatomic, strong) TBSDKRequestDataSource                            *tbsdkRequestDataSource;

//! 请求的参数
@property (nonatomic, strong) NSMutableDictionary                               *params;

/** 服务返回JSON格式的对象。
 *
 *   将服务器返回的字符串解析为对象。
 *   请调用者获取此数据后保存，以免多次访问此属性造成系统压力。
 *
 */
@property (nonatomic, strong) id                                                responseJSON;

//! NSData 对象的请求响应数据
@property (nonatomic, retain) NSData                                            *responseData;

//! NSString 对象的请求响应数据
@property (nonatomic, retain) NSString                                          *responseString;

//! 设置编码，默认为UTF8
@property (nonatomic, assign) NSStringEncoding                                  responseEncoding;

//! HTTP请求头
@property (nonatomic, strong) NSDictionary                                      *requestHeaders;

//! HTTP响应头
@property (nonatomic, strong) NSDictionary                                      *responseHeaders;

/** 请求的目标的主URL。
 *
 *  一般情况下不需要设置此属性，会自动使用TOP或MTOP的主URL。
 *  用户可以设置自己的URL地址。
 */
@property (nonatomic, strong) NSString                                          *mainURLForRequest;

//! API名称
@property (nonatomic, strong, readonly) NSString                                *apiMethod;
@property (nonatomic, strong, readonly) NSString                                *apiVersion;

//! YES,表示使用POSTt方法，反之使用GET方法。默认NO。
@property (nonatomic, unsafe_unretained) BOOL                                   usePost;

//! YES,表示使用HTTPS SSL加密通道。默认NO。
@property (nonatomic, unsafe_unretained) BOOL                                   useHTTPS;

//! 网络请求的超时时间(秒)，默认30秒钟
@property (nonatomic, unsafe_unretained) NSTimeInterval                         timeOutSeconds;

//! 调用者设置，当网络返回的时候，会有这样参数(异步调用的时候)
@property (nonatomic, strong) NSDictionary                                      *userInfo;

//! 对本次网络请求的标示（一般异步请求设置）
@property (nonatomic, unsafe_unretained) NSInteger                              tag;

/** 当登录失效时，自动登录，并重新请求当前api，
 *
 * 注意: 只有app中同时集成了LoginSDK的情况下此参数才会生效，而且只针对TOP和MTOP接口自动登录
 *
 *  YES，自动登录，NO，不自动登录。默认为NO。
 *
 */
@property (nonatomic, unsafe_unretained) BOOL                                   autoLogin;

#pragma mark - 缓存

//! 是否使用标准的HTTP Cache，默认YES，使用标准的HTTP Cache
@property (nonatomic, unsafe_unretained) BOOL                                   useHTTPCache;

//! 缓存数据的有效时间(秒，从数据请求完毕后开始计时)，默认缓存60秒
@property (nonatomic, unsafe_unretained) NSTimeInterval                         cacheTimeout;

//! 数据是否来自缓存，私有属性，开发者不需要赋值
@property (nonatomic, unsafe_unretained) BOOL                                   isFromCache;
//! 缓存数据是否是失效的
@property (nonatomic, unsafe_unretained) BOOL                                   isCacheExpired;


@property (nonatomic, unsafe_unretained) BOOL                                   forceRefresh;

//! 缓存的key
@property (nonatomic, strong) NSString                                          *cacheKey;

//! 上传或者下载进度
@property (nonatomic, weak) id<TBSDKNetworkProgressProtocol>       networkProgressDelegate;

#pragma mark - 方法

//! 自定义http请求头
- (void)addRequestHeader:(NSString *)header value:(NSString *)value;

//! 开始同步网络请求, 当网络请求完成或失败后返回
- (void)startSynchronous;

//! 开始异步请求
- (void)startAsynchronous;

/** 在缓存中查找缓存数据，如果没有缓存或者缓存数据已经过期，就会重新从网络同步下载数据。反之则从缓存中获取数据
 *
 *  @parma  cacheKey        缓存数据对应的key，不能重复，不能为空
 *  @parma  cacheTimeout    缓存数据从“缓存”到“当前”的时间差，如果大于cacheTimeout说明缓存数据失效。如果小于cacheTimeout说明缓存数据有效
 *
 */
- (void)startSynchronousByCacheKey:(NSString *)cacheKey cacheTimeout:(NSTimeInterval)cacheTimeout;

/** 在缓存中查找缓存数据，如果没有缓存或者缓存数据已经过期，就会重新从网络提异步下载数据。反之则从缓存中获取数据
 *
 *  @parma  cacheKey        缓存数据对应的key，不能重复，不能为空
 *  @parma  cacheTimeout    缓存数据从“缓存”到“当前”的时间差，如果大于cacheTimeout说明缓存数据失效。如果小于cacheTimeout说明缓存数据有效
 *
 */

- (void)startAsynchronousByCacheKey:(NSString *)cacheKey cacheTimeout:(NSTimeInterval)cacheTimeout;

/*!
 *
 */
- (NSString *) getResponseStringFromCacheByCacheKey: (NSString *)cacheKey timeout:(NSTimeInterval) cacheTimeout;

- (void)cacheResponseString;

//! 清理delegate和blocks, 然后终止本次网络请求
- (void)clearDelegatesAndCancel;

- (void)clearData;


- (void)performDelegatStartSelector;

- (void)performReciveResponseHeaders:(NSDictionary *)responseHeaders;

- (void)performDelegatSuccessSelector;


- (void)performDelegatFailSelector;
@end
