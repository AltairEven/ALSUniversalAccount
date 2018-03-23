//
//  AliCipherDB.h
//
//  Created by Pavel on 16/1/5.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "CipherCode.h"

#import "CipherResultSet.h"

#define SQLITE_OPEN_READONLY         0x00000001
#define SQLITE_OPEN_READWRITE        0x00000002  
#define SQLITE_OPEN_CREATE           0x00000004
#define SQLITE_OPEN_SHAREDCACHE      0x00020000
#define SQLITE_OPEN_SQL_CACHE        0x00200000
#define SQLITE_OPEN_PLAN_CACHE       0x00100000


@class CipherDB;

@protocol ICipherDBUpgradeDelegate <NSObject>

/**
 *  版本更新回调函数
 *
 *  @param cipherDB   对应的CipherDB对象
 *  @param oldVersion 当前数据库版本
 *  @param newVersion 新版本
 */
- (void)onUpgrade:(CipherDB*)cipherDB oldVersion:(int)oldVersion newVersion:(int)newVersion;

@end

@interface CipherDB : NSObject
{
    NSString*               _dbPath;        //数据库存放位置
    NSString*               _encryKey;      //数据库加密密钥
    BOOL                    _threadSafe;    //数据库多线程多句柄支持
}

@property (readonly, nonatomic) NSString* dbPath;
@property (readonly, nonatomic) NSString* encryKey;
@property (readwrite, nonatomic) BOOL threadSafe;

/**
 *  初始化
 *
 *  @param[in] dir     数据库文件存放目录
 *  @param[in] name    数据库文件名
 *  @param[in] version 数据库版本
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDir:(NSString*)dir dbName:(NSString*)name version:(int)version;

/**
 *  初始化
 *
 *  @param[in] dir     数据库文件存放目录
 *  @param[in] name    数据库文件名
 *  @param[in] version 数据库版本
 *  @param[in] key     数据库密钥
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDir:(NSString*)dir dbName:(NSString*)name version:(int)version key:(NSString*)key;

/**
 *  初始化
 *
 *  @param[in] name    数据库文件名
 *  @param[in] version 数据库版本
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDBName:(NSString*)name version:(int)version;

/**
 *  初始化
 *
 *  @param[in] name    数据库文件名
 *  @param[in] version 数据库版本，数据库版本必须大于0
 *  @param[in] key     数据库密钥
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDBName:(NSString*)name version:(int)version key:(NSString*)key;

/**
 *  初始化
 *
 *  @param[in] name    数据库全路径文件名
 *  @param[in] version 数据库版本，数据库版本必须大于0
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDBPath:(NSString*)path version:(int)version;

/**
 *  初始化
 *
 *  @param[in] name    数据库全路径文件名
 *  @param[in] version 数据库版本，数据库版本必须大于0
 *  @param[in] key     数据库密钥
 *
 *  @return CipherDB对象
 */
- (instancetype)initWithDBPath:(NSString*)path version:(int)version key:(NSString*)key;

/**
 *  数据库打开操作
 *
 *  @param[in] flag     打开方式
 *  @param[in] delegate 版本更新回调
 *
 *  @return 错误码
 */
- (int)open:(int)flag upgradeDelegate:(id<ICipherDBUpgradeDelegate>)delegate;

/**
 *  数据库关闭操作
 */
- (void)close;

/**
 *  开始事务
 *
 *  @return 错误码
 */
- (int)beginTransaction;

/**
 *  设置事务成功
 */
- (void)setTransactionSuccessful;

/**
 *  提交事务
 */
- (void)endTransaction;

/**
 *  执行sql语句
 *
 *  @param[in] sql sql语句, Single SQL Update Statement in sql
 *
 *  @return 错误码
 */
- (int)execUpdate:(NSString*)sql;

/**
 *  执行批量sql语句
 *
 *  @param[in] sql sql语句, Multiple SQL Update Statement in sql
 *
 *  @return 错误码
 */
- (int)execBatchUpdate:(NSString*)sql;

/**
 *  执行sql语句
 *
 *  @param[in] sql sql语句
 *  @param[in] arguments sql语句中绑定数据
 *
 *  @return 错误码
 *
 *  NSNumber* idNumber = @2;
 *  [arguments addObject:idNumber];
 *  [cipherDB execUpdate:@"UPDATE test SET value=\"second-updated\" WHERE id=?" withArgumentsArray:arguments];
 *  array中的值和SQL语句中的"?"一一对应
 */
- (int)execUpdate:(NSString*)sql withArgumentsArray:(NSArray*)arguments;

/**
 *  执行sql语句
 *
 *  @param sql       sql语句
 *  @param arguments sql语句中绑定数据
 *
 *  @return 错误码
 *
 *  NSMutableDictionary* arguments = [[NSMutableDictionary alloc] init];
 *  NSNumber* idNumber = @2;
 *  arguments setObject:idNumber forKey:@"id"];
 *  [cipherDB execUpdate:@"UPDATE test SET value=\"second-updated\" WHERE id=:id" withArgumentsDict:arguments];
 *  dictionary中的key要和where子句中要查询的属性名字一致，而且属性的值必须是 :属性名的形式，比如上例中的id属性
 */
- (int)execUpdate:(NSString*)sql withArgumentsDict:(NSDictionary*)arguments;

/**
 *  查询操作
 *
 *  @param sql sql语句
 *
 *  @return 查询结果集
 */
- (CipherResultSet*)execQuery:(NSString*)sql error:(int*)code;

/**
 *  查询操作
 *
 *  @param sql       sql语句
 *  @param arguments sql语句中绑定值
 *
 *  @return 查询结果集
 */
- (CipherResultSet*)execQuery:(NSString*)sql withArgumentsArray:(NSArray*)arguments error:(int*)code;

/**
 *  查询操作
 *
 *  @param sql       sql语句
 *  @param arguments sql语句中绑定值
 *
 *  @return 查询结果集
 */
- (CipherResultSet*)execQuery:(NSString*)sql withArgumentsDict:(NSDictionary*)arguments error:(int*)code;

/**
 * 获取数据操作的变更数量
 *
 * @param isMulti       NO-获取单条SQL变化, YES-返回属性,多条语句changeCount累加结果
 *
 * @return 返回数据库操作的变更数量
 */
- (NSInteger)getChangeCount:(BOOL)isMulti;

/**
 * 获取最近的插入数据的行号
 *
 * @return 返回RowId
 */
- (UInt64)getLastInsertRowId;


/**
 * 设置JournalMode
 *
 * @param model         如@"PRAGMA journal_mode=WAL"
 *
 *  @return 错误码
 */
- (int)setJournalMode:(NSString*)model;

/**
 *  获取错误码对应的错误信息
 *
 *  @param errCode 错误码
 *
 *  @return 错误码对应的错误信息
 */
+ (NSString*)getErrorMsg:(int)errCode;

@end
