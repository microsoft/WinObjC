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
#import <CoreLocation/CLLocationManager.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
typedef wchar_t WCHAR;
#import <UWP/WindowsDevicesGeolocation.h>

// TODO::
// todo-nithishm-11022015 - Incomplete implementation.

@implementation CLLocationManager : NSObject

/**
@Status Stub
*/
- (void)requestWhenInUseAuthorization {
}

/**
@Status Stub
*/
- (void)requestAlwaysAuthorization {
}

/**
@Status Stub
*/
+ (CLAuthorizationStatus)authorizationStatus {
    return kCLAuthorizationStatusNotDetermined;
}

/**
@Status Stub
*/
+ (BOOL)locationServicesEnabled {
    return false;
}

/**
@Status Stub
*/
+ (BOOL)deferredLocationUpdatesAvailable {
    return false;
}

/**
@Status Stub
*/
+ (BOOL)significantLocationChangeMonitoringAvailable {
    return false;
}

/**
@Status Stub
*/
+ (BOOL)headingAvailable {
    return false;
}

/**
@Status Stub
*/
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass {
    return false;
}

/**
@Status Stub
*/
+ (BOOL)isRangingAvailable {
    return false;
}

/**
@Status Stub
*/
- (instancetype)init {
    if (self = [super init]) {
        // Perform class-specific init here.
    }

    return self;
}

/**
@Status Stub
*/
- (void)dealloc {
    // Perform class-specific dealloc here.
    [super dealloc];
}

/**
@Status Stub
*/
- (void)startUpdatingLocation {
}

/**
@Status Stub
*/
- (void)stopUpdatingLocation {
}

/**
@Status Stub
*/
- (void)requestLocation {
}

/**
@Status Stub
*/
- (void)allowDeferredLocationUpdatesUntilTraveled:(CLLocationDistance)distance timeout:(NSTimeInterval)timeout {
}

/**
@Status Stub
*/
- (void)disallowDeferredLocationUpdates {
}

@end