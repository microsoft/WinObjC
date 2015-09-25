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
#include "Foundation/NSSet.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableSet.h"
#include "Foundation/NSEnumerator.h"
#include "Foundation/NSKeyedArchiver.h"
#include "Foundation/NSString.h"

void NSSetTableInit(NSSet* set, NSUInteger capacity) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    set->_table.dict = CFDictionaryCreateMutable(NULL, capacity, &kCFTypeDictionaryKeyCallBacks, NULL);
}

id NSSetTableMember(NSSet* set, id object) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    id ret = nil;

    if (CFDictionaryGetValueIfPresent(set->_table.dict, (void*)object, (const void**)&ret)) {
        return ret;
    }

    return nil;
}

void NSSetTableAddObject(NSSet* set, id object) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    if (object == nil)
        return;
    if (NSSetTableMember(set, object) == nil) {
        CFDictionarySetValue(set->_table.dict, (const void*)object, (void*)object);
    }
}

void NSSetTableInitWithObjects(NSSet* set, id* objects, int count) {
    NSSetTableInit(set, count);
    while (count--) {
        NSSetTableAddObject(set, *objects);
        objects++;
    }
}

void NSSetTableFree(NSSet* set) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        return;
    }
    if (set->_table.dict != NULL) {
        CFDictionaryRemoveAllValues(set->_table.dict);
        _CFDictionaryDestroyInternal(set->_table.dict);
    }
}

void NSSetTableRemoveObject(NSSet* set, id object) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    CFDictionaryRemoveValue(set->_table.dict, (void*)object);
}

void NSSetTableRemoveAllObjects(NSSet* set) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    CFDictionaryRemoveAllValues(set->_table.dict);
}

NSUInteger NSSetTableCount(NSSet* set) {
    if (object_getClass(set) != [NSSet class] && object_getClass(set) != [NSMutableSet class]) {
        assert(0);
    }
    return CFDictionaryGetCount(set->_table.dict);
}

void NSSetGetEnumerator(NSSet* set, void* enumeratorHolder) {
    CFDictionaryGetKeyEnumerator(set->_table.dict, enumeratorHolder);
}

int NSSetEnumeratorGetNextObject(NSSet* set, void* enumeratorHolder, id* ret, int count) {
    return CFDictionaryGetNextKey(set->_table.dict, enumeratorHolder, ret, count);
}

@implementation NSSet : NSObject
+ (id)setWithObject:(id)obj {
    return [[[self alloc] initWithObjects:&obj count:1] autorelease];
}

+ (instancetype)setWithObjects:(NSObject*)first, ... {
    va_list pReader;
    va_start(pReader, first);

    int max = 0;
    int count = 0;
    id* objs = NULL;

    if (count >= max) {
        max += 64;
        objs = (id*)EbrRealloc(objs, max * sizeof(id));
    }

    objs[count++] = first;

    id curVal = va_arg(pReader, id);

    while (curVal != NULL) {
        if (count >= max) {
            max += 64;
            objs = (id*)EbrRealloc(objs, max * sizeof(id));
        }

        objs[count++] = curVal;

        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    NSSet* ret = [[self alloc] initWithObjects:objs count:count];
    EbrFree(objs);

    return [ret autorelease];
}

- (instancetype)setByAddingObjectsFromSet:(NSSet*)set {
    NSMutableSet* result = [[self mutableCopy] autorelease];

    [result unionSet:set];

    return result;
}

- (instancetype)setByAddingObject:(id)obj {
    NSMutableSet* result = [[self mutableCopy] autorelease];

    [result addObject:obj];

    return result;
}

+ (instancetype)setWithObjects:(id*)objects count:(NSUInteger)count {
    return [[[self alloc] initWithObjects:objects count:count] autorelease];
}

+ (NSSet*)setWithSet:(NSSet*)set {
    return [[[self alloc] initWithSet:set] autorelease];
}

+ (NSSet*)setWithArray:(NSArray*)array {
    return [[[self alloc] initWithArray:array] autorelease];
}

- (instancetype)init {
    NSSetTableInit(self, 0);
    return self;
}

- (instancetype)initWithObjects:(id*)objects count:(unsigned)count {
    NSSetTableInitWithObjects(self, objects, count);
    return self;
}

- (instancetype)initWithArray:(NSArray*)array {
    NSUInteger count = [array count];
    id* objects = (id*)EbrMalloc(count * sizeof(id));

    [array getObjects:objects];

    NSSet* ret = [self initWithObjects:objects count:count];

    EbrFree(objects);
    return ret;
}

- (instancetype)initWithSet:(NSSet*)set {
    NSUInteger count = [set count];
    id* objects = (id*)EbrMalloc(count * sizeof(id));
    NSUInteger i = 0;

    for (id curObj in set) {
        assert(i < count);
        objects[i++] = curObj;
    }

    NSSet* ret = [self initWithObjects:objects count:count];
    EbrFree(objects);

    return ret;
}

- (instancetype)initWithObjects:(NSObject*)first, ... {
    va_list pReader;
    va_start(pReader, first);

    int max = 0;
    int count = 0;
    id* objs = NULL;

    if (count >= max) {
        max += 64;
        objs = (id*)EbrRealloc(objs, max * sizeof(id));
    }

    objs[count++] = first;

    id curVal = va_arg(pReader, id);

    while (curVal != NULL) {
        if (count >= max) {
            max += 64;
            objs = (id*)EbrRealloc(objs, max * sizeof(id));
        }

        objs[count++] = curVal;

        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    NSSet* ret = [self initWithObjects:objs count:count];
    EbrFree(objs);

    return ret;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    return [self initWithArray:[coder decodeObjectForKey:@"NS.objects"]];
}

- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        [coder _encodeArrayOfObjects:[self allObjects] forKey:@"NS.objects"];
    } else {
        assert(0);
    }
}

