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

// WindowsMediaImport.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Import.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaImport.h"
#include "WindowsMediaImport_priv.h"

@implementation WMIPhotoImportSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Import::IPhotoImportSourceStatics> WMIIPhotoImportSourceStatics_inst() {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Import.PhotoImportSource").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)sourceId success:(void (^)(WMIPhotoImportSource*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Import::PhotoImportSource*>> unmarshalledReturn;
    auto _comInst = WMIIPhotoImportSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(sourceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Import::PhotoImportSource*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Import::PhotoImportSource*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportSource> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportSource>(result.Get()));
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

+ (void)fromFolderAsync:(RTObject<WSIStorageFolder>*)sourceRootFolder
                success:(void (^)(WMIPhotoImportSource*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Import::PhotoImportSource*>> unmarshalledReturn;
    auto _comInst = WMIIPhotoImportSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromFolderAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(sourceRootFolder).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Import::PhotoImportSource*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Import::PhotoImportSource*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportSource> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportSource>(result.Get()));
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

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)manufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Manufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)model {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Model(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serialNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SerialNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)connectionProtocol {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionProtocol(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMIPhotoImportConnectionTransport)connectionTransport {
    ABI::Windows::Media::Import::PhotoImportConnectionTransport unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionTransport(&unmarshalledReturn));
    return (WMIPhotoImportConnectionTransport)unmarshalledReturn;
}

- (WMIPhotoImportSourceType)type {
    ABI::Windows::Media::Import::PhotoImportSourceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMIPhotoImportSourceType)unmarshalledReturn;
}

- (WMIPhotoImportPowerSource)powerSource {
    ABI::Windows::Media::Import::PhotoImportPowerSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerSource(&unmarshalledReturn));
    return (WMIPhotoImportPowerSource)unmarshalledReturn;
}

- (id /* unsigned int */)batteryLevelPercent {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_BatteryLevelPercent(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)dateTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (NSArray* /* WMIPhotoImportStorageMedium* */)storageMedia {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportStorageMedium*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_StorageMedia(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportStorageMedium_create(unmarshalledReturn.Get());
}

- (id /* BOOL */)isLocked {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLocked(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (BOOL)isMassStorage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMassStorage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (WMIPhotoImportSession*)createImportSession {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSource>(self);
    THROW_NS_IF_FAILED(_comInst->CreateImportSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSession>(unmarshalledReturn.Get());
}

@end

@implementation WMIPhotoImportOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportStage)stage {
    ABI::Windows::Media::Import::PhotoImportStage unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stage(&unmarshalledReturn));
    return (WMIPhotoImportStage)unmarshalledReturn;
}

- (WMIPhotoImportSession*)session {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSession>(unmarshalledReturn.Get());
}

- (void)continueFindingItemsAsyncWithSuccess:(void (^)(WMIPhotoImportFindItemsResult*))success
                                    progress:(void (^)(unsigned int))progress
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinueFindingItemsAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                     unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                               unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                              unsigned int>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*, unsigned int>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportFindItemsResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportFindItemsResult>(result.Get()));
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

- (void)continueImportingItemsAsyncWithSuccess:(void (^)(WMIPhotoImportImportItemsResult*))success
                                      progress:(void (^)(WMIPhotoImportProgress*))progress
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                 ABI::Windows::Media::Import::PhotoImportProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinueImportingItemsAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                     ABI::Windows::Media::Import::PhotoImportProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                               ABI::Windows::Media::Import::PhotoImportProgress>* op,
                         ABI::Windows::Media::Import::PhotoImportProgress status) {
                @autoreleasepool {
                    progressRc(WMIPhotoImportProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                              ABI::Windows::Media::Import::PhotoImportProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                          ABI::Windows::Media::Import::PhotoImportProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Import::IPhotoImportImportItemsResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMIPhotoImportImportItemsResult>(result.Get()));
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

- (void)continueDeletingImportedItemsFromSourceAsyncWithSuccess:(void (^)(WMIPhotoImportDeleteImportedItemsFromSourceResult*))success
                                                       progress:(void (^)(double))progress
                                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::
               IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*, double>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinueDeletingImportedItemsFromSourceAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::
                IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*, double>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<
                                       ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                       double>* op,
                                   double status) {
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
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                         ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                         double>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                                              double>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportDeleteImportedItemsFromSourceResult>(result.Get()));
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

@implementation WMIPhotoImportManager

ComPtr<ABI::Windows::Media::Import::IPhotoImportManagerStatics> WMIIPhotoImportManagerStatics_inst() {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Import.PhotoImportManager").Get(), &inst));
    return inst;
}

+ (void)isSupportedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WMIIPhotoImportManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupportedAsync(&unmarshalledReturn));

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

+ (void)findAllSourcesAsyncWithSuccess:(void (^)(NSArray* /* WMIPhotoImportSource* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>*>> unmarshalledReturn;
    auto _comInst = WMIIPhotoImportManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllSourcesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WMIPhotoImportSource_create(result.Get()));
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

+ (NSArray* /* WMIPhotoImportOperation* */)getPendingOperations {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportOperation*>> unmarshalledReturn;
    auto _comInst = WMIIPhotoImportManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetPendingOperations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportOperation_create(unmarshalledReturn.Get());
}

@end

@implementation WMIPhotoImportSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportSource*)source {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSource>(unmarshalledReturn.Get());
}

- (WFGUID*)sessionId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setDestinationFolder:(RTObject<WSIStorageFolder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_DestinationFolder(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(value).Get()));
}

