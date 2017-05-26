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

// WindowsStoragePickersProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsFoundation_priv.h"

id RTProxiedNSArray_NSString_create(IInspectable* val);

@class RTProxiedNSArray_NSString;

#ifndef __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Pickers::Provider::FileOpenPickerUI*,
                                                                       ABI::Windows::Storage::Pickers::Provider::FileRemovedEventArgs*>> {
    void (^_delegate)(WSPPFileOpenPickerUI*, WSPPFileRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs(
        void (^del)(WSPPFileOpenPickerUI*, WSPPFileRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI* arg0,
                                             ABI::Windows::Storage::Pickers::Provider::IFileRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPPFileOpenPickerUI>(arg0), _createRtProxy<WSPPFileRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs__DEFINED
class ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Pickers::Provider::FileOpenPickerUI*,
                                                                       ABI::Windows::Storage::Pickers::Provider::PickerClosingEventArgs*>> {
    void (^_delegate)(WSPPFileOpenPickerUI*, WSPPPickerClosingEventArgs*);

public:
    ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs(
        void (^del)(WSPPFileOpenPickerUI*, WSPPPickerClosingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI* arg0,
                                             ABI::Windows::Storage::Pickers::Provider::IPickerClosingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPPFileOpenPickerUI>(arg0), _createRtProxy<WSPPPickerClosingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Pickers::Provider::FileSavePickerUI*, IInspectable*>> {
    void (^_delegate)(WSPPFileSavePickerUI*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object(void (^del)(WSPPFileSavePickerUI*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPPFileSavePickerUI>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Pickers::Provider::FileSavePickerUI*,
                                                       ABI::Windows::Storage::Pickers::Provider::TargetFileRequestedEventArgs*>> {
    void (^_delegate)(WSPPFileSavePickerUI*, WSPPTargetFileRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs(
        void (^del)(WSPPFileSavePickerUI*, WSPPTargetFileRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI* arg0,
                                             ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSPPFileSavePickerUI>(arg0), _createRtProxy<WSPPTargetFileRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
