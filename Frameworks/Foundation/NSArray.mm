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
#include "CFArrayInternal.h"
#include "NSPropertyListReader.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSEnumerator.h"
#include "Foundation/NSKeyedArchiver.h"
#include "Foundation/NSArray.h"
#include "CoreFoundation/CFArray.h"
#include "Foundation/NSMutableString.h"
#include "CoreFoundation/CFType.h"
#include "Foundation/NSIndexSet.h"
#include "Foundation/NSNull.h"

__declspec(dllimport) extern "C" int CFNSBlockCompare(id obj1, id obj2, void* block);

@class NSXMLPropertyList, NSPropertyListReader, NSArrayConcrete, NSMutableArrayConcrete, NSPropertyListWriter_Binary;

@implementation NSArray : NSObject
+ (NSArray*)arrayWithObjects:(NSObject*)first, ... {
    va_list pReader;
    va_start(pReader, first);
    NSArray* ret = [self new];
    if (first == nil) {
        return [ret autorelease];
    }
    CFArrayAppendValue((CFMutableArrayRef)ret, (const void*)first);

    id curVal = va_arg(pReader, id);

    while (curVal != NULL) {
        CFArrayAppendValue((CFMutableArrayRef)ret, (const void*)curVal);

        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return [ret autorelease];
}

+ (NSArray*)arrayWithObject:(NSObject*)obj {
    NSArray* ret = [self new];
    CFArrayAppendValue((CFMutableArrayRef)ret, (const void*)obj);

    return [ret autorelease];
}

- (NSArray*)initWithObject:(NSObject*)obj {
    [self init];

    CFArrayAppendValue((CFMutableArrayRef)self, (const void*)obj);

    return self;
}

+ (NSArray*)array {
    NSArray* ret = [self new];

    return [ret autorelease];
}

+ (NSArray*)arrayWithObjects:(id*)objs count:(NSUInteger)count {
    NSArray* ret = [self alloc];

    _CFArrayInitInternalWithObjects((CFArrayRef)ret, (const void**)objs, count, true);

    return [ret autorelease];
}

+ (NSArray*)arrayWithArray:(NSArray*)arrayToCopy {
    NSArray* ret = [[self alloc] initWithArray:arrayToCopy];
    return [ret autorelease];
}

+ (NSArray*)arrayWithContentsOfFile:(NSString*)filename {
    id ret = [[self alloc] initWithContentsOfFile:filename];

    return [ret autorelease];
}

- (NSArray*)initWithObjects:(NSObject*)first, ... {
    va_list pReader;
    va_start(pReader, first);
    [self init];
    if (first == nil) {
        return self;
    }
    CFArrayAppendValue((CFMutableArrayRef)self, (const void*)first);

    id curVal = va_arg(pReader, id);

    while (curVal != NULL) {
        CFArrayAppendValue((CFMutableArrayRef)self, (const void*)curVal);

        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return self;
}

- (NSArray*)initWithObjects:(id*)objs count:(NSUInteger)count {
    _CFArrayInitInternalWithObjects((CFArrayRef)self, (const void**)objs, count, true);

    return self;
}

- (NSArray*)initWithObjectsTakeOwnership:(NSObject**)objs count:(NSUInteger)count {
    _CFArrayInitInternalWithObjects((CFArrayRef)self, (const void**)objs, count, false);

    return self;
}

- (NSArray*)initWithContentsOfFile:(NSString*)filename {
    const char* file = (char*)[filename UTF8String];

    NSData* data = [NSData dataWithContentsOfFile:filename];

    if (data == nil) {
        return nil;
    }

    char* pData = (char*)[data bytes];

    NSArray* ar;

    if (memcmp(pData, "<?xml", 4) == 0) {
        ar = [NSXMLPropertyList propertyListFromData:data];
        if (![ar isKindOfClass:[NSArray class]]) {
            ar = [ar objectForKey:@"$objects"];
        }
        if (![(id)ar isKindOfClass:[NSArray class]]) {
            assert(0);
        }
    } else {
        NSPropertyListReaderA reader;
        reader.init(data);
        ar = reader.read();
    }

    [self initWithArray:ar];

    return self;
}

- (NSUInteger)count {
    return CFArrayGetCount((CFArrayRef)self);
}

- (NSObject*)init {
    _CFArrayInitInternal((CFArrayRef)self);
    return self;
}

- (NSObject*)lastObject {
    int count = [self count];

    if (count == 0) {
        return nil;
    }

    return [self objectAtIndex:count - 1];
}

- (NSObject*)firstObject {
    int count = [self count];

    if (count == 0) {
        return nil;
    }

    return [self objectAtIndex:0];
}

- (id)objectAtIndex:(NSUInteger)index {
    if (index >= CFArrayGetCount((CFArrayRef)self)) {
        EbrDebugLog("objectAtIndex: index > count (%d > %d), throwing exception\n", index, CFArrayGetCount((CFArrayRef)self));
        [NSException raise:@"Array out of bounds" format:@""];
        return nil;
    }
    return (id)CFArrayGetValueAtIndex((CFArrayRef)self, index);
}

- (id)objectAtIndexedSubscript:(NSUInteger)index {
    return [self objectAtIndex:index];
}

- (NSUInteger)indexOfObject:(id)obj {
    int count = CFArrayGetCount((CFArrayRef)self);

    for (int i = 0; i < count; i++) {
        id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
        if ([obj isEqual:value]) {
            return i;
        }
    }

    return NSNotFound;
}

- (NSIndexSet*)indexesOfObjectsPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))pred {
    int count = CFArrayGetCount((CFArrayRef)self);

    NSMutableIndexSet* ret = [NSMutableIndexSet indexSet];
    for (int i = 0; i < count; i++) {
        id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
        BOOL shouldStop = false;

        if (pred(value, i, &shouldStop)) {
            [ret addIndex:i];
        }

        if (shouldStop) {
            break;
        }
    }

    return ret;
}

