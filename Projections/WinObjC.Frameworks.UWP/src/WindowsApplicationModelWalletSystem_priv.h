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

// WindowsApplicationModelWalletSystem_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelWallet_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> WAWSIWalletManagerSystemStatics_inst();

id RTProxiedNSArray_WAWWalletItem_create(IInspectable* val);

@class RTProxiedNSArray_WAWWalletItem;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::
                              ITypedEventHandler<ABI::Windows::ApplicationModel::Wallet::System::WalletItemSystemStore*, IInspectable*>> {
    void (^_delegate)(WAWSWalletItemSystemStore*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object(void (^del)(WAWSWalletItemSystemStore*,
                                                                                                              RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Wallet_System_WalletItemSystemStore_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Wallet::System::IWalletItemSystemStore* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAWSWalletItemSystemStore>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
