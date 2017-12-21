/*
 * WVURLCache.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

// 缓存的 URL 的键。
FOUNDATION_EXPORT NSString * const WVCacheURLKey;
// 缓存的本地路径的键。
FOUNDATION_EXPORT NSString * const WVCacheLocalPathKey;

@interface WVURLCache : NSObject

#pragma mark - 缓存

/**
 * 将指定 URL 的响应数据缓存到内存中。
 * 这里的 mimeType 并不是真正的 MIME Type，而是资源的扩展名，例如 .js/.jpeg/.html 等。
 */
+ (void)storeResponseForURL:(NSString *)url withResponseData:(NSData *)data withMIMEType:(NSString *)mimeType;

/**
 * 将指定的响应缓存到内存中。
 *
 * @param response 要缓存的响应。
 * @param data     要缓存的数据。
 * @param url      相应的请求 URL。
 */
+ (void)storeResponse:(NSHTTPURLResponse *)response withData:(NSData *)data forURL:(NSURL *)url;

/**
 * 将指定 URL 的与指定本地文件关联起来。
 */
+ (void)storeResponseToDiskForURL:(NSString *)url withFilePath:(NSString *)filePath;

/**
 * 返回是否存在指定 URL 的缓存。
 */
+ (BOOL)hasCacheForURL:(NSString *)url;

/**
 * 返回指定 URL 的缓存结果，如果不存在则返回 nil。
 */
+ (NSCachedURLResponse *)cachedResponseForURL:(NSString *)url;

/**
 * 清除所有缓存的响应。
 */
+ (void)removeAllCachedResponses;

#pragma mark - 预览图片

/**
 * 保存用于预览的图片。
 *
 * @return 包含预览图片信息的字典，有 url: 可用于预览的图片 URL；localPath: 图片保存的本地路径。
 */
+ (NSDictionary *)savePreviewImage:(NSData *)imageData;

/**
 * 判断指定的路径是否是有效的预览图片地址。
 */
+ (BOOL)isValidPreviewImagePath:(NSString *)path;

// 待删除
// #define WV_PREVIEW_IMAGE_URL WVCacheURLKey
// #define WV_PREVIEW_IMAGE_LOCAL_PATH WVCacheLocalPathKey

@end
