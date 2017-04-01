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

// WindowsApplicationModelSearchCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelSearchCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WASCSearchSuggestion, WASCSearchSuggestionManager, WASCSearchSuggestionsRequestedEventArgs, WASCRequestingFocusOnKeyboardInputEventArgs;
@protocol WASCISearchSuggestion, WASCISearchSuggestionsRequestedEventArgs, WASCIRequestingFocusOnKeyboardInputEventArgs, WASCISearchSuggestionManager;

// Windows.ApplicationModel.Search.Core.SearchSuggestionKind
enum _WASCSearchSuggestionKind {
    WASCSearchSuggestionKindQuery = 0,
    WASCSearchSuggestionKindResult = 1,
    WASCSearchSuggestionKindSeparator = 2,
};
typedef unsigned WASCSearchSuggestionKind;

#include "WindowsStorageStreams.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Search.Core.SearchSuggestion
#ifndef __WASCSearchSuggestion_DEFINED__
#define __WASCSearchSuggestion_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT
@interface WASCSearchSuggestion : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * detailText;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* image;
@property (readonly) NSString * imageAlternateText;
@property (readonly) WASCSearchSuggestionKind kind;
@property (readonly) NSString * tag;
@property (readonly) NSString * text;
@end

#endif // __WASCSearchSuggestion_DEFINED__

// Windows.ApplicationModel.Search.Core.SearchSuggestionManager
#ifndef __WASCSearchSuggestionManager_DEFINED__
#define __WASCSearchSuggestionManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT
@interface WASCSearchSuggestionManager : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL searchHistoryEnabled;
@property (retain) NSString * searchHistoryContext;
@property (readonly) NSMutableArray<RTObservableCollection>* /* WASCSearchSuggestion* */ suggestions;
- (EventRegistrationToken)addRequestingFocusOnKeyboardInputEvent:(void(^)(WASCSearchSuggestionManager*, WASCRequestingFocusOnKeyboardInputEventArgs*))del;
- (void)removeRequestingFocusOnKeyboardInputEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void(^)(WASCSearchSuggestionManager*, WASCSearchSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
- (void)setQuery:(NSString *)queryText;
- (void)setQueryWithLanguage:(NSString *)queryText language:(NSString *)language;
- (void)setQueryWithSearchQueryLinguisticDetails:(NSString *)queryText language:(NSString *)language linguisticDetails:(WASSearchQueryLinguisticDetails*)linguisticDetails;
- (void)addToHistory:(NSString *)queryText;
- (void)addToHistoryWithLanguage:(NSString *)queryText language:(NSString *)language;
- (void)clearHistory;
@end

#endif // __WASCSearchSuggestionManager_DEFINED__

// Windows.ApplicationModel.Search.Core.SearchSuggestionsRequestedEventArgs
#ifndef __WASCSearchSuggestionsRequestedEventArgs_DEFINED__
#define __WASCSearchSuggestionsRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT
@interface WASCSearchSuggestionsRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchSuggestionsRequest* request;
@end

#endif // __WASCSearchSuggestionsRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.Core.RequestingFocusOnKeyboardInputEventArgs
#ifndef __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__
#define __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELSEARCHCOREEXPORT
@interface WASCRequestingFocusOnKeyboardInputEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__

