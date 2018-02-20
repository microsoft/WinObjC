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

// WindowsServicesMapsGuidance.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
#define OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesMapsGuidance.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSMGGuidanceRoadSignpost, WSMGGuidanceManeuver, WSMGGuidanceRoute, WSMGGuidanceMapMatchedCoordinate, WSMGGuidanceLaneInfo, WSMGGuidanceUpdatedEventArgs, WSMGGuidanceReroutedEventArgs, WSMGGuidanceAudioNotificationRequestedEventArgs, WSMGGuidanceNavigator, WSMGGuidanceRoadSegment, WSMGGuidanceTelemetryCollector;
@protocol WSMGIGuidanceRoadSignpost, WSMGIGuidanceManeuver, WSMGIGuidanceUpdatedEventArgs, WSMGIGuidanceReroutedEventArgs, WSMGIGuidanceAudioNotificationRequestedEventArgs, WSMGIGuidanceNavigator, WSMGIGuidanceNavigator2, WSMGIGuidanceNavigatorStatics, WSMGIGuidanceNavigatorStatics2, WSMGIGuidanceRoadSegment, WSMGIGuidanceRoadSegment2, WSMGIGuidanceMapMatchedCoordinate, WSMGIGuidanceTelemetryCollectorStatics, WSMGIGuidanceTelemetryCollector, WSMGIGuidanceRouteStatics, WSMGIGuidanceRoute, WSMGIGuidanceLaneInfo;

// Windows.Services.Maps.Guidance.GuidanceManeuverKind
enum _WSMGGuidanceManeuverKind {
    WSMGGuidanceManeuverKindNone = 0,
    WSMGGuidanceManeuverKindGoStraight = 1,
    WSMGGuidanceManeuverKindUTurnRight = 2,
    WSMGGuidanceManeuverKindUTurnLeft = 3,
    WSMGGuidanceManeuverKindTurnKeepRight = 4,
    WSMGGuidanceManeuverKindTurnLightRight = 5,
    WSMGGuidanceManeuverKindTurnRight = 6,
    WSMGGuidanceManeuverKindTurnHardRight = 7,
    WSMGGuidanceManeuverKindKeepMiddle = 8,
    WSMGGuidanceManeuverKindTurnKeepLeft = 9,
    WSMGGuidanceManeuverKindTurnLightLeft = 10,
    WSMGGuidanceManeuverKindTurnLeft = 11,
    WSMGGuidanceManeuverKindTurnHardLeft = 12,
    WSMGGuidanceManeuverKindFreewayEnterRight = 13,
    WSMGGuidanceManeuverKindFreewayEnterLeft = 14,
    WSMGGuidanceManeuverKindFreewayLeaveRight = 15,
    WSMGGuidanceManeuverKindFreewayLeaveLeft = 16,
    WSMGGuidanceManeuverKindFreewayKeepRight = 17,
    WSMGGuidanceManeuverKindFreewayKeepLeft = 18,
    WSMGGuidanceManeuverKindTrafficCircleRight1 = 19,
    WSMGGuidanceManeuverKindTrafficCircleRight2 = 20,
    WSMGGuidanceManeuverKindTrafficCircleRight3 = 21,
    WSMGGuidanceManeuverKindTrafficCircleRight4 = 22,
    WSMGGuidanceManeuverKindTrafficCircleRight5 = 23,
    WSMGGuidanceManeuverKindTrafficCircleRight6 = 24,
    WSMGGuidanceManeuverKindTrafficCircleRight7 = 25,
    WSMGGuidanceManeuverKindTrafficCircleRight8 = 26,
    WSMGGuidanceManeuverKindTrafficCircleRight9 = 27,
    WSMGGuidanceManeuverKindTrafficCircleRight10 = 28,
    WSMGGuidanceManeuverKindTrafficCircleRight11 = 29,
    WSMGGuidanceManeuverKindTrafficCircleRight12 = 30,
    WSMGGuidanceManeuverKindTrafficCircleLeft1 = 31,
    WSMGGuidanceManeuverKindTrafficCircleLeft2 = 32,
    WSMGGuidanceManeuverKindTrafficCircleLeft3 = 33,
    WSMGGuidanceManeuverKindTrafficCircleLeft4 = 34,
    WSMGGuidanceManeuverKindTrafficCircleLeft5 = 35,
    WSMGGuidanceManeuverKindTrafficCircleLeft6 = 36,
    WSMGGuidanceManeuverKindTrafficCircleLeft7 = 37,
    WSMGGuidanceManeuverKindTrafficCircleLeft8 = 38,
    WSMGGuidanceManeuverKindTrafficCircleLeft9 = 39,
    WSMGGuidanceManeuverKindTrafficCircleLeft10 = 40,
    WSMGGuidanceManeuverKindTrafficCircleLeft11 = 41,
    WSMGGuidanceManeuverKindTrafficCircleLeft12 = 42,
    WSMGGuidanceManeuverKindStart = 43,
    WSMGGuidanceManeuverKindEnd = 44,
    WSMGGuidanceManeuverKindTakeFerry = 45,
    WSMGGuidanceManeuverKindPassTransitStation = 46,
    WSMGGuidanceManeuverKindLeaveTransitStation = 47,
};
typedef unsigned WSMGGuidanceManeuverKind;

