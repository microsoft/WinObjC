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

#pragma once
#import "Starboard.h"
#import <Foundation/NSRunLoop.h>
#import <Foundation/NSString.h>
#import "NSRunLoopState.h"
#import "NSInputSource.h"

@class NSDelayedPerform;

@interface NSRunLoop (Internal)
- (void)_run;
- (void)_stop;
- (void)_wakeUp;
- (void)_addInputSource:(NSInputSource*)source forMode:(NSString*)mode;
- (void)_removeInputSource:(NSInputSource*)source forMode:(NSString*)mode;
- (void)_addObserver:(NSObject*)observer forMode:(NSString*)mode;
- (void)_removeObserver:(NSObject*)observer forMode:(NSString*)mode;
- (StrongId<NSArray*>)_statesForMode:(NSString*)mode;
- (void)_processMainRunLoop:(int)value;
- (void)_shutdown;
- (void)removeTimer:(NSTimer*)timer forMode:(NSString*)mode;

@end

@interface NSRunLoop (XamlUIWaiter)
+ (void)setUIThreadMainRunLoopWaitFunction:(int (*)(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets))callback;
@end

@interface NSRunLoop ()
- (void)_invalidateTimerWithDelayedPerform:(NSDelayedPerform*)delayedPerform;
@end
