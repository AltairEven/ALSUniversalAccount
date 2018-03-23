/*
 * UIScrollView+WVInfiniteScrolling.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <UIKit/UIKit.h>

// 上拉加载的状态。
typedef NS_ENUM (NSUInteger, WVInfiniteScrollingState) {
	WVInfiniteScrollingStateStopped,
	WVInfiniteScrollingStateTriggered,
	WVInfiniteScrollingStateLoading,
	WVInfiniteScrollingStateAll = 10,
};

#pragma mark- WVInfiniteScrollingView

/**
 * WindVane 的上拉加载视图。
 */
@interface WVInfiniteScrollingView : UIView

/**
 * 活动指示器样式。
 */
@property (nonatomic, assign) UIActivityIndicatorViewStyle activityIndicatorViewStyle;

/**
 * 上拉加载视图状态。
 */
@property (nonatomic, assign) WVInfiniteScrollingState state;

/**
 * 设置自定义视图。
 */
- (void)setCustomView:(UIView *)view forState:(WVInfiniteScrollingState)state;

/**
 * 开始动画。
 */
- (void)startAnimating;

/**
 * 停止动画。
 */
- (void)stopAnimating;

@end

#pragma mark- UIScrollView (WVInfiniteScrolling)

/**
 * WindVane 的上拉加载支持。
 */
@interface UIScrollView (WVInfiniteScrolling)

/**
 * 是否显示上拉加载。
 */
@property (nonatomic, assign) BOOL wvShowsInfiniteScrolling;

/**
 * 上拉加载视图。
 */
@property (nonatomic, strong, readonly) WVInfiniteScrollingView * wvInfiniteScrollingView;

/**
 * 添加上拉加载。
 *
 * @param actionHandler 上拉加载的行为。
 */
- (void)wvAddInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;

/**
 * 触发上拉加载。
 */
- (void)wvTriggerInfiniteScrolling;

@end
