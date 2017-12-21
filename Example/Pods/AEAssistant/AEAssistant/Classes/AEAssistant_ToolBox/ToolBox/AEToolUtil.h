//
//  AEToolUtil.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AEAssistant_Category.h"

@interface AEToolUtil : NSObject
/**
 *  把传入的参数按照get的方式打包到url后面
 *
 *  @param NSString 参数字典
 *
 *  @return 拼接后的字符串
 */
+ (NSString*)addQueryStringToUrl:(NSString *)url params:(NSDictionary *)params;
/**
 *  解析url string
 *
 *  @param urlString url string
 *
 *  @return 返回参数字典
 */
+ (NSDictionary*)parsetUrl:(NSString*)urlString;
/**
 *  比较版本号大小
 *
 *  @param firstVersion  第一个版本号
 *  @param secondVersion 第二个版本号
 *
 *  @return 返回第一个比第二个的结果
            -1 firstVersion < secondVersion
            0 firstVersion = secondVersion
            1 firstVersion > secondVersion
 */
+ (int)compareVersion:(NSString *)firstVersion version:(NSString *)secondVersion;
/**
 *  将包内文件拷贝到文件沙盒
 *
 *  @param bundlePath 包内路径
 *  @param filePath   文件路径
 *
 *  @return //如果filePath中已存在，则直接返回YES
            //如果bundle和filePath中都不存在，则返回NO
            //如果bundle中存在，则复制到filePath，并返回拷贝结果。
 */
+ (BOOL)copyFileFromBundlePath:(NSString *)bundlePath toFilePath:(NSString *)filePath;
/**
 *  当前应用版本号
 *
 *  @return 当前应用版本号
 */
+ (NSString *)currentAppVersion;
/**
 *  当前应用build版本号
 *
 *  @return 当前应用build版本号
 */
+ (NSString *)currentAppBuildVersion;
/**
 *  设置当前版本第一次启动
 *
 *  @param value 是否第一次启动
 */
+ (void)setHasFirstLaunched:(BOOL)has;
/**
 *  当前版本是否第一次启动
 *
 *  @return 是否第一次启动
 */
+ (BOOL)hasFirstLaunched;

/**
 获取当前最上层的VC

 @return 当前最上层VC
 */
+ (UIViewController *)topViewController;

@end
