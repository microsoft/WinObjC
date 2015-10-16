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

#import "NSKeyValueObserving-Internal.h"

/* Exported */
FOUNDATION_EXPORT NSString* const NSKeyValueChangeKindKey = @"NSKeyValueChangeKindKey";
FOUNDATION_EXPORT NSString* const NSKeyValueChangeNewKey = @"NSKeyValueChangeNewKey";
FOUNDATION_EXPORT NSString* const NSKeyValueChangeOldKey = @"NSKeyValueChangeOldKey";
FOUNDATION_EXPORT NSString* const NSKeyValueChangeIndexesKey = @"NSKeyValueChangeIndexesKey";
FOUNDATION_EXPORT NSString* const NSKeyValueChangeNotificationIsPriorKey = @"NSKeyValueChangeNotificationIsPriorKey";

std::unordered_map<Class, std::shared_ptr<KVOClass>> KVOClass::s_kvoClasses;
std::unordered_map<Class, Class> KVOClass::s_kvoNotifyingSubclasses;
std::unordered_map<id, std::shared_ptr<KVONotifier>> KVONotifier::s_kvoInstances;
std::recursive_mutex KVOClass::s_classMutex;
std::recursive_mutex KVONotifier::s_instanceMutex;

const std::unordered_set<std::string>& KVOClass::valueDependingKeys(const std::string& key) {
    const auto found = _valueDependingKeys.find(key);
    if (found == _valueDependingKeys.end()) {
        auto& added = _valueDependingKeys[key];
        if ([originalClass respondsToSelector:@selector(keyPathsForValuesAffectingValueForKey:)]) {
            NSSet* dependingKeysFromClass = [originalClass keyPathsForValuesAffectingValueForKey:[NSString stringWithUTF8String:key.c_str()]];
            for (NSString* dependingKey in dependingKeysFromClass) {
                added.emplace([dependingKey UTF8String]);
            }
        }
        return added;
    }
    return found->second;
}

void KVOClass::dealloc(id instance) {
    KVONotifier::removeInstance(instance);
}

/* static */
Class KVOClass::notifyingClassForClass(Class cls) {
    std::lock_guard<std::recursive_mutex> lock(s_classMutex);

    if (isKVOCapable(cls)) {
        return cls;
    }

    auto it = s_kvoNotifyingSubclasses.find(cls);
    if (it != s_kvoNotifyingSubclasses.end()) {
        return it->second;
    }

    return KVOSwizzledClass::notifyingClassForClass(cls);
}

/* static */
void KVOClass::ensureObjectWillNotify(id object) {
    std::lock_guard<std::recursive_mutex> lock(s_classMutex);

    auto notifyingClass = KVOClass::notifyingClassForClass(object_getClass(object));
    object_setClass(object, notifyingClass);
}

/* static */
KVONotifier& KVONotifier::forInstance(id instance) {
    std::lock_guard<std::recursive_mutex> lock(s_instanceMutex);
    auto found = s_kvoInstances.find(instance);
    if (found == s_kvoInstances.end()) {
        KVOClass::ensureObjectWillNotify(instance);
        auto newInstance = std::make_shared<KVONotifier>(KVOClass::forInstance(instance), instance);
        s_kvoInstances.emplace(instance, newInstance);
        return *newInstance;
    }
    return *found->second;
}

