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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <Helpers/TestHelpers.h>
#import <map>
#import <random>

typedef NS_ENUM(NSInteger, NSURLConnectionDelegateType) {
    NSURLConnectionDelegateDidReceiveResponse,
    NSURLConnectionDelegateDidReceiveData,
    NSURLConnectionDelegateDidSendBodyData,
    NSURLConnectionDelegateDidFinishLoading,
    NSURLConnectionDelegateDidFailWithError
};

// Abstract wrapper around a NSURLConnection that signals a condition when a callback is received.
// Do not use this class directly - instantiate one of the subclasses instead
@interface NSURLConnectionTestHelper : NSObject <NSURLConnectionDelegate>
@property (retain) NSCondition* doneCondition;
@property BOOL done;

@property (assign) dispatch_queue_t queue;
@property (retain) NSMutableArray* delegateCallOrder;
@property (copy) NSURLResponse* response;
@property (copy) NSMutableData* data;
@property NSInteger totalBytesWritten;
@property NSInteger totalBytesExpectedToWrite;
@property (copy) NSError* error;

- (instancetype)init;
- (NSURLConnection*)createAndStartConnectionWithRequest:(NSURLRequest*)request;

@end

@implementation NSURLConnectionTestHelper
- (instancetype)init {
    if (self = [super init]) {
        _doneCondition = [NSCondition new];
        _queue = dispatch_queue_create("NSURLConnectionDelegateCallOrder", NULL);
        _delegateCallOrder = [NSMutableArray new];
        _data = [NSMutableData new];
    }
    return self;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    ASSERT_TRUE_MSG(false, "This superclass version should never be called.");
    return nil;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:@(NSURLConnectionDelegateDidReceiveResponse)];
    });
    self.response = response;
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:@(NSURLConnectionDelegateDidReceiveData)];
    });
    [self.data appendData:data];
}

- (void)connection:(NSURLConnection*)connection
              didSendBodyData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:@(NSURLConnectionDelegateDidSendBodyData)];
    });

    LOG_INFO("Wrote: %ld bytes; Total written: %ld bytes; Expected total to write: %ld bytes",
             bytesWritten,
             totalBytesWritten,
             totalBytesExpectedToWrite);

    _totalBytesWritten = totalBytesWritten;
    _totalBytesExpectedToWrite = totalBytesExpectedToWrite;
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:@(NSURLConnectionDelegateDidFailWithError)];
    });

    [self.doneCondition lock];
    self.error = e;
    self.done = YES;
    [self.doneCondition signal];
    [self.doneCondition unlock];
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection {
    dispatch_sync(self.queue, ^{
        [self.delegateCallOrder addObject:@(NSURLConnectionDelegateDidFinishLoading)];
    });

    [self.doneCondition lock];
    self.done = YES;
    [self.doneCondition signal];
    [self.doneCondition unlock];
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
        // This class cannot handle out-of-order delegate callbacks. Force all delegate callbacks to be serialized.
        _operationQueue.maxConcurrentOperationCount = 1;
    }
    return self;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSURLRequest*)request {
    NSURLConnection* connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
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

- (void)connection:(NSURLConnection*)connection
              didSendBodyData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connection:connection
                  didSendBodyData:bytesWritten
                totalBytesWritten:totalBytesWritten
        totalBytesExpectedToWrite:totalBytesExpectedToWrite];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connection:connection didFailWithError:e];
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection {
    EXPECT_TRUE([_operationQueue isEqual:[NSOperationQueue currentQueue]]);
    [super connectionDidFinishLoading:connection];
}

@end

// Subclass of NSURLConnectionHelper that starts its connection on a separate thread's run loop.
@interface NSURLConnectionTestHelper_RunLoop : NSURLConnectionTestHelper
@property BOOL isStopped;
@property (retain) THRunLoopSpinner* spinner;
@end

@implementation NSURLConnectionTestHelper_RunLoop

