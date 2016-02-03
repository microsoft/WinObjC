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
#import <HealthKit/HKObject.h>

@class NSString;
@class NSDate;
@class HKSampleType;

HEALTHKIT_EXPORT NSString* const HKSampleSortIdentifierStartDate;
HEALTHKIT_EXPORT NSString* const HKSampleSortIdentifierEndDate;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathStartDate;
HEALTHKIT_EXPORT NSString* const HKPredicateKeyPathEndDate;

HEALTHKIT_EXPORT_CLASS
@interface HKSample : HKObject <NSSecureCoding>
@property (readonly, strong) NSDate* startDate STUB_PROPERTY;
@property (readonly, strong) NSDate* endDate STUB_PROPERTY;
@property (readonly, strong) HKSampleType* sampleType STUB_PROPERTY;
@end
