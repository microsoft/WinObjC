//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <CoreGraphics/CGBase.h>
#import <CoreLocation/CLLocation.h>
#import <Foundation/NSValue.h>

typedef struct {
    CLLocationDegrees latitudeDelta;
    CLLocationDegrees longitudeDelta;
} MKCoordinateSpan;

typedef struct {
    CLLocationCoordinate2D center;
    MKCoordinateSpan span;
} MKCoordinateRegion;

typedef struct {
    double x;
    double y;
} MKMapPoint;

typedef struct {
    double width;
    double height;
} MKMapSize;

typedef struct {
    MKMapPoint origin;
    MKMapSize size;
} MKMapRect;

typedef CGFloat MKZoomScale;

@interface NSValue (NSValueMapKitAdditions)
+ (NSValue*)valueWithMKCoordinate:(CLLocationCoordinate2D)coordinate STUB_METHOD;
+ (NSValue*)valueWithMKCoordinateSpan:(MKCoordinateSpan)span STUB_METHOD;
@end
