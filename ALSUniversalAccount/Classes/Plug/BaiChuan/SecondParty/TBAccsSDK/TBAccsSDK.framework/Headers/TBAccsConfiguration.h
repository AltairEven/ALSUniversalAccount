//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 15/3/25.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBAccsVariable.h"

@interface TBAccsPublicConfiguration : NSObject

+ (TBAccsPublicConfiguration *)shareInstance;

@property (nonatomic, strong) NSString                                          *utdid;

//extHeader
@property (nonatomic, strong) NSString                                          *sid;
@property (nonatomic, strong) NSString                                          *userID;
@property (nonatomic, strong) NSString                                          *cookie;

@property (nonatomic, assign) BOOL                                              unitEnable;

@end


@interface TBAccsConfiguration : NSObject

@property (nonatomic, strong) NSString                                          *appkey;
@property (nonatomic, strong) NSString                                          *appKeyEncode;
@property (nonatomic, strong) NSString                                          *sign;          // 废弃
@property (nonatomic, strong) NSString                                          *deviceID;
@property (nonatomic, strong) NSMutableDictionary                               *requestBaseParameters;

@end
