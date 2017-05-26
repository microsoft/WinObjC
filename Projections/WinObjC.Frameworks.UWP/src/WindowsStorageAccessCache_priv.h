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

// WindowsStorageAccessCache_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> WSAIStorageApplicationPermissionsStatics_inst();
@interface WSAAccessListEntry (Internal)
+ (instancetype)createWith:(ABI::Windows::Storage::AccessCache::AccessListEntry)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Storage::AccessCache::AccessListEntry*)internalStruct;
@end
inline WSAAccessListEntry* WSAAccessListEntry_create(ABI::Windows::Storage::AccessCache::AccessListEntry val) {
    return [WSAAccessListEntry createWith:val];
}

#ifndef __ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::AccessCache::StorageItemMostRecentlyUsedList*,
                                                                       ABI::Windows::Storage::AccessCache::ItemRemovedEventArgs*>> {
    void (^_delegate)(WSAStorageItemMostRecentlyUsedList*, WSAItemRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs(
        void (^del)(WSAStorageItemMostRecentlyUsedList*, WSAItemRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList* arg0,
                                             ABI::Windows::Storage::AccessCache::IItemRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSAStorageItemMostRecentlyUsedList>(arg0), _createRtProxy<WSAItemRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
