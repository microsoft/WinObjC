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

@class HKCategoryType;
@class NSString;
@class HKCharacteristicType;
@class HKCorrelationType;
@class HKQuantityType;
@class HKWorkoutType;

HEALTHKIT_EXPORT_CLASS
@interface HKObjectType : NSObject <NSCopying, NSSecureCoding>
+ (HKCategoryType*)categoryTypeForIdentifier:(NSString*)identifier STUB_METHOD;
+ (HKCharacteristicType*)characteristicTypeForIdentifier:(NSString*)identifier STUB_METHOD;
+ (HKCorrelationType*)correlationTypeForIdentifier:(NSString*)identifier STUB_METHOD;
+ (HKQuantityType*)quantityTypeForIdentifier:(NSString*)identifier STUB_METHOD;
+ (HKWorkoutType*)workoutType STUB_METHOD;
@property (readonly, strong) NSString* identifier STUB_PROPERTY;
@end
