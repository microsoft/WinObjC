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
// Apple once documented the KVO Change Kind key as the string "kind", and as such, the string literal became
// part of the public API. We have to mimic that in case an application was written under the assumption that
// they could use @"kind" to divine the change type.
NSString* const NSKeyValueChangeKindKey = @"kind";
NSString* const NSKeyValueChangeNewKey = @"NSKeyValueChangeNewKey";
NSString* const NSKeyValueChangeOldKey = @"NSKeyValueChangeOldKey";
NSString* const NSKeyValueChangeIndexesKey = @"NSKeyValueChangeIndexesKey";
NSString* const NSKeyValueChangeNotificationIsPriorKey = @"NSKeyValueChangeNotificationIsPriorKey";

/*
*  KVO Notifiers 101
*
*  Imagine we are observing a.b.c.d on a given object.
*  Key d is declared as depending on the values of da and db.
*
*  The notification system creates 7 notifiers.
*
*                              +-----+
*                              |     |
*                              |  5  +--------+
*                              |   da|        |
*                              +--^--+        |
*                                 :           |
*                                 :           v
*  +---+    +---+    +---+    +---+---+   +#######+
*  |   |    |   |    |   |    |       |   #   7   #
*  | 1 +--->| 2 +--->| 3 +--->|   4   +--># final #
*  |  a|    |  b|    |  c|    |      d|   #       #
*  +---+    +---+    +---+    +---+---+   +#######+
*                                 :           ^
*                                 :           |
*                              +--v--+        |
*                              |     |        |
*                              |  6  +--------+
*                              |   db|
*                              +-----+
*
*  Notifiers 1 - 4 cascade the notification forward along the solid lines -- that is to say,
*  if notifier 1 fires, it triggers notifier 2 (the 'b' key on the value of 'a'),
*  if notifier 2 fires, it triggers notifier 3 (the 'c' key on the value of 'b'),
*  and so on.
*
*  At the end of the chain is the final notifier (7): it stores the information required to
*  dispatch a notification: the destination, context, keypath, pending data, etc.
*
*  'd' also has two "dependent" keys. If 5 (da) or 6 (db) change, they trigger the final notifier,
*  dispatching a change notification on keypath a.b.c.d.
*
*  They are not notified by the change to 'd': the dotted lines show dependencies only.
*
*  After every successful change notification, a notifier will reconstruct the hierarchy of nodes
*  that follow it. The notifier on 'b' (2) is dependent on the value of 'a'; therefore, if 'a' changes,
*  'b' and all subpaths need to be re-evaluated.
*
*  If 'a' were nil, we would end up with the following diagram:
*
*           +#######+
*           #   2   #
*        +-># final #
*  +---+ |  #       #
*  |   | |  +#######+
*  | 1 +-+
*  |  a| |  +:::::::+
*  +---+ |  :       :
*        +->: b.c.d :
*           :       :
*           +:::::::+
*
*  This expresses that we could not complete the keypath from a to d. Therefore, a change on 'a'
*  will trigger two things. First, a final notification for the observer. Second, a re-registration
*  of keypath b.c.d on the new value of 'a'.
*
*  Time willing, and with the presence of all objects in the chain, this diagram will eventually look
*  like the one above.
*
*  Link updating is a bit of a hairy process. Each chained notifier stores what's necessary to reconstruct
*  itself and the chain that follows it, given a new value. Therefore, when 'a' changes, it updates its chain
*  by requesting that 'b' renew itself with a.valueOf('b'). The new notifier is therefore attached to the new value,
*  and 'a' dispatches to that new notifier in the future.
*/

namespace {

class NSKVOClassBroker {
protected:
    std::recursive_mutex _classMutex;

    // Links a kvo-notifying to its NSKVOClass struct.
    std::unordered_map<Class, std::shared_ptr<NSKVOClass>> _kvoClasses;

    // This is a map from a class to its kvo-notifying counterpart.
    std::unordered_map<Class, Class> _kvoNotifyingSubclasses;

public:
    static NSKVOClassBroker& globalBroker() {
        // construct on first use
        static NSKVOClassBroker broker;
        return broker;
    }

    Class notifyingClassForClass(Class cls) {
        std::lock_guard<std::recursive_mutex> lock(_classMutex);

        if (isKVOCapable(cls)) {
            return cls;
        }

        auto it = _kvoNotifyingSubclasses.find(cls);
        if (it != _kvoNotifyingSubclasses.end()) {
            return it->second;
        }

        return NSKVOSwizzledNotifyingClassForClass(cls);
    }