- (instancetype)init {
    if (self = [super init]) {
        _spinner = [THRunLoopSpinner new];
    }
    return self;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSURLRequest*)request {
    NSURLConnection* connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
    [_spinner scheduleAndAwaitBlock:^{
        [connection start];
    }];
    return connection;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    EXPECT_TRUE([_spinner.runLoop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didReceiveResponse:response];
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    EXPECT_TRUE([_spinner.runLoop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didReceiveData:data];
}

- (void)connection:(NSURLConnection*)connection
              didSendBodyData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite {
    EXPECT_TRUE([_spinner.runLoop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection
                  didSendBodyData:bytesWritten
                totalBytesWritten:totalBytesWritten
        totalBytesExpectedToWrite:totalBytesExpectedToWrite];
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    EXPECT_TRUE([_spinner.runLoop isEqual:[NSRunLoop currentRunLoop]]);
    [super connection:connection didFailWithError:e];
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection {
    EXPECT_TRUE([_spinner.runLoop isEqual:[NSRunLoop currentRunLoop]]);
    [super connectionDidFinishLoading:connection];
}

@end

// Subclass of NSURLConnectionHelper that starts its connection on a multiple separate threads' run loops.
@interface NSURLConnectionTestHelper_MultiRunLoop : NSURLConnectionTestHelper
@property BOOL isStopped;
@property (retain) NSMutableArray<NSThread*>* threads;
@property (retain) NSMutableArray<NSRunLoop*>* loops;
@property (retain) NSMutableArray<THRunLoopSpinner*>* spinners;

// Callback objects (request, response, data...) -> NSMutableSet<NSRunLoop>
@property (retain) NSMapTable<id, NSMutableSet<NSRunLoop*>*>* callbacksFromLoops;
@end

@implementation NSURLConnectionTestHelper_MultiRunLoop

- (instancetype)init {
    if (self = [super init]) {
        _loops = [NSMutableArray<NSRunLoop*> new];
        _spinners = [NSMutableArray<THRunLoopSpinner*> new];

        for (size_t i = 0; i < 3; ++i) {
            THRunLoopSpinner* spinner = [THRunLoopSpinner new];
            [_loops addObject:spinner.runLoop];
            [_spinners addObject:spinner];
        }

        _callbacksFromLoops = [NSMapTable<id, NSMutableSet<NSRunLoop*>*> mapTableWithKeyOptions:NSMapTableObjectPointerPersonality
                                                                                   valueOptions:NSMapTableStrongMemory];
    }
    return self;
}

- (BOOL)_allRunLoopsHaveCalledBackWith:(id)callbackObject {
    @synchronized(_callbacksFromLoops) {
        NSMutableSet<NSRunLoop*>* loopsThatHaveCalledBack =
            static_cast<NSMutableSet<NSRunLoop*>*>([_callbacksFromLoops objectForKey:callbackObject]);

        if (!loopsThatHaveCalledBack) {
            loopsThatHaveCalledBack = [NSMutableSet<NSRunLoop*> new];
            [_callbacksFromLoops setObject:loopsThatHaveCalledBack forKey:callbackObject];
        }

        [loopsThatHaveCalledBack addObject:[NSRunLoop currentRunLoop]];

        return loopsThatHaveCalledBack.count == _loops.count;
    }
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSURLRequest*)request {
    NSURLConnection* connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];

    for (NSRunLoop* runLoop : _loops) {
        [connection scheduleInRunLoop:runLoop forMode:NSDefaultRunLoopMode];
    }
    [connection start];
    return connection;
}

- (void)connection:(NSURLConnection*)connection didReceiveResponse:(NSURLResponse*)response {
    EXPECT_TRUE([_loops containsObject:[NSRunLoop currentRunLoop]]);

    if ([self _allRunLoopsHaveCalledBackWith:response]) {
        [super connection:connection didReceiveResponse:response];
    }
}

- (void)connection:(NSURLConnection*)connection didReceiveData:(nonnull NSData*)data {
    EXPECT_TRUE([_loops containsObject:[NSRunLoop currentRunLoop]]);

    if ([self _allRunLoopsHaveCalledBackWith:data]) {
        [super connection:connection didReceiveData:data];
    }
}

- (void)connection:(NSURLConnection*)connection
              didSendBodyData:(NSInteger)bytesWritten
            totalBytesWritten:(NSInteger)totalBytesWritten
    totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite {
    EXPECT_TRUE([_loops containsObject:[NSRunLoop currentRunLoop]]);

    // _allRunLoopsHaveCalledBackWith: uses object pointer equality, but this callback has no object
    // reuse the same NSNumber
    static NSMutableDictionary<NSNumber*, NSNumber*>* reusedNums = [NSMutableDictionary<NSNumber*, NSNumber*> new];

    NSNumber* num = @(bytesWritten);
    @synchronized(reusedNums) {
        if (NSNumber* reusedNum = [reusedNums objectForKey:num]) {
            num = reusedNum;
        } else {
            [reusedNums setObject:num forKey:num];
        }
    }

    if ([self _allRunLoopsHaveCalledBackWith:num]) {
        [super connection:connection
                      didSendBodyData:bytesWritten
                    totalBytesWritten:totalBytesWritten
            totalBytesExpectedToWrite:totalBytesExpectedToWrite];
    }
}

- (void)connection:(NSURLConnection*)connection didFailWithError:(NSError*)e {
    EXPECT_TRUE([_loops containsObject:[NSRunLoop currentRunLoop]]);

    if ([self _allRunLoopsHaveCalledBackWith:e]) {
        [super connection:connection didFailWithError:e];
    }
}

- (void)connectionDidFinishLoading:(NSURLConnection*)connection {
    EXPECT_TRUE([_loops containsObject:[NSRunLoop currentRunLoop]]);

    if ([self _allRunLoopsHaveCalledBackWith:connection]) {
        [super connectionDidFinishLoading:connection];
    }
}

@end

// Test to verify a request can be successfully made and a valid response and data is received.
static void _testRequestWithURL(NSURLConnectionTestHelper* connectionTestHelper) {
    NSString* urlString = @"https://httpbin.org/cookies/set?winobjc=awesome";
    LOG_INFO("Establishing download task with url %@", urlString);
    NSURLConnection* connection =
        [connectionTestHelper createAndStartConnectionWithRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:urlString]]];

    // Wait for data.
    [connectionTestHelper.doneCondition lock];
    for (int i = 0; (i < 5) && (!connectionTestHelper.done); ++i) {
        [connectionTestHelper.doneCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
    }
    ASSERT_EQ_MSG(3, [connectionTestHelper.delegateCallOrder count], "FAILED: We should have received 3 delegate calls by now!");
    [connectionTestHelper.doneCondition unlock];

    // Make sure we received a response.
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidReceiveResponse) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:0]],
                    "FAILED: didReceiveResponse should be the 1st delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.response != nil), "FAILED: Response cannot be empty!");

    NSURLResponse* response = connectionTestHelper.response;
    ASSERT_TRUE_MSG([response isKindOfClass:[NSHTTPURLResponse class]], "FAILED: Response should be of kind NSHTTPURLResponse class!");

    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
    LOG_INFO("Received HTTP response headers: %d", [httpResponse allHeaderFields]);

    // Make sure we received data.
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidReceiveData) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:1]],
                    "FAILED: didReceiveData should be the 2nd delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.data != nil), "FAILED: We should have received some data!");
    LOG_INFO("Received data: %@", [[NSString alloc] initWithData:connectionTestHelper.data encoding:NSUTF8StringEncoding]);

    // Make sure we received a didFinishLoading callback
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidFinishLoading) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:2]],
                    "FAILED: didReceiveData should be the 3rd delegate to be called!");

    // Make sure there was no error.
    ASSERT_TRUE_MSG((connectionTestHelper.error == nil), "FAILED: Connection returned error %@!", connectionTestHelper.error);
}

