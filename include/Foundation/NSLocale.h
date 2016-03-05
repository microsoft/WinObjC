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

@class NSString;
@class NSArray;
@class NSDictionary;

#import <CoreFoundation/CFLocale.h>

typedef NSUInteger NSLocaleLanguageDirection;
enum {
    NSLocaleLanguageDirectionUnknown = kCFLocaleLanguageDirectionUnknown,
    NSLocaleLanguageDirectionLeftToRight = kCFLocaleLanguageDirectionLeftToRight,
    NSLocaleLanguageDirectionRightToLeft = kCFLocaleLanguageDirectionRightToLeft,
    NSLocaleLanguageDirectionTopToBottom = kCFLocaleLanguageDirectionTopToBottom,
    NSLocaleLanguageDirectionBottomToTop = kCFLocaleLanguageDirectionBottomToTop
};

FOUNDATION_EXPORT NSString* const NSLocaleIdentifier;
FOUNDATION_EXPORT NSString* const NSLocaleLanguageCode;
FOUNDATION_EXPORT NSString* const NSLocaleCountryCode;
FOUNDATION_EXPORT NSString* const NSLocaleScriptCode;
FOUNDATION_EXPORT NSString* const NSLocaleVariantCode;
FOUNDATION_EXPORT NSString* const NSLocaleExemplarCharacterSet;
FOUNDATION_EXPORT NSString* const NSLocaleCalendar;
FOUNDATION_EXPORT NSString* const NSLocaleCollationIdentifier;
FOUNDATION_EXPORT NSString* const NSLocaleUsesMetricSystem;
FOUNDATION_EXPORT NSString* const NSLocaleMeasurementSystem;
FOUNDATION_EXPORT NSString* const NSLocaleDecimalSeparator;
FOUNDATION_EXPORT NSString* const NSLocaleGroupingSeparator;
FOUNDATION_EXPORT NSString* const NSLocaleCurrencySymbol;
FOUNDATION_EXPORT NSString* const NSLocaleCurrencyCode;
FOUNDATION_EXPORT NSString* const NSLocaleCollatorIdentifier;
FOUNDATION_EXPORT NSString* const NSLocaleQuotationBeginDelimiterKey;
FOUNDATION_EXPORT NSString* const NSLocaleQuotationEndDelimiterKey;
FOUNDATION_EXPORT NSString* const NSLocaleAlternateQuotationBeginDelimiterKey;
FOUNDATION_EXPORT NSString* const NSLocaleAlternateQuotationEndDelimiterKey;
FOUNDATION_EXPORT NSString* const NSGregorianCalendar;
FOUNDATION_EXPORT NSString* const NSBuddhistCalendar;
FOUNDATION_EXPORT NSString* const NSChineseCalendar;
FOUNDATION_EXPORT NSString* const NSHebrewCalendar;
FOUNDATION_EXPORT NSString* const NSIslamicCalendar;
FOUNDATION_EXPORT NSString* const NSIslamicCivilCalendar;
FOUNDATION_EXPORT NSString* const NSJapaneseCalendar;
FOUNDATION_EXPORT NSString* const NSRepublicOfChinaCalendar;
FOUNDATION_EXPORT NSString* const NSPersianCalendar;
FOUNDATION_EXPORT NSString* const NSIndianCalendar;
FOUNDATION_EXPORT NSString* const NSISO8601Calendar;
FOUNDATION_EXPORT NSString* const NSCurrentLocaleDidChangeNotification;

FOUNDATION_EXPORT_CLASS
@interface NSLocale : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithLocaleIdentifier:(NSString*)string;
+ (instancetype)localeWithLocaleIdentifier:(NSString*)string;
+ (NSLocale*)autoupdatingCurrentLocale;
+ (NSLocale*)currentLocale;
+ (NSLocale*)systemLocale;
- (NSString*)displayNameForKey:(id)key value:(id)value;
@property (readonly, copy) NSString* localeIdentifier;
- (id)objectForKey:(id)key;
+ (NSArray*)availableLocaleIdentifiers;
+ (NSArray*)ISOCountryCodes;
+ (NSArray*)ISOCurrencyCodes;
+ (NSArray*)ISOLanguageCodes;
+ (NSArray*)commonISOCurrencyCodes;
+ (NSString*)canonicalLocaleIdentifierFromString:(NSString*)string;
+ (NSDictionary*)componentsFromLocaleIdentifier:(NSString*)string;
+ (NSString*)localeIdentifierFromComponents:(NSDictionary*)dict;
+ (NSString*)canonicalLanguageIdentifierFromString:(NSString*)string;
+ (NSString*)localeIdentifierFromWindowsLocaleCode:(uint32_t)lcid;
+ (uint32_t)windowsLocaleCodeFromLocaleIdentifier:(NSString*)localeIdentifier;
+ (NSArray*)preferredLanguages;
+ (NSLocaleLanguageDirection)characterDirectionForLanguage:(NSString*)isoLangCode;
+ (NSLocaleLanguageDirection)lineDirectionForLanguage:(NSString*)isoLangCode;
@end
