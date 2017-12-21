//
//  UIDevice+DeviceInfo.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>

@interface CTTelephonyNetworkInfo(GTelephonyNetworkInfoAddition)

+(CTTelephonyNetworkInfo *)sharedTelephonyNetworkInfo;

@end

@interface UIDevice (DeviceInfo)

+ (NSString *)deviceInfo;

+ (NSString *)deviceVersion;

@end
