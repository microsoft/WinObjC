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

// WindowsDevicesSensors.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Sensors.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesSensors.h"
#include "WindowsDevicesSensors_priv.h"

@implementation WDSISensorDataThreshold

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThreshold> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WDSSensorDataThresholdTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDSSensorType)sensorType {
    ABI::Windows::Devices::Sensors::SensorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_SensorType(&unmarshalledReturn));
    return (WDSSensorType)unmarshalledReturn;
}

@end

@implementation WDSAccelerometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics> WDSIAccelerometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Accelerometer").Get(), &inst));
    return inst;
}

+ (WDSAccelerometer*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometer> unmarshalledReturn;
    auto _comInst = WDSIAccelerometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAccelerometer>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics2> WDSIAccelerometerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Accelerometer").Get(), &inst));
    return inst;
}

+ (WDSAccelerometer*)getDefaultWithAccelerometerReadingType:(WDSAccelerometerReadingType)readingType {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometer> unmarshalledReturn;
    auto _comInst = WDSIAccelerometerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetDefaultWithAccelerometerReadingType((ABI::Windows::Devices::Sensors::AccelerometerReadingType)readingType,
                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAccelerometer>(unmarshalledReturn.Get());
}

- (WDSAccelerometerReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAccelerometerReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSAccelerometer*, WDSAccelerometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (EventRegistrationToken)addShakenEvent:(void (^)(WDSAccelerometer*, WDSAccelerometerShakenEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Shaken(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShakenEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Shaken(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

- (void)setReportLatency:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportLatency(value));
}

- (unsigned int)reportLatency {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportLatency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxBatchSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxBatchSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSAccelerometerReadingType)readingType {
    ABI::Windows::Devices::Sensors::AccelerometerReadingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometer4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingType(&unmarshalledReturn));
    return (WDSAccelerometerReadingType)unmarshalledReturn;
}

@end

@implementation WDSAccelerometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (double)accelerationX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccelerationX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)accelerationY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccelerationY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)accelerationZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccelerationZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSAccelerometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSAccelerometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAccelerometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSAccelerometerShakenEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerShakenEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAccelerometerShakenEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WDSInclinometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics> WDSIInclinometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Inclinometer").Get(), &inst));
    return inst;
}

+ (WDSInclinometer*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometer> unmarshalledReturn;
    auto _comInst = WDSIInclinometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSInclinometer>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics2> WDSIInclinometerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Inclinometer").Get(), &inst));
    return inst;
}

+ (WDSInclinometer*)getDefaultForRelativeReadings {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometer> unmarshalledReturn;
    auto _comInst = WDSIInclinometerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultForRelativeReadings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSInclinometer>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics3> WDSIInclinometerStatics3_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Inclinometer").Get(), &inst));
    return inst;
}

+ (WDSInclinometer*)getDefaultWithSensorReadingType:(WDSSensorReadingType)sensorReadingtype {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometer> unmarshalledReturn;
    auto _comInst = WDSIInclinometerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultWithSensorReadingType((ABI::Windows::Devices::Sensors::SensorReadingType)sensorReadingtype,
                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSInclinometer>(unmarshalledReturn.Get());
}

- (WDSInclinometerReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSInclinometerReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSInclinometer*, WDSInclinometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

- (WDSSensorReadingType)readingType {
    ABI::Windows::Devices::Sensors::SensorReadingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingType(&unmarshalledReturn));
    return (WDSSensorReadingType)unmarshalledReturn;
}

@end

@implementation WDSInclinometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (float)pitchDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_PitchDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)rollDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_RollDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)yawDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_YawDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSMagnetometerAccuracy)yawAccuracy {
    ABI::Windows::Devices::Sensors::MagnetometerAccuracy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReadingYawAccuracy>(self);
    THROW_NS_IF_FAILED(_comInst->get_YawAccuracy(&unmarshalledReturn));
    return (WDSMagnetometerAccuracy)unmarshalledReturn;
}

@end

@implementation WDSInclinometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSInclinometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IInclinometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSInclinometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSGyrometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IGyrometerStatics> WDSIGyrometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Gyrometer").Get(), &inst));
    return inst;
}

+ (WDSGyrometer*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometer> unmarshalledReturn;
    auto _comInst = WDSIGyrometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSGyrometer>(unmarshalledReturn.Get());
}

