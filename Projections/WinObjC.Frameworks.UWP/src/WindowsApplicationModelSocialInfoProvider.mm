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

// WindowsApplicationModelSocialInfoProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.SocialInfo.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelSocialInfoProvider.h"
#include "WindowsApplicationModelSocialInfoProvider_priv.h"

@implementation WASPSocialFeedUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)ownerRemoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerRemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSocialFeedKind)kind {
    ABI::Windows::ApplicationModel::SocialInfo::SocialFeedKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WASSocialFeedKind)unmarshalledReturn;
}

- (NSMutableArray* /* WASSocialFeedItem* */)items {
    ComPtr<IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WASSocialFeedItem_create(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)commitAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->CommitAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WASPSocialDashboardItemUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)ownerRemoteId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_OwnerRemoteId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASSocialFeedContent*)content {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialFeedContent>(unmarshalledReturn.Get());
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setTimestamp:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->put_Timestamp(*[value internalStruct]));
}

- (void)setThumbnail:(WASSocialItemThumbnail*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Thumbnail(_getRtInterface<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail>(value).Get()));
}

- (WASSocialItemThumbnail*)thumbnail {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::ISocialItemThumbnail> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASSocialItemThumbnail>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)commitAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->CommitAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WFUri*)targetUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setTargetUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WASPSocialInfoProviderManager

ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
WASPISocialInfoProviderManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.SocialInfo.Provider.SocialInfoProviderManager").Get(), &inst));
    return inst;
}

+ (void)createSocialFeedUpdaterAsync:(WASSocialFeedKind)kind
                                mode:(WASSocialFeedUpdateMode)mode
                       ownerRemoteId:(NSString*)ownerRemoteId
                             success:(void (^)(WASPSocialFeedUpdater*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater*>>
        unmarshalledReturn;
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateSocialFeedUpdaterAsync((ABI::Windows::ApplicationModel::SocialInfo::SocialFeedKind)kind,
                                                              (ABI::Windows::ApplicationModel::SocialInfo::SocialFeedUpdateMode)mode,
                                                              nsStrToHstr(ownerRemoteId).Get(),
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WASPSocialFeedUpdater>(result.Get()));
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

+ (void)createDashboardItemUpdaterAsync:(NSString*)ownerRemoteId
                                success:(void (^)(WASPSocialDashboardItemUpdater*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater*>>
        unmarshalledReturn;
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDashboardItemUpdaterAsync(nsStrToHstr(ownerRemoteId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPSocialDashboardItemUpdater>(result.Get()));
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

+ (void)updateBadgeCountValue:(NSString*)itemRemoteId newCount:(int)newCount {
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UpdateBadgeCountValue(nsStrToHstr(itemRemoteId).Get(), newCount));
}

+ (void)reportNewContentAvailable:(NSString*)contactRemoteId kind:(WASSocialFeedKind)kind {
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ReportNewContentAvailable(nsStrToHstr(contactRemoteId).Get(),
                                                           (ABI::Windows::ApplicationModel::SocialInfo::SocialFeedKind)kind));
}

+ (void)provisionAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProvisionAsync(&unmarshalledReturn));

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

+ (RTObject<WFIAsyncAction>*)deprovisionAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WASPISocialInfoProviderManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DeprovisionAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSMutableArray_WASSocialFeedItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItem*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::SocialInfo::ISocialFeedItem*,
                                                                  IVector<ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItem*>,
                                                                  WASSocialFeedItem,
                                                                  ABI::Windows::ApplicationModel::SocialInfo::SocialFeedItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
