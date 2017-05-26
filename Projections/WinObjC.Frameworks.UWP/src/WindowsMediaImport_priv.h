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

// WindowsMediaImport_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Media::Import::IPhotoImportSourceStatics> WMIIPhotoImportSourceStatics_inst();
ComPtr<ABI::Windows::Media::Import::IPhotoImportManagerStatics> WMIIPhotoImportManagerStatics_inst();
@interface WMIPhotoImportProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Import::PhotoImportProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Import::PhotoImportProgress*)internalStruct;
@end
inline WMIPhotoImportProgress* WMIPhotoImportProgress_create(ABI::Windows::Media::Import::PhotoImportProgress val) {
    return [WMIPhotoImportProgress createWith:val];
}

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportItem_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportOperation_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportSidecar_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportSource_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportStorageMedium_create(IInspectable* val);
id RTProxiedNSArray_WMIPhotoImportVideoSegment_create(IInspectable* val);

@class Nullable_Boolean, Nullable_UInt32, Nullable_WFDateTime, RTProxiedNSArray_NSString, RTProxiedNSArray_WMIPhotoImportItem,
    RTProxiedNSArray_WMIPhotoImportOperation;
@class RTProxiedNSArray_WMIPhotoImportSidecar, RTProxiedNSArray_WMIPhotoImportSource, RTProxiedNSArray_WMIPhotoImportStorageMedium,
    RTProxiedNSArray_WMIPhotoImportVideoSegment;

#ifndef __ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                       ABI::Windows::Media::Import::PhotoImportItemImportedEventArgs*>> {
    void (^_delegate)(WMIPhotoImportFindItemsResult*, WMIPhotoImportItemImportedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs(
        void (^del)(WMIPhotoImportFindItemsResult*, WMIPhotoImportItemImportedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Import::IPhotoImportFindItemsResult* arg0,
                                             ABI::Windows::Media::Import::IPhotoImportItemImportedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMIPhotoImportFindItemsResult>(arg0), _createRtProxy<WMIPhotoImportItemImportedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                       ABI::Windows::Media::Import::PhotoImportSelectionChangedEventArgs*>> {
    void (^_delegate)(WMIPhotoImportFindItemsResult*, WMIPhotoImportSelectionChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs(
        void (^del)(WMIPhotoImportFindItemsResult*, WMIPhotoImportSelectionChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Import::IPhotoImportFindItemsResult* arg0,
                                             ABI::Windows::Media::Import::IPhotoImportSelectionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMIPhotoImportFindItemsResult>(arg0), _createRtProxy<WMIPhotoImportSelectionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