std::shared_ptr<KVOObservedKey> KVONotifier::_addSubscriber(std::shared_ptr<KVOSubscriber> subscriber,
                                                            const std::string& keypath) {
    auto pointPosition = keypath.find('.');
    std::string key(keypath, 0, pointPosition); // if pointPosition is npos, this is just the whole string.
    std::string remainingKeypath(keypath);
    if (pointPosition != std::string::npos) {
        remainingKeypath.erase(0, pointPosition + 1);
    }

    notifyingClass.ensureKeyWillNotify(key);
    auto& newKey = _observedKeys[key];
    if (!newKey) {
        newKey.reset(new KVOObservedKey(shared_from_this(), key));
    }
    newKey->addSubscriber(subscriber);

    if (pointPosition != std::string::npos) {
        std::shared_ptr<KVOObservedKey> dependentKey;
        id value = _valueForKey(key);
        if (value != nil) {
            auto& notifierForValue = KVONotifier::forInstance(value);
            dependentKey = notifierForValue._addSubscriber(subscriber, remainingKeypath);
        } else {
            // If the value didn't exist, we need to register the full keypath for null resolution.
            // Once an instance exists at that keypath, we'll complete observer registration.
            dependentKey = std::make_shared<KVOObservedKey>(shared_from_this(), keypath);
        }

        newKey->addDependentKey(dependentKey);
    }

    for (auto& dependedKey : notifyingClass.valueDependingKeys(key)) {
        auto newDependingKey = _addSubscriber(subscriber, dependedKey);
        newDependingKey->addDependentKey(newKey);
    }

    return newKey;
}

void KVONotifier::_removeSubscriber(std::shared_ptr<KVOSubscriber> subscriber, const std::string& keypath) {
    auto pointPosition = keypath.find('.');
    std::string key(keypath, 0, pointPosition); // if pointPosition is npos, this is just the whole string.
    std::string remainingKeypath(keypath);
    if (pointPosition != std::string::npos) {
        remainingKeypath.erase(0, pointPosition + 1);
    }

    auto foundKey = _observedKeys.find(key);
    if (foundKey == _observedKeys.end()) {
        return;
    }

    for (auto dependentKey : foundKey->second->_dependentKeys) {
        auto observedSubInstance = dependentKey->weakInstance.lock();
        if (observedSubInstance) {
            observedSubInstance->_removeSubscriber(subscriber, remainingKeypath);
        }
    }
    foundKey->second->removeSubscriber(subscriber);
    foundKey->second->pruneDeadKeys();

    if (!foundKey->second->hasDependents()) {
        _observedKeys.erase(foundKey);
    }

    _subscribers.erase(subscriber);
}

void KVONotifier::_reregisterSubkeys(KVOObservedKey& notifyingKey) {
    if (notifyingKey._dependentKeys.size() > 0) { // && _kvCache[notifyingKey.key] != getValueForKey(notifyingKey.key)) {
        notifyingKey._dependentKeys.clear();
        // TODO(DH) This is inefficient: we are re-registering the entire keypath from its root every time.
        // If we don't even have a dotted keypath, there isn't much of a reason to re-register.
        for (auto& subscriber : notifyingKey._subscribers) {
            auto notifier = subscriber->weakNotifier.lock();
            notifier->_addSubscriber(subscriber, subscriber->keypath);
        }
    }
}

void KVONotifier::_dispatch(KVOObservedKey& notifyingKey, KVOPendingNotification& pendingNotification, bool prior) {
    NSMutableDictionary* notificationDictionary = pendingNotification.notificationDictionary;
    if (!notificationDictionary) {
        notificationDictionary = [NSMutableDictionary dictionary];
        pendingNotification.notificationDictionary = notificationDictionary;

        notificationDictionary[NSKeyValueChangeKindKey] = @(NSKeyValueChangeSetting);
    }

    for (auto& subscriber : notifyingKey._subscribers) {
        // Notify if we are a prior notification and options requested that, or if we aren't prior.
        bool shouldNotify = (prior && subscriber->hasOption(NSKeyValueObservingOptionPrior)) || !prior;
        NSMutableDictionary* outgoing = shouldNotify ? [notificationDictionary mutableCopy] : nil;
        auto notifier = subscriber->weakNotifier.lock();

        if (!pendingNotification.initial && subscriber->hasOption(NSKeyValueObservingOptionOld)) {
            auto& old = pendingNotification.priorValue;
            if (!old) {
                old.attach(notifier->_valueForKey(subscriber->keypath) ?: [NSNull null]);
            }

            [outgoing setObject:old forKey:NSKeyValueChangeOldKey];
        }

        if (!prior && subscriber->hasOption(NSKeyValueObservingOptionNew)) {
            auto& newVal = pendingNotification.newValue;
            if (!newVal) {
                newVal.attach(notifier->_valueForKey(subscriber->keypath) ?: [NSNull null]);
            }

            [outgoing setObject:newVal forKey:NSKeyValueChangeNewKey];
        }

        if (prior) {
            [outgoing setObject:@(YES) forKey:NSKeyValueChangeNotificationIsPriorKey];
        }

        if (outgoing) {
            [subscriber->observer observeValueForKeyPath:[NSString stringWithUTF8String:subscriber->keypath.c_str()]
                                                ofObject:notifier->instance
                                                  change:outgoing
                                                 context:subscriber->context];
        }
    }
}

