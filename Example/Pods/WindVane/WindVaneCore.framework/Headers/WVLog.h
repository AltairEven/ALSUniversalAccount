/*
 * WVLog.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVUserConfig.h"
#import <Foundation/Foundation.h>

#pragma mark - WindVane Modules

// WindVane 模块名称。
typedef NS_ENUM(NSInteger, WVModuleName) {
	WVModuleCore,       // Core 模块。
	WVModuleConfig,     // Core 模块的配置功能。
	WVModuleBridge,     // Bridge 模块。
	WVModuleBasic,      // Basic 模块。
	WVModuleAPI,        // API 模块。
	WVModulePackageApp, // PackageApp 模块。
	WVModuleTBExt,      // TBExtension 模块。
	WVModuleJS,         // JS 模块。
	WVModuleNoName,     // 无模块名称。
	WVModuleExtra,      // 额外模块。
};

#pragma mark - WVExternalLogProtocol

/**
 * WindVane 的外部日志协议，用于将日志输出到外部。
 */
@protocol WVExternalLogProtocol <NSObject>

@required

/**
 * 外部日志的级别。
 * 保证在输出日志前正确的检查日志级别。
 */
- (WVLogLevel)logLevel;

/**
 * 输出 Error 日志。
 */
- (void)error:(NSString *)message;

/**
 * 输出 Warn 日志。
 */
- (void)warn:(NSString *)message;

/**
 * 输出 Info 日志。
 */
- (void)info:(NSString *)message;

/**
 * 输出 Debug 日志。
 */
- (void)debug:(NSString *)message;

/**
 * 输出 Verbose 日志。
 */
- (void)verbose:(NSString *)message;

@end

#pragma mark - WVLog

/**
 * WindVane 的日志类。
 */
@interface WVLog : NSObject

/**
 * 注册指定的外部日志。
 */
+ (void)registerExternalLog:(id<WVExternalLogProtocol>)externalLog;

/**
 * 获取已注册的外部日志。
 */
+ (id<WVExternalLogProtocol>)registeredExternalLog;

/**
 * 检查指定级别的日志是否可以输出。
 * 一般情况下无需调用此方法，仅当需要做复杂的日志拼接时使用。
 *
 * @param level 要检查的日志级别。
 *
 * @return 如果可以输出，则为 YES；否则为 NO。
 */
+ (BOOL)checkLogLevel:(WVLogLevel)level;

/**
 * 返回远程日志是否开启。
 * 在远程日志未开启时，可以避免一些不需要的日志格式化。
 */
+ (BOOL)remoteLogEnabled;

/**
 * 写入到指定的远程日志。
 * 通过这里写入的日志，支持通过 http://wapp.m.taobao.com/app/windvane/log.html 实时查看。
 *
 * @param message 日志消息。
 * @param level   日志级别，有效值有 Error、Warn、Info、Debug 和 Verbose。
 * @param module  日志模块，请正确传入业务方标识，例如 Weex、WindVane 等。
 */
+ (void)writeRemoteLog:(NSString *)message withLevel:(NSString *)level withModule:(NSString *)module;

@end

#pragma mark - WVLog Globacl Functions

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 输出 Error 日志。
 */
void WVLogError(WVModuleName module, NSString * format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 * 输出 Warn 日志。
 */
void WVLogWarn(WVModuleName module, NSString * format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 * 输出 Info 日志。
 */
void WVLogInfo(WVModuleName module, NSString * format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 * 输出 Debug 日志。
 */
void WVLogDebug(WVModuleName module, NSString * format, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 * 输出 Verbose 日志。
 */
void WVLogVerbose(WVModuleName module, NSString * format, ...) NS_FORMAT_FUNCTION(2, 3);

#ifdef __cplusplus
}
#endif
