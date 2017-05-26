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

// WindowsApplicationModelSearchCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Search.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelSearchCore.h"
#include "WindowsApplicationModelSearchCore_priv.h"

@implementation WASCSearchSuggestion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASCSearchSuggestionKind)kind {
    ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WASCSearchSuggestionKind)unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)detailText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetailText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamReference>*)image {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Image(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (NSString*)imageAlternateText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageAlternateText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WASCSearchSuggestionManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.Search.Core.SearchSuggestionManager").Get(),
                                              &out));
    return [_createRtProxy<WASCSearchSuggestionManager>(out.Get()) retain];
}

- (BOOL)searchHistoryEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchHistoryEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSearchHistoryEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchHistoryEnabled((boolean)value));
}

- (NSString*)searchHistoryContext {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchHistoryContext(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSearchHistoryContext:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchHistoryContext(nsStrToHstr(value).Get()));
}

- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetLocalContentSuggestionSettings(
        _getRtInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(settings).Get()));
}

- (void)setQuery:(NSString*)queryText {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetQuery(nsStrToHstr(queryText).Get()));
}

- (void)setQueryWithLanguage:(NSString*)queryText language:(NSString*)language {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetQueryWithLanguage(nsStrToHstr(queryText).Get(), nsStrToHstr(language).Get()));
}

- (void)setQueryWithSearchQueryLinguisticDetails:(NSString*)queryText
                                        language:(NSString*)language
                               linguisticDetails:(WASSearchQueryLinguisticDetails*)linguisticDetails {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetQueryWithSearchQueryLinguisticDetails(
        nsStrToHstr(queryText).Get(),
        nsStrToHstr(language).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>(linguisticDetails).Get()));
}

- (NSMutableArray<RTObservableCollection>* /* WASCSearchSuggestion* */)suggestions {
    ComPtr<IObservableVector<ABI::Windows::ApplicationModel::Search::Core::SearchSuggestion*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Suggestions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_WASCSearchSuggestion_create(unmarshalledReturn.Get());
}

- (void)addToHistory:(NSString*)queryText {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->AddToHistory(nsStrToHstr(queryText).Get()));
}

- (void)addToHistoryWithLanguage:(NSString*)queryText language:(NSString*)language {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->AddToHistoryWithLanguage(nsStrToHstr(queryText).Get(), nsStrToHstr(language).Get()));
}

- (void)clearHistory {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->ClearHistory());
}

- (EventRegistrationToken)addSuggestionsRequestedEvent:(void (^)(WASCSearchSuggestionManager*,
                                                                 WASCSearchSuggestionsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SuggestionsRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SuggestionsRequested(token));
}

- (EventRegistrationToken)addRequestingFocusOnKeyboardInputEvent:(void (^)(WASCSearchSuggestionManager*,
                                                                           WASCRequestingFocusOnKeyboardInputEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_RequestingFocusOnKeyboardInput(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRequestingFocusOnKeyboardInputEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RequestingFocusOnKeyboardInput(token));
}

@end

@implementation WASCSearchSuggestionsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSearchQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchQueryLinguisticDetails>(unmarshalledReturn.Get());
}

- (WASSearchSuggestionsRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchSuggestionsRequest>(unmarshalledReturn.Get());
}

@end

@implementation WASCRequestingFocusOnKeyboardInputEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

id RTProxiedObservableNSMutableArray_WASCSearchSuggestion_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter = std::make_unique<
        ObservableArrayAdapterObj<IObservableVector<ABI::Windows::ApplicationModel::Search::Core::SearchSuggestion*>,
                                  RTObservableArrayObj<ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestion*,
                                                       IVector<ABI::Windows::ApplicationModel::Search::Core::SearchSuggestion*>,
                                                       WASCSearchSuggestion,
                                                       ABI::Windows::ApplicationModel::Search::Core::SearchSuggestion*,
                                                       dummyObjCCreator,
                                                       dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}
