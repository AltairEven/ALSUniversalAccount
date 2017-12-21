//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 13-1-29.
//  Copyright (c) 2013年 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKConfiguration.h"

#define SERVER_TIME_OFFSET_KEY                  @"server time date offset key in userDefaults"
#define DEVICEID_KEY                            @"devicdID key"
#define DEVICEID_VERSION_KEY                    @"devicdID version key"
#define DEVICEID_APP_KEY                        @"device app key"
#define kIsNotFist                              @"is newiphone"
#define kTBSDKNetworkSDKOldDeviceIdKey          @"kTBSDKNetworkSDKOldDeviceIdKey"
#define kTBSDKNetworkSDKDeviceIDChange          @"kTBSDKNetworkSDKDeviceIDChange"

//获取时间戳时间间隔
#define kFetchServerTimeInterval    30

//获取时间戳的次数上限
#define kFetchServerTimeCount       10


#define kGetDeviceIDInterval        12

@class TBSDKConfiguration;
@protocol TBSDKErrorRule;

/** TBSDKConfiguration的类的辅助类
 *
 *  为TBSDKConfiguration提供一些必要的方法
 */
@interface TBSDKConfigurationHelper : NSObject

@property (nonatomic, strong) TBSDKConfiguration                                *configuration;
@property (nonatomic, strong) NSConditionLock                                   *createDeviceIDLock;

+ (id)shareInstance;

//! 从服务器获取手机的唯一标示DeviceID，error是错误返回值，可以为空
- (NSString*) getDeviceIDFromServer: (id<TBSDKErrorRule>*)error;

//! 获取本地时间与服务器的时间差
- (void)fetchServerTimeIntervalAndSetToConfiguration;


@end