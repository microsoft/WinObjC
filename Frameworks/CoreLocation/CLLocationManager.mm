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

#import <StubReturn.h>
#import <Starboard.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLLocationManager.h>
#import <CoreLocation/CLLocationManagerDelegate.h>
#import "NSLogging.h"
#import <UWP/WindowsDevicesGeolocation.h>
#import <UWP/WindowsApplicationModelExtendedExecution.h>
#import <limits>
#import <mutex>

const CLLocationDistance CLLocationDistanceMax = std::numeric_limits<double>::max();
const NSTimeInterval CLTimeIntervalMax = std::numeric_limits<double>::max();

static const wchar_t* TAG = L"CLLocationManager";

static std::mutex s_extendedExecutionMutex;
static WAEExtendedExecutionSession* s_uwpExecutionSession;
static EventRegistrationToken s_uwpEventRegistrationToken;
static uint32_t s_extendedExecutionRequestCount;

/**
 * Helper method to request for an extended execution asynchronously.
 */
static void _requestExtendedExecutionAsync() {
    void (^onSucess)(WAEExtendedExecutionResult result);
    void (^onFailure)(NSError* error);

    onSucess = ^void(WAEExtendedExecutionResult result) {
        if (result == WAEExtendedExecutionResultAllowed) {
            NSTraceInfo(TAG, @"Requesting extended execution succeeded.");
        } else {
            NSTraceError(TAG, @"Requesting extended execution failed with result %ld!", result);
        }
    };

    onFailure = ^void(NSError* error) {
        NSTraceError(TAG, @"Requesting extended execution failed with error: %@(%d)", error, [error code]);
    };

    [s_uwpExecutionSession requestExtensionAsyncWithSuccess:onSucess failure:onFailure];
}

/**
 * Helper method to handle the revoked event from extended execution.
 * @param {WAEExtendedExecutionRevokedReason} Extended execution revoked reason.
 */
static void _handleExtendedExecutionRevokedEvent(WAEExtendedExecutionRevokedReason reason) {
    std::lock_guard<std::mutex> lock(s_extendedExecutionMutex);
    NSTraceInfo(TAG, @"Requesting extended execution revoked with reason %ld!", reason);
    if (s_extendedExecutionRequestCount != 0) {
        // Request back again for extended execution.
        // WAEExtendedExecutionRevokedReasonResumed will happen everytime the app is resumed to the foreground during an active
        // execution sessions. Only log a warning when the revoke reason is not WAEExtendedExecutionRevokedReasonResumed.
        if (reason != WAEExtendedExecutionRevokedReasonResumed) {
            NSTraceWarning(TAG, @"Requesting extended execution revoked when request count was %ld!", s_extendedExecutionRequestCount);
        }
        _requestExtendedExecutionAsync();
    }
}

/**
 * Helper method to create an extended executions session and request for extended execution.
 */
static void _requestExtendedExecutionSession() {
    std::lock_guard<std::mutex> lock(s_extendedExecutionMutex);
    // Only request for an extended execution session if it is does not already exist.
    if (++s_extendedExecutionRequestCount == 1) {
        NSTraceInfo(TAG, @"Requesting extended execution.");
        s_uwpExecutionSession = [WAEExtendedExecutionSession make];
        s_uwpExecutionSession.reason = WAEExtendedExecutionReasonLocationTracking;
        s_uwpExecutionSession.Description = @"CoreLocation Periodic Location Update request";
        s_uwpEventRegistrationToken =
            [s_uwpExecutionSession addRevokedEvent:^void(RTObject* obj, WAEExtendedExecutionRevokedEventArgs* args) {
                _handleExtendedExecutionRevokedEvent(args.reason);
            }];
        _requestExtendedExecutionAsync();
    }
}

/**
 * Helper method to remove extended execution session.
 */
static void _removeExtendedExecutionSession() {
    std::lock_guard<std::mutex> lock(s_extendedExecutionMutex);
    // Remove the extended execution session only when there are no more pending requests.
    FAIL_FAST_IF_MSG(E_UNEXPECTED, (s_extendedExecutionRequestCount == 0), "There is no extended execution session active!");
    if (--s_extendedExecutionRequestCount == 0) {
        NSTraceInfo(TAG, @"Removing extended execution.");
        [s_uwpExecutionSession removeRevokedEvent:s_uwpEventRegistrationToken];
        [s_uwpExecutionSession close];
        s_uwpExecutionSession = nullptr;
    }
}

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
    BOOL _extendedExecutionSessionRequested;
}

@property (readwrite, copy, nonatomic) CLLocation* location;
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

    NSTraceVerbose(TAG, @"desiredAccuracyInMeters set to %f ", accuracy);
}

/**
 * Setter method for distanceFilter property.
 * @param {CLLocationDistance} the minimum distance (measured in meters) a device must move horizontally before an update event is
 * generated.
 */
- (void)setDistanceFilter:(CLLocationDistance)filter {
    _distanceFilter = filter;
    _uwpGeolocator.movementThreshold = filter;
    NSTraceVerbose(TAG, @"movementThreshold set to %f", filter);
}

