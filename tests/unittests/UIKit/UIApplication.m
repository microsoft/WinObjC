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

#include "gtest-api.h"
#include "UIKit/UIApplication.h"
#include "UWP/WindowsSystem.h"

// Mock launcher allowing us to spoof launchUriAsync and queryUriSupportAsync behavior
@interface MockWSLauncher : RTObject

// Mock methods
+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;

+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure;

// Invokes previously set success method, allowing us to spoof an app launch
+ (void)invokeLaunchSuccess:(NSNumber*)didLaunch;

// Invokes previously set failure method, allowing us to spoof an app launch
+ (void)invokeLaunchFailure:(NSError*)failure;

// Invokes previously set success method, allowing us to spoof a scheme handler query
+ (void)invokeQuerySuccess:(NSNumber*)status;

// Invokes previously set failure method, allowing us to spoof a scheme handler query
+ (void)invokeQueryFailure:(NSError*)failure;

// Waits on condition2 - used as a secondary condition to set up race condition tests
+ (void)waitForCondition2;

// Signals condition2 - used as a secondary condition to set up race condition tests
+ (void)signalCondition2;
@end

@implementation MockWSLauncher
static void (^_launchSuccessFunction)(BOOL) = nil;
static void (^_launchFailureFunction)(NSError*) = nil;
static void (^_querySuccessFunction)(WSLaunchQuerySupportStatus) = nil;
static void (^_queryFailureFunction)(NSError*) = nil;

// The MockWSLauncher internals are declared static as globals even though they are only accessed by class functions.
static NSCondition* s_condition;
static NSCondition* s_condition2;
static NSInteger s_count;
static BOOL s_launchReady;

+ (NSInteger)count {
    return s_count;
}

+ (void)setup {
    s_condition = [NSCondition new];
    s_condition2 = [NSCondition new];
    s_launchReady = NO;
    s_count = 0;
}

+ (void)cleanUp {
    Block_release(_launchSuccessFunction);
    Block_release(_launchFailureFunction);
    Block_release(_querySuccessFunction);
    Block_release(_queryFailureFunction);
    _launchSuccessFunction = nil;
    _launchFailureFunction = nil;
    _querySuccessFunction = nil;
    _queryFailureFunction = nil;
    [s_condition release];
    [s_condition2 release];
    s_condition = nil;
    s_condition2 = nil;
}

+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    [s_condition lock];
    if (!_launchSuccessFunction) {
        _launchSuccessFunction = Block_copy(success);
        _launchFailureFunction = Block_copy(failure);
    }

    s_launchReady = YES;
    [s_condition signal];
    [s_condition unlock];
}

+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure {
    [s_condition lock];
    if (!_querySuccessFunction) {
        _querySuccessFunction = Block_copy(success);
        _queryFailureFunction = Block_copy(failure);
    }

    s_launchReady = YES;
    [s_condition signal];
    [s_condition unlock];
}

+ (void)invokeLaunchSuccess:(NSNumber*)didLaunch {
    [s_condition lock];
    [self signalCondition2];
    while (!s_launchReady) {
        [s_condition wait];
    }

    s_launchReady = NO;
    s_count++;
    _launchSuccessFunction([didLaunch boolValue]);
    [s_condition unlock];
}

+ (void)invokeLaunchFailure:(NSError*)failure {
    [s_condition lock];
    [self signalCondition2];
    while (!s_launchReady) {
        [s_condition wait];
    }

    s_launchReady = NO;
    _launchFailureFunction(failure);
    [s_condition unlock];
}

+ (void)invokeQuerySuccess:(NSNumber*)status {
    [s_condition lock];
    [self signalCondition2];
    while (!s_launchReady) {
        [s_condition wait];
    }

    s_launchReady = NO;
    s_count++;
    _querySuccessFunction([status unsignedIntegerValue]);
    [s_condition unlock];
}

+ (void)invokeQueryFailure:(NSError*)failure {
    [s_condition lock];
    [self signalCondition2];
    while (!s_launchReady) {
        [s_condition wait];
    }

    s_launchReady = NO;
    _queryFailureFunction(failure);
    [s_condition unlock];
}

