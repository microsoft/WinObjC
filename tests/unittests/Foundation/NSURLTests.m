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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <windows.h>

// Needed for dirname outside of Windows
#if !TARGET_OS_WIN32
#import <libgen.h>
#endif

void testNSURLMethod(SEL selector, NSURL* input, id argument, NSURL* expected) {
    NSURL* actual = [input performSelector:selector withObject:argument];
    ASSERT_OBJCEQ_MSG(expected, actual, "FAILED: expected != actual");
}

TEST(NSURL, NSURLTests) {
    NSURL* testURL = [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"];
    NSURL* testURL2 = [[NSURL alloc] initWithString:@"http://www.test.com/"];
    NSURL* testURL3 = [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"];
    NSURL* testURL4 = [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html?Foo#24"];
    NSURL* testURL5 = [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"];
    NSURL* testURL6 = [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"];
    NSURL* testURL7 = [[NSURL alloc] initWithString:@"http://www.test.com/.foo"];

    // URLByDeletingPathExtension tests
    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/.foo"]);

    // URLByDeletingLastPathComponent
    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/../"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL5,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com../?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    // URLByStandardizingPath
    testNSURLMethod(@selector(URLByStandardizingPath), testURL4, nil, [[NSURL alloc] initWithString:@"file:///home/index.html"]);

    // URLByStandardizingPath should only work on URLs with the file: scheme - all other schemes should return a copy
    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL6, nil, [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/.foo"]);

    // URLByAppendingPathExtension
    NSString* extension = @"txt";
    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL2,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL3,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL4,
                    extension,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL5,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL6,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL7,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.foo.txt"]);

    [testURL release];
    [testURL2 release];
    [testURL3 release];
    [testURL4 release];
    [testURL5 release];
    [testURL6 release];
    [testURL7 release];
}

TEST(NSURL, StandardizedURL) {
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo"], nil, [NSURL URLWithString:@"/tmp/foo"]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/.."], nil, [NSURL URLWithString:@"/tmp"]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/../.."], nil, [NSURL URLWithString:@""]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/../../.."], nil, [NSURL URLWithString:@""]);
    testNSURLMethod(@selector(standardizedURL),
                    [NSURL URLWithString:@"file://~/home/../home/./index.txt?Foo#24"],
                    nil,
                    [NSURL URLWithString:@"file://~/home/index.txt?Foo#24"]);
}

TEST(NSURL, URLByAppendingPathComponent) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"."];
    NSURL* newFileURL = [fileURL URLByAppendingPathComponent:@"Hello.txt"];
    ASSERT_TRUE([newFileURL isFileURL]);

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    fileURLString = [fileURLString stringByAppendingString:@"Hello.txt"];
    ASSERT_OBJCEQ(fileURLString, newFileURLString);

    // Appending "" should just add a slash
    newFileURL = [newFileURL URLByAppendingPathComponent:@""];
    fileURLString = [fileURLString stringByAppendingString:@"/"];
    newFileURLString = [newFileURL absoluteString];
    ASSERT_OBJCEQ(fileURLString, newFileURLString);

    // But only once
    newFileURL = [newFileURL URLByAppendingPathComponent:@""];
    newFileURLString = [newFileURL absoluteString];
    ASSERT_OBJCEQ(fileURLString, newFileURLString);
}

TEST(NSURL, URLByAppendingPathExtension) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"usr"];
    NSURL* newFileURL = [fileURL URLByAppendingPathExtension:@"World.txt"];
    ASSERT_TRUE_MSG([newFileURL isFileURL], "The passed URL should be a file URL type");

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    fileURLString = [fileURLString stringByAppendingString:@".World.txt"];
    ASSERT_OBJCEQ_MSG(fileURLString, newFileURLString, "File URLs do not match!");
}

TEST(NSURL, CheckResourceIsReachable) {
    NSFileManager* manager = [NSFileManager defaultManager];
    NSString* originalPath = [manager currentDirectoryPath];
    // construct target URL using current directory and relative URL
    // get test startup full path
    wchar_t startUpPath[_MAX_PATH];
    auto fullPath = GetCurrentTestDirectory();
    std::mbstowcs(startUpPath, fullPath.c_str(), _MAX_PATH);

// File systems differ between platforms - Windows needs separate handling for drive character, etc
#if TARGET_OS_WIN32
    // construct the start up dir
    wchar_t drive[_MAX_DRIVE];
    wchar_t dir[_MAX_DIR];
    ASSERT_TRUE(::_wsplitpath_s(startUpPath, drive, _countof(drive), dir, _countof(dir), nullptr, 0, nullptr, 0) == 0);
    ASSERT_TRUE(::_wmakepath_s(startUpPath, _countof(startUpPath), drive, dir, L"", L"") == 0);

    // change current dir to app start up path
    ASSERT_TRUE(SetCurrentDirectoryW(startUpPath) != 0);
#else
    char tempBuffer[_MAX_PATH];
    wcstombs(tempBuffer, startUpPath, _MAX_PATH);

    ASSERT_TRUE(chdir(dirname(tempBuffer)) == 0);
#endif

    NSURL* baseURL = [NSURL fileURLWithPath:[manager currentDirectoryPath]];
    NSURL* targetURL = [NSURL URLWithString:@"data/NSFileManagerUT.txt" relativeToURL:baseURL];
    ASSERT_TRUE_MSG([targetURL checkResourceIsReachableAndReturnError:nullptr], "The target URL %@ exists", targetURL);

    NSURL* targetURLNonExist = [NSURL URLWithString:@"data/foo.txt" relativeToURL:baseURL];
    ASSERT_FALSE_MSG([targetURLNonExist checkResourceIsReachableAndReturnError:nullptr],
                     "The target %@URL does not exist",
                     targetURLNonExist);
    ASSERT_TRUE([manager changeCurrentDirectoryPath:originalPath]);
}

