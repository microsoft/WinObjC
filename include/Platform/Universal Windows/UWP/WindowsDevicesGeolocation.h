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
@class WDGGeopoint, WDGGeopath, WDGGeoboundingBox, WDGGeocoordinateSatelliteData, WDGVenueData, WDGGeocoordinate, WDGCivicAddress,
    WDGGeoposition, WDGPositionChangedEventArgs, WDGStatusChangedEventArgs, WDGGeolocator, WDGGeocircle;
@class WDGBasicGeoposition;
@protocol WDGIGeoshape
, WDGIGeopoint, WDGIGeopointFactory, WDGIGeopath, WDGIGeopathFactory, WDGIGeoboundingBox, WDGIGeoboundingBoxFactory,
    WDGIGeoboundingBoxStatics, WDGIGeocoordinateSatelliteData, WDGIVenueData, WDGIGeocoordinate, WDGIGeocoordinateWithPositionData,
    WDGIGeocoordinateWithPoint, WDGIGeocoordinateWithPositionSourceTimestamp, WDGIGeoposition, WDGIGeoposition2, WDGICivicAddress,
    WDGIPositionChangedEventArgs, WDGIStatusChangedEventArgs, WDGIGeolocator, WDGIGeolocatorWithScalarAccuracy, WDGIGeolocatorStatics,
    WDGIGeocircle, WDGIGeocircleFactory;

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
    WDGGeoshapeTypeGeopath = 2,
    WDGGeoshapeTypeGeoboundingBox = 3,
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

// Windows.Devices.Geolocation.GeolocationAccessStatus
enum _WDGGeolocationAccessStatus {
    WDGGeolocationAccessStatusUnspecified = 0,
    WDGGeolocationAccessStatusAllowed = 1,
    WDGGeolocationAccessStatusDenied = 2,
};
typedef unsigned WDGGeolocationAccessStatus;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

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
@property (readonly) unsigned int spatialReferenceId;
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
                                                    spatialReferenceId:(unsigned int)spatialReferenceId ACTIVATOR;
@property (readonly) WDGBasicGeoposition* position;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned int spatialReferenceId;
@end

#endif // __WDGGeopoint_DEFINED__

// Windows.Devices.Geolocation.Geopath
#ifndef __WDGGeopath_DEFINED__
#define __WDGGeopath_DEFINED__

WINRT_EXPORT
@interface WDGGeopath : RTObject <WDGIGeoshape>
+ (WDGGeopath*)create:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions ACTIVATOR;
+ (WDGGeopath*)createWithAltitudeReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                   altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem ACTIVATOR;
+ (WDGGeopath*)createWithAltitudeReferenceAndSpatialReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                      altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                           spatialReferenceId:(unsigned int)spatialReferenceId ACTIVATOR;
@property (readonly) NSArray* positions;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned int spatialReferenceId;
@end

#endif // __WDGGeopath_DEFINED__

// Windows.Devices.Geolocation.GeoboundingBox
#ifndef __WDGGeoboundingBox_DEFINED__
#define __WDGGeoboundingBox_DEFINED__

WINRT_EXPORT
@interface WDGGeoboundingBox : RTObject <WDGIGeoshape>
+ (WDGGeoboundingBox*)tryCompute:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions;
+ (WDGGeoboundingBox*)tryComputeWithAltitudeReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                    altitudeRefSystem:(WDGAltitudeReferenceSystem)altitudeRefSystem;
+ (WDGGeoboundingBox*)tryComputeWithAltitudeReferenceAndSpatialReference:(id<NSFastEnumeration> /* WDGBasicGeoposition* */)positions
                                                       altitudeRefSystem:(WDGAltitudeReferenceSystem)altitudeRefSystem
                                                      spatialReferenceId:(unsigned int)spatialReferenceId;
