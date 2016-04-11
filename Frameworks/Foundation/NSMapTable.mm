//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/NSCoder.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSMapTable.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSMutableDictionary.h>
#import <NSPointerFunctionsConcrete.h>
#import <Starboard.h>

#import <memory>
#import <objc/objc-arc.h>
#import <unordered_map>

static NSString* const NSMapTableKeyOptionsEncodingKey = @"NSMapTableKeyOptionsEncodingKey";
static NSString* const NSMapTableValueOptionsEncodingKey = @"NSMapTableValueOptionsEncodingKey";
static NSString* const NSMapTableKeysEncodingKey = @"NSMapTableKeysEncodingKey";
static NSString* const NSMapTableValuesEncodingKey = @"NSMapTableValuesEncodingKey";

// Struct to represent NSPointerFunctions.hashFunction as std::hash, for keys in the internal map
struct _NSMapTableKeyHash {
    NSPointerFunctions* functions;

    std::size_t operator()(const id& item) const {
        if (functions.hashFunction != nullptr) {
            return functions.hashFunction(item, functions.sizeFunction);
        }
        return 0;
    }
};

// Struct to represent NSPointerFunctions.isEqualFunction as std::equal, for keys in the internal map
struct _NSMapTableKeyEqual {
    NSPointerFunctions* functions;

    bool operator()(const id& item1, const id& item2) const {
        if (functions.isEqualFunction != nullptr) {
            return functions.isEqualFunction(item1, item2, functions.sizeFunction);
        }
        return false;
    }
};

// Data structure to use internally
using internalmap_t = std::unordered_map<id, id, _NSMapTableKeyHash, _NSMapTableKeyEqual>;

// Used as an associated object on weak keys
// This causes the key's dealloc to trigger the dealloc of this object,
// allowing for automatic removal of the corresponding entry from the table
@interface _NSMapTableKeyDeallocObserver : NSObject
- (instancetype)initWithId:(id)anId mapTable:(NSMapTable*)mapTable;
- (void)deactivate;
@end

@implementation _NSMapTableKeyDeallocObserver {
@private
    id _heldId; // unsafe unretained
    NSMapTable* _mapTable; // weak
}

- (instancetype)initWithId:(id)anId mapTable:(NSMapTable*)mapTable {
    if (self = [super init]) {
        _heldId = anId;
        objc_storeWeak(&_mapTable, mapTable);
    }

    return self;
}

- (void)deactivate {
    // When removeObjectForKey/removeAllObjects/setObject with a new key manually removes a pair from the internal map,
    // the Handler should also no longer (redundantly) try to remove the pair again,
    // or (incorrectly) try to remove a future/replacement pair
    // deactivate the dealloc functionality by setting _mapTable to nil
    objc_destroyWeak(&_mapTable);
}

- (void)dealloc {
    [objc_loadWeak(&_mapTable) removeObjectForKey:_heldId];
    objc_destroyWeak(&_mapTable);
    [super dealloc];
}

@end

// Specialization of NSEnumerator for NSMapTable
@interface _NSMapTableEnumerator : NSEnumerator
- (instancetype)initWithSTLIterator:(internalmap_t::iterator)iterator container:(internalmap_t*)container returnKeys:(BOOL)returnKeys;
@end

@implementation _NSMapTableEnumerator {
@private
    internalmap_t::iterator _iterator;
    internalmap_t* _container; // assign
    BOOL _returnKeys;
}

- (instancetype)initWithSTLIterator:(internalmap_t::iterator)iterator container:(internalmap_t*)container returnKeys:(BOOL)returnKeys {
    if (self = [super init]) {
        _iterator = iterator;
        _container = container;
        _returnKeys = returnKeys;
    }

    return self;
}

- (NSObject*)nextObject {
    if (_iterator != _container->end()) {
        NSObject* ret = _returnKeys ? _iterator->first : _iterator->second;
        ++_iterator;
        return ret;
    }

    return nil;
}
@end

@implementation NSMapTable {
@private
    internalmap_t _internalMap;
}

/**
 @Status Interoperable
 @Notes Designated Initializer
*/
- (instancetype)initWithKeyOptions:(NSPointerFunctionsOptions)keys
                      valueOptions:(NSPointerFunctionsOptions)values
                          capacity:(NSUInteger)capacity {
    return [self initWithKeyPointerFunctions:[NSPointerFunctions pointerFunctionsWithOptions:keys]
                       valuePointerFunctions:[NSPointerFunctions pointerFunctionsWithOptions:values]
                                    capacity:capacity];
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSMapTable*)mapTableWithKeyOptions:(NSPointerFunctionsOptions)keyOptions valueOptions:(NSPointerFunctionsOptions)valueOptions {
    return [[[self alloc] initWithKeyOptions:keyOptions valueOptions:valueOptions capacity:0] autorelease];
}

