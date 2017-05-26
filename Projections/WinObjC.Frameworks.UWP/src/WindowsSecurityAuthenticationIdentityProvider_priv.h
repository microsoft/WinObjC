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

// WindowsSecurityAuthenticationIdentityProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst();
ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();

id RTProxiedNSArray_WSAIPSecondaryAuthenticationFactorInfo_create(IInspectable* val);

@class RTProxiedNSArray_WSAIPSecondaryAuthenticationFactorInfo;

#ifndef __EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs__DEFINED
#define __EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs__DEFINED
class EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Security::Authentication::Identity::Provider::
                                                                      SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs*);

public:
    EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(
        void (^del)(RTObject*, WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(
        IInspectable* arg0,
        ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs* arg1)
        override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
