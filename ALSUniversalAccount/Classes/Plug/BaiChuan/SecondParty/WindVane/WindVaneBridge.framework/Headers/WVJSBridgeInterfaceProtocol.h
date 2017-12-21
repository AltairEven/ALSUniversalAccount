/*
 * WVJSBridgeInterfaceProtocol.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVBridgeProtocol.h>

/*************************************************************************************
 * 请移步 <WindVaneBridge/WVBridgeProtocol.h>
 * 这里的用法是准备废弃的，请总是使用 WVBridgeHandler
*************************************************************************************/

#define MSG_RET_EXP MSG_RET_EXCEPTION
#define WV_JSB_DEFINE_INSTANCE(NAME) -(void)NAME : (NSDictionary *)params withCallback : (WVJSBResponse)callback withWebView : (UIView<WVWebViewBasicProtocol> *)webview withViewController : (UIViewController *)viewController
#define WV_JSB_DEFINE_STATIC(NAME) +(void)NAME : (NSDictionary *)params withCallback : (WVJSBResponse)callback withWebView : (UIView<WVWebViewBasicProtocol> *)webview withViewController : (UIViewController *)viewController
#define WV_JSB_CALLBACK(CALLBACK, RET, RESULT) \
	do {                                       \
		if (CALLBACK) {                        \
			CALLBACK(RET, RESULT);             \
		}                                      \
	} while (0)
#define WV_JSB_CALLBACK_RETURN(CALLBACK, RET, RESULT) \
	{                                                 \
		if (CALLBACK) {                               \
			CALLBACK(RET, RESULT);                    \
		}                                             \
		return;                                       \
	}
#define WV_JSB_CALLBACK_PARAM_ERR_RETURN(MSG) WV_JSB_CALLBACK_RETURN(callback, MSG_RET_PARAM_ERR, @{ MSG_RESULT_MSG_NAME : MSG });
#define WV_JSB_CALLBACK_INVALID_PARAM_RETURN(PARAM_NAME) WV_JSB_CALLBACK_RETURN(callback, MSG_RET_PARAM_ERR, @{ MSG_RESULT_MSG_NAME : @"Invalid parameter " PARAM_NAME "." });
#define WV_JSB_CHECK_PARAMS_RETURN()                            \
	do {                                                        \
		if (!params || params.count <= 0) {                     \
			WV_JSB_CALLBACK_PARAM_ERR_RETURN(@"No parameter."); \
		}                                                       \
	} while (0)
#define WV_JSB_CALLBACK_NOT_SUPPORTED_RETURN(METHOD) WV_JSB_CALLBACK_RETURN(callback, MSG_RET_FAILED, @{ MSG_RESULT_MSG_NAME : METHOD @" is not supported." });

/**
 * 动态 JSBridge 的实例作用域，与 WVBridgeScope 完全等价。
 * 建议使用 WVBridgeScope 的相应值。
 */
typedef WVBridgeScope WVJSBridgeScope;
enum {
	WVJSBridgeScopeInvocation = WVBridgeScopeInvocation,
	WVJSBridgeScopePage = WVBridgeScopePage,
	WVJSBridgeScopeWebView = WVBridgeScopeView,
	WVJSBridgeScopeStatic = WVBridgeScopeStatic,
};
typedef WVBridgeCallback WVJSBResponse;

// 命名错误的宏
#define MSG_USER_DENIED       MSG_RET_USER_DENIED
#define MSG_USER_CANCELED     MSG_RET_USER_CANCELED
