//
//  ALBBOpenAccountPluginServiceProtocol.h
//  ALBBOpenAccountPluginAdapter
//
//  Created by yixiao on 16/11/29.
//  Copyright (c) 2016年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountService.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountLoginViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountRegisterViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountFindPwdViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountSetPwdViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountResetPwdViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountLoginNoPwdViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountOneStepRegisterViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountBindPhoneViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountCountryCodeViewDelegate.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountSSODelegate.h>

typedef void (^ALBBOpenAccountQrLoginSuccessCallback)();
typedef void (^ALBBOpenAccountQrLoginFailedCallback)(NSError *error);


/**
 *  ALBBOpenAccountUIService 核心服务类
 *  获取实例方式ALBBService(ALBBOpenAccountUIService)，必须确保在初始化成功后才调用
 */
@protocol ALBBOpenAccountUIService <NSObject>

/**
 *  账密登录 root方式
 */
- (void)showLoginWithConfiguration:(void (^)(UINavigationBar *navigationBar, BOOL *hidesBar))configuration
                           success:(ALBBOpenAccountSuccessCallback)success
                           failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  账密登录
 *  @param success 登陆成功回调
 *  @param failure 登录失败回调，只有用户取消登录才会执行
 */
- (void)showLoginInNavigationController:(UINavigationController *)navigationController
                                success:(ALBBOpenAccountSuccessCallback)success
                                failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  账密登录（模态视图）
 *  @param success 登陆成功回调
 *  @param failure 登录失败回调，只有用户取消登录才会执行
 */
- (void)presentLoginViewController:(UIViewController *)presentingViewController
                           success:(ALBBOpenAccountSuccessCallback)success
                           failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  短信登录
 *  @param success 登陆成功回调
 *  @param failure 登录失败回调，只有用户取消登录才会执行
 */
- (void)showLoginNoPwdInNavigationController:(UINavigationController *)navigationController
                                     success:(ALBBOpenAccountSuccessCallback)success
                                     failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  短信登录（模态视图）
 *  @param success 登陆成功回调
 *  @param failure 登录失败回调，只有用户取消登录才会执行
 */
- (void)presentLoginNoPwdViewController:(UIViewController *)presentingViewController
                                     success:(ALBBOpenAccountSuccessCallback)success
                                     failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  注册
 *  @param success 注册成功回调
 *  @param failure 注册失败回调，只有用户取消注册才会执行
 */
- (void)showRegisterInNavigationController:(UINavigationController *)navigationController
                                   success:(ALBBOpenAccountSuccessCallback)success
                                   failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  注册（模态视图）
 *  @param success 注册成功回调
 *  @param failure 注册失败回调，只有用户取消注册才会执行
 */
- (void)presentRegisterViewController:(UIViewController *)presentingViewController
                              success:(ALBBOpenAccountSuccessCallback)success
                              failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  单步注册
 *  @param success 注册成功回调
 *  @param failure 注册失败回调，只有用户取消注册才会执行
 */
- (void)showOneStepRegisterInNavigationController:(UINavigationController *)navigationController
                                          success:(ALBBOpenAccountSuccessCallback)success
                                          failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  单步注册（模态视图）
 *  @param success 注册成功回调
 *  @param failure 注册失败回调，只有用户取消注册才会执行
 */
- (void)presentOneStepRegisterViewController:(UIViewController *)presentingViewController
                                     success:(ALBBOpenAccountSuccessCallback)success
                                     failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  手机找密
 *  @param success 找密成功回调
 *  @param failure 找密失败回调，只有用户取消找密才会执行
 */
- (void)showFindPasswordInNavigationController:(UINavigationController *)navigationController
                                       success:(ALBBOpenAccountSuccessCallback)success
                                       failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  手机找密（模态视图）
 *  @param success 找密成功回调
 *  @param failure 找密失败回调，只有用户取消找密才会执行
 */
- (void)presentFindPasswordViewController:(UIViewController *)presentingViewController
                                  success:(ALBBOpenAccountSuccessCallback)success
                                  failure:(ALBBOpenAccountFailedCallback)failure;

/**
 *  绑定手机
 *  @param success 手机绑定成功回调
 *  @param failure 手机绑定失败回调，用户取消绑定或者登录态失效会执行，登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @discussion 如果failure传nil，登录态失效时会跳出toast提示用户重新登录
 */
- (void)showBindMobileInNavigationController:(UINavigationController *)navigationController
                                     success:(ALBBOpenAccountSuccessCallback)success
                                     failure:(ALBBOpenAccountFailedCallback)failure;
/**
 *  绑定手机（模态视图）
 *  @param success 手机绑定成功回调
 *  @param failure 手机绑定失败回调，用户取消绑定或者登录态失效会执行，登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @discussion 如果failure传nil，登录态失效时会跳出toast提示用户重新登录
 */
- (void)presentBindMobileViewController:(UIViewController *)presentingViewController
                                success:(ALBBOpenAccountSuccessCallback)success
                                failure:(ALBBOpenAccountFailedCallback)failure;


