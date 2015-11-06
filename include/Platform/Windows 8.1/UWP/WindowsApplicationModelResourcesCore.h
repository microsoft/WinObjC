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

// WindowsApplicationModelResourcesCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WARCResourceMap, WARCResourceContext, WARCResourceManager, WARCResourceQualifier, WARCResourceCandidate, WARCNamedResource,
    WARCResourceMapIterator, WARCResourceMapMapView, WARCResourceMapMapViewIterator, WARCResourceQualifierObservableMap,
    WARCResourceQualifierMapView, WARCResourceQualifierVectorView, WARCResourceCandidateVectorView, WARCResourceContextLanguagesVectorView;
@protocol WARCIResourceManager
, WARCIResourceManagerStatics, WARCIResourceQualifier, WARCIResourceContext, WARCIResourceContextStatics, WARCIResourceContextStatics2,
    WARCIResourceCandidate, WARCINamedResource, WARCIResourceMap;

#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.ApplicationModel.Resources.Core.ResourceMap
#ifndef __WARCResourceMap_DEFINED__
#define __WARCResourceMap_DEFINED__

WINRT_EXPORT
@interface WARCResourceMap : RTObject
@property (readonly) WFUri* uri;
@property (readonly) unsigned size;
- (WARCResourceCandidate*)getValue:(NSString*)resource;
- (WARCResourceCandidate*)getValueForContext:(NSString*)resource context:(WARCResourceContext*)context;
- (WARCResourceMap*)getSubtree:(NSString*)reference;
// Could not find base class Windows.Foundation.Collections.IMapView`2<String,Windows.ApplicationModel.Resources.Core.NamedResource> type
// information
// Could not find base class Windows.Foundation.Collections.IMapView`2<String,Windows.ApplicationModel.Resources.Core.NamedResource> type
// information
@end

#endif // __WARCResourceMap_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceContext
#ifndef __WARCResourceContext_DEFINED__
#define __WARCResourceContext_DEFINED__

WINRT_EXPORT
@interface WARCResourceContext : RTObject
+ (WARCResourceContext*)getForCurrentView;
+ (void)setGlobalQualifierValue:(NSString*)key value:(NSString*)value;
+ (void)resetGlobalQualifierValues;
+ (void)resetGlobalQualifierValuesForSpecifiedQualifiers:(id<NSFastEnumeration> /*String*/)qualifierNames;
+ (WARCResourceContext*)getForViewIndependentUse;
+ (WARCResourceContext*)createMatchingContext:(id<NSFastEnumeration> /*WARCResourceQualifier*/)result;
+ (instancetype)create ACTIVATOR;
@property (copy) id<NSFastEnumeration> /*String*/ languages;
// Failed to generate property QualifierValues (Can't marshal Windows.Foundation.Collections.IObservableMap`2<String,String>)
// Failed to generate member get_QualifierValues (Can't marshal Windows.Foundation.Collections.IObservableMap`2<String,String>)
- (void)reset;
- (void)resetQualifierValues:(id<NSFastEnumeration> /*String*/)qualifierNames;
- (void)overrideToMatch:(id<NSFastEnumeration> /*WARCResourceQualifier*/)result;
- (WARCResourceContext*)clone;
@end

#endif // __WARCResourceContext_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceManager
#ifndef __WARCResourceManager_DEFINED__
#define __WARCResourceManager_DEFINED__

WINRT_EXPORT
@interface WARCResourceManager : RTObject
+ (BOOL)isResourceReference:(NSString*)resourceReference;
@property (readonly) NSDictionary* /*String, WARCResourceMap*/ allResourceMaps;
@property (readonly) WARCResourceContext* defaultContext;
@property (readonly) WARCResourceMap* mainResourceMap;
+ (WARCResourceManager*)current;
- (void)loadPriFiles:(id<NSFastEnumeration> /*WSIStorageFile*/)files;
- (void)unloadPriFiles:(id<NSFastEnumeration> /*WSIStorageFile*/)files;
@end

#endif // __WARCResourceManager_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifier
#ifndef __WARCResourceQualifier_DEFINED__
#define __WARCResourceQualifier_DEFINED__

WINRT_EXPORT
@interface WARCResourceQualifier : RTObject
@property (readonly) BOOL isDefault;
@property (readonly) BOOL isMatch;
@property (readonly) NSString* qualifierName;
@property (readonly) NSString* qualifierValue;
@property (readonly) double score;
@end

#endif // __WARCResourceQualifier_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceCandidate
#ifndef __WARCResourceCandidate_DEFINED__
#define __WARCResourceCandidate_DEFINED__

