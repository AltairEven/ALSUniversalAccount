//
//  AliSecXLocalStorage.h
//  AliSecXLocalStorage
//
//  Created by jupeng.xia on 14-8-20.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSInteger{
    AliSec_LocalStorage_Folder_Documents,
    AliSec_LocalStorage_Folder_Library
}AliSec_LocalStorage_Folder;

@interface AliSecXLocalStorage : NSObject

/*
 *功能:     从keychain中载入key对应的字符串
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回对应字符串，失败返回nil
 *@param key:不能为nil
 */
+(NSString*) loadStringFromKeychain:(NSString*) key;

/*
 *功能:     从keychain中指定service中载入key对应的字符串
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回对应字符串，失败返回nil
 *@param key:不能为nil
 */
+(NSString*) loadStringFromKeychain:(NSString*) key service:(NSString*)serviceName;

/*
 *功能:     将字符串（键－值对）存入keychain
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回value长度，失败返回0
 *@param key:键、值都不能为nil
 */
+(NSInteger) saveStringToKeychain:(NSString*) key Value:(NSString*)value;

/*
 *功能:     从keychain中删除字符串（键－值）
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param key:不能为nil
 */
+(BOOL) deleteItemFromKeychain:(NSString*) key;

/*
 *功能:     从keychain中指定service中删除字符串（键－值）
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param key:不能为nil
 */
+(BOOL) deleteItemFromKeychain:(NSString*) key service:(NSString*)serviceName;

/*
 *功能:     从keychain中载入字符串
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回key对应字符串,失败返回nil
 *@param key:不能为nil
 *@param error:失败时保存错误信息
 */
+(NSString*) loadStringFromKeychain:(NSString*) key error:(NSError **)error;

/*
 *功能:     将字符串(键－值对)存入keychain
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param key:不能为nil
 *@param value:不能为nil
 *@param error:失败时保存错误信息
 */
+(BOOL) saveStringToKeychain:(NSString*) key Value:(NSString*)value error:(NSError **)error;

/*
 *功能:     从keychain中删除字符串（键－值对）
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param key:不能为nil
 *@param error:失败时保存错误信息
 */
+(BOOL) deleteItemFromKeychain:(NSString*) key error:(NSError **)error;

+(NSData*) loadDataFromKeychain:(NSString*) key;
+(NSInteger) saveDataToKeychain:(NSString*) key Value:(NSData*)value;

/*
 *功能:     从app沙盒的Documentation文件夹内载入字节流数据
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件名对应字节流,失败返回nil
 *@param fileName:文件名，不能包含特殊字符，不能包含子文件（夹）
 *@param error:失败时保存错误信息
 */
//+(NSData*) loadDataFromFile:(NSString*) fileName;

/*
 *功能:     将字节流数据存入app沙盒内的Documentation内
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param fileName:保存文件名，不能为nil，不能包含特殊字符，不能包含子文件（夹）
 *@param value：字节流数据
 */
//+(BOOL) saveDataToFile:(NSString*) fileName Value:(NSData*)value;

/*
 *功能:     测试app沙盒的Documentation文件夹内是否包含某文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param fileName:文件名，不能为nil，不能包含特殊字符，不能包含子文件（夹）
 */
+(BOOL)isFileExist:(NSString*)fileName;

/*
 *功能:     在app沙盒的Documentation文件夹内创建新文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param fileName:文件名，不能为nil，不能包含特殊字符，不能包含子文件（夹）
 */
+(BOOL)createFile:(NSString*)fileName;

/*
 *功能:     获取app沙盒的Documentation文件夹文件列表
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件列表,失败返回nil
 *@param error:失败时保存错误信息
 */
//+(NSArray*) getDocumentsFolderFileList:(NSError **)error;

/*
 *功能:     获取app沙盒的Documentation文件夹内文件大小
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件大小，失败返回0
 *@param fileName:文件名，不能为nil，不能包含特殊字符，不能包含子文件（夹）
 *@param error:失败时保存错误信息
 */
+(unsigned long long) getFileSize:(NSString*)fileName error:(NSError **)error;

/*
 *功能:     移除app沙盒的Documentation文件夹内文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes，失败返回no
 *@param fileName:文件名，不能为nil，不能包含特殊字符，不能包含子文件（夹）
 *@param error:失败时保存错误信息
 */
+(BOOL)removeFile:(NSString*)fileName error:(NSError **)error;

//+(void) appendDataToFile:(NSString*)subPath Value:(NSData*)value;
//@property(nonatomic,strong) NSString *docPath;

/*
 *功能:     从app沙盒的指定文件夹内载入字节流数据
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件名对应字节流,失败返回nil
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 */
+(NSData*) loadDataFromFile:(NSString*) fileName fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path;

/*
 *功能:     将字节流数据存入app沙盒内的指定文件夹内
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回保存的字节数,失败返回0
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 *@param value：字节流数据
 */
+(NSInteger) saveDataToFile:(NSString*) fileName Value:(NSData*)value fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path;

/*
 *功能:     测试app沙盒的指定文件夹内是否包含某文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 */
+(BOOL)isFileExist:(NSString*)fileName fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path;

/*
 *功能:     在app沙盒的指定文件夹内创建新文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes,失败返回no
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 */
+(BOOL)createFile:(NSString*)fileName fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path error:(NSError **)error;

/*
 *功能:     获取app沙盒的指定文件夹内文件列表
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件列表,失败返回nil
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 *@param error:失败时保存错误信息
 */
+(NSArray*) getDocumentsFolderFileListFromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path error:(NSError **)error ;

/*
 *功能:     获取app沙盒的指定文件夹内文件大小
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回文件大小，失败返回0
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 *@param error:失败时保存错误信息
 */
+(unsigned long long) getFileSize:(NSString*)fileName fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path error:(NSError **)error;

/*
 *功能:     移除app沙盒的指定文件夹内文件
 *线程安全: 是
 *可重入:   是
 *@return: 成功返回yes，失败返回no
 *@param fileName:文件名，不能包含特殊字符
 *@param folder:选择app内置文件夹
 *@param path:内置文件夹到文件名之间的路径
 *@param error:失败时保存错误信息
 */
+(BOOL)removeFile:(NSString*)fileName fromFolder:(AliSec_LocalStorage_Folder)folder withPath:(NSString*)path error:(NSError **)error;

@end






