- (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(id, NSUInteger, BOOL*))pred {
    int count = CFArrayGetCount((CFArrayRef)self);

    for (int i = 0; i < count; i++) {
        id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
        BOOL shouldStop = false;

        if (pred(value, i, &shouldStop)) {
            return i;
        }

        if (shouldStop) {
            break;
        }
    }

    return NSNotFound;
}

- (NSUInteger)indexOfObject:(id)obj inRange:(NSRange)range {
    unsigned count = CFArrayGetCount((CFArrayRef)self);

    for (unsigned i = range.location; i < count && i < (range.location + range.length); i++) {
        id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
        if ([obj isEqual:value]) {
            return i;
        }
    }

    return NSNotFound;
}

- (NSUInteger)indexOfObjectIdenticalTo:(id)obj {
    int count = CFArrayGetCount((CFArrayRef)self);

    for (int i = 0; i < count; i++) {
        if ((id)CFArrayGetValueAtIndex((CFArrayRef)self, i) == obj) {
            return i;
        }
    }

    return NSNotFound;
}

- (NSArray*)initWithCoder:(NSCoder*)coder {
    id array = [coder decodeObjectForKey:@"NS.objects"];

    [self initWithArray:array];
    return self;
}

- (NSArray*)initWithArray:(NSArray*)arrayToCopy {
    if (arrayToCopy != nil &&
        (object_getClass(arrayToCopy) == [NSArrayConcrete class] || object_getClass(arrayToCopy) == [NSMutableArrayConcrete class])) {
        int objCount = CFArrayGetCount((CFArrayRef)arrayToCopy);
        id* objs = NULL;

        if (objCount > 0) {
            objs = (id*)_CFArrayGetPtr((CFArrayRef)arrayToCopy);
        }

        _CFArrayInitInternalWithObjects((CFArrayRef)self, (const void**)objs, objCount, true);
    } else {
        id* objs = NULL;
        int objCount = 0;

        int count = [arrayToCopy count];
        objs = (id*)malloc(count * sizeof(id));

        for (int i = 0; i < count; i++) {
            objs[objCount++] = [arrayToCopy objectAtIndex:i];
        }

        _CFArrayInitInternalWithObjects((CFArrayRef)self, (const void**)objs, objCount, true);
        free(objs);
    }

    return self;
}

