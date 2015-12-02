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

#include "gtest-api.h"
#include "Starboard.h"
#include <windows.h>
#include <CoreFoundation\CFAttributedString.h>
#include <Foundation\NSAttributedString.h>
#include <Foundation\NSDictionary.h>
#include <Foundation\NSMutableAttributedString.h>

void assertAttributeAt(
    NSAttributedString* aStr, NSString* attrName, id expectedValue, NSUInteger expectedLocation, NSUInteger expectedLength) {
    NSRange outRange;

    id attribute = [aStr attribute:attrName atIndex:expectedLocation effectiveRange:&outRange];
    ASSERT_EQ(expectedValue, attribute);
    ASSERT_EQ(expectedLocation, outRange.location);
    ASSERT_EQ(expectedLength, outRange.length);

    // Do a redundant check at the end of the range for safety
    attribute = [aStr attribute:attrName atIndex:(expectedLocation + expectedLength - 1) effectiveRange:&outRange];
    ASSERT_EQ(expectedValue, attribute);
    ASSERT_EQ(expectedLocation, outRange.location);
    ASSERT_EQ(expectedLength, outRange.length);
}

NSMutableAttributedString* SixCharacterTestString() {
    return [[NSMutableAttributedString alloc] initWithString:@"AAAAAA"];
}

// Exercise the CFAttrList functions

TEST(Foundation, AttributedString_Add) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 2);
}

TEST(Foundation, AttributedString_AddBeforeAndAfter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(0, 1)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(5, 1)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 1);
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 2);
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 5, 1);
}

TEST(Foundation, AttributedString_CoalesceOverlapAfter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(3, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 3);
}

TEST(Foundation, AttributedString_CoalesceAdjacentAfter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(4, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 4);
}

TEST(Foundation, AttributedString_CoalesceOverlapBefore) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 3);
}

TEST(Foundation, AttributedString_CoalesceAdjacentBefore) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(0, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 4);
}

TEST(Foundation, AttributedString_CoalesceComplex) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(0, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(4, 1)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(4, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 6);
}

TEST(Foundation, AttributedString_RemoveBefore) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr removeAttribute:NSFontAttributeName range:NSMakeRange(1, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 3, 1);
}

TEST(Foundation, AttributedString_RemoveAfter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr removeAttribute:NSFontAttributeName range:NSMakeRange(3, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 1);
}

TEST(Foundation, AttributedString_RemoveCenter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr removeAttribute:NSFontAttributeName range:NSMakeRange(2, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 1);
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 4, 1);
}

TEST(Foundation, AttributedString_RemoveAll) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr removeAttribute:NSFontAttributeName range:NSMakeRange(1, 4)];

    assertAttributeAt(aStr, NSFontAttributeName, nil, 0, 6);

    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr removeAttribute:NSFontAttributeName range:NSMakeRange(0, 6)];
    assertAttributeAt(aStr, NSFontAttributeName, nil, 0, 6);
}

TEST(Foundation, AttributedString_OverwriteAfter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(3, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 1);
    assertAttributeAt(aStr, NSFontAttributeName, @"value2", 3, 2);
}

TEST(Foundation, AttributedString_OverwriteBefore) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value2", 3, 1);
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 2);
}

TEST(Foundation, AttributedString_NoOverwrite) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(0, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value3" range:NSMakeRange(4, 2)];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 2);
    assertAttributeAt(aStr, NSFontAttributeName, @"value2", 2, 2);
    assertAttributeAt(aStr, NSFontAttributeName, @"value3", 4, 2);
}

