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

// Waits on TestCondition - used as a secondary condition to set up race condition tests
+ (void)waitForTestCondition;

// Signals TestCondition - used as a secondary condition to set up race condition tests
+ (void)waitForTestCondition;
@end

@implementation MockWSLauncher
static void (^_launchSuccessFunction)(BOOL) = nil;
static void (^_launchFailureFunction)(NSError*) = nil;
static void (^_querySuccessFunction)(WSLaunchQuerySupportStatus) = nil;
static void (^_queryFailureFunction)(NSError*) = nil;

// The MockWSLauncher internals are declared static as globals even though they are only accessed by class functions.
static NSCondition* s_launchCompleteCondition;
static NSCondition* s_queryCompleteCondition;
static NSCondition* s_testCondition;
static NSCondition* s_invokeLaunchCompleteCondition;
static NSInteger s_count;
static BOOL s_launchReady;

+ (NSInteger)count {
    return s_count;
}

+ (void)setup {
    s_launchCompleteCondition = [NSCondition new];
    s_queryCompleteCondition = [NSCondition new];
    s_testCondition = [NSCondition new];
    s_invokeLaunchCompleteCondition = [NSCondition new];
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
    [s_launchCompleteCondition lock];
    [s_launchCompleteCondition unlock];
    [s_queryCompleteCondition lock];
    [s_queryCompleteCondition unlock];
    [s_testCondition lock];
    [s_testCondition unlock];
    [s_invokeLaunchCompleteCondition lock];
    [s_invokeLaunchCompleteCondition unlock];
    [s_launchCompleteCondition release];
    [s_queryCompleteCondition release];
    [s_testCondition release];
    [s_invokeLaunchCompleteCondition release];
    s_launchCompleteCondition = nil;
    s_queryCompleteCondition = nil;
    s_testCondition = nil;
    s_invokeLaunchCompleteCondition = nil;
}

+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    [s_launchCompleteCondition lock];
    if (!_launchSuccessFunction) {
        _launchSuccessFunction = Block_copy(success);
        _launchFailureFunction = Block_copy(failure);
    }

    s_launchReady = YES;
    [s_launchCompleteCondition signal];
    [s_launchCompleteCondition unlock];
}

+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure {
    [s_queryCompleteCondition lock];
    if (!_querySuccessFunction) {
        _querySuccessFunction = Block_copy(success);
        _queryFailureFunction = Block_copy(failure);
    }

    s_launchReady = YES;
    [s_queryCompleteCondition signal];
    [s_queryCompleteCondition unlock];
}

+ (void)invokeLaunchSuccess:(NSNumber*)didLaunch {
    [s_launchCompleteCondition lock];
    [self signalTestCondition];
    while (!s_launchReady) {
        [s_launchCompleteCondition wait];
    }

    s_launchReady = NO;
    s_count++;
    _launchSuccessFunction([didLaunch boolValue]);
    [self signalInvokeLaunchCompleteCondition];
    [s_launchCompleteCondition unlock];
}

+ (void)invokeLaunchFailure:(NSError*)failure {
    [s_launchCompleteCondition lock];
    [self signalTestCondition];
    while (!s_launchReady) {
        [s_launchCompleteCondition wait];
    }

    s_launchReady = NO;
    _launchFailureFunction(failure);
    [self signalInvokeLaunchCompleteCondition];
    [s_launchCompleteCondition unlock];
}

+ (void)invokeQuerySuccess:(NSNumber*)status {
    [s_queryCompleteCondition lock];
    [self signalTestCondition];
    while (!s_launchReady) {
        [s_queryCompleteCondition wait];
    }

    s_launchReady = NO;
    s_count++;
    _querySuccessFunction([status unsignedIntegerValue]);
    [s_queryCompleteCondition unlock];
}

+ (void)invokeQueryFailure:(NSError*)failure {
    [s_queryCompleteCondition lock];
    [self signalTestCondition];
    while (!s_launchReady) {
        [s_queryCompleteCondition wait];
    }

    s_launchReady = NO;
    _queryFailureFunction(failure);
    [s_queryCompleteCondition unlock];
}

+ (void)waitForTestCondition {
    [s_testCondition lock];
    [s_testCondition wait];
    [s_testCondition unlock];
}

+ (void)signalTestCondition {
    [s_testCondition lock];
    [s_testCondition signal];
    [s_testCondition unlock];
}

+ (void)waitForInvokeLaunchCompleteCondition {
    [s_invokeLaunchCompleteCondition lock];
    [s_invokeLaunchCompleteCondition wait];
    [s_invokeLaunchCompleteCondition unlock];
}

