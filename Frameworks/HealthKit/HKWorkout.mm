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

#import <StubReturn.h>

#import <HealthKit/HKWorkout.h>

NSString* const HKWorkoutSortIdentifierDuration = @"HKWorkoutSortIdentifierDuration";
NSString* const HKWorkoutSortIdentifierTotalDistance = @"HKWorkoutSortIdentifierTotalDistance";
NSString* const HKWorkoutSortIdentifierTotalEnergyBurned = @"HKWorkoutSortIdentifierTotalEnergyBurned";
NSString* const HKPredicateKeyPathWorkoutDuration = @"HKPredicateKeyPathWorkoutDuration";
NSString* const HKPredicateKeyPathWorkoutTotalDistance = @"HKPredicateKeyPathWorkoutTotalDistance";
NSString* const HKPredicateKeyPathWorkoutTotalEnergyBurned = @"HKPredicateKeyPathWorkoutTotalEnergyBurned";
NSString* const HKPredicateKeyPathWorkoutType = @"HKPredicateKeyPathWorkoutType";

@implementation HKWorkout

/**
 @Status Stub
 @Notes
*/
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType startDate:(NSDate*)startDate endDate:(NSDate*)endDate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                               duration:(NSTimeInterval)duration
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                               metadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                          workoutEvents:(NSArray*)workoutEvents
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                               metadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                               duration:(NSTimeInterval)duration
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                                 device:(HKDevice*)device
                               metadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)workoutWithActivityType:(HKWorkoutActivityType)workoutActivityType
                              startDate:(NSDate*)startDate
                                endDate:(NSDate*)endDate
                          workoutEvents:(NSArray*)workoutEvents
                      totalEnergyBurned:(HKQuantity*)totalEnergyBurned
                          totalDistance:(HKQuantity*)totalDistance
                                 device:(HKDevice*)device
                               metadata:(NSDictionary*)metadata {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