// Test to verify a request can be successfully made but no data was received and a valid response error code was received.
static void _testRequestWithURL_Failure(NSURLConnectionTestHelper* connectionTestHelper) {
    NSString* urlString = @"https://httpbin.org/status/404";
    LOG_INFO("Establishing download task with url %@", urlString);
    NSURLConnection* connection =
        [connectionTestHelper createAndStartConnectionWithRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:urlString]]];

    // Wait for a response.
    [connectionTestHelper.doneCondition lock];
    for (int i = 0; (i < 5) && (!connectionTestHelper.done); ++i) {
        [connectionTestHelper.doneCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
    }
    ASSERT_EQ_MSG(2, [connectionTestHelper.delegateCallOrder count], "FAILED: We should have received 2 delegate calls by now!");
    [connectionTestHelper.doneCondition unlock];

    // Make sure we received a response.
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidReceiveResponse) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:0]],
                    "FAILED: didReceiveResponse should be the 1st delegate to be called!");
    ASSERT_TRUE_MSG((connectionTestHelper.response != nil), "FAILED: Response cannot be empty!");

    NSURLResponse* response = connectionTestHelper.response;
    ASSERT_TRUE_MSG([response isKindOfClass:[NSHTTPURLResponse class]], "FAILED: Response should be of kind NSHTTPURLResponse class!");

    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(404, [httpResponse statusCode], "FAILED: HTTP status 404 was expected!");

    // Make sure we received a didFinishLoading callback
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidFinishLoading) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:1]],
                    "FAILED: didReceiveData should be the 2nd delegate to be called!");

    // Make sure we did not receive any data.
    ASSERT_TRUE_MSG((connectionTestHelper.data.length == 0), "FAILED: We should not have received any data!");

    // Make sure there was no error.
    ASSERT_TRUE_MSG((connectionTestHelper.error == nil), "FAILED: Connection returned error %@!", connectionTestHelper.error);
}

