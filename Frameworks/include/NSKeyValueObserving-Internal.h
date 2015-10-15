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

#import <Foundation/Foundation.h>
#include <Starboard.h>
#include <Starboard/String.h>
#include "../objcrt/runtime.h"

#include <new>
#include <tuple>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <memory>

struct KVONotifier;

struct KVOClass {
    Class originalClass;
    Class notifyingClass;

    std::unordered_map<std::string, std::unordered_set<std::string>> _valueDependingKeys;

    KVOClass(Class originalClass, Class notifyingClass)
        : originalClass(originalClass), notifyingClass(notifyingClass), _valueDependingKeys() {
    }

    virtual void dealloc(id instance);

    const std::unordered_set<std::string>& valueDependingKeys(const std::string& key);

    virtual void ensureKeyWillNotify(const std::string&) {
    }

    /* statics */
protected:
    static std::recursive_mutex s_classMutex;

    // Links a kvo-notifying to its KVOClass struct.
    static std::unordered_map<Class, std::shared_ptr<KVOClass>> s_kvoClasses;

    // This is a map from a class to its kvo-notifying counterpart.
    static std::unordered_map<Class, Class> s_kvoNotifyingSubclasses;

public:
    static bool isKVOCapable(Class cls) {
        return class_getMethodImplementation(object_getClass(cls), @selector(_NSKVO)) != nullptr;
    }
    static bool isKVOCapable(id objcInstance) {
        return isKVOCapable(object_getClass(objcInstance));
    }

    static Class notifyingClassForClass(Class cls);
    static KVOClass& forClass(Class cls) {
        std::lock_guard<std::recursive_mutex> lock(s_classMutex);
        return *(s_kvoClasses[cls]);
    }
    static KVOClass& forInstance(id objcInstance) {
        return forClass((id)object_getClass(objcInstance));
    }

    static void ensureObjectWillNotify(id objcInstance);

    // must happen under lock
    static void registerClassPair(Class notifyingClass, Class originalClass, std::shared_ptr<KVOClass>&& attachedInfo = nullptr) {
        s_kvoNotifyingSubclasses.emplace(originalClass, notifyingClass);
        if (!attachedInfo) {
            s_kvoClasses.emplace(notifyingClass, std::make_shared<KVOClass>(originalClass, notifyingClass));
        } else {
            s_kvoClasses.emplace(notifyingClass, std::move(attachedInfo));
        }
    }
};

struct KVOSubscriber {
    id observer; // We do not retain our own observer, as that would create a retain cycle.
    NSKeyValueObservingOptions options;
    void* context;
    std::string keypath;
    std::weak_ptr<KVONotifier> weakNotifier;

    KVOSubscriber(id observer,
                  NSKeyValueObservingOptions options,
                  void* context,
                  const std::string& keypath,
                  const std::shared_ptr<KVONotifier>& notifier)
        : observer(observer), options(options), context(context), keypath(keypath), weakNotifier(notifier) {
    }
    bool hasOption(NSKeyValueObservingOptions opt) const {
        return (options & opt) > 0;
    }
};

struct KVOObservedKey : public std::enable_shared_from_this<KVOObservedKey> {
    std::weak_ptr<KVONotifier> weakInstance;
    std::string key; // Key is relative to instance.

    KVOObservedKey(const std::shared_ptr<KVONotifier>& instance, const std::string& key) : weakInstance(instance), key(key) {
    }

    std::unordered_set<std::shared_ptr<KVOSubscriber>> _subscribers;
    std::unordered_set<std::shared_ptr<KVOObservedKey>> _dependentKeys;

    void addSubscriber(std::shared_ptr<KVOSubscriber> subscriber) {
        _subscribers.insert(subscriber);
    }
    void removeSubscriber(std::shared_ptr<KVOSubscriber> subscriber) {
        _subscribers.erase(subscriber);
    }
    void addDependentKey(const std::shared_ptr<KVOObservedKey>& k) {
        _dependentKeys.insert(k);
    }
    bool hasDependents() {
        return !_subscribers.empty() || !_dependentKeys.empty();
    }
    void pruneDeadKeys() {
        for (auto it = _dependentKeys.begin(); it != _dependentKeys.end();) {
            if (!(*it)->hasDependents()) {
                it = _dependentKeys.erase(it);
            } else {
                ++it;
            }
        }
    }
};

struct KVONotifier : public std::enable_shared_from_this<KVONotifier> {
    KVOClass& notifyingClass;
    id instance;

private:
    std::recursive_mutex _mutex;

    std::unordered_set<std::shared_ptr<KVOSubscriber>> _subscribers;
    std::unordered_map<std::string, std::shared_ptr<KVOObservedKey>> _observedKeys;

    static std::unordered_map<id, std::shared_ptr<KVONotifier>> s_kvoInstances;
    static std::recursive_mutex s_instanceMutex;

public:
    KVONotifier(KVOClass& notifyingClass, id instance) : notifyingClass(notifyingClass), instance(instance), _mutex() {
    }
    KVONotifier(const KVONotifier&) = delete;
    const KVONotifier& operator=(const KVONotifier&) = delete;

