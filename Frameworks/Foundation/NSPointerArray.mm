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
#import <Foundation/NSException.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSPointerArray.h>
#import <NSPointerFunctionsConcrete.h>

static NSUInteger sizeFunction(const void* item) {
    return static_cast<NSUInteger>(sizeof(void*));
}

@implementation NSPointerArray {
    // The number of allocated elements.
    // This implementation tries to allocate space for the pointers ahead of time, in order
    // to avoid allocation each time one inserts a pointer in the array. This variable
    // reflects the size of the allocated array.
    NSUInteger _allocated;
    // The number of elements in the NSPointerArray.
    // This value should always be less, or equal than _allocated variable.
    NSUInteger _count;
    // A C array containing all pointers of the NSPointerArray.
    void** _container;
};

+ (id)allocWithZone:(NSZone*)zone {
    if (self != [NSPointerArray class]) {
        return nil;
    }
    return [super allocWithZone:zone];
}

- (instancetype)init {
    if (self = [super init]) {
        _allocated = 0;
        _count = 0;
        _container = nullptr;
        _pointerFunctions = nil;
    }
    return self;
}

- (void)dealloc {
    // Release each non-null pointer in the array, according to the current policy.
    auto relinquish = self.pointerFunctions.relinquishFunction;
    if (relinquish) {
        for (NSUInteger i = 0; i < _count; i++) {
            void* ptr = _container[i];
            if (ptr != nullptr) {
                relinquish(ptr, sizeFunction);
            }
        }
    }
    free(_container);
    [_pointerFunctions release];
    [super dealloc];
}

