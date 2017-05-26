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

// WindowsStorageSearch_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsStorageFileProperties_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDataText_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Storage::Search::IContentIndexerStatics> WSSIContentIndexerStatics_inst();
static ComPtr<ABI::Windows::Storage::Search::IQueryOptionsFactory> WSSIQueryOptionsFactory_inst();
@interface WSSSortEntry (Internal)
+ (instancetype)createWith:(ABI::Windows::Storage::Search::SortEntry)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Storage::Search::SortEntry*)internalStruct;
@end
inline WSSSortEntry* WSSSortEntry_create(ABI::Windows::Storage::Search::SortEntry val) {
    return [WSSSortEntry createWith:val];
}

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WSSSortEntry_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_RTObject_WSSIIndexableContent_create(IInspectable* val);
id RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFolder_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WSSSortEntry_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_RTProxiedNSArray_WDTTextSegment_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WSSSortEntry, RTProxiedNSArray_RTObject_WSIStorageItem,
    RTProxiedNSArray_RTObject_WSSIIndexableContent;
@class RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSArray_WDTTextSegment, RTProxiedNSArray_WSStorageFile,
    RTProxiedNSArray_WSStorageFolder;
@class RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WSSSortEntry,
    RTProxiedNSMutableDictionary_NSString_RTObject;
@class RTProxiedNSMutableDictionary_NSString_RTProxiedNSArray_WDTTextSegment;

#ifndef __ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::Search::IStorageQueryResultBase*, IInspectable*>> {
    void (^_delegate)(RTObject<WSSIStorageQueryResultBase>*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object(void (^del)(RTObject<WSSIStorageQueryResultBase>*,
                                                                                                RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Search::IStorageQueryResultBase* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSSIStorageQueryResultBase>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

typedef IMapView<HSTRING, IInspectable*>* IMapView_HSTRING_IInspectablePtr_Ptr;
