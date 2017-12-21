//
//  CipherResultSet.h
//
//  Created by Pavel on 16/1/5.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TYPE_INTEGER    1
#define TYPE_FLOAT      2
#define TYPE_TEXT       3
#define TYPE_BLOB       4
#define TYPE_NULL       5

@interface CipherResultSet : NSObject

/**
 *  释放结果集操作
 *
 *  注意：查询完之后，必须调用该接口，释放CipherResultSet
 */
- (void)close;

/**
 *  设置statement
 *
 *  @param[in] statement CipherDB对应的Statement
 *
 *  注意：该接口供CipherDB内部使用，调用者不需要调用该接口。
 */
- (void)setStatement:(void*)statement;

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
 *  @param[out] code        错误码
 *
 *  @return 对应列的int型值
 */
- (int)intForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取int型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的int型值
 */
- (int)intForColumnIndex:(int)columnIndex  error:(int*)code;

/**
 *  通过列名获取long型值
 *
 *  @param[in]  columnName  列名
 *  @param[out] code        错误码
 *
 *  @return 对应列的long型值
 */
- (long)longForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取long型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的long型值
 */
- (long)longForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取long long型值
 *
 *  @param[in]  columnName  列名
 *  @param[out] code        错误码
 *
 *  @return 对应列的long long型值
 */
- (long long)longLongForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取long long型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的long long型值
 */
- (long long)longLongForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取double型值
 *
 *  @param[in]  columnName  列名
 *  @param[out] code        错误码
 *
 *  @return 对应列的double型值
 */
- (double)doubleForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取double型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的double型值
 */
- (double)doubleForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取string型值
 *
 *  @param[in]  columnName  列名
 *  @param[out] code        错误码
 *
 *  @return 对应列的string型值
 */
- (NSString*)stringForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取string型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的string型值
 */
- (NSString*)stringForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取bytes型值
 *
 *  @param[in]  columnName  列名
 *  @param[out] code        错误码
 *
 *  @return 对应列的bytes型值
 */
- (NSData*)dataForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取bytes型值
 *
 *  @param[in]  columnIndex 列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的bytes型值
 */
- (NSData*)dataForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取列类型
 *
 *  @param[in] columnName  列名
 *  @param[out] code       错误码
 *
 *  @return 对应列的类型
 */
- (int)typeForColumn:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取列类型
 *
 *  @param[in] columnIndex  列索引
 *  @param[out] code        错误码
 *
 *  @return 对应列的类型
 */
- (int)typeForColumnIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取对应的列索引
 *
 *  @param columnName[in]    列名
 *  @param code[out]         错误码
 *
 *  @return 对应列名的列索引
 */
- (int)columnIndexForName:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取对应的列名
 *
 *  @param columnIndex[in]  列索引
 *  @param code[out]        错误码
 *
 *  @return 对应列索引的列名
 */
- (NSString*)columnNameForIndex:(int)columnIndex error:(int*)code;

/**
 *  通过列名获取id类型值
 *
 *  @param columnName[in]   列名
 *  @param code[out]        错误码
 *
 *  @return 对应列索引的列名
 */
- (id)objectForColumnName:(NSString*)columnName error:(int*)code;

/**
 *  通过列索引获取id类型值
 *
 *  @param columnIndex[in]  列索引
 *  @param code[out]        错误码
 *
 *  @return 对应列索引的列名
 */
- (id)objectForColumnIndex:(int)columnIdx error:(int*)code;

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
