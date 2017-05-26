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

// WindowsWebHttpDiagnostics_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsWebHttp_priv.h"
#include "WindowsSystemDiagnostics_priv.h"
ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> WWHDIHttpDiagnosticProviderStatics_inst();

id RTProxiedNSArray_WWHDHttpDiagnosticSourceLocation_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_WWHDHttpDiagnosticSourceLocation;

#ifndef __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProvider*,
                              ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs*>> {
    void (^_delegate)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs(
        void (^del)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider* arg0,
           ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WWHDHttpDiagnosticProvider>(arg0),
                      _createRtProxy<WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProvider*,
                                                       ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs*>> {
    void (^_delegate)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestSentEventArgs*);

public:
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs(
        void (^del)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderRequestSentEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider* arg0,
           ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WWHDHttpDiagnosticProvider>(arg0),
                      _createRtProxy<WWHDHttpDiagnosticProviderRequestSentEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProvider*,
                              ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs*>> {
    void (^_delegate)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderResponseReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs(
        void (^del)(WWHDHttpDiagnosticProvider*, WWHDHttpDiagnosticProviderResponseReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider* arg0,
           ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WWHDHttpDiagnosticProvider>(arg0),
                      _createRtProxy<WWHDHttpDiagnosticProviderResponseReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
