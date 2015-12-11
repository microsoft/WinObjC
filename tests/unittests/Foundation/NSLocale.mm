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

TEST(Foundation, NSLocale_SanityTest) {
    LOG_INFO("NSLocale sanity test: ");

    // Basic test to get preferredLanguages.
    NSArray* preferredLanguages = [NSLocale preferredLanguages];
    ASSERT_GE_MSG([preferredLanguages count], 0, "There should always be atleast one default preferred language set!");
    LOG_INFO("System has %d preferred language(s) set.", [preferredLanguages count]);
}

TEST(Foundation, NSLocale_ObjectForKey) {
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