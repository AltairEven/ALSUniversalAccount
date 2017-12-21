//
//  AEHttpRequestConfiguration.m
//  AEAssistant_Network
//
//  Created by Altair on 7/27/16.
//  Copyright © 2016 StarDust. All rights reserved.
//

#import "AEHttpRequestConfiguration.h"
#import "AEAssistant_ToolBox.h"

@implementation AEHttpRequestConfiguration

+ (instancetype)defaultConfiguration {
    AEHttpRequestConfiguration *config = [[AEHttpRequestConfiguration alloc] init];
    [config setStringEncoding:NSUTF8StringEncoding];
    [config setTimeoutSeconds:10.0];
    [config setHttpMethod:@"GET"];
//    [config setErrorBlock:nil];
//    [config setLogoutErrorNumber:nil];
//    [config setRequestUserInfo:nil];
//    [config setDisplayDebugInfo:NO];
    [config setValidationBlock:^(NSDictionary *responseData) {
        if (responseData == nil) {
            NSError *error = [NSError errorWithDomain:@"Http request client. ResponseObject nil." code:-301 userInfo:nil];
            return error;
        }
        if (responseData == NULL) {
            NSError *error = [NSError errorWithDomain:@"Http request client. ResponseObject  NULL." code:-302 userInfo:nil];
            return error;
        }
        NSInteger errorNo = [[responseData objectForKey:@"code"] integerValue];
        if (errorNo <= 0) {
            NSError *error = nil;
            if ([responseData objectForKey:@"msg"]) {
                NSDictionary *userInfo = [NSDictionary dictionaryWithObject:[responseData objectForKey:@"msg"] forKey:kErrMsgKey];
                error = [NSError errorWithDomain:@"Http request client." code:errorNo userInfo:userInfo];
            }
            
            return error;
        }
        return (NSError *)nil;
    }];
//    [config setRetryCount:0];
    
    return config;
}


#pragma mark NSCopying

- (instancetype)copyWithZone:(NSZone *)zone {
    AEHttpRequestConfiguration *config = [[AEHttpRequestConfiguration alloc] init];
    [config setStringEncoding:[self stringEncoding]];
    [config setTimeoutSeconds:[self timeoutSeconds]];
    [config setHttpMethod:[self httpMethod]];
    [config setErrorBlock:[self errorBlock]];
    [config setLogoutErrorNumber:[[self logoutErrorNumber] copy]];
    [config setRequestUserInfo:[[self requestUserInfo] copy]];
    [config setDisplayDebugInfo:[self displayDebugInfo]];
    [config setValidationBlock:[[self validationBlock] copy]];
    [config setRequestBeforeBlock:[[self requestBeforeBlock] copy]];

//    [config setRetryCount:[self retryCount]];
    
    return config;
}

@end
