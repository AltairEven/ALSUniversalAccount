/*
 * WVCommonUtil.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVUserConfig.h"
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

// 判断是否是调试模式的宏。
#define WV_DEBUG [WVUserConfig isDebugMode]
// 返回指定名称 selector 的字符串。
#define WV_SEL_NAME(NAME) (NSStringFromSelector(@selector(NAME)))
// 将多行字面量转换为 char *，圆括号必须匹配。
#define WV_LITERAL_TO_STRING(...) #__VA_ARGS__
#define WV_LITERAL_VALUE_TO_STRING(...) WV_LITERAL_TO_STRING(__VA_ARGS__)
// 将多行字面量转换为 NSString *，圆括号必须匹配。
#define WV_LITERAL_TO_NSSTRING(...) @ #__VA_ARGS__
#define WV_LITERAL_VALUE_TO_NSSTRING(...) WV_LITERAL_TO_NSSTRING(__VA_ARGS__)
// 符号函数。
#define SGN_IMPL(X, L) ({ __typeof__(X) __NSX_PASTE__(__x,L) = (X); (__NSX_PASTE__(__x,L) < 0) ? -1 : (__NSX_PASTE__(__x,L) > 0); })
#define SGN(X) SGN_IMPL(X, __COUNTER__)

/**
 * 返回两个浮点数是否相等。
 */
NS_INLINE BOOL doubleEquals(double x, double y) {
	return fabs(x - y) < DBL_EPSILON;
}

/**
 * 返回指定浮点数是否为零。
 */
NS_INLINE BOOL doubleEqualToZero(double x) {
	return fabs(x) < DBL_EPSILON;
}

/**
 * 将弧度转换为角度。
 */
NS_INLINE double rad2deg(double radians) {
	return radians * 180.0 / M_PI;
}

// WindVane 网络状态。
typedef NS_ENUM(NSInteger, WVNetworkStatus) {
	WVNetworkStatusNone = 0, // 无网络。
	WVNetworkStatusWiFi = 1, // WiFi 网络。
	WVNetworkStatus2G = 2,   // 2G 网络。
	WVNetworkStatus3G = 3,   // 3G 网络。
	WVNetworkStatus4G = 4,   // 4G 网络。
	WVNetworkStatusWWAN = 5  // 未知非 WiFi 网络（无法区分 2G/3G/4G）。
};

// URL 的内容类型，其中 WVURLContentMediumSecurity 需要业务方自行设置，其它会自动根据 Domain 配置决定。
typedef NS_OPTIONS(NSInteger, WVURLContentType) {
	WVURLContentForbidden = -1,          // 要被禁止的内容。
	WVURLContentInsecurity = 1 << 0,     // 不安全的内容（未知的三方域名）。
	WVURLContentLowSecurity = 1 << 1,    // 低安全的内容（白名单内的三方域名）。
	WVURLContentMediumSecurity = 1 << 2, // 中级安全的内容（较为受控的三方域名）。
	WVURLContentHighSecurity = 1 << 3,   // 高安全的内容（Ali 域名）。
};

@interface WVCommonUtil : NSObject

#pragma mark - Number Util

/**
 * 返回一个随机的 double。
 *
 * @return 一个随机的 double 值，其范围为 [0, 1)。
 */
+ (double)randomDouble;

/**
 * 返回一个随机无符号整数。
 *
 * @return 一个随机的无符号整数，其范围为 [0, max)。
 */
+ (NSUInteger)randomUnsignedInteger:(NSUInteger)max;

/**
 * 生成一个随机数，并测试是否满足指定采样率。
 *
 * @param sampleRate 采样率，其范围为 [0, 1]。
 *
 * @return 如果生成的随机数满足采样率，则为 YES；否则为 NO。
 */
+ (BOOL)testSampleRate:(double)sampleRate;

#pragma mark - Domain Check

/**
 * 返回指定 URL 的内容类型。
 */
+ (WVURLContentType)getURLContentType:(NSString *)url;

/**
 * 检查是否是 Ali 安全域名。
 */
+ (BOOL)checkIsSecurityDomain:(NSString *)url;

/**
 * 检查是否是三方域名。
 */
+ (BOOL)checkIsThirdPartyDomain:(NSString *)url;

/**
 * 检查是否是黑名单域名。
 */
+ (BOOL)checkIsForbiddenDomain:(NSString *)url;

#pragma mark - String Util

/**
 * 利用时间戳、计数器、硬件地址产生的全局唯一标识。
 */
+ (NSString *)UUIDString;

/**
 * 修复直接将 JSON 字符串作为 js 使用时，\u2028 和 \u2029 导致 JS 报错的问题。
 */
+ (NSString *)fixJSON2JSBug:(NSString *)json;

#pragma mark - Network Util

