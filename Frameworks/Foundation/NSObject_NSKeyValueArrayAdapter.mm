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
#import <objc/objc.h>
#import <string>
#import <memory>
#import <vector>
#import <Starboard/String.h>

#import <NSObject_NSKeyValueCoding-Internal.h>

/*
* KVC Array Adapters
*
* On the reference platform, valueForKey:@"xx" will return a NSArray-workalike if you implement
* countOfXx and objectInXxAtIndex:.
*
* mutableArrayValueForKey:@"xx" will ALWAYS return an NSArray-workalike. It'll do the following things:
* - Preferentially use countOfXx and objectInXxAtIndex: for accessors.
* - Preferentially use insertObject:inXxAtIndex: and -removeObjectFromXxAtIndex: for mutators.
* - If these don't exist, accessors and mutators are proxied through to the following:
*     - The getters getXx, xx, and isXx.
*     - The instance Variables _xx or xx.
*     - valueForKey:@"xx"
* - If we used an ivar or valueForKey:, values of nil become empty arrays, @[].
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
* NSMutableArray* array = [object mutableArrayValueForKey:@"xx"];
* [object setValue:@[@1024] forKey:@"xx"];
*
* [[array objectAtIndex:0] isEqual:@(1024)];
*
* holds true.
*/

namespace {
struct ProxyArray {
    ProxyArray(id target, NSString* key, objc_ivar* ivar)
        : _target(target), _ivar(ivar), _treatNilValueAsEmptyArray(false), _targetSelectors() {
        _key.attach([key copy]);
        const char* rawKey = [key UTF8String];

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

        _targetSelectors.get = KVCGetterForPropertyName(target, rawKey);
        _targetSelectors.set = KVCSetterForPropertyName(target, rawKey);

        // Per the reference platform: If there's no setter (we're falling back to setValue:forKey:)
        // we have to treat nil values as empty arrays so that the user can mutate them.
        _treatNilValueAsEmptyArray = !_targetSelectors.set;
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
            return [_call<NSArray*>(_target, _targetSelectors.objectsAt, [NSIndexSet indexSetWithIndex:index]) firstObject];
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
    bool _treatNilValueAsEmptyArray;

    // Private helper to mimic reference platform behavior for missing methods
    template <typename... Args>
    void _getMutateAndSet(SEL cmd, Args... args) {
        id currentValue = _get(_target, _targetSelectors.get, _ivar, _key);

        if (!currentValue && !_treatNilValueAsEmptyArray) {
            [NSException
                 raise:NSInvalidArgumentException
                format:@"-[_NSKeyProxyArray %s]: value for key %@ on object %p is nil", sel_getName(cmd), _key.get(), _target.get()];
        }

        if (currentValue && !_ivar) {
            currentValue = [[currentValue mutableCopy] autorelease];
        } else if (!currentValue && _treatNilValueAsEmptyArray) {
            currentValue = [NSMutableArray array];
        }

        auto imp = objc_msg_lookup(currentValue, cmd);
        reinterpret_cast<void (*)(id, SEL, Args...)>(imp)(currentValue, cmd, args...);
        _set(currentValue, _target, _targetSelectors.set, _ivar, _key);
    }
};
}

@interface _NSKeyProxyArray () {
    std::shared_ptr<ProxyArray> _proxyArray;
}
@end

@interface _NSMutableKeyProxyArray () {
    std::shared_ptr<ProxyArray> _proxyArray;
}
- (id)_initWithProxyArray:(std::shared_ptr<ProxyArray>)proxyArray;
@end

@implementation _NSKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxyArray = std::make_shared<ProxyArray>(object, key, ivar);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyArray->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyArray->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyArray->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyArray->getObjectsRange(objects, range);
}

- (_NSMutableKeyProxyArray*)_mutableProxy {
    return [[[_NSMutableKeyProxyArray alloc] _initWithProxyArray:_proxyArray] autorelease];
}

- (NSMutableArray*)mutableCopy {
    return [self _mutableProxy];
}
@end

@implementation _NSMutableKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxyArray = std::make_shared<ProxyArray>(object, key, ivar);
    }
    return self;
}

- (id)_initWithProxyArray:(std::shared_ptr<ProxyArray>)proxyArray {
    if (self = [super init]) {
        _proxyArray = std::move(proxyArray);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyArray->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyArray->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyArray->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyArray->getObjectsRange(objects, range);
}

// mutable methods
- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    _proxyArray->insertObjectAtIndex(object, index);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    _proxyArray->removeObjectAtIndex(index);
}

- (void)addObject:(id)object {
    _proxyArray->addObject(object);
}

- (void)removeLastObject {
    _proxyArray->removeLastObject();
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)object {
    _proxyArray->replaceObjectAtIndexWithObject(index, object);
}

@end
