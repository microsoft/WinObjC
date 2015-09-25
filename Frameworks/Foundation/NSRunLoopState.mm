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

#include <WinSock2.h>
#undef WIN32

#include "Starboard.h"
#include "CoreFoundation/CFRunLoop.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSDate.h"
#include "NSRunLoopState.h"
#include "NSRunLoopSource.h"
#include "NSDelayedPerform.h"
#include "NSSelectInputSource.h"
#include "dispatch/dispatch.h"
#include "sys/timespec.h"

int (*UIEventTimedMultipleWaitCallback)(EbrEvent* events,
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

@implementation NSRunLoopState : NSObject
- (NSObject*)init {
    _timers = [NSMutableArray new];
    _observers = [NSMutableArray new];
    _cancelSource = (NSInputSource*)[NSRunLoopSource new];
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
            [_timers _moveObjectAtIndexToEnd:i];
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
            EbrDebugLog("Too many signal sources!  Count=%d\n", _numWaitSignals);
            *((char*)0xBAAFF00D) = 0;
        }
        for (int i = 0; i < _numWaitSignals; i++) {
            if (_waitSignals[i] == ((NSRunLoopSource*)source)->_signaledEvent) {
                return;
            }
        }
        _waitSignalPriority[_numWaitSignals] = [source priority];
        _waitSignalObjects[_numWaitSignals] = [source retain];
        _waitSignals[_numWaitSignals] = ((NSRunLoopSource*)source)->_signaledEvent;
        _numWaitSignals++;

        return;
    } else if ([source isKindOfClass:[NSSelectInputSource class]]) {
        if (_numWaitSockets >= MAX_WAITSOCKETS) {
            EbrDebugLog("Too many socket sources!  Count=%d\n", _numWaitSockets);
            *((char*)0xBAAFF00D) = 0;
        }
        _waitSocketObjects[_numWaitSockets] = [source retain];
        _waitSockets[_numWaitSockets] = (int)[source descriptor];
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
            memmove(
                &_waitSignalObjects[idx], &_waitSignalObjects[idx + 1], (_numWaitSignals - idx - 1) * sizeof(EbrEvent));
            memmove(
                &_waitSignalPriority[idx], &_waitSignalPriority[idx + 1], (_numWaitSignals - idx - 1) * sizeof(int));
            _numWaitSignals--;
        } else
            EbrDebugLog("Warning: requested source for removal doesn't exist\n");
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
            EbrDebugLog("Warning: requested socket for removal doesn't exist\n");
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
            if ([check isEqualToPerform:delayed]) {
                [timer invalidate];
            }
        }
    }
}

- (void)acceptInputForMode:(NSString*)mode beforeDate:(NSDate*)date {
    EbrBlockIfBackground();

    SocketWait socks;
    fd_set read, write, error;

    if (_numWaitSockets > 0) {
        socks.max = 0;
        socks.fdread = (void*)&read;
        socks.fdwrite = (void*)&write;
        socks.fderror = (void*)&error;
        FD_ZERO(&read);
        FD_ZERO(&write);
        FD_ZERO(&error);

        for (int i = 0; i < _numWaitSockets; i++) {
            int mask = ((NSSelectInputSource*)_waitSocketObjects[i])->_eventMask;
            if (mask & NSSelectReadEvent) {
                FD_SET(_waitSockets[i], &read);
                if (_waitSockets[i] > socks.max)
                    socks.max = _waitSockets[i];
            }
            if (mask & NSSelectWriteEvent) {
                FD_SET(_waitSockets[i], &write);
                if (_waitSockets[i] > socks.max)
                    socks.max = _waitSockets[i];
            }
            if (mask & NSSelectExceptEvent) {
                FD_SET(_waitSockets[i], &error);
                if (_waitSockets[i] > socks.max)
                    socks.max = _waitSockets[i];
            }
        }

        if (!_builtWakeupSockets) {
            dumb_socketpair((SOCKET*)_wakeupSockets, 0);
            _builtWakeupSockets = true;
        }
        socks.WakeupSocketRead = _wakeupSockets[0];
        socks.WakeupSocketWrite = _wakeupSockets[1];
        FD_SET(_wakeupSockets[0], &read);
        if (_wakeupSockets[0] > socks.max) {
            socks.max = _wakeupSockets[0];
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
            // Yield to UI thread so it can continue XAML event loop:
            UIEventTimedMultipleWaitCallback(nullptr, 0, 0, nullptr);
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

#ifdef USE_KHR_RENDERBUFFERS
    EbrSignalsSafe();
#endif

    int signaled = 0;
    if ([NSThread currentThread] == [NSThread mainThread]) {
        //  If we're blocking on the UI thread, call UIEventTimedMultipleWait,
        //  which will yield to any other UI dispatcher (such as Xaml)
        signaled = UIEventTimedMultipleWaitCallback(
            _waitSignals, _numWaitSignals, timeout, _numWaitSockets > 0 ? &socks : NULL);
    } else {
        signaled =
            EbrEventTimedMultipleWait(_waitSignals, _numWaitSignals, timeout, _numWaitSockets > 0 ? &socks : NULL);
    }

#ifdef USE_KHR_RENDERBUFFERS
    EbrSignalsUnsafe();
#endif

    if (signaled != -1) {
        [_waitSignalObjects[signaled] fire];
    }

    if (_numWaitSockets > 0 && socks.result > 0) {
        for (int i = 0; i < _numWaitSockets; i++) {
            int mask = ((NSSelectInputSource*)_waitSocketObjects[i])->_eventMask;
            if (mask & NSSelectReadEvent) {
                if (FD_ISSET(_waitSockets[i], &read)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectReadEvent];
                }
            }
            if (mask & NSSelectWriteEvent) {
                if (FD_ISSET(_waitSockets[i], &write)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectWriteEvent];
                }
            }
            if (mask & NSSelectExceptEvent) {
                if (FD_ISSET(_waitSockets[i], &error)) {
                    [_waitSocketObjects[i] processImmediateEvents:NSSelectExceptEvent];
                }
            }
        }
    }
}

- (NSString*)description {
    return [NSString
        stringWithFormat:@"%@, %i inputSources %i sockets", [super description], _numWaitSignals, _numWaitSockets];
}

+ (void)setUIThreadWaitFunction:
    (int (*)(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets))callback {
    UIEventTimedMultipleWaitCallback = callback;
}
@end
