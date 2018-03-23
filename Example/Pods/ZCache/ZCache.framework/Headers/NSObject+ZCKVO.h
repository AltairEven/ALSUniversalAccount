/*
 NSObject+ZCKVO.h
 
 Created by WindVane.
 Copyright (c) 2018年 阿里巴巴-淘宝技术部. All rights reserved.
 */


#import <Foundation/Foundation.h>

/**
 KVO 的观察者。
 */
@interface ZCObserver<TargetType> : NSObject

/**
 观察的目标对象。
 */
@property (nonatomic, weak, readonly, nullable) TargetType target;

/**
 观察的 keypath。
 */
@property (nonatomic, copy, readonly, nonnull) NSString * keyPath;

@end

/**
 返回指定对象、指定属性的 KeyPath。
 */
#define zckeypath(OBJ, PATH) (((void)(NO && ((void)OBJ.PATH, NO)), # PATH))

/**
 观察者回调
 
 @pram observer 观察者信息
 @pram change 值的改变信息。
 */
typedef void(^ ZCObserverBlock)(ZCObserver * _Nonnull observer, NSDictionary<NSString *, id> * _Nonnull change);

/**
 提供 KVO 的扩展功能。
 */
@interface NSObject (ZCKVO)

/**
 为当前对象的指定 keypath 创建观察者，在当前对象销毁后自行停止。
 */
- (void)zcAddObserverForKeyPath:(NSString * _Nonnull)keyPath options:(NSKeyValueObservingOptions)options callback:(ZCObserverBlock _Nonnull)observer;

@end
