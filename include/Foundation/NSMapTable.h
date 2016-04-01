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
#import <Foundation/NSFastEnumeration.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSPointerFunctions.h>

@class NSPointerFunctions;
@class NSEnumerator;
@class NSDictionary;

typedef NS_OPTIONS(NSUInteger, NSMapTableOptions) {
    NSMapTableStrongMemory = 0,
    NSMapTableCopyIn = NSPointerFunctionsCopyIn,
    NSMapTableObjectPointerPersonality = NSPointerFunctionsObjectPointerPersonality,
    NSMapTableWeakMemory = NSPointerFunctionsWeakMemory
};

FOUNDATION_EXPORT_CLASS
@interface NSMapTable : NSObject <NSCoding, NSCopying, NSFastEnumeration>

- (instancetype)initWithKeyOptions:(NSPointerFunctionsOptions)keys
                      valueOptions:(NSPointerFunctionsOptions)values
                          capacity:(NSUInteger)capacity;
+ (NSMapTable*)mapTableWithKeyOptions:(NSPointerFunctionsOptions)keyOptions valueOptions:(NSPointerFunctionsOptions)valueOptions;
- (instancetype)initWithKeyPointerFunctions:(NSPointerFunctions*)keyFunctions
                      valuePointerFunctions:(NSPointerFunctions*)valueFunctions
                                   capacity:(NSUInteger)initialCapacity;
+ (NSMapTable*)strongToStrongObjectsMapTable;
+ (NSMapTable*)weakToStrongObjectsMapTable;
+ (NSMapTable*)strongToWeakObjectsMapTable;
+ (NSMapTable*)weakToWeakObjectsMapTable;

- (id)objectForKey:(id)aKey;
- (NSEnumerator*)keyEnumerator;
- (NSEnumerator*)objectEnumerator;

- (void)setObject:(id)anObject forKey:(id)aKey;
- (void)removeObjectForKey:(id)aKey;
- (void)removeAllObjects;

- (NSDictionary*)dictionaryRepresentation;

@property (readonly) NSUInteger count;
@property (readonly, copy) NSPointerFunctions* keyPointerFunctions;
@property (readonly, copy) NSPointerFunctions* valuePointerFunctions;

@end