- (NSArray*)initWithArray:(id)arrayToCopy copyItems:(BOOL)copyFlag {
    [self init];

    int count = [arrayToCopy count];
    for (int i = 0; i < count; i++) {
        id curVal = [arrayToCopy objectAtIndex:i];

        if (copyFlag) {
            id copy = [curVal copyWithZone:nil];
            CFArrayAppendValue((CFMutableArrayRef)self, (const void*)copy);
            [copy release];
        } else {
            CFArrayAppendValue((CFMutableArrayRef)self, (const void*)curVal);
        }
    }

    return self;
}

- (NSObject*)valueForKey:(NSString*)key {
    id ret = [NSMutableArray array];

    id enumerator = [self objectEnumerator];
    id curVal = [enumerator nextObject];

    while (curVal != nil) {
        id newvalue = [curVal valueForKey:key];
        if (newvalue == nil) {
            [ret addObject:[NSNull null]];
        } else {
            [ret addObject:newvalue];
        }

        curVal = [enumerator nextObject];
    }

    return ret;
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount {
    if (state->state == 0) {
        state->mutationsPtr = (unsigned long*)&state->extra[1];
        state->extra[0] = (unsigned long)[self objectEnumerator];
        state->state = 1;
    }
    assert(maxCount > 0);

    NSUInteger numRet = 0;
    state->itemsPtr = stackBuf;

    while (maxCount > 0) {
        id next = [(id)state->extra[0] nextObject];
        if (next == nil) {
            break;
        }

        *stackBuf = next;
        stackBuf++;
        numRet++;
        maxCount--;
    }

    return numRet;
}

- (void)makeObjectsPerformSelector:(SEL)selector {
    id enumerator = [self objectEnumerator];

    id nextObject = [enumerator nextObject];

    while (nextObject != nil) {
        [nextObject performSelector:selector];
        nextObject = [enumerator nextObject];
    }
}

- (void)setValue:(NSObject*)value forKey:(NSString*)key {
    for (NSObject* cur in self) {
        [cur setValue:value forKey:key];
    }
}

- (void)makeObjectsPerformSelector:(SEL)selector withObject:(NSObject*)obj {
    id enumerator = [self objectEnumerator];

    id nextObject = [enumerator nextObject];

    while (nextObject != nil) {
        [nextObject performSelector:selector withObject:obj];
        nextObject = [enumerator nextObject];
    }
}

- (BOOL)containsObject:(NSObject*)obj {
    for (NSObject* curObj in self) {
        if ([curObj isEqual:obj]) {
            return TRUE;
        }
    }

    return FALSE;
}

- (NSString*)componentsJoinedByString:(NSString*)str {
    id ret = [NSMutableString new];
    id enumerator = [self objectEnumerator];
    id nextObject = [enumerator nextObject];

    bool addSeparator = false;

    while (nextObject != nil) {
        if (addSeparator) {
            [ret appendString:str];
        }
        addSeparator = true;
        [ret appendString:nextObject];

        nextObject = [enumerator nextObject];
    }

    return [ret autorelease];
}

typedef NSInteger (*compFuncType)(id, id, void*);

- (NSArray*)sortedArrayUsingFunction:(compFuncType)compFunc context:(void*)context {
    NSArray* ret = [NSMutableArray arrayWithArray:self];
    [ret sortUsingFunction:compFunc context:context];

    return ret;
}

- (NSArray*)sortedArrayUsingComparator:(NSComparator)comparator {
    NSArray* ret = [NSMutableArray arrayWithArray:self];

    [ret sortUsingFunction:CFNSBlockCompare context:comparator];

    return ret;
}

- (NSArray*)filteredArrayUsingPredicate:(NSPredicate*)predicate {
    NSArray* ret = [NSMutableArray arrayWithArray:self];
    [ret filterUsingPredicate:predicate];

    return ret;
}

- (NSObject*)mutableCopy {
    return [self mutableCopyWithZone:nil];
}

- (NSObject*)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableArray alloc] initWithArray:self];
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (NSEnumerator*)objectEnumerator {
    id ret = [NSEnumerator enumeratorWithIterator:CFArrayGetValueEnumerator forObject:self nextFunction:CFArrayGetNextValue];

    return ret;
}

- (NSEnumerator*)reverseObjectEnumerator {
    return [NSEnumerator enumeratorWithArrayReverse:self];
}

