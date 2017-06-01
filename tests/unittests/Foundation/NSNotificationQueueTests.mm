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
#import <Helpers/TestHelpers.h>
#import <Windows.h>

// NSNotificationQueue has different semantics on Windows.
OSX_DISABLED_TEST(NSNotificationQueue, PostNow) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    StrongId<THRunLoopSpinner> spinner{ woc::TakeOwnership, [THRunLoopSpinner new] };

    __block StrongId<NSNotificationQueue> queue;
    [spinner scheduleAndAwaitBlock:^{
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

    [spinner scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostNow];
    }];

    // Counter should become 1 immediately when the block fires; that's the point of NSPostNow.
    ASSERT_EQ(1, counter);
}

// NSNotificationQueue has different semantics on Windows.
OSX_DISABLED_TEST(NSNotificationQueue, PostASAP) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    StrongId<THRunLoopSpinner> spinner{ woc::TakeOwnership, [THRunLoopSpinner new] };

    __block StrongId<NSNotificationQueue> queue;
    [spinner scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block THBooleanCondition* condition = [[THBooleanCondition new] autorelease];
    __block int counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    ++counter;
                                    [condition broadcast];
                                }];

    [spinner scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostASAP];
    }];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_EQ(1, counter);
}

// NSNotificationQueue has different semantics on Windows.
OSX_DISABLED_TEST(NSNotificationQueue, PostWhenIdle) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    StrongId<THRunLoopSpinner> spinner{ woc::TakeOwnership, [THRunLoopSpinner new] };

    __block StrongId<NSNotificationQueue> queue;
    [spinner scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block THBooleanCondition* condition = [[THBooleanCondition new] autorelease];
    __block int counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    ++counter;
                                    [condition broadcast];
                                }];

    [spinner scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostWhenIdle];
    }];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];

    ASSERT_EQ(1, counter);
}

// NSNotificationQueue has different semantics on Windows.
OSX_DISABLED_TEST(NSNotificationQueue, AllThreePostingStyles) {
    static NSString* s_TestNotificationName = @(GetTestFullName().c_str());
    NSNotificationCenter* notificationCenter = [[NSNotificationCenter new] autorelease];
    StrongId<THRunLoopSpinner> spinner{ woc::TakeOwnership, [THRunLoopSpinner new] };

    __block StrongId<NSNotificationQueue> queue;
    [spinner scheduleAndAwaitBlock:^{
        queue.attach([[NSNotificationQueue alloc] initWithNotificationCenter:notificationCenter]);
    }];

    __block THBooleanCondition* condition = [[THBooleanCondition new] autorelease];
    __block long counter = 0;
    [notificationCenter addObserverForName:s_TestNotificationName
                                    object:nil
                                     queue:nil
                                usingBlock:^(NSNotification* note) {
                                    ASSERT_OBJCEQ(s_TestNotificationName, note.name);
                                    if (3 == InterlockedIncrement(&counter)) {
                                        [condition broadcast];
                                    }
                                }];

    [spinner scheduleAndAwaitBlock:^{
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostNow];
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostASAP];
        [queue enqueueNotification:[NSNotification notificationWithName:s_TestNotificationName object:nil] postingStyle:NSPostWhenIdle];
    }];

    [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:20]];
    ASSERT_EQ(3, counter);
}

// NSNotificationQueue has different semantics on Windows.
OSX_DISABLED_TEST(NSNotificationQueue, ThreadsHaveDifferentQueues) {
    StrongId<THRunLoopSpinner> spinner1{ woc::TakeOwnership, [THRunLoopSpinner new] };
    StrongId<THRunLoopSpinner> spinner2{ woc::TakeOwnership, [THRunLoopSpinner new] };

    __block StrongId<NSNotificationQueue> queue1;
    [spinner1 scheduleAndAwaitBlock:^{
        queue1 = [NSNotificationQueue defaultQueue];
    }];

    __block StrongId<NSNotificationQueue> queue2;
    [spinner2 scheduleAndAwaitBlock:^{
        queue2 = [NSNotificationQueue defaultQueue];
    }];

    ASSERT_NE(queue1, queue2);
}
