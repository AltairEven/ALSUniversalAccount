//
//  TBSDKMTOPServer.h
//  mtopext
//
//  避免接入方大改, 兼容他们继续使用TBSDKMTOPServer
//
//  Created by sihai on 12/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKServer.h"
#import "MtopExtRequest.h"
#import "TBSDKServerDelegate.h"
#import "MtopExtRequestDelegate.h"

typedef enum _TBSDKMTOPCachePolicy {
    //    默认cache策略。使用这个策略时，request会先查看cache中是否有可用的缓存数据。如果没有，request会像普通request那样工作。
    //    如果有缓存数据并且缓存数据没有过期，那么request会使用缓存的数据，而且不会向服务器通信。如果缓存数据过期了，request会先进行GET请求来想服务器询问数据是否有新的版本。如果服务器说缓存的数据就是当前版本，那么缓存数据将被使用，不会下载新数据。在这种情况下，cache的有效期将被设定为服务器端提供的新的有效期。如果服务器提供更新的内容，那么新内容会被下载，并且新的数据以及它的有效期将被写入cache。
    TBSDKMTOPAskServerIfModifiedWhenStaleCachePolicy = 0,
    
    //不使用任何cache策略，普通的请求
    TBSDKMTOPDoNotReadAndWriteCacheCachePolicy,
    
    //用于强制刷新，没有cache回调，一定请求网络数据
    TBSDKMTOPAskServerIfModifiedCachePolicy,
    
    //用于强制刷新，有cache回调，一定请求网络数据
    TBSDKMTOPAskServerIfModifiedCacheAndReturnCachePolicy
    
} TBSDKMTOPCachePolicy;

@interface TBSDKMTOPServer : TBSDKServer<MtopExtRequestDelegate>

#pragma mark - 属性

//! MTOP请求的业务参数
@property (nonatomic, strong, readonly) NSMutableDictionary                     *dataDict;

//! MTOP执行耗时参数
@property (nonatomic, strong, readonly) NSDictionary                            *mtopPreDataDict;

@property(assign, nonatomic) MtopSessionExpiredOption sessionExpiredOption;     // Session失效选项

/*!
 * 需要设定独立的sid和ecode
 */
@property (nonatomic, unsafe_unretained) BOOL                       needEcodeSign;

/* 需要设定独立的sid和eCode */
@property (assign, nonatomic) BOOL                                  isNeedWua;
@property (assign, nonatomic) WuaType                               wuaType;

/* wua 用户行为参数 */
@property (strong, nonatomic) NSString*                             openAppkey;
@property (strong, nonatomic) NSString*                             wuaPageName;
@property (strong, nonatomic) NSString*                             wuaCtrlName;
@property (assign, nonatomic) float                                 xCoordinate;
@property (assign, nonatomic) float                                 yCoordinate;

@property (nonatomic, strong) NSString*                             sid;
@property (nonatomic, strong) NSString*                             eCode;
@property (nonatomic, strong) NSString*                             bigPipeReuseIdentifier;


@property (nonatomic, strong) NSString*                             httpCacheKey;

@property (nonatomic, unsafe_unretained) TBSDKMTOPCachePolicy       mtopCachePolicy;

@property (nonatomic, strong, readonly) NSURL*                      url;

// api single request custom host
@property (nonatomic, strong) NSString*                             customHost;

@property (nonatomic, strong) NSArray*                              blackCacheKeyParam;

/* 是否是来自离线操作的请 */
@property (assign, nonatomic) BOOL                                  isFromOffline;

@property(strong, nonatomic) NSString                               *userID;

@property (assign, nonatomic) BOOL                                  isLoginCacnel;

#pragma mark - 方法

/*! 
 * 创建一个指定API的请求，
 *
 *  @param  method  方法名称，例如 com.taobao.items.search
 */
+ (id) requestWithMethod: (NSString*) method;

/*! 
 * 创建一个指定方法的请求
 *
 *  @param method 方法名称，例如 com.taobao.items.search
 */
- (id) initWithMethod: (NSString*) method;

/*!
 * 添加“协议”参数
 *
 *  @param param    参数值
 *  @param key      参数名称
 */
- (void) addParam: (NSObject*) param forKey: (NSString*) key;

/*!
 * 删除“协议”请求参数
 */
- (void) removeParam: (NSString*) key;

/*! 
 * 添加无线 MTOP 请求"业务"参数
 *
 *  @param param    参数值
 *  @param key      参数名称
 */
- (void) addDataParam: (NSObject*) param forKey: (NSString*) key;

/*! 删除MTOP 请求"业务"参数
 *
 *  @param  key     使用“addDataParam:forKey:传入的key”
 *  @see    - addDataParam:forKey:
 */
- (void) removeDataParam: (NSString*) key;

/*!
 * 获取cache key
 */
- (NSString*)getOfflineCacheKey;


/*!
 * 添加要发送的文件
 *
 *  @param      data             要发送的文件
 *  @param      fileName         文件的名字
 *  @param      key              http post方法对应的key
 *
 */
- (void) addData: (NSData*) data withFileName: (NSString*) fileName forKey: (NSString*) key;

/*!
 * 通过MtopExtResponse填充响应
 * @param response
 */
- (void) fillWithMtopResponse: (MtopExtResponse*) response;

/*!
 * 设置本次请求的ttid
 */
- (void) setTtid: (NSString*) ttid;

/*!
 * 设置mtop header的扩展参数
 */
- (void) setMtopRequestHeaderExt:(NSString *) headerString;

/*!
 * 开始对服务端的响应数据校验
 */
- (void) enableResponseValidate;

/*!
 * 开始对服务端的响应数据校验
 */
- (void) disableResponseValidate;

/*!
 * 禁止从主线程回调
 *
 */
- (void) notUseMainThreadCallback;

/*!
 * 从主线程回调
 *
 */
- (void) useMainThreadCallback;

/*!
 *
 *
 *
 */
- (void) setLocation: (double) longitude latitude: (double) latitude;

@end
