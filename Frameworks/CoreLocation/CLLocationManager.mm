//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <limits>
#import <mutex>
#import <ctime>
#import <CoreLocation/CLHeading.h>
#import "CLHeadingInternal.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.Devices.Geolocation.h>
#import <winrt/Windows.Devices.Sensors.h>
#import <winrt/Windows.ApplicationModel.ExtendedExecution.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Devices::Geolocation;
using namespace winrt::Windows::Devices::Sensors;
using namespace winrt::Windows::ApplicationModel::ExtendedExecution;
namespace WF = winrt::Windows::Foundation;

const CLLocationDistance CLLocationDistanceMax = std::numeric_limits<double>::max();
const NSTimeInterval CLTimeIntervalMax = std::numeric_limits<double>::max();

static const wchar_t* TAG = L"CLLocationManager";

// Issue #2529: clang bug forces us to redeclare this from the C++/WinRT headers
constexpr winrt::clock::time_point winrt::clock::time_t_epoch;

static std::mutex s_extendedExecutionMutex;
static TrivialDefaultConstructor<ExtendedExecutionSession> s_uwpExecutionSession;
static winrt::event_token s_uwpEventRegistrationToken;
static uint32_t s_extendedExecutionRequestCount;

/**
 * Helper method to request for an extended execution asynchronously.
 */
static void _requestExtendedExecutionAsync() {
    WF::IAsyncOperation<ExtendedExecutionResult> async = s_uwpExecutionSession.RequestExtensionAsync();

    async.Completed(objcwinrt::callback([] (const WF::IAsyncOperation<ExtendedExecutionResult>& op, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            ExtendedExecutionResult result = op.GetResults();

            if (result == ExtendedExecutionResult::Allowed) {
                NSTraceInfo(TAG, @"Requesting extended execution succeeded.");
            } else {
                NSTraceError(TAG, @"Requesting extended execution failed with result %d!", result);
            }
        } else if (status == WF::AsyncStatus::Canceled) {
            NSTraceError(TAG, @"Extended execution request was canceled");
        } else {
            NSTraceError(TAG, @"Requesting extended execution failed with error %08lx", (unsigned long)op.ErrorCode());
        }
    }));
}

/**
 * Helper method to handle the revoked event from extended execution.
 * @param {WAEExtendedExecutionRevokedReason} reason: Extended execution revoked reason.
 */
