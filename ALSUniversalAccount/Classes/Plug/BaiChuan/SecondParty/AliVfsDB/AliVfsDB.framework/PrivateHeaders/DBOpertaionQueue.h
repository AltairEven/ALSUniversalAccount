//
//  DBOpertaionQueue.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/9.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AliDB.h"

@interface DBOpertaion : NSObject

@property(copy, nonatomic)      NSString*                   type;               // 任务类型，是SQL还是SQLExt
@property(readwrite, nonatomic) BOOL                        isWrite;            // 是否写任务
@property(readwrite, nonatomic) BOOL                        isAttach;           // 是否是Attach任务
@property(readwrite, nonatomic) BOOL                        isTranscation;      // 是否是事务
@property(readwrite, nonatomic) BOOL                        isBatch;            // 是否是批量语句
@property(copy, nonatomic)      NSString*                   sql;                // SQL字符串
@property(strong, nonatomic)    NSArray*                    arguments;          // 参数，和SQL中的 ? 一一对应
@property(copy, nonatomic)      AliDBTransactionBlock       transactionBlock;   // 事务block
@property(copy, nonatomic)      AliDBExecCallback           execCallback;       // 执行完成之后的回调
@property(copy, nonatomic)      AliDBExtExecCallback        extExecCallback;    // SQL扩展执行完成之后的回调
@property(strong, nonatomic)    AliDBExecResult*            result;             // SQL执行之后的结果
@property(strong, nonatomic)    id                          extContext;         // SQL Ext Context
@property(strong, nonatomic)    id                          extResult;          // SQL Ext执行之后的结果
@property(weak, nonatomic)      id<AliDBSQLExtProcessor>    processor;          // 处理器
@property(weak, nonatomic)      id<AliDBLoggerProtocol>     logger;             // logger，埋点
@property(readwrite, nonatomic) BOOL                        isLog;              // 是否做操作统计
@property(readwrite, nonatomic) double                      beginTime;          // 操作开始时间
@property(readwrite, nonatomic) double                      endTime;            // 操作结束时间
@property(weak, nonatomic)      AliDB*                      dbHandle;           // 事务时需要使用

@property(readwrite, nonatomic) BOOL                        isMerged;           // 是否是合并操作
@property(strong, nonatomic)    NSMutableArray*             mergedQueue;        // 合并的操作队列

@end

@interface DBOpertaionQueue : NSObject

@property (readonly, nonatomic) NSUInteger count;

- (void)addOpertaion:(DBOpertaion*)operation;
- (void)removeOperation:(DBOpertaion*)operation;
- (DBOpertaion*)firstOperation;
- (DBOpertaion*)lastOperation;


@end
