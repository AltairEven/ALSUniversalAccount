//
//  TDVSDK.h
//  TrustedDeviceVerification
//
//  Created by Li Fengzhong on 13-7-30.
//  Copyright (c) 2013年 Li Fengzhong. All rights reserved.
//

//  UMID SDK v 1.2.0 for iOS

#import <Foundation/Foundation.h>

@protocol DPUrlReqeustService <NSObject>

@required

/**
 *  由接入方实现的通信服务类，为umid sdk提供通信服务，
 *  sendRequest函数需要支持重复调用
 *
 *  @param host 目标主机地址
 *  @param url  完整的请求url
 *  @param handler: 将网络请求结果返回的回调
 */
- (void) sendRequestWithHost: (NSString*) host
                         url: (NSString*) url
             responseHandler: (void (^) (NSData* data, NSError* error)) handler;

@end

/**
 *  umid 使用的环境变量定义
 */
typedef enum {
    /**
     *  线上环境
     */
    DP_ENVIRONMENT_ONLINE = 0,
    /**
     *  预发布环境
     */
    DP_ENVIRONMENT_PRE,
    /**
     *  日常环境
     */
    DP_ENVIRONMENT_DAILY,
    /**
     *  美国线上环境
     */
    DP_ENVIRONMENT_ONLINE_US,
    /**
     *  未设置
     */
    DP_ENVIRONMENT_UNSET
} DP_ENVIRONMENT;



@interface DP : NSObject

///////////////业务接口//////////////////

/**
*  初始化 umid sdk，推荐在应用启动时，在主线程内调用此接口
*
*  @param appKey  appkey，注意此值要与 dpEnv 对应，线上环境对应传线上的 appkey，以此类推
*  @param dpEnv   接入应用当前的环境，包括线上，预发，线上
*  @param service 请参考DPUrlReqeustService的定义，本值可传 nil
*  @param handler 初始化的结果回调，如果不关心初始化结果，可以传 nil，（注意，block 的调用线程不做保证）
*
*  @return 初始化函数调用的结果，不代表 umid sdk 真正的初始化结果
*/
+ (BOOL) initWithAppkey: (NSString*) appKey
            environment: (DP_ENVIRONMENT) dpEnv
             urlService: (id<DPUrlReqeustService>) service
          resultHandler: (void (^) (NSString* securityToken, NSError* error)) handler;

/**
 *  初始化 umid sdk，推荐在应用启动时，在主线程内调用此接口
 *
 *  @param appKey   appkey，注意此值要与 dpEnv 对应，线上环境对应传线上的 appkey，以此类推
 *  @param dpEnv    接入应用当前的环境，包括线上，预发，线上
 *  @param authCode 授权码，指定umid使用哪个加密文件，注意入参appkey在authCode对应的图片中要存在
 *  @param service  请参考DPUrlReqeustService的定义，本值可传 nil
 *  @param handler  初始化的结果回调，如果不关心初始化结果，可以传 nil，（注意，block 的调用线程不做保证）
 *
 *  @return 初始化函数调用的结果，不代表 umid sdk 真正的初始化结果
 */
+ (BOOL) initWithAppkey: (NSString*) appKey
            environment: (DP_ENVIRONMENT) dpEnv
               authCode: (NSString*) authCode
             urlService: (id<DPUrlReqeustService>) service
          resultHandler: (void (^) (NSString* securityToken, NSError* error)) handler;


/**
 *  获取 securityToken，不调用初始化，调用此接口需要传入相应环境的配置
 *
 *  @return 返回 24位或32位的 securitytoken，接口调用失败时，返回内容为24个0的字符串
 */
+ (NSString*) getSecurityToken: (DP_ENVIRONMENT) envForToken;



///////////////mock 测试接口///////////////

/**
 *  清空客户端 umid 相关的数据，恢复到第一次初始化之前的状态
 *
 *  @param envToReset
 */
+ (void) resetClientData: (DP_ENVIRONMENT) envToReset;

/**
 *  获取SDK当前版本号
 */
+ (NSString*) getSDKVersion;

/**
 *  设置UMID线上访问地址
 *
 *  @param host 要设置的线上地址，如ynuf.alipay.com，不要带协议头，不要带后面的参数，只能传纯host地址
 */
+ (void) setOnlineHost: (NSString*) host;

/////////////////////////////////////////






//////////////////废弃接口////////////////

/**
 *  获取 securityToken，不调用初始化，直接调用此接口时，默认使用线上配置
 *
 *  @return 返回 24位或32位的 securitytoken，接口调用失败时，返回内容为24个0的字符串
 */
+ (NSString*) getSecurityToken;

+ (BOOL) initWithUrlRequestService: (id<DPUrlReqeustService>) service __attribute__((deprecated));

+ (void) sendLoginResultWithUserName: (NSString*) userName
                       resultHandler: (void (^) (NSNumber* resultCode, NSError* error)) resultHandler __attribute__((deprecated));

+ (void) updateSDKEnviornment __attribute__((deprecated));

+ (void) setSDKEnviornment: (NSInteger) version __attribute__((deprecated));

/////////////////////////////////////////

/////////////////////////////////////////


@end