+ (NSSet*)set {
    return [[self new] autorelease];
}

- (BOOL)containsObject:(id)obj {
    return [self member:obj] != nil;
}

- (id)anyObject {
    for (id curObj in self) {
        return curObj;
    }

    return nil;
}

- (NSArray*)allObjects {
    return [[self objectEnumerator] allObjects];
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSMutableSet*)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableSet alloc] initWithSet:self];
}

- (void)makeObjectsPerformSelector:(SEL)selector {
    for (id curObj in self) {
        _m(curObj, selector);
    }
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state
                                  objects:(id*)stackBuf
                                    count:(unsigned)maxCount {
    if (state->state == 0) {
        state->state = 1;
        state->mutationsPtr = &state->state;
        NSSetGetEnumerator(self, state->extra);
    }
    assert(maxCount > 0);

    state->itemsPtr = stackBuf;
    return NSSetEnumeratorGetNextObject(self, state->extra, stackBuf, maxCount);
}

- (BOOL)isSubsetOfSet:(NSSet*)other {
    if (self == other)
        return YES;

    for (id curObj in self) {
        if ([other member:curObj] == nil)
            return NO;
    }

    return YES;
}

- (BOOL)intersectsSet:(NSSet*)other {
    if (self == other)
        return YES;

    for (id curObj in self) {
        if ([other member:curObj])
            return YES;
    }

    return NO;
}

- (BOOL)isEqualToSet:(NSSet*)other {
    if (self == other)
        return YES;

    if ([self count] != [other count])
        return NO;

    for (id curObj in self) {
        if ([other member:curObj] == nil)
            return NO;
    }

    return YES;
}

- (void)enumerateObjectsUsingBlock:(void (^)(id, BOOL*))block {
    [self enumerateObjectsWithOptions:0 usingBlock:block];
}

- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(void (^)(id, BOOL*))block {
    if (options & NSEnumerationReverse) {
        assert(0);
    } else {
        BOOL stop = FALSE;
        int i = 0;

        for (id curObj in self) {
            EbrCallBlock(block, "dddd", block, curObj, i, &stop);
            i++;
            if (stop)
                break;
        }
    }
}

- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)descriptors {
    NSArray* ret = [self allObjects];
    [ret sortedArrayUsingDescriptors:descriptors];

    return ret;
}

- (id)member:(id)obj {
    return NSSetTableMember(self, obj);
}

- (unsigned)count {
    return NSSetTableCount(self);
}

- (void)dealloc {
    NSSetTableFree(self);
    [super dealloc];
}

- (NSEnumerator*)objectEnumerator {
    return [NSEnumerator enumeratorWithIterator:NSSetGetEnumerator
                                      forObject:self
                                   nextFunction:NSSetEnumeratorGetNextObject];
}

@end