- (NSArray*)sortedArrayUsingSelector:(SEL)selector {
    NSArray* newArray = [NSMutableArray alloc];
    [newArray initWithArray:self];

    [newArray sortUsingSelector:selector];

    return [newArray autorelease];
}

- (NSArray*)sortedArrayUsingDescriptors:(NSArray*)descriptors {
    NSArray* newArray = [NSMutableArray alloc];
    [newArray initWithArray:self];

    [newArray sortUsingDescriptors:descriptors];

    return [newArray autorelease];
}

- (NSArray*)subarrayWithRange:(NSRange)range {
    NSArray* newArray = [NSArray new];

    for (NSUInteger i = range.location; i < range.location + range.length; i++) {
        id obj = [self objectAtIndex:i];
        CFArrayAppendValue((CFMutableArrayRef)newArray, (const void*)obj);
    }

    return [newArray autorelease];
}

- (NSObject*)firstObjectCommonWithArray:(NSArray*)array {
    int i, count = [self count];

    for (i = 0; i < count; i++) {
        id obj = [self objectAtIndex:i];

        if ([array indexOfObject:obj] != NSNotFound) {
            return obj;
        }
    }

    return nil;
}

- (NSArray*)arrayByAddingObject:(NSObject*)obj {
    NSArray* newArray = [[[self class] alloc] initWithArray:self];

    CFArrayAppendValue((CFMutableArrayRef)newArray, (const void*)obj);

    return [newArray autorelease];
}

- (NSArray*)arrayByAddingObjectsFromArray:(NSArray*)arr {
    NSArray* newArray = [[[self class] alloc] initWithArray:self];

    id arrEnum = [arr objectEnumerator];
    id curObj = [arrEnum nextObject];

    while (curObj != nil) {
        CFArrayAppendValue((CFMutableArrayRef)newArray, (const void*)curObj);
        curObj = [arrEnum nextObject];
    }

    return [newArray autorelease];
}

- (NSArray*)pathsMatchingExtensions:(NSArray*)extensions {
    id ret = [[NSMutableArray alloc] init];

    id arrEnum = [self objectEnumerator];
    id curObj = [arrEnum nextObject];

    int extCount = [extensions count];

    while (curObj != nil) {
        id ext = [curObj pathExtension];

        for (int i = 0; i < extCount; i++) {
            id curExt = [extensions objectAtIndex:i];

            if ([curExt isEqualToString:ext]) {
                [ret addObject:curExt];
            }
        }
        curObj = [arrEnum nextObject];
    }

    return ret;
}

- (NSUInteger)indexOfObject:(NSObject*)obj
              inSortedRange:(NSRange)range
                    options:(NSBinarySearchingOptions)options
            usingComparator:(NSComparator)comparator {
    if (range.length == 0) {
        if (options & NSBinarySearchingInsertionIndex) {
            return range.location;
        }

        return NSNotFound;
    }
    if (range.length == 1) {
        id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, range.location);
        int cmp = comparator(obj, value);

        if (cmp == NSOrderedSame) {
            return range.location;
        } else if (cmp <= NSOrderedAscending) {
            if (options & NSBinarySearchingInsertionIndex) {
                return range.location;
            } else {
                return NSNotFound;
            }
        } else {
            //  NSOrderedDescending
            if (options & NSBinarySearchingInsertionIndex) {
                return range.location + 1;
            } else {
                return NSNotFound;
            }
        }
    } else {
        //  Not positive if the logic is right here .. need to run some tests (and also optimize properly)
        int count = CFArrayGetCount((CFArrayRef)self);
        int start = range.location;
        int end = range.location + range.length;
        int inc = 1;
        int insertIdx = end;

        if (options & NSBinarySearchingLastEqual) {
            for (int i = end - 1; i < count && i >= start; i--) {
                id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
                int cmp = comparator(obj, value);

                if (cmp == 0) {
                    return i;
                }
                if (cmp > 0) {
                    insertIdx = i;
                }
            }
        } else {
            //  First equal
            for (int i = start; i < count && i < end; i++) {
                id value = (id)CFArrayGetValueAtIndex((CFArrayRef)self, i);
                int cmp = comparator(obj, value);

                if (cmp == 0) {
                    return i;
                }
                if (cmp > 0 && insertIdx == end) {
                    insertIdx = i;
                }
            }
        }

        if (options & NSBinarySearchingInsertionIndex) {
            return insertIdx;
        }

        return NSNotFound;
    }
}

