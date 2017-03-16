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

#include <Windows.h>
#include <winsock2.h>
#include <sys/time.h>

#define PTW32_TIMESPEC_TO_FILETIME_OFFSET (((LONGLONG)27111902 << 32) + (LONGLONG)3577643008)

static void filetime_to_timeval(const FILETIME* ft, struct timeval* ts) {
    ts->tv_sec = (int)((*(LONGLONG*)ft - PTW32_TIMESPEC_TO_FILETIME_OFFSET) / 10000000);
    ts->tv_usec = (int)((*(LONGLONG*)ft - PTW32_TIMESPEC_TO_FILETIME_OFFSET - ((LONGLONG)ts->tv_sec * (LONGLONG)10000000)) / 10);
}

extern "C" int gettimeofday(struct timeval* tv, struct timezone* tz) {
    FILETIME ft;

    GetSystemTimeAsFileTime(&ft);

    if (tv) {
        filetime_to_timeval(&ft, tv);
    }

    return 0;
}
