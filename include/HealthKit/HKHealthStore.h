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
#import <HealthKit/HealthKitConstants.h>

@class NSSet;
@class NSError;
@class HKBiologicalSexObject;
@class HKBloodTypeObject;
@class NSDate;
@class HKFitzpatrickSkinTypeObject;
@class HKObject;
@class HKObjectType;
@class NSArray;
@class NSPredicate;
@class HKWorkout;
@class HKQuantity;
@class HKQuery;
@class NSDictionary;

HEALTHKIT_EXPORT NSString* const HKUserPreferencesDidChangeNotification;

HEALTHKIT_EXPORT_CLASS
@interface HKHealthStore : NSObject
- (HKAuthorizationStatus)authorizationStatusForType:(HKObjectType*)type STUB_METHOD;
+ (BOOL)isHealthDataAvailable STUB_METHOD;
- (void)requestAuthorizationToShareTypes:(NSSet*)typesToShare
                               readTypes:(NSSet*)typesToRead
                              completion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)handleAuthorizationForExtensionWithCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (HKBiologicalSexObject*)biologicalSexWithError:(NSError* _Nullable*)error STUB_METHOD;
- (HKBloodTypeObject*)bloodTypeWithError:(NSError* _Nullable*)error STUB_METHOD;
- (NSDate*)dateOfBirthWithError:(NSError* _Nullable*)error STUB_METHOD;
- (HKFitzpatrickSkinTypeObject*)fitzpatrickSkinTypeWithError:(NSError* _Nullable*)error STUB_METHOD;
- (void)deleteObject:(HKObject*)object withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)deleteObjects:(NSArray*)objects withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)deleteObjectsOfType:(HKObjectType*)objectType
                  predicate:(NSPredicate*)predicate
             withCompletion:(void (^)(BOOL, NSUInteger, NSError*))completion STUB_METHOD;
- (NSDate*)earliestPermittedSampleDate STUB_METHOD;
- (void)saveObject:(HKObject*)object withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)saveObjects:(NSArray*)objects withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)addSamples:(NSArray*)samples toWorkout:(HKWorkout*)workout completion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)splitTotalEnergy:(HKQuantity*)totalEnergy
               startDate:(NSDate*)startDate
                 endDate:(NSDate*)endDate
          resultsHandler:(void (^)(HKQuantity*, HKQuantity*, NSError*))resultsHandler STUB_METHOD;
- (void)executeQuery:(HKQuery*)query STUB_METHOD;
- (void)stopQuery:(HKQuery*)query STUB_METHOD;
- (void)preferredUnitsForQuantityTypes:(NSSet*)quantityTypes completion:(void (^)(NSDictionary*, NSError*))completion STUB_METHOD;
- (void)enableBackgroundDeliveryForType:(HKObjectType*)type
                              frequency:(HKUpdateFrequency)frequency
                         withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)disableBackgroundDeliveryForType:(HKObjectType*)type withCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
- (void)disableAllBackgroundDeliveryWithCompletion:(void (^)(BOOL, NSError*))completion STUB_METHOD;
@end
