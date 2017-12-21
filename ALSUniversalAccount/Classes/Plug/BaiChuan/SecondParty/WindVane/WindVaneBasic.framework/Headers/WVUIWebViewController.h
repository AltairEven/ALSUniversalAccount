/*
 * WVUIWebViewController.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVRuleWebViewController.h"
#import "WVWebViewControllerProtocol.h"
#import <UIKit/UIKit.h>

#pragma mark - Constant

// 错误页面背景图片名称。
#define WVUIVC_ERROR_BACKGROUND_IMG @"WindVaneResource.bundle/wifi"
// WebView 背景图片名称。
#define WVUIVC_BACKGROUND_IMG @"WindVaneResource.bundle/all_bg_small"
// 顶部下拉刷新箭头图片名称。
#define WVUIVC_ARROW_IMG @"WindVaneResource.bundle/upload1"
// 工具栏最左边第一个返回按钮图片名称。
#define WVUIVC_TOOLBAR_POP_IMG @"WindVaneResource.bundle/toolbar_webview_back"
// 工具栏后退按钮图片名称。
#define WVUIVC_TOOLBAR_BACK_IMG @"WindVaneResource.bundle/toolbar_webview_pre"
// 工具栏前进按钮图片名称。
#define WVUIVC_TOOLBAR_NEXT_IMG @"WindVaneResource.bundle/toolbar_webview_next"
// 工具栏停止按钮图片名称。
#define WVUIVC_TOOLBAR_STOP_IMG @"WindVaneResource.bundle/toolbar_webview_stop"
// 工具栏刷新按钮图片名称。
#define WVUIVC_TOOLBAR_REFRESH_IMG @"WindVaneResource.bundle/toolbar_webview_refresh"
// 工具栏背景图片名称。
#define WVUIVC_TOOLBAR_BACKGROUND_IMG @"WindVaneResource.bundle/toolbar_webview_background"

#pragma mark - WVUIWebViewController

/**
 * 提供了 WindVane WebView UI 扩展的 ViewController。
 */
@interface WVUIWebViewController : WVRuleWebViewController <WVWebViewControllerProtocol>

#pragma mark - WebView

/**
 * 需要在 viewDidLoad 时自动加载的页面请求，会与 loadUrl 同步变化。
 */
@property (nonatomic, copy, nullable) NSURLRequest * loadRequest;

/**
 * 需要在 viewDidLoad 时自动加载的页面地址，会与 loadRequest 同步变化。
 */
@property (nonatomic, copy, nullable) NSString * loadUrl;

/**
 * 自定义导航栏高度 - 用于计算 WebView 高度。
 */
@property (nonatomic, assign) CGFloat navBarHeight;

/**
 * 自定义 TabBar 高度 - 用于计算 WebView 高度。
 */
@property (nonatomic, assign) CGFloat tabBarHeight;

#pragma mark - Status Bar

/**
 隐藏导航栏时，Status Bar 背景的颜色，默认为 nil。
 
 @discussion iOS 7 的 Status Bar 在导航栏隐藏的时候会背景透明，与 WebView 中的内容遮盖。
 如果希望为 Status Bar 添加一个不透明背景，可以设置此属性为需要的颜色。
 自 iOS11 后，iPhoneX 的机型状态栏高度变为 44pt，不再适合自动设置状态栏高度，应当由前端主动填充合适的背景，让状态栏与背景融合起来。
 */
@property (nonatomic, strong, nullable) UIColor * statusBarColor NS_DEPRECATED_IOS(7_0, 10_0);

/**
 [iOS 7 适配] 隐藏导航栏时，为 Status Bar 添加白色背景颜色。
 
 @discussion 自 iOS11 后，iPhoneX 的机型状态栏高度变为 44pt，不再适合自动设置状态栏高度，应当由前端主动填充合适的背景，让状态栏与背景融合起来。
 */
- (void)supportiOS7WithoutStatusBar NS_DEPRECATED_IOS(7_0, 10_0);

#pragma mark - Toolbar

/**
 * 是否使用带有前进、后退、刷新、停止基本浏览器功能的默认工具栏，默认为 NO。
 */
@property (nonatomic, assign, getter=isUseToolbar) BOOL useToolbar;

/**
 * 工具栏。
 */
@property (nonatomic, strong, readonly, nullable) WVWebViewToolbar * toolbar;

/**
 * 工具栏的高度，默认为 40px。
 */
@property (nonatomic, assign) CGFloat toolbarHeight;

/**
 * 是否动态显示工具栏。
 */
@property (nonatomic, assign) BOOL showToolBarDynamic;

/**
 * 是否仅在发生错误的时候，才使用工具栏，无错误发生的时候，一直隐藏起来。
 * 仅在 useToolbar=YES 时候生效。
 */
@property (nonatomic, assign, getter=isUseToolbarOnlyError) BOOL useToolbarOnlyError;

