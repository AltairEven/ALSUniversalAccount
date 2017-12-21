//
//  AFHttpRequestWrapper.h
//  AEAssistant_Network
//
//  Created by Altair on 7/25/16.
//  Copyright © 2016 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEAssistant_Category.h"
#import "AEAssistant_ToolBox.h"
#import <AFNetworking/AFNetworking.h>

@interface AFHttpRequestWrapper : NSObject


+ (NSURLSessionTask *)requestWithUrlRequest:(NSURLRequest *)urlRequest
                             stringEncoding:(NSStringEncoding)encoding
                                  parameter:(NSDictionary *)parameter
                                    success:(void (^)(NSURLRequest *request, id responseObject))success
                                    failure:(void (^)(NSURLRequest *request, NSError *error))failure;


+ (NSURLSessionTask *)requestWithUrlRequest:(NSURLRequest *)urlRequest
                             stringEncoding:(NSStringEncoding)encoding
                                  parameter:(NSDictionary *)parameter
                  constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                                    success:(void (^)(NSURLRequest *request, id responseObject))success
                                    failure:(void (^)(NSURLRequest *request, NSError *error))failure;

+ (NSURLSessionUploadTask *)uploadFileWithUrlRequest:(NSURLRequest *)urlRequest
                                      stringEncoding:(NSStringEncoding)encoding
                                           parameter:(NSDictionary *)parameter
                           constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                                            progress:(void (^) (NSProgress *progress))progressBlock
                                             success:(void (^)(NSURLRequest *request, id responseObject))success
                                             failure:(void (^)(NSURLRequest *request, NSError *error))failure;

+ (NSURLSessionDownloadTask *)downloadFileWithUrlRequest:(NSURLRequest *)urlRequest
                                          stringEncoding:(NSStringEncoding)encoding
                                               parameter:(NSDictionary *)parameter
                                                progress:(void (^) (NSProgress *progress))progressBlock
                                             destination:(NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destination
                                                 success:(void (^)(NSURLRequest *request, NSURL *filePath))success
                                                 failure:(void (^)(NSURLRequest *request, NSError *error))failure;

@end
