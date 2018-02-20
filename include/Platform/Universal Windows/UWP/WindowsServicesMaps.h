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

// WindowsServicesMaps.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSERVICESMAPSEXPORT
#define OBJCUWPWINDOWSSERVICESMAPSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsServicesMaps.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSMMapAddress, WSMMapLocation, WSMManeuverWarning, WSMMapRouteManeuver, WSMMapRouteLeg, WSMMapRoute, WSMEnhancedWaypoint, WSMMapLocationFinderResult, WSMMapRouteFinderResult, WSMMapRouteDrivingOptions, WSMPlaceInfo, WSMPlaceInfoCreateOptions, WSMMapLocationFinder, WSMMapRouteFinder, WSMMapService, WSMMapManager;
@protocol WSMIMapRouteDrivingOptions, WSMIMapAddress, WSMIMapAddress2, WSMIMapLocation, WSMIMapLocationFinderResult, WSMIMapRouteManeuver, WSMIMapRouteManeuver2, WSMIMapRouteManeuver3, WSMIManeuverWarning, WSMIMapRouteLeg, WSMIMapRouteLeg2, WSMIMapRoute, WSMIMapRoute2, WSMIMapRoute3, WSMIMapRoute4, WSMIMapRouteFinderResult, WSMIMapRouteFinderResult2, WSMIEnhancedWaypoint, WSMIEnhancedWaypointFactory, WSMIMapLocationFinderStatics, WSMIMapLocationFinderStatics2, WSMIMapRouteFinderStatics, WSMIMapRouteFinderStatics2, WSMIMapRouteFinderStatics3, WSMIMapServiceStatics, WSMIMapManagerStatics, WSMIMapServiceStatics2, WSMIMapServiceStatics3, WSMIMapServiceStatics4, WSMIPlaceInfoCreateOptions, WSMIPlaceInfoStatics, WSMIPlaceInfo;

// Windows.Services.Maps.MapRouteOptimization
enum _WSMMapRouteOptimization {
    WSMMapRouteOptimizationTime = 0,
    WSMMapRouteOptimizationDistance = 1,
    WSMMapRouteOptimizationTimeWithTraffic = 2,
    WSMMapRouteOptimizationScenic = 3,
};
typedef unsigned WSMMapRouteOptimization;

// Windows.Services.Maps.MapRouteRestrictions
enum _WSMMapRouteRestrictions {
    WSMMapRouteRestrictionsNone = 0,
    WSMMapRouteRestrictionsHighways = 1,
    WSMMapRouteRestrictionsTollRoads = 2,
    WSMMapRouteRestrictionsFerries = 4,
    WSMMapRouteRestrictionsTunnels = 8,
    WSMMapRouteRestrictionsDirtRoads = 16,
    WSMMapRouteRestrictionsMotorail = 32,
};
typedef unsigned WSMMapRouteRestrictions;

// Windows.Services.Maps.MapRouteManeuverKind
enum _WSMMapRouteManeuverKind {
    WSMMapRouteManeuverKindNone = 0,
    WSMMapRouteManeuverKindStart = 1,
    WSMMapRouteManeuverKindStopover = 2,
    WSMMapRouteManeuverKindStopoverResume = 3,
    WSMMapRouteManeuverKindEnd = 4,
    WSMMapRouteManeuverKindGoStraight = 5,
    WSMMapRouteManeuverKindUTurnLeft = 6,
    WSMMapRouteManeuverKindUTurnRight = 7,
    WSMMapRouteManeuverKindTurnKeepLeft = 8,
    WSMMapRouteManeuverKindTurnKeepRight = 9,
    WSMMapRouteManeuverKindTurnLightLeft = 10,
    WSMMapRouteManeuverKindTurnLightRight = 11,
    WSMMapRouteManeuverKindTurnLeft = 12,
    WSMMapRouteManeuverKindTurnRight = 13,
    WSMMapRouteManeuverKindTurnHardLeft = 14,
    WSMMapRouteManeuverKindTurnHardRight = 15,
    WSMMapRouteManeuverKindFreewayEnterLeft = 16,
    WSMMapRouteManeuverKindFreewayEnterRight = 17,
    WSMMapRouteManeuverKindFreewayLeaveLeft = 18,
    WSMMapRouteManeuverKindFreewayLeaveRight = 19,
    WSMMapRouteManeuverKindFreewayContinueLeft = 20,
    WSMMapRouteManeuverKindFreewayContinueRight = 21,
    WSMMapRouteManeuverKindTrafficCircleLeft = 22,
    WSMMapRouteManeuverKindTrafficCircleRight = 23,
    WSMMapRouteManeuverKindTakeFerry = 24,
};
typedef unsigned WSMMapRouteManeuverKind;

