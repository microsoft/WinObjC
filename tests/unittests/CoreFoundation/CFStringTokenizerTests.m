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

#include "gtest-api.h"
#include <CoreFoundation/CFStringTokenizer.h>
#include <CoreFoundation/CFString.h>

static void verifyRange(CFStringTokenizerRef tokenizer, CFIndex location, CFIndex length) {
    ASSERT_NE(CFStringTokenizerAdvanceToNextToken(tokenizer), kCFStringTokenizerTokenNone);
    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(range.location, location);
    ASSERT_EQ(range.length, length);
}

static void verifyCount(CFStringTokenizerRef tokenizer, int count) {
    CFStringTokenizerTokenType tokenType = kCFStringTokenizerTokenNone;
    unsigned int index = 0;
    CFRange invalidRange = CFRangeMake(0, -1);
    while (kCFStringTokenizerTokenNone != (tokenType = CFStringTokenizerAdvanceToNextToken(tokenizer))) {
        CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
        ASSERT_NE(range.length, invalidRange.length);
        index++;
    }
    ASSERT_EQ(count, index);
}

TEST(CFStringTokenizer, EnglishWordBreak) {
    CFStringRef string = CFSTR("dog cat pig");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 5);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, EnglishWordBreakEmpty) {
    CFStringRef string = CFSTR("");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    ASSERT_EQ(CFStringTokenizerAdvanceToNextToken(tokenizer), kCFStringTokenizerTokenNone);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, NULLString) {
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer =
        CFStringTokenizerCreate(kCFAllocatorDefault, NULL, CFRangeMake(0, -1), kCFStringTokenizerUnitWordBoundary, locale);
    ASSERT_TRUE(NULL != tokenizer);
    ASSERT_EQ(CFStringTokenizerAdvanceToNextToken(tokenizer), kCFStringTokenizerTokenNone);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, EnglishWordBreakRange) {
    CFStringRef string = CFSTR("dog cat pig");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string /*dog cat */,
                                                             CFRangeMake(0, CFStringGetLength(string) - 3),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 4);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, EnglishWordBreak2) {
    CFStringRef string = CFSTR("hello\r\n world. \r new line?\rn");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 14);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, EnglishSentenceBreak2) {
    CFStringRef string = CFSTR("hello\r\n world. \r new line?\rn");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitSentence,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 4);

    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, ChineseWordBreak) {
    CFStringRef string = CFSTR(/*I love Microsoft*/ "我爱微软");

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("zh-cn"));

    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyRange(tokenizer, 0, 1); // 我 I
    verifyRange(tokenizer, 1, 1); // 爱 love
    verifyRange(tokenizer, 2, 2); // 微软 microsoft

    CFRelease(tokenizer);
    CFRelease(locale);
}
TEST(CFStringTokenizer, ChineseWordBreakRange) {
    CFStringRef string = CFSTR(/*I love Microsoft*/ "我爱微软");

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("zh-cn"));

    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string /*I love*/,
                                                             CFRangeMake(0, CFStringGetLength(string) - 2),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyRange(tokenizer, 0, 1); // 我 I
    verifyRange(tokenizer, 1, 1); // 爱 love
    ASSERT_EQ(CFStringTokenizerAdvanceToNextToken(tokenizer), kCFStringTokenizerTokenNone);

    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, ArabicWordBreak) {
    CFStringRef string = CFSTR(/*System Preferences*/ "تفضيلات النظام");

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));

    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyRange(tokenizer, 0, 7); // تفضيلات
    verifyRange(tokenizer, 7, 1); // space
    verifyRange(tokenizer, 8, 6); // النظام

    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, ArabicWordBreakRange) {
    CFStringRef string = CFSTR(/*System Preferences*/ "تفضيلات النظام");

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));

    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string) - 4),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyRange(tokenizer, 0, 7); // تفضيلات
    verifyRange(tokenizer, 7, 1); // space
    verifyRange(tokenizer, 8, 2); // ظام
    ASSERT_EQ(CFStringTokenizerAdvanceToNextToken(tokenizer), kCFStringTokenizerTokenNone);

    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, ArabicSentenceBreak) {
    CFStringRef string = CFSTR(
        "هم الغرب ونحن العرب .. والفرق بيننا نقطة..هم يتفاهمون بالحوار ونحن بالخوار .. والفرق بيننا نقطة .. هم يعيشون مع بعضهم البعض "
        "في حالة تحالف ونحن في تخالف .. والفرق بيننا نقطة . ");
    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitSentence,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 6);

    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, ArabicLineBreak) {
    CFStringRef string = CFSTR(
        "هم الغرب ونحن العرب .. والفرق بيننا نقطة..هم يتفاهمون بالحوار ونحن بالخوار .. والفرق بيننا نقطة .. هم يعيشون مع بعضهم البعض "
        "في حالة تحالف ونحن في تخالف .. والفرق بيننا نقطة . ");
    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitLineBreak,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    verifyCount(tokenizer, 28);

    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, EnglishWordBreakGoToIndex) {
    CFStringRef string = CFSTR("Hello World");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    ASSERT_NE(kCFStringTokenizerTokenNone, CFStringTokenizerGoToTokenAtIndex(tokenizer, 10));

    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(6, range.location);
    ASSERT_EQ(5, range.length);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, ArabicWordBreakGoToIndex) {
    CFStringRef string = CFSTR(/*System Preferences*/ "تفضيلات النظام");

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));

    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    ASSERT_NE(kCFStringTokenizerTokenNone, CFStringTokenizerGoToTokenAtIndex(tokenizer, 10));
    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(range.location, 8);
    ASSERT_EQ(range.length, 6);
    CFRelease(tokenizer);
    CFRelease(locale);
}

