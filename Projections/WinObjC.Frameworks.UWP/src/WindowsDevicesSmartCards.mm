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

// WindowsDevicesSmartCards.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.SmartCards.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSmartCards.h"
#include "WindowsDevicesSmartCards_priv.h"

@implementation WDSSmartCardTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardTriggerType)triggerType {
    ABI::Windows::Devices::SmartCards::SmartCardTriggerType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerType(&unmarshalledReturn));
    return (WDSSmartCardTriggerType)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)sourceAppletId {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceAppletId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)triggerData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriggerData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDSSmartCardEmulator*)emulator {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emulator(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardEmulator>(unmarshalledReturn.Get());
}

- (void)tryLaunchCurrentAppAsync:(NSString*)arguments success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->TryLaunchCurrentAppAsync(nsStrToHstr(arguments).Get(), &unmarshalledReturn));

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

- (void)tryLaunchCurrentAppWithBehaviorAsync:(NSString*)arguments
                                    behavior:(WDSSmartCardLaunchBehavior)behavior
                                     success:(void (^)(BOOL))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardTriggerDetails2>(self);
    THROW_NS_IF_FAILED(_comInst->TryLaunchCurrentAppWithBehaviorAsync(nsStrToHstr(arguments).Get(),
                                                                      (ABI::Windows::Devices::SmartCards::SmartCardLaunchBehavior)behavior,
                                                                      &unmarshalledReturn));

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

@end

@implementation WDSSmartCardEmulator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics2> WDSISmartCardEmulatorStatics2_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardEmulator").Get(),
                                                       &inst));
    return inst;
}

+ (void)getAppletIdGroupRegistrationsAsyncWithSuccess:(void (^)(NSArray* /* WDSSmartCardAppletIdGroupRegistration* */))success
                                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>*>>
        unmarshalledReturn;
    auto _comInst = WDSISmartCardEmulatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetAppletIdGroupRegistrationsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WDSSmartCardAppletIdGroupRegistration_create(result.Get()));
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