// Windows.Services.Maps.MapManeuverNotices
enum _WSMMapManeuverNotices {
    WSMMapManeuverNoticesNone = 0,
    WSMMapManeuverNoticesToll = 1,
    WSMMapManeuverNoticesUnpaved = 2,
};
typedef unsigned WSMMapManeuverNotices;

// Windows.Services.Maps.MapLocationFinderStatus
enum _WSMMapLocationFinderStatus {
    WSMMapLocationFinderStatusSuccess = 0,
    WSMMapLocationFinderStatusUnknownError = 1,
    WSMMapLocationFinderStatusInvalidCredentials = 2,
    WSMMapLocationFinderStatusBadLocation = 3,
    WSMMapLocationFinderStatusIndexFailure = 4,
    WSMMapLocationFinderStatusNetworkFailure = 5,
    WSMMapLocationFinderStatusNotSupported = 6,
};
typedef unsigned WSMMapLocationFinderStatus;

// Windows.Services.Maps.MapRouteFinderStatus
enum _WSMMapRouteFinderStatus {
    WSMMapRouteFinderStatusSuccess = 0,
    WSMMapRouteFinderStatusUnknownError = 1,
    WSMMapRouteFinderStatusInvalidCredentials = 2,
    WSMMapRouteFinderStatusNoRouteFound = 3,
    WSMMapRouteFinderStatusNoRouteFoundWithGivenOptions = 4,
    WSMMapRouteFinderStatusStartPointNotFound = 5,
    WSMMapRouteFinderStatusEndPointNotFound = 6,
    WSMMapRouteFinderStatusNoPedestrianRouteFound = 7,
    WSMMapRouteFinderStatusNetworkFailure = 8,
    WSMMapRouteFinderStatusNotSupported = 9,
};
typedef unsigned WSMMapRouteFinderStatus;

// Windows.Services.Maps.MapLocationDesiredAccuracy
enum _WSMMapLocationDesiredAccuracy {
    WSMMapLocationDesiredAccuracyHigh = 0,
    WSMMapLocationDesiredAccuracyLow = 1,
};
typedef unsigned WSMMapLocationDesiredAccuracy;

// Windows.Services.Maps.WaypointKind
enum _WSMWaypointKind {
    WSMWaypointKindStop = 0,
    WSMWaypointKindVia = 1,
};
typedef unsigned WSMWaypointKind;

// Windows.Services.Maps.MapServiceDataUsagePreference
enum _WSMMapServiceDataUsagePreference {
    WSMMapServiceDataUsagePreferenceDefault = 0,
    WSMMapServiceDataUsagePreferenceOfflineMapDataOnly = 1,
};
typedef unsigned WSMMapServiceDataUsagePreference;

// Windows.Services.Maps.TrafficCongestion
enum _WSMTrafficCongestion {
    WSMTrafficCongestionUnknown = 0,
    WSMTrafficCongestionLight = 1,
    WSMTrafficCongestionMild = 2,
    WSMTrafficCongestionMedium = 3,
    WSMTrafficCongestionHeavy = 4,
};
typedef unsigned WSMTrafficCongestion;

