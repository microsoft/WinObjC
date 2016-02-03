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

#import <Foundation/NSURLSessionTask.h>
@class NSData;

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionDownloadTask : NSURLSessionTask <NSCopying>
- (void)cancelByProducingResumeData:(void (^)(NSData*))completionHandler;
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
