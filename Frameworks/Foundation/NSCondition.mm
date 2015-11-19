/* Copyright (c) 2010 Sven Weidauer

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Starboard.h"
#include "Platform/EbrPlatform.h"
#include "Foundation/NSLock.h"

#include <math.h>
#include <pthread.h>

#ifdef NEEDTIMESPEC
struct timespec {
    long tv_sec;
    long tv_nsec;
};
#endif

#ifndef WIN32
#include <errno.h>
#endif

struct _mach_timeval {
    long tv_sec;
    long tv_usec;
};

@implementation NSCondition {
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
    idretaintype(NSString) _name;
}
- (instancetype)init {
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_cond, NULL);
    return self;
}

- (void)dealloc {
    int ret = pthread_mutex_destroy(&_mutex);
    assert(ret == 0);
    ret = pthread_cond_destroy(&_cond);
    assert(ret == 0);
    [super dealloc];
}

- (void)lock {
    pthread_mutex_lock(&_mutex);
}

- (void)unlock {
    pthread_mutex_unlock(&_mutex);
}

/**
 @Status Interoperable
*/
- (void)signal {
    pthread_cond_signal(&_cond);
}

/**
 @Status Interoperable
*/
- (void)broadcast {
    pthread_cond_broadcast(&_cond);
}

/**
 @Status Interoperable
*/
- (void)wait {
    pthread_cond_wait(&_cond, &_mutex);
}

/**
 @Status Interoperable
*/
- (BOOL)waitUntilDate:(NSDate*)date {
    int rc;
    struct timespec t = { 0 };
    struct EbrTimeval tv;
    NSTimeInterval d = [date timeIntervalSinceNow];

    EbrGetTimeOfDay(&tv);

    t.tv_sec = tv.tv_sec;
    t.tv_nsec = tv.tv_usec * 1000;

    t.tv_sec += (unsigned int)d;
    t.tv_nsec = (long)((double)t.tv_nsec + fmod(d, 1.0) * 1000000000.0);

    t.tv_sec += t.tv_nsec / 1000000000;
    t.tv_nsec %= 1000000000;

    switch ((rc = pthread_cond_timedwait(&_cond, &_mutex, &t))) {
        case 0:
            return YES;

        case 0x274c /* ETIMEDOUT in ios */:
            if ((rc = pthread_mutex_unlock(&_mutex)) != 0) {
                [NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
            }
            return NO;

        default:
            if ((rc = pthread_mutex_unlock(&_mutex)) != 0) {
                [NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
            }
            [NSException raise:NSInvalidArgumentException format:@"failed to lock %@ before date %@ (errno: %d)", self, date, rc];
            return NO;
    }
}

/**
 @Status Interoperable
*/
- (void)setName:(NSString*)newName {
    _name.attach([newName copy]);
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return _name;
}
@end

@implementation NSConditionLock {
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;
    idretaintype(NSString) _name;
    NSInteger _value;
}

+ (instancetype)alloc {
    NSConditionLock* ret = [super alloc];
    return ret;
}

- (instancetype)init {
    return [self initWithCondition:0];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCondition:(NSInteger)value {
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_cond, NULL);
    _value = value;

    return self;
}

/**
 @Status Interoperable
*/
- (NSInteger)condition {
    return _value;
}

- (void)dealloc {
    int ret = pthread_mutex_destroy(&_mutex);
    assert(ret == 0);
    ret = pthread_cond_destroy(&_cond);
    assert(ret == 0);
    [super dealloc];
}

- (void)lock {
    pthread_mutex_lock(&_mutex);
}

- (void)unlock {
    pthread_mutex_unlock(&_mutex);
}

- (void)signal {
    pthread_cond_signal(&_cond);
}

- (void)broadcast {
    pthread_cond_broadcast(&_cond);
}

- (void)wait {
    pthread_cond_wait(&_cond, &_mutex);
}

- (BOOL)tryLock {
    return pthread_mutex_trylock(&_mutex) == 0;
}

- (void)lockWhenCondition:(NSInteger)condition {
    int rc;

    if ((rc = pthread_mutex_lock(&_mutex)) != 0) {
        [NSException raise:NSInvalidArgumentException format:@"failed to lock %@ (errno: %d)", self, rc];
    }

    while (_value != condition) {
        switch ((rc = pthread_cond_wait(&_cond, &_mutex))) {
            case 0:
                break;

            default:
                if ((rc = pthread_mutex_unlock(&_mutex)) != 0) {
                    [NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
                }
                [NSException raise:NSInvalidArgumentException format:@"failed to lock %@ (errno: %d)", self, rc];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)unlockWithCondition:(NSInteger)condition {
    _value = condition;
    int rc;
    if ((rc = pthread_cond_broadcast(&_cond)) != 0) {
        [NSException raise:NSInvalidArgumentException format:@"failed to broadcast %@ (errno: %d)", self, rc];
    }
    if ((rc = pthread_mutex_unlock(&_mutex)) != 0) {
        [NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
    }
}

/**
 @Status Interoperable
*/
- (void)setName:(NSString*)newName {
    _name = newName;
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return _name;
}
@end
