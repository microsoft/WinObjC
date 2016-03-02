/*
Original Author: Michael Ash on 11/9/08.
Copyright (c) 2008 Rogue Amoeba Software LLC

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSOperation.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"
#include "LoggingNative.h"

static const wchar_t* TAG = L"NSOperation";

#if __cplusplus
#include <pthread.h>
#include <string.h>
struct NSOperationPriv {
    NSOperationQueuePriority priority;
    id dependencies;
    void (^completionBlock)(void);

    pthread_cond_t finishCondition;
    pthread_mutex_t finishLock;

    int executing : 1;
    int cancelled : 1;
    int finished : 1;

    NSOperationPriv() {
        memset(this, 0, sizeof(NSOperationPriv));
        pthread_cond_init(&finishCondition, 0);

        pthread_mutexattr_t attr;

        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&finishLock, &attr);
        pthread_mutexattr_destroy(&attr);
    }

    ~NSOperationPriv() {
        pthread_cond_destroy(&finishCondition);
        pthread_mutex_destroy(&finishLock);
    }
};
#else
struct NSOperationPriv;
#endif

@interface NSOperation () {
    struct NSOperationPriv* priv;
}
@end

@implementation NSOperation

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    // This class dispatches its own notifications.
    return NO;
}

/**
 @Status Interoperable
*/
+ (id)allocWithZone:(NSZone*)zone {
    NSOperation* ret = [super allocWithZone:zone];

    ret->priv = new NSOperationPriv();

    return ret;
}

/**
 @Status Interoperable
*/
- (NSOperationQueuePriority)queuePriority {
    return priv->priority;
}

/**
 @Status Interoperable
*/
- (void)addDependency:(id)operation {
    if (priv->dependencies == nil) {
        priv->dependencies = [[NSMutableArray alloc] init];
    }
    [priv->dependencies addObject:operation];
}

/**
 @Status Interoperable
*/
- (void)setQueuePriority:(NSOperationQueuePriority)priority {
    priv->priority = priority;
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
    id oldBlock = priv->completionBlock;
    priv->completionBlock = [block copy];
    [oldBlock release];
}

/**
 @Status Interoperable
*/
- (void (^)(void))completionBlock {
    return priv->completionBlock;
}

/**
 @Status Interoperable
*/
- (BOOL)isReady {
    //  Note, check dependencies when we get them
    int count = [priv->dependencies count];

    for (int i = 0; i < count; i++) {
        id op = [priv->dependencies objectAtIndex:i];

        if (![op isFinished]) {
            return NO;
        }
    }
    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)isCancelled {
    return priv->cancelled != 0;
}

/**
 @Status Interoperable
*/
- (BOOL)isFinished {
    return priv->finished != 0;
}

/**
 @Status Interoperable
*/
- (BOOL)isExecuting {
    return priv->executing != 0;
}

/**
 @Status Interoperable
*/
- (void)start {
    if (!priv->executing && !priv->finished) {
        bool execute = false;

        pthread_mutex_lock(&priv->finishLock);
        if (!priv->cancelled) {
            [self willChangeValueForKey:@"isExecuting"];
            priv->executing = 1;
            [self didChangeValueForKey:@"isExecuting"];
            execute = true;
        }
        pthread_mutex_unlock(&priv->finishLock);
        if (execute) {
            [self main];
        }

        if (execute) {
            [self willChangeValueForKey:@"isExecuting"];
        }

        [self _setFinished:YES
            andPerformUnderLock:^{
                if (execute) {
                    priv->executing = 0;
                    [self didChangeValueForKey:@"isExecuting"];
                }
            }];
    }
}

/**
 @Status Interoperable
*/
- (void)setFinished:(BOOL)finished {
    [self _setFinished:finished andPerformUnderLock:nil];
}

- (void)_setFinished:(BOOL)finished andPerformUnderLock:(void (^)())block {
    // yes, this is ugly: priv->finished is an int though.
    int newValue = finished ? 1 : 0;
    pthread_mutex_lock(&priv->finishLock);

    [self willChangeValueForKey:@"isFinished"];

    if (priv->finished != newValue) {
        priv->finished = newValue;
    }

    [self didChangeValueForKey:@"isFinished"];

    if (block) {
        block();
    }

    if (newValue == 1) {
        pthread_cond_broadcast(&priv->finishCondition);
    }

    pthread_mutex_unlock(&priv->finishLock);

    // This may seem unintuitive, but the completion
    // block is intended to be called even if the operation
    // is cancelled.
    if (newValue == 1 && priv->completionBlock) {
        priv->completionBlock();
        [priv->completionBlock release];
        priv->completionBlock = nil;
    }
}

/**
 @Status Interoperable
*/
- (void)cancel {
    if (priv->cancelled == 0) {
        pthread_mutex_lock(&priv->finishLock);
        [self willChangeValueForKey:@"isCancelled"];
        priv->cancelled = 1;
        [self didChangeValueForKey:@"isCancelled"];
        pthread_mutex_unlock(&priv->finishLock);
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
    pthread_mutex_lock(&priv->finishLock);
    if (![self isFinished]) {
        pthread_cond_wait(&priv->finishCondition, &priv->finishLock);
    }
    pthread_mutex_unlock(&priv->finishLock);
}

/**
 @Status Interoperable
*/
- (id)dependencies {
    return priv->dependencies;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    assert(!priv->completionBlock);
    delete priv;
    [super dealloc];
}

/**
 @Status Stub
 @Notes
*/
- (void)removeDependency:(NSOperation*)operation {
    UNIMPLEMENTED();
}

@end
