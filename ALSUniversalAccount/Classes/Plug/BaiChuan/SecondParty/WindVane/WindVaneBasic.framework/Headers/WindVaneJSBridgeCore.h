/*
 * WindVaneJSBridgeCore.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVBridgeProtocol.h>
#import <WindVaneBridge/WVJSBridgeInterfaceProtocol.h>

/*************************************************************************************
 * 请移步 <WindVaneBridge/WVBridgeProtocol.h>
 * 这里的用法是准备废弃的，请总是使用 WVBridgeHandler
*************************************************************************************/

typedef void (^WVJSBridgeHandler)(NSDictionary * params, WVJSBResponse callback, UIView<WVWebViewBasicProtocol> * webview, UIViewController * viewController);
typedef void (^WVPrivateJSBridgeHandler)(NSDictionary * params, WVJSBResponse callback);
typedef void (^WVJSBHandler)(NSString * data, WVJSBResponse wvJSBResponseCallback, UIViewController * sourceViewController, UIWebView * webView);
typedef void (^WVPrivateJSBHandler)(NSString * data, WVJSBResponse wvJSBResponseCallback);
typedef void (^WVJSBResetHandler)(UIViewController * sourceViewController, UIWebView * webView);
typedef void (^WVJSBDeallocHandler)(UIViewController * sourceViewController, UIWebView * webView);

// 因为存在对 self 的强引用，所以很容易导致循环引用，因此不再提供。
// #define WV_JSB_RELEASE_SERVICE ;

DEPRECATED_ATTRIBUTE
@interface WindVaneJSBridgeCore : NSObject
+ (NSString *)parseJSBHandlerName:(NSURLRequest *)request DEPRECATED_ATTRIBUTE;
+ (NSString *)parseJSBHandlerClassName:(NSURLRequest *)request DEPRECATED_ATTRIBUTE;
+ (NSString *)parseJSBHandlerIfid:(NSURLRequest *)request DEPRECATED_ATTRIBUTE;
+ (NSString *)parseJSBHandlerParam:(NSURLRequest *)request DEPRECATED_ATTRIBUTE;
@end
