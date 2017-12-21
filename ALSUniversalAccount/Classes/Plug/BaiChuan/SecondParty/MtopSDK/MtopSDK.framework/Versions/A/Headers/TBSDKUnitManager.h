//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//
//  Created by 亿刀 on 14-6-16.
//  Copyright (c) 2014年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kTBSDKUnitDemoteNotification @"kTBSDKUnitDemoteNotification"

@interface TBSDKUnitManager : NSObject

+ (TBSDKUnitManager *)shareInstance;

// get current user's unit host
- (NSString *)currentUserHost:(NSString *) apiName
                   apiVersion:(NSString *) apiVersion
               apiListVersion:(NSString **)apiListVersion
                         host:(NSString *) host
                   unitPrefix:(NSString *) unitPrefix
                       userId:(NSString *) userId;

// api response unit handler
- (void) apiUnitResponseHeaders:(NSDictionary *) responseHeaders
                     withUserId:(NSString *) userId;


#pragma mark - 
#pragma mark 内部使用

// 需要读取网络sdk版本号来划分单元化逻辑
+ (BOOL)readNetworkSdkUnitInfo;

// 获取当前登录用户的单元化信息
+ (NSString *)getCurUserUnit:(NSString *)userId;

// 更新当前登录用户的单元化信息
+ (void)updateCurUserUnit:(NSString *)unit userId:(NSString *)userId;

@end