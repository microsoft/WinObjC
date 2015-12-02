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

#import <Foundation/NSObject.h>

typedef NS_ENUM(NSInteger, NSURLSessionTaskState) {
    NSURLSessionTaskStateRunning = 0,
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,
    NSURLSessionTaskStateCompleted = 3,
};

FOUNDATION_EXPORT const float NSURLSessionTaskPriorityDefault;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityLow;
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityHigh;

@class NSURLRequest;
@class NSURLResponse;
@class NSString;
@class NSError;
@class NSURLSession;
@class NSURLCredential;
@class NSURLAuthenticationChallenge;

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionTask : NSObject <NSCopying, NSObject>

- (void)cancel;
- (void)resume;
- (void)suspend;

@property(assign) float priority;
@property(copy) NSString* taskDescription;

@property(readonly) NSURLSessionTaskState state;
@property(readonly) int64_t countOfBytesExpectedToReceive;
@property(readonly) int64_t countOfBytesReceived;
@property(readonly) int64_t countOfBytesExpectedToSend;
@property(readonly) int64_t countOfBytesSent;
@property(readonly, copy) NSURLRequest* currentRequest;
@property(readonly, copy) NSURLRequest* originalRequest;
@property(readonly, copy) NSURLResponse* response;
@property(readonly) NSUInteger taskIdentifier;
@property(readonly, copy) NSError* error;

@end

@protocol NSURLSessionTaskDelegate <NSObject>
@optional
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error;
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler;
- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task willPerformHTTPRedirection:(NSHTTPURLResponse*)response newRequest:(NSURLRequest*)request completionHandler:(void (^)(NSURLRequest*))completionHandler;
@end