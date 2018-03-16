/*
 * WVCommonConfigModel.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVConfigModel.h"
#import <Foundation/Foundation.h>

// WindVane 功能状态。
typedef NS_ENUM(NSInteger, WVModuleStatus) {
	WVModuleStatusClosed = 0,         // 功能被关闭。
	WVModuleStatusOpened = 1,         // 功能开启。
	WVModuleStatusOpenedAndUpdate = 2 // 功能开启且会自动更新配置。
};

/**
 * WindVane 公共配置。
 */
@interface WVCommonConfigModel : WVConfigModel

/**
 * 要补全的 URL Scheme，默认为 @"http:"。
 */
@property (nonatomic, copy) NSString * urlScheme;

/**
 * Monitor 的功能状态，默认为 WVModuleStatusOpenedAndUpdate。
 */
@property (nonatomic, assign) WVModuleStatus monitorStatus;

/**
 * URL 拦截的功能状态，默认为 WVModuleStatusOpenedAndUpdate。
 */
@property (nonatomic, assign) WVModuleStatus urlRuleStatus;
/**
 * PackageApp 功能状态。
 */
@property (nonatomic, assign) WVModuleStatus packageAppStatus;

/**
 * 配置更新的时间间隔（毫秒），默认为 5 分钟。
 */
@property (nonatomic, assign) NSInteger configUpdateInterval;

#pragma mark - Bridge

/**
 * 是否允许跨页面的 WVBridge 调用，默认为 NO。
 */
@property (nonatomic, assign) BOOL allowCrossPageBridgeInvocation;

#pragma mark - WebView

/**
 * 在切换后台时是否自动暂停 WebGL，默认为 YES。
 */
@property (nonatomic, assign) BOOL autoPauseWebGL;

/**
 * 要排除 Native Bridge 的版本正则表达式，默认为 nil。
 */
@property (nonatomic, copy) NSString * nativeBridgeExclusion;

/**
 * 是否主动监听 meta 的改变，默认为 YES。
 */
@property (nonatomic, assign) BOOL watchMeta;

/**
 当前版本是否要注入 Native Bridge。
 */
@property (nonatomic, assign, readonly) BOOL useNativeBridge;

/**
 * 修复 iOS 9.3.X MutationObserver Crash 问题的 JS 路径。
 */
@property (nonatomic, copy) NSString * mutationObserverFixJSPath;

/**
 是否在 VC Appear 时同步 WKWebView 的 Cookie，默认为 NO。
 */
@property (nonatomic, assign, readonly) BOOL syncWKCookieWhenAppear;

/**
 是否在 NSHTTPCookieStorage 发生变化时时同步 WKWebView 的 Cookie，性能消耗较大，默认为 NO。
 */
@property (nonatomic, assign, readonly) BOOL syncWKCookieWhenChanged;

@end
