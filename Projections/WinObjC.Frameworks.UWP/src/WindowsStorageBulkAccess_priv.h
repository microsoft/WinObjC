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

// WindowsStorageBulkAccess_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsStorageFileProperties_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageSearch_priv.h"
static ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactoryFactory> WSBIFileInformationFactoryFactory_inst();

id RTProxiedNSArray_RTObject_WSBIStorageItemInformation_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_WSBFileInformation_create(IInspectable* val);
id RTProxiedNSArray_WSBFolderInformation_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFolder_create(IInspectable* val);

@class RTProxiedNSArray_RTObject_WSBIStorageItemInformation, RTProxiedNSArray_RTObject_WSIStorageItem, RTProxiedNSArray_WSBFileInformation;
@class RTProxiedNSArray_WSBFolderInformation, RTProxiedNSArray_WSStorageFile, RTProxiedNSArray_WSStorageFolder;

#ifndef __ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*, IInspectable*>> {
    void (^_delegate)(RTObject<WSBIStorageItemInformation>*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object(void (^del)(RTObject<WSBIStorageItemInformation>*,
                                                                                                    RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::BulkAccess::IStorageItemInformation* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSBIStorageItemInformation>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
