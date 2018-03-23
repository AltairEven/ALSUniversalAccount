//
//  aluBaseInfo.h
//  AliUniversalAccount
//
//  Created by ethan on 11/13/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "aluJsonableObject.h"

@interface aluBaseInfo : aluJsonableObject

@property(nonatomic,copy, readonly) NSString* sdkVersion;
@property(nonatomic,copy) NSString* locale;
@property(nonatomic,copy) NSString* site;
@property(nonatomic,copy) NSString* appName;
@property(nonatomic,copy) NSString* appVersion;
@property(nonatomic,copy) NSString* deviceId;
@property(nonatomic,copy) NSString* ttid;
@property(nonatomic,copy) NSString* utdid;

//时间戳
@property(nonatomic, copy)NSString* t;
//是否使用安全令牌
@property(nonatomic, copy)NSString* useDeviceToken;
//设备令牌key
@property(nonatomic, copy)NSString* deviceTokenKey;
//设备令牌签名
@property(nonatomic, copy)NSString* deviceTokenSign;

//待删除，目前提供给TBMemberCenter用。后面整理
@property(nonatomic, copy)NSString* deviceName;
@property(nonatomic, copy)NSString* itemId;
@property(nonatomic, copy)NSString* token;
@property(nonatomic, strong)NSDictionary* ext;

@end
