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

@class HKQueryAnchor;
@class HKSampleType;
@class NSPredicate;
@class NSArray;
@class NSError;

#define HKAnchoredObjectQueryNoAnchor (0)

HEALTHKIT_EXPORT_CLASS
@interface HKAnchoredObjectQuery : HKQuery

- (instancetype)initWithType:(HKSampleType*)type
                   predicate:(NSPredicate*)predicate
                      anchor:(NSUInteger)anchor
                       limit:(NSUInteger)limit
           completionHandler:(void (^)(HKAnchoredObjectQuery*, NSArray*, NSUInteger, NSError*))handler STUB_METHOD;

- (instancetype)initWithType:(HKSampleType*)type
                   predicate:(NSPredicate*)predicate
                      anchor:(HKQueryAnchor*)anchor
                       limit:(NSUInteger)limit
              resultsHandler:(void (^)(HKAnchoredObjectQuery*, NSArray*, NSArray*, HKQueryAnchor*, NSError*))handler STUB_METHOD;

@property (copy, nonatomic, nonnull) void (^updateHandler)(HKAnchoredObjectQuery*, NSArray*, NSArray*, HKQueryAnchor*, NSError*)
    STUB_PROPERTY;

@end
