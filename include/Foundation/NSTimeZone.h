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
#import <Foundation/NSCopying.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSecureCoding.h>

@class NSString;
@class NSData;
@class NSDictionary;
@class NSArray;
@class NSDate;
@class NSLocale;

typedef enum : NSInteger {
    NSTimeZoneNameStyleStandard,
    NSTimeZoneNameStyleShortStandard,
    NSTimeZoneNameStyleDaylightSaving,
    NSTimeZoneNameStyleShortDaylightSaving,
    NSTimeZoneNameStyleGeneric,
    NSTimeZoneNameStyleShortGeneric
} NSTimeZoneNameStyle;

FOUNDATION_EXPORT NSString* const NSSystemTimeZoneDidChangeNotification;

FOUNDATION_EXPORT_CLASS
@interface NSTimeZone : NSObject <NSCopying, NSSecureCoding>
+ (instancetype)timeZoneWithAbbreviation:(NSString*)abbreviation;
+ (instancetype)timeZoneWithName:(NSString*)tzName;
+ (instancetype)timeZoneWithName:(NSString*)tzName data:(NSData*)data;
+ (instancetype)timeZoneForSecondsFromGMT:(NSInteger)seconds;
- (instancetype)initWithName:(NSString*)tzName;
- (instancetype)initWithName:(NSString*)tzName data:(NSData*)data;
+ (NSString*)timeZoneDataVersion STUB_METHOD;
+ (NSTimeZone*)localTimeZone;
+ (NSTimeZone*)defaultTimeZone;
+ (void)setDefaultTimeZone:(NSTimeZone*)aTimeZone;
+ (void)resetSystemTimeZone;
+ (NSTimeZone*)systemTimeZone;
+ (NSDictionary*)abbreviationDictionary;
+ (NSArray*)knownTimeZoneNames;
+ (void)setAbbreviationDictionary:(NSDictionary*)dict;
@property (readonly, copy) NSString* abbreviation;
- (NSString*)abbreviationForDate:(NSDate*)aDate;
@property (readonly, copy) NSString* name;
@property (readonly) NSInteger secondsFromGMT;
- (NSInteger)secondsFromGMTForDate:(NSDate*)aDate;
@property (readonly, copy) NSData* data;
- (BOOL)isEqualToTimeZone:(NSTimeZone*)aTimeZone;
@property (readonly, copy) NSString* description;
- (NSString*)localizedName:(NSTimeZoneNameStyle)style locale:(NSLocale*)locale;
@property (readonly, getter=isDaylightSavingTime) BOOL daylightSavingTime;
@property (readonly) NSTimeInterval daylightSavingTimeOffset;
- (BOOL)isDaylightSavingTimeForDate:(NSDate*)aDate;
- (NSTimeInterval)daylightSavingTimeOffsetForDate:(NSDate*)aDate;
@property (readonly, copy) NSDate* nextDaylightSavingTimeTransition;
- (NSDate*)nextDaylightSavingTimeTransitionAfterDate:(NSDate*)aDate;
@end
