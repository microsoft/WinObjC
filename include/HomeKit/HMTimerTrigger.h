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

#import <HomeKit/HomeKitExport.h>
#import <Foundation/NSObject.h>
#import <HomeKit/HMTrigger.h>

@class NSCalendar;
@class NSDate;
@class NSDateComponents;
@class NSError;
@class NSString;
@class NSTimeZone;

HOMEKIT_EXPORT_CLASS
@interface HMTimerTrigger : HMTrigger
- (instancetype)initWithName:(NSString*)name
                    fireDate:(NSDate*)fireDate
                    timeZone:(NSTimeZone*)timeZone
                  recurrence:(NSDateComponents*)recurrence
          recurrenceCalendar:(NSCalendar*)recurrenceCalendar STUB_METHOD;
@property (readonly, copy, nonatomic) NSDate* fireDate STUB_PROPERTY;
- (void)updateFireDate:(NSDate*)fireDate completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSDateComponents* recurrence STUB_PROPERTY;
- (void)updateRecurrence:(NSDateComponents*)recurrence completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSCalendar* recurrenceCalendar STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSTimeZone* timeZone STUB_PROPERTY;
- (void)updateTimeZone:(NSTimeZone*)timeZone completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@end
