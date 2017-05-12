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

#import <Foundation/Foundation.h>
#import <Starboard.h>
#import <Starboard/String.h>
#import <Starboard/SmartTypes.h>

#import "NSObject_NSKeyValueCoding-Internal.h"

/*
* KVC Set Adapters
*
* On the reference platform, valueForKey:@"xx" will return a NSSet-workalike if you implement
* countOfXx, enumeratorOfXx:, and memberOfXx:.
*
* mutableSetValueForKey:@"xx" will ALWAYS return an NSSet-workalike. It'll do the following things:
* - Preferentially use countOfXx, enumeratorOfXx:, and memberOfXx: for accessors.
* - Preferentially use insertObject:inXxAtIndex: and -removeObjectFromXxAtIndex: for mutators.
* - If these don't exist, accessors and mutators are proxied through to the following:
*     - The getters getXx, xx, and isXx.
*     - The instance Variables _xx or xx.
*     - valueForKey:@"xx"
* - If we used an ivar or valueForKey:, values of nil become empty NSSets.
* - If we used a getter, a mutable copy of the object we get back is made.
* - The mutation is attempted.
*     - If we used an ivar, this will fail for immutable members.
* - If a method mutated the copy of xx, setters cascade as follows:
*     - The setter setXx:
*     - Directly into the instance variable _xx or xx.
*     - setValue: forKey:@"xx"
*
* Exceptions are expected at every stage of this pipeline.
* if the ivar xx contains a NSNumber, we will attempt (fail) to get a mutable copy of it,
* and then attempt (fail) to treat it like an array. This is entirely in keeping
* with the behaviour of the reference platform.
*
* No caching is done, as, on the reference platform
*
* NSMutableSet* set = [object mutableSetValueForKey:@"xx"];
* [object setValue:[NSSet setWithObject:@1024] forKey:@"xx"];
*
* [set containsObject:@1024];
*
* holds true.
*/

namespace {
struct ProxySet {
    ProxySet(id target, NSString* key, objc_ivar* ivar)
        : _target(target), _ivar(ivar), _targetSelectors(), _treatNilValueAsEmptySet(false) {
        _key.attach([key copy]);
        const char* rawKey = [key UTF8String];

        // Required selectors count, objectEnumerator, and member: to back proxy set
        setIfResponds(target, std::string("countOf").append(1, toupper(rawKey[0])).append(rawKey + 1), &_targetSelectors.count);
        setIfResponds(target, std::string("enumeratorOf").append(1, toupper(rawKey[0])).append(rawKey + 1), &_targetSelectors.enumeratorOf);
        setIfResponds(target,
                      std::string("memberOf").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":"),
                      &_targetSelectors.memberOf);

        // Required selectors addObject:, removeObject:, unionSet:, and minusSet: to back mutable proxy set
        setIfResponds(target,
                      std::string("add").append(1, toupper(rawKey[0])).append(rawKey + 1).append("Object:"),
                      &_targetSelectors.addObject);
        setIfResponds(target,
                      std::string("remove").append(1, toupper(rawKey[0])).append(rawKey + 1).append("Object:"),
                      &_targetSelectors.removeObject);
        setIfResponds(target, std::string("add").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":"), &_targetSelectors.unionSet);
        setIfResponds(target,
                      std::string("remove").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":"),
                      &_targetSelectors.minusSet);

        // Optional selectors that will be used if available
        setIfResponds(target,
                      std::string("intersect").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":"),
                      &_targetSelectors.intersectSet);
        setIfResponds(target, std::string("set").append(1, toupper(rawKey[0])).append(rawKey + 1).append(":"), &_targetSelectors.setSet);

        _targetSelectors.get = KVCGetterForPropertyName(target, rawKey);
        _targetSelectors.set = KVCSetterForPropertyName(target, rawKey);

        // Per the reference platform: If there's no setter (we're falling back to setValue:forKey:)
        // we have to treat nil values as empty arrays so that the user can mutate them.
        _treatNilValueAsEmptySet = !_targetSelectors.set;
    }

    // Accessors for proxy set
    NSUInteger count() {
        if (_targetSelectors.count) {
            return _call<NSUInteger>(_target, _targetSelectors.count);
        }

        return [_get(_target, _targetSelectors.get, _ivar, _key) count];
    }

    id member(id obj) {
        if (_targetSelectors.memberOf) {
            return _call<id>(_target, _targetSelectors.memberOf, obj);
        }

        return [_get(_target, _targetSelectors.get, _ivar, _key) member:obj];
    }

    NSEnumerator* objectEnumerator() {
        if (_targetSelectors.enumeratorOf) {
            return _call<NSEnumerator*>(_target, _targetSelectors.enumeratorOf);
        }

        return [_get(_target, _targetSelectors.get, _ivar, _key) objectEnumerator];
    }

    // Mutators for mutable proxy set
    void addObject(id obj) {
        if (_targetSelectors.addObject) {
            _call<void>(_target, _targetSelectors.addObject, obj);
        } else {
            NSSet* set = [NSSet setWithObject:obj];
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
            getMutateAndSet(@selector(addObject:), obj);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
        }
    }

    void removeObject(id obj) {
        if (_targetSelectors.removeObject) {
            _call<void>(_target, _targetSelectors.removeObject, obj);
        } else {
            NSSet* set = [NSSet setWithObject:obj];
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
            getMutateAndSet(@selector(removeObject:), obj);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
        }
    }

    void unionSet(NSSet* set) {
        if (_targetSelectors.unionSet) {
            _call<void>(_target, _targetSelectors.unionSet, set);
        } else {
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
            getMutateAndSet(@selector(unionSet:), set);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
        }
    }

    void minusSet(NSSet* set) {
        if (_targetSelectors.minusSet) {
            _call<void>(_target, _targetSelectors.minusSet, set);
        } else {
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
            getMutateAndSet(@selector(minusSet:), set);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
        }
    }

    void intersectSet(NSSet* set) {
        if (_targetSelectors.intersectSet) {
            _call<void>(_target, _targetSelectors.intersectSet, set);
        } else {
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueIntersectSetMutation usingObjects:set];
            getMutateAndSet(@selector(intersectSet:), set);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueIntersectSetMutation usingObjects:set];
        }
    }

    void setSet(NSSet* set) {
        if (_targetSelectors.setSet) {
            _call<void>(_target, _targetSelectors.setSet, set);
        } else {
            [_target willChangeValueForKey:_key withSetMutation:NSKeyValueSetSetMutation usingObjects:set];
            getMutateAndSet(@selector(setSet:), set);
            [_target didChangeValueForKey:_key withSetMutation:NSKeyValueSetSetMutation usingObjects:set];
        }
    }

