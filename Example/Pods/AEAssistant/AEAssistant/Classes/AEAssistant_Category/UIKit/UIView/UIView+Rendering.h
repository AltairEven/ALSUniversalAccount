//
//  UIView+Rendering.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Rendering)
/**
 *  在view上画线
 *
 *  @param view      被画的view
 *  @param start     起始点
 *  @param end       结束点
 *  @param width     宽度
 *  @param gap       虚线的间隔
 *  @param length    长度
 *  @param color     颜色
 *  @param isVirtual 是否虚线
 */
- (void)drawLineWithStartPoint:(CGPoint)start endPoint:(CGPoint)end lineWidth:(CGFloat)width gap:(CGFloat)gap sectionLength:(CGFloat)length color:(UIColor *)color isVirtual:(BOOL)isVirtual;
/**
 *  为view渲染渐变色背景
 *
 *  @param view      被渲染的view
 *  @param frame     显示的区域
 *  @param start     渐变起始点
 *  @param end       渐变结束点
 *  @param colors    颜色
 *  @param locations 渐变关键点
 */
- (void)renderGradientWithDisplayFrame:(CGRect)frame startPoint:(CGPoint)start endPoint:(CGPoint)end colors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations;

@end
