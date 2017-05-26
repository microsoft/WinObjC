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

// WindowsStorage_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageSearch_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsStorageFileProperties_priv.h"
#include "WindowsStorageProvider_priv.h"
ComPtr<ABI::Windows::Storage::IStorageLibraryStatics> WSIStorageLibraryStatics_inst();
ComPtr<ABI::Windows::Storage::IStorageLibraryStatics2> WSIStorageLibraryStatics2_inst();
ComPtr<ABI::Windows::Storage::IStorageFolderStatics> WSIStorageFolderStatics_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersStatics> WSIKnownFoldersStatics_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersStatics3> WSIKnownFoldersStatics3_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersPlaylistsStatics> WSIKnownFoldersPlaylistsStatics_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersSavedPicturesStatics> WSIKnownFoldersSavedPicturesStatics_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersStatics2> WSIKnownFoldersStatics2_inst();
ComPtr<ABI::Windows::Storage::IKnownFoldersCameraRollStatics> WSIKnownFoldersCameraRollStatics_inst();
ComPtr<ABI::Windows::Storage::IStorageFileStatics> WSIStorageFileStatics_inst();
ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics2> WSIDownloadsFolderStatics2_inst();
ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics> WSIDownloadsFolderStatics_inst();
ComPtr<ABI::Windows::Storage::IFileIOStatics> WSIFileIOStatics_inst();
ComPtr<ABI::Windows::Storage::IPathIOStatics> WSIPathIOStatics_inst();
ComPtr<ABI::Windows::Storage::ICachedFileManagerStatics> WSICachedFileManagerStatics_inst();
ComPtr<ABI::Windows::Storage::ISystemProperties> WSISystemProperties_inst();
ComPtr<ABI::Windows::Storage::IApplicationDataStatics2> WSIApplicationDataStatics2_inst();
ComPtr<ABI::Windows::Storage::IApplicationDataStatics> WSIApplicationDataStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFolder_create(IInspectable* val);
id RTProxiedNSArray_WSStorageLibraryChange_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WSApplicationDataContainer_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_WSStorageFolder_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_RTObject_WSIStorageItem,
    RTProxiedNSArray_WSStorageFile;
@class RTProxiedNSArray_WSStorageFolder, RTProxiedNSArray_WSStorageLibraryChange, RTProxiedNSDictionary_NSString_WSApplicationDataContainer;
@class RTProxiedNSMutableArray_NSString, RTProxiedObservableNSMutableArray_WSStorageFolder;

#ifndef __ITypedEventHandler_Windows_Storage_ApplicationData_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_ApplicationData_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_ApplicationData_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::ApplicationData*, IInspectable*>> {
    void (^_delegate)(WSApplicationData*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_ApplicationData_System_Object(void (^del)(WSApplicationData*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_ApplicationData_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::IApplicationData* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSApplicationData>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object__DEFINED
class ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Storage::StorageLibrary*, IInspectable*>> {
    void (^_delegate)(WSStorageLibrary*, RTObject*);

public:
    ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object(void (^del)(WSStorageLibrary*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::IStorageLibrary* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSStorageLibrary>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WSApplicationDataSetVersionHandler_shim__DEFINED
#define __WSApplicationDataSetVersionHandler_shim__DEFINED
class WSApplicationDataSetVersionHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Storage::IApplicationDataSetVersionHandler> {
    void (^_delegate)(WSSetVersionRequest*);

public:
    WSApplicationDataSetVersionHandler_shim(void (^del)(WSSetVersionRequest*)) : _delegate([del copy]) {
    }
    ~WSApplicationDataSetVersionHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::ISetVersionRequest* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSSetVersionRequest>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WSStreamedFileDataRequestedHandler_shim__DEFINED
#define __WSStreamedFileDataRequestedHandler_shim__DEFINED
class WSStreamedFileDataRequestedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Storage::IStreamedFileDataRequestedHandler> {
    void (^_delegate)(WSStreamedFileDataRequest*);

public:
    WSStreamedFileDataRequestedHandler_shim(void (^del)(WSStreamedFileDataRequest*)) : _delegate([del copy]) {
    }
    ~WSStreamedFileDataRequestedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Storage::Streams::IOutputStream* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WSStreamedFileDataRequest>(arg0));
            return 0;
        };
    }
};
#endif
