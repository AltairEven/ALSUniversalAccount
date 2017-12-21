//
//  NSString+Convertion.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+Convertion.h"

@implementation NSString (Convertion)


+ (NSString *)distanceDescriptionWithMeters:(NSUInteger)meters {
    NSString *des = @"";
    if (meters < 1000) {
        des = [NSString stringWithFormat:@"%lu米", (unsigned long)meters];
    } else {
        CGFloat km = meters / 1000.0;
        des = [NSString stringWithFormat:@"%.2f千米", km];
    }
    return des;
}

+ (CLLocationCoordinate2D)coordinateFromString:(NSString *)string {
    if (![string isKindOfClass:[NSString class]]) {
        return CLLocationCoordinate2DMake(0, 0);
    }
    if ([string length] == 0) {
        return CLLocationCoordinate2DMake(0, 0);
    }
    NSArray *components = [string componentsSeparatedByString:@","];
    if ([components count] != 2) {
        return CLLocationCoordinate2DMake(0, 0);
    }
    
    NSString *lonString = [components firstObject];
    [lonString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    CLLocationDegrees lon = [lonString doubleValue];
    
    NSString *latString = [components lastObject];
    [latString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    CLLocationDegrees lat = [latString doubleValue];
    
    return CLLocationCoordinate2DMake(lat, lon);
}

+ (NSString *)stringFromCoordinate:(CLLocationCoordinate2D)coordinate {
    return [NSString stringWithFormat:@"%f,%f", coordinate.longitude, coordinate.latitude];
}


+ (NSString *)jsonFromObject:(id)obj {
    if (!obj) {
        return nil;
    }
    NSString *jsonString = nil;
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:obj
                                                       options:NSJSONWritingPrettyPrinted // Pass 0 if you don't care about the readability of the generated string
                                                         error:&error];
    if (! jsonData) {
        NSLog(@"Got an error: %@", error);
    } else {
        jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    return jsonString;
}

@end
