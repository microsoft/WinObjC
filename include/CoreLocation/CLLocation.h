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
#import <stdint.h> // uint32_t

enum _CLError {
    kCLErrorLocationUnknown = 0,
    kCLErrorDenied = 1,
    kCLErrorNetwork = 2,
};
typedef uint32_t CLError;

typedef double CLLocationAccuracy;
typedef double CLLocationDegrees;
typedef double CLLocationDistance;
typedef double CLLocationSpeed;
typedef double CLLocationDirection;

typedef struct {
    CLLocationDegrees latitude;
    CLLocationDegrees longitude;
} CLLocationCoordinate2D;

CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyHundredMeters;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyKilometer;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyThreeKilometers;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyBestForNavigation;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyBest;
CORELOCATION_EXPORT const CLLocationDistance kCLDistanceFilterNone;

CORELOCATION_EXPORT const CLLocationCoordinate2D kCLLocationCoordinate2DInvalid;
CORELOCATION_EXPORT const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;

CORELOCATION_EXPORT CLLocationCoordinate2D CLLocationCoordinate2DMake(CLLocationDegrees latitude, CLLocationDegrees longitude);
CORELOCATION_EXPORT BOOL CLLocationCoordinate2DIsValid(CLLocationCoordinate2D coordinate);

CORELOCATION_EXPORT_CLASS
@interface CLLocation : NSObject <NSCopying>

@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;
@property (readonly, nonatomic) CLLocationDistance altitude;
// TODO::
// todo-nithishm-11022015 - Need to implement CLFloor.
// @property(readonly, nonatomic, copy) CLFloor* floor;
@property (readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;
@property (readonly, nonatomic) CLLocationAccuracy verticalAccuracy;
@property (readonly, nonatomic, copy) NSDate* timestamp;
@property (nonatomic, readonly, copy) NSString* description;
@property (readonly, nonatomic) CLLocationSpeed speed;
@property (readonly, nonatomic) CLLocationDirection course;

- (CLLocationDistance)distanceFromLocation:(const CLLocation*)location;
- (CLLocationDistance)getDistanceFrom:(const CLLocation*)location;
- (id)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                altitude:(CLLocationDistance)altitude
      horizontalAccuracy:(CLLocationAccuracy)hAccuracy
        verticalAccuracy:(CLLocationAccuracy)vAccuracy
               timestamp:(NSDate*)timestamp;
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                altitude:(CLLocationDistance)altitude
      horizontalAccuracy:(CLLocationAccuracy)hAccuracy
        verticalAccuracy:(CLLocationAccuracy)vAccuracy
                  course:(CLLocationDirection)course
                   speed:(CLLocationSpeed)speed
               timestamp:(NSDate*)timestamp;

@end