//
//  AFHttpRequestWrapper.m
//  AEAssistant_Network
//
//  Created by Altair on 7/25/16.
//  Copyright © 2016 StarDust. All rights reserved.
//

#import "AFHttpRequestWrapper.h"

@implementation AFHttpRequestWrapper

+ (NSURLSessionTask *)requestWithUrlRequest:(NSURLRequest *)urlRequest stringEncoding:(NSStringEncoding)encoding parameter:(NSDictionary *)parameter success:(void (^)(NSURLRequest *, id))success failure:(void (^)(NSURLRequest *, NSError *))failure {
    //session
    AFHTTPSessionManager   *sessionManager = [[AFHTTPSessionManager alloc] initWithBaseURL:nil];
    //request
    sessionManager.requestSerializer.timeoutInterval = urlRequest.timeoutInterval;
    sessionManager.requestSerializer.stringEncoding = encoding;
    sessionManager.requestSerializer.networkServiceType = urlRequest.networkServiceType;
    sessionManager.requestSerializer.cachePolicy = urlRequest.cachePolicy;
    NSDictionary *headerInfo = [urlRequest allHTTPHeaderFields];
    if ([headerInfo count] > 0) {
        for (NSString *key in [headerInfo allKeys]) {
            NSString *value = [headerInfo objectForKey:key];
            if (value && [value isKindOfClass:[NSString class]]) {
                [sessionManager.requestSerializer setValue:value forHTTPHeaderField:key];
            }
        }
    }
    
    NSError *error = nil;
    NSMutableURLRequest *request = [sessionManager.requestSerializer requestWithMethod:urlRequest.HTTPMethod URLString:[[urlRequest URL] absoluteString] parameters:parameter error:&error];
    if (error && failure) {
        failure(urlRequest, error);
    }
    request.timeoutInterval = urlRequest.timeoutInterval;
    request.networkServiceType = urlRequest.networkServiceType;
    request.cachePolicy = urlRequest.cachePolicy;
    request.allHTTPHeaderFields = urlRequest.allHTTPHeaderFields;
    //response
    sessionManager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/xml", @"text/html", @"text/plain",nil];
    [(AFJSONResponseSerializer *)sessionManager.responseSerializer setRemovesKeysWithNullValues:YES];
    //task
    NSURLSessionTask *task = [sessionManager dataTaskWithRequest:request completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
        if (error) {
            if (failure) {
                failure(request, error);
            }
        } else {
            if (success) {
                success(request, responseObject);
            }
        }
    }];
    return task;
}

+ (NSURLSessionTask *)requestWithUrlRequest:(NSURLRequest *)urlRequest stringEncoding:(NSStringEncoding)encoding parameter:(NSDictionary *)parameter constructingBodyWithBlock:(void (^)(id<AFMultipartFormData>))block success:(void (^)(NSURLRequest *, id))success failure:(void (^)(NSURLRequest *, NSError *))failure {
    //session
    AFHTTPSessionManager   *sessionManager = [[AFHTTPSessionManager alloc] initWithBaseURL:nil];
    //request
    sessionManager.requestSerializer.timeoutInterval = urlRequest.timeoutInterval;
    sessionManager.requestSerializer.stringEncoding = encoding;
    sessionManager.requestSerializer.networkServiceType = urlRequest.networkServiceType;
    sessionManager.requestSerializer.cachePolicy = urlRequest.cachePolicy;
    NSDictionary *headerInfo = [urlRequest allHTTPHeaderFields];
    if ([headerInfo count] > 0) {
        for (NSString *key in [headerInfo allKeys]) {
            NSString *value = [headerInfo objectForKey:key];
            if (value && [value isKindOfClass:[NSString class]]) {
                [sessionManager.requestSerializer setValue:value forHTTPHeaderField:key];
            }
        }
    }
    NSError *error = nil;
    NSMutableURLRequest *mRequest = [sessionManager.requestSerializer multipartFormRequestWithMethod:urlRequest.HTTPMethod URLString:urlRequest.URL.absoluteString parameters:parameter constructingBodyWithBlock:block error:&error];
    if (error) {
        return nil;
    }
    mRequest.timeoutInterval = urlRequest.timeoutInterval;
    mRequest.networkServiceType = urlRequest.networkServiceType;
    mRequest.cachePolicy = urlRequest.cachePolicy;
    mRequest.allHTTPHeaderFields = urlRequest.allHTTPHeaderFields;
    
    //response
    sessionManager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/xml", @"text/html", @"text/plain",nil];
    [(AFJSONResponseSerializer *)sessionManager.responseSerializer setRemovesKeysWithNullValues:YES];
    //task
    NSURLSessionTask *task = [sessionManager dataTaskWithRequest:mRequest completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
        if (error) {
            if (failure) {
                failure(mRequest, error);
            }
        } else {
            if (success) {
                success(mRequest, responseObject);
            }
        }
    }];
    return task;
}

