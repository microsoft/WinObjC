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
#import <MapKit/MapKitDataTypes.h>
#import <CoreLocation/CLLocation.h>
#import <CoreGraphics/CGGeometry.h>

@class NSString;

MAPKIT_EXPORT MKCoordinateSpan MKCoordinateSpanMake(CLLocationDegrees latitudeDelta, CLLocationDegrees longitudeDelta) STUB_METHOD;
MAPKIT_EXPORT MKCoordinateRegion MKCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, MKCoordinateSpan span) STUB_METHOD;
MAPKIT_EXPORT MKCoordinateRegion MKCoordinateRegionMakeWithDistance(CLLocationCoordinate2D centerCoordinate,
                                                                    CLLocationDistance latitudinalMeters,
                                                                    CLLocationDistance longitudinalMeters) STUB_METHOD;
MAPKIT_EXPORT MKMapPoint MKMapPointMake(double x, double y) STUB_METHOD;
MAPKIT_EXPORT MKMapSize MKMapSizeMake(double width, double height) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectMake(double x, double y, double width, double height) STUB_METHOD;
MAPKIT_EXPORT MKMapPoint MKMapPointForCoordinate(CLLocationCoordinate2D coordinate) STUB_METHOD;
MAPKIT_EXPORT CLLocationCoordinate2D MKCoordinateForMapPoint(MKMapPoint mapPoint) STUB_METHOD;
MAPKIT_EXPORT MKCoordinateRegion MKCoordinateRegionForMapRect(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT CLLocationDistance MKMetersPerMapPointAtLatitude(CLLocationDegrees latitude) STUB_METHOD;
MAPKIT_EXPORT double MKMapPointsPerMeterAtLatitude(CLLocationDegrees latitude) STUB_METHOD;
MAPKIT_EXPORT CLLocationDistance MKMetersBetweenMapPoints(MKMapPoint a, MKMapPoint b) STUB_METHOD;
MAPKIT_EXPORT CGFloat MKRoadWidthAtZoomScale(MKZoomScale zoomScale) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMinX(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMinY(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMidX(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMidY(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMaxX(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetMaxY(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetWidth(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT double MKMapRectGetHeight(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapPointEqualToPoint(MKMapPoint point1, MKMapPoint point2) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapSizeEqualToSize(MKMapSize size1, MKMapSize size2) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectEqualToRect(MKMapRect rect1, MKMapRect rect2) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectContainsPoint(MKMapRect rect, MKMapPoint point) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectContainsRect(MKMapRect rect1, MKMapRect rect2) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectIntersectsRect(MKMapRect rect1, MKMapRect rect2) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectIsNull(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectIsEmpty(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectUnion(MKMapRect rect1, MKMapRect rect2) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectIntersection(MKMapRect rect1, MKMapRect rect2) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectInset(MKMapRect rect, double dx, double dy) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectOffset(MKMapRect rect, double dx, double dy) STUB_METHOD;
MAPKIT_EXPORT void MKMapRectDivide(MKMapRect rect, MKMapRect* slice, MKMapRect* remainder, double amount, CGRectEdge edge) STUB_METHOD;
MAPKIT_EXPORT NSString* MKStringFromMapPoint(MKMapPoint point) STUB_METHOD;
MAPKIT_EXPORT NSString* MKStringFromMapSize(MKMapSize size) STUB_METHOD;
MAPKIT_EXPORT NSString* MKStringFromMapRect(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT BOOL MKMapRectSpans180thMeridian(MKMapRect rect) STUB_METHOD;
MAPKIT_EXPORT MKMapRect MKMapRectRemainder(MKMapRect rect) STUB_METHOD;
