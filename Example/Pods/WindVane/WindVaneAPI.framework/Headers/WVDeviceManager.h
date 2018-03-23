/*
 * WVDeviceManager.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import <Foundation/Foundation.h>

/**
 * 设备运动发生改变的回调。
 * 设备运动的数据，具体定义可以参考 https://w3c.github.io/deviceorientation/spec-source-orientation.html#devicemotion。
 *
 * @param userAcceleration  设备在 x、y、z 轴上的加速度，单位是 m/s^2。
 * @param totalAcceleration 设备在 x、y、z 轴上带重力的加速度，单位是 m/s^2。
 * @param alpha             设备绕 z 轴旋转加速度，单位是 °/s。
 * @param beta              设备绕 x 轴旋转加速度，单位是 °/s。
 * @param gamma             设备绕 y 轴旋转加速度，单位是 °/s。
 *
 * @result 如果当前回调是否仍然有效，则返回 YES；否则返回 NO，会移除当前回调。
 */
typedef BOOL (^WVDeviceMotionCallback)(CMAcceleration userAcceleration, CMAcceleration totalAcceleration, double alpha, double beta, double gamma);

/**
 * 设备方向发生改变的回调。
 * 设备方向的数据，具体定义可以参考 https://w3c.github.io/deviceorientation/spec-source-orientation.html#deviceorientation。
 *
 * @param alpha 设备绕 z 轴旋转方向，值从 0 到 360，单位是 °。
 * @param beta  设备绕 x 轴旋转方向，值从 -180 到 180，单位是 °。
 * @param gamma 设备绕 y 轴旋转方向，值从 -90 到 90，单位是 °。
 *
 * @result 如果当前回调是否仍然有效，则返回 YES；否则返回 NO，会移除当前回调。
 */
typedef BOOL (^WVDeviceOrientationCallback)(double alpha, double beta, double gamma);

/**
 * 提供设备传感器相关的功能。
 */
@interface WVDeviceManager : NSObject

#pragma mark Motion

/**
 * 返回是否可以监听设备运动。
 */
+ (BOOL)motionAvailable;

/**
 * 添加设备运动发生改变的监听。
 * 即使可能无法正确监听设备运动，也会使用 ({0, 0, 0}, {0, 0, 0}, 0, 0, 0) 回调一次。
 *
 * @param callback 设备方向发生改变的回调。
 * @param interval 回调的时间间隔。
 */
+ (void)watchMotion:(WVDeviceMotionCallback _Nonnull)callback withInterval:(NSTimeInterval)interval;

/**
 * 移除设备运动发生改变的监听。
 *
 * @param callback 设备运动发生改变的监听。
 */
+ (void)removeMotion:(WVDeviceMotionCallback _Nonnull)callback;

#pragma mark Orientation

/**
 * 返回是否可以监听设备方向。
 */
+ (BOOL)orientationAvailable;

/**
 * 添加设备方向发生改变的监听。
 * 即使可能无法正确监听设备方向，也会使用 (0, 0, 0) 回调一次。
 *
 * @param callback 设备方向发生改变的回调。
 * @param interval 回调的时间间隔。
 */
+ (void)watchOrientation:(WVDeviceOrientationCallback _Nonnull)callback withInterval:(NSTimeInterval)interval;

/**
 * 移除设备方向发生改变的监听。
 *
 * @param callback 设备方向发生改变的监听。
 */
+ (void)removeOrientation:(WVDeviceOrientationCallback _Nonnull)callback;

@end
