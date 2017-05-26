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

#import <Foundation/NSNotificationQueue.h>
#import <StubReturn.h>
#import <Starboard/SmartTypes.h>

@interface NSNotificationQueue () {
    StrongId<NSNotificationCenter> _notificationCenter;
}
@end

@implementation NSNotificationQueue
/**
 @Status Interoperable
*/
+ (NSNotificationQueue*)defaultQueue {
    @synchronized(self) {
        NSNotificationQueue* threadQueue = [[[NSThread currentThread] threadDictionary] objectForKey:self];
        if (!threadQueue) {
            threadQueue = [[[NSNotificationQueue alloc] initWithNotificationCenter:[NSNotificationCenter defaultCenter]] autorelease];
            [[[NSThread currentThread] threadDictionary] setObject:threadQueue forKey:self];
        }
        return [[threadQueue retain] autorelease];
    }
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
    if (!notification) {
        [NSException raise:NSInvalidArgumentException format:@"*** %s: notification cannot be nil", __PRETTY_FUNCTION__];
    }

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
        default:
            [NSException raise:NSInvalidArgumentException format:@"*** %s: unknown posting style %u", __PRETTY_FUNCTION__, (unsigned int)postingStyle];
            break;
    }
}

/**
 @Status NotInPlan
 @Notes Won't unqueue anything because notifications are posted immediately.
*/
- (void)dequeueNotificationsMatching:(NSNotification*)notification coalesceMask:(NSUInteger)coalesceMask {
    UNIMPLEMENTED();
}

@end
