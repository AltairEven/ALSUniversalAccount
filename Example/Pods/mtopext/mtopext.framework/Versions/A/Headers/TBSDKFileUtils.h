//
//  TBSDKFileUtils.h
//  mtopsdk
//
//  Created by sihai on 30/7/14.
//  Copyright (c) 2014 mtop. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBSDKFileUtils : NSObject

/**
 * 判断文件是否存在
 * param fileName 完整路径的文件名
 * return
 *          TRUE    存在
 *          FALSE   不存在
 */
+(BOOL) isExists: (NSString*) fileName;

/**
 *
 */
+(NSString*) getFileName: (NSString*) filePath;

/**
 * 获取文件名后缀
 * param fileName 文件名
 * return
 *          "" 非规范的文件名
 *          文件名后缀, 如 jpg, gif, png等等
 */
+(NSString*) getSuffix: (NSString*) fileName;

@end
