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

// WindowsApplicationModelSearch.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Search.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsApplicationModelSearch_priv.h"

@implementation WASISearchPaneQueryChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

@end

@implementation WASSearchPaneVisibilityChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WASSearchPaneQueryChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

@end

@implementation WASSearchPaneQuerySubmittedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

@end

@implementation WASSearchPaneResultSuggestionChosenEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WASSearchPaneSuggestionsRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WASSearchPaneSuggestionsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WASSearchSuggestionCollection*)searchSuggestionCollection {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchSuggestionCollection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchSuggestionCollection>(unmarshalledReturn.Get());
}

- (WASSearchPaneSuggestionsRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneSuggestionsRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WASSearchPaneSuggestionsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASSearchPaneSuggestionsRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneSuggestionsRequest>(unmarshalledReturn.Get());
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSearchPaneQueryLinguisticDetails*)linguisticDetails {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinguisticDetails(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPaneQueryLinguisticDetails>(unmarshalledReturn.Get());
}

@end

@implementation WASSearchPane

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPane> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication>
WASISearchPaneStaticsWithHideThisApplication_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Search.SearchPane").Get(), &inst));
    return inst;
}

+ (void)hideThisApplication {
    auto _comInst = WASISearchPaneStaticsWithHideThisApplication_inst();
    THROW_NS_IF_FAILED(_comInst->HideThisApplication());
}

ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStatics> WASISearchPaneStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Search.SearchPane").Get(), &inst));
    return inst;
}

+ (WASSearchPane*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPane> unmarshalledReturn;
    auto _comInst = WASISearchPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchPane>(unmarshalledReturn.Get());
}

- (void)setSearchHistoryEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchHistoryEnabled((boolean)value));
}

- (BOOL)searchHistoryEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchHistoryEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSearchHistoryContext:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->put_SearchHistoryContext(nsStrToHstr(value).Get()));
}

- (NSString*)searchHistoryContext {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchHistoryContext(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPlaceholderText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaceholderText(nsStrToHstr(value).Get()));
}

- (NSString*)placeholderText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)queryText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(WASSearchPane*, WASSearchPaneVisibilityChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_VisibilityChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisibilityChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisibilityChanged(token));
}

- (EventRegistrationToken)addQueryChangedEvent:(void (^)(WASSearchPane*, WASSearchPaneQueryChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_QueryChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeQueryChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_QueryChanged(token));
}

- (EventRegistrationToken)addSuggestionsRequestedEvent:(void (^)(WASSearchPane*, WASSearchPaneSuggestionsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_SuggestionsRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SuggestionsRequested(token));
}

- (EventRegistrationToken)addQuerySubmittedEvent:(void (^)(WASSearchPane*, WASSearchPaneQuerySubmittedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_QuerySubmitted(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeQuerySubmittedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_QuerySubmitted(token));
}

- (EventRegistrationToken)addResultSuggestionChosenEvent:(void (^)(WASSearchPane*, WASSearchPaneResultSuggestionChosenEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_ResultSuggestionChosen(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResultSuggestionChosenEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ResultSuggestionChosen(token));
}

- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->SetLocalContentSuggestionSettings(
        _getRtInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(settings).Get()));
}

- (void)showOverloadDefault {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->ShowOverloadDefault());
}

- (void)showOverloadWithQuery:(NSString*)query {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->ShowOverloadWithQuery(nsStrToHstr(query).Get()));
}

- (void)setShowOnKeyboardInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowOnKeyboardInput((boolean)value));
}

- (BOOL)showOnKeyboardInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowOnKeyboardInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)trySetQueryText:(NSString*)query {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPane>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetQueryText(nsStrToHstr(query).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WASSearchPaneQueryLinguisticDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* NSString * */)queryTextAlternatives {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextAlternatives(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)queryTextCompositionStart {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextCompositionStart(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)queryTextCompositionLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextCompositionLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WASSearchSuggestionCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)appendQuerySuggestion:(NSString*)text {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection>(self);
    THROW_NS_IF_FAILED(_comInst->AppendQuerySuggestion(nsStrToHstr(text).Get()));
}

- (void)appendQuerySuggestions:(id<NSFastEnumeration> /* NSString * */)suggestions {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection>(self);
    THROW_NS_IF_FAILED(_comInst->AppendQuerySuggestions(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(suggestions).Get())));
}

- (void)appendResultSuggestion:(NSString*)text
                    detailText:(NSString*)detailText
                           tag:(NSString*)tag
                         image:(RTObject<WSSIRandomAccessStreamReference>*)image
            imageAlternateText:(NSString*)imageAlternateText {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection>(self);
    THROW_NS_IF_FAILED(
        _comInst->AppendResultSuggestion(nsStrToHstr(text).Get(),
                                         nsStrToHstr(detailText).Get(),
                                         nsStrToHstr(tag).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(image).Get(),
                                         nsStrToHstr(imageAlternateText).Get()));
}

- (void)appendSearchSeparator:(NSString*)label {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection>(self);
    THROW_NS_IF_FAILED(_comInst->AppendSearchSeparator(nsStrToHstr(label).Get()));
}

@end

@implementation WASLocalContentSuggestionSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Search.LocalContentSuggestionSettings").Get(), &out));
    return [_createRtProxy<WASLocalContentSuggestionSettings>(out.Get()) retain];
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WSStorageFolder* */)locations {
    ComPtr<IVector<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSStorageFolder_create(unmarshalledReturn.Get());
}

- (void)setAqsFilter:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AqsFilter(nsStrToHstr(value).Get()));
}

- (NSString*)aqsFilter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AqsFilter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableArray* /* NSString * */)propertiesToMatch {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ILocalContentSuggestionSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_PropertiesToMatch(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WASSearchQueryLinguisticDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> WASISearchQueryLinguisticDetailsFactory_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.Search.SearchQueryLinguisticDetails").Get(), &inst));
    return inst;
}

+ (WASSearchQueryLinguisticDetails*)makeInstance:(id<NSFastEnumeration> /* NSString * */)queryTextAlternatives
                       queryTextCompositionStart:(unsigned int)queryTextCompositionStart
                      queryTextCompositionLength:(unsigned int)queryTextCompositionLength {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails> unmarshalledReturn;
    auto _comInst = WASISearchQueryLinguisticDetailsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                     ConvertToIterable<NSString, HSTRING>(queryTextAlternatives).Get()),
                                 queryTextCompositionStart,
                                 queryTextCompositionLength,
                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WASSearchQueryLinguisticDetails>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)queryTextAlternatives {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextAlternatives(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)queryTextCompositionStart {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextCompositionStart(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)queryTextCompositionLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryTextCompositionLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WASSearchSuggestionsRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WASSearchSuggestionsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WASSearchSuggestionCollection*)searchSuggestionCollection {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SearchSuggestionCollection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchSuggestionCollection>(unmarshalledReturn.Get());
}

- (WASSearchSuggestionsRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Search::ISearchSuggestionsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSearchSuggestionsRequestDeferral>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSStorageFolder_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Storage::StorageFolder*>,
                                                RTMutableArrayObj<ABI::Windows::Storage::IStorageFolder*,
                                                                  IVector<ABI::Windows::Storage::StorageFolder*>,
                                                                  WSStorageFolder,
                                                                  ABI::Windows::Storage::StorageFolder*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