+ (void)signalInvokeLaunchCompleteCondition {
    [s_invokeLaunchCompleteCondition lock];
    [s_invokeLaunchCompleteCondition signal];
    [s_invokeLaunchCompleteCondition unlock];
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
    [MockWSLauncher waitForTestCondition];
}

// On a separate thread, delivers launch failure
void invokeLaunchFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeLaunchFailure:) object:testError];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForTestCondition];
}

// On a separate thread, delivers query results
void invokeQuerySuccess(unsigned int status) {
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class]
                                               selector:@selector(invokeQuerySuccess:)
                                                 object:[NSNumber numberWithUnsignedInteger:status]];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForTestCondition];
}

// On a separate thread, delivers query failure
void invokeQueryFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeQueryFailure:) object:testError];
    [thread autorelease];
    [thread start];
    [MockWSLauncher waitForTestCondition];
}

TEST(UIKit, UIApplicationOpenURLSuccess) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    // Because [UIApplication openURL:] first checks if the URL to open is valid, setup test such that query returns success
    invokeQuerySuccess(WSLaunchQuerySupportStatusAvailable);
    // Now set up the success for the launch - this result is actually not verified in this test as the URL open happens
    // asynchronously.
    invokeLaunchSuccess(YES);
    BOOL result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(YES, result, "openURL returned unexpected result");
    // Because the actual URL step is asynchronous, wait for it to complete before proceeding to the next test
    [MockWSLauncher waitForInvokeLaunchCompleteCondition];

    [MockWSLauncher cleanUp];
}

TEST(UIKit, UIApplicationOpenURLFailure) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];
    NSURL* testURL = [NSURL URLWithString:@"http://www.bing.com/news"];

    // Because [UIApplication openURL:] first checks if the URL to open is valid, setup test such that query returns failure
    invokeQuerySuccess(WSLaunchQuerySupportStatusNotSupported);
    // There is no need to setup anything for launch as [UIApplication openURL:] will not invoke launch if the [UIApplication canOpenURL:]
    // fails.
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

    // For the first test setup setup query and launch to success
    invokeQuerySuccess(WSLaunchQuerySupportStatusAvailable);
    invokeLaunchSuccess(YES);
    // For the second test setup setup query to failure
    invokeQuerySuccess(WSLaunchQuerySupportStatusNotSupported);

    BOOL result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(YES, result, "openURL returned unexpected result");
    [MockWSLauncher waitForInvokeLaunchCompleteCondition];
    // Verify both query and launch got invoked.
    ASSERT_EQ_MSG(2, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

    result = [testApplication openURL:testURL];
    ASSERT_EQ_MSG(NO, result, "openURL returned unexpected result");
    // Verify only got invoked.
    ASSERT_EQ_MSG(3, [MockWSLauncher count], "openURL resulted in unexpected success function call count");

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

@interface MockResponder : UIResponder {
@public
    BOOL didAction;
    BOOL didActionFromSender;
    BOOL didActionFromSenderForEvent;
}

- (void)doAction;
- (void)doAction:(id)sender;
- (void)doAction:(id)sender forEvent:(UIEvent*)event;
@end

@implementation MockResponder
- (void)doAction {
    didAction = YES;
}

- (void)doAction:(id)sender {
    didActionFromSender = YES;
}

- (void)doAction:(id)sender forEvent:(UIEvent*)event {
    didActionFromSenderForEvent = YES;
}
@end

TEST(UIKit, UIApplicationSendAction) {
    [MockWSLauncher setup];
    UIApplication* testApplication = [[UIApplication alloc] _initForTestingWithLauncher:[MockWSLauncher class]];

    MockResponder* responder = [MockResponder new];
    EXPECT_TRUE([testApplication sendAction:@selector(doAction) to:responder from:nil forEvent:nil]);
    EXPECT_TRUE(responder->didAction);

    EXPECT_TRUE([testApplication sendAction:@selector(doAction:) to:responder from:nil forEvent:nil]);
    EXPECT_TRUE(responder->didActionFromSender);

    EXPECT_TRUE([testApplication sendAction:@selector(doAction:forEvent:) to:responder from:nil forEvent:nil]);
    EXPECT_TRUE(responder->didActionFromSenderForEvent);

    EXPECT_FALSE([testApplication sendAction:@selector(nonexistent) to:responder from:nil forEvent:nil]);

    [responder release];
    [MockWSLauncher cleanUp];
}