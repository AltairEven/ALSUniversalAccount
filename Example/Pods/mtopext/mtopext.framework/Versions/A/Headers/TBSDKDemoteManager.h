//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by Roger.Mu on 14-11-06.
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKBIZCacheObject.h"

#define kTBSDKDemoteSPDY @"kTBSDKDemoteSPDY"
#define kTBSDKDemoteURLConnection @"kTBSDKDemoteURLConnection"

@interface TBSDKDemoteManager : NSOperationQueue

@property (nonatomic, unsafe_unretained) BOOL netWorkUTOnOff;
@property (nonatomic, unsafe_unretained) long long postGzipOnoff;
@property (nonatomic, unsafe_unretained) int sslLimited;
@property (nonatomic, unsafe_unretained) BOOL unitEnable;
@property (nonatomic, weak) id nwDemote;

+ (TBSDKDemoteManager *)shareInstance;

#pragma mark -- mtopsdk switch interface functions

- (BOOL)isDemoteCache;

- (void)demoteCache;

- (void)unDemoteCache;

- (BOOL)isDemoteSSL;

- (void)unSSL;

- (BOOL)isDemoteSPDY;

- (void)unDemoteSPDY;

- (void)demoteSPDY;

- (BOOL)isDemoteDNS;

- (void)unDemoteDNS;

- (void)demoteDNS;

- (void)stopHttpDNS;

#pragma mark -- mtop cache interface functions

/**
 * cache biz object change to cache dictionary
 */
- (void)setBizCache:(TBSDKBIZCacheObject *) bizCache;

@end
