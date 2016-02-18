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

TEST(Foundation, NSRegularExpressionTests) {
    LOG_INFO("NSRegularExpression test: ");
    NSError* error = nil;

    // Test that we can do a simple regex search.
    NSRegularExpression* regex =
        [NSRegularExpression regularExpressionWithPattern:@"(sub)(.*)" options:NSRegularExpressionCaseInsensitive error:&error];

    NSString* testString = @"test subject";
    NSRange range = { 0, testString.length };
    NSUInteger matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    int numberOfCaptureGroups = regex.numberOfCaptureGroups;

    ASSERT_EQ(numberOfCaptureGroups, 2);

    testString = @"test SuBjEcT";
    matches = [regex numberOfMatchesInString:testString options:0 range:range];
    ASSERT_EQ(matches, 1);

    // Test that a case sensitive match will not match incorrect case of a string.
    regex = [NSRegularExpression regularExpressionWithPattern:@"(SuB)(.*)" options:0 error:&error];
    matches = [regex numberOfMatchesInString:testString options:0 range:range];
    ASSERT_EQ(matches, 1);

    testString = @"test subject";
    matches = [regex numberOfMatchesInString:testString options:0 range:range];
    ASSERT_EQ(matches, 0);

    regex = [NSRegularExpression regularExpressionWithPattern:@"Bad" options:NSRegularExpressionCaseInsensitive error:&error];

    testString = @"Bad Match";
    range = { 0, testString.length };

    NSTextCheckingResult* firstMatch = [regex firstMatchInString:testString options:NSRegularExpressionCaseInsensitive range:range];
    NSRange rangeresult = firstMatch.range;

    NSString* replaced = [regex replacementStringForResult:firstMatch inString:testString offset:0 template:@"Good"];
    ASSERT_OBJCEQ(@"Good", replaced);

    replaced = [regex stringByReplacingMatchesInString:testString options:0 range:rangeresult withTemplate:@"Good"];

    ASSERT_OBJCEQ(@"Good Match", replaced);

    // We replaced "Bad" with "Good" so the offset is +1
    NSTextCheckingResult* offsetFromReplacement = [firstMatch resultByAdjustingRangesWithOffset:1];

    rangeresult = offsetFromReplacement.range;
    ASSERT_EQ(rangeresult.location, 1);

    regex = [NSRegularExpression regularExpressionWithPattern:@"iOS" options:0 error:&error];

    NSMutableString* mutableTestString = [@"iOS is amazing" mutableCopy];
    matches = [regex replaceMatchesInString:mutableTestString
                                    options:NSRegularExpressionCaseInsensitive
                                      range:{ 0, mutableTestString.length }
                               withTemplate:@"Windows"];

    ASSERT_OBJCEQ(@"Windows is amazing", mutableTestString);

    testString = @"The Windows bridge for iOS";

    NSRange theRange =
        [regex rangeOfFirstMatchInString:testString options:NSRegularExpressionCaseInsensitive range:NSMakeRange(0, testString.length)];

    ASSERT_EQ(theRange.location, 23);
    ASSERT_EQ(theRange.length, 3);

    testString = @"Windows is great!";

    theRange =
        [regex rangeOfFirstMatchInString:testString options:NSRegularExpressionCaseInsensitive range:NSMakeRange(0, testString.length)];

    ASSERT_EQ(theRange.location, NSNotFound);
    ASSERT_EQ(theRange.length, 0);

    NSString* escapedPattern = [NSRegularExpression escapedPatternForString:@"The following characters should be escaped: $^*()+/?[{}. \\"];
    NSString* escapedTemplate = [NSRegularExpression escapedPatternForString:@"Only $ and \\ should be escaped"];

    ASSERT_OBJCEQ(@"The following characters should be escaped: \\$\\^\\*\\(\\)\\+\\/\\?\\[\\{\\}\\. \\\\", escapedPattern);
    ASSERT_OBJCEQ(@"Only \\$ and \\\\ should be escaped", escapedTemplate);
}

