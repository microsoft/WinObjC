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
typedef wchar_t WCHAR;
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
@end
@implementation MockWSLauncher
static void (^_launchSuccessFunction)(BOOL) = nil;
static void (^_launchFailureFunction)(NSError*) = nil;
static void (^_querySuccessFunction)(WSLaunchQuerySupportStatus) = nil;
static void (^_queryFailureFunction)(NSError*) = nil;
NSCondition* _condition;
NSInteger _count;
BOOL _launchReady;

+ (NSInteger)count {
    return _count;
}

+ (void)initSingleton {
    _condition = [NSCondition new];
    _launchReady = NO;
    _count = 0;
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
    [_condition release];
}

+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    [_condition lock];
    if (_launchSuccessFunction == nil) {
        _launchSuccessFunction = Block_copy(success);
        _launchFailureFunction = Block_copy(failure);
    }

    _launchReady = YES;
    [_condition signal];
    [_condition unlock];

}

+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure {

    [_condition lock];
    if (_querySuccessFunction == nil) {
        _querySuccessFunction = Block_copy(success);
        _queryFailureFunction = Block_copy(failure);
    }

    _launchReady = YES;
    [_condition signal];
    [_condition unlock];
}

+ (void)invokeLaunchSuccess:(NSNumber*)didLaunch {
    [_condition lock];
    while (!_launchReady) {
        [_condition wait];
    }

    _launchReady = NO;
    _count++;
    [_condition unlock];
    _launchSuccessFunction([didLaunch boolValue]);
}

+ (void)invokeLaunchFailure:(NSError*)failure {
    [_condition lock];
    while (!_launchReady) {
        [_condition wait];
    }

    _launchReady = NO;
    [_condition unlock];
    _launchFailureFunction(failure);
}

+ (void)invokeQuerySuccess:(NSNumber*)status {
    [_condition lock];
    while (!_launchReady) {
        [_condition wait];
    }

    _launchReady = NO;
    _count++;
    [_condition unlock];
    _querySuccessFunction([status unsignedIntegerValue]);
}

+ (void)invokeQueryFailure:(NSError*)failure {
    [_condition lock];
    while (!_launchReady) {
        [_condition wait];
    }

    _launchReady = NO;
    [_condition unlock];
    _queryFailureFunction(failure);
}
@end

// Exposes internal methods on UIApplication so we can pass in a mock WSLauncher
@interface UIApplication (TestPrivate)
- (instancetype)_initForTestingWithLauncher:(Class)launcher;
@end

// On a separate thread, delivers launch results
void invokeLaunchSuccess(BOOL didLaunch) {
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeLaunchSuccess:) object:[NSNumber numberWithBool:didLaunch]];
    [thread autorelease];
    [thread start];
}

// On a separate thread, delivers launch failure
void invokeLaunchFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeLaunchFailure:) object:testError];
    [thread autorelease];
    [thread start];
}

// On a separate thread, delivers query results
void invokeQuerySuccess(unsigned int status) {
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeQuerySuccess:) object:[NSNumber numberWithUnsignedInteger:status]];
    [thread autorelease];
    [thread start];
}

// On a separate thread, delivers query failure
void invokeQueryFailure() {
    NSError* testError = [NSError errorWithDomain:@"test" code:1 userInfo:nil];
    NSThread* thread = [[NSThread alloc] initWithTarget:[MockWSLauncher class] selector:@selector(invokeQueryFailure:) object:testError];
    [thread autorelease];
    [thread start];
}

TEST(UIKit, UIApplicationOpenURLSuccess) {
    [MockWSLauncher initSingleton];
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
    [MockWSLauncher initSingleton];
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
    [MockWSLauncher initSingleton];
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
    [MockWSLauncher initSingleton];
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
    [MockWSLauncher initSingleton];
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
    [MockWSLauncher initSingleton];
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