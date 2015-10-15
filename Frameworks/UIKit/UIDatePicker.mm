//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"
#include <UIKit/UIKit.h>

static const int MAX_DATEPICKER_COMPONENTS = 4;

#define MAX_YEAR_RANGE 1000
#define MAX_DAY_RANGE 1000

#define YEAR_START (2010 - (MAX_YEAR_RANGE / 2))

void fatalMsg(const char* err) {
    assert(0);
}

@implementation UIDatePicker {
    idretaintype(NSDate) _date;
    idretaintype(NSDate) _dayStartDate;
    idretaintype(UIPickerView) _pickerView;
    idretaintype(NSArray) _months, _shortMonths;
    idretaintype(NSArray) _weekdays;
    idretaintype(NSDate) _dayStartTime;
    UIDatePickerMode _mode;
    idretaintype(NSDate) __minimumDate, __maximumDate;
    idretaintype(NSString) _hoursLabel, _minutesLabel;
    bool _didSnapTime;
}

static void populateDates(UIDatePicker* self) {
    CGRect pos;
    pos = [self bounds];
    pos.origin.x = 0;
    pos.origin.y = 0;
    self->_pickerView.attach([[UIPickerView alloc] initWithFrame:pos]);
    [self->_pickerView setAutoresizingMask:UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth];

    [self->_pickerView setDataSource:(id<UIPickerViewDataSource>)self];
    [self->_pickerView setDelegate:(id<UIPickerViewDelegate>)self];
    [self setAutoresizesSubviews:TRUE];
    [self addSubview:self->_pickerView];

    self->_months.attach([NSMutableArray new]);
    [self->_months addObject:@"January"];
    [self->_months addObject:@"February"];
    [self->_months addObject:@"March"];
    [self->_months addObject:@"April"];
    [self->_months addObject:@"May"];
    [self->_months addObject:@"June"];
    [self->_months addObject:@"July"];
    [self->_months addObject:@"August"];
    [self->_months addObject:@"September"];
    [self->_months addObject:@"October"];
    [self->_months addObject:@"November"];
    [self->_months addObject:@"December"];

    self->_shortMonths.attach([NSMutableArray new]);
    [self->_shortMonths addObject:@"Jan"];
    [self->_shortMonths addObject:@"Feb"];
    [self->_shortMonths addObject:@"Mar"];
    [self->_shortMonths addObject:@"Apr"];
    [self->_shortMonths addObject:@"May"];
    [self->_shortMonths addObject:@"Jun"];
    [self->_shortMonths addObject:@"Jul"];
    [self->_shortMonths addObject:@"Aug"];
    [self->_shortMonths addObject:@"Sep"];
    [self->_shortMonths addObject:@"Oct"];
    [self->_shortMonths addObject:@"Nov"];
    [self->_shortMonths addObject:@"Dec"];

    self->_weekdays.attach([NSMutableArray new]);
    [self->_weekdays addObject:@"Sun"];
    [self->_weekdays addObject:@"Mon"];
    [self->_weekdays addObject:@"Tue"];
    [self->_weekdays addObject:@"Wed"];
    [self->_weekdays addObject:@"Thur"];
    [self->_weekdays addObject:@"Fri"];
    [self->_weekdays addObject:@"Sat"];
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    [super initWithCoder:coder];
    populateDates(self);
    return self;
}

- (instancetype)initWithFrame:(CGRect)pos {
    pos.size.width = 320.0f;
    pos.size.height = 216.0f;
    [super initWithFrame:pos];
    populateDates(self);
    [self setDate:[NSDate date]];

    return self;
}

