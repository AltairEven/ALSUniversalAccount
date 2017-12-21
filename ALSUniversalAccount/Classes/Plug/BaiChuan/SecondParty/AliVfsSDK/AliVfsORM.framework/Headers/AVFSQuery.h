//
//  AVFSQuery.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/7/19.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSResultSet.h"
#import "AVFSObjectContext.h"

typedef NS_OPTIONS(NSUInteger, AVFSSortOrder) {
    AVFSSortOrderAscending = 1 << 0,
    AVFSSortOrderDescending = 1 << 1,
    AVFSSortOrderNoCase = 1 << 2,
};

@interface AVFSQuery : NSObject

/**
 *  where查询
 *
 *  @param where where条件
 *
 *  @return 查询实例
 */
- (AVFSQuery*)where:(NSString*)where;

/**
 *  格式化where查询
 *
 *  @param format 格式化的where条件
 *
 *  @return 查询实例
 */
- (AVFSQuery*)whereWithFormat:(NSString*)format,...;

/**
 *  参数化where查询
 *
 *  @param format 格式化的where条件
 *  @param params 格式化参数
 *
 *  @return 查询实例
 */
- (AVFSQuery*)whereWithFormat:(NSString*)format withParams:(NSArray*)params;

/**
 *  限制获取数
 *
 *  @param limit 限制上限
 *
 *  @return 查询实例
 */
- (AVFSQuery*)limit:(int)limit;

/**
 *  查询排序
 *
 *  @param property 要排序的属性名
 *  @param order    排序方式
 *
 *  @return 查询实例
 */
- (AVFSQuery*)orderOn:(NSString*)property by:(AVFSSortOrder)order;

/**
 *  查询偏移
 *
 *  @param offset 偏移量
 *
 *  @return 查询实例
 */
- (AVFSQuery*)offset:(int)offset;

/**
 *  获取对象组
 *
 *  @return 对象组
 */
- (AVFSResultSet *)fetch;

/**
 *  异步获取对象组
 *
 *  @param responseBlock 对象组回调
 */
- (void)asyncFetch:(void (^)(AVFSResultSet* results))responseBlock;

/**
 *  获取对象组到指定上下文
 *
 *  @param context 事务上下文
 *
 *  @return 对象组
 */
- (AVFSResultSet *)fetchIntoContext:(AVFSObjectContext*)context;

/**
 *  获取对象数目
 *
 *  @return 对象数目
 */
- (NSUInteger)count;

/**
 *  获取某个属性值的非重复列表
 *
 *  @param propertyName 属性名
 *
 *  @return 属性值的非重复列表
 */
- (NSArray*)distinct:(NSString*)propertyName;

/**
 *  获取某个属性值的总和
 *
 *  @param propertyName 属性名
 *
 *  @return 属性值的总和
 */
- (double)sum:(NSString*)propertyName;

/**
 *  获取对象组并按照属性分组
 *
 *  @param propertyName 属性名
 *
 *  @return 分组字典
 */
- (NSDictionary*)groupBy:(NSString*)propertyName;

@end
