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
#import <NSDateInternal.h>
#import <CoreLocation/CLLocationManager.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
typedef wchar_t WCHAR;
#import <UWP/WindowsDevicesGeolocation.h>

/**
 * CLLocationManager class extension.
 */
@interface CLLocationManager () {
    NSThread* _callerThread;
    WDGGeolocator* _uwpGeolocator;
    EventRegistrationToken _uwpStatusToken;
    EventRegistrationToken _uwpPeriodicPositionChangeToken;
    // Ensures one ongoing call to request location authorization.
    BOOL _authorizing;
    BOOL _statusUpdateRequested;
    // Ensures atleast one ongoing periodic location update request.
    BOOL _periodicLocationUpdateRequested;
}

@property (readwrite, nonatomic, retain) CLLocation* location;
@end

/**
 * CLLocationManager main implementation.
 */
@implementation CLLocationManager

static const NSString* c_CLLocationManagerErrorDomain = @"CLLocationManager";
static CLAuthorizationStatus g_authorizationStatus = kCLAuthorizationStatusNotDetermined;
static const int64_t c_maximumAgeInSeconds = 1LL;
static const int64_t c_timeoutInSeconds = 15LL;

/**
 * [setDesiredAccuracy: description]
 * @param {CLLocationAccuracy} accuracy the accuracy of the location data in meters.
 */
- (void)setDesiredAccuracy:(CLLocationAccuracy)accuracy {
    _desiredAccuracy = accuracy;
    // TODO::
    // bug-nithish-110602015 - 5381942: Nullable UInt32 (IReference<UInt32> in C++) does not work over ObjC projection.
    // For now use desiredAccuracy until the bug is fixed.
    //_uwpGeolocator.desiredAccuracyInMeters = [NSNumber numberWithUnsignedInt:accuracy];
    if (accuracy > 10) {
        _uwpGeolocator.desiredAccuracy = WDGPositionAccuracyDefault;
    } else {
        _uwpGeolocator.desiredAccuracy = WDGPositionAccuracyHigh;
    }

    DLog(@"desiredAccuracyInMeters set to %f ", accuracy);
}

/**
 * Setter method for distanceFilter property.
 * @param {CLLocationDistance} the minimum distance (measured in meters) a device must move horizontally before an update event is
 * generated.
 */
- (void)setDistanceFilter:(CLLocationDistance)filter {
    _distanceFilter = filter;
    _uwpGeolocator.movementThreshold = filter;
    DLog(@"movementThreshold set to %f", filter);
}

/**
 * Getter method for locationServicesEnabled property.
 * @return {BOOL} indicates whether location services are enabled on the device.
 */
- (BOOL)locationServicesEnabled {
    return (g_authorizationStatus == kCLAuthorizationStatusAuthorized) ? YES : NO;
}

/**
 * Delivers authorization status to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_callauthorizationStatusDelegate {
    if ([self.delegate respondsToSelector:@selector(locationManager:didChangeAuthorizationStatus:)]) {
        [self.delegate locationManager:self didChangeAuthorizationStatus:g_authorizationStatus];
    }
    @synchronized(self) {
        _authorizing = NO;
    }
}

/**
 * Delivers location to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_callUpdateLocationsDelegate {
    NSArray* locationArray = [[NSArray alloc] initWithObjects:_location, nil];

    if ([self.delegate respondsToSelector:@selector(locationManager:didUpdateLocations:)]) {
        [self.delegate locationManager:self didUpdateLocations:locationArray];
    }

    [locationArray release];
}

/**
 * Delivers location errors to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 *
 *  Note: This method assumed caller has retained the NSError object before calling.
 */
- (void)_callLocationFailedDelegate:(NSError*)error {
    if ([self.delegate respondsToSelector:@selector(locationManager:didFailWithError:)]) {
        [self.delegate locationManager:self didFailWithError:error];
    }

    [error release];
}

- (void)_handleAuthorizationStateChange {
    [self performSelector:@selector(_callauthorizationStatusDelegate) onThread:_callerThread withObject:nil waitUntilDone:NO];
}

