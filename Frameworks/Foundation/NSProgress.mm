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

#import <Starboard.h>
#import <Foundation/NSProgress.h>
#import <Foundation/NSBundle.h>
#import <memory>
#import <stack>

NSString* const NSProgressEstimatedTimeRemainingKey = @"NSProgressEstimatedTimeRemainingKey";
NSString* const NSProgressThroughputKey = @"NSProgressThroughputKey";
NSString* const NSProgressKindFile = @"NSProgressKindFile";
NSString* const NSProgressFileOperationKindKey = @"NSProgressFileOperationKindKey";
NSString* const NSProgressFileTotalCountKey = @"NSProgressFileTotalCountKey";
NSString* const NSProgressFileCompletedCountKey = @"NSProgressFileCompletedCountKey";
NSString* const NSProgressFileOperationKindDownloading = @"NSProgressFileOperationKindDownloading";
NSString* const NSProgressFileOperationKindDecompressingAfterDownloading = @"NSProgressFileOperationKindDecompressingAfterDownloading";
NSString* const NSProgressFileOperationKindReceiving = @"NSProgressFileOperationKindReceiving";
NSString* const NSProgressFileOperationKindCopying = @"NSProgressFileOperationKindCopying";

// Struct that supports the currentProgress-related APIs
struct CurrentProgress {
    StrongId<NSProgress> progress;

    // Gets assigned to the _parentPendingUnitCount of child NSProgresses
    int64_t pendingUnitCountToAssign;

    // See NSProgress class reference:
    // If you don’t create any child progress objects between the calls to becomeCurrentWithPendingUnitCount: and resignCurrent,
    // the “parent” progress automatically updates its completedUnitCount by adding the pending units.
    //
    // On the reference platform, this seems to not extend to children explicitly added in addChild, however
    bool childCreated;
};

// Stack of NSProgress objects that have becomeCurrent
thread_local static std::shared_ptr<std::stack<CurrentProgress>> s_currentProgressStack;

// Returns the stack of NSProgress objects that have becomeCurrent on the current thread, initializing it if necessary
static decltype(s_currentProgressStack)& _getProgressStackForCurrentThread() {
    if (!s_currentProgressStack) {
        s_currentProgressStack = std::make_shared<std::stack<CurrentProgress>>();
    }

    return s_currentProgressStack;
}

@implementation NSProgress {
@private
    // explicitly declared here for custom set/get
    int64_t _completedUnitCount;
    StrongId<NSString> _localizedDescription;
    StrongId<NSString> _localizedAdditionalDescription;

    // Pending unit count must be kept per-child, as different children can have different pending unit counts
    int64_t _parentPendingUnitCount;
    StrongId<NSProgress> _parent;
}