TEST(Foundation, AttributedString_ReplaceConstantInner) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withString:@"BB"];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 4);
    ASSERT_OBJCEQ(@"AABBAA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceExpandInner) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withString:@"BBBB"];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 6);
    ASSERT_OBJCEQ(@"AABBBBAA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceContractInner) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];
    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withString:@""];

    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 2);
    ASSERT_OBJCEQ(@"AAAA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceExpandOuter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];

    [aStr replaceCharactersInRange:NSMakeRange(3, 2) withString:@"BBBB"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 5); // +1 not originally in attribute range, +2 string length
    ASSERT_OBJCEQ(@"AAABBBBA", [aStr string]);

    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withString:@"CCCC"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 7); // +2 string length
    ASSERT_OBJCEQ(@"AACCCCBBBA", [aStr string]);

    [aStr replaceCharactersInRange:NSMakeRange(0, 10) withString:@"DDDDDDDDDDDD"]; // 12 chars now
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 12);
    ASSERT_OBJCEQ(@"DDDDDDDDDDDD", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceContractOuter) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 4)];

    [aStr replaceCharactersInRange:NSMakeRange(3, 2) withString:@"B"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 3); // -1 string length
    ASSERT_OBJCEQ(@"AAABA", [aStr string]);

    [aStr replaceCharactersInRange:NSMakeRange(0, 2) withString:@""];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 2); // +1 not originally in attribute range, -2 string length
    ASSERT_OBJCEQ(@"ABA", [aStr string]);

    [aStr replaceCharactersInRange:NSMakeRange(0, 3) withString:@"D"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 1);
    ASSERT_OBJCEQ(@"D", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceAdjacent) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];

    [aStr replaceCharactersInRange:NSMakeRange(0, 2) withString:@"B"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 2); // Should not have expanded the attribute
    ASSERT_OBJCEQ(@"BAAAA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceOverwriteExpand) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(0, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(2, 2)];

    [aStr replaceCharactersInRange:NSMakeRange(1, 2) withString:@"BBBB"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 0, 5);
    assertAttributeAt(aStr, NSFontAttributeName, @"value2", 5, 1);
    ASSERT_OBJCEQ(@"ABBBBAAA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceOverwriteContract) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(4, 2)];

    [aStr replaceCharactersInRange:NSMakeRange(3, 2) withString:@"B"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 2, 2);
    assertAttributeAt(aStr, NSFontAttributeName, @"value2", 4, 1);
    ASSERT_OBJCEQ(@"AAABA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceOverwriteMultiple) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:NSFontAttributeName value:@"value1" range:NSMakeRange(1, 1)];
    [aStr addAttribute:NSFontAttributeName value:@"value2" range:NSMakeRange(2, 1)];
    [aStr addAttribute:NSFontAttributeName value:@"value3" range:NSMakeRange(3, 1)];
    [aStr addAttribute:NSFontAttributeName value:@"value4" range:NSMakeRange(4, 1)];

    [aStr replaceCharactersInRange:NSMakeRange(1, 4) withString:@"BBBBBBBB"];
    assertAttributeAt(aStr, NSFontAttributeName, @"value1", 1, 8);
    ASSERT_OBJCEQ(@"ABBBBBBBBA", [aStr string]);
}

// Test unexercised exposed interfaces
TEST(Foundation, AttributedString_AddAttributeToMultipleKeys) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(1, 1)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(3, 1)];
    [aStr addAttribute:@"key3" value:@"value3" range:NSMakeRange(3, 1)];

    assertAttributeAt(aStr, @"key1", @"value1", 1, 1);
    assertAttributeAt(aStr, @"key2", @"value2", 3, 1);
    assertAttributeAt(aStr, @"key3", @"value3", 3, 1);
}

TEST(Foundation, AttributedString_SetAttributes) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(1, 4)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(1, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1NEW", @"key1", @"value2NEW", @"key2", nil];

    [aStr setAttributes:attrs range:NSMakeRange(2, 2)];

    assertAttributeAt(aStr, @"key1", @"value1", 1, 1);
    assertAttributeAt(aStr, @"key1", @"value1NEW", 2, 2);
    assertAttributeAt(aStr, @"key1", @"value1", 4, 1);
    assertAttributeAt(aStr, @"key2", @"value2", 1, 1);
    assertAttributeAt(aStr, @"key2", @"value2NEW", 2, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 4, 1);
    ASSERT_OBJCEQ(@"AAAAAA", [aStr string]);
}

TEST(Foundation, AttributedString_AddAttributes) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    [aStr addAttributes:attrs range:NSMakeRange(2, 2)];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 2, 2);
}

TEST(Foundation, AttributedString_InitWithString) {
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"foo"];
    ASSERT_OBJCEQ(@"foo", [aStr string]);
    ASSERT_EQ(3, [aStr length]);
    assertAttributeAt(aStr, NSFontAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_InitWithStringAttributes) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"foo" attributes:attrs];

    ASSERT_OBJCEQ(@"foo", [aStr string]);
    ASSERT_EQ(3, [aStr length]);

    assertAttributeAt(aStr, @"key1", @"value1", 0, 3);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, NSBackgroundColorAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_InitWithAttributedString) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStrBase = [[NSAttributedString alloc] initWithString:@"foo" attributes:attrs];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithAttributedString:aStrBase];

    ASSERT_OBJCEQ(@"foo", [aStr string]);
    ASSERT_EQ(3, [aStr length]);

    assertAttributeAt(aStr, @"key1", @"value1", 0, 3);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, NSBackgroundColorAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_AttributeAtIndexNoRange) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"foo" attributes:attrs];

    ASSERT_OBJCEQ(@"value1", [aStr attribute:@"key1" atIndex:1 effectiveRange:nil]);
    ASSERT_OBJCEQ(@"value2", [aStr attribute:@"key2" atIndex:1 effectiveRange:nil]);
}

