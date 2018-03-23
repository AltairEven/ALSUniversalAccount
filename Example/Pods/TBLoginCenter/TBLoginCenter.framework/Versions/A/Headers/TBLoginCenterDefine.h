//
//  TBLoginCenterDefine.h
//  TBLogin
//
//  Created by 寻弦 on 15/1/4.
//
//

typedef void(^LoginTokenCallerFailBlock)(void);
typedef void(^LoginTokenFailBlock)(NSError *err,NSInteger sessionExpiredCode,LoginTokenCallerFailBlock callerFailBlock);

typedef enum {
    TBLoginTypeManualLogin,
    TBLoginTypeAutoLogin,
    TBLoginTypeTaobaoSSOLogin,
    TBLoginTypeAlipaySSOLogin
} TBLoginType;

