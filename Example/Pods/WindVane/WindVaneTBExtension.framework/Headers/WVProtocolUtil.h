/*
 * WVProtocolUtil.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/*!
 * 淘宝业务：URL跳转标记，用来判断当前执行Load的URL的类型
 */
typedef NS_ENUM(NSInteger, TBWVLinkType) {
	T_DETAIL = 100,
	T_SEARCH = 200,
	T_SHOP = 300,
	T_CART = 400,
	T_ORDER = 500,
	T_MYTB = 600,
	T_FAV = 700,
	T_YYZ = 800,
	T_WW = 900,
	T_LOGIN = 1000,
	T_LOGOUT = 1100,
	T_BUY = 1200,
	T_TMALL_PACKAGE = 1300,
	T_ITUNES = 1400
};

#pragma mark - 已废弃，预计于 2019.1.1 删除

DEPRECATED_MSG_ATTRIBUTE("这里的规则不再更新，功能已废弃，请自行实现 URL 拦截逻辑")
@interface WVProtocolUtil : NSObject

// 获取商品ID
+ (NSString *)getAuctionItemId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取店铺ID
+ (NSString *)getShopId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取店铺店主用户ID
+ (NSString *)getShopUserId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取搜索关键字
+ (NSString *)getSearchKeyWorkd:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取搜索的类目ID
+ (NSString *)getSearchCateId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取搜索的属性ID
+ (NSString *)getSearchPPath:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取订单状态类型值
+ (NSString *)getOrderStatus:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取下单操作的SKUID
+ (NSString *)getBuyOrderSkuId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取下单操作的购物车ID
+ (NSArray *)getCartId:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取旺旺聊天对方的用户名
+ (NSString *)getWWChatToUser:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取聚划算的KEY
+ (NSString *)getJHSKey:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

// 获取登陆回来后的URL，如果能获取到，则使用之，如果获取不到，则刷新当前webview中的页面
+ (NSString *)getReloadPageUrlAfterLogin:(NSDictionary *)param DEPRECATED_ATTRIBUTE;

@end
