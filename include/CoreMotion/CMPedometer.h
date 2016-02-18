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

#import <CoreMotion/CoreMotionExport.h>

#import <Foundation/NSObject.h>

#import <objc/runtime.h>

@class CMPedometerData;
@class NSError;
@class NSDate;

typedef void (^CMPedometerHandler)(CMPedometerData* pedometerData, NSError* error);

COREMOTION_EXPORT_CLASS
@interface CMPedometer : NSObject
+ (BOOL)isStepCountingAvailable STUB_METHOD;
+ (BOOL)isDistanceAvailable STUB_METHOD;
+ (BOOL)isFloorCountingAvailable STUB_METHOD;
+ (BOOL)isPaceAvailable STUB_METHOD;
+ (BOOL)isCadenceAvailable STUB_METHOD;
- (void)startPedometerUpdatesFromDate:(NSDate*)start withHandler:(CMPedometerHandler)handler STUB_METHOD;
- (void)stopPedometerUpdates STUB_METHOD;
- (void)queryPedometerDataFromDate:(NSDate*)start toDate:(NSDate*)end withHandler:(CMPedometerHandler)handler STUB_METHOD;
@end
