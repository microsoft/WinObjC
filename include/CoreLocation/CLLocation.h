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
#import <Foundation/NSObject.h>

@class CLFloor;
@class NSDate;

CORELOCATION_EXPORT_CLASS
@interface CLLocation : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                          altitude:(CLLocationDistance)altitude
                horizontalAccuracy:(CLLocationAccuracy)hAccuracy
                  verticalAccuracy:(CLLocationAccuracy)vAccuracy
                         timestamp:(NSDate*)timestamp;
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                          altitude:(CLLocationDistance)altitude
                horizontalAccuracy:(CLLocationAccuracy)hAccuracy
                  verticalAccuracy:(CLLocationAccuracy)vAccuracy
                            course:(CLLocationDirection)course
                             speed:(CLLocationSpeed)speed
                         timestamp:(NSDate*)timestamp;
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;
@property (readonly, nonatomic) CLLocationDistance altitude;
@property (readonly, copy, nonatomic) CLFloor* floor STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;
@property (readonly, nonatomic) CLLocationAccuracy verticalAccuracy;
@property (readonly, copy, nonatomic) NSDate* timestamp;
@property (readonly, copy, nonatomic) NSString* description;
- (CLLocationDistance)distanceFromLocation:(const CLLocation*)location;
- (CLLocationDistance)getDistanceFrom:(const CLLocation*)location;
@property (readonly, nonatomic) CLLocationSpeed speed;
@property (readonly, nonatomic) CLLocationDirection course;
@end
