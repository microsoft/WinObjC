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

#include <pthread.h>

#include "Windows.h"
#undef WIN32

#include "Starboard.h"

#include "Foundation/NSString.h"
#include "Foundation/NSOperation.h"
#include "Foundation/NSRunLoop.h"

#include "Etc.h"
#include "Hash.h"

#include "Foundation/NSAutoreleasePool.h"

#undef dispatch_once

DWORD _dispatch_group_create()
{
    return (DWORD) [NSNull new];
}

void dispatch_group_enter(dispatch_group_t group)
{
}

void dispatch_group_leave(dispatch_group_t group)
{
}

DWORD _dispatch_group_wait(DWORD group)
{
    return 0;
}

pthread_key_t g_currentDispatchQueue;

dispatch_queue_t dispatch_get_current_queue()
{
    dispatch_queue_t ret = (dispatch_queue_t) pthread_getspecific(g_currentDispatchQueue);
    return ret;
}

void dispatch_async(dispatch_queue_t queue, dispatch_block_t block);

void dispatch_apply(size_t iterations, dispatch_queue_t queue, void (^block)(size_t))
{
    for ( int i = 0; i < iterations; i ++ ) {
        block(i);
    }
}

void dispatch_group_async(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block)
{
    //dispatch_retain(group);
    dispatch_group_enter(group);
    dispatch_async(queue, block);
    /*
    _dispatch_async(queue, ^{
                     block();
                     dispatch_group_leave(group);
                     dispatch_release(group);
             });
     }
     */
}
     
@interface _NSDispatchSemaphore : NSObject {
@public
    DWORD handle;
}
@end


@implementation _NSDispatchSemaphore : NSObject
    -(void) dealloc {
        HANDLE semHandle = (HANDLE) handle;

        CloseHandle(semHandle);

        [super dealloc];
    }

    
@end

dispatch_semaphore_t dispatch_semaphore_create(long count)
{
    _NSDispatchSemaphore* ret = [_NSDispatchSemaphore new];

    ret->handle = (DWORD) CreateSemaphoreEx(NULL, count, count < 15 ? 15 : count, NULL, 0, SEMAPHORE_ALL_ACCESS);

    return (dispatch_semaphore_t) ret;
}

long dispatch_semaphore_wait(dispatch_semaphore_t sem, dispatch_time_t time)
{
    _NSDispatchSemaphore* obj = (id) sem;

    assert(time == 0xFFFFFFFFFFFFFFFFLL);
    HANDLE semHandle = (HANDLE) obj->handle;

    WaitForSingleObjectEx(semHandle, INFINITE, FALSE);

    return 0;
}

long dispatch_semaphore_signal(dispatch_semaphore_t sem)
{
    _NSDispatchSemaphore* obj = (id) sem;

    EbrDebugLog("Warning: dispatch_semaphore_signal doesn't notify of woken threads\n");
    HANDLE semHandle = (HANDLE) obj->handle;

    BOOL ret = ReleaseSemaphore(semHandle, 1, NULL);
    if ( !ret ) {
        assert(0);
    }

    return 0;
}

dispatch_queue_t dispatch_queue_create(const char *name, dispatch_queue_attr_t attr)
{
    id ret = [NSOperationQueue new];
    [ret setName:[NSString stringWithCString: name]];

    return (dispatch_queue_t) ret;
}

DWORD _dispatch_queue_get_label(id queue)
{
    id name = [queue name];
    if ( name == nil ) return 0;

    char *ret = _strdup((char *) [name UTF8String]);
    return (DWORD) ret;
}

DWORD _dispatch_set_target_queue(id obj, id target)
{
    EbrDebugLog("_dispatch_set_target_queue not supported\n");
    return 0;
}

dispatch_queue_t dispatch_get_global_queue(dispatch_queue_priority_t priority, unsigned long flags)
{
    static id globalQueue = nil;

    if ( globalQueue == nil ) {
        globalQueue = [NSOperationQueue new];
    }

    return (dispatch_queue_t) globalQueue;
}

struct dispatch_queue_s _dispatch_main_q;

