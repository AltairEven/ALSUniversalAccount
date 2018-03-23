//
// SecurityGuardSDK version 2.3.0
//

#import <Foundation/Foundation.h>



/**
 *  通用安全接口调用中，SecurityGuardParamContex中paramDict参数中使用到的key
 */

/**
 *  input参数key，sso token 加解密接口使用
 */
extern NSString* const SG_KEY_INDIE_KIT_INPUT;



/**
 *  user name参数key，toptoekn接口使用
 */
extern NSString* const SG_KEY_INDIE_KIT_USERNAME;



/**
 *  timeestamp参数key，toptoken接口，security check接口使用
 */
extern NSString* const SG_KEY_INDIE_KIT_TIMESTAMP;



/**
 *  filesignature参数key，validate file接口使用
 */
extern NSString* const SG_KEY_INDIE_KIT_FILESIGNATURE;



/**
 *  filehash参数key，validate file接口使用
 */
extern NSString* const SG_KEY_INDIE_KIT_FILEHASH;



/**
 *  通用安全接口调用中，SecurityGuardParamContex中requestType参数中使用到的值
 */

/**
 *  top token接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_TOP_TOKEN;



/**
 *  security check接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_SECURITY_CHECK;




/**
 *  sso token 加密接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_ENCRYPT_SSO_TOKEN;



/**
 *  sso token 解密接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_DECRYPT_SSO_TOKEN;



/**
 *  file validate 解密接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_VALIDATE_FILE;


/**
 *  无效通用安全接口
 */
extern NSInteger const SG_ENUM_INDIE_KIT_INVALID;