/**
 @Status Interoperable
*/
- (id)init {
    if (self = [super init]) {
        _cancellable = YES;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_userInfo release];
    [_kind release];
    [_cancellationHandler release];
    [_pausingHandler release];
    [_resumingHandler release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithParent:(NSProgress*)parentProgressOrNil userInfo:(NSDictionary*)userInfoOrNil {
    if (self = [super init]) {
        if (parentProgressOrNil) {
            if ([parentProgressOrNil isEqual:[NSProgress currentProgress]]) {
                // Assign parent
                _parent = parentProgressOrNil;

                // s_currentProgressStack must not be empty to have reached here
                CurrentProgress& current = s_currentProgressStack->top();

                // Keep track of the pendingUnitCount to increment in the parent
                _parentPendingUnitCount = current.pendingUnitCountToAssign;

                // See NSProgress class reference:
                // If you don’t create any child progress objects between the calls to becomeCurrentWithPendingUnitCount: and resignCurrent,
                // the “parent” progress automatically updates its completedUnitCount by adding the pending units.
                // Mark that a child was created from currentProgress
                current.childCreated = true;

            } else {
                // For some reason, the reference platform seems to only care about this here, and nowhere else
                [NSException raise:NSInvalidArgumentException format:@"The parent of an NSProgress object must be the currentProgress"];
            }
        }

        _userInfo = userInfoOrNil ? [[NSMutableDictionary alloc] initWithDictionary:userInfoOrNil] : [NSMutableDictionary new];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (NSProgress*)discreteProgressWithTotalUnitCount:(int64_t)unitCount {
    NSProgress* ret = [[NSProgress alloc] initWithParent:nil userInfo:nil];
    ret->_totalUnitCount = unitCount;
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount {
    NSProgress* ret = [[NSProgress alloc] initWithParent:[NSProgress currentProgress] userInfo:nil];
    ret->_totalUnitCount = unitCount;
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (NSProgress*)progressWithTotalUnitCount:(int64_t)unitCount
                                   parent:(NSProgress*)parent
                         pendingUnitCount:(int64_t)portionOfParentTotalUnitCount {
    // This does not seem to cancel the resignCurrent automatic behavior either
    NSProgress* ret = [NSProgress discreteProgressWithTotalUnitCount:unitCount];
    [parent addChild:ret withPendingUnitCount:portionOfParentTotalUnitCount];
    return ret;
}

/**
 @Status Interoperable
*/
+ (NSProgress*)currentProgress {
    auto currentProgressStack = _getProgressStackForCurrentThread();
    return currentProgressStack->empty() ? nullptr : currentProgressStack->top().progress;
}

/**
 @Status Interoperable
*/
- (void)becomeCurrentWithPendingUnitCount:(int64_t)unitCount {
    if ([self isEqual:[NSProgress currentProgress]]) {
        [NSException raise:NSInvalidArgumentException
                    format:@"NSProgress object is already current on this thread %@", [NSThread currentThread]];

    } else {
        _getProgressStackForCurrentThread()->push({ self, unitCount });
    }
}

/**
 @Status Interoperable
*/
- (void)addChild:(NSProgress*)child withPendingUnitCount:(int64_t)inUnitCount {
    @synchronized(child) {
        if (child->_parent) {
            [NSException raise:NSInvalidArgumentException
                        format:@"NSProgress %x was already the child of another progress %x", child, (id)child->_parent];

        } else {
            child->_parent = self;
            child->_parentPendingUnitCount = inUnitCount;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)resignCurrent {
    // If self is the top element on the current progress stack, pop it
    // Be sure to check if self == nil here, otherwise [nil resignCurrent] may cause a pop on an empty stack
    if (self && [self isEqual:[NSProgress currentProgress]]) {
        auto currentProgressStack = _getProgressStackForCurrentThread();

        // See NSProgress class reference:
        // If you don’t create any child progress objects between the calls to becomeCurrentWithPendingUnitCount: and resignCurrent,
        // the "parent" progress automatically updates its completedUnitCount by adding the pending units.
        if (!currentProgressStack->top().childCreated) {
            [self _incrementCompletedUnitCount:currentProgressStack->top().pendingUnitCountToAssign];
        }

        currentProgressStack->pop();

    } else {
        [NSException raise:NSInvalidArgumentException
                    format:@"NSProgress was not the current progress on this thread %@", [NSThread currentThread]];
    }
}

/**
 @Status Interoperable
*/
- (void)setCompletedUnitCount:(int64_t)inUnitCount {
    // Override synthesized setter so that parent can be updated with pendingUnitCount if necessary
    @synchronized(self) { // Property is atomic
        if ((_parent) && (inUnitCount >= _totalUnitCount) && (inUnitCount != _completedUnitCount)) {
            [_parent _incrementCompletedUnitCount:_parentPendingUnitCount];
        }

        _completedUnitCount = inUnitCount;
    }
}

- (void)_incrementCompletedUnitCount:(int64_t)inUnitCount {
    @synchronized(self) {
        [self setCompletedUnitCount:(_completedUnitCount + inUnitCount)];
    }
}

/**
 @Status Interoperable
*/
- (int64_t)completedUnitCount {
    // Pairing a synthesized getter with a user-defined setter would otherwise generate a warning
    @synchronized(self) { // Property is atomic
        return _completedUnitCount;
    }
}

/**
 @Status Interoperable
*/
- (double)fractionCompleted {
    // Override synthesized getter so that this can be calculated dynamically
    @synchronized(self) { // Property is atomic
        return (double)_completedUnitCount / _totalUnitCount;
    }
}

/**
 @Status Interoperable
*/
- (void)cancel {
    decltype(_cancellationHandler) cancellationHandler;

    @synchronized(self) {
        _cancelled = YES;
        cancellationHandler = _cancellationHandler;
    }

    if (cancellationHandler) {
        cancellationHandler();
    }
}

/**
 @Status Interoperable
*/
- (void)pause {
    decltype(_pausingHandler) pausingHandler;

    @synchronized(self) {
        _paused = YES;
        pausingHandler = _pausingHandler;
    }

    if (pausingHandler) {
        pausingHandler();
    }
}

/**
 @Status Interoperable
*/
- (void)resume {
    decltype(_resumingHandler) resumingHandler;

    @synchronized(self) {
        _paused = NO;
        resumingHandler = _resumingHandler;
    }

    if (resumingHandler) {
        resumingHandler();
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isIndeterminate {
    return (_totalUnitCount <= 0) && (_completedUnitCount <= 0);
}

/**
 @Status Interoperable
*/
- (void)setUserInfoObject:(id)objectOrNil forKey:(NSString*)key {
    [reinterpret_cast<NSMutableDictionary*>(_userInfo) setObject:objectOrNil forKey:key];
}

/**
 @Status Interoperable
*/
- (void)setLocalizedDescription:(NSString*)newDescription {
    @synchronized(self) {
        _localizedDescription.attach([newDescription copy]);
    }
}

/**
 @Status Interoperable
*/
- (NSString*)localizedDescription {
    @synchronized(self) {
        // Return user-specified value if set
        if (_localizedDescription) {
            return [[_localizedDescription copy] autorelease];
        }

        // Otherwise, dynamically describe
        if ([_kind isEqual:NSProgressKindFile]) {
            NSString* operationKind = [_userInfo objectForKey:NSProgressFileOperationKindKey];
            NSString* verbString = NSLocalizedString(@"Processing", nil);

            if (operationKind) {
                if ([operationKind isEqual:NSProgressFileOperationKindDownloading]) {
                    verbString = NSLocalizedString(@"Downloading", nil);

                } else if ([operationKind isEqual:NSProgressFileOperationKindDecompressingAfterDownloading]) {
                    verbString = NSLocalizedString(@"Decompressing", nil);

                } else if ([operationKind isEqual:NSProgressFileOperationKindReceiving]) {
                    verbString = NSLocalizedString(@"Receiving", nil);

                } else if ([operationKind isEqual:NSProgressFileOperationKindCopying]) {
                    verbString = NSLocalizedString(@"Copying", nil);
                }
            }

            NSNumber* totalFiles = [_userInfo objectForKey:NSProgressFileTotalCountKey];
            if (totalFiles) {
                return [NSString localizedStringWithFormat:@"%@ %d files...", verbString, [totalFiles intValue]];
            } else {
                return [NSString localizedStringWithFormat:@"%@ files...", verbString];
            }

        } else {
            return [NSString localizedStringWithFormat:@"%.0f completed", [self fractionCompleted] * 100];
        }

        return @"";
    }
}

/**
 @Status Interoperable
*/
- (void)setLocalizedAdditionalDescription:(NSString*)newDescription {
    @synchronized(self) {
        _localizedAdditionalDescription.attach([newDescription copy]);
    }
}

/**
 @Status Interoperable
*/
- (NSString*)localizedAdditionalDescription {
    @synchronized(self) {
        // Return user-specified value if set
        if (_localizedAdditionalDescription) {
            return [[_localizedAdditionalDescription copy] autorelease];
        }

        NSString* ret = @"";

        // Otherwise, dynamically describe
        if ([_kind isEqual:NSProgressKindFile]) {
            if ([_userInfo count] > 1) {
                NSNumber* completedFiles = [_userInfo objectForKey:NSProgressFileCompletedCountKey];
                NSNumber* totalFiles = [_userInfo objectForKey:NSProgressFileTotalCountKey];
                if (completedFiles && totalFiles) {
                    ret = [ret stringByAppendingFormat:NSLocalizedString(@"%d of %d files", nil),
                                                       [totalFiles intValue],
                                                       [completedFiles intValue]];
                }

                NSNumber* bytesPerSecond = [_userInfo objectForKey:NSProgressThroughputKey];
                if (bytesPerSecond) {
                    ret = [ret stringByAppendingFormat:NSLocalizedString(@"(%d bytes/second)", nil), [bytesPerSecond intValue]];
                }

            } else {
                ret = [NSString
                    localizedStringWithFormat:NSLocalizedString(@"%lld bytes of %lld bytes", nil), _completedUnitCount, _totalUnitCount];
            }

        } else {
            ret = [ret stringByAppendingFormat:NSLocalizedString(@"%lld of %lld", nil), _completedUnitCount, _totalUnitCount];
        }

        NSNumber* secondsRemaining = [_userInfo objectForKey:NSProgressEstimatedTimeRemainingKey];
        if (secondsRemaining) {
            if ([ret length] > 0) {
                ret = [ret stringByAppendingString:NSLocalizedString(@" - ", nil)];
            }

            ret = [ret stringByAppendingFormat:NSLocalizedString(@"%d seconds remaining", nil), [secondsRemaining intValue]];
        }

        return ret;
    }
}

@end