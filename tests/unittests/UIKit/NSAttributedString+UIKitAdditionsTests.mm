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
#import <Foundation\NSAttributedString.h>
#import <Foundation\NSDictionary.h>
#import <Foundation\NSMutableAttributedString.h>
#import <UIKit\UIKit.h>

#import <vector>
#import <windows.h>

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

TEST(Foundation, AttributedString_InitWithData_HtmlBasic) {
    NSAttributedString* aStr = [[NSAttributedString alloc] initWithData:[@"<b>OBJ</b>" dataUsingEncoding:NSUTF8StringEncoding]
                                                                options:@{
                                                                    NSDocumentTypeDocumentAttribute : NSHTMLTextDocumentType
                                                                }
                                                     documentAttributes:nil
                                                                  error:nullptr];
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
                                           error:nullptr];
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
                                                                  error:nullptr];
    ASSERT_OBJCEQ(@"OBJ", [aStr string]);
    ASSERT_EQ(0, [[aStr attributesAtIndex:0 effectiveRange:nullptr] count]);
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

TEST(Foundation, AttributedString_ReplaceUsingSubclass) {
    NSMutableAttributedString* aStr = SixCharacterTestString();
    [aStr addAttribute:@"key1" value:@"value1" range:NSMakeRange(2, 4)];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:@"value1", @"key1", @"value2", @"key2", nil];
    NSTextStorage* aStr2 = [[NSTextStorage alloc] initWithString:@"OBJ" attributes:attrs];
    [aStr2 removeAttribute:@"key1" range:NSMakeRange(2, 1)];

    [aStr replaceCharactersInRange:NSMakeRange(2, 2) withAttributedString:aStr2];

    assertAttributeAt(aStr, @"key1", @"value1", 2, 2);
    assertAttributeAt(aStr, @"key1", @"value1", 5, 2);
    assertAttributeAt(aStr, @"key2", @"value2", 2, 3);
    ASSERT_OBJCEQ(@"AAOBJAA", [aStr string]);
}