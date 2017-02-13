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

#include <windows.h>

#include "Foundation/NSThread.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSMutableDictionary.h"

#include <pthread.h>
#include "Platform/EbrPlatform.h"

#include <mutex>

static const wchar_t* TAG = L"NSThread";

static const NSUInteger kNSThreadDefaultStackSize = 1024 * 1024;
static const double kNSThreadDefaultPriority = 0.5;

static std::mutex s_mainThreadMutex;
static StrongId<NSThread> s_mainThread;
static BOOL s_isMultiThreaded = NO;

static NSThread* _setOrGetCurrentThread(NSThread* thread, bool createIfNil) {
    // Use a lazy initialized block scope thread_local to manage the lifetime of currentThread.
    // Note that non-trivial file scope thread_locals are apparently not supported in current clang version.
    thread_local static StrongId<NSThread> tlsCurrentThread;

    if (thread != nil) {
        // We've been passed a thread. Designate as current thread and assume ownership.
        tlsCurrentThread = thread;
    } else if (tlsCurrentThread == nil && createIfNil) {
        // No current thread exists. Create a new one, as requested.
        tlsCurrentThread.attach([[NSThread alloc] init]);
    }

    return tlsCurrentThread;
}

static void _setCurrentThread(NSThread* thread) {
    _setOrGetCurrentThread(thread, false);
}

static NSThread* _getCurrentThreadOrNil() {
    return _setOrGetCurrentThread(nil, false);
}

static NSThread* _getOrCreateCurrentThread() {
    return _setOrGetCurrentThread(nil, true);
}

@interface NSThread () {
    StrongId<NSObject> _target;
    SEL _selector;
    StrongId<NSObject> _object;

    double _threadPriority;

    StrongId<NSRunLoop> _runLoop;

    StrongId<NSDictionary> _threadDictionary;
    StrongId<NSString> _name;

    pthread_t _pthread;
}

@property (atomic, readwrite, getter=isExecuting) BOOL executing;
@property (atomic, readwrite, getter=isCancelled) BOOL cancelled;
@property (atomic, readwrite, getter=isFinished) BOOL finished;
@end

@implementation NSThread
/**
@Status Interoperable
*/
+ (void)detachNewThreadSelector:(SEL)selector toTarget:(NSObject*)obj withObject:(NSObject*)objParam {
    NSThread* ret = [[self alloc] initWithTarget:obj selector:selector object:objParam];
    [ret start];
    [ret release];
}

/**
@Status Interoperable
*/
+ (void)sleepForTimeInterval:(NSTimeInterval)interval {
    EbrBlockIfBackground();

    __int64 nsecs = static_cast<__int64>(interval * 1000000000.0);
    EbrSleep(nsecs);
}

/**
@Status Interoperable
*/
+ (void)sleepUntilDate:(NSDate*)date {
    EbrBlockIfBackground();

    NSTimeInterval interval = [date timeIntervalSinceNow];
    if (interval > 0.0) {
        [self sleepForTimeInterval:interval];
    }
}

static int _convertPriorityToThreadPriority(double priority, int policy) {
    return static_cast<int>(priority * (double)sched_get_priority_max(policy) - (double)sched_get_priority_min(policy));
}

- (BOOL)_updateThreadPriority:(double)priority {
    int policy;
    struct sched_param getparam;
    int status = pthread_getschedparam(_pthread, &policy, &getparam);
    if (status != 0) {
        TraceError(TAG, L"Error retrieving pthread sched_param. Error code : %d.", status);
        return NO;
    }

    // Convert double to expected pthread priority value
    int pthreadPriority = _convertPriorityToThreadPriority(priority, policy);

    const struct sched_param param { pthreadPriority };

    // call setpriority on pthread
    status = pthread_setschedparam(_pthread, policy, &param);

    if (status != 0) {
        TraceError(TAG, L"Error setting pthread sched_param. Error code : %d. Requested priority: %d", status, priority);
    }
    return status == 0;
}

/**
@Status Interoperable
@Notes Thread priority is never guaranteed to affect the behavior of thread execution. Valid values for priority are 0 to 1 with .5 being
the default thread priority. Utilizes win32 thread priority.
*/
+ (BOOL)setThreadPriority:(double)priority {
    NSThread* curThread = [self currentThread];
    if (curThread != nil) {
        [curThread setThreadPriority:priority];
        return YES;
    }
    return NO;
}

/**
@Status Interoperable
@Notes The priority of the currently running thread. Utilizes win32 thread priority mapped to a 0 to 1 representation.
*/
+ (double)threadPriority {
    NSThread* curThread = [self currentThread];
    return [curThread threadPriority];
}

/**
@Status Interoperable
*/
- (void)setThreadPriority:(double)priority {
    _threadPriority = priority;
    if (_pthread) {
        [self _updateThreadPriority:priority];
    }
}

