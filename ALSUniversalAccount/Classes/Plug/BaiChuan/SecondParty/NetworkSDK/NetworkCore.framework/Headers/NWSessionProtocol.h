//
//  NWSessionProtocol.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 2017/1/11.
//  Copyright © 2017年 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ChallengeCompletionHandler)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * credential);

@protocol NWSessionAuthenticationChallengeDelegate <NSObject>

- (BOOL)URLSession:(NSURLSession *)session
              task:(NSURLSessionTask *)task
didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(ChallengeCompletionHandler)completionHandler;

@end

@interface NWSessionProtocol : NSURLProtocol

+ (void)setAuthenticationChallengeDelegate:(id<NWSessionAuthenticationChallengeDelegate>) delegate;

@end

