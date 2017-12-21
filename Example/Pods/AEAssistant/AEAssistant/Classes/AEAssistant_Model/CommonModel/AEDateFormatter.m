//
//  AEDateFormatter.m
//  Pods
//
//  Created by Altair on 05/04/2017.
//
//

#import "AEDateFormatter.h"

@implementation AEDateFormatter

+ (NSDateFormatter *)dateFormatterWithFormatString:(NSString *)format {
    NSMutableDictionary *threadDic = [[NSThread mainThread] threadDictionary];
    
    NSString *key = [NSString stringWithFormat:@"AEDateFormatter:%@", format];
    NSDateFormatter *dateFormatter = [threadDic objectForKey:key];
    if (!dateFormatter) {
        dateFormatter = [[NSDateFormatter alloc] init];
        dateFormatter.dateFormat = format;
        [threadDic setObject:dateFormatter forKey:key];
    }
    return dateFormatter;
}

@end