static void _handleExtendedExecutionRevokedEvent(ExtendedExecutionRevokedReason reason) {
    std::lock_guard<std::mutex> lock(s_extendedExecutionMutex);
    NSTraceInfo(TAG, @"Requesting extended execution revoked with reason %lu!", (unsigned long)reason);
    if (s_extendedExecutionRequestCount != 0) {
        // Request back again for extended execution.
        // ExtendedExecutionRevokedReason::Resumed will happen everytime the app is resumed to the foreground during an active
        // execution sessions. Only log a warning when the revoke reason is not ExtendedExecutionRevokedReason::Resumed.
        if (reason != ExtendedExecutionRevokedReason::Resumed) {
            NSTraceWarning(TAG, @"Requesting extended execution revoked when request count was %lu!", (unsigned long)s_extendedExecutionRequestCount);
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
        s_uwpExecutionSession = ExtendedExecutionSession();
        s_uwpExecutionSession.Reason(ExtendedExecutionReason::LocationTracking);
        s_uwpExecutionSession.Description(L"CoreLocation Periodic Location Update request");
        s_uwpEventRegistrationToken =
            s_uwpExecutionSession.Revoked(objcwinrt::callback([] (const WF::IInspectable& obj, const ExtendedExecutionRevokedEventArgs& args) {
                _handleExtendedExecutionRevokedEvent(args.Reason());
            }));
        _requestExtendedExecutionAsync();
    }
}

/**
 * Helper method to remove extended execution session.
 */
static void _removeExtendedExecutionSession() {
    std::lock_guard<std::mutex> lock(s_extendedExecutionMutex);

    if (s_extendedExecutionRequestCount == 0) {
        return;
    }

    if (--s_extendedExecutionRequestCount == 0) {
        NSTraceInfo(TAG, @"Removing extended execution.");
        s_uwpExecutionSession.Revoked(s_uwpEventRegistrationToken);
        s_uwpExecutionSession.Close();
        s_uwpExecutionSession = nullptr;
    }
}

/**
 * CLLocationManager class extension.
 */
@interface CLLocationManager () {
    NSThread* _callerThread;
    TrivialDefaultConstructor<Geolocator> _uwpGeolocator;
    TrivialDefaultConstructor<Compass> _uwpCompass;
    winrt::event_token _uwpStatusToken;
    winrt::event_token _uwpPeriodicPositionChangeToken;
    winrt::event_token _uwpPeriodicHeadingChangeToken;
    // Ensures one ongoing call to request location authorization.
    BOOL _authorizing;
    BOOL _statusUpdateRequested;
    // Ensures atleast one ongoing periodic location update request.
    BOOL _periodicLocationUpdateRequested;
    BOOL _periodicHeadingUpdateRequested;
}

@property (readwrite, copy, nonatomic) CLLocation* location;
@property (readwrite, copy, nonatomic) CLHeading* heading;
@end

/**
 * CLLocationManager main implementation.
 */
@implementation CLLocationManager

@synthesize heading = _heading;

static const NSString* c_CLLocationManagerErrorDomain = @"CLLocationManager";
static CLAuthorizationStatus g_authorizationStatus = kCLAuthorizationStatusNotDetermined;
static const std::chrono::seconds c_maximumAgeInSeconds(1);
static const std::chrono::seconds c_timeoutInSeconds(15);

/**
 * [setDesiredAccuracy: description]
 * @param {CLLocationAccuracy} accuracy: the accuracy of the location data in meters.
 */
- (void)setDesiredAccuracy:(CLLocationAccuracy)accuracy {
    _desiredAccuracy = accuracy;
    _uwpGeolocator.DesiredAccuracyInMeters(objcwinrt::optional<unsigned int>(accuracy));

    NSTraceVerbose(TAG, @"desiredAccuracyInMeters set to %f ", accuracy);
}

/**
 * Setter method for distanceFilter property.
 * @param {CLLocationDistance} filter: the minimum distance (measured in meters) a device must move horizontally before an update event is
 * generated.
 */
- (void)setDistanceFilter:(CLLocationDistance)filter {
    _distanceFilter = filter;
    _uwpGeolocator.MovementThreshold(filter);
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
 * Delivers heading to the location manager delegate. This method needs to be called on the thread that was used to
 * initialize the location manager instance.
 */
- (void)_callUpdateHeadingsDelegate {
    assert([[NSThread currentThread] isEqual:_callerThread]);
    if ([self.delegate respondsToSelector:@selector(locationManager:didUpdateHeading:)]) {
        [self.delegate locationManager:self didUpdateHeading:self.heading];
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

        WF::IAsyncOperation<GeolocationAccessStatus> async = Geolocator::RequestAccessAsync();

        async.Completed(objcwinrt::callback([self] (const WF::IAsyncOperation<GeolocationAccessStatus>& op, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                @synchronized(self) {
                    GeolocationAccessStatus accessStatus = op.GetResults();

                    switch (accessStatus) {
                        case GeolocationAccessStatus::Unspecified:
                            g_authorizationStatus = kCLAuthorizationStatusNotDetermined;
                            break;
                        case GeolocationAccessStatus::Allowed:
                            g_authorizationStatus = kCLAuthorizationStatusAuthorized;
                            break;
                        case GeolocationAccessStatus::Denied:
                            g_authorizationStatus = kCLAuthorizationStatusDenied;
                            break;
                        default:
                            NSTraceInfo(TAG, @"CLLocationManager: Unexpected location authorization status %d", accessStatus);
                            g_authorizationStatus = kCLAuthorizationStatusDenied;
                    }

                    // Register for status change events from Windows.
                    // We do not do this in init because this can pop up an UI and we do not want that to happen until the app has requested
                    // for authorization.
                    __weak CLLocationManager* weakSelf = self;
                    if (!_statusUpdateRequested) {
                        _uwpStatusToken = _uwpGeolocator.StatusChanged(objcwinrt::callback([weakSelf] (const Geolocator& geolocator, const StatusChangedEventArgs& event) {
                            [weakSelf _handleStatusChangedEvent:geolocator statusEvent:event];
                        }));
                    }
                }

                // Deliver status to location manager's authorization delegate.
                [self _handleAuthorizationStateChange];

                // Deliver access denied error to location manager's location delegate.
                if (g_authorizationStatus == kCLAuthorizationStatusDenied) {
                    [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                         code:kCLErrorDenied
                                                                     userInfo:nil]];
                }
            } else {
                NSTraceInfo(TAG, @"Location authorization error: %08lx, status: %u", (unsigned long)op.ErrorCode(), (unsigned)status);
                FAIL_FAST_MSG("Unexpected failure while authorizing location.");
            }
        }));
    }
}

