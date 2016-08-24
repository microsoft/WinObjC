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

#import <Starboard/SmartTypes.h>
#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <future>
#import <windows.h>

@interface NSTimerTestObj : NSObject {
    NSCondition* _calledCondition;
    StrongId<id> _dummyVal;
}
@property (assign) BOOL called;
@property (assign) NSUInteger count;
@property (assign) NSUInteger maxCalls;
@end

@implementation NSTimerTestObj
- (instancetype)initWithValue:(BOOL)value count:(NSUInteger)count {
    if (self = [self initWithValue:value]) {
        _maxCalls = count;
    }

    return self;
}

- (instancetype)initWithValue:(BOOL)value {
    if (self = [super init]) {
        _calledCondition = [[NSCondition alloc] init];
        _called = value;
        _count = 0;
        _maxCalls = 0;
    }
    return self;
}

- (void)testFunction {
    _called = YES;
    _count++;
    if (_count >= _maxCalls) {
        [_calledCondition lock];
        [_calledCondition broadcast];
        [_calledCondition unlock];
    }
}

- (void)testFunctionWithDummyArg:(id)dummyVal {
    _called = YES;
    _count++;
    _dummyVal = dummyVal;
    if (_count >= _maxCalls) {
        [_calledCondition lock];
        [_calledCondition broadcast];
        [_calledCondition unlock];
    }
}

- (void)reset {
    // reset call count.
    _maxCalls = 0;
    _count = 0;
    _called = NO;
}

- (id)dummyVal {
    return _dummyVal;
}

- (BOOL)waitOnCalledConditionForInterval:(NSTimeInterval)interval {
    [_calledCondition lock];
    BOOL ret = [_calledCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:interval]];
    [_calledCondition unlock];
    return ret;
}

- (void)dealloc {
    [_calledCondition release];
    [super dealloc];
}

@end

TEST(NSTimer, NegativeTimeInterval) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO] autorelease];
    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:-5.0 target:testObj selector:@selector(testFunction) userInfo:nil repeats:YES];

    ASSERT_GE_MSG([timer timeInterval], 0., "FAILED:timeInterval should be non negative.");

    NSTimer* timer0 = [NSTimer scheduledTimerWithTimeInterval:0.0 target:testObj selector:@selector(testFunction) userInfo:nil repeats:YES];

    ASSERT_GE_MSG([timer timeInterval], 0., "FAILED:timeInterval should be non negative.");
}

TEST(NSTimer, ScheduledTimerWithTimeInterval) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO] autorelease];
    volatile long waitCompletion = 0;

    auto selectorCalledAsync = std::async(std::launch::async,
                                          [&waitCompletion, testObj]() {
                                              BOOL fooChanged = [testObj waitOnCalledConditionForInterval:15] && [testObj called];
                                              _InterlockedExchange(&waitCompletion, 1L);
                                              return fooChanged;
                                          });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:0.1 target:testObj selector:@selector(testFunction) userInfo:nil repeats:NO];
    ASSERT_TRUE_MSG(timer != nil, "FAILED: timer should not be nil.");

    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid before fire.");
    ASSERT_TRUE_MSG([timer userInfo] == nil, "FAILED: not expected userinfo.");
    ASSERT_EQ_MSG(0, [timer tolerance], "FAILED:  tolerance should be 0 by default.");

    for (;;) {
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (waitCompletion) {
            break;
        }
    }

    ASSERT_TRUE_MSG(![timer isValid], "FAILED: The timer should not be valid.");
    ASSERT_EQ_MSG(YES, selectorCalledAsync.get(), "FAILED: the scheduled timer did not call the method.");
}

TEST(NSTimer, ScheduledTimerWithTimeIntervalRepeat) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO count:5] autorelease];
    volatile long waitCompletion = 0;

    auto selectorCalledAsync = std::async(std::launch::async,
                                          [&waitCompletion, testObj]() {
                                              BOOL fooChanged = [testObj waitOnCalledConditionForInterval:15] && [testObj called];
                                              _InterlockedExchange(&waitCompletion, 1L);
                                              return fooChanged;
                                          });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:0.1 target:testObj selector:@selector(testFunction) userInfo:nil repeats:YES];
    ASSERT_TRUE_MSG(timer != nil, "FAILED: timer should not be nil.");

    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid before fire.");
    ASSERT_TRUE_MSG([timer userInfo] == nil, "FAILED: not expected userinfo.");
    ASSERT_EQ_MSG(0, [timer tolerance], "FAILED:  tolerance should be 0 by default.");

    for (;;) {
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (waitCompletion) {
            break;
        }
    }
    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid as it's a repeater.");
    [timer invalidate];
    ASSERT_TRUE_MSG(![timer isValid], "FAILED: The timer should not be valid after invalidation.");
    ASSERT_EQ_MSG(YES, selectorCalledAsync.get(), "FAILED: the scheduled timer did not call the method.");
}

