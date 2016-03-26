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
#include <unicode/datefmt.h>
#include <unicode/dtfmtsym.h>
#include <unicode/locid.h>

#include <COMIncludes.h>
#include <wrl/client.h>
#include <wrl/wrappers/corewrappers.h>
#include <windows.system.userprofile.h>
#include <windows.globalization.h>
#include <COMIncludes_End.h>
#include "StringHelpers.h"

using namespace Microsoft::WRL;
using namespace ABI::Windows::System::UserProfile;
using namespace ABI::Windows::Foundation::Collections;
using namespace Windows::Foundation;

NSString* const NSLocaleIdentifier = @"NSLocaleIdentifier";
NSString* const NSLocaleLanguageCode = @"NSLocaleLanguageCode";
NSString* const NSLocaleCountryCode = @"NSLocaleCountryCode";
NSString* const NSLocaleScriptCode = @"NSLocaleScriptCode";
NSString* const NSLocaleVariantCode = @"NSLocaleVariantCode";
NSString* const NSLocaleExemplarCharacterSet = @"NSLocaleExemplarCharacterSet";
NSString* const NSLocaleCalendar = @"NSLocaleCalendar";
NSString* const NSLocaleCollationIdentifier = @"NSLocaleCollationIdentifier";
NSString* const NSLocaleUsesMetricSystem = @"NSLocaleUsesMetricSystem";
NSString* const NSLocaleMeasurementSystem = @"NSLocaleMeasurementSystem";
NSString* const NSLocaleDecimalSeparator = @"NSLocaleDecimalSeparator";
NSString* const NSLocaleGroupingSeparator = @"NSLocaleGroupingSeparator";
NSString* const NSLocaleCurrencySymbol = @"NSLocaleCurrencySymbol";
NSString* const NSLocaleCurrencyCode = @"NSLocaleCurrencyCode";
NSString* const NSLocaleCollatorIdentifier = @"NSLocaleCollatorIdentifier";
NSString* const NSLocaleQuotationBeginDelimiterKey = @"NSLocaleQuotationBeginDelimiterKey";
NSString* const NSLocaleQuotationEndDelimiterKey = @"NSLocaleQuotationEndDelimiterKey";
NSString* const NSLocaleAlternateQuotationBeginDelimiterKey = @"NSLocaleAlternateQuotationBeginDelimiterKey";
NSString* const NSLocaleAlternateQuotationEndDelimiterKey = @"NSLocaleAlternateQuotationEndDelimiterKey";

NSString* const NSGregorianCalendar = @"NSGregorianCalendar";
NSString* const NSBuddhistCalendar = @"NSBuddhistCalendar";
NSString* const NSChineseCalendar = @"NSChineseCalendar";
NSString* const NSHebrewCalendar = @"NSHebrewCalendar";
NSString* const NSIslamicCalendar = @"NSIslamicCalendar";
NSString* const NSIslamicCivilCalendar = @"NSIslamicCivilCalendar";
NSString* const NSJapaneseCalendar = @"NSJapaneseCalendar";
NSString* const NSRepublicOfChinaCalendar = @"NSRepublicOfChinaCalendar";
NSString* const NSPersianCalendar = @"NSPersianCalendar";
NSString* const NSIndianCalendar = @"NSIndianCalendar";
NSString* const NSISO8601Calendar = @"NSISO8601Calendar";

NSString* const NSCurrentLocaleDidChangeNotification = @"NSCurrentLocaleDidChangeNotification";

static NSLocale* _currentLocale;

@implementation NSLocale {
    // NSArray<NSString*>* _userPreferredLanguages;
    NSArray* _userPreferredLanguages;
    // NSArray<NSString*>* _userPreferredCurrencies;
    NSArray* _userPreferredCurrencies;
    NSString* _userPreferredLanguage;
    // _userPreferredLanguage seperated by "-" and stored as an array of NSStrings.
    // NSArray<NSString*>* _userPreferredLanguagesSeperatedByString;
    NSArray* _userPreferredLanguagesSeperatedByString;
    // NSArray<NSString*>* _ISOCountryCodes;
    NSArray* _ISOCountryCodes;
    // NSArray<NSString*>* _ISOLanguageCodes;
    NSArray* _ISOLanguageCodes;
    icu::Locale _locale;
    StrongId<NSString> _localeCountryCode;
}

