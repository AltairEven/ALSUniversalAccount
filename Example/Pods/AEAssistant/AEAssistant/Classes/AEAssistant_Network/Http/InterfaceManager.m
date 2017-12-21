//
//  InterfaceManager.m
//  KidsTC
//
//  Created by 钱烨 on 8/4/15.
//  Copyright (c) 2015 KidsTC. All rights reserved.
//

#import "InterfaceManager.h"
#import "AEHttpRequestHandler.h"

#define AppSDKVersion     @"0"
#define kAppSDKVersionKey  @"kAppSDKVersionKey"
#define kInterfaceBundleVersion @"kInterfaceBundleVersion"

static InterfaceManager *_sharedInstance = nil;

@interface InterfaceManager ()

@property (nonatomic, strong) AEHttpRequestHandler *downloadClient;

- (void)cleanInterfaceInfo;

- (NSString *)getConfigVersion;

- (void)downloadInterfaceListSusseed:(NSDictionary *)respData;

- (void)downloadInterfaceListFailed:(NSError *)error;

- (void)refresh:(NSDictionary *)data;

@end

@implementation InterfaceManager

- (instancetype)init {
    self = [super init];
    if (self) {
        if (![AEToolUtil hasFirstLaunched]) {
            //未启动过
            [self cleanInterfaceInfo];
        }
        [self refresh:nil];
    }
    return self;
}

+ (instancetype)sharedManager {
    static dispatch_once_t token;
    dispatch_once(&token, ^{
        _sharedInstance = [[InterfaceManager alloc] init];
    });
    return _sharedInstance;
}

#pragma mark Private methods

- (NSString *)getConfigVersion {
    NSString *versionLocal = [[NSUserDefaults standardUserDefaults] objectForKey:kAppSDKVersionKey];
    if (versionLocal == nil)
    {
        versionLocal = AppSDKVersion;
    }
    return versionLocal;
}

- (void)downloadInterfaceListSusseed:(NSDictionary *)respData {
    _interfaceData = respData;
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^(){
        
        BOOL res = [self.interfaceData writeToFile:FILE_CACHE_PATH(@"interface_list.plist") atomically:NO];
        if (!res)
        {
            _interfaceData = [self loadBundle];
        }
        else
        {
            NSString *newVersion = [self.interfaceData objectForKey:@"version"];
            [[NSUserDefaults standardUserDefaults] setObject:newVersion forKey:kAppSDKVersionKey];
            [[NSUserDefaults standardUserDefaults] setObject:[AEToolUtil currentAppVersion] forKey:kInterfaceBundleVersion];
            [[NSUserDefaults standardUserDefaults] synchronize];
        }
        dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(){
            [self refresh:self.interfaceData];
        });
    });
}

- (void)downloadInterfaceListFailed:(NSError *)error {
    [self refresh:nil];
}

- (NSDictionary*)loadBundle
{
    NSDictionary*dic = [NSDictionary dictionaryWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"interface_list" ofType:@"plist"]];
    return dic;
}

- (void)cleanInterfaceInfo {
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:kAppSDKVersionKey];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:kInterfaceBundleVersion];
    [[NSUserDefaults standardUserDefaults] synchronize];
}


- (void)refresh:(NSDictionary*)data
{
    @synchronized (self) {
        if(data) {
            _interfaceData = data;
            _URLMapWithAlias = [NSDictionary dictionaryWithDictionary:[data objectForKey:@"data"]];
        }
        else
        {
            NSDictionary *URLMap = [NSDictionary dictionaryWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"interface_list" ofType:@"plist"]];
            _URLMapWithAlias = [NSDictionary dictionaryWithDictionary:[URLMap objectForKey:@"data"]];
        }
    }
}


#pragma mark Public methods

- (void)updateInterface {
    if ([self.interfaceListAddress length] == 0) {
        return;
    }
    if (!self.downloadClient) {
        if (!self.downloadClient) {
            self.downloadClient = [AEHttpRequestHandler clientWithUrlString:self.interfaceListAddress];
        }
    }
    NSDictionary *param = [NSDictionary dictionaryWithObjectsAndKeys:[self getConfigVersion], @"cfgver", @"1", @"app", [AEToolUtil currentAppVersion], @"appVersion", nil];
    
    __weak InterfaceManager *weakSelf = self;
    [weakSelf.downloadClient startHttpRequestWithParameter:param success:^(AEHttpRequestHandler *handler, NSDictionary *responseData) {
        [weakSelf downloadInterfaceListSusseed:responseData];
    } failure:^(AEHttpRequestHandler *handler, NSError *error) {
        [weakSelf downloadInterfaceListFailed:error];
    }];
    
    [AEToolUtil setHasFirstLaunched:YES];
}

- (NSString *)getURLStringWithAliasName:(NSString *)aliasName {
    NSString *urlString = [[self.URLMapWithAlias objectForKey:aliasName] objectForKey:@"url"];
    if (![urlString isKindOfClass:[NSString class]] || [urlString length] == 0) {
        return nil;
    }
    if (self.configuration) {
        //有配置项的情况
        NSMutableString *apiString = [NSMutableString stringWithFormat:@"%@://%@", self.configuration.protocol, self.configuration.host];
        if (self.configuration.port) {
            [apiString appendFormat:@":%@", self.configuration.port];
        }
        [apiString appendString:urlString];
        urlString = [apiString copy];
    }
    //补充问号
    if ([urlString rangeOfString:@"?"].location == NSNotFound) {
        urlString = [NSString stringWithFormat:@"%@?", urlString];
    }
    return urlString;
}

- (NSString *)getURLSendDataMethodWithAliasName:(NSString *)aliasName {
    NSString * httpMethod = [[self.URLMapWithAlias objectForKey:aliasName] objectForKey:@"method"];
    if (!httpMethod || ![httpMethod isKindOfClass:[NSString class]] || [httpMethod length] == 0) {
        return nil;
    }
    return [httpMethod uppercaseString];
}

@end

@implementation InterfaceManagerConfiguration

@end
