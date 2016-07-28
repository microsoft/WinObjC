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

#import "Starboard/SmartTypes.h"
#import "TestFramework.h"
#import "CoreFoundation/CoreFoundation.h"

// Helper that verifies the result of CFURLCreateStringByAddingPercentEscapes
static void testAddPercentEscapes(CFStringRef expected,
                                  CFStringRef string,
                                  CFStringRef charactersToLeaveUnescaped,
                                  CFStringRef legalURLCharactersToBeEscaped,
                                  CFStringEncoding encoding) {
    ASSERT_EQ(kCFCompareEqualTo,
              CFStringCompare(expected,
                              CFURLCreateStringByAddingPercentEscapes(
                                  nullptr, string, charactersToLeaveUnescaped, legalURLCharactersToBeEscaped, encoding),
                              0));
}

// Helper that verifies the result of CFURLCreateStringByReplacingPercentEscapesUsingEncoding
static void testReplacePercentEscapes(CFStringRef expected, CFStringRef string, CFStringRef charactersToLeaveEscaped) {
    ASSERT_EQ(kCFCompareEqualTo,
              CFStringCompare(expected,
                              CFURLCreateStringByReplacingPercentEscapesUsingEncoding(nullptr,
                                                                                      string,
                                                                                      charactersToLeaveEscaped,
                                                                                      kCFStringEncodingUTF8),
                              0));
}

// Asserts string equality, then releases the latter string
static void compareAndRelease(CFStringRef expected, CFStringRef actual) {
    if (expected == nullptr) {
        ASSERT_EQ(expected, actual);
    } else {
        ASSERT_EQ(kCFCompareEqualTo, CFStringCompare(expected, actual, 0));
    }

    if (actual != nullptr) {
        CFRelease(actual);
    }
}

TEST(CFURL, CreateStringByAddingPercentEscapes) {
    // Basic test
    testAddPercentEscapes(CFSTR("Legal?!+=Illegal\%25\%5C\%5E\%3E"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          nullptr,
                          nullptr,
                          kCFStringEncodingUTF8);

    // Empty strings
    testAddPercentEscapes(CFSTR("Legal?!+=Illegal\%25\%5C\%5E\%3E"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR(""),
                          CFSTR(""),
                          kCFStringEncodingUTF8);
    testAddPercentEscapes(CFSTR(""), CFSTR(""), CFSTR(""), CFSTR(""), kCFStringEncodingUTF8);

    // Change encoding
    testAddPercentEscapes(CFSTR("Legal?!+=Illegal\%FF\%FE\%25\%00\%FF\%FE\%5C\%00\%FF\%FE\%5E\%00\%FF\%FE\%3E\%00"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR(""),
                          CFSTR(""),
                          kCFStringEncodingUnicode);

    testAddPercentEscapes(CFSTR("Legal?!+=Illegal\%25\%5C\%5E\%3E"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR(""),
                          CFSTR(""),
                          kCFStringEncodingASCII);

    // Allow chars to remain unescaped
    testAddPercentEscapes(CFSTR("Legal?!+=Illegal\%\\^\%FF\%FE\%3E\%00"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR("\%\\^"),
                          CFSTR(""),
                          kCFStringEncodingUnicode);

    // Force chars to be escaped
    testAddPercentEscapes(CFSTR("Legal\%3F\%21\%2B\%3DIllegal\%25\%5C\%5E\%3E"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR(""),
                          CFSTR("?!+="),
                          kCFStringEncodingASCII);

    // Both
    testAddPercentEscapes(CFSTR("Legal\%FF\%FE\%3F\%00\%FF\%FE\%21\%00\%FF\%FE\%2B\%00\%FF\%FE\%3D\%00Illegal\%\\^\%FF\%FE\%3E\%00"),
                          CFSTR("Legal?!+=Illegal\%\\^>"),
                          CFSTR("\%\\^"),
                          CFSTR("?!+="),
                          kCFStringEncodingUnicode);
}

TEST(CFURL, CreateStringByReplacingPercentEscapes) {
    // Basic test
    testReplacePercentEscapes(CFSTR("Some!String;With?=Characters&"), CFSTR("Some\%21String\%3BWith\%3F\%3DCharacters\%26"), CFSTR(""));
    ASSERT_EQ(kCFCompareEqualTo,
              CFStringCompare(CFSTR("Some!String;With?=Characters&"),
                              CFURLCreateStringByReplacingPercentEscapesUsingEncoding(nullptr,
                                                                                      CFSTR("Some\%21String\%3BWith\%3F\%3DCharacters\%26"),
                                                                                      CFSTR(""),
                                                                                      kCFStringEncodingUTF8),
                              0));

    // Empty charactersToLeaveEscaped
    testReplacePercentEscapes(CFSTR("Some!String;With?=Characters&"), CFSTR("Some\%21String\%3BWith\%3F\%3DCharacters\%26"), CFSTR(""));

    // Lowercase percent encodings
    testReplacePercentEscapes(CFSTR("Some!String;With?=Characters&"), CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"), CFSTR(""));
    ASSERT_EQ(kCFCompareEqualTo,
              CFStringCompare(CFSTR("Some!String;With?=Characters&"),
                              CFURLCreateStringByReplacingPercentEscapesUsingEncoding(nullptr,
                                                                                      CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                                                                                      CFSTR(""),
                                                                                      kCFStringEncodingUTF8),
                              0));

    // Ignore some characters
    testReplacePercentEscapes(CFSTR("Some\%21String;With?\%3dCharacters&"),
                              CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                              CFSTR("!="));

    // Ignore all characters
    testReplacePercentEscapes(CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                              CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                              CFSTR(";?!=&"));

    testReplacePercentEscapes(CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                              CFSTR("Some\%21String\%3bWith\%3f\%3dCharacters\%26"),
                              nullptr);

    // NS Version
}

TEST(CFURL, CopyPath_CopyPathExtension) {
    CFURLRef pathUrl = CFURLCreateWithString(nullptr, CFSTR("http://www.example.com/index.html"), nullptr);
    CFAutorelease(pathUrl);
    compareAndRelease(CFSTR("/index.html"), (CFStringRef)CFURLCopyPath(pathUrl));
    compareAndRelease(CFSTR("/index.html"), (CFStringRef)CFURLCopyPath(static_cast<CFURLRef>(pathUrl)));

    CFURLRef pathExtensionUrl = CFURLCreateWithString(nullptr, CFSTR("file:///path/to/file.txt"), nullptr);
    CFAutorelease(pathExtensionUrl);

    compareAndRelease(CFSTR("txt"), (CFStringRef)CFURLCopyPathExtension(pathExtensionUrl));
    compareAndRelease(CFSTR("txt"), (CFStringRef)CFURLCopyPathExtension(static_cast<CFURLRef>(pathExtensionUrl)));

    CFURLRef emptyUrl = CFURLCreateWithString(nullptr, CFSTR(""), nullptr);
    CFAutorelease(emptyUrl);

    compareAndRelease(nullptr, (CFStringRef)CFURLCopyPath(emptyUrl));
    compareAndRelease(nullptr, (CFStringRef)CFURLCopyPath(static_cast<CFURLRef>(emptyUrl)));
    compareAndRelease(nullptr, (CFStringRef)CFURLCopyPathExtension(emptyUrl));
    compareAndRelease(nullptr, (CFStringRef)CFURLCopyPathExtension(static_cast<CFURLRef>(emptyUrl)));
}