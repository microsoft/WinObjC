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

// WindowsApplicationModelSearch.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelSearch.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASSearchPaneVisibilityChangedEventArgs, WASSearchPaneQueryChangedEventArgs, WASSearchPaneQuerySubmittedEventArgs, WASSearchPaneResultSuggestionChosenEventArgs, WASSearchPaneSuggestionsRequestDeferral, WASSearchPaneSuggestionsRequest, WASSearchPaneSuggestionsRequestedEventArgs, WASSearchPane, WASSearchPaneQueryLinguisticDetails, WASSearchSuggestionCollection, WASLocalContentSuggestionSettings, WASSearchQueryLinguisticDetails, WASSearchSuggestionsRequestDeferral, WASSearchSuggestionsRequest;
@protocol WASISearchPaneVisibilityChangedEventArgs, WASISearchPaneQueryChangedEventArgs, WASISearchPaneQuerySubmittedEventArgs, WASISearchPaneQuerySubmittedEventArgsWithLinguisticDetails, WASISearchPaneResultSuggestionChosenEventArgs, WASISearchPaneSuggestionsRequestDeferral, WASISearchPaneSuggestionsRequest, WASISearchPaneSuggestionsRequestedEventArgs, WASISearchPaneStatics, WASISearchPaneStaticsWithHideThisApplication, WASISearchPane, WASISearchPaneQueryLinguisticDetails, WASISearchSuggestionCollection, WASILocalContentSuggestionSettings, WASISearchQueryLinguisticDetailsFactory, WASISearchQueryLinguisticDetails, WASISearchSuggestionsRequestDeferral, WASISearchSuggestionsRequest;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Search.ISearchPaneQueryChangedEventArgs
#ifndef __WASISearchPaneQueryChangedEventArgs_DEFINED__
#define __WASISearchPaneQueryChangedEventArgs_DEFINED__

@protocol WASISearchPaneQueryChangedEventArgs
@property (readonly) NSString * language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@end

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASISearchPaneQueryChangedEventArgs : RTObject <WASISearchPaneQueryChangedEventArgs>
@end

#endif // __WASISearchPaneQueryChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneVisibilityChangedEventArgs
#ifndef __WASSearchPaneVisibilityChangedEventArgs_DEFINED__
#define __WASSearchPaneVisibilityChangedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneVisibilityChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL visible;
@end

#endif // __WASSearchPaneVisibilityChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQueryChangedEventArgs
#ifndef __WASSearchPaneQueryChangedEventArgs_DEFINED__
#define __WASSearchPaneQueryChangedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneQueryChangedEventArgs : RTObject <WASISearchPaneQueryChangedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@end

#endif // __WASSearchPaneQueryChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQuerySubmittedEventArgs
#ifndef __WASSearchPaneQuerySubmittedEventArgs_DEFINED__
#define __WASSearchPaneQuerySubmittedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneQuerySubmittedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@end

#endif // __WASSearchPaneQuerySubmittedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneResultSuggestionChosenEventArgs
#ifndef __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__
#define __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneResultSuggestionChosenEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * tag;
@end

#endif // __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestDeferral
#ifndef __WASSearchPaneSuggestionsRequestDeferral_DEFINED__
#define __WASSearchPaneSuggestionsRequestDeferral_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneSuggestionsRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WASSearchPaneSuggestionsRequestDeferral_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequest
#ifndef __WASSearchPaneSuggestionsRequest_DEFINED__
#define __WASSearchPaneSuggestionsRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneSuggestionsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isCanceled;
@property (readonly) WASSearchSuggestionCollection* searchSuggestionCollection;
- (WASSearchPaneSuggestionsRequestDeferral*)getDeferral;
@end

#endif // __WASSearchPaneSuggestionsRequest_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestedEventArgs
#ifndef __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__
#define __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneSuggestionsRequestedEventArgs : RTObject <WASISearchPaneQueryChangedEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchPaneSuggestionsRequest* request;
@end

