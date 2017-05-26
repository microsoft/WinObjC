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

// WindowsDevicesSensors_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsDisplay_priv.h"
ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics> WDSIAccelerometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IAccelerometerStatics2> WDSIAccelerometerStatics2_inst();
ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics> WDSIInclinometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics2> WDSIInclinometerStatics2_inst();
ComPtr<ABI::Windows::Devices::Sensors::IInclinometerStatics3> WDSIInclinometerStatics3_inst();
ComPtr<ABI::Windows::Devices::Sensors::IGyrometerStatics> WDSIGyrometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::ICompassStatics> WDSICompassStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::ILightSensorStatics> WDSILightSensorStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics> WDSIOrientationSensorStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics3> WDSIOrientationSensorStatics3_inst();
ComPtr<ABI::Windows::Devices::Sensors::IOrientationSensorStatics2> WDSIOrientationSensorStatics2_inst();
ComPtr<ABI::Windows::Devices::Sensors::ISimpleOrientationSensorStatics> WDSISimpleOrientationSensorStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IMagnetometerStatics> WDSIMagnetometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IActivitySensorStatics> WDSIActivitySensorStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IBarometerStatics> WDSIBarometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics> WDSIPedometerStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IPedometerStatics2> WDSIPedometerStatics2_inst();
static ComPtr<ABI::Windows::Devices::Sensors::IPedometerDataThresholdFactory> WDSIPedometerDataThresholdFactory_inst();
ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics> WDSIProximitySensorStatics_inst();
ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorStatics2> WDSIProximitySensorStatics2_inst();
static ComPtr<ABI::Windows::Devices::Sensors::IProximitySensorDataThresholdFactory> WDSIProximitySensorDataThresholdFactory_inst();
ComPtr<ABI::Windows::Devices::Sensors::IAltimeterStatics> WDSIAltimeterStatics_inst();

id RTProxiedNSArray_WDSActivitySensorReading_create(IInspectable* val);
id RTProxiedNSArray_WDSActivitySensorReadingChangeReport_create(IInspectable* val);
id RTProxiedNSArray_WDSActivityType_create(IInspectable* val);
id RTProxiedNSArray_WDSPedometerReading_create(IInspectable* val);
id RTProxiedNSArray_WDSProximitySensorReading_create(IInspectable* val);
id RTProxiedNSDictionary_WDSPedometerStepKind_WDSPedometerReading_create(IInspectable* val);
id RTProxiedNSMutableArray_WDSActivityType_create(IInspectable* val);

@class Nullable_Double, Nullable_UInt32, RTProxiedNSArray_WDSActivitySensorReading, RTProxiedNSArray_WDSActivitySensorReadingChangeReport;
@class RTProxiedNSArray_WDSActivityType, RTProxiedNSArray_WDSPedometerReading, RTProxiedNSArray_WDSProximitySensorReading,
    RTProxiedNSDictionary_WDSPedometerStepKind_WDSPedometerReading;
