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

#import <StubReturn.h>

#import <HomeKit/HMTimerTrigger.h>
#import "AssertARCEnabled.h"

@implementation HMTimerTrigger

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithName:(NSString*)name
                    fireDate:(NSDate*)fireDate
                    timeZone:(NSTimeZone*)timeZone
                  recurrence:(NSDateComponents*)recurrence
          recurrenceCalendar:(NSCalendar*)recurrenceCalendar {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateFireDate:(NSDate*)fireDate completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateRecurrence:(NSDateComponents*)recurrence completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)updateTimeZone:(NSTimeZone*)timeZone completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

@end
