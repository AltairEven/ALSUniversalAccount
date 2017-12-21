//
//  AVFSSQLiteProtocol.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/2.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSCursorProtocol.h"

@protocol AVFSDatabaseProtocol <NSObject>

/**
 *  初始化
 *
 *  @param inPath 数据库路径
 *
 *  @return 数据库实例
 */
- (instancetype)initWithPath:(NSString*)inPath;

/**
 *  执行数据库更新，包括 CREATE, UPDATE, INSERT, ALTER, COMMIT, BEGIN, DETACH, DELETE, DROP, END, EXPLAIN, VACUUM, 和 REPLACE
 *
 *  @param sql    sql语句
 *  @param values 插入值
 *  @param error  错误
 *
 *  @return 是否更新成功
 */
- (void)executeUpdate:(NSString *)sql values:(NSArray *)values error:(NSError *__autoreleasing *)error;

/**
 *  执行数据库查询，包括 SELECT
 *
 *  @param sql    sql语句
 *  @param values 插入值
 *  @param error  错误
 *
 *  @return 游标
 */
- (id<AVFSCursorProtocol>)executeQuery:(NSString *)sql values:(NSArray *)values error:(NSError *__autoreleasing *)error;

/**
 *  执行事务操作
 *
 *  @param block 事务回调
 */
- (void)inTransaction:(void (^)(id<AVFSDatabaseProtocol> db, BOOL *rollback))block;

@optional
/**
 *  初始化加密数据库
 *
 *  @param inPath 数据库路径
 *  @param key    数据库密钥
 *
 *  @return 数据库实例
 */
- (instancetype)initWithPath:(NSString *)inPath key:(NSString *)key;

@end
