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

@class NSDate;
@class HKQuantityType;
@class NSArray;
@class HKQuantity;
@class HKSource;

typedef enum : NSUInteger {
    HKStatisticsOptionNone = 0,
    HKStatisticsOptionSeparateBySource = 1 << 0,
    HKStatisticsOptionDiscreteAverage = 1 << 1,
    HKStatisticsOptionDiscreteMin = 1 << 2,
    HKStatisticsOptionDiscreteMax = 1 << 3,
    HKStatisticsOptionCumulativeSum = 1 << 4,
} HKStatisticsOptions;

HEALTHKIT_EXPORT_CLASS
@interface HKStatistics : NSObject <NSCopying, NSSecureCoding>
@property (readonly, strong) NSDate* startDate STUB_PROPERTY;
@property (readonly, strong) NSDate* endDate STUB_PROPERTY;
@property (readonly, strong) HKQuantityType* quantityType STUB_PROPERTY;
@property (readonly, strong) NSArray* sources STUB_PROPERTY;
- (HKQuantity*)averageQuantity STUB_METHOD;
- (HKQuantity*)averageQuantityForSource:(HKSource*)source STUB_METHOD;
- (HKQuantity*)maximumQuantity STUB_METHOD;
- (HKQuantity*)maximumQuantityForSource:(HKSource*)source STUB_METHOD;
- (HKQuantity*)minimumQuantity STUB_METHOD;
- (HKQuantity*)minimumQuantityForSource:(HKSource*)source STUB_METHOD;
- (HKQuantity*)sumQuantity STUB_METHOD;
- (HKQuantity*)sumQuantityForSource:(HKSource*)source STUB_METHOD;
@end
