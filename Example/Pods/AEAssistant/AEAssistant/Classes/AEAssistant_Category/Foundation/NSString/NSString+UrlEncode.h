//
//  NSString_1.h
//  iphone51buy
//
//  Created by Bai Haoquan on 12-9-11.
//  modify by qitao (add URLDecodedString, queryParameters)
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (UrlEncode)

- (NSString *) urlencode;

- (NSString*)URLDecodedString;
- (NSDictionary*)queryParameters;

@end