private:
    StrongId<NSObject> _target;
    StrongId<NSString> _key;
    struct {
        /* Immutable Accessors */
        // required
        SEL count;
        SEL enumeratorOf;
        SEL memberOf;

        /* Mutable Accessors */
        // requires one of these
        SEL addObject;
        SEL unionSet;
        // and one of these
        SEL removeObject;
        SEL minusSet;
        // optional
        SEL intersectSet;
        SEL setSet;

        /* Brute Force Mutator */
        SEL get;
        SEL set;
    } _targetSelectors;
    objc_ivar* _ivar;
    bool _treatNilValueAsEmptySet;

    // Private helper to mimic reference platform behavior for missing methods
    template <typename... Args>
    void getMutateAndSet(SEL cmd, Args... args) {
        id currentValue = _get(_target, _targetSelectors.get, _ivar, _key);

        if (!currentValue && !_treatNilValueAsEmptySet) {
            [NSException raise:NSInvalidArgumentException
                        format:@"-[_NSKeyProxySet %s]: value for key %@ on object %p is nil", sel_getName(cmd), _key.get(), _target.get()];
        }

        if (currentValue && !_ivar) {
            currentValue = [[currentValue mutableCopy] autorelease];
        } else if (!currentValue && _treatNilValueAsEmptySet) {
            currentValue = [NSMutableSet set];
        }

        auto imp = objc_msg_lookup(currentValue, cmd);
        reinterpret_cast<void (*)(id, SEL, Args...)>(imp)(currentValue, cmd, args...);
        _set(currentValue, _target, _targetSelectors.set, _ivar, _key);
    }
};
}

@interface _NSKeyProxySet () {
    std::shared_ptr<ProxySet> _proxySet;
}
@end

@interface _NSMutableKeyProxySet () {
    std::shared_ptr<ProxySet> _proxySet;
}
- (id)_initWithProxySet:(std::shared_ptr<ProxySet>)proxySet;
@end

@implementation _NSKeyProxySet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxySet = std::make_shared<ProxySet>(object, key, ivar);
    }

    return self;
}

- (NSUInteger)count {
    return _proxySet->count();
}

- (id)member:(id)obj {
    return _proxySet->member(obj);
}

- (NSEnumerator*)objectEnumerator {
    return _proxySet->objectEnumerator();
}

- (_NSMutableKeyProxySet*)_mutableProxy {
    return [[[_NSMutableKeyProxySet alloc] _initWithProxySet:_proxySet] autorelease];
}

- (NSMutableSet*)mutableCopy {
    return [self _mutableProxy];
}

@end

@implementation _NSMutableKeyProxySet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxySet = std::make_shared<ProxySet>(object, key, ivar);
    }
    return self;
}

- (id)_initWithProxySet:(std::shared_ptr<ProxySet>)proxySet {
    if (self = [super init]) {
        _proxySet = std::move(proxySet);
    }
    return self;
}

- (NSUInteger)count {
    return _proxySet->count();
}

- (id)member:(id)obj {
    return _proxySet->member(obj);
}

- (NSEnumerator*)objectEnumerator {
    return _proxySet->objectEnumerator();
}

- (void)addObject:(id)obj {
    _proxySet->addObject(obj);
}

- (void)removeObject:(id)obj {
    _proxySet->removeObject(obj);
}

- (void)unionSet:(NSSet*)set {
    _proxySet->unionSet(set);
}

- (void)minusSet:(NSSet*)set {
    _proxySet->minusSet(set);
}

- (void)intersectSet:(NSSet*)set {
    _proxySet->intersectSet(set);
}

- (void)setSet:(NSSet*)set {
    _proxySet->setSet(set);
}

@end