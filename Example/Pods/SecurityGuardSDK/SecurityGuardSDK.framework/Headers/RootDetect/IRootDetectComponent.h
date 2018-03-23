//
// SecurityGuardSDK version 2.3.0
//


#ifndef SecurityGuardSDK_IRootDetectComponent_h
#define SecurityGuardSDK_IRootDetectComponent_h

@class SecurityGuardParamContext;

#import <Foundation/Foundation.h>

@protocol IRootDetectComponent <NSObject>

/**
 *  检测设备是否已经越狱
 *
 *  @return YES, 设备已经越狱, NO, 设备未越狱
 */
- (BOOL) isRoot;

@end


#endif