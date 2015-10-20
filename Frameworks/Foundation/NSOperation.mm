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
#include "Foundation/NSOperation.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableArray.h"

@implementation NSOperation

+ (id)allocWithZone:(NSZone*)zone {
    NSOperation* ret = [super allocWithZone:zone];

    ret->priv = new NSOperationPriv();

    [ret addObserver:(id)ret forKeyPath:@"isFinished" options:0 context:nil];

    return ret;
}

- (NSOperationQueuePriority)queuePriority {
    return priv->priority;
}

- (void)addDependency:(id)operation {
    if (priv->dependencies == nil) {
        priv->dependencies = [[NSMutableArray alloc] init];
    }
    [priv->dependencies addObject:operation];
}

- (void)setQueuePriority:(NSOperationQueuePriority)priority {
    priv->priority = priority;
}

- (id)setThreadPriority:(double)priority {
    EbrDebugLog("NSOperationQueue setThreadPriority not supported\n");
    return self;
}

- (void)setCompletionBlock:(void (^)(void))block {
    id oldBlock = priv->completionBlock;
    priv->completionBlock = [block copy];
    [oldBlock release];
}

- (void (^)(void))completionBlock {
    return priv->completionBlock;
}

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

- (BOOL)isCancelled {
    return priv->cancelled != 0;
}

- (BOOL)isFinished {
    return priv->finished != 0;
}

- (BOOL)isExecuting {
    return priv->executing != 0;
}

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
        [self willChangeValueForKey:@"isFinished"];
        pthread_mutex_lock(&priv->finishLock);
        priv->finished = 1;
        [self didChangeValueForKey:@"isFinished"];
        if (execute) {
            priv->executing = 0;
            [self didChangeValueForKey:@"isExecuting"];
        }
        pthread_mutex_unlock(&priv->finishLock);
    }
}

- (void)cancel {
    if (priv->cancelled == 0) {
        pthread_mutex_lock(&priv->finishLock);
        [self willChangeValueForKey:@"isCancelled"];
        priv->cancelled = 1;
        [self didChangeValueForKey:@"isCancelled"];
        pthread_mutex_unlock(&priv->finishLock);
    }
}

- (void)main {
}

- (void)waitUntilFinished {
    pthread_mutex_lock(&priv->finishLock);
    if (![self isFinished]) {
        pthread_cond_wait(&priv->finishCondition, &priv->finishLock);
    }
    pthread_mutex_unlock(&priv->finishLock);
}

- (id)dependencies {
    return priv->dependencies;
}

- (void)observeValueForKeyPath:(id)keyPath ofObject:(id)obj change:(id)changeDictionary context:(void*)context {
    pthread_mutex_lock(&priv->finishLock);
    int finished = [self isFinished];
    if (finished) {
        pthread_cond_broadcast(&priv->finishCondition);
    }
    pthread_mutex_unlock(&priv->finishLock);

    // Someone might do something stupid like waitUntilFinished in the completion block,
    // which would deadlock if these weren't separated.
    if (finished && priv->completionBlock != nil) {
        priv->completionBlock();
        [priv->completionBlock release];
        priv->completionBlock = nil;
    }
}

- (void)dealloc {
    assert(priv->completionBlock == nil);
    [self removeObserver:self forKeyPath:@"isFinished"];
    delete priv;
    [super dealloc];
}

@end