/**
 @Status Interoperable
 @Notes Designated Initializer
*/
- (instancetype)initWithKeyPointerFunctions:(NSPointerFunctions*)keyFunctions
                      valuePointerFunctions:(NSPointerFunctions*)valueFunctions
                                   capacity:(NSUInteger)initialCapacity {
    if (self = [super init]) {
        _keyPointerFunctions = [keyFunctions copy];
        _valuePointerFunctions = [valueFunctions copy];

        _internalMap = internalmap_t(initialCapacity, { _keyPointerFunctions }, { _keyPointerFunctions });
    }

    return self;
}

// Helper for calling NSPointerFunctions.acquireFunction
+ (id)_acquireItem:(id)anObject pointerFunctions:(NSPointerFunctions*)pointerFunctions {
    auto acquireFunction = pointerFunctions.acquireFunction;
    return acquireFunction ?
               reinterpret_cast<id>(acquireFunction(anObject,
                                                    pointerFunctions.sizeFunction,
                                                    [reinterpret_cast<_NSConcretePointerFunctions*>(pointerFunctions) copyIn])) :
               anObject;
}

// Helper for calling NSPointerFunctions.relinquishFunction
+ (void)_relinquishItem:(id)anObject pointerFunctions:(NSPointerFunctions*)pointerFunctions {
    auto relinquishFunction = pointerFunctions.relinquishFunction;
    if (relinquishFunction) {
        relinquishFunction(anObject, pointerFunctions.sizeFunction);
    }
}

// Helper that erases an entry from the internal map, then relinquishes the key/value
- (void)_eraseAndRelinquish:(internalmap_t::iterator)entry {
    id value = entry->second;
    id key = entry->first;

    if (_NSMapTableKeyDeallocObserver* deallocObserver = objc_getAssociatedObject(key, self)) {
        // Turn off/remove the associated object
        [deallocObserver deactivate];
        objc_setAssociatedObject(key, self, nil, OBJC_ASSOCIATION_RETAIN);
    }

    if ([reinterpret_cast<_NSConcretePointerFunctions*>(_valuePointerFunctions) weakMemory]) {
        // If values are weak, mark the value as no longer weakly stored, so that it does not get invalidly auto-nilled later
        objc_destroyWeak(&entry->second);
    }

    _internalMap.erase(entry);
    [NSMapTable _relinquishItem:value pointerFunctions:_valuePointerFunctions];
    [NSMapTable _relinquishItem:key pointerFunctions:_keyPointerFunctions];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [self removeAllObjects];
    [_keyPointerFunctions release];
    [_valuePointerFunctions release];

    [super dealloc];
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSMapTable*)strongToStrongObjectsMapTable {
    return [self mapTableWithKeyOptions:NSMapTableStrongMemory valueOptions:NSMapTableStrongMemory];
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSMapTable*)weakToStrongObjectsMapTable {
    return [self mapTableWithKeyOptions:NSMapTableWeakMemory valueOptions:NSMapTableStrongMemory];
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSMapTable*)strongToWeakObjectsMapTable {
    return [self mapTableWithKeyOptions:NSMapTableStrongMemory valueOptions:NSMapTableWeakMemory];
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSMapTable*)weakToWeakObjectsMapTable {
    return [self mapTableWithKeyOptions:NSMapTableWeakMemory valueOptions:NSMapTableWeakMemory];
}

/**
 @Status Interoperable
 @Notes
*/
- (id)objectForKey:(id)aKey {
    auto entry = _internalMap.find(aKey);

    if (entry != _internalMap.end()) {
        return entry->second;
    }

    return nil;
}

