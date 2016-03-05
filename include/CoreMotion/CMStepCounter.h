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

@class NSError;
@class NSDate;
@class NSOperationQueue;

typedef void (^CMStepQueryHandler)(NSInteger numberOfSteps, NSError* error);
typedef void (^CMStepUpdateHandler)(NSInteger numberOfSteps, NSDate* timestamp, NSError* error);

COREMOTION_EXPORT_CLASS
@interface CMStepCounter : NSObject
+ (BOOL)isStepCountingAvailable STUB_METHOD;
- (void)startStepCountingUpdatesToQueue:(NSOperationQueue*)queue
                               updateOn:(NSInteger)stepCounts
                            withHandler:(CMStepUpdateHandler)handler STUB_METHOD;
- (void)stopStepCountingUpdates STUB_METHOD;
- (void)queryStepCountStartingFrom:(NSDate*)start
                                to:(NSDate*)end
                           toQueue:(NSOperationQueue*)queue
                       withHandler:(CMStepQueryHandler)handler STUB_METHOD;
@end
