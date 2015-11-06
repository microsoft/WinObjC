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
@class WASSearchPaneQueryLinguisticDetails, WASSearchSuggestionCollection, WASLocalContentSuggestionSettings,
    WASSearchQueryLinguisticDetails, WASSearchSuggestionsRequestDeferral, WASSearchSuggestionsRequest;
@protocol WASISearchPaneQueryLinguisticDetails
, WASISearchSuggestionCollection, WASILocalContentSuggestionSettings, WASISearchQueryLinguisticDetailsFactory,
    WASISearchQueryLinguisticDetails, WASISearchSuggestionsRequestDeferral, WASISearchSuggestionsRequest;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails
#ifndef __WASSearchPaneQueryLinguisticDetails_DEFINED__
#define __WASSearchPaneQueryLinguisticDetails_DEFINED__

WINRT_EXPORT
@interface WASSearchPaneQueryLinguisticDetails : RTObject
@property (readonly) NSArray* queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
@end

#endif // __WASSearchPaneQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionCollection
#ifndef __WASSearchSuggestionCollection_DEFINED__
#define __WASSearchSuggestionCollection_DEFINED__

WINRT_EXPORT
@interface WASSearchSuggestionCollection : RTObject
@property (readonly) unsigned int size;
- (void)appendQuerySuggestion:(NSString*)text;
- (void)appendQuerySuggestions:(id<NSFastEnumeration> /* NSString * */)suggestions;
- (void)appendResultSuggestion:(NSString*)text
                    detailText:(NSString*)detailText
                           tag:(NSString*)tag
                         image:(RTObject<WSSIRandomAccessStreamReference>*)image
            imageAlternateText:(NSString*)imageAlternateText;
- (void)appendSearchSeparator:(NSString*)label;
@end

#endif // __WASSearchSuggestionCollection_DEFINED__

// Windows.ApplicationModel.Search.LocalContentSuggestionSettings
#ifndef __WASLocalContentSuggestionSettings_DEFINED__
#define __WASLocalContentSuggestionSettings_DEFINED__

WINRT_EXPORT
@interface WASLocalContentSuggestionSettings : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL enabled;
@property (copy) NSString* aqsFilter;
@property (readonly) NSMutableArray* locations;
@property (readonly) NSMutableArray* propertiesToMatch;
@end

#endif // __WASLocalContentSuggestionSettings_DEFINED__

// Windows.ApplicationModel.Search.SearchQueryLinguisticDetails
#ifndef __WASSearchQueryLinguisticDetails_DEFINED__
#define __WASSearchQueryLinguisticDetails_DEFINED__

WINRT_EXPORT
@interface WASSearchQueryLinguisticDetails : RTObject
+ (WASSearchQueryLinguisticDetails*)createInstance:(id<NSFastEnumeration> /* NSString * */)queryTextAlternatives
                         queryTextCompositionStart:(unsigned int)queryTextCompositionStart
                        queryTextCompositionLength:(unsigned int)queryTextCompositionLength ACTIVATOR;
@property (readonly) NSArray* queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
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
