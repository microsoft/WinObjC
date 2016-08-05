//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <CoreLocation/CoreLocationExport.h>
#import <CoreLocation/CoreLocationDataTypes.h>
#import <CoreLocation/CoreLocationConstants.h>

@protocol CLLocationManagerDelegate;
@class CLRegion;
@class CLBeaconRegion;
@class CLLocation;
@class CLHeading;

typedef NS_ENUM(uint32_t, CLAuthorizationStatus) {
    kCLAuthorizationStatusNotDetermined = 0,
    kCLAuthorizationStatusRestricted,
    kCLAuthorizationStatusDenied,
    kCLAuthorizationStatusAuthorized,
    kCLAuthorizationStatusAuthorizedAlways = kCLAuthorizationStatusAuthorized,
    kCLAuthorizationStatusAuthorizedWhenInUse
};

typedef NSInteger CLActivityType;
enum {
    CLActivityTypeOther = 1,
    CLActivityTypeAutomotiveNavigation,
    CLActivityTypeFitness,
    CLActivityTypeOtherNavigation,
};

CORELOCATION_EXPORT const CLLocationDistance CLLocationDistanceMax;
CORELOCATION_EXPORT const NSTimeInterval CLTimeIntervalMax;
CORELOCATION_EXPORT_CLASS
@interface CLLocationManager : NSObject
- (void)requestWhenInUseAuthorization;
- (void)requestAlwaysAuthorization;
+ (CLAuthorizationStatus)authorizationStatus;
+ (BOOL)locationServicesEnabled;
+ (BOOL)deferredLocationUpdatesAvailable;
+ (BOOL)significantLocationChangeMonitoringAvailable;
+ (BOOL)headingAvailable;
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass;
+ (BOOL)isRangingAvailable;
@property (assign, nonatomic) id<CLLocationManagerDelegate> delegate;
- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
- (void)requestLocation;
@property (assign, nonatomic) BOOL pausesLocationUpdatesAutomatically STUB_PROPERTY;
@property (assign, nonatomic) BOOL allowsBackgroundLocationUpdates;
@property (assign, nonatomic) CLLocationDistance distanceFilter;
@property (assign, nonatomic) CLLocationAccuracy desiredAccuracy;
@property (assign, nonatomic) CLActivityType activityType;
- (void)startMonitoringSignificantLocationChanges STUB_METHOD;
- (void)stopMonitoringSignificantLocationChanges STUB_METHOD;
- (void)startUpdatingHeading;
- (void)stopUpdatingHeading;
- (void)dismissHeadingCalibrationDisplay STUB_METHOD;
@property (assign, nonatomic) CLLocationDegrees headingFilter;
@property (assign, nonatomic) CLDeviceOrientation headingOrientation;
- (void)startMonitoringForRegion:(CLRegion*)region STUB_METHOD;
- (void)stopMonitoringForRegion:(CLRegion*)region STUB_METHOD;
@property (readonly, copy, nonatomic) NSSet* monitoredRegions STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationDistance maximumRegionMonitoringDistance STUB_PROPERTY;
- (void)startRangingBeaconsInRegion:(CLBeaconRegion*)region STUB_METHOD;
- (void)stopRangingBeaconsInRegion:(CLBeaconRegion*)region STUB_METHOD;
- (void)requestStateForRegion:(CLRegion*)region STUB_METHOD;
@property (readonly, copy, nonatomic) NSSet* rangedRegions STUB_PROPERTY;
- (void)startMonitoringVisits STUB_METHOD;
- (void)stopMonitoringVisits STUB_METHOD;
- (void)allowDeferredLocationUpdatesUntilTraveled:(CLLocationDistance)distance timeout:(NSTimeInterval)timeout STUB_METHOD;
- (void)disallowDeferredLocationUpdates STUB_METHOD;
@property (readonly, copy, nonatomic) CLLocation* location;
@property (readonly, copy, nonatomic) CLHeading* heading;
+ (BOOL)regionMonitoringAvailable STUB_METHOD;
+ (BOOL)regionMonitoringEnabled STUB_METHOD;
- (void)startMonitoringForRegion:(CLRegion*)region desiredAccuracy:(CLLocationAccuracy)accuracy STUB_METHOD;
@property (assign, nonatomic) BOOL locationServicesEnabled;
@property (copy, nonatomic) NSString* purpose;
@end
