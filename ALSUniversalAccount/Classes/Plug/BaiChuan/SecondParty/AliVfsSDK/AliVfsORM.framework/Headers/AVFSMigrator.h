//
//  AVFSMigrator.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/8/17.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AVFSMigrator : NSObject

/**
 *  数据库数据迁移
 *
 *  @param filePath        要迁移数据的数据库路径
 *  @param tablesToConvert 要迁移的表
 *  @param block           进度回调
 */
+ (void)migrateFromDatabaseFile:(NSString*)filePath tables:(NSArray*)tablesToConvert progressBlock:(void (^)(float progess, BOOL finished))block;

@end
