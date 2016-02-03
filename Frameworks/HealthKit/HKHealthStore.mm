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

#import <HealthKit/HKHealthStore.h>

NSString* const HKUserPreferencesDidChangeNotification = @"HKUserPreferencesDidChangeNotification";

@implementation HKHealthStore

/**
 @Status Stub
 @Notes
*/
- (HKAuthorizationStatus)authorizationStatusForType:(HKObjectType*)type {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)isHealthDataAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)requestAuthorizationToShareTypes:(NSSet*)typesToShare
                               readTypes:(NSSet*)typesToRead
                              completion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)handleAuthorizationForExtensionWithCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (HKBiologicalSexObject*)biologicalSexWithError:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (HKBloodTypeObject*)bloodTypeWithError:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)dateOfBirthWithError:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (HKFitzpatrickSkinTypeObject*)fitzpatrickSkinTypeWithError:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteObject:(HKObject*)object withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteObjects:(NSArray*)objects withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteObjectsOfType:(HKObjectType*)objectType
                  predicate:(NSPredicate*)predicate
             withCompletion:(void (^)(BOOL, NSUInteger, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSDate*)earliestPermittedSampleDate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveObject:(HKObject*)object withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)saveObjects:(NSArray*)objects withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addSamples:(NSArray*)samples toWorkout:(HKWorkout*)workout completion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)splitTotalEnergy:(HKQuantity*)totalEnergy
               startDate:(NSDate*)startDate
                 endDate:(NSDate*)endDate
          resultsHandler:(void (^)(HKQuantity*, HKQuantity*, NSError*))resultsHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)executeQuery:(HKQuery*)query {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopQuery:(HKQuery*)query {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)preferredUnitsForQuantityTypes:(NSSet*)quantityTypes completion:(void (^)(NSDictionary*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enableBackgroundDeliveryForType:(HKObjectType*)type
                              frequency:(HKUpdateFrequency)frequency
                         withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)disableBackgroundDeliveryForType:(HKObjectType*)type withCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)disableAllBackgroundDeliveryWithCompletion:(void (^)(BOOL, NSError*))completion {
    UNIMPLEMENTED();
}

@end