+ (void)registerAppletIdGroupAsync:(WDSSmartCardAppletIdGroup*)appletIdGroup
                           success:(void (^)(WDSSmartCardAppletIdGroupRegistration*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>>
        unmarshalledReturn;
    auto _comInst = WDSISmartCardEmulatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RegisterAppletIdGroupAsync(
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(appletIdGroup).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardAppletIdGroupRegistration>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)unregisterAppletIdGroupAsync:(WDSSmartCardAppletIdGroupRegistration*)registration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WDSISmartCardEmulatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterAppletIdGroupAsync(
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(registration).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (unsigned short)maxAppletIdGroupRegistrations {
    unsigned short unmarshalledReturn;
    auto _comInst = WDSISmartCardEmulatorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxAppletIdGroupRegistrations(&unmarshalledReturn));
    return unmarshalledReturn;
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics> WDSISmartCardEmulatorStatics_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardEmulator").Get(),
                                                       &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSSmartCardEmulator*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardEmulator*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardEmulatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardEmulator*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardEmulator*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulator> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardEmulator>(result.Get()));
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

- (WDSSmartCardEmulatorEnablementPolicy)enablementPolicy {
    ABI::Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnablementPolicy(&unmarshalledReturn));
    return (WDSSmartCardEmulatorEnablementPolicy)unmarshalledReturn;
}

- (EventRegistrationToken)addApduReceivedEvent:(void (^)(WDSSmartCardEmulator*, WDSSmartCardEmulatorApduReceivedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ApduReceived(
        Make<
            ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeApduReceivedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ApduReceived(value));
}

- (EventRegistrationToken)addConnectionDeactivatedEvent:(void (^)(WDSSmartCardEmulator*,
                                                                  WDSSmartCardEmulatorConnectionDeactivatedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ConnectionDeactivated(
        Make<
            ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConnectionDeactivatedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ConnectionDeactivated(value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (BOOL)isHostCardEmulationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulator2>(self);
    THROW_NS_IF_FAILED(_comInst->IsHostCardEmulationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDSSmartCardAppletIdGroupRegistration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardAppletIdGroupActivationPolicy)activationPolicy {
    ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivationPolicy(&unmarshalledReturn));
    return (WDSSmartCardAppletIdGroupActivationPolicy)unmarshalledReturn;
}

- (WDSSmartCardAppletIdGroup*)appletIdGroup {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppletIdGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardAppletIdGroup>(unmarshalledReturn.Get());
}

- (void)requestActivationPolicyChangeAsync:(WDSSmartCardAppletIdGroupActivationPolicy)policy
                                   success:(void (^)(WDSSmartCardActivationPolicyChangeResult))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(self);
    THROW_NS_IF_FAILED(
        _comInst->RequestActivationPolicyChangeAsync((ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy)policy,
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDSSmartCardActivationPolicyChangeResult)result);
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

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)setAutomaticResponseApdusAsync:(id<NSFastEnumeration> /* WDSSmartCardAutomaticResponseApdu* */)apdus {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->SetAutomaticResponseApdusAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu*,
            ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu*>>::type>*>(
            ConvertToIterable<
                WDSSmartCardAutomaticResponseApdu,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu*,
                                                                  ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu*>>(
                apdus)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WDSSmartCardAppletIdGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardAppletIdGroup").Get(), &out));
    return [_createRtProxy<WDSSmartCardAppletIdGroup>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory> WDSISmartCardAppletIdGroupFactory_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardAppletIdGroup").Get(),
                                                       &inst));
    return inst;
}

+ (WDSSmartCardAppletIdGroup*)make:(NSString*)displayName
                         appletIds:(NSMutableArray* /* RTObject<WSSIBuffer>* */)appletIds
                 emulationCategory:(WDSSmartCardEmulationCategory)emulationCategory
                     emulationType:(WDSSmartCardEmulationType)emulationType {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup> unmarshalledReturn;
    auto _comInst = WDSISmartCardAppletIdGroupFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(nsStrToHstr(displayName).Get(),
                         static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                             ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IBuffer*,
                                                                               ABI::Windows::Storage::Streams::IBuffer*>>::type>*>(
                             ConvertToVector<RTObject<WSSIBuffer>,
                                             ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Storage::Streams::IBuffer*,
                                                                                               ABI::Windows::Storage::Streams::IBuffer*>>(
                                 appletIds)
                                 .Get()),
                         (ABI::Windows::Devices::SmartCards::SmartCardEmulationCategory)emulationCategory,
                         (ABI::Windows::Devices::SmartCards::SmartCardEmulationType)emulationType,
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSSmartCardAppletIdGroup>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics> WDSISmartCardAppletIdGroupStatics_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardAppletIdGroup").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned short)maxAppletIds {
    unsigned short unmarshalledReturn;
    auto _comInst = WDSISmartCardAppletIdGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxAppletIds(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* RTObject<WSSIBuffer>* */)appletIds {
    ComPtr<IVector<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppletIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WSSIBuffer_create(unmarshalledReturn.Get());
}

- (WDSSmartCardEmulationCategory)smartCardEmulationCategory {
    ABI::Windows::Devices::SmartCards::SmartCardEmulationCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartCardEmulationCategory(&unmarshalledReturn));
    return (WDSSmartCardEmulationCategory)unmarshalledReturn;
}

- (void)setSmartCardEmulationCategory:(WDSSmartCardEmulationCategory)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmartCardEmulationCategory((ABI::Windows::Devices::SmartCards::SmartCardEmulationCategory)value));
}

- (WDSSmartCardEmulationType)smartCardEmulationType {
    ABI::Windows::Devices::SmartCards::SmartCardEmulationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartCardEmulationType(&unmarshalledReturn));
    return (WDSSmartCardEmulationType)unmarshalledReturn;
}

- (void)setSmartCardEmulationType:(WDSSmartCardEmulationType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmartCardEmulationType((ABI::Windows::Devices::SmartCards::SmartCardEmulationType)value));
}

- (BOOL)automaticEnablement {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomaticEnablement(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutomaticEnablement:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroup>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutomaticEnablement((boolean)value));
}

@end

@implementation WDSSmartCardEmulatorApduReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)commandApdu {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandApdu(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDSSmartCardEmulatorConnectionProperties*)connectionProperties {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardEmulatorConnectionProperties>(unmarshalledReturn.Get());
}

- (void)tryRespondAsync:(RTObject<WSSIBuffer>*)responseApdu success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryRespondAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(responseApdu).Get(), &unmarshalledReturn));

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

