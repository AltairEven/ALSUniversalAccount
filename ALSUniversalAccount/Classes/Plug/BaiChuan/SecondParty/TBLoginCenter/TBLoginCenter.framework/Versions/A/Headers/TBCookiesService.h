//
//  TBCookiesService.h
//  TBLogin
//
//  Created by 寻弦 on 14-6-12.
//  Modified by 御道<madding.lip@alibaba-inc.com> on 2016-07-25
//
//
#import <Foundation/Foundation.h>

@interface TBCookiesService : NSObject

+ (instancetype)sharedInstance;


/**
 * Function：
 * 尝试刷新cookie，方法内会有疲劳度控制，
 * 刷新cookie失败，会尝试autologin，
 * autologin失败后弹不弹登录页面根据needLoginView的值。
 *
 * 刷新完了后，会回调completionHandler，传入的参数hasRefreshed为YES代表刷新cookie成功，hasRefreshed为NO代表未刷新或者刷新失败，
 * cancelationHandler在拉起登录页面后，用户手动取消登录页面时会调用
 */

/**
 *  TODO: 规范化注释内容 --madding.lip
 *  刷新CookieStorage和Ｍtop请求中的Cookie信息：
 *    - 1.调用mtop刷新cookie接口，成功：回调，失败：走2
 *    - 2.调用mtop自动登陆接口，成功：回调completionHander，失败：走3
 *    - 3.拉起用户登陆界面，用户点击取消，回调cancelationHandler，否则最终回调completionHander
 *
 *  @param needTimeCheck      是否需要按规则刷新cookie：若不需要按规则更新，直接更新cookie
 *  @param needLoginView      在刷新cookie失败后，走自动登录失败时，是否需要开启登陆界面
 *  @param completionHander   获取cookie或者自动登陆成功后回调函数
 *  @param cancelationHandler 在刷新cookie和自动登陆失败后，在弹出登陆界面时，用户取消登陆接口时回调函数
 */
- (void)getCookiesWithNeedTimeCheck:(BOOL)needTimeCheck
                      needLoginView:(BOOL)needLoginView
                  completionHandler:(void (^)(BOOL hasRefreshed))completionHander
                  cancelationHander:(void (^)())cancelationHandler;

@end