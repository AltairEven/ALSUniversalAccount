/*
 * WVDynamicHandler.h
 *
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneBridge/WVBridgeProtocol.h>

/**
 * WVBridge 提供了 WebView/Weex/Native 通用的 Bridge 协议。
 * 具体的教程可以参考 WindVane 的版本正式文档 http://h5.alibaba-inc.com/windvane/JSBridge.html，此处作为快捷上手帮助。
 *
 * 提供动态 WVBridge（对类名有要求，但无需注册，会自动反射查找）：
 * [STEP 1] 令你要输出为服务的类集成 WVDynamicHandler（引入头文件 <WindVaneBridge/WindVaneBridge.h>）。
 * [STEP 2] [可选]根据需要重写 instanceScope 方法，设置实例的作用域，具体的定义参见 WVBridgeScope 枚举。
 * [STEP 3] 你要输出的方法的命名需要遵循规范：
 *            -/+ (void)handlerName:(NSDictionary *)params withWVBridgeContext:(id<WVBridgeCallbackContext>)context
 *            其中 handlerName 即为你提供给 WVBridge 调用方的方法名称。
 *          · 第一个参数为 NSDictionary *，是 WVBridge 调用方传入的参数对象。
 *          · 第二个参数为 id<WVBridgeCallbackContext>，是 WVBridge 的调用上下文。
 * [STEP 4] 在你的方法中，使用 [context callbackSuccess:RESULT]/[context callbackFailure:RET withResult:RESULT]
 *          来输出执行成功/失败的结果返回给 WVBridge 调用方。
 * [STEP 5] 当你的 WVBridge API 逻辑执行完毕，可以主动调用 [context releaseHandler:self] 方法来主动释放内存，否则就只能等到页面销毁的时候才会释放。
 *          注意在 dealloc 中调用 [context releaseHandler:self] 是没有意义的，因此此时对象已经被释放了。
 *
 * 提供普通 WVBridge（需要注册才能够使用）：
 * · 使用 WVRegisterBridge 宏注册全局 WVBridge 处理器；
 * · 使用 WVRegisterBridgeAlias 宏注册全局 WVBridge 别名；
 * · 使用 WVRegisterBridgeClass 宏注册全局 WVBridge 类；
 *
 * [注意] 1. WVBridge 总是在主线程调用，如果有耗时操作，请务必自行切换线程。
 *       2. 可能你提供的服务带有多个阶段输出性，请使用 [context dispatchEvent:eventName withParam:param] 将结果通过事件的方式输出给 WVBridge 调用方。
 */

/**
 * 动态 WVBridge 的基类。
 */
@interface WVDynamicHandler : NSObject <WVBridgeProtocol>

/**
 * WVBridge 的上下文。
 */
@property (nonatomic, weak) id<WVBridgeContext> context;

/**
 * 当前 WVBridge API 绑定到的 UIViewController。
 */
@property (nonatomic, weak, readonly) UIViewController * viewController;

/**
 * 当前 WVBridge API 绑定到的 WebView。
 */
@property (nonatomic, weak, readonly) UIView<WVWebViewBasicProtocol> * webview;

/**
 * 主动释放当前实例。
 */
- (void)releaseInstance;

@end

/*
 * [设计想法] 为什么不直接设计成反射调用任意代码，并且OC不需要遵循任何规则?
 *
 *  其实对于前端页面和客户端具体编码的实现者而言比较好的设计方式是按照常规的习惯来编写OC代码，然后容器可以自动的通过
 *  反射的方式来调用任何的部分，当方法采用直接return的方式，那么则为同步输出，如果是异步的方式，则为异步输出。
 *  在技术上没有问题，但是在安全上缺存在着很大的漏洞隐患。一旦外部代码安全AOP拦截器逻辑出现bug，那么很可能系统的任何
 *  的类和方法，都能够被前端JS直接调用，尤其是下单和session相关数据的获取接口。
 *  所以，综合以上多种因素考虑，目前还是需要客户端OC实现者在编写输出方法的时候来遵循一定的规则和主动的调用一些方法。
 */