- (void)dealloc {
    CFArrayRemoveAllValues((CFArrayRef)self);
    _CFArrayDestroyInternal((CFArrayRef)self);

    [super dealloc];
}

- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically {
    EbrDebugLog("Writing array to file %s\n", [file UTF8String]);

    id data = [NSMutableData data];
    [NSPropertyListWriter_Binary serializePropertyList:self intoData:data];
    return [data writeToFile:file atomically:atomically];
}

- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        [coder _encodeArrayOfObjects:self forKey:@"NS.objects"];
    } else {
        int i, count = [self count];

        [coder encodeValueOfObjCType:"i" at:&count];
        for (i = 0; i < count; i++) {
            [coder encodeObject:[self objectAtIndex:i]];
        }
    }
}

- (NSString*)description {
    EbrDebugLog("NSArray description not supported\n");
    return @"Not supported";
}

+ (NSObject*)allocWithZone:(NSZone*)zone {
    if (self == [NSArray class]) {
        return NSAllocateObject((Class)[NSArrayConcrete class], 0, zone);
    }

    return NSAllocateObject((Class)self, 0, zone);
}

- (void)getObjects:(id*)objects {
    NSUInteger i, count = [self count];

    for (i = 0; i < count; i++) {
        objects[i] = [self objectAtIndex:i];
    }
}

- (void)enumerateObjectsUsingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    [self enumerateObjectsWithOptions:0 usingBlock:block];
}

- (void)enumerateObjectsWithOptions:(NSUInteger)options usingBlock:(void (^)(id, NSUInteger, BOOL*))block {
    int i, count = [self count];

    BOOL stop = FALSE;

    if (options & NSEnumerationReverse) {
        for (i = count - 1; i >= 0 && !stop; i--) {
            id curObj = [self objectAtIndex:i];
            block(curObj, i, &stop);
        }
    } else {
        for (i = 0; i < count && !stop; i++) {
            id curObj = [self objectAtIndex:i];
            block(curObj, i, &stop);
        }
    }
}

- (void)getObjects:(id*)objects range:(NSRange)range {
    unsigned count = [self count];
    unsigned loc = range.location;

    if (range.location + range.length > count) {
        // NSRaiseException(NSRangeException,self,_cmd,@"range %@ beyond count %d",
        // NSStringFromRange(range),[self count]);
        assert(0);
    }

    for (unsigned i = 0; i < range.length; i++) {
        objects[i] = [self objectAtIndex:loc + i];
    }
}

- (BOOL)isEqual:(NSObject*)other {
    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSArray class]]) {
        return NO;
    }

    return [self isEqualToArray:other];
}

- (NSArray*)allObjects {
    return self;
}

- (BOOL)isEqualToArray:(NSArray*)otherArray {
    if ([self count] != [otherArray count]) {
        return NO;
    }

    int i, count = [self count];
    for (i = 0; i < count; i++) {
        id obj1 = [self objectAtIndex:i];
        id obj2 = [otherArray objectAtIndex:i];

        if (![obj1 isEqual:obj2]) {
            return NO;
        }
    }

    return YES;
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    unsigned idx = [indexes firstIndex];
    id ret = [NSMutableArray array];
    unsigned count = [self count];

    while (idx != NSNotFound) {
        if (idx >= count) {
            EbrDebugLog("objectsAtIndexes: index > count (%d > %d), throwing exception\n", idx, count);
            [NSException raise:@"Array out of bounds" format:@""];
            return nil;
        }
        [ret addObject:[self objectAtIndex:idx]];
        idx = [indexes indexGreaterThanIndex:idx];
    }
    return ret;
}

@end

@implementation NSArrayConcrete : NSArray
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(NSUInteger)maxCount {
    DWORD count = CFArrayGetCount((CFArrayRef)self);
    if (state->state >= count) {
        return 0;
    }

    state->itemsPtr = (id*)_CFArrayGetPtr((CFArrayRef)self);
    state->state = count;
    state->mutationsPtr = (unsigned long*)self;

    return count;
}

@end