// Windows.Services.Maps.ManeuverWarningKind
enum _WSMManeuverWarningKind {
    WSMManeuverWarningKindNone = 0,
    WSMManeuverWarningKindAccident = 1,
    WSMManeuverWarningKindAdministrativeDivisionChange = 2,
    WSMManeuverWarningKindAlert = 3,
    WSMManeuverWarningKindBlockedRoad = 4,
    WSMManeuverWarningKindCheckTimetable = 5,
    WSMManeuverWarningKindCongestion = 6,
    WSMManeuverWarningKindConstruction = 7,
    WSMManeuverWarningKindCountryChange = 8,
    WSMManeuverWarningKindDisabledVehicle = 9,
    WSMManeuverWarningKindGateAccess = 10,
    WSMManeuverWarningKindGetOffTransit = 11,
    WSMManeuverWarningKindGetOnTransit = 12,
    WSMManeuverWarningKindIllegalUTurn = 13,
    WSMManeuverWarningKindMassTransit = 14,
    WSMManeuverWarningKindMiscellaneous = 15,
    WSMManeuverWarningKindNoIncident = 16,
    WSMManeuverWarningKindOther = 17,
    WSMManeuverWarningKindOtherNews = 18,
    WSMManeuverWarningKindOtherTrafficIncidents = 19,
    WSMManeuverWarningKindPlannedEvent = 20,
    WSMManeuverWarningKindPrivateRoad = 21,
    WSMManeuverWarningKindRestrictedTurn = 22,
    WSMManeuverWarningKindRoadClosures = 23,
    WSMManeuverWarningKindRoadHazard = 24,
    WSMManeuverWarningKindScheduledConstruction = 25,
    WSMManeuverWarningKindSeasonalClosures = 26,
    WSMManeuverWarningKindTollbooth = 27,
    WSMManeuverWarningKindTollRoad = 28,
    WSMManeuverWarningKindTollZoneEnter = 29,
    WSMManeuverWarningKindTollZoneExit = 30,
    WSMManeuverWarningKindTrafficFlow = 31,
    WSMManeuverWarningKindTransitLineChange = 32,
    WSMManeuverWarningKindUnpavedRoad = 33,
    WSMManeuverWarningKindUnscheduledConstruction = 34,
    WSMManeuverWarningKindWeather = 35,
};
typedef unsigned WSMManeuverWarningKind;

// Windows.Services.Maps.ManeuverWarningSeverity
enum _WSMManeuverWarningSeverity {
    WSMManeuverWarningSeverityNone = 0,
    WSMManeuverWarningSeverityLowImpact = 1,
    WSMManeuverWarningSeverityMinor = 2,
    WSMManeuverWarningSeverityModerate = 3,
    WSMManeuverWarningSeveritySerious = 4,
};
typedef unsigned WSMManeuverWarningSeverity;

#include "WindowsDevicesGeolocation.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Services.Maps.MapAddress
#ifndef __WSMMapAddress_DEFINED__
#define __WSMMapAddress_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapAddress : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * buildingFloor;
@property (readonly) NSString * buildingName;
@property (readonly) NSString * buildingRoom;
@property (readonly) NSString * buildingWing;
@property (readonly) NSString * continent;
@property (readonly) NSString * country;
@property (readonly) NSString * countryCode;
@property (readonly) NSString * district;
@property (readonly) NSString * neighborhood;
@property (readonly) NSString * postCode;
@property (readonly) NSString * region;
@property (readonly) NSString * regionCode;
@property (readonly) NSString * street;
@property (readonly) NSString * streetNumber;
@property (readonly) NSString * town;
@property (readonly) NSString * formattedAddress;
@end

#endif // __WSMMapAddress_DEFINED__

// Windows.Services.Maps.MapLocation
#ifndef __WSMMapLocation_DEFINED__
#define __WSMMapLocation_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapLocation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMMapAddress* address;
@property (readonly) NSString * Description;
@property (readonly) NSString * displayName;
@property (readonly) WDGGeopoint* point;
@end

#endif // __WSMMapLocation_DEFINED__

// Windows.Services.Maps.ManeuverWarning
#ifndef __WSMManeuverWarning_DEFINED__
#define __WSMManeuverWarning_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMManeuverWarning : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMManeuverWarningKind kind;
@property (readonly) WSMManeuverWarningSeverity severity;
@end

#endif // __WSMManeuverWarning_DEFINED__

// Windows.Services.Maps.MapRouteManeuver
#ifndef __WSMMapRouteManeuver_DEFINED__
#define __WSMMapRouteManeuver_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRouteManeuver : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * exitNumber;
@property (readonly) NSString * instructionText;
@property (readonly) WSMMapRouteManeuverKind kind;
@property (readonly) double lengthInMeters;
@property (readonly) WSMMapManeuverNotices maneuverNotices;
@property (readonly) WDGGeopoint* startingPoint;
@property (readonly) double endHeading;
@property (readonly) double startHeading;
@property (readonly) NSString * streetName;
@property (readonly) NSArray* /* WSMManeuverWarning* */ warnings;
@end