- (NSArray*)_getUserPreferredLanguages {
    return [[_userPreferredLanguages retain] autorelease];
}

- (NSArray*)_getISOCountryCodes {
    return [[_ISOCountryCodes retain] autorelease];
}

- (NSArray*)_getISOLanguageCodes {
    return [[_ISOLanguageCodes retain] autorelease];
}

- (NSArray*)_getUserPreferredCurrencies {
    return [[_userPreferredCurrencies retain] autorelease];
}

/**
 * KVC accessor for NSLocaleIdentifier.
 * @return {NSString*} the key for the locale identifier..
 */
- (NSString*)getNSLocaleIdentifier {
    return [[_userPreferredLanguage retain] autorelease];
}

/**
 * KVC accessor for NSLocaleLanguageCode.
 * @return {NSString*} the key for the locale language code.
 */
- (NSString*)getNSLocaleLanguageCode {
    if ([_userPreferredLanguagesSeperatedByString count] > 0) {
        return [_userPreferredLanguagesSeperatedByString objectAtIndex:0];
    } else {
        return nil;
    }
}

/**
 * KVC accessor for NSLocaleCountryCode.
 * @return {NSString*} the key for the locale country code.
 */
- (NSString*)getNSLocaleCountryCode {
    if (!_localeCountryCode) {
        _localeCountryCode = [NSLocale _currentNSLocaleCountryCode];
    }
    return _localeCountryCode;
}

/**
 * Helper method for retrieving system's region setting.
 */
+ (NSString*)_currentNSLocaleCountryCode {
    @synchronized(self) {
        ComPtr<IGlobalizationPreferencesStatics> globalizationPreferences;
        RETURN_NULL_IF_FAILED(
            GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_UserProfile_GlobalizationPreferences).Get(),
                                 &globalizationPreferences));

        Wrappers::HString regionSetting;
        RETURN_NULL_IF_FAILED(globalizationPreferences->get_HomeGeographicRegion(regionSetting.GetAddressOf()));

        return Strings::WideToNSString(regionSetting.Get());
    }
}

/**
 * KVC accessor for NSLocaleVariantCode.
 * @return {NSString*} the key for the locale variant code.
 */
- (NSString*)getNSLocaleVariantCode {
    if ([_userPreferredLanguagesSeperatedByString count] > 2) {
        return [_userPreferredLanguagesSeperatedByString objectAtIndex:3];
    } else {
        return nil;
    }
}

/**
 * KVC accessor for NSLocaleCurrencyCode.
 * @return {NSString*} the key for the currency code associated with the locale.
 */
- (NSString*)getNSLocaleCurrencyCode {
    if ([_userPreferredCurrencies count] > 0) {
        return [_userPreferredCurrencies objectAtIndex:0];
    } else {
        return nil;
    }
}

- (icu::Locale*)_createICULocale {
    return _locale.clone();
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        // Initialize region
        _localeCountryCode = [NSLocale _currentNSLocaleCountryCode];
        // Initialize user preferred languagess
        [self _initUserPreferredLanguages];
        // Initialize user preferred currencies
        [self _initUserPreferredCurrencies];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_userPreferredLanguagesSeperatedByString release];
    [_userPreferredLanguage release];
    [_userPreferredLanguages release];
    [_userPreferredCurrencies release];
    [_ISOCountryCodes release];

    [super dealloc];
}

- (NSArray*)_enumerateUserPreferredLanguages {
    ComPtr<IGlobalizationPreferencesStatics> globalizationPreferences;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_UserProfile_GlobalizationPreferences).Get(),
                             &globalizationPreferences));

    ComPtr<IVectorView<HSTRING>> languages;
    RETURN_NULL_IF_FAILED(globalizationPreferences->get_Languages(languages.GetAddressOf()));

    unsigned int size = 0;
    RETURN_NULL_IF_FAILED(languages->get_Size(&size));

    NSMutableArray* languageArray = [[NSMutableArray new] autorelease];
    unsigned int rawLength;

    for (unsigned int i = 0; i < size; ++i) {
        Wrappers::HString wrlString;
        RETURN_NULL_IF_FAILED(languages->GetAt(i, wrlString.GetAddressOf()));

        const wchar_t* rawString = WindowsGetStringRawBuffer(wrlString.Get(), &rawLength);

        [languageArray
            addObject:[[[NSString alloc] initWithBytes:rawString length:(rawLength * sizeof(wchar_t)) encoding:NSUnicodeStringEncoding]
                          autorelease]];
    }

    return languageArray;
}

