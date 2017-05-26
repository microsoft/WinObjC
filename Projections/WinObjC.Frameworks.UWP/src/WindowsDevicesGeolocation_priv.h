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

// WindowsDevicesGeolocation_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::Geolocation::IGeopointFactory> WDGIGeopointFactory_inst();
static ComPtr<ABI::Windows::Devices::Geolocation::IGeopathFactory> WDGIGeopathFactory_inst();
static ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxFactory> WDGIGeoboundingBoxFactory_inst();
ComPtr<ABI::Windows::Devices::Geolocation::IGeoboundingBoxStatics> WDGIGeoboundingBoxStatics_inst();
ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics2> WDGIGeolocatorStatics2_inst();
ComPtr<ABI::Windows::Devices::Geolocation::IGeolocatorStatics> WDGIGeolocatorStatics_inst();
static ComPtr<ABI::Windows::Devices::Geolocation::IGeocircleFactory> WDGIGeocircleFactory_inst();
@interface WDGBasicGeoposition (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::Geolocation::BasicGeoposition)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::Geolocation::BasicGeoposition*)internalStruct;
@end
inline WDGBasicGeoposition* WDGBasicGeoposition_create(ABI::Windows::Devices::Geolocation::BasicGeoposition val) {
    return [WDGBasicGeoposition createWith:val];
}

id RTProxiedIterableNSArray_WDGBasicGeoposition_create(IInspectable* val);
id RTProxiedNSArray_WDGBasicGeoposition_create(IInspectable* val);
id RTProxiedNSArray_WDGGeoposition_create(IInspectable* val);

@class Nullable_Double, Nullable_UInt32, Nullable_WDGBasicGeoposition, Nullable_WFDateTime, RTProxiedIterableNSArray_WDGBasicGeoposition;
@class RTProxiedNSArray_WDGBasicGeoposition, RTProxiedNSArray_WDGGeoposition;

#ifndef __ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Geolocation::Geolocator*,
                                                                       ABI::Windows::Devices::Geolocation::PositionChangedEventArgs*>> {
    void (^_delegate)(WDGGeolocator*, WDGPositionChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs(
        void (^del)(WDGGeolocator*, WDGPositionChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_PositionChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Geolocation::IGeolocator* arg0,
                                             ABI::Windows::Devices::Geolocation::IPositionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDGGeolocator>(arg0), _createRtProxy<WDGPositionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Geolocation::Geolocator*,
                                                                       ABI::Windows::Devices::Geolocation::StatusChangedEventArgs*>> {
    void (^_delegate)(WDGGeolocator*, WDGStatusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs(
        void (^del)(WDGGeolocator*, WDGStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Geolocation_Geolocator_Windows_Devices_Geolocation_StatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Geolocation::IGeolocator* arg0,
                                             ABI::Windows::Devices::Geolocation::IStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDGGeolocator>(arg0), _createRtProxy<WDGStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
