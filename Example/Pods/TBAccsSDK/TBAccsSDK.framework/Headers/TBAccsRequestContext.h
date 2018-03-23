//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 15/5/18.
//
//

#import <Foundation/Foundation.h>
#import "TBAccsVariable.h"

@interface TBAccsRequestContext : NSObject

//必填 结果回调block
@property (nonatomic, copy) TBAccsManagerResponseBlock callBack;

//必填 业务方申请的id
@property (nonatomic, strong) NSString *serviceID;

//需要发送的数据
@property (nonatomic, strong) NSData *sendData;

//用户id
@property (nonatomic, strong) NSString *userID;

//路由id
@property (nonatomic, strong) NSString *routID;

//非必填  附加头里的业务方标示
@property (nonatomic, strong) NSString *serviceFlag;

//非必填 标示，业务方可以定义自己的tag
@property (nonatomic, strong) NSString *tag;

@property (nonatomic, strong) NSString *host;

@property (nonatomic, assign) AccsDataFlagType dataFlagType;

@property (nonatomic, assign) double timeout;

@property (nonatomic, assign) double retryInterval;

// 是否为单元请求 不能删除，外部有调用
@property (nonatomic, assign) BOOL isUnit;


@end
