//
//  aluUIAppearanceDelegate.h
//  UniversalAccount
//
//  Created by shaobin on 3/21/14.
//  Modified by madding.lip on 10/01/16.
//  Copyright (c) 2014 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol aluNavigationBarAppearance

@optional
- (void)setControllerBackgroundColor:(UIColor *)viewColor;

- (void)setNavBarCenterItemTitle:(NSString *)title;
- (void)setNavBarLeftBarItemTitle:(NSString *)title;
- (void)setNavBarLeftBarItemFont:(UIFont *)font;
- (void)setNavBarLeftBarItemTitleColor:(UIColor *)titleColor;
- (void)setNavBarRightBarCustomView:(UIView *)view;

- (void)setNavBarRightBarItemTitle:(NSString *)title;
- (void)setNavBarRightBarItemFont:(UIFont *)font;
- (void)setNavBarRightBarItemTitleColor:(UIColor *)titleColor;

@required
- (void)setNavBarLeftBarItemImage:(UIImage *)image;
- (void)setNavBarLeftBarItemImage:(UIImage *)image forState:(UIControlState)state;
- (void)setNavBarLeftBarItemHighLightImage:(UIImage *)image;

@end

#pragma mark - 登录页面
@protocol aluAlipayLoginPageAppearance <aluNavigationBarAppearance>
@optional
- (void)setPasswordTextHolder:(NSString*)pwdTextHolder;
- (void)setUserIdTextHolder:(NSString*)idTextHolder;
- (UIView *)bigBackgroundView;
- (UIView *)contentView;
- (UIButton *)loginButton;
- (UIButton *)otherLoginButton;
- (UIButton *)forgetPwdButton;
#pragma mark - 界面定制
- (void)configureRegisterEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;
- (void)configureOtherLoginEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;

- (void)setLoginPageTitle:(NSString*) title;

@end

@protocol aluHistoryLoginPageAppearance <aluNavigationBarAppearance>
@optional
- (UIView *)bigBackgroundView;
- (UIView *)contentView;
- (UIButton *)loginButton;
- (UIButton *)otherLoginButton;
- (UIButton *)forgetPwdButton;
#pragma mark - 界面定制
- (void)configureRegisterEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;
- (void)configureOtherLoginEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;
- (void)configureRetrivePwdEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;

- (void)setLoginPageTitle:(NSString*) title;
@end

@protocol aluTaobaoLoginPageAppearance <aluNavigationBarAppearance>
@optional
- (UIView *)bigBackgroundView;
- (UIView *)contentView;
- (UIButton *)loginButton;
- (UIButton *)otherLoginButton;
- (UIButton *)forgetPwdButton;
//注册按钮
- (UIButton *)aluRegButton;
#pragma mark - 界面定制
- (void)setRegBtnImage:(UIImage *)image highLightImage:(UIImage*)highLightImg;

- (void)configureUserNameEntry:(NSString *)userNamePlaceholder passwordEntry:(NSString *)passwordPlaceholder;
- (void)configureRegisterEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;
- (void)configureOtherLoginEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;
- (void)configureRetrivePwdEntry:(UIFont *)font normalColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;

#pragma mark - 界面定制
- (void)setLoginPageTitle:(NSString*) title;
- (void)setBackButtonAtRight:(UIButton*) backBtn;
- (void)setLogidLabelTextColor:(UIColor*) labelTextColor;
- (void)setLogidTextColor:(UIColor*) textColor;
- (void)setPasswordLabelTextColor:(UIColor*) labelTextColor;
- (void)setPasswordTextColor:(UIColor*) textColor;

//登录框在打开登录页面时, 是否隐藏键盘.默认是NO, 也就是显示键盘
- (void)setKeyboardHidden:(BOOL)keyboardHidden;
@end

#pragma mark - 注册页面
@protocol aluRegisterPageAppearance <aluNavigationBarAppearance>
@optional
- (UIButton *)nextStepButton;
- (void)setAgreementColor:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor __attribute__ ((deprecated));
- (void)setRegisterPageTitle:(NSString*) title;

