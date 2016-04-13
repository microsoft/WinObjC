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

#import "Starboard.h"
#import "StubReturn.h"
#import "../CoreFoundationAdditions/CFDictionaryInternal.h"
#import "NSEnumeratorInternal.h"
#import "CoreFoundation/CFDictionary.h"
#import "Foundation/NSMutableDictionary.h"
#import "Foundation/NSString.h"
#import "Foundation/NSData.h"
#import "Foundation/NSEnumerator.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSKeyedArchiver.h"
#import "LoggingNative.h"
#import "NSPropertyListWriter_binary.h"
#import "NSKeyedArchiverInternal.h"

static const wchar_t* TAG = L"NSDictionary";

@class NSPropertyListReader;
@class NSPropertyListSerialization;

struct SortedKeysHelperCtx {
    id dict;
    SEL sel;
    id comparator;
};

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

@implementation NSDictionary

/**
 @Status Interoperable
*/
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString*)key {
    // This class uses setObject:forKey: as a setter, and has no key-specific setters.
    return NO;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
+ (instancetype)dictionaryWithObjects:(id _Nonnull const[])vals forKeys:(id<NSCopying> _Nonnull const[])keys count:(NSUInteger)count {
    NSDictionary* ret = [[self alloc] initWithObjects:vals forKeys:keys count:count];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const[])vals forKeys:(id<NSCopying> _Nonnull const[])keys count:(unsigned)count {
    [self init];

    for (unsigned i = 0; i < count; i++) {
        id key = [static_cast<NSObject*>(keys[i]) copy];
        CFDictionarySetValue((CFMutableDictionaryRef)self, (const void*)key, (void*)vals[i]);
        [key release];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)_initWithObjectsTakeOwnership:(id*)vals forKeys:(id*)keys count:(unsigned)count {
    [self init];

    for (unsigned i = 0; i < count; i++) {
        id key = [keys[i] copy];
        CFDictionarySetValueUnretained((CFMutableDictionaryRef)self, (const void*)key, (void*)vals[i]);
        [key release];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)dictionaryWithObject:(id)val forKey:(id)key {
    NSDictionary* ret = [self new];

    key = [key copy];
    CFDictionarySetValue((CFMutableDictionaryRef)ret, (const void*)key, (void*)val);
    [key release];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dictionaryWithDictionary:(NSDictionary*)dictionary {
    NSDictionary* ret = [self alloc];
    [ret initWithDictionary:dictionary];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)dictionaryWithObjects:(NSArray*)vals forKeys:(NSArray*)keys {
    return [[[self alloc] initWithObjects:vals forKeys:keys] autorelease];
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)coder {
    NSArray* keys = [coder decodeObjectOfClasses:coder.allowedClasses forKey:@"NS.keys"];
    NSArray* values = [coder decodeObjectOfClasses:coder.allowedClasses forKey:@"NS.objects"];

    [self initWithObjects:values forKeys:keys];

    return self;
}

/**
 @Status Interoperable
*/
- (id)objectForKey:(id)key {
    if (key == nil) {
        TraceWarning(TAG, L"Warning: objectForKey called with nil");
        return nil;
    }

    return (id)CFDictionaryGetValue((CFDictionaryRef)self, (const void*)key);
}

/**
 @Status Interoperable
*/
- (id)objectForKeyedSubscript:(id)key {
    return [self objectForKey:key];
}

/**
 @Status Interoperable
*/
- (id)valueForKey:(id)key {
    const char* keyName = (const char*)[key UTF8String];

    if (keyName[0] == '@') {
        assert(0);
    }

    id ret = [self objectForKey:key];

    return ret;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDictionary:(NSDictionary*)dictionary {
    if (dictionary != nil) {
        if ((object_getClass(dictionary) == [NSDictionary class] || object_getClass(dictionary) == [NSMutableDictionary class]) &&
            (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class])) {
            _CFDictionaryCopyInternal((CFDictionaryRef)self, (CFDictionaryRef)dictionary);
        } else {
            unsigned numPairs = [dictionary count];

            id* keys = (id*)IwCalloc(numPairs, sizeof(id));
            id* vals = (id*)IwCalloc(numPairs, sizeof(id));

            CFDictionaryGetKeysAndValues((CFDictionaryRef)dictionary, (const void**)keys, (const void**)vals);

            [self initWithObjects:vals forKeys:keys count:numPairs];

            IwFree(keys);
            IwFree(vals);
        }
    } else {
        self = [self init];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)initWithDictionary:(NSDictionary*)dictionary copyItems:(BOOL)copyItems {
    NSUInteger count = [dictionary count];

    id* keys = (id*)IwCalloc(count, sizeof(id));
    id* vals = (id*)IwCalloc(count, sizeof(id));
    unsigned numPairs = 0;

    NSEnumerator* enumerator = [dictionary keyEnumerator];
    id curKey = [enumerator nextObject];

    while (curKey != nil) {
        id curObj = [dictionary objectForKey:curKey];

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

    IwFree(keys);
    IwFree(vals);

    return self;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)initWithContentsOfFile:(NSString*)filename {
    if (filename == nil) {
        TraceVerbose(TAG, L"initWithContentsOfFile: nil!");
        [self release];
        return nil;
    }

    const char* file = (const char*)[filename UTF8String];
    id data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];

    NSDictionary* deserializedDict = nil;
    if (data) {
        deserializedDict = [NSPropertyListSerialization
            propertyListFromData:data
                mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]] ? NSPropertyListMutableContainersAndLeaves :
                                                                                    NSPropertyListImmutable
                          format:0
                errorDescription:0];
    }

    if (deserializedDict && [deserializedDict isKindOfClass:[NSDictionary class]]) {
        //  Steal its dictionary
        return [self initWithDictionary:deserializedDict];
    } else {
        TraceError(TAG, L"Error deserializing NSDictionary");
        [self release];
        return nil;
    }
    return self;
}

/**
 @Status Interoperable
*/
+ (NSDictionary*)dictionaryWithContentsOfFile:(NSString*)filename {
    return [[[self alloc] initWithContentsOfFile:filename] autorelease];
}

/**
 @Status Caveat
 @Notes Only file:// URLs supported
*/
+ (NSDictionary*)dictionaryWithContentsOfURL:(NSURL*)url {
    const char* file = (char*)[[url path] UTF8String];
    NSData* data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];
    if (data == nil) {
        return nil;
    }

    return [NSPropertyListSerialization
        propertyListFromData:data
            mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]] ? NSPropertyListMutableContainersAndLeaves :
                                                                                NSPropertyListImmutable
                      format:0
            errorDescription:0];
}

