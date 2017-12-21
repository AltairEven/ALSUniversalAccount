/*
 * WVImageService.h
 *
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// 图片的资源预览地址（@"resourceURL"）。
FOUNDATION_EXPORT NSString * _Nonnull const WVImageResourceURLKey;

/**
 * 提供图片相关服务。
 */
@interface WVImageService : NSObject

/**
 * 根据指定的选项压缩图片为 JPEG 格式。
 *
 * @param image  要压缩的图片。
 * @param params 压缩的选项。
 *
 * @return 压缩后的图片数据。
 */
+ (NSData * _Nullable)compressImage:(UIImage * _Nonnull)image withParams:(NSDictionary * _Nullable)params;

/**
 * 将指定图像保存到相册。
 *
 * @param image    需要保存的图像。
 * @param callback 图像保存完毕的回调。
 */
+ (void)saveImageToAlbum:(UIImage * _Nonnull)image withCallback:(void (^_Nullable)(NSError * _Nullable))callback;

@end