// Windows.Services.Maps.Guidance.GuidanceMode
enum _WSMGGuidanceMode {
    WSMGGuidanceModeNone = 0,
    WSMGGuidanceModeSimulation = 1,
    WSMGGuidanceModeNavigation = 2,
    WSMGGuidanceModeTracking = 3,
};
typedef unsigned WSMGGuidanceMode;

// Windows.Services.Maps.Guidance.GuidanceAudioMeasurementSystem
enum _WSMGGuidanceAudioMeasurementSystem {
    WSMGGuidanceAudioMeasurementSystemMeters = 0,
    WSMGGuidanceAudioMeasurementSystemMilesAndYards = 1,
    WSMGGuidanceAudioMeasurementSystemMilesAndFeet = 2,
};
typedef unsigned WSMGGuidanceAudioMeasurementSystem;

// Windows.Services.Maps.Guidance.GuidanceAudioNotifications
enum _WSMGGuidanceAudioNotifications {
    WSMGGuidanceAudioNotificationsNone = 0,
    WSMGGuidanceAudioNotificationsManeuver = 1,
    WSMGGuidanceAudioNotificationsRoute = 2,
    WSMGGuidanceAudioNotificationsGps = 4,
    WSMGGuidanceAudioNotificationsSpeedLimit = 8,
    WSMGGuidanceAudioNotificationsTraffic = 16,
    WSMGGuidanceAudioNotificationsTrafficCamera = 32,
};
typedef unsigned WSMGGuidanceAudioNotifications;

// Windows.Services.Maps.Guidance.GuidanceAudioNotificationKind
enum _WSMGGuidanceAudioNotificationKind {
    WSMGGuidanceAudioNotificationKindManeuver = 0,
    WSMGGuidanceAudioNotificationKindRoute = 1,
    WSMGGuidanceAudioNotificationKindGps = 2,
    WSMGGuidanceAudioNotificationKindSpeedLimit = 3,
    WSMGGuidanceAudioNotificationKindTraffic = 4,
    WSMGGuidanceAudioNotificationKindTrafficCamera = 5,
};
typedef unsigned WSMGGuidanceAudioNotificationKind;

// Windows.Services.Maps.Guidance.GuidanceLaneMarkers
enum _WSMGGuidanceLaneMarkers {
    WSMGGuidanceLaneMarkersNone = 0,
    WSMGGuidanceLaneMarkersLightRight = 1,
    WSMGGuidanceLaneMarkersRight = 2,
    WSMGGuidanceLaneMarkersHardRight = 4,
    WSMGGuidanceLaneMarkersStraight = 8,
    WSMGGuidanceLaneMarkersUTurnLeft = 16,
    WSMGGuidanceLaneMarkersHardLeft = 32,
    WSMGGuidanceLaneMarkersLeft = 64,
    WSMGGuidanceLaneMarkersLightLeft = 128,
    WSMGGuidanceLaneMarkersUTurnRight = 256,
    WSMGGuidanceLaneMarkersUnknown = -1,
};
typedef unsigned WSMGGuidanceLaneMarkers;

