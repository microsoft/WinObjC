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

// WindowsDevicesPower.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Power.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPower.h"
#include "WindowsDevicesPower_priv.h"

@implementation WDPBatteryReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Power::IBatteryReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* int */)chargeRateInMilliwatts {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBatteryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChargeRateInMilliwatts(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (id /* int */)designCapacityInMilliwattHours {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBatteryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesignCapacityInMilliwattHours(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (id /* int */)fullChargeCapacityInMilliwattHours {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBatteryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullChargeCapacityInMilliwattHours(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (id /* int */)remainingCapacityInMilliwattHours {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBatteryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemainingCapacityInMilliwattHours(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (WSPBatteryStatus)status {
    ABI::Windows::System::Power::BatteryStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBatteryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSPBatteryStatus)unmarshalledReturn;
}

@end

@implementation WDPBattery

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Power::IBattery> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Power::IBatteryStatics> WDPIBatteryStatics_inst() {
    ComPtr<ABI::Windows::Devices::Power::IBatteryStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Power.Battery").Get(), &inst));
    return inst;
}

+ (WDPBattery*)aggregateBattery {
    ComPtr<ABI::Windows::Devices::Power::IBattery> unmarshalledReturn;
    auto _comInst = WDPIBatteryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AggregateBattery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPBattery>(unmarshalledReturn.Get());
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPBattery*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Power::Battery*>> unmarshalledReturn;
    auto _comInst = WDPIBatteryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Power::Battery*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Power::Battery*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Power::IBattery> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPBattery>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIBatteryStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPBatteryReport*)getReport {
    ComPtr<ABI::Windows::Devices::Power::IBatteryReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->GetReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPBatteryReport>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addReportUpdatedEvent:(void (^)(WDPBattery*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReportUpdated(Make<ITypedEventHandler_Windows_Devices_Power_Battery_System_Object>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReportUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Power::IBattery>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReportUpdated(token));
}

@end
