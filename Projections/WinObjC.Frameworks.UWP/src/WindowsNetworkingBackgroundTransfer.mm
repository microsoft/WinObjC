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

// WindowsNetworkingBackgroundTransfer.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.BackgroundTransfer.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingBackgroundTransfer.h"
#include "WindowsNetworkingBackgroundTransfer_priv.h"

@implementation WNBIBackgroundTransferBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMethod:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Method(nsStrToHstr(value).Get()));
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroup:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(nsStrToHstr(value).Get()));
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

@end

@implementation WNBIBackgroundTransferOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)guid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Guid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFUri*)requestedUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResultStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (WNBResponseInformation*)getResponseInformation {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResponseInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBResponseInformation>(unmarshalledReturn.Get());
}

@end

@implementation WNBIBackgroundTransferOperationPriority

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNBBackgroundTransferPriority)priority {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->get_Priority(&unmarshalledReturn));
    return (WNBBackgroundTransferPriority)unmarshalledReturn;
}

- (void)setPriority:(WNBBackgroundTransferPriority)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->put_Priority((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority)value));
}

@end

@implementation WNBIBackgroundTransferContentPartFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WNBBackgroundTransferContentPart*)createWithName:(NSString*)name {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateWithName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferContentPart>(unmarshalledReturn.Get());
}

