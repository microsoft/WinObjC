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
#include "CoreFoundation/CFDictionary.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSString.h"
#include "Foundation/NSData.h"
#include "Foundation/NSEnumerator.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSKeyedArchiver.h"

@class NSPropertyListReader;
@class NSPropertyListSerialization;
@class NSPropertyListWriter_Binary;

struct SortedKeysHelperCtx {
    id dict;
    SEL sel;
    id comparator;
};

__declspec(dllimport) extern "C" int CFNSBlockCompare(id obj1, id obj2, id block);

static int _NSDict_SortedKeysHelper(id key1, id key2, void* context) {
    SortedKeysHelperCtx* ctx = (SortedKeysHelperCtx*)context;
    id obj1 = [ctx->dict objectForKey:key1];
    id obj2 = [ctx->dict objectForKey:key2];

    if (ctx->sel != NULL) {
        int ret = (int)[obj1 performSelector:ctx->sel withObject:obj2];
        return ret;
    } else {
        int ret = (int)CFNSBlockCompare(obj1, obj2, ctx->comparator);

        return ret;
    }
}

@implementation NSDictionary : NSObject
+ (instancetype)dictionaryWithObjectsAndKeys:(id)firstObj, ... {
    va_list pReader;
    va_start(pReader, firstObj);
    NSDictionary* ret = [self new];

    void* curVal = (void*)firstObj;

    while (curVal != NULL) {
        id curKey = va_arg(pReader, id);

        curKey = [curKey copy];
        CFDictionarySetValue((CFMutableDictionaryRef)ret, (const void*)curKey, curVal);
        [curKey release];

        curVal = (void*)va_arg(pReader, id);
    }

    va_end(pReader);

    return [ret autorelease];
}

+ (instancetype)dictionaryWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    NSDictionary* ret = [[self alloc] initWithObjects:vals forKeys:keys count:count];

    return [ret autorelease];
}

- (instancetype)initWithObjects:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    [self init];

    for (unsigned i = 0; i < count; i++) {
        id key = [keys[i] copy];
        CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)vals[i]);
        [key release];
    }

    return self;
}

- (instancetype)initWithObjectsTakeOwnership:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    [self init];

    for (unsigned i = 0; i < count; i++) {
        id key = [keys[i] copy];
        CFDictionarySetValueUnretained((CFMutableDictionaryRef)self, (const void*)key, (void*)vals[i]);
        [key release];
    }

    return self;
}

+ (instancetype)dictionaryWithObject:(id)val forKey:(id)key {
    NSDictionary* ret = [self new];

    key = [key copy];
    CFDictionarySetValue((CFMutableDictionaryRef)ret, (const void*)key, (void*)val);
    [key release];

    return [ret autorelease];
}

+ (instancetype)dictionaryWithDictionary:(NSDictionary*)dictionary {
    NSDictionary* ret = [self alloc];
    [ret initWithDictionary:dictionary];

    return [ret autorelease];
}

+ (instancetype)dictionaryWithObjects:(NSArray*)vals forKeys:(NSArray*)keys {
    return [[[self alloc] initWithObjects:vals forKeys:keys] autorelease];
}

- (instancetype)initWithObjectsAndKeys:(id)firstObj, ... {
    va_list pReader;
    va_start(pReader, firstObj);
    [self init];

    id curVal = firstObj;

    while (curVal != NULL) {
        id curKey = va_arg(pReader, id);

        id key = [curKey copy];
        CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)curVal);
        [key release];

        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return self;
}

- (instancetype)initWithObjects:(id)vals forKeys:(id)keys {
    [self init];

    int count = [vals count];

    for (int i = 0; i < count; i++) {
        id val = [vals objectAtIndex:i];
        id key = [keys objectAtIndex:i];

        key = [key copy];
        CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)val);
        [key release];
    }

    return self;
}

- (instancetype)initWithObject:(id)val forKey:(id)key {
    [self init];

    key = [key copy];
    CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)val);
    [key release];

    return self;
}

- (id)initWithCoder:(id)coder {
    NSArray* keys = [coder decodeObjectForKey:@"NS.keys"];
    NSArray* values = [coder decodeObjectForKey:@"NS.objects"];

    [self initWithObjects:values forKeys:keys];

    return self;
}

- (id)objectForKey:(id)key {
    if (key == nil) {
        EbrDebugLog("Warning: objectForKey called with nil\n");
        return nil;
    }

    return (id)CFDictionaryGetValue((CFDictionaryRef)self, (const void*)key);
}