/**
 * Requests location access authorization from the user. This method will pop up an UI the first time it gets called after app install.
 */
- (void)_requestLocationAuthorization {
    @synchronized(self) {
        if (_authorizing == YES) {
            return;
        }

        _authorizing = YES;

        // Simply return without delivering status if the authorization status is already known (i.e it is not
        // kCLAuthorizationStatusNotDetermined).
        if (g_authorizationStatus != kCLAuthorizationStatusNotDetermined) {
            _authorizing = NO;
            return;
        }

        void (^accessSucess)(WDGGeolocationAccessStatus status);
        void (^accessFailure)(NSError* error);

        accessSucess = ^void(WDGGeolocationAccessStatus status) {
            @synchronized(self) {
                switch (status) {
                    case WDGGeolocationAccessStatusUnspecified:
                        g_authorizationStatus = kCLAuthorizationStatusNotDetermined;
                        break;
                    case WDGGeolocationAccessStatusAllowed:
                        g_authorizationStatus = kCLAuthorizationStatusAuthorized;
                        break;
                    case WDGGeolocationAccessStatusDenied:
                        g_authorizationStatus = kCLAuthorizationStatusDenied;
                        break;
                    default:
                        VLog(@"CLLocationManager: Unexpected location authorization status %d: ", status);
                        g_authorizationStatus = kCLAuthorizationStatusDenied;
                }

                // Register for status change events from Windows.
                // We do not do this in init because this can pop up an UI and we do not want that to happen until the app has requested
                // for authorization.
                if (!_statusUpdateRequested) {
                    _uwpStatusToken =
                        [_uwpGeolocator addStatusChangedEvent:^void(WDGGeolocator* geolocator, WDGStatusChangedEventArgs* event) {
                            [self _handleStatusChangedEvent:geolocator statusEvent:event];
                        }];
                    _statusUpdateRequested = YES;
                }
            }

            // Deliver status to location manager'a authorixation delegate.
            [self _handleAuthorizationStateChange];

            // Deliver access denied error to location manager's location delegate.
            if (g_authorizationStatus == kCLAuthorizationStatusDenied) {
                [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                     code:kCLErrorDenied
                                                                 userInfo:nil]];
            }

        };

        accessFailure = ^void(NSError* error) {
            VLog(@"Location authorization error: %@", error);
            // TODO: switch to failfast call.
            assert(!"Unexpected failure while authorizing location.");
        };

        [WDGGeolocator requestAccessAsyncWithSuccess:accessSucess failure:accessFailure];
    }
}

/**
 * Handles geolocator's state change events.
 * @param {WDGGeolocator*} geolocator geolocator instance.
 * @param {WDGStatusChangedEventArgs*} event StatusChangedEventArgs  received from Windows.
 */
- (void)_handleStatusChangedEvent:(WDGGeolocator*)geolocator statusEvent:(WDGStatusChangedEventArgs*)event {
    @synchronized(self) {
        DLog(@"Received status change event.");
        CLAuthorizationStatus authorizationStatus = g_authorizationStatus;
        BOOL positionStatusNoData = NO;
        switch (event.status) {
            case WDGPositionStatusDisabled:
                DLog(@"Received status change event with status denied (%d).", event.status);
                authorizationStatus = kCLAuthorizationStatusDenied;
                break;
            case WDGPositionStatusNoData:
                DLog(@"Received status change event with status no-data (%d).", event.status);
                positionStatusNoData = YES;
                break;
            default:
                // For all other status events WDGPositionStatusReady, WDGPositionStatusInitializing, WDGPositionStatusNotAvailable and
                // WDGPositionStatusNotInitialized.
                DLog(@"Received status change event with status %d.", event.status);
                authorizationStatus = kCLAuthorizationStatusAuthorized;
        }

        if (authorizationStatus != g_authorizationStatus) {
            g_authorizationStatus = authorizationStatus;
            // Deliver status to location manager delegates
            [self _handleAuthorizationStateChange];
            [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                 code:kCLErrorDenied
                                                             userInfo:nil]];
        }

        if (positionStatusNoData == YES) {
            [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                 code:kCLErrorLocationUnknown
                                                             userInfo:nil]];
        }
    }
}

