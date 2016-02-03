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
@class NSString;
@class NSDate;
@class NSCalendar;
@class NSLocale;
@class NSTimeZone;

typedef enum NSDateIntervalFormatterStyle : NSUInteger {
    NSDateIntervalFormatterNoStyle = 0,
    NSDateIntervalFormatterShortStyle = 1,
    NSDateIntervalFormatterMediumStyle = 2,
    NSDateIntervalFormatterLongStyle = 3,
    NSDateIntervalFormatterFullStyle = 4
} NSDateIntervalFormatterStyle;

FOUNDATION_EXPORT_CLASS
@interface NSDateIntervalFormatter : NSFormatter <NSCoding, NSCopying>
- (NSString*)stringFromDate:(NSDate*)fromDate toDate:(NSDate*)toDate STUB_METHOD;
@property NSDateIntervalFormatterStyle dateStyle STUB_PROPERTY;
@property NSDateIntervalFormatterStyle timeStyle STUB_PROPERTY;
@property (copy) NSString* dateTemplate STUB_PROPERTY;
@property (copy) NSCalendar* calendar STUB_PROPERTY;
@property (copy) NSLocale* locale STUB_PROPERTY;
@property (copy) NSTimeZone* timeZone STUB_PROPERTY;
@end
