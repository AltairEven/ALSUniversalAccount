//
//  AEHttpCookieManager.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/22.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "AEHttpCookieManager.h"


static AEHttpCookieManager *_sharedManager = nil;

@implementation AEHttpCookieManager

- (id)init
{
    self = [super init];
    if (self) {
    }
    
    return self;
}


+ (instancetype)sharedManager
{
    static dispatch_once_t predicate = 0;
    
    dispatch_once(&predicate, ^ (void) {
        _sharedManager = [[AEHttpCookieManager alloc] init];
    });
    
    return _sharedManager;
}


- (void)setIcsonCookieWithName:(NSString *)name andValue:(NSString *)value
{
    if (!name || !value) {
        return;
    }
    NSDictionary *propertiesKidsTC = [NSDictionary dictionaryWithObjectsAndKeys:
                                      name, NSHTTPCookieName,
                                      value, NSHTTPCookieValue,
                                      @"/", NSHTTPCookiePath,
                                      self.cookieDomain, NSHTTPCookieDomain, nil];
    NSHTTPCookie *kisTCCookie = [NSHTTPCookie cookieWithProperties:propertiesKidsTC];
    
    //set cookie
    [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookie:kisTCCookie];
}


- (void)setCookie:(NSHTTPCookie *)cookie
{
    [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookie:cookie];
}


- (void)setIcsonCookiesWithNameValueDictionaries:(NSArray *)array
{
    if (!array) {
        return;
    }
    
    for (NSDictionary *properties in array) {
        [self setIcsonCookieWithName:[[properties allKeys] objectAtIndex:0] andValue:[[properties allValues] objectAtIndex:0]];
    }
}



- (void)setIcsonCookiesWithNamesAndValues:(NSString *)first, ...
{
    va_list arguments;
    NSString *eachString;
    if (first) {
        va_start(arguments, first);
        
        int n = 0;
        NSMutableArray *nameArray = [[NSMutableArray alloc] initWithObjects:first, nil];
        NSMutableArray *valueArray = [[NSMutableArray alloc] init];
        
        while ((eachString = va_arg(arguments, NSString *))) {
            NSLog(@"%@",eachString);
            n ++;
            if (n % 2) {
                //奇数位是value
                [valueArray addObject:eachString];
            } else {
                //偶数位是name
                [nameArray addObject:eachString];
            }
            
        }
        va_end(arguments);
        //调用设置cookie方法
        [self setIcsonCookiesWithNames:nameArray andValues:valueArray];
    }
}


- (void)setIcsonCookiesWithNames:(NSArray *)namesArray andValues:(NSArray *)valuesArray
{
    if (!namesArray || !valuesArray) {
        return;
    }
    NSUInteger nameCount = [namesArray count];
    NSUInteger valueCount = [valuesArray count];
    if (nameCount != valueCount) {
        return;
    }
    
    for (NSUInteger n = 0; n < nameCount; n ++) {
        NSString *name = [namesArray objectAtIndex:n];
        NSString *value = [valuesArray objectAtIndex:n];
        [self setIcsonCookieWithName:name andValue:value];
    }
}


- (void)setCookies:(NSArray *)cookiesArray
{
    [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookies:cookiesArray forURL:nil mainDocumentURL:nil];
}


- (NSHTTPCookie *)getCookieWithName:(NSString *)name
{
    if (!name) {
        return nil;
    }
    NSHTTPCookieStorage *storage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    for (NSHTTPCookie *cookie in [storage cookies])
    {
        if ([cookie.name isEqualToString:name] && [cookie.domain isEqualToString:self.cookieDomain]) {
            return cookie;
        }
    }
    return nil;
}


- (NSArray *)getCookiesWithNames:(NSArray *)namesArray
{
    if (!namesArray) {
        return nil;
    }
    
    NSMutableArray *cookieArray = [[NSMutableArray alloc] init];
    for (NSString *name in namesArray) {
        NSHTTPCookie *cookie = [self getCookieWithName:name];
        if (cookie) {
            [cookieArray addObject:cookie];
        }
    }
    
    if ([cookieArray count] > 0) {
        return cookieArray;
    }
    return nil;
}


- (NSArray *)getAllCookies
{
    return [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies];
}


- (void)deleteCookieWithName:(NSString *)name
{
    if (!name) {
        return;
    }
    NSHTTPCookieStorage *storage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    for (NSHTTPCookie *cookie in [storage cookies])
    {
        if ([cookie.name isEqualToString:name]) {
            [storage deleteCookie:cookie];
        }
    }
}


- (void)deleteAllCookies
{
    NSHTTPCookieStorage *storage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    for (NSHTTPCookie *cookie in [storage cookies])
    {
        [storage deleteCookie:cookie];
    }
}

@end
