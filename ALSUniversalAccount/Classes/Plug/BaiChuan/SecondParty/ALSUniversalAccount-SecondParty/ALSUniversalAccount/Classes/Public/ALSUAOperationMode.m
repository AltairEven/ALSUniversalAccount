//
//  ALSUAOperationMode.m
//  AlisportsUniversalAccount
//
//  Created by Altair on 13/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "ALSUAOperationMode.h"

NSString *const ALSUAModeAccount = @"ALSUAModeAccount";
NSString *const ALSUAModeMobilePhone = @"ALSUAModeMobilePhone";
NSString *const ALSUAModeEmail = @"ALSUAModeEmail";
NSString *const ALSUAModeBaiChuanCloud = @"ALSUAModeBaiChuanCloud";
NSString *const ALSUAModeBaiChuanThirdParty = @"ALSUAModeBaiChuanThirdParty";
NSString *const ALSUAModeTaoBao = @"1";
NSString *const ALSUAModeAlipay = @"ALSUAModeAlipay";
NSString *const ALSUAModeWechat = @"2";
NSString *const ALSUAModeQQ = @"4";
NSString *const ALSUAModeWeibo = @"3";


NSString *const ALSUAModeAuto = @"ALSUAModeAuto";
NSString *const ALSUniversalAccount = @"ALSUniversalAccount";

@implementation ALSUAOperationMode

- (instancetype)init {
    return nil;
}

- (instancetype)initWithName:(NSString *)name operationType:(ALSUniveraslAccountOperationType)type {
    if (![name isKindOfClass:[NSString class]] || [name length] == 0) {
        return nil;
    }
    if ((ALSUniveraslAccountOperationTypeAll & type) != type) {
        return nil;
    }
    
    self = [super init];
    if (self) {
        _name = [name copy];
        _allowCovers = YES;
        _operationType = type;
        _transitionType = ALSUAOperationModeTransitionTypePresent;
    }
    return self;
}

+ (instancetype)modeWithName:(NSString *)name operationType:(ALSUniveraslAccountOperationType)type {
    ALSUAOperationMode *mode = [[ALSUAOperationMode alloc] initWithName:name operationType:type];
    return mode;
}

@end
