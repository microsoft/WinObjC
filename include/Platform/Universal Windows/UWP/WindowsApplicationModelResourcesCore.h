//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsApplicationModelResourcesCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelResourcesCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WARCResourceMap, WARCResourceContext, WARCNamedResource, WARCResourceManager, WARCResourceQualifier, WARCResourceCandidate, WARCResourceMapIterator, WARCResourceMapMapView, WARCResourceMapMapViewIterator, WARCResourceQualifierObservableMap, WARCResourceQualifierMapView, WARCResourceQualifierVectorView, WARCResourceCandidateVectorView, WARCResourceContextLanguagesVectorView;
@class WARCResourceLayoutInfo;
@protocol WARCIResourceManager, WARCIResourceManager2, WARCIResourceManagerStatics, WARCIResourceQualifier, WARCIResourceContext, WARCIResourceContextStatics, WARCIResourceContextStatics2, WARCIResourceContextStatics3, WARCIResourceCandidate, WARCIResourceCandidate2, WARCINamedResource, WARCIResourceMap;

// Windows.ApplicationModel.Resources.Core.ResourceQualifierPersistence
enum _WARCResourceQualifierPersistence {
    WARCResourceQualifierPersistenceNone = 0,
    WARCResourceQualifierPersistenceLocalMachine = 1,
};
typedef unsigned WARCResourceQualifierPersistence;

#include "WindowsStorage.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.ApplicationModel.Resources.Core.ResourceLayoutInfo
OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceLayoutInfo : NSObject
+ (instancetype)new;
@property unsigned int majorVersion;
@property unsigned int minorVersion;
@property unsigned int resourceSubtreeCount;
@property unsigned int namedResourceCount;
@property int checksum;
@end

// Windows.ApplicationModel.Resources.Core.ResourceMap
#ifndef __WARCResourceMap_DEFINED__
#define __WARCResourceMap_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceMap : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* uri;
@property (readonly) unsigned int size;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (WARCResourceCandidate*)getValue:(NSString *)resource;
- (WARCResourceCandidate*)getValueForContext:(NSString *)resource context:(WARCResourceContext*)context;
- (WARCResourceMap*)getSubtree:(NSString *)reference;
@end

#endif // __WARCResourceMap_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceContext
#ifndef __WARCResourceContext_DEFINED__
#define __WARCResourceContext_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceContext : RTObject
+ (void)setGlobalQualifierValueWithPersistence:(NSString *)key value:(NSString *)value persistence:(WARCResourceQualifierPersistence)persistence;
+ (WARCResourceContext*)getForCurrentView;
+ (void)setGlobalQualifierValue:(NSString *)key value:(NSString *)value;
+ (void)resetGlobalQualifierValues;
+ (void)resetGlobalQualifierValuesForSpecifiedQualifiers:(id<NSFastEnumeration> /* NSString * */)qualifierNames;
+ (WARCResourceContext*)getForViewIndependentUse;
+ (WARCResourceContext*)createMatchingContext:(id<NSFastEnumeration> /* WARCResourceQualifier* */)result;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSArray* /* NSString * */ languages;
@property (readonly) NSMutableDictionary<RTObservableCollection>* /* NSString *, NSString * */ qualifierValues;
- (void)reset;
- (void)resetQualifierValues:(id<NSFastEnumeration> /* NSString * */)qualifierNames;
- (void)overrideToMatch:(id<NSFastEnumeration> /* WARCResourceQualifier* */)result;
- (WARCResourceContext*)clone;
@end

#endif // __WARCResourceContext_DEFINED__

// Windows.ApplicationModel.Resources.Core.NamedResource
#ifndef __WARCNamedResource_DEFINED__
#define __WARCNamedResource_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCNamedResource : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WARCResourceCandidate* */ candidates;
@property (readonly) WFUri* uri;
- (WARCResourceCandidate*)resolve;
- (WARCResourceCandidate*)resolveForContext:(WARCResourceContext*)resourceContext;
- (NSArray* /* WARCResourceCandidate* */)resolveAll;
- (NSArray* /* WARCResourceCandidate* */)resolveAllForContext:(WARCResourceContext*)resourceContext;
@end

