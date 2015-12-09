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

#import <Foundation/Foundation.h>
#include <unicode/datefmt.h>
#include <unicode/dtfmtsym.h>
#include <unicode/locid.h>

using WCHAR = wchar_t;

#include <COMIncludes.h>
#include <wrl/client.h>
#include <wrl/wrappers/corewrappers.h>
#include <windows.system.userprofile.h>
#include <COMIncludes_End.h>

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

NSString* const NSCurrentLocaleDidChangeNotification = @"NSCurrentLocaleDidChangeNotification";

static NSLocale* _currentLocale;

@implementation NSLocale {
    // NSArray<NSString*>* _userPreferredLanguages;
    NSArray* _userPreferredLanguages;
    // NSArray<NSString*>* userPreferredCurrencies;
    NSArray* _userPreferredCurrencies;
    NSString* _userPreferredLanguage;
    // _userPreferredLanguage seperated by "-" and stored as an array of NSStrings.
    // NSArray<NSString*>* _userPreferredLanguagesSeperatedByString;
    NSArray* _userPreferredLanguagesSeperatedByString;
    icu::Locale _locale;
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
    if ([_userPreferredLanguagesSeperatedByString count] > 1) {
        return [_userPreferredLanguagesSeperatedByString objectAtIndex:1];
    } else {
        return nil;
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
    // NSArray<NSString*>* componentStrings
    if ([_userPreferredCurrencies count] > 0) {
        return [_userPreferredCurrencies objectAtIndex:0];
    } else {
        return nil;
    }
}

- (icu::Locale*)_createICULocale {
    return _locale.clone();
}

- (instancetype)init {
    if (self = [super init]) {
        _userPreferredLanguages = [[NSLocale preferredLanguages] retain];

        if ([_userPreferredLanguages count] > 0) {
            const char* language = static_cast<const char*>([[_userPreferredLanguages objectAtIndex:0] UTF8String]);
            _locale = icu::Locale(language);
            _userPreferredLanguage = [[_userPreferredLanguages objectAtIndex:0] retain];
            _userPreferredLanguagesSeperatedByString = [[_userPreferredLanguage componentsSeparatedByString:@"-"] retain];
        } else {
            _locale = icu::Locale();
            _userPreferredLanguage = nil;
            _userPreferredLanguagesSeperatedByString = nil;
        }

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

        _userPreferredCurrencies = [nsCurrencies retain];
    }

    return self;
}

- (void)dealloc {
    [_userPreferredLanguagesSeperatedByString release];
    [_userPreferredLanguage release];
    [_userPreferredLanguages release];
    [_userPreferredCurrencies release];

    [super dealloc];
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
 @Status Caveat
 @Notes Only NSLocaleIdentifier is supported
*/
- (NSString*)displayNameForKey:(id)key value:(id)value {
    if ([NSLocaleIdentifier isEqualToString:key]) {
        icu::Locale displayLocale = icu::Locale::createFromName([value UTF8String]);

        UnicodeString retStr;
        displayLocale.getDisplayName(_locale, retStr);

        return NSStringFromICU(retStr);
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

+ (void)initialize {
    if (self == [NSLocale class]) {
        _currentLocale = [self new];
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)currentLocale {
    return [[_currentLocale retain] autorelease];
}

+ (NSArray*)preferredLanguages {
    ComPtr<IGlobalizationPreferencesStatics> globalizationPreferences;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_UserProfile_GlobalizationPreferences).Get(),
                             &globalizationPreferences));

    ComPtr<IVectorView<HSTRING>> languages;
    RETURN_NULL_IF_FAILED(globalizationPreferences->get_Languages(languages.GetAddressOf()));

    unsigned int size = 0;
    RETURN_NULL_IF_FAILED(languages->get_Size(&size));

    NSMutableArray* toRet = [[NSMutableArray new] autorelease];
    unsigned int rawLength;

    for (unsigned int i = 0; i < size; ++i) {
        Wrappers::HString wrlString;
        RETURN_NULL_IF_FAILED(languages->GetAt(i, wrlString.GetAddressOf()));

        const wchar_t* rawString = WindowsGetStringRawBuffer(wrlString.Get(), &rawLength);

        [toRet addObject:[[[NSString alloc] initWithBytes:rawString length:(rawLength * sizeof(wchar_t)) encoding:NSUnicodeStringEncoding]
                             autorelease]];
    }

    return toRet;
}

- (id)valueForUndefinedKey:(NSString*)key {
    // We always return nil for valueForKey we do not support.
    return nil;
}

@end
