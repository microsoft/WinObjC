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

// WindowsStorageBulkAccess.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.BulkAccess.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageBulkAccess.h"
#include "WindowsStorageBulkAccess_priv.h"

@implementation WSBIStorageItemInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::BulkAccess::IStorageItemInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSFMusicProperties*)musicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFMusicProperties>(unmarshalledReturn.Get());
}

- (WSFVideoProperties*)videoProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFVideoProperties>(unmarshalledReturn.Get());
}

- (WSFImageProperties*)imageProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IImageProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFImageProperties>(unmarshalledReturn.Get());
}

- (WSFDocumentProperties*)documentProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IDocumentProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFDocumentProperties>(unmarshalledReturn.Get());
}

- (WSFBasicProperties*)basicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BasicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFBasicProperties>(unmarshalledReturn.Get());
}

- (WSFStorageItemThumbnail*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFStorageItemThumbnail>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_ThumbnailUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ThumbnailUpdated(eventCookie));
}

- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesUpdated(eventCookie));
}

@end

@implementation WSBFileInformationFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactoryFactory> WSBIFileInformationFactoryFactory_inst() {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactoryFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.BulkAccess.FileInformationFactory").Get(),
                                                       &inst));
    return inst;
}

+ (WSBFileInformationFactory*)makeWithMode:(RTObject<WSSIStorageQueryResultBase>*)queryResult mode:(WSFThumbnailMode)mode {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactory> unmarshalledReturn;
    auto _comInst = WSBIFileInformationFactoryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithMode(_getRtInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(queryResult).Get(),
                                                (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSBFileInformationFactory>(unmarshalledReturn.Get()) retain];
}

+ (WSBFileInformationFactory*)makeWithModeAndSize:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                             mode:(WSFThumbnailMode)mode
                           requestedThumbnailSize:(unsigned int)requestedThumbnailSize {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactory> unmarshalledReturn;
    auto _comInst = WSBIFileInformationFactoryFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithModeAndSize(_getRtInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(queryResult).Get(),
                                        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                        requestedThumbnailSize,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSBFileInformationFactory>(unmarshalledReturn.Get()) retain];
}

+ (WSBFileInformationFactory*)makeWithModeAndSizeAndOptions:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                                       mode:(WSFThumbnailMode)mode
                                     requestedThumbnailSize:(unsigned int)requestedThumbnailSize
                                           thumbnailOptions:(WSFThumbnailOptions)thumbnailOptions {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactory> unmarshalledReturn;
    auto _comInst = WSBIFileInformationFactoryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithModeAndSizeAndOptions(
        _getRtInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(queryResult).Get(),
        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
        requestedThumbnailSize,
        (ABI::Windows::Storage::FileProperties::ThumbnailOptions)thumbnailOptions,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSBFileInformationFactory>(unmarshalledReturn.Get()) retain];
}

+ (WSBFileInformationFactory*)makeWithModeAndSizeAndOptionsAndFlags:(RTObject<WSSIStorageQueryResultBase>*)queryResult
                                                               mode:(WSFThumbnailMode)mode
                                             requestedThumbnailSize:(unsigned int)requestedThumbnailSize
                                                   thumbnailOptions:(WSFThumbnailOptions)thumbnailOptions
                                                          delayLoad:(BOOL)delayLoad {
    ComPtr<ABI::Windows::Storage::BulkAccess::IFileInformationFactory> unmarshalledReturn;
    auto _comInst = WSBIFileInformationFactoryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithModeAndSizeAndOptionsAndFlags(
        _getRtInterface<ABI::Windows::Storage::Search::IStorageQueryResultBase>(queryResult).Get(),
        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
        requestedThumbnailSize,
        (ABI::Windows::Storage::FileProperties::ThumbnailOptions)thumbnailOptions,
        (boolean)delayLoad,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSBFileInformationFactory>(unmarshalledReturn.Get()) retain];
}

- (void)getItemsAsync:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* RTObject<WSBIStorageItemInformation>* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsync(startIndex, maxItemsToRetrieve, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WSBIStorageItemInformation_create(result.Get()));
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

- (void)getItemsAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSBIStorageItemInformation>* */))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_RTObject_WSBIStorageItemInformation_create(result.Get()));
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

- (void)getFilesAsync:(unsigned int)startIndex
    maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
               success:(void (^)(NSArray* /* WSBFileInformation* */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsync(startIndex, maxItemsToRetrieve, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSBFileInformation_create(result.Get()));
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

- (void)getFilesAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSBFileInformation* */))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSBFileInformation_create(result.Get()));
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

- (void)getFoldersAsync:(unsigned int)startIndex
     maxItemsToRetrieve:(unsigned int)maxItemsToRetrieve
                success:(void (^)(NSArray* /* WSBFolderInformation* */))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsync(startIndex, maxItemsToRetrieve, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSBFolderInformation_create(result.Get()));
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

