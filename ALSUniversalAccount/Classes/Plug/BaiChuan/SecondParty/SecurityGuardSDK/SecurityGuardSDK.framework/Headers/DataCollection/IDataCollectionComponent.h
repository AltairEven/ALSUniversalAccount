//
// SecurityGuardSDK version 2.3.0
//

#import <Foundation/Foundation.h>

@protocol IDataCollectionComponent <NSObject>

/**
 *  设置用户昵称
 *  @param umid, 用户昵称
 *  @return YES, 设置后值发生改变, NO, 设置失败或值未发生改变
 */
- (BOOL) setNick:(NSString*) nick;


/**
 *  获取用户昵称
 *
 *  @return 用户昵称，获取失败返回nil
 */
- (NSString*) getNick;

/**
 *  设置用户昵称
 *  @param nick, 用户昵称
 *  @param flag, 目前当flag&1 ＝＝ 1成立时表示获取alipay的nick
 *  @return YES, 设置后值发生改变, NO, 设置失败或值未发生改变
 */
- (BOOL) setNickEx: (int) flag  nick:(NSString*) nick;


/**
 *  获取用户昵称
 *  @param flag, 目前当flag&1 ＝＝ 1成立时表示获取alipay的nick
 *
 *  @return 用户昵称，获取失败返回nil
 */
- (NSString*) getNickEx: (int) flag;


/**
 *  获取加密的的设备与环境信息
 *
 *  @param mode 要使用加密算法的种类，定义请见StaticDataEncryptDefine.h
 *  @param key  加密时使用的密钥所对应的 key
 *
 *  @return 加密后的设备与环境信息
 */
- (NSString*) getEncryptedDevAndEnvInfo: (int) mode  key: (NSString*) key;

@end
