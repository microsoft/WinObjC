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

#include "Starboard.h"
#import <Foundation/NSNotification.h>
#import <Foundation/NSNotificationCenter.h>
#include "LoggingNative.h"

static const wchar_t* TAG = L"NSNotificationCenter";

@interface NSNotificationReceiver : NSObject {
@public
    NSObject* object;
    void (^block)(NSNotification* block);
    SEL selector;
    NSObject* notificationSender;
    bool valid;
}
@end

@implementation NSNotificationReceiver
@end

NSNotificationCenter* defaultCenter;

@implementation NSNotificationCenter {
    NSMutableDictionary* observers;
}
static NSMutableArray* arrayForObservers(NSNotificationCenter* self, NSString* key, bool create = false) {
    NSMutableArray* ret = [self->observers objectForKey:key];
    if (ret) {
        return ret;
    }

    if (!create) {
        return nil;
    }

    ret = [NSMutableArray new];
    [self->observers setObject:ret forKey:key];
    [ret release];

    return ret;
}

/**
 @Status Interoperable
*/
+ (NSNotificationCenter*)defaultCenter {
    if (defaultCenter == nil) {
        defaultCenter = [NSNotificationCenter new];
    }

    return defaultCenter;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    observers = [[NSMutableDictionary alloc] init];
    return self;
}

/**
 @Status Interoperable
*/
- (void)postNotificationName:(NSString*)name object:(NSObject*)sender {
    NSNotification* notification = [NSNotification notificationWithName:name object:sender];
    [self postNotification:notification];
}

/**
 @Status Interoperable
*/
- (void)postNotification:(NSNotification*)notification {
    NSString* name = [notification name];

    NSArray* arr = arrayForObservers(self, name);
    if (arr == nil) {
        return;
    }

    NSObject* sender = [notification object];
    int count = CFArrayGetCount((CFArrayRef)arr);
    unsigned int numSendTo = 0;
    id* sendTo = (id*)IwMalloc(count * sizeof(id));
    for (unsigned int i = 0; i < count; i++) {
        NSNotificationReceiver* observer = (NSNotificationReceiver*)CFArrayGetValueAtIndex((CFArrayRef)arr, i);
        if (!observer->valid) {
            continue;
        }
        if (observer->notificationSender != NULL && observer->notificationSender != sender) {
            continue;
        }

        sendTo[numSendTo] = observer;
        [sendTo[numSendTo++] retain];
    }

    for (unsigned int i = 0; i < numSendTo; i++) {
        NSNotificationReceiver* observer = sendTo[i];

        if (!observer->valid) {
            [observer release];
            continue;
        }

        if (!observer->block) {
            [observer->object performSelector:observer->selector withObject:notification];
        } else {
            observer->block(notification);
        }
        [observer release];
    }
    IwFree(sendTo);
}

/**
 @Status Interoperable
*/
- (void)postNotificationName:(NSString*)name object:(NSObject*)sender userInfo:(NSDictionary*)userInfo {
    NSNotification* notification = [NSNotification notificationWithName:name object:sender userInfo:userInfo];

    [self postNotification:notification];
}

/**
 @Status Interoperable
*/
- (void)addObserver:(id)observer selector:(SEL)selName name:(NSString*)name object:(id)object {
    if (name == nil) {
        return;
    }

    NSNotificationReceiver* newObserver = [NSNotificationReceiver new];

    newObserver->object = observer;
    newObserver->selector = selName;
    newObserver->notificationSender = object;
    newObserver->valid = true;

    [arrayForObservers(self, name, true) addObject:newObserver];
    [newObserver release];
}

/**
 @Status Caveat
 @Notes queue parameter not supported
*/
- (id<NSObject>)addObserverForName:(NSString*)name
                            object:(id)object
                             queue:(NSNotificationQueue*)queue
                        usingBlock:(void (^)(NSNotification*))block {
    if (queue != nil) {
        TraceVerbose(TAG, L"addObserverForName: queue != nil!");
        assert(0);
        return nil;
    }

    NSNotificationReceiver* newObserver = [NSNotificationReceiver new];

    newObserver->object = [NSObject new]; //  Placeholder object for observer
    newObserver->block = [block copy];
    newObserver->selector = NULL;
    newObserver->notificationSender = object;
    newObserver->valid = true;

    [arrayForObservers(self, name, true) addObject:newObserver];
    [newObserver release];

    return newObserver->object;
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer name:(NSString*)name object:(id)object {
    id arr = arrayForObservers(self, name);
    if (arr == nil) {
        return;
    }

    int numItems = CFArrayGetCount((CFArrayRef)arr);

    for (int i = numItems - 1; i >= 0; i--) {
        NSNotificationReceiver* curObserver = (NSNotificationReceiver*)CFArrayGetValueAtIndex((CFArrayRef)arr, i);

        if (!curObserver->valid) {
            continue;
        }
        if (curObserver->object != observer) {
            continue;
        }
        if (object != nil && curObserver->notificationSender != object) {
            continue;
        }

        curObserver->valid = false;
        if (curObserver->block) {
            [curObserver->block release];
            [curObserver->object release];
            curObserver->block = nil;
            curObserver->object = nil;
        }

        // Remove the object *after* freeing its block and object
        CFArrayRemoveValueAtIndex((CFMutableArrayRef)arr, i);
    }

    if (CFArrayGetCount((CFArrayRef)arr) == 0) {
        [observers setObject:nil forKey:name];
    }
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer {
    NSArray* copiedAllKeys = [[observers allKeys] copy];
    for (NSString* curName in copiedAllKeys) {
        [self removeObserver:observer name:curName object:nil];
    }
    [copiedAllKeys release];
}
@end
