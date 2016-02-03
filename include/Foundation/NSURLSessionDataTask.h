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

#import <Foundation/NSURLSession.h>
#import <Foundation/NSURLSessionTask.h>

@class NSURLSession;
@class NSURLSessionDownloadTask;

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDataTask : NSURLSessionTask <NSCopying>
@end

typedef NS_ENUM(NSInteger, NSURLSessionResponseDisposition) {
    NSURLSessionResponseCancel = 0,
    NSURLSessionResponseAllow = 1,
    NSURLSessionResponseBecomeDownload = 2
};

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
