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
#include "Platform/EbrPlatform.h"
#include "Foundation/NSLock.h"

#include <math.h>
#include <pthread.h>

#ifdef NEEDTIMESPEC
struct timespec
{
    long tv_sec;
    long tv_nsec;
};
#endif

#ifndef WIN32
#include <errno.h>
#endif

struct _mach_timeval
{
    long        tv_sec;
    long        tv_usec;
};

@implementation NSCondition
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    idretain _name;
}

    +(id) /* use typed version */ alloc {
        NSCondition* ret = [super alloc];

        pthread_mutex_init(&ret->mutex, NULL);
        pthread_cond_init(&ret->cond, NULL);
        return ret;
    }

    -(void) dealloc {
        int ret = pthread_mutex_destroy(&mutex);
        assert(ret == 0);
        ret = pthread_cond_destroy(&cond);
        assert(ret == 0);
        [super dealloc];
    }

    -(id) /* use typed version */ lock {
        pthread_mutex_lock(&mutex);

        return self;
    }

    -(id) /* use typed version */ unlock {
        pthread_mutex_unlock(&mutex);

        return self;
    }

    -(id) /* use typed version */ signal {
        pthread_cond_signal(&cond);

        return self;
    }

    -(id) /* use typed version */ broadcast {
        pthread_cond_broadcast(&cond);

        return self;
    }

    -(id) /* use typed version */ wait {
        pthread_cond_wait(&cond, &mutex);

        return self;
    }

    -(BOOL) waitUntilDate:(id)date {
        int rc;
        struct timespec t={0};
        struct EbrTimeval tv;
        NSTimeInterval d = [date timeIntervalSinceNow];

        EbrGetTimeOfDay(&tv);

        t.tv_sec = tv.tv_sec;
        t.tv_nsec = tv.tv_usec * 1000;

        t.tv_sec +=(unsigned int)d;
        t.tv_nsec = (long)((double)t.tv_nsec + fmod(d, 1.0)*1000000000.0);

        t.tv_sec += t.tv_nsec / 1000000000;
        t.tv_nsec %= 1000000000;

        switch ((rc = pthread_cond_timedwait(&cond, &mutex, &t))) {
            case 0:
                return YES;

            case 0x274c /* ETIMEDOUT in ios */:
                /*
                if((rc = pthread_mutex_unlock(&mutex)) != 0) {
                    //[NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
                    assert(0);
                }
                */
                return NO;

            default:
                if((rc = pthread_mutex_unlock(&mutex)) != 0) {
                    //[NSException raise:NSInvalidArgumentException format:@"failed to unlock %@ (errno: %d)", self, rc];
                }
                //[NSException raise:NSInvalidArgumentException format:@"failed to lock %@ before date %@ (errno: %d)", self, date, rc];
                assert(0);
                return NO;
        }
    }

    /* annotate with type */ -(void) setName:(id)newName {
        _name = newName;
    }

    /* annotate with type */ -(id) name {
        return _name;
    }

    
@end

