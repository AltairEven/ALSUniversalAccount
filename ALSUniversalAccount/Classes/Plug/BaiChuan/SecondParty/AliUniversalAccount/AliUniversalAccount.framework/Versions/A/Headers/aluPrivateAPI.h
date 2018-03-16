//
//  aluPrivateAPI.h
//  AliUniversalAccount
//
//  Created by ethan on 12/23/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "aluDeviceUser.h"
#import "aluSession.h"
#import "aluBaseInfo.h"
#import <UIKit/UIKit.h>
typedef enum
{
  BT_TAOBAO=0,
  BT_ALIPAY=1
} BUTTON_TYPE;

typedef void(^aluSSOLoginCallBack)(id result, NSError *err, NSDictionary *reserved, BOOL needWriteSession);
typedef void (^refreshAlipayCookie)(BOOL isSuc ,NSArray* ckArray);

/**
 *  一切业务方不要使用aluPrivateAPI中的API
 */
@interface aluPrivateAPI : NSObject

+ (instancetype)sharedInstance;
#pragma mark - 生成签名. 以默认的用户加签
/**
 *  1. 用设备令牌生成签名
 *
 *  2. 如果是参与签名的key=value之value为nil, 请设置为@"". 
 *
 *  3. 注意: 参与签名的用户是最近登录的用户, 如果返回nil或者@"", 表示签名失败
 *
 *  @param dic 参与签名的因子
 *
 *  @return 签名
 */
- (NSString*)generateSignWithContent:(NSString*)content;

/**
 *  生成签名
 */
- (NSString *)generateSignWithContentDic:(NSDictionary<NSString*, NSString*>*)dic;

/**
 *  获取当前用户的tokenKey
 */
- (NSString *)getCurrentUserTokenKey;

/**
 *  保存兼容性账户
 */
-(void)saveCompatibleUser:(aluDeviceUser*)user;

#pragma mark - 加签, 传入tokenKey

#pragma mark - 存贮计数器
-(void)writeClock:(NSNumber*)clock;
-(NSNumber*)readClock;

-(void)markSsoPageAsLoginRefer;
-(void)clearSsoPageAsLoginRefer;

-(void)loginBySsoTokenUrl:(NSURL*)url callback:(aluSSOLoginCallBack)aluSSOCallback;

#pragma mark - session代理设置
-(void)setProxySession:(id<aluSession>) session;

#pragma mark - 多语言相关接口
-(NSString *)getMultiLanguageString:(NSString *)str;

- (void)aluCultivateAlipayCookies : (refreshAlipayCookie)callback;

#pragma mark - 打点相关
-(NSString *)getLoginMoinitorValueByKey:(NSString *)key;
-(NSString *)getOtherMoinitorValueByKey:(NSString *)key;
-(NSString *)getSSOMoinitorValueByKey:(NSString *)key;

#pragma mark - 日志相关
-(void)debug:(NSString*)format,...;

//临时返回处理支付宝返回逻辑的实例
- (id)getAlipayHandler;

- (void)setSecrityKey:(NSString *)secrityKey;

/**
 *除了千牛之外, 其他App不要调用该方法.
 */
- (void)autoLogin: (NSString*) autoLoginToken
           userId: (NSString*) userId
         reserved: (NSDictionary*) reserved
        onSuccess: (void (^)(NSString *responseString, id responseJson)) success
          onError: (void (^)(id error)) error;

- (void)unifytokenLogin:(NSString *)token
               callback:(void (^)(NSString *responseString)) callback;


- (void)showMBProgressHUD;

- (void)hideMBProgressHUD;

- (void)assembleInfo:(aluBaseInfo *)baseInfo;

- (UIButton *)taobaoLoginButtonWithFrame:(CGRect)frame
                                   title:(NSString *)title
                                  target:(id)target
                                  action:(SEL)action;

- (UIButton *)taobaoRegButtonWithFrame:(CGRect)frame
                                 title:(NSString *)title
                                target:(id)target
                                action:(SEL)action;

- (void)setButtonStyle:(UIButton*)button
                  type:(BUTTON_TYPE)type;

- (UIImage*) bgImageFromColors:(NSArray*)colors
                     withFrame: (CGRect)frame;

- (UIImage *)imageByApplyingAlpha:(CGFloat)alpha
                            image:(UIImage*)image;

- (UIColor *)colorWithRGB:(int)rgbValue
                    alpha:(CGFloat)alpha;

- (UIImage *)imageWithColor:(UIColor *)color;
@end
