//
//  ASSTokenResult.h
//  APSecSecuritySDK
//
//  Created by xingchen on 15/3/3.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ASSTokenResult;

/*
    异步初始化回调block定义，以ASSTokenResult为参数
 */
typedef void (^ASSSecureSdkCallback)(ASSTokenResult* result);

/*
    同步和异步接口调用所返回的数据结构，包含Umid Token，vkeyid和vkeyid token
    如果异步初始化由于网络等原因失败，同步接口返回的结果将采用以下降级方案：
        1）Umid token在utdid存在的情况下将返回utdid，否则将返回24个0
        2）VKEYID将在旧版apdid存在的情况下返回旧版apdid，否则返回随机串
        3）VKEYID token将返回空字符串:@""
 */

@interface ASSTokenResult : NSObject

@property (nonatomic, strong) NSString* umidToken;

@property (nonatomic, strong) NSString* vkeyidToken;

@property (nonatomic, strong) NSString* vkeyid;

@property (nonatomic, strong) NSString* clientKey;

@end
