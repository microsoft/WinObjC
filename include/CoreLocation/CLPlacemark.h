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

#import <CoreLocation/CoreLocationExport.h>
#import <Foundation/NSObject.h>

@class CLLocation;
@class CLRegion;
@class NSTimeZone;
@class NSDictionary;
@class NSArray;

CORELOCATION_EXPORT_CLASS
@interface CLPlacemark : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithPlacemark:(CLPlacemark*)placemark STUB_METHOD;
@property (readonly, copy, nonatomic) CLLocation* location STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDictionary* addressDictionary STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* ISOcountryCode STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* country STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* postalCode STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* administrativeArea STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* subAdministrativeArea STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* locality STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* subLocality STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* thoroughfare STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* subThoroughfare STUB_PROPERTY;
@property (readonly, copy, nonatomic) CLRegion* region STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSTimeZone* timeZone STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* inlandWater STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* ocean STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* areasOfInterest STUB_PROPERTY;
@end
