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

#include <mutex>

static const NSUInteger kNSThreadDefaultStackSize = 1024 * 1024;
static const double kNSThreadDefaultPriority = 0.5;

pthread_key_t tlsNSThread, tlsNSThreadRunLoop;

static std::mutex s_mainThreadMutex;
static StrongId<NSThread> s_mainThread;
static BOOL s_isMultiThreaded = NO;

@interface NSThread () {
    StrongId<NSObject> _target;
    SEL _selector;
    StrongId<NSObject> _object;

    double _threadPriority;

    StrongId<NSRunLoop> _runLoop;

    StrongId<NSDictionary> _threadDictionary;
    StrongId<NSString> _name;
}
+ (NSThread*)_threadObjectFromCurrentThread;
- (void)_associateWithCurrentThread;

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

/**
@Status Stub
*/
+ (void)setThreadPriority:(double)priority {
    UNIMPLEMENTED();
    NSThread* curThread = [self currentThread];
    [curThread setThreadPriority:priority];
}

/**
@Status Stub
*/
+ (double)threadPriority {
    UNIMPLEMENTED();
    NSThread* curThread = [self currentThread];
    return [curThread threadPriority];
}

/**
@Status Stub
*/
- (void)setThreadPriority:(double)priority {
    UNIMPLEMENTED();
    _threadPriority = priority;
}

/**
@Status Stub
*/
- (double)threadPriority {
    UNIMPLEMENTED();
    return _threadPriority;
}

/**
@Status Interoperable
*/
- (NSObject*)init {
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

- (void)_associateWithCurrentThread {
    pthread_setspecific(tlsNSThread, reinterpret_cast<void*>(self));
}

- (void)_associateWithMainThread {
    std::lock_guard<std::mutex> lock(s_mainThreadMutex);
    [self _associateWithCurrentThread];
    if (s_mainThread && s_mainThread != self) {
        [NSException raise:NSInternalInconsistencyException format:@"+[NSThread mainThread] already associated with %@; attempt to usurp by %@.", static_cast<id>(s_mainThread), self];
        return;
    }
    s_mainThread = self;
}

+ (NSThread*)_threadObjectFromCurrentThread {
    return reinterpret_cast<NSThread*>(pthread_getspecific(tlsNSThread));
}

/**
@Status Interoperable
*/
+ (BOOL)isMainThread {
    return [self _threadObjectFromCurrentThread] == [self mainThread];
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

struct ThreadBodyData {
    StrongId<NSThread> thread;
};

static void* _threadBody(void* context) {
    ThreadBodyData* bodyData = reinterpret_cast<ThreadBodyData*>(context);

    [bodyData->thread _associateWithCurrentThread];

    // The body of every NSThread boils down to calling -main.
    [bodyData->thread setExecuting:YES];
    [bodyData->thread main];
    [bodyData->thread setFinished:YES];
    [bodyData->thread setExecuting:NO];

    // Allocated in -start.
    delete bodyData;

    return NULL;
}

/**
@Status Interoperable
*/
- (void)start {
    s_isMultiThreaded = YES;

    ThreadBodyData* bodyData = new ThreadBodyData{self};
    // bodyData is deleted in _threadBody when the thread exits.

    pthread_t newThread;
    pthread_attr_t attrs;
    pthread_attr_init(&attrs);

    pthread_attr_setstacksize(&attrs, _stackSize);
    pthread_create(&newThread, &attrs, _threadBody, bodyData);
    pthread_attr_destroy(&attrs);
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
    NSThread* currentThread = [[self class] _threadObjectFromCurrentThread];

    if (currentThread == nil) {
        currentThread = [NSThread new];
        [currentThread _associateWithCurrentThread];
    }
    return currentThread;
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

+ (void)initialize {
    if (tlsNSThread == 0) {
        pthread_key_create(&tlsNSThread, NULL);
    }
}

@end
