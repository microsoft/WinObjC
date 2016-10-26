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

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_Search.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASSearchPaneQueryLinguisticDetails, WASSearchSuggestionCollection, WASLocalContentSuggestionSettings,
    WASSearchQueryLinguisticDetails, WASSearchSuggestionsRequestDeferral, WASSearchSuggestionsRequest;
@protocol WASISearchPaneQueryLinguisticDetails
, WASISearchSuggestionCollection, WASILocalContentSuggestionSettings, WASISearchQueryLinguisticDetailsFactory,
    WASISearchQueryLinguisticDetails, WASISearchSuggestionsRequestDeferral, WASISearchSuggestionsRequest;

#include "WindowsStorageStreams.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Search.SearchPaneQueryLinguisticDetails
#ifndef __WASSearchPaneQueryLinguisticDetails_DEFINED__
#define __WASSearchPaneQueryLinguisticDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASSearchPaneQueryLinguisticDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* NSString * */ queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
@end

#endif // __WASSearchPaneQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionCollection
#ifndef __WASSearchSuggestionCollection_DEFINED__
#define __WASSearchSuggestionCollection_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASSearchSuggestionCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
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

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASLocalContentSuggestionSettings : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property BOOL enabled;
@property (retain) NSString* aqsFilter;
@property (readonly) NSMutableArray* /* WSStorageFolder* */ locations;
@property (readonly) NSMutableArray* /* NSString * */ propertiesToMatch;
@end

#endif // __WASLocalContentSuggestionSettings_DEFINED__

// Windows.ApplicationModel.Search.SearchQueryLinguisticDetails
#ifndef __WASSearchQueryLinguisticDetails_DEFINED__
#define __WASSearchQueryLinguisticDetails_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASSearchQueryLinguisticDetails : RTObject
+ (WASSearchQueryLinguisticDetails*)makeInstance:(id<NSFastEnumeration> /* NSString * */)queryTextAlternatives
                       queryTextCompositionStart:(unsigned int)queryTextCompositionStart
                      queryTextCompositionLength:(unsigned int)queryTextCompositionLength ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* NSString * */ queryTextAlternatives;
@property (readonly) unsigned int queryTextCompositionLength;
@property (readonly) unsigned int queryTextCompositionStart;
@end

#endif // __WASSearchQueryLinguisticDetails_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequestDeferral
#ifndef __WASSearchSuggestionsRequestDeferral_DEFINED__
#define __WASSearchSuggestionsRequestDeferral_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASSearchSuggestionsRequestDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)complete;
@end

#endif // __WASSearchSuggestionsRequestDeferral_DEFINED__

// Windows.ApplicationModel.Search.SearchSuggestionsRequest
#ifndef __WASSearchSuggestionsRequest_DEFINED__
#define __WASSearchSuggestionsRequest_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_SEARCH_EXPORT
@interface WASSearchSuggestionsRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) BOOL isCanceled;
@property (readonly) WASSearchSuggestionCollection* searchSuggestionCollection;
- (WASSearchSuggestionsRequestDeferral*)getDeferral;
@end

#endif // __WASSearchSuggestionsRequest_DEFINED__