/**
 * Getter method for (deprecated) locationServicesEnabled property.
 * @return {BOOL} indicates whether location services are enabled on the device.
 */
- (BOOL)locationServicesEnabled {
    return (g_authorizationStatus == kCLAuthorizationStatusAuthorized) ? YES : NO;
}

/**
 @Status Interoperable
 @return {BOOL} indicates whether location services are enabled on the device.
*/
+ (BOOL)locationServicesEnabled {
    return (g_authorizationStatus == kCLAuthorizationStatusAuthorized) ? YES : NO;
}

/**
 * Delivers authorization status to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_callauthorizationStatusDelegate {
    assert([[NSThread currentThread] isEqual:_callerThread]);
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
    assert([[NSThread currentThread] isEqual:_callerThread]);
    NSArray* locationArray = [[NSArray alloc] initWithObjects:_location, nil];

    if ([self.delegate respondsToSelector:@selector(locationManager:didUpdateLocations:)]) {
        [self.delegate locationManager:self didUpdateLocations:locationArray];
    }
}

/**
 * Delivers location update to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_didUpdateToLocationsDelegate:(CLLocation*)previousLocation {
    assert([[NSThread currentThread] isEqual:_callerThread]);
    if ([self.delegate respondsToSelector:@selector(locationManager:didUpdateToLocation:fromLocation:)]) {
        [self.delegate locationManager:self didUpdateToLocation:self.location fromLocation:previousLocation];
    }
}

/**
 * Delivers location errors to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_callLocationFailedDelegate:(NSError*)error {
    assert([[NSThread currentThread] isEqual:_callerThread]);
    if ([self.delegate respondsToSelector:@selector(locationManager:didFailWithError:)]) {
        [self.delegate locationManager:self didFailWithError:error];
    }
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
                        NSTraceInfo(TAG, @"CLLocationManager: Unexpected location authorization status %d: ", status);
                        g_authorizationStatus = kCLAuthorizationStatusDenied;
                }

                // Register for status change events from Windows.
                // We do not do this in init because this can pop up an UI and we do not want that to happen until the app has requested
                // for authorization.
                __weak CLLocationManager* weakSelf = self;
                if (!_statusUpdateRequested) {
                    _uwpStatusToken =
                        [_uwpGeolocator addStatusChangedEvent:^void(WDGGeolocator* geolocator, WDGStatusChangedEventArgs* event) {
                            [weakSelf _handleStatusChangedEvent:geolocator statusEvent:event];
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
            NSTraceInfo(TAG, @"Location authorization error: %@", error);
            FAIL_FAST_MSG(E_UNEXPECTED, "Unexpected failure while authorizing location.");
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
        NSTraceVerbose(TAG, @"Received status change event.");
        CLAuthorizationStatus authorizationStatus = g_authorizationStatus;
        BOOL positionStatusNoData = NO;
        switch (event.status) {
            case WDGPositionStatusDisabled:
                NSTraceVerbose(TAG, @"Received status change event with status denied (%d).", event.status);
                authorizationStatus = kCLAuthorizationStatusDenied;
                break;
            case WDGPositionStatusNoData:
                NSTraceVerbose(TAG, @"Received status change event with status no-data (%d).", event.status);
                positionStatusNoData = YES;
                break;
            default:
                // For all other status events WDGPositionStatusReady, WDGPositionStatusInitializing, WDGPositionStatusNotAvailable and
                // WDGPositionStatusNotInitialized.
                NSTraceVerbose(TAG, @"Received status change event with status %d.", event.status);
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
    NSTraceVerbose(TAG, @"Received position changed event.");
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

        CLLocation* previousLocation = self.location;

        // Number of seconds between Jan 1, 1601 UTC (Windows FILETIME) and Jan 1, 1970 UTC (POSIX/Epoch time)
        static const int64_t c_windowsToUnixNumSecondsOffset = 11644473600LL;
        // Ratio between 100ns (Windows FILETIME unit) and 1s (POSIX/Epoch time unit)
        static const int64_t c_windowsToUnixTimeUnitRatio = 10000LL;

        // First convert Windows Gps epoch to Unix epoch.
        // Note: this corrects for the 10 year base time difference between gps epoch (1980) and  posix epoch (1970)
        int64_t posixEpoch =
            (geocoordinator.timestamp.universalTime / c_windowsToUnixTimeUnitRatio) - c_windowsToUnixNumSecondsOffset * 1000LL;

        // TODO::
        // todo-nithishm-11062015 -
        //     1. Bug 5381942 prevents us from fetching the speed value from IReference<double>. Harcoding for now as a workaround.
        //     2. How to obtain course?
        //
        self.location = [[CLLocation alloc] initWithCoordinate:coordinate
                                                      altitude:[geocoordinator.altitude doubleValue]
                                            horizontalAccuracy:geocoordinator.accuracy
                                              verticalAccuracy:[geocoordinator.altitudeAccuracy doubleValue]
                                                        course:0
                                                         speed:0
                                                     timestamp:[NSDate dateWithTimeIntervalSince1970:(double)posixEpoch]];

        // Deliver location to the appropriate location manager delegate
        if (_periodicLocationUpdateRequested) {
            if (![self.location isEqual:previousLocation]) {
                [self performSelector:@selector(_didUpdateToLocationsDelegate:)
                             onThread:_callerThread
                           withObject:previousLocation
                        waitUntilDone:NO];
            }
        } else {
            [self performSelector:@selector(_callUpdateLocationsDelegate) onThread:_callerThread withObject:nil waitUntilDone:NO];
        }
    }
}

/**
 * Handles errors related with location updates.
 * @param {NSError*} error location update error received from Windows.
 */
