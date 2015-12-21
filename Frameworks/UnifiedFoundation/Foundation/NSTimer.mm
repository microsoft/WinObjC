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

#import <math.h>
#import <Starboard.h>
#import <CoreFoundation/CFArray.h>
#import <Foundation/NSRunLoop.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSTimer.h>
#import "NSRunLoopState.h"
#import "NSRunLoop+Internal.h"

@implementation NSTimer {
    BOOL _repeats;
    BOOL _valid;
    BOOL _isDestroying;
    id _timerTarget;
    BOOL _timerTargetReleased;
    double _interval;
    double _nextFireTime;
    SEL _sel;
    NSObject* _userInfo;
    NSMutableArray* _addedToModes;
    BOOL _canFire;
}

/**
 @Status Interoperable
*/
- (void)invalidate {
    if (_valid) {
        _valid = FALSE;
        [_timerTarget autorelease];
        _timerTargetReleased = TRUE;
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isValid {
    return _valid;
}

- (void)_addedToMode:(NSRunLoopState*)runLoopState {
    CFArrayAppendValue((CFMutableArrayRef)_addedToModes, (const void*)runLoopState);
}

- (void)_removedFromMode:(NSRunLoopState*)runLoopState {
    [_addedToModes removeObject:runLoopState];
}

- (void)dealloc {
    if (_isDestroying) {
        EbrDebugLog("Warning: NSTimer over-released\n");
        return;
    }

    _isDestroying = TRUE;
    int count = CFArrayGetCount((CFArrayRef)_addedToModes) - 1;
    while (count >= 0) {
        NSRunLoopState* runLoopState = (NSRunLoopState*)CFArrayGetValueAtIndex((CFArrayRef)_addedToModes, count);
        [runLoopState removeTimer:self];
        count--;
    }
    [_addedToModes release];
    _addedToModes = nil;
    if (!_timerTargetReleased) {
        _timerTargetReleased = TRUE;
        [_timerTarget release];
    }

    if (_userInfo != nil) {
        [_userInfo release];
    }

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)fire {
    [self retain];

    if (_canFire) {
        _canFire = FALSE;

        if (_valid) {
            if (_repeats) {
                double curTime = [NSDate timeIntervalSinceReferenceDate];
                if (_interval > 0.0) {
                    _nextFireTime += (floor((curTime - _nextFireTime) / _interval) + 1.0) * _interval;
                } else {
                    _nextFireTime = curTime;
                }
            }

            if (_sel != NULL) {
                [_timerTarget performSelector:_sel withObject:self];
            } else {
                [_timerTarget invoke];
            }

            if (!_repeats) {
                _valid = FALSE;
            }
        }

        _canFire = TRUE;
    }

    [self release];
}

/**
 @Status Interoperable
*/
- (NSObject*)userInfo {
    return _userInfo;
}

/**
 @Status Interoperable
*/
- (double)timeInterval {
    double ret;

    if (_repeats && _valid) {
        ret = _interval;
    } else {
        ret = 0;
    }
    return ret;
}

- (double)nextFireTime {
    double ret;

    if (!_valid) {
        ret = 0.0f;
    } else {
        ret = _nextFireTime;
    }

    return ret;
}

/**
 @Status Interoperable
*/
+ (NSTimer*)scheduledTimerWithTimeInterval:(double)seconds
                                    target:(id)target
                                  selector:(SEL)selector
                                  userInfo:(NSObject*)userInfo
                                   repeats:(BOOL)repeats {
    NSTimer* pNewTimer = [self alloc];

    pNewTimer->_addedToModes = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    pNewTimer->_repeats = repeats;
    pNewTimer->_valid = TRUE;
    pNewTimer->_sel = selector;
    pNewTimer->_timerTarget = [target retain];
    pNewTimer->_interval = seconds;
    pNewTimer->_nextFireTime = [NSDate timeIntervalSinceReferenceDate] + pNewTimer->_interval;
    pNewTimer->_userInfo = [userInfo retain];
    pNewTimer->_canFire = TRUE;

    [[NSRunLoop currentRunLoop] addTimer:pNewTimer forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop currentRunLoop] _wakeUp];
    return [pNewTimer autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTimer*)timerWithTimeInterval:(double)seconds
                           target:(id)target
                         selector:(SEL)selector
                         userInfo:(NSObject*)userInfo
                          repeats:(BOOL)repeats {
    NSTimer* pNewTimer = [self alloc];

    pNewTimer->_addedToModes = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    pNewTimer->_repeats = repeats;
    pNewTimer->_valid = TRUE;
    pNewTimer->_sel = selector;
    pNewTimer->_timerTarget = [target retain];
    pNewTimer->_interval = seconds;
    pNewTimer->_nextFireTime = [NSDate timeIntervalSinceReferenceDate] + pNewTimer->_interval;
    pNewTimer->_userInfo = [userInfo retain];
    pNewTimer->_canFire = TRUE;
    return [pNewTimer autorelease];
}

/**
 @Status Interoperable
*/
- (NSTimer*)initWithFireDate:(NSDate*)date
                    interval:(double)seconds
                      target:(id)target
                    selector:(SEL)selector
                    userInfo:(NSObject*)userInfo
                     repeats:(BOOL)repeats {
    _addedToModes = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    _repeats = repeats;
    _sel = selector;
    _timerTarget = [target retain];
    _interval = seconds;
    _nextFireTime = [date timeIntervalSinceReferenceDate];
    _userInfo = [userInfo retain];
    _canFire = TRUE;

    _valid = TRUE;

    return self;
}

/**
 @Status Interoperable
*/
+ (NSTimer*)timerWithTimeInterval:(double)seconds invocation:(NSInvocation*)target repeats:(BOOL)repeats {
    NSTimer* pNewTimer = [self alloc];

    pNewTimer->_addedToModes = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    pNewTimer->_repeats = repeats;
    pNewTimer->_valid = TRUE;
    pNewTimer->_sel = NULL;
    [target retainArguments];
    pNewTimer->_timerTarget = [target retain];
    pNewTimer->_interval = seconds;
    pNewTimer->_nextFireTime = [NSDate timeIntervalSinceReferenceDate] + pNewTimer->_interval;
    pNewTimer->_userInfo = nil;
    pNewTimer->_canFire = TRUE;

    return [pNewTimer autorelease];
}

/**
 @Status Interoperable
*/
+ (NSTimer*)scheduledTimerWithTimeInterval:(double)seconds invocation:(NSInvocation*)target repeats:(BOOL)repeats {
    NSTimer* pNewTimer = [self alloc];

    pNewTimer->_addedToModes = (NSMutableArray*)CFArrayCreateMutable(NULL, 0, NULL);
    pNewTimer->_repeats = repeats;
    pNewTimer->_valid = TRUE;
    pNewTimer->_sel = NULL;
    [target retainArguments];
    pNewTimer->_timerTarget = [target retain];
    pNewTimer->_interval = seconds;
    pNewTimer->_nextFireTime = [NSDate timeIntervalSinceReferenceDate] + pNewTimer->_interval;
    pNewTimer->_userInfo = nil;
    pNewTimer->_canFire = TRUE;

    [[NSRunLoop currentRunLoop] addTimer:pNewTimer forMode:@"kCFRunLoopDefaultMode"];
    [[NSRunLoop currentRunLoop] _wakeUp];

    return [pNewTimer autorelease];
}

/**
 @Status Interoperable
*/
- (void)setFireDate:(NSDate*)date {
    _nextFireTime = [date timeIntervalSinceReferenceDate];
}

/**
 @Status Interoperable
*/
- (NSDate*)fireDate {
    return [NSDate dateWithTimeIntervalSinceReferenceDate:_nextFireTime];
}

@end
