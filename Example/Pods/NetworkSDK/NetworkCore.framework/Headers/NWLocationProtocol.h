//
//  NWLocationProtocol.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 2017/8/2.
//  Copyright © 2017年 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol NWLocationProtocol <NSObject>

@required

@property (nonatomic, strong) NSString *latitude;

@property (nonatomic, strong) NSString *longtitude;

@property (nonatomic, strong) NSString *accuracy;

@end


@protocol NWLocationQueryProtocol <NSObject>

@required

- (id<NWLocationProtocol>)currentLocation;

@end