/**
 * Handles geolocator's position change events.
 * @param {WDGGeolocator*} geolocator geolocator instance.
 * @param {WDGPositionChangedEventArgs*} event PositionChangedEventArgs received from Windows.
 */
- (void)_handlePositionChangedEvent:(WDGGeolocator*)geolocator statusEvent:(WDGPositionChangedEventArgs*)event {
    DLog(@"Received position changed event.");
    [self _handleLocationUpdate:event.position];
}

/**
 * Handles location change updates.
 * @param {WDGGeoposition*} geoposition updated location values received from Windows.
 */
- (void)_handleLocationUpdate:(WDGGeoposition*)geoposition {
    @synchronized(self) {
        WDGGeocoordinate* geocoordinator = geoposition.coordinate;
        CLLocationCoordinate2D coordinate = { geocoordinator.latitude, geocoordinator.longitude };

        // TODO::
        // todo-nithishm-11062015 -
        //     1. Bug 5381942 prevents us from fetching the speed value from IReference<double>. Harcoding for now as a workaround.
        //     2. How to obtain course?
        //
        self.location =
            [[[CLLocation alloc] initWithCoordinate:coordinate
                                           altitude:[geocoordinator.altitude doubleValue]
                                 horizontalAccuracy:geocoordinator.accuracy
                                   verticalAccuracy:[geocoordinator.altitudeAccuracy doubleValue]
                                             course:0
                                              speed:0
                                          timestamp:[NSDate _dateWithWindowsGPSTime:geocoordinator.timestamp.universalTime]] autorelease];

        // Deliver location to the location manager delegate
        [self performSelector:@selector(_callUpdateLocationsDelegate) onThread:_callerThread withObject:nil waitUntilDone:NO];
    }
}

/**
 * Handles errors related with location updates.
 * @param {NSError*} error location update error received from Windows.
 */
- (void)_handleLocationUpdateError:(NSError*)error {
    // Deliver location update failure to the location manager delegate.
    // Note: We retain the NSError object before calling performSelector:onThread: as the method does not guarentee retaining it.
    [self performSelector:@selector(_callLocationFailedDelegate:) onThread:_callerThread withObject:[error retain] waitUntilDone:NO];
}

/**
 * Helper method to call Windows GetGeopositionAsync to get location updates.
 */
- (void)_getGeopositionAsync {
    void (^onSucess)(WDGGeoposition* position);
    void (^onFailure)(NSError* error);

    onSucess = ^void(WDGGeoposition* position) {
        VLog(@"Get geoposition update succeeded.");
        // We purposely do not update the location from here as we already have a PositionChange event registered in this code path and
        // updating the location from here would just be a duplicate.
    };

    onFailure = ^void(NSError* error) {
        VLog(@"Get geoposition update failed with error: %@(%d)", error, [error code]);
        [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                             code:kCLErrorNetwork
                                                         userInfo:nil]];
    };

    [_uwpGeolocator getGeopositionAsyncWithSuccess:onSucess failure:onFailure];
}

/**
 * Helper method to call Windows GetGeopositionAsync with ages and timeout in seconds to get location.
 * Hardcoding maximum acceptable age of cached location data to 1 second and timeout value to 15 seconds.
 */
- (void)_getGeopositionAsyncWithAgeAndTimeout {
    void (^onSucess)(WDGGeoposition* position);
    void (^onFailure)(NSError* error);

    onSucess = ^void(WDGGeoposition* position) {
        VLog(@"Get single geoposition update succeeded.");
        [self _handleLocationUpdate:position];
    };

    onFailure = ^void(NSError* error) {
        VLog(@"Get single geoposition update failed with error: %@(%d)", error, [error code]);
        [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                             code:kCLErrorNetwork
                                                         userInfo:nil]];
    };

    WFTimeSpan* maximumAge = [WFTimeSpan new];
    maximumAge.duration = c_maximumAgeInSeconds * 1000LL * 10000LL;
    WFTimeSpan* timeout = [WFTimeSpan new];
    timeout.duration = c_timeoutInSeconds * 1000LL * 10000LL;

    [_uwpGeolocator getGeopositionAsyncWithAgeAndTimeout:maximumAge timeout:timeout success:onSucess failure:onFailure];

    [maximumAge release];
    [timeout release];
}

