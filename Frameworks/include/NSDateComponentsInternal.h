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

#pragma once

#include <Foundation/NSDateComponents.h>

// This is the index of NSCalendarUnitWeekdayOrdinal in s_individualFlags. This is the cutoff for mathematical units in
// the individual flags array.
static const int NSDateComponentsMathematicalUnitCutoff = 8;

// These are the flags that represent a valid date.
static const NSCalendarUnit s_NSDateComponentsIndividualFlags[] = { NSCalendarUnitEra,
                                                                    NSCalendarUnitYear,
                                                                    NSCalendarUnitMonth,
                                                                    NSCalendarUnitDay,
                                                                    NSCalendarUnitHour,
                                                                    NSCalendarUnitMinute,
                                                                    NSCalendarUnitSecond,
                                                                    NSCalendarUnitNanosecond,
                                                                    NSCalendarUnitWeekdayOrdinal,
                                                                    NSCalendarUnitYearForWeekOfYear,
                                                                    NSCalendarUnitQuarter,
                                                                    NSCalendarUnitWeekOfYear,
                                                                    NSCalendarUnitWeekOfMonth,
                                                                    NSCalendarUnitWeekday };

// Strictly the mathematical units. This is seperated from s_individualFlags because the enumeration function needs both
// mathematical and interpretive units for deciding which method to use to match.
static const NSCalendarUnit s_NSDateComponentsIndividualMathematicalUnits[] = { NSCalendarUnitEra,   NSCalendarUnitYear,
                                                                                NSCalendarUnitMonth, NSCalendarUnitDay,
                                                                                NSCalendarUnitHour,  NSCalendarUnitMinute,
                                                                                NSCalendarUnitSecond };

// These are not all flags, but rather just the flags that can be modified/accessed via valueForComponent and setValue:ForComponent.
static const NSCalendarUnit s_NSDateComponentsAllFlagOptions =
    NSCalendarUnitEra | NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute |
    NSCalendarUnitSecond | NSCalendarUnitWeekday | NSCalendarUnitWeekdayOrdinal | NSCalendarUnitQuarter | NSCalendarUnitWeekOfMonth |
    NSCalendarUnitWeekOfYear | NSCalendarUnitYearForWeekOfYear | NSCalendarUnitNanosecond;

static const NSCalendarUnit s_NSDateComponentsValidMathematicalFlags = NSCalendarUnitEra | NSCalendarUnitYear | NSCalendarUnitMonth |
                                                                       NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute |
                                                                       NSCalendarUnitSecond;

@interface NSDateComponents (Internal)

- (BOOL)_componentsMatch:(NSDateComponents*)comp2 forUnits:(NSCalendarUnit)units;

@end