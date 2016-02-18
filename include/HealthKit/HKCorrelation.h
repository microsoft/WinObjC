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
#import <HealthKit/HKSample.h>

@class HKCorrelationType;
@class HKObjectType;
@class NSDate;
@class NSSet;
@class NSDictionary;
@class HKDevice;

HEALTHKIT_EXPORT_CLASS
@interface HKCorrelation : HKSample <NSSecureCoding>
+ (instancetype)correlationWithType:(HKCorrelationType*)correlationType
                          startDate:(NSDate*)startDate
                            endDate:(NSDate*)endDate
                            objects:(NSSet*)objects STUB_METHOD;
+ (instancetype)correlationWithType:(HKCorrelationType*)correlationType
                          startDate:(NSDate*)startDate
                            endDate:(NSDate*)endDate
                            objects:(NSSet*)objects
                           metadata:(NSDictionary*)metadata STUB_METHOD;
+ (instancetype)correlationWithType:(HKCorrelationType*)correlationType
                          startDate:(NSDate*)startDate
                            endDate:(NSDate*)endDate
                            objects:(NSSet*)objects
                             device:(HKDevice*)device
                           metadata:(NSDictionary*)metadata STUB_METHOD;
@property (readonly) HKCorrelationType* correlationType STUB_PROPERTY;
@property (readonly, copy) NSSet* objects STUB_PROPERTY;
- (NSSet*)objectsForType:(HKObjectType*)objectType STUB_METHOD;
@end
