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
#import <CoreFoundation/CoreFoundation.h>

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, CurrencyCode) {
    // Disabled due to [SR-250]

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyStyle;
    // numberFormatter.currencyCode = @"T";
    // numberFormatter.currencyDecimalSeparator = @"_";
    // auto formattedString = [numberFormatter stringFromNumber:@42];
    // ASSERT_OBJCEQ(formattedString, @"T 42_00");
}

// Disabled until further investigation is done.
TEST(NSNumberFormatter, DecimalSeparator) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
    numberFormatter.decimalSeparator = @"-";
    NSNumber* num = @42.42;
    auto formattedString = [numberFormatter stringFromNumber:num];
    ASSERT_OBJCEQ(formattedString, @"42-42");
}

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, CurrencyDecimalSeparator) {
    // Disabled due to [SR-250]

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyStyle;
    // numberFormatter.currencyDecimalSeparator = @"-";
    // numberFormatter.currencyCode = @"T";
    // auto formattedString = [numberFormatter stringFromNumber:@42.42];
    // ASSERT_OBJCEQ(formattedString, @"T 42-42");
}

TEST(NSNumberFormatter, AlwaysShowDecimalSeparator) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.decimalSeparator = @"-";
    numberFormatter.alwaysShowsDecimalSeparator = true;
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"42-");
}

// Fail grouping separator
TEST(NSNumberFormatter, DISABLED_GroupingSeparator) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
    numberFormatter.usesGroupingSeparator = YES;
    numberFormatter.groupingSeparator = @"_";
    auto formattedString = [numberFormatter stringFromNumber:@42000];
    ASSERT_OBJCEQ(formattedString, @"42_000");
}

// Percent symbol fails, possibly encoding problem.
TEST(NSNumberFormatter, DISABLED_PercentSymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.numberStyle = NSNumberFormatterPercentStyle;
    numberFormatter.percentSymbol = @"💯";
    auto formattedString = [numberFormatter stringFromNumber:@0.42];
    ASSERT_OBJCEQ(formattedString, @"42💯");
}

TEST(NSNumberFormatter, ZeroSymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.zeroSymbol = @"⚽️";
    auto formattedString = [numberFormatter stringFromNumber:@0];
    ASSERT_OBJCEQ(formattedString, @"⚽️");
}

TEST(NSNumberFormatter, NotANumberSymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.notANumberSymbol = @"👽";
    double number = -42;
    NSNumber* numberObject = [NSNumber numberWithDouble:sqrt(number)];
    auto formattedString = [numberFormatter stringFromNumber:numberObject];
    ASSERT_OBJCEQ(formattedString, @"👽");
}

TEST(NSNumberFormatter, PositiveInfinitySymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.positiveInfinitySymbol = @"🚀";

    NSNumber* numberObject = [NSNumber numberWithDouble:42.0 / 0];
    auto formattedString = [numberFormatter stringFromNumber:numberObject];
    ASSERT_OBJCEQ(formattedString, @"🚀");
}

TEST(NSNumberFormatter, MinusSignSymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.minusSign = @"👎";
    auto formattedString = [numberFormatter stringFromNumber:@-42];
    ASSERT_OBJCEQ(formattedString, @"👎42");
}

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, PlusSignSymbol) {
    // DONTFIXME: How do we show the plus sign from a NSNumberFormatter?

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.plusSign = @"👍";
    // auto formattedString = [numberFormatter stringFromNumber:@42];
    // ASSERT_OBJCEQ(formattedString, @"👍42");
}

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, CurrencySymbol) {
    // Disabled due to [SR-250]

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyStyle;
    // numberFormatter.currencySymbol = @"🍯";
    // numberFormatter.currencyDecimalSeparator = @"_";
    // auto formattedString = [numberFormatter stringFromNumber:@42];
    // ASSERT_OBJCEQ(formattedString, @"🍯 42_00");
}

TEST(NSNumberFormatter, ExponentSymbol) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.numberStyle = NSNumberFormatterScientificStyle;
    numberFormatter.exponentSymbol = @"⬆️";
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"4.2⬆️1");
}

TEST(NSNumberFormatter, MinimumIntegerDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.minimumIntegerDigits = 3;
    auto formattedString = [numberFormatter stringFromNumber:@0];
    ASSERT_OBJCEQ(formattedString, @"000");
}

TEST(NSNumberFormatter, MaximumIntegerDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.maximumIntegerDigits = 3;
    auto formattedString = [numberFormatter stringFromNumber:@1000];
    ASSERT_OBJCEQ(formattedString, @"000");
}

TEST(NSNumberFormatter, MinimumFractionDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.minimumFractionDigits = 3;
    numberFormatter.decimalSeparator = @"-";
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"42-000");
}

TEST(NSNumberFormatter, MaximumFractionDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.maximumFractionDigits = 3;
    numberFormatter.decimalSeparator = @"-";
    auto formattedString = [numberFormatter stringFromNumber:@42.4242];
    ASSERT_OBJCEQ(formattedString, @"42-424");
}

TEST(NSNumberFormatter, GroupingSize) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.groupingSize = 4;
    numberFormatter.groupingSeparator = @"_";
    numberFormatter.usesGroupingSeparator = true;
    auto formattedString = [numberFormatter stringFromNumber:@42000];
    ASSERT_OBJCEQ(formattedString, @"4_2000");
}

