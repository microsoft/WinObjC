//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "windows.h"
#import <CoreLocation/CLGeocoder.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLPlacemark.h>
#import <StubReturn.h>
#import "CLPlacemarkInternal.h"
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.Devices.Geolocation.h>
#import <winrt/Windows.Services.Maps.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Devices::Geolocation;
using namespace winrt::Windows::Services::Maps;
namespace WF = winrt::Windows::Foundation;

@interface CLGeocoder () {
}

@property (nonatomic, readwrite, getter=isGeocoding) BOOL geocoding;
@end

@implementation CLGeocoder

- (instancetype)init {
    if (self = [super init]) {
        _geocoding = false;
    }

    return self;
}

/**
 @Status Interoperable
 @Notes Registers app with underlying Bing service (see https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding)
*/
+ (void)setWindowsServiceToken:(NSString*)token {
    MapService::ServiceToken(objcwinrt::string(token));
}

// Helper function to convert WSM error code to NSError codes
NSError* parseError(const MapLocationFinderResult& results) {
    // Unknown Error and Status Not Supported don't map to any iOS error codes
    MapLocationFinderStatus status = results.Status();
    if (status == MapLocationFinderStatus::Success) {
        return nullptr;
    } else if (status == MapLocationFinderStatus::UnknownError) {
        return nullptr;
    } else if (status == MapLocationFinderStatus::InvalidCredentials) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorDenied userInfo:nullptr];
    } else if (status == MapLocationFinderStatus::BadLocation) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorLocationUnknown userInfo:nullptr];
    } else if (status == MapLocationFinderStatus::IndexFailure) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeFoundNoResult userInfo:nullptr];
    } else if (status == MapLocationFinderStatus::NetworkFailure) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorNetwork userInfo:nullptr];
    } else if (status == MapLocationFinderStatus::NotSupported) {
        return nullptr;
    }

    return nullptr;
}

// Helper function to parse address results from the location finder and put them into an array of placemarks
void createResultsArray(const MapLocationFinderResult& results, NSMutableArray* geocodeResult) {
    int geocodeResultCount = results.Locations().Size();
    for (int i = 0; i < geocodeResultCount; i++) {
        MapLocation currentResult = results.Locations().GetAt(i);
        MapAddress currentAddress = currentResult.Address();

        NSMutableDictionary* addressDictionary = [[NSMutableDictionary alloc] init];

        NSString* placemarkName;
        if (!currentAddress.StreetNumber().empty() && !currentAddress.Street().empty()) {
            placemarkName = [NSString stringWithFormat:@"%S %S",
                                                       (const unichar*)currentAddress.StreetNumber().c_str(),
                                                       (const unichar*)currentAddress.Street().c_str()];
        } else if (!currentAddress.Street().empty()) {
            placemarkName = objcwinrt::string(currentAddress.Street());
        } else if (!currentAddress.Town().empty() && !currentAddress.Region().empty()) {
            placemarkName = [NSString
                stringWithFormat:@"%S, %S", (const unichar*)currentAddress.Town().c_str(), (const unichar*)currentAddress.Region().c_str()];
        } else if (!currentAddress.Town().empty()) {
            placemarkName = objcwinrt::string(currentAddress.Town());
        } else {
            // Do whatever Windows decides should be the default
            placemarkName = objcwinrt::string(currentAddress.FormattedAddress());
        }

        [addressDictionary setValue:placemarkName forKey:@"placemarkName"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.CountryCode()) forKey:@"CountryCode"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.Country()) forKey:@"Country"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.PostCode()) forKey:@"PostalCode"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.Region()) forKey:@"AdministrativeArea"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.District()) forKey:@"SubAdministrativeArea"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.Town()) forKey:@"Locality"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.Neighborhood()) forKey:@"SubLocality"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.Street()) forKey:@"Thoroughfare"];
        [addressDictionary setValue:objcwinrt::string(currentAddress.StreetNumber()) forKey:@"SubThoroughfare"];
        CLLocation* resultLocation = [[CLLocation alloc] initWithLatitude:currentResult.Point().Position().Latitude
                                                                longitude:currentResult.Point().Position().Longitude];

        CLPlacemark* currentPlacemark = [[CLPlacemark alloc] initWithLocation:resultLocation dictionary:addressDictionary];
        [geocodeResult addObject:currentPlacemark];
    }
}

