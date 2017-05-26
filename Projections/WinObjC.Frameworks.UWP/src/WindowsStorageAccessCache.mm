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

// WindowsStorageAccessCache.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.AccessCache.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageAccessCache.h"
#include "WindowsStorageAccessCache_priv.h"

@implementation WSAIStorageItemAccessList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageItemAccessList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOverloadDefaultMetadata(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->Add(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), nsStrToHstr(metadata).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplaceOverloadDefaultMetadata(nsStrToHstr(token).Get(),
                                                                     _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get()));
}

- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplace(nsStrToHstr(token).Get(),
                                              _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(),
                                              nsStrToHstr(metadata).Get()));
}

- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderWithOptionsAsync(nsStrToHstr(token).Get(),
                                                           (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)remove:(NSString*)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(nsStrToHstr(token).Get()));
}

- (BOOL)containsItem:(NSString*)token {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->ContainsItem(nsStrToHstr(token).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->CheckAccess(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSAAccessListEntryView*)entries {
    ComPtr<IVectorView<ABI::Windows::Storage::AccessCache::AccessListEntry>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Entries(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAAccessListEntryView>(unmarshalledReturn.Get());
}

- (unsigned int)maximumItemsAllowed {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaximumItemsAllowed(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSAAccessListEntryView {
    RTArrayObj<ABI::Windows::Storage::AccessCache::AccessListEntry,
               IVectorView<ABI::Windows::Storage::AccessCache::AccessListEntry>,
               WSAAccessListEntry,
               ABI::Windows::Storage::AccessCache::AccessListEntry,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WSAAccessListEntry,
                             ABI::Windows::Storage::AccessCache::AccessListEntry,
                             ABI::Windows::Storage::AccessCache::AccessListEntry)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Storage::AccessCache::AccessListEntry>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSAStorageItemMostRecentlyUsedList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addItemRemovedEvent:(void (^)(WSAStorageItemMostRecentlyUsedList*, WSAItemRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemRemoved(
        Make<
            ITypedEventHandler_Windows_Storage_AccessCache_StorageItemMostRecentlyUsedList_Windows_Storage_AccessCache_ItemRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemRemovedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemRemoved(eventCookie));
}

- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOverloadDefaultMetadata(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->Add(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), nsStrToHstr(metadata).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplaceOverloadDefaultMetadata(nsStrToHstr(token).Get(),
                                                                     _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get()));
}

- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplace(nsStrToHstr(token).Get(),
                                              _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(),
                                              nsStrToHstr(metadata).Get()));
}

- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderWithOptionsAsync(nsStrToHstr(token).Get(),
                                                           (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)remove:(NSString*)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(nsStrToHstr(token).Get()));
}

- (BOOL)containsItem:(NSString*)token {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->ContainsItem(nsStrToHstr(token).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->CheckAccess(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSAAccessListEntryView*)entries {
    ComPtr<IVectorView<ABI::Windows::Storage::AccessCache::AccessListEntry>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Entries(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAAccessListEntryView>(unmarshalledReturn.Get());
}

- (unsigned int)maximumItemsAllowed {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaximumItemsAllowed(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)addWithMetadataAndVisibility:(RTObject<WSIStorageItem>*)file
                                 metadata:(NSString*)metadata
                               visibility:(WSARecentStorageItemVisibility)visibility {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>(self);
    THROW_NS_IF_FAILED(_comInst->AddWithMetadataAndVisibility(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(),
                                                              nsStrToHstr(metadata).Get(),
                                                              (ABI::Windows::Storage::AccessCache::RecentStorageItemVisibility)visibility,
                                                              &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addOrReplaceWithMetadataAndVisibility:(NSString*)token
                                         file:(RTObject<WSIStorageItem>*)file
                                     metadata:(NSString*)metadata
                                   visibility:(WSARecentStorageItemVisibility)visibility {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList2>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOrReplaceWithMetadataAndVisibility(nsStrToHstr(token).Get(),
                                                        _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(),
                                                        nsStrToHstr(metadata).Get(),
                                                        (ABI::Windows::Storage::AccessCache::RecentStorageItemVisibility)visibility));
}

@end

@implementation WSAItemRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::AccessCache::IItemRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAAccessListEntry*)removedEntry {
    ABI::Windows::Storage::AccessCache::AccessListEntry unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IItemRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemovedEntry(&unmarshalledReturn));
    return WSAAccessListEntry_create(unmarshalledReturn);
}

@end

@implementation WSAStorageItemAccessList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageItemAccessList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)addOverloadDefaultMetadata:(RTObject<WSIStorageItem>*)file {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOverloadDefaultMetadata(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)add:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(
        _comInst->Add(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), nsStrToHstr(metadata).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addOrReplaceOverloadDefaultMetadata:(NSString*)token file:(RTObject<WSIStorageItem>*)file {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplaceOverloadDefaultMetadata(nsStrToHstr(token).Get(),
                                                                     _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get()));
}

- (void)addOrReplace:(NSString*)token file:(RTObject<WSIStorageItem>*)file metadata:(NSString*)metadata {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->AddOrReplace(nsStrToHstr(token).Get(),
                                              _getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(),
                                              nsStrToHstr(metadata).Get()));
}

- (void)getItemAsync:(NSString*)token success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileAsync:(NSString*)token success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderAsync:(NSString*)token success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(token).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getItemWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(RTObject<WSIStorageItem>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::IStorageItem*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageItem> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSIStorageItem>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFileWithOptionsAsync:(NSString*)token
                        options:(WSAAccessCacheOptions)options
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileWithOptionsAsync(nsStrToHstr(token).Get(),
                                                         (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getFolderWithOptionsAsync:(NSString*)token
                          options:(WSAAccessCacheOptions)options
                          success:(void (^)(WSStorageFolder*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderWithOptionsAsync(nsStrToHstr(token).Get(),
                                                           (ABI::Windows::Storage::AccessCache::AccessCacheOptions)options,
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)remove:(NSString*)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(nsStrToHstr(token).Get()));
}

- (BOOL)containsItem:(NSString*)token {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->ContainsItem(nsStrToHstr(token).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (BOOL)checkAccess:(RTObject<WSIStorageItem>*)file {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->CheckAccess(_getRtInterface<ABI::Windows::Storage::IStorageItem>(file).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSAAccessListEntryView*)entries {
    ComPtr<IVectorView<ABI::Windows::Storage::AccessCache::AccessListEntry>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Entries(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAAccessListEntryView>(unmarshalledReturn.Get());
}

- (unsigned int)maximumItemsAllowed {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::AccessCache::IStorageItemAccessList>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaximumItemsAllowed(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSAStorageApplicationPermissions

ComPtr<ABI::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> WSAIStorageApplicationPermissionsStatics_inst() {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageApplicationPermissionsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Storage.AccessCache.StorageApplicationPermissions").Get(), &inst));
    return inst;
}

+ (WSAStorageItemAccessList*)futureAccessList {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageItemAccessList> unmarshalledReturn;
    auto _comInst = WSAIStorageApplicationPermissionsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FutureAccessList(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAStorageItemAccessList>(unmarshalledReturn.Get());
}

+ (WSAStorageItemMostRecentlyUsedList*)mostRecentlyUsedList {
    ComPtr<ABI::Windows::Storage::AccessCache::IStorageItemMostRecentlyUsedList> unmarshalledReturn;
    auto _comInst = WSAIStorageApplicationPermissionsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MostRecentlyUsedList(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAStorageItemMostRecentlyUsedList>(unmarshalledReturn.Get());
}

@end

@implementation WSAAccessListEntry {
    ABI::Windows::Storage::AccessCache::AccessListEntry structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Storage::AccessCache::AccessListEntry)s {
    WSAAccessListEntry* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Storage::AccessCache::AccessListEntry*)internalStruct {
    return &structVal;
}
- (NSString*)token {
    return hstrToNSStr(structVal.Token);
}
- (void)setToken:(NSString*)val {
    structVal.Token = nsStrToHstr(val).Detach();
}
- (NSString*)metadata {
    return hstrToNSStr(structVal.Metadata);
}
- (void)setMetadata:(NSString*)val {
    structVal.Metadata = nsStrToHstr(val).Detach();
}
@end
