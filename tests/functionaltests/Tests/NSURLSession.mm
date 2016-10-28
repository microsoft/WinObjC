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

#include <TestFramework.h>
#include <Foundation/Foundation.h>
#include <cmath>

static const NSTimeInterval c_testTimeoutInSec = 5;
static const NSTimeInterval c_testDownloadTimeoutInSec = 30;

typedef NS_ENUM(NSInteger, NSURLSessionAllDelegateType) {
    NSURLSessionDelegateWillPerformHTTPRedirection,
    NSURLSessionDelegateDidCompleteWithError,
    NSURLSessionDataDelegateDidReceiveResponse,
    NSURLSessionDataDelegateDidReceiveData,
    NSURLSessionDownloadDelegateDidResumeAtOffset,
    NSURLSessionDownloadDelegateDidWriteData,
    NSURLSessionDownloadDelegateDidFinishDownloadingToURL
};

//
// NSURLSessionDataTask tests
//

@interface NSURLSessionDataTaskTestHelper : NSObject <NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLSessionDataDelegate> {
    dispatch_queue_t _queue;
    NSOperationQueue* _delegateQueue;
}
// TODO::
// todo-nithishm-03312016 - Switch from NSCondition to dispatch_semaphore_t once bug 7075799 is fixed.
@property NSCondition* condition;
@property NSMutableArray* delegateCallOrder;
@property (copy) NSURLRequest* redirectionRequest;
@property (copy) NSURLResponse* response;
@property (copy) NSData* data;
@property (copy) NSError* completedWithError;

- (instancetype)init;
- (NSURLSession*)createSession;
@end

@implementation NSURLSessionDataTaskTestHelper

- (instancetype)init {
    if (self = [super init]) {
        self->_condition = [[NSCondition alloc] init];
        _queue = dispatch_queue_create("NSURLSessionDataDelegateCallOrder", NULL);
        self->_delegateCallOrder = [NSMutableArray array];
    }
    return self;
}

- (NSURLSession*)createSession {
    _delegateQueue = [[NSOperationQueue alloc] init];
    [_delegateQueue setMaxConcurrentOperationCount:5];
    return [NSURLSession sessionWithConfiguration:nil delegate:self delegateQueue:_delegateQueue];
}

//
// NSURLSessionDelegate
//
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error {
    // TODO::
    // todo-nithishm-03312016 - Have tests for these.
}

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    // TODO::
    // todo-nithishm-03312016 - Have tests for these.
}

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session {
}

//
// NSURLSessionTaskDelegate
//
- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateWillPerformHTTPRedirection]];
    });

    self.redirectionRequest = request;
    completionHandler(request);
    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateDidCompleteWithError]];
    });
    self.completedWithError = error;
    [self.condition signal];
}

//
// NSURLSessionDataDelegate
//
- (void)URLSession:(NSURLSession*)session
              dataTask:(NSURLSessionDataTask*)task
    didReceiveResponse:(NSURLResponse*)response
     completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDataDelegateDidReceiveResponse]];
    });
    self.response = response;
    completionHandler(NSURLSessionResponseAllow);
    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session dataTask:(NSURLSessionDataTask*)task didReceiveData:(NSData*)data {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDataDelegateDidReceiveData]];
    });
    self.data = data;
    [self.condition signal];
}

@end

/**
 * Test to verify a that two tasks do not have the same identifier.
 */
