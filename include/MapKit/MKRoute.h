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
#import <MapKit/MKDirectionsRequest.h>
#import <CoreLocation/CLLocation.h>

@class MKPolyline;
@class NSArray;
@class NSString;

MAPKIT_EXPORT_CLASS
@interface MKRoute : NSObject
@property (readonly, nonatomic) MKPolyline* polyline STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* steps STUB_PROPERTY;
@property (readonly, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* advisoryNotices STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationDistance distance STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval expectedTravelTime STUB_PROPERTY;
@property (readonly, nonatomic) MKDirectionsTransportType transportType STUB_PROPERTY;
@end
