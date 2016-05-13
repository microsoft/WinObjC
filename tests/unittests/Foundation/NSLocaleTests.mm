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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSLocale, PreferredLanguagesTest) {
    LOG_INFO("NSLocale sanity test: ");

    // Basic test to get Preferred Languages.
    NSArray* preferredLanguages = [NSLocale preferredLanguages];
    ASSERT_GE_MSG([preferredLanguages count], 0, "There should always be atleast one default preferred language set!");
    LOG_INFO("System has %d preferred language(s) set.", [preferredLanguages count]);
}

TEST(NSLocale, ObjectForKey) {
    LOG_INFO("NSLocale objectForKey method test: ");

    NSLocale* locale = [NSLocale currentLocale];

    // Note we cannot test for specific value as it depends on the user locale preference set on the device this test is running on.

    // Test NSLocaleIdentifier.
    NSString* localeIdentifier = [locale objectForKey:NSLocaleIdentifier];
    ASSERT_GE_MSG([localeIdentifier length], 0, "NSLocaleIdentifier cannot be empty or nil!");
    LOG_INFO("NSLocaleIdentifier value is %@.", localeIdentifier);

    // Test NSLocaleLanguageCode
    NSString* localeLanguageCode = [locale objectForKey:NSLocaleLanguageCode];
    ASSERT_GE_MSG([localeLanguageCode length], 0, "NSLocaleLanguageCode cannot be empty or nil!");
    LOG_INFO("NSLocaleLanguageCode value is %@.", localeLanguageCode);

    // Test NSLocaleCountryCode
    NSString* localeCountryCode = [locale objectForKey:NSLocaleCountryCode];
    ASSERT_GE_MSG([localeCountryCode length], 0, "NSLocaleCountryCode cannot be empty or nil!");
    LOG_INFO("NSLocaleCountryCode value is %@.", localeCountryCode);

    // Test NSLocaleCurrencyCode
    NSString* localeCurrencyCode = [locale objectForKey:NSLocaleCurrencyCode];
    ASSERT_GE_MSG([localeCurrencyCode length], 0, "NSLocaleCurrencyCode cannot be empty or nil!");
    LOG_INFO("NSLocaleCurrencyCode value is %@.", localeCurrencyCode);

    // Test to verify we get a nil when we ask for some random object key.
    NSString* randomObject = [locale objectForKey:@"RandomObject"];
    ASSERT_EQ_MSG([randomObject length], 0, "Random object for key should return nil!");
}

TEST(NSLocale, ClassMethods) {
    LOG_INFO("NSLocale class method tests: ");
    int count;

    // Test availableLocaleIdentifiers
    LOG_INFO("NSLocale availableLocaleIdentifiers test");
    NSArray* availableLocaleIdentifiers = [NSLocale availableLocaleIdentifiers];
    ASSERT_GE_MSG([availableLocaleIdentifiers count], 0, "There should always be atleast one locale identifier!");
    LOG_INFO("Obtained %d locale identifier(s).", [availableLocaleIdentifiers count]);
    count = 0;
    for (NSString* localeIdentifier in availableLocaleIdentifiers) {
        LOG_INFO("(%d) Locale identifier %@.", ++count, localeIdentifier);
    }

    // Test ISOCountryCodes.
    LOG_INFO("NSLocale ISOCountryCodes test");
    NSArray* ISOCountryCodes = [NSLocale ISOCountryCodes];
    ASSERT_GE_MSG([ISOCountryCodes count], 0, "There should always be atleast one country code returned by the system!");
    LOG_INFO("Obtained %d country code(s).", [ISOCountryCodes count]);
    count = 0;
    for (NSString* ISOCountryCode in ISOCountryCodes) {
        LOG_INFO("(%d) Country code %@.", ++count, ISOCountryCode);
    }

    // Test ISOLanguageCodes.
    LOG_INFO("NSLocale ISOLanguageCodes test");
    NSArray* ISOLanguageCodes = [NSLocale ISOLanguageCodes];
    ASSERT_GE_MSG([ISOLanguageCodes count], 0, "There should always be atleast one language code returned by the system!");
    LOG_INFO("Obtained %d language code(s).", [ISOLanguageCodes count]);
    count = 0;
    for (NSString* ISOLanguageCode in ISOLanguageCodes) {
        LOG_INFO("(%d) Language code %@.", ++count, ISOLanguageCode);
    }

    // Test ISOCurrencyCodes.
    LOG_INFO("NSLocale ISOCurrencyCodes test");
    NSArray* ISOCurrencyCodes = [NSLocale ISOCurrencyCodes];
    ASSERT_GE_MSG([ISOCurrencyCodes count], 0, "There should always be atleast one currency code returned by the system!");
    LOG_INFO("Obtained %d currency code(s).", [ISOCurrencyCodes count]);
    count = 0;
    for (NSString* ISOCurrencyCode in ISOCurrencyCodes) {
        LOG_INFO("(%d) Currency code %@.", ++count, ISOCurrencyCode);
    }

    // Test commonISOCurrencyCodes.
    LOG_INFO("NSLocale commonISOCurrencyCodes test");
    NSArray* commonISOCurrencyCodes = [NSLocale commonISOCurrencyCodes];
    ASSERT_GE_MSG([commonISOCurrencyCodes count], 0, "There should always be atleast one common currency code returned by the system!");
    LOG_INFO("Obtained %d common currency code(s).", [commonISOCurrencyCodes count]);
    count = 0;
    for (NSString* commonISOCurrencyCode in commonISOCurrencyCodes) {
        LOG_INFO("(%d) Common currency code %@.", ++count, commonISOCurrencyCode);
    }
}

