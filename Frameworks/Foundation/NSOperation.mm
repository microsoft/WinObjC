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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/NSOperation.h>
#import <condition_variable>
#import <mutex>

@implementation NSOperation {
    StrongId<NSMutableArray> _dependencies;
    StrongId<void(^)()> _completionBlock;
    std::condition_variable_any _finishCondition;
    std::recursive_mutex _finishLock;
    std::recursive_mutex _dependenciesLock;
    std::recursive_mutex _completionBlockLock;
    std::recursive_mutex _readyLock;
}

@synthesize cancelled = _cancelled;
@synthesize executing = _executing;
@synthesize finished = _finished;
@synthesize ready = _ready;

static const NSString* NSOperationContext = @"context";

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    // This class dispatches its own notifications.
    return NO;
}

- (void)_checkReady {
    std::lock_guard<std::recursive_mutex> lock(_readyLock);
    bool newReady = YES;

    // If cancelled, skip this logic and set _ready to YES. Otherwise check dependencies.
    if (![self isCancelled]) {
        std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
        for(NSOperation* op in (NSArray*)_dependencies) {
            if (![op isFinished]) {
                newReady = NO;
            }
        }
    }

    if (_ready != newReady) {
        [self willChangeValueForKey:@"isReady"];
        _ready = newReady;
        [self didChangeValueForKey:@"isReady"];
    }
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if (context == (void*)NSOperationContext) {
        if (object == self) {
            _finishLock.lock();
            _finishCondition.notify_all();
            _finishLock.unlock();
        } else {
            [self _checkReady];
        }
    }
}

- (id)init {
    if (self = [super init]) {
        _dependencies.attach([NSMutableArray new]);
        _ready = YES;
        [self addObserver:self forKeyPath:@"isFinished" options:0 context:(void*)NSOperationContext];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isReady {
    std::lock_guard<std::recursive_mutex> lock(_readyLock);
    return _ready;
}

/**
 @Status Interoperable
*/
- (void)addDependency:(id)operation {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    [self willChangeValueForKey:@"dependencies"];
    [_dependencies addObject:operation];
    [operation addObserver:self forKeyPath:@"isFinished" options:0 context:(void*)NSOperationContext];
    [self didChangeValueForKey:@"dependencies"];
    [self _checkReady];
}

/**
 @Status Interoperable
*/
- (void)removeDependency:(NSOperation*)operation {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    NSUInteger index = [_dependencies indexOfObject:operation];
    if (index != NSNotFound) {
        [self willChangeValueForKey:@"dependencies"];
        [operation removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
        [_dependencies removeObject:operation];
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

    THROW_NS_IF(E_INVALIDARG, (_executing || ![self isReady]));
    
    _finishLock.lock();
    BOOL shouldExecute = !_cancelled; // Note: in the cancelled case, [self main] is not called but isFinished will still be observable
    if (shouldExecute) {
        [self willChangeValueForKey:@"isExecuting"];
        _executing = YES;
        [self didChangeValueForKey:@"isExecuting"];
    }
    _finishLock.unlock();
    
    if (shouldExecute) {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        [self main];
        [pool release];
    }

    [self _finish:shouldExecute];
}

- (void)_finish:(BOOL)didExecute {
    _finishLock.lock();
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

    _completionBlockLock.lock();
    void (^completion)(void) = [_completionBlock retain];
    _completionBlock = nil;
    _completionBlockLock.unlock();

    _finishLock.unlock();
    
    if (completion) {
        completion();
    }

    [completion release];
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
    _finishLock.lock();
    while (![self isFinished]) {
        _finishCondition.wait(_finishLock);
    }

    _finishLock.unlock();
}

/**
 @Status Interoperable
*/
- (NSArray*)dependencies {
    std::lock_guard<std::recursive_mutex> lock(_dependenciesLock);
    NSArray* copy = [[_dependencies copy] autorelease];
    return copy;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _dependenciesLock.lock();
    for(NSOperation* op in (NSArray*)_dependencies) {
        [op removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
    }

    _dependenciesLock.unlock();
    [self removeObserver:self forKeyPath:@"isFinished" context:(void*)NSOperationContext];
    [super dealloc];
}

@end
