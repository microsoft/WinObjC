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

static CFStringRef key1 = CFSTR("key1");
static CFStringRef key2 = CFSTR("key2");
static CFStringRef key3 = CFSTR("key3");
static CFStringRef value1 = CFSTR("value1");
static CFStringRef value2 = CFSTR("value2");
static CFStringRef value3 = CFSTR("value3");

TEST(CFAttributedString, ReplaceString) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, CFSTR("CFAttributedString"));
    ASSERT_EQ(YES, CFEqual(CFSTR("CFAttributedString"), CFAttributedStringGetString(aStr)));
    ASSERT_EQ([@"CFAttributedString" length], CFAttributedStringGetLength(aStr));

    CFRelease(aStr);
}

TEST(CFAttributedString, SetGetAttribute) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, CFSTR("CFAttributedString"));
    CFAttributedStringSetAttribute(aStr, { 1, 5 }, key1, value1);
    assertAttributeAt(aStr, key1, value1, 1, 5);

    CFRelease(aStr);
}

TEST(CFAttributedString, SetGetRemoveAttributes) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, CFSTR("CFAttributedString"));

    const void* keys[] = { key1, key2 };
    const void* values[] = { value1, value2 };
    CFDictionaryRef dict = CFDictionaryCreate(nullptr, keys, values, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

    CFAttributedStringSetAttributes(aStr, { 0, 4 }, dict, false);
    assertAttributeAt(aStr, key1, value1, 0, 4);
    assertAttributeAt(aStr, key2, value2, 0, 4);

    // Don't clear existing attributes, should append the ranges
    CFAttributedStringSetAttributes(aStr, { 4, 4 }, dict, false);
    assertAttributeAt(aStr, key1, value1, 0, 8);
    assertAttributeAt(aStr, key2, value2, 0, 8);

    // Clear existing attributes
    const void* existingKeys[] = { key1 };
    const void* existingValues[] = { value2 };
    CFAttributedStringSetAttributes(aStr,
                                    { 4, 2 },
                                    static_cast<CFDictionaryRef>(CFAutorelease(CFDictionaryCreate(nullptr,
                                                                                                  existingKeys,
                                                                                                  existingValues,
                                                                                                  1,
                                                                                                  &kCFTypeDictionaryKeyCallBacks,
                                                                                                  &kCFTypeDictionaryValueCallBacks))),
                                    true);
    assertAttributeAt(aStr, key1, value2, 4, 2);
    assertAttributeAt(aStr, key2, NULL, 4, 2);

    // Remove half the attribute
    CFAttributedStringRemoveAttribute(aStr, { 4, 1 }, key1);
    assertAttributeAt(aStr, key1, NULL, 4, 1);
    assertAttributeAt(aStr, key1, value2, 5, 1);

    CFRelease(aStr);
}

TEST(CFAttributedString, ReplaceAttributedString) {
    CFMutableAttributedStringRef aStr1 = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr1, { 0, 0 }, CFSTR("CFAttributedString"));

    const void* keys[] = { key1 };
    const void* values[] = { value1, value1 };
    CFDictionaryRef dict = static_cast<CFDictionaryRef>(
        CFAutorelease(CFDictionaryCreate(nullptr, keys, values, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks)));

    CFAttributedStringRef aStr2 = CFAttributedStringCreate(NULL, CFSTR("StringTwo"), dict);

    CFAttributedStringReplaceAttributedString(aStr1, { 0, 2 }, aStr2);
    assertAttributeAt(aStr1, key1, value1, 0, 9);
    ASSERT_EQ(YES, CFEqual(CFSTR("StringTwoAttributedString"), CFAttributedStringGetString(aStr1)));

    CFRelease(aStr1);
    CFRelease(aStr2);
}

TEST(CFAttributedString, CreateMutableCopy) {
    const void* keys[] = { key1 };
    const void* values[] = { value1, value1 };
    CFDictionaryRef dict = static_cast<CFDictionaryRef>(
        CFAutorelease(CFDictionaryCreate(nullptr, keys, values, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks)));
    CFAttributedStringRef aStr = CFAttributedStringCreate(NULL, CFSTR("Objective-C"), dict);
    CFMutableAttributedStringRef aStrCopy = CFAttributedStringCreateMutableCopy(NULL, 1024, aStr);
    ASSERT_EQ(YES, CFEqual(aStr, aStrCopy));
}

TEST(CFAttributedString, GetAttribute_s_AndLongestEffectiveRange) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, CFSTR("CFAttributedString"));
    CFAttributedStringSetAttribute(aStr, { 0, 2 }, key1, value1);
    CFAttributedStringSetAttribute(aStr, { 0, 10 }, key2, value2);

    CFRange outRange;

    ASSERT_EQ(value1, CFAttributedStringGetAttribute(aStr, 0, key1, &outRange));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(2, outRange.length);

    ASSERT_EQ(value1, CFAttributedStringGetAttributeAndLongestEffectiveRange(aStr, 0, key1, { 0, 1 }, &outRange));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(1, outRange.length);

    const void* keys[] = { key1, key2 };
    const void* values[] = { value1, value2 };
    CFDictionaryRef expectedDict =
        CFDictionaryCreate(nullptr, keys, values, 2, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

    ASSERT_EQ(true, CFEqual(expectedDict, CFAttributedStringGetAttributes(aStr, 0, &outRange)));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(2, outRange.length);

    ASSERT_EQ(true, CFEqual(expectedDict, CFAttributedStringGetAttributesAndLongestEffectiveRange(aStr, 0, { 0, 1 }, &outRange)));
    ASSERT_EQ(0, outRange.location);
    ASSERT_EQ(1, outRange.length);

    CFRelease(aStr);
}

TEST(CFAttributedString, CreateWithSubstring) {
    CFMutableAttributedStringRef aStr = CFAttributedStringCreateMutable(NULL, 1024);
    CFAttributedStringReplaceString(aStr, { 0, 0 }, CFSTR("CFAttributedString"));
    CFAttributedStringSetAttribute(aStr, { 0, 2 }, key1, value1);
    CFAttributedStringSetAttribute(aStr, { 0, 10 }, key2, value2);

    CFAttributedStringRef subStr = CFAttributedStringCreateWithSubstring(NULL, aStr, { 0, 3 });
    assertAttributeAt(subStr, key1, value1, 0, 2);
    assertAttributeAt(subStr, key2, value2, 0, 2);
    assertAttributeAt(subStr, key2, value2, 2, 1);
    ASSERT_EQ(YES, CFEqual(CFSTR("CFA"), CFAttributedStringGetString(subStr)));

    CFRelease(aStr);
    CFRelease(subStr);
}