/**
 @Status Caveat
 @Notes Only file:// URLs supported
*/
- (NSDictionary*)initWithContentsOfURL:(id)url {
    const char* file = (char*)[[url path] UTF8String];
    NSData* data = [NSData dataWithContentsOfFile:[NSString stringWithCString:file]];

    NSDictionary* dictionary = nil;
    if (data) {
        dictionary = [NSPropertyListSerialization
            propertyListFromData:data
                mutabilityOption:[self isKindOfClass:[NSMutableDictionary class]] ? NSPropertyListMutableContainersAndLeaves :
                                                                                    NSPropertyListImmutable
                          format:0
                errorDescription:0];
    }

    return [self initWithDictionary:dictionary];
}

/**
 @Status Interoperable
*/
+ (NSDictionary*)dictionary {
    NSDictionary* ret = [NSDictionary new];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)init {
    _CFDictionaryInitInternal((CFDictionaryRef)self);

    return self;
}

/**
 @Status Interoperable
*/
- (NSArray*)allValues {
    if (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class]) {
        int count = CFDictionaryGetCount((CFDictionaryRef)self);

        if (count == 0) {
            return [NSArray array];
        }

        id* values = (id*)IwCalloc(count, sizeof(id));
        CFDictionaryGetKeysAndValues((CFDictionaryRef)self, NULL, (const void**)values);

        NSArray* ret = [NSArray arrayWithObjects:values count:count];
        IwFree(values);

        return ret;
    } else {
        unsigned count = [self count];

        if (count == 0) {
            return [NSArray array];
        }

        id* values = (id*)IwCalloc(count, sizeof(id));
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
        IwFree(values);

        return ret;
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)allKeys {
    if (object_getClass(self) == [NSDictionary class] || object_getClass(self) == [NSMutableDictionary class]) {
        unsigned count = CFDictionaryGetCount((CFDictionaryRef)self);

        if (count == 0) {
            return [NSArray array];
        }

        id* keys = (id*)IwCalloc(count, sizeof(id));
        CFDictionaryGetKeysAndValues((CFDictionaryRef)self, (const void**)keys, NULL);

        NSArray* ret = [NSArray arrayWithObjects:keys count:count];
        IwFree(keys);

        return ret;
    } else {
        unsigned count = [self count];

        if (count == 0) {
            return [NSArray array];
        }

        id* keys = (id*)IwCalloc(count, sizeof(id));
        id state = [self keyEnumerator];
        id key;
        int i;

        for (i = 0; (key = [state nextObject]) != nil; i++) {
            assert(i < count);
            keys[i] = key;
        }
        assert(i == count);

        NSArray* ret = [NSArray arrayWithObjects:keys count:count];
        IwFree(keys);

        return ret;
    }
}

