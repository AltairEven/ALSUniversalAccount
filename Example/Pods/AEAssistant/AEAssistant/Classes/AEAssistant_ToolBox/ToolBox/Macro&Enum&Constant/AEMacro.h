//
//  AEMacro.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#ifndef AEMacro_h
#define AEMacro_h

//obj
#define WeakObject(obj, weakObj) __weak typeof(obj) weakObj = obj;
#define StrongObject(obj, strongObj) __strong typeof(obj) strongObj = obj;

//log
#ifdef DEBUG
#define LOG(...) NSLog(__VA_ARGS__);
#define LOG_METHOD NSLog(@"%s", __func__);
#else
#define LOG(...)
#define LOG_METHOD 
#endif

//color
#define RGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define RGBA_HEX(v, a) [UIColor colorWithRed:((float)(((v) & 0xFF0000) >> 16))/255.0 green:((float)(((v) & 0xFF00) >> 8))/255.0 blue:((float)((v) & 0xFF))/255.0 alpha:(a)]

//image
#define LOADIMAGE(fileName) [UIImage imageNamed:(fileName)]
#define LOADIMAGE_NOCACHE(filePath) [UIImage imageWithContentsOfFile:filePath]

//frame
#define XPOINTOF(view) view.frame.origin.x
#define YPOINTOF(view) view.frame.origin.y
#define WIDTHOF(view) view.frame.size.width
#define HEIGHTOF(view) view.frame.size.height

#define MOVEVIEWTOX(view, x) view.frame = CGRectMake(x, YPOINTOF(view), WIDTHOF(view), HEIGHTOF(view))
#define MOVEVIEWTOY(view, y) view.frame = CGRectMake(XPOINTOF(view), y, WIDTHOF(view), HEIGHTOF(view))
#define CHANGEWIDTHOFVIEW(view, width) view.frame = CGRectMake(XPOINTOF(view), YPOINTOF(view), width, HEIGHTOF(view))
#define CHANGEHEIGHTOFVIEW(view, height) view.frame = CGRectMake(XPOINTOF(view), YPOINTOF(view), WIDTHOF(view), height)

#define BORDER_WIDTH (1.0 / [UIScreen  mainScreen].scale)
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width


//file path
#define FILE_DOCUMENT_PATH(path) [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex: 0] stringByAppendingPathComponent: (path)]
#define FILE_CACHE_PATH(path) [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex: 0] stringByAppendingPathComponent: (path)]

//screen
#define IS_3_7_INCH_SCREEN CGSizeEqualToSize(CGSizeMake(320, 480), [[UIScreen mainScreen] bounds].size)
#define IS_4_0_INCH_SCREEN CGSizeEqualToSize(CGSizeMake(320, 568), [[UIScreen mainScreen] bounds].size)
#define IS_4_7_INCH_SCREEN CGSizeEqualToSize(CGSizeMake(375, 667), [[UIScreen mainScreen] bounds].size)
#define IS_5_5_INCH_SCREEN CGSizeEqualToSize(CGSizeMake(414, 736), [[UIScreen mainScreen] bounds].size)

//launch flag
#define kAppHasLaunchedKey ([AEToolUtil currentAppVersion])

#endif /* AEMacro_h */
