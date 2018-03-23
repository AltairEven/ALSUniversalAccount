//
//  TBSDKMTOPServer+Async4j.h
//  TBSDKNetworkSDK
//
//  Created by guxing.hh on 14-6-18.
//  Copyright (c) 2014年 ZhuoLaiQiang. All rights reserved.
//

#import "TBSDKMTOPServer.h"

@class TBSDKAsync4jInterceptor;

@interface TBSDKMTOPServer (Async4j)

@property (nonatomic, strong) TBSDKAsync4jInterceptor *interceptor;

- (void)startAsync4jRequest;

- (void)cancelAsync4jRequest;

@end