// Like the reference platform, we don't handle the case of integer personality.
static void checkPointerFunctionsPersonality(NSPointerFunctions* pointerFunctions) {
    _NSConcretePointerFunctions* pointerFunctionsImpl = reinterpret_cast<_NSConcretePointerFunctions*>(pointerFunctions);
    NSPointerFunctionsOptions options = pointerFunctionsImpl.options;

    if ((options & NSPointerFunctionsIntegerPersonality) == NSPointerFunctionsIntegerPersonality) {
        [NSException raise:NSInternalInconsistencyException
                    format:@"An unsupported PointerFunctions configuration was requested, probably for use"
                            "by NSMapTable, NSHashTable, or NSPointerArray. The requested configuration fails"
                            "due to integer personality not using opaque memory"];
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options {
    if (self = [self init]) {
        _pointerFunctions = [[NSPointerFunctions alloc] initWithOptions:options];
        checkPointerFunctionsPersonality(_pointerFunctions);
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPointerFunctions:(NSPointerFunctions*)functions {
    if (self = [self init]) {
        _pointerFunctions = [functions copy];
        checkPointerFunctionsPersonality(_pointerFunctions);
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (NSPointerArray*)pointerArrayWithOptions:(NSPointerFunctionsOptions)options {
    return [[[NSPointerArray alloc] initWithOptions:options] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSPointerArray*)pointerArrayWithPointerFunctions:(NSPointerFunctions*)functions {
    return [[[NSPointerArray alloc] initWithPointerFunctions:functions] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSPointerArray*)strongObjectsPointerArray {
    return [self pointerArrayWithOptions:NSPointerFunctionsStrongMemory | NSPointerFunctionsObjectPersonality];
}

/**
 @Status Interoperable
*/
+ (NSPointerArray*)weakObjectsPointerArray {
    return [self pointerArrayWithOptions:NSPointerFunctionsWeakMemory | NSPointerFunctionsObjectPersonality];
}

// Returns YES if the collection contains regular Objective-C objects
- (BOOL)arrayContainsObjects {
    _NSConcretePointerFunctions* pointerFunctionsImpl = reinterpret_cast<_NSConcretePointerFunctions*>(self.pointerFunctions);
    NSPointerFunctionsOptions options = pointerFunctionsImpl.options;
    return (options & (NSPointerFunctionsObjectPointerPersonality | NSPointerFunctionsOpaquePersonality)) == 0;
}

// Returns YES if the collection contains null terminated C strings
- (BOOL)arrayContainsCString {
    _NSConcretePointerFunctions* pointerFunctionsImpl = reinterpret_cast<_NSConcretePointerFunctions*>(self.pointerFunctions);
    NSPointerFunctionsOptions options = pointerFunctionsImpl.options;
    return ((options & NSPointerFunctionsCStringPersonality) == NSPointerFunctionsCStringPersonality);
}

// Returns YES if the collection contains arbitrary chunks of data
- (BOOL)arrayContainsStructs {
    _NSConcretePointerFunctions* pointerFunctionsImpl = reinterpret_cast<_NSConcretePointerFunctions*>(self.pointerFunctions);
    NSPointerFunctionsOptions options = pointerFunctionsImpl.options;
    return ((options & NSPointerFunctionsStructPersonality) == NSPointerFunctionsStructPersonality);
}

// Compute an hash value of a memory area, by adding the value of each
// byte, rotated by its index.
static NSUInteger hashMemory(const void* ptr, size_t length) {
    const int NSUIntegerBitSize = 8 * sizeof(NSUInteger);
    const unsigned char* p = reinterpret_cast<const unsigned char*>(ptr);

    NSUInteger h = 0;
    for (size_t i = 0; i < length; i++) {
        int shift = (i & (NSUIntegerBitSize - 1));
        NSUInteger c = *p++;
        // Rotation to the left of the whole word
        c = (c << shift) | (c >> (NSUIntegerBitSize - shift));
        h ^= c;
    }
    return h;
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    NSUInteger h = 0;
    if ([self arrayContainsObjects]) {
        // Use the hash function of each object
        for (NSUInteger i = 0; i < _count; i++) {
            NSObject* o = reinterpret_cast<NSObject*>(_container[i]);
            h ^= [o hash];
        }
    } else if ([self arrayContainsCString]) {
        // Use a memory hash function over a C string
        for (NSUInteger i = 0; i < _count; i++) {
            if (_container[i]) {
                const char* s = reinterpret_cast<const char*>(_container[i]);
                h ^= hashMemory(_container[i], strlen(s));
            }
        }
    } else if ([self arrayContainsStructs]) {
        // Use a memory hash function
        auto sizeFunction = self.pointerFunctions.sizeFunction;
        for (NSUInteger i = 0; i < _count; i++) {
            if (_container[i]) {
                h ^= hashMemory(_container[i], sizeFunction(_container[i]));
            }
        }
    } else {
        // The hash value is computed by adding shifted pointers of the array.
        const int NSUIntegerBitSize = 8 * sizeof(NSUInteger);
        for (NSUInteger i = 0; i < _count; i++) {
            NSUInteger p = reinterpret_cast<NSUInteger>(_container[i]);
            int shift = (i & (NSUIntegerBitSize - 1));
            p = (p << shift) | (p >> (NSUIntegerBitSize - shift));
            h ^= p;
        }
    }
    return h;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSPointerArray class]]) {
        return NO;
    }

    // Both arrays should have the same number of elements
    // (But the allocated spaced is meaningless.)
    NSPointerArray* otherArray = static_cast<NSPointerArray*>(other);
    if (otherArray.count != _count) {
        return NO;
    }

    if ([self arrayContainsObjects]) {
        // Compare each elements of the array using the "isEqual:" selector
        for (NSUInteger i = 0; i < _count; i++) {
            void* p1 = _container[i];
            void* p2 = otherArray->_container[i];

            // Same pointer means same object
            if (p1 == p2) {
                continue;
            }

            // Compare elements
            NSObject* o1 = static_cast<NSObject*>(p1);
            NSObject* o2 = static_cast<NSObject*>(p2);
            if (![o1 isEqual:o2]) {
                return NO;
            }
        }
    } else if ([self arrayContainsCString]) {
        // Compare each C-string using strcmp
        for (NSUInteger i = 0; i < _count; i++) {
            const char* s1 = reinterpret_cast<const char*>(_container[i]);
            const char* s2 = reinterpret_cast<const char*>(otherArray->_container[i]);

            // Same pointer means same object
            if (s1 == s2) {
                continue;
            }

            // If one of the pointer is null, but not the other, arrays are not equal
            if ((s1 && !s2) || (!s1 && s2)) {
                return NO;
            }
            if (strcmp(s1, s2)) {
                return NO;
            }
        }
    } else if ([self arrayContainsStructs]) {
        // Compare each C-string using memcmp
        auto sizeFunction = self.pointerFunctions.sizeFunction;
        for (NSUInteger i = 0; i < _count; i++) {
            void* p1 = _container[i];
            void* p2 = otherArray->_container[i];

            // Same pointer means same object
            if (p1 == p2) {
                continue;
            }

            // If one of the pointer is null, but not the other, arrays are not equal
            if ((p1 && !p2) || (!p1 && p2)) {
                return NO;
            }
            // Compare the size of both objects
            NSUInteger s1 = sizeFunction(p1);
            NSUInteger s2 = sizeFunction(p2);
            if (s1 != s2) {
                return NO;
            }

            if (memcmp(p1, p2, s1)) {
                return NO;
            }
        }
    } else {
        // This case is used for arbitrary pointers
        // We directly compare the value of the pointer/integer
        for (NSUInteger i = 0; i < _count; i++) {
            if (_container[i] != otherArray->_container[i]) {
                return NO;
            }
        }
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    return _count;
}

// Helper function, not publicly exposed, used by unit test to check the allocation state
- (NSUInteger)allocatedCount {
    return _allocated;
}

- (const void* const)containerPtr {
    return _container;
}

/**
 @Status Interoperable
*/
- (void)setCount:(NSUInteger)count {
    if (count == _count) {
        return;
    }

    // If we reduce the size of the collection, we release the objects after the new size
    if (count < _count) {
        auto relinquishFunction = self.pointerFunctions.relinquishFunction;
        if (relinquishFunction) {
            for (NSUInteger i = count; i < _count; i++) {
                if (_container[i]) {
                    relinquishFunction(_container[i], sizeFunction);
                    _container[i] = nullptr;
                }
            }
        }
        // Shrink the allocated memory
        _allocated = count;
        _container = static_cast<void**>(realloc(_container, sizeof(void*) * _allocated));
    }

    // Do we need some more space?
    if (count > _allocated) {
        _allocated = count;
        _container = static_cast<void**>(realloc(_container, sizeof(void*) * _allocated));
    }

    // The collection is larger, so we set all the new elements to "nullptr"
    if (count > _count) {
        memset(_container + _count, 0, sizeof(void*) * (count - _count));
    }

    _count = count;
}

/**
 @Status Interoperable
*/
- (NSArray*)allObjects {
    if (![self arrayContainsObjects]) {
        [NSException raise:NSInvalidArgumentException
                    format:@"NSPointerArray has options that cannot be used to return an array of objects"];
    }

    NSMutableArray* array = [NSMutableArray arrayWithCapacity:_count];
    for (NSUInteger i = 0; i < _count; i++) {
        auto ptr = _container[i];
        if (ptr != nullptr) {
            [array addObject:static_cast<NSObject*>(ptr)];
        }
    }
    return [NSArray arrayWithArray:array];
}

/**
 @Status Interoperable
*/
- (void*)pointerAtIndex:(NSUInteger)index {
    if (index < _count) {
        return _container[index];
    }
    return nullptr;
}

// Returns the number of elements allocated / deallocated at once
static inline NSUInteger allocationStep() {
    return 64;
}

/**
 @Status Interoperable
*/
- (void)addPointer:(void*)pointer {
    if (_count > _allocated) {
        [NSException raise:NSInternalInconsistencyException format:@"Inconsistent internal state"];
    }

    // If we have reached to maximum number of elements, we allocate more space
    if (_count == _allocated) {
        _allocated += allocationStep();
        _container = static_cast<void**>(realloc(_container, sizeof(void*) * _allocated));
    }

    // Add the pointer to the collection, using the policy of the current pointer functions
    auto acquireFunction = self.pointerFunctions.acquireFunction;
    if (pointer && acquireFunction) {
        pointer = acquireFunction(pointer, sizeFunction, NO);
    }
    _container[_count++] = pointer;
}

/**
 @Status Interoperable
*/
- (void)removePointerAtIndex:(NSUInteger)index {
    if (index >= _count) {
        [NSException raise:NSInvalidArgumentException
                    format:@"attempt to remove pointer at index %ld beyond bounds %ld", (long)index, (long)_count];
    }

    // Release the pointer, according to the current policy
    void* ptr = _container[index];
    auto relinquishFunction = self.pointerFunctions.relinquishFunction;
    if (ptr && relinquishFunction) {
        relinquishFunction(ptr, sizeFunction);
    }

    // Move the remaining pointers after the removed element
    memmove(_container + index, _container + index + 1, sizeof(void*) * (_count - index - 1));
    _count--;

    // Reduce the allocated memory, if needed
    if (_count == 0 || _allocated - _count >= allocationStep()) {
        // Compute the nearest number of allocated steps to match the count
        _allocated = _count;
        if (_allocated) {
            _container = static_cast<void**>(realloc(_container, sizeof(void*) * _allocated));
        } else {
            free(_container);
            _container = nullptr;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)insertPointer:(void*)item atIndex:(NSUInteger)index {
    if (index > _count) {
        [NSException raise:NSInvalidArgumentException
                    format:@"attempt to insert pointer at index %ld beyond bounds %ld", (long)index, (long)_count];
    }

    // Inserting a pointer at the end of the array is the same as adding a pointer
    if (index == _count) {
        [self addPointer:item];
    } else {
        // Add a pointer at the end of the array, so that we have enough space for the new element
        [self addPointer:nullptr];

        // Shift the elements
        memmove(_container + index + 1, _container + index, sizeof(void*) * (_count - index));

        // Retain the inserted element
        auto acquireFunction = self.pointerFunctions.acquireFunction;
        if (item && acquireFunction) {
            item = acquireFunction(item, sizeFunction, NO);
        }

        _container[index] = item;
    }
}

/**
 @Status Interoperable
*/
- (void)replacePointerAtIndex:(NSUInteger)index withPointer:(void*)item {
    if (index > _count) {
        [NSException raise:NSInvalidArgumentException
                    format:@"attempt to replace pointer at index %ld beyond bounds %ld", (long)index, (long)_count];
    }

    auto acquireFunction = self.pointerFunctions.acquireFunction;
    auto relinquishFunction = self.pointerFunctions.relinquishFunction;

    // We retains the new element first...
    if (item && acquireFunction) {
        item = acquireFunction(item, sizeFunction, NO);
    }

    // ..and then, we release the replaced element
    if (_container[index] && relinquishFunction) {
        relinquishFunction(_container[index], sizeFunction);
    }

    _container[index] = item;
}

/**
 @Status Interoperable
*/
- (void)compact {
    NSUInteger lastNonNull = 0;
    for (NSUInteger i = 0; i < _count; i++) {
        if (_container[i] != nullptr) {
            if (lastNonNull != i) {
                _container[lastNonNull] = _container[i];
            }
            lastNonNull++;
        }
    }

    _count = lastNonNull;

    // If the array has been compacted, we reduce the size of the allocated memory accordingly
    if (_count < _allocated) {
        if (_count == 0) {
            free(_container);
            _container = nullptr;
        } else {
            _container = static_cast<void**>(realloc(_container, sizeof(void*) * _count));
        }
        _allocated = _count;
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super init]) {
        NSUInteger options = 0;
        options = [decoder decodeIntegerForKey:@"NS.options"];
        NSUInteger count = [decoder decodeIntegerForKey:@"NS.count"];

        _pointerFunctions = [[NSPointerFunctions alloc] initWithOptions:options];

        for (NSUInteger i = 0; i < count; i++) {
            NSObject* obj = [decoder decodeObject];
            [self addPointer:static_cast<void*>(obj)];
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    if (![self arrayContainsObjects]) {
        [NSException raise:NSInvalidArgumentException format:@"NSPointerArray has options that cannot be encoded"];
    }

    NSUInteger options = (self.pointerFunctions.usesStrongWriteBarrier ? NSPointerFunctionsStrongMemory : NSPointerFunctionsWeakMemory);
    [encoder encodeInteger:options forKey:@"NS.options"];
    [encoder encodeInteger:_count forKey:@"NS.count"];

    for (NSObject* obj in self) {
        [encoder encodeObject:obj];
    }
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    if (![self arrayContainsObjects]) {
        [NSException raise:NSInvalidArgumentException format:@"NSPointerArray has options that cannot be copied"];
    }

    NSPointerArray* copy = [NSPointerArray pointerArrayWithPointerFunctions:self.pointerFunctions];
    auto acquireFunction = self.pointerFunctions.acquireFunction;
    copy.count = _count;

    // Proceed to a shallow copy of the pointers
    if (acquireFunction) {
        // We have an "acquire" function, so let's use it
        for (NSUInteger i = 0; i < _count; i++) {
            if (_container[i]) {
                copy->_container[i] = acquireFunction(_container[i], sizeFunction, NO);
            }
        }
    } else {
        // No acquire function: we just copy the pointer as-is
        memcpy(copy->_container, _container, sizeof(void*) * _count);
    }

    return copy;
}

/**
 @Status Interoperable
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    // Initial state
    if (state->state == 0) {
        // Arbitrary pointer to track mutations.
        state->mutationsPtr = reinterpret_cast<unsigned long*>(self);
        // The extra array will hold the current index in the enumeration, so let's start with element at index 0
        state->extra[0] = 0;
        // Next step...
        state->state++;
    }

    // Do we have more elements?
    if (state->extra[0] > _count) {
        return 0;
    }

    // Compute the maximum number of elements we can return
    NSUInteger remaining = _count - state->extra[0];
    NSUInteger slice = MIN(len, remaining);

    // Pointers returned
    state->itemsPtr = reinterpret_cast<id*>(_container + state->extra[0]);

    // Move the current index
    state->extra[0] += slice;

    return slice;
}

@end
