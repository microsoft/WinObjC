//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsDevicesGeolocationGeofencing.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDGGGeofence, WDGGGeofenceMonitor, WDGGGeofenceStateChangeReport;
@protocol WDGGIGeofenceFactory
, WDGGIGeofence, WDGGIGeofenceStateChangeReport, WDGGIGeofenceMonitorStatics, WDGGIGeofenceMonitor;

// Windows.Devices.Geolocation.Geofencing.MonitoredGeofenceStates
enum _WDGGMonitoredGeofenceStates {
    WDGGMonitoredGeofenceStatesNone = 0,
    WDGGMonitoredGeofenceStatesEntered = 1,
    WDGGMonitoredGeofenceStatesExited = 2,
    WDGGMonitoredGeofenceStatesRemoved = 4,
};
typedef unsigned WDGGMonitoredGeofenceStates;

// Windows.Devices.Geolocation.Geofencing.GeofenceState
enum _WDGGGeofenceState {
    WDGGGeofenceStateNone = 0,
    WDGGGeofenceStateEntered = 1,
    WDGGGeofenceStateExited = 2,
    WDGGGeofenceStateRemoved = 4,
};
typedef unsigned WDGGGeofenceState;

// Windows.Devices.Geolocation.Geofencing.GeofenceMonitorStatus
enum _WDGGGeofenceMonitorStatus {
    WDGGGeofenceMonitorStatusReady = 0,
    WDGGGeofenceMonitorStatusInitializing = 1,
    WDGGGeofenceMonitorStatusNoData = 2,
    WDGGGeofenceMonitorStatusDisabled = 3,
    WDGGGeofenceMonitorStatusNotInitialized = 4,
    WDGGGeofenceMonitorStatusNotAvailable = 5,
};
typedef unsigned WDGGGeofenceMonitorStatus;

// Windows.Devices.Geolocation.Geofencing.GeofenceRemovalReason
enum _WDGGGeofenceRemovalReason {
    WDGGGeofenceRemovalReasonUsed = 0,
    WDGGGeofenceRemovalReasonExpired = 1,
};
typedef unsigned WDGGGeofenceRemovalReason;

#include "WindowsFoundationCollections.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsFoundation.h"

// Windows.Devices.Geolocation.Geofencing.Geofence
#ifndef __WDGGGeofence_DEFINED__
#define __WDGGGeofence_DEFINED__

WINRT_EXPORT
@interface WDGGGeofence : RTObject
+ (WDGGGeofence*)create:(NSString*)id geoshape:(RTObject<WDGIGeoshape>*)geoshape ACTIVATOR;
+ (WDGGGeofence*)createWithMonitorStates:(NSString*)id
                                geoshape:(RTObject<WDGIGeoshape>*)geoshape
                         monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                               singleUse:(BOOL)singleUse ACTIVATOR;
+ (WDGGGeofence*)createWithMonitorStatesAndDwellTime:(NSString*)id
                                            geoshape:(RTObject<WDGIGeoshape>*)geoshape
                                     monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                                           singleUse:(BOOL)singleUse
                                           dwellTime:(WFTimeSpan*)dwellTime ACTIVATOR;
+ (WDGGGeofence*)createWithMonitorStatesDwellTimeStartTimeAndDuration:(NSString*)id
                                                             geoshape:(RTObject<WDGIGeoshape>*)geoshape
                                                      monitoredStates:(WDGGMonitoredGeofenceStates)monitoredStates
                                                            singleUse:(BOOL)singleUse
                                                            dwellTime:(WFTimeSpan*)dwellTime
                                                            startTime:(WFDateTime*)startTime
                                                             duration:(WFTimeSpan*)duration ACTIVATOR;
@property (readonly) WFTimeSpan* duration;
@property (readonly) WFTimeSpan* dwellTime;
@property (readonly) RTObject<WDGIGeoshape>* geoshape;
@property (readonly) NSString* id;
@property (readonly) WDGGMonitoredGeofenceStates monitoredStates;
@property (readonly) BOOL singleUse;
@property (readonly) WFDateTime* startTime;
@end

#endif // __WDGGGeofence_DEFINED__

// Windows.Devices.Geolocation.Geofencing.GeofenceMonitor
#ifndef __WDGGGeofenceMonitor_DEFINED__
#define __WDGGGeofenceMonitor_DEFINED__

WINRT_EXPORT
@interface WDGGGeofenceMonitor : RTObject
@property (readonly) id<NSFastEnumeration> /*WDGGGeofence*/ geofences;
@property (readonly) WDGGeoposition* lastKnownGeoposition;
@property (readonly) WDGGGeofenceMonitorStatus status;
+ (WDGGGeofenceMonitor*)current;
- (EventRegistrationToken)addGeofenceStateChangedEvent:(void (^)(WDGGGeofenceMonitor*, RTObject*))del;
- (void)removeGeofenceStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDGGGeofenceMonitor*, RTObject*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*WDGGGeofenceStateChangeReport*/)readReports;
@end

#endif // __WDGGGeofenceMonitor_DEFINED__

// Windows.Devices.Geolocation.Geofencing.GeofenceStateChangeReport
#ifndef __WDGGGeofenceStateChangeReport_DEFINED__
#define __WDGGGeofenceStateChangeReport_DEFINED__

WINRT_EXPORT
@interface WDGGGeofenceStateChangeReport : RTObject
@property (readonly) WDGGGeofence* geofence;
@property (readonly) WDGGeoposition* geoposition;
@property (readonly) WDGGGeofenceState newState;
@property (readonly) WDGGGeofenceRemovalReason removalReason;
@end

#endif // __WDGGGeofenceStateChangeReport_DEFINED__
