//
//  TBWVUserTrack.h
//  TBWebViewBundle
//
//  Created by 隐风 on 14-5-12.
//  Copyright (c) 2014年 TB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVane/WindVane.h>
//#import <WVPluginFramework/WVDynamicHandler.h>

@interface WVTBUserTrack : WVDynamicHandler

/**
 *  连接UT和H5的接口
 *
 *  @param data
 */
+ (void)toUT:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

/**
 *  运行时开始实时调试模式接口
 *
 *  @param data
 */
//+ (void)turnOnUTRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

/**
 *  运行时关闭实时调试模式接口
 *
 *  @param data
 */
//+ (void)turnOffUTRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

//+ (void)turnOnAppMonitorRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

//+ (void)turnOffAppMonitorRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

+ (void)turnOnRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

+ (void)turnOffRealtimeDebug:(NSDictionary*)data withCallback:(WVJSBResponse) callback withWebView:(UIWebView *) webview withViewController:(UIViewController *) viewController;

@end
