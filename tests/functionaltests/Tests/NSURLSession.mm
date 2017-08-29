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

#import <TestFramework.h>
#import <Helpers/TestHelpers.h>
#import <Foundation/Foundation.h>
#import <cmath>

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

@property (nonatomic) THBooleanCondition* condition;
@property (nonatomic) NSMutableArray* delegateCallOrder;
@property (nonatomic, copy) NSURLRequest* redirectionRequest;
@property (nonatomic, copy) NSURLResponse* response;
@property (nonatomic, copy) NSData* data;
@property (nonatomic, copy) NSError* completedWithError;

- (instancetype)init;
- (NSURLSession*)createSession;
@end

@implementation NSURLSessionDataTaskTestHelper

- (instancetype)init {
    if (self = [super init]) {
        self->_condition = [[THBooleanCondition alloc] init];
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
// Property getters
//
// Note: Since we're using @synchronized(self), the atomic annotation isn't strong enough for
// guaranteeing nonconcurrent access over the entire object. The later mutators will lock over
// self.

- (THBooleanCondition*)condition {
    @synchronized(self) {
        return _condition;
    }
}

- (NSMutableArray*)delegateCallOrder {
    @synchronized(self) {
        return _delegateCallOrder;
    }
}

- (NSURLRequest*)redirectionRequest {
    @synchronized(self) {
        return _redirectionRequest;
    }
}

- (NSURLResponse*)response {
    @synchronized(self) {
        return _response;
    }
}

- (NSData*)data {
    @synchronized(self) {
        return _data;
    }
}

- (NSError*)completedWithError {
    @synchronized(self) {
        return _completedWithError;
    }
}

//
// NSURLSessionDelegate
//
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error {
}

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
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
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateWillPerformHTTPRedirection]];
        });
        self.redirectionRequest = request;
        completionHandler(request);
    }
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateDidCompleteWithError]];
        });
        self.completedWithError = error;
    }
    [self.condition signal];
}

//
// NSURLSessionDataDelegate
//
- (void)URLSession:(NSURLSession*)session
              dataTask:(NSURLSessionDataTask*)task
    didReceiveResponse:(NSURLResponse*)response
     completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDataDelegateDidReceiveResponse]];
        });
        self.response = response;
        completionHandler(NSURLSessionResponseAllow);
    }
}

- (void)URLSession:(NSURLSession*)session dataTask:(NSURLSessionDataTask*)task didReceiveData:(NSData*)data {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDataDelegateDidReceiveData]];
        });
        self.data = data;
    }
}

@end

@interface NSURLSessionDownloadTaskTestHelper : NSObject <NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLSessionDownloadDelegate> {
    dispatch_queue_t _queue;
    NSOperationQueue* _delegateQueue;
    bool _didWriteDatadelegateCalled;
}

@property (nonatomic) THBooleanCondition* condition;
@property (nonatomic) NSMutableArray* delegateCallOrder;
@property (nonatomic, copy) NSURLRequest* redirectionRequest;
@property (nonatomic) int64_t totalBytesExpectedToWrite;
@property (nonatomic) int64_t totalBytesWritten;
@property (nonatomic, copy) NSURL* downloadedLocation;
@property (nonatomic, copy) NSError* completedWithError;

- (instancetype)init;
- (NSURLSession*)createSession;
@end

@implementation NSURLSessionDownloadTaskTestHelper

- (instancetype)init {
    if (self = [super init]) {
        self->_condition = [[THBooleanCondition alloc] init];
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
// Property getters
//
// Note: Since we're using @synchronized(self), the atomic annotation isn't strong enough for
// guaranteeing nonconcurrent access over the entire object. The later mutators will lock over
// self.

- (THBooleanCondition*)condition {
    @synchronized(self) {
        return _condition;
    }
}

- (NSMutableArray*)delegateCallOrder {
    @synchronized(self) {
        return _delegateCallOrder;
    }
}

- (NSURLRequest*)redirectionRequest {
    @synchronized(self) {
        return _redirectionRequest;
    }
}

- (int64_t)totalBytesExpectedToWrite {
    @synchronized(self) {
        return _totalBytesExpectedToWrite;
    }
}

- (int64_t)totalBytesWritten {
    @synchronized(self) {
        return _totalBytesWritten;
    }
}

- (NSURL*)downloadedLocation {
    @synchronized(self) {
        return _downloadedLocation;
    }
}

- (NSError*)completedWithError {
    @synchronized(self) {
        return _completedWithError;
    }
}

//
// NSURLSessionDelegate
//
- (void)URLSession:(NSURLSession*)session didBecomeInvalidWithError:(NSError*)error {
}

- (void)URLSession:(NSURLSession*)session
    didReceiveChallenge:(NSURLAuthenticationChallenge*)challenge
      completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential* credential))completionHandler {
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
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateWillPerformHTTPRedirection]];
        });
        self.redirectionRequest = request;
        completionHandler(request);
    }
}

