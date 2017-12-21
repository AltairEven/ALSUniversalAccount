//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by ZhuoLaiQiang on 15/7/23.
//
//

#import <Foundation/Foundation.h>
#import <TBAccsSDK/TBAccsManager.h>

@protocol TBAccsCallbackProtocol <NSObject>

@required

/**
 * 接收下行消息的回调
 */
+ (TBAccsManagerResponseBlock)callBack;


/**
 * 对应的 service ID
 */
+ (NSString *)serviceID;

@optional

/**
 * 使用的 ACCS 域名。可选选项，如果没有实现，则使用默认配置的 centerHost
 */
+ (NSString *)accsHost;

@end
