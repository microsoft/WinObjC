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
#include "StubReturn.h"

#import <Foundation/Foundation.h>
#import "NSCFLocale.h"

NSString* const NSLocaleIdentifier = static_cast<NSString*>(kCFLocaleIdentifier);
NSString* const NSLocaleLanguageCode = static_cast<NSString*>(kCFLocaleLanguageCode);
NSString* const NSLocaleCountryCode = static_cast<NSString*>(kCFLocaleCountryCode);
NSString* const NSLocaleScriptCode = static_cast<NSString*>(kCFLocaleScriptCode);
NSString* const NSLocaleVariantCode = static_cast<NSString*>(kCFLocaleVariantCode);
NSString* const NSLocaleExemplarCharacterSet = static_cast<NSString*>(kCFLocaleExemplarCharacterSet);
NSString* const NSLocaleCalendar = static_cast<NSString*>(kCFLocaleCalendar);
NSString* const NSLocaleCollationIdentifier = static_cast<NSString*>(kCFLocaleCollationIdentifier);
NSString* const NSLocaleUsesMetricSystem = static_cast<NSString*>(kCFLocaleUsesMetricSystem);
NSString* const NSLocaleMeasurementSystem = static_cast<NSString*>(kCFLocaleMeasurementSystem);
NSString* const NSLocaleDecimalSeparator = static_cast<NSString*>(kCFLocaleDecimalSeparator);
NSString* const NSLocaleGroupingSeparator = static_cast<NSString*>(kCFLocaleGroupingSeparator);
NSString* const NSLocaleCurrencySymbol = static_cast<NSString*>(kCFLocaleCurrencySymbol);
NSString* const NSLocaleCurrencyCode = static_cast<NSString*>(kCFLocaleCurrencyCode);
NSString* const NSLocaleCollatorIdentifier = static_cast<NSString*>(kCFLocaleCollatorIdentifier);
NSString* const NSLocaleQuotationBeginDelimiterKey = static_cast<NSString*>(kCFLocaleQuotationBeginDelimiterKey);
NSString* const NSLocaleQuotationEndDelimiterKey = static_cast<NSString*>(kCFLocaleQuotationEndDelimiterKey);
NSString* const NSLocaleAlternateQuotationBeginDelimiterKey = static_cast<NSString*>(kCFLocaleAlternateQuotationBeginDelimiterKey);
NSString* const NSLocaleAlternateQuotationEndDelimiterKey = static_cast<NSString*>(kCFLocaleAlternateQuotationEndDelimiterKey);

NSString* const NSGregorianCalendar = static_cast<NSString*>(kCFGregorianCalendar);
NSString* const NSBuddhistCalendar = static_cast<NSString*>(kCFBuddhistCalendar);
NSString* const NSChineseCalendar = static_cast<NSString*>(kCFChineseCalendar);
NSString* const NSHebrewCalendar = static_cast<NSString*>(kCFHebrewCalendar);
NSString* const NSIslamicCalendar = static_cast<NSString*>(kCFIslamicCalendar);
NSString* const NSIslamicCivilCalendar = static_cast<NSString*>(kCFIslamicCivilCalendar);
NSString* const NSJapaneseCalendar = static_cast<NSString*>(kCFJapaneseCalendar);
NSString* const NSRepublicOfChinaCalendar = static_cast<NSString*>(kCFRepublicOfChinaCalendar);
NSString* const NSPersianCalendar = static_cast<NSString*>(kCFPersianCalendar);
NSString* const NSIndianCalendar = static_cast<NSString*>(kCFIndianCalendar);
NSString* const NSISO8601Calendar = static_cast<NSString*>(kCFISO8601Calendar);

NSString* const NSCurrentLocaleDidChangeNotification = static_cast<NSString*>(kCFLocaleCurrentLocaleDidChangeNotification);

@implementation NSLocale

/**
 @Status Interoperable
*/
+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSLocale, NSLocalePrototype);