- (WNBBackgroundTransferContentPart*)createWithNameAndFileName:(NSString*)name fileName:(NSString*)fileName {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateWithNameAndFileName(nsStrToHstr(name).Get(), nsStrToHstr(fileName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferContentPart>(unmarshalledReturn.Get());
}

@end

@implementation WNBDownloadOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSIStorageFile>*)resultFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResultFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

- (WNBBackgroundDownloadProgress*)progress {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return WNBBackgroundDownloadProgress_create(unmarshalledReturn);
}

- (void)startAsyncWithSuccess:(void (^)(WNBDownloadOperation*))success
                     progress:(void (^)(WNBDownloadOperation*))progress
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                 ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                     ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>* op,
            ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation* status) {
            @autoreleasepool {
                progressRc(_createRtProxy<WNBDownloadOperation>(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>>>(
            [successRc, failureRc](
                ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                      ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>* op,
                AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createRtProxy<WNBDownloadOperation>(result.Get()));
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

- (void)attachAsyncWithSuccess:(void (^)(WNBDownloadOperation*))success
                      progress:(void (^)(WNBDownloadOperation*))progress
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                 ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->AttachAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                     ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>* op,
            ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation* status) {
            @autoreleasepool {
                progressRc(_createRtProxy<WNBDownloadOperation>(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>>>(
            [successRc, failureRc](
                ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                      ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>* op,
                AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createRtProxy<WNBDownloadOperation>(result.Get()));
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

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (WFGUID*)guid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Guid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFUri*)requestedUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResultStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (WNBResponseInformation*)getResponseInformation {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResponseInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBResponseInformation>(unmarshalledReturn.Get());
}

- (WNBBackgroundTransferPriority)priority {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->get_Priority(&unmarshalledReturn));
    return (WNBBackgroundTransferPriority)unmarshalledReturn;
}

- (void)setPriority:(WNBBackgroundTransferPriority)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->put_Priority((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority)value));
}

- (WNBBackgroundTransferGroup*)transferGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferGroup>(unmarshalledReturn.Get());
}

@end

@implementation WNBUnconstrainedTransferRequestResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isUnconstrained {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnconstrained(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WNBUploadOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSIStorageFile>*)sourceFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

- (WNBBackgroundUploadProgress*)progress {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return WNBBackgroundUploadProgress_create(unmarshalledReturn);
}

- (void)startAsyncWithSuccess:(void (^)(WNBUploadOperation*))success
                     progress:(void (^)(WNBUploadOperation*))progress
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                 ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                     ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
            ABI::Windows::Networking::BackgroundTransfer::IUploadOperation* status) {
            @autoreleasepool {
                progressRc(_createRtProxy<WNBUploadOperation>(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>>>(
            [successRc, failureRc](
                ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                      ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (void)attachAsyncWithSuccess:(void (^)(WNBUploadOperation*))success
                      progress:(void (^)(WNBUploadOperation*))progress
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                 ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation>(self);
    THROW_NS_IF_FAILED(_comInst->AttachAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                     ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
            ABI::Windows::Networking::BackgroundTransfer::IUploadOperation* status) {
            @autoreleasepool {
                progressRc(_createRtProxy<WNBUploadOperation>(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>>>(
            [successRc, failureRc](
                ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                      ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (WFGUID*)guid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Guid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFUri*)requestedUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

- (RTObject<WSSIInputStream>*)getResultStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResultStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (WNBResponseInformation*)getResponseInformation {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetResponseInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBResponseInformation>(unmarshalledReturn.Get());
}

- (WNBBackgroundTransferPriority)priority {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->get_Priority(&unmarshalledReturn));
    return (WNBBackgroundTransferPriority)unmarshalledReturn;
}

- (void)setPriority:(WNBBackgroundTransferPriority)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferOperationPriority>(self);
    THROW_NS_IF_FAILED(_comInst->put_Priority((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferPriority)value));
}

- (WNBBackgroundTransferGroup*)transferGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferGroup>(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundTransferGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> WNBIBackgroundTransferGroupStatics_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundTransferGroup").Get(), &inst));
    return inst;
}

+ (WNBBackgroundTransferGroup*)createGroup:(NSString*)name {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> unmarshalledReturn;
    auto _comInst = WNBIBackgroundTransferGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateGroup(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferGroup>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNBBackgroundTransferBehavior)transferBehavior {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferBehavior(&unmarshalledReturn));
    return (WNBBackgroundTransferBehavior)unmarshalledReturn;
}

- (void)setTransferBehavior:(WNBBackgroundTransferBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransferBehavior((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferBehavior)value));
}

@end

@implementation WNBBackgroundTransferCompletionGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundTransferCompletionGroup").Get(), &out));
    return [_createRtProxy<WNBBackgroundTransferCompletionGroup>(out.Get()) retain];
}

- (RTObject<WABIBackgroundTrigger>*)trigger {
    ComPtr<ABI::Windows::ApplicationModel::Background::IBackgroundTrigger> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Trigger(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WABIBackgroundTrigger>(unmarshalledReturn.Get());
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)enable {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>(self);
    THROW_NS_IF_FAILED(_comInst->Enable());
}

@end

@implementation WNBBackgroundTransferContentPart

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundTransferContentPart").Get(), &out));
    return [_createRtProxy<WNBBackgroundTransferContentPart>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>
WNBIBackgroundTransferContentPartFactory_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundTransferContentPart").Get(), &inst));
    return inst;
}

+ (WNBBackgroundTransferContentPart*)makeWithName:(NSString*)name {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> unmarshalledReturn;
    auto _comInst = WNBIBackgroundTransferContentPartFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNBBackgroundTransferContentPart>(unmarshalledReturn.Get()) retain];
}

+ (WNBBackgroundTransferContentPart*)makeWithNameAndFileName:(NSString*)name fileName:(NSString*)fileName {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart> unmarshalledReturn;
    auto _comInst = WNBIBackgroundTransferContentPartFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithNameAndFileName(nsStrToHstr(name).Get(), nsStrToHstr(fileName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNBBackgroundTransferContentPart>(unmarshalledReturn.Get()) retain];
}

- (void)setHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart>(self);
    THROW_NS_IF_FAILED(_comInst->SetHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart>(self);
    THROW_NS_IF_FAILED(_comInst->SetText(nsStrToHstr(value).Get()));
}

- (void)setFile:(RTObject<WSIStorageFile>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart>(self);
    THROW_NS_IF_FAILED(_comInst->SetFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

@end

@implementation WNBResponseInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isResumable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsResumable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFUri*)actualUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (unsigned int)statusCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSDictionary* /* NSString *, NSString * */)headers {
    ComPtr<IMapView<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IResponseInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundDownloader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundDownloader").Get(),
                                              &out));
    return [_createRtProxy<WNBBackgroundDownloader>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> WNBIBackgroundDownloaderFactory_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundDownloader").Get(), &inst));
    return inst;
}

+ (WNBBackgroundDownloader*)makeWithCompletionGroup:(WNBBackgroundTransferCompletionGroup*)completionGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader> unmarshalledReturn;
    auto _comInst = WNBIBackgroundDownloaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithCompletionGroup(
        _getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>(completionGroup).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNBBackgroundDownloader>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> WNBIBackgroundDownloaderUserConsent_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundDownloader").Get(), &inst));
    return inst;
}

+ (void)requestUnconstrainedDownloadsAsync:(id<NSFastEnumeration> /* WNBDownloadOperation* */)operations
                                   success:(void (^)(WNBUnconstrainedTransferRequestResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundDownloaderUserConsent_inst();
    THROW_NS_IF_FAILED(_comInst->RequestUnconstrainedDownloadsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                              ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation*>>::type>*>(
            ConvertToIterable<
                WNBDownloadOperation,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation*>>(
                operations)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUnconstrainedTransferRequestResult>(result.Get()));
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

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> WNBIBackgroundDownloaderStaticMethods_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundDownloader").Get(), &inst));
    return inst;
}

+ (void)getCurrentDownloadsAsyncWithSuccess:(void (^)(NSArray* /* WNBDownloadOperation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundDownloaderStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentDownloadsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBDownloadOperation_create(result.Get()));
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

+ (void)getCurrentDownloadsForGroupAsync:(NSString*)group
                                 success:(void (^)(NSArray* /* WNBDownloadOperation* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundDownloaderStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentDownloadsForGroupAsync(nsStrToHstr(group).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBDownloadOperation_create(result.Get()));
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

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> WNBIBackgroundDownloaderStaticMethods2_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundDownloader").Get(), &inst));
    return inst;
}

+ (void)getCurrentDownloadsForTransferGroupAsync:(WNBBackgroundTransferGroup*)group
                                         success:(void (^)(NSArray* /* WNBDownloadOperation* */))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundDownloaderStaticMethods2_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentDownloadsForTransferGroupAsync(
        _getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(group).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBDownloadOperation_create(result.Get()));
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

- (WNBDownloadOperation*)createDownload:(WFUri*)uri resultFile:(RTObject<WSIStorageFile>*)resultFile {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDownload(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                _getRtInterface<ABI::Windows::Storage::IStorageFile>(resultFile).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBDownloadOperation>(unmarshalledReturn.Get());
}

- (WNBDownloadOperation*)createDownloadFromFile:(WFUri*)uri
                                     resultFile:(RTObject<WSIStorageFile>*)resultFile
                                requestBodyFile:(RTObject<WSIStorageFile>*)requestBodyFile {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDownloadFromFile(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                        _getRtInterface<ABI::Windows::Storage::IStorageFile>(resultFile).Get(),
                                                        _getRtInterface<ABI::Windows::Storage::IStorageFile>(requestBodyFile).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBDownloadOperation>(unmarshalledReturn.Get());
}

- (void)createDownloadAsync:(WFUri*)uri
                 resultFile:(RTObject<WSIStorageFile>*)resultFile
          requestBodyStream:(RTObject<WSSIInputStream>*)requestBodyStream
                    success:(void (^)(WNBDownloadOperation*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDownloadAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::IStorageFile>(resultFile).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(requestBodyStream).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNBDownloadOperation>(result.Get()));
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

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMethod:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Method(nsStrToHstr(value).Get()));
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroup:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(nsStrToHstr(value).Get()));
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

- (WNBBackgroundTransferGroup*)transferGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferGroup>(unmarshalledReturn.Get());
}

- (void)setTransferGroup:(WNBBackgroundTransferGroup*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_TransferGroup(_getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(value).Get()));
}

- (WUNToastNotification*)successToastNotification {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuccessToastNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotification>(unmarshalledReturn.Get());
}

- (void)setSuccessToastNotification:(WUNToastNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SuccessToastNotification(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(value).Get()));
}

- (WUNToastNotification*)failureToastNotification {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FailureToastNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotification>(unmarshalledReturn.Get());
}

- (void)setFailureToastNotification:(WUNToastNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_FailureToastNotification(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(value).Get()));
}

- (WUNTileNotification*)successTileNotification {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuccessTileNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileNotification>(unmarshalledReturn.Get());
}

- (void)setSuccessTileNotification:(WUNTileNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SuccessTileNotification(_getRtInterface<ABI::Windows::UI::Notifications::ITileNotification>(value).Get()));
}

- (WUNTileNotification*)failureTileNotification {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FailureTileNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileNotification>(unmarshalledReturn.Get());
}

- (void)setFailureTileNotification:(WUNTileNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_FailureTileNotification(_getRtInterface<ABI::Windows::UI::Notifications::ITileNotification>(value).Get()));
}

- (WNBBackgroundTransferCompletionGroup*)completionGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloader3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompletionGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferCompletionGroup>(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundUploader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory> WNBIBackgroundUploaderFactory_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundUploader").Get(), &inst));
    return inst;
}

+ (WNBBackgroundUploader*)makeWithCompletionGroup:(WNBBackgroundTransferCompletionGroup*)completionGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader> unmarshalledReturn;
    auto _comInst = WNBIBackgroundUploaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithCompletionGroup(
        _getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup>(completionGroup).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNBBackgroundUploader>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundUploader").Get(),
                                              &out));
    return [_createRtProxy<WNBBackgroundUploader>(out.Get()) retain];
}

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> WNBIBackgroundUploaderStaticMethods2_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundUploader").Get(), &inst));
    return inst;
}

+ (void)getCurrentUploadsForTransferGroupAsync:(WNBBackgroundTransferGroup*)group
                                       success:(void (^)(NSArray* /* WNBUploadOperation* */))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundUploaderStaticMethods2_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentUploadsForTransferGroupAsync(
        _getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(group).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBUploadOperation_create(result.Get()));
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

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> WNBIBackgroundUploaderStaticMethods_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundUploader").Get(), &inst));
    return inst;
}

+ (void)getCurrentUploadsAsyncWithSuccess:(void (^)(NSArray* /* WNBUploadOperation* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundUploaderStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentUploadsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBUploadOperation_create(result.Get()));
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

+ (void)getCurrentUploadsForGroupAsync:(NSString*)group
                               success:(void (^)(NSArray* /* WNBUploadOperation* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundUploaderStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentUploadsForGroupAsync(nsStrToHstr(group).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WNBUploadOperation_create(result.Get()));
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

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> WNBIBackgroundUploaderUserConsent_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundUploader").Get(), &inst));
    return inst;
}

+ (void)requestUnconstrainedUploadsAsync:(id<NSFastEnumeration> /* WNBUploadOperation* */)operations
                                 success:(void (^)(WNBUnconstrainedTransferRequestResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WNBIBackgroundUploaderUserConsent_inst();
    THROW_NS_IF_FAILED(_comInst->RequestUnconstrainedUploadsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                              ABI::Windows::Networking::BackgroundTransfer::IUploadOperation*>>::type>*>(
            ConvertToIterable<
                WNBUploadOperation,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                                  ABI::Windows::Networking::BackgroundTransfer::IUploadOperation*>>(
                operations)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UnconstrainedTransferRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUnconstrainedTransferRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUnconstrainedTransferRequestResult>(result.Get()));
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

- (WNBUploadOperation*)createUpload:(WFUri*)uri sourceFile:(RTObject<WSIStorageFile>*)sourceFile {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateUpload(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                              _getRtInterface<ABI::Windows::Storage::IStorageFile>(sourceFile).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBUploadOperation>(unmarshalledReturn.Get());
}

- (void)createUploadFromStreamAsync:(WFUri*)uri
                       sourceStream:(RTObject<WSSIInputStream>*)sourceStream
                            success:(void (^)(WNBUploadOperation*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateUploadFromStreamAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                              _getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(sourceStream).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (void)createUploadWithFormDataAndAutoBoundaryAsync:(WFUri*)uri
                                               parts:(id<NSFastEnumeration> /* WNBBackgroundTransferContentPart* */)parts
                                             success:(void (^)(WNBUploadOperation*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateUploadWithFormDataAndAutoBoundaryAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
            ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>::type>*>(
            ConvertToIterable<WNBBackgroundTransferContentPart,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
                                  ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>(parts)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (void)createUploadWithSubTypeAsync:(WFUri*)uri
                               parts:(id<NSFastEnumeration> /* WNBBackgroundTransferContentPart* */)parts
                             subType:(NSString*)subType
                             success:(void (^)(WNBUploadOperation*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateUploadWithSubTypeAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
            ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>::type>*>(
            ConvertToIterable<WNBBackgroundTransferContentPart,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
                                  ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>(parts)
                .Get()),
        nsStrToHstr(subType).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (void)createUploadWithSubTypeAndBoundaryAsync:(WFUri*)uri
                                          parts:(id<NSFastEnumeration> /* WNBBackgroundTransferContentPart* */)parts
                                        subType:(NSString*)subType
                                       boundary:(NSString*)boundary
                                        success:(void (^)(WNBUploadOperation*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader>(self);
    THROW_NS_IF_FAILED(_comInst->CreateUploadWithSubTypeAndBoundaryAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
            ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>::type>*>(
            ConvertToIterable<WNBBackgroundTransferContentPart,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
                                  ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*>>(parts)
                .Get()),
        nsStrToHstr(subType).Get(),
        nsStrToHstr(boundary).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WNBUploadOperation>(result.Get()));
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

- (void)setRequestHeader:(NSString*)headerName headerValue:(NSString*)headerValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->SetRequestHeader(nsStrToHstr(headerName).Get(), nsStrToHstr(headerValue).Get()));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)credential {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(credential).Get()));
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setMethod:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Method(nsStrToHstr(value).Get()));
}

- (NSString*)group {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setGroup:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(nsStrToHstr(value).Get()));
}

- (WNBBackgroundTransferCostPolicy)costPolicy {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CostPolicy(&unmarshalledReturn));
    return (WNBBackgroundTransferCostPolicy)unmarshalledReturn;
}

- (void)setCostPolicy:(WNBBackgroundTransferCostPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_CostPolicy((ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferCostPolicy)value));
}

- (WNBBackgroundTransferGroup*)transferGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransferGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferGroup>(unmarshalledReturn.Get());
}

- (void)setTransferGroup:(WNBBackgroundTransferGroup*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_TransferGroup(_getRtInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroup>(value).Get()));
}

- (WUNToastNotification*)successToastNotification {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuccessToastNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotification>(unmarshalledReturn.Get());
}

- (void)setSuccessToastNotification:(WUNToastNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SuccessToastNotification(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(value).Get()));
}

- (WUNToastNotification*)failureToastNotification {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FailureToastNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotification>(unmarshalledReturn.Get());
}

- (void)setFailureToastNotification:(WUNToastNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_FailureToastNotification(_getRtInterface<ABI::Windows::UI::Notifications::IToastNotification>(value).Get()));
}

- (WUNTileNotification*)successTileNotification {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuccessTileNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileNotification>(unmarshalledReturn.Get());
}

- (void)setSuccessTileNotification:(WUNTileNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_SuccessTileNotification(_getRtInterface<ABI::Windows::UI::Notifications::ITileNotification>(value).Get()));
}

- (WUNTileNotification*)failureTileNotification {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FailureTileNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileNotification>(unmarshalledReturn.Get());
}

- (void)setFailureTileNotification:(WUNTileNotification*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_FailureTileNotification(_getRtInterface<ABI::Windows::UI::Notifications::ITileNotification>(value).Get()));
}

- (WNBBackgroundTransferCompletionGroup*)completionGroup {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploader3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompletionGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNBBackgroundTransferCompletionGroup>(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundTransferError

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods>
WNBIBackgroundTransferErrorStaticMethods_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.BackgroundTransferError").Get(), &inst));
    return inst;
}

+ (WWWebErrorStatus)getStatus:(int)hresult {
    ABI::Windows::Web::WebErrorStatus unmarshalledReturn;
    auto _comInst = WNBIBackgroundTransferErrorStaticMethods_inst();
    THROW_NS_IF_FAILED(_comInst->GetStatus(hresult, &unmarshalledReturn));
    return (WWWebErrorStatus)unmarshalledReturn;
}

@end

@implementation WNBContentPrefetcher

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcher> WNBIContentPrefetcher_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcher> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.ContentPrefetcher").Get(), &inst));
    return inst;
}

+ (NSMutableArray* /* WFUri* */)contentUris {
    ComPtr<IVector<ABI::Windows::Foundation::Uri*>> unmarshalledReturn;
    auto _comInst = WNBIContentPrefetcher_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentUris(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WFUri_create(unmarshalledReturn.Get());
}

+ (void)setIndirectContentUri:(WFUri*)value {
    auto _comInst = WNBIContentPrefetcher_inst();
    THROW_NS_IF_FAILED(_comInst->put_IndirectContentUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

+ (WFUri*)indirectContentUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WNBIContentPrefetcher_inst();
    THROW_NS_IF_FAILED(_comInst->get_IndirectContentUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcherTime> WNBIContentPrefetcherTime_inst() {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcherTime> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.BackgroundTransfer.ContentPrefetcher").Get(), &inst));
    return inst;
}

+ (id /* WFDateTime* */)lastSuccessfulPrefetchTime {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = WNBIContentPrefetcherTime_inst();
    THROW_NS_IF_FAILED(_comInst->get_LastSuccessfulPrefetchTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundTransferCompletionGroupTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WNBDownloadOperation* */)downloads {
    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Downloads(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNBDownloadOperation_create(unmarshalledReturn.Get());
}

- (NSArray* /* WNBUploadOperation* */)uploads {
    ComPtr<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferCompletionGroupTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uploads(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WNBUploadOperation_create(unmarshalledReturn.Get());
}

@end

@implementation WNBBackgroundDownloadProgress {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress)s {
    WNBBackgroundDownloadProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress*)internalStruct {
    return &structVal;
}
- (uint64_t)bytesReceived {
    return structVal.BytesReceived;
}
- (void)setBytesReceived:(uint64_t)val {
    structVal.BytesReceived = val;
}
- (uint64_t)totalBytesToReceive {
    return structVal.TotalBytesToReceive;
}
- (void)setTotalBytesToReceive:(uint64_t)val {
    structVal.TotalBytesToReceive = val;
}
- (WNBBackgroundTransferStatus)status {
    return (WNBBackgroundTransferStatus)structVal.Status;
}
- (void)setStatus:(WNBBackgroundTransferStatus)val {
    structVal.Status = (ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus)val;
}
- (BOOL)hasResponseChanged {
    return (BOOL)structVal.HasResponseChanged;
}
- (void)setHasResponseChanged:(BOOL)val {
    structVal.HasResponseChanged = (boolean)val;
}
- (BOOL)hasRestarted {
    return (BOOL)structVal.HasRestarted;
}
- (void)setHasRestarted:(BOOL)val {
    structVal.HasRestarted = (boolean)val;
}
@end
@implementation WNBBackgroundUploadProgress {
    ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress)s {
    WNBBackgroundUploadProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress*)internalStruct {
    return &structVal;
}
- (uint64_t)bytesReceived {
    return structVal.BytesReceived;
}
- (void)setBytesReceived:(uint64_t)val {
    structVal.BytesReceived = val;
}
- (uint64_t)bytesSent {
    return structVal.BytesSent;
}
- (void)setBytesSent:(uint64_t)val {
    structVal.BytesSent = val;
}
- (uint64_t)totalBytesToReceive {
    return structVal.TotalBytesToReceive;
}
- (void)setTotalBytesToReceive:(uint64_t)val {
    structVal.TotalBytesToReceive = val;
}
- (uint64_t)totalBytesToSend {
    return structVal.TotalBytesToSend;
}
- (void)setTotalBytesToSend:(uint64_t)val {
    structVal.TotalBytesToSend = val;
}
- (WNBBackgroundTransferStatus)status {
    return (WNBBackgroundTransferStatus)structVal.Status;
}
- (void)setStatus:(WNBBackgroundTransferStatus)val {
    structVal.Status = (ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferStatus)val;
}
- (BOOL)hasResponseChanged {
    return (BOOL)structVal.HasResponseChanged;
}
- (void)setHasResponseChanged:(BOOL)val {
    structVal.HasResponseChanged = (boolean)val;
}
- (BOOL)hasRestarted {
    return (BOOL)structVal.HasRestarted;
}
- (void)setHasRestarted:(BOOL)val {
    structVal.HasRestarted = (boolean)val;
}
@end
id RTProxiedIterableNSArray_WNBBackgroundTransferContentPart_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*>,
                                RTIterableObj<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPart*,
                                              IIterable<ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*>,
                                              WNBBackgroundTransferContentPart,
                                              ABI::Windows::Networking::BackgroundTransfer::BackgroundTransferContentPart*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WNBDownloadOperation_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
                                                 RTIterableObj<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation*,
                                                               IIterable<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
                                                               WNBDownloadOperation,
                                                               ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WNBUploadOperation_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
                                                 RTIterableObj<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation*,
                                                               IIterable<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
                                                               WNBUploadOperation,
                                                               ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNBDownloadOperation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
                                         RTArrayObj<ABI::Windows::Networking::BackgroundTransfer::IDownloadOperation*,
                                                    IVectorView<ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*>,
                                                    WNBDownloadOperation,
                                                    ABI::Windows::Networking::BackgroundTransfer::DownloadOperation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WNBUploadOperation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
                                         RTArrayObj<ABI::Windows::Networking::BackgroundTransfer::IUploadOperation*,
                                                    IVectorView<ABI::Windows::Networking::BackgroundTransfer::UploadOperation*>,
                                                    WNBUploadOperation,
                                                    ABI::Windows::Networking::BackgroundTransfer::UploadOperation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, HSTRING>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          NSString,
                                          NSString,
                                          IMapView<HSTRING, HSTRING>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Foundation::Uri*>,
                                                RTMutableArrayObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                                  IVector<ABI::Windows::Foundation::Uri*>,
                                                                  WFUri,
                                                                  ABI::Windows::Foundation::Uri*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
