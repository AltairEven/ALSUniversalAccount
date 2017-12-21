//
// SecurityGuardSDK version 2.3.0
//

#import <Foundation/Foundation.h>

/**
 *  各compoent的compoentid，在获取component对象时传入
 */
typedef enum {
    /**
     *  签名component
     */
    SecureSignatureComponentID,
    /**
     *  动态存储component
     */
    DynamicDataStoreComponentID,
    /**
     *  通用安全接口component
     */
    IndieKitComponentID,
    /**
     *  静态存储component
     */
    StaticDataStoreComponentID,
    /**
     *  初始化component
     */
    InitComponentID,
    /**
     *  人机识别compnent
     */
    SecurityBodyCompnentID,
    /**
     *  Root detect compnent
     */
    RootDetectCompnentID,
    /**
     *  Simulator detect compnent
     */
    SimulatorDetectCompnentID,
    /**
     *  静态加解密component
     */
    StaticDataEncryptCompnentID,
    /**
     *  data collection compnent
     */
    DataCollectionCompnentID,
    /**
     *  dynamic data encrypt componentID
     */
    DynamicDataEncryptComponentID,
    /**
     *  DNS Hijack componentID
     */
    SecurityDNSComponentID,
    /**
     *  数据采集 componentID
     */
    UATraceComponentID,
    /**
     *  NoCapthca componentID
     */
    NoCaptchaComponentID,
    /**
     *  AtlasEncrypt ComponentID
     */
    AtlasEncryptComponentID,
    /**
     *  无效component
     */
    InvalidComponentID
    
} SecurityGuardComponentID;



/**
 *  签名接口，详细定义见：ISecureSignatureComponent.h
 */
@protocol ISecureSignatureComponent;

/**
 *  动态数据存储接口，详细定义见：IDynamicDataStoreComponent.h
 */
@protocol IDynamicDataStoreComponent;

/**
 *  独立安全接口，详细定义见：IIndieKitComponent.h
 */
@protocol IIndieKitComponent;

/**
 *  静态数据存储接口，详细定义见：IStaticDataStoreComponent.h
 */
@protocol IStaticDataStoreComponent;

/**
 *  人机识别接口，详细定义见：ISecurityBodyComponent.h
 */
@protocol ISecurityBodyComponent;

/**
 *  root测接口，详细定义见：IRootDetectComponent.h
 */
@protocol IRootDetectComponent;

/**
 *  模拟器检测接口，详细定义见：ISimulatorDetectComponent.h
 */
@protocol ISimulatorDetectComponent;

/**
 *  静态数据存储接口，详细定义见：IStaticDataEncryptComponent.h
 */
@protocol IStaticDataEncryptComponent;

/**
 *  数据采集接口，详细定义见：IDataCollectionComponent.h
 */
@protocol IDataCollectionComponent;

/**
 *  动态数据加密接口，详细定义见：IDynamicDataEncryptComponent.h
 */
@protocol IDynamicDataEncryptComponent;

/**
 *  dns校验接口，详细定义见：ISecurityDNSComponent.h
 */
@protocol ISecurityDNSComponent;

/**
 *  数据采集接口，详细定义见：IUATraceComponent.h
 */
@protocol IUATraceComponent;

/**
 *  NoCaptcha无痕验证码接口，详细定义见：INoCaptchaComponent.h
 */
@protocol INoCaptchaComponent;

/**
 *  AtlasEncrypt接口，详细定义见：IAtlasEncryptComponent.h
 */
@protocol IAtlasEncryptComponent;
/**
 *  SecurityGuardSDK管理类
 */
@interface SecurityGuardManager : NSObject



/**
 *  获取SecurityGuardManager单例对象
 *
 *  @return SecurityGuardManager单例对象
 */
+ (SecurityGuardManager*) getInstance;



/**
 *  获取安全签名接口
 *
 *  @return 返回签名接口，失败时nil
 */
- (id<ISecureSignatureComponent>) getSecureSignatureComp;



/**
 *  获取动态数据存储接口
 *
 *  @return 返回动态数据存储接口，失败时nil
 */
- (id<IDynamicDataStoreComponent>) getDynamicDataStoreComp;



/**
 *  获取独立安全接口
 *
 *  @return 返回独立安全接口，失败时nil
 */
- (id<IIndieKitComponent>) getIndieKitComp;



/**
 *  获取静态数据存储接口
 *
 *  @return 返回静态数据存储接口，失败时nil
 */
- (id<IStaticDataStoreComponent>) getStaticDataStoreComp;



/**
 *  获取人机识别接口
 *
 *  @return 返回人机识别接口，失败时nil
 */
- (id<ISecurityBodyComponent>) getSecurityBodyComp;



/**
 *  获取人机识别接口
 *
 *  @return 返回人机识别接口，失败时nil
 */
- (id<IRootDetectComponent>) getRootDetectComp;



/**
 *  获取模拟器检测接口
 *
 *  @return 返回模拟器检测接口，失败时nil
 */
- (id<ISimulatorDetectComponent>) getSimulatorDetectComp;



/**
 *  获取静态数据加密接口
 *
 *  @return 返回模拟器检测模块，失败时nil
 */
- (id<IStaticDataEncryptComponent>) getStaticDataEncryptComp;



/**
 *  获取数据采集接口
 *
 *  @return 返回数据采集接口，失败时返回nil
 */
- (id<IDataCollectionComponent>) getDataCollectionComp;



/**
 *  获取动态数据存储接口
 *
 *  @return 返回动态数据存储接口，失败时返回nil
 */
- (id<IDynamicDataEncryptComponent>) getDynamicDataEncryptComp;



/**
 *  获取dns校验接口
 *
 *  @return 返回dns校验接口，失败时返回nil
 */
- (id<ISecurityDNSComponent>) getSecurityDNSComp;

/**
 *  获取数据采集接口
 *
 *  @return 返回数据采集接口，失败时返回nil
 */
- (id<IUATraceComponent>) getUATraceComp;

/**
 *  获取NoCaptcha组件接口
 *
 *  @return 返回NoCaptcha校验接口，失败时返回nil
 */
- (id<INoCaptchaComponent>) getNoCaptchaComp;

/**
 *  获取NoCaptcha组件接口
 *
 *  @return 返回NoCaptcha校验接口，失败时返回nil
 */
- (id<IAtlasEncryptComponent>) getAtlasEncryptComp;


/**
 *  根据传入的component id获取对应的component对象
 *
 *  @param componentId 目标compoent的id
 *
 *  @return 返回componentId对应的component对象，失败时返回nil
 */
- (id) getComponent: (SecurityGuardComponentID) componentId;

/**
 *  根据传入的 protocol 获取接口
 *
 *  @param protocol 要获取的 interface
 *
 *  @return 返回的实现 protocol 的对象
 */
- (id) getInterface: (Protocol*) protocol;


/**
 *  获取sdk当前版本号
 *
 *  @return sdk当前版本号
 */
- (NSString*) getSDKVersion;



/**
 *  是否为外部版本的无线保镖SDK
 *
 *  @return 是否为外部版本的无线保镖SDK
 */
- (BOOL) isOpen;



@end
