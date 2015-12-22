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
#include "Starboard.h"
#include <windows.h>
#include <CoreFoundation\CFAttributedString.h>
#include <Foundation\NSAttributedString.h>
#include <Foundation\NSDictionary.h>
#include <Foundation\NSMutableAttributedString.h>
#include <UIKit\UIKit.h>
#include <vector>

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
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"OBJ"];
    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    ASSERT_EQ(3, [aStr length]);
    assertAttributeAt(aStr, NSFontAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_InitWithStringAttributes) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"OBJ" attributes:attrs];

    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    ASSERT_EQ(3, [aStr length]);

    assertAttributeAt(aStr, @"key1", @"value1", 0, 3);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, NSBackgroundColorAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_InitWithAttributedString) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStrBase = [[NSAttributedString alloc] initWithString:@"OBJ" attributes:attrs];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithAttributedString:aStrBase];

    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    ASSERT_EQ(3, [aStr length]);

    assertAttributeAt(aStr, @"key1", @"value1", 0, 3);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, NSBackgroundColorAttributeName, nil, 0, 3);
}

TEST(Foundation, AttributedString_AttributeAtIndexNoRange) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithString:@"OBJ" attributes:attrs];

    ASSERT_OBJCEQ(@"value1", [aStr attribute:@"key1" atIndex:1 effectiveRange:nullptr]);
    ASSERT_OBJCEQ(@"value2", [aStr attribute:@"key2" atIndex:1 effectiveRange:nullptr]);
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

    NSDictionary* attrsAt0 = [aStr attributesAtIndex:0 effectiveRange:nullptr];
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
    [aStr addAttribute:@"key3" value:@"value3" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", @"notvalue3", @"key3", nil];
    NSAttributedString* aStr2 = [[NSAttributedString alloc] initWithString:@"OBJ" attributes:attrs];

    [aStr appendAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 7);
    assertAttributeAt(aStr, @"key2", @"value2", 6, 3);
    assertAttributeAt(aStr, @"key3", @"value3", 2, 4);
    assertAttributeAt(aStr, @"key3", @"notvalue3", 6, 3);
    ASSERT_OBJCEQ(@"AAAAAAOBJ", [aStr string]);
}

TEST(Foundation, AttributedString_DeleteCharactersInRange) {
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr = [[NSMutableAttributedString alloc] initWithString:@"OBJ" attributes:attrs];

    [aStr deleteCharactersInRange:NSMakeRange(1, 1)];

    assertAttributeAt(aStr, @"key1", @"value1", 0, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 2);
    ASSERT_OBJCEQ(@"OJ", [aStr string]);
}

TEST(Foundation, AttributedString_DeleteCharactersInRangeEmptyString) {
    NSMutableAttributedString* aStr = [[NSMutableAttributedString alloc] initWithString:@""];

    [aStr deleteCharactersInRange:NSMakeRange(0, 0)];
}

TEST(Foundation, AttributedString_InsertAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"OBJ" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr insertAttributedString:aStr2 atIndex:5];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 5);
    assertAttributeAt(aStr, @"key1", @"value1", 8, 1);
    assertAttributeAt(aStr, @"key2", @"value2", 5, 3);
    ASSERT_OBJCEQ(@"AAAAAOBJA", [aStr string]);
}

TEST(Foundation, AttributedString_IsEqualToAttributedString) {
    NSMutableAttributedString* firstStr = SixCharacterTestString();
    NSMutableAttributedString* secondStr = SixCharacterTestString();
    ASSERT_EQ(YES, [firstStr isEqualToAttributedString:secondStr]);
    ASSERT_EQ(YES, [secondStr isEqualToAttributedString:firstStr]);

    [firstStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];
    ASSERT_EQ(NO, [firstStr isEqualToAttributedString:secondStr]);
    ASSERT_EQ(NO, [secondStr isEqualToAttributedString:firstStr]);

    [secondStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];
    ASSERT_EQ(YES, [firstStr isEqualToAttributedString:secondStr]);
    ASSERT_EQ(YES, [secondStr isEqualToAttributedString:firstStr]);

    [firstStr addAttribute:@"key1" value:@"value1b" range:NSMakeRange(1, 2)];
    [secondStr addAttribute:@"key1" value:@"value1b" range:NSMakeRange(1, 2)];
    [firstStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(0, 3)];
    [secondStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(0, 3)];

    ASSERT_EQ(YES, [firstStr isEqualToAttributedString:secondStr]);
    ASSERT_EQ(YES, [secondStr isEqualToAttributedString:firstStr]);
}

