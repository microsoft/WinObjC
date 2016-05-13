/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <WinSock2.h>
#undef WIN32

#import "Starboard.h"
#import "CoreFoundation/CFRunLoop.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSDate.h"
#import "NSRunLoopState.h"
#import "NSRunLoopSource.h"
#import "NSDelayedPerform.h"
#import "NSSelectInputSource.h"
#import "dispatch/dispatch.h"
#import "sys/timespec.h"
#import "LoggingNative.h"
#import "NSTimerInternal.h"

static const wchar_t* TAG = L"NSRunLoopState";

int (*g_UIEventMainRunLoopTimedMultipleWaitCallback)(EbrEvent* events,
                                                     int numEvents,
                                                     double timeout,
                                                     SocketWait* sockets) = EbrEventTimedMultipleWait;

/* Source: http://cantrip.org/socketpair.c */
/* socketpair.c
* Copyright 2007 by Nathan C. Myers <ncm@cantrip.org>; some rights reserved.
* This code is Free Software.  It may be copied freely, in original or
* modified form, subject only to the restrictions that (1) the author is
* relieved from all responsibilities for any use for any purpose, and (2)
* this copyright notice must be retained, unchanged, in its entirety.  If
* for any reason the author might be held responsible for any consequences
* of copying or use, license is withheld.
*/

/* dumb_socketpair:
*   If make_overlapped is nonzero, both sockets created will be usable for
*   "overlapped" operations via WSASend etc.  If make_overlapped is zero,
*   socks[0] (only) will be usable with regular ReadFile etc., and thus
*   suitable for use as stdin or stdout of a child process.  Note that the
*   sockets must be closed with closesocket() regardless.
*/

int dumb_socketpair(SOCKET socks[2], int make_overlapped) {
    union {
        struct sockaddr_in inaddr;
        struct sockaddr addr;
    } a;
    SOCKET listener;
    int e;
    int addrlen = sizeof(a.inaddr);
    DWORD flags = (make_overlapped ? WSA_FLAG_OVERLAPPED : 0);
    int reuse = 1;

    if (socks == 0) {
        WSASetLastError(WSAEINVAL);
        return SOCKET_ERROR;
    }

    listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == INVALID_SOCKET)
        return SOCKET_ERROR;

    memset(&a, 0, sizeof(a));
    a.inaddr.sin_family = AF_INET;
    a.inaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    a.inaddr.sin_port = 0;

    socks[0] = socks[1] = INVALID_SOCKET;
    do {
        if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, (char*)&reuse, (int)sizeof(reuse)) == -1)
            break;
        if (bind(listener, &a.addr, sizeof(a.inaddr)) == SOCKET_ERROR)
            break;
        if (getsockname(listener, &a.addr, &addrlen) == SOCKET_ERROR)
            break;
        if (listen(listener, 1) == SOCKET_ERROR)
            break;
        socks[0] = WSASocketW(AF_INET, SOCK_STREAM, 0, NULL, 0, flags);
        if (socks[0] == INVALID_SOCKET)
            break;
        if (connect(socks[0], &a.addr, sizeof(a.inaddr)) == SOCKET_ERROR)
            break;
        socks[1] = accept(listener, NULL, NULL);
        if (socks[1] == INVALID_SOCKET)
            break;

        closesocket(listener);
        return 0;

    } while (0);

    e = WSAGetLastError();
    closesocket(listener);
    closesocket(socks[0]);
    closesocket(socks[1]);
    WSASetLastError(e);
    return SOCKET_ERROR;
}

bool GetMainDispatchTimerTimeout(double* val) {
    struct timespec timespec = { 0 };

    if (dispatch_get_next_timer_fire(&timespec) != NULL) {
        *val = timespec.tv_sec * 1.0 + timespec.tv_nsec / 1000000000.0;
        return true;
    } else {
        return false;
    }
}

@interface NSRunLoopState () {
    SocketWait _socks;
    fd_set _read;
    fd_set _write;
    fd_set _error;
}
@end

