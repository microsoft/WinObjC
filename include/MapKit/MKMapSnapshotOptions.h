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
#import <MapKit/MKMapView.h>

@class MKMapCamera;

MAPKIT_EXPORT_CLASS
@interface MKMapSnapshotOptions : NSObject <NSCopying>
@property (copy, nonatomic) MKMapCamera* camera STUB_PROPERTY;
@property (assign, nonatomic) MKCoordinateRegion region STUB_PROPERTY;
@property (assign, nonatomic) MKMapRect rect STUB_PROPERTY;
@property (assign, nonatomic) MKMapType mapType STUB_PROPERTY;
@property (nonatomic) BOOL showsPointsOfInterest STUB_PROPERTY;
@property (nonatomic) BOOL showsBuildings STUB_PROPERTY;
@property (assign, nonatomic) CGSize size STUB_PROPERTY;
@property (assign, nonatomic) CGFloat scale STUB_PROPERTY;
@end
