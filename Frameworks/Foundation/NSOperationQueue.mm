/*
Original Author: Michael Ash on 11/9/08
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

#import "Starboard.h"
#import "Foundation/NSOperation.h"
#import "Foundation/NSMutableArray.h"
#import "Platform/EbrPlatform.h"
#import "Foundation/NSString.h"
#import "Foundation/NSOperationQueue.h"
#import "Foundation/NSThread.h"
#import "Foundation/NSAutoreleasePool.h"
#import "Foundation/NSLock.h"
#import <time.h>
#import "LoggingNative.h"
#import "NSOperationInternal.h"

#include <deque>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <memory>

static const wchar_t* TAG = L"NSOperationQueue";

// NOTE: NSOperationQueuePriv is totally not needed. This class is just acting as the logic encapsulation of state and data ownership for
// the
// operation queue class. The ObjectiveC class itself is perfectly capable of storing and using all this information. This is simply a
// vestige
// of the previous implementation.
class NSOperationQueuePriv {
public:
    NSOperationQueuePriv(NSOperationQueue* parent) : _thread(nullptr), _maxConcurrentOperationCount(1), _isSuspended(NO) {
        _name.attach([[NSString alloc] initWithFormat:@"NSOperationQueue %08x", parent]);
    }

    NSString* Name() {
        std::lock_guard<std::mutex> lock(_lock);
        return _name;
    }

    void SetName(NSString* name) {
        std::lock_guard<std::mutex> lock(_lock);
        _name.attach([name copy]);
    }

    BOOL RunOperationFromLists(unsigned int priority) {
        StrongId<NSOperation> candidateOperation;

        {
            std::lock_guard<std::mutex> lock(_lock);
            if (_candidateOperationsToRunNext[priority].empty()) {
                // No operations "on deck". Go pull some more in from the holding area.
                // Holding area lists are in LIFO order, but we want to execute operations in the order they were enqueued
                // so we reverse the list before we do anything with it.
                _candidateOperationsToRunNext[priority].swap(_operationsHoldingArea[priority]);
                std::reverse(_candidateOperationsToRunNext[priority].begin(), _candidateOperationsToRunNext[priority].end());
            }

            if (!_candidateOperationsToRunNext[priority].empty()) {
                candidateOperation = _candidateOperationsToRunNext[priority].back();
                _candidateOperationsToRunNext[priority].pop_back();
            }
        }

        // Now that a candidate has been determined, drop the lock so that it can potientially run.
        // NOTE: a [operation start] call will potienitally run the operation on this thread.

        if (candidateOperation != nil) {
            // Valid candidate to start. Make sure its actually ready for liftoff.
            if ([candidateOperation isReady]) {
                {
                    std::lock_guard<std::mutex> lock(_lock);

                    // Start it and set to current operation so that accounting methods (operationCount and friends)
                    // can still include this guy even though it is no longer in any list.
                    // NOTE: this (incorrectly) assumes that only one operation is ever running at a time. This is easily
                    // seen to be false whe considering asynchronous operations and any values of _maxConcurrentOperationCount
                    // other than 1 (currently ignored but should be added in the future).
                    _curOperation = candidateOperation;
                }

                [candidateOperation start];

                {
                    std::lock_guard<std::mutex> lock(_lock);

                    // Clear the current operation now that start is finished.
                    // NOTE: the assumption (inccorect) here is that the operation is now finished and
                    // we no longer need any accounting of the current operation.
                    // This is wrong because an operation could be a new fangled asynchronous
                    // one and it could finish muc later (not synchronously executed with [operation start]).
                    _curOperation = nil;
                }
            } else {
                {
                    std::lock_guard<std::mutex> lock(_lock);
                    // Not yet ready. Demote it to the holding area. Will pick it up again later.
                    _operationsHoldingArea[priority].emplace_back(std::move(candidateOperation));
                }

                // We claim that we have done some work here. This keeps the queue pumping and
                // will eventually bring this item back out for consideration and will continue
                // through this list for anyother ready operations.
                return TRUE;
            }
        }

        return candidateOperation != nil;
    }

    void WaitUntilNotSuspended() {
        std::unique_lock<std::mutex> lock(_lock);
        while (_isSuspended) {
            _suspendedCondition.wait(lock);
        }
        lock.unlock();
    }

    void ClearCandidateLists() {
        std::lock_guard<std::mutex> lock(_lock);
        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            _candidateOperationsToRunNext[i].clear();
        }
    }

    BOOL HasMoreWork() {
        std::lock_guard<std::mutex> lock(_lock);

        BOOL toReturn = _HasMoreWorkNoLock();

        if (!toReturn) {
            // No work left to do. Clear out the thread here. This signals that a new work thread is needed to be created and
            // current one can end its execution.
            //
            // NOTE: its awfully weird to have a "getter" have a side effect like nil'ing out _thread. This is needed because the
            // decision to stop the work thread is made based on not having more work and this means that the thread needs restarted
            // on the next go around. A real fix is to not manage the thread manually and use a threadpool or other mechanism to run the
            // operations.
            _thread = nil;
        }

        return toReturn;
    }

    void AddOperation(NSOperation* operation, unsigned int priority, NSOperationQueue* queue, SEL selector) {
        {
            std::lock_guard<std::mutex> lock(_lock);

            StrongId<NSOperation> strongOperation = operation;
            _operationsHoldingArea[priority].emplace_back(std::move(strongOperation));
            if (_thread == nil || _thread.get().finished) {
                _thread.attach([[NSThread alloc] initWithTarget:queue selector:selector object:nil]);
                [_thread start];
            }
        }

        _workAvailableCondition.notify_one();
    }

    void SignalAllWorkDone() {
        _allWorkDoneCondition.notify_one();
    }

    void WaitUntilAllOperationsAreFinished() {
        std::unique_lock<std::mutex> lock(_lock);

        while (_HasMoreWorkNoLock()) {
            _allWorkDoneCondition.wait(lock);
        }
    }

    void SetMaxConcurrentOperationCount(NSInteger count) {
        std::lock_guard<std::mutex> lock(_lock);
        _maxConcurrentOperationCount = count;
    }

    NSInteger MaxConcurrentOperationCount() {
        std::lock_guard<std::mutex> lock(_lock);
        return _maxConcurrentOperationCount;
    }

    NSArray<NSOperation*>* GetOperations() {
        std::lock_guard<std::mutex> lock(_lock);

        id ret = [NSMutableArray array];

        if (_curOperation != nil) {
            [ret addObject:_curOperation];
        }

        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            if (!_operationsHoldingArea[i].empty()) {
                for (const auto& op : _operationsHoldingArea[i]) {
                    [ret addObject:op];
                }
            }

            if (!_candidateOperationsToRunNext[i].empty()) {
                for (const auto& op : _candidateOperationsToRunNext[i]) {
                    [ret addObject:op];
                }
            }
        }

        return ret;
    }

    unsigned int GetOperationCount() {
        std::lock_guard<std::mutex> lock(_lock);

        unsigned int ret = 0;

        if (_curOperation != nil) {
            ret++;
        }

        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            ret += _operationsHoldingArea[i].size();
            ret += _candidateOperationsToRunNext[i].size();
        }

        return ret;
    }

    void CancelAllOperations() {
        std::lock_guard<std::mutex> lock(_lock);

        if (_curOperation != nil) {
            [_curOperation cancel];
        }

        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            if (!_operationsHoldingArea[i].empty()) {
                for (const auto& op : _operationsHoldingArea[i]) {
                    [op cancel];
                }
            }

            if (!_candidateOperationsToRunNext[i].empty()) {
                for (const auto& op : _candidateOperationsToRunNext[i]) {
                    [op cancel];
                }
            }
        }
    }

    void Resume() {
        BOOL shouldBroadcast = FALSE;
        {
            std::lock_guard<std::mutex> lock(_lock);
            if (_isSuspended) {
                _isSuspended = FALSE;
                shouldBroadcast = TRUE;
            }
        }

        if (shouldBroadcast) {
            _suspendedCondition.notify_all();
        }
    }

    void Suspend() {
        std::lock_guard<std::mutex> lock(_lock);
        _isSuspended = TRUE;
    }

    BOOL IsSuspended() {
        std::lock_guard<std::mutex> lock(_lock);
        return _isSuspended;
    }

private:
    // NOTE: this method is intended to be run under the lock but does not take the lock itself.
    BOOL _HasMoreWorkNoLock() {
        if (_curOperation != nil) {
            return TRUE;
        }

        // NOTE: This may be insufficient / racy. This only checks the holding area and not "on deck" items.
        // Its possible that the check is made right after a transfer to on deck which would incorrectly report
        // all done when some items may go back into holding and certainly all of them aren't completed. This particularly
        // would affect WaitUntilAllOperationsAreFinished.
        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            if (_operationsHoldingArea[i].empty()) {
                return TRUE;
            }
        }

        return FALSE;
    }

    std::deque<StrongId<NSOperation>> _candidateOperationsToRunNext[NSOperationQueuePriority_Count];
    std::deque<StrongId<NSOperation>> _operationsHoldingArea[NSOperationQueuePriority_Count];

    StrongId<NSThread> _thread;

    DWORD _maxConcurrentOperationCount;
    std::condition_variable _workAvailableCondition;
    std::condition_variable _suspendedCondition;
    std::condition_variable _allWorkDoneCondition;
    StrongId<NSOperation> _curOperation;
    BOOL _isSuspended;

    StrongId<NSString> _name;

    // NOTE: a normal (as opposed to recursive) mutex is used here to interop with condition variable.
    // This helps simplify the locking in this class in that fewer locks are used so the overall ownership
    // of the state this class owns is encapsulated under the single lock. However, this also means that
    // special care is needed to ensure that no re-entrant functions are used while under the lock.
    std::mutex _lock;
};

@interface NSOperationQueue () {
    std::unique_ptr<NSOperationQueuePriv> _priv;
    dispatch_queue_t _completionQueue;
}
@end

@implementation NSOperationQueue

- (id)_workThread {
    do {
        [self _doMainWork];
    } while (_priv->HasMoreWork());

    _priv->SignalAllWorkDone();

    return self;
}

- (NSOperationQueue*)_doMainWork {
    // Start from a clean slate by clearing out the candidate lists.
    // NOTE: This assumes that the candidate lists are already empty as clearing the candidate list
    // when not empty would mean permanently losing that operation. Its probably advisable to remove this
    // all together or restructuring the holding area -> candidate list transition to make sure this always holds true.
    _priv->ClearCandidateLists();

    BOOL didWork;

    id innerPool = [[NSAutoreleasePool alloc] init];

    do {
        didWork = FALSE;

        for (int i = 0; i < NSOperationQueuePriority_Count; i++) {
            // Wait until the operation queue is no longer suspended.
            // NOTE: if an operation queue becomes suspended after this point, the "in flight" operation
            // will not be suspended, it will continue as if the queue is still running.
            _priv->WaitUntilNotSuspended();
            didWork |= _priv->RunOperationFromLists(i);
        }
    } while (didWork);

    [innerPool release];

    return self;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _completionQueue = dispatch_queue_create("NSOperation finish queue", nullptr);
        _priv = std::make_unique<NSOperationQueuePriv>(self);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)addOperation:(id)op {
    [op _setCompletionQueue:_completionQueue];

    unsigned priority = 1;
    if ([op queuePriority] < NSOperationQueuePriorityNormal) {
        priority = 2;
    } else if ([op queuePriority] > NSOperationQueuePriorityNormal) {
        priority = 0;
    }

    _priv->AddOperation(op, priority, self, @selector(_workThread));
}

/**
 @Status Interoperable
*/
- (void)addOperationWithBlock:(void (^)())block {
    id op = [NSOperation new];
    [op setCompletionBlock:block];
    [self addOperation:op];
    [op release];
}

