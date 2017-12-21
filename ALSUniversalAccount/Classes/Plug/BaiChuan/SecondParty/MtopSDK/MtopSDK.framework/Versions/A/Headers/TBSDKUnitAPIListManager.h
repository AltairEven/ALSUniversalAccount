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

@class TBSDKUserUnitConfigureObject;

@interface TBSDKUnitAPIListManager : NSObject

@property (nonatomic, strong) NSString                                          *apiListVersion;


+ (TBSDKUnitAPIListManager *)shareInstance;

- (BOOL)apiIsUnit:(NSString *)apiName apiVersion:(NSString *)apiVersion;

- (void)updateUnitAPIListConfigureWithURL:(NSString *)URL
                               apiVersion:(NSString *)apiVersion
                            utilConfigure:(void (^)(NSError *error, TBSDKUnitAPIListManager *unitAPIListManager))configureObjectBlock;

@end
