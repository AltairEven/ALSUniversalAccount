//
//  ALBBOpenAccountSSOLink.h
//  ALBBOpenAccountSSO
//
//  Created by yixiao on 17/1/9.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ALBBOpenAccountSSOLink : NSObject

@property(nonatomic,strong)NSString *openAccountId;
@property(nonatomic,strong)NSString *outerId;
@property(nonatomic,assign)NSInteger outerPlatform;
@property(nonatomic,strong)NSString *nickName;

//0：未知 1：男 2：女
@property(nonatomic,assign)NSInteger gender;
@property(nonatomic,strong)NSString *avatarUrl;
@end
