//
//  AVFSDatabaseQueue.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/16.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSDatabaseProtocol.h"

@interface AVFSDatabaseQueue : NSObject

/**
 *  初始化
 *
 *  @param aPath 路径
 *  @param 加密密钥
 *  @return 实例
 */
- (instancetype)initWithPath:(NSString*)aPath key:(NSString *)key;

/**
 *  线程安全封包操作
 *
 *  @param block 操作block
 */
- (void)inDatabase:(void (^)(id<AVFSDatabaseProtocol> db))block;

/**
 *  事务操作
 *
 *  @param block 操作block
 */
- (void)inTransaction:(void (^)(id<AVFSDatabaseProtocol> db, BOOL *rollback))block;

@end
