//
//  aluDeviceUser.h
//  AliUniversalAccount
//
//  Created by ethan on 12/29/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface aluDeviceUser : NSObject
@property(nonatomic, copy) NSString* taobaoNick;
@property(nonatomic, copy) NSString* mobile;
@property(nonatomic, copy) NSString* email;
@property(nonatomic, copy) NSString* headImg;
@property(nonatomic, copy) NSString* userId;
@property(nonatomic, copy) NSString* tokenKey;
@property(nonatomic, copy) NSString* tokenSalt;
@property(nonatomic, copy) NSDictionary<NSString *, NSString *> *ext;
@end