TEST(Foundation, AttributedString_ReplaceCharactersInRangeWithAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"OBJ" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 2);
    assertAttributeAt(aStr, @"key1", @"value1", 5, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 2, 3);
    ASSERT_OBJCEQ(@"AAOBJAA", [aStr string]);
}

TEST(Foundation, AttributedString_SetAttributedString) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];
    [aStr addAttribute:@"key3" value:@"value3" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSMutableAttributedString* aStr2 = [[NSMutableAttributedString alloc] initWithString:@"OBJ" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr setAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 0, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 0, 3);
    assertAttributeAt(aStr, @"key3", nil, 0, 3);
    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
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

TEST(Foundation, AttributedString_AttributedSubstringFromRange) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(3, 2)];

    NSAttributedString* testString = [aStr attributedSubstringFromRange:NSMakeRange(1, 3)];

    ASSERT_OBJCEQ(@"AAA", [testString string]);
    assertAttributeAt(testString, @"key1", @"value1", 1, 2);
    assertAttributeAt(testString, @"key2", @"value2", 2, 1);
}

TEST(Foundation, AttributedString_EnumerateAttribute) {
    NSMutableAttributedString* aStr = SixCharacterTestString();

    // test block to pass to enumerateAttribute:
    // iterates through expected data and validates that it's the same as the returned data
    __block size_t index = 0;
    __block std::vector<std::pair<id, NSRange>> testAttributes;
    void (^testBlock)(id, NSRange, BOOL*) = ^void(id val, NSRange range, BOOL* stop) {
        ASSERT_TRUE(index < testAttributes.size());
        const auto& pair = testAttributes.at(index);
        ASSERT_OBJCEQ(pair.first, val);
        ASSERT_TRUE(NSEqualRanges(pair.second, range));
        index += 1;
    };

    // 1) basic test
    testAttributes.insert(testAttributes.end(),
                          { { @"value1", NSMakeRange(1, 1) },
                            { @"value2", NSMakeRange(2, 2) },
                            { @"value3", NSMakeRange(4, 1) },
                            { @"value4", NSMakeRange(5, 1) } });
    for (const auto& pair : testAttributes) {
        [aStr addAttribute:@"key1" value:pair.first range:pair.second];
    }

    [aStr enumerateAttribute:@"key1"
                     inRange:NSMakeRange(0, 6)
                     options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired
                  usingBlock:testBlock];
    ASSERT_EQ(testAttributes.size(), index);

    // 2) test with holes, limit the range
    [aStr release];
    aStr = [[NSMutableAttributedString alloc] initWithString:@"AAAAAAAAAA"]; // 10 characters

    testAttributes.clear();
    testAttributes.insert(testAttributes.end(),
                          { { @"value1", NSMakeRange(1, 1) },
                            { @"value2", NSMakeRange(2, 2) },
                            { @"value3", NSMakeRange(5, 1) },
                            { @"value4", NSMakeRange(7, 3) } });

    for (const auto& pair : testAttributes) {
        [aStr addAttribute:@"key1" value:pair.first range:pair.second];
    }

    // limit range to {2, 7}, excluding the first attribute and clipping part of the last (should still include the whole attribute)
    index = 1;
    [aStr enumerateAttribute:@"key1"
                     inRange:NSMakeRange(2, 7)
                     options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired
                  usingBlock:testBlock];
    ASSERT_EQ(testAttributes.size(), index);

    // 3) iterate in reverse, use longestEffectiveRange
    [aStr release];
    aStr = [[NSMutableAttributedString alloc] initWithString:@"AAAAAAAAAA"]; // 10 characters

    testAttributes.clear();
    testAttributes.insert(testAttributes.end(),
                          { { @"value4", NSMakeRange(7, 3) },
                            { @"value3", NSMakeRange(5, 1) },
                            { @"value2", NSMakeRange(2, 2) },
                            { @"value1", NSMakeRange(1, 1) } });

    for (const auto& pair : testAttributes) {
        [aStr addAttribute:@"key1" value:pair.first range:pair.second];
    }

    // due to longest effective range being used, the expected range is different from the input
    testAttributes.at(0).second = NSMakeRange(7, 2);

    index = 0;
    [aStr enumerateAttribute:@"key1" inRange:NSMakeRange(2, 7) options:NSAttributedStringEnumerationReverse usingBlock:testBlock];
    ASSERT_EQ(testAttributes.size() - 1, index); // last attribute is out of range
}