/**
 @Status Interoperable
*/
- (void)requestWhenInUseAuthorization {
    [self performSelectorOnMainThread:@selector(_requestLocationAuthorization) withObject:nil waitUntilDone:NO];
}

/**
 @Status Caveat
*/
- (void)requestAlwaysAuthorization {
    // No differentiation is made for background location authorization. Thus this function calls through to requestWhenInUseAuthorization.
    [self requestWhenInUseAuthorization];
}

/**
 @Status Interoperable
*/
+ (CLAuthorizationStatus)authorizationStatus {
    return g_authorizationStatus;
}

/**
 @Status Interoperable
*/
+ (BOOL)deferredLocationUpdatesAvailable {
    return NO;
}

/**
 @Status Interoperable
*/
+ (BOOL)significantLocationChangeMonitoringAvailable {
    return NO;
}

/**
 @Status Interoperable
*/
+ (BOOL)headingAvailable {
    return NO;
}

/**
 @Status Interoperable
*/
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass {
    return NO;
}

/**
 @Status Interoperable
*/
+ (BOOL)isRangingAvailable {
    return NO;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _authorizing = NO;
        _statusUpdateRequested = NO;
        _periodicLocationUpdateRequested = NO;
        _location = nullptr;
        // Cache the caller's thread object to use it to call delegates on.
        _callerThread = [NSThread currentThread];
        _uwpGeolocator = [WDGGeolocator create];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // Note: We do not have to synchronize here as no other method will be called in parallel at this time.
    if (_periodicLocationUpdateRequested) {
        [_uwpGeolocator removePositionChangedEvent:_uwpPeriodicPositionChangeToken];
        _periodicLocationUpdateRequested = NO;
    }
    if (_statusUpdateRequested) {
        [_uwpGeolocator removeStatusChangedEvent:_uwpStatusToken];
        _statusUpdateRequested = NO;
    }
    [_uwpGeolocator release];
    _uwpGeolocator = NULL;

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)startUpdatingLocation {
    @synchronized(self) {
        if (!_periodicLocationUpdateRequested) {
            // Register for position change event only the first time location update is requested.
            _uwpPeriodicPositionChangeToken =
                [_uwpGeolocator addPositionChangedEvent:^void(WDGGeolocator* geolocator, WDGPositionChangedEventArgs* event) {
                    [self _handlePositionChangedEvent:geolocator statusEvent:event];
                }];
            _periodicLocationUpdateRequested = YES;
        }

        [self performSelectorOnMainThread:@selector(_getGeopositionAsync) withObject:nil waitUntilDone:NO];
    }
}

/**
 @Status Interoperable
*/
- (void)stopUpdatingLocation {
    @synchronized(self) {
        if (_periodicLocationUpdateRequested) {
            [_uwpGeolocator removePositionChangedEvent:_uwpPeriodicPositionChangeToken];
            _periodicLocationUpdateRequested = NO;
        }
    }
}

/**
@Status Stub
*/
- (void)requestLocation {
    [self performSelectorOnMainThread:@selector(_getGeopositionAsyncWithAgeAndTimeout) withObject:nil waitUntilDone:NO];
}

/**
@Status Stub
*/
- (void)allowDeferredLocationUpdatesUntilTraveled:(CLLocationDistance)distance timeout:(NSTimeInterval)timeout {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (void)disallowDeferredLocationUpdates {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"[CLLocationManager] Purpose: %@, isLocationServicesEnabled: %@, periodicUpdateRequested: %@, "
                                      @"desiredAccuracy: %fm, distanceFilter: %fm, activityType: %d, lastLocation: %@",
                                      self.purpose,
                                      (self.locationServicesEnabled) ? @"YES" : @"NO",
                                      (_periodicLocationUpdateRequested) ? @"YES" : @"NO",
                                      self.desiredAccuracy,
                                      self.distanceFilter,
                                      self.activityType,
                                      self.location];
}

@end
