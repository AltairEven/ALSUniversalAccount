//
//  ThreadPoolManager.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/9.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ThreadPoolManager : NSObject

typedef void (^OperationExecBlock)();

+ (ThreadPoolManager*)sharedInstance;
- (void)submit:(OperationExecBlock)block;

- (NSInteger)setMaxConcurrentCount:(NSInteger)maxConcurrentCount;

@end
