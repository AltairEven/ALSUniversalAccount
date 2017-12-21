//
//  DBOperationScheduler.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/9.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DBOpertaionQueue.h"
#import "DBConnectionPool.h"
#import "DBProcessorManager.h"

@interface DBOperationScheduler : NSObject

- (instancetype)initWithConnectionPool:(DBConnectionPool*)pool;

- (void)addOperation:(DBOpertaion*)operation;

#ifdef DEBUG
- (NSUInteger)mergedCount;
#endif

@end
