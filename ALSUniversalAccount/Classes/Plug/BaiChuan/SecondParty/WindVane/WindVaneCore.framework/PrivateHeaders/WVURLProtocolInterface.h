/*
 * WVURLProtocolInterface.h
 *  
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * WVURLProtocol 的数据来源。
 */
typedef NS_ENUM(NSInteger, WVURLProtocolReadFromType) {
	/**
	 * 走网络。
	 */
	WVURLProtocolReadFromNetwork = 1,
	/**
	 * 走内存缓存。
	 */
	WVURLProtocolReadFromMemoryCache = 22,
	/**
	 * 走磁盘缓存。
	 */
	WVURLProtocolReadFromDiskCache = 23,
	/**
	 * 走 PackageApp。
	 */
	WVURLProtocolReadFromPackageApp = 3,
	/**
	 * 走 ZCache。
	 */
	WVURLProtocolReadFromZCache = 4,
	/**
	 * 走解 Combo。
	 */
	WVURLProtocolReadFromCombo = 8,
};

/**
 * 加载请求的成功回调。
 *
 * @param response     请求的响应。
 * @param responseData 请求的响应数据。
 * @param fromType     数据的来源。
 */
typedef void (^WVURLProtocolSuccessBlock)(NSHTTPURLResponse * _Nonnull response, NSData * _Nonnull responseData, WVURLProtocolReadFromType fromType);

/**
 * 加载请求的失败回调。
 *
 * @param error 错误信息。
 */
typedef void (^WVURLProtocolFailureBlock)(NSError * _Nullable error);

/**
 * WVURLProtocol 的子 Protocol 接口。
 */
@protocol WVURLProtocolInterface <NSObject>

@required

/**
 * 加载指定请求，并返回是否可以加载。
 *
 * @param request      要加载的请求。
 * @param successBlock 加载成功的回调。
 * @param failBlock    加载失败的回调。
 *
 * @return 如果可以加载指定请求，则返回 YES；如果不能加载指定请求，则返回 NO，WVURLProtocol 会重新发出线上请求。
 */
- (BOOL)canLoadRequest:(NSURLRequest * _Nonnull)request withSuccess:(WVURLProtocolSuccessBlock _Nullable)successBlock withFailure:(WVURLProtocolFailureBlock _Nullable)failBlock;

/**
 * 如果不能加载请求，要向线上的响应中额外增加的 Header 内容。
 */
- (NSDictionary<NSString *, NSString *> * _Nullable)externalHeaders;

@end

/**
 * WVURlProtocol 资源加载情况的监控。
 */
@protocol WVURLMonitorProtocol <NSObject>

@required

/**
 * 资源开始加载时调用。
 *
 * @param request 资源请求。
 * @param time    资源开始加载时间，为 1970 年 1 月 1 日至今的毫秒数。
 */
- (void)resource:(NSURLRequest * _Nonnull)request didStartLoadAtTime:(NSTimeInterval)time;

/**
 * 资源或页面获得状态码等信息时调用。
 *
 * @param request    资源请求。
 * @param statusCode 资源 HTTP 状态码。
 * @param fromType   自定义页面来源，如缓存、线上等。
 * @param header     响应头。
 */
- (void)resource:(NSURLRequest * _Nonnull)request didGetStatusCode:(NSInteger)statusCode withFromType:(WVURLProtocolReadFromType)fromType withHeader:(NSDictionary * _Nullable)header;

/**
 * 资源结束加载时调用。
 *
 * @param request  资源请求。
 * @param time     资源结束加载时间，为 1970 年 1 月 1 日至今的毫秒数。
 * @param dataSize 资源大小。
 */
- (void)resource:(NSURLRequest * _Nonnull)request didFinishLoadAtTime:(NSTimeInterval)time dataSize:(NSUInteger)dataSize;

@end