- (RTObject<WSIStorageFolder>*)destinationFolder {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_DestinationFolder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFolder>(unmarshalledReturn.Get());
}

- (void)setAppendSessionDateToDestinationFolder:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppendSessionDateToDestinationFolder((boolean)value));
}

- (BOOL)appendSessionDateToDestinationFolder {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppendSessionDateToDestinationFolder(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSubfolderCreationMode:(WMIPhotoImportSubfolderCreationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_SubfolderCreationMode((ABI::Windows::Media::Import::PhotoImportSubfolderCreationMode)value));
}

- (WMIPhotoImportSubfolderCreationMode)subfolderCreationMode {
    ABI::Windows::Media::Import::PhotoImportSubfolderCreationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubfolderCreationMode(&unmarshalledReturn));
    return (WMIPhotoImportSubfolderCreationMode)unmarshalledReturn;
}

- (void)setDestinationFileNamePrefix:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_DestinationFileNamePrefix(nsStrToHstr(value).Get()));
}

- (NSString*)destinationFileNamePrefix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_DestinationFileNamePrefix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)findItemsAsync:(WMIPhotoImportContentTypeFilter)contentTypeFilter
     itemSelectionMode:(WMIPhotoImportItemSelectionMode)itemSelectionMode
               success:(void (^)(WMIPhotoImportFindItemsResult*))success
              progress:(void (^)(unsigned int))progress
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession>(self);
    THROW_NS_IF_FAILED(_comInst->FindItemsAsync((ABI::Windows::Media::Import::PhotoImportContentTypeFilter)contentTypeFilter,
                                                (ABI::Windows::Media::Import::PhotoImportItemSelectionMode)itemSelectionMode,
                                                &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                     unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                               unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Import::PhotoImportFindItemsResult*,
                                                                              unsigned int>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportFindItemsResult*, unsigned int>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportFindItemsResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportFindItemsResult>(result.Get()));
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

- (void)setSubfolderDateFormat:(WMIPhotoImportSubfolderDateFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SubfolderDateFormat((ABI::Windows::Media::Import::PhotoImportSubfolderDateFormat)value));
}

- (WMIPhotoImportSubfolderDateFormat)subfolderDateFormat {
    ABI::Windows::Media::Import::PhotoImportSubfolderDateFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubfolderDateFormat(&unmarshalledReturn));
    return (WMIPhotoImportSubfolderDateFormat)unmarshalledReturn;
}

- (void)setRememberDeselectedItems:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RememberDeselectedItems((boolean)value));
}

- (BOOL)rememberDeselectedItems {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSession2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RememberDeselectedItems(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMIPhotoImportFindItemsResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportFindItemsResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportSession*)session {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSession>(unmarshalledReturn.Get());
}

- (BOOL)hasSucceeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasSucceeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMIPhotoImportItem* */)foundItems {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_FoundItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportItem_create(unmarshalledReturn.Get());
}

- (unsigned int)photosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)photosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)videosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)videosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)sidecarsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)sidecarsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)siblingsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)siblingsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)totalCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)selectAll {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->SelectAll());
}

- (void)selectNone {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNone());
}

- (RTObject<WFIAsyncAction>*)selectNewAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->SelectNewAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setImportMode:(WMIPhotoImportImportMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->SetImportMode((ABI::Windows::Media::Import::PhotoImportImportMode)value));
}

- (WMIPhotoImportImportMode)importMode {
    ABI::Windows::Media::Import::PhotoImportImportMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImportMode(&unmarshalledReturn));
    return (WMIPhotoImportImportMode)unmarshalledReturn;
}

