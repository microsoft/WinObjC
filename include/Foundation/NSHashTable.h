//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSCoding.h>
#import <Foundation/NSCopying.h>
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSPointerFunctions.h>

@class NSPointerFunctions;
@class NSArray;
@class NSEnumerator;
@class NSSet;

enum {
    NSHashTableStrongMemory = 0,
    NSHashTableCopyIn = NSPointerFunctionsCopyIn,
    NSHashTableObjectPointerPersonality = NSPointerFunctionsObjectPointerPersonality,
    NSHashTableWeakMemory = NSPointerFunctionsWeakMemory
};

FOUNDATION_EXPORT_CLASS
@interface NSHashTable : NSObject <NSCoding, NSCopying, NSFastEnumeration>
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options capacity:(NSUInteger)capacity;
- (instancetype)initWithPointerFunctions:(NSPointerFunctions*)functions capacity:(NSUInteger)initialCapacity;
+ (NSHashTable*)weakObjectsHashTable;
+ (NSHashTable*)hashTableWithOptions:(NSPointerFunctionsOptions)options;
@property (readonly, copy) NSArray* allObjects;
@property (readonly, nonatomic) id anyObject;
- (BOOL)containsObject:(id)anObject;
@property (readonly) NSUInteger count;
- (id)member:(id)object;
- (NSEnumerator*)objectEnumerator;
@property (readonly, copy) NSSet* setRepresentation;
- (void)addObject:(id)object;
- (void)removeAllObjects;
- (void)removeObject:(id)object;
- (BOOL)intersectsHashTable:(NSHashTable*)other;
- (void)intersectHashTable:(NSHashTable*)other;
- (BOOL)isEqualToHashTable:(NSHashTable*)other;
- (BOOL)isSubsetOfHashTable:(NSHashTable*)other;
- (void)minusHashTable:(NSHashTable*)other;
- (void)unionHashTable:(NSHashTable*)other;
@property (readonly, copy) NSPointerFunctions* pointerFunctions;
@end

typedef struct {
    __unsafe_unretained NSHashTable* table;
    NSUInteger i;
    struct NSHashBucket* j;
} NSHashEnumerator;

typedef struct {
    NSUInteger (*hash)(NSHashTable* table, const void*);
    BOOL (*isEqual)(NSHashTable* table, const void*, const void*);
    void (*retain)(NSHashTable* table, const void*);
    void (*release)(NSHashTable* table, void*);
    NSString* (*describe)(NSHashTable* table, const void*);
} NSHashTableCallBacks;

FOUNDATION_EXPORT const NSHashTableCallBacks NSIntHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSNonOwnedPointerHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSNonRetainedObjectHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSObjectHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSOwnedObjectIdentityHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSOwnedPointerHashCallBacks;
FOUNDATION_EXPORT const NSHashTableCallBacks NSPointerToStructHashCallBacks;

FOUNDATION_EXPORT NSHashTable* NSCreateHashTable(NSHashTableCallBacks callBacks, NSUInteger capacity);
FOUNDATION_EXPORT NSHashTable* NSCreateHashTableWithZone(NSHashTableCallBacks callBacks, NSUInteger capacity, NSZone* zone);
FOUNDATION_EXPORT NSHashTable* NSCopyHashTableWithZone(NSHashTable* table, NSZone* zone);
FOUNDATION_EXPORT void NSFreeHashTable(NSHashTable* table);
FOUNDATION_EXPORT void NSResetHashTable(NSHashTable* table);
FOUNDATION_EXPORT BOOL NSCompareHashTables(NSHashTable* table1, NSHashTable* table2);
FOUNDATION_EXPORT NSUInteger NSCountHashTable(NSHashTable* table);
FOUNDATION_EXPORT void* NSHashGet(NSHashTable* table, const void* pointer);
FOUNDATION_EXPORT NSArray* NSAllHashTableObjects(NSHashTable* table);
FOUNDATION_EXPORT NSHashEnumerator NSEnumerateHashTable(NSHashTable* table);
FOUNDATION_EXPORT void* NSNextHashEnumeratorItem(NSHashEnumerator* enumerator);
FOUNDATION_EXPORT void NSHashInsert(NSHashTable* table, const void* pointer);
FOUNDATION_EXPORT void NSHashInsertKnownAbsent(NSHashTable* table, const void* pointer);
FOUNDATION_EXPORT void* NSHashInsertIfAbsent(NSHashTable* table, const void* pointer);
FOUNDATION_EXPORT void NSHashRemove(NSHashTable* table, const void* pointer);
FOUNDATION_EXPORT NSString* NSStringFromHashTable(NSHashTable* table);