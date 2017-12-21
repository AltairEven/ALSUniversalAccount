//
//  AVFSDatabaseManager.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/2.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSDatabaseQueue.h"

@interface AVFSDatabaseManager : NSObject

/**
 *  单例
 *
 *  @return 单例
 */
+ (instancetype)sharedManager;

/**
 *  埋点实现
 */
@property (nonatomic, strong) Class loggerClass;

/**
 *  默认数据库
 *
 *  @return 默认数据库
 */
- (AVFSDatabaseQueue *)defaultDatabase;

/**
 *  默认加密数据库
 *
 *  @return 默认加密数据库
 */
- (AVFSDatabaseQueue *)defaultEncryptDatabase;

/**
 *  特定模块数据库
 *
 *  @param moduleName 模块名
 *
 *  @return 特定模块数据库
 */
- (AVFSDatabaseQueue *)databaseForModule:(NSString *)moduleName;

/**
 *  特定模块加密数据库
 *
 *  @param moduleName 模块名
 *
 *  @return 特定模块加密数据库
 */
- (AVFSDatabaseQueue *)encryptDatabaseForModule:(NSString *)moduleName;

/**
 *  清除数据库
 *
 *  @param moduleName 模块名
 */
- (void)removeDatabaseForModule:(NSString *)moduleName;

/**
 *  清除加密数据库
 *
 *  @param moduleName 模块名
 */
- (void)removeEncryptDatabaseForModule:(NSString *)moduleName;

@end
