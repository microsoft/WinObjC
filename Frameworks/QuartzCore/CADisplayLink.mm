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

#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSTimer.h"
#include "Foundation/NSRunLoop.h"
#include "../Foundation/NSRunLoopState.h"
#include "NSRunLoopSource.h"
#include "Quartzcore/CADisplayLink.h"

EbrLock _displaySyncSocketLock = EBRLOCK_INITIALIZE;
EbrEvent _displaySyncEvents[32];
int _numDisplaySyncEvents = 0;
bool _displaySyncEnabled = false;

bool CASignalDisplayLink() {
    bool ret = false;

    EbrLockEnter(_displaySyncSocketLock);
    for (int i = 0; i < _numDisplaySyncEvents; i++) {
        EbrEventSignal(_displaySyncEvents[i]);
        ret = true;
    }
    EbrLockLeave(_displaySyncSocketLock);

    return ret;
}

static IWLazyClassLookup _LazyRunLoopSource("NSRunLoopSource");
static IWLazyIvarLookup<EbrEvent> _LazySignaledOffset(_LazyRunLoopSource, "_signaledEvent");

@implementation CADisplayLink : NSObject {
    idretain _target;
    SEL _selector;
    idretaintype(NSTimer) _timer;
    bool _isPaused;
    bool _addedToUpdateList;
    idretaintype(NSRunLoopSource) _displaySyncEvent;
    int _frameInterval;

    enum CADisplayLinkRunMode _runMode;
    NSMutableDictionary* _addedRunLoops;
    double _timestamp;
}

static void addToUpdateList(CADisplayLink* self) {
    if (!self->_addedToUpdateList) {
        self->_addedToUpdateList = true;
        EbrLockEnter(_displaySyncSocketLock);
        _displaySyncEvents[_numDisplaySyncEvents++] = _LazySignaledOffset.member(self->_displaySyncEvent);
        EbrLockLeave(_displaySyncSocketLock);
    }

    if (_numDisplaySyncEvents > 0 && !_displaySyncEnabled) {
        GetCACompositor()->EnableDisplaySyncNotification();
    }
}

static void removeFromUpdateList(CADisplayLink* self) {
    if (self->_addedToUpdateList) {
        EbrLockEnter(_displaySyncSocketLock);
        for (int i = 0; i < _numDisplaySyncEvents; i++) {
            if (_displaySyncEvents[i] == _LazySignaledOffset.member(self->_displaySyncEvent)) {
                memmove(
                    &_displaySyncEvents[i], &_displaySyncEvents[i + 1], (_numDisplaySyncEvents - i) * sizeof(EbrEvent));
                _numDisplaySyncEvents--;
                break;
            }
        }
        EbrLockLeave(_displaySyncSocketLock);
    }

    if (_numDisplaySyncEvents <= 0 && _displaySyncEnabled) {
        GetCACompositor()->DisableDisplaySyncNotification();
    }
}

static void removeFromRunloops(CADisplayLink* self, NSRunLoop* runLoop = nil, NSString* mode = nil) {
    if (self->_runMode == CADisplayLinkSyncMode) {
        for (NSString* curmode in self->_addedRunLoops) {
            if (mode != nil && ![curmode isEqualToString:mode])
                continue;

            id arr = [self->_addedRunLoops objectForKey:curmode];
            for (int i = [arr count] - 1; i >= 0; i--) {
                NSRunLoop* currunloop = [arr objectAtIndex:i];

                if (runLoop != nil && currunloop != runLoop)
                    continue;

                [currunloop removeInputSource:self->_displaySyncEvent forMode:curmode];
                [arr removeObjectAtIndex:i];
                [self autorelease];
            }
        }
    } else if (self->_runMode == CADisplayLinkTimerMode) {
        for (NSString* curmode in self->_addedRunLoops) {
            if (mode != nil && ![curmode isEqualToString:mode])
                continue;

            id arr = [self->_addedRunLoops objectForKey:curmode];
            for (int i = [arr count] - 1; i >= 0; i--) {
                NSRunLoop* currunloop = [arr objectAtIndex:i];
                if (runLoop != nil && currunloop != runLoop)
                    continue;

                [currunloop removeTimer:(NSTimer*)self->_timer forMode:curmode];
                [arr removeObjectAtIndex:i];
                [self autorelease];
            }
        }
    } else {
        assert(0);
    }
}

