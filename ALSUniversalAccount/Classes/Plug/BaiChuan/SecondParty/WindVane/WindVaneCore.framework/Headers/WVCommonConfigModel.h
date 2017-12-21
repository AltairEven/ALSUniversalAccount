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
 * 执行异常恢复的间隔（毫秒），默认为 5 天。
 */
@property (nonatomic, assign) NSInteger recoveryInterval;

/**
 * Monitor 的功能状态，默认为 WVModuleStatusOpenedAndUpdate。
 */
@property (nonatomic, assign) WVModuleStatus monitorStatus;

/**
 * URL 拦截的功能状态，默认为 WVModuleStatusOpenedAndUpdate。
 */
@property (nonatomic, assign) WVModuleStatus urlRuleStatus;

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
 * 最大的 WebView 复用数量，UIWebView 和 WKWebView 会分别做复用。
 */
@property (nonatomic, assign) NSUInteger recycleCount;

/**
 * 在切换后台时是否自动暂停 WebGL，默认为 YES。
 */
@property (nonatomic, assign) BOOL autoPauseWebGL;

/**
 * 要排除 Native Bridge 的版本正则表达式，默认为 nil。
 */
@property (nonatomic, copy) NSString * injectBridgeExclusion;

/**
 * 是否主动监听 meta 的改变，默认为 YES。
 */
@property (nonatomic, assign) BOOL watchMeta;

/**
 * 当前版本是否要注入 Native Bridge。
 */
@property (nonatomic, assign, readonly) BOOL shouldInjectBridge;

/**
 * 修复 iOS 9.3.X MutationObserver Crash 问题的 JS 路径。
 */
@property (nonatomic, copy) NSString * mutationObserverFixJSPath;

#pragma mark - PackageApp

/**
 * PackageApp 功能状态。
 */
@property (nonatomic, assign) WVModuleStatus packageAppStatus;

/**
 * PackageApp 的 Zip 前缀。
 */
@property (nonatomic, copy) NSString * packageZipPrefix;

/**
 * PackageApp 的预览 Zip 前缀。
 */
@property (nonatomic, copy) NSString * packageZipPreviewPrefix;

/**
 * PackageApp 的安全校验率，键为 AppName，值为安全校验率（double [0 - 1]）。
 */
@property (nonatomic, copy) NSDictionary * verifySampleRate;

/**
 * PackageApp 单次下载个数限制。
 */
@property (nonatomic, assign) NSInteger packageDownloadLimit;

/**
 * PackageApp 本地最多个数限制。
 */
@property (nonatomic, assign) NSUInteger packageMaxAppCount;

/**
 * 预加载 App 优先级的权重。
 */
@property (nonatomic, assign) double packagePriorityWeight;

/**
 * PackageApp 统计的间隔。
 */
@property (nonatomic, assign) NSInteger packageAccessInterval;

/**
 * PackageApp 执行清理的间隔。
 */
@property (nonatomic, assign) NSInteger packageRemoveInterval;

/**
 * Package 个性化 App 直接查询更新的个数限制。
 */
@property (nonatomic, assign) NSUInteger customsDirectQueryLimit;

/**
 * Package 个性化 App 的 Combo 个数限制。
 */
@property (nonatomic, assign) NSUInteger customsComboLimit;

/**
 * 是否检查淘汰。
 */
@property (nonatomic, assign) BOOL isCheckCleanup;

/**
 * 是否开启 Combo 功能。
 */
@property (nonatomic, assign) BOOL isOpenCombo;

/**
 * 是否自动注册个性化预加载 App。
 */
@property (nonatomic, assign) BOOL isAutoRegisterApp;

@end
