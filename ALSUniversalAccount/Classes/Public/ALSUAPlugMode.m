//
//  ALSUAPlugMode.m
//  AlisportsUniversalAccount
//
//  Created by Altair on 13/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "ALSUAPlugMode.h"

@implementation ALSUAPlugMode

- (instancetype)init {
    return nil;
}

- (instancetype)initWithName:(NSString *)name supportOperationType:(ALSUniveraslAccountOperationType)type {
    if (![name isKindOfClass:[NSString class]] || [name length] == 0) {
        return nil;
    }
    if ((ALSUniveraslAccountOperationTypeAll & type) != type) {
        return nil;
    }
    self = [super init];
    if (self) {
        _name = name;
        _supportOperationType = type;
    }
    return self;
}

+ (instancetype)modeWithName:(NSString *)name supportOperationType:(ALSUniveraslAccountOperationType)type {
    ALSUAPlugMode *mode = [[ALSUAPlugMode alloc] initWithName:name supportOperationType:type];
    return mode;
}

- (BOOL)isEqualToMode:(ALSUAPlugMode *)mode {
    if (![mode isKindOfClass:[ALSUAPlugMode class]]) {
        return NO;
    }
    return ([self.name isEqualToString:mode.name] &&
            self.supportOperationType == mode.supportOperationType);
}

- (BOOL)supportOperationMode:(ALSUAOperationMode *)mode {
    return ([self.name isEqualToString:mode.name] && [self supportOperationType:mode.operationType]);
}

- (BOOL)supportOperationType:(ALSUniveraslAccountOperationType)type {
    NSUInteger support = self.supportOperationType & type;
    return support == type;
}

#pragma mark NSCopying

- (id)copyWithZone:(nullable NSZone *)zone {
    ALSUAPlugMode *mode = [[ALSUAPlugMode allocWithZone:zone] initWithName:self.name supportOperationType:self.supportOperationType];
    return mode;
}

@end


@implementation ALSUALoginPlugMode

+ (instancetype)modeWithName:(NSString *)name supportOperationType:(ALSUniveraslAccountOperationType)type {
    ALSUALoginPlugMode *mode = [[ALSUALoginPlugMode alloc] initWithName:name supportOperationType:type];
    mode.needExchangeLoginResponseFromAccountCenter = YES;
    return mode;
}


- (BOOL)isEqualToMode:(ALSUALoginPlugMode *)mode {
    if (![mode isKindOfClass:[ALSUALoginPlugMode class]]) {
        return NO;
    }
    return ([self.name isEqualToString:mode.name] &&
            self.needExchangeLoginResponseFromAccountCenter == mode.needExchangeLoginResponseFromAccountCenter &&
            self.supportOperationType == mode.supportOperationType);
}

#pragma mark NSCopying

- (id)copyWithZone:(nullable NSZone *)zone {
    ALSUALoginPlugMode *mode = [[ALSUALoginPlugMode allocWithZone:zone] initWithName:self.name supportOperationType:self.supportOperationType];
    mode.needExchangeLoginResponseFromAccountCenter = self.needExchangeLoginResponseFromAccountCenter;
    return mode;
}

@end
