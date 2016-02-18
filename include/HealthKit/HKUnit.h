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

#import <HealthKit/HealthKitExport.h>
#import <Foundation/NSEnergyFormatter.h>
#import <Foundation/NSLengthFormatter.h>
#import <Foundation/NSMassFormatter.h>
#import <Foundation/NSObject.h>

@class NSString;

typedef enum : NSInteger {
    HKMetricPrefixNone = 0,
    HKMetricPrefixPico,
    HKMetricPrefixNano,
    HKMetricPrefixMicro,
    HKMetricPrefixMilli,
    HKMetricPrefixCenti,
    HKMetricPrefixDeci,
    HKMetricPrefixDeca,
    HKMetricPrefixHecto,
    HKMetricPrefixKilo,
    HKMetricPrefixMega,
    HKMetricPrefixGiga,
    HKMetricPrefixTera
} HKMetricPrefix;
#define HKUnitMolarMassBloodGlucose (180.15588000005408)

HEALTHKIT_EXPORT_CLASS
@interface HKUnit : NSObject <NSCopying, NSSecureCoding>
+ (instancetype)unitFromString:(NSString*)string STUB_METHOD;
@property (readonly, strong) NSString* unitString STUB_PROPERTY;
- (BOOL)isNull STUB_METHOD;
+ (NSEnergyFormatterUnit)energyFormatterUnitFromUnit:(HKUnit*)unit STUB_METHOD;
+ (instancetype)unitFromEnergyFormatterUnit:(NSEnergyFormatterUnit)energyFormatterUnit STUB_METHOD;
+ (NSLengthFormatterUnit)lengthFormatterUnitFromUnit:(HKUnit*)unit STUB_METHOD;
+ (instancetype)unitFromLengthFormatterUnit:(NSLengthFormatterUnit)lengthFormatterUnit STUB_METHOD;
+ (NSMassFormatterUnit)massFormatterUnitFromUnit:(HKUnit*)unit STUB_METHOD;
+ (instancetype)unitFromMassFormatterUnit:(NSMassFormatterUnit)massFormatterUnit STUB_METHOD;
+ (instancetype)gramUnit STUB_METHOD;
+ (instancetype)gramUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)ounceUnit STUB_METHOD;
+ (instancetype)poundUnit STUB_METHOD;
+ (instancetype)stoneUnit STUB_METHOD;
+ (instancetype)moleUnitWithMolarMass:(double)gramsPerMole STUB_METHOD;
+ (instancetype)moleUnitWithMetricPrefix:(HKMetricPrefix)prefix molarMass:(double)gramsPerMole STUB_METHOD;
+ (instancetype)meterUnit STUB_METHOD;
+ (instancetype)meterUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)inchUnit STUB_METHOD;
+ (instancetype)footUnit STUB_METHOD;
+ (instancetype)yardUnit STUB_METHOD;
+ (instancetype)mileUnit STUB_METHOD;
+ (instancetype)literUnit STUB_METHOD;
+ (instancetype)literUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)fluidOunceUSUnit STUB_METHOD;
+ (instancetype)fluidOunceImperialUnit STUB_METHOD;
+ (instancetype)cupUSUnit STUB_METHOD;
+ (instancetype)cupImperialUnit STUB_METHOD;
+ (instancetype)pintUSUnit STUB_METHOD;
+ (instancetype)pintImperialUnit STUB_METHOD;
+ (instancetype)pascalUnit STUB_METHOD;
+ (instancetype)pascalUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)millimeterOfMercuryUnit STUB_METHOD;
+ (instancetype)centimeterOfWaterUnit STUB_METHOD;
+ (instancetype)atmosphereUnit STUB_METHOD;
+ (instancetype)secondUnit STUB_METHOD;
+ (instancetype)secondUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)minuteUnit STUB_METHOD;
+ (instancetype)hourUnit STUB_METHOD;
+ (instancetype)dayUnit STUB_METHOD;
+ (instancetype)jouleUnit STUB_METHOD;
+ (instancetype)jouleUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)calorieUnit STUB_METHOD;
+ (instancetype)kilocalorieUnit STUB_METHOD;
+ (instancetype)degreeCelsiusUnit STUB_METHOD;
+ (instancetype)degreeFahrenheitUnit STUB_METHOD;
+ (instancetype)kelvinUnit STUB_METHOD;
+ (instancetype)siemenUnit STUB_METHOD;
+ (instancetype)siemenUnitWithMetricPrefix:(HKMetricPrefix)prefix STUB_METHOD;
+ (instancetype)countUnit STUB_METHOD;
+ (instancetype)percentUnit STUB_METHOD;
- (HKUnit*)unitMultipliedByUnit:(HKUnit*)unit STUB_METHOD;
- (HKUnit*)unitDividedByUnit:(HKUnit*)unit STUB_METHOD;
- (HKUnit*)unitRaisedToPower:(NSInteger)power STUB_METHOD;
- (HKUnit*)reciprocalUnit STUB_METHOD;
@end
