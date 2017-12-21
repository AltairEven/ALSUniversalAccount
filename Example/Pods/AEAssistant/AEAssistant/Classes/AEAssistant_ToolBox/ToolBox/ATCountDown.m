//
//  ATCountDown.m
//  ICSON
//
//  Created by 钱烨 on 3/30/15.
//  Copyright (c) 2015 肖晓春. All rights reserved.
//

#import "ATCountDown.h"

typedef void (^ currentLeftTimeBlock) (NSTimeInterval);
typedef void (^ completionBlock) ();

@interface ATCountDown ()

@property (nonatomic, strong) dispatch_source_t countdownTimer;

@property (nonatomic, strong) currentLeftTimeBlock currentBlock;

@property (nonatomic, strong) completionBlock completionBlock;

- (void)startCountDownTimer;

@end


@implementation ATCountDown
@synthesize leftTime = _leftTime;

- (instancetype)initWithLeftTimeInterval:(NSTimeInterval)timeLeft {
    self = [super init];
    if (self) {
        _leftTime = timeLeft;
    }
    return self;
}


- (void)setLeftTime:(NSTimeInterval)leftTime {
    [self stopCountDown];
    _leftTime = leftTime;
}


- (void)startCountDownWithCurrentTimeLeft:(void (^)(NSTimeInterval))currentBlock {
    self.currentBlock = currentBlock;
    [self stopCountDown];
    [self startCountDownTimer];
}

- (void)startCountDownWithCurrentTimeLeft:(void (^)(NSTimeInterval))currentBlock completion:(void (^)())completion {
    self.currentBlock = currentBlock;
    self.completionBlock = completion;
    [self stopCountDown];
    [self startCountDownTimer];
}



- (void)stopCountDown {
    if (self.countdownTimer) {
        if (!dispatch_source_testcancel(self.countdownTimer)) {
            //尚未取消，先关闭定时器
            dispatch_source_cancel(self.countdownTimer);
        }
        self.countdownTimer = nil;
    }
}


- (void)startCountDownTimer {
    __block NSTimeInterval time = self.leftTime;
    
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    self.countdownTimer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue);
    
    dispatch_source_set_timer(self.countdownTimer, DISPATCH_TIME_NOW, 1 * NSEC_PER_SEC, 0 * NSEC_PER_SEC);
    
    __weak ATCountDown *weakSelf = self;
    dispatch_source_set_event_handler(self.countdownTimer, ^{
        time --;
        if (time <= 0) {
            [weakSelf stopCountDown];
            if (weakSelf.completionBlock) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    weakSelf.completionBlock();
                    weakSelf.completionBlock = nil;
                });
                weakSelf.currentBlock = nil;
            }
        }
        _leftTime = time;
        if (weakSelf.currentBlock) {
            dispatch_async(dispatch_get_main_queue(), ^{
                weakSelf.currentBlock(time);
            });
        }
    });
    dispatch_resume(self.countdownTimer);
}


@end
