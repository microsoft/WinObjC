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

#include "interopBase.h"
@class WASCSearchSuggestion, WASCSearchSuggestionManager, WASCSearchSuggestionsRequestedEventArgs,
    WASCRequestingFocusOnKeyboardInputEventArgs;
@protocol WASCISearchSuggestion
, WASCISearchSuggestionsRequestedEventArgs, WASCIRequestingFocusOnKeyboardInputEventArgs, WASCISearchSuggestionManager;

// Windows.ApplicationModel.Search.Core.SearchSuggestionKind
enum _WASCSearchSuggestionKind {
    WASCSearchSuggestionKindQuery = 0,
    WASCSearchSuggestionKindResult = 1,
    WASCSearchSuggestionKindSeparator = 2,
};
typedef unsigned WASCSearchSuggestionKind;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsFoundation.h"

// Windows.ApplicationModel.Search.Core.SearchSuggestion
#ifndef __WASCSearchSuggestion_DEFINED__
#define __WASCSearchSuggestion_DEFINED__

WINRT_EXPORT
@interface WASCSearchSuggestion : RTObject
@property (readonly) NSString* detailText;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* image;
@property (readonly) NSString* imageAlternateText;
@property (readonly) WASCSearchSuggestionKind kind;
@property (readonly) NSString* tag;
@property (readonly) NSString* text;
@end

#endif // __WASCSearchSuggestion_DEFINED__

// Windows.ApplicationModel.Search.Core.SearchSuggestionManager
#ifndef __WASCSearchSuggestionManager_DEFINED__
#define __WASCSearchSuggestionManager_DEFINED__

WINRT_EXPORT
@interface WASCSearchSuggestionManager : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL searchHistoryEnabled;
@property (copy) NSString* searchHistoryContext;
// Failed to generate property Suggestions (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.ApplicationModel.Search.Core.SearchSuggestion>)
- (EventRegistrationToken)addRequestingFocusOnKeyboardInputEvent:(void (^)(WASCSearchSuggestionManager*,
                                                                           WASCRequestingFocusOnKeyboardInputEventArgs*))del;
- (void)removeRequestingFocusOnKeyboardInputEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void (^)(WASCSearchSuggestionManager*,
                                                                 WASCSearchSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
- (void)setQuery:(NSString*)queryText;
- (void)setQueryWithLanguage:(NSString*)queryText language:(NSString*)language;
- (void)setQueryWithSearchQueryLinguisticDetails:(NSString*)queryText
                                        language:(NSString*)language
                               linguisticDetails:(WASSearchQueryLinguisticDetails*)linguisticDetails;
// Failed to generate member get_Suggestions (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.ApplicationModel.Search.Core.SearchSuggestion>)
- (void)addToHistory:(NSString*)queryText;
- (void)addToHistoryWithLanguage:(NSString*)queryText language:(NSString*)language;
- (void)clearHistory;
@end

#endif // __WASCSearchSuggestionManager_DEFINED__

// Windows.ApplicationModel.Search.Core.SearchSuggestionsRequestedEventArgs
#ifndef __WASCSearchSuggestionsRequestedEventArgs_DEFINED__
#define __WASCSearchSuggestionsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WASCSearchSuggestionsRequestedEventArgs : RTObject
@property (readonly) NSString* language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@property (readonly) WASSearchSuggestionsRequest* request;
@end

#endif // __WASCSearchSuggestionsRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Search.Core.RequestingFocusOnKeyboardInputEventArgs
#ifndef __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__
#define __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__

WINRT_EXPORT
@interface WASCRequestingFocusOnKeyboardInputEventArgs : RTObject
@end

#endif // __WASCRequestingFocusOnKeyboardInputEventArgs_DEFINED__
