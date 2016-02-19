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

@class CMMotionActivity;
@class NSArray;
@class NSError;
@class NSOperationQueue;
@class NSDate;

typedef void (^CMMotionActivityHandler)(CMMotionActivity* activity);
typedef void (^CMMotionActivityQueryHandler)(NSArray* activities, NSError* error);

COREMOTION_EXPORT_CLASS
@interface CMMotionActivityManager : NSObject
+ (BOOL)isActivityAvailable STUB_METHOD;
- (void)startActivityUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMMotionActivityHandler)handler STUB_METHOD;
- (void)stopActivityUpdates STUB_METHOD;
- (void)queryActivityStartingFromDate:(NSDate*)start
                               toDate:(NSDate*)end
                              toQueue:(NSOperationQueue*)queue
                          withHandler:(CMMotionActivityQueryHandler)handler STUB_METHOD;
@end
