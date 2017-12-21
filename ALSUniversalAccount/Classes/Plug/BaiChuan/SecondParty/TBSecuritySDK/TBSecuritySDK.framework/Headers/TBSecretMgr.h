//
// TBSecuritySDK version 2.3.0
//


#include  <Foundation/Foundation.h>

@interface TBSecretMgr : NSObject

#pragma mark - 服务接口

/**
 *  获取TBSecretMgr全局单例对象
 *
 *  @return TBSecretMgr全局对象
 */
+ (TBSecretMgr*) sharedInstance;

/**
 *  返回SDK当前版本号
 *
 *  @return 当前版本号
 */
- (NSString*) getVersion;



#pragma mark - 环境设置接口

/**
 *  设置SDK的环境，0为线上，1为预发，2为日常
 *
 *  @param envIndex 环境参数 （注意，0，1，2的顺序只是yw_1222.jpg中存放appkey顺序的一个约定，可以自定义其顺序）
 */
-(void) TBSetAPIEnvironment:(int) envIndex;

/**
 *  当前使用环境 （0为线上，1为预发，2为日常）
 *
 *  @return 当前使用的环境
 */
-(int) TBGetAPIEnvironment;

/**
 *  返回当前使用的appkey，appkey来自yw_1222.jpg加密文件
 *
 *  @return 返回当前环境下对应的appkey，如线上环境返回线上appkey，日常返回日常appkey
 */
- (NSString*) getAppKeyWithIos;



#pragma mark - 签名接口

/**
 *  Top签名算法
 *
 *  @param data 要签名的参数
 *
 *  @return 返回Top签名字符串，失败时返回nil
 */
- (NSString*) getTopSignWithParam: (NSString*) data;

/**
 *  Mtop签名接口
 *
 *  @param data      mtop请求中的data字段
 *  @param api       mtop请求中的api字段
 *  @param v         mtop请求中的version字段
 *  @param ecode     mtop请求中的ecode字段
 *  @param imei      mtop请求中的imei字段
 *  @param imsi      mtop请求中的imsi字段
 *  @param timestamp mtop请求中的timestamp字段
 *
 *  @return 返回mtop签名，失败时返回nil
 */
- (NSString*) getMtopSignWithParm: (NSString*) data
                              Api: (NSString*) api
                          Version: (NSString*) v
                            Ecode: (NSString*) ecode
                             Imei: (NSString*) imei
                             Imsi: (NSString*) imsi
                        TimeStamp: (NSString*) timestamp;

/**
 *  Mtop V4签名接口
 *
 *  @param ecode    mtopv4请求中的ecode参数
 *  @param data     mtopv4请求中的data参数
 *  @param t        mtopv4请求中的timestamp参数
 *  @param api      mtopv4请求中的api参数
 *  @param v        mtopv4请求中的的version参数
 *  @param sid      mtopv4请求中的sid参数
 *  @param ttid     mtopv4请求中的的ttid参数
 *  @param deviceid mtopv4请求中的的deviciid参数
 *  @param lat      mtopv4请求中的latitude参数
 *  @param lng      mtopv4请求中的的longitude参数
 *
 *  @return 返回mtopv4签名，失败时返回nil
 */
- (NSString*) getMtopV4SignWithEcode: (NSString*) ecode
                                data: (NSString*) data
                           timestamp: (NSString*) t
                                 api: (NSString*) api
                             version: (NSString*) v
                                 sid: (NSString*) sid
                                ttid: (NSString*) ttid
                            deviceid: (NSString*) deviceid
                            latitude: (NSString*) lat
                           longitude: (NSString*) lng;


/**
 *  Mtop V4 Response签名
 *
 *  @param input 待校验的参数
 *
 *  @return 返回mtop v4 rsp签名，失败时返回nil
 */
- (NSString*) getMtopV4RespSignWithInput: (NSString*) input;

/**
 *  来往签名
 *
 *  @param input       待计算签名的字符串
 *  @param appkeyIndex 签名时需要使用的appsecret所对应的appkey在yw_1222.jpg中的index，从0开始
 *
 *  @return 返回appkeyIndex对应的appsecret计算出的来往签名，失败时返回nil
 */
- (NSString*) getLaiwangSignWithInput: (NSString*) input
                          appkeyIndex: (NSNumber*) appkeyIndex;

