//
//  aluUILoginCustomConfig.h
//  AliUniversalAccount
//
//  Created by xiaowei on 15/2/3.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^LoginWaitBlock)(BOOL);

@protocol aluTaobaoLoginPageAppearance;


// 只支持淘宝账号登陆UI的自定义。aluSDK的setSelectHistoryAccountEnabled必须是NO,才支持more custom
@protocol aluUILoginMoreCustomDelegate <NSObject>

@optional
// Default is NO
- (BOOL)shouldHiddenLoginPageNavigationBar;

// 如果需要自定义present方式，实现这两个delegate
- (void)customPresentLoginPage:(UIViewController *)viewController appearance:(id<aluTaobaoLoginPageAppearance>)appearance;
- (void)customDismissLoginPage:(UIViewController *)viewController appearance:(id<aluTaobaoLoginPageAppearance>)appearance;

//帐号登录下拉框设计左边距离设置
- (CGFloat)textFieldLeftMargin;

@required

// 历史界面只有此设置
- (CGFloat)setScrollViewPaddingTop;

// 登陆区块设置 
// 此frame相对于整个content view设置
- (CGRect)loginBoxFrame;
- (UIView *)loginBoxBackgroundView;

// 此frame相对于login box设置
- (CGRect)usernameTextFieldFrame;
- (NSString *)usernamePlaceholder;

// 此frame相对于login box设置
- (CGRect)passwordTextFieldFrame;
- (NSString *)passwordPlaceholder;

// 验证码区块设置
// 此frame相对于整个content view设置
- (CGRect)verifyCodeBoxFrame;
- (UIView *)verifyCodeBoxBackgroundView;

// 此frame相对于整个verifyCodeBox设置
- (CGRect)verifyCodeImageViewFrame;

// 此frame相对于整个verifyCodeBox设置
- (CGRect)verifyCodeInputTextFieldFrame;
- (NSString *)verifyCodeInputTextFieldPlaceholder;

@optional
// 是否需要刷新按钮，默认是NO，没有的话，点击验证码刷新。刷新验证码的过程中，如果有刷新按钮的话SDK会旋转刷新按钮提示正在刷新中
- (BOOL)needVerifyRefreshButton;
- (CGRect)verifyRefreshButtonFrame;
- (UIImage *)verifyRefreshButtonNormalImage;
- (UIImage *)verifyRefreshButtonHighlightImage;

//ipad定制
- (CGRect)regButtonFrameWithOriginalFrame:(CGRect)frame;
- (CGRect)retrieveButtonFrameWithOriginalFrame:(CGRect)frame;

//是否需要账户的下拉历史列表
- (BOOL)needUserIdDropDownList;

//loginbox的背景单独设置
- (UIView *)usernameBackgroundView;
- (UIView *)passwordBackgroundView;

//千牛旺信缓冲跳转
- (void)bufferLoginWaiting:(LoginWaitBlock) block;

//关闭企业注册接口
- (BOOL)needCloseEnterpriseReg;

@end
