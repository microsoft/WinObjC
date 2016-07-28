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

#import <StubReturn.h>
#import <CoreLocation/CLHeading.h>
#import <Foundation/Foundation.h>

@implementation CLHeading

- (instancetype)initWithAccuracy:(CLLocationDirection)accuracy
                 magneticHeading:(CLLocationDirection)magneticHeading
                     trueHeading:(CLLocationDirection)trueHeading {
    if (self = [super init]) {
        _headingAccuracy = accuracy;
        _magneticHeading = magneticHeading;
        _trueHeading = trueHeading;
        _timestamp = [NSDate date];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    CLHeading* newHeading = [[[self class] allocWithZone:zone] init];
    if (newHeading) {
        newHeading->_headingAccuracy = _headingAccuracy;
        newHeading->_magneticHeading = _magneticHeading;
        newHeading->_trueHeading = _trueHeading;
        newHeading->_timestamp = [_timestamp copyWithZone:zone];
    }

    return newHeading;
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
