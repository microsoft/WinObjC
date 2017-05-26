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

// WindowsDevicesSensorsCustom.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Sensors.Custom.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSensorsCustom.h"
#include "WindowsDevicesSensorsCustom_priv.h"

@implementation WDSCCustomSensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorStatics> WDSCICustomSensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Custom.CustomSensor").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(WFGUID*)interfaceId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSCICustomSensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(interfaceId.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)sensorId success:(void (^)(WDSCCustomSensor*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Custom::CustomSensor*>> unmarshalledReturn;
    auto _comInst = WDSCICustomSensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(sensorId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::Custom::CustomSensor*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Custom::CustomSensor*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensor> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSCCustomSensor>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WDSCCustomSensorReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSCCustomSensorReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSCCustomSensor*, WDSCCustomSensorReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

@end

@implementation WDSCCustomSensorReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WDSCCustomSensorReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSCCustomSensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSCCustomSensorReading>(unmarshalledReturn.Get());
}

@end

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
