//
//  WVDownloadTask + WVPrivate.h
//  WindVaneCore
//
//  Created by lianyu.ysj on 16/2/29.
//  Copyright © 2016年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVDownloadTask.h>

@interface WVDownloadTask (WVPrivate)

/**
 * 使用指定的请求初始化。
 */
- (instancetype)initWithRequest:(NSURLRequest *)request;

#pragma mark- Request Info

/**
 * 设置下载任务的请求。
 */
- (void)setRequest:(NSURLRequest *)request;

#pragma mark- Response Info

/**
 * 设置请求得到的响应。
 */
- (void)setResponse:(NSURLResponse *)response;

/**
 * 设置请求得到的响应数据。
 */
- (void)setResponseDataWithData:(NSData *)responseData;

/**
 * 设置请求得到的响应数据从目标路径中读取。
 */
- (void)setResponseDataWithDestination;

/**
 * 设置请求过程中发生的错误。
 */
- (void)setError:(NSError *)error;

#pragma mark- Private

/**
 * 开始执行下载任务（需要子类重写）。
 */
- (void)startTask;

/**
 * 取消执行下载任务（需要子类重写）。
 */
- (void)cancelTask;

/**
 * 报告下载进度。
 */
- (void)reportProgress:(long long)totalBytes withExpected:(long long)totalBytesExpected;

/**
 * 设置当前操作已完成执行。
 */
- (void)operationFinished;

/**
 * 返回下载文件的临时路径。
 */
- (NSString *)tempPath;

/**
 * 移除临时文件。
 */
- (BOOL)deleteTempFileWithError:(NSError **)error;

@end
