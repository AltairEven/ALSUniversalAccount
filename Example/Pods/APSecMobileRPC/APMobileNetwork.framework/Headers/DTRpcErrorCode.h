//
//  DTRpcErrorCode.h
//  APMobileNetwork
//
//  Created by WenBi on 13-5-13.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum DTRpcErrorCode
{
	
	/** 网络连接错误。*/
	kDTRpcNetworkError,
	
	/** 服务端返回的数据为空。 */
	kDTRpcEmptyResponse,
	
	/** 服和端返回的 JSON 字符串格式不正确，不能成功转换成 JSON 对象。 */
	kDTRpcInvalidJSONString,
	
	/** 反序列化 JSON 对象出错。*/
	kDTRpcDecodeObjectError,
	
	/** 网络已取消。 */
	kDTRpcNetworkCancelled,
    
    /** 序列化 JSON 对象出错。*/
    kDTRpcEncodeObjectError,
	
    /** 反序列化 PB 对象出错。*/
    kDTRpcProtocolBuffersDecodeError,
    
    /** 启动后的RPC没在白名单内的RPC被拦截,启动时候调用RPC需要申请白名单*/
    kDTRpcFilterRPCInAppLaunch,
    
    /** 应用在后台且此时不建连 此时rpc不发送直接抛异常*/
    KDTRpcUnderBackgroundFetch,
    
    /** RPC大小太大了直接抛异常*/
    KDTRpcSizeControlError,
} DTRpcErrorCode;


//错误码:1002，排队人太多了，请稍后再试。处理免登时失败返回1002需要弹到登录界面的情况
#define kAPMobileNetworkReponseErrorCode1002Notification @"APMobileNetworkReponseErrorCode1002Notification"




