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

@implementation NSNotificationQueue

/**
 @Status Stub
 @Notes
*/
+ (instancetype)defaultQueue {
    // TODO: Intentionally commented out for now to prevent flooded debug spew from NSRunLoop's usage.
    // UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithNotificationCenter:(NSNotificationCenter*)notificationCenter {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enqueueNotification:(NSNotification*)notification postingStyle:(NSPostingStyle)postingStyle {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enqueueNotification:(NSNotification*)notification
               postingStyle:(NSPostingStyle)postingStyle
               coalesceMask:(NSNotificationCoalescing)coalesceMask
                   forModes:(NSArray*)modes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)dequeueNotificationsMatching:(NSNotification*)notification coalesceMask:(NSUInteger)coalesceMask {
    UNIMPLEMENTED();
}

@end