- (WDSGyrometerReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSGyrometerReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSGyrometer*, WDSGyrometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

@end

@implementation WDSGyrometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (double)angularVelocityX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AngularVelocityX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)angularVelocityY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AngularVelocityY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)angularVelocityZ {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AngularVelocityZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSGyrometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSGyrometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IGyrometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSGyrometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSCompass

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ICompass> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::ICompassStatics> WDSICompassStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::ICompassStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Compass").Get(), &inst));
    return inst;
}

+ (WDSCompass*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::ICompass> unmarshalledReturn;
    auto _comInst = WDSICompassStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSCompass>(unmarshalledReturn.Get());
}

- (WDSCompassReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::ICompassReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSCompassReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSCompass*, WDSCompassReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompass2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

@end

@implementation WDSCompassReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ICompassReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (double)headingMagneticNorth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeadingMagneticNorth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (id /* double */)headingTrueNorth {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeadingTrueNorth(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (WDSMagnetometerAccuracy)headingAccuracy {
    ABI::Windows::Devices::Sensors::MagnetometerAccuracy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassReadingHeadingAccuracy>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeadingAccuracy(&unmarshalledReturn));
    return (WDSMagnetometerAccuracy)unmarshalledReturn;
}

@end

@implementation WDSCompassReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ICompassReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSCompassReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::ICompassReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ICompassReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSCompassReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSLightSensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::ILightSensorStatics> WDSILightSensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.LightSensor").Get(), &inst));
    return inst;
}

+ (WDSLightSensor*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensor> unmarshalledReturn;
    auto _comInst = WDSILightSensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSLightSensor>(unmarshalledReturn.Get());
}

- (WDSLightSensorReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSLightSensorReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSLightSensor*, WDSLightSensorReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensorDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDSLightSensorReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensorReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (float)illuminanceInLux {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_IlluminanceInLux(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSLightSensorReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSLightSensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::ILightSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSLightSensorReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSSensorRotationMatrix

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorRotationMatrix> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)m11 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M11(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m12 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M12(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m13 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M13(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m21 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M21(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m22 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M22(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m23 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M23(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m31 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M31(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m32 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)m33 {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorRotationMatrix>(self);
    THROW_NS_IF_FAILED(_comInst->get_M33(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSSensorQuaternion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorQuaternion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)w {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorQuaternion>(self);
    THROW_NS_IF_FAILED(_comInst->get_W(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)x {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorQuaternion>(self);
    THROW_NS_IF_FAILED(_comInst->get_X(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)y {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorQuaternion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Y(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)z {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISensorQuaternion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Z(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSOrientationSensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics> WDSIOrientationSensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.OrientationSensor").Get(), &inst));
    return inst;
}

+ (WDSOrientationSensor*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensor> unmarshalledReturn;
    auto _comInst = WDSIOrientationSensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensor>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics3> WDSIOrientationSensorStatics3_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.OrientationSensor").Get(), &inst));
    return inst;
}

+ (WDSOrientationSensor*)getDefaultWithSensorReadingType:(WDSSensorReadingType)sensorReadingtype {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensor> unmarshalledReturn;
    auto _comInst = WDSIOrientationSensorStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultWithSensorReadingType((ABI::Windows::Devices::Sensors::SensorReadingType)sensorReadingtype,
                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensor>(unmarshalledReturn.Get());
}

+ (WDSOrientationSensor*)getDefaultWithSensorReadingTypeAndSensorOptimizationGoal:(WDSSensorReadingType)sensorReadingType
                                                                 optimizationGoal:(WDSSensorOptimizationGoal)optimizationGoal {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensor> unmarshalledReturn;
    auto _comInst = WDSIOrientationSensorStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultWithSensorReadingTypeAndSensorOptimizationGoal(
        (ABI::Windows::Devices::Sensors::SensorReadingType)sensorReadingType,
        (ABI::Windows::Devices::Sensors::SensorOptimizationGoal)optimizationGoal,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensor>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics2> WDSIOrientationSensorStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.OrientationSensor").Get(), &inst));
    return inst;
}

+ (WDSOrientationSensor*)getDefaultForRelativeReadings {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensor> unmarshalledReturn;
    auto _comInst = WDSIOrientationSensorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultForRelativeReadings(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensor>(unmarshalledReturn.Get());
}

- (WDSOrientationSensorReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensorReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSOrientationSensor*, WDSOrientationSensorReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

- (WDSSensorReadingType)readingType {
    ABI::Windows::Devices::Sensors::SensorReadingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingType(&unmarshalledReturn));
    return (WDSSensorReadingType)unmarshalledReturn;
}

@end

@implementation WDSOrientationSensorReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDSSensorRotationMatrix*)rotationMatrix {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorRotationMatrix> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationMatrix(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSensorRotationMatrix>(unmarshalledReturn.Get());
}

- (WDSSensorQuaternion*)quaternion {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorQuaternion> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Quaternion(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSensorQuaternion>(unmarshalledReturn.Get());
}

- (WDSMagnetometerAccuracy)yawAccuracy {
    ABI::Windows::Devices::Sensors::MagnetometerAccuracy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorReadingYawAccuracy>(self);
    THROW_NS_IF_FAILED(_comInst->get_YawAccuracy(&unmarshalledReturn));
    return (WDSMagnetometerAccuracy)unmarshalledReturn;
}

@end

@implementation WDSOrientationSensorReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSOrientationSensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSOrientationSensorReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSSimpleOrientationSensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorStatics> WDSISimpleOrientationSensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.SimpleOrientationSensor").Get(),
                                                       &inst));
    return inst;
}

+ (WDSSimpleOrientationSensor*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor> unmarshalledReturn;
    auto _comInst = WDSISimpleOrientationSensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSSimpleOrientationSensor>(unmarshalledReturn.Get());
}

- (WDSSimpleOrientation)getCurrentOrientation {
    ABI::Windows::Devices::Sensors::SimpleOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentOrientation(&unmarshalledReturn));
    return (WDSSimpleOrientation)unmarshalledReturn;
}

- (EventRegistrationToken)addOrientationChangedEvent:(void (^)(WDSSimpleOrientationSensor*,
                                                               WDSSimpleOrientationSensorOrientationChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_OrientationChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOrientationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OrientationChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

@end

@implementation WDSSimpleOrientationSensorOrientationChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDSSimpleOrientation)orientation {
    ABI::Windows::Devices::Sensors::SimpleOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WDSSimpleOrientation)unmarshalledReturn;
}

@end

@implementation WDSMagnetometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerStatics> WDSIMagnetometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Magnetometer").Get(), &inst));
    return inst;
}

+ (WDSMagnetometer*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometer> unmarshalledReturn;
    auto _comInst = WDSIMagnetometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSMagnetometer>(unmarshalledReturn.Get());
}

- (WDSMagnetometerReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSMagnetometerReading>(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSMagnetometer*, WDSMagnetometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerDeviceId>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReadingTransform:(WGDDisplayOrientations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadingTransform((ABI::Windows::Graphics::Display::DisplayOrientations)value));
}

- (WGDDisplayOrientations)readingTransform {
    ABI::Windows::Graphics::Display::DisplayOrientations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingTransform(&unmarshalledReturn));
    return (WGDDisplayOrientations)unmarshalledReturn;
}

@end

@implementation WDSMagnetometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (float)magneticFieldX {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_MagneticFieldX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)magneticFieldY {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_MagneticFieldY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)magneticFieldZ {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_MagneticFieldZ(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDSMagnetometerAccuracy)directionalAccuracy {
    ABI::Windows::Devices::Sensors::MagnetometerAccuracy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_DirectionalAccuracy(&unmarshalledReturn));
    return (WDSMagnetometerAccuracy)unmarshalledReturn;
}

@end

@implementation WDSMagnetometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSMagnetometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSMagnetometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSActivitySensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorStatics> WDSIActivitySensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.ActivitySensor").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensor*>> unmarshalledReturn;
    auto _comInst = WDSIActivitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::ActivitySensor*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensor*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Sensors::IActivitySensor> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSActivitySensor>(result.Get()));
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
    auto _comInst = WDSIActivitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSActivitySensor*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensor*>> unmarshalledReturn;
    auto _comInst = WDSIActivitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::ActivitySensor*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensor*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Sensors::IActivitySensor> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDSActivitySensor>(result.Get()));
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

+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime
                      success:(void (^)(NSArray* /* WDSActivitySensorReading* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>>
        unmarshalledReturn;
    auto _comInst = WDSIActivitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSystemHistoryAsync(*[fromTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSActivitySensorReading_create(result.Get()));
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

+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime
                                 duration:(WFTimeSpan*)duration
                                  success:(void (^)(NSArray* /* WDSActivitySensorReading* */))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>>
        unmarshalledReturn;
    auto _comInst = WDSIActivitySensorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetSystemHistoryWithDurationAsync(*[fromTime internalStruct], *[duration internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSActivitySensorReading_create(result.Get()));
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

- (void)getCurrentReadingAsyncWithSuccess:(void (^)(WDSActivitySensorReading*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensorReading*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReadingAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::ActivitySensorReading*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::ActivitySensorReading*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReading> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSActivitySensorReading>(result.Get()));
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

- (NSMutableArray* /* WDSActivityType */)subscribedActivities {
    ComPtr<IVector<ABI::Windows::Devices::Sensors::ActivityType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubscribedActivities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDSActivityType_create(unmarshalledReturn.Get());
}

- (double)powerInMilliwatts {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerInMilliwatts(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WDSActivityType */)supportedActivities {
    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ActivityType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedActivities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSActivityType_create(unmarshalledReturn.Get());
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSActivitySensor*, WDSActivitySensorReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

@end

@implementation WDSActivitySensorReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WDSActivityType)activity {
    ABI::Windows::Devices::Sensors::ActivityType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Activity(&unmarshalledReturn));
    return (WDSActivityType)unmarshalledReturn;
}

- (WDSActivitySensorReadingConfidence)confidence {
    ABI::Windows::Devices::Sensors::ActivitySensorReadingConfidence unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Confidence(&unmarshalledReturn));
    return (WDSActivitySensorReadingConfidence)unmarshalledReturn;
}

@end

@implementation WDSActivitySensorReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSActivitySensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSActivitySensorReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSActivitySensorReadingChangeReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReadingChangeReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSActivitySensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorReadingChangeReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSActivitySensorReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSActivitySensorTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WDSActivitySensorReadingChangeReport* */)readReports {
    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReadingChangeReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IActivitySensorTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->ReadReports(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSActivitySensorReadingChangeReport_create(unmarshalledReturn.Get());
}

@end

@implementation WDSBarometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IBarometerStatics> WDSIBarometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Barometer").Get(), &inst));
    return inst;
}

+ (WDSBarometer*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometer> unmarshalledReturn;
    auto _comInst = WDSIBarometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSBarometer>(unmarshalledReturn.Get());
}

- (WDSBarometerReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSBarometerReading>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSBarometer*, WDSBarometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

@end

@implementation WDSBarometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (double)stationPressureInHectopascals {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_StationPressureInHectopascals(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSBarometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSBarometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IBarometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IBarometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSBarometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSPedometerReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSPedometerStepKind)stepKind {
    ABI::Windows::Devices::Sensors::PedometerStepKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_StepKind(&unmarshalledReturn));
    return (WDSPedometerStepKind)unmarshalledReturn;
}

- (int)cumulativeSteps {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_CumulativeSteps(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)cumulativeStepsDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometerReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_CumulativeStepsDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WDSPedometer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics> WDSIPedometerStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Pedometer").Get(), &inst));
    return inst;
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Pedometer*>> unmarshalledReturn;
    auto _comInst = WDSIPedometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::Pedometer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Pedometer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sensors::IPedometer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSPedometer>(result.Get()));
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

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDSPedometer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Pedometer*>> unmarshalledReturn;
    auto _comInst = WDSIPedometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Sensors::Pedometer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Sensors::Pedometer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::Sensors::IPedometer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDSPedometer>(result.Get()));
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
    auto _comInst = WDSIPedometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)getSystemHistoryAsync:(WFDateTime*)fromTime
                      success:(void (^)(NSArray* /* WDSPedometerReading* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>> unmarshalledReturn;
    auto _comInst = WDSIPedometerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSystemHistoryAsync(*[fromTime internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSPedometerReading_create(result.Get()));
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

+ (void)getSystemHistoryWithDurationAsync:(WFDateTime*)fromTime
                                 duration:(WFTimeSpan*)duration
                                  success:(void (^)(NSArray* /* WDSPedometerReading* */))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>> unmarshalledReturn;
    auto _comInst = WDSIPedometerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetSystemHistoryWithDurationAsync(*[fromTime internalStruct], *[duration internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDSPedometerReading_create(result.Get()));
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

ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics2> WDSIPedometerStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Pedometer").Get(), &inst));
    return inst;
}

+ (NSArray* /* WDSPedometerReading* */)getReadingsFromTriggerDetails:(WDSSensorDataThresholdTriggerDetails*)triggerDetails {
    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>> unmarshalledReturn;
    auto _comInst = WDSIPedometerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetReadingsFromTriggerDetails(
        _getRtInterface<ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>(triggerDetails).Get(),
        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSPedometerReading_create(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)powerInMilliwatts {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerInMilliwatts(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSPedometer*, WDSPedometerReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (NSDictionary* /* WDSPedometerStepKind, WDSPedometerReading* */)getCurrentReadings {
    ComPtr<IMapView<ABI::Windows::Devices::Sensors::PedometerStepKind, ABI::Windows::Devices::Sensors::PedometerReading*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometer2>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReadings(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WDSPedometerStepKind_WDSPedometerReading_create(unmarshalledReturn.Get());
}

@end

@implementation WDSPedometerReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSPedometerReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IPedometerReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSPedometerReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSPedometerDataThreshold

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThreshold> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Sensors::IPedometerDataThresholdFactory> WDSIPedometerDataThresholdFactory_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IPedometerDataThresholdFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.PedometerDataThreshold").Get(),
                                                       &inst));
    return inst;
}

+ (WDSPedometerDataThreshold*)make:(WDSPedometer*)sensor stepGoal:(int)stepGoal {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThreshold> unmarshalledReturn;
    auto _comInst = WDSIPedometerDataThresholdFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::Sensors::IPedometer>(sensor).Get(),
                                        stepGoal,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSPedometerDataThreshold>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WDSProximitySensor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics> WDSIProximitySensorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.ProximitySensor").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDSIProximitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (WDSProximitySensor*)fromId:(NSString*)sensorId {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensor> unmarshalledReturn;
    auto _comInst = WDSIProximitySensorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(sensorId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSProximitySensor>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics2> WDSIProximitySensorStatics2_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.ProximitySensor").Get(), &inst));
    return inst;
}

+ (NSArray* /* WDSProximitySensorReading* */)getReadingsFromTriggerDetails:(WDSSensorDataThresholdTriggerDetails*)triggerDetails {
    ComPtr<IVectorView<ABI::Windows::Devices::Sensors::ProximitySensorReading*>> unmarshalledReturn;
    auto _comInst = WDSIProximitySensorStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetReadingsFromTriggerDetails(
        _getRtInterface<ABI::Windows::Devices::Sensors::ISensorDataThresholdTriggerDetails>(triggerDetails).Get(),
        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDSProximitySensorReading_create(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* unsigned int */)maxDistanceInMillimeters {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDistanceInMillimeters(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (id /* unsigned int */)minDistanceInMillimeters {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinDistanceInMillimeters(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (WDSProximitySensorReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSProximitySensorReading>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSProximitySensor*, WDSProximitySensorReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

- (WDSProximitySensorDisplayOnOffController*)createDisplayOnOffController {
    ComPtr<ABI::Windows::Foundation::IClosable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDisplayOnOffController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSProximitySensorDisplayOnOffController>(unmarshalledReturn.Get());
}

@end

@implementation WDSProximitySensorReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (BOOL)isDetected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDetected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (id /* unsigned int */)distanceInMillimeters {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensorReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistanceInMillimeters(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

@end

@implementation WDSProximitySensorReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSProximitySensorReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSProximitySensorReading>(unmarshalledReturn.Get());
}

@end

@implementation WDSProximitySensorDisplayOnOffController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IClosable> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDSProximitySensorDataThreshold

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThreshold> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorDataThresholdFactory> WDSIProximitySensorDataThresholdFactory_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorDataThresholdFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Sensors.ProximitySensorDataThreshold").Get(), &inst));
    return inst;
}

+ (WDSProximitySensorDataThreshold*)make:(WDSProximitySensor*)sensor {
    ComPtr<ABI::Windows::Devices::Sensors::ISensorDataThreshold> unmarshalledReturn;
    auto _comInst = WDSIProximitySensorDataThresholdFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::Sensors::IProximitySensor>(sensor).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDSProximitySensorDataThreshold>(unmarshalledReturn.Get()) retain];
}

@end

@implementation WDSAltimeter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Sensors::IAltimeterStatics> WDSIAltimeterStatics_inst() {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Sensors.Altimeter").Get(), &inst));
    return inst;
}

+ (WDSAltimeter*)getDefault {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeter> unmarshalledReturn;
    auto _comInst = WDSIAltimeterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAltimeter>(unmarshalledReturn.Get());
}

- (WDSAltimeterReading*)getCurrentReading {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeterReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAltimeterReading>(unmarshalledReturn.Get());
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)minimumReportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimumReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReportInterval:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReportInterval(value));
}

- (unsigned int)reportInterval {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReportInterval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addReadingChangedEvent:(void (^)(WDSAltimeter*, WDSAltimeterReadingChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReadingChanged(
        Make<ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReadingChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReadingChanged(token));
}

@end

@implementation WDSAltimeterReading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeterReading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeterReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (double)altitudeChangeInMeters {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeterReading>(self);
    THROW_NS_IF_FAILED(_comInst->get_AltitudeChangeInMeters(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDSAltimeterReadingChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDSAltimeterReading*)reading {
    ComPtr<ABI::Windows::Devices::Sensors::IAltimeterReading> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reading(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSAltimeterReading>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WDSActivitySensorReading_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::IActivitySensorReading*,
                                                    IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReading*>,
                                                    WDSActivitySensorReading,
                                                    ABI::Windows::Devices::Sensors::ActivitySensorReading*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSActivitySensorReadingChangeReport_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReadingChangeReport*>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::IActivitySensorReadingChangeReport*,
                                                    IVectorView<ABI::Windows::Devices::Sensors::ActivitySensorReadingChangeReport*>,
                                                    WDSActivitySensorReadingChangeReport,
                                                    ABI::Windows::Devices::Sensors::ActivitySensorReadingChangeReport*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSActivityType_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::ActivityType>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::ActivityType,
                                                    IVectorView<ABI::Windows::Devices::Sensors::ActivityType>,
                                                    WDSActivityType,
                                                    ABI::Windows::Devices::Sensors::ActivityType,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSPedometerReading_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::IPedometerReading*,
                                                    IVectorView<ABI::Windows::Devices::Sensors::PedometerReading*>,
                                                    WDSPedometerReading,
                                                    ABI::Windows::Devices::Sensors::PedometerReading*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDSProximitySensorReading_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Sensors::ProximitySensorReading*>,
                                         RTArrayObj<ABI::Windows::Devices::Sensors::IProximitySensorReading*,
                                                    IVectorView<ABI::Windows::Devices::Sensors::ProximitySensorReading*>,
                                                    WDSProximitySensorReading,
                                                    ABI::Windows::Devices::Sensors::ProximitySensorReading*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_WDSPedometerStepKind_WDSPedometerReading_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<ABI::Windows::Devices::Sensors::PedometerStepKind, ABI::Windows::Devices::Sensors::PedometerReading*>,
        DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<ABI::Windows::Devices::Sensors::PedometerStepKind,
                                                                 ABI::Windows::Devices::Sensors::PedometerStepKind,
                                                                 WDSPedometerStepKind,
                                                                 ABI::Windows::Devices::Sensors::PedometerReading*>>,
        RTMapViewObj<ABI::Windows::Devices::Sensors::PedometerStepKind,
                     ABI::Windows::Devices::Sensors::PedometerStepKind,
                     ABI::Windows::Devices::Sensors::PedometerReading*,
                     ABI::Windows::Devices::Sensors::IPedometerReading*,
                     WDSPedometerStepKind,
                     WDSPedometerReading,
                     IMapView<ABI::Windows::Devices::Sensors::PedometerStepKind, ABI::Windows::Devices::Sensors::PedometerReading*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDSActivityType_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Sensors::ActivityType>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Sensors::ActivityType,
                                                                  IVector<ABI::Windows::Devices::Sensors::ActivityType>,
                                                                  WDSActivityType,
                                                                  ABI::Windows::Devices::Sensors::ActivityType,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
