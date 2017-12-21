//
//  AliDBResultSet.h
//  AliVfsDB
//
//  Created by Pavel on 16/3/23.
//  Copyright © 2016年 Taobao lnc. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ALIDB_TYPE_INTEGER    1
#define ALIDB_TYPE_FLOAT      2
#define ALIDB_TYPE_TEXT       3
#define ALIDB_TYPE_BLOB       4
#define ALIDB_TYPE_NULL       5

@interface AliDBResultSet : NSObject

@property(nonatomic, strong) id statement;
@property(nonatomic, copy) dispatch_block_t finishBlock;


/**
 *  释放结果集操作
 *
 *  注意：查询完之后，必须调用该接口，释放AliDBResultSet
 */
- (void)close;

/**
 *  获取下条记录
 *
 *  @return 下一条记录是否存在
 */
- (BOOL)next;

/**
 *  通过列名获取int型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的int型值
 */
- (int)intForColumn:(NSString*)columnName;

/**
 *  通过列索引获取int型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的int型值
 */
- (int)intForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取long型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的long型值
 */
- (long)longForColumn:(NSString*)columnName;

/**
 *  通过列索引获取long型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的long型值
 */
- (long)longForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取long long型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的long long型值
 */
- (long long)longLongForColumn:(NSString*)columnName;

/**
 *  通过列索引获取long long型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的long long型值
 */
- (long long)longLongForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取double型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的double型值
 */
- (double)doubleForColumn:(NSString*)columnName;

/**
 *  通过列索引获取double型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的double型值
 */
- (double)doubleForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取string型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的string型值
 */
- (NSString*)stringForColumn:(NSString*)columnName;

/**
 *  通过列索引获取string型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的string型值
 */
- (NSString*)stringForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取bytes型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列的bytes型值
 */
- (NSData*)dataForColumn:(NSString*)columnName;

/**
 *  通过列索引获取bytes型值
 *
 *  @param[in]  columnIndex 列索引
 *
 *  @return 对应列的bytes型值
 */
- (NSData*)dataForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取列类型
 *
 *  @param[in] columnName  列名
 *
 *  @return 返回ALIDB_TYPE_INTEGER等以上定义的宏
 */
- (int)typeForColumn:(NSString*)columnName;

/**
 *  通过列索引获取列类型
 *
 *  @param[in] columnIndex  列索引
 *
 *  @return 返回ALIDB_TYPE_INTEGER等以上定义的宏
 */
- (int)typeForColumnIndex:(int)columnIndex;

/**
 *  通过列名获取对应的列索引
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列名的列索引
 */
- (int)columnIndexForName:(NSString*)columnName;

/**
 *  通过列索引获取对应的列名
 *
 *  @param[in]  columnIndex  列索引
 *
 *  @return 对应列索引的列名
 */
- (NSString*)columnNameForIndex:(int)columnIndex;

/**
 *  通过列名获取id型值
 *
 *  @param[in]  columnName  列名
 *
 *  @return 对应列名的id型值
 */
- (id)objectForColumn:(NSString*)columnName;

/**
 *  通过列索引获取id型值
 *
 *  @param[in]  columnIndex  列索引
 *
 *  @return 对应列索引的id型值
 */
- (id)objectForColumnIndex:(int)columnIndex;

/**
 *  返回结果数据，字典的k/v存储
 *
 *  @return 对应列索引的列名
 */
- (NSDictionary*)resultDictionary;


/**
 *  获取列数
 *
 *  @return 列数
 */
- (int)columnCount;

@end
