//
//  AliSecXDeviceInfo.h
//  AliSecXDeviceInfo
//
//  Created by jupeng.xia on 14-8-20.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AliSecXSafeUtils.h"

typedef enum: NSInteger {
    AliSecX_NETWORK_STATUS_NOTREACHABLE,
    AliSecX_NETWORK_STATUS_REACHABLEVIAWIFI,
    AliSecX_NETWORK_STATUS_REACHABLEVIAWWAN,
    AlisecX_NETWORK_STATUS_REACHABLEVIA4G,
    AlisecX_NETWORK_STATUS_REACHABLEVIA3G,
    AlisecX_NETWORK_STATUS_REACHABLEVIA2G

} AliSecXNetworkStatusEnum;

typedef void(^APSecPhotoInfoCallback) (NSArray* photos, BOOL order);

/**
 *  越狱检测
 *
 *  (uint16_t)APSecCheckJailBreak;
 */
#define APSecCheckJailBreak (APSecXSafeUtils->isJailbreak())

/*--------------------obfuscated function names -----------------------------------------*/

#define deviceInfo_UUID _16923bf24c2b4257b579fcc6bffd0888

#define DEVICE_CONCAT_DEF_DETAIL(a, b, c) a ## b ## c
#define DEVICE_CONCAT_DEF(a, b, c) DEVICE_CONCAT_DEF_DETAIL(a, b, c)
#define deviceInfo_new_name(idx) DEVICE_CONCAT_DEF(deviceInfo_UUID, idx , 20160518L)

//#define OBFUSCATION 1

#ifdef OBFUSCATION

#define getNetworkStatus   deviceInfo_new_name(1)
#define getOSVersion       deviceInfo_new_name(2)
#define getOSName          deviceInfo_new_name(3)
#define getBundleId        deviceInfo_new_name(4)
#define screenResolution   deviceInfo_new_name(5)
#define isJailBreak        deviceInfo_new_name(6)
#define isEmulator         deviceInfo_new_name(7)
//#define carrierName        deviceInfo_new_name(8)
#define getDeviceName      deviceInfo_new_name(9)
#define getIdForVendor     deviceInfo_new_name(10)
#define getAdvId           deviceInfo_new_name(11)
#define getModelName       deviceInfo_new_name(12)
#define getCpuFreq         deviceInfo_new_name(13)
#define getCpuCount        deviceInfo_new_name(14)
#define getDiskSpace       deviceInfo_new_name(15)
#define getDiskFreeSpace   deviceInfo_new_name(16)
#define getBatteryLevel    deviceInfo_new_name(17)
#define getBatteryStatus   deviceInfo_new_name(18)
#define getSSIDInfo        deviceInfo_new_name(19)
#define getKernHostName    deviceInfo_new_name(20)
#define getHWModel         deviceInfo_new_name(21)
#define getScreenWidth     deviceInfo_new_name(22)
#define getScreenHeight    deviceInfo_new_name(23)
#define getMemorySize      deviceInfo_new_name(24)
#define getAppName         deviceInfo_new_name(25)
#define getAppVersion      deviceInfo_new_name(26)
#define getNetworkInfo     deviceInfo_new_name(27)
#define getAppList         deviceInfo_new_name(28)
#define getLanguage        deviceInfo_new_name(29)
#define getTimezone        deviceInfo_new_name(30)
#define getMNC             deviceInfo_new_name(31)
#define getMCC             deviceInfo_new_name(32)
#define getSysUpTime       deviceInfo_new_name(33)
#define getSDKUpTime       deviceInfo_new_name(34)
#define getPhotoInfo       deviceInfo_new_name(35)
#define getContactInfo     deviceInfo_new_name(36)
#define getAvailableSensors        deviceInfo_new_name(37)
#define getFingerIdHashInfo        deviceInfo_new_name(38)
#define isSwizzlingForVendorId     deviceInfo_new_name(39)
#define isSwizzlingForAdvId        deviceInfo_new_name(40)

#endif

@interface AliSecXDeviceInfo : NSObject

/* move this method to somewhere !*/
+ (NSInteger) getNetworkStatus: (NSString *) serverHostName;

+ (NSString *) getOSVersion;

+ (NSString *) getOSName;

+ (NSString *) getBundleId;

+ (NSString *) screenResolution;

+ (uint16_t) isJailBreak;

+ (BOOL) isEmulator;

+ (NSString *) carrierName;

+ (NSString *) getDeviceName;

+ (NSString *) getIdForVendor;

+ (NSString *) getAdvId;

+ (NSString *) getModelName;

+ (NSInteger) getCpuFreq;

+ (NSInteger) getCpuCount;

+ (NSNumber *) getDiskSpace;

+ (NSNumber*) getDiskFreeSpace;

+ (float) getBatteryLevel;

+ (NSInteger) getBatteryStatus;;

+ (NSString *) getSSIDInfo;

+ (NSString *) getKernHostName;

+ (NSString* ) getHWModel;

+ (NSString *) getScreenWidth;

+ (NSString *) getScreenHeight;

+ (unsigned long long) getMemorySize;

+ (NSString *) getAppName;

+ (NSString *) getAppVersion;

+ (NSDictionary *) getNetworkInfo;

+ (NSData *)getAppList:(NSArray *)appURLList;

+ (NSString *) getLanguage;

+ (NSString *) getTimezone;

+ (NSString*)getMNC;

+ (NSString*)getMCC;

+ (NSString*)getSysUpTime;

+ (NSString*)getSDKUpTime;

+ (void)getPhotoInfo:(APSecPhotoInfoCallback)callback;

+ (NSDictionary*)getContactInfo;

+ (NSDictionary*)processContactList:(NSArray*)dic;

//add sensors
+ (NSString*)getAvailableSensors;
//add get touch id hash
+ (NSData *)getFingerIdHashInfo;
//add check whether api method swizzle or not 
+ (uint16_t) isSwizzlingForVendorId;
+ (uint16_t) isSwizzlingForAdvId;

@end