- (void)URLSession:(NSURLSession*)session task:(NSURLSessionTask*)task didCompleteWithError:(NSError*)error {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDelegateDidCompleteWithError]];
        });
        self.completedWithError = error;
    }
    [self.condition signal];
}

//
// NSURLSessionDownloadDelegate
//

- (void)URLSession:(NSURLSession*)session
          downloadTask:(NSURLSessionDownloadTask*)downloadTask
     didResumeAtOffset:(int64_t)fileOffset
    expectedTotalBytes:(int64_t)expectedTotalBytes {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidResumeAtOffset]];
        });
    }
}

- (void)URLSession:(NSURLSession*)session
                 downloadTask:(NSURLSessionDownloadTask*)downloadTask
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    @synchronized(self) {
        // This delegate will be called periodically.
        if (!_didWriteDatadelegateCalled) {
            dispatch_sync(_queue, ^{
                [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidWriteData]];
            });
            _didWriteDatadelegateCalled = true;
        }
        self.totalBytesExpectedToWrite = totalBytesExpectedToWrite;
        self.totalBytesWritten = totalBytesWritten;
    }
}

- (void)URLSession:(NSURLSession*)session downloadTask:(NSURLSessionDownloadTask*)downloadTask didFinishDownloadingToURL:(NSURL*)location {
    @synchronized(self) {
        dispatch_sync(_queue, ^{
            [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLSessionDownloadDelegateDidFinishDownloadingToURL]];
        });
        self.downloadedLocation = location;
    }
}

@end

@interface NSURLSessionDownloadTaskCancellingTestHelper : NSURLSessionDownloadTaskTestHelper
@property (nonatomic) THBooleanCondition* downloadCancelledCondition;
@property (nonatomic, copy) NSData* resumeData;
@end

@implementation NSURLSessionDownloadTaskCancellingTestHelper
- (instancetype)init {
    if (self = [super init]) {
        self->_downloadCancelledCondition = [[THBooleanCondition alloc] init];
    }
    return self;
}

//
// NSURLSessionDownloadDelegate
//

- (void)URLSession:(NSURLSession*)session
          downloadTask:(NSURLSessionDownloadTask*)downloadTask
     didResumeAtOffset:(int64_t)fileOffset
    expectedTotalBytes:(int64_t)expectedTotalBytes {
    [super URLSession:session downloadTask:downloadTask didResumeAtOffset:fileOffset expectedTotalBytes:expectedTotalBytes];
    [self.condition signal];
}

- (void)URLSession:(NSURLSession*)session
                 downloadTask:(NSURLSessionDownloadTask*)downloadTask
                 didWriteData:(int64_t)bytesWritten
            totalBytesWritten:(int64_t)totalBytesWritten
    totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite {
    @synchronized(self) {
        [super URLSession:session
                         downloadTask:downloadTask
                         didWriteData:bytesWritten
                    totalBytesWritten:totalBytesWritten
            totalBytesExpectedToWrite:totalBytesExpectedToWrite];
        [downloadTask cancelByProducingResumeData:^(NSData* resumeData) {
            @synchronized(self) {
                self.resumeData = resumeData;
                [self.downloadCancelledCondition signal];
            }
        }];
    }
}
@end

class NSURLSessionTests {
public:
    BEGIN_TEST_CLASS(NSURLSessionTests)
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"NSURL.AppxManifest.xml")

// Disable tests on ARM as it tries to hit a real endpoint and download significant data
// and arm machines may not have a stable ethernet connection like a build server does.
#ifdef _M_ARM
    TEST_CLASS_PROPERTY(L"Ignore", L"true")
