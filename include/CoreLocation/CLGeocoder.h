//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#pragma once

#import <CoreLocation/CoreLocationExport.h>
#import <CoreLocation/CoreLocationConstants.h>
#import <CoreLocation/CoreLocationFunctions.h>
#import <CoreLocation/CLRegion.h>
#import <CoreLocation/CLCircularRegion.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSError.h>

@class CLLocation;
@class CLRegion;

typedef void (^CLGeocodeCompletionHandler)(NSArray* placemark, NSError* error);

CORELOCATION_EXPORT_CLASS
@interface CLGeocoder : NSObject
- (void)reverseGeocodeLocation:(CLLocation*)location completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)geocodeAddressDictionary:(NSDictionary*)addressDictionary completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)geocodeAddressString:(NSString*)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)geocodeAddressString:(NSString*)addressString
                    inRegion:(CLRegion*)region
           completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)cancelGeocode STUB_METHOD;
@property (readonly, getter=isGeocoding, nonatomic) BOOL geocoding;
@end

@interface CLGeocoder (WinObjC)
// WINOBJC extension method to set underlying Bing service token, required to use CLGeocoder APIs
// See https://docs.microsoft.com/en-us/windows/uwp/maps-and-location/geocoding for more info
+ (void)setWindowsServiceToken:(NSString*)token;
@end