- (void)_initUserPreferredLanguages {
    _userPreferredLanguages = [[self _enumerateUserPreferredLanguages] retain];

    if ([_userPreferredLanguages count] > 0) {
        const char* language = const_cast<char*>([[_userPreferredLanguages objectAtIndex:0] UTF8String]);
        _locale = icu::Locale(language);
        _userPreferredLanguage = [[_userPreferredLanguages objectAtIndex:0] retain];
        _userPreferredLanguagesSeperatedByString = [[_userPreferredLanguage componentsSeparatedByString:@"-"] retain];

        NSMutableArray* languageCodes = [[[NSMutableArray alloc] init] autorelease];
        NSMutableArray* countryCodes = [[[NSMutableArray alloc] init] autorelease];
        for (NSString* userPreferredLanguage in _userPreferredLanguages) {
            NSArray* userPreferredLanguageSeperatedByString = [userPreferredLanguage componentsSeparatedByString:@"-"];
            [languageCodes addObject:[userPreferredLanguageSeperatedByString objectAtIndex:0]];
            if ([userPreferredLanguageSeperatedByString count] > 1) {
                [countryCodes addObject:[userPreferredLanguageSeperatedByString objectAtIndex:1]];
            }
        }
        _ISOLanguageCodes = [[NSArray arrayWithArray:languageCodes] retain];
        _ISOCountryCodes = [[NSArray arrayWithArray:countryCodes] retain];
    } else {
        _locale = icu::Locale();
        _userPreferredLanguage = nil;
        _userPreferredLanguagesSeperatedByString = nil;
    }
}

- (NSArray*)_enumerateUserPreferredCurrencies {
    ComPtr<IGlobalizationPreferencesStatics> globalizationPreferences;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_UserProfile_GlobalizationPreferences).Get(),
                             &globalizationPreferences));

    ComPtr<IVectorView<HSTRING>> currencies;
    RETURN_NULL_IF_FAILED(globalizationPreferences->get_Currencies(currencies.GetAddressOf()));

    unsigned int size = 0;
    RETURN_NULL_IF_FAILED(currencies->get_Size(&size));

    NSMutableArray* nsCurrencies = [[NSMutableArray new] autorelease];
    unsigned int rawLength;

    for (unsigned int i = 0; i < size; ++i) {
        Wrappers::HString wrlString;
        RETURN_NULL_IF_FAILED(currencies->GetAt(i, wrlString.GetAddressOf()));

        const wchar_t* rawString = WindowsGetStringRawBuffer(wrlString.Get(), &rawLength);

        [nsCurrencies
            addObject:[[[NSString alloc] initWithBytes:rawString length:(rawLength * sizeof(wchar_t)) encoding:NSUnicodeStringEncoding]
                          autorelease]];
    }

    return nsCurrencies;
}