/**
 * Handles geolocator's state change events.
 * @param {const Geolocator&} geolocator: geolocator instance.
 * @param {const StatusChangedEventArgs&} event: StatusChangedEventArgs received from Windows.
 */
- (void)_handleStatusChangedEvent:(const Geolocator&)geolocator statusEvent:(const StatusChangedEventArgs&)event {
    @synchronized(self) {
        NSTraceVerbose(TAG, @"Received status change event.");
        CLAuthorizationStatus authorizationStatus = g_authorizationStatus;
        BOOL positionStatusNoData = NO;
        switch (event.Status()) {
            case PositionStatus::Disabled:
                NSTraceVerbose(TAG, @"Received status change event with status denied (%d).", event.Status());
                authorizationStatus = kCLAuthorizationStatusDenied;
                break;
            case PositionStatus::NoData:
                NSTraceVerbose(TAG, @"Received status change event with status no-data (%d).", event.Status());
                positionStatusNoData = YES;
                break;
            default:
                // For all other status events PositionStatus::Ready, PositionStatus::Initializing, PositionStatus::NotAvailable and
                // PositionStatus::NotInitialized.
                NSTraceVerbose(TAG, @"Received status change event with status %d.", event.Status());
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
 * @param {const Geolocator&} geolocator: geolocator instance.
 * @param {const PositionChangedEventArgs&} event: PositionChangedEventArgs received from Windows.
 */
- (void)_handlePositionChangedEvent:(const Geolocator&)geolocator statusEvent:(const PositionChangedEventArgs&)event {
    NSTraceVerbose(TAG, @"Received position changed event.");
    [self _handleLocationUpdate:event.Position()];
}

/**
 * Handles compass's heading change events.
 * @param {const Compass&} compass: compass instance.
 * @param {const CompassReadingChangedEventArgs&} event: ReadingChangedEventArgs received from Windows.
 */
- (void)_handleHeadingChangedEvent:(const Compass&)compass statusEvent:(const CompassReadingChangedEventArgs&)event {
    NSTraceVerbose(TAG, @"Received heading changed event.");
    [self _handleHeadingUpdate:event.Reading()];
}

/**
 * Handles location change updates.
 * @param {const Geoposition&} geoposition: updated location values received from Windows.
 */
- (void)_handleLocationUpdate:(const Geoposition&)geoposition {
    @synchronized(self) {
        Geocoordinate geocoordinator = geoposition.Coordinate();
        CLLocationCoordinate2D coordinate = {
            geocoordinator.Point().Position().Latitude,
            geocoordinator.Point().Position().Longitude
        };

        CLLocation* previousLocation = self.location;

        // Compute time since Jan 1, 1970
        std::tm unixEpochTm = { 0, 0, 0, 1, 0, 70, 0, 0, -1 };
        const std::time_t unixEpoch = std::mktime(&unixEpochTm);

        std::time_t timestamp = winrt::clock::to_time_t(geocoordinator.Timestamp());
        double secsSinceEpoch = std::difftime(timestamp, unixEpoch);

        WF::IReference<double> altitudeAccuracy = geocoordinator.AltitudeAccuracy();
        WF::IReference<double> speed = geocoordinator.Speed();

        // TODO::
        // todo-nithishm-11062015 -
        //     How to obtain course?
        //
        self.location = [[CLLocation alloc] initWithCoordinate:coordinate
                                                      altitude:geocoordinator.Point().Position().Altitude
                                            horizontalAccuracy:geocoordinator.Accuracy()
                                              verticalAccuracy:(altitudeAccuracy ? altitudeAccuracy.Value() : 0)
                                                        course:0
                                                         speed:(speed ? speed.Value() : 0)
                                                     timestamp:[NSDate dateWithTimeIntervalSince1970:secsSinceEpoch]];

        // Deliver location to the appropriate location manager delegate
        if (_periodicLocationUpdateRequested && ![self.location isEqual:previousLocation]) {
            [self performSelector:@selector(_didUpdateToLocationsDelegate:)
                         onThread:_callerThread
                       withObject:previousLocation
                    waitUntilDone:NO];
        }

        // always callUpdateLocationsDelegate because didUpdateToLocationsDelegate is deprecated.
        [self performSelector:@selector(_callUpdateLocationsDelegate) onThread:_callerThread withObject:nil waitUntilDone:NO];
    }
}

/**
 * Handles heading change updates.
 * @param {const CompassReading&} compassReading: updated heading values received from Windows.
 */
- (void)_handleHeadingUpdate:(const CompassReading&)compassReading {
    @synchronized(self) {
        // WDS gives an enum for accuracy, whether it cannot be determined or is reliable/unreliable
        // As per https://msdn.microsoft.com/en-us/library/windows/hardware/dn642102%28v=vs.85%29.aspx,
        // High accuracy is given by 0-10 degrees of difference between measured and actual North,
        // approximate accuracy is between 10 and 25, while unreliable is up to 180 degrees. iOS documentation
        // states that a negative number is returned when the heading is invalid, so 180 degree error gives -1 and
        // an unknown accuracy gives -2.
        CLLocationDirection accuracy = 0.0;
        switch (compassReading.HeadingAccuracy()) {
            case MagnetometerAccuracy::Unknown:
                accuracy = -2.0;
                break;
            case MagnetometerAccuracy::Unreliable:
                accuracy = -1.0;
                break;
            case MagnetometerAccuracy::Approximate:
                accuracy = 25.0;
                break;
            case MagnetometerAccuracy::High:
                accuracy = 10.0;
                break;
            default:
                NSTraceInfo(TAG, @"Got an unknown value for heading accuracy reading.");
                accuracy = 0;
        }

        // Calculate angular change from previous heading and make sure it is larger than headingFilter
        CLLocationDegrees headingDelta = fmod(abs(self.heading.magneticHeading - compassReading.HeadingMagneticNorth()), 360.0);
        headingDelta = headingDelta > 180.0 ? 360.0 - headingDelta : headingDelta;
        if (headingDelta > self.headingFilter) {
            WF::IReference<double> trueHeading = compassReading.HeadingTrueNorth();
            self.heading = [[CLHeading alloc] initWithAccuracy:accuracy
                                               magneticHeading:compassReading.HeadingMagneticNorth()
                                                   trueHeading:(trueHeading ? trueHeading.Value() : 0.0)];

            // Call heading update delegate
            [self performSelector:@selector(_callUpdateHeadingsDelegate) onThread:_callerThread withObject:nil waitUntilDone:NO];
        }
    }
}

/**
 * Handles errors related with location updates.
 * @param {NSError*} error: location update error received from Windows.
 */
- (void)_handleLocationUpdateError:(NSError*)error {
    // Deliver location update failure to the location manager delegate.
    [self performSelector:@selector(_callLocationFailedDelegate:) onThread:_callerThread withObject:error waitUntilDone:NO];
}

/**
 * Helper method to call Windows GetGeopositionAsync to get location updates.
 */
- (void)_getGeopositionAsync {
    WF::IAsyncOperation<Geoposition> async = _uwpGeolocator.GetGeopositionAsync();

    async.Completed(objcwinrt::callback([self] (const WF::IAsyncOperation<Geoposition>& op, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            NSTraceInfo(TAG, @"Get geoposition update succeeded.");
            // We purposely do not update the location from here as we already have a PositionChange event registered
            // in this code path and updating the location from here would just be a duplicate.
        } else {
            NSTraceInfo(TAG, @"Get geoposition update failed with error: %08lx, status: %u", (unsigned long)op.ErrorCode(), (unsigned)status);
            [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                 code:kCLErrorNetwork
                                                             userInfo:nil]];
        }
    }));
}

/**
 * Helper method to call Windows GetGeopositionAsync with ages and timeout in seconds to get location.
 * Hardcoding maximum acceptable age of cached location data to 1 second and timeout value to 15 seconds.
 */
- (void)_getGeopositionAsyncWithAgeAndTimeout {
    WF::TimeSpan maximumAge = std::chrono::duration_cast<WF::TimeSpan>(c_maximumAgeInSeconds);
    WF::TimeSpan timeout = std::chrono::duration_cast<WF::TimeSpan>(c_timeoutInSeconds);

    WF::IAsyncOperation<Geoposition> async = _uwpGeolocator.GetGeopositionAsync(maximumAge, timeout);

    async.Completed(objcwinrt::callback([self] (const WF::IAsyncOperation<Geoposition>& op, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            NSTraceInfo(TAG, @"Get single geoposition update succeeded.");
            [self _handleLocationUpdate:op.GetResults()];
        } else {
            NSTraceInfo(TAG, @"Get single geoposition update failed with error: %08lx, status: %u", (unsigned long)op.ErrorCode(), (unsigned)status);
            [self _handleLocationUpdateError:[NSError errorWithDomain:(NSString*)c_CLLocationManagerErrorDomain
                                                                 code:kCLErrorNetwork
                                                             userInfo:nil]];
        }
    }));
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
    if (Compass::GetDefault()) {
        return YES;
    }

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
        _periodicHeadingUpdateRequested = NO;
        _location = nullptr;
        _heading = nullptr;
        // Cache the caller's thread object to use it to call delegates on.
        _callerThread = [NSThread currentThread];
        // Initialize WDGGeolocator.
        _uwpGeolocator = Geolocator();
        _uwpCompass = Compass::GetDefault();
        _headingOrientation = CLDeviceOrientationLandscapeLeft;
        _headingFilter = 1;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // Note: We do not have to synchronize here as no other method will be called in parallel at this time.
    if (_periodicLocationUpdateRequested) {
        _uwpGeolocator.PositionChanged(_uwpPeriodicPositionChangeToken);
        _periodicLocationUpdateRequested = NO;
    }
    if (_periodicHeadingUpdateRequested) {
        _uwpCompass.ReadingChanged(_uwpPeriodicHeadingChangeToken);
        _periodicHeadingUpdateRequested = NO;
    }

    [self stopUpdatingLocation];
    [self stopUpdatingHeading];

    if (_statusUpdateRequested) {
        _uwpGeolocator.StatusChanged(_uwpStatusToken);
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
            NSTraceInfo(TAG, @"Starting periodic location update");

            // make a single request first.  On reference platform, startUpdatingLocation will always cause at least one delegate callback
            // on windows, addPositionChangedEvent will only be called if the position indeed changed.
            [self requestLocation];

            if (self.allowsBackgroundLocationUpdates) {
                // Request for a extended execution session so location updates can continue in the background.
                _requestExtendedExecutionSession();
            }

            // Register for position change event only the first time location update is requested.
            __weak CLLocationManager* weakSelf = self;
            _uwpPeriodicPositionChangeToken =
                _uwpGeolocator.PositionChanged(objcwinrt::callback([weakSelf] (const Geolocator& geolocator, const PositionChangedEventArgs& event) {
                    [weakSelf _handlePositionChangedEvent:geolocator statusEvent:event];
                }));
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
            _uwpGeolocator.PositionChanged(_uwpPeriodicPositionChangeToken);

            _removeExtendedExecutionSession();
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
 @Status Interoperable
*/
- (void)startUpdatingHeading {
    @synchronized(self) {
        if (!_periodicHeadingUpdateRequested) {
            NSTraceInfo(TAG, @"Started periodic heading update");

            if (self.allowsBackgroundLocationUpdates) {
                // Request for a extended execution session so heading updates can continue in the background.
                _requestExtendedExecutionSession();
            }

            // Register for position change event only the first time heading update is requested.
            __weak CLLocationManager* weakSelf = self;
            _uwpPeriodicHeadingChangeToken =
                _uwpCompass.ReadingChanged(objcwinrt::callback([weakSelf] (const Compass& compass, const CompassReadingChangedEventArgs& event) {
                    [weakSelf _handleHeadingChangedEvent:compass statusEvent:event];
                }));
            _periodicHeadingUpdateRequested = YES;
        }
    }
}

/**
 @Status Interoperable
*/
- (void)stopUpdatingHeading {
    @synchronized(self) {
        if (_periodicHeadingUpdateRequested) {
            NSTraceInfo(TAG, @"Stopped periodic heading update");
            _uwpCompass.ReadingChanged(_uwpPeriodicHeadingChangeToken);

            _removeExtendedExecutionSession();
            _periodicHeadingUpdateRequested = NO;
        }
    }
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
