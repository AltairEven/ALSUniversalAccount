//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_IDynamicDataEncryptComponent_h
#define SecurityGuardSDK_IDynamicDataEncryptComponent_h



/**
 *  动态加解密接口
 */
@protocol IDynamicDataEncryptComponent <NSObject>



/**
 *  动态加密字符串值
 *
 *  @param key string值对应的key
 *
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSString*) dynamicEncrypt: (NSString*) plainText;


/**
 *  动态解密字符串值
 *
 *  @param cipherText string需要解密的字符串值
 *
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSString*) dynamicDecrypt: (NSString*) cipherText;




/**
 *  动态加密字符串值（加解密过程依赖设备硬件）
 *
 *  @param key string值对应的key
 *
 *  @return 返回加密结果，加密失败返回nil
 */
- (NSString*) dynamicEncryptDDp: (NSString*) plainText;


/**
 *  动态解密字符串值（加解密过程依赖设备硬件）
 *
 *  @param cipherText string需要解密的字符串值
 *
 *  @return 返回解密结果，解密失败返回nil
 */
- (NSString*) dynamicDecryptDDp: (NSString*) cipherText;

@end

#endif
