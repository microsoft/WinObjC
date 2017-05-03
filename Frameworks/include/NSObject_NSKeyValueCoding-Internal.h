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

#pragma once

#include <Foundation/NSString.h>
#include <Foundation/NSMutableArray.h>
#include <Foundation/NSMutableOrderedSet.h>
#include <Foundation/NSMutableSet.h>

#include <Starboard/SmartTypes.h>

#include <string>

NSString* _NSKVCSplitKeypath(NSString* keyPath, NSString* __autoreleasing* pRemainder);
struct objc_ivar* KVCIvarForPropertyName(NSObject* self, const char* propName);
SEL KVCGetterForPropertyName(NSObject* self, const char* key);
bool KVCGetViaAccessor(NSObject* self, SEL getter, id* ret);
bool KVCGetViaIvar(id self, struct objc_ivar* ivar, id* ret);
SEL KVCSetterForPropertyName(NSObject* self, const char* key);
bool KVCSetViaAccessor(NSObject* self, SEL setter, id value, NSString* key = nil);
bool KVCSetViaIvar(NSObject* self, struct objc_ivar* ivar, id value, NSString* key = nil);

namespace {

// calls a method identified by a selector, given the specified arguments
template <typename Ret, typename... Args>
inline Ret _call(id target, SEL cmd, Args... args) {
    auto imp = objc_msg_lookup(target, cmd);
    return reinterpret_cast<Ret (*)(id, SEL, Args...)>(imp)(target, cmd, args...);
}

// This wraps the getter/s.
inline id _get(id target, SEL get, objc_ivar* ivar, NSString* key) {
    id object = nil;
    if (get) {
        KVCGetViaAccessor(target, get, &object);
    } else if (ivar) {
        KVCGetViaIvar(target, ivar, &object);
    } else {
        object = [target valueForKey:key];
    }
    return object;
}

inline void _set(id newValue, id target, SEL set, objc_ivar* ivar, NSString* key) {
    if (set) {
        KVCSetViaAccessor(target, set, newValue);
    } else if (ivar) {
        KVCSetViaIvar(target, ivar, newValue);
    } else {
        [target setValue:newValue forKey:key];
    }
}

inline void setIfResponds(id target, const std::string& selectorString, SEL* out) {
    SEL sel = sel_registerName(selectorString.c_str());
    *out = [target respondsToSelector:sel] ? sel : nullptr;
}

// NSProxyArray and NSProxyOrderedSet use ProxyOrderedBase as a shared implementation
struct ProxyOrderedBase {
    ProxyOrderedBase(id target, NSString* key, objc_ivar* ivar)
        : _target(target), _ivar(ivar), _treatNilValueAsEmptyOrderedSet(false), _targetSelectors() {
        _key.attach([key copy]);
        const char* rawKey = [key UTF8String];

        // These four selectors, countOfKey, objectInKeyAtIndex, keyAtIndexes:, getKey:range:,
        // are used to back the proxy orderedSet.
        setIfResponds(target, std::string("countOf").append(1, toupper(rawKey[0])).append(rawKey + 1), &_targetSelectors.count);
        setIfResponds(target,
                      std::string("objectIn").append(1, toupper(rawKey[0])).append(rawKey + 1).append("AtIndex:"),
                      &_targetSelectors.objectIn);
        setIfResponds(target, std::string(rawKey).append("AtIndexes:"), &_targetSelectors.objectsAt);
        setIfResponds(target,
                      std::string("get").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":range:"),
                      &_targetSelectors.getRange);

        // The mutation selectors insert, remove, and replace (with Key substituted where necessary)
        // are used to back the mutation-related methods on NSMutableOrderedSet.
        setIfResponds(target,
                      std::string("insertObject:in").append(1, toupper(rawKey[0])).append(rawKey + 1).append("AtIndex:"),
                      &_targetSelectors.insertAtOne);
        setIfResponds(target,
                      std::string("removeObjectFrom").append(1, toupper(rawKey[0])).append(rawKey + 1).append("AtIndex:"),
                      &_targetSelectors.removeAtOne);
        setIfResponds(target,
                      std::string("insert").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":atIndexes:"),
                      &_targetSelectors.insertAtMany);
        setIfResponds(target,
                      std::string("remove").append(1, toupper(rawKey[0])).append(rawKey + 1).append("AtIndexes:"),
                      &_targetSelectors.removeAtMany);
        setIfResponds(target,
                      std::string("replaceObjectIn").append(1, toupper(rawKey[0])).append(rawKey + 1).append("AtIndex:withObject"),
                      &_targetSelectors.replaceOne);
        setIfResponds(target,
                      std::string("replace")
                          .append(1, toupper(rawKey[0]))
                          .append(rawKey + 1)
                          .append("AtIndexes:with")
                          .append(1, toupper(rawKey[0]))
                          .append(rawKey + 1)
                          .append(":"),
                      &_targetSelectors.replaceMany);

        _targetSelectors.get = KVCGetterForPropertyName(target, rawKey);
        _targetSelectors.set = KVCSetterForPropertyName(target, rawKey);

