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
#import <HealthKit/HKSample.h>
#import <HealthKit/HealthKitConstants.h>

@class NSString;
@class NSDate;
@class HKQuantity;
@class NSDictionary;
@class NSArray;
@class HKDevice;

HEALTHKIT_EXPORT NSString* const HKWorkoutSortIdentifierDuration;
HEALTHKIT_EXPORT NSString* const HKWorkoutSortIdentifierTotalDistance;
HEALTHKIT_EXPORT NSString* const HKWorkoutSortIdentifierTotalEnergyBurned;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathWorkoutDuration;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathWorkoutTotalDistance;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathWorkoutTotalEnergyBurned;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathWorkoutType;

HEALTHKIT_EXPORT_CLASS
@interface HKWorkout : HKSample <NSSecureCoding>
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate STUB_METHOD;
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                               duration:(NSTimeInterval)duration
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                               metadata:(NSDictionary*)metadata STUB_METHOD;
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                          workoutEvents:(NSArray*)workoutEvents
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                               metadata:(NSDictionary*)metadata STUB_METHOD;
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                               duration:(NSTimeInterval)duration
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                                 device:(HKDevice*)device
                               metadata:(NSDictionary*)metadata STUB_METHOD;
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                          workoutEvents:(NSArray*)workoutEvents
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                                 device:(HKDevice*)device
                               metadata:(NSDictionary*)metadata STUB_METHOD;
@property (readonly, assign) NSTimeInterval duration STUB_PROPERTY;
@property (readonly, strong) HKQuantity* totalDistance STUB_PROPERTY;
@property (readonly, strong) HKQuantity* totalEnergyBurned STUB_PROPERTY;
@property (readonly, assign) HKWorkoutActivityType workoutActivityType STUB_PROPERTY;
@property (readonly, copy) NSArray* workoutEvents STUB_PROPERTY;
@end
