//
//  NWNetworkProtocol.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 11/17/14.
//  Copyright (c) 2014 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NWAuthenticationChallengeDelegate <NSObject>

- (BOOL)connection:(NSURLConnection *)connection willSendRequestForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;

@end

@interface NWNetworkProtocol : NSURLProtocol

+ (void)setAuthenticationChallengeDelegate:(id<NWAuthenticationChallengeDelegate>) delegate;

@end