// Fails, does not insert grouping separators
TEST(NSNumberFormatter, DISABLED_SecondaryGroupingSize) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.secondaryGroupingSize = 2;
    numberFormatter.groupingSeparator = @"_";
    numberFormatter.usesGroupingSeparator = YES;
    auto formattedString = [numberFormatter stringFromNumber:@42000000];
    ASSERT_OBJCEQ(formattedString, @"4_20_00_000");
}

// Rounded incorrectly, should round up to 42, was rounded down to 41.
TEST(NSNumberFormatter, RoundingMode) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.maximumFractionDigits = 0;
    numberFormatter.roundingMode = NSNumberFormatterRoundCeiling;
    auto formattedString = [numberFormatter stringFromNumber:@41.0001];
    ASSERT_OBJCEQ(formattedString, @"42");
}

// Failed. Expected value is 4.2, actual is 4.
TEST(NSNumberFormatter, DISABLED_RoundingIncrement) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.numberStyle = NSNumberFormatterDecimalStyle;
    numberFormatter.roundingIncrement = @0.2;
    auto formattedString = [numberFormatter stringFromNumber:@4.25];
    ASSERT_OBJCEQ(formattedString, @"4.2");
}

TEST(NSNumberFormatter, FormatWidth) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.paddingCharacter = @"_";
    numberFormatter.formatWidth = 5;
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"___42");
}

// Negative sign appears in incorrect location. "__-42"
TEST(NSNumberFormatter, FormatPosition) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.paddingCharacter = @"_";
    numberFormatter.formatWidth = 5;
    numberFormatter.paddingPosition = NSNumberFormatterPadAfterPrefix;
    auto formattedString = [numberFormatter stringFromNumber:@-42];
    ASSERT_OBJCEQ(formattedString, @"-__42");
}

TEST(NSNumberFormatter, Multiplier) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.multiplier = @2;
    auto formattedString = [numberFormatter stringFromNumber:@21];
    ASSERT_OBJCEQ(formattedString, @"42");
}

TEST(NSNumberFormatter, PositivePrefix) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.positivePrefix = @"👍";
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"👍42");
}

TEST(NSNumberFormatter, PositiveSuffix) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.positiveSuffix = @"👍";
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"42👍");
}

TEST(NSNumberFormatter, NegativePrefix) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.negativePrefix = @"👎";
    auto formattedString = [numberFormatter stringFromNumber:@-42];
    ASSERT_OBJCEQ(formattedString, @"👎42");
}

TEST(NSNumberFormatter, NegativeSuffix) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.negativeSuffix = @"👎";
    auto formattedString = [numberFormatter stringFromNumber:@-42];
    ASSERT_OBJCEQ(formattedString, @"-42👎");
}

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, InternationalCurrencySymbol) {
    // Disabled due to [SR-250]

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyPluralStyle;
    // numberFormatter.internationalCurrencySymbol = @"💵";
    // numberFormatter.currencyDecimalSeparator = @"_";
    // auto formattedString = [numberFormatter stringFromNumber:@42];
    // ASSERT_OBJCEQ(formattedString, @"💵 42_00");
}

// Below test is commented out in line with reference swift tests
TEST(NSNumberFormatter, CurrencyGroupingSeparator) {
    // Disabled due to [SR-250]

    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyStyle;
    // numberFormatter.currencyGroupingSeparator = @"_";
    // numberFormatter.currencyCode = @"T";
    // numberFormatter.currencyDecimalSeparator = @"/";
    // auto formattedString = [numberFormatter stringFromNumber:@42000];
    // ASSERT_OBJCEQ(formattedString, @"T 42_000/00");
}

// Below test is commented out in line with reference swift tests
// DONTFIXME: Something is wrong with numberFromString implementation, I don't know exactly why, but it's not working.
TEST(NSNumberFormatter, Lenient) {
    // NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    // numberFormatter.numberStyle =  NSNumberFormatterCurrencyStyle;
    // auto nilNumberBeforeLenient = [numberFormatter numberFromString:@"42"];
    // ASSERT_OBJCEQ(nilNumberBeforeLenient, nil);
    // numberFormatter.lenient = YES;
    // auto numberAfterLenient = [numberFormatter numberFromString:@"42.42"];
    // ASSERT_OBJCEQ(numberAfterLenient, @42.42);
}

TEST(NSNumberFormatter, MinimumSignificantDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.usesSignificantDigits = true;
    numberFormatter.minimumSignificantDigits = 3;
    auto formattedString = [numberFormatter stringFromNumber:@42];
    ASSERT_OBJCEQ(formattedString, @"42.0");
}

TEST(NSNumberFormatter, MaximumSignificantDigits) {
    NSNumberFormatter* numberFormatter = [[NSNumberFormatter new] autorelease];
    numberFormatter.usesSignificantDigits = true;
    numberFormatter.maximumSignificantDigits = 3;
    auto formattedString = [numberFormatter stringFromNumber:@42.42424242];
    ASSERT_OBJCEQ(formattedString, @"42.4");
}
