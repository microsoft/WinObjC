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

#import "windows.h"
#import <CoreLocation/CLGeocoder.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLPlacemark.h>
#import <StubReturn.h>
#import <UWP/WindowsDevicesGeolocation.h>
#import <UWP/WindowsServicesMaps.h>
#import "CLPlacemarkInternal.h"

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

// Helper function to convert WSM error code to NSError codes
NSError* parseError(WSMMapLocationFinderResult* results) {
    // Unknown Error and Status Not Supported don't map to any iOS error codes
    WSMMapLocationFinderStatus status = results.status;
    if (status == WSMMapLocationFinderStatusSuccess) {
        return nullptr;
    } else if (status == WSMMapLocationFinderStatusUnknownError) {
        return nullptr;
    } else if (status == WSMMapLocationFinderStatusInvalidCredentials) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorDenied userInfo:nullptr];
    } else if (status == WSMMapLocationFinderStatusBadLocation) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorLocationUnknown userInfo:nullptr];
    } else if (status == WSMMapLocationFinderStatusIndexFailure) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeFoundNoResult userInfo:nullptr];
    } else if (status == WSMMapLocationFinderStatusNetworkFailure) {
        return [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorNetwork userInfo:nullptr];
    } else if (status == WSMMapLocationFinderStatusNotSupported) {
        return nullptr;
    }

    return nullptr;
}

// Helper function to parse address results from the location finder and put them into an array of placemarks
void createResultsArray(WSMMapLocationFinderResult* results, NSMutableArray* geocodeResult) {
    int geocodeResultCount = [results.locations count];
    for (int i = 0; i < geocodeResultCount; i++) {
        WSMMapLocation* currentResult = [results.locations objectAtIndex:i];
        WSMMapAddress* currentAddress = [currentResult address];

        NSMutableDictionary* addressDictionary = [[NSMutableDictionary alloc] init];

        NSString* placemarkName;
        if ([currentAddress streetNumber] && [currentAddress street]) {
            placemarkName = [NSString stringWithFormat:@"%@ %@", [currentAddress streetNumber], [currentAddress street]];
        } else if ([currentAddress street]) {
            placemarkName = [currentAddress street];
        } else if ([currentAddress town] && [currentAddress region]) {
            placemarkName = [NSString stringWithFormat:@"%@, %@", [currentAddress town], [currentAddress region]];
        } else if ([currentAddress town]) {
            placemarkName = [currentAddress town];
        } else {
            // Do whatever Windows decides should be the default
            placemarkName = [currentAddress formattedAddress];
        }

        [addressDictionary setValue:placemarkName forKey:@"placemarkName"];
        [addressDictionary setValue:[currentAddress countryCode] forKey:@"placemarkISOcountryCode"];
        [addressDictionary setValue:[currentAddress country] forKey:@"placemarkCountry"];
        [addressDictionary setValue:[currentAddress postCode] forKey:@"placemarkPostalCode"];
        [addressDictionary setValue:[currentAddress region] forKey:@"placemarkAdministrativeArea"];
        [addressDictionary setValue:[currentAddress district] forKey:@"placemarkSubAdministrativeArea"];
        [addressDictionary setValue:[currentAddress town] forKey:@"placemarkLocality"];
        [addressDictionary setValue:[currentAddress neighborhood] forKey:@"placemarkSubLocality"];
        [addressDictionary setValue:[currentAddress street] forKey:@"placemarkThoroughfare"];
        [addressDictionary setValue:[currentAddress streetNumber] forKey:@"placemarkSubThoroughfare"];
        CLLocation* resultLocation = [[CLLocation alloc] initWithLatitude:[[[currentResult point] position] latitude]
                                                                longitude:[[[currentResult point] position] longitude]];

        CLPlacemark* currentPlacemark = [[CLPlacemark alloc] initWithLocation:resultLocation dictionary:addressDictionary];
        [geocodeResult addObject:currentPlacemark];
    }
}