#include "WindowsServicesMaps.h"
#include "WindowsUI.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Services.Maps.Guidance.GuidanceRoadSignpost
#ifndef __WSMGGuidanceRoadSignpost_DEFINED__
#define __WSMGGuidanceRoadSignpost_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceRoadSignpost : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUColor* backgroundColor;
@property (readonly) NSString * exit;
@property (readonly) NSArray* /* NSString * */ exitDirections;
@property (readonly) NSString * exitNumber;
@property (readonly) WUColor* foregroundColor;
@end

#endif // __WSMGGuidanceRoadSignpost_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceManeuver
#ifndef __WSMGGuidanceManeuver_DEFINED__
#define __WSMGGuidanceManeuver_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceManeuver : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * departureRoadName;
@property (readonly) NSString * departureShortRoadName;
@property (readonly) int distanceFromPreviousManeuver;
@property (readonly) int distanceFromRouteStart;
@property (readonly) int endAngle;
@property (readonly) NSString * instructionText;
@property (readonly) WSMGGuidanceManeuverKind kind;
@property (readonly) NSString * nextRoadName;
@property (readonly) NSString * nextShortRoadName;
@property (readonly) WSMGGuidanceRoadSignpost* roadSignpost;
@property (readonly) int startAngle;
@property (readonly) WDGGeopoint* startLocation;
@end

#endif // __WSMGGuidanceManeuver_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceRoute
#ifndef __WSMGGuidanceRoute_DEFINED__
#define __WSMGGuidanceRoute_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceRoute : RTObject
+ (BOOL)canCreateFromMapRoute:(WSMMapRoute*)mapRoute;
+ (WSMGGuidanceRoute*)tryCreateFromMapRoute:(WSMMapRoute*)mapRoute;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeoboundingBox* boundingBox;
@property (readonly) int distance;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSArray* /* WSMGGuidanceManeuver* */ maneuvers;
@property (readonly) WDGGeopath* path;
@property (readonly) NSArray* /* WSMGGuidanceRoadSegment* */ roadSegments;
- (WSMMapRoute*)convertToMapRoute;
@end

#endif // __WSMGGuidanceRoute_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceMapMatchedCoordinate
#ifndef __WSMGGuidanceMapMatchedCoordinate_DEFINED__
#define __WSMGGuidanceMapMatchedCoordinate_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceMapMatchedCoordinate : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double currentHeading;
@property (readonly) double currentSpeed;
@property (readonly) BOOL isOnStreet;
@property (readonly) WDGGeopoint* location;
@property (readonly) WSMGGuidanceRoadSegment* road;
@end

#endif // __WSMGGuidanceMapMatchedCoordinate_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceLaneInfo
#ifndef __WSMGGuidanceLaneInfo_DEFINED__
#define __WSMGGuidanceLaneInfo_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceLaneInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isOnRoute;
@property (readonly) WSMGGuidanceLaneMarkers laneMarkers;
@end

#endif // __WSMGGuidanceLaneInfo_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceUpdatedEventArgs
#ifndef __WSMGGuidanceUpdatedEventArgs_DEFINED__
#define __WSMGGuidanceUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMGGuidanceManeuver* afterNextManeuver;
@property (readonly) int afterNextManeuverDistance;
@property (readonly) WSMGGuidanceMapMatchedCoordinate* currentLocation;
@property (readonly) int distanceToDestination;
@property (readonly) int elapsedDistance;
@property (readonly) WFTimeSpan* elapsedTime;
@property (readonly) BOOL isNewManeuver;
@property (readonly) NSArray* /* WSMGGuidanceLaneInfo* */ laneInfo;
@property (readonly) WSMGGuidanceMode mode;
@property (readonly) WSMGGuidanceManeuver* nextManeuver;
@property (readonly) int nextManeuverDistance;
@property (readonly) NSString * roadName;
@property (readonly) WSMGGuidanceRoute* route;
@property (readonly) WFTimeSpan* timeToDestination;
@end

#endif // __WSMGGuidanceUpdatedEventArgs_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceReroutedEventArgs
#ifndef __WSMGGuidanceReroutedEventArgs_DEFINED__
#define __WSMGGuidanceReroutedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceReroutedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMGGuidanceRoute* route;
@end