/**
@Status Interoperable
*/
- (double)threadPriority {
    int policy;
    struct sched_param param;
    int status = pthread_getschedparam(_pthread, &policy, &param);

    if (status != 0) {
        TraceError(TAG, L"Error retrieving pthread sched_param. Error code : %d.", status);
        return _threadPriority;
    }

    double convertedPriority = ((double)param._schedPriority) / (double)(sched_get_priority_max(policy) - sched_get_priority_min(policy));

    return convertedPriority;
}

/**
@Status Interoperable
*/
- (NSThread*)init {
    if (self = [super init]) {
        _stackSize = kNSThreadDefaultStackSize;
        _threadPriority = kNSThreadDefaultPriority;
        _runLoop.attach([NSRunLoop new]);
    }
    return self;
}

/**
@Status Interoperable
*/
- (NSThread*)initWithTarget:(NSObject*)target selector:(SEL)selector object:(NSObject*)objParam {
    if (self = [self init]) { // call our own designated initializer
        _target = target;
        _selector = selector;
        _object = objParam;
    }
    return self;
}

/**
@Status Interoperable
*/
- (void)cancel {
    self.cancelled = YES;
}

- (void)_associateWithMainThread {
    std::lock_guard<std::mutex> lock(s_mainThreadMutex);
    _setCurrentThread(self);
    if (s_mainThread && s_mainThread != self) {
        [NSException
             raise:NSInternalInconsistencyException
            format:@"+[NSThread mainThread] already associated with %@; attempt to usurp by %@.", static_cast<id>(s_mainThread), self];
        return;
    }
    s_mainThread = self;
}

/**
@Status Interoperable
*/
+ (BOOL)isMainThread {
    NSThread* main = [self mainThread];

    if (main == nil) {
        return NO;
    }

    return _getCurrentThreadOrNil() == main;
}

/**
@Status Interoperable
*/
- (BOOL)isMainThread {
    return self == [[self class] mainThread];
}

/**
@Status Interoperable
*/
+ (BOOL)isMultiThreaded {
    return s_isMultiThreaded;
}

/**
@Status Interoperable
*/
+ (NSThread*)mainThread {
    std::lock_guard<std::mutex> lock(s_mainThreadMutex);
    return s_mainThread;
}

/**
@Status Interoperable
*/
- (NSDictionary*)threadDictionary {
    if (!_threadDictionary) {
        _threadDictionary.attach([NSMutableDictionary new]);
    }

    return _threadDictionary;
}

static void* _threadBody(void* context) {
    NSThread* self = static_cast<NSThread*>(context);

    // Let current thread mechanism assume ownership.
    _setCurrentThread(self);
    [self release];

    // The body of every NSThread boils down to calling -main.
    [self setExecuting:YES];
    [self main];
    [self setFinished:YES];
    [self setExecuting:NO];

    return NULL;
}

/**
@Status Interoperable
*/
- (void)start {
    s_isMultiThreaded = YES;

    struct sched_param param = { _convertPriorityToThreadPriority(_threadPriority, 0) };

    pthread_attr_t attrs;
    pthread_attr_init(&attrs);
    auto attrDestroy = wil::ScopeExit([&attrs]() { pthread_attr_destroy(&attrs); });

    int status = pthread_attr_setstacksize(&attrs, _stackSize);

    if (status != 0) {
        TraceError(TAG, L"Error setting pthread stack size. Error code : %d.", status);
        return;
    }

    status = pthread_attr_setschedparam(&attrs, &param);

    if (status != 0) {
        TraceError(TAG, L"Error setting pthread sched_param. Error code : %d.", status);
        return;
    }

    // Stay alive while underlying thread of execution starts.
    [self retain];

    pthread_create(&_pthread, &attrs, _threadBody, self);
}

/**
@Status Interoperable
*/
- (void)main {
    if (_target) {
        auto targetImp = reinterpret_cast<void (*)(id, SEL, id)>(objc_msg_lookup(_target, _selector));
        targetImp(_target, _selector, _object);
    }
}

/**
@Status Stub
*/
+ (void)exit {
    UNIMPLEMENTED();
}

- (NSRunLoop*)_runLoop {
    return _runLoop;
}

/**
@Status Interoperable
*/
- (void)setName:(NSString*)name {
    _name.attach([name copy]);
}

/**
@Status Interoperable
*/
- (NSString*)name {
    return [[_name retain] autorelease];
}

/**
@Status Interoperable
*/
+ (NSThread*)currentThread {
    return _getOrCreateCurrentThread();
}

/**
@Status Stub
*/
+ (NSArray*)callStackReturnAddresses {
    UNIMPLEMENTED();
    return nil;
}

/**
@Status Stub
*/
+ (NSArray*)callStackSymbols {
    UNIMPLEMENTED();
    return nil;
}

@end
