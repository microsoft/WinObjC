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
#include "Foundation/NSNotificationCenter.h"

@implementation NSNotification {
    NSString* notificationName;
    id notificationObj;
    id userInfo;
}
+ (NSNotification*)notificationWithName:(NSString*)name object:(id)obj {
    NSNotification* ret = [self alloc];

    ret->notificationName = [name retain];
    ret->notificationObj = [obj retain];
    ret->userInfo = nil;

    return [ret autorelease];
}

+ (NSNotification*)notificationWithName:(NSString*)name object:(id)obj userInfo:(NSDictionary*)info {
    NSNotification* ret = [self alloc];

    ret->notificationName = [name retain];
    ret->notificationObj = [obj retain];
    ret->userInfo = [info retain];

    return [ret autorelease];
}

- (id)object {
    return notificationObj;
}

- (NSString*)name {
    return notificationName;
}

- (NSDictionary*)userInfo {
    return userInfo;
}

- (void)dealloc {
    [notificationName release];
    [notificationObj release];
    [userInfo release];

    [super dealloc];
}
@end

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

+ (NSNotificationCenter*)defaultCenter {
    if (defaultCenter == nil) {
        defaultCenter = [NSNotificationCenter new];
    }

    return defaultCenter;
}

- (instancetype)init {
    observers = [[NSMutableDictionary alloc] init];
    return self;
}

- (void)postNotificationName:(NSString*)name object:(NSObject*)sender {
    NSNotification* notification = [NSNotification notificationWithName:name object:sender];
    [self postNotification:notification];
}

- (void)postNotification:(NSNotification*)notification {
    NSString* name = [notification name];

    NSArray* arr = arrayForObservers(self, name);
    if (arr == nil) {
        return;
    }

    NSObject* sender = [notification object];
    int count = CFArrayGetCount((CFArrayRef)arr);
    unsigned int numSendTo = 0;
    id* sendTo = (id*)malloc(count * sizeof(id));
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

        if (observer->block == nil) {
            [observer->object performSelector:observer->selector withObject:notification];
        } else {
            observer->block(notification);
        }
        [observer release];
    }
    free(sendTo);
}

- (void)postNotificationName:(NSString*)name object:(NSObject*)sender userInfo:(NSDictionary*)userInfo {
    NSNotification* notification = [NSNotification notificationWithName:name object:sender userInfo:userInfo];

    [self postNotification:notification];
}

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

- (id<NSObject>)addObserverForName:(NSString*)name
                            object:(id)object
                             queue:(NSNotificationQueue*)queue
                        usingBlock:(void (^)(NSNotification*))block {
    if (queue != nil) {
        EbrDebugLog("addObserverForName: queue != nil!\n");
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
        CFArrayRemoveValueAtIndex((CFArrayRef)arr, i);
        if (curObserver->block != nil) {
            [curObserver->block release];
            [curObserver->object release];
            curObserver->block = nil;
            curObserver->object = nil;
        }
    }

    if (CFArrayGetCount((CFArrayRef)arr) == 0) {
        [observers setObject:nil forKey:name];
    }
}

- (void)removeObserver:(id)observer {
    for (NSString* curName in [observers allKeys]) {
        [self removeObserver:observer name:curName object:nil];
    }
}
@end