@implementation NSObject (NSKeyValueObservation)
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    if ([key length] > 0) {
        const char* rawKey = [key UTF8String];
        auto selectorName = woc::string::format("automaticallyNotifiesObserversOf%c%s",
                    toupper(rawKey[0]),
                    rawKey + 1);
        SEL sel = sel_registerName(selectorName.c_str());
        BOOL (*imp)(Class, SEL) = reinterpret_cast<decltype(imp)>(class_getMethodImplementation(object_getClass(self), sel));
        if (imp != nullptr) {
            return imp(self, sel);
        }
    }
    return YES;
}

+ (NSSet*)keyPathsForValuesAffectingValueForKey:(NSString*)key {
    if ([key length] > 0) {
        const char* rawKey = [key UTF8String];
        auto selectorName = woc::string::format("keyPathsForValuesAffecting%c%s",
                    toupper(rawKey[0]),
                    rawKey + 1);
        SEL sel = sel_registerName(selectorName.c_str());
        if ([self respondsToSelector:sel]) {
            return [self performSelector:sel];
        }
    }
    return [NSSet set];
}

- (void)addObserver:(id)observer forKeyPath:(NSString*)keyPath options:(NSInteger)options context:(void*)context {
    auto& notifier = KVONotifier::forInstance(self);
    notifier.addObserver(observer, [keyPath UTF8String], options, context);
}

- (void)removeObserver:(id)observer forKeyPath:(NSString*)keyPath context:(void*)context {
    auto& notifier = KVONotifier::forInstance(self);
    notifier.removeObserver(observer, [keyPath UTF8String], context);
}

- (void)removeObserver:(id)observer forKeyPath:(NSString*)keyPath {
    // TODO(DH) is it correct to use NULL to mean "remove all observers" here?
    [self removeObserver:observer forKeyPath:keyPath context:NULL];
}

- (void)willChangeValueForKey:(NSString*)key {
    if (!KVOClass::isKVOCapable((id)self)) {
        return;
    }
    auto& notifier(KVONotifier::forInstance(self));
    notifier.willChange([key UTF8String]);
}

- (void)didChangeValueForKey:(NSString*)key {
    if (!KVOClass::isKVOCapable((id)self)) {
        return;
    }
    auto& notifier(KVONotifier::forInstance(self));
    notifier.didChange([key UTF8String]);
}
@end

@interface _NSKVONotifying_NSMutableDictionary: NSMutableDictionary
@end
@implementation _NSKVONotifying_NSMutableDictionary
- (void)setObject:(id)object forKey:(NSString*)key {
    [self willChangeValueForKey:key];
    [super setObject:object forKey:key];
    [self didChangeValueForKey:key];
}

- (void)removeObjectForKey:(NSString*)key {
    [self willChangeValueForKey:key];
    [super removeObjectForKey:key];
    [self didChangeValueForKey:key];
}

// Sentinel to notify the KVO machinery that we do in fact support notifications.
+ (void)_NSKVO { }

+ (Class)class {
    return class_getSuperclass(self);
}

+ (void)load {
    KVOClass::registerClassPair(self, [NSMutableDictionary class]);
}
@end