+ (WDGGeoboundingBox*)create:(WDGBasicGeoposition*)northwestCorner southeastCorner:(WDGBasicGeoposition*)southeastCorner ACTIVATOR;
+ (WDGGeoboundingBox*)createWithAltitudeReference:(WDGBasicGeoposition*)northwestCorner
                                  southeastCorner:(WDGBasicGeoposition*)southeastCorner
                          altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem ACTIVATOR;
+ (WDGGeoboundingBox*)createWithAltitudeReferenceAndSpatialReference:(WDGBasicGeoposition*)northwestCorner
                                                     southeastCorner:(WDGBasicGeoposition*)southeastCorner
                                             altitudeReferenceSystem:(WDGAltitudeReferenceSystem)altitudeReferenceSystem
                                                  spatialReferenceId:(unsigned int)spatialReferenceId ACTIVATOR;
@property (readonly) WDGBasicGeoposition* center;
@property (readonly) double maxAltitude;
@property (readonly) double minAltitude;
@property (readonly) WDGBasicGeoposition* northwestCorner;
@property (readonly) WDGBasicGeoposition* southeastCorner;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned int spatialReferenceId;
@end

#endif // __WDGGeoboundingBox_DEFINED__

// Windows.Devices.Geolocation.GeocoordinateSatelliteData
#ifndef __WDGGeocoordinateSatelliteData_DEFINED__
#define __WDGGeocoordinateSatelliteData_DEFINED__

WINRT_EXPORT
@interface WDGGeocoordinateSatelliteData : RTObject
@property (readonly) id horizontalDilutionOfPrecision;
@property (readonly) id positionDilutionOfPrecision;
@property (readonly) id verticalDilutionOfPrecision;
@end

#endif // __WDGGeocoordinateSatelliteData_DEFINED__

// Windows.Devices.Geolocation.VenueData
#ifndef __WDGVenueData_DEFINED__
#define __WDGVenueData_DEFINED__

WINRT_EXPORT
@interface WDGVenueData : RTObject
@property (readonly) NSString* id;
@property (readonly) NSString* level;
@end

#endif // __WDGVenueData_DEFINED__

// Windows.Devices.Geolocation.Geocoordinate
#ifndef __WDGGeocoordinate_DEFINED__
#define __WDGGeocoordinate_DEFINED__

WINRT_EXPORT
@interface WDGGeocoordinate : RTObject
@property (readonly) double accuracy;
@property (readonly) id altitude;
@property (readonly) id altitudeAccuracy;
@property (readonly) id heading;
@property (readonly) double latitude;
@property (readonly) double longitude;
@property (readonly) id speed;
@property (readonly) WFDateTime* timestamp;
@property (readonly) WDGGeopoint* point;
@property (readonly) WDGPositionSource positionSource;
@property (readonly) WDGGeocoordinateSatelliteData* satelliteData;
@property (readonly) id positionSourceTimestamp;
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
@property (readonly) WDGVenueData* venueData;
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
+ (void)requestAccessAsyncWithSuccess:(void (^)(WDGGeolocationAccessStatus))success failure:(void (^)(NSError*))failure;
+ (void)getGeopositionHistoryAsync:(WFDateTime*)startTime success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
+ (void)getGeopositionHistoryWithDurationAsync:(WFDateTime*)startTime
                                      duration:(WFTimeSpan*)duration
                                       success:(void (^)(NSArray*))success
                                       failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property unsigned int reportInterval;
@property double movementThreshold;
@property WDGPositionAccuracy desiredAccuracy;
@property (readonly) WDGPositionStatus locationStatus;
@property (copy) id desiredAccuracyInMeters;
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
                                                     spatialReferenceId:(unsigned int)spatialReferenceId ACTIVATOR;
@property (readonly) WDGBasicGeoposition* center;
@property (readonly) double radius;
@property (readonly) WDGAltitudeReferenceSystem altitudeReferenceSystem;
@property (readonly) WDGGeoshapeType geoshapeType;
@property (readonly) unsigned int spatialReferenceId;
@end

#endif // __WDGGeocircle_DEFINED__
