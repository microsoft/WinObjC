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

// WindowsDevicesGeolocation.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDGGeopoint, WDGGeocoordinateSatelliteData, WDGGeocoordinate, WDGCivicAddress, WDGGeoposition, WDGPositionChangedEventArgs,
    WDGStatusChangedEventArgs, WDGGeolocator, WDGGeocircle;
@class WDGBasicGeoposition;
@protocol WDGIGeoshape
, WDGIGeopoint, WDGIGeopointFactory, WDGIGeocoordinateSatelliteData, WDGIGeocoordinate, WDGIGeocoordinateWithPositionData,
    WDGIGeocoordinateWithPoint, WDGICivicAddress, WDGIGeoposition, WDGIPositionChangedEventArgs, WDGIStatusChangedEventArgs, WDGIGeolocator,
    WDGIGeolocatorWithScalarAccuracy, WDGIGeocircle, WDGIGeocircleFactory;

// Windows.Devices.Geolocation.PositionAccuracy
enum _WDGPositionAccuracy {
    WDGPositionAccuracyDefault = 0,
    WDGPositionAccuracyHigh = 1,
};
typedef unsigned WDGPositionAccuracy;

// Windows.Devices.Geolocation.PositionStatus
enum _WDGPositionStatus {
    WDGPositionStatusReady = 0,
    WDGPositionStatusInitializing = 1,
    WDGPositionStatusNoData = 2,
    WDGPositionStatusDisabled = 3,
    WDGPositionStatusNotInitialized = 4,
    WDGPositionStatusNotAvailable = 5,
};
typedef unsigned WDGPositionStatus;

// Windows.Devices.Geolocation.PositionSource
enum _WDGPositionSource {
    WDGPositionSourceCellular = 0,
    WDGPositionSourceSatellite = 1,
    WDGPositionSourceWiFi = 2,
    WDGPositionSourceIPAddress = 3,
    WDGPositionSourceUnknown = 4,
};
typedef unsigned WDGPositionSource;

// Windows.Devices.Geolocation.GeoshapeType
enum _WDGGeoshapeType {
    WDGGeoshapeTypeGeopoint = 0,
    WDGGeoshapeTypeGeocircle = 1,
};
typedef unsigned WDGGeoshapeType;

// Windows.Devices.Geolocation.AltitudeReferenceSystem
enum _WDGAltitudeReferenceSystem {
    WDGAltitudeReferenceSystemUnspecified = 0,
    WDGAltitudeReferenceSystemTerrain = 1,
    WDGAltitudeReferenceSystemEllipsoid = 2,
    WDGAltitudeReferenceSystemGeoid = 3,
    WDGAltitudeReferenceSystemSurface = 4,
};
typedef unsigned WDGAltitudeReferenceSystem;

#include "WindowsFoundation.h"

// [struct] Windows.Devices.Geolocation.BasicGeoposition
WINRT_EXPORT
@interface WDGBasicGeoposition : NSObject
+ (instancetype) new;
@property double latitude;
@property double longitude;
@property double altitude;
@end

// Windows.Devices.Geolocation.IGeoshape
#ifndef __WDGIGeoshape_DEFINED__
#define __WDGIGeoshape_DEFINED__

@protocol WDGIGeoshape
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned spatialReferenceId;
@end

#endif // __WDGIGeoshape_DEFINED__

// Windows.Devices.Geolocation.Geopoint
#ifndef __WDGGeopoint_DEFINED__
#define __WDGGeopoint_DEFINED__

WINRT_EXPORT
@interface WDGGeopoint : RTObject <WDGIGeoshape>
+ (WDGGeopoint*)create:(WDGBasicGeoposition*)position ACTIVATOR;
+ (WDGGeopoint*)createWithAltitudeReferenceSystem:(WDGBasicGeoposition*)position
                          altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem ACTIVATOR;
+ (WDGGeopoint*)createWithAltitudeReferenceSystemAndSpatialReferenceId:(WDGBasicGeoposition*)position
                                               altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                    spatialReferenceId:(unsigned)spatialReferenceId ACTIVATOR;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned spatialReferenceId;
@property (readonly) WDGBasicGeoposition* position;
@end

#endif // __WDGGeopoint_DEFINED__

// Windows.Devices.Geolocation.GeocoordinateSatelliteData
#ifndef __WDGGeocoordinateSatelliteData_DEFINED__
#define __WDGGeocoordinateSatelliteData_DEFINED__

WINRT_EXPORT
@interface WDGGeocoordinateSatelliteData : RTObject
@property (readonly) NSNumber* horizontalDilutionOfPrecision;
@property (readonly) NSNumber* positionDilutionOfPrecision;
@property (readonly) NSNumber* verticalDilutionOfPrecision;
@end