/**
 @Status Interoperable
*/
- (NSArray*)allKeysForObject:(id)obj {
    NSEnumerator* keyEnum = [self keyEnumerator];
    NSEnumerator* valEnum = [self objectEnumerator];

    //  Grab all keys and toss 'em into an array if isEqual returns true
    unsigned numKeys = [self count];
    id* values = (id*)IwCalloc(numKeys, sizeof(id));
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
    IwFree(values);

    return ret;
}

/**
 @Status Interoperable
*/
- (NSUInteger)count {
    return CFDictionaryGetCount((CFDictionaryRef)self);
}

/**
 @Status Interoperable
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id*)stackBuf count:(unsigned)maxCount {
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

/**
 @Status Caveat
 @Notes atomically parameter not supported
*/
- (BOOL)writeToFile:(NSString*)file atomically:(BOOL)atomically {
    TraceVerbose(TAG, L"Writing dictionary to file %hs", [file UTF8String]);

    NSMutableData* data = [NSMutableData data];
    [NSPropertyListWriter_Binary serializePropertyList:self intoData:data];
    return [data writeToFile:file atomically:atomically];
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    return [NSEnumerator enumeratorWithIterator:(initIteratorFunc)CFDictionaryGetValueEnumerator
                                      forObject:self
                                   nextFunction:(nextValueFunc)CFDictionaryGetNextValue];
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)keyEnumerator {
    return [NSEnumerator enumeratorWithIterator:(initIteratorFunc)CFDictionaryGetKeyEnumerator
                                      forObject:self
                                   nextFunction:(nextValueFunc)CFDictionaryGetNextKey];
}

/* NSFileManager category helpers */

/**
 @Status Interoperable
*/
- (uint64_t)fileSize {
    __int64 ret = [[self objectForKey:NSFileSize] intValue];

    return ret;
}

/**
 @Status Interoperable
*/
- (NSString*)fileType {
    return [self objectForKey:NSFileType];
}

/**
 @Status Interoperable
*/
- (NSDate*)fileModificationDate {
    return [self objectForKey:NSFileModificationDate];
}

/**
 @Status Interoperable
*/
- (NSDate*)fileCreationDate {
    return [self objectForKey:NSFileCreationDate];
}

