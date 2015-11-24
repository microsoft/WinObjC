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

#import <Foundation/Foundation.h>
#import <Starboard.h>
#import "NSURLSessionTask-Internal.h"

#import <Windows.h>

NSString* const NSURLSessionDownloadTaskResumeData = @"NSURLSessionDownloadTaskResumeData";
@interface NSURLSessionDownloadTask () {
    NSURL *_temporaryFileURL;
    NSOutputStream *_outputStream;
    bool _resumed;
}
@end

@implementation NSURLSessionDownloadTask
/*
- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate configuration:(NSURLSessionConfiguration*)configuration dataTask:(NSURLSessionDataTask*)dataTask {
    if (self = [super _initWithTaskDelegate:taskDelegate configuration:configuration request:dataTask.currentRequest]) {
        _originalTask = [dataTask retain];
        //_configuration = configuration; // steal a strong ref.
        //_connection = _connection;

        self.priority = dataTask.priority;
        self.taskDescription = dataTask.taskDescription;
        self.state = dataTask.state;
        self.countOfBytesExpectedToReceive = dataTask.countOfBytesExpectedToReceive;
        self.countOfBytesExpectedToSend = dataTask.countOfBytesExpectedToSend;
        self.countOfBytesSent = dataTask.countOfBytesSent;
        self.currentRequest = dataTask.currentRequest;
        self.originalRequest = dataTask.originalRequest;
        self.response = dataTask.response;
        self.taskIdentifier = dataTask.taskIdentifier;
        self.error = dataTask.error;
    }
    return self;
}
*/

- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate configuration:(NSURLSessionConfiguration*)configuration resumeData:(NSData*)resumeData {
    _NSURLSessionDownloadResumeInfo* resumeInfo = [NSKeyedUnarchiver unarchiveObjectWithData:resumeData];
    if (!resumeInfo) {
        [self release];
        return nil;
    }

    NSURLRequest* originalRequest = [[[NSURLRequest alloc] initWithURL:resumeInfo.remoteURL] autorelease];
    if (self = [super _initWithTaskDelegate:taskDelegate configuration:configuration request:originalRequest]) {
        NSMutableURLRequest* newRequest = [[originalRequest mutableCopy] autorelease];
        if (resumeInfo.lastModifiedDate) {
            [newRequest setValue:resumeInfo.lastModifiedDate forHTTPHeaderField:@"If-Range"];
        }
        if (resumeInfo.etag) {
            [newRequest setValue:resumeInfo.etag forHTTPHeaderField:@"If-Range"];
        }
        // TODO does not exist etc.
        NSDictionary *fileAttributes = [[NSFileManager defaultManager] fileAttributesAtPath:[resumeInfo.fileURL path] traverseLink:NO];
        self.countOfBytesReceived = [fileAttributes fileSize];
        [newRequest setValue:[NSString stringWithFormat:@"bytes=%lld-", self.countOfBytesReceived] forHTTPHeaderField:@"Range"];
        
        self.currentRequest = newRequest;

        _temporaryFileURL = [resumeInfo.fileURL copy];
        _resumed = true;
    }
    return self;
}

- (void)dealloc {
    [_temporaryFileURL release];
    [_outputStream release];
    [super dealloc];
}

- (void)cancel {
    @synchronized(self) {
        bool shouldClose;

        if (self.state != NSURLSessionTaskStateCanceling) {
            shouldClose = true;
        }

        [super cancel];

        if (shouldClose) {
            [self _finalizeOutputStream];
        }
    }
}

- (void)_finalizeOutputStream {
    NSOutputStream* outputStream = reinterpret_cast<NSOutputStream*>(InterlockedExchangePointer(reinterpret_cast<void*volatile*>(&_outputStream), nil));
    [outputStream close];
    [outputStream release];
}

- (void)_destroyTemporaryFile {
    [[NSFileManager defaultManager] removeItemAtURL:_temporaryFileURL error:NULL];
}

/*
@Status Interoperable
*/
- (void)cancelByProducingResumeData:(void(^)(NSData* resumeData))completionHandler {
    [self cancel];
    [self _finalizeOutputStream];
    completionHandler([self _generateResumeData]);
}

- (NSData*)_generateResumeData {
    NSData* resumeData = nil;
    if ([self.response isKindOfClass:[NSHTTPURLResponse class]]) {
        _NSURLSessionDownloadResumeInfo* resumeInfo = [[_NSURLSessionDownloadResumeInfo alloc] initWithURLResponse:(NSHTTPURLResponse*)self.response temporaryFileURL:_temporaryFileURL];
        if (resumeInfo) {
            resumeData = [NSKeyedArchiver archivedDataWithRootObject:resumeInfo];
        }
        [resumeInfo release];
    }
    return resumeData;
}

- (void)_updateWithURLResponse:(NSURLResponse*)response {
    [super _updateWithURLResponse:response];
    if (!_temporaryFileURL) {
        NSString* temporaryFilename = [NSString stringWithFormat:@"Download-%p", self];
        _temporaryFileURL = [[NSURL fileURLWithPath:[NSTemporaryDirectory() stringByAppendingPathComponent:temporaryFilename]] retain];
    }
}

- (void)URLProtocol:(NSURLProtocol*)connection didReceiveResponse:(NSURLResponse*)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy {
    [super URLProtocol:connection didReceiveResponse:response cacheStoragePolicy:policy];

    if (_resumed) {
        [self._taskDelegate downloadTask:self didResumeAtOffset:self.countOfBytesReceived expectedTotalBytes:self.countOfBytesExpectedToReceive];
    }
}

- (void)URLProtocol:(NSURLProtocol*)connection didFailWithError:(NSError*)error {
    [self _finalizeOutputStream];
    NSData* resumeData = [self _generateResumeData];
    if (resumeData) {
        // If this download can be resumed, stick the resume data onto the
        // error we propagate to the delegate.

        NSMutableDictionary* newUserInfo = [error.userInfo mutableCopy];
        [newUserInfo setObject:resumeData forKey:NSURLSessionDownloadTaskResumeData];
        NSError* newError = [NSError errorWithDomain:error.domain code:error.code userInfo:newUserInfo];
        error = newError;
    }

    [super URLProtocol:connection didFailWithError:error];
}

- (void)URLProtocol:(NSURLProtocol*)connection didLoadData:(NSData*)data {
    [super URLProtocol:connection didLoadData:data];

    if (!self.response) {
        // this occasionally gets called before data happens.
        return;
    }

    if (!_outputStream) {
        _outputStream = [[NSOutputStream outputStreamToFileAtPath:[_temporaryFileURL path] append:YES] retain];
        [_outputStream open];
    }

    auto remaining = data.length;
    auto bytes = reinterpret_cast<const uint8_t*>(data.bytes);
    while (remaining > 0) {
        auto written = [_outputStream write:bytes maxLength:remaining];
        remaining -= written;
        bytes += written;
    }

    [self._taskDelegate
                     downloadTask:self
                     didWriteData:data.length
                totalBytesWritten:self.countOfBytesReceived
        totalBytesExpectedToWrite:self.countOfBytesExpectedToReceive];
}

- (void)URLProtocolDidFinishLoading:(NSURLProtocol*)connection {
    [self _finalizeOutputStream];

    // _temporaryFileURL is expected to outlive us.
    [self._taskDelegate downloadTask:self didFinishDownloadingToURL:[[_temporaryFileURL retain] autorelease]];

    [super URLProtocolDidFinishLoading:connection];

    [self _destroyTemporaryFile];
}
@end