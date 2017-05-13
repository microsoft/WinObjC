//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

typedef NS_ENUM(NSInteger, NSURLConnectionDelegateType) {
    NSURLConnectionDelegateDidReceiveResponse,
    NSURLConnectionDelegateDidReceiveData,
    NSURLConnectionDelegateDidFailWithError
};

// Abstract wrapper around a NSURLConnection that signals a condition when a callback is received.
// Do not use this class directly - instantiate one of the subclasses instead
@interface NSURLConnectionTestHelper : NSObject <NSURLConnectionDelegate>
@property (retain) NSCondition* condition;
@property (assign) dispatch_queue_t queue;
@property (retain) NSMutableArray* delegateCallOrder;
@property (copy) NSURLResponse* response;
@property (copy) NSData* data;
@property (copy) NSError* error;

- (instancetype)init;
- (NSURLConnection*)_createConnectionWithRequest:(NSString*)URLString;
- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString;

@end

@implementation NSURLConnectionTestHelper
- (instancetype)init {
    if (self = [super init]) {
        _condition = [NSCondition new];
        _queue = dispatch_queue_create("NSURLConnectionDelegateCallOrder", NULL);
        _delegateCallOrder = [NSMutableArray new];
    }
    return self;
}

- (NSURLConnection*)_createConnectionWithRequest:(NSString*)URLString {
    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:URLString]];
    NSURLConnection* connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
    return connection;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    ASSERT_TRUE_MSG(false, "This superclass version should never be called.");
    return nil;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLConnectionDelegateDidReceiveResponse]];
    });
    [self.condition lock];
    self.response = response;
    [self.condition signal];
    [self.condition unlock];
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLConnectionDelegateDidReceiveData]];
    });

    [self.condition lock];
    self.data = data;
    [self.condition signal];
    [self.condition unlock];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:[NSNumber numberWithInteger:NSURLConnectionDelegateDidFailWithError]];
    });

    [self.condition lock];
    self.error = e;
    [self.condition signal];
    [self.condition unlock];
}

@end

// Subclass of NSURLConnectionHelper that sets its connection on a delegate queue before starting it.
@interface NSURLConnectionTestHelper_OperationQueue : NSURLConnectionTestHelper
@property (retain) NSOperationQueue* operationQueue;
@end

@implementation NSURLConnectionTestHelper_OperationQueue
- (instancetype)init {
    if (self = [super init]) {
        _operationQueue = [NSOperationQueue new];
    }
    return self;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    NSURLConnection* connection = [self _createConnectionWithRequest:URLString];
    [connection setDelegateQueue:_operationQueue];
    [connection start];
    return connection;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connection:connection didReceiveResponse:response];
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connection:connection didReceiveData:data];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connection:connection didFailWithError:e];
}

@end

// Subclass of NSURLConnectionHelper that starts its connection on a separate thread's run loop.
@interface NSURLConnectionTestHelper_RunLoop : NSURLConnectionTestHelper
@property BOOL isStopped;
@property (retain) NSThread* thread;
- (void)doNothing;
- (void)spinRunLoop;
@property (assign) NSRunLoop* loop;
@end

@implementation NSURLConnectionTestHelper_RunLoop

- (instancetype)init {
    if (self = [super init]) {
        _thread = [[NSThread alloc] initWithTarget:self selector:@selector(spinRunLoop) object:nil];
        [_thread start];
    }
    return self;
}

- (void)dealloc {
    _isStopped = YES;
}

// Does nothing. Used to keep the run loop alive.
- (void)doNothing {
}

