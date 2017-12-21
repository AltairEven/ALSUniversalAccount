//
//  AEHttpCookieManager.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/22.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

//管理[NSHTTPCookieStorage sharedHTTPCookieStorage]中的cookie
@interface AEHttpCookieManager : NSObject

@property (nonatomic, strong) NSString *cookieDomain;

/*
 *brief:AEHttpCookieManager单例方法
 *return:AEHttpCookieManager实例
 */
+ (instancetype)sharedManager;

/*
 *brief:根据name和value设置cookie
 *param:name
 *param:value
 *return:void
 */
- (void)setIcsonCookieWithName:(NSString *)name andValue:(NSString *)value;

/*
 *brief:设置cookie
 *param:cookie
 *return:void
 */
- (void)setCookie:(NSHTTPCookie *)cookie;

/*
 *brief:根据Dictionary（name为key，value为value）数组设置cookie
 *param:Dictionary（name为key，value为value）数组
 *return:void
 */
- (void)setIcsonCookiesWithNameValueDictionaries:(NSArray *)array;

/*
 *brief:根据name和value不定参数设置cookie
 *param:name1, value1, name2, value2,..., nil
 *return:void
 */
- (void)setIcsonCookiesWithNamesAndValues:(NSString *)first, ...;

/*
 *brief:根据name数组和value数组设置cookie，数组长度要相等
 *param:name数组
 *param:value数组
 *return:void
 */
- (void)setIcsonCookiesWithNames:(NSArray *)namesArray andValues:(NSArray *)valuesArray;

/*
 *brief:根据cookie数组设置cookie
 *param:cookie数组
 *return:void
 */
- (void)setCookies:(NSArray *)cookiesArray;

/*
 *brief:根据name获取cookie（domain关联）
 *param:name
 *return:name对应domain关联域名的cookie
 */
- (NSHTTPCookie *)getCookieWithName:(NSString *)name;

/*
 *brief:根据name数组获取cookie（domain关联）数组
 *param:name数组
 *return:name对应domain关联域名的cookie数组
 */
- (NSArray *)getCookiesWithNames:(NSArray *)namesArray;

/*
 *brief:获取所有cookie
 *return:所有cookie的数组
 */
- (NSArray *)getAllCookies;

/*
 *brief:根据name删除cookie
 *param:name
 *return:void
 */
- (void)deleteCookieWithName:(NSString *)name;

/*
 *brief:删除所有cookie
 *return:void
 */
- (void)deleteAllCookies;

@end
