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
#import <Starboard.h>
#import <objc/objc.h>
#import <string>
#import <memory>
#import <vector>
#import <Starboard/String.h>

#import "NSObject_NSKeyValueArrayAdapter-Internal.h"

namespace {
struct ProxyInfo {
    idretaint<NSObject> _target;
    idretaint<NSString> _key;
    struct {
        /* Immutable Accessors */
        // required
        SEL count;
        // one is required
        SEL objectIn;
        SEL objectsAt;
        // optional
        SEL getRange;

        /* Mutable Accessors */
        // required
        SEL insertAtOne;
        SEL removeAtOne;
        // optional
        SEL insertAtMany;
        SEL removeAtMany;
        // super optional
        SEL replaceOne;
        SEL replaceMany;

        /* Brute Force Mutator */
        SEL get;
        SEL set;
    } _targetSelectors;

    bool setIfResponds(id target, const std::string& selectorString, SEL* out) {
        auto sel(sel_registerName(selectorString.c_str()));
        if ([target respondsToSelector:sel] && out) {
            *out = sel;
            return true;
        }
        return false;
    }

    ProxyInfo(id target, NSString* key) : _target(target) {
        _key.attach([key copy]);
        const char* rawKey = [key UTF8String];
        memset(reinterpret_cast<void*>(&_targetSelectors), 0, sizeof(_targetSelectors));

        // These four selectors, countOfKey, objectInKeyAtIndex, keyAtIndexes:, getKey:range:,
        // are used to back the proxy array.
        setIfResponds(target, woc::string::format("countOf%c%s", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.count);
        setIfResponds(target, woc::string::format("objectIn%c%sAtIndex:", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.objectIn);
        setIfResponds(target, woc::string::format("%sAtIndexes:", rawKey), &_targetSelectors.objectsAt);
        setIfResponds(target, woc::string::format("get%c%s:range:", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.getRange);

        // The mutation selectors insert, remove, and replace (with Key substituted where necessary)
        // are used to back the mutation-related methods on NSMutableArray.
        setIfResponds(target,
                      woc::string::format("insertObject:in%c%sAtIndex:", toupper(rawKey[0]), &rawKey[1]),
                      &_targetSelectors.insertAtOne);
        setIfResponds(target,
                      woc::string::format("removeObjectFrom%c%sAtIndex:", toupper(rawKey[0]), &rawKey[1]),
                      &_targetSelectors.removeAtOne);
        setIfResponds(target, woc::string::format("insert%c%s:atIndexes:", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.insertAtMany);
        setIfResponds(target, woc::string::format("remove%c%sAtIndexes:", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.removeAtMany);
        setIfResponds(target,
                      woc::string::format("replaceObjectIn%c%sAtIndex:withObject:", toupper(rawKey[0]), &rawKey[1]),
                      &_targetSelectors.replaceOne);
        setIfResponds(target,
                      woc::string::format("replace%c%sAtIndexes:with%c%s:", toupper(rawKey[0]), &rawKey[1], toupper(rawKey[0]), &rawKey[1]),
                      &_targetSelectors.replaceMany);

        // We use the same getter search mechanics as valueForKey:
        std::vector<std::string> possibleGetters{
            woc::string::format("get%c%s", toupper(rawKey[0]), &rawKey[1]),
            rawKey,
            woc::string::format("is%c%s", toupper(rawKey[0]), &rawKey[1]),
        };

        for (auto& possibleSelString : possibleGetters) {
            if (setIfResponds(target, possibleSelString, &_targetSelectors.get)) {
                break;
            }
        }

        // Setter -- if we can't find it, we will fall back to setValue:forKey:, the slow path.
        setIfResponds(target, woc::string::format("set%c%s:", toupper(rawKey[0]), &rawKey[1]), &_targetSelectors.set);
    }

    // calls a method identified by a selector, given the specified arguments
    template <typename Ret, typename... Args>
    Ret _call(SEL cmd, Args... args) {
        auto imp = objc_msg_lookup(_target, cmd);
        return reinterpret_cast<Ret (*)(id, SEL, Args...)>(imp)(_target, cmd, args...);
    }

    // This wraps the getter.
    inline id _get() {
        if (_targetSelectors.get) {
            return _call<id>(_targetSelectors.get);
        }
        return [_target valueForKey:_key];
    }

    // According to the reference documentation, if we can't call one of the specialized
    // key-specific setters, we fall through to the following two cases:
    // 1) If the class has setXxx:, we get the current value, copy it, mutate it, and set it back.
    // 2) If the class does not have setXxx:, we try to mutate it anyway.
    //    It'll likely fail.
    // This differs slightly from how it works on the reference platform:
    // If/only if you implement setXxx: is a mutable copy made, except in the case
    // of NSUserDefaults, which has some magic that we're not currently replicating.
    template <typename... Args>
    void _getMutateAndSet(SEL cmd, Args... args) {
        id currentValue = _get();
        currentValue = [[currentValue mutableCopy] autorelease];

        auto imp = objc_msg_lookup(currentValue, cmd);
        reinterpret_cast<void (*)(id, SEL, Args...)>(imp)(currentValue, cmd, args...);

        if (_targetSelectors.set) {
            _call<void>(_targetSelectors.set, currentValue);
        } else {
            _call<void>(@selector(setValue:forKey:), currentValue, _key);
        }
    }

    /* Implementations of methods called by the Objective-C side */
    NSUInteger count() {
        if (_targetSelectors.count) {
            return _call<NSUInteger>(_targetSelectors.count);
        }
        return [_get() count];
    }

    id objectAtIndex(NSUInteger index) {
        if (_targetSelectors.objectIn) {
            return _call<id>(_targetSelectors.objectIn, index);
        } else if (_targetSelectors.objectsAt) {
            return [_call<NSArray*>(_targetSelectors.objectsAt, [NSIndexSet indexSetWithIndex:index]) firstObject];
        }
        return [_get() objectAtIndex:index];
    }

    NSArray* objectsAtIndexes(NSIndexSet* indexes) {
        if (_targetSelectors.objectsAt) {
            return _call<NSArray*>(_targetSelectors.objectsAt, indexes);
        } else if (_targetSelectors.objectIn) {
            __block NSMutableArray* outArray = [NSMutableArray array];
            [indexes enumerateIndexesUsingBlock:^(NSUInteger idx, BOOL* stop) {
                id object = _call<id>(_targetSelectors.objectIn, idx);
                [outArray addObject:object];
            }];
            return outArray;
        }
        return [_get() objectsAtIndexes:indexes];
    }

    void getObjectsRange(id* objects, const NSRange& range) {
        if (_targetSelectors.getRange) {
            _call<void>(_targetSelectors.getRange, objects, range);
            return;
        }
        [_get() getObjects:objects range:range];
    }

    /* Mutables */
    void insertObjectAtIndex(id object, NSUInteger index) {
        if (_targetSelectors.insertAtOne) {
            _call<void>(_targetSelectors.insertAtOne, object, index);
            return;
        }

        _getMutateAndSet(@selector(insertObject:atIndex:), object, index);
    }

    void removeObjectAtIndex(NSUInteger index) {
        if (_targetSelectors.removeAtOne) {
            _call<void>(_targetSelectors.removeAtOne, index);
            return;
        }

        _getMutateAndSet(@selector(removeObjectAtIndex:), index);
    }

    void addObject(id object) {
        if (_targetSelectors.insertAtOne) {
            insertObjectAtIndex(object, count());
            return;
        }

        _getMutateAndSet(@selector(addObject:), object);
    }

    void removeLastObject() {
        if (_targetSelectors.removeAtOne) {
            removeObjectAtIndex(count() - 1);
            return;
        }

        _getMutateAndSet(@selector(removeLastObject));
    }

    void replaceObjectAtIndexWithObject(NSUInteger index, id object) {
        if (_targetSelectors.replaceOne) {
            _call<void>(_targetSelectors.replaceOne, index, object);
            return;
        } else if (_targetSelectors.removeAtOne && _targetSelectors.insertAtOne) {
            _call<void>(_targetSelectors.removeAtOne, index);
            _call<void>(_targetSelectors.insertAtOne, object, index);
            return;
        }

        _getMutateAndSet(@selector(replaceObjectAtIndex:withObject:), index, object);
    }
};
}

@interface _NSKeyProxyArray () {
    std::shared_ptr<ProxyInfo> _proxyInfo;
}
@end

@interface _NSMutableKeyProxyArray () {
    std::shared_ptr<ProxyInfo> _proxyInfo;
}
- (id)_initWithProxyInfo:(std::shared_ptr<ProxyInfo>)proxyInfo;
@end

@implementation _NSKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key {
    return [[[self alloc] initWithObject:object key:key] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key {
    if (self = [super init]) {
        _proxyInfo = std::make_shared<ProxyInfo>(object, key);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyInfo->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyInfo->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyInfo->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyInfo->getObjectsRange(objects, range);
}

- (_NSMutableKeyProxyArray*)_mutableProxy {
    return [[[_NSMutableKeyProxyArray alloc] _initWithProxyInfo:_proxyInfo] autorelease];
}

- (NSMutableArray*)mutableCopy {
    return [self _mutableProxy];
}
@end

@implementation _NSMutableKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key {
    return [[[self alloc] initWithObject:object key:key] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key {
    if (self = [super init]) {
        _proxyInfo = std::make_shared<ProxyInfo>(object, key);
    }
    return self;
}

- (id)_initWithProxyInfo:(std::shared_ptr<ProxyInfo>)proxyInfo {
    if (self = [super init]) {
        _proxyInfo = std::move(proxyInfo);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyInfo->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyInfo->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyInfo->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyInfo->getObjectsRange(objects, range);
}

// mutable methods
- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    _proxyInfo->insertObjectAtIndex(object, index);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    _proxyInfo->removeObjectAtIndex(index);
}

- (void)addObject:(id)object {
    _proxyInfo->addObject(object);
}

- (void)removeLastObject {
    _proxyInfo->removeLastObject();
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)object {
    _proxyInfo->replaceObjectAtIndexWithObject(index, object);
}

@end
