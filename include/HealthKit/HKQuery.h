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
#import <Foundation/NSObject.h>
#import <Foundation/NSComparisonPredicate.h>
#import <HealthKit/HealthKitConstants.h>

@class NSString;
@class NSPredicate;
@class HKSampleType;
@class NSUUID;
@class NSSet;
@class HKSource;
@class NSArray;
@class NSDate;
@class HKQuantity;
@class HKWorkout;

typedef enum : NSUInteger {
    HKQueryOptionNone = 0,
    HKQueryOptionStrictStartDate = 1 << 0,
    HKQueryOptionStrictEndDate = 1 << 1,
} HKQueryOptions;

HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyName;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyManufacturer;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyModel;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyHardwareVersion;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyFirmwareVersion;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeySoftwareVersion;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyLocalIdentifier;
HEALTHKIT_EXPORT NSString* const HKDevicePropertyKeyUDIDeviceIdentifier;

HEALTHKIT_EXPORT_CLASS
@interface HKQuery : NSObject
@property (readonly, strong) NSPredicate* predicate STUB_PROPERTY;
@property (readonly, strong) HKSampleType* sampleType STUB_PROPERTY;
+ (NSPredicate*)predicateForObjectWithUUID:(NSUUID*)UUID STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithUUIDs:(NSSet*)UUIDs STUB_METHOD;
+ (NSPredicate*)predicateForObjectsFromSource:(HKSource*)source STUB_METHOD;
+ (NSPredicate*)predicateForObjectsFromSources:(NSSet*)sources STUB_METHOD;
+ (NSPredicate*)predicateForObjectsFromDevices:(NSSet*)devices STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithDeviceProperty:(NSString*)key allowedValues:(NSSet*)allowedValues STUB_METHOD;
+ (NSPredicate*)predicateForObjectsFromSourceRevisions:(NSSet*)sourceRevisions STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key allowedValues:(NSArray*)allowedValues STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key
                                      operatorType:(NSPredicateOperatorType)operatorType
                                             value:(id)value STUB_METHOD;
+ (NSPredicate*)predicateForObjectsWithNoCorrelation STUB_METHOD;
+ (NSPredicate*)predicateForSamplesWithStartDate:(NSDate*)startDate endDate:(NSDate*)endDate options:(HKQueryOptions)options STUB_METHOD;
+ (NSPredicate*)predicateForQuantitySamplesWithOperatorType:(NSPredicateOperatorType)operatorType
                                                   quantity:(HKQuantity*)quantity STUB_METHOD;
+ (NSPredicate*)predicateForCategorySamplesWithOperatorType:(NSPredicateOperatorType)operatorType value:(NSInteger)value STUB_METHOD;
+ (NSPredicate*)predicateForObjectsFromWorkout:(HKWorkout*)workout STUB_METHOD;
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType duration:(NSTimeInterval)duration STUB_METHOD;
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType
                                       totalDistance:(HKQuantity*)totalDistance STUB_METHOD;
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType
                                   totalEnergyBurned:(HKQuantity*)totalEnergyBurned STUB_METHOD;
+ (NSPredicate*)predicateForWorkoutsWithWorkoutActivityType:(HKWorkoutActivityType)workoutActivityType STUB_METHOD;
@end
