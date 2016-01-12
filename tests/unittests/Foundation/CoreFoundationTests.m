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

#include <TestFramework.h>
#include <windows.h>

#import <CoreFoundation/CoreFoundation.h>
#import <mach/mach_time.h>

static uint64_t walltime(const struct mach_timebase_info& timebase, uint64_t value) {
    return static_cast<uint64_t>((static_cast<double>(value) * static_cast<double>(timebase.numer)) / static_cast<double>(timebase.denom));
}

TEST(CoreFoundation, mach_absolute_time) {
    struct mach_timebase_info timebase {
        0, 0
    };
    ASSERT_EQ(0, mach_timebase_info(&timebase));
    ASSERT_GT_MSG(timebase.numer, 0, "timebase should not contain bogus values");
    ASSERT_GT_MSG(timebase.denom, 0, "timebase should not contain bogus values");

    LOG_INFO("mach_timebase: %luns per %lu performance counts", timebase.numer, timebase.denom);

    // The sleeps here seem sketchy, however: these three lines are evaluated quickly enough
    // that there'd generally be too few performance counts between them.
    // We don't care about the length of the sleep, and nothing is truly gated on its length,
    // just that the platform clock advanced.
    auto measurement1 = mach_absolute_time();
    ::Sleep(1);
    auto measurement2 = mach_absolute_time();
    ::Sleep(1);
    auto measurement3 = mach_absolute_time();

    LOG_INFO("mach_absolute_time measurements: A %llu < B %llu < C %llu", measurement1, measurement2, measurement3);
    LOG_INFO("mach_absolute_time drifts      : A-B %lluns, B-C %lluns",
             walltime(timebase, measurement2 - measurement1),
             walltime(timebase, measurement3 - measurement2));

    // Vaguely test monotonicity.
    // Unfortunately, there's nothing we can do from userland to make the
    // clock run backwards. Therefore, we can only test that it
    // does in fact move forward when expected.
    EXPECT_GT(measurement3, measurement2);
    EXPECT_GT(measurement2, measurement1);
}
