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

#pragma once
#include <mach/mach_defs.h>
#include <mach/message.h>

__BEGIN_DECLS

typedef unsigned int* task_info_t;
typedef unsigned int policy_t;

enum { TASK_BASIC_INFO, TASK_THREAD_TIMES_INFO };

struct time_value_t {
    integer_t seconds;
    integer_t microseconds;
};

struct task_basic_info {
    integer_t suspend_count;
    integer_t base_priority;
    vm_size_t virtual_size;
    vm_size_t resident_size;
    struct time_value_t user_time;
    struct time_value_t system_time;
    policy_t policy;
};

typedef struct task_basic_info* task_basic_info_t;

struct task_thread_times_info {
    struct time_value_t user_time;
    struct time_value_t system_time;
};

typedef struct task_thread_times_info* task_thread_times_info_t;

mach_port_t mach_task_self();
kern_return_t task_info(task_t target_task, int flavor, task_info_t task_info, mach_msg_type_number_t* task_info_count);

__END_DECLS
