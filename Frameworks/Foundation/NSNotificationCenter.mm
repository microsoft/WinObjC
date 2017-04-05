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
#import <Foundation/NSNotification.h>
#import <Foundation/NSNotificationCenter.h>
#import <LoggingNative.h>

#import <vector>

static const wchar_t* TAG = L"NSNotificationCenter";

@interface _NSNotificationBlockObserver : NSObject {
    // Unlike _NSNotificationReceiver below, this object owns strong references to block and queue.
    // Block notifications are commonly implemented with a weak handle to its owner since the block
    // can itself cause a retain cycle.
    StrongId<void (^)(NSNotification* note)> _block;
    StrongId<NSOperationQueue> _queue;
}
@end
@implementation _NSNotificationBlockObserver
- (instancetype)initWithBlock:(void (^)(NSNotification* note))block queue:(NSOperationQueue*)queue {
    if (self = [super init]) {
        _block = block;
        _queue = queue;
    }
    return self;
}

- (void)invokeWithNotification:(NSNotification*)note {
    if (_queue) {
        // Through observation, it was determined that the reference platform will block
        // until the notification is fired.
        [_queue addOperations:@[ [NSBlockOperation blockOperationWithBlock:^{
                    _block(note);
                }] ]
            waitUntilFinished:YES];
    } else {
        _block(note);
    }
}
@end

@interface _NSNotificationReceiver : NSObject {
@public
    // To avoid retain cycles, NSNotificationCenter does not usually retain its observer/sender...
    NSObject* observer;
    // ... unless the observer was created for internal use.
    BOOL ownsObserver;

    SEL selector;

    NSObject* sender;

    NSString* name;
}
@end

@implementation _NSNotificationReceiver
- (void)postNotification:(NSNotification*)note {
    [observer performSelector:selector withObject:note];
}

- (void)dealloc {
    if (ownsObserver) {
        [observer release];
    }

    [name release];
    [super dealloc];
}
@end

@interface NSNotificationCenter () {
    // Dictionary for quick lookups on post
    StrongId<NSMutableDictionary<NSString*, NSMutableSet<_NSNotificationReceiver*>*>> _observers;

    // All known receivers
    StrongId<NSMutableSet<_NSNotificationReceiver*>> _allReceivers;
}
@end

@implementation NSNotificationCenter
/**
 @Status Interoperable
*/
+ (NSNotificationCenter*)defaultCenter {
    static StrongId<NSNotificationCenter> defaultCenter{[[NSNotificationCenter new] autorelease] };
    return defaultCenter;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _observers.attach([[NSMutableDictionary alloc] init]);
        _allReceivers.attach([[NSMutableSet alloc] init]);
    }
    return self;
}

// INVARIANT: Called under lock.
- (NSMutableSet<_NSNotificationReceiver*>*)_receiverSetForNotificationName:(NSString*)notification createIfMissing:(BOOL)create {
    NSMutableSet<_NSNotificationReceiver*>* receiverSet = [_observers objectForKey:notification];
    if (receiverSet || !create) {
        return receiverSet;
    }

    receiverSet = [NSMutableSet set];
    [_observers setObject:receiverSet forKey:notification];
    return receiverSet;
}

// INVARIANT: Called under lock.
- (NSSet<_NSNotificationReceiver*>*)_receiversForName:(NSString*)name observer:(id)observer object:(id)object {
    NSSet<_NSNotificationReceiver*>* searchSet = _allReceivers;
    if (name) {
        searchSet = [self _receiverSetForNotificationName:name createIfMissing:NO];
        if (!searchSet) {
            return nil;
        }
    }

    __block id blockObserver = observer;
    __block NSString* blockName = name;
    __block id blockObject = object;
    return [searchSet objectsPassingTest:^BOOL(_NSNotificationReceiver* receiver, BOOL* stop) {
        return (blockObserver == nil || receiver->observer == blockObserver) && (blockObject == nil || receiver->sender == blockObject) &&
               (blockName == nil || [receiver->name isEqual:blockName]);
    }];
}

// INVARIANT: Called under lock.
- (void)_addReceiver:(_NSNotificationReceiver*)receiver {
    StrongId<NSMutableSet<_NSNotificationReceiver*>> receivers = [self _receiverSetForNotificationName:receiver->name createIfMissing:YES];
    [receivers addObject:receiver];
    [_allReceivers addObject:receiver];
}

// INVARIANT: Called under lock.
- (void)_removeReceivers:(NSSet<_NSNotificationReceiver*>*)receivers forName:(NSString*)name {
    if ([receivers count] == 0) {
        return;
    }

    // Update the global receiver table ...
    [_allReceivers minusSet:receivers];

    // ... and the name lookup tables.
    if (name) {
        // Fast path: remove these observers from the provided name's table.
        StrongId<NSMutableSet<_NSNotificationReceiver*>> nameReceivers = [self _receiverSetForNotificationName:name createIfMissing:NO];
        if (!nameReceivers) {
            return;
        }

        [nameReceivers minusSet:receivers];

        if ([nameReceivers count] == 0) {
            // This can release nameReceivers; it will be retained for the scope of this method.
            [_observers removeObjectForKey:name];
        }
    } else {
        // Slow path: remove these observers from every name table.
        NSArray<NSString*>* copiedAllKeys = [[_observers allKeys] copy];
        for (NSString* key in copiedAllKeys) {
            StrongId<NSMutableSet<_NSNotificationReceiver*>> nameReceivers = [_observers objectForKey:key];
            [nameReceivers minusSet:receivers];
            if ([nameReceivers count] == 0) {
                [_observers removeObjectForKey:key];
            }
        }
        [copiedAllKeys release];
    }
}

