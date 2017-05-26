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

// WindowsSecurityAuthenticationOnlineId_priv.h
// Forward decls for private object generation
#pragma once

// Can't create proxy instantiator for type: Can't marshal
// Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>

#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>
WSAOIOnlineIdServiceTicketRequestFactory_inst();

id RTProxiedNSArray_WSAOOnlineIdServiceTicket_create(IInspectable* val);

@class RTProxiedNSArray_WSAOOnlineIdServiceTicket;

#ifndef __WFAsyncActionCompletedHandler_shim__DEFINED
#define __WFAsyncActionCompletedHandler_shim__DEFINED
class WFAsyncActionCompletedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IAsyncActionCompletedHandler> {
    void (^_delegate)(RTObject<WFIAsyncAction>*, WFAsyncStatus);

public:
    WFAsyncActionCompletedHandler_shim(void (^del)(RTObject<WFIAsyncAction>*, WFAsyncStatus)) : _delegate([del copy]) {
    }
    ~WFAsyncActionCompletedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::IAsyncAction* arg0, AsyncStatus arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFIAsyncAction>(arg0), (unsigned)arg1);
            return 0;
        };
    }
};
#endif
