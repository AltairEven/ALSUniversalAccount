//
//  WVLongPressImageRecognizer.h
//  Basic
//
//  Created by lianyu.ysj on 16/5/9.
//  Copyright © 2016年 WindVane. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * 长按图片的识别器。
 */
@interface WVLongPressImageRecognizer<ViewType: UIView *> : NSObject

/**
 * 绑定到的视图。
 */
@property (nonatomic, weak, readonly) ViewType view;

/**
 * 绑定指定视图。
 *
 * @param view 要绑定的视图。
 */
- (void)bind:(ViewType)view;

/**
 * 解绑视图。
 */
- (void)unbind;

/**
 * 提取图片。
 * 供子类重写使用。
 *
 * @param locationInView 长按的视图位置。
 * @param callback       图片提取成功的回调。
 */
- (void)fetchImage:(CGPoint)locationInView callback:(void (^)(void))callback;

/**
 * 保存图片。
 * 供子类重写使用。
 */
- (void)saveImage;

/**
 * 完成保存图片到相册。
 * 供子类重写使用。
 *
 * @param error 保存的失败信息。
 */
- (void)saveImageFinished:(NSError *)error;

/**
 * 保存图片到相册。
 *
 * @param image 要保存的图片。
 */
- (void)saveImageToAlbum:(UIImage *)image;

@end