- (void)setDatePickerMode:(UIDatePickerMode)mode {
    _mode = mode;
    [_pickerView reloadAllComponents];

    id date = [self date];
    switch (_mode) {
        case UIDatePickerModeTime:
            [_pickerView _setAlignment:UITextAlignmentLeft forComponent:0];
            setTime(self, date);
            break;
        case UIDatePickerModeDate:
            [_pickerView _setAlignment:UITextAlignmentRight forComponent:0];
            setDate(self, date);
            break;
        case UIDatePickerModeDateAndTime:
            [_pickerView _setAlignment:UITextAlignmentRight forComponent:0];
            setTime(self, date, 1);
            setDay(self, date);
            break;
        case UIDatePickerModeCountDownTimer:
            [_pickerView _setAlignment:UITextAlignmentLeft forComponent:0];
            CGRect frame = { 100, 88, 50, 50 };

            _hoursLabel = [[UILabel alloc] initWithFrame:frame];
            [self addSubview:(id)_hoursLabel];
            [_hoursLabel setBackgroundColor:[[UIColor clearColor] CGColor]];
            [_hoursLabel setText:@"hours"];

            frame.origin.x += 100;
            _minutesLabel = [[UILabel alloc] initWithFrame:frame];
            [_minutesLabel setBackgroundColor:[[UIColor clearColor] CGColor]];
            [self addSubview:(id)_minutesLabel];
            [_minutesLabel setText:@"min"];

            setTimer(self);
    }

    _dayStartDate = nil;
}

- (UIDatePickerMode)datePickerMode {
    return _mode;
}

- (void)setDate:(id)date {
    [self setDate:date animated:FALSE];
}

static void setPickerRow(UIDatePicker* self, int row, int component, BOOL animated) {
    [self->_pickerView selectRow:row inComponent:component animated:animated];
}

static void setDate(UIDatePicker* self, NSDate* date, BOOL animated = FALSE) {
    self->_date = date;

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(NSDate*)self->_date];

    setPickerRow(self, [components month] - 1, 0, animated);
    setPickerRow(self, [components day] - 1, 1, animated);
    setPickerRow(self, [components year] - YEAR_START, 2, animated);
}

static bool isDateInRange(UIDatePicker* self, id date) {
    if (self->_maximumDate != nil) {
        if ([date compare:(NSDate*)self->_maximumDate] == 1) {
            return false;
        }
    }
    if (self->_minimumDate != nil) {
        if ([date compare:(NSDate*)self->_minimumDate] == -1) {
            return false;
        }
    }

    return true;
}

NSDate* clampDate(UIDatePicker* self, NSDate* date) {
    NSDate* ret = date;

    if (self->_maximumDate != nil) {
        if ([ret compare:(NSDate*)self->_maximumDate] == 1) {
            ret = self->_maximumDate;
        }
    }
    if (self->_minimumDate != nil) {
        if ([ret compare:(NSDate*)self->_minimumDate] == -1) {
            ret = self->_minimumDate;
        }
    }

    return ret;
}

static void setTime(UIDatePicker* self, NSDate* date, int component = 0, BOOL animated = FALSE) {
    self->_date = date;

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit fromDate:(NSDate*)self->_date];

    int hour = [components hour];
    int minute = [components minute];

    [self->_pickerView selectRow:(hour - 1) % 12 inComponent:component + 0 animated:animated];
    [self->_pickerView selectRow:minute inComponent:component + 1 animated:animated];
    [self->_pickerView selectRow:hour < 12 ? 0 : 1 inComponent:component + 2 animated:animated];
}

static void setTimer(UIDatePicker* self) {
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(NSDate*)self->_date];

    [components setHour:0];
    [components setMinute:0];
    [components setSecond:0];

    self->_date = [calendar dateFromComponents:components];

    [self->_pickerView selectRow:0 inComponent:0 animated:FALSE];
    [self->_pickerView selectRow:0 inComponent:1 animated:FALSE];
}

void setDay(UIDatePicker* self, id date) {
    self->_date = date;
    [self->_pickerView selectRow:MAX_DAY_RANGE / 2 inComponent:0 animated:FALSE];
}

