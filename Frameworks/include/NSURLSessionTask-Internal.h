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

// These methods are analogues of the URLSessionDelegate methods, excepting that they
// don't specify a URL Session. In doing this, we get the ability to compose tasks
// (for example, a download task can wholly own a data task, and act as a file-writing
// wrapper around it using only its task delegate methods, without the involvement of
// a URL session.)
@protocol _NSURLSessionTaskDelegate <NSObject>
@optional
- (void)task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error;
- (void)task:(NSURLSessionTask*)task
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler;
- (void)task:(NSURLSessionTask*)task
             didSendBodyData:(int64_t)bytesSent
              totalBytesSent:(int64_t)totalBytesSent
    totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)task:(NSURLSessionTask*)task needNewBodyStream:(void (^)(NSInputStream* bodyStream))completionHandler;
- (void)task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler;

- (void)dataTask:(NSURLSessionDataTask*)task
    didReceiveResponse:(NSURLResponse*)response
     completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler;
- (void)dataTask:(NSURLSessionDataTask*)task didBecomeDownloadTask:(NSURLSessionDownloadTask*)downloadTask;
- (void)dataTask:(NSURLSessionDataTask*)task didReceiveData:(NSData*)data;
- (void)dataTask:(NSURLSessionDataTask*)task
    willCacheResponse:(NSCachedURLResponse*)proposedResponse
    completionHandler:(void (^)(NSCachedURLResponse*))completionHandler;

- (void)downloadTask:(NSURLSessionDownloadTask*)task didResumeAtOffset:(int64_t)offset expectedTotalBytes:(int64_t)expectedTotalBytes;
- (void)downloadTask:(NSURLSessionDownloadTask*)task
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
- (void)downloadTask:(NSURLSessionDownloadTask*)task didFinishDownloadingToURL:(NSURL*)url;
@end

@interface NSURLSessionTask () <NSURLProtocolClient>
- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate
              configuration:(NSURLSessionConfiguration*)configuration
                    request:(NSURLRequest*)request;
@property (readwrite, assign) id<_NSURLSessionTaskDelegate> _taskDelegate;
- (void)_updateWithURLResponse:(NSURLResponse*)response;

@property (readwrite, assign) NSURLSessionTaskState state;
@property (readwrite, assign) int64_t countOfBytesExpectedToReceive;
@property (readwrite, assign) int64_t countOfBytesReceived;
@property (readwrite, assign) int64_t countOfBytesExpectedToSend;
@property (readwrite, assign) int64_t countOfBytesSent;
@property (readwrite, copy) NSURLRequest* currentRequest;
@property (readwrite, copy) NSURLRequest* originalRequest;
@property (readwrite, copy) NSURLResponse* response;
@property (readwrite, assign) NSUInteger taskIdentifier;
@property (readwrite, copy) NSError* error;
@end

// Instances of this class are serialized and returned as Resume Data
@interface _NSURLSessionDownloadResumeInfo : NSObject <NSSecureCoding>
@property (nonatomic, copy) NSURL* remoteURL;
@property (nonatomic, copy) NSString* etag;
@property (nonatomic, copy) NSString* lastModifiedDate;
@property (nonatomic, copy) NSURL* fileURL;
- (instancetype)initWithURLResponse:(NSHTTPURLResponse*)response temporaryFileURL:(NSURL*)temporaryFileURL;
@end

@interface NSURLSessionDownloadTask ()
- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate configuration:(NSURLSessionConfiguration*)configuration resumeData:(NSData*)resumeData;
//- (id)_initWithTaskDelegate:(id<_NSURLSessionTaskDelegate>)taskDelegate configuration:(NSURLSessionConfiguration*)configuration dataTask:(NSURLSessionDataTask*)dataTask;
@end
