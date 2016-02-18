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
#import <Foundation/NSObject.h>
#import <CoreLocation/CLLocation.h>

@protocol MKReverseGeocoderDelegate;
@class MKPlacemark;

MAPKIT_EXPORT_CLASS
@interface MKReverseGeocoder : NSObject
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate STUB_METHOD;
@property (nonatomic) id<MKReverseGeocoderDelegate> delegate STUB_PROPERTY; // TODO: the property should be weak
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate STUB_PROPERTY;
@property (readonly, nonatomic) MKPlacemark* placemark STUB_PROPERTY;
- (void)start STUB_METHOD;
@property (readonly, getter=isQuerying, nonatomic) BOOL querying STUB_PROPERTY;
- (void)cancel STUB_METHOD;
@end