TEST(Foundation, AttributedString_EnumerateAttributeAndChangeLength) {
    NSMutableAttributedString* baseStr = [[NSMutableAttributedString alloc] initWithString:@"ABCDEF"];
    [baseStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(0, 1)];
    [baseStr addAttribute:@"key1" value:@"value2" range:NSMakeRange(1, 1)];
    [baseStr addAttribute:@"key1" value:@"value3" range:NSMakeRange(2, 1)];
    [baseStr addAttribute:@"key1" value:@"value4" range:NSMakeRange(3, 1)];
    [baseStr addAttribute:@"key1" value:@"value5" range:NSMakeRange(4, 1)];
    [baseStr addAttribute:@"key1" value:@"value6" range:NSMakeRange(5, 1)];

    // 1) increase length, forward
    __block NSMutableAttributedString* testString1 = [[NSMutableAttributedString alloc] initWithAttributedString:baseStr];
    [testString1 enumerateAttribute:@"key1"
                            inRange:NSMakeRange(2, 2)
                            options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired
                         usingBlock:^void(id val, NSRange range, BOOL* stop) {
                             [testString1 replaceCharactersInRange:range withString:@"ZZ"];
                         }];
    ASSERT_OBJCEQ(@"ABZZZZEF", [testString1 string]);

    // 2) increase length, reverse
    __block NSMutableAttributedString* testString2 = [[NSMutableAttributedString alloc] initWithAttributedString:baseStr];
    [testString2 enumerateAttribute:@"key1"
                            inRange:NSMakeRange(2, 2)
                            options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired | NSAttributedStringEnumerationReverse
                         usingBlock:^void(id val, NSRange range, BOOL* stop) {
                             [testString2 replaceCharactersInRange:range withString:@"ZZ"];
                         }];
    ASSERT_OBJCEQ(@"ABZZZZEF", [testString2 string]);

    // 3) decrease length, forward
    __block NSMutableAttributedString* testString3 = [[NSMutableAttributedString alloc] initWithAttributedString:baseStr];
    [testString3 enumerateAttribute:@"key1"
                            inRange:NSMakeRange(2, 2)
                            options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired
                         usingBlock:^void(id val, NSRange range, BOOL* stop) {
                             [testString3 deleteCharactersInRange:range];
                         }];
    ASSERT_OBJCEQ(@"ABEF", [testString3 string]);

    // 4) decrease length, reverse
    __block NSMutableAttributedString* testString4 = [[NSMutableAttributedString alloc] initWithAttributedString:baseStr];
    [testString4 enumerateAttribute:@"key1"
                            inRange:NSMakeRange(2, 2)
                            options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired | NSAttributedStringEnumerationReverse
                         usingBlock:^void(id val, NSRange range, BOOL* stop) {
                             [testString4 deleteCharactersInRange:range];
                         }];
    ASSERT_OBJCEQ(@"ABEF", [testString4 string]);

    // 5) decrease length, reverse, stop early
    __block NSMutableAttributedString* testString5 = [[NSMutableAttributedString alloc] initWithAttributedString:baseStr];
    [testString5 enumerateAttribute:@"key1"
                            inRange:NSMakeRange(1, 4)
                            options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired | NSAttributedStringEnumerationReverse
                         usingBlock:^void(id val, NSRange range, BOOL* stop) {
                             [testString5 deleteCharactersInRange:range];
                             *stop = YES;
                         }];
    ASSERT_OBJCEQ(@"ABCDF", [testString5 string]);
}

TEST(Foundation, AttributedString_EnumerateAttributes) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 2)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(1, 2)];
    [aStr addAttribute:@"key3" value:@"value3" range:NSMakeRange(2, 4)];
    [aStr addAttribute:@"key2" value:@"value2" range:NSMakeRange(5, 1)];

    // test block to pass to enumerateAttributes:
    // iterates through expected data and validates that it's the same as the returned data
    __block size_t index = 0;
    __block auto expectedAttributes = std::vector<std::pair<NSDictionary*, NSRange>>(
        { { @{ @"key3" : @"value3" }, NSMakeRange(4, 1) },
          { @{ @"key1" : @"value1", @"key3" : @"value3" }, NSMakeRange(3, 1) },
          { @{ @"key1" : @"value1", @"key2" : @"value2", @"key3" : @"value3" }, NSMakeRange(2, 1) } });
    void (^testBlock)(NSDictionary*, NSRange, BOOL*) = ^void(NSDictionary* val, NSRange range, BOOL* stop) {
        ASSERT_TRUE(index < expectedAttributes.size());
        const auto& pair = expectedAttributes.at(index);
        ASSERT_OBJCEQ(pair.first, val);
        ASSERT_TRUE(NSEqualRanges(pair.second, range));
        index += 1;
    };

    [aStr enumerateAttributesInRange:NSMakeRange(2, 3) options:NSAttributedStringEnumerationReverse usingBlock:testBlock];
    ASSERT_EQ(expectedAttributes.size(), index);
}

// UI Kit extensions