TEST(NSURL, GetFileSystemRepresentation) {
    NSURL* url = [NSURL fileURLWithPath:@"Hello.txt"];
    ASSERT_OBJCNE(url, nil);

    size_t pathMax = 4096;

    char resultPath[pathMax];
    ASSERT_TRUE([url getFileSystemRepresentation:resultPath maxLength:pathMax]);

    char baseResultPath[pathMax];
    ASSERT_TRUE([url.baseURL getFileSystemRepresentation:baseResultPath maxLength:pathMax]);
    NSString* expectedPath = [NSString stringWithFormat:@"%s/Hello.txt", baseResultPath];
    NSString* nsResultPath = [NSString stringWithFormat:@"%s", resultPath];
    ASSERT_OBJCEQ(expectedPath, nsResultPath);
}

TEST(NSURL, Port) {
    ASSERT_OBJCEQ(nil, [NSURL URLWithString:@"http://www.foo.com"].port);
    ASSERT_OBJCEQ(@5500, [NSURL URLWithString:@"http://www.foo.com:5500"].port);
}

TEST(NSURL, Copy) {
    NSURL* url = [NSURL URLWithString:@"http://localhost/home/home/../index.txt?Foo#24"];
    NSURL* urlCopy = [[url copy] autorelease];

    ASSERT_OBJCEQ(url, urlCopy);
}

TEST(NSURL, BridgedCast) {
    {
        CFURLRef url = CFURLCreateWithString(kCFAllocatorDefault, CFSTR("http://www.foo.com/index.txt?Foo#24"), nullptr);
        ASSERT_OBJCEQ([NSURL URLWithString:@"http://www.foo.com/index.txt?Foo#24"], (__bridge NSURL*)url);
        CFRelease(url);
    }

    {
        NSURL* url = [NSURL fileURLWithPath:@"Hello.txt"];
        CFURLRef expected = CFURLCreateWithFileSystemPath(kCFAllocatorDefault, CFSTR("Hello.txt"), kCFURLWindowsPathStyle, false);
        ASSERT_EQ(kCFCompareEqualTo,
                  CFStringCompare(CFURLGetString(expected), CFURLGetString((__bridge CFURLRef)url), static_cast<CFStringCompareFlags>(0)));
        CFRelease(expected);
    }
}

TEST(NSURL, NonLatin) {
    NSString* pathAsString = @"/temp/hello/world/中文/你好.txt";
    NSURL* pathAsURL = [NSURL fileURLWithPath:pathAsString];
    ASSERT_OBJCEQ(pathAsString, pathAsURL.path);
}

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
        self->_condition = [NSCondition new];
        self->_queue = dispatch_queue_create("NSURLConnectionDelegateCallOrder", NULL);
        self->_delegateCallOrder = [NSMutableArray new];
    }
    return self;
}

- (NSURLConnection*)_createConnectionWithRequest:(NSString*)URLString {
    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:URLString]];
    NSURLConnection* connection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:NO];
    return connection;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    // ASSERT_TRUE_MSG(false, "This superclass version should never be called.");
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
        self->_operationQueue = [NSOperationQueue new];
    }
    return self;
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    NSURLConnection* connection = [self _createConnectionWithRequest:URLString];
    [connection setDelegateQueue:_operationQueue];
    // [connection setDelegateQueue:[NSOperationQueue new]];
    // [connection setDelegateQueue:nil];
    // [connection scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    [connection start];
    [connection setDelegateQueue:[NSOperationQueue new]];
    return connection;
}

@end

// Subclass of NSURLConnectionHelper that starts its connection on a separate thread's run loop.
@interface NSURLConnectionTestHelper_RunLoop : NSURLConnectionTestHelper
@property BOOL isStopped;
@property (retain) NSThread* thread;
- (void)doNothing;
- (void)spinRunLoop;
@end

@implementation NSURLConnectionTestHelper_RunLoop

- (instancetype)init {
    if (self = [super init]) {
        self->_thread = [[NSThread alloc] initWithTarget:self selector:@selector(spinRunLoop) object:nil];
        [self->_thread start];
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
        NSRunLoop* loop = [NSRunLoop currentRunLoop];

        NSTimer* timer = [NSTimer timerWithTimeInterval:0.1 target:self selector:@selector(doNothing) userInfo:nil repeats:YES];
        [loop addTimer:timer forMode:NSDefaultRunLoopMode];

        while (!_isStopped) {
            @autoreleasepool {
                [loop runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
            }
        }
    }
}

- (NSURLConnection*)createAndStartConnectionWithRequest:(NSString*)URLString {
    NSURLConnection* connection = [self _createConnectionWithRequest:URLString];
    [connection performSelector:@selector(start) onThread:_thread withObject:nil waitUntilDone:NO];
    return connection;
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
        [connectionTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:3]];
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
        [connectionTestHelper.condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:3]];
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

TEST(NSURLExperimental, RequestWithURL_OperationQueue) {
    _testRequestWithURL([NSURLConnectionTestHelper_OperationQueue new]);
}