- (id)objectForKeyedSubscript:(id)key {
    return [self objectForKey:key];
}

- (id)valueForKey:(id)key {
    const char* keyName = (const char*)[key UTF8String];

    if (keyName[0] == '@')
        assert(0);

    id ret = [self objectForKey:key];

    return ret;
}

- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    if (dictionary != nil) {
        if ((object_getClass(dictionary) == [NSDictionary class] ||
             object_getClass(dictionary) == [NSMutableDictionary class]) &&
            (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class])) {
            _CFDictionaryCopyInternal((CFDictionaryRef)self, (CFDictionaryRef)dictionary);
        } else {
            unsigned numPairs = [dictionary count];

            id* keys = (id*)EbrCalloc(numPairs, sizeof(id));
            id* vals = (id*)EbrCalloc(numPairs, sizeof(id));

            CFDictionaryGetKeysAndValues((CFDictionaryRef)dictionary, (const void**)keys, (const void**)vals);

            [self initWithObjects:vals forKeys:keys count:numPairs];

            EbrFree(keys);
            EbrFree(vals);
        }
    } else {
        [self init];
    }

    return self;
}

- (NSDictionary*)initWithDictionary:(NSDictionary*)dict copyItems:(BOOL)copyItems {
    unsigned count = [dict count];

    id* keys = (id*)EbrCalloc(count, sizeof(id));
    id* vals = (id*)EbrCalloc(count, sizeof(id));
    unsigned numPairs = 0;

    NSEnumerator* enumerator = [dict keyEnumerator];
    id curKey = [enumerator nextObject];

    while (curKey != nil) {
        id curObj = [dict objectForKey:curKey];

        assert(numPairs <= count);
        keys[numPairs] = curKey;

        if (copyItems) {
            vals[numPairs] = [curObj copyWithZone:nil];
        } else {
            vals[numPairs] = [curObj retain];
        }
        numPairs++;

        curKey = [enumerator nextObject];
    }

    assert(numPairs == count);

    [self initWithObjects:vals forKeys:keys count:numPairs];

    for (unsigned i = 0; i < numPairs; i++) {
        [vals[i] release];
    }

    EbrFree(keys);
    EbrFree(vals);

    return self;
}

- (NSDictionary*)initWithContentsOfFile:(NSString*)filename {
    if (filename == nil) {
        EbrDebugLog("initWithContentsOfFile: nil!\n");
        return nil;
    }

    const char* file = (const char*)[filename UTF8String];
    id data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];

    NSDictionary* deserializedDict = nil;
    if (data) {
        deserializedDict =
            [NSPropertyListSerialization propertyListFromData:data
                                             mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]]
                                                                  ? NSPropertyListMutableContainersAndLeaves
                                                                  : NSPropertyListImmutable
                                                       format:0
                                             errorDescription:0];
        if (deserializedDict == nil) {
            EbrDebugLog("Error deserializing NSDictionary\n");
            return nil;
        }
    }

    if (deserializedDict) {
        //  Steal its dictionary
        return [self initWithDictionary:deserializedDict];
    } else {
        return nil;
    }
    return self;
}

+ (NSDictionary*)dictionaryWithContentsOfFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfFile:filename] autorelease];
}

+ (NSDictionary*)dictionaryWithContentsOfURL:(NSURL*)url {
    const char* file = (char*)[[url path] UTF8String];
    NSData* data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];
    if (data == nil)
        return nil;

    return [NSPropertyListSerialization
        propertyListFromData:data
            mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]] ? NSPropertyListMutableContainersAndLeaves
                                                                              : NSPropertyListImmutable
                      format:0
            errorDescription:0];
}

- (NSDictionary*)initWithContentsOfURL:(id)url {
    const char* file = (char*)[[url path] UTF8String];
    NSData* data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];

    NSDictionary* dict = nil;
    if (data) {
        dict = [NSPropertyListSerialization propertyListFromData:data
                                                mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]]
                                                                     ? NSPropertyListMutableContainersAndLeaves
                                                                     : NSPropertyListImmutable
                                                          format:0
                                                errorDescription:0];
    }

    return [self initWithDictionary:dict];
}

+ (NSDictionary*)dictionary {
    NSDictionary* ret = [NSDictionary new];

    return [ret autorelease];
}

- (NSDictionary*)init {
    _CFDictionaryInitInternal((CFDictionaryRef)self);

    return self;
}

