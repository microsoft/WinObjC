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

#import <CoreLocation/CLPlacemark.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <AddressBook/ABPerson.h>

@interface CLPlacemark ()

@property (readwrite, nonatomic) CLLocation* location;
@property (readwrite, nonatomic) NSString* name;
@property (readwrite, nonatomic) NSDictionary* addressDictionary;
@property (readwrite, nonatomic) NSString* ISOcountryCode;
@property (readwrite, nonatomic) NSString* country;
@property (readwrite, nonatomic) NSString* postalCode;
@property (readwrite, nonatomic) NSString* administrativeArea;
@property (readwrite, nonatomic) NSString* subAdministrativeArea;
@property (readwrite, nonatomic) NSString* locality;
@property (readwrite, nonatomic) NSString* subLocality;
@property (readwrite, nonatomic) NSString* thoroughfare;
@property (readwrite, nonatomic) NSString* subThoroughfare;
@property (readwrite, nonatomic) CLRegion* region;
@property (readwrite, nonatomic) NSTimeZone* timeZone;
@property (readwrite, nonatomic) NSString* inlandWater;
@property (readwrite, nonatomic) NSString* ocean;
@property (readwrite, nonatomic) NSArray<NSString*>* areasOfInterest;

@end

@implementation CLPlacemark

- (instancetype)initWithName:(NSString*)name location:(CLLocation*)location {
    if (self = [super init]) {
        _name = name;
        _location = location;
    }

    return self;
}

- (instancetype)initWithLocation:(CLLocation*)location dictionary:(NSMutableDictionary*)dictionary {
    if (self = [super init]) {
        _location = location;
        _name = [dictionary objectForKey:@"placemarkName"];
        _ISOcountryCode = [dictionary objectForKey:@"placemarkISOcountryCode"];
        _country = [dictionary objectForKey:@"placemarkCountry"];
        _postalCode = [dictionary objectForKey:@"placemarkPostalCode"];
        _administrativeArea = [dictionary objectForKey:@"placemarkAdministrativeArea"];
        _subAdministrativeArea = [dictionary objectForKey:@"placemarkSubAdministrativeArea"];
        _locality = [dictionary objectForKey:@"placemarkLocality"];
        _subLocality = [dictionary objectForKey:@"placemarkSubLocality"];
        _thoroughfare = [dictionary objectForKey:@"placemarkThoroughfare"];
        _subThoroughfare = [dictionary objectForKey:@"placemarkSubThoroughfare"];
    }

    return self;
}

/**
@Status Interoperable
*/
- (instancetype)initWithPlacemark:(CLPlacemark*)placemark {
    if (self = [super init]) {
        _location = placemark.location;
        _name = [placemark.name copy];
        _addressDictionary = [placemark.addressDictionary copy];
        _ISOcountryCode = [placemark.ISOcountryCode copy];
        _country = [placemark.country copy];
        _postalCode = [placemark.postalCode copy];
        _administrativeArea = [placemark.administrativeArea copy];
        _subAdministrativeArea = [placemark.subAdministrativeArea copy];
        _locality = [placemark.locality copy];
        _subLocality = [placemark.subLocality copy];
        _thoroughfare = [placemark.thoroughfare copy];
        _subThoroughfare = [placemark.subThoroughfare copy];
        _region = placemark.region;
        _timeZone = placemark.timeZone;
        _inlandWater = [placemark.inlandWater copy];
        _ocean = [placemark.ocean copy];
        _areasOfInterest = placemark.areasOfInterest;
    }

    return self;
}

/**
@Status Stub
*/
- (id)copyWithZone:(NSZone*)zone {
    CLPlacemark* newPlacemark = [[[self class] allocWithZone:zone] init];
    if (newPlacemark) {
        newPlacemark->_location = _location;
        newPlacemark->_name = [_name copyWithZone:zone];
        newPlacemark->_addressDictionary = [_addressDictionary copyWithZone:zone];
        newPlacemark->_ISOcountryCode = [_ISOcountryCode copyWithZone:zone];
        newPlacemark->_country = [_country copyWithZone:zone];
        newPlacemark->_postalCode = [_postalCode copyWithZone:zone];
        newPlacemark->_administrativeArea = [_administrativeArea copyWithZone:zone];
        newPlacemark->_subAdministrativeArea = [_subAdministrativeArea copyWithZone:zone];
        newPlacemark->_locality = [_locality copyWithZone:zone];
        newPlacemark->_subLocality = [_subLocality copyWithZone:zone];
        newPlacemark->_thoroughfare = [_thoroughfare copyWithZone:zone];
        newPlacemark->_subThoroughfare = [_subThoroughfare copyWithZone:zone];
        newPlacemark->_region = _region;
        newPlacemark->_timeZone = [_timeZone copyWithZone:zone];
        newPlacemark->_inlandWater = [_inlandWater copyWithZone:zone];
        newPlacemark->_ocean = [_ocean copyWithZone:zone];
        newPlacemark->_areasOfInterest = [_areasOfInterest copyWithZone:zone];
    }

    return newPlacemark;
}

/**
 @Status Stub
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

@end
