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

template <>
struct std::hash<std::tuple<id, std::string>> {
    size_t operator()(const std::tuple<id, std::string>& o) const {
        return std::hash<id>()(std::get<0>(o)) ^ (std::hash<std::string>()(std::get<1>(o)) << 4);
    }
};

// NSKVOMatchAnyContextTag is an empty struct type tag used in notifier matching.
// It signals that the first notifier that matches on everything regardless of context
// should be removed.
struct NSKVOMatchAnyContextTag {};

class NSKVONotifier {
public:
    // dispatch a notification towards the observer.
    virtual void dispatch(bool) = 0;

    // matches returns whether this notifier matches the provided observer, keypath, and context.
    virtual bool matches(id observer, const std::string& keypath, NSKVOMatchAnyContextTag) = 0;
    virtual bool matches(id observer, const std::string& keypath, void* context) = 0;

    // addDependentNotifier registers a dependent notifier for destruction when it is removed
    virtual void addDependentNotifier(const std::shared_ptr<NSKVONotifier>& dependentNotifier) = 0;

    // updateLinks will reconnect a notifier to a newly-changed value
    virtual void updateLinks(id newValue) = 0;

    // breakLink will remove a notifier's connection to its old instance
    virtual void breakLink() = 0;

    virtual ~NSKVONotifier() = default;
};

struct NSKVOClass {
    Class originalClass;
    Class notifyingClass;

private:
    std::recursive_mutex _mutex;
    std::unordered_map<std::string, std::unordered_set<std::string>> _valueDependingKeys;
    std::unordered_map<std::tuple<id, std::string>, std::vector<std::weak_ptr<NSKVONotifier>>> _notifiersByInstance;
    std::unordered_map<std::tuple<id, std::string>, std::unordered_set<std::shared_ptr<NSKVONotifier>>> _keypathNotifiersByInstance;

    std::unordered_set<std::string> _currentlyManipulatingKeys;

    void _removeNotifier(id instance, const std::string& key, const NSKVONotifier* notifier);
    static std::shared_ptr<NSKVONotifier> _notifierForSubkeyOnInstance(id newValue,
                                                                       const std::string& keypath,
                                                                       const std::shared_ptr<NSKVONotifier>& leafNotifier);
    std::shared_ptr<NSKVONotifier> _linkedNotifierForLeaf(id instance,
                                                          const std::string& keypath,
                                                          const std::shared_ptr<NSKVONotifier>& leafNotifier);

public:
    NSKVOClass(Class originalClass, Class notifyingClass)
        : originalClass(originalClass), notifyingClass(notifyingClass), _valueDependingKeys() {
    }

    const std::unordered_set<std::string>& valueDependingKeys(const std::string& key);

    id valueForKey(id instance, const std::string& key) {
        return [instance valueForKeyPath:[NSString stringWithUTF8String:key.c_str()]];
    }

    virtual void ensureKeyWillNotify(const std::string&) {
    }
    virtual void dealloc(id instance);
    void addObserver(id instance, id observer, const std::string& keypath, NSKeyValueObservingOptions options = 0, void* context = nullptr);
    template <typename TContext>
    void removeObserver(id instance, id observer, const std::string& keypath, TContext context);
    void dispatch(id instance, const std::string& key, bool prior);

    /* statics */
public:
    static bool isKVOCapable(Class cls);
    static bool isKVOCapable(id objcInstance);

    static NSKVOClass& forClass(Class cls);
    static NSKVOClass& forInstance(id objcInstance);

    static Class notifyingClassForClass(Class cls);
    static void ensureObjectWillNotify(id objcInstance);

    static void registerClassPair(Class notifyingClass, Class originalClass, std::shared_ptr<NSKVOClass>&& attachedInfo = nullptr);
};

Class NSKVOSwizzledNotifyingClassForClass(Class);
