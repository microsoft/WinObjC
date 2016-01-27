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

#import <HealthKit/HKQuery.h>

NSString* const HKDevicePropertyKeyName = @"HKDevicePropertyKeyName";
NSString* const HKDevicePropertyKeyManufacturer = @"HKDevicePropertyKeyManufacturer";
NSString* const HKDevicePropertyKeyModel = @"HKDevicePropertyKeyModel";
NSString* const HKDevicePropertyKeyHardwareVersion = @"HKDevicePropertyKeyHardwareVersion";
NSString* const HKDevicePropertyKeyFirmwareVersion = @"HKDevicePropertyKeyFirmwareVersion";
NSString* const HKDevicePropertyKeySoftwareVersion = @"HKDevicePropertyKeySoftwareVersion";
NSString* const HKDevicePropertyKeyLocalIdentifier = @"HKDevicePropertyKeyLocalIdentifier";
NSString* const HKDevicePropertyKeyUDIDeviceIdentifier = @"HKDevicePropertyKeyUDIDeviceIdentifier";

@implementation HKQuery

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectWithUUID:(NSUUID*)UUID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithUUIDs:(NSSet*)UUIDs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsFromSource:(HKSource*)source {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsFromSources:(NSSet*)sources {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsFromDevices:(NSSet*)devices {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithDeviceProperty:(NSString*)key allowedValues:(NSSet*)allowedValues {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsFromSourceRevisions:(NSSet*)sourceRevisions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key allowedValues:(NSArray*)allowedValues {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithMetadataKey:(NSString*)key operatorType:(NSPredicateOperatorType)operatorType value:(id)value {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsWithNoCorrelation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForSamplesWithStartDate:(NSDate*)startDate endDate:(NSDate*)endDate options:(HKQueryOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForQuantitySamplesWithOperatorType:(NSPredicateOperatorType)operatorType quantity:(HKQuantity*)quantity {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForCategorySamplesWithOperatorType:(NSPredicateOperatorType)operatorType value:(NSInteger)value {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForObjectsFromWorkout:(HKWorkout*)workout {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType duration:(NSTimeInterval)duration {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType totalDistance:(HKQuantity*)totalDistance {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForWorkoutsWithOperatorType:(NSPredicateOperatorType)operatorType
                                   totalEnergyBurned:(HKQuantity*)totalEnergyBurned {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForWorkoutsWithWorkoutActivityType:(HKWorkoutActivityType)workoutActivityType {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
