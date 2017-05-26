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

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSNotificationQueue.h"

@interface NSNotificationQueue () {
    StrongId<NSNotificationCenter> _notificationCenter;
}
@end

@implementation NSNotificationQueue
/**
 @Status Caveat
 @Notes Since there is no state kept by the notification queue (and it dispatches notifications immediately), there is only one default
 queue.
        The reference platform specifies that there is one per thread, and it follows that they keep different coalescing and dispatch
 state.
        It stands to reason that a singleton that doesn't queue notifications functions identically to every thread.
*/
+ (NSNotificationQueue*)defaultQueue {
    static StrongId<NSNotificationQueue> s_defaultQueue{ woc::TakeOwnership,
                                                         [[NSNotificationQueue alloc]
                                                             initWithNotificationCenter:[NSNotificationCenter defaultCenter]] };
    return s_defaultQueue;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithNotificationCenter:(NSNotificationCenter*)notificationCenter {
    if (self = [super init]) {
        _notificationCenter = notificationCenter;
    }
    return self;
}

/**
 @Status Caveat
 @Notes Does not coalesce notifications.
*/
- (void)enqueueNotification:(NSNotification*)notification postingStyle:(NSPostingStyle)postingStyle {
    [self enqueueNotification:notification
                 postingStyle:postingStyle
                 coalesceMask:(NSNotificationCoalescingOnName | NSNotificationCoalescingOnSender)
                     forModes:nil];
}

/**
 @Status Caveat
 @Notes Ignores the coalescing mask.
*/
- (void)enqueueNotification:(NSNotification*)notification
               postingStyle:(NSPostingStyle)postingStyle
               coalesceMask:(NSNotificationCoalescing)coalesceMask
                   forModes:(NSArray*)modes {
    if (!modes) {
        modes = @[ NSDefaultRunLoopMode ];
    }

    switch (postingStyle) {
        case NSPostNow:
            [_notificationCenter postNotification:notification];
            break;
        case NSPostASAP:
            // NOTE: Posting with order 0 makes this the next thing to execute when the runloop spins again.
            [[NSRunLoop currentRunLoop] performSelector:@selector(postNotification:)
                                                 target:_notificationCenter
                                               argument:notification
                                                  order:0
                                                  modes:modes];
            break;
        case NSPostWhenIdle:
            // NOTE: Approximating "later" by passing the highest order we can; this should be scheduled after all other performs.
            [[NSRunLoop currentRunLoop] performSelector:@selector(postNotification:)
                                                 target:_notificationCenter
                                               argument:notification
                                                  order:NSUIntegerMax
                                                  modes:modes];
            break;
    }
}

/**
 @Status Stub
 @Notes Doesn't unqueue anything because notifications are posted immediately.
*/
- (void)dequeueNotificationsMatching:(NSNotification*)notification coalesceMask:(NSUInteger)coalesceMask {
    UNIMPLEMENTED();
}

@end
