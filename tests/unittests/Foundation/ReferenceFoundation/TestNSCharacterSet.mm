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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSCharacterSet, Predefines) {
    NSCharacterSet* cset = [NSCharacterSet controlCharacterSet];

    ASSERT_EQ_MSG(cset, [NSCharacterSet controlCharacterSet], @"predefined charactersets should be singletons");

    ASSERT_TRUE_MSG([cset characterIsMember:static_cast<unichar>(0xFEFF)], @"Control set should contain UFEFF");
    ASSERT_TRUE_MSG([[NSCharacterSet letterCharacterSet] characterIsMember:'a'], @"Letter set should contain 'a'");
    ASSERT_TRUE_MSG([[NSCharacterSet lowercaseLetterCharacterSet] characterIsMember:'a'], @"Lowercase Letter set should contain 'a'");
    ASSERT_TRUE_MSG([[NSCharacterSet uppercaseLetterCharacterSet] characterIsMember:'A'], @"Uppercase Letter set should contain 'A'");
    ASSERT_TRUE_MSG([[NSCharacterSet uppercaseLetterCharacterSet] characterIsMember:static_cast<unichar>(0x01C5)],
                    @"Uppercase Letter set should contain U01C5");
    ASSERT_TRUE_MSG([[NSCharacterSet capitalizedLetterCharacterSet] characterIsMember:static_cast<unichar>(0x01C5)],
                    @"Uppercase Letter set should contain U01C5");
    ASSERT_TRUE_MSG([[NSCharacterSet symbolCharacterSet] characterIsMember:static_cast<unichar>(0x002B)],
                    @"Symbol set should contain U002B");
    ASSERT_TRUE_MSG([[NSCharacterSet symbolCharacterSet] characterIsMember:static_cast<unichar>(0x20B1)],
                    @"Symbol set should contain U20B1");
    ASSERT_TRUE_MSG([[NSCharacterSet newlineCharacterSet] characterIsMember:static_cast<unichar>(0x000A)],
                    @"Newline set should contain 0x000A");
    ASSERT_TRUE_MSG([[NSCharacterSet newlineCharacterSet] characterIsMember:static_cast<unichar>(0x2029)],
                    @"Newline set should contain 0x2029");

    NSMutableCharacterSet* mcset = [NSMutableCharacterSet whitespaceAndNewlineCharacterSet];
    NSCharacterSet* cset2 = [NSCharacterSet whitespaceAndNewlineCharacterSet];

    ASSERT_TRUE([mcset isSupersetOfSet:cset2]);
    ASSERT_TRUE([cset2 isSupersetOfSet:mcset]);

    ASSERT_TRUE_MSG([[NSCharacterSet whitespaceAndNewlineCharacterSet] isSupersetOfSet:[NSCharacterSet newlineCharacterSet]],
                    @"whitespace and newline should be a superset of newline");
    NSData* data = [[NSCharacterSet uppercaseLetterCharacterSet] bitmapRepresentation];
    ASSERT_OBJCNE(nil, data);
}

TEST(NSCharacterSet, Range) {
    NSCharacterSet* cset1 = [NSCharacterSet characterSetWithRange:NSMakeRange(0x20, 40)];
    for (unichar idx = 0; idx < 0xFFFF; idx++) {
        ASSERT_EQ([cset1 characterIsMember:idx], (idx >= 0x20 && idx < 0x20 + 40 ? true : false));
    }

    NSCharacterSet* cset2 = [NSCharacterSet characterSetWithRange:NSMakeRange(0x0000, 0xFFFF)];
    for (unichar idx = 0; idx < 0xFFFF; idx++) {
        ASSERT_EQ([cset2 characterIsMember:idx], true);
    }

    NSCharacterSet* cset3 = [NSCharacterSet characterSetWithRange:NSMakeRange(0x0000, 10)];
    for (unichar idx = 0; idx < 0xFFFF; idx++) {
        ASSERT_EQ([cset3 characterIsMember:idx], (idx < 10 ? true : false));
    }

    NSCharacterSet* cset4 = [NSCharacterSet characterSetWithRange:NSMakeRange(0x20, 0)];
    for (unichar idx = 0; idx < 0xFFFF; idx++) {
        ASSERT_EQ([cset4 characterIsMember:idx], false);
    }
}

TEST(NSCharacterSet, String) {
    NSCharacterSet* cset = [NSCharacterSet characterSetWithCharactersInString:@"abcABC"];
    for (unichar idx = 0; idx < 0xFFFF; idx++) {
        ASSERT_EQ([cset characterIsMember:idx],
                  (idx >= static_cast<unichar>('a') && idx <= static_cast<unichar>('c')) ||
                          (idx >= static_cast<unichar>('A') && idx <= static_cast<unichar>('C')) ?
                      true :
                      false);
    }
}

TEST(NSCharacterSet, Bitmap) {
}

TEST(NSCharacterSet, Mutables) {
    auto attachmentCharacterUnichar = static_cast<unichar>(0xFFFC);
    NSRange attachmentCharacterRange = NSMakeRange(attachmentCharacterUnichar, 1);

    NSRange initialSetRange = NSMakeRange(0, 0);
#if defined(__LITTLE_ENDIAN__)
    NSString* string = [[NSString alloc] initWithBytes:&attachmentCharacterUnichar length:2 encoding:NSUTF16LittleEndianStringEncoding];
#else
    NSString* string = [[NSString alloc] initWithBytes:&attachmentCharacterUnichar length:2 encoding:NSUTF16BigEndianStringEncoding];
#endif

    NSMutableCharacterSet* mcset1 = [NSMutableCharacterSet characterSetWithRange:initialSetRange];
    [mcset1 addCharactersInRange:attachmentCharacterRange];

    ASSERT_TRUE_MSG([mcset1 characterIsMember:attachmentCharacterUnichar],
                    @"attachmentCharacter should be member of mcset1 after being added");

    NSRange resultRange = [string rangeOfCharacterFromSet:mcset1];
    ASSERT_NE_MSG(NSNotFound, resultRange.location, @"Range of character from mcset1 set should not be nil");
    ASSERT_NE_MSG(0, resultRange.length, @"Range of character from mcset1 set should not be nil");

    NSMutableCharacterSet* mcset2 = [NSMutableCharacterSet characterSetWithRange:initialSetRange];
    [mcset2 addCharactersInString:string];

    ASSERT_TRUE_MSG([mcset2 characterIsMember:attachmentCharacterUnichar],
                    @"attachmentCharacter should be member of mcset2 after being added");
    resultRange = [string rangeOfCharacterFromSet:mcset2];
    ASSERT_NE_MSG(NSNotFound, resultRange.location, @"Range of character from mcset2 should not be nil");
    ASSERT_NE_MSG(0, resultRange.length, @"Range of character from mcset2 should not be nil");
}

TEST(NSCharacterSet, AnnexPlanes) {
}

TEST(NSCharacterSet, Planes) {
}

TEST(NSCharacterSet, InlineBuffer) {
}
