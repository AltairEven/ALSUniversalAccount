/*
 * WVUserContentController.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WindVaneBridge.h>

#pragma mark - WVUserScript

/**
 * 可以注入到 Web 页面的自定义脚本。
 */
@interface WVUserScript : NSObject

/**
 * 当前自定义脚本的键。
 */
@property (nonatomic, copy, nullable) NSString * key;

/**
 * 要注入的 JavaScript 源码。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * source;

/**
 * 使用要注入的 JavaScript 源码初始化。
 */
- (instancetype _Nonnull)initWithSource:(NSString * _Nonnull)source;

/**
 * 使用要注入的 JavaScript 源码 URL 初始化。
 */
- (instancetype _Nonnull)initWithSourceURL:(NSString * _Nonnull)sourceURL;

@end

#pragma mark - WVUserContentController

/**
 * 自定义内容控制器。
 */
@interface WVUserContentController : NSObject

/**
 * 全局自定义内容控制器，可以应用到所有 WebView 上。
 */
+ (instancetype _Nonnull)globalController;

/**
 * 在指定 WebView 中注入自定义脚本。
 */
+ (void)inject:(WVUserContentController * _Nullable)userScriptController toWebView:(UIView<WVWebViewBasicProtocol> * _Nonnull)webView;

/**
 * 获取自定义脚本列表。
 */
- (NSArray<WVUserScript *> * _Nonnull)userScripts;

/**
 * 增加指定的自定义脚本。
 */
- (void)addUserScript:(WVUserScript * _Nonnull)userScript;

/**
 * 增加指定的自定义脚本源码。
 *
 * @param source 自定义脚本源码。
 */
- (void)addUserScriptSource:(NSString * _Nonnull)source;

/**
 * 增加指定的自定义脚本源码。
 *
 * @param source 自定义脚本源码。
 * @param key    自定义脚本的键。
 */
- (void)addUserScriptSource:(NSString * _Nonnull)source withKey:(NSString * _Nullable)key;

/**
 * 删除具有指定键的自定义脚本。
 *
 * @param key 自定义脚本的键。
 */
- (void)removeUserScriptByKey:(NSString * _Nonnull)key;

/**
 * 删除所有自定义脚本。
 */
- (void)removeAllUserScripts;

@end
