//
//  AliDBCenter.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/9.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AliDBCode.h"
#import "AliDBResultSet.h"

#define kAliDBSQL    @"SQL" // 保留字，SQLExt注入时，类型不允许是SQL(大小写都不行)

// Query、Update操作执行的结果
@interface AliDBExecResult : NSObject

@property(strong, nonatomic) AliDBResultSet* resultSet;         // 游标
@property(assign, nonatomic) NSInteger changeCount;             // 修改行数
@property(assign, nonatomic) UInt64 lastInsertRowId;            // 最近插入的行号
@property(strong, nonatomic) id extContext;                     // AliDbSQLExt中的extContext
@property(strong, nonatomic) NSError* error;                    // 错误信息，错误码通过code获取，错误信息通过userInfo中的NSLocalizedDescriptionKey获取

@end

@interface AliDBSQLExt : NSObject

@property(strong, nonatomic) NSString *sql;
@property(strong, nonatomic) id extContext;

@end

// 处理器
@protocol AliDBSQLExtProcessor <NSObject>
@optional
/**
 *  从SQL扩展语句得到SQL语句
 *  @param[in] sqlExt       SQL扩展语句
 *  @return                 返回AliDBSQLExt对象
 */
- (AliDBSQLExt*)getSQL:(NSString*)sqlExt;

/**
 *  处理返回结果
 *  @param[in] result       Query或者Update操作的结果
 *  @return                 返回处理之后的结果
 */
- (id)processResult:(AliDBExecResult*)result;

@end

// 埋点
@protocol AliDBLoggerProtocol <NSObject>
@required

/**
 *  记录业务操作成功接口
 *
 *  @param page   页面名称
 *  @param monitorPoint 监控点名称
 *  @arg 附加参数，用于做横向扩展
 */
+ (void)commitSuccessWithPage:(NSString *)page monitorPoint:(NSString *)monitorPoint arg:(NSString *)arg;

/**
 *  记录业务操作失败接口
 *
 *  @param page   页面名称
 *  @param monitorPoint 监控点名称
 *  @param errorCode 错误码
 *  @param errorMsg  错误信息
 *  @arg 附加参数，用于做横向扩展
 */
+ (void)commitFailWithPage:(NSString *)page monitorPoint:(NSString *)monitorPoint errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg arg:(NSString *)arg;

/**
 * 注册性能埋点
 * @param module 模块
 * @param monitorPoint 监控点
 * @param measures 多指标
 * @param dimemsions 多维度
 */
+ (void)registerWithModule:(NSString *)module monitorPoint:(NSString *)monitorPoint measureSet:(NSArray*)measures dimensionSet:(NSArray*)dimensions;

/**
 * 提交多维度，多指标
 * @param module 监控模块
 * @param monitorPoint 监控点名称 Page+monitorPoint必须唯一
 * @param dimensionValues 维度值集合
 * @param measureValues 指标值集合
 */
+ (void)commitWithModule:(NSString*) module monitorPoint:(NSString *)monitorPoint dimensionValueSet:(NSDictionary*)dimensionValues measureValueSet:(NSDictionary*)measureValues;

@end

@interface AliDB : NSObject

/**
 *  打开数据库时的回调
 *  @param error            错误信息
 *  @param dbHandle         DB句柄
 *  @param oldVersion       老版本号
 *  @param newVersion       新版本号
 *  注意：打开数据库可能出错，通过error参数返回；打开数据库时，可能会出现数据库版本升级的问题，通过后三个参数通知给调用者
 */
typedef void (^AliDBOpenCallback)(NSError* error, AliDB* dbHandle, NSInteger oldVersion, NSInteger newVersion);

/**
 *  Query或者Update操作的结果回调
 *  @param result   操作结果
 */
typedef void (^AliDBExecCallback)(AliDBExecResult* result);

/**
 *  SQLExt的Query或者Update操作的结果回调
 *  @param result   操作结果
 */
typedef void (^AliDBExtExecCallback)(id result);

/**
 *  事务block
 *  @param dbHandle   DB句柄
 *  @param rollback   回滚
 */
typedef void (^AliDBTransactionBlock)(AliDB* dbHandle, BOOL* rollback);

/**
 *  初始化
 *  @param[in] path                 数据库的全路径文件名
 *  @param[in] version              数据库的版本，数据库版本必须大于0
 *  @param[in] AliDBOpenCallback    打开数据库的回调，打开失败或者数据库升级
 */
- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version withCallback:(AliDBOpenCallback)callback;

/**
 *  初始化
 *  @param[in] path                 数据库的全路径文件名
 *  @param[in] version              数据库的版本，数据库版本必须大于0
 *  @param[in] key                  加密的密钥
 *  @param[in] AliDBOpenCallback    打开数据库的回调，打开失败或者数据库升级
 */
- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version key:(NSString*)key withCallback:(AliDBOpenCallback)callback;

/**
 *  SQL查询-同步接口
 *  @param[in] sql  查询语句
 *  @return         返回查询结果
 */
- (AliDBExecResult*)execQuery:(NSString*)sql;

/**
 *  SQL查询-同步接口
 *  @param[in] sql          带?通配符的查询语句
 *  @param[in] arguments    通配符对应的参数
 *  @return                 返回查询结果
 */
- (AliDBExecResult*)execQuery:(NSString*)sql withArgumentsArray:(NSArray*)arguments;

