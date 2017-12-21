//
// SecurityGuardSDK version 2.3.0
//

#ifndef SecurityGuardSDK_ISimulatorDetectComponent_h
#define SecurityGuardSDK_ISimulatorDetectComponent_h

/**
 *  模拟器检测接口
 */
@protocol ISimulatorDetectComponent <NSObject>

/**
 *  判断当前设备是否是iOS模拟器
 */
- (BOOL) isSimulator;

@end

#endif
