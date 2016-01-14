/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Starboard.h>
#import <CoreFoundation/CFRunLoop.h>
#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSLock.h>
#import <Foundation/NSString.h>
#import <Foundation/NSThread.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSNotificationCenter.h>
#import <Foundation/NSOperationQueue.h>
#import <Windows.h>
#import "NSRunLoopState.h"
#import "NSOrderedPerform.h"
#import "NSRunLoop+Internal.h"
#import "dispatch/dispatch.h"

extern "C" NSString* const NSDefaultRunLoopMode = @"kCFRunLoopDefaultMode";
extern "C" NSString* const NSRunLoopCommonModes = @"kCFRunLoopCommonModes";

@interface NSRunLoop ()
@property (readwrite, copy) NSString* currentMode;
@end

static void DispatchMainRunLoopWakeup(void* arg) {
    [[NSRunLoop mainRunLoop] _wakeUp];
}

@implementation NSRunLoop : NSObject
+ (void)initialize {
    dispatch_set_wakeup_callback(DispatchMainRunLoopWakeup, NULL);
}

/**
 @Status Interoperable
*/
+ (NSRunLoop*)currentRunLoop {
    return [[NSThread currentThread] _runLoop];
}

/**
 @Status Interoperable
*/
+ (NSRunLoop*)mainRunLoop {
    return [[NSThread mainThread] _runLoop];
}

- (NSObject*)init {
    _modes = [NSMutableDictionary new];
    _commonModes = [NSMutableArray new];
    [_commonModes addObject:NSDefaultRunLoopMode];
    _currentMode = [NSDefaultRunLoopMode retain];
    _continue = [NSMutableArray new];
    _orderedPerforms = [NSMutableArray new];
    _orderedLock = [NSLock new];
    pthread_mutex_init(&_modeLock, 0);

    NSRunLoopState* state = [NSRunLoopState new];
    [_modes setObject:state forKey:NSDefaultRunLoopMode];
    [state release];

    return self;
}

- (void)dealloc {
    pthread_mutex_destroy(&_modeLock);
    [_modes release];
    [_currentMode release];
    [_commonModes release];
    [_continue release];
    [_orderedPerforms release];
    [_orderedLock release];
    [super dealloc];
}

- (NSRunLoopState*)_stateForMode:(NSString*)mode {
    pthread_mutex_lock(&_modeLock);

    NSRunLoopState* state = [_modes objectForKey:mode];

    if (state == nil) {
        state = [[NSRunLoopState new] autorelease];
        [_modes setObject:state forKey:mode];
    }

    pthread_mutex_unlock(&_modeLock);
    return state;
}

- (NSArray*)statesForMode:(NSString*)mode {
    NSMutableArray* result = [NSMutableArray new];

    if ([mode isEqualToString:NSRunLoopCommonModes]) {
        for (NSString* common in _commonModes) {
            [result addObject:[self _stateForMode:common]];
        }
    } else {
        [result addObject:[self _stateForMode:mode]];
    }

    return result;
}

- (BOOL)_orderedPerforms {
    BOOL didPerform = NO;
    NSArray* performs = nil;

    [_orderedLock lock];
    performs = [_orderedPerforms copy];
    [_orderedLock unlock];

    int count = [performs count];

    while (--count >= 0) {
        BOOL tryPerform = NO;
        NSOrderedPerform* check = [performs objectAtIndex:count];

        // if this object is still in _orderedPerforms, set tryPerform and remove it,
        // otherwise it was performed or removed already, and there's nothing to do
        [_orderedLock lock];
        unsigned int prevCount = [_orderedPerforms count];
        [_orderedPerforms removeObjectIdenticalTo:check];

        if ([_orderedPerforms count] < prevCount) {
            tryPerform = YES; // it was removed
        }
        [_orderedLock unlock];

        if (tryPerform) {
            // be careful the lock on _orderedPerforms is not held while we fire the perform
            // TODO: right now, all modes are common modes

            if ([check fireInMode:_currentMode]) {
                didPerform = YES;
            } else {
                [_orderedLock lock];
                [_orderedPerforms insertObject:check atIndex:[_orderedPerforms count]];
                [_orderedLock unlock];
            }
        }
    }

    [performs release];

    return didPerform;
}

