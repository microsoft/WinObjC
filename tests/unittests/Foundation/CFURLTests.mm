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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

// Helper that verifies the result of CFURLCreateStringByAddingPercentEscapes
static void testAddPercentEscapes(NSString* expected,
                                  NSString* string,
                                  NSString* charactersToLeaveUnescaped,
                                  NSString* legalURLCharactersToBeEscaped,
                                  CFStringEncoding encoding) {
    ASSERT_OBJCEQ(expected,
                  (NSString*)CFURLCreateStringByAddingPercentEscapes(nullptr,
                                                                     (CFStringRef)string,
                                                                     (CFStringRef)charactersToLeaveUnescaped,
                                                                     (CFStringRef)legalURLCharactersToBeEscaped,
                                                                     encoding));
}

// Helper that verifies the result of CFURLCreateStringByReplacingPercentEscapesUsingEncoding
static void testReplacePercentEscapes(NSString* expected, NSString* string, NSString* charactersToLeaveEscaped) {
    ASSERT_OBJCEQ(expected,
                  (NSString*)CFURLCreateStringByReplacingPercentEscapesUsingEncoding(nullptr,
                                                                                     (CFStringRef)string,
                                                                                     (CFStringRef)charactersToLeaveEscaped,
                                                                                     kCFStringEncodingUTF8));
}

TEST(Foundation, CFURLCreateStringByAddingPercentEscapes) {
    // Basic test
    testAddPercentEscapes(@"Legal?!+=Illegal\%25\%5C\%5E\%3E", @"Legal?!+=Illegal\%\\^>", nullptr, nullptr, kCFStringEncodingUTF8);

    // Empty strings
    testAddPercentEscapes(@"Legal?!+=Illegal\%25\%5C\%5E\%3E", @"Legal?!+=Illegal\%\\^>", @"", @"", kCFStringEncodingUTF8);
    testAddPercentEscapes(@"", @"", @"", @"", kCFStringEncodingUTF8);

    // Change encoding
    testAddPercentEscapes(@"Legal?!+=Illegal\%25\%5C\%5E\%3E", @"Legal?!+=Illegal\%\\^>", @"", @"", kCFStringEncodingUnicode);
    testAddPercentEscapes(@"Legal?!+=Illegal\%25\%5C\%5E\%3E", @"Legal?!+=Illegal\%\\^>", @"", @"", kCFStringEncodingASCII);

    // Allow chars to remain unescaped
    testAddPercentEscapes(@"Legal?!+=Illegal\%\\^\%3E", @"Legal?!+=Illegal\%\\^>", @"\%\\^", @"", kCFStringEncodingUnicode);

    // Force chars to be escaped
    testAddPercentEscapes(@"Legal\%3F\%21\%2B\%3DIllegal\%25\%5C\%5E\%3E", @"Legal?!+=Illegal\%\\^>", @"", @"?!+=", kCFStringEncodingASCII);

    // Both
    testAddPercentEscapes(@"Legal\%3F\%21\%2B\%3DIllegal\%\\^\%3E", @"Legal?!+=Illegal\%\\^>", @"\%\\^", @"?!+=", kCFStringEncodingUnicode);
}

TEST(Foundation, CFURLCreateStringByReplacingPercentEscapes) {
    // Basic test
    testReplacePercentEscapes(@"Some!String;With?=Characters&", @"Some\%21String\%3BWith\%3F\%3DCharacters\%26", nullptr);
    ASSERT_OBJCEQ(@"Some!String;With?=Characters&",
                  [@"Some\%21String\%3BWith\%3F\%3DCharacters\%26" stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]);

    // Empty charactersToLeaveEscaped
    testReplacePercentEscapes(@"Some!String;With?=Characters&", @"Some\%21String\%3BWith\%3F\%3DCharacters\%26", @"");

    // Lowercase percent encodings
    testReplacePercentEscapes(@"Some!String;With?=Characters&", @"Some\%21String\%3bWith\%3f\%3dCharacters\%26", @"");
    ASSERT_OBJCEQ(@"Some!String;With?=Characters&",
                  [@"Some\%21String\%3bWith\%3f\%3dCharacters\%26" stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding]);

    // Ignore some characters
    testReplacePercentEscapes(@"Some\%21String;With?\%3dCharacters&", @"Some\%21String\%3bWith\%3f\%3dCharacters\%26", @"\%21\%3d");

    // Ignore all characters
    testReplacePercentEscapes(@"Some\%21String\%3bWith\%3f\%3dCharacters\%26",
                              @"Some\%21String\%3bWith\%3f\%3dCharacters\%26",
                              @"\%21\%3b\%3f\%3d\%26");

    // NS Version
}