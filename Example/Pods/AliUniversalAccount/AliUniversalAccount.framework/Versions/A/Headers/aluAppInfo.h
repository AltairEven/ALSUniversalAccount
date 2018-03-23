//
//  aluAppInfo.h
//  UniversalAccount
//
//  Created by 融汇 on 14-4-11.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface aluAppInfo : NSObject

@property(nonatomic,strong) NSString *productId;
@property(nonatomic,strong) NSString *productName;
@property(nonatomic,strong) NSString *productVersion;
@property(nonatomic,strong) NSString *channel;
@property(nonatomic,strong) NSString *clientType;
@property(nonatomic,strong) NSString *appType;
@property(nonatomic,strong) NSString *userAgent;

@end