- (void)_wakeUp {
    [[self _stateForMode:_currentMode] wakeUp];
}

/**
 @Status Interoperable
*/
- (NSDate*)limitDateForMode:(NSString*)mode {
    NSRunLoopState* state = [self _stateForMode:mode];

    if (![mode isEqualToString:_currentMode]) {
        [_currentMode release];
        _currentMode = [mode retain];
        [state changingIntoMode:mode];
    }

    BOOL sleep;

    do {
        sleep = TRUE;

        [state checkHighPriorityEvents];
        if ([self _orderedPerforms]) {
            //[self _wakeUp];
            sleep = FALSE;
        } else {
            [state _notifyObservers:kCFRunLoopBeforeTimers];

            if ([state fireFirstTimer]) {
                //[self _wakeUp];
                sleep = FALSE;
            }
        }
    } while (sleep == FALSE);

    [[NSNotificationQueue defaultQueue] asapProcessMode:mode];

    return [state limitDateForMode:mode];
}

/**
 @Status Interoperable
*/
- (void)acceptInputForMode:(NSString*)mode beforeDate:(NSDate*)date {
    NSRunLoopState* state = [self _stateForMode:mode];

    if ([[NSNotificationQueue defaultQueue] hasIdleNotificationsInMode:mode]) {
        [[NSNotificationQueue defaultQueue] idleProcessMode:mode];
    } else {
        [state acceptInputForMode:mode beforeDate:date];
    }
}

- (void)invalidateTimerWithDelayedPerform:(NSDelayedPerform*)delayed {
    pthread_mutex_lock(&_modeLock);

    NSEnumerator* stateKeys = [_modes keyEnumerator];
    NSEnumerator* stateVals = [_modes objectEnumerator];
    NSString* mode = [stateKeys nextObject];
    NSRunLoopState* modeState = [stateVals nextObject];

    while (mode != nil && modeState != nil) {
        [modeState invalidateTimerWithDelayedPerform:delayed];

        mode = [stateKeys nextObject];
        modeState = [stateVals nextObject];
    }

    assert(mode == nil && modeState == nil);

    pthread_mutex_unlock(&_modeLock);
}

/**
 @Status Interoperable
*/
- (BOOL)runMode:(NSString*)mode beforeDate:(NSDate*)date {
    if (self != [NSRunLoop currentRunLoop]) {
        EbrDebugLog("Warning: attempted running alternate runloop - running current runloop for 1s instead!\n");
        date = [NSDate dateWithTimeIntervalSinceNow:1.0];
        return [[NSRunLoop currentRunLoop] runMode:mode beforeDate:date];
    }

    NSAutoreleasePool* pool = [NSAutoreleasePool new];
    if ([NSThread currentThread] == [NSThread mainThread]) {
        dispatch_main_queue_callback();
    }
    NSDate* limitDate = [self limitDateForMode:mode];

    if (limitDate != nil) {
        limitDate = [limitDate earlierDate:date];
        [self acceptInputForMode:mode beforeDate:limitDate];
    }

    if ([NSThread currentThread] == [NSThread mainThread]) {
        [[NSOperationQueue mainQueue] _doMainWork];
        dispatch_main_queue_callback();
    }

    [pool release];

    return (limitDate != nil);
}

/**
 @Status Interoperable
*/
- (void)runUntilDate:(NSDate*)date {
    while ([self runMode:NSDefaultRunLoopMode beforeDate:date]) {
        if ([date timeIntervalSinceNow] <= 0) {
            break;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)run {
    // Calling -run w/o a pool in place is valid, which is why we need one here
    // for the NSDate. Could get rid of the pool if the date was not autoreleased.
    NSDate* future = [NSDate distantFuture];

    while ([self runMode:NSDefaultRunLoopMode beforeDate:future] && !_stop)
        ;
    _stop = false;
}

/**
 @Status Interoperable
*/
- (void)addInputSource:(NSInputSource*)source forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode addInputSource:source];
    }

    [modeStates release];
}

/**
 @Status Interoperable
*/
- (void)removeInputSource:(NSInputSource*)source forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode removeInputSource:source];
    }

    [modeStates release];
}