        // Per the reference platform: If there's no setter (we're falling back to setValue:forKey:)
        // we have to treat nil values as empty orderedSets so that the user can mutate them.
        _treatNilValueAsEmptyOrderedSet = !_targetSelectors.set;
    }

    /* Implementations of methods called by the Objective-C side */
    NSUInteger count() {
        if (_targetSelectors.count) {
            return _call<NSUInteger>(_target, _targetSelectors.count);
        }
        return [_get(_target, _targetSelectors.get, _ivar, _key) count];
    }

    id objectAtIndex(NSUInteger index) {
        if (_targetSelectors.objectIn) {
            return _call<id>(_target, _targetSelectors.objectIn, index);
        } else if (_targetSelectors.objectsAt) {
            return [_call<NSOrderedSet*>(_target, _targetSelectors.objectsAt, [NSIndexSet indexSetWithIndex:index]) firstObject];
        }
        return [_get(_target, _targetSelectors.get, _ivar, _key) objectAtIndex:index];
    }

    NSArray* objectsAtIndexes(NSIndexSet* indexes) {
        if (_targetSelectors.objectsAt) {
            return _call<NSArray*>(_target, _targetSelectors.objectsAt, indexes);
        } else if (_targetSelectors.objectIn) {
            __block NSMutableArray* outArray = [NSMutableArray array];
            [indexes enumerateIndexesUsingBlock:^(NSUInteger idx, BOOL* stop) {
                id object = _call<id>(_target, _targetSelectors.objectIn, idx);
                [outArray addObject:object];
            }];
            return outArray;
        }
        return [_get(_target, _targetSelectors.get, _ivar, _key) objectsAtIndexes:indexes];
    }

    void getObjectsRange(id* objects, const NSRange& range) {
        if (_targetSelectors.getRange) {
            _call<void>(_target, _targetSelectors.getRange, objects, range);
        } else {
            [_get(_target, _targetSelectors.get, _ivar, _key) getObjects:objects range:range];
        }
    }

    /* Mutables */
    void insertObjectAtIndex(id object, NSUInteger index) {
        if (_targetSelectors.insertAtOne) {
            _call<void>(_target, _targetSelectors.insertAtOne, object, index);
        } else {
            NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:index];
            [_target willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(insertObject:atIndex:), object, index);

            [_target didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];
        }
    }

    void removeObjectAtIndex(NSUInteger index) {
        if (_targetSelectors.removeAtOne) {
            _call<void>(_target, _targetSelectors.removeAtOne, index);
        } else {
            NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:index];
            [_target willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(removeObjectAtIndex:), index);

            [_target didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];
        }
    }

    void insertObjectsAtIndexes(NSArray* objects, NSIndexSet* indexes) {
        if (_targetSelectors.insertAtMany) {
            _call<void>(_target, _targetSelectors.insertAtMany, objects, indexes);
        } else {
            [_target willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(insertObjects:atIndexes:), objects, indexes);

            [_target didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];
        }
    }

    void removeObjectsAtIndexes(NSIndexSet* indexes) {
        if (_targetSelectors.removeAtMany) {
            _call<void>(_target, _targetSelectors.removeAtMany, indexes);
        } else {
            [_target willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(removeObjectAtIndexes:), indexes);

            [_target didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];
        }
    }

    void addObject(id object) {
        if (_targetSelectors.insertAtOne) {
            insertObjectAtIndex(object, count());
        } else {
            NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:count()];
            [_target willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(addObject:), object);

            [_target didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:_key];
        }
    }

    void removeLastObject() {
        if (_targetSelectors.removeAtOne) {
            removeObjectAtIndex(count() - 1);
        } else {
            NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:count() - 1];
            [_target willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(removeLastObject));

            [_target didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:_key];
        }
    }

    void replaceObjectAtIndexWithObject(NSUInteger index, id object) {
        if (_targetSelectors.replaceOne) {
            _call<void>(_target, _targetSelectors.replaceOne, index, object);
        } else if (_targetSelectors.removeAtOne && _targetSelectors.insertAtOne) {
            _call<void>(_target, _targetSelectors.removeAtOne, index);
            _call<void>(_target, _targetSelectors.insertAtOne, object, index);
        } else {
            NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:count() - 1];
            [_target willChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:_key];

            _getMutateAndSet(@selector(replaceObjectAtIndex:withObject:), index, object);

            [_target didChange:NSKeyValueChangeReplacement valuesAtIndexes:indexes forKey:_key];
        }
    }

protected:
    virtual id _getEmptyContainer() = 0;

private:
    StrongId<NSObject> _target;
    StrongId<NSString> _key;
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
    objc_ivar* _ivar;
    bool _treatNilValueAsEmptyOrderedSet;

    // Private helper to mimic reference platform behavior for missing methods
    template <typename... Args>
    void _getMutateAndSet(SEL cmd, Args... args) {
        id currentValue = _get(_target, _targetSelectors.get, _ivar, _key);

        if (!currentValue && !_treatNilValueAsEmptyOrderedSet) {
            [NSException
                 raise:NSInvalidArgumentException
                format:@"-[_NSKeyProxyOrderedBase %s]: value for key %@ on object %p is nil", sel_getName(cmd), _key.get(), _target.get()];
        }

        if (currentValue && !_ivar) {
            currentValue = [[currentValue mutableCopy] autorelease];
        } else if (!currentValue && _treatNilValueAsEmptyOrderedSet) {
            currentValue = _getEmptyContainer();
        }

        auto imp = objc_msg_lookup(currentValue, cmd);
        reinterpret_cast<void (*)(id, SEL, Args...)>(imp)(currentValue, cmd, args...);
        _set(currentValue, _target, _targetSelectors.set, _ivar, _key);
    }
};
}

@interface _NSMutableKeyProxyArray : NSMutableArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end

@interface _NSKeyProxyArray : NSArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
- (_NSMutableKeyProxyArray*)_mutableProxy;
@end

@interface _NSMutableKeyProxySet : NSMutableSet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end

@interface _NSKeyProxySet : NSSet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
- (_NSMutableKeyProxySet*)_mutableProxy;
@end

@interface _NSMutableKeyProxyOrderedSet : NSMutableOrderedSet
+ (instancetype)proxyOrderedSetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end
