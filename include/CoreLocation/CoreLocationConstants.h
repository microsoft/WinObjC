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

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocationExport.h>
#import <CoreLocation/CoreLocationDataTypes.h>

typedef enum {
    CLDeviceOrientationUnknown = 0,
    CLDeviceOrientationPortrait,
    CLDeviceOrientationPortraitUpsideDown,
    CLDeviceOrientationLandscapeLeft,
    CLDeviceOrientationLandscapeRight,
    CLDeviceOrientationFaceUp,
    CLDeviceOrientationFaceDown
} CLDeviceOrientation;

typedef enum {
    kCLErrorLocationUnknown = 0,
    kCLErrorDenied,
    kCLErrorNetwork,
    kCLErrorHeadingFailure,
    kCLErrorRegionMonitoringDenied,
    kCLErrorRegionMonitoringFailure,
    kCLErrorRegionMonitoringSetupDelayed,
    kCLErrorRegionMonitoringResponseDelayed,
    kCLErrorGeocodeFoundNoResult,
    kCLErrorGeocodeFoundPartialResult,
    kCLErrorGeocodeCanceled,
    kCLErrorDeferredFailed,
    kCLErrorDeferredNotUpdatingLocation,
    kCLErrorDeferredAccuracyTooLow,
    kCLErrorDeferredDistanceFiltered,
    kCLErrorDeferredCanceled,
    kCLErrorRangingUnavailable,
    kCLErrorRangingFailure,
} CLError;

CORELOCATION_EXPORT NSString* const kCLErrorDomain;
CORELOCATION_EXPORT NSString* const kCLErrorUserInfoAlternateRegionKey;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyBestForNavigation;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyBest;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyHundredMeters;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyKilometer;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyThreeKilometers;
CORELOCATION_EXPORT const CLLocationCoordinate2D kCLLocationCoordinate2DInvalid;
CORELOCATION_EXPORT const CLLocationDistance kCLDistanceFilterNone;
CORELOCATION_EXPORT const CLLocationDegrees kCLHeadingFilterNone;