- (void)setDate:(NSDate*)date animated:(BOOL)animated {
    switch (_mode) {
        case UIDatePickerModeTime:
            setTime(self, date);
            break;
        case UIDatePickerModeDate:
            setDate(self, date);
            break;
        case UIDatePickerModeCountDownTimer:
            setTimer(self);
            break;
        case UIDatePickerModeDateAndTime:
            setTime(self, date, 1);
            setDay(self, date);
            _dayStartDate = nil;
            [_pickerView reloadComponent:0];
            break;
    }
}

- (void)setTimeZone:(NSTimeZone*)timeZone {
}

- (void)setLocale:(NSLocale*)locale {
}

- (void)setCalendar:(NSCalendar*)calendar {
}

- (NSDate*)date {
    if (_date == nil) {
        _date = [NSDate date];
        NSCalendar* calendar = [NSCalendar currentCalendar];
        NSDateComponents* components =
            [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(NSDate*)_date];

        _date = [calendar dateFromComponents:components];
    }
    return _date;
}

static void didSelectDate(UIDatePicker* self, int row, int component) {
    NSCalendar* calendar = [NSCalendar currentCalendar];

    unsigned month = [self->_pickerView selectedRowInComponent:0] + 1;
    unsigned day = [self->_pickerView selectedRowInComponent:1] + 1;
    unsigned year = [self->_pickerView selectedRowInComponent:2] + YEAR_START;

    //  Check if the day is invalid
    bool isInvalid = false;

    NSDateComponents* componentsCheck = [NSDateComponents new];
    [componentsCheck setMonth:month];
    [componentsCheck setYear:year];
    [componentsCheck setHour:17];

    NSDate* dateCheck = [calendar dateFromComponents:componentsCheck];
    [componentsCheck release];

    NSRange range;

    range = [calendar rangeOfUnit:NSDayCalendarUnit inUnit:NSMonthCalendarUnit forDate:(NSDate*)dateCheck];

    if (day < range.location) {
        day = range.location;
        isInvalid = true;
    }

    if (day >= (range.location + range.length)) {
        day = (range.location + range.length) - 1;
        isInvalid = true;
    }

    NSDateComponents* components = [NSDateComponents new];
    [components setMonth:month];
    [components setDay:day];
    [components setYear:year];

    // This had been here for a long time but now breaks date comparison because if
    // the current time was before 5pm, it would be "less than" the date produced.
    //[components setHour:17];

    NSDate* newDate = [calendar dateFromComponents:components];
    NSDate* clampedDate = clampDate(self, newDate);

    if (![clampedDate isEqual:newDate]) {
        isInvalid = true;
        self->_date = clampedDate;
    } else {
        self->_date = clampedDate;
    }
    [self->_pickerView invalidateAllComponents];

    [self sendEvent:self mask:UIControlEventValueChanged];

    if (isInvalid) {
        if (!self->_didSnapTime) {
            setDate(self, self->_date, TRUE);
        }
        self->_didSnapTime = true; //  We only want to snap the time once, until the user selects a valid time
    } else {
        self->_didSnapTime = false; //  Valid time has been selected, we can now snap to a valid time
    }
    if (component == 0 || component == 2) {
        //  Selected a month/year, need to re-color days
        [self->_pickerView invalidateAllComponents];
    }
}

void didSelectTime(UIDatePicker* self, int row, int component) {
    int hour = [self->_pickerView selectedRowInComponent:0] + 1;
    int minute = [self->_pickerView selectedRowInComponent:1];
    bool am = [self->_pickerView selectedRowInComponent:2] == 0;

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(NSDate*)self->_date];

    if (am) {
        hour %= 12;
    } else if (hour != 12) {
        hour += 12;
    }

    [components setHour:hour];
    [components setMinute:minute];

    NSDate* newDate = [calendar dateFromComponents:components];
    NSDate* clampedDate = clampDate(self, newDate);
    self->_date = clampedDate;
    if (![clampedDate isEqual:newDate]) {
        if (!self->_didSnapTime) {
            setTime(self, self->_date, 0, TRUE);
        }
        self->_didSnapTime = true; //  We only want to snap the time once, until the user selects a valid time
    } else {
        self->_didSnapTime = false; //  Valid time has been selected, we can now snap to a valid time
    }
    [self->_pickerView invalidateAllComponents];

    [self sendEvent:self mask:UIControlEventValueChanged];
}