WINRT_EXPORT
@interface WARCResourceCandidate : RTObject
@property (readonly) BOOL isDefault;
@property (readonly) BOOL isMatch;
@property (readonly) BOOL isMatchAsDefault;
@property (readonly) id<NSFastEnumeration> /*WARCResourceQualifier*/ qualifiers;
@property (readonly) NSString* valueAsString;
- (void)getValueAsFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (NSString*)getQualifierValue:(NSString*)qualifierName;
@end

#endif // __WARCResourceCandidate_DEFINED__

// Windows.ApplicationModel.Resources.Core.NamedResource
#ifndef __WARCNamedResource_DEFINED__
#define __WARCNamedResource_DEFINED__

WINRT_EXPORT
@interface WARCNamedResource : RTObject
@property (readonly) id<NSFastEnumeration> /*WARCResourceCandidate*/ candidates;
@property (readonly) WFUri* uri;
- (WARCResourceCandidate*)resolve;
- (WARCResourceCandidate*)resolveForContext:(WARCResourceContext*)resourceContext;
- (id<NSFastEnumeration> /*WARCResourceCandidate*/)resolveAll;
- (id<NSFastEnumeration> /*WARCResourceCandidate*/)resolveAllForContext:(WARCResourceContext*)resourceContext;
@end

#endif // __WARCNamedResource_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapIterator
#ifndef __WARCResourceMapIterator_DEFINED__
#define __WARCResourceMapIterator_DEFINED__

WINRT_EXPORT
@interface WARCResourceMapIterator : RTObject
// Failed to generate property Current (Can't marshal
// Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>)
@property (readonly) BOOL hasCurrent;
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.NamedResource>>
// type information
@end

#endif // __WARCResourceMapIterator_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapMapView
#ifndef __WARCResourceMapMapView_DEFINED__
#define __WARCResourceMapMapView_DEFINED__

WINRT_EXPORT
@interface WARCResourceMapMapView : RTObject
@property (readonly) unsigned size;
// Could not find base class Windows.Foundation.Collections.IMapView`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap> type
// information
@end

#endif // __WARCResourceMapMapView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceMapMapViewIterator
#ifndef __WARCResourceMapMapViewIterator_DEFINED__
#define __WARCResourceMapMapViewIterator_DEFINED__

WINRT_EXPORT
@interface WARCResourceMapMapViewIterator : RTObject
// Failed to generate property Current (Can't marshal
// Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>)
@property (readonly) BOOL hasCurrent;
// Could not find base class
// Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.ApplicationModel.Resources.Core.ResourceMap>>
// type information
@end

#endif // __WARCResourceMapMapViewIterator_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierObservableMap
#ifndef __WARCResourceQualifierObservableMap_DEFINED__
#define __WARCResourceQualifierObservableMap_DEFINED__

WINRT_EXPORT
@interface WARCResourceQualifierObservableMap : RTObject
@property (readonly) unsigned size;
// Could not generate add_MapChanged (Can't marshal Windows.Foundation.Collections.MapChangedEventHandler`2<String,String>)
- (void)removeMapChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableMap`2<String,String> type information
// Could not find base class Windows.Foundation.Collections.IMap`2<String,String> type information
@end

#endif // __WARCResourceQualifierObservableMap_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierMapView
#ifndef __WARCResourceQualifierMapView_DEFINED__
#define __WARCResourceQualifierMapView_DEFINED__

WINRT_EXPORT
@interface WARCResourceQualifierMapView : RTObject
@property (readonly) unsigned size;
// Could not find base class Windows.Foundation.Collections.IMapView`2<String,String> type information
@end

#endif // __WARCResourceQualifierMapView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceQualifierVectorView
#ifndef __WARCResourceQualifierVectorView_DEFINED__
#define __WARCResourceQualifierVectorView_DEFINED__

WINRT_EXPORT
@interface WARCResourceQualifierVectorView : RTObject
@property (readonly) unsigned size;
@end

#endif // __WARCResourceQualifierVectorView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceCandidateVectorView
#ifndef __WARCResourceCandidateVectorView_DEFINED__
#define __WARCResourceCandidateVectorView_DEFINED__

WINRT_EXPORT
@interface WARCResourceCandidateVectorView : RTObject
@property (readonly) unsigned size;
@end

#endif // __WARCResourceCandidateVectorView_DEFINED__

// Windows.ApplicationModel.Resources.Core.ResourceContextLanguagesVectorView
#ifndef __WARCResourceContextLanguagesVectorView_DEFINED__
#define __WARCResourceContextLanguagesVectorView_DEFINED__

WINRT_EXPORT
@interface WARCResourceContextLanguagesVectorView : RTObject
@property (readonly) unsigned size;
@end

#endif // __WARCResourceContextLanguagesVectorView_DEFINED__
