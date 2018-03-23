//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 15-1-12.
//
//

#import <Foundation/Foundation.h>

@class TBAccsRequest, TBAccsDataEntity;

@interface TBAccsUtil : NSObject

+ (NSString *)utdid;

+ (NSString *)getAppVersion;

+ (NSString *)getDeviceModel;

+ (NSString *)currentDate;

+ (NSString *)getDataID;

+ (NSDictionary *)makeCallBackDictByRequest:(TBAccsRequest *)request
                                     entity:(TBAccsDataEntity *)entity;

+ (NSString *)getStringDateByDate:(NSDate *)date;

+ (NSString *)getStringDateByDate:(NSDate *)date
                          formate:(NSString *)formate;

+ (NSString *)sdkVersion;

+ (NSString *)appVersion;

+ (NSString *)getDocPath;

+ (NSString *)dataToString:(NSData *)data;

+ (NSString *)getShortDateString:(NSDate *)date;

+ (NSString *)base64EncodedStringFrom:(NSData *)data;

+ (NSData *)dataWithBase64EncodedString:(NSString *)string;

+ (void)flowAnalysisWithBizid:(NSString *)bizeid
                      upSize:(NSString *)upSize
                    downSize:(NSString *)downSize;

+ (NSString *)appStatus;

@end
