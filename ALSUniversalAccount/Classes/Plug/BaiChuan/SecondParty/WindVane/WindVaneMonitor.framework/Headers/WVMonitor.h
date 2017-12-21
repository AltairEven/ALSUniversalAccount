/*
 * WVMonitor.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, WVMonitorOption) {
	/**
	 * H5 监控，用于监控 H5 性能和加载。
	 */
	WVMonitorOptionH5 = 1 << 0,
	/**
	 * PackageApp 监控，用于监控 PackageApp 安装情况。
	 */
	WVMonitorOptionPackage = 1 << 1,
	/**
	 * 配置监控，用于监控 WindVane 配置更新情况。
	 */
	WVMonitorOptionConfig = 1 << 2,
	/**
	 * WebView 监控，用于监控 WebView 情况。
	 */
	WVMonitorOptionWebView = 1 << 3,
	/**
	 * WVBridge 监控，用于监控 WVBridge 调用情况。
	 */
	WVMonitorOptionBridge = 1 << 4,
	// 待废弃
	WVMonitorOptionPerformance = WVMonitorOptionH5,
	WVMonitorOptionError = WVMonitorOptionH5,
	WVMonitorOptionJSBridge = WVMonitorOptionBridge,
};

/**
 * 初始化 WindVane Monitor 模块。
 * WindVane 埋点支持库，提供了埋点的 UT 通道，允许将 WindVane 的埋点情况上传到魔兔平台，包括 H5 性能埋点，错误埋点，JSBridge 埋点和预加载埋点等。
 */
@interface WVMonitor : NSObject

/**
 * 初始化 WindVane Monitor 模块，会启用所有监控模块。
 */
+ (void)startMonitoring;

/**
 * 初始化 WindVane Monitor 模块，会启用指定的监控模块。
 *
 * @param options 需要启用的监控模块，用 "|" 符号连接。
 */
+ (void)startMonitoringWithOptions:(WVMonitorOption)options;

@end
