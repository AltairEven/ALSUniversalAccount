//
//  DataChannel.h
//  ALINetworkSDK
//
//  Created by nanpo.yhl on 15-3-5.
//  Copyright (c) 2015年 nanpo.yhl. All rights reserved.
//

// -----------------------------------------------------------------------------
// ACCS请求发起者

#import <Foundation/Foundation.h>

@class DataChannel;


@protocol INWHostUrl <NSObject>
    @property (nonatomic, readonly) NSString *schema;
    @property (nonatomic, readonly) NSString *host;
    @property (nonatomic, strong)NSString* urlHashCode;
@end


@protocol DataChannelDataDelegate <NSObject>
@optional
- (void)recvCustomFrametype:(int16_t)type Flags:(int8_t)flags Data:(NSData*)data channel:(DataChannel*)channel;
- (void)notifyChannelSueesss:(DataChannel*)channel;
- (void)notifyChannelFail:(DataChannel *)channel;
@end


/*
 * 一个DataChannel表示一个域名下的数据通道,初始化一次以后，切勿销毁
 */
@interface DataChannel : NSObject

@property(nonatomic, strong) id<INWHostUrl> hostOrigin;


/**
 * 注意只有在第一次获取DataChannel的时候 delegate才有用，后面的get函数中delegate不会生效
 */
+ (DataChannel*)dataChannelWithHost:(NSString*)host;

+ (DataChannel*)createDataChannelWithHost:(NSString*)host WithEnableLocalDNS:(BOOL)enabled;

/*
 * 设置全局delegate 供accs callback
 */
+ (void)registerDataChannelDelegate:(id)delegate;


/**
 * 设置ACCS Version
 */
+ (void)setAccsVersion:(NSString *)version;

 
/*
 * 整个数据通道真正run起来，network尽量保证 accs下有可用的tcp链接
 * 建议每次前后台切换以后，都拉起一次
 */
- (void)start;

/*
 * 停止整个channel上面的数据发送
 */
- (void)stop;

/*
 * 是否存在可用的数据通道
 */
- (BOOL)hasValidChannel;

/*
 * 发送自定义帧
 * BOOL 返回值
 * YES 说明数据已经投递到tcpbuffer里面，不确保能发送到对端
 * NO 说明没有投递成功
 */
-(BOOL)sendCustomFrameType:(uint16_t)type withFlags:(uint8_t)flags withData:(NSData*)data sslIndex:(uint32_t)idx error:(NSError**)error;

@end