#endif // __WARCNamedResource_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceManager
#ifndef __WARCResourceManager_DEFINED__
#define __WARCResourceManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceManager : RTObject
+ (BOOL)isResourceReference:(NSString *)resourceReference;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSDictionary* /* NSString *, WARCResourceMap* */ allResourceMaps;
@property (readonly) WARCResourceContext* defaultContext;
@property (readonly) WARCResourceMap* mainResourceMap;
+ (WARCResourceManager*)current;
- (void)loadPriFiles:(id<NSFastEnumeration> /* RTObject<WSIStorageFile>* */)files;
- (void)unloadPriFiles:(id<NSFastEnumeration> /* RTObject<WSIStorageFile>* */)files;
- (NSArray* /* WARCNamedResource* */)getAllNamedResourcesForPackage:(NSString *)packageName resourceLayoutInfo:(WARCResourceLayoutInfo*)resourceLayoutInfo;
- (NSArray* /* WARCResourceMap* */)getAllSubtreesForPackage:(NSString *)packageName resourceLayoutInfo:(WARCResourceLayoutInfo*)resourceLayoutInfo;
@end

#endif // __WARCResourceManager_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifier
#ifndef __WARCResourceQualifier_DEFINED__
#define __WARCResourceQualifier_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceQualifier : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isDefault;
@property (readonly) BOOL isMatch;
@property (readonly) NSString * qualifierName;
@property (readonly) NSString * qualifierValue;
@property (readonly) double score;
@end

#endif // __WARCResourceQualifier_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceCandidate
#ifndef __WARCResourceCandidate_DEFINED__
#define __WARCResourceCandidate_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceCandidate : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isDefault;
@property (readonly) BOOL isMatch;
@property (readonly) BOOL isMatchAsDefault;
@property (readonly) NSArray* /* WARCResourceQualifier* */ qualifiers;
@property (readonly) NSString * valueAsString;
- (void)getValueAsFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (NSString *)getQualifierValue:(NSString *)qualifierName;
- (void)getValueAsStreamAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WARCResourceCandidate_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapIterator
#ifndef __WARCResourceMapIterator_DEFINED__
#define __WARCResourceMapIterator_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceMapIterator : RTObject
 // Failed to get type for default interface: Can't marshal Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>>
@property (readonly) RTKeyValuePair* /* NSString *, WARCNamedResource* */ current;
@property (readonly) BOOL hasCurrent;
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>> type information
@end

#endif // __WARCResourceMapIterator_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapMapView
#ifndef __WARCResourceMapMapView_DEFINED__
#define __WARCResourceMapMapView_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceMapMapView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

@end

#endif // __WARCResourceMapMapView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapMapViewIterator
#ifndef __WARCResourceMapMapViewIterator_DEFINED__
#define __WARCResourceMapMapViewIterator_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceMapMapViewIterator : RTObject
 // Failed to get type for default interface: Can't marshal Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>>
@property (readonly) RTKeyValuePair* /* NSString *, WARCResourceMap* */ current;
@property (readonly) BOOL hasCurrent;
// Could not find base class Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>> type information
@end

#endif // __WARCResourceMapMapViewIterator_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierObservableMap
#ifndef __WARCResourceQualifierObservableMap_DEFINED__
#define __WARCResourceQualifierObservableMap_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceQualifierObservableMap : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,String>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

-(void)setObject: (id)obj forKey: (id)key;
-(void)setObject:(id)object forKeyedSubscript:(id)key;
-(void)removeObjectForKey: (id)key;
-(void)removeAllObjects;
-(void)removeObjectsForKeys:(NSArray*)keys;
-(void)addEntriesFromDictionary:(NSDictionary*)otherDict;
-(void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
-(void)setDictionary: (NSDictionary*)dict;
-(EventRegistrationToken)addObserver: (RTCollectionListener)receiver;
-(void)removeObserver: (EventRegistrationToken)receiverToken;
@end

#endif // __WARCResourceQualifierObservableMap_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierMapView
#ifndef __WARCResourceQualifierMapView_DEFINED__
#define __WARCResourceQualifierMapView_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceQualifierMapView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (id)objectForKey: (id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject: (id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

@end

#endif // __WARCResourceQualifierMapView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierVectorView
#ifndef __WARCResourceQualifierVectorView_DEFINED__
#define __WARCResourceQualifierVectorView_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceQualifierVectorView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WARCResourceQualifierVectorView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceCandidateVectorView
#ifndef __WARCResourceCandidateVectorView_DEFINED__
#define __WARCResourceCandidateVectorView_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceCandidateVectorView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WARCResourceCandidateVectorView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceContextLanguagesVectorView
#ifndef __WARCResourceContextLanguagesVectorView_DEFINED__
#define __WARCResourceContextLanguagesVectorView_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELRESOURCESCOREEXPORT
@interface WARCResourceContextLanguagesVectorView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

@end

#endif // __WARCResourceContextLanguagesVectorView_DEFINED__

