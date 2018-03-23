//
//  TBSDKAsync4jInterceptor.h
//  TBSDKNetworkSDK
//
//  Created by guxing.hh on 14-6-18.
//  Copyright (c) 2014年 ZhuoLaiQiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKServer.h"
#import "TBSDKServerDelegate.h"
#import "TBSDKMTOPServer+Async4j.h"

//#define ASYNC4J_DEBUG

#define ASYNC4J_HEADER_KEY          @"m-async"
#define ASYNC4J_REQUEST_TRADE       @"10"
#define ASYNC4J_REQUEST_MTOP        @"11"
#define ASYNC4J_REQUEST_POLL        @"12"
#define ASYNC4J_RESPONSE_SUCCESS      20
#define ASYNC4J_RESPONSE_PUSH         21
#define ASYNC4J_RESPONSE_POLL         22

#define ASYNC4J_INTERNAL_ERROR      @"ASYNC4J_INTERNAL_ERROR"
#define ASYNC4J_RESPONSE_QUERY_FAIL @"ASYNC4J_RESPONSE_QUERY_FAIL"
#define ASYNC4J_RESPONSE_FETCH_FAIL @"ASYNC4J_RESPONSE_FETCH_FAIL"

@interface TBSDKAsync4jInterceptor : NSObject <TBSDKServerDelegate>

@property (nonatomic, weak) id<TBSDKServerDelegate>    delegate;
@property (nonatomic, copy) StartBlock                 onStartBlock;
@property (nonatomic, copy) FinishedBlock              onFinishedBlock;
@property (nonatomic, copy) FailBlock                  onFailBlock;
@property (nonatomic, copy) ReciveResponseHeadersBlock reciveResponseHeadersBlock;
@property (nonatomic, copy) DidLoadCache               didLoadCache;
@property (nonatomic, copy) RequestCache               requestCache;

@property (nonatomic, strong) TBSDKMTOPServer         *pollServer;
@property (nonatomic, strong) NSTimer                 *timer;
@property (nonatomic, strong) NSString                *taskId;
@property (nonatomic, assign) NSUInteger               count;
@property (nonatomic, assign) BOOL                     cancel;

- (void)intercept:(TBSDKServer *)server;
- (void)cancelPolling;

@end