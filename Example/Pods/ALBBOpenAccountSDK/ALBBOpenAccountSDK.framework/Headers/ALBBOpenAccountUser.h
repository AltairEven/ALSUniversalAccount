//
//  ALBBOpenAccountUser.h
//  ALBBOpenAccount
//
//  Created by zifan.zx on 10/29/15.
//  strongright © 2015 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ALBBOpenAccountUser : NSObject

@property (strong, nonatomic, readonly) NSString *accountId;
@property (strong, nonatomic, readonly) NSString *displayName;
@property (strong, nonatomic, readonly) NSString *avatarUrl;
@property (strong, nonatomic, readonly) NSString *mobile;
@property (strong, nonatomic, readonly) NSString *mobileLocationCode;

//是否设置了密码
@property (assign, nonatomic, readonly) BOOL hasPassword;
//如果使用三方授权登录，第三方账号的 id 信息
@property (strong, nonatomic, readonly) NSString *openId;
//扩展信息
@property (strong, nonatomic, readonly) NSString *extInfos;
//服务端返回的所有account数据都在这里面
@property (strong, nonatomic, readonly) NSDictionary *openaccountInfoDict;

//使用三方授权登录时返回的三方账号数据,包含id,nick,avatarUrl,gender(0: 未知, 1:男, 2:女)
@property (strong, nonatomic, readonly) NSDictionary *oauthInfoDict;

@end
