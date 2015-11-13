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

// WindowsApplicationModelSearch.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WASSearchPaneQueryLinguisticDetails, WASSearchPaneVisibilityChangedEventArgs, WASSearchPaneQueryChangedEventArgs,
    WASSearchPaneQuerySubmittedEventArgs, WASSearchPaneResultSuggestionChosenEventArgs, WASSearchSuggestionCollection,
    WASSearchPaneSuggestionsRequestDeferral, WASSearchPaneSuggestionsRequest, WASSearchPaneSuggestionsRequestedEventArgs,
    WASLocalContentSuggestionSettings, WASSearchPane, WASSearchQueryLinguisticDetails, WASSearchSuggestionsRequestDeferral,
    WASSearchSuggestionsRequest;
@protocol WASISearchPaneQueryLinguisticDetails
, WASISearchPaneVisibilityChangedEventArgs, WASISearchPaneQueryChangedEventArgs, WASISearchPaneQuerySubmittedEventArgs,
    WASISearchPaneQuerySubmittedEventArgsWithLinguisticDetails, WASISearchPaneResultSuggestionChosenEventArgs,
    WASISearchSuggestionCollection, WASISearchPaneSuggestionsRequestDeferral, WASISearchPaneSuggestionsRequest,
    WASISearchPaneSuggestionsRequestedEventArgs, WASILocalContentSuggestionSettings, WASISearchPaneStatics,
    WASISearchPaneStaticsWithHideThisApplication, WASISearchPane, WASISearchQueryLinguisticDetailsFactory, WASISearchQueryLinguisticDetails,
    WASISearchSuggestionsRequestDeferral, WASISearchSuggestionsRequest;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsFoundation.h"

// Windows.ApplicationModel.Search.ISearchPaneQueryChangedEventArgs
#ifndef __WASISearchPaneQueryChangedEventArgs_DEFINED__
#define __WASISearchPaneQueryChangedEventArgs_DEFINED__

@protocol WASISearchPaneQueryChangedEventArgs
@property (readonly) NSString* language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@end

#endif // __WASISearchPaneQueryChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails
#ifndef __WASSearchPaneQueryLinguisticDetails_DEFINED__
#define __WASSearchPaneQueryLinguisticDetails_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneQueryLinguisticDetails : RTObject
@property (readonly) id<NSFastEnumeration> /*String*/ queryTextAlternatives;
@property (readonly) unsigned queryTextCompositionLength;
@property (readonly) unsigned queryTextCompositionStart;
@end

#endif // __WASSearchPaneQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneVisibilityChangedEventArgs
#ifndef __WASSearchPaneVisibilityChangedEventArgs_DEFINED__
#define __WASSearchPaneVisibilityChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneVisibilityChangedEventArgs : RTObject
@property (readonly) BOOL visible;
@end

#endif // __WASSearchPaneVisibilityChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQueryChangedEventArgs
#ifndef __WASSearchPaneQueryChangedEventArgs_DEFINED__
#define __WASSearchPaneQueryChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneQueryChangedEventArgs : RTObject <WASISearchPaneQueryChangedEventArgs>
@property (readonly) NSString* language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@end

#endif // __WASSearchPaneQueryChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneQuerySubmittedEventArgs
#ifndef __WASSearchPaneQuerySubmittedEventArgs_DEFINED__
#define __WASSearchPaneQuerySubmittedEventArgs_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneQuerySubmittedEventArgs : RTObject
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@end

#endif // __WASSearchPaneQuerySubmittedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneResultSuggestionChosenEventArgs
#ifndef __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__
#define __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneResultSuggestionChosenEventArgs : RTObject
@property (readonly) NSString* tag;
@end

#endif // __WASSearchPaneResultSuggestionChosenEventArgs_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionCollection
#ifndef __WASSearchSuggestionCollection_DEFINED__
#define __WASSearchSuggestionCollection_DEFINED__

WINRT_EXPORT
@interface WASSearchSuggestionCollection : RTObject
@property (readonly) unsigned size;
- (void)appendQuerySuggestion:(NSString*)text;
- (void)appendQuerySuggestions:(id<NSFastEnumeration> /*String*/)suggestions;
- (void)appendResultSuggestion:(NSString*)text
                    detailText:(NSString*)detailText
                           tag:(NSString*)tag
                         image:(RTObject<WSSIRandomAccessStreamReference>*)image
            imageAlternateText:(NSString*)imageAlternateText;
- (void)appendSearchSeparator:(NSString*)label;
@end