- (unsigned int)selectedPhotosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPhotosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)selectedPhotosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPhotosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)selectedVideosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedVideosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)selectedVideosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedVideosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)selectedSidecarsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedSidecarsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)selectedSidecarsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedSidecarsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)selectedSiblingsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedSiblingsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)selectedSiblingsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedSiblingsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)selectedTotalCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedTotalCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)selectedTotalSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedTotalSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addSelectionChangedEvent:(void (^)(WMIPhotoImportFindItemsResult*,
                                                             WMIPhotoImportSelectionChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectionChanged(
        Make<ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportSelectionChangedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectionChanged(token));
}

- (void)importItemsAsyncWithSuccess:(void (^)(WMIPhotoImportImportItemsResult*))success
                           progress:(void (^)(WMIPhotoImportProgress*))progress
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                 ABI::Windows::Media::Import::PhotoImportProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->ImportItemsAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                     ABI::Windows::Media::Import::PhotoImportProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                               ABI::Windows::Media::Import::PhotoImportProgress>* op,
                         ABI::Windows::Media::Import::PhotoImportProgress status) {
                @autoreleasepool {
                    progressRc(WMIPhotoImportProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                              ABI::Windows::Media::Import::PhotoImportProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportImportItemsResult*,
                                                                          ABI::Windows::Media::Import::PhotoImportProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Import::IPhotoImportImportItemsResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMIPhotoImportImportItemsResult>(result.Get()));
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

- (EventRegistrationToken)addItemImportedEvent:(void (^)(WMIPhotoImportFindItemsResult*, WMIPhotoImportItemImportedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemImported(
        Make<ITypedEventHandler_Windows_Media_Import_PhotoImportFindItemsResult_Windows_Media_Import_PhotoImportItemImportedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemImportedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemImported(token));
}

- (void)addItemsInDateRangeToSelection:(WFDateTime*)rangeStart rangeLength:(WFTimeSpan*)rangeLength {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportFindItemsResult2>(self);
    THROW_NS_IF_FAILED(_comInst->AddItemsInDateRangeToSelection(*[rangeStart internalStruct], *[rangeLength internalStruct]));
}

@end

@implementation WMIPhotoImportImportItemsResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportImportItemsResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportSession*)session {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSession>(unmarshalledReturn.Get());
}

- (BOOL)hasSucceeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasSucceeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMIPhotoImportItem* */)importedItems {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImportedItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportItem_create(unmarshalledReturn.Get());
}

- (unsigned int)photosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)photosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)videosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)videosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)sidecarsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)sidecarsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)siblingsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)siblingsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)totalCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)deleteImportedItemsFromSourceAsyncWithSuccess:(void (^)(WMIPhotoImportDeleteImportedItemsFromSourceResult*))success
                                             progress:(void (^)(double))progress
                                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::
               IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*, double>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportImportItemsResult>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteImportedItemsFromSourceAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::
                IAsyncOperationProgressHandler<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*, double>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<
                                       ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                       double>* op,
                                   double status) {
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
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                         ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                         double>>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult*,
                                                              double>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMIPhotoImportDeleteImportedItemsFromSourceResult>(result.Get()));
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

@implementation WMIPhotoImportDeleteImportedItemsFromSourceResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportSession*)session {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Session(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSession>(unmarshalledReturn.Get());
}

- (BOOL)hasSucceeded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasSucceeded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMIPhotoImportItem* */)deletedItems {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeletedItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportItem_create(unmarshalledReturn.Get());
}

- (unsigned int)photosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)photosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)videosCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)videosSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideosSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)sidecarsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)sidecarsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidecarsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)siblingsCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)siblingsSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SiblingsSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)totalCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMIPhotoImportStorageMedium

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportStorageMedium> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serialNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_SerialNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMIPhotoImportStorageMediumType)storageMediumType {
    ABI::Windows::Media::Import::PhotoImportStorageMediumType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_StorageMediumType(&unmarshalledReturn));
    return (WMIPhotoImportStorageMediumType)unmarshalledReturn;
}

- (WMIPhotoImportAccessMode)supportedAccessMode {
    ABI::Windows::Media::Import::PhotoImportAccessMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedAccessMode(&unmarshalledReturn));
    return (WMIPhotoImportAccessMode)unmarshalledReturn;
}

- (uint64_t)capacityInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_CapacityInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)availableSpaceInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableSpaceInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)refresh {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportStorageMedium>(self);
    THROW_NS_IF_FAILED(_comInst->Refresh());
}

