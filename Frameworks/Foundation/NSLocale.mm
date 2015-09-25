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

NSString* const NSLocaleCountryCode = @"NSLocaleCountryCode";
NSString* const NSLocaleLanguageCode = @"NSLocaleLanguageCode";
NSString* const NSLocaleVariantCode = @"NSLocaleVariantCode";
NSString* const NSLocaleIdentifier = @"NSLocaleIdentifier";

NSString* const NSLocaleGroupingSeparator = @"NSLocaleGroupingSeparator";
NSString* const NSLocaleDecimalSeparator = @"NSLocaleDecimalSeparator";
NSString* const NSLocaleCalendar = @"NSLocaleCalendar";
NSString* const NSLocaleCurrencyCode = @"NSLocaleCurrencyCode";
NSString* const NSLocaleCurrencySymbol = @"NSLocaleCurrencySymbol";
NSString* const NSLocaleUsesMetricSystem = @"NSLocaleUsesMetricSystem";
NSString* const NSLocaleMeasurementSystem = @"NSLocaleMeasurementSystem";

NSString* const NSLocaleScriptCode = @"NSLocaleScriptCode";
NSString* const NSLocaleExemplarCharacterSet = @"NSLocaleExemplarCharacterSet";
NSString* const NSLocaleCollationIdentifier = @"NSLocaleCollationIdentifier";

NSString* const NSCurrentLocaleDidChangeNotification = @"NSCurrentLocaleDidChangeNotification";

static NSLocale* _currentLocale;

@implementation NSLocale {
    icu::Locale _locale;
}

- (icu::Locale*)_createICULocale {
    return _locale.clone();
}

- (instancetype)init {
    _locale = icu::Locale();

    return self;
}

- (instancetype)initWithLocaleIdentifier:(NSString*)identifier {
    _locale = icu::Locale::createFromName([identifier UTF8String]);

    return self;
}

+ (instancetype)localeWithLocaleIdentifier:(NSString*)identifier {
    return [[[self alloc] initWithLocaleIdentifier:identifier] autorelease];
}

- (NSString*)localeIdentifier {
    return [NSString stringWithUTF8String:_locale.getName()];
}

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

+ (void)initialize {
    if (self == [NSLocale class]) {
        _currentLocale = [self new];
    }
}

+ (instancetype)currentLocale {
    return _currentLocale;
}
@end
