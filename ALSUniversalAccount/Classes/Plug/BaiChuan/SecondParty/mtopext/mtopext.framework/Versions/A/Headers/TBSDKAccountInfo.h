//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 iTeam on 13-4-7.
//  Copyright (c) 2013年 亿刀 Iteam. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TBSDKAccountInfo : NSObject

@property (nonatomic, strong) NSString                                          *appToken;
@property (nonatomic, strong) NSString                                          *pubkey;
@property (nonatomic, strong) NSString                                          *topSession;
@property (nonatomic, strong) NSString                                          *sid;
@property (nonatomic, strong) NSString                                          *nick;
@property (nonatomic, strong) NSString                                          *userId;
@property (nonatomic, strong) NSString                                          *loginToken;
@property (nonatomic, strong) NSString                                          *ecode;
@property (nonatomic, strong) NSString                                          *logintime;
@property (nonatomic, strong) id                                                cookies;
@property (nonatomic, strong) NSString                                          *ssoToken;
@property (nonatomic, strong) NSString                                          *loginKey;
@property (nonatomic, strong) NSString                                          *password;
@property (nonatomic, strong) NSString                                          *sidInvalidTime;
@property (nonatomic)         BOOL                                              isSidInvalid;

+ (TBSDKAccountInfo *)shareInstance;

+ (BOOL)isLoggedIn;

- (void)loadAccountInfo;

- (void)clearAccountInfo;

@end