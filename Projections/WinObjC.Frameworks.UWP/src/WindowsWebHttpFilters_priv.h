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

// WindowsWebHttpFilters_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsNetworkingSockets_priv.h"
#include "WindowsSecurityCryptographyCertificates_priv.h"
#include "WindowsWebHttp_priv.h"
#include "WindowsSecurityCredentials_priv.h"

id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val);
id RTProxiedNSMutableArray_WSCCChainValidationResult_create(IInspectable* val);

@class RTProxiedNSArray_WSCCCertificate, RTProxiedNSArray_WSCCChainValidationResult, RTProxiedNSMutableArray_WSCCChainValidationResult;

#ifndef __ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Web::Http::Filters::HttpBaseProtocolFilter*,
                                                       ABI::Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs*>> {
    void (^_delegate)(WWHFHttpBaseProtocolFilter*, WWHFHttpServerCustomValidationRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs(
        void (^del)(WWHFHttpBaseProtocolFilter*, WWHFHttpServerCustomValidationRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter* arg0,
           ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WWHFHttpBaseProtocolFilter>(arg0),
                      _createRtProxy<WWHFHttpServerCustomValidationRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