/**
 *  设备登录日志
 *  @param failure 登录日志获取失败回调，失效会执行，其中登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @param deleteDeviceFailure 踢除其他设备失败回调，失效会执行，其中登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @discussion 如果failure传nil，失败时会跳出提示toast
 */
- (void)showLoginDeviceLogInNavagationController:(UINavigationController *)navigationController
                                         failure:(ALBBOpenAccountFailedCallback)failure
                             deleteDeviceFailure:(ALBBOpenAccountFailedCallback)deleteDeviceFailure;

/**
 *  设备登录日志（模态视图）
 *  @param failure 登录日志获取失败回调，失效会执行，其中登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @param deleteDeviceFailure 踢除其他设备失败回调，失效会执行，其中登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 *  @discussion 如果failure传nil，失败时会跳出提示toast
 */
- (void)presentLoginDeviceLogViewController:(UIViewController *)presentingViewController
                                    failure:(ALBBOpenAccountFailedCallback)failure
                        deleteDeviceFailure:(ALBBOpenAccountFailedCallback)deleteDeviceFailure;


/**
 *  显示国家地区选择列表
 */
- (void)showCountryCodeInNavagationController:(UINavigationController *)navigationController
                                     delegate:(id<ALBBOpenAccountPhonePrefixDelegate>)delegate;

/**
 *  二维码登录授权
 *  @param params  @{@"shortUrl":@"h5登录短链"} 其中shortUrl由扫码获得
 */
- (void)showQrLoginConfirm:(UINavigationController *)navigationController
                    params:(NSDictionary *)params
                   success:(ALBBOpenAccountQrLoginSuccessCallback)success
                   failure:(ALBBOpenAccountQrLoginFailedCallback)failure;


#pragma mark - delegate设置
/**
 *  代理设置
 *  @discussion delegate内部持有方式为weak，如果业务方需要delegate全局有效，请自行维护delegate对象
 */
- (void)setOpenAccountSSODelegate:(id<ALBBOpenAccountSSODelegate>)delegate;
- (void)setLoginViewDelegate:(id <ALBBOpenAccountLoginViewDelegate>)delegate;
- (void)setRegisterViewDelegate:(id <ALBBOpenAccountRegisterViewDelegate>)delegate;
- (void)setFindPwdViewDelegate:(id <ALBBOpenAccountFindPwdViewDelegate>)delegate;
- (void)setSetPwdViewDelegate:(id <ALBBOpenAccountSetPwdViewDelegate>)delegate;
- (void)setResetPwdViewDelegate:(id <ALBBOpenAccountResetPwdViewDelegate>)delegate;
- (void)setLoginNoPwdViewDelegate:(id<ALBBOpenAccountLoginNoPwdViewDelegate>)delegate;
- (void)setOneStepRegisterViewDelegate:(id <ALBBOpenAccountOneStepRegisterViewDelegate>)delegate;
- (void)setBindPhoneViewDelegate:(id <ALBBOpenAccountBindPhoneViewDelegate>)delegate;
- (void)setCountryCodeViewDelegate:(id <ALBBOpenAccountCountryCodeViewDelegate>)delegate;


#pragma mark - handler
/**
 * 注册数据存储自定义
 * @param clazz 设置的自定义类
 */
- (void)setRegisterFillPasswordClazz:(Class)clazz;

/**
 * 设置业务错误(eg.用户名或密码不正确)的callback（不设置默认弹出Toast）
 */
- (void)setHandleBizErrorCallback:(void (^)(NSString *errMsg))bizErrCallback;



#pragma mark 一些特殊的配置
/**
 *  在登录成功后不使用SDK的导航操作，自行在callback里处理导航栈
 */
- (void)disableSDKLoginNavAction;
- (void)enableSDKLoginNavAction;


/**
 *  在注册成功后不使用SDK的导航操作，自行在callback里处理导航栈
 */
- (void)disableSDKRegisterNavAction;
- (void)enableSDKRegisterNavAction;

/**
 *  在找回密码成功后不使用SDK的导航操作，自行在callback里处理导航栈
 */
- (void)disableSDKResetPwdNavAction;
- (void)enableSDKResetPwdNavAction;

/**
 * 在绑定手机成功后不使用SDK的导航操作，自行在callback里处理导航栈
 */
- (void)disableSDKBindPhoneNavAction;
- (void)enableSDKBindPhoneNavAction;

/**
 *  在设置密码的输入框地方，密码不显示明文， 默认显示
 */
- (void)setPasswordTextInVisibleWhenSet;

/**
 *  取消历史记录的脱敏显示
 */
- (void)invalidMaskHistoryUsername;


#pragma mark 设置图标
/**
 *  设置回退图标
 */
- (void)setBackImage:(UIImage *)backImage;

/**
 *  设置按钮图标
 */
- (void)setButtonHighLightImage:(UIImage *)buttonHighLightImage;
- (void)setButtonNormalImage:(UIImage *)buttonNormalImage;
- (void)setButtonDisableImage:(UIImage *)buttonDisableImage;

@end
