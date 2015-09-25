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

#include "Foundation/NSThread.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSMutableDictionary.h"

#include <pthread.h>
#include "Platform/EbrPlatform.h"

#include "../objcrt/runtime.h"

pthread_key_t tlsNSThread, tlsNSThreadRunLoop;

typedef struct {
    SEL sel;
    NSObject* obj;
    NSObject* param;
    NSThread* threadObj;
    char* stackBase;
    NSUInteger stackSize;
} selectorThreadParam;

NSThread* mainThread;

int runningCount = 0;
BOOL isMultiThreaded = FALSE;

class __exit_exception {};

void* selectorThread(void* param) {
    selectorThreadParam* pParam = (selectorThreadParam*)param;

    _EbrThread_t* newInfo = new _EbrThread_t();
    newInfo->tid = pthread_self();

    EbrDebugLog("Running threads: %d\n", EbrIncrement((int*)&runningCount));

    pthread_setspecific(tlsNSThread, (void*)(DWORD)pParam->threadObj);

    id thing = (id)pParam->obj;
    Class cls = object_getClass(thing);
    IMP foo = class_getMethodImplementation(cls, pParam->sel);
    foo(pParam->obj, pParam->sel, pParam->param);

    pParam->threadObj->_isFinished = TRUE;
    EbrDecrement((int*)&runningCount);
    [pParam->obj release];
    if (pParam->param != nil)
        [pParam->param release];

    if (pParam->stackBase)
        EbrFree(pParam->stackBase);
    [pParam->threadObj release];
    EbrThreadDissociate();

    return NULL;
}

@implementation NSThread : NSObject {
    NSObject* _target;
    bool _retainTarget;
    SEL _selector;
    NSObject* _object;
    double _priority;
    NSUInteger _stackSize;
    BOOL _cancelled;
    NSRunLoop* _runLoop;
    idretain _threadDictionary;
    idretain _name;
}

+ (void)detachNewThreadSelector:(SEL)selector toTarget:(NSObject*)obj withObject:(NSObject*)objParam {
    NSThread* ret = [[self alloc] initWithTarget:obj selector:selector object:objParam];
    [ret start];
    [ret release];
}

+ (void)sleepForTimeInterval:(double)interval {
    EbrBlockIfBackground();

    __int64 nsecs = (__int64)(interval * 1000000000.0);
    EbrSleep(nsecs);
}

+ (void)sleepUntilDate:(NSDate*)date {
    EbrBlockIfBackground();

    NSTimeInterval interval = [date timeIntervalSinceNow];
    if (interval > 0.0) {
        __int64 nsecs = (__int64)(interval * 1000000000.0);
        EbrSleep(nsecs);
    }
}

+ (void)setThreadPriority:(double)priority {
    NSThread* curThread = [self currentThread];
    curThread->_priority = priority;
}

- (void)setStackSize:(NSUInteger)size {
    EbrDebugLog("Stack size: %d\n", size);
    _stackSize = size;
}

- (NSThread*)initWithTarget:(NSObject*)target selector:(SEL)selector object:(NSObject*)objParam {
    _target = [target retain];
    _selector = selector;
    _object = objParam != nil ? [objParam retain] : nil;
    _stackSize = 1024 * 1024;
    _priority = 0.5f;
    _runLoop = [NSRunLoop new];

    return self;
}

- (BOOL)isCancelled {
    return _cancelled;
}

- (BOOL)isFinished {
    return _isFinished;
}

- (void)cancel {
    _cancelled = TRUE;
}

- (NSUInteger)stackSize {
    return _stackSize;
}

- (void)dealloc {
    [_runLoop release];
    [super dealloc];
}

- (NSObject*)init {
    _selector = @selector(main);
    _stackSize = 1024 * 1024;
    _target = self;
    _retainTarget = true;
    _priority = 0.5f;
    _runLoop = [NSRunLoop new];

    return self;
}

- (void)associateWithCurrentThread {
    pthread_setspecific(tlsNSThread, (void*)self);
    mainThread = self;
}

+ (void)exit {
    EbrDebugLog("NSThread::exit\n");
    assert(0);
}

+ (BOOL)isMainThread {
    NSThread* ret = (NSThread*)pthread_getspecific(tlsNSThread);

    return ret == mainThread;
}

- (BOOL)isMainThread {
    return self == mainThread;
}

+ (BOOL)isMultiThreaded {
    return isMultiThreaded;
}

+ (NSThread*)mainThread {
    return mainThread;
}

- (double)threadPriority {
    return _priority;
}

- (NSDictionary*)threadDictionary {
    if (_threadDictionary == nil) {
        _threadDictionary.attach([NSMutableDictionary new]);
    }

    return (NSDictionary*)_threadDictionary;
}

+ (double)threadPriority {
    NSThread* curThread = [self currentThread];

    return curThread->_priority;
}

- (void)start {
    isMultiThreaded = TRUE;
    selectorThreadParam* pParam = (selectorThreadParam*)malloc(sizeof(selectorThreadParam));

    pParam->stackSize = _stackSize;
    pParam->sel = _selector;
    pParam->obj = _retainTarget ? [_target retain] : _target;

    pParam->param = _object;
    pParam->threadObj = [self retain];

    pthread_t newThread;
    pParam->stackBase = NULL;
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);

    pthread_attr_setstacksize(&attrs, 1024 * 1024);
    pthread_create(&newThread, &attrs, selectorThread, pParam);
    pthread_attr_destroy(&attrs);
}

- (NSRunLoop*)_runLoop {
    return _runLoop;
}

- (void)setName:(NSString*)name {
    _name.attach([name copy]);
}

- (NSString*)name {
    return (NSString*)_name;
}

+ (NSThread*)currentThread {
    NSThread* ret = (NSThread*)pthread_getspecific(tlsNSThread);

    if (ret == nil) {
        EbrDebugLog("Warning: NSThread not associated with thread\n");
        ret = [NSThread new];
        pthread_setspecific(tlsNSThread, (void*)ret);
    }
    return ret;
}

+ (void)initialize {
    if (tlsNSThread == 0) {
        pthread_key_create(&tlsNSThread, NULL);
    }
}

@end