+ (void)waitForCondition2 {
    [s_condition2 lock];
    [s_condition2 wait];
    [s_condition2 unlock];
}

+ (void)signalCondition2 {
    [s_condition2 lock];
    [s_condition2 signal];
    [s_condition2 unlock];
}
@end

// Exposes internal methods on UIApplication so we can pass in a mock WSLauncher
@interface UIApplication (TestPrivate)
- (instancetype)_initForTestingWithLauncher:(Class)launcher;
@end

// On a separate thread, delivers launch results
void invokeLaunchSuccess(BOOL didLaunch) {
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class]
                                               selector:@selector(invokeLaunchSuccess:)
                                                 object:[NSNumber numberWithBool:didLaunch]];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForCondition2];
}

// On a separate thread, delivers launch failure
void invokeLaunchFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeLaunchFailure:) object:testError];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForCondition2];
}

// On a separate thread, delivers query results
void invokeQuerySuccess(unsigned int status) {
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class]
                                               selector:@selector(invokeQuerySuccess:)
                                                 object:[NSNumber numberWithUnsignedInteger:status]];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForCondition2];
}

// On a separate thread, delivers query failure
void invokeQueryFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeQueryFailure:) object:testError];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForCondition2];
}

TEST(UIKit, UIApplicationOpenURLSuccess) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeLaunchSuccess(YES);
    BOOL result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(YES, result, "openURL returned unexpected result");

    invokeLaunchSuccess(NO);
    result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(NO, result, "openURL returned unexpected result");

    [MockWSLauncher cleanUp];
}

TEST(UIKit, UIApplicationOpenURLFailure) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeLaunchFailure();
    BOOL result;
    ASSERT_NO_THROW(result = [testApplication openURL:testURL]);
    ASSERT_EQ_MSG(NO, result, "openURL returned unexpected result");

    [MockWSLauncher cleanUp];
}

// Verify that two successive calls will each result in a call to the success function
TEST(UIKit, UIApplicationOpenURLDoubleCall) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeLaunchSuccess(YES);
    invokeLaunchSuccess(NO);

    BOOL result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(YES, result, "openURL returned unexpected result");
    ASSERT_EQ_MSG(1, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

    result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(NO, result, "openURL returned unexpected result");
    ASSERT_EQ_MSG(2, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

    [MockWSLauncher cleanUp];
}

TEST(UIKit, UIApplicationCanOpenURLSuccess) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeQuerySuccess(WSLaunchQuerySupportStatusAvailable);
    BOOL result = [testApplication canOpenURL:testURL];
    ASSERT_EQ_MSG(YES, result, "canOpenURL returned unexpected result");

    invokeQuerySuccess(WSLaunchQuerySupportStatusNotSupported);
    result = [testApplication canOpenURL:testURL];
    ASSERT_EQ_MSG(NO, result, "canOpenURL returned unexpected result");

    [MockWSLauncher cleanUp];
}

TEST(UIKit, UIApplicationCanOpenURLFailure) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeQueryFailure();
    BOOL result;
    ASSERT_NO_THROW(result = [testApplication canOpenURL:testURL]);
    ASSERT_EQ_MSG(NO, result, "canOpenURL returned unexpected result");

    [MockWSLauncher cleanUp];
}

// Verify that two successive calls will each result in a call to the success function
TEST(UIKit, UIApplicationCanOpenURLDoubleCall) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    invokeQuerySuccess(WSLaunchQuerySupportStatusAvailable);
    invokeQuerySuccess(WSLaunchQuerySupportStatusNotSupported);

    BOOL result = [testApplication canOpenURL:testURL];
    ASSERT_EQ_MSG(YES, result, "openURL returned unexpected result");
    ASSERT_EQ_MSG(1, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

    result = [testApplication canOpenURL:testURL];
    ASSERT_EQ_MSG(NO, result, "openURL returned unexpected result");
    ASSERT_EQ_MSG(2, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

    [MockWSLauncher cleanUp];
}