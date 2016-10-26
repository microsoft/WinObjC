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

// WindowsFoundationCollections.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
#define OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Foundation_Collections.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WFCPropertySet, WFCValueSet, WFCStringMap;
@protocol WFCIVectorChangedEventArgs
, WFCIPropertySet, WFCIIterable, WFCIIterator, WFCIVectorView, WFCIVector, WFCIKeyValuePair, WFCIMap, WFCIMapView, WFCIObservableVector,
    WFCIMapChangedEventArgs, WFCIObservableMap;

// Windows.Foundation.Collections.CollectionChange
enum _WFCCollectionChange {
    WFCCollectionChangeReset = 0,
    WFCCollectionChangeItemInserted = 1,
    WFCCollectionChangeItemRemoved = 2,
    WFCCollectionChangeItemChanged = 3,
};
typedef unsigned WFCCollectionChange;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Could not generate delegate: Can't marshal 0
// Could not generate delegate: Can't marshal 0
// Windows.Foundation.Collections.IVectorChangedEventArgs
#ifndef __WFCIVectorChangedEventArgs_DEFINED__
#define __WFCIVectorChangedEventArgs_DEFINED__

@protocol WFCIVectorChangedEventArgs
@property (readonly) WFCCollectionChange collectionChange;
@property (readonly) unsigned int index;
@end

OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
@interface WFCIVectorChangedEventArgs : RTObject <WFCIVectorChangedEventArgs>
@end

#endif // __WFCIVectorChangedEventArgs_DEFINED__

// Windows.Foundation.Collections.IPropertySet
#ifndef __WFCIPropertySet_DEFINED__
#define __WFCIPropertySet_DEFINED__

@protocol WFCIPropertySet
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
@end

OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
@interface WFCIPropertySet : RTObject <WFCIPropertySet>
@end

#endif // __WFCIPropertySet_DEFINED__

// Windows.Foundation.Collections.PropertySet
#ifndef __WFCPropertySet_DEFINED__
#define __WFCPropertySet_DEFINED__

OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
@interface WFCPropertySet : RTObject <WFCIPropertySet>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
@end

#endif // __WFCPropertySet_DEFINED__

// Windows.Foundation.Collections.ValueSet
#ifndef __WFCValueSet_DEFINED__
#define __WFCValueSet_DEFINED__

OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
@interface WFCValueSet : RTObject <WFCIPropertySet>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,System.Object>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
- (EventRegistrationToken)addObserver:(RTCollectionListener)receiver;
- (void)removeObserver:(EventRegistrationToken)receiverToken;
@end

#endif // __WFCValueSet_DEFINED__

// Windows.Foundation.Collections.StringMap
#ifndef __WFCStringMap_DEFINED__
#define __WFCStringMap_DEFINED__

OBJCUWP_WINDOWS_FOUNDATION_COLLECTIONS_EXPORT
@interface WFCStringMap : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,String>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
@end

#endif // __WFCStringMap_DEFINED__
