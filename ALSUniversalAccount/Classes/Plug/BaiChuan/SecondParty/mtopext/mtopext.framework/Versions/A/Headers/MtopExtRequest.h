
//
//  MtopExtRequest.h
//  mtopext
//
//  封装的mtop api 请求
//
//  Created by sihai on 4/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MtopSDK/TBSDKRequest.h"
#import "MtopExtRequestDelegate.h"
#import "TBSDKUTUtility.h"

// 默认的版本
#define DEFAULT_VERSION         @"*"

/*!
 * cache 策略
 */
typedef enum {
    //    默认cache策略。使用这个策略时，request会先查看cache中是否有可用的缓存数据。如果没有，request会像普通request那样工作。
    //    如果有缓存数据并且缓存数据没有过期，那么request会使用缓存的数据，而且不会向服务器通信。如果缓存数据过期了，request会先进行GET请求来想服务器询问数据是否有新的版本。如果服务器说缓存的数据就是当前版本，那么缓存数据将被使用，不会下载新数据。在这种情况下，cache的有效期将被设定为服务器端提供的新的有效期。如果服务器提供更新的内容，那么新内容会被下载，并且新的数据以及它的有效期将被写入cache。
    AskServerIfModifiedWhenStaleCachePolicy = 0,
    
    //不使用任何cache策略，普通的请求
    DoNotReadAndWriteCacheCachePolicy,
    
    //用于强制刷新，没有cache回调，一定请求网络数据
    AskServerIfModifiedCachePolicy,
    
    //用于强制刷新，有cache回调，一定请求网络数据
    AskServerIfModifiedCacheAndReturnCachePolicy
    
} CachePolicy;

/*!
 * 登录控制参数
 */
typedef enum {
    MtopSessionExpiredOptionDummy                        = -1,       // 标记用的，请不要用
    MtopSessionExpiredOptionNone                         = 0,        // Session失效时，什么都不做
    MtopSessionExpiredOptionAutoLogin                    = 1,        // Session失效时，只做Auto Login
    MtopSessionExpiredOptionAutoLoginAndManualLogin      = 2         // Session失效时，先Auto Login，如果Auto Login失败，唤起登录界面
} MtopSessionExpiredOption;

/*!
 * WUA 控制参数
 */
typedef enum {
    kWuaBase        = 1,
    kWuaEx          = 2
} WuaType;

@interface MtopExtRequest : NSObject

@property(assign, nonatomic) BOOL isSync;                                       // 同步请求, 还是异步请求

@property(assign, nonatomic) BOOL isNeedEcode;                                  // 是否需要ecode签名, simple签名方式的API请设置为 NO, 默认为NO

@property(assign, nonatomic) MtopSessionExpiredOption sessionExpiredOption;     // Session失效选项

@property(assign, nonatomic) BOOL isEnableWUA;                                  // 是否启用WUA
@property(assign, nonatomic) WuaType wuaType;                                   // WUA 类型
@property (strong, nonatomic) NSString* wuaPageName;                            // 需要生成WUA的页面名称
@property (strong, nonatomic) NSString* wuaCtrlName;                            // 需要生成WUA的页面按钮
@property (assign, nonatomic) float xCoordinate;                                // 需要生成WUA的页面点击时间x坐标
@property (assign, nonatomic) float yCoordinate;                                // 需要生成WUA的页面点击时间y坐标

@property(strong, nonatomic) NSString* ttid;                                    // 业务设置的ttid

// api single request custom host
@property (nonatomic, strong) NSString* customHost;

@property(assign, nonatomic) CachePolicy cachePolicy;                           // cache策略
@property(strong, nonatomic) NSMutableArray* excludedCacheKeyParameters;        // 计算cache key 时需要排查的参数名列表, 目前用数组而没有用dict是合理的, 参数数量不会多

@property(assign, nonatomic) BOOL isFromOfflineOperation;                       // 是否是来自离线操作

@property(strong, nonatomic) TBSDKRequest* mrequest;                            // 底层的mtop请求;

@property(assign, atomic) BOOL isCanceled;                                      // 是否已经被取消

@property(weak, atomic) id<MtopExtRequestDelegate> delegate;                 // 上层设置的delegate, weak引用

// block 回调支持
@property(copy, atomic) MtopExtRequestStarted  startedBlock;                 // 请求开始
@property(copy, atomic) MtopExtRequestFailed   failedBlock;                  // 请求失败
@property(copy, atomic) MtopExtRequestSucceed  succeedBlock;                 // 请求成功


@property(weak, nonatomic) id context;                                          // 用户可以设置使用的上下文, weak引用

@property(assign, nonatomic) int8_t retryCount;                                 // 记录重试次数

@property(strong, nonatomic) UTDataSet* mtopUT;                                 // ut 记录


@property(assign, nonatomic) ServerType serverType;                             // 服务类型

@property(assign, nonatomic) BOOL isForceHttps;                                 // 强制https
@property(assign, nonatomic) BOOL isForceSpdy;                                  // 强制spdy

@property(assign, nonatomic) BOOL isNeedValidateResponse;                       // 是否需要校验服务端的响应

//@property(assign, nonatomic) CFAbsoluteTime networkstart;                       // 是否需要校验服务端的响应

