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

#include <windows.h>
#include <errno.h>
#include <stdio.h>
#include <io.h>
#include <assert.h>
#include <stdlib.h>
#include <direct.h>
#include <sys\stat.h>
#include <sys\time.h>
#include <map>
#include <regex>

#include "Platform/EbrPlatform.h"
#include "Starboard.h"
#include <pthread.h>
#include "pevents.h"
#include "PathMapper.h"
#include "LoggingNative.h"

void EbrBlockIfBackground() {
}

void EbrEventInit(EbrEvent* pEvent) {
    *pEvent = (void*)neosmart::NeoCreateEvent(false, false);
}

void EbrEventSignal(EbrEvent event) {
    neosmart::SetEvent((neosmart::neosmart_event_t)event);
}

void EbrEventWait(EbrEvent event) {
    neosmart::WaitForEvent((neosmart::neosmart_event_t)event);
}

bool EbrEventTryWait(EbrEvent event) {
    if (neosmart::WaitForEvent((neosmart::neosmart_event_t)event, 0) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

bool EbrEventTimedWait(EbrEvent event, double seconds) {
    if (neosmart::WaitForEvent((neosmart::neosmart_event_t)event, seconds * 1000.0) != 0) {
        return FALSE;
    }

    return TRUE;
}

int EbrEventTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets) {
    int signaledEvent;
    if (neosmart::WaitForMultipleEvents(
            (neosmart::neosmart_event_t*)events, numEvents, false, (uint64_t)(timeout * 1000.0), signaledEvent, sockets) != 0) {
        return -1;
    }

    return signaledEvent;
}

void EbrEventDestroy(EbrEvent event) {
    neosmart::DestroyEvent((neosmart::neosmart_event_t)event);
}

int EbrGetWantedOrientation() {
    return 1;
}

int EbrIncrement(int volatile* var) {
    return InterlockedIncrement((volatile LONG*)var);
}

int EbrDecrement(int volatile* var) {
    return InterlockedDecrement((volatile LONG*)var);
}

int EbrCompareExchange(int volatile* Destination, int Exchange, int Comperand) {
    return InterlockedCompareExchange((volatile LONG*)Destination, Exchange, Comperand);
}

void EbrSleep(__int64 nanoseconds) {
    EbrBlockIfBackground();
    Sleep((DWORD)(nanoseconds / 1000000LL));
}

extern "C" int gettimeofday(struct timeval* tv, struct timezone* tz);

int EbrGetTimeOfDay(struct EbrTimeval* curtime) {
    timeval tv;
    gettimeofday(&tv, nullptr);

    curtime->tv_sec = tv.tv_sec;
    curtime->tv_usec = tv.tv_usec;

    return 0;
}

__int64 startTime;

double EbrGetMediaTime() {
    unsigned __int64 curTime, curFreq;

    double ret;

    do {
        BOOL success = QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
        assert(success == TRUE);
        success = QueryPerformanceFrequency((LARGE_INTEGER*)&curFreq);
        assert(success == TRUE);

        // curFreq *= 2;

        if (startTime == 0) {
            startTime = curTime;
        }
        curTime -= startTime;

        ret = ((double)curTime) / ((double)curFreq);
    } while (ret != ret); //  avoids QNAN

    return ret;
}

extern "C" int EbrAssert(const char* expr, const char* file, int line) {
    printf("Assertion %s:%d: %s\n", file, line, expr);
    return 0;
}
