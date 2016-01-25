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

#pragma once

#import <CoreLocation/CoreLocationExport.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSError.h>

@class CLLocation;
@class CLRegion;

typedef void (^CLGeocodeCompletionHandler)(NSArray* placemark, NSError* error);

CORELOCATION_EXPORT_CLASS
@interface CLGeocoder : NSObject <NSObject>
- (void)reverseGeocodeLocation:(CLLocation*)location completionHandler:(CLGeocodeCompletionHandler)completionHandler STUB_METHOD;
- (void)geocodeAddressDictionary:(NSDictionary*)addressDictionary
               completionHandler:(CLGeocodeCompletionHandler)completionHandler STUB_METHOD;
- (void)geocodeAddressString:(NSString*)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler STUB_METHOD;
- (void)geocodeAddressString:(NSString*)addressString
                    inRegion:(CLRegion*)region
           completionHandler:(CLGeocodeCompletionHandler)completionHandler STUB_METHOD;
- (void)cancelGeocode STUB_METHOD;
@property (readonly, getter=isGeocoding, nonatomic) BOOL geocoding STUB_PROPERTY;
@end