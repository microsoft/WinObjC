//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSURLAuthenticationChallenge.h>

@class NSString;
@class NSArray;
@class NSData;
@class NSError;
@class NSOperationQueue;
@class NSInputStream;

@class NSURL;
@class NSURLCredential;
@class NSURLRequest;
@class NSURLResponse;
@class NSHTTPURLResponse;
@class NSCachedURLResponse;
@class NSURLSessionConfiguration;

@class NSURLSessionTask;
@class NSURLSessionDataTask;
@class NSURLSessionDownloadTask;
@class NSURLSessionUploadTask;

@protocol NSURLSessionDelegate;

typedef NS_ENUM(NSInteger, NSURLSessionTaskState) {
    NSURLSessionTaskStateRunning = 0,
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,
    NSURLSessionTaskStateCompleted = 3,
};

FOUNDATION_EXPORT const float NSURLSessionTaskPriorityDefault;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityLow;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityHigh;

FOUNDATION_EXPORT NSString* const NSURLSessionDownloadTaskResumeData;
FOUNDATION_EXPORT NSString* const NSURLErrorBackgroundTaskCancelledReasonKey;

typedef void (^NSURLSessionTaskCompletionHandler)(NSData* data, NSURLResponse* response, NSError* error);
typedef void (^NSURLSessionDownloadTaskCompletionHandler)(NSURL* location, NSURLResponse* response, NSError* error);

typedef NS_ENUM(NSUInteger, NSURLErrorBackgroundTaskCancelledReason) {
    NSURLErrorCancelledReasonUserForceQuitApplication = 0,
    NSURLErrorCancelledReasonBackgroundUpdatesDisabled = 1,
};

typedef NS_ENUM(NSInteger, NSURLSessionResponseDisposition) {
    NSURLSessionResponseCancel = 0,
    NSURLSessionResponseAllow = 1,
    NSURLSessionResponseBecomeDownload = 2
};

FOUNDATION_EXPORT const int64_t NSURLSessionTransferSizeUnknown;

FOUNDATION_EXPORT_CLASS
@interface NSURLSession : NSObject
+ (NSURLSession*)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration;
+ (NSURLSession*)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration
                                 delegate:(id<NSURLSessionDelegate>)delegate
                            delegateQueue:(NSOperationQueue*)queue;
+ (NSURLSession*)sharedSession;
@property (readonly, copy) NSURLSessionConfiguration* configuration;
@property (readonly, retain) id<NSURLSessionDelegate> delegate;
@property (readonly, retain) NSOperationQueue* delegateQueue;
@property (copy) NSString* sessionDescription;
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url;
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url completionHandler:(void (^)(NSData*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request
                           completionHandler:(void (^)(NSData*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url;
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url
                               completionHandler:(void (^)(NSURL*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request
                                   completionHandler:(void (^)(NSURL*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData;
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData
                                      completionHandler:(void (^)(NSURL*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromData:(NSData*)bodyData;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request
                                        fromData:(NSData*)bodyData
                               completionHandler:(void (^)(NSData*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromFile:(NSURL*)fileURL;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request
                                        fromFile:(NSURL*)fileURL
                               completionHandler:(void (^)(NSData*, NSURLResponse*, NSError*))completionHandler;
- (NSURLSessionUploadTask*)uploadTaskWithStreamedRequest:(NSURLRequest*)request;
- (void)finishTasksAndInvalidate;
- (void)flushWithCompletionHandler:(void (^)(void))completionHandler;
- (void)getTasksWithCompletionHandler:(void (^)(NSArray*, NSArray*, NSArray*))completionHandler;
- (void)invalidateAndCancel;
- (void)resetWithCompletionHandler:(void (^)(void))completionHandler;
@end

/* Tasks */
FOUNDATION_EXPORT_CLASS
@interface NSURLSessionTask : NSObject <NSCopying>
- (void)cancel;
- (void)resume;
- (void)suspend;
@property (readonly) NSURLSessionTaskState state;
@property float priority;
@property (readonly) int64_t countOfBytesExpectedToReceive;
@property (readonly) int64_t countOfBytesReceived;
@property (readonly) int64_t countOfBytesExpectedToSend;
@property (readonly) int64_t countOfBytesSent;
@property (readonly, copy) NSURLRequest* currentRequest;
@property (readonly, copy) NSURLRequest* originalRequest;
@property (readonly, copy) NSURLResponse* response;
@property (copy) NSString* taskDescription;
@property (readonly) NSUInteger taskIdentifier;
@property (readonly, copy) NSError* error;
@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDataTask : NSURLSessionTask <NSCopying>
@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDownloadTask : NSURLSessionTask <NSCopying>
- (void)cancelByProducingResumeData:(void (^)(NSData*))completionHandler;
@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionUploadTask : NSURLSessionDataTask <NSCopying>
@end

/* Session Delegates */
@protocol NSURLSessionDelegate <NSObject>
@optional
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error;
- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session;
@end

/* Task Delegates */
@protocol NSURLSessionTaskDelegate <NSURLSessionDelegate>
@optional
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error;
- (void)URLSession:(NSURLSession*)session
                   task:(NSURLSessionTask*)task
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;
- (void)URLSession:(NSURLSession*)session
                        task:(NSURLSessionTask*)task
             didSendBodyData:(int64_t)bytesSent
              totalBytesSent:(int64_t)totalBytesSent
    totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)URLSession:(NSURLSession*)session
              task:(NSURLSessionTask*)task
 needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler;
- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler;
@end

@protocol NSURLSessionDataDelegate <NSURLSessionTaskDelegate>
@optional
- (void)URLSession:(NSURLSession*)session
          dataTask:(NSURLSessionDataTask*)dataTask
didReceiveResponse:(NSURLResponse*)response
 completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler;
- (void)URLSession:(NSURLSession*)session
                 dataTask:(NSURLSessionDataTask*)dataTask
    didBecomeDownloadTask:(NSURLSessionDownloadTask*)downloadTask;
- (void)URLSession:(NSURLSession*)session dataTask:(NSURLSessionDataTask*)dataTask didReceiveData:(NSData*)data;
- (void)URLSession:(NSURLSession*)session
          dataTask:(NSURLSessionDataTask*)dataTask
 willCacheResponse:(NSCachedURLResponse*)proposedResponse
 completionHandler:(void (^)(NSCachedURLResponse* cachedResponse))completionHandler;
@end

@protocol NSURLSessionDownloadDelegate <NSURLSessionTaskDelegate>
- (void)URLSession:(NSURLSession*)session downloadTask:(NSURLSessionDownloadTask*)downloadTask didFinishDownloadingToURL:(NSURL*)location;

@optional
- (void)URLSession:(NSURLSession*)session
      downloadTask:(NSURLSessionDownloadTask*)downloadTask
 didResumeAtOffset:(int64_t)fileOffset
expectedTotalBytes:(int64_t)expectedTotalBytes;
- (void)URLSession:(NSURLSession*)session
                 downloadTask:(NSURLSessionDownloadTask*)downloadTask
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
@end