#endif
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(NSURLCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    /**
     * Test to verify a that two tasks do not have the same identifier.
     */
    TEST_METHOD(TaskIdentifiers) {
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
    TEST_METHOD(DataTaskWithURL) {
        NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
        NSURLSession* session = [dataTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?Hello=World"];
        LOG_INFO("Establishing data task with url %@", url);
        NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url];
        [dataTask resume];

        // Wait for data.
        for (int i = 0; (i < 5) && ([dataTaskTestHelper.delegateCallOrder count] != 4); i++) {
            [dataTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        }
        ASSERT_EQ_MSG(4,
                      [dataTaskTestHelper.delegateCallOrder count],
                      "FAILED: We should have received all four delegates call by now; got %@",
                      dataTaskTestHelper.delegateCallOrder);

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
        LOG_INFO("Received HTTP response headers: %@", [httpResponse allHeaderFields]);

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
     * Test to verify a data task call can be successfully made without a completion handler but no data was received but a valid
     * response
     * error code was received.
     */
    TEST_METHOD(DataTaskWithURL_Failure) {
        NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
        NSURLSession* session = [dataTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/status/500"];
        LOG_INFO("Establishing data task with url %@", url);
        NSURLSessionDataTask* dataTask = [session dataTaskWithURL:url];
        [dataTask resume];

        // Wait for data.
        for (int i = 0; (i < 5) && ([dataTaskTestHelper.delegateCallOrder count] != 2); i++) {
            [dataTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        }

        ASSERT_EQ_MSG(2,
                      [dataTaskTestHelper.delegateCallOrder count],
                      "FAILED: We should have received all two delegates call by now; got %@",
                      dataTaskTestHelper.delegateCallOrder);

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
    TEST_METHOD(DataTaskWithURL_WithCompletionHandler) {
        __block THBooleanCondition* condition = [[THBooleanCondition alloc] init];
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
        ASSERT_TRUE([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]);
        ASSERT_TRUE(taskResponse || taskData || taskError);

        // Make sure we received a response.
        ASSERT_TRUE_MSG((taskResponse != nil), "FAILED: Response cannot be empty!");
        if (![taskResponse isKindOfClass:[NSHTTPURLResponse class]]) {
            ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
        }
        NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)taskResponse;
        LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
        ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
        LOG_INFO("Received HTTP response headers: %@", [httpResponse allHeaderFields]);

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
    TEST_METHOD(DataTaskWithURL_WithCompletionHandler_Failure) {
        __block THBooleanCondition* condition = [[THBooleanCondition alloc] init];
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
        ASSERT_TRUE([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]);
        ASSERT_TRUE(taskResponse || taskData || taskError);

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

    /**
     * Test to verify a data task post request can be successfully made and a valid data is received with a completion handler
     */
    TEST_METHOD(DataTaskWithPostRequest) {
        __block THBooleanCondition* condition = [[THBooleanCondition alloc] init];
        __block NSURLResponse* taskResponse;
        __block NSData* taskData;
        __block NSError* taskError;

        NSURLSessionDataTaskTestHelper* dataTaskTestHelper = [[NSURLSessionDataTaskTestHelper alloc] init];
        NSURLSession* session = [dataTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/post"];
        LOG_INFO("Establishing data task with url %@", url);

        NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:url];

        static const std::string alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        request.HTTPBody = [NSData dataWithBytes:reinterpret_cast<const void*>(alphanumeric.data()) length:alphanumeric.size()];
        request.HTTPMethod = @"POST";
        [request setValue:[NSString stringWithFormat:@"%lu", alphanumeric.size()] forHTTPHeaderField:@"Content-Length"];

        NSURLSessionDataTask* dataTask = [session dataTaskWithRequest:request
                                                    completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                                                        taskResponse = response;
                                                        taskData = data;
                                                        taskError = error;
                                                        [condition signal];
                                                    }];
        [dataTask resume];

        // Wait for data.
        ASSERT_TRUE([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]]);
        ASSERT_TRUE(taskResponse || taskData || taskError);

        // Make sure we received a response.
        ASSERT_TRUE_MSG((taskResponse != nil), "FAILED: Response cannot be empty!");
        if (![taskResponse isKindOfClass:[NSHTTPURLResponse class]]) {
            ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
        }
        NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)taskResponse;
        LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
        ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
        LOG_INFO("Received HTTP response headers: %@", [httpResponse allHeaderFields]);

        // Make sure we received data.
        ASSERT_TRUE_MSG((taskData != nil), "FAILED: We should have received some data!");
        LOG_INFO("Received data: %@", [[NSString alloc] initWithData:taskData encoding:NSUTF8StringEncoding]);

        // Make sure there was no error.
        ASSERT_EQ_MSG(nil, taskError, "FAILED: Task returned error!");
    }

    //
    // NSURLSessionDownloadTask tests
    //

    /**
     * Test to verify a download task call can be successfully made without a completion handler
     */
    TEST_METHOD(DownloadTaskWithURL) {
        NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
        NSURLSession* session = [downloadTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"http://speedtest.sea01.softlayer.com/downloads/test10.zip"];
        LOG_INFO("Establishing download task with url %@", url);
        NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
        [downloadTask resume];

        // Wait for download to complete.
        for (int i = 0; (i < 5) && ([downloadTaskTestHelper.delegateCallOrder count] != 3); i++) {
            [downloadTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        }
        ASSERT_EQ_MSG(3,
                      [downloadTaskTestHelper.delegateCallOrder count],
                      "FAILED: We should have received all three delegates call by now; got %@",
                      downloadTaskTestHelper.delegateCallOrder);

        // Make sure the download started.
        ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidWriteData,
                      [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                      "FAILED: didWriteData should be the first delegate to be called!");
        double fileSizeInMB = (double)downloadTaskTestHelper.totalBytesExpectedToWrite / 1024 / 1024;
        LOG_INFO("Downloaded file size is %fMB", fileSizeInMB);
        ASSERT_EQ_MSG(11, std::lround(fileSizeInMB), "FAILED: Expected download file size does not match!");

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
    TEST_METHOD(DownloadTaskWithURL_Failure) {
        NSURLSessionDownloadTaskTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskTestHelper alloc] init];
        NSURLSession* session = [downloadTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/status/401"];
        LOG_INFO("Establishing download task with url %@", url);
        NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
        [downloadTask resume];

        // Wait for download to complete.
        for (int i = 0; (i < 5) && ([downloadTaskTestHelper.delegateCallOrder count] != 2); i++) {
            [downloadTaskTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        }
        ASSERT_EQ_MSG(2,
                      [downloadTaskTestHelper.delegateCallOrder count],
                      "FAILED: We should have received all two delegates call by now; got %@",
                      downloadTaskTestHelper.delegateCallOrder);

        ASSERT_EQ_MSG(0, downloadTaskTestHelper.totalBytesExpectedToWrite, "FAILED: Expected download file size to be ZERO!");

        // Make sure the didFinishDownloadingToURL got called first. We would never get didWriteData delegate called as the download URL
        // we have passed in is invalid.
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
    TEST_METHOD(DownloadTaskWithURL_WithCompletionHandler) {
        __block THBooleanCondition* condition = [[THBooleanCondition alloc] init];
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
        ASSERT_TRUE([condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testDownloadTimeoutInSec]]);
        ASSERT_TRUE(downloadLocation || downloadResponse || downloadError);

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
    TEST_METHOD(DownloadTaskWithURL_WithCancelResume) {
        NSURLSessionDownloadTaskCancellingTestHelper* downloadTaskTestHelper = [[NSURLSessionDownloadTaskCancellingTestHelper alloc] init];
        NSURLSession* session = [downloadTaskTestHelper createSession];
        NSURL* url = [NSURL URLWithString:@"http://speedtest.ams01.softlayer.com/downloads/test500.zip"];
        LOG_INFO("Establishing download task with url %@", url);
        NSURLSessionDownloadTask* downloadTask = [session downloadTaskWithURL:url];
        [downloadTask resume];

        [downloadTaskTestHelper.downloadCancelledCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        ASSERT_TRUE_MSG([downloadTaskTestHelper.delegateCallOrder count] >= 1,
                        "FAILED: We should have received at least one delegate call by now; got %@",
                        downloadTaskTestHelper.delegateCallOrder);

        // Make sure the download started.
        ASSERT_EQ_MSG(NSURLSessionDownloadDelegateDidWriteData,
                      [(NSNumber*)[downloadTaskTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                      "FAILED: didWriteData should be the first delegate to be called!");
        double fileSizeInMB = (double)downloadTaskTestHelper.totalBytesExpectedToWrite / 1024 / 1024;
        LOG_INFO("Downloaded file size is %fMB", fileSizeInMB);
        ASSERT_EQ_MSG(500, std::lround(fileSizeInMB), "FAILED: Expected download file size does not match!");

        ASSERT_NE(nil, downloadTaskTestHelper.resumeData);

        // Make sure download has stopped.
        ASSERT_EQ(NSURLSessionTaskStateCanceling, downloadTask.state);

        // Isolation. Each helper is intended to be used only once.
        NSURLSessionDownloadTaskCancellingTestHelper* downloadTaskTestHelper2 = [[NSURLSessionDownloadTaskCancellingTestHelper alloc] init];
        NSURLSession* session2 = [downloadTaskTestHelper2 createSession];
        // Now resume the download
        LOG_INFO("Resuming download...");
        downloadTask = [session2 downloadTaskWithResumeData:downloadTaskTestHelper.resumeData];
        [downloadTask resume];

        [downloadTaskTestHelper2.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
        ASSERT_TRUE([downloadTaskTestHelper2.delegateCallOrder containsObject:@(NSURLSessionDownloadDelegateDidResumeAtOffset)]);
    }
};