/**
 @Status Interoperable
*/
- (Class)classForCoder {
    return [NSDictionary class];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    if ([coder isKindOfClass:[NSKeyedArchiver class]]) {
        [static_cast<NSKeyedArchiver*>(coder) _encodeArrayOfObjects:[self allKeys] forKey:@"NS.keys"];
        [static_cast<NSKeyedArchiver*>(coder) _encodeArrayOfObjects:[self allValues] forKey:@"NS.objects"];
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

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (dict != NULL) {
        CFDictionaryRemoveAllValues((CFMutableDictionaryRef)self);
        _CFDictionaryDestroyInternal((CFDictionaryRef)self);
    }

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (NSMutableDictionary*)mutableCopyWithZone:(NSZone*)zone {
    return [[NSMutableDictionary alloc] initWithDictionary:self];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSDictionary class]]) {
        return NO;
    }

    return [self isEqualToDictionary:other];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToDictionary:(NSDictionary*)dictionary {
    id key;

    if (self == dictionary) {
        return YES;
    }

    if ([self count] != [dictionary count]) {
        return NO;
    }

    NSEnumerator* keys = [self keyEnumerator];
    while ((key = [keys nextObject]) != nil) {
        id value = [self objectForKey:key];
        id otherValue = [dictionary objectForKey:key];

        if (otherValue == nil) {
            return NO;
        }
        if (![value isEqual:otherValue]) {
            return NO;
        }
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (NSArray*)keysSortedByValueUsingSelector:(SEL)selector {
    SortedKeysHelperCtx ctx;

    ctx.dict = self;
    ctx.sel = selector;
    ctx.comparator = 0;

    return [[self allKeys] sortedArrayUsingFunction:_NSDict_SortedKeysHelper context:&ctx];
}

/**
 @Status Stub
*/
- (NSArray*)keysSortedByValueUsingComparator:(NSComparator)comparator {
    UNIMPLEMENTED();
    SortedKeysHelperCtx ctx;

    ctx.dict = self;
    ctx.comparator = comparator;
    ctx.sel = NULL;

    return [[self allKeys] sortedArrayUsingFunction:_NSDict_SortedKeysHelper context:&ctx];
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    thread_local unsigned int indent = 0;
    NSMutableString* s = [NSMutableString new];
    [s appendString:@"{"];
    {
        ++indent;
        auto deferPop = wil::ScopeExit([]() { --indent; });
        for (id key in [self keyEnumerator]) {
            [s appendString:@"\n"];
            for (unsigned int i = 0; i < indent; ++i) {
                [s appendString:@"    "];
            }
            [s appendFormat:@"\"%@\" = %@", [key description], [[self objectForKey:key] description]];
        }
    }
    [s appendString:@"\n"];
    for (unsigned int i = 0; i < indent; ++i) {
        [s appendString:@"    "];
    }
    [s appendString:@"}"];
    return [s autorelease];
}

/**
 @Status Stub
*/
- (NSString*)stringFromQueryComponents {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (void)enumerateKeysAndObjectsUsingBlock:(void (^)(id, id, BOOL*))block {
    [self enumerateKeysAndObjectsWithOptions:0 usingBlock:block];
}

/**
   @Status Caveat
   @Notes NSEnumerationReverse not implemented.
*/
- (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)options usingBlock:(void (^)(id, id, BOOL*))block {
    if (options & NSEnumerationReverse) {
        UNIMPLEMENTED();
        return;
    }

    _enumerateWithBlock([self keyEnumerator],
                        options,
                        ^(id key, BOOL* stop) {
                            id value = [self objectForKey:key];
                            block(key, value, stop);
                        });
}

/**
 @Status Interoperable
*/
- (NSArray*)objectsForKeys:(NSArray*)keys notFoundMarker:(id)notFoundMarker {
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:[keys count]];
    NSInteger count = [keys count];

    for (id curkey in keys) {
        id object = [self objectForKey:curkey];

        if (object == nil) {
            object = notFoundMarker;
        }

        [result addObject:object];
    }

    return result;
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSSet*)keysOfEntriesPassingTest:(BOOL (^)(id, id, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSSet*)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(id, id, BOOL*))predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)writeToURL:(NSURL*)aURL atomically:(BOOL)flag {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)fileExtensionHidden {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSNumber*)fileGroupOwnerAccountID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)fileGroupOwnerAccountName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (OSType)fileHFSCreatorCode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (OSType)fileHFSTypeCode {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)fileIsAppendOnly {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)fileIsImmutable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSNumber*)fileOwnerAccountID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)fileOwnerAccountName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)filePosixPermissions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)fileSystemFileNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSInteger)fileSystemNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)descriptionWithLocale:(id)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)descriptionWithLocale:(id)locale indent:(NSUInteger)level {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (id)sharedKeySetForKeys:(NSArray*)keys {
    UNIMPLEMENTED();
    return StubReturn();
}

@end

/**
 @Status Interoperable
*/
NSDictionary* _NSDictionaryOfVariableBindings(NSString* keys, ...) {
    if (keys == nil) {
        TraceVerbose(TAG, L"Nil keys string.");
        return nil;
    }
    NSArray* keyArray = [keys componentsSeparatedByString:@", "];
    NSMutableArray* values = [[NSMutableArray new] autorelease];

    va_list va;

    va_start(va, keys);

    id value = va_arg(va, id);
    while (value != nil) {
        [values addObject:value];
        value = va_arg(va, id);
    }
    va_end(va);

    if ([values count] != [keyArray count]) {
        TraceVerbose(TAG, L"Number of keys does not match the number of objects; nil is not a valid variable\n");
        return nil;
    }

    return [NSDictionary dictionaryWithObjects:values forKeys:keyArray];
}
