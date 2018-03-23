//
//  TBLoginCenter.h
//  TBLogin
//
//  Created by 寻弦 on 14/11/19.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <mtopext/LoginProtocol.h>
#import "TBLoginCenterDefine.h"

// ---提供给非手淘app用的通知---
#ifndef TBNotificationUserLoggedIn
#define TBNotificationUserLoggedIn                  @"TB_NOTIFICATION_USER_LOGGED_IN"
#endif

#ifndef TBNotificationUserLoggedOut
#define TBNotificationUserLoggedOut                 @"TB_NOTIFICATION_USER_LOGGED_OUT"
#endif

#ifndef kTBMainClientNotificationUserGiveUpLogin
#define kTBMainClientNotificationUserGiveUpLogin    @"TB_MAIN_CLIENT_NOTIFICATION_USER_GIVE_UP_LOGIN"
#endif

#ifndef TBNotificationLoginViewWillAppear
#define TBNotificationLoginViewWillAppear           @"TB_NOTIFICATION_LOGIN_VIEW_WILL_APPEAR"
#endif
// ---提供给非手淘app用的通知---

#define TOAST_TIME_DURATION 3
extern NSString* const aluApplyAsoTokenSessionInvalid;

typedef void(^TBSSOLoginCallBack)(BOOL isSSOLoginSuc);

@interface TBLoginCenter : NSObject<LoginProtocol>

//注册接口
- (void)doRegister;

/**
 *  基本功能同loginWithLoginOption:completionHandler:cancelationHandler:
 *  @param timeout  设置自动登录请求的timeout时间，设0的话，就是默认值30秒
 *
 */
- (void)loginWithLoginOption:(LoginOption)loginOption
                     timeout:(int)timeout
           completionHandler:(LOGIN_COMPLETION_HANDLER)completionHandler
          cancelationHandler:(LOGIN_CANCELATION_HANDLER)cancelationHandler;


/**
 *   非淘宝Session的免登流程，如旺信Session
 *
 *   推荐接入方的是使用方法是，首先调用generateLoginTokenForOtherSessionWithCompletionHandler:，然后在completionHandler中接受loginToken作为签名去请求服务端，如果服务端返回错误，调用failBlock，并传入3个参数（服务端返回的错误、服务端的Session失效的错误码、接入方自身的错误处理callerFailBlock），在failBlock中会先去判断服务端返回的错误是不是传入的Session失效错误码，如果是，就做autologin，然后再调用completionHandler，并把新生成的签名以loginToken传入。如果是其他错误，则直接调用callerFailBlock
 *
 *   [self generateLoginTokenForOtherSessionWithCompletionHandler:^(NSString *loginToken, LoginTokenFailBlock failBlock) {
 *       //用loginToken去做服务端请求
 *
 *       //服务端返回成功，则继续接入方自己的逻辑
 *
 *       //服务端返回错误，18这里假设是接入方服务端返回错误体系中的Session失效
 *       failBlock(error,18,^{
 *           //这里是接入方自己的错误处理逻辑
 *          }
 *       );
 *    }];
 *
 *
 *   注意，如果接入方不传入正常的Session失效错误码，则autologin后重新生成loginToken的逻辑不能正常运作！
 *   另外，为防止无限autologin循环，failBlock只会做1次autologin，1次generateLoginTokenForOtherSessionWithCompletionHandler:调用中，第2次传给 completionHandler的failBlock不会再做autologin，而是直接调用callerFailBlock
 */
- (void)generateLoginTokenForOtherSessionWithCompletionHandler:(void (^)(NSString *loginToken,LoginTokenFailBlock failBlock))completionHandler;

/**
 *  应用内淘系和非淘系信任登陆接口：获取havanaSsoToken用于旺信免登
 *  如果没有拿到，请做好容错处理
 */
- (void)getHavanaSsoToken:(void (^)(id result, NSError *err, NSDictionary *reserved))callback;

- (void)modifyPassword:(UIViewController *)controller;

- (void)bindPhoneNum:(UIViewController *)controller;

- (void)changePhoneNum:(UIViewController *)controller;

- (void)retrievePassword:(UIViewController *)controller;

/**
 *  会员信任登陆SDK:
 *
 *  @param url           <#url description#>
 *  @param TBSSOCallback <#TBSSOCallback description#>
 */
- (void)loginBySsoTokenUrl:(NSURL *)url
                  callback:(TBSSOLoginCallBack)TBSSOCallback;


- (void)unifytokenLogin:(NSString *)token
               callback:(void (^)(BOOL isSuccess))callback;

//注意：只能测试环境使用,通过nick一键登录
- (void)mockEasyLoginCompletionHandler:(LOGIN_COMPLETION_HANDLER)completionHandler
                               useName:(NSString *)username userPwd:(NSString *)password;

- (void)implantationLocalCookies;

//提供给windvane用
- (BOOL)isLoginURL:(NSString *)url;

- (BOOL)isLogoutURL:(NSString *)url;

//暂时暴露，业务方不要用
- (void)didObtainAluSDKLoginNotification:(NSNotification *)notification;

@end