@implementation NSRunLoopState
- (NSObject*)init {
    _timers = [NSMutableArray new];
    _observers = [NSMutableArray new];
    _cancelSource = [NSRunLoopSource new];
    [self addInputSource:_cancelSource];

    return self;
}

- (void)dealloc {
    for (NSTimer* curtimer in _timers) {
        [curtimer _removedFromMode:self];
    }
    [_cancelSource release];
    for (int i = 0; i < _numWaitSignals; i++) {
        [_waitSignalObjects[i] release];
    }
    for (int i = 0; i < _numWaitSockets; i++) {
        [_waitSocketObjects[i] release];
    }
    [_timers release];

    if (_builtWakeupSockets) {
        closesocket(_wakeupSockets[0]);
        closesocket(_wakeupSockets[1]);
    }
    [_observers release];

    [super dealloc];
}

- (void)wakeUp {
    [_cancelSource _trigger];
}

- (void)addTimer:(NSTimer*)timer {
    [_timers addObject:timer];
    [timer _addedToMode:self];
}

- (BOOL)containsTimer:(NSTimer*)timer {
    return [_timers containsObject:timer];
}

- (void)addObserver:(NSTimer*)observer {
    [_observers addObject:observer];
}

- (void)removeObserver:(NSObject*)observer {
    [_observers removeObject:observer];
}

- (void)removeTimer:(NSTimer*)timer {
    [timer _removedFromMode:self];
    [_timers removeObject:timer];
}

- (void)changingIntoMode:(NSString*)mode {
}

- (void)_notifyObservers:(uint32_t)mode {
    int i, count = [_observers count];

    for (i = 0; i < count; i++) {
        NSObject* observer = [_observers objectAtIndex:i];
        [observer notify:mode];
    }
}

- (void)checkHighPriorityEvents {
    //  Go through and fire off any high priority sources that are signaled
    for (int i = 0; i < _numWaitSignals; i++) {
        if (_waitSignalPriority[i] > 0) {
            if (EbrEventTryWait(_waitSignals[i])) {
                [_waitSignalObjects[i] fire];
            }
        }
    }
}

- (BOOL)fireFirstTimer {
    if (_starveCount == 5) {
        _starveCount = 0;
        return NO;
    }

    NSDate* now = [NSDate date];
    int i, count = [_timers count];
    NSTimer* fireTimer = nil;

    for (i = 0; i < count; i++) {
        NSTimer* check = [_timers objectAtIndex:i];

        if ([check isValid] && [now compare:[check fireDate]] != -1) {
            id object = [[_timers objectAtIndex:i] retain];
            [_timers removeObjectAtIndex:i];
            [_timers insertObject:object atIndex:[_timers count]];
            [object release];
            fireTimer = check;
            break;
        }
    }

    if (fireTimer != nil) {
        [fireTimer fire];
    }

    count = [_timers count];
    while (--count >= 0) {
        NSTimer* timer = [_timers objectAtIndex:count];
        if (![timer isValid]) {
            [timer _removedFromMode:self];
            [_timers removeObjectAtIndex:count];
        }
    }

    if (fireTimer == nil) {
        _starveCount = 0;
    } else {
        _starveCount++;
    }

    return (fireTimer != nil) ? YES : NO;
}

- (NSDate*)limitDateForMode:(NSString*)mode {
    NSDate* limit = nil;
    int count;

    count = [_timers count];
    while (--count >= 0) {
        NSTimer* timer = [_timers objectAtIndex:count];

        if (![timer isValid]) {
            [timer _removedFromMode:self];
            [_timers removeObjectAtIndex:count];
        } else {
            if (limit == nil) {
                limit = [timer fireDate];
            } else {
                limit = [limit earlierDate:[timer fireDate]];
            }
        }
    }

    if (limit == nil) {
        if (_numWaitSignals > 0 || _numWaitSockets > 0) {
            limit = [NSDate distantFuture];
        }
    }

    return limit;
}