@class RTProxiedNSMutableArray_WDSActivityType;

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Accelerometer*,
                                                       ABI::Windows::Devices::Sensors::AccelerometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSAccelerometer*, WDSAccelerometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs(
        void (^del)(WDSAccelerometer*, WDSAccelerometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IAccelerometer* arg0,
                                             ABI::Windows::Devices::Sensors::IAccelerometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSAccelerometer>(arg0), _createRtProxy<WDSAccelerometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Accelerometer*,
                                                                       ABI::Windows::Devices::Sensors::AccelerometerShakenEventArgs*>> {
    void (^_delegate)(WDSAccelerometer*, WDSAccelerometerShakenEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs(
        void (^del)(WDSAccelerometer*, WDSAccelerometerShakenEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Accelerometer_Windows_Devices_Sensors_AccelerometerShakenEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IAccelerometer* arg0,
                                             ABI::Windows::Devices::Sensors::IAccelerometerShakenEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSAccelerometer>(arg0), _createRtProxy<WDSAccelerometerShakenEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::ActivitySensor*,
                                                       ABI::Windows::Devices::Sensors::ActivitySensorReadingChangedEventArgs*>> {
    void (^_delegate)(WDSActivitySensor*, WDSActivitySensorReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs(
        void (^del)(WDSActivitySensor*, WDSActivitySensorReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_ActivitySensor_Windows_Devices_Sensors_ActivitySensorReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IActivitySensor* arg0,
                                             ABI::Windows::Devices::Sensors::IActivitySensorReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSActivitySensor>(arg0), _createRtProxy<WDSActivitySensorReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Altimeter*,
                                                                       ABI::Windows::Devices::Sensors::AltimeterReadingChangedEventArgs*>> {
    void (^_delegate)(WDSAltimeter*, WDSAltimeterReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs(
        void (^del)(WDSAltimeter*, WDSAltimeterReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Altimeter_Windows_Devices_Sensors_AltimeterReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IAltimeter* arg0,
                                             ABI::Windows::Devices::Sensors::IAltimeterReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSAltimeter>(arg0), _createRtProxy<WDSAltimeterReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Barometer*,
                                                                       ABI::Windows::Devices::Sensors::BarometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSBarometer*, WDSBarometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs(
        void (^del)(WDSBarometer*, WDSBarometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Barometer_Windows_Devices_Sensors_BarometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IBarometer* arg0,
                                             ABI::Windows::Devices::Sensors::IBarometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSBarometer>(arg0), _createRtProxy<WDSBarometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Compass*,
                                                                       ABI::Windows::Devices::Sensors::CompassReadingChangedEventArgs*>> {
    void (^_delegate)(WDSCompass*, WDSCompassReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs(
        void (^del)(WDSCompass*, WDSCompassReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Compass_Windows_Devices_Sensors_CompassReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::ICompass* arg0,
                                             ABI::Windows::Devices::Sensors::ICompassReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSCompass>(arg0), _createRtProxy<WDSCompassReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Gyrometer*,
                                                                       ABI::Windows::Devices::Sensors::GyrometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSGyrometer*, WDSGyrometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs(
        void (^del)(WDSGyrometer*, WDSGyrometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Gyrometer_Windows_Devices_Sensors_GyrometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IGyrometer* arg0,
                                             ABI::Windows::Devices::Sensors::IGyrometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSGyrometer>(arg0), _createRtProxy<WDSGyrometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Inclinometer*,
                                                       ABI::Windows::Devices::Sensors::InclinometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSInclinometer*, WDSInclinometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs(
        void (^del)(WDSInclinometer*, WDSInclinometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Inclinometer_Windows_Devices_Sensors_InclinometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IInclinometer* arg0,
                                             ABI::Windows::Devices::Sensors::IInclinometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSInclinometer>(arg0), _createRtProxy<WDSInclinometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::LightSensor*,
                                                       ABI::Windows::Devices::Sensors::LightSensorReadingChangedEventArgs*>> {
    void (^_delegate)(WDSLightSensor*, WDSLightSensorReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs(
        void (^del)(WDSLightSensor*, WDSLightSensorReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_LightSensor_Windows_Devices_Sensors_LightSensorReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::ILightSensor* arg0,
                                             ABI::Windows::Devices::Sensors::ILightSensorReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSLightSensor>(arg0), _createRtProxy<WDSLightSensorReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Magnetometer*,
                                                       ABI::Windows::Devices::Sensors::MagnetometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSMagnetometer*, WDSMagnetometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs(
        void (^del)(WDSMagnetometer*, WDSMagnetometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Magnetometer_Windows_Devices_Sensors_MagnetometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IMagnetometer* arg0,
                                             ABI::Windows::Devices::Sensors::IMagnetometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSMagnetometer>(arg0), _createRtProxy<WDSMagnetometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::OrientationSensor*,
                                                       ABI::Windows::Devices::Sensors::OrientationSensorReadingChangedEventArgs*>> {
    void (^_delegate)(WDSOrientationSensor*, WDSOrientationSensorReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs(
        void (^del)(WDSOrientationSensor*, WDSOrientationSensorReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_OrientationSensor_Windows_Devices_Sensors_OrientationSensorReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IOrientationSensor* arg0,
                                             ABI::Windows::Devices::Sensors::IOrientationSensorReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSOrientationSensor>(arg0), _createRtProxy<WDSOrientationSensorReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Pedometer*,
                                                                       ABI::Windows::Devices::Sensors::PedometerReadingChangedEventArgs*>> {
    void (^_delegate)(WDSPedometer*, WDSPedometerReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs(
        void (^del)(WDSPedometer*, WDSPedometerReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Pedometer_Windows_Devices_Sensors_PedometerReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IPedometer* arg0,
                                             ABI::Windows::Devices::Sensors::IPedometerReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSPedometer>(arg0), _createRtProxy<WDSPedometerReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::ProximitySensor*,
                                                       ABI::Windows::Devices::Sensors::ProximitySensorReadingChangedEventArgs*>> {
    void (^_delegate)(WDSProximitySensor*, WDSProximitySensorReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs(
        void (^del)(WDSProximitySensor*, WDSProximitySensorReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_ProximitySensor_Windows_Devices_Sensors_ProximitySensorReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::IProximitySensor* arg0,
                                             ABI::Windows::Devices::Sensors::IProximitySensorReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSProximitySensor>(arg0), _createRtProxy<WDSProximitySensorReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Sensors::SimpleOrientationSensor*,
                              ABI::Windows::Devices::Sensors::SimpleOrientationSensorOrientationChangedEventArgs*>> {
    void (^_delegate)(WDSSimpleOrientationSensor*, WDSSimpleOrientationSensorOrientationChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs(
        void (^del)(WDSSimpleOrientationSensor*, WDSSimpleOrientationSensorOrientationChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_SimpleOrientationSensor_Windows_Devices_Sensors_SimpleOrientationSensorOrientationChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Sensors::ISimpleOrientationSensor* arg0,
           ABI::Windows::Devices::Sensors::ISimpleOrientationSensorOrientationChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSimpleOrientationSensor>(arg0),
                      _createRtProxy<WDSSimpleOrientationSensorOrientationChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
