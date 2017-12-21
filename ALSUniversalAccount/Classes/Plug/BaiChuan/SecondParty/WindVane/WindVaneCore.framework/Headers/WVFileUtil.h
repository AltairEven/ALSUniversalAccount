/*
 * WVFileUtil.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface WVFileUtil : NSObject

/**
 * 返回主 Bundle。
 */
+ (NSBundle *)mainBundle;

/**
 * 获取临时文件目录。
 */
+ (NSString *)getTempPath:(NSString *)path;

/**
 * 获取 WindVane App 目录 Documents/wvapp。
 */
+ (NSString *)getWVAppPath;

/**
 * 获取 WindVane Config 目录 Documents/wvapp/config。
 */
+ (NSString *)getConfigPath;

/**
 * 获取 WindVane 缓存目录 /Library/Caches/WindVane。
 */
+ (NSString *)getCachesPath;

/**
 * 获取与指定 URL 相关的 WindVane 缓存目录文件 /Library/Caches/WindVane/md5(url).ext。
 * 会移除 URL 的 query 和 fragment，只保留路径本身。
 */
+ (NSString *)getCachesFilePath:(NSString *)url;

/**
 * 返回指定路径的短描述，一般用于展示或埋点。
 *
 * @param path 本地文件路径。
 *
 * @return 指定路径的短描述。
 */
+ (NSString *)getPathDesc:(NSString *)path;

#pragma mark - pathUtil

/**
 * 创建指定路径的文件夹。
 *
 * @param path  要创建的文件夹路径。
 *
 * @return 是否成功创建文件夹。
 */
+ (BOOL)createFolder:(NSString *)path;

/**
 * 创建指定路径的文件夹。
 *
 * @param path  要创建的文件夹路径。
 * @param error 创建文件夹的错误信息。
 *
 * @return 是否成功创建文件夹。
 */
+ (BOOL)createFolder:(NSString *)path error:(NSError **)error;

/**
 * 创建指定文件夹，并拒绝被 iCloud 同步。
 *
 * @param path  要创建的文件夹路径。
 */
+ (void)createFolderWithoutBackup:(NSString *)path;

/**
 * 移除指定路径的文件/文件夹。
 *
 * @param path  要移除的文件/文件夹路径。
 *
 * @return 是否成功移除文件夹。
 */
+ (BOOL)removeItemAtPath:(NSString *)path;

/**
 * 移除指定路径的文件/文件夹。
 *
 * @param path  要移除的文件/文件夹路径。
 * @param error 移除文件夹的错误信息。
 *
 * @return 是否成功移除文件夹。
 */
+ (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error;

/**
 * 将指定路径的文件/文件夹复制到其它路径。
 *
 * @param srcPath 要复制的源路径。
 * @param dstPath 要复制到的目标路径。
 *
 * @return 是否成功复制文件/文件夹。
 */
+ (BOOL)copyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;

/**
 * 将指定路径的文件/文件夹复制到其它路径。
 *
 * @param srcPath 要复制的源路径。
 * @param dstPath 要复制到的目标路径。
 * @param error   复制的错误信息。
 *
 * @return 是否成功复制文件/文件夹。
 */
+ (BOOL)copyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;

/**
 * 将指定路径的文件/文件夹移动到其它路径。
 *
 * @param srcPath 要移动的源路径。
 * @param dstPath 要移动到的目标路径。
 *
 * @return 是否成功移动文件/文件夹。
 */
+ (BOOL)moveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;

/**
 * 将指定路径的文件/文件夹移动到其它路径。
 *
 * @param srcPath 要移动的源路径。
 * @param dstPath 要移动到的目标路径。
 * @param error   移动的错误信息。
 *
 * @return 是否成功移动文件/文件夹。
 */
+ (BOOL)moveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error;

/**
 * 将指定文件夹内的的文件/文件夹复制到其它文件夹，而不是直接替换整个文件夹。
 *
 * @param srcDir 要复制的源文件夹。
 * @param dstDir 要复制到的目标文件夹。
 * @param error  复制的错误信息。
 *
 * @return 是否成功复制文件/文件夹。
 */
+ (BOOL)copyItemInDirectory:(NSString *)srcDir toDirectory:(NSString *)dstDir error:(NSError **)error;

/**
 * 遍历指定路径下的所有文件。
 * 递归遍历请谨慎使用，磁盘和内存消耗较大。
 *
 * @param path        要遍历的文件夹。
 * @param isRecursive 是否递归的遍历子文件夹。
 *
 * @return 指定路径下的所有文件。
 */
+ (NSArray<NSString *> *)listAllFilesAt:(NSString *)path isRecursive:(BOOL)isRecursive;

/**
 * 返回指定文件的大小。
 */
+ (u_int64_t)fileSizeForPath:(NSString *)path;

/**
 * 返回指定文件夹的大小。
 */
+ (u_int64_t)folderSize:(NSURL *)directory;

/**
 * 设置文件的属性，拒绝被 iCloud 同步。
 */
+ (BOOL)addSkipBackupAttributesToFile:(NSURL *)filePath;

/**
 * 获取文件的最后一次修改时间。
 */
+ (NSTimeInterval)getFileLastModifiedTime:(NSString *)filePath;

/**
 * 更新文件最后修改时间。
 */
+ (void)updateFileLastModifiedTime:(NSString *)filePath;

@end