TEST(NSURLSession, TaskIdentifiers) {
    NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
    NSURLSession* session = [dataTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?Hello=World"];

    NSURLSessionTask* dataTask = [session dataTaskWithURL:url];
    NSURLSessionTask* downloadTask = [session downloadTaskWithURL:url];

    ASSERT_NE(dataTask.taskIdentifier, downloadTask.taskIdentifier);
}

/**
 * Test to verify a data task call can be successfully made and a valid data is received without a completion handler
 */
TEST(NSURLSession, DataTaskWithURL) {
    NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
    NSURLSession* session = [dataTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?Hello=World"];
    LOG_INFO("Establishing data task with url %@", url);
    NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url];
    [dataTask resume];

    // Wait for data.
    if (![dataTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for connection timed out!");
    }

    // Give some time for all delegates to be called.
    [NSThread sleepForTimeInterval:2.0];

    // We should have all the delegates called by now.
    ASSERT_EQ_MSG(4, [dataTaskTestHelper.delegateCallOrder count], "FAILED: We should have received all four delegates call by now!");

    // Make sure willPerformHTTPRedirection delegate was first called.
    ASSERT_EQ_MSG(NSURLSessionDelegateWillPerformHTTPRedirection,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: willPerformHTTPRedirection should be the first delegate to be called!");

    // Make sure we received a response.
    ASSERT_EQ_MSG(NSURLSessionDataDelegateDidReceiveResponse,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:1] integerValue],
                  "FAILED: didReceiveResponse should be the second delegate to be called!");
    ASSERT_TRUE_MSG((dataTaskTestHelper.response != nil), "FAILED: Response cannot be empty!");
    NSURLResponse* response = dataTaskTestHelper.response;
    if (![response isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
    LOG_INFO("Received HTTP response headers: %d", [httpResponse allHeaderFields]);

    // Make sure we received data.
    ASSERT_EQ_MSG(NSURLSessionDataDelegateDidReceiveData,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:2] integerValue],
                  "FAILED: didReceiveData should be the third delegate to be called!");
    ASSERT_TRUE_MSG((dataTaskTestHelper.data != nil), "FAILED: We should have received some data!");
    LOG_INFO("Received data: %@", [[NSString alloc] initWithData:dataTaskTestHelper.data encoding:NSUTF8StringEncoding]);

    // Make sure didCompleteWithError delegate was called last.
    ASSERT_EQ_MSG(NSURLSessionDelegateDidCompleteWithError,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:3] integerValue],
                  "FAILED: willPerformHTTPRedirection should be the last delegate to be called!");
    // Make sure there was no error.
    ASSERT_TRUE_MSG((dataTaskTestHelper.completedWithError == nil),
                    "FAILED: Data task returned error %@!",
                    dataTaskTestHelper.completedWithError);
}

/**
 * Test to verify a data task call can be successfully made without a completion handler but no data was received but a valid response
 * error code was received.
 */
