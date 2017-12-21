//
//  AEHttpRequestUserInfo.m
//  AEAssistant_Network
//
//  Created by Altair on 7/27/16.
//  Copyright © 2016 StarDust. All rights reserved.
//

#import "AEHttpRequestUserInfo.h"

@implementation AEHttpRequestUserInfo

+ (instancetype)infoWithAppending:(NSDictionary<NSString *,NSString *> *)appendingInfo andHeader:(NSDictionary<NSString *,NSString *> *)headerInfo {
    AEHttpRequestUserInfo *info = [[AEHttpRequestUserInfo alloc] init];
    info.infoAppendingAfterQueryString = appendingInfo;
    info.infoInHttpHeader = headerInfo;
    
    return info;
}

- (instancetype)copyWithZone:(NSZone *)zone {
    AEHttpRequestUserInfo *userInfo = [[AEHttpRequestUserInfo alloc] init];
    [userInfo setInfoAppendingAfterQueryString:[[self infoAppendingAfterQueryString] copy]];
    [userInfo setInfoInHttpHeader:[[self infoInHttpHeader] copy]];
    
    return userInfo;
}

@end
