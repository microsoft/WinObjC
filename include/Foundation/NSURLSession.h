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

#ifndef _NSURLSESSION_H_
#define _NSURLSESSION_H_

#import <Foundation/NSTask.h>
#import <Foundation/NSURLRequest.h>

@class NSURLResponse;
@class NSURLCache;
@class NSError;
@class NSOperationQueue;

typedef NS_ENUM(NSInteger, NSURLSessionTaskState) {
    NSURLSessionTaskStateRunning = 0,
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,
    NSURLSessionTaskStateCompleted = 3,
};

typedef NS_ENUM(NSInteger, NSURLSessionResponseDisposition) {
    NSURLSessionResponseCancel = 0,
    NSURLSessionResponseAllow = 1,
    NSURLSessionResponseBecomeDownload = 2
};

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionTask : NSObject

@property (readonly) NSURLResponse* response;
@property (readonly) NSURLSessionTaskState state;
@property (readonly) NSURLRequest* originalRequest;
@property (readonly) NSURLRequest* currentRequest;
@property (readonly) NSURLRequest* error;

- (void)cancel;
- (void)resume;
- (void)suspend;

@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDownloadTask : NSURLSessionTask

@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDataTask : NSURLSessionTask

@end

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionConfiguration : NSObject

@property (nonatomic) BOOL allowsCellularAccess;
@property (nonatomic) NSURLCache* URLCache;
@property (nonatomic) NSURLRequestCachePolicy requestCachePolicy;
@property (nonatomic) NSTimeInterval timeoutIntervalForResource;
@property (nonatomic) NSTimeInterval timeoutIntervalForRequest;
@property (nonatomic) NSUInteger HTTPMaximumConnectionsPerHost;

+ (instancetype)ephemeralSessionConfiguration;
+ (instancetype)defaultSessionConfiguration;
+ (instancetype)backgroundSessionConfiguration:(NSString*)name;

@end

@class NSURLCredential;
@class NSURLAuthenticationChallenge;

typedef NS_ENUM(NSInteger, NSURLSessionAuthChallengeDisposition) {
    NSURLSessionAuthChallengeUseCredential = 0,
    NSURLSessionAuthChallengePerformDefaultHandling = 1,
    NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,
    NSURLSessionAuthChallengeRejectProtectionSpace = 3,
};

FOUNDATION_EXPORT_CLASS
@interface NSURLSession : NSObject
+ (instancetype)sessionWithConfiguration:(NSURLSessionConfiguration*)configuration
                                delegate:(id)delegate
                           delegateQueue:(NSOperationQueue*)operationQueue;

- (NSURLSessionConfiguration*)configuration;
- (NSURLSessionDownloadTask*)downloadTaskWithURL:(NSURL*)url;
- (NSURLSessionDataTask*)dataTaskWithURL:(NSURL*)url;
- (NSURLSessionDownloadTask*)downloadTaskWithResumeData:(NSData*)resumeData;
- (NSURLSessionDownloadTask*)downloadTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request;
- (NSURLSessionDataTask*)dataTaskWithRequest:(NSURLRequest*)request
                           completionHandler:(void (^)(NSData*, NSURLResponse* response, NSError* error))completion;
@end

@protocol NSURLSessionDelegate <NSObject>

- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error;

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session;

@end

#endif /* _NSURLSESSION_H_ */
