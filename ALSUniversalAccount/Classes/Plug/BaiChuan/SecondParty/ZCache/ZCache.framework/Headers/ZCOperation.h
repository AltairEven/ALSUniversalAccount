/*
 ZCOperation.h
 
 Created by WindVane.
 Copyright (c) 2018年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class ZCOperation;

/**
 作为操作执行的 block。
 
 @param prevOperation 上一个操作，仅在 then 方法中可用。
 @return 可以返回 ZCOperation *，也可以返回 NSError * 作为执行错误信息，其它类型会被当做返回值。
 */
typedef id _Nullable (^ZCOperationBlock)(id _Nonnull prevOperation);

/**
 表示支持逻辑和数据流的 NSOperation。
 */
@interface ZCOperation<ValueType> : NSOperation<NSProgressReporting>

/**
 当前操作的错误信息，表示操作的执行过程中是否出现了错误。
 */
@property (nonatomic, strong, nullable) NSError * error;

/**
 与当前操作相关的值。
 */
@property (atomic, strong, nullable) ValueType value;

/**
 当前操作的进度。
 */
@property (nonatomic, strong, readonly, nonnull) NSProgress * progress;

/**
 要在当前操作成功后，执行指定的 block，会在默认队列中执行。
 不允许持有 then 返回的 block。
 */
@property (nonatomic, copy, readonly, nonnull) ZCOperation * _Nonnull (^then)(ZCOperationBlock _Nonnull);

/**
 要在当前操作失败后，执行指定的 block，会在默认队列中执行。
 不允许持有 recover 返回的 block。
 */
@property (nonatomic, copy, readonly, nonnull) ZCOperation * _Nonnull (^recover)(ZCOperationBlock _Nonnull);

/**
 要在当前操作结束后，执行指定的 block。
 不允许持有 finally 返回的 block。
 
 @discussion block 的入参是当前操作，返回值会被全部丢弃，但可以返回 ZCOperation * 已实现异步操作。
 */
@property (nonatomic, copy, readonly, nonnull) ZCOperation * _Nonnull (^finally)(ZCOperationBlock _Nonnull);

/**
 为当前操作添加指定的依赖，并返回当前操作。
 不允许持有 addDependencies 返回的 block。
 */
@property (nonatomic, copy, readonly, nonnull) ZCOperation * _Nonnull (^addDependencies)(NSArray<ZCOperation *> * _Nonnull);

/**
 将当前操作在指定 NSOperationQueue 中执行，并返回当前操作。
 不允许持有 useQueue 返回的 block。
 */
@property (nonatomic, copy, readonly, nonnull) ZCOperation * _Nonnull (^useQueue)(NSOperationQueue * _Nonnull);

#pragma mark - Extend

/**
 执行当前操作，子类重写以提供自己的执行逻辑。
 */
- (void)executeOperation;

/**
 取消当前操作的执行，子类重写以提供自己的取消逻辑。
 */
- (void)cancelOperation;

/**
 检查操作的依赖，决定操作是否可以执行，允许子类重写以提供自己的检查逻辑。
 
 @return 如果允许操作执行，返回 YES；否则返回 NO。
 */
- (BOOL)checkDependencies;

/**
 当前操作已执行完毕。
 */
- (void)finished;

/**
 当前操作已执行完毕。
 
 @param error 操作执行过程中的错误。
 */
- (void)finishedWithError:(NSError * _Nullable)error;

/**
 当前操作已被取消。
 
 @param error 导致操作取消的错误。
 */
- (void)cancelWithError:(NSError * _Nullable)error;

#pragma mark - Factory

/**
 默认操作队列。
 */
+ (NSOperationQueue * _Nonnull)defaultQueue;

/**
 使用指定的结果，创建已成功完成的操作。
 */
+ (instancetype _Nonnull)resolvedOperation:(id _Nullable)value;

/**
 使用指定的错误信息，创建已被拒绝的操作。
 */
+ (instancetype _Nonnull)rejectedOperation:(NSError * _Nonnull)error;

/**
 使用指定的 Block 创建操作。
 */
+ (instancetype _Nonnull)operationWithBlock:(ZCOperationBlock _Nonnull)block;

/**
 使用指定的异步 Block 创建操作，传入当前操作，需要主动调用操作的 finishWithError: 方法。
 */
+ (instancetype _Nonnull)operationWithAsyncBlock:(void (^ _Nonnull)(ZCOperation * _Nonnull))block;

@end
