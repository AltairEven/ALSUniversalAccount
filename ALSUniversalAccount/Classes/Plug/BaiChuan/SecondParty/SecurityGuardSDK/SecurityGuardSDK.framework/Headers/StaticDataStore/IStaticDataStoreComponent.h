//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_IStaticDataStoreComponent_h
#define SecurityGuardSDK_IStaticDataStoreComponent_h



/**
 *  静态解密接口
 */
@protocol IStaticDataStoreComponent <NSObject>



/**
 *  根据传入的key，返回key的种类，种类定义请见staticdatadefine.h
 *
 *  @param key 要判断类型的key
 *
 *  @return key的类型，定义请见staticdatadefine.h
 */
- (NSInteger) getKeyType: (NSString*) key;



/**
 *  根据index找到对应的appkey（index从0开始，按在无线保镖网站生成加密文件时填写的顺序排列）
 *
 *  @param index key的顺序
 *
 *  @return index对应的appkey，调用失败时返回nil
 */
- (NSString*) getAppKey: (NSNumber*) index;



/**
 *  根据key，找到对应的extradata
 *
 *  @param key 目标extradata对应的key
 *
 *  @return key对应的extradata，调用失败时返回nil
 */
- (NSString*) getExtraData: (NSString*) key;



@end



#endif
