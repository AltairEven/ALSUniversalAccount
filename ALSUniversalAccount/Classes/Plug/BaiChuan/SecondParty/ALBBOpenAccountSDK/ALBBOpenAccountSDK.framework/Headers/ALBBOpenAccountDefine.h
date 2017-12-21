//
//  ALBBOpenAccountDefine.h
//  ALBBOpenAccount
//
//  Created by zifan.zx on 10/29/15.
//  Copyright © 2015 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

/** OpenAccount消息代码 */
typedef NS_ENUM (NSUInteger,ALBBOpenAccountCode) {
    /** 起始代码 */
    ALBBOpenAccountCodeBegin                   = 551,
    
    /** RPC返回空值 */
    ALBBOpenAccountCodeRpcResultNilError       = 551,
    
    /** RPC返回值反序列化失败 */
    ALBBOpenAccountCodeDeserializerError,
    
    /** RPC返回码错误 */
    ALBBOpenAccountCodeRPCResultCodeError,
    
    /** RPC请求失败 */
    ALBBOpenAccountCodeRpcRequestError,
    
    /** 登录会话过期 */
    ALBBOpenAccountCodeSessionExpireError,
    
    /** 登录失败 */
    ALBBOpenAccountCodeLoginError,
        
    /** init失败 */
    ALBBOpenAccountCodeConnectionRequestError,
    
    /** Loginid已经设置，无法再次设置 */
    ALBBOpenAccountCodeLoginIdExistError,
    
    /** refresh session失败 */
    ALBBOpenAccountCodeRefreshSessionError,
    
    /** 终止代码 */
    ALBBOpenAccountCodeEnd                     = 570,

};
