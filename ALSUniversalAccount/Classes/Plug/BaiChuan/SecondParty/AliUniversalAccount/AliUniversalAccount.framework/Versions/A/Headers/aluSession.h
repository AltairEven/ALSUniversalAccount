//
//  aluSession.h
//  AliUniversalAccount
//
//  Created by Bangzhe Liu on 16/3/21.
//  Copyright © 2016年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol aluSession <NSObject>

-(NSString *)sessionId;
-(NSString *)userId;

@end
