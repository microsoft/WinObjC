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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSLocale, Constants) {
    ASSERT_OBJCEQ(NSCurrentLocaleDidChangeNotification, @"kCFLocaleCurrentLocaleDidChangeNotification");

    ASSERT_OBJCEQ(NSLocaleIdentifier, @"kCFLocaleIdentifierKey");

    ASSERT_OBJCEQ(NSLocaleLanguageCode, @"kCFLocaleLanguageCodeKey");

    ASSERT_OBJCEQ(NSLocaleCountryCode, @"kCFLocaleCountryCodeKey");

    ASSERT_OBJCEQ(NSLocaleScriptCode, @"kCFLocaleScriptCodeKey");

    ASSERT_OBJCEQ(NSLocaleVariantCode, @"kCFLocaleVariantCodeKey");

    ASSERT_OBJCEQ(NSLocaleExemplarCharacterSet, @"kCFLocaleExemplarCharacterSetKey");

    ASSERT_OBJCEQ(NSLocaleCalendar, @"kCFLocaleCalendarKey");

    ASSERT_OBJCEQ(NSLocaleCollationIdentifier, @"collation");

    ASSERT_OBJCEQ(NSLocaleUsesMetricSystem, @"kCFLocaleUsesMetricSystemKey");

    ASSERT_OBJCEQ(NSLocaleMeasurementSystem, @"kCFLocaleMeasurementSystemKey");

    ASSERT_OBJCEQ(NSLocaleDecimalSeparator, @"kCFLocaleDecimalSeparatorKey");

    ASSERT_OBJCEQ(NSLocaleGroupingSeparator, @"kCFLocaleGroupingSeparatorKey");

    ASSERT_OBJCEQ(NSLocaleCurrencySymbol, @"kCFLocaleCurrencySymbolKey");

    ASSERT_OBJCEQ(NSLocaleCurrencyCode, @"currency");

    ASSERT_OBJCEQ(NSLocaleCollatorIdentifier, @"kCFLocaleCollatorIdentifierKey");

    ASSERT_OBJCEQ(NSLocaleQuotationBeginDelimiterKey, @"kCFLocaleQuotationBeginDelimiterKey");

    ASSERT_OBJCEQ(NSLocaleQuotationEndDelimiterKey, @"kCFLocaleQuotationEndDelimiterKey");

    ASSERT_OBJCEQ(NSLocaleAlternateQuotationBeginDelimiterKey, @"kCFLocaleAlternateQuotationBeginDelimiterKey");

    ASSERT_OBJCEQ(NSLocaleAlternateQuotationEndDelimiterKey, @"kCFLocaleAlternateQuotationEndDelimiterKey");
}
