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

// WindowsStorageProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
ComPtr<ABI::Windows::Storage::Provider::ICachedFileUpdaterStatics> WSPICachedFileUpdaterStatics_inst();

#ifndef __ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*, IInspectable*>> {
    void (^_delegate)(WSPCachedFileUpdaterUI*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object(void (^del)(WSPCachedFileUpdaterUI*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Provider::ICachedFileUpdaterUI* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPCachedFileUpdaterUI>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Provider::CachedFileUpdaterUI*,
                                                                       ABI::Windows::Storage::Provider::FileUpdateRequestedEventArgs*>> {
    void (^_delegate)(WSPCachedFileUpdaterUI*, WSPFileUpdateRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs(
        void (^del)(WSPCachedFileUpdaterUI*, WSPFileUpdateRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Provider::ICachedFileUpdaterUI* arg0,
                                             ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPCachedFileUpdaterUI>(arg0), _createRtProxy<WSPFileUpdateRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