- (void)_handleLocationUpdateError:(NSError*)error {
    // Deliver location update failure to the location manager delegate.
    [self performSelector:@selector(_callLocationFailedDelegate:) onThread:_callerThread withObject:error waitUntilDone:NO];
}

/**
 * Helper method to call Windows GetGeopositionAsync to get location updates.
 */
- (void)_getGeopositionAsync {
    void (^onSucess)(WDGGeoposition* position);
    void (^onFailure)(NSError* error);

    onSucess = ^void(WDGGeoposition* position) {
        NSTraceInfo(TAG, @"Get geoposition update succeeded.");
        // We purposely do not update the location from here as we already have a PositionChange event registered in this code path and
        // updating the location from here would just be a duplicate.
    };

    onFailure = ^void(NSError* error) {
        NSTraceInfo(TAG, @"Get geoposition update failed with error: %@(%d)", error, [error code]);
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
        NSTraceInfo(TAG, @"Get single geoposition update succeeded.");
        [self _handleLocationUpdate:position];
    };

    onFailure = ^void(NSError* error) {
        NSTraceInfo(TAG, @"Get single geoposition update failed with error: %@(%d)", error, [error code]);
        [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                             code:kCLErrorNetwork
                                                         userInfo:nil]];
    };

    WFTimeSpan* maximumAge = [WFTimeSpan new];
    maximumAge.duration = c_maximumAgeInSeconds * 1000LL * 10000LL;
    WFTimeSpan* timeout = [WFTimeSpan new];
    timeout.duration = c_timeoutInSeconds * 1000LL * 10000LL;

    [_uwpGeolocator getGeopositionAsyncWithAgeAndTimeout:maximumAge timeout:timeout success:onSucess failure:onFailure];
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
    // No differentiation is made for background location authorization. Thus this function calls through to
    // requestWhenInUseAuthorization.
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
        // Initialize WDGGeolocator.
        _uwpGeolocator = [WDGGeolocator make];
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
    if (_extendedExecutionSessionRequested) {
        _removeExtendedExecutionSession();
        _extendedExecutionSessionRequested = NO;
    }
    if (_statusUpdateRequested) {
        [_uwpGeolocator removeStatusChangedEvent:_uwpStatusToken];
        _statusUpdateRequested = NO;
    }
    _uwpGeolocator = nullptr;
}

/**
 @Status Interoperable
*/
- (void)startUpdatingLocation {
    @synchronized(self) {
        if (!_periodicLocationUpdateRequested) {
            NSTraceInfo(TAG, @"Started periodic location update");

            if (self.allowsBackgroundLocationUpdates) {
                // Request for a extended execution session so location updates can continue in the background.
                _requestExtendedExecutionSession();
                _extendedExecutionSessionRequested = YES;
            }

            // Register for position change event only the first time location update is requested.
            __weak CLLocationManager* weakSelf = self;
            _uwpPeriodicPositionChangeToken =
                [_uwpGeolocator addPositionChangedEvent:^void(WDGGeolocator* geolocator, WDGPositionChangedEventArgs* event) {
                    [weakSelf _handlePositionChangedEvent:geolocator statusEvent:event];
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
            NSTraceInfo(TAG, @"Stopped periodic location update");
            [_uwpGeolocator removePositionChangedEvent:_uwpPeriodicPositionChangeToken];
            if (_extendedExecutionSessionRequested) {
                _removeExtendedExecutionSession();
                _extendedExecutionSessionRequested = NO;
            }
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

/**
 @Status Stub
*/
- (void)startMonitoringSignificantLocationChanges {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)stopMonitoringSignificantLocationChanges {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)startUpdatingHeading {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)stopUpdatingHeading {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)dismissHeadingCalibrationDisplay {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)startMonitoringForRegion:(CLRegion*)region {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)startMonitoringForRegion:(CLRegion*)region desiredAccuracy:(CLLocationAccuracy)accuracy {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)stopMonitoringForRegion:(CLRegion*)region {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)startRangingBeaconsInRegion:(CLBeaconRegion*)region {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)stopRangingBeaconsInRegion:(CLBeaconRegion*)region {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)requestStateForRegion:(CLRegion*)region {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)startMonitoringVisits {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)stopMonitoringVisits {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
+ (BOOL)regionMonitoringAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (BOOL)regionMonitoringEnabled {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
