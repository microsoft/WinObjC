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

#import <EventKit/EKObject.h>
#import <EventKit/EventKitExport.h>

#import <Foundation/NSObject.h>

@class NSDate;
@class EKStructuredLocation;

typedef enum {
    EKAlarmTypeDisplay,
    EKAlarmTypeAudio,
    EKAlarmTypeProcedure,
    EKAlarmTypeEmail,
} EKAlarmType;

typedef enum {
    EKAlarmProximityNone,
    EKAlarmProximityEnter,
    EKAlarmProximityLeave,
} EKAlarmProximity;

EVENTKIT_EXPORT_CLASS
@interface EKAlarm : EKObject <NSCopying, NSObject>
+ (EKAlarm*)alarmWithAbsoluteDate:(NSDate*)date STUB_METHOD;
+ (EKAlarm*)alarmWithRelativeOffset:(NSTimeInterval)offset STUB_METHOD;
@property (copy, nonatomic) NSDate* absoluteDate STUB_PROPERTY;
@property (nonatomic) NSTimeInterval relativeOffset STUB_PROPERTY;
@property (copy, nonatomic) EKStructuredLocation* structuredLocation STUB_PROPERTY;
@property (nonatomic) EKAlarmProximity proximity STUB_PROPERTY;
@end
