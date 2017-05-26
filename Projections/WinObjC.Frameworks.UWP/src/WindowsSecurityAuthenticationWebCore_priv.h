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

// WindowsSecurityAuthenticationWebCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsSystem_priv.h"
static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> WSAWCIWebTokenRequestFactory_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
WSAWCIWebAuthenticationCoreManagerStatics3_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
WSAWCIWebAuthenticationCoreManagerStatics2_inst();
ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
WSAWCIWebAuthenticationCoreManagerStatics_inst();
static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> WSAWCIWebProviderErrorFactory_inst();
static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> WSAWCIWebTokenResponseFactory_inst();

id RTProxiedIterableNSArray_WSCWebAccount_create(IInspectable* val);
id RTProxiedNSArray_WSAWCWebTokenResponse_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_WSCWebAccount, RTProxiedNSArray_WSAWCWebTokenResponse, RTProxiedNSMutableDictionary_NSString_NSString;

#ifndef __ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object__DEFINED
class ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::Security::Authentication::Web::Core::WebAccountMonitor*, IInspectable*>> {
    void (^_delegate)(WSAWCWebAccountMonitor*, RTObject*);

public:
    ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object(void (^del)(WSAWCWebAccountMonitor*,
                                                                                                            RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSAWCWebAccountMonitor>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Security::Authentication::Web::Core::WebAccountMonitor*,
                                                       ABI::Windows::Security::Authentication::Web::Core::WebAccountEventArgs*>> {
    void (^_delegate)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*);

public:
    ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs(
        void (^del)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor* arg0,
                                             ABI::Windows::Security::Authentication::Web::Core::IWebAccountEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSAWCWebAccountMonitor>(arg0), _createRtProxy<WSAWCWebAccountEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
