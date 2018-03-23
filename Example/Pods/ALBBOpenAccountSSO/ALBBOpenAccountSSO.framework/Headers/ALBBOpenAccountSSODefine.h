//
//  ALBBOpenAccountSSODefine.h
//  ALBBOpenAccountSSO
//
//  Created by yixiao on 16/10/28.
//  Copyright © 2016年 Alibaba. All rights reserved.
//


/** OpenAccount消息代码 */
typedef NS_ENUM (NSUInteger,ALBBOpenAccountSSOCode) {
    /** 起始代码 */
    ALBBOpenAccountSSOCodeBegin                   = 601,
    
    /** SSOType不存在 */
    ALBBOpenAccountSSOCodeTypeError               = 601,
    
    /** SSO平台Appkey未设置 */
    ALBBOpenAccountSSOCodeAppkeyError,
    
    /** 淘宝授权未设置targetURL */
    ALBBOpenAccountSSOCodeUnSetTargetUrlError,
    
    /** 支付宝授权未初始化 */
    ALBBOpenAccountSSOCodeAlipayUnInit,
  
    /** 未发现平台依赖包 */
    ALBBOpenAccountSSOCodePlatformDependenceError,
    
    /** 未发现友盟包 */
    ALBBOpenAccountSSOCodeUmengDependenceError,
    
    /** 未发现淘宝登录依赖包 */
    ALBBOpenAccountSSOCodeTAOBAODependenceError,
    
    /** 三方账号授权失败 */
    ALBBOpenAccountSSOCodeGetThirdAccountError,
    
    /** 用户取消三方账号授权 */
    ALBBOpenAccountSSOCodeUserCancelAuthError,
    
    /** 用户关闭核身 */
    ALBBOpenAccountSSOCodeUserCloseIVAuthError,
    
    /** 终止代码 */
    ALBBOpenAccountSSOCodeEnd                     = 620,
    
};