void assertFontTraitAt(NSAttributedString* aStr,
                       NSUInteger expectedLocation,
                       NSUInteger expectedLength,
                       UIFontDescriptorSymbolicTraits trait) {
    NSRange outRange;

    UIFont* font = reinterpret_cast<UIFont*>([aStr attribute:NSFontAttributeName atIndex:expectedLocation effectiveRange:&outRange]);

    ASSERT_OBJCNE(nil, font);
    ASSERT_NE(0, [[font fontDescriptor] symbolicTraits] & trait);
    ASSERT_EQ(expectedLocation, outRange.location);
    ASSERT_EQ(expectedLength, outRange.length);
}

void assertFontTraitNotAt(NSAttributedString* aStr,
                          NSUInteger expectedLocation,
                          NSUInteger expectedLength,
                          UIFontDescriptorSymbolicTraits trait) {
    NSRange outRange;

    UIFont* font = reinterpret_cast<UIFont*>([aStr attribute:NSFontAttributeName atIndex:expectedLocation effectiveRange:&outRange]);

    ASSERT_OBJCNE(nil, font);
    ASSERT_EQ(0, [[font fontDescriptor] symbolicTraits] & trait);
    ASSERT_EQ(expectedLocation, outRange.location);
    ASSERT_EQ(expectedLength, outRange.length);
}

TEST(Foundation, AttributedString_InitWithData_HtmlBasic) {
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithData:[@"<b>OBJ</b>" dataUsingEncoding:NSUTF8StringEncoding]
                                                                options:@{
                                                                    NSDocumentTypeDocumentAttribute : NSHTMLTextDocumentType
                                                                }
                                                     documentAttributes:nil
                                                                  error:nil];
    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    assertFontTraitAt(aStr, 0, 3, UIFontDescriptorTraitBold);
}

TEST(Foundation, AttributedString_InitWithData_HtmlFontTraitsAndBreak) {
    NSAttributedString* aStr =
        [[NSAttributedString alloc] initWithData:[@"<b>AAA<i>BBB<u>C<br></u></i>AAAA</b>" dataUsingEncoding:NSUTF8StringEncoding]
                                         options:@{
                                             NSDocumentTypeDocumentAttribute : NSHTMLTextDocumentType
                                         }
                              documentAttributes:nil
                                           error:nil];
    ASSERT_OBJCEQ(@"AAABBBC\r\nAAAA", [aStr string]);

    assertFontTraitAt(aStr, 0, 3, UIFontDescriptorTraitBold);
    assertFontTraitNotAt(aStr, 0, 3, UIFontDescriptorTraitItalic);

    assertFontTraitAt(aStr, 3, 4, UIFontDescriptorTraitBold);
    assertFontTraitAt(aStr, 3, 4, UIFontDescriptorTraitItalic);

    assertAttributeAt(aStr, NSUnderlineStyleAttributeName, @(NSUnderlineStyleSingle), 6, 1);

    assertFontTraitAt(aStr, 9, 4, UIFontDescriptorTraitBold);
    assertFontTraitNotAt(aStr, 9, 4, UIFontDescriptorTraitItalic);
}

TEST(Foundation, AttributedString_InitWithData_PlainText) {
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithData:[@"OBJ" dataUsingEncoding:NSUTF8StringEncoding]
                                                                options:@{
                                                                    NSDocumentTypeDocumentAttribute : NSPlainTextDocumentType
                                                                }
                                                     documentAttributes:nil
                                                                  error:nil];
    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    ASSERT_EQ(0, [[aStr attributesAtIndex:0 effectiveRange:nil] count]);
}

TEST(Foundation, AttributedString_InitWithData_BadEncodingOption) {
    NSError* error = nil;
    NSAttributedString* aStr =
        [[NSAttributedString alloc] initWithData:[@"OBJ" dataUsingEncoding:NSUTF8StringEncoding]
                                         options:@{
                                             NSDocumentTypeDocumentAttribute : NSHTMLTextDocumentType,
                                             NSCharacterEncodingDocumentAttribute : @(NSUTF32LittleEndianStringEncoding)
                                         }
                              documentAttributes:nil
                                           error:&error];
    ASSERT_OBJCNE(nil, error);
}

TEST(Foundation, AttributedString_InitWithData_NilInput) {
    NSError* error = nil;
    NSAttributedString* aStr =
        [[NSAttributedString alloc] initWithData:nil
                                         options:@{
                                             NSDocumentTypeDocumentAttribute : NSHTMLTextDocumentType,
                                             NSCharacterEncodingDocumentAttribute : @(NSUTF32LittleEndianStringEncoding)
                                         }
                              documentAttributes:nil
                                           error:&error];
    ASSERT_OBJCEQ(nil, aStr);
}