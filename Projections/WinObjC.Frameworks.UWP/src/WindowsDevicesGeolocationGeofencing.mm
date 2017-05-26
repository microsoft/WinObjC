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

// WindowsDevicesGeolocationGeofencing.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Geolocation.Geofencing.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesGeolocationGeofencing.h"
#include "WindowsDevicesGeolocationGeofencing_priv.h"

@implementation WDGGGeofence

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceFactory> WDGGIGeofenceFactory_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Geolocation.Geofencing.Geofence").Get(),
                                                       &inst));
    return inst;
}

+ (WDGGGeofence*)make:(NSString*)id geoshape:(RTObject<WDGIGeoshape>*)geoshape {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> unmarshalledReturn;
    auto _comInst = WDGGIGeofenceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(id).Get(),
                                        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(geoshape).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGGeofence>(unmarshalledReturn.Get()) retain];
}

+ (WDGGGeofence*)makeWithMonitorStates:(NSString*)id
                              geoshape:(RTObject<WDGIGeoshape>*)geoshape
                       monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                             singleUse:(BOOL)singleUse {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> unmarshalledReturn;
    auto _comInst = WDGGIGeofenceFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithMonitorStates(nsStrToHstr(id).Get(),
                                          _getRtInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(geoshape).Get(),
                                          (ABI::Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates)monitoredStates,
                                          (boolean)singleUse,
                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGGeofence>(unmarshalledReturn.Get()) retain];
}

+ (WDGGGeofence*)makeWithMonitorStatesAndDwellTime:(NSString*)id
                                          geoshape:(RTObject<WDGIGeoshape>*)geoshape
                                   monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                                         singleUse:(BOOL)singleUse
                                         dwellTime:(WFTimeSpan*)dwellTime {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> unmarshalledReturn;
    auto _comInst = WDGGIGeofenceFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithMonitorStatesAndDwellTime(nsStrToHstr(id).Get(),
                                                      _getRtInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(geoshape).Get(),
                                                      (ABI::Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates)
                                                          monitoredStates,
                                                      (boolean)singleUse,
                                                      *[dwellTime internalStruct],
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGGeofence>(unmarshalledReturn.Get()) retain];
}

+ (WDGGGeofence*)makeWithMonitorStatesDwellTimeStartTimeAndDuration:(NSString*)id
                                                           geoshape:(RTObject<WDGIGeoshape>*)geoshape
                                                    monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                                                          singleUse:(BOOL)singleUse
                                                          dwellTime:(WFTimeSpan*)dwellTime
                                                          startTime:(WFDateTime*)startTime
                                                           duration:(WFTimeSpan*)duration {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> unmarshalledReturn;
    auto _comInst = WDGGIGeofenceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithMonitorStatesDwellTimeStartTimeAndDuration(
        nsStrToHstr(id).Get(),
        _getRtInterface<ABI::Windows::Devices::Geolocation::IGeoshape>(geoshape).Get(),
        (ABI::Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates)monitoredStates,
        (boolean)singleUse,
        *[dwellTime internalStruct],
        *[startTime internalStruct],
        *[duration internalStruct],
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGGGeofence>(unmarshalledReturn.Get()) retain];
}

- (WFDateTime*)startTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)dwellTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_DwellTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDGGMonitoredGeofenceStates)monitoredStates {
    ABI::Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_MonitoredStates(&unmarshalledReturn));
    return (WDGGMonitoredGeofenceStates)unmarshalledReturn;
}

- (RTObject<WDGIGeoshape>*)geoshape {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoshape> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Geoshape(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGIGeoshape>(unmarshalledReturn.Get());
}

- (BOOL)singleUse {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence>(self);
    THROW_NS_IF_FAILED(_comInst->get_SingleUse(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDGGGeofenceMonitor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics> WDGGIGeofenceMonitorStatics_inst() {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Geolocation.Geofencing.GeofenceMonitor").Get(), &inst));
    return inst;
}

+ (WDGGGeofenceMonitor*)current {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor> unmarshalledReturn;
    auto _comInst = WDGGIGeofenceMonitorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGGeofenceMonitor>(unmarshalledReturn.Get());
}

- (WDGGGeofenceMonitorStatus)status {
    ABI::Windows::Devices::Geolocation::Geofencing::GeofenceMonitorStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDGGGeofenceMonitorStatus)unmarshalledReturn;
}

- (NSMutableArray* /* WDGGGeofence* */)geofences {
    ComPtr<IVector<ABI::Windows::Devices::Geolocation::Geofencing::Geofence*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Geofences(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WDGGGeofence_create(unmarshalledReturn.Get());
}

- (WDGGeoposition*)lastKnownGeoposition {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastKnownGeoposition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoposition>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addGeofenceStateChangedEvent:(void (^)(WDGGGeofenceMonitor*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->add_GeofenceStateChanged(
        Make<ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object>(eventHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGeofenceStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GeofenceStateChanged(token));
}

- (NSArray* /* WDGGGeofenceStateChangeReport* */)readReports {
    ComPtr<IVectorView<ABI::Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->ReadReports(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDGGGeofenceStateChangeReport_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDGGGeofenceMonitor*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusChanged(
        Make<ITypedEventHandler_Windows_Devices_Geolocation_Geofencing_GeofenceMonitor_System_Object>(eventHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusChanged(token));
}

@end

@implementation WDGGGeofenceStateChangeReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDGGGeofenceState)newState {
    ABI::Windows::Devices::Geolocation::Geofencing::GeofenceState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewState(&unmarshalledReturn));
    return (WDGGGeofenceState)unmarshalledReturn;
}

- (WDGGGeofence*)geofence {
    ComPtr<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Geofence(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGGeofence>(unmarshalledReturn.Get());
}

- (WDGGeoposition*)geoposition {
    ComPtr<ABI::Windows::Devices::Geolocation::IGeoposition> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Geoposition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGGeoposition>(unmarshalledReturn.Get());
}

- (WDGGGeofenceRemovalReason)removalReason {
    ABI::Windows::Devices::Geolocation::Geofencing::GeofenceRemovalReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemovalReason(&unmarshalledReturn));
    return (WDGGGeofenceRemovalReason)unmarshalledReturn;
}

@end

id RTProxiedNSArray_WDGGGeofenceStateChangeReport_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport*>,
                                         RTArrayObj<ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport*,
                                                    IVectorView<ABI::Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport*>,
                                                    WDGGGeofenceStateChangeReport,
                                                    ABI::Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WDGGGeofence_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Devices::Geolocation::Geofencing::Geofence*>,
                                                RTMutableArrayObj<ABI::Windows::Devices::Geolocation::Geofencing::IGeofence*,
                                                                  IVector<ABI::Windows::Devices::Geolocation::Geofencing::Geofence*>,
                                                                  WDGGGeofence,
                                                                  ABI::Windows::Devices::Geolocation::Geofencing::Geofence*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