/**
 * 获取网络状态。
 */
+ (WVNetworkStatus)networkStatus;

/**
 * 获取网络访问技术。
 */
+ (NSString *)networkAccess;

/**
 * 获取当前是否是 WiFi 环境。
 */
+ (BOOL)isWIFI;

/**
 * 返回指定的状态码是否表示成功。
 *
 * @param statusCode 要判断的状态码。
 *
 * @return 如果指定的状态码表示成功，则为 YES；否则为 NO。
 */
+ (BOOL)isStatusCodeSuccess:(NSInteger)statusCode;

#pragma mark - Other

/**
 * 返回本机处理器数目。
 */
+ (NSUInteger)processorCount;

/**
 * 返回应用启动或最近一次从后台切换到前台的时间。
 *
 * @return 返回应用启动或最近一次从后台切换到前台的时间。
 */
+ (NSTimeInterval)foregroundTime;

/**
 * 将服务器时间（自 1970 年 1 月 1 日以来的毫秒数）转换为本地时间。
 */
+ (long long)serverIntervalToLocal:(long long)interval;

@end

#pragma mark - Safe Type

#if defined __cplusplus
extern "C" {
#endif

#define WV_SAFE_TYPE_INVOKE(NAME, VALUE, DEFAULT, ...) NAME(VALUE, DEFAULT)

/**
 * 安全的转换为 BOOL 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
BOOL wvSafeBOOL(id value, BOOL defaultValue);
#define WV_SAFE_BOOL(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeBOOL, VALUE, ##__VA_ARGS__, NO)

/**
 * 安全的转换为 NSInteger 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
NSInteger wvSafeInteger(id value, NSInteger defaultValue);
#define WV_SAFE_INTEGER(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeInteger, VALUE, ##__VA_ARGS__, 0)

/**
 * 安全的转换为 NSUInteger 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
NSUInteger wvSafeUnsignedInteger(id value, NSUInteger defaultValue);
#define WV_SAFE_UINTEGER(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeUnsignedInteger, VALUE, ##__VA_ARGS__, 0)

/**
 * 安全的转换为 long long 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
long long wvSafeLongLong(id value, long long defaultValue);
#define WV_SAFE_LLONG(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeLongLong, VALUE, ##__VA_ARGS__, 0LL)

/**
 * 安全的转换为 unsigned long long 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
unsigned long long wvSafeUnsignedLongLong(id value, unsigned long long defaultValue);
#define WV_SAFE_ULLONG(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeUnsignedLongLong, VALUE, ##__VA_ARGS__, 0ULL)

/**
 * 安全的转换为 CGFloat 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
CGFloat wvSafeFloat(id value, CGFloat defaultValue);
#define WV_SAFE_FLOAT(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeFloat, VALUE, ##__VA_ARGS__, 0.0)

/**
 * 安全的转换为 double 类型，如果不存在或类型错误则返回默认值。
 * 具体的转换规则由 value 的实际类型决定。
 */
double wvSafeDouble(id value, double defaultValue);
#define WV_SAFE_DOUBLE(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeDouble, VALUE, ##__VA_ARGS__, 0.0)

/**
 * 安全的转换为 NSString 类型，如果不存在或类型错误则返回默认值。
 */
NSString * wvSafeString(id value, NSString * defaultValue);
#define WV_SAFE_STRING(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeString, VALUE, ##__VA_ARGS__, nil)

/**
 * 安全的转换为 NSArray 类型，如果不存在或类型错误则返回默认值。
 */
NSArray * wvSafeArray(id value, NSArray * defaultValue);
#define WV_SAFE_ARRAY(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeArray, VALUE, ##__VA_ARGS__, nil)

/**
 * 安全的转换为 NSDictionary 类型，如果不存在或类型错误则返回默认值。
 */
NSDictionary * wvSafeDictionary(id value, NSDictionary * defaultValue);
#define WV_SAFE_DICTIONARY(VALUE, ...) WV_SAFE_TYPE_INVOKE(wvSafeDictionary, VALUE, ##__VA_ARGS__, nil)

#pragma mark - Perform Block

/**
 * 如果当前已经是主线程，那么直接调用；否则在主线程异步调用指定 Block。
 */
void WVPerformBlockOnMainThread(dispatch_block_t block);

/**
 * 在主线程同步调用指定的 Block。
 */
void WVPerformBlockSyncOnMainThread(dispatch_block_t block);

/**
 * 在后台线程异步调用指定 Block。
 */
void WVPerformBlockOnGlobalThread(dispatch_block_t block);

/**
 * 在指定 queue 同步调用指定 Block。
 */
void WVPerformBlockSyncOnQueue(dispatch_queue_t queue, dispatch_block_t block);

#if defined __cplusplus
};
#endif
