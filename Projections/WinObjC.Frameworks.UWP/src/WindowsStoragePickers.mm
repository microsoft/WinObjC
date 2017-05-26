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

// WindowsStoragePickers.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.Pickers.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStoragePickers.h"
#include "WindowsStoragePickers_priv.h"

@implementation WSPFilePickerSelectedFilesArray {
    RTArrayObj<ABI::Windows::Storage::IStorageFile*,
               IVectorView<ABI::Windows::Storage::StorageFile*>,
               WSStorageFile,
               ABI::Windows::Storage::StorageFile*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj, WSStorageFile, ABI::Windows::Storage::IStorageFile*, ABI::Windows::Storage::StorageFile*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Storage::StorageFile*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSPFilePickerFileTypesOrderedMap {
    RTMapObj<HSTRING,
             HSTRING,
             IVector<HSTRING>*,
             IVector<HSTRING>*,
             NSString,
             RTProxiedNSMutableArray,
             IMap<HSTRING, IVector<HSTRING>*>,
             dummyObjCCreator,
             RTProxiedNSMutableArray_NSString_create,
             dummyWRLCreator,
             ConvertToVector<NSString, HSTRING>>
        _map;
}
INTEROP_IMPL_MAP(self.comObj,
                 RTProxiedNSMutableDictionary_NSString_RTProxiedNSMutableArray_NSString,
                 HSTRING,
                 HSTRING,
                 IVector<HSTRING>*,
                 IVector<HSTRING>*,
                 NSString,
                 RTProxiedNSMutableArray)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMap<HSTRING, IVector<HSTRING>*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSPFileExtensionVector {
    RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator> _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, NSString, HSTRING, HSTRING)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<HSTRING>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WSPFileOpenPicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::IFileOpenPicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Pickers.FileOpenPicker").Get(), &out));
    return [_createRtProxy<WSPFileOpenPicker>(out.Get()) retain];
}

ComPtr<ABI::Windows::Storage::Pickers::IFileOpenPickerStatics> WSPIFileOpenPickerStatics_inst() {
    ComPtr<ABI::Windows::Storage::Pickers::IFileOpenPickerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Pickers.FileOpenPicker").Get(), &inst));
    return inst;
}

+ (void)resumePickSingleFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = WSPIFileOpenPickerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ResumePickSingleFileAsync(&unmarshalledReturn));

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

- (WSPPickerViewMode)viewMode {
    ABI::Windows::Storage::Pickers::PickerViewMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewMode(&unmarshalledReturn));
    return (WSPPickerViewMode)unmarshalledReturn;
}

- (void)setViewMode:(WSPPickerViewMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_ViewMode((ABI::Windows::Storage::Pickers::PickerViewMode)value));
}

- (NSString*)settingsIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SettingsIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSettingsIdentifier:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SettingsIdentifier(nsStrToHstr(value).Get()));
}

- (WSPPickerLocationId)suggestedStartLocation {
    ABI::Windows::Storage::Pickers::PickerLocationId unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedStartLocation(&unmarshalledReturn));
    return (WSPPickerLocationId)unmarshalledReturn;
}

- (void)setSuggestedStartLocation:(WSPPickerLocationId)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedStartLocation((ABI::Windows::Storage::Pickers::PickerLocationId)value));
}