TEST(NSLocale, ArchivingUnarchiving) {
    LOG_INFO("NSLocale archiving and unarchiving test: ");

    NSLocale* locale = [NSLocale localeWithLocaleIdentifier:@"en_US"];

    //
    // Get the information from the system.
    //
    // NSLocaleIdentifier.
    NSString* localeIdentifier = [locale objectForKey:NSLocaleIdentifier];
    LOG_INFO("NSLocaleIdentifier value is %@.", localeIdentifier);

    // NSLocaleLanguageCode
    NSString* localeLanguageCode = [locale objectForKey:NSLocaleLanguageCode];
    LOG_INFO("NSLocaleLanguageCode value is %@.", localeLanguageCode);

    // NSLocaleCountryCode
    NSString* localeCountryCode = [locale objectForKey:NSLocaleCountryCode];
    LOG_INFO("NSLocaleCountryCode value is %@.", localeCountryCode);

    // NSLocaleCurrencyCode
    NSString* localeCurrencyCode = [locale objectForKey:NSLocaleCurrencyCode];
    LOG_INFO("NSLocaleCurrencyCode value is %@.", localeCurrencyCode);

    //
    // Archive locale into data.
    //
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:locale];

    //
    // Unarchive locale from data.
    //
    NSLocale* localeUnarchived = [NSKeyedUnarchiver unarchiveObjectWithData:data];

    //
    // Perform test on the unarchived data.
    //
    // NSLocaleIdentifier.
    NSString* localeIdentifierUnarchived = [localeUnarchived objectForKey:NSLocaleIdentifier];
    LOG_INFO("NSLocaleIdentifierUnarchived value is %@.", localeIdentifierUnarchived);
    EXPECT_OBJCEQ_MSG(localeIdentifier, localeIdentifierUnarchived, "localeIdentifier data does not match!");

    // NSLocaleLanguageCode
    NSString* localeLanguageCodeUnarchived = [localeUnarchived objectForKey:NSLocaleLanguageCode];
    LOG_INFO("NSLocaleLanguageCodeUnarchived value is %@.", localeLanguageCodeUnarchived);
    EXPECT_OBJCEQ_MSG(localeLanguageCode, localeLanguageCodeUnarchived, "localeLanguageCode data does not match!");

    // NSLocaleCountryCode
    NSString* localeCountryCodeUnarchived = [localeUnarchived objectForKey:NSLocaleCountryCode];
    LOG_INFO("NSLocaleCountryCodeUnarchived value is %@.", localeCountryCodeUnarchived);
    EXPECT_OBJCEQ_MSG(localeCountryCode, localeCountryCodeUnarchived, "localeCountryCode data does not match!");

    // NSLocaleCurrencyCode
    NSString* localeCurrencyCodeUnarchived = [localeUnarchived objectForKey:NSLocaleCurrencyCode];
    LOG_INFO("NSLocaleCurrencyCodeUnarchived value is %@.", localeCurrencyCodeUnarchived);
    EXPECT_OBJCEQ_MSG(localeCurrencyCode, localeCurrencyCodeUnarchived, "localeCurrencyCodeUnarchived data does not match!");
}

TEST(NSLocale, BasicTests) {
    //
    // Basic tests to make sure various locales can be instantiated.
    //
    NSLocale* testLocale = [NSLocale localeWithLocaleIdentifier:@"en_US"];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"en_US");

    testLocale = [NSLocale localeWithLocaleIdentifier:@"tr"];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"tr");

    testLocale = [NSLocale localeWithLocaleIdentifier:@"de_DE"];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"de_DE");

    testLocale = [NSLocale localeWithLocaleIdentifier:@"en_GB"];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"en_GB");

    testLocale = [NSLocale localeWithLocaleIdentifier:@"gibberish"];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"gibberish");

    // Should legitimately be a blank identifier.
    testLocale = [NSLocale systemLocale];
    ASSERT_OBJCEQ([testLocale localeIdentifier], @"");

    // Actual user setting locale, should not be empty.
    testLocale = [NSLocale currentLocale];
    ASSERT_OBJCNE([testLocale localeIdentifier], @"");
}