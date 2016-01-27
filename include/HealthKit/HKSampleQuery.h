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

@class HKSampleType;
@class NSPredicate;
@class NSArray;
@class NSError;

#define HKObjectQueryNoLimit (0)

HEALTHKIT_EXPORT_CLASS
@interface HKSampleQuery : HKQuery
- (instancetype)initWithSampleType:(HKSampleType*)sampleType
                         predicate:(NSPredicate*)predicate
                             limit:(NSUInteger)limit
                   sortDescriptors:(NSArray*)sortDescriptors
                    resultsHandler:(void (^)(HKSampleQuery*, NSArray*, NSError*))resultsHandler STUB_METHOD;
@property (readonly) NSUInteger limit STUB_PROPERTY;
@property (readonly, copy) NSArray* sortDescriptors STUB_PROPERTY;
@end