TEST(CFStringTokenizer, EnglishWordBreakGoToIndex2) {
    CFStringRef string = CFSTR("Hello World");
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer = CFStringTokenizerCreate(kCFAllocatorDefault,
                                                             string,
                                                             CFRangeMake(0, CFStringGetLength(string)),
                                                             kCFStringTokenizerUnitWordBoundary,
                                                             locale);
    ASSERT_TRUE(NULL != tokenizer);
    ASSERT_NE(kCFStringTokenizerTokenNone, CFStringTokenizerGoToTokenAtIndex(tokenizer, 8));

    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(6, range.location);
    ASSERT_EQ(5, range.length);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, EnglishSetText) {
    CFLocaleRef locale = CFLocaleCopyCurrent();
    CFStringTokenizerRef tokenizer =
        CFStringTokenizerCreate(kCFAllocatorDefault, NULL, CFRangeMake(0, -1), kCFStringTokenizerUnitWordBoundary, locale);

    ASSERT_TRUE(NULL != tokenizer);

    CFStringRef string = CFSTR("Hello World");
    ASSERT_NO_THROW({ CFStringTokenizerSetString(tokenizer, string, CFRangeMake(0, CFStringGetLength(string))); });

    ASSERT_NE(kCFStringTokenizerTokenNone, CFStringTokenizerGoToTokenAtIndex(tokenizer, 8));

    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(6, range.location);
    ASSERT_EQ(5, range.length);
    CFRelease(locale);
    CFRelease(tokenizer);
}

TEST(CFStringTokenizer, ArabicWordSetText) {
    CFStringRef string = NULL;

    CFLocaleRef locale = CFLocaleCreate(kCFAllocatorDefault, CFSTR("az-Arab"));

    CFStringTokenizerRef tokenizer =
        CFStringTokenizerCreate(kCFAllocatorDefault, string, CFRangeMake(0, -1), kCFStringTokenizerUnitWordBoundary, locale);
    ASSERT_TRUE(NULL != tokenizer);

    string = CFSTR(/*System Preferences*/ "تفضيلات النظام");
    ASSERT_NO_THROW({ CFStringTokenizerSetString(tokenizer, string, CFRangeMake(0, CFStringGetLength(string))); });

    ASSERT_NE(kCFStringTokenizerTokenNone, CFStringTokenizerGoToTokenAtIndex(tokenizer, 10));
    CFRange range = CFStringTokenizerGetCurrentTokenRange(tokenizer);
    ASSERT_EQ(range.location, 8);
    ASSERT_EQ(range.length, 6);
    CFRelease(tokenizer);
    CFRelease(locale);
}