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

#import <Foundation/NSOperationQueue.h>

#import <Foundation/NSBlockOperation.h>
#import <Foundation/NSCondition.h>

#import "NSOperationInternal.h"
#import "Starboard.h"

#import <atomic>
#import <mutex>
#import <queue>

static const wchar_t* TAG = L"NSOperationQueue";

// Private helper that converts NSQualityOfService -> QOS_CLASS
static inline long _QOSClassForNSQualityOfService(NSQualityOfService quality) {
    switch (quality) {
        case NSQualityOfServiceUserInteractive:
            return QOS_CLASS_USER_INTERACTIVE;
        case NSQualityOfServiceUserInitiated:
            return QOS_CLASS_USER_INITIATED;
        case NSQualityOfServiceUtility:
            return QOS_CLASS_UTILITY;
        case NSQualityOfServiceBackground:
// currently generates a warning:
// 'QOS_CLASS_BACKGROUND' is deprecated: QOS_CLASS_BACKGROUND is the same as DISPATCH_QUEUE_PRIORITY_LOW on WinObjC
// TODO #2241: should go away once libdispatch is updated
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
            return QOS_CLASS_BACKGROUND;
#pragma clang diagnostic pop
        case NSQualityOfServiceDefault:
        default:
            return QOS_CLASS_DEFAULT;
    }
}

// Private helper that compares two NSOperations and orders the higher-priority one first
static NSInteger _compareOperationPriority(NSOperation* op1, NSOperation* op2, void* context) {
    NSOperationQueuePriority pri1 = op1.queuePriority;
    NSOperationQueuePriority pri2 = op2.queuePriority;
    if (pri1 > pri2) {
        return NSOrderedAscending;
    } else if (pri1 < pri2) {
        return NSOrderedDescending;
    }
    return NSOrderedSame;
}

// STL compare for NSOperation*, sorting by queuePriority, putting the greatest priority first
struct _NSOperation_ComparePrioritySTL {
    bool operator()(NSOperation* lhs, NSOperation* rhs) {
        return lhs.queuePriority > rhs.queuePriority;
    }
};

// Used for [NSOperationQueue currentQueue]
static StrongId<NSOperationQueue*>& _getCurrentQueue() {
    thread_local static StrongId<NSOperationQueue*> tls_currentQueue;
    return tls_currentQueue;
}

// Used for key-value observing on held operations - comparing pointers to these is faster than comparing keypaths
static char _NSOperationQueue_IsFinishedContext;
static char _NSOperationQueue_IsReadyContext;

// Subclass of NSOperationQueue for [NSOperationQueue mainQueue], with appropriate properties made immutable
#pragma region _NSOperationQueue_MainQueue

@interface _NSOperationQueue_MainQueue : NSOperationQueue
@end

@implementation _NSOperationQueue_MainQueue
- (dispatch_queue_t)underlyingQueue {
    return dispatch_get_main_queue();
}

- (void)setUnderlyingQueue:(dispatch_queue_t)queue {
}

- (NSQualityOfService)qualityOfService {
    return NSQualityOfServiceUserInteractive;
}

- (void)setQualityOfService:(NSQualityOfService)quality {
}
@end

#pragma endregion // _NSOperationQueue_MainQueue

#pragma region NSOperationQueue

@interface NSOperationQueue () {
@private
    // The actual dispatch queue to which operations are dispatched
    // Currently, changing between dispatch queues is done by reassigning this member
    // TODO #2241:  WinObjC's libdispatch cannot create concurrent dispatch queues (DISPATCH_QUEUE_CONCURRENT just returns a serial queue)
    //              Because of this, NSOperationQueue has to directly use the global concurrent queues to get concurrent behavior
    //              Once DISPATCH_QUEUE_CONCURRENT works properly, this should dispatch_set_target instead of reassigning the member
    dispatch_queue_t _dispatchQueue;

    // This backs the public property underlyingQueue. if this is set, _dispatchQueue is set to this
    dispatch_queue_t _underlyingQueue;

    NSQualityOfService _qualityOfService;