@end

@implementation WMIPhotoImportSidecar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSidecar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSidecar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (uint64_t)sizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSidecar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)date {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSidecar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WMIPhotoImportVideoSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportVideoSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportVideoSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (uint64_t)sizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportVideoSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_SizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)date {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportVideoSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WMIPhotoImportSidecar*)sibling {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSidecar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportVideoSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSidecar>(unmarshalledReturn.Get());
}

- (NSArray* /* WMIPhotoImportSidecar* */)sidecars {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportSidecar*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportVideoSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sidecars(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportSidecar_create(unmarshalledReturn.Get());
}

@end

@implementation WMIPhotoImportItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (uint64_t)itemKey {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemKey(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMIPhotoImportContentType)contentType {
    ABI::Windows::Media::Import::PhotoImportContentType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return (WMIPhotoImportContentType)unmarshalledReturn;
}

- (uint64_t)sizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_SizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)date {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WMIPhotoImportSidecar*)sibling {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSidecar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sibling(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportSidecar>(unmarshalledReturn.Get());
}

- (NSArray* /* WMIPhotoImportSidecar* */)sidecars {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportSidecar*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sidecars(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportSidecar_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMIPhotoImportVideoSegment* */)videoSegments {
    ComPtr<IVectorView<ABI::Windows::Media::Import::PhotoImportVideoSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoSegments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMIPhotoImportVideoSegment_create(unmarshalledReturn.Get());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSelected:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSelected((boolean)value));
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)importedFileNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImportedFileNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)deletedFileNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeletedFileNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WMIPhotoImportSelectionChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportSelectionChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSelectionEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportSelectionChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMIPhotoImportItemImportedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportItemImportedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMIPhotoImportItem*)importedItem {
    ComPtr<ABI::Windows::Media::Import::IPhotoImportItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Import::IPhotoImportItemImportedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImportedItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMIPhotoImportItem>(unmarshalledReturn.Get());
}

@end

@implementation WMIPhotoImportProgress {
    ABI::Windows::Media::Import::PhotoImportProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Import::PhotoImportProgress)s {
    WMIPhotoImportProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Import::PhotoImportProgress*)internalStruct {
    return &structVal;
}
- (unsigned int)itemsImported {
    return structVal.ItemsImported;
}
- (void)setItemsImported:(unsigned int)val {
    structVal.ItemsImported = val;
}
- (unsigned int)totalItemsToImport {
    return structVal.TotalItemsToImport;
}
- (void)setTotalItemsToImport:(unsigned int)val {
    structVal.TotalItemsToImport = val;
}
- (uint64_t)bytesImported {
    return structVal.BytesImported;
}
- (void)setBytesImported:(uint64_t)val {
    structVal.BytesImported = val;
}
- (uint64_t)totalBytesToImport {
    return structVal.TotalBytesToImport;
}
- (void)setTotalBytesToImport:(uint64_t)val {
    structVal.TotalBytesToImport = val;
}
- (double)importProgress {
    return structVal.ImportProgress;
}
- (void)setImportProgress:(double)val {
    structVal.ImportProgress = val;
}
@end
id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportItem*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportItem*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportItem*>,
                                                    WMIPhotoImportItem,
                                                    ABI::Windows::Media::Import::PhotoImportItem*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportOperation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportOperation*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportOperation*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportOperation*>,
                                                    WMIPhotoImportOperation,
                                                    ABI::Windows::Media::Import::PhotoImportOperation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportSidecar_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportSidecar*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportSidecar*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportSidecar*>,
                                                    WMIPhotoImportSidecar,
                                                    ABI::Windows::Media::Import::PhotoImportSidecar*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportSource_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportSource*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportSource*>,
                                                    WMIPhotoImportSource,
                                                    ABI::Windows::Media::Import::PhotoImportSource*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportStorageMedium_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportStorageMedium*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportStorageMedium*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportStorageMedium*>,
                                                    WMIPhotoImportStorageMedium,
                                                    ABI::Windows::Media::Import::PhotoImportStorageMedium*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMIPhotoImportVideoSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Import::PhotoImportVideoSegment*>,
                                         RTArrayObj<ABI::Windows::Media::Import::IPhotoImportVideoSegment*,
                                                    IVectorView<ABI::Windows::Media::Import::PhotoImportVideoSegment*>,
                                                    WMIPhotoImportVideoSegment,
                                                    ABI::Windows::Media::Import::PhotoImportVideoSegment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
