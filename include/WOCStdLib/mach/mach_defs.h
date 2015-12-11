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

#ifndef __MACH_DEFS_H
#define __MACH_DEFS_H

#include <sys/cdefs.h>

__BEGIN_DECLS

struct semaphore;

__END_DECLS

typedef int                 cpu_type_t;
typedef int                 cpu_subtype_t;
typedef int                 vm_prot_t;
typedef unsigned int        thread_t;
typedef unsigned int        mach_port_t;
typedef mach_port_t         host_t;
typedef unsigned int        task_t;
typedef int                 kern_return_t;
typedef struct semaphore    *semaphore_t;

#define KERN_SUCCESS        0

#define SYNC_POLICY_FIFO    0x0

__BEGIN_DECLS
extern mach_port_t mach_task_self();

extern kern_return_t semaphore_create(task_t, semaphore_t*, int, int);
extern kern_return_t semaphore_destroy(task_t, semaphore_t);
extern kern_return_t semaphore_wait(semaphore_t);
extern kern_return_t semaphore_signal(semaphore_t);
__END_DECLS


#endif