    // Protects _dispatchQueue, _underlyingQueue, and _qualityOfService
    // Should never be locked before _concurrentOperationCountLock
    std::recursive_mutex _dispatchQueueLock;

    StrongId<NSMutableArray> _operations;

    std::atomic_bool _suspended;

    // Tracks the number of currently executing operations, for use with maxConcurrentOperationCount
    NSInteger _currentConcurrentOperationCount;
    NSInteger _maxConcurrentOperationCount;

    // Enqueued operations to execute once execution is possible
    // Enqueued elements are:
    // 1) already stored in _operations, so don't need to be separately retained
    // 2) delayed due to the queue's suspension, or due to hitting maxConcurrentOperations
    // 3) sorted according to queuePriority, with highest priority first
    // Non-ready operations are handled separately
    std::priority_queue<NSOperation*, std::vector<NSOperation*>, _NSOperation_ComparePrioritySTL> _queuedOperations;
    std::recursive_mutex _concurrentOperationCountLock; // Protects _currentConcurrentOperationCount and _queuedOperations
}

- (BOOL)_belowMaxConcurrentOperations;
- (void)_startOperation:(NSOperation*)operation;
- (void)_popAndStartQueuedOperations;
- (void)_setDispatchQueueUsingQualityOfService;
@end

@implementation NSOperationQueue

// Private helper that checks whether maxConcurrentOperationCount has been exceeded
- (BOOL)_belowMaxConcurrentOperations {
    std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
    NSInteger maxOps = self.maxConcurrentOperationCount;
    return (maxOps <= 0) || (_currentConcurrentOperationCount < maxOps);
}

// Private helper that tries to start a single NSOperation on the dispatch queue and manages associated state.
// If the operation is not startable due to the state of the queue (ie: suspension, above max concurrent operations)
// it is enqueued for later.
// If the operation is not ready, this is a no-op
// (the operation can try to start again later once the queue receives a KVO notification that it became ready)
- (void)_startOperation:(NSOperation*)operation {
    @synchronized(operation) {
        if (operation.executing || operation.finished) {
            TraceError(TAG, L"Attempted to start an operation that was already executing or finished; ignoring.");
            return;
        }

        if (!operation.ready) {
            // Deliberate no-op (see function comments)
            return;
        }

        {
            std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
            if ((self.suspended) || (![self _belowMaxConcurrentOperations])) {
                // Enqueue the operation for later
                _queuedOperations.push(operation);
                return;
            }

            ++_currentConcurrentOperationCount;
        } // _concurrentOperationCountLock scope

        std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
        dispatch_async(_dispatchQueue, ^{
            // Check if currentQueue needs to be changed
            StrongId<NSOperationQueue*>& currentQueue = _getCurrentQueue();
            StrongId<NSOperationQueue*> prevCurrentQueue(currentQueue.get());
            bool needToChangeCurrentQueue = (![[NSThread currentThread] isMainThread]) && (!(self == currentQueue.get()));

            // If so, cache the previous currentQueue stored in the threadDictionary, and store the new currentQueue
            if (needToChangeCurrentQueue) {
                currentQueue = self;
            }

            // Restore state once the operation is done, and attempt to start any queued operations
            auto cleanup = wil::ScopeExit([self, &currentQueue, &prevCurrentQueue, needToChangeCurrentQueue]() {
                if (needToChangeCurrentQueue) {
                    currentQueue = prevCurrentQueue.get();
                }

                std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
                --_currentConcurrentOperationCount;

                [self _popAndStartQueuedOperations];
            });

            // Run the actual operation
            [operation start];
        });
    }
}

// Private helper that starts as many queued operations as possible
- (void)_popAndStartQueuedOperations {
    if (!self.suspended) {
        std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
        while (([self _belowMaxConcurrentOperations]) && (!_queuedOperations.empty())) {
            NSOperation* operation = _queuedOperations.top();
            _queuedOperations.pop();
            [self _startOperation:operation];
        }
    }
}

// Private helper that sets _dispatchQueue based on the current quality of service
- (void)_setDispatchQueueUsingQualityOfService {
    std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
    _dispatchQueue = dispatch_get_global_queue(_QOSClassForNSQualityOfService(self.qualityOfService), 0);
}

