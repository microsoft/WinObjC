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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import "Starboard/SmartTypes.h"

#import <future>
#import <windows.h>

@interface TestObject : NSObject {
    StrongId<NSCondition> _fooCondition;
    StrongId<NSCondition> _barCondition;
}

@property (atomic) int foo;
@property (atomic) int bar;

- (void)incrementFoo;
- (void)incrementBar:(NSNumber*)amount;

@end

@implementation TestObject

- (id)init {
    if (self = [super init]) {
        _fooCondition.attach([[NSCondition alloc] init]);
        _barCondition.attach([[NSCondition alloc] init]);
    }
    return self;
}

- (void)incrementFoo {
    @synchronized(self) {
        self.foo += 1;
        [_fooCondition broadcast];
    }
}

- (void)incrementBar:(NSNumber*)amount {
    @synchronized(self) {
        self.bar += [amount intValue];
        [_barCondition broadcast];
    }
}

- (BOOL)waitOnFooForInterval:(NSTimeInterval)interval {
    return [_fooCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:interval]];
}

- (BOOL)waitOnBarForInterval:(NSTimeInterval)interval {
    return [_barCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:interval]];
}
@end

static const NSTimeInterval testDuration = 5.;

TEST(NSObject, PerformSelectorAfterDelaySanity) {
    volatile long fooWaitCompleted = 0;
    StrongId<TestObject> testObject = [[[TestObject alloc] init] autorelease];

    auto fooChangedAsync = std::async(std::launch::async,
                                      [&fooWaitCompleted, testObject]() {
                                          BOOL fooChanged = [testObject waitOnFooForInterval:testDuration] && [testObject foo] != 0;
                                          _InterlockedExchange(&fooWaitCompleted, 1L);
                                          return fooChanged;
                                      });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:0.25];

    for (;;) {
        // Spin the run loop until the async test wait gives up or completes.
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (fooWaitCompleted) {
            break;
        }
    }

    ASSERT_TRUE_MSG(fooChangedAsync.get(), "testObject.foo did not change despite waiting for selector to fire");
}

TEST(NSObject, CancelPreviousPerformRequestsWithTarget) {
    volatile long fooWaitCompleted = 0;
    StrongId<TestObject> testObject = [[[TestObject alloc] init] autorelease];

    auto fooChangedAsync = std::async(std::launch::async,
                                      [&fooWaitCompleted, testObject]() {
                                          BOOL fooChanged = [testObject waitOnFooForInterval:testDuration] && [testObject foo] != 0;
                                          _InterlockedExchange(&fooWaitCompleted, 1L);
                                          return fooChanged;
                                      });

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:1];
    [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];

    [NSObject cancelPreviousPerformRequestsWithTarget:testObject];

    for (;;) {
        // Spin the run loop until the async test wait gives up or completes.
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (fooWaitCompleted) {
            break;
        }
    }

    ASSERT_FALSE_MSG(fooChangedAsync.get(), "testObject.foo changed despite being cancelled");
}

TEST(NSObject, CancelPreviousPerformRequestsWithTargetSelectorObject) {
    volatile long fooWaitCompleted = 0, barWaitCompleted = 0;
    StrongId<TestObject> testObject = [[[TestObject alloc] init] autorelease];

    auto fooChangedAsync = std::async(std::launch::async,
                                      [&fooWaitCompleted, testObject]() {
                                          BOOL fooChanged = [testObject waitOnFooForInterval:testDuration] && [testObject foo] != 0;
                                          _InterlockedExchange(&fooWaitCompleted, 1L);
                                          return fooChanged;
                                      });

    auto barChangedAsync = std::async(std::launch::async,
                                      [&barWaitCompleted, testObject]() {
                                          bool barChanged = [testObject waitOnBarForInterval:testDuration] && [testObject bar] != 0;
                                          _InterlockedExchange(&barWaitCompleted, 1L);
                                          return barChanged;
                                      });

    NSNumber* amount = @(5);

    NSRunLoop* runLoop = [NSRunLoop currentRunLoop];

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:0.25];
    [testObject performSelector:@selector(incrementBar:) withObject:amount afterDelay:1];

    [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];

    [NSObject cancelPreviousPerformRequestsWithTarget:testObject selector:@selector(incrementBar:) object:amount];

    for (;;) {
        // Spin the run loop until the async test wait gives up or completes.
        [runLoop runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];
        if (fooWaitCompleted && barWaitCompleted) {
            break;
        }
    }

    ASSERT_TRUE_MSG(fooChangedAsync.get(), "testObject.foo did not change despite waiting for selector to fire");
    ASSERT_FALSE_MSG(barChangedAsync.get(), "testObject.bar changed despite being cancelled");
}