static void _testRequestWithURL_Post(NSURLConnectionTestHelper* connectionTestHelper, bool useStream) {
    NSString* urlString = @"https://httpbin.org/post";
    LOG_INFO("Establishing upload task with url %@", urlString);

    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:urlString]];

    // Generate a random alphanumeric string to use in the body
    static const std::string alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::vector<unsigned char> data((1 << 15) + 1);
    std::default_random_engine engine;
    engine.seed(2);
    std::uniform_int_distribution<> distribution(0, alphanumeric.length() - 1);
    std::generate(data.begin(), data.end(), [&distribution, &engine] { return alphanumeric[distribution(engine)]; });

    NSData* nsData = [NSData dataWithBytesNoCopy:data.data() length:data.size() freeWhenDone:NO];

    if (useStream) {
        request.HTTPBodyStream = [NSInputStream inputStreamWithData:nsData];
    } else {
        request.HTTPBody = nsData;
    }
    request.HTTPMethod = @"POST";
    [request setValue:[NSString stringWithFormat:@"%lu", data.size()] forHTTPHeaderField:@"Content-Length"];

    // Start the connection
    NSURLConnection* connection = [connectionTestHelper createAndStartConnectionWithRequest:request];

    // Wait for the connection to finish
    [connectionTestHelper.doneCondition lock];
    for (int i = 0; (i < 5) && (!connectionTestHelper.done); ++i) {
        [connectionTestHelper.doneCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:c_testTimeoutInSec]];
    }
    ASSERT_LE_MSG(4, [connectionTestHelper.delegateCallOrder count], "FAILED: We should have received 4 or more delegate calls by now!");
    [connectionTestHelper.doneCondition unlock];

    size_t index = 0;

    // Should have received a number of didSendBodyData callbacks
    for (; (index < [connectionTestHelper.delegateCallOrder count]) &&
           ([[connectionTestHelper.delegateCallOrder objectAtIndex:index] isEqual:@(NSURLConnectionDelegateDidSendBodyData)]);
         ++index) {
    }
    ASSERT_LT_MSG(0, index, "FAILED: Should have received one or more didSendBodyData calls.");
    ASSERT_EQ(data.size(), connectionTestHelper.totalBytesWritten);
    ASSERT_GE(data.size(), connectionTestHelper.totalBytesExpectedToWrite);

    // Make sure we received a response.
    ASSERT_TRUE_MSG([@(NSURLConnectionDelegateDidReceiveResponse) isEqual:[connectionTestHelper.delegateCallOrder objectAtIndex:index]],
                    "FAILED: didReceiveResponse should be the 1st delegate to be called after sending body data!");
    ASSERT_TRUE_MSG((connectionTestHelper.response != nil), "FAILED: Response cannot be empty!");

    NSURLResponse* response = connectionTestHelper.response;
    ASSERT_TRUE_MSG([response isKindOfClass:[NSHTTPURLResponse class]], "FAILED: Response should be of kind NSHTTPURLResponse class!");

    NSHTTPURLResponse* httpResponse = (NSHTTPURLResponse*)response;
    LOG_INFO("Received HTTP response status: %ld", [httpResponse statusCode]);
    ASSERT_EQ_MSG(200, [httpResponse statusCode], "FAILED: HTTP status 200 expected!");
    LOG_INFO("Received HTTP response headers: %d", [httpResponse allHeaderFields]);

    // Should have received a number of didReceiveData callbacks
    size_t receivedResponseIndex = index++;
    for (; (index < [connectionTestHelper.delegateCallOrder count]) &&
           ([[connectionTestHelper.delegateCallOrder objectAtIndex:index] isEqual:@(NSURLConnectionDelegateDidReceiveData)]);
         ++index) {
    }
    ASSERT_LT_MSG(receivedResponseIndex, index, "FAILED: Should have received one or more didReceiveData calls.");

    // Should have received a didFinishLoading callback last
    ASSERT_TRUE_MSG([[connectionTestHelper.delegateCallOrder objectAtIndex:index] isEqual:@(NSURLConnectionDelegateDidFinishLoading)] &&
                        (index == [connectionTestHelper.delegateCallOrder count] - 1),
                    "FAILED: didFinishLoading should be the last delegate to be called!");

    // The returned data should contain the posted body
    ASSERT_TRUE_MSG((connectionTestHelper.data != nil), "FAILED: We should have received some data!");
    NSRange rangeOfPostedData =
        [connectionTestHelper.data rangeOfData:nsData options:0 range:NSMakeRange(0, connectionTestHelper.data.length)];
    ASSERT_NE_MSG(NSNotFound, rangeOfPostedData.location, "FAILED: Returned data should contain the posted data.");

    // Make sure there was no error.
    ASSERT_TRUE_MSG((connectionTestHelper.error == nil), "FAILED: Connection returned error %@!", connectionTestHelper.error);
}