/**
 *  新版来往签名
 *
 *  @param input        待计算签名的字符串
 *  @param encryptedKey 使用appkeyIndex对应的appsecret加密过的密文
 *  @param appkeyIndex  解密encryptedKey时需要的appsecret所对应的appkey在yw_1222.jpg中的index，从0开始
 *
 *  @return 使用解密后的encryptedKey计算出的来往签名，失败时返回nil
 */
- (NSString*) getLaiwangSignWithInput: (NSString*) input
                         encryptedKey: (NSString*) encryptedKey
                          appkeyIndex: (NSNumber*) appkeyIndex;

/**
 *  天猫加签接口
 *
 *  @param input  待计算签名的字符串
 *  @param appkey 用来计算签名的appsecret所对应的appkey
 *
 *  @return 通过appkey对应的appsecret与input计算出的签名
 */
- (NSString*) getTmallSignWithInput: (NSString*) input
                             appkey: (NSString*) appkey;

/**
 *  获取agoo签名
 *
 *  @param input  拼接好的入参
 *  @param appkey 用来计算签名的appsecret对应的appkey
 *
 *  @return 返回通过appkey对应的secret与input计算出的签名
 */
- (NSString*) getAgooSignWithInput: (NSString*) input
                            appkey: (NSString*) appkey;



#pragma mark - 其他安全接口

/**
 *  获取top token 接口
 *
 *  @param user      用户的nick
 *  @param timestamp top请求中的时间戳参数
 *
 *  @return 返回toptoken
 */

- (NSString*) getTopTokenWithUser: (NSString*) user TimeStamp: (NSString*) timestamp;

/**
 *   获取安全校验串，该函数需要和服务器配合使用，在服务商进行相应的校验；
 *
 *  @param timestamp 时间戳参数
 *
 *  @return 通过时间戳与应用公钥进行计算后得到的校验串
 */
- (NSString*) getSecretParam: (NSString*) timestamp;



#pragma mark - SSO Token加解密接口

/**
 *  sso token专用加密接口
 *
 *  @param input sso token
 *
 *  @return 加密后的sso token，base64编码，失败时返回nil
 */
- (NSData*) encrypt: (NSData*) input;

/**
 *  sso token专用解密接口，与encryt接口配对使用
 *
 *  @param input sso token加密且base64后的密文
 *
 *  @return 解密后的明文sso token，失败时返回nil
 */
- (NSData*) decrypt: (NSData*) input;



#pragma mark - 人机识别接口

/**
 *  计算人机识别参数
 *
 *  @param timestamp 携带人机识别参数的网络请求中携带的时间戳参数，如mtop中的t参数类型的参数
 *
 *  @return 返回使用timestamp计算出的人机识别参数wua
 */
- (NSString*) secBodyData: (NSString*) timestamp;

/**
 *  UserTrack SDK写入User Track Record使用的接口，普通用户无需调用
 *
 *  @param usertrackData User Track 记录
 */
- (void) dataReceive: (NSString*) usertrackData;



#pragma mark - 环境安全接口

/**
 *  是否为越狱设备
 *
 *  @return 如果当前设备是越狱或模拟器，本接口返回YES，其他情况返回NO
 */
- (BOOL) isRoot;

/**
 *  是否是模拟器
 *
 *  @return 当前设备是否是模拟器
 */
- (BOOL) isSimulator;



#pragma mark - 废弃接口，请勿使用

/**
 *  向全局存储写入数据
 *
 *  @param anObject 待写入的对象
 *  @param aKey     指定的key
 */
- (void) setObject: (id<NSCoding>) anObject
            forKey: (NSString*) aKey __attribute__((deprecated));

/**
 *  获取全局存储中的数据
 *
 *  @param aKey 存储的值对应的key
 *
 *  @return aKey对应的全局存储中存储的值
 */
- (id) objectForkey: (NSString*) aKey __attribute__((deprecated));

/**
 *  删除apkey对应的全局存储中的值
 *
 *  @param aKey 想要删除的值对应的key
 */
- (void) removeObjectForKey: (NSString*) aKey __attribute__((deprecated));

/**
 *  检查一个方法是否被劫持
 *
 *  @param className 待检测的方法所属的类
 *  @param selectorName 方法名
 *
 *  @return 方法是否被劫持
 */
- (BOOL) checkMethodSecurity: (NSString*) className
                     SELName: (NSString*) selectorName __attribute__((deprecated));

@end