- (NSArray*)allValues {
    if (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class]) {
        int count = CFDictionaryGetCount((CFDictionaryRef)self);

        if (count == 0) {
            return [NSArray array];
        }

        id* values = (id*)EbrCalloc(count, sizeof(id));
        CFDictionaryGetKeysAndValues((CFDictionaryRef)self, NULL, (const void**)values);

        NSArray* ret = [NSArray arrayWithObjects:values count:count];
        EbrFree(values);

        return ret;
    } else {
        unsigned count = [self count];

        if (count == 0) {
            return [NSArray array];
        }

        id* values = (id*)EbrCalloc(count, sizeof(id));
        id state = [self keyEnumerator];
        id key;
        unsigned i;
        for (i = 0; (key = [state nextObject]) != nil; i++) {
            assert(i < count);
            id value = [self objectForKey:key];

            values[i] = value;
        }
        assert(i == count);

        NSArray* ret = [NSArray arrayWithObjects:values count:count];
        EbrFree(values);

        return ret;
    }
}

- (NSArray*)allKeys {
    if (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class]) {
        unsigned count = CFDictionaryGetCount((CFDictionaryRef)self);

        if (count == 0) {
            return [NSArray array];
        }

        id* keys = (id*)EbrCalloc(count, sizeof(id));
        CFDictionaryGetKeysAndValues((CFDictionaryRef)self, (const void**)keys, NULL);

        NSArray* ret = [NSArray arrayWithObjects:keys count:count];
        EbrFree(keys);

        return ret;
    } else {
        unsigned count = [self count];

        if (count == 0) {
            return [NSArray array];
        }

        id* keys = (id*)EbrCalloc(count, sizeof(id));
        id state = [self keyEnumerator];
        id key;
        int i;

        for (i = 0; (key = [state nextObject]) != nil; i++) {
            assert(i < count);
            keys[i] = key;
        }
        assert(i == count);

        NSArray* ret = [NSArray arrayWithObjects:keys count:count];
        EbrFree(keys);

        return ret;
    }
}

- (NSArray*)allKeysForObject:(id)obj {
    NSEnumerator* keyEnum = [self keyEnumerator];
    NSEnumerator* valEnum = [self objectEnumerator];

    //  Grab all keys and toss 'em into an array if isEqual returns true
    unsigned numKeys = [self count];
    id* values = (id*)EbrCalloc(numKeys, sizeof(id));
    unsigned numValues = 0;

    id curKey = [keyEnum nextObject];
    id curValue = [valEnum nextObject];
    while (curKey != nil) {
        assert(numValues <= numKeys);

        if ([curValue isEqual:obj] == TRUE) {
            values[numValues++] = curKey;
        }

        curKey = [keyEnum nextObject];
        curValue = [valEnum nextObject];
    }

    NSArray* ret = [NSArray arrayWithObjects:values count:numValues];
    EbrFree(values);

    return ret;
}

- (unsigned)count {
    return CFDictionaryGetCount((CFDictionaryRef)self);
}

- (unsigned)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(unsigned)maxCount {
    Class ours = [self class];

    if (ours == [NSDictionary class] || ours == [NSMutableDictionary class]) {
        if (state->state == 0) {
            state->state = 1;
            state->mutationsPtr = &state->state;
            CFDictionaryGetKeyEnumerator((CFDictionaryRef)self, state->extra);
        }
        assert(maxCount > 0);

        state->itemsPtr = stackBuf;
        return CFDictionaryGetNextKey((CFDictionaryRef)self, state->extra, stackBuf, maxCount);
    }

    if (state->state == 0) {
        state->mutationsPtr = (unsigned long*)&state->extra[1];
        state->extra[0] = (unsigned long)[self keyEnumerator];
        state->state = 1;
    }
    assert(maxCount > 0);

    NSUInteger numRet = 0;
    state->itemsPtr = stackBuf;

    while (maxCount > 0) {
        id next = [(id)state->extra[0] nextObject];
        if (next == nil)
            break;

        *stackBuf = next;
        stackBuf++;
        numRet++;
        maxCount--;
    }

    return numRet;
}

- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically {
    EbrDebugLog("Writing dictionary to file %s\n", [file UTF8String]);

    NSMutableData* data = [NSMutableData data];
    [NSPropertyListWriter_Binary serializePropertyList:self intoData:data];
    return [data writeToFile:file atomically:atomically];
}

- (NSEnumerator*)objectEnumerator {
    return [NSEnumerator enumeratorWithIterator:CFDictionaryGetValueEnumerator
                                      forObject:self
                                   nextFunction:CFDictionaryGetNextValue];
}

