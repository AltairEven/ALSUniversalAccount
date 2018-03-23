//
//  ARUPInitConfiguration.h
//  ARUP
//
//  Created by 亿刀 on 16/1/26.
//  Copyright © 2016年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ARUPEnvironment)
{
    /**
     *  上线
     */
    ARUPEnvironmentRelease = 0,
    
    /**
     *  预发
     */
    ARUPEnvironmentDebug,
    
    /**
     *  日常
     */
    ARUPEnvironmentDaily
};

@class ARUPConfiguration;

/**
 *  arup系统配置类
 */
@interface ARUPSystemConfiguration : NSObject

/**
 *  获取单例
 *
 *  @return 单例
 */
+ (instancetype _Nonnull)shareInstance;

- (void)putServerConfigByEnvironment:(ARUPEnvironment)environment
                              domain:(NSString *_Nonnull)domain
                                  ip:(NSString *_Nonnull)ip;

/**
 *  设置环境
 */
@property (nonatomic, assign) ARUPEnvironment environment;

/**
 *  API服务器Name
 */
@property (nonatomic, nonnull, strong) NSString *apiServerDomainName;

/**
 *  API服务器的ip
 */
@property (nonatomic, nonnull, strong) NSString *apiServerIP;

/**
 *  配置信息
 */
@property (nullable, strong, nonatomic, readonly) ARUPConfiguration *configuration;

/**
 *  appkey
 */
@property (nonatomic, nonnull) NSString *appkey;

/**
 *  设备ID
 */
@property (nonatomic, nonnull, readonly, strong) NSString *deviceID;

@property (nonatomic, assign) double timeDifference;

/**
 *  和服务器校准后的本地时间
 */
@property (nonatomic, assign, nullable) NSDate *nowDate;

@property (nonatomic, strong, nullable) NSString *userID;

@end
