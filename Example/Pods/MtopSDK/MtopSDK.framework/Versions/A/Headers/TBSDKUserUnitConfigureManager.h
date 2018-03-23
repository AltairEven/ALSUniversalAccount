//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 14-6-16.
//  Copyright (c) 2014年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKUserUnitConfigureObject.h"

@class TBSDKUserUnitConfigureObject;

@interface TBSDKUserUnitConfigureManager : NSObject

+ (TBSDKUserUnitConfigureManager *)shareInstance;

- (TBSDKUserUnitConfigureObject *)getUserUnitConfigure:(NSString *)userId;

- (void)setUserUnitWithUserID:(NSString *)userID
                     unitType:(TBSDKUnitType)unitType
                     prefix:(NSString *)prefix;



@end