#endif // __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPane
#ifndef __WASSearchPane_DEFINED__
#define __WASSearchPane_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPane : RTObject
+ (void)hideThisApplication;
+ (WASSearchPane*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL showOnKeyboardInput;
@property BOOL searchHistoryEnabled;
@property (retain) NSString * searchHistoryContext;
@property (retain) NSString * placeholderText;
@property (readonly) NSString * language;
@property (readonly) NSString * queryText;
@property (readonly) BOOL visible;
- (EventRegistrationToken)addQueryChangedEvent:(void(^)(WASSearchPane*, WASSearchPaneQueryChangedEventArgs*))del;
- (void)removeQueryChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuerySubmittedEvent:(void(^)(WASSearchPane*, WASSearchPaneQuerySubmittedEventArgs*))del;
- (void)removeQuerySubmittedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResultSuggestionChosenEvent:(void(^)(WASSearchPane*, WASSearchPaneResultSuggestionChosenEventArgs*))del;
- (void)removeResultSuggestionChosenEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void(^)(WASSearchPane*, WASSearchPaneSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVisibilityChangedEvent:(void(^)(WASSearchPane*, WASSearchPaneVisibilityChangedEventArgs*))del;
- (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
- (void)showOverloadDefault;
- (void)showOverloadWithQuery:(NSString *)query;
- (BOOL)trySetQueryText:(NSString *)query;
@end

#endif // __WASSearchPane_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails
#ifndef __WASSearchPaneQueryLinguisticDetails_DEFINED__
#define __WASSearchPaneQueryLinguisticDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchPaneQueryLinguisticDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
@end

#endif // __WASSearchPaneQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionCollection
#ifndef __WASSearchSuggestionCollection_DEFINED__
#define __WASSearchSuggestionCollection_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchSuggestionCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (void)appendQuerySuggestion:(NSString *)text;
- (void)appendQuerySuggestions:(id<NSFastEnumeration> /* NSString * */)suggestions;
- (void)appendResultSuggestion:(NSString *)text detailText:(NSString *)detailText tag:(NSString *)tag image:(RTObject<WSSIRandomAccessStreamReference>*)image imageAlternateText:(NSString *)imageAlternateText;
- (void)appendSearchSeparator:(NSString *)label;
@end

#endif // __WASSearchSuggestionCollection_DEFINED__

// Windows.ApplicationModel.Search.LocalContentSuggestionSettings
#ifndef __WASLocalContentSuggestionSettings_DEFINED__
#define __WASLocalContentSuggestionSettings_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASLocalContentSuggestionSettings : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL enabled;
@property (retain) NSString * aqsFilter;
@property (readonly) NSMutableArray* /* WSStorageFolder* */ locations;
@property (readonly) NSMutableArray* /* NSString * */ propertiesToMatch;
@end

#endif // __WASLocalContentSuggestionSettings_DEFINED__

// Windows.ApplicationModel.Search.SearchQueryLinguisticDetails
#ifndef __WASSearchQueryLinguisticDetails_DEFINED__
#define __WASSearchQueryLinguisticDetails_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchQueryLinguisticDetails : RTObject
+ (WASSearchQueryLinguisticDetails*)makeInstance:(id<NSFastEnumeration> /* NSString * */)queryTextAlternatives queryTextCompositionStart:(unsigned int)queryTextCompositionStart queryTextCompositionLength:(unsigned int)queryTextCompositionLength ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
@end

#endif // __WASSearchQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequestDeferral
#ifndef __WASSearchSuggestionsRequestDeferral_DEFINED__
#define __WASSearchSuggestionsRequestDeferral_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchSuggestionsRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WASSearchSuggestionsRequestDeferral_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequest
#ifndef __WASSearchSuggestionsRequest_DEFINED__
#define __WASSearchSuggestionsRequest_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHEXPORT
@interface WASSearchSuggestionsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isCanceled;
@property (readonly) WASSearchSuggestionCollection* searchSuggestionCollection;
- (WASSearchSuggestionsRequestDeferral*)getDeferral;
@end

#endif // __WASSearchSuggestionsRequest_DEFINED__

