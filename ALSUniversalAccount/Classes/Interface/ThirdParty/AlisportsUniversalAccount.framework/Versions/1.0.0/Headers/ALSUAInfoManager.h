//
//  ALSUAInfoManager.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 11/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ALSUAInfoQueryByAliuid = 1,
    ALSUAInfoQueryByEmail  = 2,
    ALSUAInfoQueryByMobile = 3
}ALSUAInfoQueryType;

@class ALSUAInfoQueryExtension;

@interface ALSUAInfoManager : NSObject

+ (instancetype)sharedManager;

/**
 账号信息获取
 @param queryType 查询方式
 @param context 手机号或者邮箱地址，根据queryType来传入
 @param needDetailInfo 是否需要详细信息 默认为0 不需要
 @param ext 扩展查询字段
 @param result 返回结果
 @return 是否操作成功
 */
- (BOOL)getAccountInfoWithQueryType:(ALSUAInfoQueryType)queryType queryContext:(NSString *)context needDetailInfo:(BOOL)needDetailInfo extension:(ALSUAInfoQueryExtension *)ext result:(void(^)(NSError *error, NSDictionary *userInfo))result;

/**
 更新账户信息
 
 @param citizenInfo 账户信息
 @param result 更新结果
 @return 方法调用结果
 */
- (BOOL)updateAccountInfo:(NSDictionary *)citizenInfo
                   result:(void(^)(NSError *error, NSDictionary *userInfo))result;

@end

@interface ALSUAInfoQueryExtension : NSObject

@property (nonatomic, assign) BOOL needCompanyInfo;

@property (nonatomic, assign) BOOL needTaobaoInfo;

- (NSString *)queryString;

@end
