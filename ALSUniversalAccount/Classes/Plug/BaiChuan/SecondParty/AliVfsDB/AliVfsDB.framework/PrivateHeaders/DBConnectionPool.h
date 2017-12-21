//
//  DBConnectionPool.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/9.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef SQLITE_ENABLE_CONNECTION_EXTEND
#define kMaxExtConnectionCount          2
#endif

#import "CipherDB.h"
#import "AliDB.h"
#import "DBOpertaionQueue.h"
#import "AliDBResultSet.h"

@class DBConnectionPool;

typedef void (^DBConnectionOpenCallback)(NSError* error, DBConnectionPool* connectionPool, NSInteger oldVersion, NSInteger newVersion);
typedef void (^OperationFinishBlock)();

@interface DBConnection : NSObject

- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version upgradeDelegate:(id<ICipherDBUpgradeDelegate>)delegate;
- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version key:(NSString*)key upgradeDelegate:(id<ICipherDBUpgradeDelegate>)delegate;

- (void)execOperation:(DBOpertaion*)operation withFinishBlock:(OperationFinishBlock)finishBlock;
- (void)execOperation:(DBOpertaion*)operation;

@end

@interface DBConnectionPool : NSObject <ICipherDBUpgradeDelegate>

- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version withCallback:(DBConnectionOpenCallback)callback;
- (instancetype)initWithDBPath:(NSString*)path version:(NSInteger)version key:(NSString*)key withCallback:(DBConnectionOpenCallback)callback;

#ifdef SQLITE_WAL_MODE
- (DBConnection*)getIdleReadConnection;
- (DBConnection*)getIdleWriteConnection;
#endif

- (DBConnection*)getIdleConnection;
- (DBConnection*)getBusyConnection;

- (void)releaseConnection:(DBConnection*)connection;

- (void)execOperation:(DBOpertaion*)operation; // 如果想让连接池中所有空闲线程都执行该Operation，调用该函数，目前该函数用于Attach

- (NSUInteger)setConnectionCount:(NSUInteger)connectionCount;
- (NSUInteger)connectionCount;

#ifdef SQLITE_ENABLE_CONNECTION_EXTEND
- (NSUInteger)extConnectionCount;
- (BOOL)creatExtConnection;
- (DBConnection*)getExtIdleConnection;
#endif

@end