//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 13-6-26.
//  Copyright (c) 2013年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBSDKCacheFile : NSObject


// 缓存文件 设置
+(BOOL)cacheFileSet:(NSString*)fileName contents:(NSString*)contents;

// 缓存文件 设置 NSData
+(BOOL)cacheFileSetNsdata:(NSString*)fileName contents:(NSData*)contents;

// 缓存文件 读取
+(NSString*)cacheFileGet:(NSString*)fileName;

// 缓存文件 读取 NSData
+(NSData*)cacheFileGetNSdata:(NSString*)fileName;

// 缓存文件 是否过期
// expiredSecond 过期多少秒
+(BOOL)cacheFileExpired:(NSString*)fileName expiredSecond:(NSInteger)expiredSecond;

// 缓存文件 是否存在
+(BOOL)cacheFileExists:(NSString*)fileName;

// 缓存文件 删除
+(BOOL)cacheFileDelete:(NSString*)fileName;

// 缓存文件 路径
+(NSString*)cacheFilePath:(NSString*)fileName;

// 删除所有缓存文件
+ (void)clearAllCache;

@end