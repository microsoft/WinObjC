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
#import <HealthKit/HKQuery.h>
#import <HealthKit/HKStatistics.h>

@class HKQuantityType;
@class NSPredicate;
@class NSDate;
@class NSDateComponents;
@class HKStatisticsCollection;
@class NSError;
@class HKStatistics;

HEALTHKIT_EXPORT_CLASS
@interface HKStatisticsCollectionQuery : HKQuery
- (instancetype)initWithQuantityType:(HKQuantityType*)quantityType
             quantitySamplePredicate:(NSPredicate*)quantitySamplePredicate
                             options:(HKStatisticsOptions)options
                          anchorDate:(NSDate*)anchorDate
                  intervalComponents:(NSDateComponents*)intervalComponents STUB_METHOD;
@property (copy, nonatomic, nonnull) void (^initialResultsHandler)(HKStatisticsCollectionQuery*, HKStatisticsCollection*, NSError*)
    STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^statisticsUpdateHandler)
    (HKStatisticsCollectionQuery*, HKStatistics*, HKStatisticsCollection*, NSError*) STUB_PROPERTY;
@property (readonly, strong) NSDate* anchorDate STUB_PROPERTY;
@property (readonly, copy) NSDateComponents* intervalComponents STUB_PROPERTY;
@property (readonly) HKStatisticsOptions options STUB_PROPERTY;
@end