static void addToRunloops(CADisplayLink* self) {
    if (self->_runMode == CADisplayLinkSyncMode) {
        for (NSString* curmode in self->_addedRunLoops) {
            id arr = [self->_addedRunLoops objectForKey:curmode];
            for (NSRunLoop* currunloop in arr) {
                [currunloop addInputSource:self->_displaySyncEvent forMode:curmode];
                [self retain];
            }
        }
    } else if (self->_runMode == CADisplayLinkTimerMode) {
        for (NSString* curmode in self->_addedRunLoops) {
            id arr = [self->_addedRunLoops objectForKey:curmode];
            for (NSRunLoop* currunloop in arr) {
                [currunloop addTimer:self->_timer forMode:curmode];
                [self retain];
            }
        }
    } else {
        assert(0);
    }
}

static void createTimerIfNeeded(CADisplayLink* self) {
    if (self->_timer == nil) {
        double interval = (1.0 / (60.0 / (double)self->_frameInterval));
        id fireDate = [NSDate dateWithTimeIntervalSinceNow:interval];

        self->_timer.attach([[NSTimer alloc] initWithFireDate:fireDate
                                                     interval:interval
                                                       target:(id)self
                                                     selector:@selector(_updateDisplayLink)
                                                     userInfo:NULL
                                                      repeats:TRUE]);
    }
}

+ (instancetype)displayLinkWithTarget:(NSObject*)target selector:(SEL)selector {
    CADisplayLink* ret = [self alloc];

    ret->_frameInterval = 1;
    ret->_target = target;
    ret->_selector = selector;
    ret->_displaySyncEvent.attach([NSRunLoopSource new]);
    [ret->_displaySyncEvent setSourceDelegate:(id)ret selector:@selector(_updateDisplayLink)];
    ret->_addedRunLoops = [NSMutableDictionary new];

    return [ret autorelease];
}

- (double)duration {
    // assume 60 FPS.
    return (1.0 / (60.0 / (double)_frameInterval));
}

- (NSInteger)frameInterval {
    return _frameInterval;
}

- (void)setFrameInterval:(NSInteger)interval {
    if (interval < 1)
        interval = 1;
    _frameInterval = interval;

    if (_frameInterval != 1) {
        removeFromRunloops(self);
        _runMode = CADisplayLinkTimerMode;
        _timer = nil;
        createTimerIfNeeded(self);
        addToRunloops(self);
    } else {
        if (_runMode != CADisplayLinkSyncMode) {
            removeFromRunloops(self);
            _runMode = CADisplayLinkSyncMode;
            addToRunloops(self);
        }
    }
}

- (void)removeFromRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode {
    removeFromRunloops(self, runLoop, mode);
}

- (void)setPaused:(BOOL)paused {
    _isPaused = paused != FALSE;
}

- (BOOL)isPaused {
    return _isPaused;
}

- (void)_updateDisplayLink {
    if (!_isPaused) {
        _timestamp = EbrGetMediaTime();
        [_target performSelector:_selector withObject:self];
    }
}

- (void)invalidate {
    removeFromRunloops(self);
    removeFromUpdateList(self);
    [_addedRunLoops removeAllObjects];
    _target = nil;
}

- (void)addToRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode {
    id modesArray = [_addedRunLoops objectForKey:mode];
    if (modesArray == nil) {
        modesArray = [NSMutableArray array];
        [_addedRunLoops setObject:modesArray forKey:mode];
    }
    [modesArray addObject:runLoop];
    if (_runMode == CADisplayLinkSyncMode) {
        [runLoop addInputSource:_displaySyncEvent forMode:mode];
        [self retain];
        addToUpdateList(self);
        [_displaySyncEvent _trigger];
    } else {
        createTimerIfNeeded(self);
        [runLoop addTimer:_timer forMode:mode];
        [self retain];
    }
}

- (void)dealloc {
    [self invalidate];

    removeFromUpdateList(self);

    _displaySyncEvent = nil;
    _timer = nil;
    _target = nil;
    [_addedRunLoops release];

    [super dealloc];
}

- (double)timestamp {
    return _timestamp;
}

@end
