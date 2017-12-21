//
//  InterfaceManager.h
//  KidsTC
//
//  Created by 钱烨 on 8/4/15.
//  Copyright (c) 2015 KidsTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class InterfaceManagerConfiguration;

@interface InterfaceManager : NSObject

@property (nonatomic, copy) NSString *interfaceListAddress;

@property (nonatomic, strong, readonly) NSDictionary *interfaceData;

@property (nonatomic, strong, readonly) NSDictionary * URLMapWithAlias;

@property (nonatomic, strong) InterfaceManagerConfiguration *configuration; //配置项，默认nil，如果非nil，则读取其中所有配置

+ (instancetype)sharedManager;

- (void)updateInterface;

- (NSString *)getURLStringWithAliasName:(NSString *)aliasName;

- (NSString *)getURLSendDataMethodWithAliasName:(NSString *)aliasName;

@end


@interface InterfaceManagerConfiguration : NSObject

@property (nonatomic, copy) NSString *protocol; //必填。协议，如http, https

@property (nonatomic, copy) NSString *host; //必填。域名

@property (nonatomic, copy) NSNumber *port; //端口

@end