#endif // __WSMMapRouteManeuver_DEFINED__

// Windows.Services.Maps.MapRouteLeg
#ifndef __WSMMapRouteLeg_DEFINED__
#define __WSMMapRouteLeg_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRouteLeg : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeoboundingBox* boundingBox;
@property (readonly) WFTimeSpan* estimatedDuration;
@property (readonly) double lengthInMeters;
@property (readonly) NSArray* /* WSMMapRouteManeuver* */ maneuvers;
@property (readonly) WDGGeopath* path;
@property (readonly) WFTimeSpan* durationWithoutTraffic;
@property (readonly) WSMTrafficCongestion trafficCongestion;
@end

#endif // __WSMMapRouteLeg_DEFINED__

// Windows.Services.Maps.MapRoute
#ifndef __WSMMapRoute_DEFINED__
#define __WSMMapRoute_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRoute : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDGGeoboundingBox* boundingBox;
@property (readonly) WFTimeSpan* estimatedDuration;
@property (readonly) BOOL isTrafficBased;
@property (readonly) NSArray* /* WSMMapRouteLeg* */ legs;
@property (readonly) double lengthInMeters;
@property (readonly) WDGGeopath* path;
@property (readonly) BOOL hasBlockedRoads;
@property (readonly) WSMMapRouteRestrictions violatedRestrictions;
@property (readonly) WFTimeSpan* durationWithoutTraffic;
@property (readonly) WSMTrafficCongestion trafficCongestion;
@property (readonly) BOOL isScenic;
@end

#endif // __WSMMapRoute_DEFINED__

// Windows.Services.Maps.EnhancedWaypoint
#ifndef __WSMEnhancedWaypoint_DEFINED__
#define __WSMEnhancedWaypoint_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMEnhancedWaypoint : RTObject
+ (WSMEnhancedWaypoint*)make:(WDGGeopoint*)point kind:(WSMWaypointKind)kind ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMWaypointKind kind;
@property (readonly) WDGGeopoint* point;
@end

#endif // __WSMEnhancedWaypoint_DEFINED__

// Windows.Services.Maps.MapLocationFinderResult
#ifndef __WSMMapLocationFinderResult_DEFINED__
#define __WSMMapLocationFinderResult_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapLocationFinderResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSMMapLocation* */ locations;
@property (readonly) WSMMapLocationFinderStatus status;
@end

#endif // __WSMMapLocationFinderResult_DEFINED__

// Windows.Services.Maps.MapRouteFinderResult
#ifndef __WSMMapRouteFinderResult_DEFINED__
#define __WSMMapRouteFinderResult_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRouteFinderResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSMMapRoute* route;
@property (readonly) WSMMapRouteFinderStatus status;
@property (readonly) NSArray* /* WSMMapRoute* */ alternateRoutes;
@end

#endif // __WSMMapRouteFinderResult_DEFINED__

// Windows.Services.Maps.MapRouteDrivingOptions
#ifndef __WSMMapRouteDrivingOptions_DEFINED__
#define __WSMMapRouteDrivingOptions_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRouteDrivingOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WSMMapRouteRestrictions routeRestrictions;
@property WSMMapRouteOptimization routeOptimization;
@property unsigned int maxAlternateRouteCount;
@property (retain) id /* double */ initialHeading;
@end

#endif // __WSMMapRouteDrivingOptions_DEFINED__

// Windows.Services.Maps.PlaceInfo
#ifndef __WSMPlaceInfo_DEFINED__
#define __WSMPlaceInfo_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMPlaceInfo : RTObject
+ (WSMPlaceInfo*)create:(WDGGeopoint*)referencePoint;
+ (WSMPlaceInfo*)createWithGeopointAndOptions:(WDGGeopoint*)referencePoint options:(WSMPlaceInfoCreateOptions*)options;
+ (WSMPlaceInfo*)createFromIdentifier:(NSString *)identifier;
+ (WSMPlaceInfo*)createFromIdentifierWithOptions:(NSString *)identifier defaultPoint:(WDGGeopoint*)defaultPoint options:(WSMPlaceInfoCreateOptions*)options;
+ (WSMPlaceInfo*)createFromMapLocation:(WSMMapLocation*)location;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayAddress;
@property (readonly) NSString * displayName;
@property (readonly) RTObject<WDGIGeoshape>* geoshape;
@property (readonly) NSString * identifier;
+ (BOOL)isShowSupported;
- (void)show:(WFRect*)selection;
- (void)showWithPreferredPlacement:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
@end

