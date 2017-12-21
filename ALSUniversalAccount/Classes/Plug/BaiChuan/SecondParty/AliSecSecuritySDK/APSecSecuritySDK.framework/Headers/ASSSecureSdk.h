//
//  ASSSecureSdk.h
//  APSecSecuritySDK
//
//  Created by xingchen on 15/2/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASSTokenResult.h"

typedef enum : NSInteger{
    
    //线上环境
    ASS_ENVIRONMENT_ONLINE = 0,
    
    //预发环境
    ASS_ENVIRONMENT_PRE,
    
    //测试环境
    ASS_ENVIRONMENT_SIT,
    
    //日常环境
    ASS_ENVIRONMENT_DAILY,
    
    //开发环境
    ASS_ENVIRONMENT_DEV
    
}ASS_ENVIRONMENT;

@interface ASSSecureSdk : NSObject

/*
    异步初始化Umid SDK和VKEYID，推荐在应用启动时调用，无线程要求
    @param envMode  接入应用当前的环境，包括线上，预发，日常
    @param utdid    utdid，传入保证VKEY ID与utdid正确相关联
    @param tid      tid，传入保证VKEY ID与tid正确相关联
    @param callback 初始化完成后的结果回调，包含Umid token，VKEYID和VKEYID  token
 */
+ (void) initToken:(ASS_ENVIRONMENT)envMode utdid:(NSString*)utdid tid:(NSString*)tid callback:(ASSSecureSdkCallback)callback;

/*
    异步初始化Umid SDK和VKEYID，推荐在应用启动时调用，无线程要求
    @param envMode  接入应用当前的环境，包括线上，预发，日常
    @param inArgs   初始化参数，包含两项内容：tid与userid，传入保证VKEY ID与其正确关联，取不到传入空字符串
    @param callback 初始化完成后的结果回调，包含Umid token，VKEYID和VKEYID  token
 */
+ (void) initToken:(ASS_ENVIRONMENT)envMode parameters:(NSDictionary*)inArgs callback:(ASSSecureSdkCallback)callback;

/*
    同步获取Umid token，VKEYID和VKEYID token的接口，无网络请求。
    同步调用前应当先调用过异步初始化接口
 
    如果异步初始化由于网络等原因失败，同步接口将返回降级方案：
        1）Umid token在utdid存在的情况下将返回utdid，否则将返回24个0
        2）VKEYID将在旧版apdid存在的情况下返回旧版apdid，否则返回随机串
        3）VKEYID token将返回空字符串:@""
 */
+ (ASSTokenResult*)getTokenResult;

+ (NSString*)getUtdid;

+ (void)saveTrustData:(NSString*)inArg;

+ (NSString*)loadTrustData;


@end
