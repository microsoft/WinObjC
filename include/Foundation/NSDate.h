//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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

@class NSString;

#define NSTimeIntervalSince1970 978307200.0

FOUNDATION_EXPORT const NSString* NSSystemClockDidChangeNotification;

FOUNDATION_EXPORT_CLASS
@interface NSDate : NSObject <NSCopying, NSSecureCoding>

+ (instancetype)date;
+ (instancetype)dateWithTimeIntervalSinceNow:(NSTimeInterval)seconds;
+ (instancetype)dateWithTimeInterval:(NSTimeInterval)seconds sinceDate:(NSDate*)date;
+ (instancetype)dateWithTimeIntervalSinceReferenceDate:(NSTimeInterval)seconds;
+ (instancetype)dateWithTimeIntervalSince1970:(NSTimeInterval)seconds;
- (instancetype)initWithTimeIntervalSinceNow:(NSTimeInterval)seconds;
- (instancetype)initWithTimeInterval:(NSTimeInterval)seconds sinceDate:(NSDate*)refDate;
- (instancetype)initWithTimeIntervalSinceReferenceDate:(NSTimeInterval)seconds;
- (instancetype)initWithTimeIntervalSince1970:(NSTimeInterval)seconds;
+ (NSDate*)distantFuture;
+ (NSDate*)distantPast;
- (BOOL)isEqualToDate:(NSDate*)anotherDate;
- (NSDate*)earlierDate:(NSDate*)anotherDate;
- (NSDate*)laterDate:(NSDate*)anotherDate;
- (NSComparisonResult)compare:(NSDate*)anotherDate;
- (NSTimeInterval)timeIntervalSinceDate:(NSDate*)anotherDate;
@property (readonly) NSTimeInterval timeIntervalSinceNow;
+ (NSTimeInterval)timeIntervalSinceReferenceDate;
@property (readonly) NSTimeInterval timeIntervalSinceReferenceDate;
@property (readonly) NSTimeInterval timeIntervalSince1970;
- (instancetype)dateByAddingTimeInterval:(NSTimeInterval)seconds;
- (id)addTimeInterval:(NSTimeInterval)seconds;
@property (readonly, copy) NSString* description;
- (NSString*)descriptionWithLocale:(id)locale;
@end
