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

// WindowsApplicationModelSearch_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsStorage_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication>
WASISearchPaneStaticsWithHideThisApplication_inst();
ComPtr<ABI::Windows::ApplicationModel::Search::ISearchPaneStatics> WASISearchPaneStatics_inst();
static ComPtr<ABI::Windows::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> WASISearchQueryLinguisticDetailsFactory_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WSStorageFolder_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_NSString, RTProxiedNSMutableArray_NSString,
    RTProxiedNSMutableArray_WSStorageFolder;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Search::SearchPane*,
                                                       ABI::Windows::ApplicationModel::Search::SearchPaneQueryChangedEventArgs*>> {
    void (^_delegate)(WASSearchPane*, WASSearchPaneQueryChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs(
        void (^del)(WASSearchPane*, WASSearchPaneQueryChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQueryChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Search::ISearchPane* arg0,
                                             ABI::Windows::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASSearchPane>(arg0), _createRtProxy<WASSearchPaneQueryChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Search::SearchPane*,
                                                       ABI::Windows::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs*>> {
    void (^_delegate)(WASSearchPane*, WASSearchPaneQuerySubmittedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs(
        void (^del)(WASSearchPane*, WASSearchPaneQuerySubmittedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneQuerySubmittedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Search::ISearchPane* arg0,
                                             ABI::Windows::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASSearchPane>(arg0), _createRtProxy<WASSearchPaneQuerySubmittedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Search::SearchPane*,
                              ABI::Windows::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs*>> {
    void (^_delegate)(WASSearchPane*, WASSearchPaneResultSuggestionChosenEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs(
        void (^del)(WASSearchPane*, WASSearchPaneResultSuggestionChosenEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneResultSuggestionChosenEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Search::ISearchPane* arg0,
           ABI::Windows::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASSearchPane>(arg0), _createRtProxy<WASSearchPaneResultSuggestionChosenEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Search::SearchPane*,
                                                       ABI::Windows::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs*>> {
    void (^_delegate)(WASSearchPane*, WASSearchPaneSuggestionsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs(
        void (^del)(WASSearchPane*, WASSearchPaneSuggestionsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneSuggestionsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Search::ISearchPane* arg0,
           ABI::Windows::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASSearchPane>(arg0), _createRtProxy<WASSearchPaneSuggestionsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Search::SearchPane*,
                                                       ABI::Windows::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs*>> {
    void (^_delegate)(WASSearchPane*, WASSearchPaneVisibilityChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs(
        void (^del)(WASSearchPane*, WASSearchPaneVisibilityChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_SearchPane_Windows_ApplicationModel_Search_SearchPaneVisibilityChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Search::ISearchPane* arg0,
                                             ABI::Windows::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASSearchPane>(arg0), _createRtProxy<WASSearchPaneVisibilityChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
