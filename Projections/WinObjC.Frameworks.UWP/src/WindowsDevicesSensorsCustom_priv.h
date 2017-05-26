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

// WindowsDevicesSensorsCustom_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Sensors::Custom::ICustomSensorStatics> WDSCICustomSensorStatics_inst();

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSDictionary_NSString_RTObject;

#ifndef __ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Sensors::Custom::CustomSensor*,
                                                       ABI::Windows::Devices::Sensors::Custom::CustomSensorReadingChangedEventArgs*>> {
    void (^_delegate)(WDSCCustomSensor*, WDSCCustomSensorReadingChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs(
        void (^del)(WDSCCustomSensor*, WDSCCustomSensorReadingChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Sensors_Custom_CustomSensor_Windows_Devices_Sensors_Custom_CustomSensorReadingChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Sensors::Custom::ICustomSensor* arg0,
                                             ABI::Windows::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSCCustomSensor>(arg0), _createRtProxy<WDSCCustomSensorReadingChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
