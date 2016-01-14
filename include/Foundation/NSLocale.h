/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#import <Foundation/NSObject.h>
#import <CoreFoundation/CFLocale.h>

@class NSArray, NSDictionary;

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

typedef NS_ENUM(NSUInteger, NSLocaleLanguageDirection) {
    NSLocaleLanguageDirectionUnknown = kCFLocaleLanguageDirectionUnknown,
    NSLocaleLanguageDirectionLeftToRight = kCFLocaleLanguageDirectionLeftToRight,
    NSLocaleLanguageDirectionRightToLeft = kCFLocaleLanguageDirectionRightToLeft,
    NSLocaleLanguageDirectionTopToBottom = kCFLocaleLanguageDirectionTopToBottom,
    NSLocaleLanguageDirectionBottomToTop = kCFLocaleLanguageDirectionBottomToTop
};

FOUNDATION_EXPORT_CLASS
@interface NSLocale : NSObject <NSSecureCoding, NSCopying>

@property (readonly, copy) NSString* localeIdentifier;

+ (NSLocale*)systemLocale;
+ (NSLocale*)currentLocale;
+ (NSLocale*)autoupdatingCurrentLocale;

+ (NSArray*)availableLocaleIdentifiers;
+ (NSArray*)ISOCountryCodes;
+ (NSArray*)ISOLanguageCodes;
+ (NSArray*)ISOCurrencyCodes;
+ (NSArray*)commonISOCurrencyCodes;

+ (NSString*)canonicalLocaleIdentifierFromString:(NSString*)string;
+ (NSDictionary*)componentsFromLocaleIdentifier:(NSString*)identifier;
+ (NSString*)localeIdentifierFromComponents:(NSDictionary*)components;
+ (NSString*)canonicalLanguageIdentifierFromString:(NSString*)string;
+ (NSString*)localeIdentifierFromWindowsLocaleCode:(uint32_t)lcid;
+ (uint32_t)windowsLocaleCodeFromLocaleIdentifier:(NSString*)localeIdentifier;

+ (NSArray*)preferredLanguages;

+ (NSLocaleLanguageDirection)characterDirectionForLanguage:(NSString*)isoLangCode;
+ (NSLocaleLanguageDirection)lineDirectionForLanguage:(NSString*)isoLangCode;

+ (instancetype)localeWithLocaleIdentifier:(NSString*)string;

- (instancetype)initWithLocaleIdentifier:(NSString*)identifier;

- (id)objectForKey:(id)key;

- (NSString*)displayNameForKey:key value:value;

@end
