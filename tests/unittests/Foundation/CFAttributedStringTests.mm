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
#import <Starboard.h>
#import <CoreFoundation\CFAttributedString.h>
#import <CoreFoundation\CFString.h>
#import <Foundation\Foundation.h>

void assertAttributeAt(
    CFAttributedStringRef aStr, CFStringRef attrName, CFTypeRef expectedValue, CFIndex expectedLocation, CFIndex expectedLength) {
    CFRange outRange;

    CFTypeRef attribute = CFAttributedStringGetAttribute(aStr, expectedLocation, attrName, &outRange);
    ASSERT_EQ(expectedValue, attribute);
    ASSERT_EQ(expectedLocation, outRange.location);
    ASSERT_EQ(expectedLength, outRange.length);
}

static CFStringRef key1 = (__bridge CFStringRef) @"key1";
static CFStringRef key2 = (__bridge CFStringRef) @"key2";
static CFStringRef key3 = (__bridge CFStringRef) @"key3";
static CFStringRef value1 = (__bridge CFStringRef) @"value1";
static CFStringRef value2 = (__bridge CFStringRef) @"value2";
static CFStringRef value3 = (__bridge CFStringRef) @"value3";

TEST(CFAttributedString, ReplaceString) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");
    ASSERT_EQ(YES, CFEqual((__bridge CFStringRef) @"CFAttributedString", CFAttributedStringGetString(aStr)));
    ASSERT_EQ([@"CFAttributedString" length], CFAttributedStringGetLength(aStr));

    CFRelease(aStr);
}

TEST(CFAttributedString, SetGetAttribute) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");
    CFAttributedStringSetAttribute(aStr, { 1, 5 }, key1, value1);
    assertAttributeAt(aStr, key1, value1, 1, 5);

    CFRelease(aStr);
}

TEST(CFAttributedString, SetGetRemoveAttributes) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");

    CFDictionaryRef dict = (__bridge CFDictionaryRef)
        @{ (__bridge NSString*) key1 : (__bridge NSString*)value1, (__bridge NSString*) key2 : (__bridge NSString*)value2 };

    CFAttributedStringSetAttributes(aStr, { 0, 4 }, dict, false);
    assertAttributeAt(aStr, key1, value1, 0, 4);
    assertAttributeAt(aStr, key2, value2, 0, 4);

    // Don't clear existing attributes, should append the ranges
    CFAttributedStringSetAttributes(aStr, { 4, 4 }, dict, false);
    assertAttributeAt(aStr, key1, value1, 0, 8);
    assertAttributeAt(aStr, key2, value2, 0, 8);

    // Clear existing attributes
    CFAttributedStringSetAttributes(aStr,
                                    { 4, 2 },
                                    (__bridge CFDictionaryRef) @{ (__bridge NSString*) key1 : (__bridge NSString*)value2 },
                                    true);
    assertAttributeAt(aStr, key1, value2, 4, 2);
    assertAttributeAt(aStr, key2, NULL, 4, 2);

    // Remove half the attribute
    CFAttributedStringRemoveAttribute(aStr, { 4, 1 }, key1);
    assertAttributeAt(aStr, key1, NULL, 4, 1);
    assertAttributeAt(aStr, key1, value2, 5, 1);

    CFRelease(aStr);
    CFRelease(dict);
}

TEST(CFAttributedString, ReplaceAttributedString) {
    CFMutableAttributedStringRef aStr1 = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr1, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");

    CFAttributedStringRef aStr2 =
        CFAttributedStringCreate(NULL,
                                 (__bridge CFStringRef) @"StringTwo",
                                 (__bridge CFDictionaryRef) @{ (__bridge NSString*) key1 : (__bridge NSString*)value1 });

    CFAttributedStringReplaceAttributedString(aStr1, { 0, 2 }, aStr2);
    assertAttributeAt(aStr1, key1, value1, 0, 9);
    ASSERT_EQ(YES, CFEqual((__bridge CFStringRef) @"StringTwoAttributedString", CFAttributedStringGetString(aStr1)));

    CFRelease(aStr1);
    CFRelease(aStr2);
}

TEST(CFAttributedString, CreateMutableCopy) {
    CFAttributedStringRef aStr =
        CFAttributedStringCreate(NULL,
                                 (__bridge CFStringRef) @"Objective-C",
                                 (__bridge CFDictionaryRef) @{ (__bridge NSString*) key1 : (__bridge NSString*)value1 });
    CFMutableAttributedStringRef aStrCopy = CFAttributedStringCreateMutableCopy(NULL, 1024, aStr);
    ASSERT_EQ(YES, [(__bridge NSAttributedString*)aStr isEqualToAttributedString:(__bridge NSAttributedString*)aStrCopy]);
}

TEST(CFAttributedString, GetAttribute_s_AndLongestEffectiveRange) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");
    CFAttributedStringSetAttribute(aStr, { 0, 2 }, key1, value1);
    CFAttributedStringSetAttribute(aStr, { 0, 10 }, key2, value2);

    CFRange outRange;

    ASSERT_EQ(value1, CFAttributedStringGetAttribute(aStr, 0, key1, &outRange));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(2, outRange.length);

    ASSERT_EQ(value1, CFAttributedStringGetAttributeAndLongestEffectiveRange(aStr, 0, key1, { 0, 1 }, &outRange));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(1, outRange.length);

    CFDictionaryRef expectedDict = (__bridge CFDictionaryRef)
        @{ (__bridge NSString*) key1 : (__bridge NSString*)value1, (__bridge NSString*) key2 : (__bridge NSString*)value2 };

    ASSERT_EQ(true, CFEqual(expectedDict, CFAttributedStringGetAttributes(aStr, 0, &outRange)));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(2, outRange.length);

    ASSERT_EQ(true, CFEqual(expectedDict, CFAttributedStringGetAttributesAndLongestEffectiveRange(aStr, 0, { 0, 1 }, &outRange)));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(1, outRange.length);

    CFRelease(aStr);
    CFRelease(expectedDict);
}

TEST(CFAttributedString, CreateWithSubstring) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, (__bridge CFStringRef) @"CFAttributedString");
    CFAttributedStringSetAttribute(aStr, { 0, 2 }, key1, value1);
    CFAttributedStringSetAttribute(aStr, { 0, 10 }, key2, value2);

    CFAttributedStringRef subStr = CFAttributedStringCreateWithSubstring(NULL, aStr, { 0, 3 });
    assertAttributeAt(subStr, key1, value1, 0, 2);
    assertAttributeAt(subStr, key2, value2, 0, 3);
    ASSERT_EQ(YES, CFEqual((__bridge CFStringRef) @"CFA", CFAttributedStringGetString(subStr)));

    CFRelease(aStr);
    CFRelease(subStr);
}