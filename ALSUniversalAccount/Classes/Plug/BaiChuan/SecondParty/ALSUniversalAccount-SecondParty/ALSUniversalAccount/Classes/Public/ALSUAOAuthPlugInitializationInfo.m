//
//  ALSUAOAuthPlugInitializationInfo.m
//  AlisportsUniversalAccount
//
//  Created by Altair on 17/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "ALSUAOAuthPlugInitializationInfo.h"

@implementation ALSUAOAuthPlugInitializationInfo

- (instancetype)initWithOAuthPlatform:(ALSUAOAuthPlatformType)type appKey:(NSString *)key appSecret:(NSString *)secret urlScheme:(NSString *)scheme andRedirectUrl:(NSString *)url {
    self = [super init];
    if (self) {
        self.platformType = type;
        self.appKey = key;
        self.appSecret = secret;
        self.urlScheme = scheme;
        self.redirectUrl = url;
    }
    return self;
}

+ (instancetype)infoWithOAuthPlatform:(ALSUAOAuthPlatformType)type appKey:(NSString *)key appSecret:(NSString *)secret urlScheme:(NSString *)scheme andRedirectUrl:(NSString *)url {
    return [[ALSUAOAuthPlugInitializationInfo alloc] initWithOAuthPlatform:type appKey:key appSecret:secret urlScheme:scheme andRedirectUrl:url];
}


#pragma mark NSCopying

- (id)copyWithZone:(nullable NSZone *)zone {
    ALSUAOAuthPlugInitializationInfo *info = [[ALSUAOAuthPlugInitializationInfo allocWithZone:zone] initWithOAuthPlatform:self.platformType appKey:self.appKey appSecret:self.appSecret urlScheme:self.urlScheme andRedirectUrl:self.redirectUrl];
    return info;
}

@end
