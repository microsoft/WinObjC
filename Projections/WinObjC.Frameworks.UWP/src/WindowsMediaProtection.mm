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

// WindowsMediaProtection.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Protection.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaProtection.h"
#include "WindowsMediaProtection_priv.h"

@implementation WMPIMediaProtectionServiceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)protectionSystem {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionSystem(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFGUID*)type {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

@end

@implementation WMPMediaProtectionManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.MediaProtectionManager").Get(), &out));
    return [_createRtProxy<WMPMediaProtectionManager>(out.Get()) retain];
}

- (EventRegistrationToken)addServiceRequestedEvent:(WMPServiceRequestedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServiceRequested(Make<WMPServiceRequestedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServiceRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServiceRequested(cookie));
}

- (EventRegistrationToken)addRebootNeededEvent:(WMPRebootNeededEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_RebootNeeded(Make<WMPRebootNeededEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRebootNeededEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RebootNeeded(cookie));
}

- (EventRegistrationToken)addComponentLoadFailedEvent:(WMPComponentLoadFailedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ComponentLoadFailed(Make<WMPComponentLoadFailedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeComponentLoadFailedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ComponentLoadFailed(cookie));
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMPServiceRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IServiceRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMPIMediaProtectionServiceRequest>*)request {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionServiceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IServiceRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPIMediaProtectionServiceRequest>(unmarshalledReturn.Get());
}

- (WMPMediaProtectionServiceCompletion*)completion {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionServiceCompletion> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IServiceRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completion(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaProtectionServiceCompletion>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)mediaPlaybackItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IServiceRequestedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaPlaybackItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

@end

@implementation WMPComponentLoadFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IComponentLoadFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPRevocationAndRenewalInformation*)information {
    ComPtr<ABI::Windows::Media::Protection::IRevocationAndRenewalInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IComponentLoadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Information(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPRevocationAndRenewalInformation>(unmarshalledReturn.Get());
}

- (WMPMediaProtectionServiceCompletion*)completion {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionServiceCompletion> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IComponentLoadFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completion(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaProtectionServiceCompletion>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaProtectionServiceCompletion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionServiceCompletion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete:(BOOL)success {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionServiceCompletion>(self);
    THROW_NS_IF_FAILED(_comInst->Complete((boolean)success));
}

@end

@implementation WMPRevocationAndRenewalInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IRevocationAndRenewalInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* WMPRevocationAndRenewalItem* */)items {
    ComPtr<IVector<ABI::Windows::Media::Protection::RevocationAndRenewalItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMPRevocationAndRenewalItem_create(unmarshalledReturn.Get());
}

@end

@implementation WMPRevocationAndRenewalItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IRevocationAndRenewalItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPRevocationAndRenewalReasons)reasons {
    ABI::Windows::Media::Protection::RevocationAndRenewalReasons unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reasons(&unmarshalledReturn));
    return (WMPRevocationAndRenewalReasons)unmarshalledReturn;
}

- (NSString*)headerHash {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderHash(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)publicKeyHash {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicKeyHash(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)renewalId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenewalId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMPMediaProtectionPMPServer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionPMPServer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Protection::IMediaProtectionPMPServerFactory> WMPIMediaProtectionPMPServerFactory_inst() {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionPMPServerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.MediaProtectionPMPServer").Get(),
                                                       &inst));
    return inst;
}

+ (WMPMediaProtectionPMPServer*)makePMPServer:(RTObject<WFCIPropertySet>*)pProperties {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionPMPServer> unmarshalledReturn;
    auto _comInst = WMPIMediaProtectionPMPServerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePMPServer(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(pProperties).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaProtectionPMPServer>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IMediaProtectionPMPServer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMPProtectionCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IProtectionCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.ProtectionCapabilities").Get(), &out));
    return [_createRtProxy<WMPProtectionCapabilities>(out.Get()) retain];
}

- (WMPProtectionCapabilityResult)isTypeSupported:(NSString*)type keySystem:(NSString*)keySystem {
    ABI::Windows::Media::Protection::ProtectionCapabilityResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IProtectionCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->IsTypeSupported(nsStrToHstr(type).Get(), nsStrToHstr(keySystem).Get(), &unmarshalledReturn));
    return (WMPProtectionCapabilityResult)unmarshalledReturn;
}

@end

@implementation WMPHdcpSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Protection::IHdcpSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Protection.HdcpSession").Get(), &out));
    return [_createRtProxy<WMPHdcpSession>(out.Get()) retain];
}

- (BOOL)isEffectiveProtectionAtLeast:(WMPHdcpProtection)protection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IHdcpSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsEffectiveProtectionAtLeast((ABI::Windows::Media::Protection::HdcpProtection)protection, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* WMPHdcpProtection */)getEffectiveProtection {
    ComPtr<IReference<ABI::Windows::Media::Protection::HdcpProtection>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IHdcpSession>(self);
    THROW_NS_IF_FAILED(_comInst->GetEffectiveProtection(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WMPHdcpProtection, ABI::Windows::Media::Protection::HdcpProtection>::convert(unmarshalledReturn.Get());
}

- (void)setDesiredMinProtectionAsync:(WMPHdcpProtection)protection
                             success:(void (^)(WMPHdcpSetProtectionResult))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::HdcpSetProtectionResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IHdcpSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetDesiredMinProtectionAsync((ABI::Windows::Media::Protection::HdcpProtection)protection, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Protection::HdcpSetProtectionResult>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Protection::HdcpSetProtectionResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Protection::HdcpSetProtectionResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMPHdcpSetProtectionResult)result);
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

- (EventRegistrationToken)addProtectionChangedEvent:(void (^)(WMPHdcpSession*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IHdcpSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ProtectionChanged(Make<ITypedEventHandler_Windows_Media_Protection_HdcpSession_System_Object>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProtectionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Protection::IHdcpSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ProtectionChanged(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMPComponentRenewal

ComPtr<ABI::Windows::Media::Protection::IComponentRenewalStatics> WMPIComponentRenewalStatics_inst() {
    ComPtr<ABI::Windows::Media::Protection::IComponentRenewalStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Protection.ComponentRenewal").Get(), &inst));
    return inst;
}

+ (void)renewSystemComponentsAsync:(WMPRevocationAndRenewalInformation*)information
                           success:(void (^)(WMPRenewalStatus))success
                          progress:(void (^)(unsigned int))progress
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Protection::RenewalStatus, unsigned int>>
        unmarshalledReturn;
    auto _comInst = WMPIComponentRenewalStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RenewSystemComponentsAsync(
        _getRtInterface<ABI::Windows::Media::Protection::IRevocationAndRenewalInformation>(information).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Media::Protection::RenewalStatus, unsigned int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Protection::RenewalStatus, unsigned int>* op,
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
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Media::Protection::RenewalStatus,
                                                                              unsigned int>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Media::Protection::RenewalStatus, unsigned int>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Protection::RenewalStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMPRenewalStatus)result);
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

id RTProxiedNSMutableArray_WMPRevocationAndRenewalItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Protection::RevocationAndRenewalItem*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Protection::IRevocationAndRenewalItem*,
                                                                  IVector<ABI::Windows::Media::Protection::RevocationAndRenewalItem*>,
                                                                  WMPRevocationAndRenewalItem,
                                                                  ABI::Windows::Media::Protection::RevocationAndRenewalItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
