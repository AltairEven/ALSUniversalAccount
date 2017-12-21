//
//  NSDate+Convertion.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct {
    NSUInteger hour;
    NSUInteger min;
    NSUInteger sec;
}TimeStructHMS;

@interface NSDate (Convertion)
/**
 *  将HTTP时间字符串转换成NSDate
 *
 *  @param httpDate HTTP时间字符串
 *
 *  @return 返回值
 */
+ (NSDate *)dateFromHttpDateString:(NSString *)httpDate;
/**
 *  将时间戳转换成字符串
 *
 *  @param timeSeconds   为0时表示当前时间,可以传入你定义的时间戳
 *  @param timeFormatStr 为空返回当当时间戳,不为空返回你写的时间格式(yyyy-MM-dd HH:ii:ss)
 *  @param timeZoneStr   区域([NSTimeZone systemTimeZone]获得当前时区字符串)
 *
 *  @return 转换后的字符串
 */
+ (NSString *)formatTimeStamp:(NSTimeInterval)timeSeconds withTimeFormat:(NSString *)timeFormatStr timeZone:(NSString *)timeZoneStr;
/**
 *  将秒转换成字符串(天时分秒，0则不返回改单位)
 *
 *  @param interval 秒
 *
 *  @return 字符串
 */
+ (NSString *)timeStringFromTimeInterval:(NSTimeInterval)interval;
/**
 *  将秒转换成字符串(天时分秒，0则不返回改单位，最多取三个单位，从最大单位取起)
 *
 *  @param interval 秒
 *
 *  @return 字符串
 */
+ (NSString *)limitedTimeStringFromTimeInterval:(NSTimeInterval)interval;
/**
 *  将秒转换成字符串(天时分秒，0显示00)
 *
 *  @param interval 秒
 *  @param show     是否返回天
 *
 *  @return 字符串
 */
+ (NSString *)timeDHMSStringWithInterval:(NSTimeInterval)interval showDay:(BOOL)show;
/**
 *  将秒转换成时间结构
 *
 *  @param interval 秒
 *
 *  @return 时间结构
 */
+ (TimeStructHMS)timeStructHMSWithInterval:(NSTimeInterval)interval;

@end
