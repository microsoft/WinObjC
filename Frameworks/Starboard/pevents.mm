/* Source: https://github.com/NeoSmart/PEvents */

/*
Copyright (C) 2011 - 2012 by NeoSmart Technologies <http://neosmart.net/>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*
* WIN32 Events for POSIX
* Author: Mahmoud Al-Qudsi <mqudsi@neosmart.net>
* Copyright (C) 2011 - 2012 by NeoSmart Technologies
* This code is released under the terms of the MIT License
*/

#include <winsock2.h>
#include "Starboard.h"
#include "pevents.h"
#include <assert.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/timespec.h>
#ifdef WFMO
#include <algorithm>
#include <deque>
#endif

namespace neosmart {
#ifdef WFMO
struct neosmart_wfmo_t_ {
    pthread_mutex_t Mutex;
    pthread_cond_t CVariable;
    union {
        int FiredEvent; // WFSO
        int EventsLeft; // WFMO
    } Status;
    bool StillWaiting;
    int RefCount;
    bool WaitAll;
    int WakeupSocket;

    void Destroy() {
        int ret = pthread_mutex_destroy(&Mutex);
        if (ret != 0) {
            EbrDebugLog("pevents mutex destroy error: %d", ret);
        }

        ret = pthread_cond_destroy(&CVariable);

        if (ret != 0) {
            EbrDebugLog("pevents cond destroy error: %d", ret);
        }
    }
};
typedef neosmart_wfmo_t_* neosmart_wfmo_t;

struct neosmart_wfmo_info_t_ {
    neosmart_wfmo_t Waiter;
    int WaitIndex;
};
typedef neosmart_wfmo_info_t_* neosmart_wfmo_info_t;
#endif

struct neosmart_event_t_ {
    bool AutoReset;
    pthread_cond_t CVariable;
    pthread_mutex_t Mutex;
    bool State;
#ifdef WFMO
    std::deque<neosmart_wfmo_info_t_> RegisteredWaits;
#endif
};

#ifdef WFMO
bool RemoveExpiredWaitHelper(neosmart_wfmo_info_t_ wait) {
    int result = pthread_mutex_trylock(&wait.Waiter->Mutex);

    if (result == EBUSY) {
        return false;
    }

    assert(result == 0);

    if (wait.Waiter->StillWaiting == false) {
        --wait.Waiter->RefCount;
        assert(wait.Waiter->RefCount >= 0);
        if (wait.Waiter->RefCount == 0) {
            result = pthread_mutex_unlock(&wait.Waiter->Mutex);
            assert(result == 0);
            wait.Waiter->Destroy();
            delete wait.Waiter;
        } else {
            result = pthread_mutex_unlock(&wait.Waiter->Mutex);
            assert(result == 0);
        }

        return true;
    }

    result = pthread_mutex_unlock(&wait.Waiter->Mutex);
    assert(result == 0);

    return false;
}
#endif

neosmart_event_t NeoCreateEvent(bool manualReset, bool initialState) {
    neosmart_event_t event = new neosmart_event_t_;

    int result = pthread_cond_init(&event->CVariable, 0);
    assert(result == 0);

    result = pthread_mutex_init(&event->Mutex, 0);
    assert(result == 0);

    event->State = false;
    event->AutoReset = !manualReset;

    if (initialState) {
        result = SetEvent(event);
        assert(result == 0);
    }

    return event;
}

int UnlockedWaitForEvent(neosmart_event_t event, uint64_t milliseconds) {
    int result = 0;
    if (!event->State) {
        // Zero-timeout event state check optimization
        if (milliseconds == 0) {
            return ETIMEDOUT;
        }

        timespec ts;
        if (milliseconds != (uint64_t)-1) {
            EbrTimeval tv;
            EbrGetTimeOfDay(&tv);

            uint64_t nanoseconds =
                ((uint64_t)tv.tv_sec) * 1000 * 1000 * 1000 + milliseconds * 1000 * 1000 + ((uint64_t)tv.tv_usec) * 1000;

            ts.tv_sec = long(nanoseconds / 1000 / 1000 / 1000);
            ts.tv_nsec = long(nanoseconds - ((uint64_t)ts.tv_sec) * 1000 * 1000 * 1000);
        }

        do {
            // Regardless of whether it's an auto-reset or manual-reset event:
            // wait to obtain the event, then lock anyone else out
            if (milliseconds != (uint64_t)-1) {
                result = pthread_cond_timedwait(&event->CVariable, &event->Mutex, &ts);
            } else {
                result = pthread_cond_wait(&event->CVariable, &event->Mutex);
            }
        } while (result == 0 && !event->State);

        if (result == 0 && event->AutoReset) {
            // We've only accquired the event if the wait succeeded
            event->State = false;
        }
    } else if (event->AutoReset) {
        // It's an auto-reset event that's currently available;
        // we need to stop anyone else from using it
        result = 0;
        event->State = false;
    }
    // Else we're trying to obtain a manual reset event with a signalled state;
    // don't do anything

    return result;
}

int WaitForEvent(neosmart_event_t event, uint64_t milliseconds) {
    int tempResult;
    if (milliseconds == 0) {
        tempResult = pthread_mutex_trylock(&event->Mutex);
        if (tempResult == EBUSY) {
            return ETIMEDOUT;
        }
    } else {
        tempResult = pthread_mutex_lock(&event->Mutex);
    }

    assert(tempResult == 0);

    int result = UnlockedWaitForEvent(event, milliseconds);

    tempResult = pthread_mutex_unlock(&event->Mutex);
    assert(tempResult == 0);

    return result;
}

#ifdef WFMO
int WaitForMultipleEvents(neosmart_event_t* events, int count, bool waitAll, uint64_t milliseconds) {
    int unused;
    return WaitForMultipleEvents(events, count, waitAll, milliseconds, unused, NULL);
}

int WaitForMultipleEvents(
    neosmart_event_t* events, int count, bool waitAll, uint64_t milliseconds, int& waitIndex, SocketWait* sockets) {
    neosmart_wfmo_t wfmo = new neosmart_wfmo_t_;

    int result = 0;
    int tempResult = pthread_mutex_init(&wfmo->Mutex, 0);
    assert(tempResult == 0);

    tempResult = pthread_cond_init(&wfmo->CVariable, 0);
    assert(tempResult == 0);

    neosmart_wfmo_info_t_ waitInfo;
    waitInfo.Waiter = wfmo;
    waitInfo.WaitIndex = -1;

    wfmo->WaitAll = waitAll;
    wfmo->StillWaiting = true;
    wfmo->RefCount = 1;
    wfmo->WakeupSocket = -1;
    if (sockets) {
        wfmo->WakeupSocket = sockets->WakeupSocketWrite;
        sockets->result = -1;
    }

    if (waitAll) {
        wfmo->Status.EventsLeft = count;
    } else {
        wfmo->Status.FiredEvent = -1;
    }

    tempResult = pthread_mutex_lock(&wfmo->Mutex);
    assert(tempResult == 0);

    bool done = false;
    waitIndex = -1;

    for (int i = 0; i < count; ++i) {
        waitInfo.WaitIndex = i;

        // Must not release lock until RegisteredWait is potentially added
        tempResult = pthread_mutex_lock(&events[i]->Mutex);
        assert(tempResult == 0);

        // Before adding this wait to the list of registered waits, let's clean up old, expired waits while we have the
        // event lock anyway
        events[i]->RegisteredWaits.erase(std::remove_if(events[i]->RegisteredWaits.begin(),
                                                        events[i]->RegisteredWaits.end(),
                                                        RemoveExpiredWaitHelper),
                                         events[i]->RegisteredWaits.end());

        if (UnlockedWaitForEvent(events[i], 0) == 0) {
            tempResult = pthread_mutex_unlock(&events[i]->Mutex);
            assert(tempResult == 0);

            if (waitAll) {
                --wfmo->Status.EventsLeft;
                assert(wfmo->Status.EventsLeft >= 0);
            } else {
                wfmo->Status.FiredEvent = i;
                waitIndex = i;
                done = true;
                break;
            }
        } else {
            events[i]->RegisteredWaits.push_back(waitInfo);
            ++wfmo->RefCount;

            tempResult = pthread_mutex_unlock(&events[i]->Mutex);
            assert(tempResult == 0);
        }
    }

    timespec ts;
    if (!done) {
        if (milliseconds == 0) {
            result = ETIMEDOUT;
            done = true;
        } else if (milliseconds != (uint64_t)-1) {
            EbrTimeval tv;
            EbrGetTimeOfDay(&tv);

            uint64_t nanoseconds =
                ((uint64_t)tv.tv_sec) * 1000 * 1000 * 1000 + milliseconds * 1000 * 1000 + ((uint64_t)tv.tv_usec) * 1000;

            ts.tv_sec = long(nanoseconds / 1000 / 1000 / 1000);
            ts.tv_nsec = long(nanoseconds - ((uint64_t)ts.tv_sec) * 1000 * 1000 * 1000);
        }
    }

    while (!done) {
        // One (or more) of the events we're monitoring has been triggered?

        // If we're waiting for all events, assume we're done and check if there's an event that hasn't fired
        // But if we're waiting for just one event, assume we're not done until we find a fired event
        done = (waitAll && wfmo->Status.EventsLeft == 0) || (!waitAll && wfmo->Status.FiredEvent != -1);

        if (!done) {
            if (milliseconds != (uint64_t)-1) {
                if (wfmo->WakeupSocket != -1) {
                    pthread_mutex_unlock(&wfmo->Mutex);
                    struct __ws2_timeval tv;
                    tv.tv_sec = long(milliseconds / 1000);
                    tv.tv_usec = (milliseconds % 1000) * 1000;
                    int selectResult = select(sockets->max + 1,
                                              (fd_set*)sockets->fdread,
                                              (fd_set*)sockets->fdwrite,
                                              (fd_set*)sockets->fderror,
                                              &tv);
                    pthread_mutex_lock(&wfmo->Mutex);
                    if (selectResult == -1) {
                        //  Timeout or error
                        result = -1;
                    } else {
                        if (FD_ISSET(sockets->WakeupSocketRead, (fd_set*)sockets->fdread)) {
                            //  Clear the socket
                            char buf[256];
                            while (recv(sockets->WakeupSocketRead, buf, 256, 0) == 256)
                                ;
                            result = 0;
                        } else {
                            sockets->result = selectResult;
                            result = -1;
                        }
                    }
                } else {
                    result = pthread_cond_timedwait(&wfmo->CVariable, &wfmo->Mutex, &ts);
                }
            } else {
                result = pthread_cond_wait(&wfmo->CVariable, &wfmo->Mutex);
            }

            if (result != 0) {
                break;
            }
        }
    }

    waitIndex = wfmo->Status.FiredEvent;
    if (waitIndex != -1) {
        result = 0;
    }
    wfmo->StillWaiting = false;

    --wfmo->RefCount;
    assert(wfmo->RefCount >= 0);
    if (wfmo->RefCount == 0) {
        pthread_mutex_unlock(&wfmo->Mutex);

        wfmo->Destroy();
        delete wfmo;
    } else {
        tempResult = pthread_mutex_unlock(&wfmo->Mutex);
        assert(tempResult == 0);
    }

    return result;
}
#endif

int DestroyEvent(neosmart_event_t event) {
    int result = pthread_mutex_lock(&event->Mutex);
    assert(result == 0);

#ifdef WFMO
    while (!event->RegisteredWaits.empty()) {
        neosmart_wfmo_info_t i = &event->RegisteredWaits.front();

        result = pthread_mutex_lock(&i->Waiter->Mutex);
        assert(result == 0);

        --i->Waiter->RefCount;
        assert(i->Waiter->RefCount >= 0);
        if (i->Waiter->RefCount == 0) {
            pthread_mutex_unlock(&i->Waiter->Mutex);
            i->Waiter->Destroy();
            delete i->Waiter;
        } else {
            result = pthread_mutex_unlock(&i->Waiter->Mutex);
            assert(result == 0);
        }
        event->RegisteredWaits.pop_front();
    }
#endif
    result = pthread_mutex_unlock(&event->Mutex);
    assert(result == 0);

    result = pthread_cond_destroy(&event->CVariable);
    assert(result == 0);

    result = pthread_mutex_destroy(&event->Mutex);
    assert(result == 0);

    delete event;

    return 0;
}

int SetEvent(neosmart_event_t event) {
    int result = pthread_mutex_lock(&event->Mutex);
    assert(result == 0);

    event->State = true;

    // Depending on the event type, we either trigger everyone or only one
    if (event->AutoReset) {
#ifdef WFMO
        while (!event->RegisteredWaits.empty()) {
            neosmart_wfmo_info_t i = &event->RegisteredWaits.front();

            result = pthread_mutex_lock(&i->Waiter->Mutex);
            assert(result == 0);

            --i->Waiter->RefCount;
            assert(i->Waiter->RefCount >= 0);
            if (!i->Waiter->StillWaiting) {
                if (i->Waiter->RefCount == 0) {
                    pthread_mutex_unlock(&i->Waiter->Mutex);
                    i->Waiter->Destroy();
                    delete i->Waiter;
                } else {
                    result = pthread_mutex_unlock(&i->Waiter->Mutex);
                    assert(result == 0);
                }
                event->RegisteredWaits.pop_front();
                continue;
            }

            event->State = false;

            if (i->Waiter->WaitAll) {
                --i->Waiter->Status.EventsLeft;
                assert(i->Waiter->Status.EventsLeft >= 0);
                // We technically should do i->Waiter->StillWaiting = Waiter->Status.EventsLeft != 0
                // but the only time it'll be equal to zero is if we're the last event, so no one
                // else will be checking the StillWaiting flag. We're good to go without it.
            } else {
                i->Waiter->Status.FiredEvent = i->WaitIndex;
                i->Waiter->StillWaiting = false;
            }

            //  Kick the socket if it has one
            if (i->Waiter->WakeupSocket != -1) {
                send(i->Waiter->WakeupSocket, "x", 1, 0);
            }

            result = pthread_cond_signal(&i->Waiter->CVariable);
            assert(result == 0);

            result = pthread_mutex_unlock(&i->Waiter->Mutex);
            assert(result == 0);

            event->RegisteredWaits.pop_front();

            result = pthread_mutex_unlock(&event->Mutex);
            assert(result == 0);

            return 0;
        }
#endif
        // event->State can be false if compiled with WFMO support
        if (event->State) {
            result = pthread_cond_signal(&event->CVariable);
            assert(result == 0);

            result = pthread_mutex_unlock(&event->Mutex);
            assert(result == 0);

            return 0;
        }
    } else {
        //
        *((char*)0xBAADF00D) = 0;
#ifdef WFMO
#if 0
for(size_t i = 0; i < event->RegisteredWaits.size(); ++i)
{
neosmart_wfmo_info_t info = &event->RegisteredWaits[i];

result = pthread_mutex_lock(&info->Waiter->Mutex);
assert(result == 0);

--info->Waiter->RefCount;
assert(info->Waiter->RefCount >= 0);

if(!info->Waiter->StillWaiting)
{
if(info->Waiter->RefCount == 0)
{
pthread_mutex_unlock(&info->Waiter->Mutex);
info->Waiter->Destroy();
delete info->Waiter;
}
else
{
result = pthread_mutex_unlock(&info->Waiter->Mutex);
assert(result == 0);
}
continue;
}

if(info->Waiter->WaitAll)
{
--info->Waiter->Status.EventsLeft;
assert(info->Waiter->Status.EventsLeft >= 0);
//We technically should do i->Waiter->StillWaiting = Waiter->Status.EventsLeft != 0
//but the only time it'll be equal to zero is if we're the last event, so no one
//else will be checking the StillWaiting flag. We're good to go without it.
}
else
{
info->Waiter->Status.FiredEvent = info->WaitIndex;
info->Waiter->StillWaiting = false;
}

result = pthread_cond_signal(&info->Waiter->CVariable);
assert(result == 0);

result = pthread_mutex_unlock(&info->Waiter->Mutex);
assert(result == 0);
}
event->RegisteredWaits.clear();
#endif
        result = pthread_cond_broadcast(&event->CVariable);
        assert(result == 0);

        result = pthread_mutex_unlock(&event->Mutex);
        assert(result == 0);
#endif
    }

    return 0;
}

int ResetEvent(neosmart_event_t event) {
    int result = pthread_mutex_lock(&event->Mutex);
    assert(result == 0);

    event->State = false;

    result = pthread_mutex_unlock(&event->Mutex);
    assert(result == 0);

    return 0;
}
}
