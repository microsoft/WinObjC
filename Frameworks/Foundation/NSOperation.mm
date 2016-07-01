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

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSOperation.h"

static const wchar_t* TAG = L"NSOperation";

@implementation NSOperation {
    StrongId<NSMutableArray> _dependencies;
    void (^_completionBlock)(void);
    pthread_cond_t _finishCondition;
    pthread_mutex_t _finishLock;
    pthread_mutex_t _dependenciesLock;
    pthread_mutex_t _completionBlockLock;
}

@synthesize cancelled = _cancelled;
@synthesize executing = _executing;
@synthesize finished = _finished;

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    // This class dispatches its own notifications.
    return NO;
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if ([keyPath isEqualToString:@"isFinished"]) {
        pthread_mutex_lock(&_finishLock);
        pthread_cond_broadcast(&_finishCondition);
        pthread_mutex_unlock(&_finishLock);
    }
}

- (id)init {
    if (self = [super init]) {
        _dependencies.attach([NSMutableArray new]);
        pthread_cond_init(&_finishCondition, 0);
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&_finishLock, &attr);
        pthread_mutexattr_destroy(&attr);
        pthread_mutex_init(&_dependenciesLock, NULL);
        pthread_mutex_init(&_completionBlockLock, NULL);

        [self addObserver:self forKeyPath:@"isFinished" options:0 context:NULL];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)addDependency:(id)operation {
    pthread_mutex_lock(&_dependenciesLock);
    [_dependencies addObject:operation];
    pthread_mutex_unlock(&_dependenciesLock);
}

/**
 @Status Interoperable
*/
- (void)removeDependency:(NSOperation*)operation {
    pthread_mutex_lock(&_dependenciesLock);
    [_dependencies removeObject:operation];
    pthread_mutex_unlock(&_dependenciesLock);
}

/**
 @Status Interoperable
*/
- (BOOL)isReady {
    if ([self isCancelled]) {
        return YES;
    }

    pthread_mutex_lock(&_dependenciesLock);
    int count = [_dependencies count];

    for (int i = 0; i < count; i++) {
        id op = [_dependencies objectAtIndex:i];

        if (![op isFinished]) {
            pthread_mutex_unlock(&_dependenciesLock);
            return NO;
        }
    }

    pthread_mutex_unlock(&_dependenciesLock);
    return YES;
}

/**
 @Status Stub
*/
- (double)threadPriority {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setThreadPriority:(double)priority {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setCompletionBlock:(void (^)(void))block {
    pthread_mutex_lock(&_completionBlockLock);
    [_completionBlock autorelease];
    _completionBlock = [block copy];
    pthread_mutex_unlock(&_completionBlockLock);
}

/**
 @Status Interoperable
*/
- (void (^)(void))completionBlock {
    pthread_mutex_lock(&_completionBlockLock);
    id ret = [[_completionBlock retain] autorelease];
    pthread_mutex_unlock(&_completionBlockLock);
    return ret;
}

/**
 @Status Interoperable
*/
- (BOOL)isCancelled {
    return _cancelled;
}

/**
 @Status Interoperable
*/
- (BOOL)isFinished {
    return _finished;
}

/**
 @Status Interoperable
*/
- (BOOL)isExecuting {
    return _executing;
}

/**
 @Status Interoperable
*/
- (void)start {
    if (_finished) {
        return;
    }

    THROW_NS_IF(E_INVALIDARG, (_executing || ![self isReady]));
    
    pthread_mutex_lock(&_finishLock);
    BOOL shouldExecute = !_cancelled; // Note: in the cancelled case, [self main] is not called but isFinished will still be observable
    if (shouldExecute) {
        [self willChangeValueForKey:@"isExecuting"];
        _executing = YES;
        [self didChangeValueForKey:@"isExecuting"];
    }
    pthread_mutex_unlock(&_finishLock);
    
    if (shouldExecute) {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        [self main];
        [pool release];
    }

    [self _finish:shouldExecute];
}

- (void)_finish:(BOOL)didExecute {
    pthread_mutex_lock(&_finishLock);
    if (didExecute) {
        [self willChangeValueForKey:@"isExecuting"];
    }

    [self willChangeValueForKey:@"isFinished"];
    _finished = YES;
    [self didChangeValueForKey:@"isFinished"];

    if (didExecute) {
        _executing = NO;
        [self didChangeValueForKey:@"isExecuting"];
    }

    pthread_mutex_lock(&_completionBlockLock);
    void (^completion)(void) = [_completionBlock retain];
    pthread_mutex_unlock(&_completionBlockLock);

    pthread_mutex_unlock(&_finishLock);
    
    if (completion) {
        completion();
    }

    [completion release];
}

/**
 @Status Interoperable
*/
- (void)cancel {
    if (_cancelled == NO) {
        pthread_mutex_lock(&_finishLock);
        [self willChangeValueForKey:@"isCancelled"];
        _cancelled = YES;
        [self didChangeValueForKey:@"isCancelled"];
        pthread_mutex_unlock(&_finishLock);
    }
}

/**
 @Status Interoperable
*/
- (void)main {
}

/**
 @Status Interoperable
*/
- (void)waitUntilFinished {
    pthread_mutex_lock(&_finishLock);
    while (![self isFinished]) {
        pthread_cond_wait(&_finishCondition, &_finishLock);
    }

    pthread_mutex_unlock(&_finishLock);
}

/**
 @Status Interoperable
*/
- (NSArray*)dependencies {
    pthread_mutex_lock(&_dependenciesLock);
    NSArray* copy = [[_dependencies copy] autorelease];
    pthread_mutex_unlock(&_dependenciesLock);
    return copy;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [self removeObserver:self forKeyPath:@"isFinished" context:NULL];
    pthread_cond_destroy(&_finishCondition);
    pthread_mutex_destroy(&_finishLock);
    pthread_mutex_destroy(&_dependenciesLock);
    pthread_mutex_destroy(&_completionBlockLock);
    [_completionBlock release];
    [super dealloc];
}

@end
