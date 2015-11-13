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

// WindowsServicesMaps.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSMMapAddress, WSMMapLocation, WSMMapRouteManeuver, WSMMapRouteLeg, WSMMapRoute, WSMMapLocationFinderResult, WSMMapRouteFinderResult,
    WSMMapRouteDrivingOptions, WSMMapLocationFinder, WSMMapRouteFinder, WSMMapService, WSMMapManager;
@protocol WSMIMapRouteDrivingOptions
, WSMIMapAddress, WSMIMapAddress2, WSMIMapLocation, WSMIMapLocationFinderResult, WSMIMapRouteManeuver, WSMIMapRouteManeuver2,
    WSMIMapRouteLeg, WSMIMapRoute, WSMIMapRoute2, WSMIMapRouteFinderResult, WSMIMapRouteFinderResult2, WSMIMapLocationFinderStatics,
    WSMIMapRouteFinderStatics, WSMIMapRouteFinderStatics2, WSMIMapServiceStatics, WSMIMapManagerStatics, WSMIMapServiceStatics2;

// Windows.Services.Maps.MapRouteOptimization
enum _WSMMapRouteOptimization {
    WSMMapRouteOptimizationTime = 0,
    WSMMapRouteOptimizationDistance = 1,
    WSMMapRouteOptimizationTimeWithTraffic = 2,
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

#include "WindowsFoundation.h"
#include "WindowsDevicesGeolocation.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.Services.Maps.MapAddress
#ifndef __WSMMapAddress_DEFINED__
#define __WSMMapAddress_DEFINED__

WINRT_EXPORT
@interface WSMMapAddress : RTObject
@property (readonly) NSString* buildingFloor;
@property (readonly) NSString* buildingName;
@property (readonly) NSString* buildingRoom;
@property (readonly) NSString* buildingWing;
@property (readonly) NSString* continent;
@property (readonly) NSString* country;
@property (readonly) NSString* countryCode;
@property (readonly) NSString* district;
@property (readonly) NSString* neighborhood;
@property (readonly) NSString* postCode;
@property (readonly) NSString* region;
@property (readonly) NSString* regionCode;
@property (readonly) NSString* street;
@property (readonly) NSString* streetNumber;
@property (readonly) NSString* town;
@property (readonly) NSString* formattedAddress;
@end

#endif // __WSMMapAddress_DEFINED__

// Windows.Services.Maps.MapLocation
#ifndef __WSMMapLocation_DEFINED__
#define __WSMMapLocation_DEFINED__

WINRT_EXPORT
@interface WSMMapLocation : RTObject
@property (readonly) WSMMapAddress* address;
@property (readonly) NSString* description;
@property (readonly) NSString* displayName;
@property (readonly) WDGGeopoint* point;
@end

#endif // __WSMMapLocation_DEFINED__

// Windows.Services.Maps.MapRouteManeuver
#ifndef __WSMMapRouteManeuver_DEFINED__
#define __WSMMapRouteManeuver_DEFINED__

WINRT_EXPORT
@interface WSMMapRouteManeuver : RTObject
@property (readonly) NSString* exitNumber;
@property (readonly) NSString* instructionText;
@property (readonly) WSMMapRouteManeuverKind kind;
@property (readonly) double lengthInMeters;
@property (readonly) WSMMapManeuverNotices maneuverNotices;
@property (readonly) WDGGeopoint* startingPoint;
@property (readonly) double endHeading;
@property (readonly) double startHeading;
@property (readonly) NSString* streetName;
@end

#endif // __WSMMapRouteManeuver_DEFINED__

// Windows.Services.Maps.MapRouteLeg
#ifndef __WSMMapRouteLeg_DEFINED__
#define __WSMMapRouteLeg_DEFINED__

WINRT_EXPORT
@interface WSMMapRouteLeg : RTObject
@property (readonly) WDGGeoboundingBox* boundingBox;
@property (readonly) WFTimeSpan* estimatedDuration;
@property (readonly) double lengthInMeters;
@property (readonly) NSArray* maneuvers;
@property (readonly) WDGGeopath* path;
@end

#endif // __WSMMapRouteLeg_DEFINED__

// Windows.Services.Maps.MapRoute
#ifndef __WSMMapRoute_DEFINED__
#define __WSMMapRoute_DEFINED__

WINRT_EXPORT
@interface WSMMapRoute : RTObject
@property (readonly) WDGGeoboundingBox* boundingBox;
@property (readonly) WFTimeSpan* estimatedDuration;
@property (readonly) BOOL isTrafficBased;
@property (readonly) NSArray* legs;
@property (readonly) double lengthInMeters;
@property (readonly) WDGGeopath* path;
@property (readonly) BOOL hasBlockedRoads;
@property (readonly) WSMMapRouteRestrictions violatedRestrictions;
@end

#endif // __WSMMapRoute_DEFINED__

// Windows.Services.Maps.MapLocationFinderResult
#ifndef __WSMMapLocationFinderResult_DEFINED__
#define __WSMMapLocationFinderResult_DEFINED__

WINRT_EXPORT
@interface WSMMapLocationFinderResult : RTObject
@property (readonly) NSArray* locations;
@property (readonly) WSMMapLocationFinderStatus status;
@end

#endif // __WSMMapLocationFinderResult_DEFINED__

// Windows.Services.Maps.MapRouteFinderResult
#ifndef __WSMMapRouteFinderResult_DEFINED__
#define __WSMMapRouteFinderResult_DEFINED__

WINRT_EXPORT
@interface WSMMapRouteFinderResult : RTObject
@property (readonly) WSMMapRoute* route;
@property (readonly) WSMMapRouteFinderStatus status;
@property (readonly) NSArray* alternateRoutes;
@end

#endif // __WSMMapRouteFinderResult_DEFINED__

// Windows.Services.Maps.MapRouteDrivingOptions
#ifndef __WSMMapRouteDrivingOptions_DEFINED__
#define __WSMMapRouteDrivingOptions_DEFINED__

WINRT_EXPORT
@interface WSMMapRouteDrivingOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property WSMMapRouteRestrictions routeRestrictions;
@property WSMMapRouteOptimization routeOptimization;
@property unsigned int maxAlternateRouteCount;
@property (copy) id initialHeading;
@end

#endif // __WSMMapRouteDrivingOptions_DEFINED__

// Windows.Services.Maps.MapLocationFinder
#ifndef __WSMMapLocationFinder_DEFINED__
#define __WSMMapLocationFinder_DEFINED__

WINRT_EXPORT
@interface WSMMapLocationFinder : RTObject
+ (void)findLocationsAtAsync:(WDGGeopoint*)queryPoint
                     success:(void (^)(WSMMapLocationFinderResult*))success
                     failure:(void (^)(NSError*))failure;
+ (void)findLocationsAsync:(NSString*)searchText
            referencePoint:(WDGGeopoint*)referencePoint
                   success:(void (^)(WSMMapLocationFinderResult*))success
                   failure:(void (^)(NSError*))failure;
+ (void)findLocationsWithMaxCountAsync:(NSString*)searchText
                        referencePoint:(WDGGeopoint*)referencePoint
                              maxCount:(unsigned int)maxCount
                               success:(void (^)(WSMMapLocationFinderResult*))success
                               failure:(void (^)(NSError*))failure;
@end

#endif // __WSMMapLocationFinder_DEFINED__

// Windows.Services.Maps.MapRouteFinder
#ifndef __WSMMapRouteFinder_DEFINED__
#define __WSMMapRouteFinder_DEFINED__

WINRT_EXPORT
@interface WSMMapRouteFinder : RTObject
+ (void)getDrivingRouteAsync:(WDGGeopoint*)startPoint
                    endPoint:(WDGGeopoint*)endPoint
                     success:(void (^)(WSMMapRouteFinderResult*))success
                     failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationAsync:(WDGGeopoint*)startPoint
                                    endPoint:(WDGGeopoint*)endPoint
                                optimization:(WSMMapRouteOptimization)optimization
                                     success:(void (^)(WSMMapRouteFinderResult*))success
                                     failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationAndRestrictionsAsync:(WDGGeopoint*)startPoint
                                                   endPoint:(WDGGeopoint*)endPoint
                                               optimization:(WSMMapRouteOptimization)optimization
                                               restrictions:(WSMMapRouteRestrictions)restrictions
                                                    success:(void (^)(WSMMapRouteFinderResult*))success
                                                    failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptimizationRestrictionsAndHeadingAsync:(WDGGeopoint*)startPoint
                                                          endPoint:(WDGGeopoint*)endPoint
                                                      optimization:(WSMMapRouteOptimization)optimization
                                                      restrictions:(WSMMapRouteRestrictions)restrictions
                                                  headingInDegrees:(double)headingInDegrees
                                                           success:(void (^)(WSMMapRouteFinderResult*))success
                                                           failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                  success:(void (^)(WSMMapRouteFinderResult*))success
                                  failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsAndOptimizationAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                            optimization:(WSMMapRouteOptimization)optimization
                                                 success:(void (^)(WSMMapRouteFinderResult*))success
                                                 failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsOptimizationAndRestrictionsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                                        optimization:(WSMMapRouteOptimization)optimization
                                                        restrictions:(WSMMapRouteRestrictions)restrictions
                                                             success:(void (^)(WSMMapRouteFinderResult*))success
                                                             failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteFromWaypointsOptimizationRestrictionsAndHeadingAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                                               optimization:(WSMMapRouteOptimization)optimization
                                                               restrictions:(WSMMapRouteRestrictions)restrictions
                                                           headingInDegrees:(double)headingInDegrees
                                                                    success:(void (^)(WSMMapRouteFinderResult*))success
                                                                    failure:(void (^)(NSError*))failure;
+ (void)getWalkingRouteAsync:(WDGGeopoint*)startPoint
                    endPoint:(WDGGeopoint*)endPoint
                     success:(void (^)(WSMMapRouteFinderResult*))success
                     failure:(void (^)(NSError*))failure;
+ (void)getWalkingRouteFromWaypointsAsync:(id<NSFastEnumeration> /* WDGGeopoint* */)wayPoints
                                  success:(void (^)(WSMMapRouteFinderResult*))success
                                  failure:(void (^)(NSError*))failure;
+ (void)getDrivingRouteWithOptionsAsync:(WDGGeopoint*)startPoint
                               endPoint:(WDGGeopoint*)endPoint
                                options:(WSMMapRouteDrivingOptions*)options
                                success:(void (^)(WSMMapRouteFinderResult*))success
                                failure:(void (^)(NSError*))failure;
@end

#endif // __WSMMapRouteFinder_DEFINED__

// Windows.Services.Maps.MapService
#ifndef __WSMMapService_DEFINED__
#define __WSMMapService_DEFINED__

WINRT_EXPORT
@interface WSMMapService : RTObject
+ (NSString*)serviceToken;
+ (void)setServiceToken:(NSString*)value;
+ (NSString*)worldViewRegionCode;
@end

#endif // __WSMMapService_DEFINED__

// Windows.Services.Maps.MapManager
#ifndef __WSMMapManager_DEFINED__
#define __WSMMapManager_DEFINED__

WINRT_EXPORT
@interface WSMMapManager : RTObject
+ (void)showDownloadedMapsUI;
+ (void)showMapsUpdateUI;
@end

#endif // __WSMMapManager_DEFINED__