    void registerClassPair(Class notifyingClass, Class originalClass, std::shared_ptr<NSKVOClass>&& attachedInfo) {
        std::lock_guard<std::recursive_mutex> lock(_classMutex);
        _kvoNotifyingSubclasses.emplace(originalClass, notifyingClass);
        if (!attachedInfo) {
            _kvoClasses.emplace(notifyingClass, std::make_shared<NSKVOClass>(originalClass, notifyingClass));
        } else {
            _kvoClasses.emplace(notifyingClass, std::move(attachedInfo));
        }
    }

    bool isKVOCapable(Class cls) {
        std::lock_guard<std::recursive_mutex> lock(_classMutex);
        return _kvoClasses.find(cls) != _kvoClasses.end();
    }

    NSKVOClass& forClass(Class cls) {
        std::lock_guard<std::recursive_mutex> lock(_classMutex);
        return *(_kvoClasses[cls]);
    }
};

constexpr static NSKVOMatchAnyContextTag NSKVOMatchAnyContext{};

class NSKVOConcreteNotifier : public NSKVONotifier {
private:
    std::function<void(const NSKVONotifier*)> _deregistrationHook;
    std::vector<std::shared_ptr<NSKVONotifier>> _dependentNotifiers;

public:
    void setDeregistrationHook(std::function<void(const NSKVONotifier*)>&& hook) {
        _deregistrationHook = std::move(hook);
    }
    void addDependentNotifier(const std::shared_ptr<NSKVONotifier>& dependentNotifier) override {
        _dependentNotifiers.emplace_back(dependentNotifier);
    }
    void breakLink() override {
        auto dependentNotifiersCopy = _dependentNotifiers;
        for (const auto& dependentNotifier : dependentNotifiersCopy) {
            dependentNotifier->breakLink();
        }
        if (_deregistrationHook) {
            _deregistrationHook(this);
        }
    }
};

class NSKVOForwardingNotifier : public NSKVOConcreteNotifier {
private:
    std::shared_ptr<NSKVONotifier> _chainedNotifier;
    std::function<std::shared_ptr<NSKVONotifier>(id)> _replacementLink;

public:
    NSKVOForwardingNotifier(const std::shared_ptr<NSKVONotifier>& chainedNotifier,
                            const std::function<std::shared_ptr<NSKVONotifier>(id)>& replacementLink)
        : _chainedNotifier(chainedNotifier), _replacementLink(replacementLink) {
    }
    void dispatch(bool prior) override {
        _chainedNotifier->dispatch(prior);
    }
    bool matches(id observer, const std::string& keypath, NSKVOMatchAnyContextTag) override {
        return _chainedNotifier->matches(observer, keypath, NSKVOMatchAnyContext);
    }
    bool matches(id observer, const std::string& keypath, void* context) override {
        return _chainedNotifier->matches(observer, keypath, context);
    }
    void updateLinks(id newValue) override {
        auto nextChainInChain = std::dynamic_pointer_cast<NSKVOForwardingNotifier>(_chainedNotifier);
        if (nextChainInChain && nextChainInChain->_replacementLink) {
            nextChainInChain->breakLink();
            _chainedNotifier = nextChainInChain->_replacementLink(newValue);
        }
    }
    void breakLink() override {
        _chainedNotifier->breakLink();
        NSKVOConcreteNotifier::breakLink();
    }
};

struct NSKVOFinalNotifier : public NSKVOConcreteNotifier {
    NSKVOClass& kvoClass;
    id observer; // We do not retain our own observer, as that would create a retain cycle.
    id instance;
    NSKeyValueObservingOptions options;
    void* context;
    std::string keypath;
    idretaint<NSMutableDictionary> notificationDictionary;

    NSKVOFinalNotifier(
        NSKVOClass& kvoClass, id observer, id instance, NSKeyValueObservingOptions options, void* context, const std::string& keypath)
        : kvoClass(kvoClass), observer(observer), instance(instance), options(options), context(context), keypath(keypath) {
        if (_hasOption(NSKeyValueObservingOptionInitial)) {
            auto oldOptions = options;
            options &= ~(NSKeyValueObservingOptionPrior | NSKeyValueObservingOptionOld);
            this->dispatch(false);
            options = oldOptions;
        }
    }
    bool _hasOption(NSKeyValueObservingOptions opt) const {
        return (options & opt) > 0;
    }

