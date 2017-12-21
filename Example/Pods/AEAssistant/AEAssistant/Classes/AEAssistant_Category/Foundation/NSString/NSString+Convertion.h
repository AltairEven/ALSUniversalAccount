//
//  NSString+Convertion.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface NSString (Convertion)

+ (NSString *)distanceDescriptionWithMeters:(NSUInteger)meters;

+ (CLLocationCoordinate2D)coordinateFromString:(NSString *)string;

+ (NSString *)stringFromCoordinate:(CLLocationCoordinate2D)coordinate;

+ (NSString *)jsonFromObject:(id)obj;

@end
