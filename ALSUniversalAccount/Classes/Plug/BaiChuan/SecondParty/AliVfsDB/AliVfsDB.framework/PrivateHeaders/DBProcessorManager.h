//
//  DBProcessorManager.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/11.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AliDB.h"

@interface DBProcessorManager : NSObject

- (NSInteger)setSQLExtProcessor:(id<AliDBSQLExtProcessor>)processor extType:(NSString*)type;
- (id<AliDBSQLExtProcessor>)processorForType:(NSString*)type;

@end
