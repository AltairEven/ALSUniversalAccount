//
//  NSDate+Convertion.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSDate+Convertion.h"

static NSDateFormatter* CreateDateFormatter(NSString *format)
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"en_US"]];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithAbbreviation:@"GMT"]];
    [dateFormatter setDateFormat:format];
    return dateFormatter;
}

@implementation NSDate (Convertion)

+ (NSDate *)dateFromHttpDateString:(NSString *)httpDate
{
    static NSDateFormatter *RFC1123DateFormatter;
    static NSDateFormatter *ANSICDateFormatter;
    static NSDateFormatter *RFC850DateFormatter;
    NSDate *date = nil;
    
    @synchronized(self) // NSDateFormatter isn't thread safe
    {
        // RFC 1123 date format - Sun, 06 Nov 1994 08:49:37 GMT
        if (!RFC1123DateFormatter) RFC1123DateFormatter = CreateDateFormatter(@"EEE, dd MMM yyyy HH:mm:ss z");
        date = [RFC1123DateFormatter dateFromString:httpDate];
        if (!date)
        {
            // ANSI C date format - Sun Nov  6 08:49:37 1994
            if (!ANSICDateFormatter) ANSICDateFormatter = CreateDateFormatter(@"EEE MMM d HH:mm:ss yyyy");
            date = [ANSICDateFormatter dateFromString:httpDate];
            if (!date)
            {
                // RFC 850 date format - Sunday, 06-Nov-94 08:49:37 GMT
                if (!RFC850DateFormatter) RFC850DateFormatter = CreateDateFormatter(@"EEEE, dd-MMM-yy HH:mm:ss z");
                date = [RFC850DateFormatter dateFromString:httpDate];
            }
        }
    }
    
    return date;
}


+ (NSString *)formatTimeStamp:(NSTimeInterval)timeSeconds withTimeFormat:(NSString *)timeFormatStr timeZone:(NSString *)timeZoneStr
{
    NSString *dateString;
    NSDate *ordDate;
    
    if( timeSeconds>0){
        ordDate = [NSDate dateWithTimeIntervalSince1970:timeSeconds];
    } else {
        ordDate = [[NSDate alloc] init];
    }
    
    if( timeFormatStr==nil){
        dateString =[NSString stringWithFormat:@"%u",(unsigned int)[ordDate timeIntervalSince1970]];
    }else{
        NSDateFormatter *dateFormatter =[[NSDateFormatter alloc] init];
        [dateFormatter setDateFormat:timeFormatStr];
        
        if( timeZoneStr != nil){
            [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:timeZoneStr]];
        }
        
        dateString =[dateFormatter stringFromDate: ordDate];
    }
    
    return dateString;
}


+ (NSString *)timeStringFromTimeInterval:(NSTimeInterval)interval {
    NSInteger ti = (NSInteger)interval;
    NSInteger seconds = ti % 60;
    NSInteger minutes = (ti / 60) % 60;
    NSInteger days = (ti / 86400);
    NSInteger hours = (ti / 3600 ) % 24;
    
    if (days > 0) {
        return [NSString stringWithFormat:@"%li天%02li小时%02li分%02li秒", (long)days, (long)hours, (long)minutes, (long)seconds];
    }
    
    if (hours > 0) {
        return [NSString stringWithFormat:@"%02li小时%02li分%02li秒", (long)hours, (long)minutes, (long)seconds];
    }
    
    if (minutes > 0) {
        return [NSString stringWithFormat:@"%02li分%02li秒", (long)minutes, (long)seconds];
    }
    
    return [NSString stringWithFormat:@"%02li秒", (long)seconds];
}

+ (NSString *)limitedTimeStringFromTimeInterval:(NSTimeInterval)interval {
    NSInteger ti = (NSInteger)interval;
    NSInteger seconds = ti % 60;
    NSInteger minutes = (ti / 60) % 60;
    NSInteger days = (ti / 86400);
    NSInteger hours = (ti / 3600 ) % 24;
    
    if (days > 0) {
        return [NSString stringWithFormat:@"%li天%02li小时%02li分", (long)days, (long)hours, (long)minutes];
    }
    
    if (hours > 0) {
        return [NSString stringWithFormat:@"%02li小时%02li分%02li秒", (long)hours, (long)minutes, (long)seconds];
    }
    
    if (minutes > 0) {
        return [NSString stringWithFormat:@"%02li分%02li秒", (long)minutes, (long)seconds];
    }
    
    return [NSString stringWithFormat:@"%02li秒", (long)seconds];
}


+ (NSString *)timeDHMSStringWithInterval:(NSTimeInterval)interval showDay:(BOOL)show {
    NSUInteger intTime = interval;
    
    NSUInteger day = intTime / 3600 / 24;
    NSUInteger hour = (intTime % (24 * 3600)) / 3600;
    NSUInteger minute = (intTime % 3600) / 60;
    NSUInteger second = (intTime % 3600) % 60;
    NSString *timeString = @"";
    if (day < 1) {
        timeString = [NSString stringWithFormat:@"%02lu时%02lu分%02lu秒", (unsigned long)hour, (unsigned long)minute, (unsigned long)second];
    } else {
        if (show) {
            timeString = [NSString stringWithFormat:@"%lu天%02lu时%02lu分%02lu秒", (unsigned long)day, (unsigned long)hour, (unsigned long)minute, (unsigned long)second];
        } else {
            hour += day * 24;
            timeString = [NSString stringWithFormat:@"%02lu时%02lu分%02lu秒", (unsigned long)hour, (unsigned long)minute, (unsigned long)second];
        }
    }
    return timeString;
}


+ (TimeStructHMS)timeStructHMSWithInterval:(NSTimeInterval)interval {
    NSUInteger intTime = interval;
    TimeStructHMS t1;
    t1.hour = intTime / 3600;
    t1.min = (intTime % 3600) / 60;
    t1.sec = (intTime % 3600) % 60;
    return t1;
}


@end