+ (BOOL)automaticallyNotifiesObserversOfOperations {
    // This class manually notifies for operations, which generates changes in addOperation/s.
    return NO;
}

+ (BOOL)automaticallyNotifiesObserversOfOperationCount {
    // This class manually notifies for operationCount, as it changes at the same time as operations
    return NO;
}

- (instancetype)init {
    if (self = [super init]) {
        _operations.attach([NSMutableArray new]);
        _maxConcurrentOperationCount = NSOperationQueueDefaultMaxConcurrentOperationCount;
        _qualityOfService = NSQualityOfServiceDefault;

        if (dispatch_queue_t underlyingQueue = [self underlyingQueue]) {
            _dispatchQueue = underlyingQueue;
        } else {
            [self _setDispatchQueueUsingQualityOfService];
        }
    }
    return self;
}

- (void)dealloc {
    [_name release];

    for (NSOperation* op in _operations.get()) {
        [op removeObserver:self forKeyPath:@"isFinished" context:&_NSOperationQueue_IsFinishedContext];
        [op removeObserver:self forKeyPath:@"isReady" context:&_NSOperationQueue_IsReadyContext];
    }

    if (_underlyingQueue) {
        dispatch_release(_underlyingQueue);
    }

    [super dealloc];
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    NSOperation* op = static_cast<NSOperation*>(object);
    if ((context == &_NSOperationQueue_IsFinishedContext) && (op.finished)) {
        // Minor optimization:
        // Because of constraints in addOperation:, it is safe to assume that there is exactly one instance of op in the array
        // removeObject: keeps going after finding first instance of object, which is unnecessary work
        // indexOfObject: uses isEqual: instead of ==; for NSOperations, pointer equality is probably sufficient
        // Use indexOfObjectIdentical:op instead
        @synchronized(_operations.get()) {
            NSUInteger index = [_operations indexOfObjectIdenticalTo:op];
            if (index == NSNotFound) {
                TraceError(TAG, L"Observed an operation finishing that was not in this operation queue");
                return;
            }

            [self willChangeValueForKey:@"operations"];
            [self willChangeValueForKey:@"operationCount"];
            [_operations removeObjectAtIndex:index];
            [self didChangeValueForKey:@"operationCount"];
            [self didChangeValueForKey:@"operations"];
        }

        // Clean up state from addOperation:
        [op removeObserver:self forKeyPath:@"isFinished" context:&_NSOperationQueue_IsFinishedContext];
        [op removeObserver:self forKeyPath:@"isReady" context:&_NSOperationQueue_IsReadyContext];

    } else if ((context == &_NSOperationQueue_IsReadyContext) && (op.ready) && !(op.executing)) {
        NSOperation* op = static_cast<NSOperation*>(object);
        [self _startOperation:op];
    }
}

/**
 @Status Interoperable
*/
+ (NSOperationQueue*)currentQueue {
    if ([[NSThread currentThread] isMainThread]) {
        return [[self class] mainQueue];
    }

    return _getCurrentQueue().get();
}

/**
 @Status Interoperable
*/
+ (NSOperationQueue*)mainQueue {
    static StrongId<NSOperationQueue> mainQueue = [[_NSOperationQueue_MainQueue new] autorelease];
    return mainQueue;
}

/**
 @Status Interoperable
*/
- (void)addOperation:(NSOperation*)op {
    @synchronized(op) {
        if (op.executing || op.finished) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException
                                           reason:@"operation is already or finished executing"
                                         userInfo:nil];
        }

        if (!op._markInQueue) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException
                                           reason:@"operation is already in an operation queue"
                                         userInfo:nil];
        }

        [self willChangeValueForKey:@"operations"];
        [self willChangeValueForKey:@"operationCount"];

        @synchronized(_operations.get()) {
            [_operations addObject:op];
        }

        [self didChangeValueForKey:@"operationCount"];
        [self didChangeValueForKey:@"operations"];

        [op addObserver:self forKeyPath:@"isFinished" options:0 context:&_NSOperationQueue_IsFinishedContext];
        [op addObserver:self forKeyPath:@"isReady" options:0 context:&_NSOperationQueue_IsReadyContext];

        [self _startOperation:op];
    }
}

