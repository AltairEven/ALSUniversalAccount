//
// SecurityGuardSDK version 2.3.0
//

/**
 *  签名调用中，SecurityGuardParamContex中paramDict参数中使用到的key
 */

/**
 *  单参数签名接口入参key，common md5签名，
 *  common hmacsha1签名，top签名，mtopv4rsp签名，
 *  来往签名，1688签名，跳蚤街签名，旺信签名，
 *  umid签名使用，tmall签名，agoo签名
 */
extern NSString* const SG_KEY_SIGN_INPUT;



/**
 *  imei参数key，mtop签名使用
 */
extern NSString* const SG_KEY_SIGN_IMEI;



/**
 *  imsi参数key，mtop签名使用
 */
extern NSString* const SG_KEY_SIGN_IMSI;



/**
 *  ecode参数key, mtop签名使用
 */
extern NSString* const SG_KEY_SIGN_ECODE;



/**
 *  data参数key，mtop签名，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_DATA;



/**
 *  api参数key, mtop签名，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_API;



/**
 *  version参数key, mtop签名，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_VERSION;



/**
 *  timestamp参数key, mtop签名, mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_TIME;



/**
 *  sid参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_SID;



/**
 *  ttid参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_TTID;



/**
 *  deviceid参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_DEVICDEID;



/**
 *  latitude参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_LAT;



/**
 *  longitude参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_LNG;//纬度



/**
 *  m-ext参数key，mtopv4签名使用
 */
extern NSString* const SG_KEY_SIGN_EXT;//m-ext参数



/**
 *  param参数key，新来往签名使用
 */
extern NSString* const SG_KEY_SIGN_PARAM;



/**
 *  加密密钥参数key，新来往签名使用
 */
extern NSString* const SG_KEY_SIGN_KEY;



/**
 *  str1参数key，千牛签名使用
 */
extern NSString* const SG_KEY_SIGN_STR1;



/**
 *  str2参娄key，千牛签名使用
 */
extern NSString* const SG_KEY_SIGN_STR2;


/**
 *  Atlas参娄key，Atlas签名使用
 */
extern NSString* const SG_KEY_SIGN_ATLAS;



/**
 *  签名调用中，SecurityGuardParamContex中requestType参数中使用到的值
 */

/**
 *  common md5签名
 */
extern NSInteger const SG_ENUM_SIGN_COMMON_MD5;



/**
 *  common hmac sha1签名
 */
extern NSInteger const SG_ENUM_SIGN_COMMON_HMAC_SHA1;



/**
 *  top签名
 */
extern NSInteger const SG_ENUM_SIGN_TOP;



/**
 *  mtop签名
 */
extern NSInteger const SG_ENUM_SIGN_MTOP;



/**
 *  mtop v4签名
 */
extern NSInteger const SG_ENUM_SIGN_MTOP_V4;



/**
 *  mtop v4 rsp签名
 */
extern NSInteger const SG_ENUM_SIGN_MTOP_V4_RSP;



/**
 *  来往签名
 */
extern NSInteger const SG_ENUM_SIGN_LAIWANG;



/**
 *  新来往签名
 */
extern NSInteger const SG_ENUM_SIGN_LAIWANG_EX;



/**
 *  1688签名
 */
extern NSInteger const SG_ENUM_SIGN_1688;



/**
 *  千牛签名
 */
extern NSInteger const SG_ENUM_SIGN_QIANNIU;



/**
 *  跳蚤街签名
 */
extern NSInteger const SG_ENUM_SIGN_FLYSTREET;



/**
 *  旺信签名
 */
extern NSInteger const SG_ENUM_SIGN_WANGXIN;



/**
 *  umid签名
 */
extern NSInteger const SG_ENUM_SIGN_UMID;



/**
 *  tmall签名
 */
extern NSInteger const SG_ENUM_SIGN_TMALL;



/**
 *  agoo签名
 */
extern NSInteger const SG_ENUM_SIGN_AGOO;



/**
 *  mtop v4扩展签名
 */
extern NSInteger const SG_ENUM_SIGN_MTOP_V4_EX;



/**
 *  虾米签名
 */
extern NSInteger const SG_ENUM_SIGN_XIAMI;

/**
 *  Atlas
 签名
 */
extern NSInteger const SG_ENUM_SIGN_ATLAS;

/**
 *  Fast Atlas
 签名
 */
extern NSInteger const SG_ENUM_SIGN_ATLAS_FAST;

/**
 *  Fast Atlas2
 签名
 */
extern NSInteger const SG_ENUM_SIGN_ATLAS_FAST2;

/**
 *  无效签名类型
 */
extern NSInteger const SG_ENUM_SIGN_INVALID;