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

#include "Starboard.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSDictionaryConcrete.h"
#include <CoreFoundation/CFDictionary.h>
#include <vector>

static const wchar_t* TAG = L"NSDictionary";

#pragma region Immutable Concrete Subclass
@implementation NSDictionaryConcrete {
@private
    StrongId<NSCFDictionary> _nscf;
}

- (instancetype)init {
    return [self initWithObjects:nil forKeys:nil count:0];
}

- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    if (self = [super init]) {
        std::vector<id> keyCopies(count);
        for (unsigned i = 0; i < count; i++) {
            keyCopies[i] = [keys[i] copy];
        }

        _nscf.attach(reinterpret_cast<NSCFDictionary*>(static_cast<NSDictionary*>(CFDictionaryCreate(NULL,
                                                                                                     (const void**)(keyCopies.data()),
                                                                                                     (const void**)(vals),
                                                                                                     count,
                                                                                                     &kCFTypeDictionaryKeyCallBacks,
                                                                                                     &kCFTypeDictionaryValueCallBacks))));

        for (unsigned i = 0; i < count; i++) {
            [keyCopies[i] release];
        }
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, objectForKey:(id)key);
- INNER_BRIDGE_CALL(_nscf, NSEnumerator*, keyEnumerator);

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@implementation NSMutableDictionaryConcrete {
@private
    StrongId<NSCFDictionary> _nscf;
}

- (instancetype)init {
    return [self initWithCapacity:0];
}

- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFDictionary*>(static_cast<NSDictionary*>(
            CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks))));
        for (unsigned i = 0; i < count; i++) {
            [_nscf setObject:vals[i] forKey:keys[i]];
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)numItems {
    if (self = [super init]) {
        _nscf.attach(reinterpret_cast<NSCFDictionary*>(static_cast<NSDictionary*>(
            CFDictionaryCreateMutable(NULL, numItems, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks))));
    }
    return self;
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, objectForKey:(id)key);
- INNER_BRIDGE_CALL(_nscf, NSEnumerator*, keyEnumerator);
- INNER_BRIDGE_CALL(_nscf, void, setObject:(id)anObject forKey:(id<NSCopying>)aKey);
- INNER_BRIDGE_CALL(_nscf, void, removeObjectForKey:(id)key);
- INNER_BRIDGE_CALL(_nscf, void, removeAllObjects);
- INNER_BRIDGE_CALL(_nscf, NSArray*, allValues);
- INNER_BRIDGE_CALL(_nscf, NSArray*, allKeys);

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFDictionary

BRIDGED_CLASS_REQUIRED_IMPLS(CFDictionaryRef, CFDictionaryGetTypeID, NSDictionary, NSCFDictionary)

- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    FAIL_FAST();
    return nil;
}

- (instancetype)initWithCapacity:(NSUInteger)numElements {
    FAIL_FAST();
    return nil;
}

- (id)objectForKey:(id)key {
    if (key == nil) {
        TraceWarning(TAG, L"Warning: objectForKey called with nil\n");
        return nil;
    }

    return (id)CFDictionaryGetValue((CFDictionaryRef)self, (const void*)key);
}

- (NSUInteger)count {
    return CFDictionaryGetCount((CFDictionaryRef)self);
}

- (NSEnumerator*)keyEnumerator {
    // TODO: BUG 7087201
    // This isn't quite correct because it snapshots the keys at this moment,
    // but it's technically not supported to mutate while enumerating, so go with it.
    return [[self allKeys] objectEnumerator];
}

- (void)setObject:(id)object forKey:(id)key {
    key = [key copy];
    CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)object);
    [key release];
}

- (void)removeObjectForKey:(id)key {
    CFDictionaryRemoveValue((CFMutableDictionaryRef)self, (void*)key);
}

- (void)removeAllObjects {
    CFDictionaryRemoveAllValues((CFMutableDictionaryRef)self);
}

- (NSArray*)allValues {
    int count = CFDictionaryGetCount(static_cast<CFDictionaryRef>(self));

    if (count == 0) {
        return [NSArray array];
    }

    std::vector<id> values(count);
    CFDictionaryGetKeysAndValues((CFDictionaryRef)self, nullptr, (const void**)values.data());

    return [NSArray arrayWithObjects:values.data() count:values.size()];
}

- (NSArray*)allKeys {
    int count = CFDictionaryGetCount(static_cast<CFDictionaryRef>(self));

    if (count == 0) {
        return [NSArray array];
    }

    std::vector<id> keys(count);
    CFDictionaryGetKeysAndValues((CFDictionaryRef)self, (const void**)keys.data(), nullptr);

    return [NSArray arrayWithObjects:keys.data() count:keys.size()];
}

@end
#pragma endregion