TEST(Foundation, AttributedString_AttributeAtIndexInRange) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 2)];

    NSRange outRange;
    id attribute = [aStr attribute:@"key1" atIndex:3 longestEffectiveRange:&outRange inRange:NSMakeRange(1, 2)];
    ASSERT_OBJCEQ(@"value1", attribute);
    ASSERT_EQ(2, outRange.location);
    ASSERT_EQ(1, outRange.length);
}

TEST(Foundation, AttributedString_AttributesAtIndex) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(3, 2)];

    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(0, 1)];

    NSDictionary* attrsAt0 = [aStr attributesAtIndex:0 effectiveRange:nil];
    ASSERT_EQ(1, [attrsAt0 count]);
    ASSERT_OBJCEQ(@"value1", [attrsAt0 objectForKey:@"key1"]);

    NSRange outRange;
    NSDictionary* attrsAt3 = [aStr attributesAtIndex:3 effectiveRange:&outRange];
    ASSERT_EQ(2, [attrsAt3 count]);
    ASSERT_OBJCEQ(@"value1", [attrsAt3 objectForKey:@"key1"]);
    ASSERT_OBJCEQ(@"value2", [attrsAt3 objectForKey:@"key2"]);
    ASSERT_EQ(3, outRange.location);
    ASSERT_EQ(1, outRange.length);
}

TEST(Foundation, AttributedString_AttributesAtIndexInRange) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(1, 3)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(0, 4)];

    NSRange outRange;
    NSDictionary* attrsAt3 = [aStr attributesAtIndex:2 longestEffectiveRange:&outRange inRange:NSMakeRange(2, 1)];
    ASSERT_EQ(2, [attrsAt3 count]);
    ASSERT_OBJCEQ(@"value1", [attrsAt3 objectForKey:@"key1"]);
    ASSERT_OBJCEQ(@"value2", [attrsAt3 objectForKey:@"key2"]);
    ASSERT_EQ(2, outRange.location);
    ASSERT_EQ(1, outRange.length);
}

TEST(Foundation, AttributedString_AppendAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStr2 = [[NSAttributedString alloc] initWithString:@"foo" attributes:attrs];

    [aStr appendAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 7);
    assertAttributeAt(aStr, @"key2", @"value2", 6, 3);
    ASSERT_OBJCEQ(@"AAAAAAfoo", [aStr string]);
}

TEST(Foundation, AttributedString_DeleteCharactersInRange) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr = [[NSMutableAttributedString alloc] initWithString:@"foo" attributes:attrs];

    [aStr deleteCharactersInRange:NSMakeRange(1, 1)];

    assertAttributeAt(aStr, @"key1", @"value1", 0, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 2);
    ASSERT_OBJCEQ(@"fo", [aStr string]);
}

TEST(Foundation, AttributedString_DeleteCharactersInRangeEmptyString) {
    NSMutableAttributedString* aStr = [[NSMutableAttributedString alloc] initWithString:@""];

    [aStr deleteCharactersInRange:NSMakeRange(0, 0)];
}

TEST(Foundation, AttributedString_InsertAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"foo" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr insertAttributedString:aStr2 atIndex:5];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 5);
    assertAttributeAt(aStr, @"key1", @"value1", 8, 1);
    assertAttributeAt(aStr, @"key2", @"value2", 5, 3);
    ASSERT_OBJCEQ(@"AAAAAfooA", [aStr string]);
}

TEST(Foundation, AttributedString_ReplaceCharactersInRangeWithAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"foo" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 2);
    assertAttributeAt(aStr, @"key1", @"value1", 5, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 2, 3);
    ASSERT_OBJCEQ(@"AAfooAA", [aStr string]);
}

TEST(Foundation, AttributedString_SetAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];
    [aStr addAttribute:@"key3" value:@"value3" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"foo" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr setAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 0, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, @"key3", nil, 0, 3);
    ASSERT_OBJCEQ(@"foo", [aStr string]);
}

TEST(Foundation, AttributedString_ThrowsBounds) {
    NSMutableAttributedString* aStr = SixCharacterTestString();

    NSError* error = nil;
    try {
        [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 7)];
    }
    CATCH_POPULATE_NSERROR(&error);
    ASSERT_EQ(E_BOUNDS, error.code);
}