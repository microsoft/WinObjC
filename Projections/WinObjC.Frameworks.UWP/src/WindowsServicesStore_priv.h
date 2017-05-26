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

// WindowsServicesStore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsSystem_priv.h"
static ComPtr<ABI::Windows::Services::Store::IStorePurchasePropertiesFactory> WSSIStorePurchasePropertiesFactory_inst();
ComPtr<ABI::Windows::Services::Store::IStoreContextStatics> WSSIStoreContextStatics_inst();
ComPtr<ABI::Windows::Services::Store::IStoreRequestHelperStatics> WSSIStoreRequestHelperStatics_inst();
@interface WSSStorePackageUpdateStatus (Internal)
+ (instancetype)createWith:(ABI::Windows::Services::Store::StorePackageUpdateStatus)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Services::Store::StorePackageUpdateStatus*)internalStruct;
@end
inline WSSStorePackageUpdateStatus* WSSStorePackageUpdateStatus_create(ABI::Windows::Services::Store::StorePackageUpdateStatus val) {
    return [WSSStorePackageUpdateStatus createWith:val];
}

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WSSStorePackageUpdate_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WSSStoreAvailability_create(IInspectable* val);
id RTProxiedNSArray_WSSStoreImage_create(IInspectable* val);
id RTProxiedNSArray_WSSStorePackageUpdate_create(IInspectable* val);
id RTProxiedNSArray_WSSStorePackageUpdateStatus_create(IInspectable* val);
id RTProxiedNSArray_WSSStoreSku_create(IInspectable* val);
id RTProxiedNSArray_WSSStoreVideo_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSSStoreLicense_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSSStoreProduct_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WSSStorePackageUpdate, RTProxiedNSArray_NSString,
    RTProxiedNSArray_WSSStoreAvailability;
@class RTProxiedNSArray_WSSStoreImage, RTProxiedNSArray_WSSStorePackageUpdate, RTProxiedNSArray_WSSStorePackageUpdateStatus,
    RTProxiedNSArray_WSSStoreSku;
@class RTProxiedNSArray_WSSStoreVideo, RTProxiedNSDictionary_NSString_WSSStoreLicense, RTProxiedNSDictionary_NSString_WSSStoreProduct;

#ifndef __ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object__DEFINED
class ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Services::Store::StoreContext*, IInspectable*>> {
    void (^_delegate)(WSSStoreContext*, RTObject*);

public:
    ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object(void (^del)(WSSStoreContext*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Store_StoreContext_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Services::Store::IStoreContext* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSSStoreContext>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object__DEFINED
class ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Services::Store::StorePackageLicense*, IInspectable*>> {
    void (^_delegate)(WSSStorePackageLicense*, RTObject*);

public:
    ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object(void (^del)(WSSStorePackageLicense*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Services_Store_StorePackageLicense_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Services::Store::IStorePackageLicense* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSSStorePackageLicense>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
