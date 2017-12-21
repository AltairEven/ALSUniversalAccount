//
//  TBPostLoginHandler.h
//  TBLogin
//
//  Created by 寻弦 on 14/11/21.
//
//

#import <Foundation/Foundation.h>
#import <mtopext/LoginProtocol.h>
#import "TBLoginCenterDefine.h"

#define SESSION_KEY_UMIDTOKEN4TAOBAO         @"SESSION_KEY_UMIDTOKEN4TAOBAO"
#define SESSION_KEY_HAVANA_TOKEN             @"havanaSsoToken"
#define SESSION_KEY_HAVANA_TOKEN_EXPIREDTIME @"havanaSsoTokenExpiredTime"


@protocol TBSessionManagerDelegate <NSObject>

@optional
/**
 *  接入方在此方法中可以存储额外的Session相关字段
 *  @param session      即将写入文件的Session字典
 *  @param loginResult  登录网关完整的返回结果
 */
- (void)sessionManagerDidStoreSession:(NSMutableDictionary *)session withLoginResult:(NSDictionary *)loginResult;

/**
 *  接入方可在此方法中额外删除自己在session:didStoreWithLoginResult:中插入的Session相关字段
 *  @param session  即将写入文件的Session字段
 */
- (void)sessionManagerDidClearSession:(NSMutableDictionary *)session;
@end


@interface TBSessionManager : NSObject

@property (nonatomic,weak)id<TBSessionManagerDelegate> delegate;

+ (instancetype)sharedManager;
- (NSDictionary *)currentSession;

/**
 *  登陆成功session信息存储接口
 *   - 将session信息缓存到currentSession
 *   - 将session信息存储持久化到[黑匣子|Documents|UserDefaults]
 *
 *  @param loginResult [自动登陆|手工登陆]返回的json数据，
 *  @param loginType   登陆方式
 */
- (void)storeSessionWithLoginResult:(NSDictionary *)loginResult loginType:(TBLoginType)loginType;
/**
 *  删除session信息
 *    - 删除内存session：currentSession
 *    - 删除持久化session：[黑匣子|Documents|UserDefaults]
 */
- (void)clearSession;
/**
 *  更新session中的cookie信息，并持久化
 *
 *  @param cookies 更新的全部cookie信息，格式为jsonArray[NSHTTPCookie1,NSHTTPCookie2]
 */
- (void)setCookies:(id)cookies;

/**
 *  失效session信息并持久化
 */
- (void)makeSessionInvalidLocally;


@end

