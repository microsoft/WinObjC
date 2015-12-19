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
#import <mach/mach.h>

TEST(Mach, MachTaskInfoBasics) {
    task_basic_info basic_info;
    mach_msg_type_number_t size = sizeof(basic_info);
    kern_return_t retVal = task_info(mach_task_self(), TASK_BASIC_INFO, reinterpret_cast<task_info_t>(&basic_info), &size);

    ASSERT_EQ_MSG(retVal, KERN_SUCCESS, "FAILED: task_info call for TASK_BASIC_INFO failed");
    ASSERT_EQ_MSG(size, sizeof(basic_info) / sizeof(integer_t), "FAILED: size is invalid");
    ASSERT_GT_MSG(basic_info.virtual_size, 0, "FAILED: virtual size is invalid");
    ASSERT_GT_MSG(basic_info.resident_size, 0, "FAILED: resident size is invalid");
}

TEST(Mach, MachTaskInfoThreadTimes) {
    task_thread_times_info time_info;
    mach_msg_type_number_t size = sizeof(time_info);
    kern_return_t retVal = task_info(mach_task_self(), TASK_THREAD_TIMES_INFO, reinterpret_cast<task_info_t>(&time_info), &size);

    ASSERT_EQ_MSG(retVal, KERN_SUCCESS, "FAILED: task_info call for TASK_BASIC_INFO failed");
    ASSERT_EQ_MSG(size, sizeof(time_info) / sizeof(integer_t), "FAILED: size is invalid");
    ASSERT_GT_MSG(time_info.user_time.microseconds, 0, "FAILED: user time is invalid");
    ASSERT_GT_MSG(time_info.system_time.microseconds, 0, "FAILED: system time is invalid");

    // check that the user time indeed advances
    time_value_t user_time_before = time_info.user_time;
    time_t start;
    time_t cur;

    time(&start);
    do {
        time(&cur);
    } while (cur - start <= 2); // eat battery for 2 seconds

    retVal = task_info(mach_task_self(), TASK_THREAD_TIMES_INFO, reinterpret_cast<task_info_t>(&time_info), &size);

    ASSERT_EQ_MSG(retVal, KERN_SUCCESS, "FAILED: task_info call for TASK_BASIC_INFO failed");
    ASSERT_EQ_MSG(size, sizeof(time_info) / sizeof(integer_t), "FAILED: size is invalid");
    ASSERT_GT_MSG(time_info.user_time.microseconds, 0, "FAILED: user time is invalid");
    ASSERT_GT_MSG(time_info.user_time.seconds - user_time_before.seconds, 1, "FAILED: user time must have increased by 2 seconds");
}
