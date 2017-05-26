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

// WindowsDevicesGeolocationGeofencing_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceFactory> WDGGIGeofenceFactory_inst();
ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics> WDGGIGeofenceMonitorStatics_inst();

id RTProxiedNSArray_WDGGGeofenceStateChangeReport_create(IInspectable* val);
id RTProxiedNSMutableArray_WDGGGeofence_create(IInspectable* val);

@class RTProxiedNSArray_WDGGGeofenceStateChangeReport, RTProxiedNSMutableArray_WDGGGeofence;

#ifndef __ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Geolocation::Geofencing::GeofenceMonitor*, IInspectable*>> {
    void (^_delegate)(WDGGGeofenceMonitor*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object(void (^del)(WDGGGeofenceMonitor*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDGGGeofenceMonitor>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
