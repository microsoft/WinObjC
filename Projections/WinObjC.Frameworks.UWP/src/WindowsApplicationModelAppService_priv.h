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

// WindowsApplicationModelAppService_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystemRemoteSystems_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::ApplicationModel::AppService::IAppServiceCatalogStatics> WAAIAppServiceCatalogStatics_inst();

id RTProxiedNSArray_WAAppInfo_create(IInspectable* val);

@class RTProxiedNSArray_WAAppInfo;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceClosedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceClosedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceClosedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::AppService::AppServiceConnection*,
                                                       ABI::Windows::ApplicationModel::AppService::AppServiceClosedEventArgs*>> {
    void (^_delegate)(WAAAppServiceConnection*, WAAAppServiceClosedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceClosedEventArgs(
        void (^del)(WAAAppServiceConnection*, WAAAppServiceClosedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceClosedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::AppService::IAppServiceConnection* arg0,
                                             ABI::Windows::ApplicationModel::AppService::IAppServiceClosedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppServiceConnection>(arg0), _createRtProxy<WAAAppServiceClosedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceRequestReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceRequestReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceRequestReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::AppService::AppServiceConnection*,
                                                       ABI::Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs*>> {
    void (^_delegate)(WAAAppServiceConnection*, WAAAppServiceRequestReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceRequestReceivedEventArgs(
        void (^del)(WAAAppServiceConnection*, WAAAppServiceRequestReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_AppService_AppServiceConnection_Windows_ApplicationModel_AppService_AppServiceRequestReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::AppService::IAppServiceConnection* arg0,
           ABI::Windows::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppServiceConnection>(arg0), _createRtProxy<WAAAppServiceRequestReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