    bool matches(id observer, const std::string& keypath, NSKVOMatchAnyContextTag) override {
        return this->observer == observer && this->keypath == keypath;
    }

    bool matches(id observer, const std::string& keypath, void* context) override {
        return this->observer == observer && this->keypath == keypath && this->context == context;
    }

    // As this is a terminal node, there are no further chained notifiers to renew.
    void updateLinks(id newValue) override {
    }

    void dispatch(bool prior) override {
        if (!notificationDictionary) {
            notificationDictionary = [NSMutableDictionary dictionary];
            [notificationDictionary setObject:@(NSKeyValueChangeSetting) forKey:NSKeyValueChangeKindKey];
        }

        if (prior && _hasOption(NSKeyValueObservingOptionOld)) {
            [notificationDictionary setObject:kvoClass.valueForKey(instance, keypath) ?: [NSNull null] forKey:NSKeyValueChangeOldKey];
        }

        if (!prior && _hasOption(NSKeyValueObservingOptionNew)) {
            [notificationDictionary setObject:kvoClass.valueForKey(instance, keypath) ?: [NSNull null] forKey:NSKeyValueChangeNewKey];
        }

        // Notify if we are a prior notification and options requested that, or if we aren't prior.
        bool shouldNotify = (prior && _hasOption(NSKeyValueObservingOptionPrior)) || !prior;

        if (!shouldNotify) {
            return;
        }

        if (prior) {
            NSMutableDictionary* outgoing = [notificationDictionary mutableCopy];
            [outgoing setObject:@(YES) forKey:NSKeyValueChangeNotificationIsPriorKey];
            [observer observeValueForKeyPath:[NSString stringWithUTF8String:keypath.c_str()] ofObject:instance change:outgoing context:context];
        } else {
            [observer observeValueForKeyPath:[NSString stringWithUTF8String:keypath.c_str()]
                                    ofObject:instance
                                      change:notificationDictionary
                                     context:context];
            notificationDictionary = nil;
        }
    }
};
}

const std::unordered_set<std::string>& NSKVOClass::valueDependingKeys(const std::string& key) {
    const auto found = _valueDependingKeys.find(key);
    if (found == _valueDependingKeys.end()) {
        auto& added = _valueDependingKeys[key];
        if ([originalClass respondsToSelector:@selector(keyPathsForValuesAffectingValueForKey:)]) {
            NSSet* dependingKeysFromClass =
                [originalClass keyPathsForValuesAffectingValueForKey:[NSString stringWithUTF8String:key.c_str()]];
            for (NSString* dependingKey in dependingKeysFromClass) {
                added.emplace([dependingKey UTF8String]);
            }
        }
        return added;
    }
    return found->second;
}

void NSKVOClass::dealloc(id instance) {
    // WE CANNOT USE instance AS AN OBJECT IN HERE.
    // It has been deallocated, and we are updating our bookkeeping.
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    for (auto i = _notifiersByInstance.begin(); i != _notifiersByInstance.end();) {
        if (std::get<0>(i->first) == instance) {
            i = _notifiersByInstance.erase(i);
        } else {
            ++i;
        }
    }

    for (auto i = _keypathNotifiersByInstance.begin(); i != _keypathNotifiersByInstance.end(); ++i) {
        if (std::get<0>(i->first) == instance && i->second.size() > 0) {
            [NSException raise:NSInvalidArgumentException
                        format:@"Instance of %s deallocated with observers still registered.", class_getName(originalClass)];
        }
    }
}

/* static */
void NSKVOClass::ensureObjectWillNotify(id object) {
    auto notifyingClass = NSKVOClassBroker::globalBroker().notifyingClassForClass(object_getClass(object));
    object_setClass(object, notifyingClass);
}

/* static */
bool NSKVOClass::isKVOCapable(Class cls) {
    return NSKVOClassBroker::globalBroker().isKVOCapable(cls);
}
/* static */
bool NSKVOClass::isKVOCapable(id objcInstance) {
    return isKVOCapable(object_getClass(objcInstance));
}

/* static */
NSKVOClass& NSKVOClass::forClass(Class cls) {
    return NSKVOClassBroker::globalBroker().forClass(cls);
}