/**
 @Status Interoperable
*/
- (void)reverseGeocodeLocation:(CLLocation*)location completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    @synchronized(self) {
        if (!CLLocationCoordinate2DIsValid(location.coordinate)) {
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               completionHandler(nullptr,
                                                 [NSError errorWithDomain:@"kCLErrorDomain"
                                                                     code:kCLErrorGeocodeFoundNoResult
                                                                 userInfo:nullptr]);
                           });
        } else if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               completionHandler(nullptr,
                                                 [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nullptr]);
                           });
        } else {
            self.geocoding = true;

            WDGBasicGeoposition* geoposition = [[WDGBasicGeoposition alloc] init];
            geoposition.latitude = location.coordinate.latitude;
            geoposition.longitude = location.coordinate.longitude;

            WDGGeopoint* geopoint = [WDGGeopoint make:geoposition];

            [WSMMapLocationFinder findLocationsAtAsync:geopoint
                success:^void(WSMMapLocationFinderResult* results) {
                    self.geocoding = false;

                    WSMMapLocationFinderStatus status = results.status;
                    NSError* geocodeStatus = parseError(results);

                    NSMutableArray* geocodeResult = [[NSMutableArray alloc] init];
                    createResultsArray(results, geocodeResult);

                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(geocodeResult, geocodeStatus);
                                   });
                }
                failure:^void(NSError* error) {
                    self.geocoding = false;
                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(nullptr, error);
                                   });
                }];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)geocodeAddressDictionary:(NSDictionary*)addressDictionary completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    @synchronized(self) {
        if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               completionHandler(nullptr,
                                                 [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nullptr]);
                           });
        } else {
            self.geocoding = true;

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

            [WSMMapLocationFinder findLocationsAsync:fullAddress
                referencePoint:nullptr
                success:^void(WSMMapLocationFinderResult* results) {
                    self.geocoding = false;

                    WSMMapLocationFinderStatus status = results.status;
                    NSError* geocodeStatus = parseError(results);

                    NSMutableArray* geocodeResult = [[NSMutableArray alloc] init];
                    createResultsArray(results, geocodeResult);

                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(geocodeResult, geocodeStatus);
                                   });
                }
                failure:^void(NSError* error) {
                    self.geocoding = false;
                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(nullptr, error);
                                   });
                }];
        }
    }
}

/**
 @Status Interoperable
*/
- (void)geocodeAddressString:(NSString*)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    @synchronized(self) {
        if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               completionHandler(nullptr,
                                                 [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nullptr]);
                           });
        } else {
            self.geocoding = true;
            [WSMMapLocationFinder findLocationsAsync:addressString
                referencePoint:nullptr
                success:^void(WSMMapLocationFinderResult* results) {
                    self.geocoding = false;

                    WSMMapLocationFinderStatus status = results.status;
                    NSError* geocodeStatus = parseError(results);

                    NSMutableArray* geocodeResult = [[NSMutableArray alloc] init];
                    createResultsArray(results, geocodeResult);

                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(geocodeResult, geocodeStatus);
                                   });
                }
                failure:^void(NSError* error) {
                    self.geocoding = false;
                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(nullptr, error);
                                   });
                }];
        }
    }
}

/**
 @Status Caveat
 @Notes There is no direct Windows API mapping to geocode within a region.
        Therefore, this API currently just uses the center of the region as a hint for Geocoding.
*/
- (void)geocodeAddressString:(NSString*)addressString
                    inRegion:(CLRegion*)region
           completionHandler:(CLGeocodeCompletionHandler)completionHandler {
    @synchronized(self) {
        if (self.isGeocoding) {
            dispatch_async(dispatch_get_main_queue(),
                           ^{
                               completionHandler(nullptr,
                                                 [NSError errorWithDomain:@"kCLErrorDomain" code:kCLErrorGeocodeCanceled userInfo:nullptr]);
                           });
        } else {
            self.geocoding = true;
            WDGBasicGeoposition* geoposition = [[WDGBasicGeoposition alloc] init];
            geoposition.latitude = region.center.latitude;
            geoposition.longitude = region.center.longitude;

            WDGGeopoint* geopoint = [WDGGeopoint make:geoposition];

            [WSMMapLocationFinder findLocationsAsync:addressString
                referencePoint:geopoint
                success:^void(WSMMapLocationFinderResult* results) {
                    self.geocoding = false;

                    WSMMapLocationFinderStatus status = results.status;
                    NSError* geocodeStatus = parseError(results);

                    NSMutableArray* geocodeResult = [[NSMutableArray alloc] init];
                    createResultsArray(results, geocodeResult);

                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(geocodeResult, geocodeStatus);
                                   });
                }
                failure:^void(NSError* error) {
                    self.geocoding = false;
                    dispatch_async(dispatch_get_main_queue(),
                                   ^{
                                       completionHandler(nullptr, error);
                                   });
                }];
        }
    }
}

/**
 @Status Stub
*/
- (void)cancelGeocode {
    UNIMPLEMENTED();
}

@end