static void didSelectTimer(UIDatePicker* self, int row, int component) {
    int hour = [self->_pickerView selectedRowInComponent:0];
    int minute = [self->_pickerView selectedRowInComponent:1];

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(NSDate*)self->_date];
    [components setHour:hour];
    [components setMinute:minute];
    [components setSecond:0];

    self->_date = [calendar dateFromComponents:components];
    [self sendEvent:self mask:UIControlEventValueChanged];
}

static void didSelectDateAndTime(UIDatePicker* self, int row, int component) {
    int day = [self->_pickerView selectedRowInComponent:0];
    int hour = [self->_pickerView selectedRowInComponent:1] + 1;
    int minute = [self->_pickerView selectedRowInComponent:2];
    bool am = [self->_pickerView selectedRowInComponent:3] == 0;

    NSCalendar* calendar = [NSCalendar currentCalendar];

    NSDateComponents* calcComponents = [NSDateComponents new];
    [calcComponents setDay:day];
    NSDate* daySelected = [calendar dateByAddingComponents:calcComponents toDate:(NSDate*)self->_dayStartTime options:0];
    [calcComponents release];

    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:(id)daySelected];

    if (am) {
        hour %= 12;
    } else if (hour != 12) {
        hour += 12;
    }

    [components setHour:hour];
    [components setMinute:minute];

    self->_date = [calendar dateFromComponents:components];
    [self sendEvent:self mask:UIControlEventValueChanged];
}

- (void)pickerView:(UIPickerView*)picker didSelectRow:(int)row inComponent:(int)component {
    switch (_mode) {
        case UIDatePickerModeTime:
            didSelectTime(self, row, component);
            break;
        case UIDatePickerModeCountDownTimer:
            didSelectTimer(self, row, component);
            break;
        case UIDatePickerModeDate:
            didSelectDate(self, row, component);
            break;
        case UIDatePickerModeDateAndTime:
            didSelectDateAndTime(self, row, component);
            break;
    }
}

- (NSUInteger)numberOfComponentsInPickerView:(id)picker {
    switch (_mode) {
        case UIDatePickerModeCountDownTimer:
            return 2;

        case UIDatePickerModeDateAndTime:
            return 4;

        default:
            return 3;
    }
}

static int numRowsDate(int component) {
    switch (component) {
        case 0: // Month
            return 12;
        case 1: // Day
            return 31;
        case 2: // Year
            return MAX_YEAR_RANGE;
    }
    fatalMsg("Component out of range");
}

static NSDateComponents* finishTime(UIDatePicker* self) {
    NSCalendar* calendar = [NSCalendar currentCalendar];

    NSDateComponents* finishDate;
    if (self->_maximumDate) {
        finishDate = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit fromDate:(NSDate*)self->_maximumDate];
    } else {
        finishDate = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit fromDate:(NSDate*)self->_date];
        [finishDate setHour:23];
        [finishDate setMinute:59];
    }

    return finishDate;
}

NSDateComponents* minTime(UIDatePicker* self) {
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* diffDate = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit
                                             fromDate:(NSDate*)self->_minimumDate
                                               toDate:(NSDate*)self->_maximumDate
                                              options:0];

    NSDateComponents* finishDate = finishTime(self);

    NSDateComponents* startDate;

    // We default the start date to beginning of day if we're spanning days.
    if (self->_minimumDate && [finishDate hour] > [diffDate hour]) {
        startDate = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit fromDate:(NSDate*)self->_minimumDate];
    } else {
        // With no minimum date we start at the beginning of the day:
        startDate = [calendar components:NSHourCalendarUnit | NSMinuteCalendarUnit fromDate:(NSDate*)self->_date];
        [startDate setHour:0];
        [startDate setMinute:0];
    }

    return startDate;
}

