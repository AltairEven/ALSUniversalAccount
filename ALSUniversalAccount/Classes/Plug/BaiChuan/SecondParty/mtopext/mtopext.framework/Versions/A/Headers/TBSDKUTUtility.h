//  '########'########::'######:'########:'##:::'##:
//  ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//  ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//  ::: ##::::########:. ######::##:::: ##:#####::::
//  ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//  ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//  ::: ##::::########:. ######::########::##::. ##:
//  :::..::::........:::......::........::..::::..::
//
//  UTListener.h
//  TBSDK
//
//  Created by Roger.Mu on 3/19/14.
//  Copyright (c) 2014 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define UT_TYPE_PERF @"performace"
#define UT_TYPE_TOTALTCP @"totalTcp"
#define UT_TYPE_DEMOTELEVEL @"demote"
#define UT_TYPE_STD @"stdUTLog"
#define UT_TYPE_ERROR @"error"
#define UT_TYPE_MTOPUT @"mtoput"


#define NOTIFICATION_FILE_UPLOADED  @"kTBSDKFileUploaded"

// report cache
@interface UTReportDataSet : NSObject

@property (nonatomic, copy) NSNumber *spdyTotalTimes;
@property (nonatomic, copy) NSNumber *spdyTotaldates;
@property (nonatomic, copy) NSNumber *spdyTotalContentLength;
@property (nonatomic, copy) NSNumber *httpTotalTimes;
@property (nonatomic, copy) NSNumber *httpTotalDates;
@property (nonatomic, copy) NSNumber *httpTotalContentLength;

// cache properties
@property (nonatomic, assign) int cacheTotalTimes;
@property (nonatomic, assign) int cacheReadTotalDates;
@property (nonatomic, assign) int cacheReadTotalTimes;
@property (nonatomic, assign) int cacheWriteTotalDates;
@property (nonatomic, assign) int cacheWriteTotalTimes;
@property (nonatomic, assign) int cacheWriteTotalContentLength;


+ (UTReportDataSet *)shareInstance;

- (void) saveHttpTotalData:(NSInteger) totalTimes
             withTotalDate:(NSNumber *) totalDate
    withTotalContentLength:(NSNumber *) totalContentLength;
- (void) saveSPDYTotalData:(NSInteger) totalTimes
             withTotalDate:(NSNumber *) totalDate
    withTotalContentLength:(NSNumber *) totalContentLength;

// increment tcp link times
- (void) incrementTcpLinks:(NSNumber *) times;

// increment cache hit times
- (void) incrementCacheHitTimes:(NSNumber *) readDate;

// increment cache times
- (void) incrementCacheTimes;

// increment cache 
- (void) incrementCacheWrite:(NSNumber *) writeDate withCacheSize: (long) cacheSize;

- (int) getTotalTimes;
- (double) getTotalDates;
- (int) getTotalContantLength;
- (NSInteger) getTcpLinkTimes;
- (NSInteger) getTcpLinkDates;
- (void) cleanAll;
@end


// write log data set of UT framework
@interface UTDataSet : NSObject <NSCopying>

@property (nonatomic, copy) NSNumber *dnsStartTime;
@property (nonatomic, copy) NSNumber *dnsEndTime;
@property (nonatomic, copy) NSString *tcpLinkDate;
@property (nonatomic, copy) NSString *oneWayTime;
@property (nonatomic, copy) NSString *dnsTime;
@property (nonatomic, copy) NSString *utType;
@property (nonatomic, copy) NSString *tcpTotalTimes;
@property (nonatomic, copy) NSString *tcpTotalDates;
@property (nonatomic, copy) NSString *SpdyTotalTimes;

@property (nonatomic, copy) NSString *errorCode;
@property (nonatomic, copy) NSString *errorInfo;
@property (nonatomic, copy) NSString *errorMemo;

@property (nonatomic, assign) int eventid;
@property (nonatomic, copy) NSDictionary *args;
@property (nonatomic, copy) NSString *arg1;
@property (nonatomic, copy) NSString *arg2;
@property (nonatomic, copy) NSString *arg3;

@property (nonatomic, copy) NSString *expression;

// mtop properties
@property (atomic) CFAbsoluteTime mtopStartTime;
@property (atomic) CFAbsoluteTime mtopEndTime;
@property (nonatomic) CFAbsoluteTime jsonParseStartTime;
@property (nonatomic) CFAbsoluteTime jsonParseEndTime;
@property (nonatomic) CFAbsoluteTime sendWaitStart;
@property (nonatomic) CFAbsoluteTime sendWaitEnd;
@property (nonatomic, strong) NSString *mtopOneWayTime;
@property (nonatomic, strong) NSString *isSync;


-(UTDataSet *)initWithType: (NSString *)utype;

@end

// UT log base object
@interface TBSDKUTUtility : NSObject

// ----- properties -----
@property (nonatomic, strong) NSMutableArray *utCacheArray;
// ----------------------

// get UT on-off
- (BOOL) setUT;

#pragma mark init
// UT share instance
+ (TBSDKUTUtility *)shareInstance;

- (TBSDKUTUtility *)init;

#pragma mark event listener
// dns parse event by listen
- (void)onDnsParseTime: (UTDataSet *) dataSet;

// tcp create link event by listen
- (void)onTcpLinkTime: (long long) startDate withEndDate: (long long) endDate;

// request start event
- (void)onRequestStart: (NSString *) requestType;

// request cache event
- (void)onRequestCache;

// request hit cache event
- (void)onHitedRequestCache: (NSNumber *) readDate;

// request write cache event
- (void)onWriteResponseCache: (NSNumber *) writeDate withCacheSize: (long) cacheSize;

// request end event
- (void)onRequestEnd: (NSString *) requestType
   withContentLength: (int) contentLength
   withError        : (NSError *) error;

// handle error event
- (void)onError: (NSError *) error;

// on times finished event
- (void)onOneTimesFinished: (UTDataSet *) dataSet;

// write UT log
- (void)writeUTLog: (UTDataSet *)dataSet;

#pragma mark notification
// home key event listener
-(void) writeUtLogByHomeKey: (NSNotification *) notification;

// spdy demote event listener
+ (void) writeUtLogByDemoteSpdy: (NSString *) errorInfo withUrl:(NSString *) url;

@end