class NSURLConnectionTests {
public:
    BEGIN_TEST_CLASS(NSURLConnectionTests)
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

    TEST_CLASS_CLEANUP(NSURLClassCleanup) {
        return FunctionalTestCleanupUIApplication();
    }

    /**
     * Tests to verify a request can be successfully made and a valid response and data is received.
     */
    TEST_METHOD(RequestWithURL_OperationQueue) {
        _testRequestWithURL([NSURLConnectionTestHelper_OperationQueue new]);
    }

    TEST_METHOD(RequestWithURL_RunLoop) {
        _testRequestWithURL([NSURLConnectionTestHelper_RunLoop new]);
    }

    TEST_METHOD(RequestWithURL_MultiRunLoop) {
        _testRequestWithURL([NSURLConnectionTestHelper_MultiRunLoop new]);
    }

    /**
     * Tests to verify a request can be successfully made but no data was received and a valid response error code was received.
     */
    TEST_METHOD(RequestWithURL_Failure_OperationQueue) {
        _testRequestWithURL_Failure([NSURLConnectionTestHelper_OperationQueue new]);
    }

    TEST_METHOD(RequestWithURL_Failure_RunLoop) {
        _testRequestWithURL_Failure([NSURLConnectionTestHelper_RunLoop new]);
    }

    TEST_METHOD(RequestWithURL_Failure_MultiRunLoop) {
        _testRequestWithURL_Failure([NSURLConnectionTestHelper_RunLoop new]);
    }

    /**
     * Tests to verify a post request can be successfully made and a valid response and data is received.
     */
    TEST_METHOD(RequestWithURL_Post_OperationQueue) {
        _testRequestWithURL_Post([NSURLConnectionTestHelper_OperationQueue new], true);
        _testRequestWithURL_Post([NSURLConnectionTestHelper_OperationQueue new], false);
    }

    TEST_METHOD(RequestWithURL_Post_RunLoop) {
        _testRequestWithURL_Post([NSURLConnectionTestHelper_RunLoop new], true);
        _testRequestWithURL_Post([NSURLConnectionTestHelper_RunLoop new], false);
    }

    TEST_METHOD(RequestWithURL_Post_MultiRunLoop) {
        _testRequestWithURL_Post([NSURLConnectionTestHelper_MultiRunLoop new], true);
        _testRequestWithURL_Post([NSURLConnectionTestHelper_MultiRunLoop new], false);
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