/**
 @Status Interoperable
*/
+ (instancetype)localeWithLocaleIdentifier:(NSString*)identifier {
    return [[[self alloc] initWithLocaleIdentifier:identifier] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLocaleIdentifier:(NSString*)string {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)localeIdentifier {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
+ (NSArray*)availableLocaleIdentifiers {
    return [static_cast<NSArray*>(CFLocaleCopyAvailableLocaleIdentifiers()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOCountryCodes {
    return [static_cast<NSArray*>(CFLocaleCopyISOCountryCodes()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOLanguageCodes {
    return [static_cast<NSArray*>(CFLocaleCopyISOLanguageCodes()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOCurrencyCodes {
    return [static_cast<NSArray*>(CFLocaleCopyISOCurrencyCodes()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSArray*)commonISOCurrencyCodes {
    return [static_cast<NSArray*>(CFLocaleCopyCommonISOCurrencyCodes()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)canonicalLocaleIdentifierFromString:(NSString*)string {
    return [static_cast<NSString*>(CFLocaleCreateCanonicalLocaleIdentifierFromString(kCFAllocatorDefault, static_cast<CFStringRef>(string)))
        autorelease];
}

/**
 @Status Interoperable
*/
+ (NSDictionary*)componentsFromLocaleIdentifier:(NSString*)identifier {
    return [static_cast<NSDictionary*>(
        CFLocaleCreateComponentsFromLocaleIdentifier(kCFAllocatorDefault, static_cast<CFStringRef>(identifier))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)localeIdentifierFromComponents:(NSDictionary*)components {
    return [static_cast<NSString*>(
        CFLocaleCreateLocaleIdentifierFromComponents(kCFAllocatorDefault, static_cast<CFDictionaryRef>(components))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)canonicalLanguageIdentifierFromString:(NSString*)string {
    return [static_cast<NSString*>(
        CFLocaleCreateCanonicalLanguageIdentifierFromString(kCFAllocatorDefault, static_cast<CFStringRef>(string))) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSString*)localeIdentifierFromWindowsLocaleCode:(uint32_t)lcid {
    return [static_cast<NSString*>(CFLocaleCreateLocaleIdentifierFromWindowsLocaleCode(kCFAllocatorDefault, lcid)) autorelease];
}

/**
 @Status Interoperable
*/
+ (uint32_t)windowsLocaleCodeFromLocaleIdentifier:(NSString*)localeIdentifier {
    return CFLocaleGetWindowsLocaleCodeFromLocaleIdentifier(static_cast<CFStringRef>(localeIdentifier));
}

/**
 @Status Interoperable
*/
+ (NSLocaleLanguageDirection)characterDirectionForLanguage:(NSString*)isoLangCode {
    return (NSLocaleLanguageDirection)CFLocaleGetLanguageCharacterDirection(static_cast<CFStringRef>(isoLangCode));
}

/**
 @Status Interoperable
*/
+ (NSLocaleLanguageDirection)lineDirectionForLanguage:(NSString*)isoLangCode {
    return (NSLocaleLanguageDirection)CFLocaleGetLanguageLineDirection(static_cast<CFStringRef>(isoLangCode));
}

/**
 @Status Interoperable
*/
- (NSString*)displayNameForKey:(id)key value:(id)value {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)objectForKey:(id)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
+ (NSLocale*)currentLocale {
    return [static_cast<NSLocale*>(CFLocaleCopyCurrent()) autorelease];
}

/**
 @Status Interoperable
*/
+ (NSLocale*)systemLocale {
    return static_cast<NSLocale*>(CFLocaleGetSystem());
}

/**
 @Status Interoperable
*/
+ (NSLocale*)autoupdatingCurrentLocale {
    return [self currentLocale];
}

/**
 @Status Interoperable
*/
+ (NSArray*)preferredLanguages {
    return [static_cast<NSArray*>(CFLocaleCopyPreferredLanguages()) autorelease];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if ([coder allowsKeyedCoding]) {
        return [self initWithLocaleIdentifier:[coder decodeObjectOfClass:[NSString class] forKey:@"NS.localeIdentifier"]];
    } else {
        UNIMPLEMENTED_WITH_MSG("NSLocale initWithCoder: with non-keyed NSCoder currently unsupported");
        [self release];
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:[self localeIdentifier] forKey:@"NS.localeIdentifier"];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

// Returning nil is acceptable here because _prefs is used as a cache to store information about the
// current locale. CFLocale only has a private method for getting this information as well which we cannot
// rely on to be there. Additionally, this will only get called from CFLocale and used in DateFormatter and
// NumberFormatter as a way to avoid look ups iff this class is overridden. This means implementing this
// function would provide no value to the developer.
- (NSDictionary*)_prefs {
    return nil;
}

// Hard coded to return false. This function is used as an optimization step in CFString to fast path
// retrieving the ID of a language for a given locale. By returning false, the attempt to grab an id
// for a given locale will always happpen. To avoid this, NSLocale would need to know if it's an invalid
// locale via this _nullLocale property. For the purposes of bridging, we cannot store this information.
// Thus, the slow path for the _CFStrGetLanguageIdentifierForLocale in CFString will be taken.
- (Boolean)_nullLocale {
    return false;
}

// Do nothing as commented above
- (void)_setNullLocale {
}

// This function will only be called by CFLocale in an overriden class. The use case for this particular
// function seems strange as it seems virtually identical to the displayNameForKey function already
// defined above. With bridging in place as well, this function won't work as intended and would require
// additional work that won't hold value to a developer.
- (NSString*)_copyDisplayNameForKey:(id)key value:(id)value {
    return value;
}

- (NSUInteger)hash {
    return [[self localeIdentifier] hash];
}

- (BOOL)isEqual:(id)anObject {
    if (self == anObject) {
        return YES;
    }
    if (![anObject isKindOfClass:[NSLocale class]]) {
        return NO;
    }

    return [[self localeIdentifier] isEqual:[static_cast<NSLocale*>(anObject) localeIdentifier]];
}

@end