TEST(NSURLSession, DataTaskWithURL_Failure) {
    NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
    NSURLSession* session = [dataTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/status/500"];
    LOG_INFO("Establishing data task with url %@", url);
    NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url];
    [dataTask resume];

    // Wait for data.
    if (![dataTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for connection timed out!");
    }

    // Give some time for all delegates to be called.
    [NSThread sleepForTimeInterval:2.0];

    // We should have all the delegates called by now.
    ASSERT_EQ_MSG(2, [dataTaskTestHelper.delegateCallOrder count], "FAILED: We should have received all two delegates call by now!");

    // Make sure we received a response.
    ASSERT_EQ_MSG(NSURLSessionDataDelegateDidReceiveResponse,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didReceiveResponse should be the second delegate to be called!");
    ASSERT_TRUE_MSG((dataTaskTestHelper.response != nil), "FAILED: Response cannot be empty!");
    NSURLResponse* response = dataTaskTestHelper.response;
    if (![response isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(500, [httpResponse statusCode], "FAILED: HTTP status 500 expected!");

    // Make sure we did not receive any data.
    ASSERT_TRUE_MSG((dataTaskTestHelper.data == nil), "FAILED: We should have not received any data!");

    // Make sure didCompleteWithError delegate was called last.
    ASSERT_EQ_MSG(NSURLSessionDelegateDidCompleteWithError,
                  [(NSNumber*)[dataTaskTestHelper.delegateCallOrder objectAtIndex:1] integerValue],
                  "FAILED: willPerformHTTPRedirection should be the last delegate to be called!");
    // Make sure there was no error.
    ASSERT_TRUE_MSG((dataTaskTestHelper.completedWithError == nil),
                    "FAILED: Data task returned error %@!",
                    dataTaskTestHelper.completedWithError);
}

/**
 * Test to verify a data task call can be successfully made and a valid data is received with a completion handler
 */
TEST(NSURLSession, DataTaskWithURL_WithCompletionHandler) {
    __block NSCondition* condition = [[NSCondition alloc] init];
    __block NSURLResponse* taskResponse;
    __block NSData* taskData;
    __block NSError* taskError;

    NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
    NSURLSession* session = [dataTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?You=There"];
    LOG_INFO("Establishing data task with url %@", url);
    NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url
                                            completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                                                taskResponse = response;
                                                taskData = data;
                                                taskError = error;
                                                [condition signal];
                                            }];
    [dataTask resume];

    // Wait for data.
    [condition lock];
    ASSERT_TRUE_MSG((taskResponse || taskData || taskError) ||
                        [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                    "FAILED: Waiting for connection timed out!");
    [condition unlock];

    // Make sure we received a response.
    ASSERT_TRUE_MSG((taskResponse != nil), "FAILED: Response cannot be empty!");
    if (![taskResponse isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)taskResponse;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
    LOG_INFO("Received HTTP response headers: %d", [httpResponse allHeaderFields]);

    // Make sure we received data.
    ASSERT_TRUE_MSG((taskData != nil), "FAILED: We should have received some data!");
    LOG_INFO("Received data: %@", [[NSString alloc] initWithData:taskData encoding:NSUTF8StringEncoding]);

    // Make sure there was no error.
    ASSERT_EQ_MSG(nil, taskError, "FAILED: Task returned error!");
}

/**
 * Test to verify a data task call can be successfully made with a completion handler but no data was received but a valid response
 * error code was received.
 */
TEST(NSURLSession, DataTaskWithURL_WithCompletionHandler_Failure) {
    __block NSCondition* condition = [[NSCondition alloc] init];
    __block NSURLResponse* taskResponse;
    __block NSData* taskData;
    __block NSError* taskError;

    NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
    NSURLSession* session = [dataTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/status/403"];
    LOG_INFO("Establishing data task with url %@", url);
    NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url
                                            completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                                                taskResponse = response;
                                                taskData = data;
                                                taskError = error;
                                                [condition signal];
                                            }];
    [dataTask resume];

    // Wait for data.
    [condition lock];
    ASSERT_TRUE_MSG((taskResponse || taskData || taskError) ||
                        [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                    "FAILED: Waiting for connection timed out!");
    [condition unlock];

    // Make sure we received a response.
    ASSERT_TRUE_MSG((taskResponse != nil), "FAILED: Response cannot be empty!");
    if (![taskResponse isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)taskResponse;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(403, [httpResponse statusCode], "FAILED: HTTP status 403 expected!");

    // Make sure we did not receive any data.
    ASSERT_TRUE_MSG((taskData == nil), "FAILED: We should not have received any data!");

    // Make sure there was no error.
    ASSERT_EQ_MSG(nil, taskError, "FAILED: Connection returned error!");
}

//
// NSURLSessionDownloadTask tests
//

@interface NSURLSessionDownloadTaskTestHelper : NSObject <NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLSessionDownloadDelegate> {
    dispatch_queue_t _queue;
    NSOperationQueue* _delegateQueue;
    bool _didWriteDatadelegateCalled;
}
// TODO::
// todo-nithishm-bug - Switch from NSCondition to dispatch_semaphore_t once bug 7075799 is fixed.
@property NSCondition* condition;
@property NSCondition* conditionDownloadComplete;
@property NSCondition* conditionDownloadResumed;
@property NSMutableArray* delegateCallOrder;
@property (copy) NSURLRequest* redirectionRequest;
@property int64_t totalBytesExpectedToWrite;
@property int64_t totalBytesWritten;
@property (copy) NSURL* downloadedLocation;
@property (copy) NSError* completedWithError;

- (instancetype)init;
- (NSURLSession*)createSession;
@end

@implementation NSURLSessionDownloadTaskTestHelper

- (instancetype)init {
    if (self = [super init]) {
        self->_condition = [[NSCondition alloc] init];
        self->_conditionDownloadComplete = [[NSCondition alloc] init];
        self->_conditionDownloadResumed = [[NSCondition alloc] init];
        _queue = dispatch_queue_create("NSURLSessionDataDelegateCallOrder", NULL);
        self->_delegateCallOrder = [NSMutableArray array];
    }
    return self;
}

- (NSURLSession*)createSession {
    _delegateQueue = [[NSOperationQueue alloc] init];
    [_delegateQueue setMaxConcurrentOperationCount:5];
    return [NSURLSession sessionWithConfiguration:nil delegate:self delegateQueue:_delegateQueue];
}

//
// NSURLSessionDelegate
//
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error {
    // TODO::
    // todo-nithishm-03312016 - Have tests for these.
}

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
    // TODO::
    // todo-nithishm-03312016 - Have tests for these.
}

- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession*)session {
}

//
// NSURLSessionTaskDelegate
//
- (void)URLSession:(NSURLSession*)session
                          task:(NSURLSessionTask*)task
    willPerformHTTPRedirection:(NSHTTPURLResponse*)response
                    newRequest:(NSURLRequest*)request
             completionHandler:(void (^)(NSURLRequest*))completionHandler {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateWillPerformHTTPRedirection]];
    });
    self.redirectionRequest = request;
    completionHandler(request);

    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateDidCompleteWithError]];
    });
    self.completedWithError = error;

    [self.condition signal];
}

