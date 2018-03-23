//
//  TBSDKServerDelegate.h
//  mtopext
//
//  Created by sihai on 12/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBSDKServer;

@protocol TBSDKServerDelegate <NSObject>

@optional

/*!
 *
 */
- (void) requestStarted: (TBSDKServer*) server;

/*!
 *
 */
- (void) requestReceivedResponseHeaders: (NSDictionary *) responseHeaders;

/*!
 * cache 命中数据，但是数据失效情况下才会回调这个函数，如果缓存命中且缓存数据有效，直接回调requestSuccess了
 */
- (void) didLoadCache: (TBSDKServer*) server responseHeader: (NSDictionary*) responseHeaders body: (NSString*) body;

/*!
 *
 */
- (void) requestSuccess:(TBSDKServer*) server;

/*!
 *
 */
- (void) requestFailed:(TBSDKServer*) server;

/*!
 *
 */
- (NSArray*) requestCache: (TBSDKServer*) server responseHeader: (NSDictionary*) responseHeader body: (NSString*)responseDataString;

@end
