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

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <Starboard/SmartTypes.h>
#import "TestUtils.h"

#import <atomic>

@interface NSNotificationQueueTestHelper : NSObject {
    NSRunLoop* _loop;
    BOOL _isStopped;
    _NSBooleanCondition* _threadStartedCondition;
}
@property (retain) NSThread* thread;
- (void)scheduleAndAwaitBlock:(void (^)())block;
@end

@implementation NSNotificationQueueTestHelper

- (instancetype)init {
    if (self = [super init]) {
        _thread = [[NSThread alloc] initWithTarget:self selector:@selector(spinRunLoop) object:nil];
        _threadStartedCondition = [[_NSBooleanCondition alloc] init];
        [_thread start];
        [_threadStartedCondition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:10]];

        ASSERT_TRUE(_threadStartedCondition.isOpen);
    }
    return self;
}

- (void)dealloc {
    _isStopped = YES;
    [_thread release];
    [_threadStartedCondition release];
    [super dealloc];
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

        [_threadStartedCondition broadcast];

        while (!_isStopped) {
            @autoreleasepool {
                [_loop runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
            }
        }
    }
}

- (void)scheduleAndAwaitBlock:(void (^)())block {
    _NSBooleanCondition* condition = [[_NSBooleanCondition new] autorelease];
    void (^wrappedBlock)() = ^{
        block();
        [condition broadcast];
    };

    [_loop performSelector:@selector(invoke) target:wrappedBlock argument:nil order:0 modes:@[ NSDefaultRunLoopMode ]];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_TRUE(condition.isOpen);
}
@end

TEST(NSNotificationQueue, PostNow) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    NSNotificationQueueTestHelper* helper = [[NSNotificationQueueTestHelper new] autorelease];

    __block StrongId<NSNotificationQueue> queue;
    [helper scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block int counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ++counter;
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                }];

    [helper scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostNow];
    }];

    // Counter should become 1 immediately when the block fires; that's the point of NSPostNow.
    ASSERT_EQ(1, counter);
}

TEST(NSNotificationQueue, PostASAP) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    NSNotificationQueueTestHelper* helper = [[NSNotificationQueueTestHelper new] autorelease];

    __block StrongId<NSNotificationQueue> queue;
    [helper scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block _NSBooleanCondition* condition = [[_NSBooleanCondition new] autorelease];
    __block int counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    ++counter;
                                    [condition broadcast];
                                }];

    [helper scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostASAP];
    }];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_EQ(1, counter);
}

TEST(NSNotificationQueue, PostWhenIdle) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    NSNotificationQueueTestHelper* helper = [[NSNotificationQueueTestHelper new] autorelease];

    __block StrongId<NSNotificationQueue> queue;
    [helper scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block _NSBooleanCondition* condition = [[_NSBooleanCondition new] autorelease];
    __block int counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    ++counter;
                                    [condition broadcast];
                                }];

    [helper scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostWhenIdle];
    }];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_EQ(1, counter);
}

TEST(NSNotificationQueue, AllThreePostingStyles) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    NSNotificationQueueTestHelper* helper = [[NSNotificationQueueTestHelper new] autorelease];

    __block StrongId<NSNotificationQueue> queue;
    [helper scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    dispatch_semaphore_t sema = dispatch_semaphore_create(0);
    std::atomic<int> counter{ 0 };
    std::atomic<int>* counterp = &counter; // __block couldn't defeat the copy construction of std::atomic?
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    ++(*counterp);
                                    dispatch_semaphore_signal(sema);
                                }];

    [helper scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostNow];
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostASAP];
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostWhenIdle];
    }];

    dispatch_time_t timeout = dispatch_time(DISPATCH_TIME_NOW, 20 * 1000000000 /*ns*/);
    dispatch_semaphore_wait(sema, timeout); // three signals
    dispatch_semaphore_wait(sema, timeout);
    dispatch_semaphore_wait(sema, timeout);

    ASSERT_EQ(3, counter);
}

TEST(NSNotificationQueue, ThreadsHaveDifferentQueues) {
    NSNotificationQueueTestHelper* helper1 = [[NSNotificationQueueTestHelper new] autorelease];
    NSNotificationQueueTestHelper* helper2 = [[NSNotificationQueueTestHelper new] autorelease];

    __block StrongId<NSNotificationQueue> queue1;
    [helper1 scheduleAndAwaitBlock:^{
        queue1 = [NSNotificationQueue defaultQueue];
    }];

    __block StrongId<NSNotificationQueue> queue2;
    [helper2 scheduleAndAwaitBlock:^{
        queue2 = [NSNotificationQueue defaultQueue];
    }];

    ASSERT_NE(queue1, queue2);
}