- (void)getFoldersAsyncDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* WSBFolderInformation* */))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsyncDefaultStartAndCount(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSBFolderInformation_create(result.Get()));
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

- (RTObject*)getVirtualizedItemsVector {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetVirtualizedItemsVector(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getVirtualizedFilesVector {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetVirtualizedFilesVector(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)getVirtualizedFoldersVector {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IFileInformationFactory>(self);
    THROW_NS_IF_FAILED(_comInst->GetVirtualizedFoldersVector(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WSBFileInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::BulkAccess::IStorageItemInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSFMusicProperties*)musicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFMusicProperties>(unmarshalledReturn.Get());
}

- (WSFVideoProperties*)videoProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFVideoProperties>(unmarshalledReturn.Get());
}

- (WSFImageProperties*)imageProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IImageProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFImageProperties>(unmarshalledReturn.Get());
}

- (WSFDocumentProperties*)documentProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IDocumentProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFDocumentProperties>(unmarshalledReturn.Get());
}

- (WSFBasicProperties*)basicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BasicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFBasicProperties>(unmarshalledReturn.Get());
}

- (WSFStorageItemThumbnail*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFStorageItemThumbnail>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_ThumbnailUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ThumbnailUpdated(eventCookie));
}

- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesUpdated(eventCookie));
}

