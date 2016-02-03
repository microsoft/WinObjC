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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSFormatter.h>
#import <Foundation/NSCalendar.h>

@class NSString;
@class NSDateComponents;
@class NSDate;
@class NSCalendar;

typedef enum NSDateComponentsFormatterUnitsStyle : NSInteger {
    NSDateComponentsFormatterUnitsStylePositional = 0,
    NSDateComponentsFormatterUnitsStyleAbbreviated,
    NSDateComponentsFormatterUnitsStyleShort,
    NSDateComponentsFormatterUnitsStyleFull,
    NSDateComponentsFormatterUnitsStyleSpellOut
} NSDateComponentsFormatterUnitsStyle;
typedef enum NSDateComponentsFormatterZeroFormattingBehavior : NSUInteger {
    NSDateComponentsFormatterZeroFormattingBehaviorNone = (0),
    NSDateComponentsFormatterZeroFormattingBehaviorDefault = (1 << 0),
    NSDateComponentsFormatterZeroFormattingBehaviorDropLeading = (1 << 1),
    NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle = (1 << 2),
    NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing = (1 << 3),
    NSDateComponentsFormatterZeroFormattingBehaviorDropAll =
        (NSDateComponentsFormatterZeroFormattingBehaviorDropLeading | NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle |
         NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing),
    NSDateComponentsFormatterZeroFormattingBehaviorPad = (1 << 16),
} NSDateComponentsFormatterZeroFormattingBehavior;

FOUNDATION_EXPORT_CLASS
@interface NSDateComponentsFormatter : NSFormatter <NSCoding, NSCopying>
- (NSString*)stringFromDateComponents:(NSDateComponents*)components STUB_METHOD;
- (NSString*)stringForObjectValue:(id)obj STUB_METHOD;
- (NSString*)stringFromDate:(NSDate*)startDate toDate:(NSDate*)endDate STUB_METHOD;
- (NSString*)stringFromTimeInterval:(NSTimeInterval)ti STUB_METHOD;
+ (NSString*)localizedStringFromDateComponents:(NSDateComponents*)components
                                    unitsStyle:(NSDateComponentsFormatterUnitsStyle)unitsStyle STUB_METHOD;
@property NSCalendarUnit allowedUnits STUB_PROPERTY;
@property BOOL allowsFractionalUnits STUB_PROPERTY;
@property (copy) NSCalendar* calendar STUB_PROPERTY;
@property BOOL collapsesLargestUnit STUB_PROPERTY;
@property BOOL includesApproximationPhrase STUB_PROPERTY;
@property BOOL includesTimeRemainingPhrase STUB_PROPERTY;
@property NSInteger maximumUnitCount STUB_PROPERTY;
@property NSDateComponentsFormatterUnitsStyle unitsStyle STUB_PROPERTY;
@property NSDateComponentsFormatterZeroFormattingBehavior zeroFormattingBehavior STUB_PROPERTY;
@end
