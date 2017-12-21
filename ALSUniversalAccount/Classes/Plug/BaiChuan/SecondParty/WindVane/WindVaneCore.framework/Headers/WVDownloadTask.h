/*
 * WVDownloadTask.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, WVDownloadTaskPriority) {
	WVDownloadTaskPriorityImmediately, // 需要立即下载。
	WVDownloadTaskPriorityHigh,        // 高优先级。
	WVDownloadTaskPriorityDefault,     // 默认优先级。
	WVDownloadTaskPriorityLow,         // 低优先级。
};

/**
 * WindVane 下载任务。
 */
@interface WVDownloadTask : NSOperation

typedef void (^WVDownloadProgressBlock)(long long totalBytes, long long totalBytesExpected);
typedef void (^WVDownloadCompletionBlock)(WVDownloadTask * task);

/**
 * 是否检查响应是否为 200 且数据不为空。
 */
@property (nonatomic, assign, getter=isCheckResponse) BOOL checkResponse;

#pragma mark - Request Info

/**
 * 下载任务的请求。
 */
@property (nonatomic, copy, readonly) NSURLRequest * request;

/**
 * 是否需要断点续传。
 */
@property (nonatomic, assign) BOOL shouldResume;

/**
 * 最后完成的目标文件路径，如果设置了的话，总是会将下载的文件写入此路径。
 */
@property (nonatomic, copy) NSString * destinationPath;

/**
 * 其它用户自定义数据。
 */
@property (nonatomic, copy) NSDictionary * userInfo;

#pragma mark - Response Info

/**
 * 请求得到的响应。
 */
@property (nonatomic, strong, readonly) NSURLResponse * response;

/**
 * HTTP 响应的状态码。
 */
@property (nonatomic, assign, readonly) NSInteger statusCode;

/**
 * 请求得到的响应数据。
 */
@property (nonatomic, copy, readonly) NSData * responseData;

/**
 * 请求得到的响应字符串。
 */
@property (nonatomic, copy, readonly) NSString * responseString;

/**
 * 请求得到的响应 JSON。
 */
@property (nonatomic, strong, readonly) id responseJson;

/**
 * 请求过程中发生的错误。
 */
@property (nonatomic, strong, readonly) NSError * error;

#pragma mark - Handler

/**
 * 任务完成的回调线程，默认为非主线程。
 */
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t completionQueue;
#else
@property (nonatomic, assign) dispatch_queue_t completionQueue;
#endif

/**
 * 下载进度处理器。
 */
@property (nonatomic, copy) WVDownloadProgressBlock progressBlock;

/**
 * 设置指定的成功和失败回调作为完成回调。
 */
- (void)setCompletionBlockWithSuccess:(WVDownloadCompletionBlock)success failure:(WVDownloadCompletionBlock)failure;

#pragma mark - Factory

/**
 * 使用指定的 URL 地址创建一个下载任务。
 * 会自动对已经开始的下载任务做强引用。
 */
+ (WVDownloadTask *)taskWithString:(NSString *)url withPriority:(WVDownloadTaskPriority)priority;

/**
 * 使用指定的 URL 创建一个下载任务。
 * 会自动对已经开始的下载任务做强引用。
 */
+ (WVDownloadTask *)taskWithURL:(NSURL *)url withPriority:(WVDownloadTaskPriority)priority;

/**
 * 使用指定的请求创建一个下载任务。
 * 会自动对已经开始的下载任务做强引用。
 */
+ (WVDownloadTask *)taskWithRequest:(NSURLRequest *)request withPriority:(WVDownloadTaskPriority)priority;

@end
