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

//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/NSOperation.h>
#import <atomic>
#import <condition_variable>
#import <mutex>

#import "NSOperationInternal.h"

static wchar_t TAG[] = L"NSOperation";

@implementation NSOperation {
    StrongId<NSMutableSet> _dependencies;
    NSUInteger _outstandingDependenciesCount;
    StrongId<void (^)()> _completionBlock;
    std::condition_variable_any _finishCondition;

    // The locks. _finishLock should be taken before _completionBlockLock if both need to be taken. No other locks should overlap.
    std::recursive_mutex _finishLock; // guards _finished, _executing, and _cancelled
    std::recursive_mutex _dependenciesLock; // guards _dependencies, _outstandingDependenciesCount and _ready
    std::recursive_mutex _completionBlockLock; // guards _completionBlock

    std::atomic<NSOperationQueuePriority> _queuePriority;
    std::atomic<BOOL> _inQueue;
}

@synthesize cancelled = _cancelled;
@synthesize executing = _executing;
@synthesize finished = _finished;
@synthesize ready = _ready;
@synthesize _completionQueue = _completionQueue;

static const NSString* NSOperationContext = @"context";

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    // This class dispatches its own notifications.
    return NO;
}

- (void)_checkReady {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    bool newReady = YES;

    // If cancelled, skip this logic and set _ready to YES. Otherwise check dependency ready count.
    if (![self isCancelled]) {
        if (_outstandingDependenciesCount > 0) {
            newReady = NO;
        }
    }

    if (_ready != newReady) {
        [self willChangeValueForKey:@"isReady"];
        _ready = newReady;
        [self didChangeValueForKey:@"isReady"];
    }
}

- (void)_dispatchCompletionBlock {
    dispatch_queue_t completionQueue = _completionQueue;
    if (!completionQueue) {
        // It is legal to run an NSOperation without an operation queue.
        // If somebody's doing that, we have to run the completion block on the global background queue.
        // We can't run it immediately, as it could attempt to take a lock held by the originating thread.
        completionQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    }

    dispatch_async(completionQueue, ^{
        decltype(_completionBlock) localCompletion;

        { // _completionBlockLock scope
            std::lock_guard<std::recursive_mutex> lock(_completionBlockLock);
            localCompletion = std::move(_completionBlock);
            _completionBlock = nil;
        } // end _completionBlockLock scope

        if (localCompletion) {
            localCompletion();
        }
    });
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if (context == (void*)NSOperationContext) {
        if (object == self) {
            std::lock_guard<std::recursive_mutex> lock(_finishLock);
            if ([self isFinished]) {
                _finishCondition.notify_all();
                [self _dispatchCompletionBlock];
            }
        } else {
            std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
            if ([_dependencies containsObject:object]) {
                if ([object isFinished]) {
                    _outstandingDependenciesCount--;
                }
            }

            [self _checkReady];
        }
    }
}