void dispatch_async(dispatch_queue_t queue, dispatch_block_t block)
{
    EbrDebugLog("dispatch_async not supported\n");

    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        block = [block copy];   //  correct?
        [block performSelectorOnMainThread:@selector(invoke) withObject:nil waitUntilDone:FALSE];
        [block autorelease];
        return;
    }

    id operation = [NSBlockOperation new];
    [operation addExecutionBlock:block];

    [queue addOperation:operation];
    [operation release];
}

void dispatch_group_notify(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block)
{
    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        block = [block copy];   //  correct?
        [block performSelectorOnMainThread:@selector(invoke) withObject:nil waitUntilDone:FALSE];
        [block autorelease];
        return;
    }

    id operation = [NSBlockOperation new];
    [operation addExecutionBlock:block];

    [queue addOperation:operation];
    [operation release];
}
     
@interface NSDispatchSyncOperation : NSOperation {
@public
    EbrEvent _dispatchReady, _dispatchDone;
}
@end


@implementation NSDispatchSyncOperation : NSOperation
    /* annotate with type */ -(id) init {
        EbrEventInit(&_dispatchReady);
        EbrEventInit(&_dispatchDone);
        return self;
    }

    /* annotate with type */ -(id) main {
        EbrEventSignal(_dispatchReady);
        EbrEventWait(_dispatchDone);

        return self;
    }

    -(void) dealloc {
        EbrEventDestroy(_dispatchReady);
        EbrEventDestroy(_dispatchDone);
        [super dealloc];
    }

    
@end

void dispatch_sync(dispatch_queue_t queue, dispatch_block_t block)
{
    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        block = [block copy];
        [block performSelectorOnMainThread:@selector(invoke) withObject:nil waitUntilDone:TRUE];
        [block autorelease];
        return;
    }

    NSDispatchSyncOperation* operation = [NSDispatchSyncOperation new];

    [queue addOperation:(id) operation];
    [operation release];
    EbrEventWait(operation->_dispatchReady);

    //  Perform the synchronous task on the calling thread
    block();
    EbrEventSignal(operation->_dispatchDone);
}

void dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block)
{
    return dispatch_sync(queue, block);
}

void dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block)
{
    dispatch_async(queue, block);
}

void dispatch_release(dispatch_object_t queue)
{
    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        return;
    }
    [queue release];
}

void dispatch_retain(dispatch_object_t queue)
{
    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        return;
    }

    [queue retain];
}

DWORD _dispatch_resume(DWORD queue)
{
    EbrDebugLog("dispatch_resume not supported\n");
    return 0;
}

void dispatch_once(dispatch_once_t *once, dispatch_block_t block)
{
    if ( *once == 0 ) {
        *once = 1;
        block();
    }
}

unsigned __int64 _dispatch_time(unsigned __int64 when, unsigned __int64 delta)
{
    if ( when == 0 ) {
        double ret = EbrGetMediaTime() + ((double) delta / 1000000000.0);
        return *((unsigned __int64 *) &ret);
    }

    assert(0);
    EbrDebugLog("dispatch_time not implemented\n");
    return 0;
}

void dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block)
{
    EbrDebugLog("_dispatch_after not supported\n");

    if ( queue == (dispatch_queue_t) &_dispatch_main_q ) {
        double delay = (*((double *) &when)) - EbrGetMediaTime();
        id copy = [block copy];
        [copy performSelector:@selector(invoke) withObject:nil afterDelay:delay];
        [copy release];
        return;
    }

    EbrDebugLog("_dispatch_after not implemented\n");
    assert(0);
}

DWORD _dispatch_source_create(DWORD type, DWORD *handle, DWORD mask, DWORD queue)
{
    EbrDebugLog("_dispatch_source_create not supported\n");

    return 0;
}

DWORD _dispatch_source_set_event_handler(id source, id handlerBlock)
{
    EbrDebugLog("_dispatch_source_set_event_handler not supported\n");

    return 0;
}

DWORD _dispatch_source_set_cancel_handler(id source, id handlerBlock)
{
    EbrDebugLog("_dispatch_source_set_cancel_handler not supported\n");

    return 0;
}

DWORD _dispatch_source_set_timer(id source, double start, double interval, double leeway)
{
    EbrDebugLog("_dispatch_source_set_timer not supported\n");
    return 0;
}

void RegisterDispatchLib()
{
    pthread_key_create(&g_currentDispatchQueue, NULL);
}