/**
 @Status Interoperable
*/
- (void)addOperations:(id)operations waitUntilFinished:(BOOL)wait {
    for (id curOp in operations) {
        [self addOperation:curOp];
    }

    if (wait) {
        for (id curOp in operations) {
            [curOp waitUntilFinished];
        }
    }
}

/**
 @Status Stub
*/
- (void)setMaxConcurrentOperationCount:(NSInteger)count {
    UNIMPLEMENTED();
    _priv->SetMaxConcurrentOperationCount(count);
}

/**
 @Status Stub
*/
- (NSInteger)maxConcurrentOperationCount {
    UNIMPLEMENTED();
    return _priv->MaxConcurrentOperationCount();
}

/**
 @Status Interoperable
*/
- (NSArray<NSOperation*>*)operations {
    return _priv->GetOperations();
}

/**
 @Status Interoperable
*/
- (unsigned)operationCount {
    return _priv->GetOperationCount();
}

/**
 @Status Interoperable
*/
- (void)cancelAllOperations {
    return _priv->CancelAllOperations();
}

/**
 @Status Interoperable
*/
- (void)waitUntilAllOperationsAreFinished {
    _priv->WaitUntilAllOperationsAreFinished();
}

/**
 @Status Interoperable
*/
- (void)setSuspended:(BOOL)suspend {
    if (suspend) {
        [self suspend];
    } else {
        [self resume];
    }
}

/**
 @Status Interoperable
*/
- (id)resume {
    _priv->Resume();
    return self;
}

/**
 @Status Interoperable
*/
- (id)suspend {
    _priv->Suspend();
    return self;
}

/**
 @Status Interoperable
*/
- (void)setName:(id)name {
    _priv->SetName(name);
}

/**
 @Status Interoperable
*/
- (id)name {
    return _priv->Name();
}

- (BOOL)isSuspended {
    return _priv->IsSuspended();
}

/**
 @Status Interoperable
*/
+ (id)mainQueue {
    static StrongId<NSOperationQueue> _mainQueue = [[[self alloc] init] autorelease];
    return _mainQueue;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    dispatch_release(_completionQueue);
    [super dealloc];
}

/**
 @Status Interoperable
*/
+ (id)currentQueue {
    if ([NSThread isMainThread]) {
        return [self mainQueue];
    }

    // NOTE: this is obviously wrong as self is a META class not an instance of the class.
    // Likely there needs to be thread local storage queue or perhaps just only return the mainQueue
    assert(0);

    return self;
}

@end
