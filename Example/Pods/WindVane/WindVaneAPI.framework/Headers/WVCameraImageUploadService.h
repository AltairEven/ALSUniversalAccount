/*
 * WVCameraImageUploadService.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBasic/WVURLCache.h>
#import <WindVaneBridge/WVJSBridgeInterfaceProtocol.h>

// 出参
#define WV_TAKE_PHOTO_RESULT_LOCAL_PATH WVCacheLocalPathKey /*本地文件的路径*/
#define WV_TAKE_PHOTO_RESULT_RESOURCE_URL @"resourceURL"    /*资源预览地址*/
#define WV_TAKE_PHOTO_RESULT_TFS_KEY @"tfsKey"              /* TFS 地址 */

/**
 * 重写图片上传部分的协议，外部可直接注册入 WindVane。
 */
@protocol WVCameraImageUploadProtocol <NSObject>

@required

/**
 * 上传文件协议方法。
 *
 * @param path      上传文件的本地文件路径。
 * @param param     JSBridge 的请求参数。
 * @param callback  回调方法，请使用该方法来完成对 JS 的通知。
 * @param resultDic 结果字典，其中已经包含了部分 WindVane 的处理结果。
 * @param webview   调用摄像头 JSBridge 的 WebView 对象，如果你要在自己的类里面持有，请用弱引用。
 */
- (void)uploadImageToCDN:(NSString *)path withParam:(NSDictionary *)param withCallback:(WVJSBResponse)callback withResultDic:(NSMutableDictionary *)resultDic withWebView:(UIView<WVWebViewBasicProtocol> *)webview;

@end

@interface WVCameraImageUploadService : NSObject

/**
 * 注册图像上传的处理器。
 */
+ (void)registerImageUploadHandler:(id<WVCameraImageUploadProtocol>)imageUploadHandler;

/**
 * 获取已注册的图像上传处理器。
 */
+ (id<WVCameraImageUploadProtocol>)registeredImageUploadHandler;

@end