/**
 @Status Interoperable
 @Notes App must authenticate map service WSMMapService to use (see
 https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding)
*/
- (void)reverseGeocodeLocation:(CLLocation*)location completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    @synchronized(self) {
        if (!CLLocationCoordinate2DIsValid(location.coordinate)) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completionHandler(nullptr, [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeFoundNoResult userInfo:nullptr]);
            });
        } else if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completionHandler(nullptr, [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nullptr]);
            });
        } else {
            self.geocoding = true;

            BasicGeoposition geoposition;
            geoposition.Latitude = location.coordinate.latitude;
            geoposition.Longitude = location.coordinate.longitude;

            Geopoint geopoint(geoposition);

            WF::IAsyncOperation<MapLocationFinderResult> async = MapLocationFinder::FindLocationsAtAsync(geopoint);

            async.Completed(objcwinrt::callback(
                [self, completionHandler](const WF::IAsyncOperation<MapLocationFinderResult>& op, WF::AsyncStatus status) {
                    NSError* geocodeStatus = objcwinrt::to_nserror(op, status);
                    NSMutableArray* geocodeResult = nil;
                    self.geocoding = NO;

                    if (status == WF::AsyncStatus::Completed) {
                        MapLocationFinderResult result = op.GetResults();
                        geocodeStatus = parseError(result);

                        geocodeResult = [NSMutableArray new];
                        createResultsArray(result, geocodeResult);
                    }

                    dispatch_async(dispatch_get_main_queue(), ^{
                        completionHandler(geocodeResult, geocodeStatus);
                    });
                }));
        }
    }
}

/**
 Internal method
*/
- (void)_geocodeAddress:(NSString*)address atPoint:(const Geopoint&)point completionHandler:(CLGeocodeCompletionHandler)completion {
    @synchronized(self) {
        if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(), ^{
                completion(nil, [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nil]);
            });
        } else {
            self.geocoding = YES;

            WF::IAsyncOperation<MapLocationFinderResult> async = MapLocationFinder::FindLocationsAsync(objcwinrt::string(address), point);

            async.Completed(
                objcwinrt::callback([self, completion](const WF::IAsyncOperation<MapLocationFinderResult>& op, WF::AsyncStatus status) {
                    NSError* geocodeStatus = objcwinrt::to_nserror(op, status);
                    NSMutableArray* geocodeResult = nil;
                    self.geocoding = NO;

                    if (status == WF::AsyncStatus::Completed) {
                        MapLocationFinderResult result = op.GetResults();
                        geocodeStatus = parseError(result);

                        geocodeResult = [NSMutableArray new];
                        createResultsArray(result, geocodeResult);
                    }

                    dispatch_async(dispatch_get_main_queue(), ^{
                        completion(geocodeResult, geocodeStatus);
                    });
                }));
        }
    }
}

/**
 @Status Interoperable
 @Notes App must authenticate map service WSMMapService to use (see
 https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding)
*/
- (void)geocodeAddressDictionary:(NSDictionary*)addressDictionary completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    const NSString* addressStreet = (const NSString*)[addressDictionary objectForKey:@"Street"];
    const NSString* addressCity = (const NSString*)[addressDictionary objectForKey:@"City"];
    const NSString* addressState = (const NSString*)[addressDictionary objectForKey:@"State"];
    const NSString* addressZIP = (const NSString*)[addressDictionary objectForKey:@"ZIP"];
    const NSString* addressCountry = (const NSString*)[addressDictionary objectForKey:@"Country"];

    NSMutableString* fullAddress = [[NSMutableString alloc] init];
    if (addressStreet) {
        [fullAddress appendFormat:@"%@, ", addressStreet];
    }

    if (addressCity) {
        [fullAddress appendFormat:@"%@, ", addressCity];
    }

    if (addressState && addressZIP) {
        [fullAddress appendFormat:@"%@ %@, ", addressState, addressZIP];
    } else if (addressState) {
        [fullAddress appendFormat:@"%@, ", addressState];
    } else if (addressZIP) {
        [fullAddress appendFormat:@"%@, ", addressZIP];
    }

    if (addressCountry) {
        [fullAddress appendFormat:@"%@", addressCountry];
    }

    if ([fullAddress hasSuffix:@", "]) {
        [fullAddress deleteCharactersInRange:NSMakeRange([fullAddress length] - 2, 2)];
    }

    [self _geocodeAddress:fullAddress atPoint:nullptr completionHandler:completionHandler];
}

/**
 @Status Interoperable
 @Notes App must authenticate map service WSMMapService to use (see
 https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding)
*/
- (void)geocodeAddressString:(NSString*)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    [self _geocodeAddress:addressString atPoint:nullptr completionHandler:completionHandler];
}

/**
 @Status Caveat
 @Notes There is no direct Windows API mapping to geocode within a region.
        Therefore, this API currently just uses the center of the region as a hint for Geocoding.
        App must authenticate map service WSMMapService to use (see
 https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding)
*/
- (void)geocodeAddressString:(NSString*)addressString
                    inRegion:(CLRegion*)region
           completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    BasicGeoposition geoposition;
    geoposition.Latitude = region.center.latitude;
    geoposition.Longitude = region.center.longitude;

    Geopoint geopoint(geoposition);

    [self _geocodeAddress:addressString atPoint:geopoint completionHandler:completionHandler];
}

/**
 @Status Stub
*/
- (void)cancelGeocode {
    UNIMPLEMENTED();
}

@end