- (WDSSmartCardAutomaticResponseStatus)automaticResponseStatus {
    ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomaticResponseStatus(&unmarshalledReturn));
    return (WDSSmartCardAutomaticResponseStatus)unmarshalledReturn;
}

- (void)tryRespondWithCryptogramsAsync:(RTObject<WSSIBuffer>*)responseTemplate
              cryptogramPlacementSteps:(id<NSFastEnumeration> /* WDSSmartCardCryptogramPlacementStep* */)cryptogramPlacementSteps
                               success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>(self);
    THROW_NS_IF_FAILED(_comInst->TryRespondWithCryptogramsAsync(
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(responseTemplate).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*,
            ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep*>>::type>*>(
            ConvertToIterable<
                WDSSmartCardCryptogramPlacementStep,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*,
                                                                  ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep*>>(
                cryptogramPlacementSteps)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (void)tryRespondWithCryptogramsAndStateAsync:(RTObject<WSSIBuffer>*)responseTemplate
                      cryptogramPlacementSteps:(id<NSFastEnumeration> /* WDSSmartCardCryptogramPlacementStep* */)cryptogramPlacementSteps
                                     nextState:(id /* unsigned int */)nextState
                                       success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>(self);
    THROW_NS_IF_FAILED(_comInst->TryRespondWithCryptogramsAndStateAsync(
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(responseTemplate).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*,
            ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep*>>::type>*>(
            ConvertToIterable<
                WDSSmartCardCryptogramPlacementStep,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*,
                                                                  ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep*>>(
                cryptogramPlacementSteps)
                .Get()),
        BuildNullable<unsigned int>(nextState),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (unsigned int)state {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)tryRespondWithStateAsync:(RTObject<WSSIBuffer>*)responseApdu
                       nextState:(id /* unsigned int */)nextState
                         success:(void (^)(BOOL))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>(self);
    THROW_NS_IF_FAILED(_comInst->TryRespondWithStateAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(responseApdu).Get(),
                                                          BuildNullable<unsigned int>(nextState),
                                                          &unmarshalledReturn));

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

@end

@implementation WDSSmartCardEmulatorConnectionDeactivatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardEmulatorConnectionProperties*)connectionProperties {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardEmulatorConnectionProperties>(unmarshalledReturn.Get());
}

- (WDSSmartCardEmulatorConnectionDeactivatedReason)reason {
    ABI::Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WDSSmartCardEmulatorConnectionDeactivatedReason)unmarshalledReturn;
}

@end

@implementation WDSSmartCardEmulatorConnectionProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WDSSmartCardEmulatorConnectionSource)source {
    ABI::Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(&unmarshalledReturn));
    return (WDSSmartCardEmulatorConnectionSource)unmarshalledReturn;
}

@end

@implementation WDSSmartCardAutomaticResponseApdu

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory> WDSISmartCardAutomaticResponseApduFactory_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardAutomaticResponseApdu").Get(), &inst));
    return inst;
}