/** 
 *  定制淘宝协议
 *  @param text             淘宝协议的文案，可传nil，使用默认的淘宝注册协议文案
 *  @param link             淘宝协议的链接，可传nil，使用默认的淘宝注册协议URL
 *  @param normalColor      normal状态下的颜色
 *  @param highLightColor   highlight状态下的颜色
 */
- (void)setTaobaoAgreementText:(NSString *)text link:(NSString *)link color:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;

/**
 *  定制支付宝协议
 *  @param text             支付宝协议的文案，可传nil，使用默认的支付宝注册协议文案
 *  @param link             支付宝协议的链接，可传nil，使用默认的支付宝注册协议URL
 *  @param normalColor      normal状态下的颜色
 *  @param highLightColor   highlight状态下的颜色
 */
- (void)setAlipayAgreementText:(NSString *)text link:(NSString *)link color:(UIColor *)normalColor highLightColor:(UIColor *)highLightColor;

@end


@protocol aluRegSMSVerifyPageAppearacne <aluNavigationBarAppearance>
@optional
- (UIButton *)nextStepButton;
#pragma mark - 界面定制
- (void)setRegSMSVerifyPageTitle:(NSString*) title;

@end

@protocol aluRegSetPwdPageAppearacne <aluNavigationBarAppearance>
@optional
- (UIButton *)confirmButton;

@end

#pragma mark - 绑定账号页面
@protocol aluBindTaobaoPageAppearacne <aluNavigationBarAppearance>
@optional
- (UIButton *)confirmButton;

@end

@protocol aluBindAlipayPageAppearacne <aluNavigationBarAppearance>
@optional
- (UIButton *)confirmButton;

@end

#pragma mark - 短信认证页面
@protocol aluSMSVerifyPageAppearacne <aluNavigationBarAppearance>
@optional
- (UIButton *)nextStepButton;

@end

@protocol aluSSOGuidePageAppearacne <aluNavigationBarAppearance>
@optional
@end

#pragma mark - aluUIAppearanceDelegate
@protocol aluUIAppearanceDelegate <NSObject>

@optional

/**
 配置顶部导航栏的背景色，标题栏自己大小等属性，当一个新的navigationController创建时被调用
 */
- (void)appearanceOfNavigationBar:(UINavigationBar *)navBar;

/**
 配置顶部状态栏的颜色的前景色
 */
- (UIStatusBarStyle)appearanceOfStatusBarStyle;

/**
 注册
 */
- (void)appearanceOfRegisterPage:(id<aluRegisterPageAppearance>)appearance;
- (void)appearanceOfRegCountryListPage:(id<aluNavigationBarAppearance>)appearance;
- (void)appearanceOfRegSMSVerifyPage:(id<aluRegSMSVerifyPageAppearacne>)appearance;
- (void)appearanceOfRegSetPwdPage:(id<aluRegSetPwdPageAppearacne>)appearance;

/**
 登录
 */
- (void)appearanceOfAlipayLoginPage:(id<aluAlipayLoginPageAppearance>)appearance;
- (void)appearanceOfTaobaoLoginPage:(id<aluTaobaoLoginPageAppearance>)appearance;
- (void)appearanceOfHistoryLoginPage:(id<aluHistoryLoginPageAppearance>)appearance;

/**
 绑定账号
 */
- (void)appearanceOfBindAlipayPage:(id<aluBindAlipayPageAppearacne>)appearance;
- (void)appearanceOfBindTaobaoPage:(id<aluBindTaobaoPageAppearacne>)appearance;

/**
 短信认证
 */
- (void)appearanceOfSMSVerigyPage:(id<aluSMSVerifyPageAppearacne>)appearance;

- (void)appearanceOfH5Page:(id<aluNavigationBarAppearance>)appearance;


/**
 *引导页定制
 */
- (void)appearanceOfSSOGuidePage:(id<aluSSOGuidePageAppearacne>)appearance;

@end

