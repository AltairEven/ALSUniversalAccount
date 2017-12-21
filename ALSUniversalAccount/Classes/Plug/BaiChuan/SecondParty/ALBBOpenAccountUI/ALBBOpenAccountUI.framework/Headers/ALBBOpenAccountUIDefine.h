//
//  ALBBOpenAccountUIDefine.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 15/7/14.
//
//

#import <Foundation/Foundation.h>


typedef NS_ENUM (NSUInteger, ALBBOpenAccountUICode) {
    /** 起始代码 */
    ALBBOpenAccountUICodeBegin  = 571,
    
    /** 登陆失败 */
    ALBBOpenAccountUICodeLoginError,
    
    /** 无密登陆失败 */
    ALBBOpenAccountUICodeLoginNoPwdError,

    /** 短信码验证失败 */
    ALBBOpenAccountUICodeCheckSmsCodeError,
    
    /** 注册失败 */
    ALBBOpenAccountUICodeRegisterError,
    
    /** 重置密码失败 */
    ALBBOpenAccountUICodeResetPwdError,
    
    /** 短信验证码发送失败 */
    ALBBOpenAccountUICodeCheckSmsCodeSendError,
    
    /** 验证码获取失败 */
    ALBBOpenAccountUICodeCheckCodeLoadError,
    
    /** rpc返回码错误 */
    ALBBOpenAccountUICodeRpcResultCodeError,
    
    /** rpc返回的ALBBOpenResult空值错误 */
    ALBBOpenAccountUICodeRpcResultNilError,
    
    /** 获取绑定信息失败 */
    ALBBOpenAccountUICodeGetManagerInfoError,
    
    /** 获取手机前缀失败 */
    ALBBOpenAccountUICodeRpcRequestError,
    
    /** 用户取消了登录 */
    ALBBOpenAccountUICodeLoginCancelError,
    
    /** 用户取消了注册 */
    ALBBOpenAccountUICodeRegisterCancelError,
    
    /** 用户取消了找密 */
    ALBBOpenAccountUICodeFindPwdCancelError,
    
    /** 用户取消了改密 */
    ALBBOpenAccountUICodeSetPwdCancelError,
    
    /** 用户取消了绑定手机 */
    ALBBOpenAccountUICodeBindMobileCancelError,
    
    /** 终止代码 */
    ALBBOpenAccountUICodeEnd    = 600,
};
