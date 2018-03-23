//
//  OrangLog.h
//  orange
//
//  Created by jiangpan on 2018/1/11.
//  Copyright © 2018年 ZhuoLaiQiang. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
extern "C" {
#endif

extern NSString* orangeAddPercentStr(NSString * rawStr);
// 开启OrangeLog日志(默认不开启)
extern void openOrangeLog(int level);
    
#ifdef __cplusplus
}
#endif

typedef NS_ENUM(NSUInteger,OrangeLogLevel){
    OrangeLogLevel_ERROR = 0,
    OrangeLogLevel_WARNING,
    OrangeLogLevel_INFO,
    OrangeLogLevel_DEBUG,
    OrangeLogLevel_ALL
};


#define ORANGE_TLOG_MODEL_NAME @"ORANGE"

#define ORANGE_ERRORLOG(...)\
[[OrangLogDefaultImp shareInstance] log:OrangeLogLevel_ERROR file:__FILE__ func:__func__ line:__LINE__ module:ORANGE_TLOG_MODEL_NAME msg:__VA_ARGS__]

#define ORANGE_DEBUGLOG(...)\
[[OrangLogDefaultImp shareInstance] log:OrangeLogLevel_DEBUG file:__FILE__ func:__func__ line:__LINE__ module:ORANGE_TLOG_MODEL_NAME msg:__VA_ARGS__]

#define ORANGE_INFOLOG(...)\
[[OrangLogDefaultImp shareInstance] log:OrangeLogLevel_INFO file:__FILE__ func:__func__ line:__LINE__ module:ORANGE_TLOG_MODEL_NAME msg:__VA_ARGS__]


@protocol OrangeLogProtocol <NSObject>
- (void)log:(NSInteger)level fullMsg:(NSString *)msg;
@end

@interface OrangeLog : NSObject

+ (instancetype) shareInstance;

+ (void)log:(NSUInteger)level msg:(NSString *)msg;

@end


@interface OrangLogDefaultImp:NSObject <OrangeLogProtocol>

+ (instancetype)shareInstance;

- (void)log:(NSInteger)level file:(const char *)file func:(const char *)func line:(int)line module:(NSString *)module msg:(NSString *)fmt,...;

@end