// Keeps the run loop on the current thread spinning.
- (void)spinRunLoop {
    @autoreleasepool {
        _loop = [NSRunLoop currentRunLoop];

        NSTimer* timer = [NSTimer timerWithTimeInterval:0.1 target:self selector:@selector(doNothing) userInfo:nil repeats:YES];
        [_loop addTimer:timer forMode:NSDefaultRunLoopMode];

        while (!_isStopped) {
            @autoreleasepool {
                [_loop runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
            }
        }
    }
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    NSURLConnection* connection = [self _createConnectionWithRequest:URLString];
    [connection performSelector:@selector(start) onThread:_thread withObject:nil waitUntilDone:NO];
    return connection;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    EXPECT_TRUE([_loop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didReceiveResponse:response];
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    EXPECT_TRUE([_loop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didReceiveData:data];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    EXPECT_TRUE([_loop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didFailWithError:e];
}

@end

// Test to verify a request can be successfully made and a valid response and data is received.
static void _testRequestWithURL(NSURLConnectionTestHelper* connectionTestHelper) {
    NSString* urlString = @"https://httpbin.org/cookies/set?winobjc=awesome";
    LOG_INFO("Establishing download task with url %@", urlString);
    NSURLConnection* connection = [connectionTestHelper createAndStartConnectionWithRequest:urlString];

    // Wait for data.
    [connectionTestHelper.condition lock];
    for (int i = 0; (i < 5) && ([connectionTestHelper.delegateCallOrder count] != 2); i++) {
        [connectionTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
    }
    ASSERT_EQ_MSG(2, [connectionTestHelper.delegateCallOrder count], "FAILED: We should have received two delegates call by now!");
    [connectionTestHelper.condition unlock];

    // Make sure we received a response.
    ASSERT_EQ_MSG(NSURLConnectionDelegateDidReceiveResponse,
                  [(NSNumber*)[connectionTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didReceiveResponse should be the first delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.response != nil), "FAILED: Response cannot be empty!");
    NSURLResponse* response = connectionTestHelper.response;
    if (![response isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
    LOG_INFO("Received HTTP response headers: %d", [httpResponse allHeaderFields]);

    // Make sure we received data.
    ASSERT_EQ_MSG(NSURLConnectionDelegateDidReceiveData,
                  [(NSNumber*)[connectionTestHelper.delegateCallOrder objectAtIndex:1] integerValue],
                  "FAILED: didReceiveData should be the first delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.data != nil), "FAILED: We should have received some data!");
    LOG_INFO("Received data: %@", [[NSString alloc] initWithData:connectionTestHelper.data encoding:NSUTF8StringEncoding]);

    // Make sure there was no error.
    ASSERT_TRUE_MSG((connectionTestHelper.error == nil), "FAILED: Connection returned error %@!", connectionTestHelper.error);
}

// Test to verify a request can be successfully made but no data was received and a valid response error code was received.
static void _testRequestWithURL_Failure(NSURLConnectionTestHelper* connectionTestHelper) {
    NSString* urlString = @"https://httpbin.org/status/404";
    LOG_INFO("Establishing download task with url %@", urlString);
    NSURLConnection* connection = [connectionTestHelper createAndStartConnectionWithRequest:urlString];

    // Wait for a response.
    [connectionTestHelper.condition lock];

    for (int i = 0; (i < 5) && ([connectionTestHelper.delegateCallOrder count] != 1); i++) {
        [connectionTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
    }
    ASSERT_EQ_MSG(1, [connectionTestHelper.delegateCallOrder count], "FAILED: We should have received one delegate call by now!");
    [connectionTestHelper.condition unlock];

    // Make sure we received a response.
    ASSERT_EQ_MSG(NSURLConnectionDelegateDidReceiveResponse,
                  [(NSNumber*)[connectionTestHelper.delegateCallOrder objectAtIndex:0] integerValue],
                  "FAILED: didReceiveResponse should be the first delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.response != nil), "FAILED: Response cannot be empty!");
    NSURLResponse* response = connectionTestHelper.response;
    if (![response isKindOfClass:[NSHTTPURLResponse class]]) {
        ASSERT_FALSE_MSG(true, "FAILED: Response should be of kind NSHTTPURLResponse class!");
    }
    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(404, [httpResponse statusCode], "FAILED: HTTP status 404 was expected!");

    // Make sure we did not receive any data.
    ASSERT_TRUE_MSG((connectionTestHelper.data == nil), "FAILED: We should not have received any data!");

    // Make sure there was no error.
    ASSERT_TRUE_MSG((connectionTestHelper.error == nil), "FAILED: Connection returned error %@!", connectionTestHelper.error);
}

class NSURLConnectionTests {
public:
    BEGIN_TEST_CLASS(NSURLConnectionTests)
    TEST_CLASS_PROPERTY(L"UAP:AppXManifest", L"NSURL.AppxManifest.xml")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(NSURLClassSetup) {
        return FunctionalTestSetupUIApplication();
    }

    TEST_CLASS_CLEANUP(NSURLClassCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    /**
     * Test to verify a request can be successfully made and a valid response and data is received, after setting a delegate queue.
     */
    TEST_METHOD(RequestWithURL_OperationQueue) {
        _testRequestWithURL([NSURLConnectionTestHelper_OperationQueue new]);
    }

    /**
     * Test to verify a request can be successfully made and a valid response and data is received, on a run loop.
     */
    TEST_METHOD(RequestWithURL_RunLoop) {
        _testRequestWithURL([NSURLConnectionTestHelper_RunLoop new]);
    }

    /**
     * Test to verify a request can be successfully made but no data was received and a valid response error code was received,
     * after setting a delegate queue.
     */
    TEST_METHOD(RequestWithURL_Failure_OperationQueue) {
        _testRequestWithURL_Failure([NSURLConnectionTestHelper_OperationQueue new]);
    }

    /**
     * Test to verify a request can be successfully made but no data was received and a valid response error code was received,
     * on a run loop.
     */
    TEST_METHOD(RequestWithURL_Failure_RunLoop) {
        _testRequestWithURL_Failure([NSURLConnectionTestHelper_RunLoop new]);
    }

    /**
     * Test to verify that [NSURLConnection sendSynchronousRequest] successfully completes.
     * This also implicitly tests [NSURLConnection sendAsynchronousRequest], as the synchronous version is built on top of it.
     */
    TEST_METHOD(SendSynchronousRequest) {
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?winobjc=awesome"];
        NSURLRequest* request = [NSURLRequest requestWithURL:url];
        NSURLResponse* response = nil;
        NSError* error = nil;

        NSData* data = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:&error];
        ASSERT_EQ(error, nil);
        ASSERT_NE(0, data.length);
    }

    /**
     Test to verify that [NSData dataWithContentsOfURL] successfully completes.
     */
    TEST_METHOD(NSDataWithContentsOfURL) {
        NSURL* url = [NSURL URLWithString:@"https://httpbin.org/cookies/set?winobjc=awesome"];
        NSData* data = [NSData dataWithContentsOfURL:url];
        ASSERT_NE(0, data.length);
    }
};