- (NSEnumerator*)keyEnumerator {
    return [NSEnumerator enumeratorWithIterator:CFDictionaryGetKeyEnumerator
                                      forObject:self
                                   nextFunction:CFDictionaryGetNextKey];
}

/* NSFileManager category helpers */
- (uint64_t)fileSize {
    __int64 ret = [[self objectForKey:@"NSFileSize"] intValue];

    return ret;
}

- (NSString*)fileType {
    return [self objectForKey:@"NSFileType"];
}

- (NSDate*)fileModificationDate {
    EbrDebugLog("NSDictionary::fileModificationDate not implemented\n");

    return [NSDate date];
}

- (NSDate*)fileCreationDate {
    return [self objectForKey:@"NSFileCreationDate"];
}

- (id)classForArchiver {
    return [NSDictionary class];
}

- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        [coder _encodeArrayOfObjects:[self allKeys] forKey:@"NS.keys"];
        [coder _encodeArrayOfObjects:[self allValues] forKey:@"NS.objects"];
    } else {
        NSEnumerator* state = [self keyEnumerator];
        unsigned count = [self count];

        assert(0);

        /*
        id key;
        coder)"encodeValueOfObjCType:", @encode(int) at:&count];

        while((key=[state nextObject])!=nil){
        id value=[self objectForKey:key];

        [coder encodeObject:key];
        [coder encodeObject:value];
        }
        */
    }
}

- (void)dealloc {
    if (dict != NULL) {
        CFDictionaryRemoveAllValues((CFMutableDictionaryRef)self);
        _CFDictionaryDestroyInternal((CFDictionaryRef)self);
    }

    [super dealloc];
}

- (NSMutableDictionary*)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableDictionary alloc] initWithDictionary:self];
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (BOOL)isEqual:(id)other {
    if (self == other)
        return YES;

    if (![other isKindOfClass:[NSDictionary class]])
        return NO;

    return [self isEqualToDictionary:other];
}

- (BOOL)isEqualToDictionary:(NSDictionary*)dictionary {
    id key;

    if (self == dictionary)
        return YES;

    if ([self count] != [dictionary count])
        return NO;

    NSEnumerator* keys = [self keyEnumerator];
    while ((key = [keys nextObject]) != nil) {
        id value = [self objectForKey:key];
        id otherValue = [dictionary objectForKey:key];

        if (otherValue == nil)
            return NO;
        if (![value isEqual:otherValue])
            return NO;
    }

    return YES;
}

- (NSArray*)keysSortedByValueUsingSelector:(SEL)selector {
    SortedKeysHelperCtx ctx;

    ctx.dict = self;
    ctx.sel = selector;
    ctx.comparator = 0;

    return [[self allKeys] sortedArrayUsingFunction:_NSDict_SortedKeysHelper context:&ctx];
}

- (NSArray*)keysSortedByValueUsingComparator:(NSComparator)comparator {
    SortedKeysHelperCtx ctx;

    ctx.dict = self;
    ctx.comparator = comparator;
    ctx.sel = NULL;

    return [[self allKeys] sortedArrayUsingFunction:_NSDict_SortedKeysHelper context:&ctx];
}

- (NSString*)description {
    return [[NSString alloc] initWithData:[NSPropertyListSerialization dataFromPropertyList:self
                                                                                     format:NSPropertyListXMLFormat_v1_0
                                                                           errorDescription:nil]
                                 encoding:NSUTF8StringEncoding];
}

- (NSString*)stringFromQueryComponents {
    EbrDebugLog("stringFromQueryComponents not supported\n");
    return nil;
}

- (void)getObjects:(id*)objects andKeys:(id*)keys {
    NSEnumerator* state = [self keyEnumerator];
    id key;
    NSInteger i;

    for (i = 0; (key = [state nextObject]) != nil; i++) {
        id value = [self objectForKey:key];

        objects[i] = value;
        keys[i] = key;
    }
}

- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(id, id, BOOL*))block {
    NSEnumerator* state = [self keyEnumerator];
    id key;
    NSInteger i;
    BOOL stop = FALSE;

    for (i = 0; (key = [state nextObject]) != nil; i++) {
        id value = [self objectForKey:key];

        block(key, value, &stop);
        if (stop)
            break;
    }
}

- (NSArray*)objectsForKeys:(NSArray*)keys notFoundMarker:(id)notFoundMarker {
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:[keys count]];
    NSInteger count = [keys count];

    for (id curkey in keys) {
        id object = [self objectForKey:curkey];

        if (object == nil)
            object = notFoundMarker;

        [result addObject:object];
    }

    return result;
}

@end