#endif // __WDGGeocoordinateSatelliteData_DEFINED__

// Windows.Devices.Geolocation.Geocoordinate
#ifndef __WDGGeocoordinate_DEFINED__
#define __WDGGeocoordinate_DEFINED__

WINRT_EXPORT
@interface WDGGeocoordinate : RTObject
@property (readonly) WDGPositionSource positionSource;
@property (readonly) WDGGeocoordinateSatelliteData* satelliteData;
@property (readonly) double accuracy;
@property (readonly) NSNumber* altitude;
@property (readonly) NSNumber* altitudeAccuracy;
@property (readonly) NSNumber* heading;
@property (readonly) double latitude;
@property (readonly) double longitude;
@property (readonly) NSNumber* speed;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDGGeopoint* point;
@end

#endif // __WDGGeocoordinate_DEFINED__

// Windows.Devices.Geolocation.CivicAddress
#ifndef __WDGCivicAddress_DEFINED__
#define __WDGCivicAddress_DEFINED__

WINRT_EXPORT
@interface WDGCivicAddress : RTObject
@property (readonly) NSString* city;
@property (readonly) NSString* country;
@property (readonly) NSString* postalCode;
@property (readonly) NSString* state;
@property (readonly) WFDateTime* timestamp;
@end

#endif // __WDGCivicAddress_DEFINED__

// Windows.Devices.Geolocation.Geoposition
#ifndef __WDGGeoposition_DEFINED__
#define __WDGGeoposition_DEFINED__

WINRT_EXPORT
@interface WDGGeoposition : RTObject
@property (readonly) WDGCivicAddress* civicAddress;
@property (readonly) WDGGeocoordinate* coordinate;
@end

#endif // __WDGGeoposition_DEFINED__

// Windows.Devices.Geolocation.PositionChangedEventArgs
#ifndef __WDGPositionChangedEventArgs_DEFINED__
#define __WDGPositionChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDGPositionChangedEventArgs : RTObject
@property (readonly) WDGGeoposition* position;
@end

#endif // __WDGPositionChangedEventArgs_DEFINED__

// Windows.Devices.Geolocation.StatusChangedEventArgs
#ifndef __WDGStatusChangedEventArgs_DEFINED__
#define __WDGStatusChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDGStatusChangedEventArgs : RTObject
@property (readonly) WDGPositionStatus status;
@end

#endif // __WDGStatusChangedEventArgs_DEFINED__

// Windows.Devices.Geolocation.Geolocator
#ifndef __WDGGeolocator_DEFINED__
#define __WDGGeolocator_DEFINED__

WINRT_EXPORT
@interface WDGGeolocator : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSNumber* desiredAccuracyInMeters;
@property unsigned reportInterval;
@property double movementThreshold;
@property WDGPositionAccuracy desiredAccuracy;
@property (readonly) WDGPositionStatus locationStatus;
- (EventRegistrationToken)addPositionChangedEvent:(void (^)(WDGGeolocator*, WDGPositionChangedEventArgs*))del;
- (void)removePositionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WDGGeolocator*, WDGStatusChangedEventArgs*))del;
- (void)removeStatusChangedEvent:(EventRegistrationToken)tok;
- (void)getGeopositionAsyncWithSuccess:(void (^)(WDGGeoposition*))success failure:(void (^)(NSError*))failure;
- (void)getGeopositionAsyncWithAgeAndTimeout:(WFTimeSpan*)maximumAge
                                     timeout:(WFTimeSpan*)timeout
                                     success:(void (^)(WDGGeoposition*))success
                                     failure:(void (^)(NSError*))failure;
@end

#endif // __WDGGeolocator_DEFINED__

// Windows.Devices.Geolocation.Geocircle
#ifndef __WDGGeocircle_DEFINED__
#define __WDGGeocircle_DEFINED__

WINRT_EXPORT
@interface WDGGeocircle : RTObject <WDGIGeoshape>
+ (WDGGeocircle*)create:(WDGBasicGeoposition*)position radius:(double)radius ACTIVATOR;
+ (WDGGeocircle*)createWithAltitudeReferenceSystem:(WDGBasicGeoposition*)position
                                            radius:(double)radius
                           altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem ACTIVATOR;
+ (WDGGeocircle*)createWithAltitudeReferenceSystemAndSpatialReferenceId:(WDGBasicGeoposition*)position
                                                                 radius:(double)radius
                                                altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                     spatialReferenceId:(unsigned)spatialReferenceId ACTIVATOR;
@property (readonly) WDGBasicGeoposition* center;
@property (readonly) double radius;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned spatialReferenceId;
@end

#endif // __WDGGeocircle_DEFINED__
