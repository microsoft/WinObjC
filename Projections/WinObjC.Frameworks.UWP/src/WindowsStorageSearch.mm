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

// WindowsStorageSearch.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.Search.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageSearch.h"
#include "WindowsStorageSearch_priv.h"

@implementation WSSIIndexableContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IIndexableContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMap<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (void)setStream:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (NSString*)streamContentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStreamContentType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreamContentType(nsStrToHstr(value).Get()));
}

@end

@implementation WSSIStorageQueryResultBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageQueryResultBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ContentsChanged(Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContentsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContentsChanged(eventCookie));
}

- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionsChanged(
        Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(changedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionsChanged(eventCookie));
}

- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->FindStartIndexAsync([value comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSSQueryOptions*)getCurrentQueryOptions {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentQueryOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get());
}

- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyNewQueryOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(newQueryOptions).Get()));
}

@end

@implementation WSSIStorageFolderQueryOperations

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageFolderQueryOperations> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getIndexedStateAsyncWithSuccess:(void (^)(WSSIndexedState))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Search::IndexedState>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->GetIndexedStateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Search::IndexedState>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Search::IndexedState>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Storage::Search::IndexedState result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSSIndexedState)result);
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

- (WSSStorageFileQueryResult*)createFileQueryOverloadDefault {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFileQueryOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageFileQueryResult*)createFileQuery:(WSSCommonFileQuery)query {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFileQuery((ABI::Windows::Storage::Search::CommonFileQuery)query, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageFileQueryResult*)createFileQueryWithOptions:(WSSQueryOptions*)queryOptions {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFileQueryWithOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(queryOptions).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageFolderQueryResult*)createFolderQueryOverloadDefault {
    ComPtr<ABI::Windows::Storage::Search::IStorageFolderQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFolderQueryOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFolderQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageFolderQueryResult*)createFolderQuery:(WSSCommonFolderQuery)query {
    ComPtr<ABI::Windows::Storage::Search::IStorageFolderQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFolderQuery((ABI::Windows::Storage::Search::CommonFolderQuery)query, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFolderQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageFolderQueryResult*)createFolderQueryWithOptions:(WSSQueryOptions*)queryOptions {
    ComPtr<ABI::Windows::Storage::Search::IStorageFolderQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFolderQueryWithOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(queryOptions).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFolderQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageItemQueryResult*)createItemQuery {
    ComPtr<ABI::Windows::Storage::Search::IStorageItemQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateItemQuery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageItemQueryResult>(unmarshalledReturn.Get());
}

- (WSSStorageItemQueryResult*)createItemQueryWithOptions:(WSSQueryOptions*)queryOptions {
    ComPtr<ABI::Windows::Storage::Search::IStorageItemQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateItemQueryWithOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(queryOptions).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageItemQueryResult>(unmarshalledReturn.Get());
}

- (void)getFilesAsync:(WSSCommonFileQuery)query
            startIndex:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* WSStorageFile* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsync((ABI::Windows::Storage::Search::CommonFileQuery)query,
                                               startIndex,
                                               maxItemsToRetrieve,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFile*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFile_create(result.Get()));
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

- (void)getFilesAsyncOverloadDefaultStartAndCount:(WSSCommonFileQuery)query
                                          success:(void (^)(NSArray* /* WSStorageFile* */))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetFilesAsyncOverloadDefaultStartAndCount((ABI::Windows::Storage::Search::CommonFileQuery)query, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFile*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFile_create(result.Get()));
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

- (void)getFoldersAsync:(WSSCommonFolderQuery)query
             startIndex:(unsigned int)startIndex
     maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
                success:(void (^)(NSArray* /* WSStorageFolder* */))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsync((ABI::Windows::Storage::Search::CommonFolderQuery)query,
                                                 startIndex,
                                                 maxItemsToRetrieve,
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFolder*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFolder*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFolder_create(result.Get()));
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

- (void)getFoldersAsyncOverloadDefaultStartAndCount:(WSSCommonFolderQuery)query
                                            success:(void (^)(NSArray* /* WSStorageFolder* */))success
                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsyncOverloadDefaultStartAndCount((ABI::Windows::Storage::Search::CommonFolderQuery)query,
                                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFolder*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFolder*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFolder_create(result.Get()));
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

- (void)getItemsAsync:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsync(startIndex, maxItemsToRetrieve, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::IStorageItem*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::IStorageItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WSIStorageItem_create(result.Get()));
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

- (BOOL)areQueryOptionsSupported:(WSSQueryOptions*)queryOptions {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->AreQueryOptionsSupported(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(queryOptions).Get(),
                                                          &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCommonFolderQuerySupported:(WSSCommonFolderQuery)query {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsCommonFolderQuerySupported((ABI::Windows::Storage::Search::CommonFolderQuery)query, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCommonFileQuerySupported:(WSSCommonFileQuery)query {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->IsCommonFileQuerySupported((ABI::Windows::Storage::Search::CommonFileQuery)query, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSSContentIndexer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::Search::IContentIndexerStatics> WSSIContentIndexerStatics_inst() {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Search.ContentIndexer").Get(), &inst));
    return inst;
}

+ (WSSContentIndexer*)getIndexerWithName:(NSString*)indexName {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexer> unmarshalledReturn;
    auto _comInst = WSSIContentIndexerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIndexerWithName(nsStrToHstr(indexName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSContentIndexer>(unmarshalledReturn.Get());
}

+ (WSSContentIndexer*)getIndexer {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexer> unmarshalledReturn;
    auto _comInst = WSSIContentIndexerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetIndexer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSContentIndexer>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)addAsync:(RTObject<WSSIIndexableContent>*)indexableContent {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->AddAsync(_getRtInterface<ABI::Windows::Storage::Search::IIndexableContent>(indexableContent).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)updateAsync:(RTObject<WSSIIndexableContent>*)indexableContent {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAsync(_getRtInterface<ABI::Windows::Storage::Search::IIndexableContent>(indexableContent).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync:(NSString*)contentId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(nsStrToHstr(contentId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteMultipleAsync:(id<NSFastEnumeration> /* NSString * */)contentIds {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeleteMultipleAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                          ConvertToIterable<NSString, HSTRING>(contentIds).Get()),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAllAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAllAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)retrievePropertiesAsync:(NSString*)contentId
           propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        nsStrToHstr(contentId).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMapView<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMapView<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMapView<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSDictionary_NSString_RTObject_create(result.Get()));
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

- (uint64_t)revision {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Revision(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSContentIndexerQuery*)createQueryWithSortOrderAndLanguage:(NSString*)searchFilter
                                          propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                                                     sortOrder:(id<NSFastEnumeration> /* WSSSortEntry* */)sortOrder
                                          searchFilterLanguage:(NSString*)searchFilterLanguage {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexerQuery> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateQueryWithSortOrderAndLanguage(
        nsStrToHstr(searchFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        static_cast<
            IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Storage::Search::SortEntry>::type>*>(
            ConvertToIterable<WSSSortEntry, ABI::Windows::Storage::Search::SortEntry>(sortOrder).Get()),
        nsStrToHstr(searchFilterLanguage).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSContentIndexerQuery>(unmarshalledReturn.Get());
}

- (WSSContentIndexerQuery*)createQueryWithSortOrder:(NSString*)searchFilter
                               propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                                          sortOrder:(id<NSFastEnumeration> /* WSSSortEntry* */)sortOrder {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexerQuery> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQueryOperations>(self);
    THROW_NS_IF_FAILED(_comInst->CreateQueryWithSortOrder(
        nsStrToHstr(searchFilter).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        static_cast<
            IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Storage::Search::SortEntry>::type>*>(
            ConvertToIterable<WSSSortEntry, ABI::Windows::Storage::Search::SortEntry>(sortOrder).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSContentIndexerQuery>(unmarshalledReturn.Get());
}

- (WSSContentIndexerQuery*)createQuery:(NSString*)searchFilter
                  propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexerQuery> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQueryOperations>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateQuery(nsStrToHstr(searchFilter).Get(),
                              static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                  ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSContentIndexerQuery>(unmarshalledReturn.Get());
}

@end

@implementation WSSValueAndLanguage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IValueAndLanguage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Search.ValueAndLanguage").Get(), &out));
    return [_createRtProxy<WSSValueAndLanguage>(out.Get()) retain];
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IValueAndLanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IValueAndLanguage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IValueAndLanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IValueAndLanguage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value([value comObj].Get()));
}

@end

@implementation WSSContentIndexerQuery

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IContentIndexerQuery> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->GetCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (void)getPropertiesAsyncWithSuccess:(void (^)(NSArray* /* NSDictionary* < NSString *, RTObject* > */))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<IMapView<HSTRING, IInspectable*>*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<IMapView<HSTRING, IInspectable*>*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<IMapView<HSTRING, IInspectable*>*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<IMapView<HSTRING, IInspectable*>*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(result.Get()));
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

- (void)getPropertiesRangeAsync:(unsigned int)startIndex
                       maxItems:(unsigned int)maxItems
                        success:(void (^)(NSArray* /* NSDictionary* < NSString *, RTObject* > */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<IMapView<HSTRING, IInspectable*>*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertiesRangeAsync(startIndex, maxItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<IMapView<HSTRING, IInspectable*>*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<IMapView<HSTRING, IInspectable*>*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<IMapView<HSTRING, IInspectable*>*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(result.Get()));
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

- (void)getAsyncWithSuccess:(void (^)(NSArray* /* RTObject<WSSIIndexableContent>* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->GetAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WSSIIndexableContent_create(result.Get()));
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

- (void)getRangeAsync:(unsigned int)startIndex
             maxItems:(unsigned int)maxItems
              success:(void (^)(NSArray* /* RTObject<WSSIIndexableContent>* */))success
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->GetRangeAsync(startIndex, maxItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WSSIIndexableContent_create(result.Get()));
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

- (WSStorageFolder*)queryFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IContentIndexerQuery>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueryFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

@end

@implementation WSSIndexableContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IIndexableContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Search.IndexableContent").Get(), &out));
    return [_createRtProxy<WSSIndexableContent>(out.Get()) retain];
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMap<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (void)setStream:(RTObject<WSSIRandomAccessStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(value).Get()));
}

- (NSString*)streamContentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setStreamContentType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IIndexableContent>(self);
    THROW_NS_IF_FAILED(_comInst->put_StreamContentType(nsStrToHstr(value).Get()));
}

@end

@implementation WSSQueryOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Storage::Search::IQueryOptionsFactory> WSSIQueryOptionsFactory_inst() {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptionsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Search.QueryOptions").Get(), &inst));
    return inst;
}

+ (WSSQueryOptions*)makeCommonFileQuery:(WSSCommonFileQuery)query fileTypeFilter:(id<NSFastEnumeration> /* NSString * */)fileTypeFilter {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = WSSIQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateCommonFileQuery((ABI::Windows::Storage::Search::CommonFileQuery)query,
                                        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(fileTypeFilter).Get()),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get()) retain];
}

+ (WSSQueryOptions*)makeCommonFolderQuery:(WSSCommonFolderQuery)query {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = WSSIQueryOptionsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateCommonFolderQuery((ABI::Windows::Storage::Search::CommonFolderQuery)query, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Search.QueryOptions").Get(), &out));
    return [_createRtProxy<WSSQueryOptions>(out.Get()) retain];
}

- (NSMutableArray* /* NSString * */)fileTypeFilter {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypeFilter(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WSSFolderDepth)folderDepth {
    ABI::Windows::Storage::Search::FolderDepth unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FolderDepth(&unmarshalledReturn));
    return (WSSFolderDepth)unmarshalledReturn;
}

- (void)setFolderDepth:(WSSFolderDepth)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FolderDepth((ABI::Windows::Storage::Search::FolderDepth)value));
}

- (NSString*)applicationSearchFilter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationSearchFilter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setApplicationSearchFilter:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationSearchFilter(nsStrToHstr(value).Get()));
}

- (NSString*)userSearchFilter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserSearchFilter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUserSearchFilter:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserSearchFilter(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WSSIndexerOption)indexerOption {
    ABI::Windows::Storage::Search::IndexerOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IndexerOption(&unmarshalledReturn));
    return (WSSIndexerOption)unmarshalledReturn;
}

- (void)setIndexerOption:(WSSIndexerOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IndexerOption((ABI::Windows::Storage::Search::IndexerOption)value));
}

- (NSMutableArray* /* WSSSortEntry* */)sortOrder {
    ComPtr<IVector<ABI::Windows::Storage::Search::SortEntry>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SortOrder(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSSSortEntry_create(unmarshalledReturn.Get());
}

- (NSString*)groupPropertyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GroupPropertyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSSDateStackOption)dateStackOption {
    ABI::Windows::Storage::Search::DateStackOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateStackOption(&unmarshalledReturn));
    return (WSSDateStackOption)unmarshalledReturn;
}

- (NSString*)saveToString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->SaveToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)loadFromString:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->LoadFromString(nsStrToHstr(value).Get()));
}

- (void)setThumbnailPrefetch:(WSFThumbnailMode)mode requestedSize:(unsigned int)requestedSize options:(WSFThumbnailOptions)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(_comInst->SetThumbnailPrefetch((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                      requestedSize,
                                                      (ABI::Windows::Storage::FileProperties::ThumbnailOptions)options));
}

- (void)setPropertyPrefetch:(WSFPropertyPrefetchOptions)options
       propertiesToRetrieve:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptions>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPropertyPrefetch((ABI::Windows::Storage::FileProperties::PropertyPrefetchOptions)options,
                                      static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                          ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get())));
}

- (NSMutableArray* /* NSString * */)storageProviderIdFilter {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IQueryOptionsWithProviderFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_StorageProviderIdFilter(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSSStorageFileQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getFilesAsync:(unsigned int)startIndex
     maxNumberOfItems:(unsigned int)maxNumberOfItems
              success:(void (^)(NSArray* /* WSStorageFile* */))success
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFileQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsync(startIndex, maxNumberOfItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFile*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFile_create(result.Get()));
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

- (void)getFilesAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFileQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFile*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFile_create(result.Get()));
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

- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ContentsChanged(Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContentsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContentsChanged(eventCookie));
}

- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionsChanged(
        Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(changedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionsChanged(eventCookie));
}

- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->FindStartIndexAsync([value comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSSQueryOptions*)getCurrentQueryOptions {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentQueryOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get());
}

- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyNewQueryOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(newQueryOptions).Get()));
}