- (NSString*)commitButtonText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommitButtonText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCommitButtonText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommitButtonText(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)fileTypeFilter {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypeFilter(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (void)pickSingleFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleFileAsync(&unmarshalledReturn));

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

- (void)pickMultipleFilesAsyncWithSuccess:(void (^)(NSArray* /* WSStorageFile* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Storage::StorageFile*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickMultipleFilesAsync(&unmarshalledReturn));

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

- (void)pickSingleFileAsync:(NSString*)pickerOperationId success:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPickerWithOperationId>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleFileAsync(nsStrToHstr(pickerOperationId).Get(), &unmarshalledReturn));

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

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (void)pickSingleFileAndContinue {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleFileAndContinue());
}

- (void)pickMultipleFilesAndContinue {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileOpenPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickMultipleFilesAndContinue());
}

@end

@implementation WSPFileSavePicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::IFileSavePicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Pickers.FileSavePicker").Get(), &out));
    return [_createRtProxy<WSPFileSavePicker>(out.Get()) retain];
}

- (NSString*)settingsIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SettingsIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSettingsIdentifier:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SettingsIdentifier(nsStrToHstr(value).Get()));
}

- (WSPPickerLocationId)suggestedStartLocation {
    ABI::Windows::Storage::Pickers::PickerLocationId unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedStartLocation(&unmarshalledReturn));
    return (WSPPickerLocationId)unmarshalledReturn;
}

- (void)setSuggestedStartLocation:(WSPPickerLocationId)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedStartLocation((ABI::Windows::Storage::Pickers::PickerLocationId)value));
}

- (NSString*)commitButtonText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommitButtonText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCommitButtonText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommitButtonText(nsStrToHstr(value).Get()));
}

- (NSMutableDictionary* /* NSString *, NSMutableArray* < NSString * > */)fileTypeChoices {
    ComPtr<IMap<HSTRING, IVector<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypeChoices(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)defaultFileExtension {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultFileExtension(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDefaultFileExtension:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultFileExtension(nsStrToHstr(value).Get()));
}

- (WSStorageFile*)suggestedSaveFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedSaveFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (void)setSuggestedSaveFile:(WSStorageFile*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedSaveFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

- (NSString*)suggestedFileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedFileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSuggestedFileName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedFileName(nsStrToHstr(value).Get()));
}

- (void)pickSaveFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSaveFileAsync(&unmarshalledReturn));

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

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (void)pickSaveFileAndContinue {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickSaveFileAndContinue());
}

- (NSString*)enterpriseId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker3>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnterpriseId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setEnterpriseId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFileSavePicker3>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnterpriseId(nsStrToHstr(value).Get()));
}

@end

@implementation WSPFolderPicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::IFolderPicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Pickers.FolderPicker").Get(), &out));
    return [_createRtProxy<WSPFolderPicker>(out.Get()) retain];
}

- (WSPPickerViewMode)viewMode {
    ABI::Windows::Storage::Pickers::PickerViewMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewMode(&unmarshalledReturn));
    return (WSPPickerViewMode)unmarshalledReturn;
}

- (void)setViewMode:(WSPPickerViewMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_ViewMode((ABI::Windows::Storage::Pickers::PickerViewMode)value));
}

- (NSString*)settingsIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SettingsIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSettingsIdentifier:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SettingsIdentifier(nsStrToHstr(value).Get()));
}

- (WSPPickerLocationId)suggestedStartLocation {
    ABI::Windows::Storage::Pickers::PickerLocationId unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedStartLocation(&unmarshalledReturn));
    return (WSPPickerLocationId)unmarshalledReturn;
}

- (void)setSuggestedStartLocation:(WSPPickerLocationId)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedStartLocation((ABI::Windows::Storage::Pickers::PickerLocationId)value));
}

- (NSString*)commitButtonText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommitButtonText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCommitButtonText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommitButtonText(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)fileTypeFilter {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileTypeFilter(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (void)pickSingleFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleFolderAsync(&unmarshalledReturn));

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

- (WFCValueSet*)continuationData {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (void)pickFolderAndContinue {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::IFolderPicker2>(self);
    THROW_NS_IF_FAILED(_comInst->PickFolderAndContinue());
}

@end

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

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<MutableDictionaryAdapterObj<
        IMap<HSTRING, IVector<HSTRING>*>,
        DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IVector<HSTRING>*>>,
        RTMapObj<HSTRING,
                 HSTRING,
                 IVector<HSTRING>*,
                 IVector<HSTRING>*,
                 NSString,
                 RTProxiedNSMutableArray,
                 IMap<HSTRING, IVector<HSTRING>*>,
                 dummyObjCCreator,
                 RTProxiedNSMutableArray_NSString_create,
                 dummyWRLCreator,
                 ConvertToVector<NSString, HSTRING>>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
