/*
 * WVCookieUtil.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

// HttpOnly 的 Cookie 名称。
FOUNDATION_EXPORT NSString * _Nonnull const WVHttpCookieHttpOnly;

@interface WVCookieUtil : NSObject

/**
 * 根据指定的字符串设置 Cookie。
 *
 * @param cookieStr 要设置的 Cookie 字符串。
 * @param url       Cookie 所属 URL，当 cookieStr 未提供 domain 或 path 时，基于此 URL 进行补全。
 *
 * @return 是否成功设置了 Cookie。
 */
+ (BOOL)setCookieWithString:(NSString * _Nullable)cookieStr forURL:(NSURL * _Nullable)url;

/**
 * 根据指定的字典设置 Cookie。
 *
 * @param cookieDict Cookie 属性字典。
 * @param url        Cookie 所属 URL，当 cookieDict 未提供 domain 或 path 时，基于此 URL 进行补全。
 *
 * @return 是否成功设置了 Cookie。
 */
+ (BOOL)setCookieWithDictionary:(NSDictionary<NSString *, NSString *> * _Nullable)cookieDict forURL:(NSURL * _Nullable)url;

/**
 * 读取指定 URL 下的所有 Cookie。
 */
+ (NSDictionary<NSString *, NSString *> * _Nonnull)readCookies:(NSURL * _Nonnull)url;

@end

/**
 * 提供 NSHTTPCookie 类的扩展方法。
 */
@interface NSHTTPCookie (WVUtility)

/**
 * 使用 Set-Cookie 对应的 cookie 字符串初始化。
 *
 * @param cookieStr Cookie 字符串。
 * @param url       Cookie 所属 URL，当 cookieStr 未提供 domain 或 path 时，基于此 URL 进行补全。
 *
 * @return 创建的 Cookie。
 *
 * @discussion 如果 Cookie 字符串未包含 domain，且 url 为 nil，则无法正确创建 Cookie。
 *
 * @code
 * NSURL * url = [NSURL URLWithString:@"http://h5.m.taobao.com/index.html"];
 * [NSHTTPCookie wvCookieWithString:@"myCookieName=myCookieValue; Domain=.m.taobao.com; Expires=Fri, 21-Dec-2012 09:32:18 GMT; Path=/" forURL:url];
 * @code
 */
+ (NSHTTPCookie * _Nullable)wvCookieWithString:(NSString * _Nonnull)cookieStr forURL:(NSURL * _Nullable)url;

/**
 * 使用 Cookie 属性字典初始化。
 *
 * @param cookieDict Cookie 属性字典。
 * @param url        Cookie 所属 URL，当 cookieDict 未提供 domain 或 path 时，基于此 URL 进行补全。
 *
 * @return 创建的 Cookie。
 *
 * @discussion 如果 Cookie 属性字典未包含 domain，且 url 为 nil，则无法正确创建 Cookie。
 */
+ (NSHTTPCookie * _Nullable)wvCookieWithDictionary:(NSDictionary<NSString *, NSString *> * _Nonnull)cookieDict forURL:(NSURL * _Nullable)url;

@end
