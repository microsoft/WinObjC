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
#import <Foundation/NSCachedURLResponse.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSHTTPURLResponse.h>
#import <Foundation/NSInputStream.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSUrlSession.h>
#import <Foundation/NSURLAuthenticationChallenge.h>
#import <Foundation/NSURLCredential.h>

@class NSURLSession;
@class NSURLRequest;
@class NSURLResponse;
@class NSString;
@class NSError;

typedef NS_ENUM(NSInteger, NSURLSessionTaskState) {
    NSURLSessionTaskStateRunning = 0,
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,
    NSURLSessionTaskStateCompleted = 3,
};

FOUNDATION_EXPORT const float NSURLSessionTaskPriorityDefault;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityLow;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityHigh;

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

@protocol NSURLSessionTaskDelegate
@optional
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error;

@optional
- (void)URLSession:(NSURLSession*)session
                   task:(NSURLSessionTask*)task
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;

@optional
- (void)URLSession:(NSURLSession*)session
                        task:(NSURLSessionTask*)task
             didSendBodyData:(int64_t)bytesSent
              totalBytesSent:(int64_t)totalBytesSent
    totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;

@optional
- (void)URLSession:(NSURLSession*)session
              task:(NSURLSessionTask*)task
 needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler;

@optional
- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler;

@end