//
// NSURLSessionDownloadDelegate
//

- (void)URLSession:(NSURLSession*)session
          downloadTask:(NSURLSessionDownloadTask*)downloadTask
     didResumeAtOffset:(int64_t)fileOffset
    expectedTotalBytes:(int64_t)expectedTotalBytes {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidResumeAtOffset]];
    });
    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session
                 downloadTask:(NSURLSessionDownloadTask*)downloadTask
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    // This delegate will be called periodically.
    if (!_didWriteDatadelegateCalled) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidWriteData]];
        });
        _didWriteDatadelegateCalled = true;
    }
    self.totalBytesExpectedToWrite = totalBytesExpectedToWrite;
    self.totalBytesWritten = totalBytesWritten;
    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session downloadTask:(NSURLSessionDownloadTask*)downloadTask didFinishDownloadingToURL:(NSURL*)location {
    [self.condition lock];
    dispatch_sync(_queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidFinishDownloadingToURL]];
    });
    self.downloadedLocation = location;
    [self.condition signal];
    [self.conditionDownloadComplete signal];
}

@end

/**
 * Test to verify a download task call can be successfully made without a completion handler
 */
TEST(NSURLSession, DownloadTaskWithURL) {
    NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
    NSURLSession* session = [downloadTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"http://speedtest.sea01.softlayer.com/downloads/test10.zip"];
    LOG_INFO("Establishing download task with url %@", url);
    NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
    [downloadTask resume];

    // Wait for download to complete.
    if (![downloadTaskTestHelper.conditionDownloadComplete
            waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testDownloadTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for download timed out!");
    }

    // Give some time for all delegates to be called.
    [NSThread sleepForTimeInterval:1.0];

    // We should have all the delegates called by now.
    ASSERT_EQ_MSG(3, [downloadTaskTestHelper.delegateCallOrder count], "FAILED: We should have received all three delegates call by now!");

    // Make sure the download started.
    ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidWriteData,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didWriteData should be the first delegate to be called!");
    double fileSizeInMB = (double)downloadTaskTestHelper.totalBytesExpectedToWrite / 1024 / 1024;
    LOG_INFO("Downloaded file size is %fMB", fileSizeInMB);
    ASSERT_EQ_MSG(10, std::floor(fileSizeInMB), "FAILED: Expected download file size does not match!");

    // Make sure the didFinishDownloadingToURL got called.
    ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidFinishDownloadingToURL,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:1] integerValue],
                  "FAILED: didFinishDownloadingToURL should be the second delegate to be called!");

    // Make sure didCompleteWithError delegate was called last.
    ASSERT_EQ_MSG(NSURLSessionDelegateDidCompleteWithError,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:2] integerValue],
                  "FAILED: willPerformHTTPRedirection should be the last delegate to be called!");
    // Make sure there was no error.
    ASSERT_TRUE_MSG((downloadTaskTestHelper.completedWithError == nil),
                    "FAILED: Data task returned error %@!",
                    downloadTaskTestHelper.completedWithError);
}

