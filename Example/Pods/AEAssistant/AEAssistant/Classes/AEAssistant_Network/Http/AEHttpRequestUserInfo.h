//
//  AEHttpRequestUserInfo.h
//  AEAssistant_Network
//
//  Created by Altair on 7/27/16.
//  Copyright © 2016 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AEHttpRequestUserInfo : NSObject <NSCopying>

@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *infoAppendingAfterQueryString;

@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *infoInHttpHeader;

+ (instancetype)infoWithAppending:(NSDictionary<NSString *, NSString *> *)appendingInfo andHeader:(NSDictionary<NSString *, NSString *> *)headerInfo;

@end
