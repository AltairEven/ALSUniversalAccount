/*
 * WVDomainConfigModel.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVCommonUtil.h"
#import "WVConfigModel.h"
#import <Foundation/Foundation.h>

#pragma mark - WVURLRule

/**
 URL 的规则。
 */
@interface WVURLRule : WVModelObject

/**
 * 预加载的额外响应 Header。
 */
@property (nonatomic, copy, readonly, nonnull) NSDictionary<NSString *, NSString *> * pkgHeader;

@end

#pragma mark - WVDomainConfigModel

/**
 * WindVane 域名配置。
 */
@interface WVDomainConfigModel : WVConfigModel

/**
 * Ali 域名，允许使用 JSBridge。
 */
@property (nonatomic, copy, nullable) NSString * aliDomain;

/**
 * 三方域名，不允许使用 JSBridge。
 */
@property (nonatomic, copy, nullable) NSString * thirdPartyDomain;

/**
 * 黑名单域名，不允许访问。
 */
@property (nonatomic, copy, nullable) NSString * forbiddenDomain;

/**
 * 黑名单域名要重定向到的 URL。
 */
@property (nonatomic, copy, nullable) NSString * forbiddenDomainRedirectURL;

#pragma mark - Domain Check

/**
 * 返回指定 URL 的内容类型。
 */
- (WVURLContentType)getURLContentType:(NSString * _Nullable)url;

/**
 * 检查是否是 Ali 安全域名。
 */
- (BOOL)checkIsAliDomain:(NSString * _Nullable)url;

/**
 * 检查是否是三方域名。
 */
- (BOOL)checkIsThirdPartyDomain:(NSString * _Nullable)url;

/**
 * 检查是否是黑名单域名。
 */
- (BOOL)checkIsForbiddenDomain:(NSString * _Nullable)url;

#pragma mark - URL Rule

/**
 返回与指定 URL 相关的规则。

 @param url 要检查的 URL。
 @return 与 URL 相关的规则，如果没有则返回 nil。
 */
- (WVURLRule * _Nullable)getURLRule:(NSString * _Nullable)url;

@end
