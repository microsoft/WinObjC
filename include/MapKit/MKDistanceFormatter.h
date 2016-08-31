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
#pragma once

#import <MapKit/MapKitExport.h>
#import <CoreLocation/CLLocation.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSLocale;

typedef enum {
    MKDistanceFormatterUnitsDefault,
    MKDistanceFormatterUnitsMetric,
    MKDistanceFormatterUnitsImperial,
    MKDistanceFormatterUnitsImperialWithYards
} MKDistanceFormatterUnits;

typedef enum {
    MKDistanceFormatterUnitStyleDefault = 0,
    MKDistanceFormatterUnitStyleAbbreviated,
    MKDistanceFormatterUnitStyleFull
} MKDistanceFormatterUnitStyle;

MAPKIT_EXPORT_CLASS
@interface MKDistanceFormatter : NSObject <NSObject, NSCopying, NSCoding>
- (NSString*)stringFromDistance:(CLLocationDistance)distance STUB_METHOD;
- (CLLocationDistance)distanceFromString:(NSString*)distance STUB_METHOD;
@property (copy, nonatomic) NSLocale* locale STUB_PROPERTY;
@property (assign, nonatomic) MKDistanceFormatterUnits units STUB_PROPERTY;
@property (assign, nonatomic) MKDistanceFormatterUnitStyle unitStyle STUB_PROPERTY;
@end
