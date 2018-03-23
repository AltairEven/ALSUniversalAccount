//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_IIndieKitComponent_h
#define SecurityGuardSDK_IIndieKitComponent_h

@class SecurityGuardParamContext;



/**
 *  独立安全接口
 */
@protocol IIndieKitComponent <NSObject>



/**
 *  发起安全接口调用请求
 *
 *  @param paramContext 参数结构体对象
 *
 *  @return 安全接口返回值，失败时返回nil
 */
- (NSString*) indieKitRequest: (SecurityGuardParamContext*) paramContext;



/**
 *  对文件完整性进行校验
 *
 *  @param signature 待校验的文件的签名，base64字符串
 *  @param hash      待校验的文件的hash值，base64字符串
 *  @param key       计算文件签名时用到的密钥所对应的key
 *
 *  @return 文件校验结果，-1代表接口调用失败，0代表文件与签名不对应，1代代表文件与签名对应
 */
- (int) validateFileSignature: (NSString*) signature
                     fileHash: (NSString*) hash
                    secretKey: (NSString*) key;



@end



#endif