    static KVONotifier& forInstance(id instance);
    static void removeInstance(id instance) {
        std::lock_guard<std::recursive_mutex> lock(s_instanceMutex);
        s_kvoInstances.erase(instance);
    }

private:
    id _valueForKey(const std::string& key) {
        return [instance valueForKeyPath:[NSString stringWithUTF8String:key.c_str()]];
    }

    std::shared_ptr<KVOObservedKey> _addSubscriber(std::shared_ptr<KVOSubscriber> subscriber, const std::string& keypath);
    void _removeSubscriber(std::shared_ptr<KVOSubscriber> subscriber, const std::string& keypath);
    void _reregisterSubkeys(KVOObservedKey& notifyingKey);

    struct KVOPendingNotification {
        idretaint<NSMutableDictionary> notificationDictionary;
        bool initial;
        idretaint<NSObject> priorValue;
        idretaint<NSObject> newValue;
    };

    std::unordered_map<std::string, KVOPendingNotification> _pendingNotifications;

    void _dispatch(KVOObservedKey& notifyingKey, KVOPendingNotification& pendingNotification, bool prior);

public:
    void addObserver(id observer, const std::string& keypath, NSKeyValueObservingOptions options = 0, void* context = nullptr) {
        auto newEntry = _subscribers.emplace(new KVOSubscriber(observer, options, context, keypath, shared_from_this()));
        auto& subscriber = *(newEntry.first);
        auto newKey = _addSubscriber(subscriber, keypath);
        if (subscriber->hasOption(NSKeyValueObservingOptionInitial)) {
            KVOPendingNotification pendingNotification;
            pendingNotification.initial = true;
            _dispatch(*newKey, pendingNotification, false);
        }
    }

    void removeObserver(id observer, const std::string& keypath, void* context) {
        auto foundSubscriber =
            std::find_if(_subscribers.begin(),
                         _subscribers.end(),
                         [&observer, &keypath, &context](const decltype(_subscribers)::value_type& subscriber) {
                             return subscriber->observer == observer && subscriber->keypath == keypath && subscriber->context == context;
                         });
        if (foundSubscriber == _subscribers.end()) {
            NSLog(@"KVO: Attempted to remove observer for unregistered keypath %@.%s.", instance, keypath.c_str());
            return;
        }
        _removeSubscriber(*foundSubscriber, keypath);
    }

    void willChange(const std::string& key) {
        auto foundKey = _observedKeys.find(key);
        if (foundKey == _observedKeys.end()) {
            return;
        }
        _dispatch(*foundKey->second, _pendingNotifications[key], true);
    }

    void didChange(const std::string& key) {
        auto foundKey = _observedKeys.find(key);
        if (foundKey == _observedKeys.end()) {
            return;
        }
        _dispatch(*foundKey->second, _pendingNotifications[key], false);
        _reregisterSubkeys(*foundKey->second);
        _pendingNotifications.erase(key);
    }
};

// Swizzling stuff
struct KVOSwizzledMethod {
    std::string key;
    size_t valueSize;
    IMP origImp;
    KVOSwizzledMethod(const std::string& key) : key(key), valueSize(0), origImp(nullptr) {
    }
    KVOSwizzledMethod(const std::string& key, const char* objcType, IMP origImp)
        : key(key), valueSize(getArgumentSize(objcType)), origImp(origImp) {
    }
    template <typename... Args>
    void callOriginal(id self, SEL _cmd, Args... args) {
        ((void (*)(id, SEL, Args...))origImp)(self, _cmd, std::forward<Args>(args)...);
    }
    template <typename... Args>
    void callOriginalVariadic(id self, SEL _cmd, Args... args) {
        ((void (*)(id, SEL, ...))origImp)(self, _cmd, std::forward<Args>(args)...);
    }
};

struct KVOSwizzledClass : public KVOClass {
private:
    std::unordered_map<SEL, KVOSwizzledMethod> _selectorMethodInfo;
    std::recursive_mutex _mutex;
    std::function<void(id)> _deallocInstance;

public:
    KVOSwizzledClass(Class originalClass, Class notifyingClass) : KVOClass(originalClass, notifyingClass), _selectorMethodInfo(), _mutex() {
        auto deallocIMP = (void (*)(id, SEL))class_getMethodImplementation(originalClass, @selector(dealloc));
        _deallocInstance = std::bind(deallocIMP, std::placeholders::_1, @selector(dealloc));
    }
    KVOSwizzledMethod& swizzledMethod(SEL sel) {
        std::lock_guard<std::recursive_mutex> lock(_mutex);
        return _selectorMethodInfo.at(sel);
    }
    void ensureKeyWillNotify(const std::string& key) override;

    void dealloc(id instance) override {
        KVOClass::dealloc(instance);
        _deallocInstance(instance);
    }

    static Class notifyingClassForClass(Class cls);
};
