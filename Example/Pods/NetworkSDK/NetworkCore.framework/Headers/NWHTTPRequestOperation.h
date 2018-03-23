//
//  NWHTTPRequestOperation.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 5/8/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import "NWURLConnectionOperation.h"

@interface NWHTTPRequestOperation : NWURLConnectionOperation

- (void)setCompletionBlockWithSuccess:(void (^)(NWHTTPRequestOperation *operation, id responseObject))success
                              failure:(void (^)(NWHTTPRequestOperation *operation, NSError *error))failure;

@end
