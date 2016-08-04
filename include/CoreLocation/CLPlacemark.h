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
#import <Foundation/NSObject.h>

@class CLLocation;
@class CLRegion;
@class NSTimeZone;
@class NSDictionary;
@class NSArray;

CORELOCATION_EXPORT_CLASS
@interface CLPlacemark : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithPlacemark:(CLPlacemark*)placemark;
@property (readonly, copy, nonatomic) CLLocation* location;
@property (readonly, copy, nonatomic) NSString* name;
@property (readonly, copy, nonatomic) NSDictionary* addressDictionary;
@property (readonly, copy, nonatomic) NSString* ISOcountryCode;
@property (readonly, copy, nonatomic) NSString* country;
@property (readonly, copy, nonatomic) NSString* postalCode;
@property (readonly, copy, nonatomic) NSString* administrativeArea;
@property (readonly, copy, nonatomic) NSString* subAdministrativeArea;
@property (readonly, copy, nonatomic) NSString* locality;
@property (readonly, copy, nonatomic) NSString* subLocality;
@property (readonly, copy, nonatomic) NSString* thoroughfare;
@property (readonly, copy, nonatomic) NSString* subThoroughfare;
@property (readonly, copy, nonatomic) CLRegion* region;
@property (readonly, copy, nonatomic) NSTimeZone* timeZone;
@property (readonly, copy, nonatomic) NSString* inlandWater;
@property (readonly, copy, nonatomic) NSString* ocean;
@property (readonly, copy, nonatomic) NSArray* areasOfInterest;
@end