@property(assign, nonatomic) BOOL isNotUseMainThreadCallback;                   // YES: 不从主线程回调, NO: 从主线程回调

@property(strong, nonatomic) NSString *userID;

@property(strong, nonatomic) NSString *clientTraceId;

/*!
 * 初始化一个API请求对象
 * @param apiName       API名称
 * @param apiVersion    API版本
 * @return
 *              MtopExtRequest
 */
- (MtopExtRequest*) initWithApiName: (NSString*) apiName apiVersion: (NSString*) apiVersion;

/*!
 * 设置网络超时
 * @param timeout 超时时间，单位秒
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) setNetworkTimeout: (int) timeout;

/*!
 * 走https
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) useHttps;

/*!
 * 禁止走https
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) disableHttps;

/*!
 * 使用post
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) useHttpPost;

/*!
 * 添加一个http请求头
 * @param value     HTTP头value, 请不要做urlencode, 底层会统一做的
 * @param key       HTTP头key
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addHttpHeader: (NSString*) value forKey: (NSString*) key;

/*!
 * 一次添加多个头
 * @param kvs
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addHttpHeaders: (NSDictionary*) kvs;

/*!
 * 添加一个协议级参数
 * @param value     参数值
 * @param key       参数名
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addProtocolParameter: (NSString*) value forKey: (NSString*) key;

/*!
 * 添加一个扩展参数和data参数平级
 * @param value     参数值
 * @param key       参数名
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addExtParameter: (id) value forKey: (NSString*) key;

/*!
 * 一次添加多个扩展参数和data参数平级
 * @param kvs
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addExtParameters: (NSDictionary*) kvs;

/*!
 * 移除一个扩展参数
 * @param key
 * @return
 *              MtopExtRequest 以便可以链式操作
 *
 */
- (MtopExtRequest*) removeExtParameter: (NSString*) key;

/*!
 * 添加一个业务参数(业务级别参数)
 * @param value     参数值
 * @param key       参数名
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addBizParameter: (id) value forKey: (NSString*) key;

/*!
 * 一次添加多个业务参数(业务级别参数)
 * @param kvs
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addBizParameters: (NSDictionary*) kvs;

/*!
 * 移除一个业务参数
 * @param key
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) removeBizParameter:(NSString*) key;

/*!
 * 为了TBSDKMtopServer兼容提供的, 不建议使用
 * @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) clearBizParameters;

/*!
 * 添加要上传的文件
 * @param data          文件数据
 * @param fileName      本地文件名(全路径)
 * @param forKey        form field 的 key
 * @return
 *              MtopExtRequest 以便可以链式操作
 *
 */
- (MtopExtRequest*) addUploadFileWithData: (NSData*) data fileName: (NSString*) fileName forKey: (NSString*) key;

/*!
 * 添加一个计算cache key 时排查的参数名
 * @param name 参数名
 *  @return
 *              MtopExtRequest 以便可以链式操作
 */
- (MtopExtRequest*) addExcludedCacheKeyParameter: (NSString*) name;


/*!
 * 指示生成WUA, 并设定WUA可选参数
 * @param pageName
 * @param ctrlName
 * @param xCoordinate
 * @param yCoordinate
 */
- (MtopExtRequest*) enableWUAWithPageName: (NSString*) pageName ctrlName: (NSString*) ctrlName xCoordinate: (float) xCoordinate yCoordinate: (float) yCoordinate;

/*!
 * 获取请求id (请求id是系统生成的唯一的标识)
 * @return
 *              NSString
 */
- (NSString*) getRequestId;

/*!
 * 获取API名称
 * @return
 *              NSString
 */
- (NSString*) getApiName;

/*!
 * 获取API版本
 * @return
 *              NSString
 */
- (NSString*) getApiVersion;

/*!
 * 为了TBSDKMtopServer兼容提供的, 不建议使用
 * @param apiVersion
 *
 */
- (void) setApiName: (NSString*) apiName;

/*!
 * 为了TBSDKMtopServer兼容提供的, 不建议使用
 * @param apiVersion
 *
 */
- (void) setApiVersion: (NSString*) apiVersion;

/*!
 * 获取扩展参数
 * @return
 *              NSDictionary
 */
- (NSDictionary*) getExtParameters;

/*!
 * 获取业务参数
 * @return
 *              NSDictionary
 */
- (NSDictionary*) getBizParameters;

/*!
 * 判断请求是否要求使用了post
 * @return
 *              YES
 *              NO
 */
- (BOOL) isUseHttpPost;

/*!
 * 判断请求是否要求使用了https
 * @return
 *              YES
 *              NO
 */
- (BOOL) isUseHttps;

/*!
 * 重试计数 retryCount += 1
 */
- (void) retryed;

/*!
 * 是否需要重试
 */
- (BOOL) isNeedRetry;

/*!
 * mtop ut 开始 (开始请求)
 * @param isSync
 */
- (void) utStart: (BOOL) isSync;

/*!
 * mtop ut 结束
 */
- (void) utEnd;

/*!
 * mtop ut json解析开始
 */
- (void) utJsonParseStartTime;

/*!
 * mtop ut json解析结束
 */
- (void) utJsonParseEndTime;

/*!
 * 取消
 */
- (void) cancel;

/*!
 *
 */
- (BOOL) isNeedCallback;

@end
