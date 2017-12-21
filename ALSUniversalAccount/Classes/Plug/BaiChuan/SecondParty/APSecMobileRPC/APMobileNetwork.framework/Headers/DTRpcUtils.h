//
//  DTRpcUtils.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "DTRpcErrorCode.h"
extern NSString * const NSLocalizedAlertKey;
@class DTRpcMethod;
/*
 * Creates an error object according to specified code, failure reason and description.
 *
 * @param code Error code.
 * @param reason A string containing the localized explanation of the reason for the error.
 * @param description A string containing the localized description of the error.
 *
 * @return An \code NSError object.
 */
NSError* DTRpcCreateError(DTRpcErrorCode code, NSString *reason, NSString *description);

/*
 * Creates an error object according to specified code, failure reason and description.
 *
 * @param code Error code.
 * @param reason A string containing the localized explanation of the reason for the error.
 * @param description A string containing the localized description of the error.
 *
 * @return An \code NSError object.
 */
NSError* DTRpcCreateErrorWithAlert(DTRpcErrorCode code, NSString *reason, NSString *description,NSString *alert);

/*
 * Creates an error object according to specified code, failure reason, description and cause error.
 *
 * @param code Error code.
 * @param reason A string containing the localized explanation of the reason for the error.
 * @param description A string containing the localized description of the error.
 * @param causeError Cause Network Error
 *
 * @return An \code NSError object.
 */
NSError * DTRpcCreateErrorWithCause(DTRpcErrorCode code, NSString *reason, NSString *description, NSError *causeError);


/**
 *  限流产生的错误
 *
 * @param code Error code.
 * @param reason A string containing the localized explanation of the reason for the error.
 * @param description A string containing the localized description of the error.
 *  @param controlStr  A dictionary containing traffic control info.
 *
 *  @return An \code NSError object.
 */
NSError * DTRpcCreateFlowControlError(DTRpcErrorCode code, NSString *reason, NSString *description, NSDictionary* controlDic);

@interface DTRpcUtils : NSObject

/*
 * Creates an error object according to specified code, failure reason and description.
 *
 * @param code Error code.
 * @param reason A string containing the localized explanation of the reason for the error.
 * @param description A string containing the localized description of the error.
 *
 * @return An \code NSError object.
 */
//+ (NSError *)errorWithCode:(DTRpcErrorCode)code reason:(NSString *)reason description:(NSString *)description;

/*
 * Creates an initialized URL request with specified values.
 *
 * @param aURL The URL for the new request.
 *
 * @return The newly created URL request.
 */
//+ (NSMutableURLRequest *)mutableURLRequestWithURL:(NSURL *)aURL;

/**
 *  RPC Default Timeout
 *
 *  @return timeout s
 */
+ (NSTimeInterval)requestTimeout;

/**
 *  RPC URL Is Online
 *
 *  @param urlString url
 *
 *  @return yes or no
 */
+(BOOL) isRpcURLOnline:(NSString *)urlString;
/**
 *  获取md5key
 *
 *  @param method 业务提供method
 *  @param params 参数
 *
 *  @return md5key字符串
 */
+(NSString*)rpcKeyWithMethod:(DTRpcMethod *)method params:(NSArray *)params;
/**
 *
 *  @return 获取productID
 */
+(NSString*)productID;
//+(NSString *)DateToLongString;
/**
 *
 *  @return cookie开关
 */
+(BOOL)cookieSwitch;
/**
 *
 *  @return amrpc开关
 */
+(BOOL)amrpcSwitch;
/**
 *
 *  @return 时间戳
 */
+(NSString*)timestampLogger;
/**
 *  host转ip
 *
 *  @param host 主机名
 *
 *  @return ip
 */
+(NSString*)hostToIP:(NSString*)host;
/**
 *  是否持久化cookie
 */
+(BOOL)storageCookie;
/**
 *  urlRequest中添加ProductVersion
 *
 *  @param urlRequest
 */
+(void)addProductVersion:(NSMutableURLRequest*)urlRequest;
/**
 *  urlRequest中添加userId
 *
 *  @param urlRequest
 */
+(void)adduserId:(NSMutableURLRequest*)urlRequest;
/**
 *  根据data获取md5值
 *
 *  @param data
 *
 *  @return md5值
 */
+ (NSString *)MD5String:(NSData*)data;
/**
 *  GZip压缩
 *
 *  @param input 压缩前
 *
 *  @return 压缩后
 */
+ (NSData*)compressGZip:(NSData*)input;
/**
 *  是否使用新的签名
 *
 *  @return
 */
+ (BOOL)useNewSign;
/**
 *  往可重试列表添加operationType
 *
 *  @param operationType
 *  @param resend   “0”或“1”
 */
+ (void)addRetryableOperationType:(NSString*)operationType value:(NSString*)resend;

/**
 *  反序列化json串
 *  @param 输入串
 *  @return 反序列化结果
 */
+ (id)getJsonValueFromString:(NSString*)str;
@end