#endif // __WASSearchSuggestionCollection_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestDeferral
#ifndef __WASSearchPaneSuggestionsRequestDeferral_DEFINED__
#define __WASSearchPaneSuggestionsRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneSuggestionsRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WASSearchPaneSuggestionsRequestDeferral_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequest
#ifndef __WASSearchPaneSuggestionsRequest_DEFINED__
#define __WASSearchPaneSuggestionsRequest_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneSuggestionsRequest : RTObject
@property (readonly) BOOL isCanceled;
@property (readonly) WASSearchSuggestionCollection* searchSuggestionCollection;
- (WASSearchPaneSuggestionsRequestDeferral*)getDeferral;
@end

#endif // __WASSearchPaneSuggestionsRequest_DEFINED__

// Windows.ApplicationModel.Search.SearchPaneSuggestionsRequestedEventArgs
#ifndef __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__
#define __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneSuggestionsRequestedEventArgs : RTObject <WASISearchPaneQueryChangedEventArgs>
@property (readonly) WASSearchPaneSuggestionsRequest* request;
@property (readonly) NSString* language;
@property (readonly) WASSearchPaneQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@end

#endif // __WASSearchPaneSuggestionsRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.LocalContentSuggestionSettings
#ifndef __WASLocalContentSuggestionSettings_DEFINED__
#define __WASLocalContentSuggestionSettings_DEFINED__

WINRT_EXPORT
@interface WASLocalContentSuggestionSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL enabled;
@property (copy) NSString* aqsFilter;
@property (readonly) id<NSFastEnumeration> /*WSStorageFolder*/ locations;
@property (readonly) id<NSFastEnumeration> /*String*/ propertiesToMatch;
@end

#endif // __WASLocalContentSuggestionSettings_DEFINED__

// Windows.ApplicationModel.Search.SearchPane
#ifndef __WASSearchPane_DEFINED__
#define __WASSearchPane_DEFINED__

WINRT_EXPORT
@interface WASSearchPane : RTObject
+ (void)hideThisApplication;
+ (WASSearchPane*)getForCurrentView;
@property BOOL showOnKeyboardInput;
@property BOOL searchHistoryEnabled;
@property (copy) NSString* searchHistoryContext;
@property (copy) NSString* placeholderText;
@property (readonly) NSString* language;
@property (readonly) NSString* queryText;
@property (readonly) BOOL visible;
- (EventRegistrationToken)addQueryChangedEvent:(void (^)(WASSearchPane*, WASSearchPaneQueryChangedEventArgs*))del;
- (void)removeQueryChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuerySubmittedEvent:(void (^)(WASSearchPane*, WASSearchPaneQuerySubmittedEventArgs*))del;
- (void)removeQuerySubmittedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResultSuggestionChosenEvent:(void (^)(WASSearchPane*, WASSearchPaneResultSuggestionChosenEventArgs*))del;
- (void)removeResultSuggestionChosenEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void (^)(WASSearchPane*, WASSearchPaneSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WASSearchPane*, WASSearchPaneVisibilityChangedEventArgs*))del;
- (void)removeVisibilityChangedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
- (void)showOverloadDefault;
- (void)showOverloadWithQuery:(NSString*)query;
- (BOOL)trySetQueryText:(NSString*)query;
@end

#endif // __WASSearchPane_DEFINED__

// Windows.ApplicationModel.Search.SearchQueryLinguisticDetails
#ifndef __WASSearchQueryLinguisticDetails_DEFINED__
#define __WASSearchQueryLinguisticDetails_DEFINED__

WINRT_EXPORT
@interface WASSearchQueryLinguisticDetails : RTObject
+ (WASSearchQueryLinguisticDetails*)createInstance:(id<NSFastEnumeration> /*String*/)queryTextAlternatives
                         queryTextCompositionStart:(unsigned)queryTextCompositionStart
                        queryTextCompositionLength:(unsigned)queryTextCompositionLength ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*String*/ queryTextAlternatives;
@property (readonly) unsigned queryTextCompositionLength;
@property (readonly) unsigned queryTextCompositionStart;
@end

#endif // __WASSearchQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequestDeferral
#ifndef __WASSearchSuggestionsRequestDeferral_DEFINED__
#define __WASSearchSuggestionsRequestDeferral_DEFINED__

WINRT_EXPORT
@interface WASSearchSuggestionsRequestDeferral : RTObject
- (void)complete;
@end

#endif // __WASSearchSuggestionsRequestDeferral_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequest
#ifndef __WASSearchSuggestionsRequest_DEFINED__
#define __WASSearchSuggestionsRequest_DEFINED__

WINRT_EXPORT
@interface WASSearchSuggestionsRequest : RTObject
@property (readonly) BOOL isCanceled;
@property (readonly) WASSearchSuggestionCollection* searchSuggestionCollection;
- (WASSearchSuggestionsRequestDeferral*)getDeferral;
@end

#endif // __WASSearchSuggestionsRequest_DEFINED__