- (void)addInputSource:(NSInputSource*)source {
    if ([source isKindOfClass:[NSRunLoopSource class]]) {
        if (_numWaitSignals >= MAX_WAITSIGNALS) {
            TraceVerbose(TAG, L"Too many signal sources!  Count=%d", _numWaitSignals);
            *((char*)0xBAAFF00D) = 0;
        }
        for (int i = 0; i < _numWaitSignals; i++) {
            if (_waitSignals[i] == ((NSRunLoopSource*)source)->_signaledEvent) {
                return;
            }
        }
        _waitSignalPriority[_numWaitSignals] = [static_cast<NSRunLoopSource*>(source) priority];
        _waitSignalObjects[_numWaitSignals] = [source retain];
        _waitSignals[_numWaitSignals] = ((NSRunLoopSource*)source)->_signaledEvent;
        _numWaitSignals++;

        return;
    } else if ([source isKindOfClass:[NSSelectInputSource class]]) {
        if (_numWaitSockets >= MAX_WAITSOCKETS) {
            TraceVerbose(TAG, L"Too many socket sources!  Count=%d", _numWaitSockets);
            *((char*)0xBAAFF00D) = 0;
        }
        _waitSocketObjects[_numWaitSockets] = [source retain];
        _waitSockets[_numWaitSockets] = (int)[static_cast<NSSelectInputSource*>(source) descriptor];
        _numWaitSockets++;

        return;
    } else {
        assert(0);
    }
}

- (void)removeInputSource:(NSInputSource*)source {
    if ([source isKindOfClass:[NSRunLoopSource class]]) {
        int idx = NSNotFound;
        for (int i = 0; i < _numWaitSignals; i++) {
            if ([source isEqual:_waitSignalObjects[i]]) {
                idx = i;
                break;
            }
        }

        if (idx != NSNotFound) {
            [source release];
            memmove(&_waitSignals[idx], &_waitSignals[idx + 1], (_numWaitSignals - idx - 1) * sizeof(EbrEvent));
            memmove(&_waitSignalObjects[idx], &_waitSignalObjects[idx + 1], (_numWaitSignals - idx - 1) * sizeof(EbrEvent));
            memmove(&_waitSignalPriority[idx], &_waitSignalPriority[idx + 1], (_numWaitSignals - idx - 1) * sizeof(int));
            _numWaitSignals--;
        } else
            TraceWarning(TAG, L"Warning: requested source for removal doesn't exist");
        return;
    } else if ([source isKindOfClass:[NSSelectInputSource class]]) {
        int idx = NSNotFound;
        for (int i = 0; i < _numWaitSockets; i++) {
            if ([source isEqual:_waitSocketObjects[i]]) {
                idx = i;
                break;
            }
        }

        if (idx != NSNotFound) {
            [source release];
            memmove(&_waitSockets[idx], &_waitSockets[idx + 1], (_numWaitSockets - idx - 1) * sizeof(int));
            memmove(&_waitSocketObjects[idx], &_waitSocketObjects[idx + 1], (_numWaitSockets - idx - 1) * sizeof(id));
            _numWaitSockets--;
        } else
            TraceWarning(TAG, L"Warning: requested socket for removal doesn't exist");
        return;
    } else {
        assert(0);
    }
}

- (void)invalidateTimerWithDelayedPerform:(NSDelayedPerform*)delayed {
    int count = [_timers count];

    while (--count >= 0) {
        NSTimer* timer = [_timers objectAtIndex:count];
        NSObject* check = [timer userInfo];

        if ([check isKindOfClass:[NSDelayedPerform class]]) {
            if ([static_cast<NSDelayedPerform*>(check) isEqualToPerform:delayed]) {
                [timer invalidate];
            }
        }
    }
}