/* static */
NSKVOClass& NSKVOClass::forInstance(id objcInstance) {
    ensureObjectWillNotify(objcInstance);
    return forClass((id)object_getClass(objcInstance));
}

/* static */
void NSKVOClass::registerClassPair(Class notifyingClass, Class originalClass, std::shared_ptr<NSKVOClass>&& attachedInfo) {
    NSKVOClassBroker::globalBroker().registerClassPair(notifyingClass, originalClass, std::move(attachedInfo));
}

void NSKVOClass::_removeNotifier(id instance, const std::string& key, const NSKVONotifier* notifier) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);

    auto& notifierSet = _notifiersByInstance[std::make_tuple(instance, key)];
    auto found = std::find_if(notifierSet.begin(),
                              notifierSet.end(),
                              [notifier](const std::weak_ptr<NSKVONotifier>& searchingNotifier) -> bool {
                                  auto lockedSearchingNotifier(searchingNotifier.lock());
                                  return lockedSearchingNotifier && notifier == lockedSearchingNotifier.get();
                              });
    if (found != notifierSet.end()) {
        notifierSet.erase(found);
    }
}

/* static */
std::shared_ptr<NSKVONotifier> NSKVOClass::_notifierForSubkeyOnInstance(id newValue,
                                                                        const std::string& keypath,
                                                                        const std::shared_ptr<NSKVONotifier>& leafNotifier) {
    if (keypath.size() == 0) {
        return leafNotifier;
    }

    if (!newValue) {
        return std::make_shared<NSKVOForwardingNotifier>(leafNotifier,
                                                         std::bind(&NSKVOClass::_notifierForSubkeyOnInstance,
                                                                   std::placeholders::_1,
                                                                   keypath,
                                                                   leafNotifier));
    } else {
        return NSKVOClass::forInstance(newValue)._linkedNotifierForLeaf(newValue, keypath, leafNotifier);
    }
}

std::shared_ptr<NSKVONotifier> NSKVOClass::_linkedNotifierForLeaf(id instance,
                                                                  const std::string& keypath,
                                                                  const std::shared_ptr<NSKVONotifier>& leafNotifier) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);

    std::string remainingKeypath(keypath);
    auto pointPosition = remainingKeypath.find('.');
    std::string keyComponent(remainingKeypath, 0, pointPosition);

    _currentlyManipulatingKeys.emplace(keyComponent);

    ensureKeyWillNotify(keyComponent);

    std::shared_ptr<NSKVONotifier> chainedNotifier;
    if (pointPosition == std::string::npos) {
        // The notifier for a leaf entry:
        //     1) chains the leaf notifier.
        chainedNotifier = leafNotifier;
    } else {
        // The notifier for an intermediate entry:
        //     1) Dispatches a notification towards the final notifier (as the value has changed)
        //     2) Recreates the remainder of the notifier chain from this point with real values.
        //     3) Removes its own entry.

        id descentInstance = valueForKey(instance, keyComponent);
        remainingKeypath.erase(0, pointPosition + 1);

        chainedNotifier = _notifierForSubkeyOnInstance(descentInstance, remainingKeypath, leafNotifier);
    }

    auto notifier(std::make_shared<NSKVOForwardingNotifier>(
        chainedNotifier, std::bind(&NSKVOClass::_notifierForSubkeyOnInstance, std::placeholders::_1, remainingKeypath, leafNotifier)));

    const auto& dependingKeys = valueDependingKeys(keyComponent);
    for (const auto& dependingKey : dependingKeys) {
        if (_currentlyManipulatingKeys.count(dependingKey) == 0) {
            notifier->addDependentNotifier(_linkedNotifierForLeaf(instance, dependingKey, leafNotifier));
        }
    }

    notifier->setDeregistrationHook(std::bind(&NSKVOClass::_removeNotifier, this, instance, keyComponent, std::placeholders::_1));

    _notifiersByInstance[std::make_tuple(instance, keyComponent)].emplace_back(notifier);

    _currentlyManipulatingKeys.erase(keyComponent);

    return notifier;
}

void NSKVOClass::addObserver(
    id observedInstance, id observer, const std::string& keypath, NSKeyValueObservingOptions options, void* context) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    std::shared_ptr<NSKVONotifier> finalNotifier(new NSKVOFinalNotifier{ *this, observer, observedInstance, options, context, keypath });

    auto rootNotifier = _linkedNotifierForLeaf(observedInstance, keypath, finalNotifier);
    _keypathNotifiersByInstance[std::make_tuple(observedInstance, keypath)].emplace(std::move(rootNotifier));
}

