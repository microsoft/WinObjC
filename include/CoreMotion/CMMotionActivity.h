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

#import <CoreMotion/CMLogItem.h>
#import <CoreMotion/CoreMotionExport.h>

#import <Foundation/NSObject.h>

#import <objc/runtime.h>

@class NSDate;

typedef enum : NSInteger {
    CMMotionActivityConfidenceLow = 0,
    CMMotionActivityConfidenceMedium,
    CMMotionActivityConfidenceHigh
} CMMotionActivityConfidence;

COREMOTION_EXPORT_CLASS
@interface CMMotionActivity : CMLogItem <NSCopying, NSSecureCoding>
@property (readonly, nonatomic) BOOL stationary STUB_PROPERTY;
@property (readonly, nonatomic) BOOL walking STUB_PROPERTY;
@property (readonly, nonatomic) BOOL running STUB_PROPERTY;
@property (readonly, nonatomic) BOOL automotive STUB_PROPERTY;
@property (readonly, nonatomic) BOOL cycling STUB_PROPERTY;
@property (readonly, nonatomic) BOOL unknown STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* startDate STUB_PROPERTY;
@property (readonly, nonatomic) CMMotionActivityConfidence confidence STUB_PROPERTY;
@end