/**
 *  SQL更新-同步接口
 *  @param[in] sql  更新语句
 *  @return         返回操作结果
 */
- (AliDBExecResult*)execUpdate:(NSString*)sql;

/**
 *  SQL更新-同步接口
 *  @param[in] sql          带?通配符的更新语句
 *  @param[in] arguments    通配符对应的参数
 *  @return                 返回更新结果
 */
- (AliDBExecResult*)execUpdate:(NSString*)sql withArgumentsArray:(NSArray*)arguments;

/**
 *  SQL批量更新-同步接口
 *  @param[in] sql  更新语句
 *  @return         返回操作结果
 */
- (AliDBExecResult*)execBatchUpdate:(NSString*)sql;

/**
 *  SQL扩展查询-同步接口
 *  @param[in] extType  扩展类型
 *  @param[in] sqlExt   sql扩展语句
 *  @return             返回查询结果
 */
- (id)execQueryExt:(NSString*)extType sqlExt:(NSString*)sqlExt;

/**
 *  SQL扩展更新-同步接口
 *  @param[in] extType  扩展类型
 *  @param[in] sqlExt   sql扩展语句
 *  @return             返回操作结果
 */
- (id)execUpdateExt:(NSString*)extType sqlExt:(NSString*)sqlExt;

/**
 *  SQL事务-同步接口
 *  @param[in] block        block
 *  @return                 返回事务结果
 */
- (AliDBExecResult*)inTransaction:(AliDBTransactionBlock)block;

/**
 *  SQL查询-异步接口
 *  @param[in] sql          查询语句
 *  @param[in] callback     回调
 */
- (void)execQuery:(NSString*)sql withCallback:(AliDBExecCallback)callback;

/**
 *  SQL查询-异步接口
 *  @param[in] sql          查询语句
 *  @param[in] arguments    通配符对应的参数
 *  @param[in] callback     回调
 */
- (void)execQuery:(NSString*)sql withArgumentsArray:(NSArray*)arguments withCallback:(AliDBExecCallback)callback;

/**
 *  SQL更新-异步接口
 *  @param[in] sql          更新语句
 *  @param[in] callback     回调
 */
- (void)execUpdate:(NSString*)sql withCallback:(AliDBExecCallback)callback;

/**
 *  SQL更新-异步接口
 *  @param[in] sql          更新语句
 *  @param[in] arguments    通配符对应的参数
 *  @param[in] callback     回调
 */
- (void)execUpdate:(NSString*)sql withArgumentsArray:(NSArray*)arguments withCallback:(AliDBExecCallback)callback;

/**
 *  SQL批量更新-异步接口
 *  @param[in] sql          更新语句
 *  @param[in] callback     回调
 */
- (void)execBatchUpdate:(NSString*)sql withCallback:(AliDBExecCallback)callback;

/**
 *  SQL扩展查询-异步接口
 *  @param[in] extType  扩展类型
 *  @param[in] sqlExt   sql扩展语句
 *  @param[in] callback 回调
 */
- (void)execQueryExt:(NSString*)extType sqlExt:(NSString*)sqlExt withCallback:(AliDBExtExecCallback)callback;

/**
 *  SQL扩展更新-异步接口
 *  @param[in] extType  扩展类型
 *  @param[in] sqlExt   sql扩展语句
 *  @param[in] callback 回调
 */
- (void)execUpdateExt:(NSString*)extType sqlExt:(NSString*)sqlExt withCallback:(AliDBExtExecCallback)callback;

/**
 *  SQL事务-异步接口
 *  @param[in] block        事务回调
 *  @param[in] callback     回调
 */
- (void)inTransaction:(AliDBTransactionBlock)block withCallback:(AliDBExecCallback)callback;

/**
 *  SQL扩展处理器器注入
 *  @param[in] processor    SQL扩展处理器
 *  @param[in] type         扩展类型
 *  @return                 如果设置正确，返回ALIDB_ERR_NONE，否则，返回定义在AliDBCode.h中定义的错误码
 *  注意：可以通过设置processor为nil，来取消处理器的注入
 */
- (NSInteger)setSQLExtProcessor:(id<AliDBSQLExtProcessor>)processor extType:(NSString*)type;

/**
 *  设置连接数
 *  @param[in] count    连接数
 *  @return             设置完之后实际的连接数
 *  注意：设置连接数为count，有两种case，一种是增加当前的连接数，一种是减少当前的连接数
 *  增加连接数：设置新的连接数为count，设置完之后返回实际的连接数，如果打开新的出现问题，可能会出现实际的连接数小于count的情形
 *  减少连接数：设置新的连接数为count，设置完之后返回实际的连接数，在设置时，如果连接都在使用中，可能出现实际的连接数大于count的情形
 */
- (NSUInteger)setConnectionCount:(NSUInteger)count;

/**
 *  获取连接数
 *  @return     返回当前连接数
 */
- (NSUInteger)connectionCount;

/**
 *  获取扩展连接数
 *  @return     返回当前扩展连接数
 */

- (NSUInteger)extConnectionCount;

/**
 *  获取当前合并操作数
 *  @return     返回当前合并的操作数
 */

- (NSUInteger)mergedCount;


/**
 *  设置logger
 *  @param[in] processor    logger
 */
- (void)setDBLogger:(id<AliDBLoggerProtocol>)logger;

@end