- (id)init {
    if (self = [super init]) {
        _dependencies.attach([NSMutableSet new]);
        _ready = YES;
        [self addObserver:self forKeyPath:@"isFinished" options:0 context:(void*)NSOperationContext];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isReady {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    return _ready;
}

/**
 @Status Interoperable
*/
- (void)addDependency:(id)operation {
    std::lock_guard<std::recursive_mutex> dependenciesLock(_dependenciesLock);
    [self willChangeValueForKey:@"dependencies"];
    [_dependencies addObject:operation];
    _outstandingDependenciesCount++; // will be decremented if necessary in observeValueForKey, due to NSKeyValueObservingOptionInitial
    [operation addObserver:self forKeyPath:@"isFinished" options:NSKeyValueObservingOptionInitial context:(void*)NSOperationContext];
    [self didChangeValueForKey:@"dependencies"];
    [self _checkReady];
}

/**
 @Status Interoperable
*/
- (void)removeDependency:(NSOperation*)operation {
    std::lock_guard<std::recursive_mutex> dependenciesLock(_dependenciesLock);
    if ([_dependencies containsObject:operation]) {
        [self willChangeValueForKey:@"dependencies"];
        if (![operation isFinished]) {
            _outstandingDependenciesCount--;
        }

        [_dependencies removeObject:operation];
        [operation removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
        [self didChangeValueForKey:@"dependencies"];
        [self _checkReady];
    }
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
    std::lock_guard<std::recursive_mutex> lock(_completionBlockLock);
    [self willChangeValueForKey:@"completionBlock"];
    _completionBlock = block;
    [self didChangeValueForKey:@"completionBlock"];
}

/**
 @Status Interoperable
*/
- (void (^)(void))completionBlock {
    std::lock_guard<std::recursive_mutex> lock(_completionBlockLock);
    return [[_completionBlock retain] autorelease];
}

/**
 @Status Interoperable
*/
- (BOOL)isCancelled {
    std::lock_guard<std::recursive_mutex> lock(_finishLock);
    return _cancelled;
}

/**
 @Status Interoperable
*/
- (BOOL)isFinished {
    std::lock_guard<std::recursive_mutex> lock(_finishLock);
    return _finished;
}

/**
 @Status Interoperable
*/
- (BOOL)isExecuting {
    std::lock_guard<std::recursive_mutex> lock(_finishLock);
    return _executing;
}

/**
 @Status Interoperable
*/
- (BOOL)isConcurrent {
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)isAsynchronous {
    return NO;
}

/**
 @Status Interoperable
*/
- (void)start {
    if (_finished) {
        return;
    }

    THROW_NS_IF(E_INVALIDARG, (self.executing || !self.ready));

    BOOL shouldExecute;
    { // _finishLock scope
        std::lock_guard<std::recursive_mutex> lock(_finishLock);

        shouldExecute = !_cancelled; // Note: in the cancelled case, [self main] is not called but isFinished will still be observable
        if (shouldExecute) {
            [self willChangeValueForKey:@"isExecuting"];
            _executing = YES;
            [self didChangeValueForKey:@"isExecuting"];
        }
    }

    if (shouldExecute) {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        [self main];
        [pool release];
    }

    { // _finishLock scope
        std::lock_guard<std::recursive_mutex> lock(_finishLock);
        if (shouldExecute) {
            [self willChangeValueForKey:@"isExecuting"];
        }

        [self willChangeValueForKey:@"isFinished"];
        _finished = YES;
        [self didChangeValueForKey:@"isFinished"];

        if (shouldExecute) {
            _executing = NO;
            [self didChangeValueForKey:@"isExecuting"];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)cancel {
    std::lock_guard<std::recursive_mutex> lock(_finishLock);
    if (_cancelled == NO) {
        [self willChangeValueForKey:@"isCancelled"];
        _cancelled = YES;
        [self didChangeValueForKey:@"isCancelled"];
        [self _checkReady];
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
    std::lock_guard<std::recursive_mutex> lock(_finishLock);
    while (![self isFinished]) {
        _finishCondition.wait(_finishLock);
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)dependencies {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    return [_dependencies allObjects];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    { // _dependenciesLock scope
        std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
        for (NSOperation* op in (NSSet*)_dependencies) {
            [op removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
        }
    }

    [self removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSOperationQueuePriority)queuePriority {
    return _queuePriority;
}

/**
 @Status Interoperable
*/
- (void)setQueuePriority:(NSOperationQueuePriority)queuePriority {
    // queuePriority floors to the closest constant to Normal
    if (queuePriority >= NSOperationQueuePriorityVeryHigh) {
        _queuePriority = NSOperationQueuePriorityVeryHigh;

    } else if (queuePriority >= NSOperationQueuePriorityHigh) {
        _queuePriority = NSOperationQueuePriorityHigh;

    } else if (queuePriority > NSOperationQueuePriorityLow) {
        _queuePriority = NSOperationQueuePriorityNormal;

    } else if (queuePriority > NSOperationQueuePriorityVeryLow) {
        _queuePriority = NSOperationQueuePriorityLow;

    } else {
        _queuePriority = NSOperationQueuePriorityVeryLow;
    }
}

- (BOOL)_markInQueue {
    return !_inQueue.fetch_or(YES); // only returns true for the first caller
}

@end
