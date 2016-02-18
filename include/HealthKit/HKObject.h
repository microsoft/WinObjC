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

@class NSString;
@class NSUUID;
@class NSDictionary;
@class HKDevice;
@class HKSource;
@class HKSourceRevision;

HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathUUID;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathSource;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathMetadata;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathCorrelation;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathWorkout;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathDevice;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathSourceRevision;

HEALTHKIT_EXPORT_CLASS
@interface HKObject : NSObject <NSSecureCoding>
@property (readonly, strong) NSUUID* UUID STUB_PROPERTY;
@property (readonly, copy) NSDictionary* metadata STUB_PROPERTY;
@property (readonly, strong) HKDevice* device STUB_PROPERTY;
@property (readonly, strong) HKSource* source STUB_PROPERTY;
@property (readonly, strong) HKSourceRevision* sourceRevision STUB_PROPERTY;
@end