+ (WDSSmartCardAutomaticResponseApdu*)make:(RTObject<WSSIBuffer>*)commandApdu responseApdu:(RTObject<WSSIBuffer>*)responseApdu {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu> unmarshalledReturn;
    auto _comInst = WDSISmartCardAutomaticResponseApduFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(commandApdu).Get(),
                                        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(responseApdu).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSSmartCardAutomaticResponseApdu>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WSSIBuffer>*)commandApdu {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandApdu(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setCommandApdu:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommandApdu(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (RTObject<WSSIBuffer>*)commandApduBitMask {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandApduBitMask(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setCommandApduBitMask:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommandApduBitMask(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (BOOL)shouldMatchLength {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldMatchLength(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShouldMatchLength:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShouldMatchLength((boolean)value));
}

- (RTObject<WSSIBuffer>*)appletId {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppletId(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setAppletId:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppletId(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (RTObject<WSSIBuffer>*)responseApdu {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseApdu(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setResponseApdu:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>(self);
    THROW_NS_IF_FAILED(_comInst->put_ResponseApdu(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (id /* unsigned int */)inputState {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputState(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setInputState:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputState(BuildNullable<unsigned int>(value)));
}

- (id /* unsigned int */)outputState {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputState(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setOutputState:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutputState(BuildNullable<unsigned int>(value)));
}

- (BOOL)allowWhenCryptogramGeneratorNotPrepared {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowWhenCryptogramGeneratorNotPrepared(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowWhenCryptogramGeneratorNotPrepared:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowWhenCryptogramGeneratorNotPrepared((boolean)value));
}

@end

@implementation WDSSmartCardCryptogramPlacementStep

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardCryptogramPlacementStep").Get(),
                                              &out));
    return [_createRtProxy<WDSSmartCardCryptogramPlacementStep>(out.Get()) retain];
}

- (WDSSmartCardCryptogramAlgorithm)algorithm {
    ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_Algorithm(&unmarshalledReturn));
    return (WDSSmartCardCryptogramAlgorithm)unmarshalledReturn;
}

- (void)setAlgorithm:(WDSSmartCardCryptogramAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_Algorithm((ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm)value));
}

- (RTObject<WSSIBuffer>*)sourceData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setSourceData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceData(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (NSString*)cryptogramMaterialPackageName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_CryptogramMaterialPackageName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCryptogramMaterialPackageName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_CryptogramMaterialPackageName(nsStrToHstr(value).Get()));
}

- (NSString*)cryptogramMaterialName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_CryptogramMaterialName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCryptogramMaterialName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_CryptogramMaterialName(nsStrToHstr(value).Get()));
}

- (int)templateOffset {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_TemplateOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTemplateOffset:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_TemplateOffset(value));
}

- (int)cryptogramOffset {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_CryptogramOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCryptogramOffset:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_CryptogramOffset(value));
}

- (int)cryptogramLength {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_CryptogramLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCryptogramLength:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_CryptogramLength(value));
}

- (WDSSmartCardCryptogramPlacementOptions)cryptogramPlacementOptions {
    ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_CryptogramPlacementOptions(&unmarshalledReturn));
    return (WDSSmartCardCryptogramPlacementOptions)unmarshalledReturn;
}

- (void)setCryptogramPlacementOptions:(WDSSmartCardCryptogramPlacementOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_CryptogramPlacementOptions((ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions)value));
}

- (WDSSmartCardCryptogramPlacementStep*)chainedOutputStep {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChainedOutputStep(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardCryptogramPlacementStep>(unmarshalledReturn.Get());
}

- (void)setChainedOutputStep:(WDSSmartCardCryptogramPlacementStep*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChainedOutputStep(
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>(value).Get()));
}

@end

@implementation WDSSmartCardCryptogramGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics> WDSISmartCardCryptogramGeneratorStatics_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardCryptogramGenerator").Get(), &inst));
    return inst;
}

+ (void)getSmartCardCryptogramGeneratorAsyncWithSuccess:(void (^)(WDSSmartCardCryptogramGenerator*))success
                                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGenerator*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardCryptogramGeneratorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSmartCardCryptogramGeneratorAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGenerator*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGenerator*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardCryptogramGenerator>(result.Get()));
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

