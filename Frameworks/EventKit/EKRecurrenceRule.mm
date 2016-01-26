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

#import <EventKit/EKRecurrenceRule.h>
#import <StubReturn.h>

@implementation EKRecurrenceRule
/**
 @Status Stub
 @Notes
*/
- (instancetype)initRecurrenceWithFrequency:(EKRecurrenceFrequency)type interval:(NSInteger)interval end:(EKRecurrenceEnd*)end {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initRecurrenceWithFrequency:(EKRecurrenceFrequency)type
                                   interval:(NSInteger)interval
                              daysOfTheWeek:(NSArray*)days
                             daysOfTheMonth:(NSArray*)monthDays
                            monthsOfTheYear:(NSArray*)months
                             weeksOfTheYear:(NSArray*)weeksOfTheYear
                              daysOfTheYear:(NSArray*)daysOfTheYear
                               setPositions:(NSArray*)setPositions
                                        end:(EKRecurrenceEnd*)end {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
