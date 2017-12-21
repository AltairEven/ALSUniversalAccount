//
//  ALSUABaiChuanPlugInitializationInfo.m
//  AlisportsUniversalAccount
//
//  Created by Altair on 17/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "ALSUABaiChuanPlugInitializationInfo.h"

@implementation ALSUABaiChuanPlugInitializationInfo

- (instancetype)initWithAppKey:(NSString *)key appSecret:(NSString *)secret {
    self = [super init];
    if (self) {
        self.appKey = key;
        self.appSecret = secret;
    }
    return self;
}

+ (instancetype)infoWithAppKey:(NSString *)key appSecret:(NSString *)secret {
    return [[ALSUABaiChuanPlugInitializationInfo alloc] initWithAppKey:key appSecret:secret];
}


#pragma mark NSCopying

- (id)copyWithZone:(nullable NSZone *)zone {
    ALSUABaiChuanPlugInitializationInfo *info = [[ALSUABaiChuanPlugInitializationInfo allocWithZone:zone] initWithAppKey:self.appKey appSecret:self.appSecret];
    return info;
}

@end
