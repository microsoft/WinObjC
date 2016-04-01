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
#include "StubReturn.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSDictionaryConcrete.h"
#include <CoreFoundation/CFDictionary.h>
#include <vector>

static const wchar_t* TAG = L"NSDictionary";

@implementation NSDictionaryConcrete

BRIDGED_CLASS_REQUIRED_IMPLS(CFDictionaryRef, CFDictionaryGetTypeID, NSDictionary, NSDictionaryConcrete)

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    NSDictionaryConcrete* newSelf = nullptr;
    // need to figure out if this is a mutable init or not.
    if ([self isMemberOfClass:[NSMutableDictionary class]]) {
        newSelf = reinterpret_cast<NSDictionaryConcrete*>(static_cast<NSMutableDictionary*>(
            CFDictionaryCreateMutable(NULL, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks)));

        for (unsigned i = 0; i < count; i++) {
            id key = [keys[i] copy];
            CFDictionarySetValue(static_cast<CFMutableDictionaryRef>(newSelf), (const void*)key, (void*)vals[i]);
            [key release];
        }
    } else {
        std::vector<id> keyCopies(count);
        for (unsigned i = 0; i < count; i++) {
            keyCopies[i] = [keys[i] copy];
        }

        newSelf = reinterpret_cast<NSDictionaryConcrete*>(static_cast<NSDictionary*>(CFDictionaryCreate(NULL,
                                                                                                        (const void**)(keyCopies.data()),
                                                                                                        (const void**)(vals),
                                                                                                        count,
                                                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                                                        &kCFTypeDictionaryValueCallBacks)));

        for (unsigned i = 0; i < count; i++) {
            [keyCopies[i] release];
        }
    }

    [self release];
    self = newSelf;
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [self initWithObjects:nullptr forKeys:nullptr count:0];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(NSUInteger)numElements {
    NSDictionaryConcrete* newSelf = reinterpret_cast<NSDictionaryConcrete*>(static_cast<NSMutableDictionary*>(
        CFDictionaryCreateMutable(NULL, numElements, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks)));
    [self release];
    self = newSelf;
    return self;
}

/**
 @Status Interoperable
*/
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
    // HACKHACK: this isn't quite correct because it snapshots the keys at this moment.
    // its technically not supported to mutate while enumerating so go with it.
    return [[self allKeys] objectEnumerator];
}

/**
 @Status Interoperable
*/
- (void)setObject:(id)object forKey:(id)key {
    key = [key copy];
    CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)object);
    [key release];
}

/**
 @Status Interoperable
*/
- (void)removeObjectForKey:(id)key {
    CFDictionaryRemoveValue((CFMutableDictionaryRef)self, (void*)key);
}

/**
 @Status Interoperable
*/
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
