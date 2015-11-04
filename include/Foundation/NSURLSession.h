//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSURLRequest.h>

typedef NS_ENUM(NSInteger, NSURLSessionResponseDisposition) {
    NSURLSessionResponseCancel = 0,
    NSURLSessionResponseAllow = 1,
    NSURLSessionResponseBecomeDownload = 2
};

FOUNDATION_EXPORT const int64_t NSURLSessionTransferSizeUnknown;

// A key in the error dictionary that provides resume data.
FOUNDATION_EXPORT NSString* const NSURLSessionDownloadTaskResumeData;

// An NSNumber value indicating why a background task was cancelled.
FOUNDATION_EXPORT NSString* const NSURLErrorBackgroundTaskCancelledReasonKey;

typedef NS_ENUM(NSUInteger, NSURLErrorBackgroundTaskCancelledReason) {
   NSURLErrorCancelledReasonUserForceQuitApplication =    0,
   NSURLErrorCancelledReasonBackgroundUpdatesDisabled =   1,
};

@class NSURLCredential;
@class NSURLAuthenticationChallenge;
@class NSURLSessionTask;
@class NSURLSessionDataTask;
@class NSURLSessionDownloadTask;
@class NSURLSessionUploadTask;

typedef NS_ENUM(NSInteger, NSURLSessionAuthChallengeDisposition) {
    NSURLSessionAuthChallengeUseCredential = 0,
    NSURLSessionAuthChallengePerformDefaultHandling = 1,
    NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,
    NSURLSessionAuthChallengeRejectProtectionSpace = 3,
};

@protocol NSURLSessionDelegate;

typedef void(^NSURLSessionTaskCompletionHandler)(NSData* data, NSURLResponse* response, NSError* error);
typedef void(^NSURLSessionDownloadTaskCompletionHandler)(NSURL* location, NSURLResponse* response, NSError* error);

FOUNDATION_EXPORT_CLASS
@interface NSURLSession : NSObject
+ (instancetype)sharedSession;
+ (instancetype)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration;
+ (instancetype)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration
                                delegate:(id<NSURLSessionDelegate>)delegate
                           delegateQueue:(NSOperationQueue*)operationQueue;

@property (readonly, copy) NSURLSessionConfiguration* configuration;
@property (readonly, retain) id<NSURLSessionDelegate> delegate;
@property (readonly, retain) NSOperationQueue* delegateQueue;
@property (copy) NSString* sessionDescription;

- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url;
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler;

- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url;
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler;
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler;
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData;
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData completionHandler:(NSURLSessionDownloadTaskCompletionHandler)completionHandler;

- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromData:(NSData*)data;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromData:(NSData*)data completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromFile:(NSURL*)fileURL;
- (NSURLSessionUploadTask*)uploadTaskWithRequest:(NSURLRequest*)request fromFile:(NSURL*)fileURL completionHandler:(NSURLSessionTaskCompletionHandler)completionHandler;
- (NSURLSessionUploadTask*)uploadTaskWithStreamedRequest:(NSURLRequest*)request;

- (void)finishTasksAndInvalidate;
- (void)flushWithCompletionHandler:(void(^)(void))completionHandler;
- (void)getTasksWithCompletionHandler:(void(^)(NSArray* dataTasks, NSArray* uploadTasks, NSArray* downloadTasks))completionHandler;
- (void)invalidateAndCancel;
- (void)resetWithCompletionHandler:(void(^)(void))completionHandler;
@end

@protocol NSURLSessionDelegate <NSObject>

- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error;

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session;

@end