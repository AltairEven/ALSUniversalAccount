//
//  NSDate+CommonDate.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSDate+CommonDate.h"

@implementation NSDate (CommonDate)

+ (NSDate *)GMTNow
{
    NSDate * now = [NSDate date];
    NSInteger gmtOffset = [[NSTimeZone localTimeZone] secondsFromGMT];
    return [NSDate dateWithTimeInterval:gmtOffset sinceDate:now];
}

+ (NSTimeInterval)nowTimeStamp {
    NSDate *date = [NSDate date];
    NSTimeZone *zone = [NSTimeZone systemTimeZone];
    NSInteger interval = [zone secondsFromGMTForDate: date];
    NSDate *localeDate = [date  dateByAddingTimeInterval: interval];
    return [localeDate timeIntervalSince1970];
}

@end
