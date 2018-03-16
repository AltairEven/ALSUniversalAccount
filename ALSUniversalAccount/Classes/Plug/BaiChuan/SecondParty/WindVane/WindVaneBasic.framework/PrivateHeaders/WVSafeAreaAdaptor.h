//
//  WVSafeAreaAdaptor.h
//  Basic
//
//  Created by lianyu.ysj on 2017/10/2.
//  Copyright © 2017年 WindVane. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 包含对安全域区域的适配逻辑。
 */
@interface WVSafeAreaAdaptor : NSObject

/**
 判断是否是 iOS 11。
 貌似有越狱机系统是 iOS11，但调用任何 iOS11 方法都会 Crash，只能再主动检测一下。
 */
+ (BOOL)isIOS11;

/**
 返回指定 UI 方向下的设备 SafeArea 间距。
 
 @param orientation UI 方向。
 @return 设备 SafeArea 间距，忽略 TabBar 等 UI 元素。
 */
+ (UIEdgeInsets)safeAreaInsets:(UIInterfaceOrientation)orientation;

/**
 返回指定 UIScrollView 的 adjustedContentInset。
 */
+ (UIEdgeInsets)adjustedContentInset:(UIScrollView *)scrollView;

@end

