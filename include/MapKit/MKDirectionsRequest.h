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

#import <MapKit/MapKitExport.h>
#import <Foundation/NSObject.h>

@class NSURL;
@class MKMapItem;
@class NSDate;

typedef enum {
    MKDirectionsTransportTypeAutomobile = 1 << 0,
    MKDirectionsTransportTypeWalking = 1 << 1,
    MKDirectionsTransportTypeAny = NSUIntegerMax
} MKDirectionsTransportType;

MAPKIT_EXPORT_CLASS
@interface MKDirectionsRequest : NSObject
+ (BOOL)isDirectionsRequestURL:(NSURL*)url STUB_METHOD;
- (instancetype)initWithContentsOfURL:(NSURL*)url STUB_METHOD;
- (MKMapItem*)source STUB_METHOD;
- (void)setSource:(MKMapItem*)source STUB_METHOD;
- (MKMapItem*)destination STUB_METHOD;
- (void)setDestination:(MKMapItem*)destination STUB_METHOD;
@property (nonatomic) MKDirectionsTransportType transportType STUB_PROPERTY;
@property (nonatomic) BOOL requestsAlternateRoutes STUB_PROPERTY;
@property (copy, nonatomic) NSDate* departureDate STUB_PROPERTY;
@property (copy, nonatomic) NSDate* arrivalDate STUB_PROPERTY;
@end