#endif // __WSMPlaceInfo_DEFINED__

// Windows.Services.Maps.PlaceInfoCreateOptions
#ifndef __WSMPlaceInfoCreateOptions_DEFINED__
#define __WSMPlaceInfoCreateOptions_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMPlaceInfoCreateOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * displayName;
@property (retain) NSString * displayAddress;
@end

#endif // __WSMPlaceInfoCreateOptions_DEFINED__

// Windows.Services.Maps.MapLocationFinder
#ifndef __WSMMapLocationFinder_DEFINED__
#define __WSMMapLocationFinder_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapLocationFinder : RTObject
+ (void)findLocationsAtWithAccuracyAsync:(WDGGeopoint*)queryPoint accuracy:(WSMMapLocationDesiredAccuracy)accuracy success:(void (^)(WSMMapLocationFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)findLocationsAtAsync:(WDGGeopoint*)queryPoint success:(void (^)(WSMMapLocationFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)findLocationsAsync:(NSString *)searchText referencePoint:(WDGGeopoint*)referencePoint success:(void (^)(WSMMapLocationFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)findLocationsWithMaxCountAsync:(NSString *)searchText referencePoint:(WDGGeopoint*)referencePoint maxCount:(unsigned int)maxCount success:(void (^)(WSMMapLocationFinderResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSMMapLocationFinder_DEFINED__

// Windows.Services.Maps.MapRouteFinder
#ifndef __WSMMapRouteFinder_DEFINED__
#define __WSMMapRouteFinder_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapRouteFinder : RTObject
+ (void)getDrivingRouteWithOptionsAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint options:(WSMMapRouteDrivingOptions*)options success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromEnhancedWaypointsAsync:(id<NSFastEnumeration> /* WSMEnhancedWaypoint* */)waypoints success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromEnhancedWaypointsWithOptionsAsync:(id<NSFastEnumeration> /* WSMEnhancedWaypoint* */)waypoints options:(WSMMapRouteDrivingOptions*)options success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint optimization:(WSMMapRouteOptimization)optimization success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationAndRestrictionsAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint optimization:(WSMMapRouteOptimization)optimization restrictions:(WSMMapRouteRestrictions)restrictions success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationRestrictionsAndHeadingAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint optimization:(WSMMapRouteOptimization)optimization restrictions:(WSMMapRouteRestrictions)restrictions headingInDegrees:(double)headingInDegrees success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsAndOptimizationAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints optimization:(WSMMapRouteOptimization)optimization success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints optimization:(WSMMapRouteOptimization)optimization restrictions:(WSMMapRouteRestrictions)restrictions success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints optimization:(WSMMapRouteOptimization)optimization restrictions:(WSMMapRouteRestrictions)restrictions headingInDegrees:(double)headingInDegrees success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getWalkingRouteAsync:(WDGGeopoint*)startPoint endPoint:(WDGGeopoint*)endPoint success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
+ (void)getWalkingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints success:(void (^)(WSMMapRouteFinderResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSMMapRouteFinder_DEFINED__

// Windows.Services.Maps.MapService
#ifndef __WSMMapService_DEFINED__
#define __WSMMapService_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapService : RTObject
+ (NSString *)serviceToken;
+ (void)setServiceToken:(NSString *)value;
+ (NSString *)worldViewRegionCode;
+ (NSString *)dataAttributions;
+ (WSMMapServiceDataUsagePreference)dataUsagePreference;
+ (void)setDataUsagePreference:(WSMMapServiceDataUsagePreference)value;
@end

#endif // __WSMMapService_DEFINED__

// Windows.Services.Maps.MapManager
#ifndef __WSMMapManager_DEFINED__
#define __WSMMapManager_DEFINED__

OBJCUWPWINDOWSSERVICESMAPSEXPORT
@interface WSMMapManager : RTObject
+ (void)showDownloadedMapsUI;
+ (void)showMapsUpdateUI;
@end

#endif // __WSMMapManager_DEFINED__

