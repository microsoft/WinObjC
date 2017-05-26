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

// WindowsApplicationModelSearchCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsApplicationModelSearch_priv.h"
#include "WindowsFoundation_priv.h"

id RTProxiedObservableNSMutableArray_WASCSearchSuggestion_create(IInspectable* val);

@class RTProxiedObservableNSMutableArray_WASCSearchSuggestion;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionManager*,
                              ABI::Windows::ApplicationModel::Search::Core::RequestingFocusOnKeyboardInputEventArgs*>> {
    void (^_delegate)(WASCSearchSuggestionManager*, WASCRequestingFocusOnKeyboardInputEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs(
        void (^del)(WASCSearchSuggestionManager*, WASCRequestingFocusOnKeyboardInputEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_RequestingFocusOnKeyboardInputEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager* arg0,
           ABI::Windows::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASCSearchSuggestionManager>(arg0), _createRtProxy<WASCRequestingFocusOnKeyboardInputEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionManager*,
                              ABI::Windows::ApplicationModel::Search::Core::SearchSuggestionsRequestedEventArgs*>> {
    void (^_delegate)(WASCSearchSuggestionManager*, WASCSearchSuggestionsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs(
        void (^del)(WASCSearchSuggestionManager*, WASCSearchSuggestionsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Search_Core_SearchSuggestionManager_Windows_ApplicationModel_Search_Core_SearchSuggestionsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionManager* arg0,
           ABI::Windows::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WASCSearchSuggestionManager>(arg0), _createRtProxy<WASCSearchSuggestionsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