/**
 @Status Interoperable
*/
- (void)addTimer:(NSTimer*)timer forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode addTimer:timer];
    }

    [modeStates release];
}

/**
 @Status Stub
*/
- (void)addPort:(id)port forMode:(id)mode {
    UNIMPLEMENTED();
    EbrDebugLog("NSRunLoop addPort not supported\n");
}

- (BOOL)containsTimer:(NSTimer*)timer forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        if ([curMode containsTimer:timer]) {
            [modeStates release];
            return TRUE;
        }
    }

    [modeStates release];

    return FALSE;
}

- (void)addObserver:(NSObject*)observer forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode addObserver:(NSTimer*)observer];
    }

    [modeStates release];
}

- (void)removeObserver:(NSObject*)observer forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode removeObserver:observer];
    }

    [modeStates release];
}

- (void)removeTimer:(NSTimer*)timer forMode:(NSString*)mode {
    NSArray* modeStates = [self statesForMode:mode];

    for (NSRunLoopState* curMode in modeStates) {
        [curMode removeTimer:timer];
    }

    [modeStates release];
}

- (NSArray*)_getModes {
    pthread_mutex_lock(&_modeLock);

    NSEnumerator* keys = [_modes keyEnumerator];

    NSEnumerator* curKey = [keys nextObject];
    NSMutableArray* ret = [NSMutableArray new];

    while (curKey != nil) {
        [ret addObject:curKey];

        curKey = [keys nextObject];
    }

    pthread_mutex_unlock(&_modeLock);
    return ret;
}

- (NSArray*)resolveCommonModes:(NSArray*)modes {
    NSMutableArray* result = [[NSMutableArray alloc] init];

    for (unsigned int i = 0; i < [modes count]; i++) {
        NSString* check = [modes objectAtIndex:i];

        if ([check isEqualToString:NSRunLoopCommonModes]) {
            [result addObjectsFromArray:_commonModes];
        } else {
            [result addObject:check];
        }
    }

    return result;
}

/**
 @Status Interoperable
*/
- (void)performSelector:(SEL)selector target:(NSObject*)target argument:(NSObject*)argument order:(int)order modes:(NSArray*)modes {
    NSArray* performModes = [self resolveCommonModes:modes];
    NSOrderedPerform* perform =
        [[NSOrderedPerform alloc] initWithSelector:selector target:target argument:argument order:order modes:performModes];
    [performModes release];
    [_orderedLock lock];

    int count = [_orderedPerforms count];

    while (--count >= 0) {
        NSOrderedPerform* check = [_orderedPerforms objectAtIndex:count];
        NSInteger checkOrder = (NSInteger)[check order];

        if (checkOrder > order)
            break;
    }
    [_orderedPerforms insertObject:perform atIndex:count + 1];
    [_orderedLock unlock];
    [self _wakeUp];
    [perform release];
}

/**
 @Status Interoperable
*/
- (void)cancelPerformSelector:(const char*)selector target:(NSObject*)target argument:(NSObject*)argument {
    [_orderedLock lock];
    int count = [_orderedPerforms count];

    while (--count >= 0) {
        NSOrderedPerform* check = [_orderedPerforms objectAtIndex:count];

        if (strcmp((char*)[check selector], selector) == 0 && [check target] == target && [check argument] == argument) {
            [_orderedPerforms removeObjectAtIndex:count];
        }
    }
    [_orderedLock unlock];
}

/**
 @Status Interoperable
*/
- (void)cancelPerformSelectorsWithTarget:(NSObject*)target {
    [_orderedLock lock];
    int count = [_orderedPerforms count];

    while (--count >= 0) {
        id check = [_orderedPerforms objectAtIndex:count];

        if ([check target] == target) {
            [_orderedPerforms removeObjectAtIndex:count];
        }
    }
    [_orderedLock unlock];
}

/**
 @Status Interoperable
 @Notes CFRunLoop and NSRunLoop are the same object.  Returns self.
*/
- (NSRunLoop*)getCFRunLoop {
    return self;
}

- (void)_stop {
    _stop = true;
}

+ (void)setUIThreadWaitFunction:(int (*)(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets))callback {
    [NSRunLoopState setUIThreadWaitFunction:callback];
}
@end
