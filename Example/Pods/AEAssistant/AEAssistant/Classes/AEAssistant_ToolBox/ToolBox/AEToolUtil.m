//
//  AEToolUtil.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "AEToolUtil.h"

@implementation AEToolUtil

+ (NSString*)addQueryStringToUrl:(NSString *)url params:(NSDictionary *)params {
    if (nil == url) {
        return @"";
    }
    NSMutableString *urlWithQuerystring = [[NSMutableString alloc] initWithString:url];
    // Convert the params into a query string
    if (params) {
        for(id key in params) {
            NSString *sKey = [key description];
            NSString *sVal = [[params objectForKey:key] description];
            //是否有？，必须处理这个
            if ([urlWithQuerystring rangeOfString:@"?"].location==NSNotFound) {
                [urlWithQuerystring appendFormat:@"?%@=%@", [sKey urlEscape], [sVal urlEscape]];
            } else {
                [urlWithQuerystring appendFormat:@"&%@=%@", [sKey urlEscape], [sVal urlEscape]];
            }
        }
    }
    
    return urlWithQuerystring;
}


+ (int)compareVersion:(NSString *)firstVersion version:(NSString *)secondVersion {
    int result = 0;
    NSArray *firstVersionItems = [firstVersion componentsSeparatedByString:@"."];
    NSArray *secondVersionItems = [secondVersion componentsSeparatedByString:@"."];
    for (int i = 0; i<[firstVersionItems count] || i< [secondVersionItems count]; i++)
    {
        int firstItem = 0;
        int secondItem = 0;
        if (i<[firstVersionItems count])
        {
            firstItem = [[firstVersionItems objectAtIndex:i] intValue];
        }
        if (i<[secondVersionItems count])
        {
            secondItem = [[secondVersionItems objectAtIndex:i] intValue];
        }
        
        if (firstItem != secondItem)
        {
            result = (firstItem<secondItem)?-1:1;
            break;
        }
    }
    
    return result;
}


+ (NSDictionary*)parsetUrl:(NSString*)urlString {
    if ([urlString length] == 0) {
        return nil;
    }
    NSString *questionSymbol = @"?";
    NSInteger index = [urlString rangeOfString:questionSymbol].location;
    if([urlString length] > index+1)
    {
        urlString = [urlString substringFromIndex:index+1];
    }
    NSString *connectSymbol = @"&";
    NSArray *arrayOfKeyValue = [urlString componentsSeparatedByString:connectSymbol];
    NSString *key = nil;
    NSString *value = nil;
    NSString *equalSymbol = @"=";
    NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
    for(NSString *str in arrayOfKeyValue)
    {
        NSArray *array = [str componentsSeparatedByString:equalSymbol];
        if([array count] == 2)
        {
            key = [array objectAtIndex:0];
            value = [array objectAtIndex:1];
        }else if([array count] == 1)
        {
            key = [array objectAtIndex:0];
            value = @" ";
        }
        else if([array count]>2)
        {
            key = [array objectAtIndex:0];
            
            NSInteger equalSymbolIndex = [str rangeOfString:equalSymbol].location;
            if([str length] > equalSymbolIndex+1)
            {
                value = [str substringFromIndex:equalSymbolIndex+1];
            }
            else
            {
                value = @" ";
            }
        }
        else
        {
            key = @" ";
            value = @" ";
        }
        [dic setObject:value forKey:key];
    }
    if ([dic count] == 0) {
        return nil;
    }
    return [NSDictionary dictionaryWithDictionary:dic];
}


+ (BOOL)copyFileFromBundlePath:(NSString *)bundlePath toFilePath:(NSString *)filePath {
    NSFileManager *manager = [NSFileManager defaultManager];
    if ([manager fileExistsAtPath:filePath isDirectory:NULL]) {
        return YES;
    }
    if (![manager fileExistsAtPath:bundlePath isDirectory:NULL]) {
        return NO;
    }
    BOOL checkCopyValidData = YES;//判断是否拷贝成功
    NSError *error=nil;
    [[NSFileManager defaultManager] copyItemAtPath:bundlePath toPath:filePath error:&error ];
    if (error!=nil) {
        NSLog(@"%@", error);
        NSLog(@"%@", [error userInfo]);
        checkCopyValidData = NO;
    }
    return checkCopyValidData;
}

+ (NSString *)currentAppVersion {
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *version = [infoDict objectForKey:@"CFBundleShortVersionString"];
    return version;
}

+ (NSString *)currentAppBuildVersion {
    NSDictionary *infoDict = [[NSBundle mainBundle] infoDictionary];
    NSString *version = [infoDict objectForKey:@"CFBundleVersion"];
    return version;
}


+ (void)setHasFirstLaunched:(BOOL)has {
    [[NSUserDefaults standardUserDefaults] setObject:[NSNumber numberWithBool:has] forKey:[AEToolUtil currentAppVersion]];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

+ (BOOL)hasFirstLaunched {
    BOOL has = [[[NSUserDefaults standardUserDefaults] objectForKey:[AEToolUtil currentAppVersion]] boolValue];
    return has;
}

+ (UIViewController *)topViewController {
    UIViewController *resultVC = [AEToolUtil topViewControllerOfViewController:[[UIApplication sharedApplication].keyWindow rootViewController]];
    while (resultVC.presentedViewController) {
        resultVC = [AEToolUtil topViewControllerOfViewController:resultVC.presentedViewController];
    }
    return resultVC;
}

+ (UIViewController *)topViewControllerOfViewController:(UIViewController *)vc {
    if ([vc isKindOfClass:[UINavigationController class]]) {
        return [AEToolUtil topViewControllerOfViewController:[(UINavigationController *)vc topViewController]];
    } else if ([vc isKindOfClass:[UITabBarController class]]) {
        return [AEToolUtil topViewControllerOfViewController:[(UITabBarController *)vc selectedViewController]];
    } else {
        return vc;
    }
    return nil;
}

@end
