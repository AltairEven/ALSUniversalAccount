//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by Luke on 3/30/13.
// 
//  Copyright (c) 2013 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TBMTOPExternalCookiesKey @"TBMTOPExternalCookies"

@interface TBSDKCookieUtility : NSObject

/*!
 将Set Cookie对应的cookie字符串解析成一个字典数据结构
 example:
 "imewweoriw=i0syJl1Vo8MrJrrOh%2B24JA%3D%3D; Domain=.waptest.taobao.com; Expires=Sat, 30-Mar-2013 09:32:18 GMT; Path=/"
 转换成
 {
    imewweoriw = i0syJl1Vo8MrJrrOh%2B24JA%3D%3D;
    Domain = .waptest.taobao.com;
    Expires = Sat, 30-Mar-2013 09:32:18 GMT;
    Path = /
 }
 */
+ (NSDictionary *)cookieMapWithCookieString:(NSString *)cookieString;


/*!
 将一个普通的CookieMap转换成标准的Cookie Properties
 此CookieMap可能是从CookieString转换而来的map，也可能是api返回的一个cookie map
 */
+ (NSDictionary *)cookiePropertiesWithCookieMap:(NSDictionary *)cookieMap;

/**
 *  将单个NSHTTPCookie写入CookieStorage
 *
 *  @param cookieString 单条cookie的string字符，如："key=value: Domain=.taobao.com; Path=/; Expires=Sat, 30-Mar-2013 09:32:18 GMT"
 */
+ (void)setCookieWithCookieString:(NSString *)cookieString;

/**
 *  将单个NSHTTPCookie写入CookieStorage
 *
 *  @param cookieMap cookie对应的map结构，如:
 *    @{
 *      key=value;
 *      Domain=.taobao.com;
 *      Paht=/;
 *      Expires=Sat, 30-Mar-2013 09:32:18 GMT
 *    }
 */
+ (void)setCookieWithMTOPCookieMap:(NSDictionary *)cookieMap;

/*!
 登出后，不再清除所有的cookie，种什么清什么
+ (void)deleteAllCookiesFromCookieStorge;
 */

//专门用来处理MTOP登录的cookie的设置删除等操作
/*!
 目前的实践得出这样的结论，NSHTTPCookieStorage的删除或者设置cookie并不会同步的持久化到磁盘，有一会儿的延迟。如果在持久化之前app收到SIGKILL，则会导致cookie操作的失败。
 所以为了确保mtop登录cookie的正确性，将其在userDefaults中保存一份
 */
+ (void)setMTOPLoginCookiesWithCookieMaps:(NSArray *)cookieMaps ssoDomains:(NSArray *)ssoDomains;

/**
 *  <#Description#>
 *
 *  @param cookieStrings <#cookieStrings description#>
 *  @param ssoDomains    <#ssoDomains description#>
 */
+ (void)setMTOPLoginCookiesWithCookieStrings:(NSArray *)cookieStrings ssoDomains:(NSArray *)ssoDomains;
#pragma mark - 写cookie到cookie store中, 不扩展域名
//这个接口种进去的，不会主动删除，logout会删除
+ (void)setMTOPLoginCookiesWithCookieStringsWihoutExtDomain:(NSArray *)cookieStrings;
+ (void)reloadMTOPLoginCookiesFromUserDefaults;
+ (void)deleteMTOPLoginCookiesFromCookieStorageWithNeedClearSessionOnlyCookies:(BOOL)needClearSessionOnlyCookies;//从cookieStore中删除mtop登录cookie
+ (void)deleteMTOPLoginCookiesWithNeedClearSessionOnlyCookies:(BOOL)needClearSessionOnlyCookies;//删除所有的cookie包括记录在userdefaults中的

+ (void)deleteMTOPLoginExternalCookiesFromCookieStorage;

@end
