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

// WindowsStorage.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorage.h"
#include "WindowsStorage_priv.h"

@implementation WSIStorageItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStreamedFileDataRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStreamedFileDataRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)failAndClose:(WSStreamedFileFailureMode)failureMode {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStreamedFileDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->FailAndClose((ABI::Windows::Storage::StreamedFileFailureMode)failureMode));
}

@end

@implementation WSIStorageFolder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFolder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStorageFile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStorageItem2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageItem2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStorageItemProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageItemProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStorageItemProperties2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageItemProperties2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions(
        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode, &unmarshalledReturn));

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

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned int)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned int)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsync((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

@end

@implementation WSIStorageItemPropertiesWithProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageItemPropertiesWithProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageProvider*)provider {
    ComPtr<ABI::Windows::Storage::IStorageProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemPropertiesWithProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Provider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageProvider>(unmarshalledReturn.Get());
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

@end

@implementation WSIStorageFilePropertiesWithAvailability

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFilePropertiesWithAvailability> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isAvailable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageFilePropertiesWithAvailability>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSIStorageFolder2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFolder2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@end

@implementation WSIStorageFile2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFile2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@implementation WSStorageLibrary

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageLibrary> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::IStorageLibraryStatics> WSIStorageLibraryStatics_inst() {
    ComPtr<ABI::Windows::Storage::IStorageLibraryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.StorageLibrary").Get(), &inst));
    return inst;
}

+ (void)getLibraryAsync:(WSKnownLibraryId)libraryId success:(void (^)(WSStorageLibrary*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageLibrary*>> unmarshalledReturn;
    auto _comInst = WSIStorageLibraryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLibraryAsync((ABI::Windows::Storage::KnownLibraryId)libraryId, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageLibrary*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageLibrary*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageLibrary> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageLibrary>(result.Get()));
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

ComPtr<ABI::Windows::Storage::IStorageLibraryStatics2> WSIStorageLibraryStatics2_inst() {
    ComPtr<ABI::Windows::Storage::IStorageLibraryStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.StorageLibrary").Get(), &inst));
    return inst;
}

+ (void)getLibraryForUserAsync:(WSUser*)user
                     libraryId:(WSKnownLibraryId)libraryId
                       success:(void (^)(WSStorageLibrary*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageLibrary*>> unmarshalledReturn;
    auto _comInst = WSIStorageLibraryStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetLibraryForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                        (ABI::Windows::Storage::KnownLibraryId)libraryId,
                                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageLibrary*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageLibrary*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageLibrary> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageLibrary>(result.Get()));
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

- (void)requestAddFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAddFolderAsync(&unmarshalledReturn));

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

- (void)requestRemoveFolderAsync:(WSStorageFolder*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestRemoveFolderAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(folder).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (NSMutableArray<RTObservableCollection>* /* WSStorageFolder* */)folders {
    ComPtr<IObservableVector<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(_comInst->get_Folders(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_WSStorageFolder_create(unmarshalledReturn.Get());
}

- (WSStorageFolder*)saveFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(_comInst->get_SaveFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDefinitionChangedEvent:(void (^)(WSStorageLibrary*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(_comInst->add_DefinitionChanged(Make<ITypedEventHandler_Windows_Storage_StorageLibrary_System_Object>(handler).Get(),
                                                       &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDefinitionChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DefinitionChanged(eventCookie));
}

- (WSStorageLibraryChangeTracker*)changeTracker {
    ComPtr<ABI::Windows::Storage::IStorageLibraryChangeTracker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibrary2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeTracker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageLibraryChangeTracker>(unmarshalledReturn.Get());
}

@end

@implementation WSStorageFolder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFolder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::IStorageFolderStatics> WSIStorageFolderStatics_inst() {
    ComPtr<ABI::Windows::Storage::IStorageFolderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.StorageFolder").Get(), &inst));
    return inst;
}

+ (void)getFolderFromPathAsync:(NSString*)path success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIStorageFolderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFolderFromPathAsync(nsStrToHstr(path).Get(), &unmarshalledReturn));

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

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions(
        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode, &unmarshalledReturn));

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

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned int)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned int)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsync((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

@implementation WSStorageLibraryChangeTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageLibraryChangeTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageLibraryChangeReader*)getChangeReader {
    ComPtr<ABI::Windows::Storage::IStorageLibraryChangeReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->GetChangeReader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageLibraryChangeReader>(unmarshalledReturn.Get());
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChangeTracker>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WSKnownFolders

ComPtr<ABI::Windows::Storage::IKnownFoldersStatics> WSIKnownFoldersStatics_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)musicLibrary {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MusicLibrary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)picturesLibrary {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PicturesLibrary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)videosLibrary {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VideosLibrary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)documentsLibrary {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DocumentsLibrary(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)homeGroup {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HomeGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)removableDevices {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RemovableDevices(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)mediaServerDevices {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaServerDevices(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Storage::IKnownFoldersStatics3> WSIKnownFoldersStatics3_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (void)getFolderForUserAsync:(WSUser*)user
                     folderId:(WSKnownFolderId)folderId
                      success:(void (^)(WSStorageFolder*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetFolderForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                       (ABI::Windows::Storage::KnownFolderId)folderId,
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

ComPtr<ABI::Windows::Storage::IKnownFoldersPlaylistsStatics> WSIKnownFoldersPlaylistsStatics_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersPlaylistsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)playlists {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersPlaylistsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Playlists(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Storage::IKnownFoldersSavedPicturesStatics> WSIKnownFoldersSavedPicturesStatics_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersSavedPicturesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)savedPictures {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersSavedPicturesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SavedPictures(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Storage::IKnownFoldersStatics2> WSIKnownFoldersStatics2_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)objects3D {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Objects3D(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)appCaptures {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AppCaptures(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (WSStorageFolder*)recordedCalls {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_RecordedCalls(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Storage::IKnownFoldersCameraRollStatics> WSIKnownFoldersCameraRollStatics_inst() {
    ComPtr<ABI::Windows::Storage::IKnownFoldersCameraRollStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.KnownFolders").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)cameraRoll {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WSIKnownFoldersCameraRollStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CameraRoll(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

@end

@implementation WSStorageFile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageFile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::IStorageFileStatics> WSIStorageFileStatics_inst() {
    ComPtr<ABI::Windows::Storage::IStorageFileStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.StorageFile").Get(), &inst));
    return inst;
}

+ (void)getFileFromPathAsync:(NSString*)path success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFileFromPathAsync(nsStrToHstr(path).Get(), &unmarshalledReturn));

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

+ (void)getFileFromApplicationUriAsync:(WFUri*)uri success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFileFromApplicationUriAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
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

+ (void)createStreamedFileAsync:(NSString*)displayNameWithExtension
                  dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested
                      thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                        success:(void (^)(WSStorageFile*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateStreamedFileAsync(nsStrToHstr(displayNameWithExtension).Get(),
                                          Make<WSStreamedFileDataRequestedHandler_shim>(dataRequested).Get(),
                                          _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(thumbnail).Get(),
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

+ (void)replaceWithStreamedFileAsync:(RTObject<WSIStorageFile>*)fileToReplace
                       dataRequested:(WSStreamedFileDataRequestedHandler)dataRequested
                           thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                             success:(void (^)(WSStorageFile*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReplaceWithStreamedFileAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(fileToReplace).Get(),
        Make<WSStreamedFileDataRequestedHandler_shim>(dataRequested).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(thumbnail).Get(),
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

+ (void)createStreamedFileFromUriAsync:(NSString*)displayNameWithExtension
                                   uri:(WFUri*)uri
                             thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                               success:(void (^)(WSStorageFile*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateStreamedFileFromUriAsync(
        nsStrToHstr(displayNameWithExtension).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(thumbnail).Get(),
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

+ (void)replaceWithStreamedFileFromUriAsync:(RTObject<WSIStorageFile>*)fileToReplace
                                        uri:(WFUri*)uri
                                  thumbnail:(RTObject<WSSIRandomAccessStreamReference>*)thumbnail
                                    success:(void (^)(WSStorageFile*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIStorageFileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReplaceWithStreamedFileFromUriAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(fileToReplace).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(thumbnail).Get(),
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

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions:(WSFThumbnailMode)mode
                                                                success:(void (^)(WSFStorageItemThumbnail*))success
                                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultSizeDefaultOptions(
        (ABI::Windows::Storage::FileProperties::ThumbnailMode)mode, &unmarshalledReturn));

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

- (void)getScaledImageAsThumbnailAsyncOverloadDefaultOptions:(WSFThumbnailMode)mode
                                               requestedSize:(unsigned int)requestedSize
                                                     success:(void (^)(WSFStorageItemThumbnail*))success
                                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetScaledImageAsThumbnailAsyncOverloadDefaultOptions((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

- (void)getScaledImageAsThumbnailAsync:(WSFThumbnailMode)mode
                         requestedSize:(unsigned int)requestedSize
                               options:(WSFThumbnailOptions)options
                               success:(void (^)(WSFStorageItemThumbnail*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::StorageItemThumbnail*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageItemProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetScaledImageAsThumbnailAsync((ABI::Windows::Storage::FileProperties::ThumbnailMode)mode,
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

@implementation WSDownloadsFolder

ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics2> WSIDownloadsFolderStatics2_inst() {
    ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.DownloadsFolder").Get(), &inst));
    return inst;
}

+ (void)createFileForUserAsync:(WSUser*)user
                   desiredName:(NSString*)desiredName
                       success:(void (^)(WSStorageFile*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFileForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                        nsStrToHstr(desiredName).Get(),
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

+ (void)createFolderForUserAsync:(WSUser*)user
                     desiredName:(NSString*)desiredName
                         success:(void (^)(WSStorageFolder*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFolderForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                          nsStrToHstr(desiredName).Get(),
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

+ (void)createFileForUserWithCollisionOptionAsync:(WSUser*)user
                                      desiredName:(NSString*)desiredName
                                           option:(WSCreationCollisionOption)option
                                          success:(void (^)(WSStorageFile*))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFileForUserWithCollisionOptionAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                           nsStrToHstr(desiredName).Get(),
                                                                           (ABI::Windows::Storage::CreationCollisionOption)option,
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

+ (void)createFolderForUserWithCollisionOptionAsync:(WSUser*)user
                                        desiredName:(NSString*)desiredName
                                             option:(WSCreationCollisionOption)option
                                            success:(void (^)(WSStorageFolder*))success
                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFolderForUserWithCollisionOptionAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                             nsStrToHstr(desiredName).Get(),
                                                                             (ABI::Windows::Storage::CreationCollisionOption)option,
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

ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics> WSIDownloadsFolderStatics_inst() {
    ComPtr<ABI::Windows::Storage::IDownloadsFolderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.DownloadsFolder").Get(), &inst));
    return inst;
}

+ (void)createFileAsync:(NSString*)desiredName success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFileAsync(nsStrToHstr(desiredName).Get(), &unmarshalledReturn));

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

+ (void)createFolderAsync:(NSString*)desiredName success:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFolderAsync(nsStrToHstr(desiredName).Get(), &unmarshalledReturn));

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

+ (void)createFileWithCollisionOptionAsync:(NSString*)desiredName
                                    option:(WSCreationCollisionOption)option
                                   success:(void (^)(WSStorageFile*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFileWithCollisionOptionAsync(nsStrToHstr(desiredName).Get(),
                                                                    (ABI::Windows::Storage::CreationCollisionOption)option,
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

+ (void)createFolderWithCollisionOptionAsync:(NSString*)desiredName
                                      option:(WSCreationCollisionOption)option
                                     success:(void (^)(WSStorageFolder*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = WSIDownloadsFolderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFolderWithCollisionOptionAsync(nsStrToHstr(desiredName).Get(),
                                                                      (ABI::Windows::Storage::CreationCollisionOption)option,
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

@end

@implementation WSStorageLibraryChange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageLibraryChange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageLibraryChangeType)changeType {
    ABI::Windows::Storage::StorageLibraryChangeType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WSStorageLibraryChangeType)unmarshalledReturn;
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)previousPath {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChange>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousPath(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isOfType:(WSStorageItemTypes)type {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChange>(self);
    THROW_NS_IF_FAILED(_comInst->IsOfType((ABI::Windows::Storage::StorageItemTypes)type, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getStorageItemAsyncWithSuccess:(void (^)(RTObject<WSIStorageItem>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChange>(self);
    THROW_NS_IF_FAILED(_comInst->GetStorageItemAsync(&unmarshalledReturn));

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

@end

@implementation WSStorageLibraryChangeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageLibraryChangeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WSStorageLibraryChange* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageLibraryChange*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBatchAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Storage::StorageLibraryChange*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageLibraryChange*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Storage::StorageLibraryChange*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSStorageLibraryChange_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)acceptChangesAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageLibraryChangeReader>(self);
    THROW_NS_IF_FAILED(_comInst->AcceptChangesAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSStreamedFileDataRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->WriteAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
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

- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->FlushAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)failAndClose:(WSStreamedFileFailureMode)failureMode {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStreamedFileDataRequest>(self);
    THROW_NS_IF_FAILED(_comInst->FailAndClose((ABI::Windows::Storage::StreamedFileFailureMode)failureMode));
}

@end

@implementation WSStorageStreamTransaction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageStreamTransaction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageStreamTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)commitAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageStreamTransaction>(self);
    THROW_NS_IF_FAILED(_comInst->CommitAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSStorageProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IStorageProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IStorageProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSFileIO

ComPtr<ABI::Windows::Storage::IFileIOStatics> WSIFileIOStatics_inst() {
    ComPtr<ABI::Windows::Storage::IFileIOStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.FileIO").Get(), &inst));
    return inst;
}

+ (void)readTextAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadTextAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)readTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                         encoding:(WSSUnicodeEncoding)encoding
                          success:(void (^)(NSString*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadTextWithEncodingAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                           (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (RTObject<WFIAsyncAction>*)writeTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString*)contents {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteTextAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                nsStrToHstr(contents).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                               contents:(NSString*)contents
                                               encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteTextWithEncodingAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                            nsStrToHstr(contents).Get(),
                                                            (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendTextAsync:(RTObject<WSIStorageFile>*)file contents:(NSString*)contents {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AppendTextAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                 nsStrToHstr(contents).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                contents:(NSString*)contents
                                                encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AppendTextWithEncodingAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                             nsStrToHstr(contents).Get(),
                                                             (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)readLinesAsync:(RTObject<WSIStorageFile>*)file
               success:(void (^)(NSMutableArray* /* NSString * */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadLinesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_NSString_create(result.Get()));
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

+ (void)readLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                          encoding:(WSSUnicodeEncoding)encoding
                           success:(void (^)(NSMutableArray* /* NSString * */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadLinesWithEncodingAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                            (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_NSString_create(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->WriteLinesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                  static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                      ConvertToIterable<NSString, HSTRING>(lines).Get()),
                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                   lines:(id<NSFastEnumeration> /* NSString * */)lines
                                                encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteLinesWithEncodingAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(lines).Get()),
        (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(RTObject<WSIStorageFile>*)file lines:(id<NSFastEnumeration> /* NSString * */)lines {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AppendLinesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                   static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                       ConvertToIterable<NSString, HSTRING>(lines).Get()),
                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(RTObject<WSIStorageFile>*)file
                                                    lines:(id<NSFastEnumeration> /* NSString * */)lines
                                                 encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AppendLinesWithEncodingAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(lines).Get()),
        (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)readBufferAsync:(RTObject<WSIStorageFile>*)file
                success:(void (^)(RTObject<WSSIBuffer>*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadBufferAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(RTObject<WSIStorageFile>*)file buffer:(RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteBufferAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(RTObject<WSIStorageFile>*)file buffer:(NSArray* /* uint8_t */)buffer {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = WSIFileIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteBytesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                 __buffer_ArrayLen,
                                                 __buffer_Array,
                                                 unmarshalledReturn.GetAddressOf()));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSPathIO

ComPtr<ABI::Windows::Storage::IPathIOStatics> WSIPathIOStatics_inst() {
    ComPtr<ABI::Windows::Storage::IPathIOStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.PathIO").Get(), &inst));
    return inst;
}

+ (void)readTextAsync:(NSString*)absolutePath success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadTextAsync(nsStrToHstr(absolutePath).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)readTextWithEncodingAsync:(NSString*)absolutePath
                         encoding:(WSSUnicodeEncoding)encoding
                          success:(void (^)(NSString*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadTextWithEncodingAsync(nsStrToHstr(absolutePath).Get(),
                                                           (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (RTObject<WFIAsyncAction>*)writeTextAsync:(NSString*)absolutePath contents:(NSString*)contents {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->WriteTextAsync(nsStrToHstr(absolutePath).Get(), nsStrToHstr(contents).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeTextWithEncodingAsync:(NSString*)absolutePath
                                               contents:(NSString*)contents
                                               encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteTextWithEncodingAsync(nsStrToHstr(absolutePath).Get(),
                                                            nsStrToHstr(contents).Get(),
                                                            (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendTextAsync:(NSString*)absolutePath contents:(NSString*)contents {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AppendTextAsync(nsStrToHstr(absolutePath).Get(), nsStrToHstr(contents).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendTextWithEncodingAsync:(NSString*)absolutePath
                                                contents:(NSString*)contents
                                                encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AppendTextWithEncodingAsync(nsStrToHstr(absolutePath).Get(),
                                                             nsStrToHstr(contents).Get(),
                                                             (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)readLinesAsync:(NSString*)absolutePath
               success:(void (^)(NSMutableArray* /* NSString * */))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadLinesAsync(nsStrToHstr(absolutePath).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_NSString_create(result.Get()));
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

+ (void)readLinesWithEncodingAsync:(NSString*)absolutePath
                          encoding:(WSSUnicodeEncoding)encoding
                           success:(void (^)(NSMutableArray* /* NSString * */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadLinesWithEncodingAsync(nsStrToHstr(absolutePath).Get(),
                                                            (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_NSString_create(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)writeLinesAsync:(NSString*)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->WriteLinesAsync(nsStrToHstr(absolutePath).Get(),
                                  static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                      ConvertToIterable<NSString, HSTRING>(lines).Get()),
                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeLinesWithEncodingAsync:(NSString*)absolutePath
                                                   lines:(id<NSFastEnumeration> /* NSString * */)lines
                                                encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteLinesWithEncodingAsync(
        nsStrToHstr(absolutePath).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(lines).Get()),
        (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendLinesAsync:(NSString*)absolutePath lines:(id<NSFastEnumeration> /* NSString * */)lines {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AppendLinesAsync(nsStrToHstr(absolutePath).Get(),
                                   static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                       ConvertToIterable<NSString, HSTRING>(lines).Get()),
                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)appendLinesWithEncodingAsync:(NSString*)absolutePath
                                                    lines:(id<NSFastEnumeration> /* NSString * */)lines
                                                 encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AppendLinesWithEncodingAsync(
        nsStrToHstr(absolutePath).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(lines).Get()),
        (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)readBufferAsync:(NSString*)absolutePath success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReadBufferAsync(nsStrToHstr(absolutePath).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)writeBufferAsync:(NSString*)absolutePath buffer:(RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WriteBufferAsync(nsStrToHstr(absolutePath).Get(),
                                                  _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)writeBytesAsync:(NSString*)absolutePath buffer:(NSArray* /* uint8_t */)buffer {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __buffer_ArrayLen = 0;
    bool __buffer_IsTemp = false;
    uint8_t* __buffer_Array = NULL;
    if (!ConvertToCArray<uint8_t>(buffer, &__buffer_ArrayLen, &__buffer_Array, &__buffer_IsTemp))
        assert(0);

    auto _comInst = WSIPathIOStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->WriteBytesAsync(nsStrToHstr(absolutePath).Get(), __buffer_ArrayLen, __buffer_Array, unmarshalledReturn.GetAddressOf()));
    if (__buffer_IsTemp)
        CoTaskMemFree(__buffer_Array);
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSCachedFileManager

ComPtr<ABI::Windows::Storage::ICachedFileManagerStatics> WSICachedFileManagerStatics_inst() {
    ComPtr<ABI::Windows::Storage::ICachedFileManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.CachedFileManager").Get(), &inst));
    return inst;
}

+ (void)deferUpdates:(RTObject<WSIStorageFile>*)file {
    auto _comInst = WSICachedFileManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DeferUpdates(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get()));
}

+ (void)completeUpdatesAsync:(RTObject<WSIStorageFile>*)file
                     success:(void (^)(WSPFileUpdateStatus))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Provider::FileUpdateStatus>> unmarshalledReturn;
    auto _comInst = WSICachedFileManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CompleteUpdatesAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Provider::FileUpdateStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Provider::FileUpdateStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Storage::Provider::FileUpdateStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSPFileUpdateStatus)result);
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

@implementation WSSystemAudioProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemAudioProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)encodingBitrate {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemAudioProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingBitrate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemGPSProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemGPSProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)latitudeDecimal {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemGPSProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_LatitudeDecimal(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)longitudeDecimal {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemGPSProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_LongitudeDecimal(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemImageProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemImageProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)horizontalSize {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalSize(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)verticalSize {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalSize(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemMediaProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemMediaProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)duration {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)producer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Producer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)publisher {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Publisher(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)subTitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubTitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)writer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Writer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)year {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMediaProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Year(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemMusicProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemMusicProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)albumArtist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumArtist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)albumTitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumTitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)artist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Artist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)composer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Composer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)conductor {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Conductor(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayArtist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayArtist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)genre {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Genre(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)trackNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemPhotoProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemPhotoProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)cameraManufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemPhotoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraManufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)cameraModel {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemPhotoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraModel(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dateTaken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemPhotoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateTaken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)orientation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemPhotoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)peopleNames {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemPhotoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeopleNames(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemVideoProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISystemVideoProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)director {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Director(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)frameHeight {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameHeight(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)frameWidth {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameWidth(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)orientation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)totalBitrate {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISystemVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalBitrate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSystemProperties

ComPtr<ABI::Windows::Storage::ISystemProperties> WSISystemProperties_inst() {
    ComPtr<ABI::Windows::Storage::ISystemProperties> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.SystemProperties").Get(), &inst));
    return inst;
}

+ (NSString*)author {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Author(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)itemNameDisplay {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemNameDisplay(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)keywords {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Keywords(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rating {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rating(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WSSystemAudioProperties*)audio {
    ComPtr<ABI::Windows::Storage::ISystemAudioProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Audio(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemAudioProperties>(unmarshalledReturn.Get());
}

+ (WSSystemGPSProperties*)gPS {
    ComPtr<ABI::Windows::Storage::ISystemGPSProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_GPS(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemGPSProperties>(unmarshalledReturn.Get());
}

+ (WSSystemMediaProperties*)media {
    ComPtr<ABI::Windows::Storage::ISystemMediaProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Media(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemMediaProperties>(unmarshalledReturn.Get());
}

+ (WSSystemMusicProperties*)music {
    ComPtr<ABI::Windows::Storage::ISystemMusicProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Music(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemMusicProperties>(unmarshalledReturn.Get());
}

+ (WSSystemPhotoProperties*)photo {
    ComPtr<ABI::Windows::Storage::ISystemPhotoProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Photo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemPhotoProperties>(unmarshalledReturn.Get());
}

+ (WSSystemVideoProperties*)video {
    ComPtr<ABI::Windows::Storage::ISystemVideoProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Video(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemVideoProperties>(unmarshalledReturn.Get());
}

+ (WSSystemImageProperties*)image {
    ComPtr<ABI::Windows::Storage::ISystemImageProperties> unmarshalledReturn;
    auto _comInst = WSISystemProperties_inst();
    THROW_NS_IF_FAILED(_comInst->get_Image(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSystemImageProperties>(unmarshalledReturn.Get());
}

@end

@implementation WSApplicationData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IApplicationData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::IApplicationDataStatics2> WSIApplicationDataStatics2_inst() {
    ComPtr<ABI::Windows::Storage::IApplicationDataStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.ApplicationData").Get(), &inst));
    return inst;
}

+ (void)getForUserAsync:(WSUser*)user success:(void (^)(WSApplicationData*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::ApplicationData*>> unmarshalledReturn;
    auto _comInst = WSIApplicationDataStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::ApplicationData*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::ApplicationData*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IApplicationData> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSApplicationData>(result.Get()));
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

ComPtr<ABI::Windows::Storage::IApplicationDataStatics> WSIApplicationDataStatics_inst() {
    ComPtr<ABI::Windows::Storage::IApplicationDataStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.ApplicationData").Get(), &inst));
    return inst;
}

+ (WSApplicationData*)current {
    ComPtr<ABI::Windows::Storage::IApplicationData> unmarshalledReturn;
    auto _comInst = WSIApplicationDataStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSApplicationData>(unmarshalledReturn.Get());
}

- (unsigned int)Version {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setVersionAsync:(unsigned int)desiredVersion handler:(WSApplicationDataSetVersionHandler)handler {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->SetVersionAsync(desiredVersion,
                                                 Make<WSApplicationDataSetVersionHandler_shim>(handler).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearAllAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAllAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearAsync:(WSApplicationDataLocality)locality {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAsync((ABI::Windows::Storage::ApplicationDataLocality)locality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WSApplicationDataContainer*)localSettings {
    ComPtr<ABI::Windows::Storage::IApplicationDataContainer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSApplicationDataContainer>(unmarshalledReturn.Get());
}

- (WSApplicationDataContainer*)roamingSettings {
    ComPtr<ABI::Windows::Storage::IApplicationDataContainer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingSettings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSApplicationDataContainer>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)localFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)roamingFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)temporaryFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_TemporaryFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDataChangedEvent:(void (^)(WSApplicationData*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataChanged(Make<ITypedEventHandler_Windows_Storage_ApplicationData_System_Object>(handler).Get(),
                                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataChanged(token));
}

- (void)signalDataChanged {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->SignalDataChanged());
}

- (uint64_t)roamingStorageQuota {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoamingStorageQuota(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSStorageFolder*)localCacheFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalCacheFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)getPublisherCacheFolder:(NSString*)folderName {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData3>(self);
    THROW_NS_IF_FAILED(_comInst->GetPublisherCacheFolder(nsStrToHstr(folderName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearPublisherCacheFolderAsync:(NSString*)folderName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData3>(self);
    THROW_NS_IF_FAILED(_comInst->ClearPublisherCacheFolderAsync(nsStrToHstr(folderName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)sharedLocalFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationData3>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharedLocalFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

@end

@implementation WSSetVersionRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISetVersionRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)currentVersion {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISetVersionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentVersion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)desiredVersion {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISetVersionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredVersion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSetVersionDeferral*)getDeferral {
    ComPtr<ABI::Windows::Storage::ISetVersionDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISetVersionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSetVersionDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WSApplicationDataContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::IApplicationDataContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSApplicationDataLocality)locality {
    ABI::Windows::Storage::ApplicationDataLocality unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Locality(&unmarshalledReturn));
    return (WSApplicationDataLocality)unmarshalledReturn;
}

- (RTObject<WFCIPropertySet>*)values {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Values(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, WSApplicationDataContainer* */)containers {
    ComPtr<IMapView<HSTRING, ABI::Windows::Storage::ApplicationDataContainer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Containers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WSApplicationDataContainer_create(unmarshalledReturn.Get());
}

- (WSApplicationDataContainer*)createContainer:(NSString*)name disposition:(WSApplicationDataCreateDisposition)disposition {
    ComPtr<ABI::Windows::Storage::IApplicationDataContainer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContainer(nsStrToHstr(name).Get(),
                                                 (ABI::Windows::Storage::ApplicationDataCreateDisposition)disposition,
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSApplicationDataContainer>(unmarshalledReturn.Get());
}

- (void)deleteContainer:(NSString*)name {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::IApplicationDataContainer>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteContainer(nsStrToHstr(name).Get()));
}

@end

@implementation WSSetVersionDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::ISetVersionDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::ISetVersionDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WSApplicationDataContainerSettings {
    RTObservableMapObjFull<HSTRING,
                           HSTRING,
                           IInspectable*,
                           IInspectable*,
                           NSString,
                           RTObject,
                           IMap<HSTRING, IInspectable*>,
                           dummyObjCCreator,
                           dummyObjCCreator,
                           dummyWRLCreator,
                           dummyWRLCreator>
        _map;
}
INTEROP_IMPL_OBSMAP_FULL(self.comObj,
                         RTProxiedObservableNSMutableDictionary_NSString_RTObject,
                         HSTRING,
                         HSTRING,
                         IInspectable*,
                         IInspectable*,
                         NSString,
                         RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSApplicationDataCompositeValue {
    RTObservableMapObjFull<HSTRING,
                           HSTRING,
                           IInspectable*,
                           IInspectable*,
                           NSString,
                           RTObject,
                           IMap<HSTRING, IInspectable*>,
                           dummyObjCCreator,
                           dummyObjCCreator,
                           dummyWRLCreator,
                           dummyWRLCreator>
        _map;
}
INTEROP_IMPL_OBSMAP_FULL(self.comObj,
                         RTProxiedObservableNSMutableDictionary_NSString_RTObject,
                         HSTRING,
                         HSTRING,
                         IInspectable*,
                         IInspectable*,
                         NSString,
                         RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.ApplicationDataCompositeValue").Get(), &out));
    return [_createRtProxy<WSApplicationDataCompositeValue>(out.Get()) retain];
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
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

id RTProxiedNSArray_WSStorageLibraryChange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Storage::StorageLibraryChange*>,
                                         RTArrayObj<ABI::Windows::Storage::IStorageLibraryChange*,
                                                    IVectorView<ABI::Windows::Storage::StorageLibraryChange*>,
                                                    WSStorageLibraryChange,
                                                    ABI::Windows::Storage::StorageLibraryChange*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WSApplicationDataContainer_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, ABI::Windows::Storage::ApplicationDataContainer*>,
                             DictionaryKeyEnumeratorAdapterObj<
                                 RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Storage::ApplicationDataContainer*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          ABI::Windows::Storage::ApplicationDataContainer*,
                                          ABI::Windows::Storage::IApplicationDataContainer*,
                                          NSString,
                                          WSApplicationDataContainer,
                                          IMapView<HSTRING, ABI::Windows::Storage::ApplicationDataContainer*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedObservableNSMutableArray_WSStorageFolder_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter =
        std::make_unique<ObservableArrayAdapterObj<IObservableVector<ABI::Windows::Storage::StorageFolder*>,
                                                   RTObservableArrayObj<ABI::Windows::Storage::IStorageFolder*,
                                                                        IVector<ABI::Windows::Storage::StorageFolder*>,
                                                                        WSStorageFolder,
                                                                        ABI::Windows::Storage::StorageFolder*,
                                                                        dummyObjCCreator,
                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}
