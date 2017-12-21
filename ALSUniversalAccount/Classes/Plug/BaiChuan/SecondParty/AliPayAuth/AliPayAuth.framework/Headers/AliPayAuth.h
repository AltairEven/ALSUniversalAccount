//
//  AliPayAuth.h
//  AliPayAuth
//
//  Created by ouxi on 16/10/31.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, AliPayAuthFailure) {
    AliPayAuth_ParameterNull,                       //入参为空
    AliPayAuth_EncError,                            //加密失败
    AliPayAuth_SignError,                           //签名失败
    AliPayAuth_OpenWalletError,                     //打开钱包失败，需要安装支付宝
    AliPayAuth_GetAuthTokenError                    //获取authtoken失败
};

@protocol AliPayAuthDelegate <NSObject>

/**
 支付宝授权成功

 @param authToken 授权码
 */
- (void)aliPayAuthSuccess:(NSString *)authToken;

/**
 支付宝授权取消
 */
- (void)aliPayAuthDidCancel;


/**
 支付宝授权失败

 @param errorCode 失败错误码，参见AliPayAuthFailure
 @param errorMessage 失败信息
 */
- (void)aliPayAuthFailure:(NSUInteger)errorCode message:(NSString *)errorMessage;

/**
 支付宝授权埋点回调接口
 */
- (void)monitorAliPayAuth:(NSString *)arg1 args:(nullable NSDictionary *)args;

@end


@interface AliPayAuth : NSObject

/**
 授权初始化方法

 @param delegate 回调delegate
 @return 授权实例
 */
+ (instancetype)instanceWithDelegate:(id<AliPayAuthDelegate>)delegate;

/**
 * 第三方调用，判断能否跳转支付宝
 */
- (BOOL)canOpenAlipay;

/**
 * 第三方调用，用来判断当前钱包版本是否支持授权登录
 */
- (BOOL)canSupportAliPayAuth;

/**
 打开支付宝钱包，获取授权authToken，调用前请检查canOpenAlipay && canSupportAliPayAuth
 
 @param appKey 用于AES 加密 和 Atlas 签名
 @param uuid 设备唯一标识id
 @param callbackUrl 支付宝钱包回调的URL
 */
- (void)openAliPayAuth:(NSString *)appKey
                  uuid:(NSString *)uuid
              callback:(NSString *)callbackUrl;

/**
 * 判断传入的url是否为授权登录
 */
- (BOOL)canHandleOpenURL:(NSURL *)url;

/**
 * 处理授权登录的URL
 */
- (void)handleOpenURL:(NSURL *)url;


@end

NS_ASSUME_NONNULL_END