int numRowsTime(int component) {
    switch (component) {
        case 0: // Hours
            return 12;
        case 1: // Minutes
            return 60;
        case 2: // AM/PM
            return 2;
    }
    fatalMsg("Component out of range");
}

int numRowsTimer(int component) {
    switch (component) {
        case 0: // Hours
            return 12;
        case 1: // Minutes
            return 60;
    }
    fatalMsg("Component out of range");
}

int numRowsDay() {
    return MAX_DAY_RANGE;
}

- (NSUInteger)pickerView:(id)picker numberOfRowsInComponent:(int)component {
    switch (_mode) {
        case UIDatePickerModeTime:
            return numRowsTime(component);
        case UIDatePickerModeDate:
            return numRowsDate(component);
        case UIDatePickerModeCountDownTimer:
            return numRowsTimer(component);
        case UIDatePickerModeDateAndTime:
            if (component > 0) {
                return numRowsTime(component - 1);
            }
            return numRowsDay();
    }

    return 0;
}

static float rowWidthDate(int component) {
    switch (component) {
        case 0:
            return 150.0f;
        case 1:
            return 50.0f;
        case 2:
            return 100.0f;
        default:
            fatalMsg("Component out of range");
    }
}

- (float)pickerView:(UIPickerView*)picker widthForComponent:(int)component {
    switch (_mode) {
        case UIDatePickerModeTime:
            return 50.f;
        case UIDatePickerModeCountDownTimer:
            return 100.f;
        case UIDatePickerModeDate:
            return rowWidthDate(component);
        case UIDatePickerModeDateAndTime:
            if (component > 0) {
                return 50.f;
            }
            return 145.0f;
    }

    return 0;
}

static NSString* titleForDateRow(UIDatePicker* self, unsigned row, int component, id* color) {
    id ret = nil;
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit
                    fromDate:(id)self->_date];

    switch (component) {
        case 0:
            [components setMonth:row + 1];
            ret = [self->_months objectAtIndex:row];
            break;
        case 1:
            [components setDay:row + 1];
            ret = [NSString stringWithFormat:@"%d", row + 1];
            break;
        case 2:
            [components setYear:YEAR_START + row];
            ret = [NSString stringWithFormat:@"%d", YEAR_START + row];
            break;
        default:
            fatalMsg("Component out of range");
    }

    bool isValid = true;
    if (component == 1) {
        //  Figure out if this date combination is valid
        NSRange range;

        range = [calendar rangeOfUnit:NSDayCalendarUnit inUnit:NSMonthCalendarUnit forDate:(NSDate*)self->_date];

        unsigned day = row + 1;

        if (day < range.location || day >= (range.location + range.length)) {
            isValid = false;
        }
    }

    if (isValid) {
        id newDate = [calendar dateFromComponents:components];
        if (!isDateInRange(self, newDate)) {
            isValid = false;
        }
    }

    if (isValid) {
        *color = [UIColor blackColor];
    } else {
        *color = [UIColor lightGrayColor];
    }

    return ret;
}