- (NSString*)fileType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)openAsync:(WSFileAccessMode)accessMode
          success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->OpenAsync((ABI::Windows::Storage::FileAccessMode)accessMode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (void)openTransactedWriteAsyncWithSuccess:(void (^)(WSStorageStreamTransaction*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageStreamTransaction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->OpenTransactedWriteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageStreamTransaction*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageStreamTransaction*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::IStorageStreamTransaction> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSStorageStreamTransaction>(result.Get()));
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

- (void)copyOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                  success:(void (^)(WSStorageFile*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(
        _comInst->CopyOverloadDefaultNameAndOptions(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
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

- (void)copyOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                    desiredNewName:(NSString*)desiredNewName
                           success:(void (^)(WSStorageFile*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->CopyOverloadDefaultOptions(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
                                                            nsStrToHstr(desiredNewName).Get(),
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

- (void)copyOverload:(RTObject<WSIStorageFolder>*)destinationFolder
      desiredNewName:(NSString*)desiredNewName
              option:(WSNameCollisionOption)option
             success:(void (^)(WSStorageFile*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->CopyOverload(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
                                              nsStrToHstr(desiredNewName).Get(),
                                              (ABI::Windows::Storage::NameCollisionOption)option,
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

- (RTObject<WFIAsyncAction>*)copyAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->CopyAndReplaceAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(fileToReplace).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)moveOverloadDefaultNameAndOptions:(RTObject<WSIStorageFolder>*)destinationFolder {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(
        _comInst->MoveOverloadDefaultNameAndOptions(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)moveOverloadDefaultOptions:(RTObject<WSIStorageFolder>*)destinationFolder
                                         desiredNewName:(NSString*)desiredNewName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->MoveOverloadDefaultOptions(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
                                                            nsStrToHstr(desiredNewName).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)moveOverload:(RTObject<WSIStorageFolder>*)destinationFolder
                           desiredNewName:(NSString*)desiredNewName
                                   option:(WSNameCollisionOption)option {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->MoveOverload(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(destinationFolder).Get(),
                                              nsStrToHstr(desiredNewName).Get(),
                                              (ABI::Windows::Storage::NameCollisionOption)option,
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)moveAndReplaceAsync:(RTObject<WSIStorageFile>*)fileToReplace {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile>(self);
    THROW_NS_IF_FAILED(_comInst->MoveAndReplaceAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(fileToReplace).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->RenameAsyncOverloadDefaultOptions(nsStrToHstr(desiredName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->RenameAsync(nsStrToHstr(desiredName).Get(),
                                             (ABI::Windows::Storage::NameCollisionOption)option,
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsyncOverloadDefaultOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync((ABI::Windows::Storage::StorageDeleteOption)option, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::BasicProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->GetBasicPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::BasicProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::BasicProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFBasicProperties>(result.Get()));
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

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSFileAttributes)attributes {
    ABI::Windows::Storage::FileAttributes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(&unmarshalledReturn));
    return (WSFileAttributes)unmarshalledReturn;
}

- (WFDateTime*)dateCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (BOOL)isOfType:(WSStorageItemTypes)type {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->IsOfType((ABI::Windows::Storage::StorageItemTypes)type, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReadAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStreamWithContentType>(result.Get()));
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

- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IInputStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IInputStreamReference>(self);
    THROW_NS_IF_FAILED(_comInst->OpenSequentialReadAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IInputStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetThumbnailAsyncOverloadDefaultSizeDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned int)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsyncOverloadDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                                         requestedSize,
                                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned int)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                   requestedSize,
                                                   (ABI::Windows::Storage::FileProperties::ThumbnailOptions)options,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)folderRelativeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FolderRelativeId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSFStorageItemContentProperties*)properties {
    ComPtr<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFStorageItemContentProperties>(unmarshalledReturn.Get());
}

- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem2>(self);
    THROW_NS_IF_FAILED(_comInst->GetParentAsync(&unmarshalledReturn));

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

- (BOOL)IsEqual:(RTObject<WSIStorageItem>*)item {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem2>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::Storage::IStorageItem>(item).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSStorageProvider*)provider {
    ComPtr<ABI::Windows::Storage::IStorageProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemPropertiesWithProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Provider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageProvider>(unmarshalledReturn.Get());
}

- (BOOL)isAvailable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFilePropertiesWithAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)openWithOptionsAsync:(WSFileAccessMode)accessMode
                     options:(WSStorageOpenOptions)options
                     success:(void (^)(RTObject<WSSIRandomAccessStream>*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile2>(self);
    THROW_NS_IF_FAILED(_comInst->OpenWithOptionsAsync((ABI::Windows::Storage::FileAccessMode)accessMode,
                                                      (ABI::Windows::Storage::StorageOpenOptions)options,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStream*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStream*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStream>(result.Get()));
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

- (void)openTransactedWriteWithOptionsAsync:(WSStorageOpenOptions)options
                                    success:(void (^)(WSStorageStreamTransaction*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageStreamTransaction*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFile2>(self);
    THROW_NS_IF_FAILED(
        _comInst->OpenTransactedWriteWithOptionsAsync((ABI::Windows::Storage::StorageOpenOptions)options, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageStreamTransaction*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageStreamTransaction*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::IStorageStreamTransaction> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSStorageStreamTransaction>(result.Get()));
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

@end

@implementation WSBFolderInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::BulkAccess::IStorageItemInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSFMusicProperties*)musicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFMusicProperties>(unmarshalledReturn.Get());
}

- (WSFVideoProperties*)videoProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFVideoProperties>(unmarshalledReturn.Get());
}

- (WSFImageProperties*)imageProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IImageProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFImageProperties>(unmarshalledReturn.Get());
}

- (WSFDocumentProperties*)documentProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IDocumentProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFDocumentProperties>(unmarshalledReturn.Get());
}

- (WSFBasicProperties*)basicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_BasicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFBasicProperties>(unmarshalledReturn.Get());
}

- (WSFStorageItemThumbnail*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFStorageItemThumbnail>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addThumbnailUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_ThumbnailUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeThumbnailUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ThumbnailUpdated(eventCookie));
}

- (EventRegistrationToken)addPropertiesUpdatedEvent:(void (^)(RTObject<WSBIStorageItemInformation>*, RTObject*))changedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertiesUpdated(
        Make<ITypedEventHandler_Windows_Storage_BulkAccess_IStorageItemInformation_System_Object>(changedHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertiesUpdatedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::BulkAccess::IStorageItemInformation>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertiesUpdated(eventCookie));
}

- (void)createFileAsyncOverloadDefaultOptions:(NSString*)desiredName
                                      success:(void (^)(WSStorageFile*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFileAsyncOverloadDefaultOptions(nsStrToHstr(desiredName).Get(), &unmarshalledReturn));

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

- (void)createFileAsync:(NSString*)desiredName
                options:(WSCreationCollisionOption)options
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFileAsync(nsStrToHstr(desiredName).Get(),
                                                 (ABI::Windows::Storage::CreationCollisionOption)options,
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

- (void)createFolderAsyncOverloadDefaultOptions:(NSString*)desiredName
                                        success:(void (^)(WSStorageFolder*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFolderAsyncOverloadDefaultOptions(nsStrToHstr(desiredName).Get(), &unmarshalledReturn));

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

- (void)createFolderAsync:(NSString*)desiredName
                  options:(WSCreationCollisionOption)options
                  success:(void (^)(WSStorageFolder*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFolderAsync(nsStrToHstr(desiredName).Get(),
                                                   (ABI::Windows::Storage::CreationCollisionOption)options,
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

- (void)getFileAsync:(NSString*)name success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetFileAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

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

- (void)getFolderAsync:(NSString*)name success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetFolderAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

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

- (void)getItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

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

- (void)getFilesAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success
                                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetFilesAsyncOverloadDefaultOptionsStartAndCount(&unmarshalledReturn));

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

- (void)getFoldersAsyncOverloadDefaultOptionsStartAndCountWithSuccess:(void (^)(NSArray* /* WSStorageFolder* */))success
                                                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFolder*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetFoldersAsyncOverloadDefaultOptionsStartAndCount(&unmarshalledReturn));

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

- (void)getItemsAsyncOverloadDefaultStartAndCountWithSuccess:(void (^)(NSArray* /* RTObject<WSIStorageItem>* */))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::IStorageItem*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemsAsyncOverloadDefaultStartAndCount(&unmarshalledReturn));

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

- (RTObject<WFIAsyncAction>*)renameAsyncOverloadDefaultOptions:(NSString*)desiredName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->RenameAsyncOverloadDefaultOptions(nsStrToHstr(desiredName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)renameAsync:(NSString*)desiredName option:(WSNameCollisionOption)option {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->RenameAsync(nsStrToHstr(desiredName).Get(),
                                             (ABI::Windows::Storage::NameCollisionOption)option,
                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsyncOverloadDefaultOptions {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsyncOverloadDefaultOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deleteAsync:(WSStorageDeleteOption)option {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync((ABI::Windows::Storage::StorageDeleteOption)option, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getBasicPropertiesAsyncWithSuccess:(void (^)(WSFBasicProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::BasicProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->GetBasicPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::BasicProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::BasicProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFBasicProperties>(result.Get()));
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

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSFileAttributes)attributes {
    ABI::Windows::Storage::FileAttributes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attributes(&unmarshalledReturn));
    return (WSFileAttributes)unmarshalledReturn;
}

- (WFDateTime*)dateCreated {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateCreated(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (BOOL)isOfType:(WSStorageItemTypes)type {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem>(self);
    THROW_NS_IF_FAILED(_comInst->IsOfType((ABI::Windows::Storage::StorageItemTypes)type, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                   success:(void (^)(WSFStorageItemThumbnail*))success
                                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetThumbnailAsyncOverloadDefaultSizeDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (void)getThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                  requestedSize:(unsigned int)requestedSize
                                        success:(void (^)(WSFStorageItemThumbnail*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsyncOverloadDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                                         requestedSize,
                                                                         &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (void)getThumbnailAsync:(WSFThumbnailMode)mode
            requestedSize:(unsigned int)requestedSize
                  options:(WSFThumbnailOptions)options
                  success:(void (^)(WSFStorageItemThumbnail*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
                                                   requestedSize,
                                                   (ABI::Windows::Storage::FileProperties::ThumbnailOptions)options,
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFStorageItemThumbnail>(result.Get()));
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

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)folderRelativeId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FolderRelativeId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSFStorageItemContentProperties*)properties {
    ComPtr<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFStorageItemContentProperties>(unmarshalledReturn.Get());
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

- (void)getParentAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem2>(self);
    THROW_NS_IF_FAILED(_comInst->GetParentAsync(&unmarshalledReturn));

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

- (BOOL)IsEqual:(RTObject<WSIStorageItem>*)item {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItem2>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::Storage::IStorageItem>(item).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)tryGetItemAsync:(NSString*)name success:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFolder2>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetItemAsync(nsStrToHstr(name).Get(), &unmarshalledReturn));

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

- (WSStorageProvider*)provider {
    ComPtr<ABI::Windows::Storage::IStorageProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemPropertiesWithProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Provider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageProvider>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_WSBIStorageItemInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>,
                                         RTArrayObj<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*,
                                                    IVectorView<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*>,
                                                    RTObject<WSBIStorageItemInformation>,
                                                    ABI::Windows::Storage::BulkAccess::IStorageItemInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageItem*,
                                                                                        IVectorView<ABI::Windows::Storage::IStorageItem*>,
                                                                                        RTObject<WSIStorageItem>,
                                                                                        ABI::Windows::Storage::IStorageItem*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSBFileInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>,
                                         RTArrayObj<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*,
                                                    IVectorView<ABI::Windows::Storage::BulkAccess::FileInformation*>,
                                                    WSBFileInformation,
                                                    ABI::Windows::Storage::BulkAccess::FileInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSBFolderInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>,
                                         RTArrayObj<ABI::Windows::Storage::BulkAccess::IStorageItemInformation*,
                                                    IVectorView<ABI::Windows::Storage::BulkAccess::FolderInformation*>,
                                                    WSBFolderInformation,
                                                    ABI::Windows::Storage::BulkAccess::FolderInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSStorageFile_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageFile*,
                                                                                        IVectorView<ABI::Windows::Storage::StorageFile*>,
                                                                                        WSStorageFile,
                                                                                        ABI::Windows::Storage::StorageFile*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSStorageFolder_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::StorageFolder*>,
                                                                             RTArrayObj<ABI::Windows::Storage::IStorageFolder*,
                                                                                        IVectorView<ABI::Windows::Storage::StorageFolder*>,
                                                                                        WSStorageFolder,
                                                                                        ABI::Windows::Storage::StorageFolder*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
