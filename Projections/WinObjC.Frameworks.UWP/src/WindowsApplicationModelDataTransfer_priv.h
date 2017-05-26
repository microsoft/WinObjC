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

// WindowsApplicationModelDataTransfer_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsSecurityEnterpriseData_priv.h"
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics> WADIStandardDataFormatsStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IStandardDataFormatsStatics2> WADIStandardDataFormatsStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IHtmlFormatHelperStatics> WADIHtmlFormatHelperStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IClipboardStatics> WADIClipboardStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics> WADIDataTransferManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManagerStatics2> WADIDataTransferManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ISharedStorageAccessManagerStatics> WADISharedStorageAccessManagerStatics_inst();

id RTProxiedIterableNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSSRandomAccessStreamReference_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_WSSRandomAccessStreamReference_create(IInspectable* val);

@class RTProxiedIterableNSArray_RTObject_WSIStorageItem, RTProxiedNSArray_NSString, RTProxiedNSArray_RTObject_WSIStorageItem,
    RTProxiedNSDictionary_NSString_WSSRandomAccessStreamReference;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableDictionary_NSString_WSSRandomAccessStreamReference;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackage*, IInspectable*>> {
    void (^_delegate)(WADDataPackage*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object(void (^del)(WADDataPackage*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::DataTransfer::IDataPackage* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDataPackage>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackage*,
                                                       ABI::Windows::ApplicationModel::DataTransfer::OperationCompletedEventArgs*>> {
    void (^_delegate)(WADDataPackage*, WADOperationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs(
        void (^del)(WADDataPackage*, WADOperationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataPackage_Windows_ApplicationModel_DataTransfer_OperationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::DataTransfer::IDataPackage* arg0,
                                             ABI::Windows::ApplicationModel::DataTransfer::IOperationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDataPackage>(arg0), _createRtProxy<WADOperationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::DataTransfer::DataTransferManager*,
                                                       ABI::Windows::ApplicationModel::DataTransfer::DataRequestedEventArgs*>> {
    void (^_delegate)(WADDataTransferManager*, WADDataRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs(
        void (^del)(WADDataTransferManager*, WADDataRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_DataRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager* arg0,
                                             ABI::Windows::ApplicationModel::DataTransfer::IDataRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDataTransferManager>(arg0), _createRtProxy<WADDataRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::DataTransfer::DataTransferManager*,
                                                       ABI::Windows::ApplicationModel::DataTransfer::TargetApplicationChosenEventArgs*>> {
    void (^_delegate)(WADDataTransferManager*, WADTargetApplicationChosenEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs(
        void (^del)(WADDataTransferManager*, WADTargetApplicationChosenEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DataTransferManager_Windows_ApplicationModel_DataTransfer_TargetApplicationChosenEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::DataTransfer::IDataTransferManager* arg0,
           ABI::Windows::ApplicationModel::DataTransfer::ITargetApplicationChosenEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDataTransferManager>(arg0), _createRtProxy<WADTargetApplicationChosenEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WADDataProviderHandler_shim__DEFINED
#define __WADDataProviderHandler_shim__DEFINED
class WADDataProviderHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::ApplicationModel::DataTransfer::IDataProviderHandler> {
    void (^_delegate)(WADDataProviderRequest*);

public:
    WADDataProviderHandler_shim(void (^del)(WADDataProviderRequest*)) : _delegate([del copy]) {
    }
    ~WADDataProviderHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::DataTransfer::IDataProviderRequest* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDataProviderRequest>(arg0));
            return 0;
        };
    }
};
#endif