/**
 * Test to verify a download task call can be made without a completion handler
 */
TEST(NSURLSession, DownloadTaskWithURL_Failure) {
    NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
    NSURLSession* session = [downloadTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"https://httpbin.org/status/401"];
    LOG_INFO("Establishing download task with url %@", url);
    NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
    [downloadTask resume];

    // Wait for download to complete.
    if (![downloadTaskTestHelper.conditionDownloadComplete
            waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testDownloadTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for download timed out!");
    }

    // Give some time for all delegates to be called.
    [NSThread sleepForTimeInterval:1.0];

    // We should have all the delegates called by now.
    ASSERT_EQ_MSG(2, [downloadTaskTestHelper.delegateCallOrder count], "FAILED: We should have received all two delegates call by now!");

    ASSERT_EQ_MSG(0, downloadTaskTestHelper.totalBytesExpectedToWrite, "FAILED: Expected download file size to be ZERO!");

    // Make sure the didFinishDownloadingToURL got called first. We would never get didWriteData delegate called as the download URL we
    // have passed in invalid.
    ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidFinishDownloadingToURL,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didFinishDownloadingToURL should be the second delegate to be called!");

    // Make sure didCompleteWithError delegate was called last.
    ASSERT_EQ_MSG(NSURLSessionDelegateDidCompleteWithError,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:1] integerValue],
                  "FAILED: willPerformHTTPRedirection should be the last delegate to be called!");
    // Make sure there was no error.
    ASSERT_TRUE_MSG((downloadTaskTestHelper.completedWithError == nil),
                    "FAILED: Download task returned error %@!",
                    downloadTaskTestHelper.completedWithError);
}

/**
 * Test to verify a download task call can be successfully made with a completion handler
 */
TEST(NSURLSession, DownloadTaskWithURL_WithCompletionHandler) {
    __block NSCondition* condition = [[NSCondition alloc] init];
    __block NSURLResponse* downloadResponse;
    __block NSURL* downloadLocation;
    __block NSError* downloadError;

    NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
    NSURLSession* session = [downloadTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"http://speedtest.sea01.softlayer.com/downloads/test10.zip"];
    LOG_INFO("Establishing download task with url %@", url);
    NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url
                                                        completionHandler:^(NSURL* location, NSURLResponse* response, NSError* error) {
                                                            downloadLocation = location;
                                                            downloadResponse = response;
                                                            downloadError = error;
                                                            [condition signal];
                                                        }];
    [downloadTask resume];

    // Wait for download to complete.
    [condition lock];
    ASSERT_TRUE_MSG((downloadLocation || downloadResponse || downloadError) ||
                        [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testDownloadTimeoutInSec]],
                    "FAILED: Waiting for download timed out!");
    [condition unlock];

    // Make sure we get a download location.
    ASSERT_TRUE_MSG((downloadLocation != nil), "FAILED: Downloaded location cannot be empty!");
    LOG_INFO("File downloaded at location %@", downloadLocation);

    // Make sure there was no error.
    ASSERT_EQ_MSG(nil, downloadError, "FAILED: Download task returned error!");
}