- (NSMutableDictionary* /* NSString *, NSArray* < WDTTextSegment* > */)getMatchingPropertiesWithRanges:(WSStorageFile*)file {
    ComPtr<IMap<HSTRING, IVectorView<ABI::Windows::Data::Text::TextSegment>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFileQueryResult2>(self);
    THROW_NS_IF_FAILED(_comInst->GetMatchingPropertiesWithRanges(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                                 unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_RTProxiedNSArray_WDTTextSegment_create(unmarshalledReturn.Get());
}

@end

@implementation WSSStorageFolderQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageFolderQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getFoldersAsync:(unsigned int)startIndex
       maxNumberOfItems:(unsigned int)maxNumberOfItems
                success:(void (^)(NSArray* /* WSStorageFolder* */))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsync(startIndex, maxNumberOfItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFolder*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFolder*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFolder_create(result.Get()));
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

- (void)getFoldersAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFolder* */))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageFolderQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageFolder*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::StorageFolder*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSStorageFolder_create(result.Get()));
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

- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ContentsChanged(Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContentsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContentsChanged(eventCookie));
}

- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionsChanged(
        Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(changedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionsChanged(eventCookie));
}

- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->FindStartIndexAsync([value comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSSQueryOptions*)getCurrentQueryOptions {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentQueryOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get());
}

- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyNewQueryOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(newQueryOptions).Get()));
}

@end

@implementation WSSStorageItemQueryResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageItemQueryResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getItemsAsync:(unsigned int)startIndex
     maxNumberOfItems:(unsigned int)maxNumberOfItems
              success:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageItemQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsync(startIndex, maxNumberOfItems, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::IStorageItem*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::IStorageItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WSIStorageItem_create(result.Get()));
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

- (void)getItemsAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageItemQueryResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::IStorageItem*>*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Storage::IStorageItem*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_RTObject_WSIStorageItem_create(result.Get()));
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

- (void)getItemCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemCountAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addContentsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ContentsChanged(Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContentsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContentsChanged(eventCookie));
}

- (EventRegistrationToken)addOptionsChangedEvent:(void (^)(RTObject<WSSIStorageQueryResultBase>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_OptionsChanged(
        Make<ITypedEventHandler_Windows_Storage_Search_IStorageQueryResultBase_System_Object>(changedHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOptionsChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OptionsChanged(eventCookie));
}

- (void)findStartIndexAsync:(RTObject*)value success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->FindStartIndexAsync([value comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<unsigned int>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<unsigned int>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        unsigned int result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

- (WSSQueryOptions*)getCurrentQueryOptions {
    ComPtr<ABI::Windows::Storage::Search::IQueryOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentQueryOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSQueryOptions>(unmarshalledReturn.Get());
}

- (void)applyNewQueryOptions:(WSSQueryOptions*)newQueryOptions {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyNewQueryOptions(_getRtInterface<ABI::Windows::Storage::Search::IQueryOptions>(newQueryOptions).Get()));
}

@end

@implementation WSSSortEntryVector {
    RTMutableArrayObj<ABI::Windows::Storage::Search::SortEntry,
                      IVector<ABI::Windows::Storage::Search::SortEntry>,
                      WSSSortEntry,
                      ABI::Windows::Storage::Search::SortEntry,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WSSSortEntry, ABI::Windows::Storage::Search::SortEntry, ABI::Windows::Storage::Search::SortEntry)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::Storage::Search::SortEntry>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSSStorageLibraryContentChangedTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageFolder*)folder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (WSSStorageItemQueryResult*)createModifiedSinceQuery:(WFDateTime*)lastQueryTime {
    ComPtr<ABI::Windows::Storage::Search::IStorageItemQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Search::IStorageLibraryContentChangedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->CreateModifiedSinceQuery(*[lastQueryTime internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageItemQueryResult>(unmarshalledReturn.Get());
}

@end

@implementation WSSSortEntry {
    ABI::Windows::Storage::Search::SortEntry structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Storage::Search::SortEntry)s {
    WSSSortEntry* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Storage::Search::SortEntry*)internalStruct {
    return &structVal;
}
- (NSString*)propertyName {
    return hstrToNSStr(structVal.PropertyName);
}
- (void)setPropertyName:(NSString*)val {
    structVal.PropertyName = nsStrToHstr(val).Detach();
}
- (BOOL)ascendingOrder {
    return (BOOL)structVal.AscendingOrder;
}
- (void)setAscendingOrder:(BOOL)val {
    structVal.AscendingOrder = (boolean)val;
}
@end
id RTProxiedIterableNSArray_WSSSortEntry_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Storage::Search::SortEntry>,
                                                 RTIterableObj<ABI::Windows::Storage::Search::SortEntry,
                                                               IIterable<ABI::Windows::Storage::Search::SortEntry>,
                                                               WSSSortEntry,
                                                               ABI::Windows::Storage::Search::SortEntry,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WSSIIndexableContent_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>,
                                         RTArrayObj<ABI::Windows::Storage::Search::IIndexableContent*,
                                                    IVectorView<ABI::Windows::Storage::Search::IIndexableContent*>,
                                                    RTObject<WSSIIndexableContent>,
                                                    ABI::Windows::Storage::Search::IIndexableContent*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<IMapView_HSTRING_IInspectablePtr_Ptr>,
                        RTArrayObj<IMapView_HSTRING_IInspectablePtr_Ptr,
                                   IVectorView<IMapView_HSTRING_IInspectablePtr_Ptr>,
                                   RTProxiedNSDictionary,
                                   IMapView_HSTRING_IInspectablePtr_Ptr,
                                   RTProxiedNSDictionary_NSString_RTObject_create,
                                   ConvertToVectorView<RTProxiedNSDictionary,
                                                       ABI::Windows::Foundation::Internal::AggregateType<IMapView<HSTRING, IInspectable*>*,
                                                                                                         IMapView<HSTRING, IInspectable*>*>,
                                                       RTProxiedNSDictionary_NSString_RTObject_create>>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                             RTArrayObj<ABI::Windows::Data::Text::TextSegment,
                                                                                        IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                                        WDTTextSegment,
                                                                                        ABI::Windows::Data::Text::TextSegment,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSSSortEntry_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Storage::Search::SortEntry>,
                                                RTMutableArrayObj<ABI::Windows::Storage::Search::SortEntry,
                                                                  IVector<ABI::Windows::Storage::Search::SortEntry>,
                                                                  WSSSortEntry,
                                                                  ABI::Windows::Storage::Search::SortEntry,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, IInspectable*>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             IInspectable*,
                                             IInspectable*,
                                             NSString,
                                             RTObject,
                                             IMap<HSTRING, IInspectable*>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_RTProxiedNSArray_WDTTextSegment_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, IVectorView<ABI::Windows::Data::Text::TextSegment>*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IVectorView<ABI::Windows::Data::Text::TextSegment>*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 IVectorView<ABI::Windows::Data::Text::TextSegment>*,
                 IVectorView<ABI::Windows::Data::Text::TextSegment>*,
                 NSString,
                 RTProxiedNSArray,
                 IMap<HSTRING, IVectorView<ABI::Windows::Data::Text::TextSegment>*>,
                 dummyObjCCreator,
                 RTProxiedNSArray_WDTTextSegment_create,
                 dummyWRLCreator,
                 ConvertToVectorView<WDTTextSegment, ABI::Windows::Data::Text::TextSegment>>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