- (void)_initUserPreferredCurrencies {
    _userPreferredCurrencies = [[self _enumerateUserPreferredCurrencies] retain];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithLocaleIdentifier:(NSString*)identifier {
    _locale = icu::Locale::createFromName([identifier UTF8String]);

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)localeWithLocaleIdentifier:(NSString*)identifier {
    return [[[self alloc] initWithLocaleIdentifier:identifier] autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)localeIdentifier {
    return [NSString stringWithUTF8String:_locale.getName()];
}

/**
 @Status Interoperable
*/
+ (NSArray*)availableLocaleIdentifiers {
    return [NSArray arrayWithObject:[[self systemLocale] localeIdentifier]];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOCountryCodes {
    return [[self systemLocale] _getISOCountryCodes];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOLanguageCodes {
    return [[self systemLocale] _getISOLanguageCodes];
}

/**
 @Status Interoperable
*/
+ (NSArray*)ISOCurrencyCodes {
    return [[self systemLocale] _getUserPreferredCurrencies];
}

/**
 @Status Interoperable
*/
+ (NSArray*)commonISOCurrencyCodes {
    return [[self systemLocale] _getUserPreferredCurrencies];
}

/**
 @Status Stub
*/
+ (NSString*)canonicalLocaleIdentifierFromString:(NSString*)string {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSDictionary*)componentsFromLocaleIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSString*)localeIdentifierFromComponents:(NSDictionary*)components {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSString*)canonicalLanguageIdentifierFromString:(NSString*)string {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (NSString*)localeIdentifierFromWindowsLocaleCode:(uint32_t)lcid {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (uint32_t)windowsLocaleCodeFromLocaleIdentifier:(NSString*)localeIdentifier {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
+ (NSLocaleLanguageDirection)characterDirectionForLanguage:(NSString*)isoLangCode {
    UNIMPLEMENTED();
    return NSLocaleLanguageDirectionUnknown;
}

/**
 @Status Stub
*/
+ (NSLocaleLanguageDirection)lineDirectionForLanguage:(NSString*)isoLangCode {
    UNIMPLEMENTED();
    return NSLocaleLanguageDirectionUnknown;
}

/**
 @Status Caveat
 @Notes Only NSLocaleIdentifier is supported
*/
- (NSString*)displayNameForKey:(id)key value:(id)value {
    if ([NSLocaleIdentifier isEqualToString:key]) {
        icu::Locale displayLocale = icu::Locale::createFromName([value UTF8String]);

        UnicodeString retStr;
        displayLocale.getDisplayName(_locale, retStr);

        std::string realStr;
        retStr.toUTF8String(realStr);
        return [NSString stringWithUTF8String:realStr.c_str()];

    } else {
        [NSException raiseWithLogging:@"NSLocaleException" format:@"displayNameForKey: Unknown key %@", key];
        return nil;
    }
}

/**
 @Status Caveat
 @Notes Only NSLocaleIdentifier, NSLocaleLanguageCode, NSLocaleCountryCode, NSLocaleVariantCode and NSLocaleCurrencySymbol is supported.
*/
- (id)objectForKey:(id)key {
    // Using Accessor Search Patterns here.
    return [self valueForKey:key];
}

/**
 @Status Interoperable
*/
+ (void)initialize {
    if (self == [NSLocale class]) {
        _currentLocale = [self new];
    }
}

/**
 @Status Interoperable
*/
+ (NSLocale*)currentLocale {
    return [[_currentLocale retain] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSLocale*)systemLocale {
    return [self currentLocale];
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
    return [[self systemLocale] _getUserPreferredLanguages];
}

/**
 @Status Interoperable
*/
- (id)valueForUndefinedKey:(NSString*)key {
    // We always return nil for valueForKey we do not support.
    return nil;
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
    if (self = [super init]) {
        // Can't encode/decode _locale. We will have to recreate it.
        _userPreferredLanguages = [[coder decodeObjectOfClass:[NSArray class] forKey:@"userPreferredLanguages"] retain];
        _userPreferredCurrencies = [[coder decodeObjectOfClass:[NSArray class] forKey:@"userPreferredCurrencies"] retain];
        _userPreferredLanguage = [[coder decodeObjectOfClass:[NSString class] forKey:@"userPreferredLanguage"] retain];
        _userPreferredLanguagesSeperatedByString =
            [[coder decodeObjectOfClass:[NSArray class] forKey:@"userPreferredLanguagesSeperatedByString"] retain];
        if ([_userPreferredLanguages count] > 0) {
            const char* language = const_cast<char*>([[_userPreferredLanguages objectAtIndex:0] UTF8String]);
            _locale = icu::Locale(language);
        } else {
            _locale = icu::Locale();
        }
        _ISOCountryCodes = [[coder decodeObjectOfClass:[NSArray class] forKey:@"ISOCountryCodes"] retain];
        _ISOLanguageCodes = [[coder decodeObjectOfClass:[NSArray class] forKey:@"ISOLanguageCodes"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    // Can't encode/decode _locale. We will have to recreate it.
    [coder encodeObject:_userPreferredLanguages forKey:@"userPreferredLanguages"];
    [coder encodeObject:_userPreferredCurrencies forKey:@"userPreferredCurrencies"];
    [coder encodeObject:_userPreferredLanguage forKey:@"userPreferredLanguage"];
    [coder encodeObject:_userPreferredLanguagesSeperatedByString forKey:@"userPreferredLanguagesSeperatedByString"];
    [coder encodeObject:_ISOCountryCodes forKey:@"ISOCountryCodes"];
    [coder encodeObject:_ISOLanguageCodes forKey:@"ISOLanguageCodes"];
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
