//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#import <Foundation/NSURLProtocol.h>

@class NSURLRequest;
@class NSData;
@class NSURLResponse;
@class NSError;
@class NSOperationQueue;
@class NSRunLoop;
@class NSString;
@class NSInputStream;
@class NSURLProtectionSpace;
@class NSURL;

FOUNDATION_EXPORT_CLASS
@interface NSURLConnection : NSObject <NSURLProtocolClient> {
    id _request;
    id _protocol;
    id _delegate;
    id _response;
    unsigned _storagePolicy;
    BOOL _didRetain, _didRelease, _scheduled;
}

+ (BOOL)canHandleRequest:(NSURLRequest*)request;
@property (readonly, copy) NSURLRequest* originalRequest;
@property (readonly, copy) NSURLRequest* currentRequest;
+ (NSData*)sendSynchronousRequest:(NSURLRequest*)request
                returningResponse:(NSURLResponse* _Nullable*)response
                            error:(NSError* _Nullable*)error;
+ (NSURLConnection*)connectionWithRequest:(NSURLRequest*)request delegate:(id)delegate;
- (instancetype)initWithRequest:(NSURLRequest*)request delegate:(id)delegate;
- (instancetype)initWithRequest:(NSURLRequest*)request delegate:(id)delegate startImmediately:(BOOL)startImmediately;
+ (void)sendAsynchronousRequest:(NSURLRequest*)request
                          queue:(NSOperationQueue*)queue
              completionHandler:(void (^)(NSURLResponse*, NSData*, NSError*))handler;
- (void)start;
- (void)cancel;
- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode;
- (void)setDelegateQueue:(NSOperationQueue*)queue STUB_METHOD;
- (void)unscheduleFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode;
@end

@protocol NSURLConnectionDelegate <NSObject>
@optional
- (void)connection:(NSURLConnection*)connection willSendRequestForAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (BOOL)connection:(NSURLConnection*)connection canAuthenticateAgainstProtectionSpace:(NSURLProtectionSpace*)protectionSpace;
- (void)connection:(NSURLConnection*)connection didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (void)connection:(NSURLConnection*)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge;
- (BOOL)connectionShouldUseCredentialStorage:(NSURLConnection*)connection;
- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)error;
@end

@protocol NSURLConnectionDataDelegate <NSURLConnectionDelegate>
@optional
- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response;
- (void)connection:(NSURLConnection*)connection didReceiveData:(NSData*)data;
- (void)connection:(NSURLConnection*)connection
              didSendBodyData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;
- (void)connectionDidFinishLoading:(NSURLConnection*)connection;
- (NSURLRequest*)connection:(NSURLConnection*)connection
            willSendRequest:(NSURLRequest*)request
           redirectResponse:(NSURLResponse*)redirectResponse;
- (NSInputStream*)connection:(NSURLConnection*)connection needNewBodyStream:(NSURLRequest*)request;
- (NSCachedURLResponse*)connection:(NSURLConnection*)connection willCacheResponse:(NSCachedURLResponse*)cachedResponse;
@end

@protocol NSURLConnectionDownloadDelegate <NSURLConnectionDelegate>
@optional
- (void)connection:(NSURLConnection*)connection
      didWriteData:(long long)bytesWritten
 totalBytesWritten:(long long)totalBytesWritten
expectedTotalBytes:(long long)expectedTotalBytes;
- (void)connectionDidResumeDownloading:(NSURLConnection*)connection
                     totalBytesWritten:(long long)totalBytesWritten
                    expectedTotalBytes:(long long)expectedTotalBytes;

- (void)connectionDidFinishDownloading:(NSURLConnection*)connection destinationURL:(NSURL*)destinationURL;
@end