/**
 @Status Interoperable
*/
- (void)addOperations:(NSArray<NSOperation*>*)ops waitUntilFinished:(BOOL)wait {
    NSArray<NSOperation*>* sortedOps = [ops sortedArrayUsingFunction:_compareOperationPriority context:nullptr];
    [self willChangeValueForKey:@"operations"];
    [self willChangeValueForKey:@"operationCount"];
    for (NSOperation* operation in sortedOps) {
        [self addOperation:operation];
    }
    [self didChangeValueForKey:@"operationCount"];
    [self didChangeValueForKey:@"operations"];

    if (wait) {
        for (NSOperation* operation in sortedOps) {
            [operation waitUntilFinished];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)addOperationWithBlock:(void (^)(void))block {
    [self addOperation:[NSBlockOperation blockOperationWithBlock:block]];
}

/**
 @Status Interoperable
*/
- (NSArray<__kindof NSOperation*>*)operations {
    @synchronized(_operations.get()) {
        return [[_operations copy] autorelease];
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)operationCount {
    @synchronized(_operations.get()) {
        return [_operations count];
    }
}

/**
 @Status Interoperable
*/
- (void)cancelAllOperations {
    @synchronized(_operations.get()) {
        for (NSOperation* operation in _operations.get()) {
            [operation cancel];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)waitUntilAllOperationsAreFinished {
    while (NSOperation* lastOp = [_operations lastObject]) {
        [lastOp waitUntilFinished];
    }
}

/**
 @Status Interoperable
*/
- (NSQualityOfService)qualityOfService {
    std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
    return _qualityOfService;
}

/**
 @Status Interoperable
*/
- (void)setQualityOfService:(NSQualityOfService)quality {
    std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
    if (_qualityOfService == quality) {
        return;
    }

    _qualityOfService = quality;

    if (self.underlyingQueue) {
        return; // underlyingQueue overrides qualityOfService
    }

    // Switch to using a dispatch queue with the right QOS
    [self _setDispatchQueueUsingQualityOfService];
}

/**
 @Status Interoperable
*/
- (BOOL)isSuspended {
    return _suspended;
}

/**
 @Status Interoperable
*/
- (void)setSuspended:(BOOL)suspended {
    _suspended = suspended;
    [self _popAndStartQueuedOperations];
}

/**
 @Status Interoperable
*/
- (NSInteger)maxConcurrentOperationCount {
    std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
    return _maxConcurrentOperationCount;
}

/**
 @Status Interoperable
*/
- (void)setMaxConcurrentOperationCount:(NSInteger)maxConcurrentOperationCount {
    std::lock_guard<std::recursive_mutex> lock(_concurrentOperationCountLock);
    _maxConcurrentOperationCount = maxConcurrentOperationCount;
    [self _popAndStartQueuedOperations];
}

/**
 @Status Interoperable
*/
- (dispatch_queue_t)underlyingQueue {
    std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
    return _underlyingQueue;
}

/**
 @Status Interoperable
*/
- (void)setUnderlyingQueue:(dispatch_queue_t)queue {
    std::lock_guard<std::recursive_mutex> lock(_dispatchQueueLock);
    if (queue == _underlyingQueue) {
        return;
    }

    if (self.operationCount != 0) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"operationCount is not equal to 0" userInfo:nil];
    }

    if (queue == dispatch_get_main_queue()) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"underlyingQueue must not be main queue" userInfo:nil];
    }

    // release a ref to the old underlying queue if it exists
    if (_underlyingQueue) {
        dispatch_release(_underlyingQueue);
    }

    if (queue) {
        // Change _dispatchQueue to use the new underlying queue
        dispatch_retain(queue);
        _dispatchQueue = queue;
    } else {
        // Return to using qualityOfService
        [self _setDispatchQueueUsingQualityOfService];
    }

    _underlyingQueue = queue;
}

@end

#pragma endregion // NSOperationQueue