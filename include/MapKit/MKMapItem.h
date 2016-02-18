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

@class NSString;
@class MKPlacemark;
@class NSURL;
@class NSTimeZone;
@class NSArray;
@class NSDictionary;

MAPKIT_EXPORT NSString* const MKLaunchOptionsDirectionsModeKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsMapTypeKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsMapCenterKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsMapSpanKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsShowsTrafficKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsCameraKey;
MAPKIT_EXPORT NSString* const MKLaunchOptionsDirectionsModeDriving;
MAPKIT_EXPORT NSString* const MKLaunchOptionsDirectionsModeWalking;
MAPKIT_EXPORT NSString* const MKLaunchOptionsDirectionsModeTransit;

MAPKIT_EXPORT_CLASS
@interface MKMapItem : NSObject
+ (MKMapItem*)mapItemForCurrentLocation STUB_METHOD;
- (instancetype)initWithPlacemark:(MKPlacemark*)placemark STUB_METHOD;
@property (readonly, nonatomic) MKPlacemark* placemark STUB_PROPERTY;
@property (readonly, nonatomic) BOOL isCurrentLocation STUB_PROPERTY;
@property (copy, nonatomic) NSString* name STUB_PROPERTY;
@property (copy, nonatomic) NSString* phoneNumber STUB_PROPERTY;
@property (nonatomic, strong) NSURL* url STUB_PROPERTY;
@property (copy, nonatomic) NSTimeZone* timeZone STUB_PROPERTY;
+ (BOOL)openMapsWithItems:(NSArray*)mapItems launchOptions:(NSDictionary*)launchOptions STUB_METHOD;
- (BOOL)openInMapsWithLaunchOptions:(NSDictionary*)launchOptions STUB_METHOD;
@end
