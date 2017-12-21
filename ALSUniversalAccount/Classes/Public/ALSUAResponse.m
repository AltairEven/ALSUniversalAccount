//
//  ALSUAResponse.m
//  wesg
//
//  Created by Altair on 22/02/2017.
//  Copyright © 2017 AliSports. All rights reserved.
//

#import "ALSUAResponse.h"
#import "ALSUAPlugMode.h"

NSString *const kALSUABaichuanLoginStartNotification = @"kALSUABaichuanLoginStartNotification";
NSString *const kALSUABaichuanLoginFinishedNotification = @"kALSUABaichuanLoginFinishedNotification";

@implementation ALSUAResponse

- (instancetype)init {
    self = [super init];
    if (self) {
        self.operationFinished = YES;
    }
    return self;
}

- (instancetype)initWithOriginalMode:(ALSUAOperationMode *)originalMode {
    if (![originalMode isKindOfClass:[ALSUAOperationMode class]]) {
        return nil;
    }
    self = [self init];
    if (self) {
        _originalMode = originalMode;
    }
    return self;
}

@end


@interface ALSUALoginResponse ()

@property (nonatomic, copy) NSString *aliUid;  //阿里体育用户uid

@property (nonatomic, copy) NSString *accessToken; //用户accesstoken

@end

@implementation ALSUALoginResponse

- (instancetype)initWithOriginalMode:(ALSUAOperationMode *)originalMode plugMode:(ALSUALoginPlugMode *)plugMode {
    self = [super initWithOriginalMode:originalMode];
    if (self) {
        if ([plugMode isKindOfClass:[ALSUALoginPlugMode class]]) {
            self.plugMode = plugMode;
        }
    }
    return self;
}

- (NSString *)businessToken {
#if __has_include ("ALSUAAESService.h")
    return [ALSUAAESService businessSideAESOperate:ALSAESOperationEncrypt withString:self.token];
#else
    return self.token;
#endif
}

@end


@implementation ALSUABindPhoneResponse


@end

@implementation ALSUASetPasswordResponse


@end

@implementation ALSUABindTaobaoResponse


@end
