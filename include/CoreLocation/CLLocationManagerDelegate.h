//******************************************************************************
//
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
#import <CoreLocation/CLRegion.h>
#import <CoreLocation/CLLocationManager.h>

@class CLVisit;

@protocol CLLocationManagerDelegate <NSObject>
@optional
- (void)locationManager:(CLLocationManager*)manager didUpdateLocations:(NSArray*)locations;

@optional
- (void)locationManager:(CLLocationManager*)manager didFailWithError:(NSError*)error;

@optional
- (void)locationManager:(CLLocationManager*)manager didFinishDeferredUpdatesWithError:(NSError*)error;

@optional
- (void)locationManager:(CLLocationManager*)manager didUpdateToLocation:(CLLocation*)newLocation fromLocation:(CLLocation*)oldLocation;

@optional
- (void)locationManagerDidPauseLocationUpdates:(CLLocationManager*)manager;

@optional
- (void)locationManagerDidResumeLocationUpdates:(CLLocationManager*)manager;

@optional
- (void)locationManager:(CLLocationManager*)manager didUpdateHeading:(CLHeading*)newHeading;

@optional
- (BOOL)locationManagerShouldDisplayHeadingCalibration:(CLLocationManager*)manager;

@optional
- (void)locationManager:(CLLocationManager*)manager didEnterRegion:(CLRegion*)region;

@optional
- (void)locationManager:(CLLocationManager*)manager didExitRegion:(CLRegion*)region;

@optional
- (void)locationManager:(CLLocationManager*)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion*)region;

@optional
- (void)locationManager:(CLLocationManager*)manager monitoringDidFailForRegion:(CLRegion*)region withError:(NSError*)error;

@optional
- (void)locationManager:(CLLocationManager*)manager didStartMonitoringForRegion:(CLRegion*)region;

@optional
- (void)locationManager:(CLLocationManager*)manager didRangeBeacons:(NSArray*)beacons inRegion:(CLBeaconRegion*)region;

@optional
- (void)locationManager:(CLLocationManager*)manager rangingBeaconsDidFailForRegion:(CLBeaconRegion*)region withError:(NSError*)error;

@optional
- (void)locationManager:(CLLocationManager*)manager didVisit:(CLVisit*)visit;

@optional
- (void)locationManager:(CLLocationManager*)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end
