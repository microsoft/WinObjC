//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Starboard.h>
#import <CoreLocation/CLLocation.h>

const CLLocationAccuracy kCLLocationAccuracyHundredMeters = 100;
const CLLocationAccuracy kCLLocationAccuracyKilometer = 1000;
const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters = 10;
const CLLocationAccuracy kCLLocationAccuracyThreeKilometers = 3000;
const CLLocationAccuracy kCLLocationAccuracyBestForNavigation = 1;
const CLLocationAccuracy kCLLocationAccuracyBest = 5;
const CLLocationDistance kCLDistanceFilterNone = 0;

/**
 * CLLocation class extension.
 */
@interface CLLocation () {
    volatile NSUInteger _hashCode;
}

@property (readwrite, nonatomic) CLLocationCoordinate2D coordinate;
@property (readwrite, nonatomic, assign) CLLocationDistance altitude;
// TODO::
// todo-nithishm-11022015 - Need to implement CLFloor.
// @property(readwrite, nonatomic, copy) CLFloor* floor;
@property (readwrite, nonatomic, assign) CLLocationAccuracy horizontalAccuracy;
@property (readwrite, nonatomic, assign) CLLocationAccuracy verticalAccuracy;
@property (readwrite, nonatomic, copy) NSDate* timestamp;
@property (readwrite, nonatomic, copy) NSString* description;
@property (readwrite, nonatomic, assign) CLLocationSpeed speed;
@property (readwrite, nonatomic, assign) CLLocationDirection course;
@end

/**
 * CLLocation main implementation.
 */
@implementation CLLocation

/**
 @Status Stub
*/
CORELOCATION_EXPORT BOOL CLLocationCoordinate2DIsValid(CLLocationCoordinate2D coordinate) {
    UNIMPLEMENTED();
    return FALSE;
}

/**
 @Status Stub
*/
- (CLLocationDistance)distanceFromLocation:(const CLLocation*)location {
    UNIMPLEMENTED();
    return (CLLocationDistance)0;
}

/**
 @Status Stub
*/
- (CLLocationDistance)getDistanceFrom:(const CLLocation*)location {
    UNIMPLEMENTED();
    return (CLLocationDistance)0;
}

/**
 @Status Interoperable
*/
- (id)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude {
    CLLocationCoordinate2D coordinate = { latitude, longitude };
    return [self initWithCoordinate:coordinate altitude:0 horizontalAccuracy:0 verticalAccuracy:0 course:0 speed:0 timestamp:nil];
}

/**
 @Status Interoperable
*/
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                altitude:(CLLocationDistance)altitude
      horizontalAccuracy:(CLLocationAccuracy)hAccuracy
        verticalAccuracy:(CLLocationAccuracy)vAccuracy
               timestamp:(NSDate*)timestamp {
    return [self initWithCoordinate:coordinate
                           altitude:altitude
                 horizontalAccuracy:hAccuracy
                   verticalAccuracy:vAccuracy
                             course:0
                              speed:0
                          timestamp:timestamp];
}

/**
 @Status Interoperable
*/
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                altitude:(CLLocationDistance)altitude
      horizontalAccuracy:(CLLocationAccuracy)hAccuracy
        verticalAccuracy:(CLLocationAccuracy)vAccuracy
                  course:(CLLocationDirection)course
                   speed:(CLLocationSpeed)speed
               timestamp:(NSDate*)timestamp {
    if (self = [super init]) {
        _coordinate = coordinate;
        _altitude = altitude;
        // TODO::
        // todo-nithishm-11022015 - Need to implement CLFloor.
        // _floor = 0;
        _horizontalAccuracy = hAccuracy;
        _verticalAccuracy = vAccuracy;
        _course = course;
        _speed = speed;
        _timestamp = [timestamp copy];
        _description = nil;
    }

    return self;
}

- (void)dealloc {
    if (_timestamp != nil) {
        [_timestamp release];
    }

    if (_description != nil) {
        [_description release];
    }

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (other == self) {
        return YES;
    }

    if ((!other) || (![other isKindOfClass:[self class]])) {
        return NO;
    }

    return [self isEqualToLocation:other];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToLocation:(CLLocation*)aLocation {
    if (self == aLocation) {
        return YES;
    }

    if (self.coordinate.longitude != aLocation.coordinate.longitude) {
        return NO;
    }
    if (self.coordinate.longitude != aLocation.coordinate.longitude) {
        return NO;
    }
    if (self.altitude != aLocation.altitude) {
        return NO;
    }
    // TODO::
    // todo-nithishm-11022015 - Need to implement CLFloor.
    // if (![[self floor] isEqual:[aLocation floor]]) {
    //     return NO;
    // }
    if (self.horizontalAccuracy != aLocation.horizontalAccuracy) {
        return NO;
    }
    if (self.verticalAccuracy != aLocation.verticalAccuracy) {
        return NO;
    }
    // Note: We do pointer comparison here before calling isEqual because timestamp can be nil.
    if ((self.timestamp != aLocation.timestamp) && (![self.timestamp isEqual:aLocation.timestamp])) {
        return NO;
    }
    if (![self.description isEqual:aLocation.description]) {
        return NO;
    }
    if (self.speed != aLocation.speed) {
        return NO;
    }
    if (self.course != aLocation.course) {
        return NO;
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    NSUInteger result = _hashCode;
    if (result == 0) {
        result = 17;
        result = 31 * result + self.coordinate.longitude;
        result = 31 * result + self.coordinate.latitude;
        result = 31 * result + self.altitude;
        // TODO::
        // todo-nithishm-11022015 - Need to implement CLFloor.
        // result = 31 * result + [self floor];
        result = 31 * result + self.horizontalAccuracy;
        result = 31 * result + self.verticalAccuracy;
        result = 31 * result + [self.timestamp hash];
        result = 31 * result + [self.description hash];
        result = 31 * result + self.speed;
        result = 31 * result + self.course;
        _hashCode = result;
    }

    return result;
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    // TODO::
    // todo-nithishm-11022015 - Need to log proper heading value.
    return [NSString stringWithFormat:@"<%f, %f> +/- %fm (speed %fkph / heading 0) @ <%@>",
                                      self.coordinate.latitude,
                                      self.coordinate.longitude,
                                      self.horizontalAccuracy,
                                      (self.speed * 3.6),
                                      self.timestamp];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    CLLocation* newLocation = [[[self class] allocWithZone:zone] init];
    if (newLocation) {
        newLocation->_coordinate = _coordinate;
        newLocation->_altitude = _altitude;
        // TODO::
        // todo-nithishm-11022015 - Need to implement CLFloor.
        // newLocation->_floor = _floor;
        newLocation->_horizontalAccuracy = _horizontalAccuracy;
        newLocation->_verticalAccuracy = _verticalAccuracy;
        newLocation->_timestamp = [_timestamp copyWithZone:zone];
        newLocation->_description = [_description copyWithZone:zone];
        newLocation->_speed = _speed;
        newLocation->_course = _course;
    }

    return newLocation;
}

@end