template <typename TContext>
void NSKVOClass::removeObserver(id instance, id observer, const std::string& keypath, TContext context) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);

    auto& keypathNotifiers(_keypathNotifiersByInstance[std::make_tuple(instance, keypath)]);
    auto copiedNotifiers(keypathNotifiers);
    for (const auto& notifier : copiedNotifiers) {
        if (notifier->matches(observer, keypath, context)) {
            notifier->breakLink();
            keypathNotifiers.erase(notifier);

            // We're only supposed to remove a single observer.
            return;
        }
    }

    [NSException raise:NSInvalidArgumentException
                format:@"Cannot remove observer %@ for keypath \"%s\" from %@ as it is not a registered observer.",
                       observer,
                       keypath.c_str(),
                       instance];
}

void NSKVOClass::dispatch(id instance, const std::string& key, bool prior) {
    std::lock_guard<std::recursive_mutex> lock(_mutex);

    if (_currentlyManipulatingKeys.count(key) > 0) {
        // Don't dispatch a notification for a key we are already notifying on.
        return;
    }
    _currentlyManipulatingKeys.emplace(key);

    auto copiedNotifiers(_notifiersByInstance[std::make_tuple(instance, key)]);
    for (const auto& notifier : copiedNotifiers) {
        auto lockedNotifier(notifier.lock());
        if (lockedNotifier) {
            lockedNotifier->dispatch(prior);
            if (!prior) {
                // TODO(DH): Look at caching these values, and only update if necessary.
                lockedNotifier->updateLinks(valueForKey(instance, key));
            }
        }
    }

    _currentlyManipulatingKeys.erase(key);
}

@implementation NSObject (NSKeyValueObservation)

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    if ([key length] > 0) {
        const char* rawKey = [key UTF8String];
        auto selectorName = woc::string::format("automaticallyNotifiesObserversOf%c%s", toupper(rawKey[0]), rawKey + 1);
        SEL sel = sel_registerName(selectorName.c_str());
        BOOL (*imp)(Class, SEL) = reinterpret_cast<decltype(imp)>(class_getMethodImplementation(object_getClass(self), sel));
        if (imp != nullptr) {
            return imp(self, sel);
        }
    }
    return YES;
}

/**
 @Status Interoperable
*/
+ (NSSet*)keyPathsForValuesAffectingValueForKey:(NSString*)key {
    if ([key length] > 0) {
        const char* rawKey = [key UTF8String];
        auto selectorName = woc::string::format("keyPathsForValuesAffecting%c%s", toupper(rawKey[0]), rawKey + 1);
        SEL sel = sel_registerName(selectorName.c_str());
        if ([self respondsToSelector:sel]) {
            return [self performSelector:sel];
        }
    }
    return [NSSet set];
}

/**
 @Status Interoperable
*/
- (void)addObserver:(id)observer forKeyPath:(NSString*)keyPath options:(NSInteger)options context:(void*)context {
    auto& kvoClass = NSKVOClass::forInstance(self);
    kvoClass.addObserver(self, observer, [keyPath UTF8String], options, context);
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer forKeyPath:(NSString*)keyPath context:(void*)context {
    auto& kvoClass = NSKVOClass::forInstance(self);
    kvoClass.removeObserver(self, observer, [keyPath UTF8String], context);
}

/**
 @Status Interoperable
*/
- (void)removeObserver:(id)observer forKeyPath:(NSString*)keyPath {
    auto& kvoClass = NSKVOClass::forInstance(self);
    kvoClass.removeObserver(self, observer, [keyPath UTF8String], NSKVOMatchAnyContext);
}

/**
 @Status Interoperable
*/
- (void)willChangeValueForKey:(NSString*)key {
    if (!NSKVOClass::isKVOCapable((id)self)) {
        return;
    }
    auto& kvoClass(NSKVOClass::forInstance(self));
    kvoClass.dispatch(self, [key UTF8String], true);
}

/**
 @Status Interoperable
*/
- (void)didChangeValueForKey:(NSString*)key {
    if (!NSKVOClass::isKVOCapable((id)self)) {
        return;
    }
    auto& kvoClass(NSKVOClass::forInstance(self));
    kvoClass.dispatch(self, [key UTF8String], false);
}
@end
