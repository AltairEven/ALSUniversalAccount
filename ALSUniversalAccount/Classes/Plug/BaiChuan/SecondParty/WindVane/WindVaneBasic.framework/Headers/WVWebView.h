/*
 * WVWebView.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVWebViewDelegate.h"
#import "WVWebViewProtocol.h"
#import "WindVaneJSBridgeCore.h"
#import <UIKit/UIKit.h>

@interface WVWebView : UIWebView <WVWebViewProtocol>

/*!
 * 挂载的归属源 UIViewController
 */
@property (nonatomic, weak) UIViewController * sourceViewController;

#pragma mark - Configuration

/**
 * 获取当前 WebView 加载页面的 title。
 */
@property (nonatomic, copy, readonly) NSString * title;

/**
 * 当前 WebView 是否启用 WebGL。
 *
 * @discussion 在应用切后台时自动关闭，切回前台后自动打开。
 * 关闭的话，会使 canvas.getContext('webgl') 返回 null，但是并不会停用已拿到的 WebGLRenderingContext 的功能。
 * 所以此开关仅能部分避免切后台后 JS 调用 WebGL 导致的 Crash，与 H5 的具体用法有关。
 */
@property (nonatomic, assign, getter=isWebGLEnabled) BOOL webGLEnabled;

#pragma mark - Delegate

/**
 * 当前 WebView 的委托。
 */
@property (nonatomic, weak) id<WVWebViewDelegate> windVaneDelegate;

#pragma mark - Life cycle

/**
 * [注意：必须在 ViewController 的 viewWillDisappear 中调用!!!] 释放 WebView 的服务。
 */
- (void)releaseWebViewService;

/**
 * [注意：必须在 ViewController 的 viewWillAppear 中调用!!!] 重新绑定 WebView 的服务。
 */
- (void)bindingWebViewService;

/**
 将当前 WebView 恢复成初始化时的状态，可以之后复用 WebView。
 */
- (void)recycle;

/**
 准备重新使用当前 WebView，必须在重新使用前调用。
 */
- (void)reuse;

#pragma mark - JSBridge

/**
 * 是否开启 JSBridge 服务，默认为 NO。
 */
@property (nonatomic, assign, getter=isOpenLocalService) BOOL openLocalService;

#pragma mark - URL Interrupted

/*!
 * 关闭URL拦截解析服务
 */
+ (void)closeURLInterruptedModule;

/*!
 * 开启URL拦截解析服务
 */
+ (void)openURLInterruptedModule;

/*!
 * URL拦截解析服务是否开启
 */
+ (BOOL)isOpenURLInterruptedModule;

/*!
 * 从 Request 中获取 body
 */
+ (NSString *)getRequestBodyForPost:(NSURLRequest *)request;

/*!
 * 判断是否是 Post 请求
 */
+ (BOOL)isPostRequest:(NSURLRequest *)request;

@end