TEST(Foundation, NSRegularExpression_ArchivingUnarchiving) {
    LOG_INFO("NSRegularExpression archiving and unarchiving test: ");

    NSRegularExpression* regex =
        [NSRegularExpression regularExpressionWithPattern:@"(sub)(.*)" options:NSRegularExpressionCaseInsensitive error:nullptr];

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:regex];

    NSRegularExpression* regularExpressionUnarchived = [NSKeyedUnarchiver unarchiveObjectWithData:data];

    // Simple test that NSRegularExpression is working
    NSString* testString = @"test subject";
    NSRange range = { 0, testString.length };
    NSUInteger matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    testString = @"test SuBJeCt";
    matches = [regex numberOfMatchesInString:testString options:0 range:range];
    ASSERT_EQ(matches, 1);

    NSTextCheckingResult* firstMatch = [regex firstMatchInString:testString options:NSRegularExpressionCaseInsensitive range:range];
    NSRange rangeresult = firstMatch.range;

    // NSTextCheckingResult* jj = [[NSTextCheckingResult alloc] init];
    NSData* textCheckingData = [NSKeyedArchiver archivedDataWithRootObject:firstMatch];

    NSTextCheckingResult* textCheckUnarchived = [NSKeyedUnarchiver unarchiveObjectWithData:textCheckingData];

    NSRange unarchivedRange = textCheckUnarchived.range;

    ASSERT_EQ(rangeresult.location, unarchivedRange.location);
    ASSERT_EQ(rangeresult.length, unarchivedRange.length);
}

TEST(Foundation, NSRegularExpression_OptionsTest) {
    NSRegularExpression* regex =
        [NSRegularExpression regularExpressionWithPattern:@"(sub)(.*)" options:NSRegularExpressionCaseInsensitive error:nullptr];

    NSString* testString = @"test subject";
    NSRange range = { 0, testString.length };
    NSUInteger matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    regex = [NSRegularExpression regularExpressionWithPattern:@"t h i s m a t c h"
                                                      options:NSRegularExpressionAllowCommentsAndWhitespace
                                                        error:nullptr];

    testString = @"thismatch";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    regex = [NSRegularExpression regularExpressionWithPattern:@"Match [this] entire $ sentence."
                                                      options:NSRegularExpressionIgnoreMetacharacters
                                                        error:nullptr];

    testString = @"Match [this] entire $ sentence.";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    regex =
        [NSRegularExpression regularExpressionWithPattern:@"line.test" options:NSRegularExpressionDotMatchesLineSeparators error:nullptr];

    testString = @"newline\ntest";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    regex = [NSRegularExpression regularExpressionWithPattern:@"^is$" options:NSRegularExpressionAnchorsMatchLines error:nullptr];

    testString = @"Only this\nis\nis a match";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    regex =
        [NSRegularExpression regularExpressionWithPattern:@"here$"
                                                  options:(NSRegularExpressionUseUnixLineSeparators | NSRegularExpressionAnchorsMatchLines)
                                                    error:nullptr];

    testString = @"Don't match here\rOnly match here\nextra";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 1);

    // Try to match all line separators, not just unix to validate above test.
    regex = [NSRegularExpression regularExpressionWithPattern:@"here$" options:(NSRegularExpressionAnchorsMatchLines) error:nullptr];

    testString = @"Match here\rAnd also match here\nextra";
    range = { 0, testString.length };
    matches = [regex numberOfMatchesInString:testString options:0 range:range];

    ASSERT_EQ(matches, 2);
}

TEST(Foundation, NSRegularExpressionErrorTest) {
    NSError* error = nil;
    NSRegularExpression* regex =
        [NSRegularExpression regularExpressionWithPattern:@"(" options:NSRegularExpressionCaseInsensitive error:&error];

    EXPECT_OBJCEQ(regex, nil);
    EXPECT_OBJCNE(error, nil);
}