TEST(NSTimer, ScheduledTimerWithTimeIntervalFireOnce) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO] autorelease];
    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:1 target:testObj selector:@selector(testFunction) userInfo:nil repeats:NO];

    ASSERT_TRUE_MSG(timer != nil, "FAILED: timer should not be nil.");

    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid before fire.");
    ASSERT_TRUE_MSG([timer userInfo] == nil, "FAILED: not expected userinfo.");
    ASSERT_EQ_MSG(0, [timer tolerance], "FAILED:  tolerance should be 0 by default.");

    [timer fire];
    ASSERT_EQ_MSG(NO, [timer isValid], "FAILED: timer should not valid.");
    ASSERT_EQ_MSG(YES, [testObj called], "FAILED: the object's method should be called.");
    ASSERT_EQ_MSG(1, [testObj count], "FAILED: the object's method should be called once only.");
}

TEST(NSTimer, ScheduledTimerWithTimeIntervalFireRepeat) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO count:5] autorelease];
    volatile long waitCompletion = 0;

    auto selectorCalledAsync = std::async(std::launch::async,
                                          [&waitCompletion, testObj]() {
                                              BOOL fooChanged = [testObj waitOnCalledConditionForInterval:15] && [testObj called];
                                              _InterlockedExchange(&waitCompletion, 1L);
                                              return fooChanged;
                                          });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:0.1 target:testObj selector:@selector(testFunction) userInfo:nil repeats:YES];
    ASSERT_TRUE_MSG(timer != nil, "FAILED: timer should not be nil.");

    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid before fire.");
    ASSERT_TRUE_MSG([timer userInfo] == nil, "FAILED: not expected userinfo.");
    ASSERT_EQ_MSG(0, [timer tolerance], "FAILED:  tolerance should be 0 by default.");

    for (;;) {
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (waitCompletion) {
            break;
        }
    }
    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid as it's a repeater.");
    ASSERT_EQ_MSG(YES, selectorCalledAsync.get(), "FAILED: the scheduled timer did not call the method.");

    // reset the object.
    [testObj reset];

    [timer fire];
    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid as it's a repeater.");
    ASSERT_TRUE_MSG([testObj called], "FAILED: The method should have been called.");
    ASSERT_TRUE_MSG([testObj count] > 0, "FAILED: The method should have been called.");

    [timer invalidate];
    ASSERT_TRUE_MSG(![timer isValid], "FAILED: The timer should not be valid after invalidation.");
}

TEST(NSTimer, ScheduledTimerWithTimeIntervalWithInvocation) {
    NSTimerTestObj* testObj = [[[NSTimerTestObj alloc] initWithValue:NO] autorelease];
    volatile long waitCompletion = 0;

    auto selectorCalledAsync = std::async(std::launch::async,
                                          [&waitCompletion, testObj]() {
                                              BOOL fooChanged = [testObj waitOnCalledConditionForInterval:15] && [testObj called];
                                              _InterlockedExchange(&waitCompletion, 1L);
                                              return fooChanged;
                                          });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    NSString* testDummyArg = [[NSString alloc] initWithString:@"DummyString"];

    SEL selector = @selector(testFunctionWithDummyArg:);
    NSMethodSignature* sig = [testObj methodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];
    [invocation setSelector:selector];
    [invocation setTarget:testObj];
    [invocation setArgument:&testDummyArg atIndex:2];

    NSTimer* timer = [NSTimer scheduledTimerWithTimeInterval:0.1 invocation:invocation repeats:NO];
    ASSERT_TRUE_MSG(timer != nil, "FAILED: timer should not be nil.");

    [testDummyArg release];

    ASSERT_TRUE_MSG([timer isValid], "FAILED: The timer should be valid before fire.");
    ASSERT_TRUE_MSG([timer userInfo] == nil, "FAILED: not expected userinfo.");
    ASSERT_EQ_MSG(0, [timer tolerance], "FAILED:  tolerance should be 0 by default.");

    for (;;) {
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (waitCompletion) {
            break;
        }
    }

    ASSERT_TRUE_MSG(![timer isValid], "FAILED: The timer should not be valid.");
    ASSERT_EQ_MSG(YES, selectorCalledAsync.get(), "FAILED: the scheduled timer did not call the method.");
    ASSERT_OBJCEQ_MSG(testDummyArg, [testObj dummyVal], "FAILED: argument was not retained.");
}