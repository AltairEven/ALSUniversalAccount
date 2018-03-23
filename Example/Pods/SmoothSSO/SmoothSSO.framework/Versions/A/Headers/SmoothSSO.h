//
//  SmoothSSO.h
//  SmoothSSO
//
//  Created by Bangzhe Liu on 16/2/24.
//  Copyright (c) 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmthLoginCustomDelegate.h"
#import <AliUniversalAccount/aluUIAppearanceDelegate.h>


typedef void(^smthLoginCallback)(id result, NSError *err, NSDictionary *reserved);

typedef enum {
    smthRelease = 0,    //线上环境
    smthReleaseDebug,   //预发环境
    smthDaily           //日常环境
} SmthEnv;

/**
 *  SSO基础服务
 */
@interface SmoothSSO : NSObject

+(instancetype) sharedIntance;

@property(nonatomic,assign)BOOL isOpenSSOEnable;
@property(nonatomic,assign)BOOL isCloseLoginByPwd;
@property(nonatomic,assign)BOOL isCloseLoginByTB;
@property(nonatomic,assign)BOOL isCloseLoginByAlipay;
@property(nonatomic,copy)NSString* vkeyidToken;
@property(nonatomic, weak)id<SmthLoginCustomDelegate> smthLoginCustomDelegate;
@property(nonatomic, weak)id<aluUIAppearanceDelegate> aluAppearanceDelegate;
#pragma mark- 初始化SDK. 在应用初始化时调用
-(void) setEnv:(SmthEnv)env;

#pragma mark- 二方App需要调用的接口
//检查手淘是否支持SSO
- (BOOL)isTaobaoSSOEnabled;//帐密出淘宝SSO条件的判断
- (BOOL)isTaobaoSSOEnabledOpen;//引导页出淘宝SSO条件的判断

- (BOOL)isAlipaySSOEnabled;//帐密出支付宝SSO条件的判断
- (BOOL)isAlipaySSOEnabledOpen;//引导页出支付宝SSO条件的判断

- (void)setSecrityKey:(NSString *)secrityKey;
- (void)setIsOpenSSOEnable:(BOOL)enable;

- (void)setTaobaoCallBackUrl:(NSString *)targetUrl;

- (void)setAppKeyValue:(NSString * )appKey;

- (void)setAlipayCallBackUrl:(NSString *) targetUrl;

- (void)openSSOLoginPageWithExtraInfo:(NSDictionary *)extraInfo
                           controller:(UIViewController *)presentingController;
//跳转到淘宝去申请ssoToken
-(void)jump2TaobaoWithAppKey:(NSString*)appKey
                   targetURL:(NSString*)targetURL;

#pragma mark - 支付宝相关业务调用的API, 淘系禁用
//获取UUID
- (NSString*)getUUID;
- (NSString*)getVkeyidToken;
//从支付宝调往淘宝
- (void)alipayJump2TaobaoWithAppKey:(NSString*)appKey
                           targetURL:(NSString*)targetURL;

- (void)jump2AlipayFromAPIWithSecurityKey:(NSString*)securityKey
                        targetURL:(NSString*)targetURL
                        extraInfo:(NSDictionary *)extraInfo;

#pragma mark - 手淘调用的方法. 其他业务方禁止调用
- (NSString *)taobaoSignWithSsoVersion:(NSString *)version
                              ssoToken:(NSString *)ssoToken
                                userId:(NSString *)userId
                                     t:(NSString *)t
                                appKey:(NSString *)appKey;

- (BOOL)canHandleAlipayCallbackUrl:(NSURL*)url;
@end
