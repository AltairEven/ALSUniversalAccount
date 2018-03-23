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
	// 预加载来源
	// 来自 PackageApp。
	// ZCacheResourceFromPackageApp = 3,
	// 来自 ZCache 1.0。
	// ZCacheResourceFromZCache1 = 4,
	// 来自解 Combo。
	// ZCacheResourceFromCombo = 8,
	// 来自 ZCache 2.0。
	// ZCacheResourceFromZCache2 = 9,
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