+ (NSURLSessionUploadTask *)uploadFileWithUrlRequest:(NSURLRequest *)urlRequest stringEncoding:(NSStringEncoding)encoding parameter:(NSDictionary *)parameter constructingBodyWithBlock:(void (^)(id<AFMultipartFormData>))block progress:(void (^)(NSProgress *))progressBlock success:(void (^)(NSURLRequest *, id))success failure:(void (^)(NSURLRequest *, NSError *))failure {
    //session
    AFHTTPSessionManager   *sessionManager = [[AFHTTPSessionManager alloc] initWithBaseURL:nil];
    //request
    sessionManager.requestSerializer.timeoutInterval = urlRequest.timeoutInterval;
    sessionManager.requestSerializer.stringEncoding = encoding;
    sessionManager.requestSerializer.networkServiceType = urlRequest.networkServiceType;
    sessionManager.requestSerializer.cachePolicy = urlRequest.cachePolicy;
    NSDictionary *headerInfo = [urlRequest allHTTPHeaderFields];
    if ([headerInfo count] > 0) {
        for (NSString *key in [headerInfo allKeys]) {
            NSString *value = [headerInfo objectForKey:key];
            if (value && [value isKindOfClass:[NSString class]]) {
                [sessionManager.requestSerializer setValue:value forHTTPHeaderField:key];
            }
        }
    }
    NSError *error = nil;
    NSMutableURLRequest *mRequest = [sessionManager.requestSerializer multipartFormRequestWithMethod:urlRequest.HTTPMethod URLString:urlRequest.URL.absoluteString parameters:parameter constructingBodyWithBlock:block error:&error];
    if (error) {
        return nil;
    }
    mRequest.timeoutInterval = urlRequest.timeoutInterval;
    mRequest.networkServiceType = urlRequest.networkServiceType;
    mRequest.cachePolicy = urlRequest.cachePolicy;
    mRequest.allHTTPHeaderFields = urlRequest.allHTTPHeaderFields;
    
    //response
    sessionManager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/xml", @"text/html", @"text/plain",nil];
    [(AFJSONResponseSerializer *)sessionManager.responseSerializer setRemovesKeysWithNullValues:YES];
    //task
    NSURLSessionUploadTask *task = [sessionManager uploadTaskWithRequest:mRequest fromData:nil progress:progressBlock completionHandler:^(NSURLResponse * _Nonnull response, id  _Nullable responseObject, NSError * _Nullable error) {
        if (error) {
            if (failure) {
                failure(mRequest, error);
            }
        } else {
            if (success) {
                success(mRequest, responseObject);
            }
        }
    }];
    return task;
}

+ (NSURLSessionDownloadTask *)downloadFileWithUrlRequest:(NSURLRequest *)urlRequest stringEncoding:(NSStringEncoding)encoding parameter:(NSDictionary *)parameter progress:(void (^)(NSProgress *))progressBlock destination:(nullable NSURL *(^)(NSURL *, NSURLResponse *))destination success:(void (^)(NSURLRequest *, NSURL *))success failure:(void (^)(NSURLRequest *, NSError *))failure {
    //session
    AFHTTPSessionManager   *sessionManager = [[AFHTTPSessionManager alloc] initWithBaseURL:nil];
    //request
    sessionManager.requestSerializer.timeoutInterval = urlRequest.timeoutInterval;
    sessionManager.requestSerializer.stringEncoding = encoding;
    sessionManager.requestSerializer.networkServiceType = urlRequest.networkServiceType;
    sessionManager.requestSerializer.cachePolicy = urlRequest.cachePolicy;
    NSDictionary *headerInfo = [urlRequest allHTTPHeaderFields];
    if ([headerInfo count] > 0) {
        for (NSString *key in [headerInfo allKeys]) {
            NSString *value = [headerInfo objectForKey:key];
            if (value && [value isKindOfClass:[NSString class]]) {
                [sessionManager.requestSerializer setValue:value forHTTPHeaderField:key];
            }
        }
    }
    NSError *error = nil;
    NSMutableURLRequest *mRequest = [sessionManager.requestSerializer requestWithMethod:urlRequest.HTTPMethod URLString:[[urlRequest URL] absoluteString] parameters:parameter error:&error];
    if (error) {
        return nil;
    }
    mRequest.timeoutInterval = urlRequest.timeoutInterval;
    mRequest.networkServiceType = urlRequest.networkServiceType;
    mRequest.cachePolicy = urlRequest.cachePolicy;
    mRequest.allHTTPHeaderFields = urlRequest.allHTTPHeaderFields;
    
    //response
    sessionManager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/xml", @"text/html", @"text/plain",nil];
    [(AFJSONResponseSerializer *)sessionManager.responseSerializer setRemovesKeysWithNullValues:YES];
    //task
    NSURLSessionDownloadTask *task = [sessionManager downloadTaskWithRequest:mRequest progress:progressBlock destination:destination completionHandler:^(NSURLResponse * _Nonnull response, NSURL * _Nullable filePath, NSError * _Nullable error) {
        if (error) {
            if (failure) {
                failure(mRequest, error);
            }
        } else {
            if (success) {
                success(mRequest, filePath);
            }
        }
    }];
    return task;
}

@end