static id titleForTimeRow(UIDatePicker* self, int row, int component, UIColor** color) {
    id ret = nil;

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components =
        [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSHourCalendarUnit | NSMinuteCalendarUnit
                    fromDate:(NSDate*)self->_date];
    int hour = [components hour];

    switch (component) {
        case 0: { // Hours
            int am = hour < 12;

            hour = row + 1;

            if (am) {
                hour %= 12;
            } else if (hour != 12) {
                hour += 12;
            }
            [components setHour:hour];
            ret = [NSString stringWithFormat:@"%d", row + 1];
        } break;
        case 1: // Minutes
            [components setMinute:row];
            ret = [NSString stringWithFormat:@"%02d", row];
            break;
        case 2: // AM/PM
            if (row == 0) {
                if (hour >= 12) {
                    hour -= 12;
                }
            } else {
                if (hour < 12) {
                    hour += 12;
                }
            }
            [components setHour:hour];
            ret = row == 0 ? @"AM" : @"PM";
            break;
        default:
            fatalMsg("Component out of range");
    }

    if (color) {
        id newDate = [calendar dateFromComponents:components];
        if (isDateInRange(self, newDate)) {
            *color = [UIColor blackColor];
        } else {
            *color = [UIColor lightGrayColor];
        }
    }

    return ret;
}

static NSString* titleForTimerRow(int row, int component) {
    switch (component) {
        case 0:
        case 1:
            return [NSString stringWithFormat:@"%d", row];
        default:
            fatalMsg("Component out of range");
    }
}

static NSString* titleForDayRow(UIDatePicker* self, int row) {
    if (self->_dayStartDate == nil) {
        self->_dayStartDate = self->_date;
    }
    NSDate* curDate = self->_dayStartDate;
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* components = [NSDateComponents new];
    [components setDay:-(MAX_DAY_RANGE / 2)];
    NSDate* startDate = [calendar dateByAddingComponents:components toDate:curDate options:0];
    self->_dayStartTime = startDate;

    [components setDay:row];
    NSDate* retDate = [calendar dateByAddingComponents:components toDate:startDate options:0];
    NSDateComponents* retDateComponents =
        [calendar components:NSDayCalendarUnit | NSMonthCalendarUnit | NSWeekdayCalendarUnit fromDate:retDate];

    int day = [retDateComponents day];
    int month = [retDateComponents month];
    int weekday = [retDateComponents weekday];
    [components release];

    NSString* nameOfWeekday = [self->_weekdays objectAtIndex:weekday - 1];
    NSString* nameOfMonth = [self->_shortMonths objectAtIndex:month - 1];
    NSString* ret = [NSString stringWithFormat:@"%@ %@ %d", nameOfWeekday, nameOfMonth, day];

    return ret;
}

- (NSString*)pickerView:(UIDatePicker*)picker titleForRow:(unsigned)row forComponent:(int)component withColor:(UIColor**)color {
    switch (_mode) {
        case UIDatePickerModeTime:
            return titleForTimeRow(self, row, component, color);
        case UIDatePickerModeCountDownTimer:
            *color = [UIColor blackColor];
            return titleForTimerRow(row, component);
        case UIDatePickerModeDate:
            return titleForDateRow(self, row, component, color);
        case UIDatePickerModeDateAndTime:
            *color = [UIColor blackColor];
            if (component > 0) {
                return titleForTimeRow(self, row, component - 1, NULL);
            }
            return titleForDayRow(self, row);
    }
    fatalMsg("Invalid mode");
}

static void resetPickerPositions(UIDatePicker* self) {
    switch (self->_mode) {
        case UIDatePickerModeTime:
            setTime(self, clampDate(self, self->_date));
            break;
        case UIDatePickerModeDate:
            setDate(self, clampDate(self, self->_date));
            break;
    }
}

- (void)setMinimumDate:(NSDate*)date {
    _minimumDate = date;
    resetPickerPositions(self);
    [_pickerView invalidateAllComponents];
}

- (void)setMaximumDate:(NSDate*)date {
    _maximumDate = date;
    resetPickerPositions(self);
    [_pickerView invalidateAllComponents];
}

- (void)setMinuteInterval:(NSUInteger)interval {
}

- (void)dealloc {
    _date = nil;
    _dayStartDate = nil;
    _pickerView = nil;
    _months = nil;
    [super dealloc];
}
@end
