//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSNotificationCenter;
@class NSNotification;
@class NSArray;

typedef enum {
    NSNotificationNoCoalescing = 0,
    NSNotificationCoalescingOnName = 1,
    NSNotificationCoalescingOnSender = 2
} NSNotificationCoalescing;
typedef enum { NSPostWhenIdle = 1, NSPostASAP = 2, NSPostNow = 3 } NSPostingStyle;

FOUNDATION_EXPORT_CLASS
@interface NSNotificationQueue : NSObject
- (instancetype)initWithNotificationCenter:(NSNotificationCenter*)notificationCenter STUB_METHOD;
+ (NSNotificationQueue*)defaultQueue;
- (void)enqueueNotification:(NSNotification*)notification postingStyle:(NSPostingStyle)postingStyle STUB_METHOD;
- (void)enqueueNotification:(NSNotification*)notification
               postingStyle:(NSPostingStyle)postingStyle
               coalesceMask:(NSNotificationCoalescing)coalesceMask
                   forModes:(NSArray*)modes STUB_METHOD;
- (void)dequeueNotificationsMatching:(NSNotification*)notification coalesceMask:(NSUInteger)coalesceMask STUB_METHOD;
@end