/**
 @Status Interoperable
 @Notes
*/
- (NSEnumerator*)keyEnumerator {
    return [[[_NSMapTableEnumerator alloc] initWithSTLIterator:_internalMap.begin() container:&_internalMap returnKeys:YES] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSEnumerator*)objectEnumerator {
    return [[[_NSMapTableEnumerator alloc] initWithSTLIterator:_internalMap.begin() container:&_internalMap returnKeys:NO] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (void)setObject:(id)anObject forKey:(id)aKey {
    id keyToUse = [NSMapTable _acquireItem:aKey pointerFunctions:_keyPointerFunctions];
    id valueToUse = [NSMapTable _acquireItem:anObject pointerFunctions:_valuePointerFunctions];

    // Remove existing values first to make sure the proper relinquishes get called
    [self removeObjectForKey:keyToUse];

    auto insertedElement = _internalMap.emplace(keyToUse, valueToUse);

    // Set the value to auto nil, if memory is weak
    if ([reinterpret_cast<_NSConcretePointerFunctions*>(_valuePointerFunctions) weakMemory]) {
        objc_storeWeak(&insertedElement.first->second, valueToUse);
    }

    // Key is expected to remove the entry, not just nil the key, if memory is weak
    if ([reinterpret_cast<_NSConcretePointerFunctions*>(_keyPointerFunctions) weakMemory]) {
        // Attach an associated object to the key, then release it -
        // This ties its lifetime with that of the key, allowing removal of the map entry on its (key's) dealloc
        _NSMapTableKeyDeallocObserver* deallocObserver = [[_NSMapTableKeyDeallocObserver alloc] initWithId:keyToUse mapTable:self];
        // Since the key can be used as a key in multiple map tables, and thus have multiple _NSMapTableKeyDeallocObservers associated,
        // use self (this NSMapTable) as the key for the association
        objc_setAssociatedObject(keyToUse, self, deallocObserver, OBJC_ASSOCIATION_RETAIN);
        [deallocObserver release];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)removeObjectForKey:(id)aKey {
    auto it = _internalMap.find(aKey);
    if (it != _internalMap.end()) {
        [self _eraseAndRelinquish:it];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (void)removeAllObjects {
    while (!_internalMap.empty()) {
        const auto& it = _internalMap.begin();
        [self _eraseAndRelinquish:it];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (NSDictionary*)dictionaryRepresentation {
    NSMutableDictionary* ret = [NSMutableDictionary new];

    for (const auto& it : _internalMap) {
        [ret setObject:it.second forKey:it.first];
    }

    return [ret autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (NSUInteger)count {
    return _internalMap.size();
}

/**
 @Status Interoperable
 @Notes For encoding/decoding, all keys/values must also support NSCoding
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    NSPointerFunctionsOptions keyOptions = [decoder decodeIntForKey:NSMapTableKeyOptionsEncodingKey];
    NSPointerFunctionsOptions valueOptions = [decoder decodeIntForKey:NSMapTableValueOptionsEncodingKey];

    if (self = [self initWithKeyOptions:keyOptions valueOptions:valueOptions capacity:0]) {
        StrongId<NSMutableArray> keyArray = [decoder decodeObjectOfClass:[NSMutableArray class] forKey:NSMapTableKeysEncodingKey];
        StrongId<NSMutableArray> valueArray = [decoder decodeObjectOfClass:[NSMutableArray class] forKey:NSMapTableValuesEncodingKey];

        for (size_t i = 0; i < [keyArray count]; i++) {
            [self setObject:[valueArray objectAtIndex:i] forKey:[keyArray objectAtIndex:i]];
        }
    }

    return self;
}

/**
 @Status Interoperable
 @Notes For encoding/decoding, all keys/values must also support NSCoding
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeInt:[reinterpret_cast<_NSConcretePointerFunctions*>(_keyPointerFunctions) options]
                forKey:NSMapTableKeyOptionsEncodingKey];
    [encoder encodeInt:[reinterpret_cast<_NSConcretePointerFunctions*>(_valuePointerFunctions) options]
                forKey:NSMapTableValueOptionsEncodingKey];

    size_t count = [self count];

    StrongId<NSMutableArray> keyArray = [NSMutableArray arrayWithCapacity:count];
    StrongId<NSMutableArray> valueArray = [NSMutableArray arrayWithCapacity:count];

    size_t i = 0;
    for (const auto& it : _internalMap) {
        [keyArray addObject:it.first];
        [valueArray addObject:it.second];
    }

    [encoder encodeObject:keyArray forKey:NSMapTableKeysEncodingKey];
    [encoder encodeObject:valueArray forKey:NSMapTableValuesEncodingKey];
}

/**
 @Status Interoperable
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    NSMapTable* ret = [[[self class] alloc] initWithKeyPointerFunctions:_keyPointerFunctions
                                                  valuePointerFunctions:_valuePointerFunctions
                                                               capacity:[self count]];

    for (const auto& it : _internalMap) {
        [ret setObject:it.second forKey:it.first];
    }

    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    // [NSEnumerator countByEnumeratingWithState] stores the Enumerator in state->extra[0]
    return [(state->extra[0] ? (NSEnumerator*)state->extra[0] : [self keyEnumerator]) countByEnumeratingWithState:state
                                                                                                          objects:stackbuf
                                                                                                            count:len];
}

@end