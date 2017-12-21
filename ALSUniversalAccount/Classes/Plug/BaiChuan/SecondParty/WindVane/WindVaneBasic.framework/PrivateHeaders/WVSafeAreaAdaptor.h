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
 */
+ (BOOL)isIOS11;

/**
 表示是通过 Xcode9 编译的模式。
 */
+ (void)Xcode9Mode;

/**
 返回是否是 Xcode8 编译的兼容模式。
 */
+ (BOOL)isXcode8CompatibleMode;

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

/**
 一段时间内仍然会使用 Xcode8 编译 SDK，这时是无法正常使用 iOS11 的新 API 的。
 为了对 iPhoneX 做兼容，这里声明了一些 iOS11 的新 API。
 */
@interface UIView (WVSafeAreaCompatible)

@property (nonatomic,readonly) UIEdgeInsets safeAreaInsets NS_AVAILABLE_IOS(11_0);

@end

@interface UIScrollView (WVSafeAreaCompatible)

@property (nonatomic, readonly) UIEdgeInsets adjustedContentInset NS_AVAILABLE_IOS(11_0);

@end