- (void)acceptInputForMode:(NSString*)mode beforeDate:(NSDate*)date {
    EbrBlockIfBackground();

    if (_numWaitSockets > 0) {
        _socks.max = 0;
        _socks.fdread = (void*)&_read;
        _socks.fdwrite = (void*)&_write;
        _socks.fderror = (void*)&_error;
        FD_ZERO(&_read);
        FD_ZERO(&_write);
        FD_ZERO(&_error);

        for (int i = 0; i < _numWaitSockets; i++) {
            int mask = ((NSSelectInputSource*)_waitSocketObjects[i])->_eventMask;
            if (mask & NSSelectReadEvent) {
                FD_SET(_waitSockets[i], &_read);
                if (_waitSockets[i] > _socks.max)
                    _socks.max = _waitSockets[i];
            }
            if (mask & NSSelectWriteEvent) {
                FD_SET(_waitSockets[i], &_write);
                if (_waitSockets[i] > _socks.max)
                    _socks.max = _waitSockets[i];
            }
            if (mask & NSSelectExceptEvent) {
                FD_SET(_waitSockets[i], &_error);
                if (_waitSockets[i] > _socks.max)
                    _socks.max = _waitSockets[i];
            }
        }

        if (!_builtWakeupSockets) {
            dumb_socketpair((SOCKET*)_wakeupSockets, 0);
            _builtWakeupSockets = true;
        }
        _socks.WakeupSocketRead = _wakeupSockets[0];
        _socks.WakeupSocketWrite = _wakeupSockets[1];
        FD_SET(_wakeupSockets[0], &_read);
        if (_wakeupSockets[0] > _socks.max) {
            _socks.max = _wakeupSockets[0];
        }
    }

    //  Go through and fire off any sources that are signaled
    bool didSignal = false;
    for (int i = 0; i < _numWaitSignals; i++) {
        if (EbrEventTryWait(_waitSignals[i])) {
            [_waitSignalObjects[i] fire];
            didSignal = true;
        }
    }

    if (didSignal) {
        if ([NSThread currentThread] == [NSThread mainThread]) {
            // Do an yield with zero timeout so the runloop can be scheduled again.
            g_UIEventMainRunLoopTimedMultipleWaitCallback(nullptr, 0, 0, nullptr);
        }
        return;
    }

    double timeout = [date timeIntervalSinceNow];
    double nextDispatchTimer;

    if ([NSThread currentThread] == [NSThread mainThread]) {
        //  Wake up early to service any dispatch timers
        if (GetMainDispatchTimerTimeout(&nextDispatchTimer)) {
            timeout = nextDispatchTimer;
        }
    }
    if (timeout > 60 * 60 * 24)
        timeout = 60 * 60 * 24;
    if (timeout < 0)
        timeout = 0;
    if (timeout > 0) {
        [self _notifyObservers:kCFRunLoopBeforeWaiting];
    }

    int signaled = 0;
    if ([NSThread currentThread] == [NSThread mainThread]) {
        //  If we're on the UI thread, call UIEventTimedMultipleWait, which will yield and schedule
        // the runloop to run again.
        g_UIEventMainRunLoopTimedMultipleWaitCallback(_waitSignals, _numWaitSignals, timeout, _numWaitSockets > 0 ? &_socks : NULL);
    } else {
        signaled = EbrEventTimedMultipleWait(_waitSignals, _numWaitSignals, timeout, _numWaitSockets > 0 ? &_socks : NULL);
        [self _handleSignaledInput:signaled];
    }
}

- (void)_handleSignaledInput:(int)signaled {
    if (signaled != -1) {
        [_waitSignalObjects[signaled] fire];
    }

    if (_numWaitSockets > 0 && _socks.result > 0) {
        for (int i = 0; i < _numWaitSockets; i++) {
            int mask = ((NSSelectInputSource*)_waitSocketObjects[i])->_eventMask;
            if (mask & NSSelectReadEvent) {
                if (FD_ISSET(_waitSockets[i], &_read)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectReadEvent];
                }
            }
            if (mask & NSSelectWriteEvent) {
                if (FD_ISSET(_waitSockets[i], &_write)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectWriteEvent];
                }
            }
            if (mask & NSSelectExceptEvent) {
                if (FD_ISSET(_waitSockets[i], &_error)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectExceptEvent];
                }
            }
        }
    }
}

- (NSString*)description {
    return [NSString stringWithFormat:@"%@, %i inputSources %i sockets", [super description], _numWaitSignals, _numWaitSockets];
}

+ (void)setUIThreadMainRunLoopWaitFunction:(int (*)(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets))callback {
    g_UIEventMainRunLoopTimedMultipleWaitCallback = callback;
}
@end
