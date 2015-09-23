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

#include "gtest-api.h"
#include <windows.h>

#import <CoreFoundation/CoreFoundation.h>
#import <mach/mach_time.h>

TEST(CoreFoundation, SanityTest) {
    uint64_t start = mach_absolute_time();
    ::Sleep(1500);
    uint64_t end = mach_absolute_time();
    struct mach_timebase_info elapsed;

    ASSERT_EQ_MSG(
        mach_timebase_info(&elapsed), KERN_SUCCESS,
        "mach_timebase_info failed");

    uint64_t elapsedNS = (end - start) * elapsed.numer / elapsed.denom;
    int64_t diff = elapsedNS - 1500000000LL;

    if ( diff < 0 )
    {
        diff = -diff;
    }

    LOG_INFO("mach_absolute_time jitter: %lldns ", diff);

    ASSERT_FALSE_MSG(
        diff > 20000000,
        "FAILED: mach_absolute_time drift too high (%llu, %llu, %d, %d)",
        start, 
        end,
        elapsed.numer,
        elapsed.denom);
}