/**
 @Status Interoperable
*/
- (void)postNotificationName:(NSString*)name object:(NSObject*)sender {
    [self postNotificationName:name object:sender userInfo:nil];
}

/**
 @Status Interoperable
*/
- (void)postNotificationName:(NSString*)name object:(NSObject*)sender userInfo:(NSDictionary*)userInfo {
    // Since object could be mid-deallocation, this notification must not be leaked into an autorelease pool.
    StrongId<NSNotification> notification;
    notification.attach([[NSNotification alloc] initWithName:name object:sender userInfo:userInfo]);
    [self postNotification:notification];
}

/**
 @Status Interoperable
*/
- (void)postNotification:(NSNotification*)notification {
    if (!notification) {
        [NSException raise:NSInvalidArgumentException format:@"%hs: Notification cannot be nil", __PRETTY_FUNCTION__];
        return;
    }

    NSString* name = [notification name];

    // This method does not use _receiversForName:(...) above as it treats a nil _notification_ sender as a wildcard.
    // We want to treat a nil _receiver_ sender as a wildcard.
    // We'd like to avoid using autoreleased objects here: since a notification can be dispatched against a deallocating
    // object, tight control over its lifetime is required.
    std::vector<StrongId<_NSNotificationReceiver>> validReceivers{ 0 };
    @synchronized(self) {
        NSMutableSet<_NSNotificationReceiver*>* receivers = [self _receiverSetForNotificationName:name createIfMissing:NO];
        if (!receivers) {
            return;
        }

        @autoreleasepool { // If the NSNotification subclass's object getter autoreleases object, catch it in this pool.
            NSObject* sender = [notification object];
            validReceivers.reserve([receivers count]);
            for (_NSNotificationReceiver* receiver in receivers) {
                if (receiver->sender == nil || receiver->sender == sender) {
                    validReceivers.emplace_back(receiver);
                }
            }
        }
    }

    // Notification post happens outside of the lock over self; receivers are allowed to
    // manipulate the notification center's state.

    // Receivers are retained for the duration of this notification post.
    for (auto& receiver : validReceivers) {
        [receiver postNotification:notification];
    }
}

- (void)_addObserver:(id)observer selector:(SEL)selector name:(NSString*)name object:(id)object withOwningReference:(BOOL)owningReference {
    if (!name || !observer || !selector) {
        if (owningReference) {
            [observer release];
        }
        return;
    }

    _NSNotificationReceiver* newReceiver = [_NSNotificationReceiver new];

    newReceiver->observer = observer; // If owningReference, observer already bears a +1 internal retain count.
    newReceiver->ownsObserver = owningReference;
    newReceiver->selector = selector;
    newReceiver->sender = object;
    newReceiver->name = [name copy]; // Contractually released by _NSNotificationReceiver.

    @synchronized(self) {
        [self _addReceiver:newReceiver];
    }

    [newReceiver release];
}

/**
 @Status Interoperable
*/
- (void)addObserver:(id)observer selector:(SEL)selector name:(NSString*)name object:(id)object {
    [self _addObserver:observer selector:selector name:name object:object withOwningReference:NO];
}

/**
 @Status Interoperable
*/
- (id<NSObject>)addObserverForName:(NSString*)name
                            object:(id)object
                             queue:(NSOperationQueue*)queue
                        usingBlock:(void (^)(NSNotification*))block {
    if (!block) {
        [NSException raise:NSInvalidArgumentException format:@"%hs: Block cannot be nil", __PRETTY_FUNCTION__];
        return nil;
    }

    // The documentation states that this method returns an opaque object that acts as the observer, and
    // the returned observer should be able to be removed with `removeObserver:`.
    // To make that work, we must register this observer object just like a normal observer.
    _NSNotificationBlockObserver* blockObserver = [[[_NSNotificationBlockObserver alloc] initWithBlock:block queue:queue] autorelease];
    // blockObserver's new +1 reference is consumed by the notification receiver, indicated by withOwningReference:YES.
    [self _addObserver:[blockObserver retain] selector:@selector(invokeWithNotification:) name:name object:object withOwningReference:YES];
    return blockObserver;
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer name:(NSString*)name object:(id)object {
    @synchronized(self) {
        NSSet<_NSNotificationReceiver*>* receiversToRemove = [self _receiversForName:name observer:observer object:object];
        [self _removeReceivers:receiversToRemove forName:name];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer {
    @synchronized(self) {
        NSSet<_NSNotificationReceiver*>* receiversToRemove = [self _receiversForName:nil observer:observer object:nil];
        [self _removeReceivers:receiversToRemove forName:nil];
    }
}
@end
