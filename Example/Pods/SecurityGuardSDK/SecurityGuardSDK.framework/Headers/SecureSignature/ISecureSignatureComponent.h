//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_ISecureSignatureComponent_h
#define SecurityGuardSDK_ISecureSignatureComponent_h

@class SecurityGuardParamContext;



/**
 *  签名接口
 */
@protocol ISecureSignatureComponent <NSObject>



/**
 *  发起签名请求
 *
 *  @param paramContext 包含签名所需要参数的结构体对象
 *
 *  @return 签名值，失败时返回nil
 */
- (NSString*) signRequest: (SecurityGuardParamContext*) paramContext;



@end



#endif