#endif // __WSMGGuidanceReroutedEventArgs_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceAudioNotificationRequestedEventArgs
#ifndef __WSMGGuidanceAudioNotificationRequestedEventArgs_DEFINED__
#define __WSMGGuidanceAudioNotificationRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceAudioNotificationRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* NSString * */ audioFilePaths;
@property (readonly) WSMGGuidanceAudioNotificationKind audioNotification;
@property (readonly) NSString * audioText;
@end

#endif // __WSMGGuidanceAudioNotificationRequestedEventArgs_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceNavigator
#ifndef __WSMGGuidanceNavigator_DEFINED__
#define __WSMGGuidanceNavigator_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceNavigator : RTObject
+ (WSMGGuidanceNavigator*)getCurrent;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WSMGGuidanceAudioNotifications audioNotifications;
@property WSMGGuidanceAudioMeasurementSystem audioMeasurementSystem;
@property BOOL isGuidanceAudioMuted;
+ (BOOL)useAppProvidedVoice;
- (EventRegistrationToken)addDestinationReachedEvent:(void(^)(WSMGGuidanceNavigator*, RTObject*))del;
- (void)removeDestinationReachedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGuidanceUpdatedEvent:(void(^)(WSMGGuidanceNavigator*, WSMGGuidanceUpdatedEventArgs*))del;
- (void)removeGuidanceUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRerouteFailedEvent:(void(^)(WSMGGuidanceNavigator*, RTObject*))del;
- (void)removeRerouteFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReroutedEvent:(void(^)(WSMGGuidanceNavigator*, WSMGGuidanceReroutedEventArgs*))del;
- (void)removeReroutedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReroutingEvent:(void(^)(WSMGGuidanceNavigator*, RTObject*))del;
- (void)removeReroutingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserLocationLostEvent:(void(^)(WSMGGuidanceNavigator*, RTObject*))del;
- (void)removeUserLocationLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUserLocationRestoredEvent:(void(^)(WSMGGuidanceNavigator*, RTObject*))del;
- (void)removeUserLocationRestoredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAudioNotificationRequestedEvent:(void(^)(WSMGGuidanceNavigator*, WSMGGuidanceAudioNotificationRequestedEventArgs*))del;
- (void)removeAudioNotificationRequestedEvent:(EventRegistrationToken)tok;
- (void)startNavigating:(WSMGGuidanceRoute*)route;
- (void)startSimulating:(WSMGGuidanceRoute*)route speedInMetersPerSecond:(int)speedInMetersPerSecond;
- (void)startTracking;
- (void)pause;
- (void)resume;
- (void)stop;
- (void)repeatLastAudioNotification;
- (void)setGuidanceVoice:(int)voiceId voiceFolder:(NSString *)voiceFolder;
- (void)updateUserLocation:(WDGGeocoordinate*)userLocation;
- (void)updateUserLocationWithPositionOverride:(WDGGeocoordinate*)userLocation positionOverride:(WDGBasicGeoposition*)positionOverride;
@end

#endif // __WSMGGuidanceNavigator_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceRoadSegment
#ifndef __WSMGGuidanceRoadSegment_DEFINED__
#define __WSMGGuidanceRoadSegment_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceRoadSegment : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) BOOL isHighway;
@property (readonly) BOOL isTollRoad;
@property (readonly) BOOL isTunnel;
@property (readonly) WDGGeopath* path;
@property (readonly) NSString * roadName;
@property (readonly) NSString * shortRoadName;
@property (readonly) double speedLimit;
@property (readonly) WFTimeSpan* travelTime;
@property (readonly) BOOL isScenic;
@end

#endif // __WSMGGuidanceRoadSegment_DEFINED__

// Windows.Services.Maps.Guidance.GuidanceTelemetryCollector
#ifndef __WSMGGuidanceTelemetryCollector_DEFINED__
#define __WSMGGuidanceTelemetryCollector_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSGUIDANCEEXPORT
@interface WSMGGuidanceTelemetryCollector : RTObject
+ (WSMGGuidanceTelemetryCollector*)getCurrent;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int uploadFrequency;
@property double speedTrigger;
@property BOOL enabled;
- (void)clearLocalData;
@end

#endif // __WSMGGuidanceTelemetryCollector_DEFINED__

