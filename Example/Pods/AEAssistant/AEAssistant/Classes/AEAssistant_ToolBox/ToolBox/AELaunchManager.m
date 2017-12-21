//
//  AELaunchManager.m
//  Pods
//
//  Created by Altair on 05/04/2017.
//
//

#import "AELaunchManager.h"
#import "NSDate+CommonDate.h"
#import "NSDate+Helpers.h"

#define kLastLaunchTimeKey (@"kAELaunchManager_LastLaunchTimeKey")
#define kNowLaunchTimeKey (@"kAELaunchManager_NowLaunchTimeKey")

@implementation AELaunchManager

+ (void)setLaunched {
    //当前时间
    NSDate *currentDate = [NSDate GMTNow];
    
    NSDate *lastLaunchDate = [[NSUserDefaults standardUserDefaults] objectForKey:kNowLaunchTimeKey];
    //记录当前启动时间
    [[NSUserDefaults standardUserDefaults] setObject:currentDate forKey:kNowLaunchTimeKey];
    if (!lastLaunchDate) {
        //如果存在已记录的当前启动时间，则把它记录为上次启动时间
        [[NSUserDefaults standardUserDefaults] setObject:currentDate forKey:kLastLaunchTimeKey];
    }
}

+ (BOOL)isDailyFirstLaunch {
    //获取上次启动时间
    NSDate *lastLaunchDate = [[NSUserDefaults standardUserDefaults] objectForKey:kLastLaunchTimeKey];
    //进入该方法，说明已启动
    [AELaunchManager setLaunched];
    if (!lastLaunchDate) {
        return YES;
    }
    NSDate *lastDayDate = [lastLaunchDate dateWithoutTime];
    NSDate *currentDayDate = [[NSDate GMTNow] dateWithoutTime];
    if ([lastDayDate compare:currentDayDate] == NSOrderedAscending) {
        //记录的日期比当前小
        return YES;
    }
    return NO;
}

@end
