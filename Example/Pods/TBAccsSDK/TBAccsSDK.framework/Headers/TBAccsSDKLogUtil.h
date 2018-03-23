//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 13-3-25.
//  Copyright (c) 2013年 亿刀. All rights reserved.
//


#import "TBAccsVariable.h"
#ifdef __cplusplus
extern "C" {
#endif
    
#import <Foundation/Foundation.h>
    
    void tbAccsSDKSwitchLog(BOOL logCtr);
    
    void tbAccsSDKNSLog(NSString *formate, ...);
    
    void tbAccsSDKNSLogError(NSString *formate, ...);
    
#define AccsLog(formate, args...) tbAccsSDKNSLogError(@"[M:ACCS:%d]|" formate, k_AccsSDK_Version, ##args)

    
#define AccsLogError(formate, args...) tbAccsSDKNSLogError(@"[M:ACCS:%d]|" formate, k_AccsSDK_Version, ##args)
    

    
#ifdef __cplusplus
}
#endif



