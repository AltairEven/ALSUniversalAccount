//
// TBSecuritySDK version 2.3.0
//

#import <Foundation/Foundation.h>

@interface TBSAlgrithm : NSObject



/**
 *  umid签名专用签名算法，其他用户请忽略
 *
 *  @param payLoad 待签名的入参
 *
 *  @return 将appsec在payload首尾拼接后sha1的hexstring，如果失败返回nil
 */
+ (NSString*) makeSignatureWithPayload: (NSString*) payLoad;



/**
 *  将传入的NSString使用appsecret加密，因为appsecret做为密钥，鉴于appkey有变化的特性，所以本算法不适合持久化数据的加密
 *
 *  @param stringToEncrypt 待加密字符串
 *
 *  @return appsecret作为密钥种子，使用aes128加密再base64后的字符串，如果失败返回nil
 */
+ (NSString*) encryptString: (NSString*) stringToEncrypt;



/**
 *  将传入的base64 string密文使用appsecret解密，与encryptString配对使用。
 *
 *  @param stringtoDecrypt 待解密的base64NSString，
 *
 *  @return appsecret作为密钥种子，base64解码后，使用aes128解密后得到的字符串，如果失败返回nil
 */
+ (NSString*) decryptString: (NSString*) stringtoDecrypt;



/**
 *  将传入的NSString使用appKey对应的appsecret加密
 *
 *  @param stringToEncrypt stringToEncrypt 待加密字符串
 *  @param appKey 密钥种子的appsecret对应的appkey，此参数传错误的appkey时，将默认使用yw_1222.jpg中的第一个appsecet
 *
 *  @return appsecret作为密钥种子，使用aes128加密再base64后的字符串，如果失败返回nil
 */
+ (NSString*) encryptData: (NSString*) stringToEncrypt
               withAppKey: (NSString*) appKey;



/**
 *  将传入的密文NSString使用appsecret作为密钥解密，与encryptData:withAppKey配对使用
 *
 *  @param stringToDecrypt stringtoDecrypt 待解密的base64NSString
 *  @param appKey 密钥种子的appsecret对应的appkey，此参数传错误的appkey时，将默认使用yw_1222.jpg中的第一个appsecet
 *
 *  @return 解密后的明文，如果失败返回nil
 */
+ (NSString*) decryptData: (NSString*) stringToDecrypt
               withAppKey: (NSString*) appKey;



/**
 *  将传入的NSData使用appKey对应的appsecret加密
 *
 *  @param dataToEncrypt 待加密的NSData对象
 *  @param appKey 密钥种子appsecret对应的appkey，此参数传错误的appkey时，将默认使用yw_1222.jpg中的第一个appsecet
 *
 *  @return 使用appsecret作为密钥种子，使用aes128加密后的NSData对象，失败时返回nil
 */
+ (NSData*) encryptByte: (NSData*) dataToEncrypt
             withAppKey: (NSString*) appKey;



/**
 *  将传入的加密过的NSData对象使用appkey对应的appsececret解密，与encryptByte:withAppkey配对使用
 *
 *  @param dataToDecrypt 待解密数据
 *  @param appKey 密钥种子appsecret对应的appkey，此参数传错误的appkey时，将默认使用yw_1222.jpg中的第一个appsecet
 *
 *  @return 使用appsecret作为密钥种子，使用aes128解密后的NSData对象，失败时返回nil
 */
+ (NSData*) decryptByte: (NSData*) dataToDecrypt
             withAppKey: (NSString*) appKey;



@end
