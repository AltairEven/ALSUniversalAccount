//
//  NWURLConnectionOperation.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 5/11/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AFOperationState) {
    AFOperationPausedState      = -1,
    AFOperationReadyState       = 1,
    AFOperationExecutingState   = 2,
    AFOperationFinishedState    = 3,
};

typedef NSURLRequest *(^NWURLConnectionOperationRedirectResponseBlock)(NSURLConnection *connection, NSURLRequest *request, NSURLResponse *redirectResponse);

@interface NWURLConnectionOperation : NSOperation <NSURLConnectionDelegate, NSURLConnectionDataDelegate, NSCopying>

// properties
@property (readonly, nonatomic, strong) NSURLRequest *request;
@property (readonly, nonatomic, strong) NSURLResponse *response;
@property (readonly, nonatomic, strong) NSData *responseData;
@property (nonatomic, copy) NSString *responseString;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign) NSStringEncoding responseStringEncoding;
@property (readwrite, nonatomic, assign) long long totalBytesRead;
@property (nonatomic, strong) NSURLConnection *connection;
@property (nonatomic, strong) NSRecursiveLock *lock;
@property (nonatomic, strong) NSOutputStream *outputStream;

@property (nonatomic, strong) NSSet *runLoopModes;
@property (nonatomic, assign) AFOperationState state;

// block methods poperty
@property (readwrite, nonatomic, copy) NWURLConnectionOperationRedirectResponseBlock redirectResponse;

// upload and download process
@property (readwrite, nonatomic, copy) void (^uploadProgress)(NSUInteger bytes, long long totalBytes, long long totalBytesExpected);
@property (readwrite, nonatomic, copy) void (^downloadProgress)(NSUInteger bytes, long long totalBytes, long long totalBytesExpected);

// methods
-(instancetype) initWithRequest: (NSURLRequest *) urlRequest;

// block methods
- (void)setUploadProgressBlock:(void (^)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite))block;
- (void)setDownloadProgressBlock:(void (^)(NSUInteger bytesRead, long long totalBytesRead, long long totalBytesExpectedToRead))block;
- (void)setRedirectResponseBlock:(NSURLRequest * (^)(NSURLConnection *connection, NSURLRequest *request, NSURLResponse *redirectResponse))block;

//由于NSURLProtocol有限制,didReceiveResponse方法在内部第二次重试的时候不会收到，因此这里手动通知
- (void)connection:(NSURLConnection __unused *)connection didReceiveResponseWhenEncounterError:(NSURLResponse *)response;

@end

@interface NWRequestDelegate : NSObject

@property (nonatomic, weak) NWURLConnectionOperation *weakConnection;

@end