/**
 * 点击工具栏左边第一个按钮要执行的方法，默认为 pop 当前 ViewController。
 */
- (void)goFirstClicked;

/**
 * 隐藏默认的工具栏。
 */
- (void)hiddenToolBar;

/**
 * 显示默认的工具栏。
 */
- (void)showToolBar;

/**
 * 如果需要提供自己的工具栏，请设置 useToolbar=NO，然后自行提供工具栏，并设置以下的属性。
 * 会自动根据当前 WebView 状态，设置按钮的 enabled。
 */
/**
 * 自定义的回退按钮。
 */
@property (nonatomic, weak, nullable) id customToolBarGoBackButton;

/**
 * 自定义的前进按钮。
 */
@property (nonatomic, weak, nullable) id customToolBarGoForwardButton;

/**
 * 自定义的停止按钮。
 */
@property (nonatomic, weak, nullable) id customToolBarStopLoadingButton;

/**
 * 自定义的刷新按钮。
 */
@property (nonatomic, weak, nullable) id customToolBarRefreshButton;

#pragma mark - 定制错误页

/**
 * 显示错误页。
 * 允许由子类重写以自定义错误页。
 *
 * @param webView 产生错误的 WebView。
 * @param error   错误信息。
 */
- (void)showErrorView:(UIView<WVWebViewProtocol> * _Nonnull)webView didFailLoadWithError:(NSError * _Nonnull)error;

/**
 * 隐藏错误页。
 * 允许由子类重写以自定义错误页。
 */
- (void)removeErrorView;

#pragma mark - 定制加载框

/**
 * 是否显示加载框，默认为 YES。
 * 可以设置为 NO 不显示加载框，此时可以使用 KVO 监听 WebView.estimatedProgress 的改变，实现加载进度。
 */
@property (nonatomic, assign, getter=isShowLoadingBox) BOOL showLoadingBox;

/**
 * 显示加载框。
 * 允许由子类重写以自定义加载框。
 */
- (void)showLoadingBox;

/**
 * 使用指定的标题显示加载框。
 * 允许由子类重写以自定义加载框。
 */
- (void)showLoadingBoxWithTitle:(NSString * _Nullable)title;

/**
 * 隐藏加载框。
 * 允许由子类重写以自定义加载框。
 */
- (void)hiddenLoadingBox;

#pragma mark - 设备旋转

/**
 * 支持的设备旋转方向。
 * 设置为 0 会使用系统默认的设备旋转方向，客户端可能需要自行重写设置方法，才能实现完整的转屏适配。
 */
@property (nonatomic, assign) UIInterfaceOrientationMask interfaceOrientationMask;

/**
 * 首选的设备旋转方向。
 */
@property (nonatomic, assign) UIInterfaceOrientation preferredInterfaceOrientation;

#pragma mark - 已废弃，预计于 2018.8.1 删除

- (void)showAlert:(NSString * _Nullable)msg DEPRECATED_MSG_ATTRIBUTE("不再支持");
// 设置工具栏样式，请直接设置 toolbar 的相关属性，不再使用覆盖方法的方式。
- (float)getToolBarHeight DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbarHeight 属性");
- (UIImage * _Nullable)getToolBarBackgroundImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 backgroundImage 属性");
- (UIImage * _Nullable)getFastTargetBtnImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 firstButtonImage 属性");
- (UIImage * _Nullable)getGoBackBtnImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 backButtonImage 属性");
- (UIImage * _Nullable)getGoForwardBtnImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 forwardButtonImage 属性");
- (UIImage * _Nullable)getRefreshBtnImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 stopButtonImage 属性");
- (UIImage * _Nullable)getStopLoadBtnImage DEPRECATED_MSG_ATTRIBUTE("请直接设置 toolbar 的 refreshButtonImage 属性");

- (UIColor * _Nullable)getBackgroundColor DEPRECATED_MSG_ATTRIBUTE("不再支持"); // 不会再被调用。
// 已废弃，请在 configPullToRefreshStyle 中自行设置下拉刷新组件的相关样式属性。
- (UIImage * _Nullable)getArrowImage DEPRECATED_MSG_ATTRIBUTE("不再支持");
- (float)getArrowHeight DEPRECATED_MSG_ATTRIBUTE("不再支持");
- (float)getArrowWidth DEPRECATED_MSG_ATTRIBUTE("不再支持");
- (UIColor * _Nullable)getTopArrowTxtColor DEPRECATED_MSG_ATTRIBUTE("不再支持");   // 不会再被调用。
- (UIFont * _Nullable)getPullRefreshFontSize DEPRECATED_MSG_ATTRIBUTE("不再支持"); // 不会再被调用。
- (void)resumUsePullRefresh DEPRECATED_MSG_ATTRIBUTE("请设置 usePullToRefresh 属性为 YES");

@end
