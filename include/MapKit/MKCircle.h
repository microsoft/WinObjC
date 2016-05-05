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

#import <MapKit/MapKitExport.h>
#import <MapKit/MKAnnotation.h>
#import <MapKit/MKOverlay.h>
#import <Foundation/NSObject.h>
#import <MapKit/MKShape.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKitDataTypes.h>

MAPKIT_EXPORT_CLASS
@interface MKCircle : MKShape <MKAnnotation, MKOverlay, NSObject>
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord radius:(CLLocationDistance)radius STUB_METHOD;
+ (instancetype)circleWithMapRect:(MKMapRect)mapRect STUB_METHOD;
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationDistance radius STUB_PROPERTY;
@property (readonly, nonatomic) MKMapRect boundingMapRect STUB_PROPERTY;
@end