- (NSArray* /* WDSSmartCardCryptogramMaterialType */)supportedCryptogramMaterialTypes {
    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCryptogramMaterialTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmartCardCryptogramMaterialType_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDSSmartCardCryptogramAlgorithm */)supportedCryptogramAlgorithms {
    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCryptogramAlgorithms(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmartCardCryptogramAlgorithm_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDSSmartCardCryptogramMaterialPackageFormat */)supportedCryptogramMaterialPackageFormats {
    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCryptogramMaterialPackageFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageFormat_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat */)
    supportedCryptogramMaterialPackageConfirmationResponseFormats {
    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCryptogramMaterialPackageConfirmationResponseFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDSSmartCardCryptogramStorageKeyCapabilities */)supportedSmartCardCryptogramStorageKeyCapabilities {
    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedSmartCardCryptogramStorageKeyCapabilities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSSmartCardCryptogramStorageKeyCapabilities_create(unmarshalledReturn.Get());
}

- (void)deleteCryptogramMaterialStorageKeyAsync:(NSString*)storageKeyName
                                        success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteCryptogramMaterialStorageKeyAsync(nsStrToHstr(storageKeyName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (void)createCryptogramMaterialStorageKeyAsync:(WDSSmartCardUnlockPromptingBehavior)promptingBehavior
                                 storageKeyName:(NSString*)storageKeyName
                                      algorithm:(WDSSmartCardCryptogramStorageKeyAlgorithm)algorithm
                                   capabilities:(WDSSmartCardCryptogramStorageKeyCapabilities)capabilities
                                        success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->CreateCryptogramMaterialStorageKeyAsync(
        (ABI::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior)promptingBehavior,
        nsStrToHstr(storageKeyName).Get(),
        (ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm)algorithm,
        (ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities)capabilities,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (void)requestCryptogramMaterialStorageKeyInfoAsync:(WDSSmartCardUnlockPromptingBehavior)promptingBehavior
                                      storageKeyName:(NSString*)storageKeyName
                                              format:(WSCCCryptographicPublicKeyBlobType)format
                                             success:(void (^)(WDSSmartCardCryptogramStorageKeyInfo*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->RequestCryptogramMaterialStorageKeyInfoAsync(
        (ABI::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior)promptingBehavior,
        nsStrToHstr(storageKeyName).Get(),
        (ABI::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType)format,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardCryptogramStorageKeyInfo>(result.Get()));
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

- (void)importCryptogramMaterialPackageAsync:(WDSSmartCardCryptogramMaterialPackageFormat)format
                              storageKeyName:(NSString*)storageKeyName
                         materialPackageName:(NSString*)materialPackageName
                   cryptogramMaterialPackage:(RTObject<WSSIBuffer>*)cryptogramMaterialPackage
                                     success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->ImportCryptogramMaterialPackageAsync(
        (ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat)format,
        nsStrToHstr(storageKeyName).Get(),
        nsStrToHstr(materialPackageName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(cryptogramMaterialPackage).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (void)tryProvePossessionOfCryptogramMaterialPackageAsync:(WDSSmartCardUnlockPromptingBehavior)promptingBehavior
                                            responseFormat:(WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat)responseFormat
                                       materialPackageName:(NSString*)materialPackageName
                                              materialName:(NSString*)materialName
                                                 challenge:(RTObject<WSSIBuffer>*)challenge
                                                   success:(void (^)(WDSSmartCardCryptogramMaterialPossessionProof*))success
                                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->TryProvePossessionOfCryptogramMaterialPackageAsync(
        (ABI::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior)promptingBehavior,
        (ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat)responseFormat,
        nsStrToHstr(materialPackageName).Get(),
        nsStrToHstr(materialName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(challenge).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSSmartCardCryptogramMaterialPossessionProof>(result.Get()));
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

- (void)requestUnlockCryptogramMaterialForUseAsync:(WDSSmartCardUnlockPromptingBehavior)promptingBehavior
                                           success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->RequestUnlockCryptogramMaterialForUseAsync(
        (ABI::Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior)promptingBehavior, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

- (void)deleteCryptogramMaterialPackageAsync:(NSString*)materialPackageName
                                     success:(void (^)(WDSSmartCardCryptogramGeneratorOperationStatus))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteCryptogramMaterialPackageAsync(nsStrToHstr(materialPackageName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardCryptogramGeneratorOperationStatus)result);
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

@implementation WDSSmartCardCryptogramStorageKeyInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardCryptogramGeneratorOperationStatus)operationStatus {
    ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_OperationStatus(&unmarshalledReturn));
    return (WDSSmartCardCryptogramGeneratorOperationStatus)unmarshalledReturn;
}

- (WSCCCryptographicPublicKeyBlobType)publicKeyBlobType {
    ABI::Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicKeyBlobType(&unmarshalledReturn));
    return (WSCCCryptographicPublicKeyBlobType)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)publicKey {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublicKey(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDSSmartCardCryptographicKeyAttestationStatus)attestationStatus {
    ABI::Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttestationStatus(&unmarshalledReturn));
    return (WDSSmartCardCryptographicKeyAttestationStatus)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)attestation {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Attestation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)attestationCertificateChain {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AttestationCertificateChain(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WDSSmartCardCryptogramStorageKeyCapabilities)capabilities {
    ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(&unmarshalledReturn));
    return (WDSSmartCardCryptogramStorageKeyCapabilities)unmarshalledReturn;
}

- (NSString*)operationalRequirements {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OperationalRequirements(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSSmartCardCryptogramMaterialPossessionProof

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardCryptogramGeneratorOperationStatus)operationStatus {
    ABI::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>(self);
    THROW_NS_IF_FAILED(_comInst->get_OperationStatus(&unmarshalledReturn));
    return (WDSSmartCardCryptogramGeneratorOperationStatus)unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)proof {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>(self);
    THROW_NS_IF_FAILED(_comInst->get_Proof(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDSSmartCardReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReaderStatics> WDSISmartCardReaderStatics_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardReader").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISmartCardReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorWithKind:(WDSSmartCardReaderKind)kind {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSISmartCardReaderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDeviceSelectorWithKind((ABI::Windows::Devices::SmartCards::SmartCardReaderKind)kind, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSSmartCardReader*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardReader*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardReader*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardReader*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReader> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSSmartCardReader>(result.Get()));
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

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSSmartCardReaderKind)kind {
    ABI::Windows::Devices::SmartCards::SmartCardReaderKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WDSSmartCardReaderKind)unmarshalledReturn;
}

- (void)getStatusAsyncWithSuccess:(void (^)(WDSSmartCardReaderStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardReaderStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->GetStatusAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardReaderStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardReaderStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Devices::SmartCards::SmartCardReaderStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WDSSmartCardReaderStatus)result);
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

- (void)findAllCardsAsyncWithSuccess:(void (^)(NSArray* /* WDSSmartCard* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllCardsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSSmartCard_create(result.Get()));
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

- (EventRegistrationToken)addCardAddedEvent:(void (^)(WDSSmartCardReader*, WDSCardAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_CardAdded(
        Make<ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCardAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CardAdded(token));
}

- (EventRegistrationToken)addCardRemovedEvent:(void (^)(WDSSmartCardReader*, WDSCardRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_CardRemoved(
        Make<ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCardRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CardRemoved(token));
}

@end

@implementation WDSSmartCard

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCard> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCardReader*)reader {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReader> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCard>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reader(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardReader>(unmarshalledReturn.Get());
}

- (void)getStatusAsyncWithSuccess:(void (^)(WDSSmartCardStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCard>(self);
    THROW_NS_IF_FAILED(_comInst->GetStatusAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Devices::SmartCards::SmartCardStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WDSSmartCardStatus)result);
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

- (void)getAnswerToResetAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCard>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnswerToResetAsync(&unmarshalledReturn));

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

- (void)connectAsyncWithSuccess:(void (^)(WDSSmartCardConnection*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardConnect>(self);
    THROW_NS_IF_FAILED(_comInst->ConnectAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardConnection*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardConnection*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardConnection> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardConnection>(result.Get()));
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

@implementation WDSCardAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ICardAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCard*)smartCard {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ICardAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartCard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCard>(unmarshalledReturn.Get());
}

@end

@implementation WDSCardRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ICardRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSSmartCard*)smartCard {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ICardRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartCard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCard>(unmarshalledReturn.Get());
}

@end

@implementation WDSSmartCardProvisioning

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics> WDSISmartCardProvisioningStatics_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardProvisioning").Get(),
                                                       &inst));
    return inst;
}

+ (void)fromSmartCardAsync:(WDSSmartCard*)card success:(void (^)(WDSSmartCardProvisioning*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromSmartCardAsync(_getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCard>(card).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardProvisioning>(result.Get()));
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

+ (void)requestVirtualSmartCardCreationAsync:(NSString*)friendlyName
                           administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                   pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                     success:(void (^)(WDSSmartCardProvisioning*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestVirtualSmartCardCreationAsync(
        nsStrToHstr(friendlyName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(administrativeKey).Get(),
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(pinPolicy).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardProvisioning>(result.Get()));
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

+ (void)requestVirtualSmartCardCreationAsyncWithCardId:(NSString*)friendlyName
                                     administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                             pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                                cardId:(WFGUID*)cardId
                                               success:(void (^)(WDSSmartCardProvisioning*))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestVirtualSmartCardCreationAsyncWithCardId(
        nsStrToHstr(friendlyName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(administrativeKey).Get(),
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(pinPolicy).Get(),
        cardId.guidValue,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardProvisioning>(result.Get()));
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

+ (void)requestVirtualSmartCardDeletionAsync:(WDSSmartCard*)card success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestVirtualSmartCardDeletionAsync(_getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCard>(card).Get(),
                                                       &unmarshalledReturn));

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

ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2> WDSISmartCardProvisioningStatics2_inst() {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardProvisioning").Get(),
                                                       &inst));
    return inst;
}

+ (void)requestAttestedVirtualSmartCardCreationAsync:(NSString*)friendlyName
                                   administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                           pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                             success:(void (^)(WDSSmartCardProvisioning*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAttestedVirtualSmartCardCreationAsync(
        nsStrToHstr(friendlyName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(administrativeKey).Get(),
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(pinPolicy).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardProvisioning>(result.Get()));
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

+ (void)requestAttestedVirtualSmartCardCreationAsyncWithCardId:(NSString*)friendlyName
                                             administrativeKey:(RTObject<WSSIBuffer>*)administrativeKey
                                                     pinPolicy:(WDSSmartCardPinPolicy*)pinPolicy
                                                        cardId:(WFGUID*)cardId
                                                       success:(void (^)(WDSSmartCardProvisioning*))success
                                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>> unmarshalledReturn;
    auto _comInst = WDSISmartCardProvisioningStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAttestedVirtualSmartCardCreationAsyncWithCardId(
        nsStrToHstr(friendlyName).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(administrativeKey).Get(),
        _getRtInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(pinPolicy).Get(),
        cardId.guidValue,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardProvisioning*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardProvisioning>(result.Get()));
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

- (WDSSmartCard*)smartCard {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCard> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmartCard(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCard>(unmarshalledReturn.Get());
}

- (void)getIdAsyncWithSuccess:(void (^)(WFGUID*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<GUID>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->GetIdAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<GUID>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<GUID>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        GUID result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_makeObjcFrom<GUID>(result));
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

- (void)getNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->GetNameAsync(&unmarshalledReturn));

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

- (void)getChallengeContextAsyncWithSuccess:(void (^)(WDSSmartCardChallengeContext*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardChallengeContext*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->GetChallengeContextAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::SmartCards::SmartCardChallengeContext*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::SmartCards::SmartCardChallengeContext*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSSmartCardChallengeContext>(result.Get()));
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

- (void)requestPinChangeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPinChangeAsync(&unmarshalledReturn));

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

- (void)requestPinResetAsync:(WDSSmartCardPinResetHandler)handler success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning>(self);
    THROW_NS_IF_FAILED(_comInst->RequestPinResetAsync(Make<WDSSmartCardPinResetHandler_shim>(handler).Get(), &unmarshalledReturn));

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

- (void)getAuthorityKeyContainerNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardProvisioning2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAuthorityKeyContainerNameAsync(&unmarshalledReturn));

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

@end

@implementation WDSSmartCardPinPolicy

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Devices.SmartCards.SmartCardPinPolicy").Get(), &out));
    return [_createRtProxy<WDSSmartCardPinPolicy>(out.Get()) retain];
}

- (unsigned int)minLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinLength(value));
}

- (unsigned int)maxLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxLength(value));
}

- (WDSSmartCardPinCharacterPolicyOption)uppercaseLetters {
    ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_UppercaseLetters(&unmarshalledReturn));
    return (WDSSmartCardPinCharacterPolicyOption)unmarshalledReturn;
}

- (void)setUppercaseLetters:(WDSSmartCardPinCharacterPolicyOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_UppercaseLetters((ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption)value));
}

- (WDSSmartCardPinCharacterPolicyOption)lowercaseLetters {
    ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_LowercaseLetters(&unmarshalledReturn));
    return (WDSSmartCardPinCharacterPolicyOption)unmarshalledReturn;
}

- (void)setLowercaseLetters:(WDSSmartCardPinCharacterPolicyOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_LowercaseLetters((ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption)value));
}

- (WDSSmartCardPinCharacterPolicyOption)digits {
    ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_Digits(&unmarshalledReturn));
    return (WDSSmartCardPinCharacterPolicyOption)unmarshalledReturn;
}

- (void)setDigits:(WDSSmartCardPinCharacterPolicyOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_Digits((ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption)value));
}

- (WDSSmartCardPinCharacterPolicyOption)specialCharacters {
    ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpecialCharacters(&unmarshalledReturn));
    return (WDSSmartCardPinCharacterPolicyOption)unmarshalledReturn;
}

- (void)setSpecialCharacters:(WDSSmartCardPinCharacterPolicyOption)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinPolicy>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpecialCharacters((ABI::Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption)value));
}

@end

@implementation WDSSmartCardChallengeContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)challenge {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_Challenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)verifyResponseAsync:(RTObject<WSSIBuffer>*)response success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->VerifyResponseAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(response).Get(), &unmarshalledReturn));

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

- (RTObject<WFIAsyncAction>*)provisionAsync:(RTObject<WSSIBuffer>*)response formatCard:(BOOL)formatCard {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext>(self);
    THROW_NS_IF_FAILED(_comInst->ProvisionAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(response).Get(),
                                                (boolean)formatCard,
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)provisionAsyncWithNewCardId:(RTObject<WSSIBuffer>*)response
                                              formatCard:(BOOL)formatCard
                                               newCardId:(WFGUID*)newCardId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext>(self);
    THROW_NS_IF_FAILED(_comInst->ProvisionAsyncWithNewCardId(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(response).Get(),
                                                             (boolean)formatCard,
                                                             newCardId.guidValue,
                                                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)changeAdministrativeKeyAsync:(RTObject<WSSIBuffer>*)response
                                     newAdministrativeKey:(RTObject<WSSIBuffer>*)newAdministrativeKey {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardChallengeContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->ChangeAdministrativeKeyAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(response).Get(),
                                               _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(newAdministrativeKey).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSSmartCardPinResetRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)challenge {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Challenge(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDSSmartCardPinResetDeferral*)getDeferral {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardPinResetDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSmartCardPinResetDeferral>(unmarshalledReturn.Get());
}

- (void)setResponse:(RTObject<WSSIBuffer>*)response {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SetResponse(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(response).Get()));
}

@end

@implementation WDSSmartCardPinResetDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardPinResetDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardPinResetDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WDSSmartCardConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)transmitAsync:(RTObject<WSSIBuffer>*)command success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::SmartCards::ISmartCardConnection>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransmitAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(command).Get(), &unmarshalledReturn));

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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

id RTProxiedIterableNSArray_WDSSmartCardAutomaticResponseApdu_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu*>,
                                RTIterableObj<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu*,
                                              IIterable<ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu*>,
                                              WDSSmartCardAutomaticResponseApdu,
                                              ABI::Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WDSSmartCardCryptogramPlacementStep_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*>,
                                RTIterableObj<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep*,
                                              IIterable<ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*>,
                                              WDSSmartCardCryptogramPlacementStep,
                                              ABI::Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCard_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>,
                                         RTArrayObj<ABI::Windows::Devices::SmartCards::ISmartCard*,
                                                    IVectorView<ABI::Windows::Devices::SmartCards::SmartCard*>,
                                                    WDSSmartCard,
                                                    ABI::Windows::Devices::SmartCards::SmartCard*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardAppletIdGroupRegistration_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>,
                                         RTArrayObj<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration*,
                                                    IVectorView<ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*>,
                                                    WDSSmartCardAppletIdGroupRegistration,
                                                    ABI::Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardCryptogramAlgorithm_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm>,
                                         RTArrayObj<ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm,
                                                    IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm>,
                                                    WDSSmartCardCryptogramAlgorithm,
                                                    ABI::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>,
        RTArrayObj<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat,
                   IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>,
                   WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat,
                   ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat,
                   dummyObjCCreator,
                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>,
                        RTArrayObj<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat,
                                   IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>,
                                   WDSSmartCardCryptogramMaterialPackageFormat,
                                   ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardCryptogramMaterialType_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType>,
                                         RTArrayObj<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType,
                                                    IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType>,
                                                    WDSSmartCardCryptogramMaterialType,
                                                    ABI::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSSmartCardCryptogramStorageKeyCapabilities_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>,
                        RTArrayObj<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities,
                                   IVectorView<ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>,
                                   WDSSmartCardCryptogramStorageKeyCapabilities,
                                   ABI::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WSSIBuffer_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Storage::Streams::IBuffer*>,
                                                RTMutableArrayObj<ABI::Windows::Storage::Streams::IBuffer*,
                                                                  IVector<ABI::Windows::Storage::Streams::IBuffer*>,
                                                                  RTObject<WSSIBuffer>,
                                                                  ABI::Windows::Storage::Streams::IBuffer*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
