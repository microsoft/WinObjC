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
#import <MapKit/MKMultiPoint.h>
#import <MapKit/MapKitDataTypes.h>

@class NSArray;

MAPKIT_EXPORT_CLASS
@interface MKPolygon : MKMultiPoint <MKAnnotation, MKOverlay>
+ (instancetype)polygonWithPoints:(MKMapPoint*)points count:(NSUInteger)count STUB_METHOD;
+ (instancetype)polygonWithPoints:(MKMapPoint*)points count:(NSUInteger)count interiorPolygons:(NSArray*)interiorPolygons STUB_METHOD;
+ (instancetype)polygonWithCoordinates:(CLLocationCoordinate2D*)coords count:(NSUInteger)count STUB_METHOD;
+ (instancetype)polygonWithCoordinates:(CLLocationCoordinate2D*)coords
                                 count:(NSUInteger)count
                      interiorPolygons:(NSArray*)interiorPolygons STUB_METHOD;
@property (readonly) NSArray* interiorPolygons STUB_PROPERTY;
@end
