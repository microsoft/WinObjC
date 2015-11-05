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

#import <Foundation/Foundation.h>
#import <StarboardExport.h>
#import <stdint.h>

enum _CLError {
    kCLErrorLocationUnknown = 0, 
    kCLErrorDenied = 1
};
typedef uint32_t CLError;

typedef double CLLocationAccuracy;
typedef double CLLocationDegrees;
typedef double CLLocationDistance;
typedef double CLLocationSpeed;
typedef double CLLocationDirection;

typedef struct {
    CLLocationDegrees latitude;
    CLLocationDegrees longitude;
} CLLocationCoordinate2D;

SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyHundredMeters;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyKilometer;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyThreeKilometers;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyBestForNavigation;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyBest;
SB_EXPORT const CLLocationDistance kCLDistanceFilterNone;

SB_EXPORT const CLLocationCoordinate2D kCLLocationCoordinate2DInvalid;
SB_EXPORT const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;

SB_EXPORT CLLocationCoordinate2D CLLocationCoordinate2DMake(CLLocationDegrees latitude, CLLocationDegrees longitude);

@interface CLLocation : NSObject

@property(readonly, nonatomic) CLLocationCoordinate2D coordinate;
@property(readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;
@property(readonly, nonatomic) CLLocationAccuracy verticalAccuracy;
@property(readonly, nonatomic) CLLocationDistance altitude;

-(CLLocationDistance)distanceFromLocation:(const CLLocation *)location;
-(CLLocationDistance)getDistanceFrom:(const CLLocation *)location;
- (id)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;

@end

BOOL CLLocationCoordinate2DIsValid(CLLocationCoordinate2D coordinate);
