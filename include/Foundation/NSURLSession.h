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
#import <Foundation/NSURLSessionTask.h>
#import <Foundation/NSURLSessionDataTask.h>
#import <Foundation/NSURLSessionDownloadTask.h>
#import <Foundation/NSURLSessionUploadTask.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSURLSessionConfiguration;
@protocol NSURLSessionDelegate;
@class NSOperationQueue;
@class NSURLSessionTask;
@class NSURLSessionDataTask;
@class NSURL;
@class NSData;
@class NSURLResponse;
@class NSError;
@class NSURLRequest;
@class NSURLSessionDownloadTask;
@class NSURLSessionUploadTask;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSURLSessionDownloadTaskResumeData;
FOUNDATION_EXPORT NSString* const NSURLErrorBackgroundTaskCancelledReasonKey;

typedef void (^NSURLSessionTaskCompletionHandler)(NSData* data, NSURLResponse* response, NSError* error);
typedef void (^NSURLSessionDownloadTaskCompletionHandler)(NSURL* location, NSURLResponse* response, NSError* error);

enum {
    NSURLErrorCancelledReasonUserForceQuitApplication = 0,
    NSURLErrorCancelledReasonBackgroundUpdatesDisabled = 1,
};

typedef NSUInteger NSURLErrorBackgroundTaskCancelledReason;

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

@protocol NSURLSessionDelegate
@optional
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error;

@optional
- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;

@optional
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session;

@end
