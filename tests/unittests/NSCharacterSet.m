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

// Every character in NSString* testString must exist in the character set passed in.
void testCharacter(NSCharacterSet* charSet, NSString* testString) {
    unsigned int stringLength = [testString length];
    NSInteger charSetLength = [charSet count];

    ASSERT_TRUE_MSG(stringLength == charSetLength,
                    "FAILED: Character set has different length than expected.\nExpected: %d\nActual: %d",
                    stringLength,
                    charSetLength);

    for (int i = 0; i < stringLength; i++) {
        unichar current = [testString characterAtIndex:i];
        ASSERT_TRUE_MSG(
            [charSet characterIsMember:current],
            "FAILED: [CharacterSet characterIsMember:current] has mismatched character between expected and actual.\nCharacter: %c",
            current);
    }
}

// This is for testing whether or not the character set is actually instantiated in the correct way and contains the expected characters.
TEST(Foundation, NSCharacterSet_SanityTest) {
    LOG_INFO("NSCharacterSet sanity test: ");

    NSCharacterSet* alphaNumeric = [NSCharacterSet alphanumericCharacterSet];
    NSString* alphaNumericString = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    NSCharacterSet* decimalDigitCharacterSet = [NSCharacterSet decimalDigitCharacterSet];
    NSString* decimalDigitCharacterSetString = @"0123456789";

    NSCharacterSet* letterCharacterSet = [NSCharacterSet letterCharacterSet];
    NSString* letterCharacterSetString = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    NSCharacterSet* lowercaseLetterCharacterSet = [NSCharacterSet lowercaseLetterCharacterSet];
    NSString* lowercaseLetterCharacterSetString = @"abcdefghijklmnopqrstuvwxyz";

    NSCharacterSet* newlineCharacterSet = [NSCharacterSet newlineCharacterSet];
    NSString* newlineCharacterSetString = @"\r\n";

    NSCharacterSet* punctuationCharacterSet = [NSCharacterSet punctuationCharacterSet];
    NSString* punctuationCharacterSetString = @"!\"%'(),-./:;?[\\]{}";

    NSCharacterSet* uppercaseLetterCharacterSet = [NSCharacterSet uppercaseLetterCharacterSet];
    NSString* uppercaseLetterCharacterSetString = @"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    NSCharacterSet* whitespaceAndNewlineCharacterSet = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    NSString* whitespaceAndNewlineCharacterSetString = @" \t\r\n";

    NSCharacterSet* whitespaceCharacterSet = [NSCharacterSet whitespaceCharacterSet];
    NSString* whitespaceCharacterSetString = @" \t";

    NSCharacterSet* URLFragmentAllowedCharacterSet = [NSCharacterSet URLFragmentAllowedCharacterSet];
    NSString* URLFragmentAllowedCharacterSetString = @"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";

    NSCharacterSet* URLHostAllowedCharacterSet = [NSCharacterSet URLHostAllowedCharacterSet];
    NSString* URLHostAllowedCharacterSetString = @"!$&'()*+,-.0123456789:;=ABCDEFGHIJKLMNOPQRSTUVWXYZ[]_abcdefghijklmnopqrstuvwxyz~";

    NSCharacterSet* URLPasswordAllowedCharacterSet = [NSCharacterSet URLPasswordAllowedCharacterSet];
    NSString* URLPasswordAllowedCharacterSetString = @"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";

    NSCharacterSet* URLPathAllowedCharacterSet = [NSCharacterSet URLPathAllowedCharacterSet];
    NSString* URLPathAllowedCharacterSetString = @"!$&'()*+,-./0123456789:=@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";

    NSCharacterSet* URLQueryAllowedCharacterSet = [NSCharacterSet URLQueryAllowedCharacterSet];
    NSString* URLQueryAllowedCharacterSetString = @"!$&'()*+,-./0123456789:;=?@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";

    NSCharacterSet* URLUserAllowedCharacterSet = [NSCharacterSet URLUserAllowedCharacterSet];
    NSString* URLUserAllowedCharacterSetString = @"!$&'()*+,-.0123456789;=ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz~";

    testCharacter(alphaNumeric, alphaNumericString);
    testCharacter(decimalDigitCharacterSet, decimalDigitCharacterSetString);
    testCharacter(letterCharacterSet, letterCharacterSetString);
    testCharacter(lowercaseLetterCharacterSet, lowercaseLetterCharacterSetString);
    testCharacter(newlineCharacterSet, newlineCharacterSetString);
    testCharacter(punctuationCharacterSet, punctuationCharacterSetString);
    testCharacter(uppercaseLetterCharacterSet, uppercaseLetterCharacterSetString);
    testCharacter(whitespaceAndNewlineCharacterSet, whitespaceAndNewlineCharacterSetString);
    testCharacter(whitespaceCharacterSet, whitespaceCharacterSetString);

    testCharacter(URLFragmentAllowedCharacterSet, URLFragmentAllowedCharacterSetString);
    testCharacter(URLHostAllowedCharacterSet, URLHostAllowedCharacterSetString);
    testCharacter(URLPasswordAllowedCharacterSet, URLPasswordAllowedCharacterSetString);
    testCharacter(URLPathAllowedCharacterSet, URLPathAllowedCharacterSetString);
    testCharacter(URLQueryAllowedCharacterSet, URLQueryAllowedCharacterSetString);
    testCharacter(URLUserAllowedCharacterSet, URLUserAllowedCharacterSetString);
}

TEST(Foundation, NSCharacterSet_MutableCopy) {
    NSCharacterSet* alphaNumeric = [NSCharacterSet alphanumericCharacterSet];
    NSMutableCharacterSet* mutableSet = [alphaNumeric mutableCopy];
    [mutableSet addCharactersInString:@"!"];

    NSString* bangOnlyString = @"!";

    NSRange foundAlphaRange = [bangOnlyString rangeOfCharacterFromSet:alphaNumeric];
    ASSERT_EQ_MSG(NSNotFound, foundAlphaRange.location, "mutable copy should not have mutated the original!");
    NSRange foundBangRange = [bangOnlyString rangeOfCharacterFromSet:mutableSet];
    ASSERT_NE(NSNotFound, foundBangRange.location);

    EXPECT_NO_THROW([mutableSet release]);
}

TEST(Foundation, NSCharacterSet_InvertTest) {
    NSCharacterSet* alphaNumeric = [NSCharacterSet alphanumericCharacterSet];
    NSString* alphaNumericString = @"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    NSCharacterSet* invertedSet = [alphaNumeric invertedSet];

    NSRange foundNonAlphaRange = [alphaNumericString rangeOfCharacterFromSet:invertedSet];

    ASSERT_EQ(NSNotFound, foundNonAlphaRange.location);
}