//
//  AVFSObject.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/7/19.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSQuery.h"
#import "AVFSObjectContext.h"

@interface AVFSObject : NSObject

@property (nonatomic, strong)   NSNumber                      *Id;

/**
 *  初始化并添加到上下文
 *
 *  @param context 上下文
 *
 *  @return 元对象
 */
- (instancetype)initWithContext:(AVFSObjectContext *)context;

/**
 *  指定Entity模块名
 *
 *  @return 模块名
 */
+ (NSString *)moduleForEntity;

/**
 *  指定索引
 *
 *  @return 索引列表
 */
+ (NSArray *)indexesForEntity;

/**
 *  属性默认值
 *
 *  @return 属性默认值键值对
 */
+ (NSDictionary*)defaultValuesForEntity;

/**
 *  不重复的唯一属性
 *
 *  @return 属性名列表
 */
+ (NSArray*)uniqueProperties;

/**
 *  获取查询对象
 *
 *  @return 查询对象
 */
+ (AVFSQuery *)query;

/**
 *  清除所有记录
 */
+ (void)clearRecords;

/**
 *  保存或更新到DB
 *
 *  @return 是否成功（注：如果对象在事务上下文中，则该接口不会进行保存，执行该操作是不必要的，需要事务上下文进行commit才能保存）
 */
- (BOOL)save;

/**
 *  从DB中移除
 *
 *  @return 是否成功（注：如果对象在事务上下文中，则该接口不会真正进行删除，但是该操作会设置标记因而是必要的，需要事务上下文进行commit才能最终删除）
 */
- (BOOL)remove;

@end
