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

#pragma once

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocationExport.h>
#import <CoreLocation/CLLocation.h>
#import <stdint.h> // uint32_t

@class CLRegion;
@protocol CLLocationManagerDelegate;

typedef NS_ENUM(uint32_t, CLAuthorizationStatus) {
    kCLAuthorizationStatusNotDetermined = 0,
    kCLAuthorizationStatusRestricted,
    kCLAuthorizationStatusDenied,
    kCLAuthorizationStatusAuthorized,
    kCLAuthorizationStatusAuthorizedAlways = kCLAuthorizationStatusAuthorized,
    kCLAuthorizationStatusAuthorizedWhenInUse
};

enum _CLActivityType {
    CLActivityTypeOther = 1,
    CLActivityTypeAutomotiveNavigation,
    CLActivityTypeFitness,
    CLActivityTypeOtherNavigation,
};
typedef uint32_t CLActivityType;

CORELOCATION_EXPORT_CLASS
@interface CLLocationManager : NSObject

@property (copy, nonatomic) NSString* purpose;
@property (assign, nonatomic) id<CLLocationManagerDelegate> delegate;
@property (assign, nonatomic) CLLocationAccuracy desiredAccuracy;
@property (readonly, nonatomic) BOOL locationServicesEnabled;
@property (assign, nonatomic) CLActivityType activityType;
@property (assign, nonatomic) CLLocationDistance distanceFilter;
@property (readonly, nonatomic) CLLocation* location;
@property (readonly, nonatomic) NSSet* monitoredRegions;

- (void)requestAlwaysAuthorization;
- (void)requestWhenInUseAuthorization;
+ (CLAuthorizationStatus)authorizationStatus;
+ (BOOL)locationServicesEnabled;
+ (BOOL)deferredLocationUpdatesAvailable;
+ (BOOL)significantLocationChangeMonitoringAvailable;
+ (BOOL)headingAvailable;
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass;
+ (BOOL)isRangingAvailable;
- (void)startUpdatingLocation;
- (void)stopUpdatingLocation;
- (void)requestLocation;
- (void)allowDeferredLocationUpdatesUntilTraveled:(CLLocationDistance)distance timeout:(NSTimeInterval)timeout;
- (void)disallowDeferredLocationUpdates;

// TODO::
// todo-nithishm-11022015 - Need to support other methods in future.

@end