inline int _GetLastDelegateCall(NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper) {
    return [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:([downloadTaskTestHelper.delegateCallOrder count] - 1)]
        integerValue];
}

/**
 * Test to verify a download task call can be successfully made and can be cancelled/resumed at runtime.
 */
TEST(NSURLSession, DownloadTaskWithURL_WithCancelResume) {
    NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
    NSURLSession* session = [downloadTaskTestHelper createSession];
    NSURL* url = [NSURL URLWithString:@"http://speedtest.ams01.softlayer.com/downloads/test500.zip"];
    LOG_INFO("Establishing download task with url %@", url);
    NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
    [downloadTask resume];

    // Wait for first delegate to be arrive.
    if (![downloadTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for download timed out!");
    }

    // Make sure the download started.
    ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidWriteData,
                  [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didWriteData should be the first delegate to be called!");
    double fileSizeInMB = (double)downloadTaskTestHelper.totalBytesExpectedToWrite / 1024 / 1024;
    LOG_INFO("Downloaded file size is %fMB", fileSizeInMB);
    ASSERT_EQ_MSG(500, std::floor(fileSizeInMB), "FAILED: Expected download file size does not match!");

    // Make sure download is in progress.
    double lastBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", lastBytesDownloaded);
    [NSThread sleepForTimeInterval:0.5];
    double currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", currentBytesDownloaded);
    ASSERT_GT_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should be in progress!");
    [NSThread sleepForTimeInterval:0.5];
    lastBytesDownloaded = currentBytesDownloaded;
    currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", currentBytesDownloaded);
    ASSERT_GT_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should be in progress!");

    // Now cancel the download
    // TODO::
    // todo-nithishm-03312016- Switch from NSCondition to dispatch_semaphore_t once bug 7075799 is fixed.
    __block NSCondition* conditionCancelled = [[NSCondition alloc] init];
    __block NSData* downloadResumeData;
    LOG_INFO("Cancelling download...");
    [downloadTask cancelByProducingResumeData:^(NSData* resumeData) {
        LOG_INFO("Download cancelled");
        downloadResumeData = resumeData;
        [conditionCancelled signal];
    }];

    // Wait for the task to be cancelled.
    [conditionCancelled lock];
    ASSERT_TRUE_MSG(downloadResumeData || [conditionCancelled waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]],
                    "FAILED: Waiting for download timed out!");
    [conditionCancelled unlock];

    // Make sure download has stopped.
    lastBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    [NSThread sleepForTimeInterval:0.5];
    currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    ASSERT_EQ_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should have stopped!");
    [NSThread sleepForTimeInterval:1];
    lastBytesDownloaded = currentBytesDownloaded;
    currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    ASSERT_EQ_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should have stopped!");
    LOG_INFO("Download stuck at - %fMB", currentBytesDownloaded);

    LOG_INFO("Resuming download...");
    // Now resume the download
    [session downloadTaskWithResumeData:downloadResumeData];
    [downloadTask resume];

    // Wait for resume delegate.
    if (![downloadTaskTestHelper.conditionDownloadResumed waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]) {
        // Wait timed out.
        ASSERT_FALSE_MSG(true, "FAILED: Waiting for download resume timed out!");
    }

    LOG_INFO("Download resumed");

    // Make sure download is in progress again.
    lastBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", lastBytesDownloaded);
    [NSThread sleepForTimeInterval:0.5];
    currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", currentBytesDownloaded);
    ASSERT_GT_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should be in progress!");
    [NSThread sleepForTimeInterval:0.5];
    lastBytesDownloaded = currentBytesDownloaded;
    currentBytesDownloaded = (double)downloadTaskTestHelper.totalBytesWritten / 1024 / 1024;
    LOG_INFO("Download in progress - %fMB", currentBytesDownloaded);
    ASSERT_GT_MSG(currentBytesDownloaded, lastBytesDownloaded, "FAILED: File download should be in progress!");
}