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

typedef NS_ENUM(NSInteger, TBSDKUnitType)
{
    TBSDKUnitTypeCenter = 0,
    TBSDKUnitTypeUnit = 1,
};

@interface TBSDKUserUnitConfigureObject : NSObject

@property (nonatomic, strong) NSString                                          *userId;
@property (nonatomic, unsafe_unretained) TBSDKUnitType                          unitType;
@property (nonatomic, strong) NSString                                          *prefix;

@end