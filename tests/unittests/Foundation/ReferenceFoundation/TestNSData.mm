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
#import <vector>

TEST(NSData, WriteToURLOptions) {
    NSData* saveData = [NSData dataWithContentsOfURL:[[NSBundle mainBundle] URLForResource:@"Test" withExtension:@"plist"]];
    auto savePath = @"/tmp/Test.plist";

    NSError* error = nil;
    [saveData writeToFile:savePath options:NSDataWritingAtomic error:&error];
    ASSERT_OBJCEQ(error, nil);

    auto fileManager = [NSFileManager defaultManager];
    ASSERT_TRUE([fileManager fileExistsAtPath:savePath]);
    [fileManager removeItemAtPath:savePath error:&error];
    ASSERT_OBJCEQ(error, nil);
}

TEST(NSData, EmptyDescription) {
    auto expected = @"<>";

    std::vector<uint8_t> bytes = {};
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];

    ASSERT_OBJCEQ(expected, data.description);
}

TEST(NSData, Description) {
    auto expected = @"<ff4c3e00 55>";

    std::vector<uint8_t> bytes = { 0xff, 0x4c, 0x3e, 0x00, 0x55 };
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];

    ASSERT_OBJCEQ(data.description, expected);
}

TEST(NSData, LongDescription) {
    // taken directly from Foundation
    auto expected = @"<ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 "
                    @"82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff "
                    @"6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 "
                    @"d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e "
                    @"4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 "
                    @"ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 "
                    @"82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff "
                    @"6e4482d8 ff6e4482 d8ff6e44 82d8ff6e 4482d8ff 6e4482d8 ff6e4482 d8ff6e44 82d8>";

    std::vector<uint8_t> bytes = { 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e,
                                   0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82,
                                   0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff,
                                   0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44,
                                   0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8,
                                   0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e,
                                   0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82,
                                   0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff,
                                   0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44,
                                   0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8,
                                   0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e,
                                   0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82,
                                   0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff,
                                   0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44,
                                   0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8,
                                   0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e,
                                   0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82,
                                   0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff,
                                   0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44,
                                   0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8,
                                   0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e,
                                   0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8, 0xff, 0x6e, 0x44, 0x82, 0xd8 };

    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];

    ASSERT_OBJCEQ(expected, data.description);
}

TEST(NSData, DebugDescription) {
    auto expected = @"<ff4c3e00 55>";

    std::vector<uint8_t> bytes = { 0xff, 0x4c, 0x3e, 0x00, 0x55 };
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];

    ASSERT_OBJCEQ(data.debugDescription, expected);
}

TEST(NSData, LimitDebugDescription) {
    auto expected =
        @"<ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff>";

    std::vector<uint8_t> bytes(1024, 0xff);
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];
    ASSERT_OBJCEQ(data.debugDescription, expected);
}

TEST(NSData, LongDebugDescription) {
    auto expected =
        @"<ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ... ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff>";

    std::vector<uint8_t> bytes(100000, 0xff);
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];
    ASSERT_OBJCEQ(data.debugDescription, expected);
}

TEST(NSData, EdgeDebugDescription) {
    auto expected =
        @"<ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ... ffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ff>";

    std::vector<uint8_t> bytes(1025, 0xff);
    NSData* data = [NSData dataWithBytes:bytes.data() length:bytes.size()];
    ASSERT_OBJCEQ(data.debugDescription, expected);
}

TEST(NSData, EdgeNoCopyDescription) {
    auto expected =
        @"<ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ... ffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff ffffffff "
        @"ffffffff ffffffff ffffffff ffffffff ff>";

    std::vector<uint8_t> bytes(1025, 0xff);
    NSData* data = [NSData dataWithBytesNoCopy:bytes.data() length:bytes.size() freeWhenDone:false];
    ASSERT_OBJCEQ(data.debugDescription, expected);
    ASSERT_EQ(data.bytes, bytes.data());
}

TEST(NSData, InitializeWithBase64EncodedDataGetsDecodedData) {
    auto plainText = @"ARMA virumque cano, Troiae qui primus ab oris\nItaliam, fato profugus, Laviniaque venit";
    auto encodedText =
        @"QVJNQSB2aXJ1bXF1ZSBjYW5vLCBUcm9pYWUgcXVpIHByaW11cyBhYiBvcmlzCkl0YWxpYW0sIGZhdG8gcHJvZnVndXMsIExhdmluaWFxdWUgdmVuaXQ=";
    NSData* encodedData;
    if (!(encodedData = [encodedText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not get UTF-8 data");
        return;
    }
    NSData* decodedData;
    if (!(decodedData = [[[NSData alloc] initWithBase64EncodedData:encodedData options:0] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not Base-64 decode data");
        return;
    }
    NSString* decodedText;
    if (!(decodedText = [[[NSString alloc] initWithData:decodedData encoding:NSUTF8StringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert decoded data to a UTF-8 String");
        return;
    }

    ASSERT_OBJCEQ(decodedText, plainText);
    ASSERT_TRUE([decodedData isEqualToData:[plainText dataUsingEncoding:NSUTF8StringEncoding]]);
}

TEST(NSData, InitializeWithBase64EncodedDataWithNonBase64CharacterIsNil) {
    auto encodedText =
        @"QVJNQSB2aXJ1bXF1ZSBjYW5vLCBUcm9pYWUgcXVpIHBya$W11cyBhYiBvcmlzCkl0YWxpYW0sIGZhdG8gcHJvZnVndXMsIExhdmluaWFxdWUgdmVuaXQ=";
    NSData* encodedData;
    if (!(encodedData = [encodedText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not get UTF-8 data");
        return;
    }
    NSData* decodedData = [[[NSData alloc] initWithBase64EncodedData:encodedData options:0] autorelease];
    ASSERT_OBJCEQ(decodedData, nil);
}

TEST(NSData, InitializeWithBase64EncodedDataWithNonBase64CharacterWithOptionToAllowItSkipsCharacter) {
    auto plainText = @"ARMA virumque cano, Troiae qui primus ab oris\nItaliam, fato profugus, Laviniaque venit";
    auto encodedText =
        @"QVJNQSB2aXJ1bXF1ZSBjYW5vLCBUcm9pYWUgcXVpIHBya$W11cyBhYiBvcmlzCkl0YWxpYW0sIGZhdG8gcHJvZnVndXMsIExhdmluaWFxdWUgdmVuaXQ=";
    NSData* encodedData;
    if (!(encodedData = [encodedText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not get UTF-8 data");
        return;
    }
    NSData* decodedData;
    if (!(decodedData =
              [[[NSData alloc] initWithBase64EncodedData:encodedData options:NSDataBase64DecodingIgnoreUnknownCharacters] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not Base-64 decode data");
        return;
    }
    NSString* decodedText;
    if (!(decodedText = [[[NSString alloc] initWithData:decodedData encoding:NSUTF8StringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert decoded data to a UTF-8 String");
        return;
    }

    ASSERT_OBJCEQ(decodedText, plainText);
    ASSERT_TRUE([decodedData isEqualToData:[plainText dataUsingEncoding:NSUTF8StringEncoding]]);
}

TEST(NSData, InitializeWithBase64EncodedStringGetsDecodedData) {
    auto plainText = @"ARMA virumque cano, Troiae qui primus ab oris\nItaliam, fato profugus, Laviniaque venit";
    auto encodedText =
        @"QVJNQSB2aXJ1bXF1ZSBjYW5vLCBUcm9pYWUgcXVpIHByaW11cyBhYiBvcmlzCkl0YWxpYW0sIGZhdG8gcHJvZnVndXMsIExhdmluaWFxdWUgdmVuaXQ=";
    NSData* decodedData;
    if (!(decodedData = [[[NSData alloc] initWithBase64EncodedString:encodedText options:0] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not Base-64 decode data");
        return;
    }
    NSString* decodedText;
    if (!(decodedText = [[[NSString alloc] initWithData:decodedData encoding:NSUTF8StringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert decoded data to a UTF-8 String");
        return;
    }

    ASSERT_OBJCEQ(decodedText, plainText);
}

TEST(NSData, Base64EncodedDataGetsEncodedText) {
    auto plainText = @"Constitit, et lacrimans, `Quis iam locus’ inquit `Achate,\nquae regio in terris nostri non plena laboris?`";
    auto encodedText = @"Q29uc3RpdGl0LCBldCBsYWNyaW1hbnMsIGBRdWlzIGlhbSBsb2N1c+"
                       @"KAmSBpbnF1aXQgYEFjaGF0ZSwKcXVhZSByZWdpbyBpbiB0ZXJyaXMgbm9zdHJpIG5vbiBwbGVuYSBsYWJvcmlzP2A=";
    NSData* data;
    if (!(data = [plainText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not encode UTF-8 string");
        return;
    }
    NSData* encodedData = [data base64EncodedDataWithOptions:0];
    NSString* encodedTextResult;
    if (!(encodedTextResult = [[[NSString alloc] initWithData:encodedData encoding:NSASCIIStringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert encoded data to an ASCII String");
        return;
    }
    ASSERT_OBJCEQ(encodedTextResult, encodedText);
}

TEST(NSData, Base64EncodedDataWithOptionToInsertLineFeedsContainsLineFeed) {
    auto plainText = @"Constitit, et lacrimans, `Quis iam locus’ inquit `Achate,\nquae regio in terris nostri non plena laboris?`";
    auto encodedText = @"Q29uc3RpdGl0LCBldCBsYWNyaW1hbnMsIGBRdWlzIGlhbSBsb2N1c+"
                       @"KAmSBpbnF1\naXQgYEFjaGF0ZSwKcXVhZSByZWdpbyBpbiB0ZXJyaXMgbm9zdHJpIG5vbiBwbGVu\nYSBsYWJvcmlzP2A=";
    NSData* data;
    if (!(data = [plainText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not encode UTF-8 string");
        return;
    }
    NSData* encodedData =
        [data base64EncodedDataWithOptions:NSDataBase64Encoding64CharacterLineLength | NSDataBase64EncodingEndLineWithLineFeed];
    NSString* encodedTextResult;
    if (!(encodedTextResult = [[[NSString alloc] initWithData:encodedData encoding:NSASCIIStringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert encoded data to an ASCII String");
        return;
    }
    ASSERT_OBJCEQ(encodedTextResult, encodedText);
}

TEST(NSData, Base64EncodedDataWithOptionToInsertCarriageReturnContainsCarriageReturn) {
    auto plainText = @"Constitit, et lacrimans, `Quis iam locus’ inquit `Achate,\nquae regio in terris nostri non plena laboris?`";
    auto encodedText = @"Q29uc3RpdGl0LCBldCBsYWNyaW1hbnMsIGBRdWlzIGlhbSBsb2N1c+"
                       @"KAmSBpbnF1aXQgYEFjaGF0\rZSwKcXVhZSByZWdpbyBpbiB0ZXJyaXMgbm9zdHJpIG5vbiBwbGVuYSBsYWJvcmlzP2A=";
    NSData* data;
    if (!(data = [plainText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not encode UTF-8 string");
        return;
    }
    NSData* encodedData =
        [data base64EncodedDataWithOptions:NSDataBase64Encoding76CharacterLineLength | NSDataBase64EncodingEndLineWithCarriageReturn];
    NSString* encodedTextResult;
    if (!(encodedTextResult = [[[NSString alloc] initWithData:encodedData encoding:NSASCIIStringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert encoded data to an ASCII String");
        return;
    }
    ASSERT_OBJCEQ(encodedTextResult, encodedText);
}

TEST(NSData, Base64EncodedDataWithOptionToInsertCarriageReturnAndLineFeedContainsBoth) {
    auto plainText = @"Revocate animos, maestumque timorem mittite: forsan et haec olim meminisse iuvabit.";
    auto encodedText =
        @"UmV2b2NhdGUgYW5pbW9zLCBtYWVzdHVtcXVlIHRpbW9yZW0gbWl0dGl0ZTogZm9yc2FuIGV0IGhh\r\nZWMgb2xpbSBtZW1pbmlzc2UgaXV2YWJpdC4=";
    NSData* data;
    if (!(data = [plainText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not encode UTF-8 string");
        return;
    }
    NSData* encodedData =
        [data base64EncodedDataWithOptions:NSDataBase64Encoding76CharacterLineLength | NSDataBase64EncodingEndLineWithCarriageReturn |
                                           NSDataBase64EncodingEndLineWithLineFeed];
    NSString* encodedTextResult;
    if (!(encodedTextResult = [[[NSString alloc] initWithData:encodedData encoding:NSASCIIStringEncoding] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not convert encoded data to an ASCII String");
        return;
    }
    ASSERT_OBJCEQ(encodedTextResult, encodedText);
}

TEST(NSData, Base64EncodedStringGetsEncodedText) {
    auto plainText = @"Revocate animos, maestumque timorem mittite: forsan et haec olim meminisse iuvabit.";
    auto encodedText = @"UmV2b2NhdGUgYW5pbW9zLCBtYWVzdHVtcXVlIHRpbW9yZW0gbWl0dGl0ZTogZm9yc2FuIGV0IGhhZWMgb2xpbSBtZW1pbmlzc2UgaXV2YWJpdC4=";
    NSData* data;
    if (!(data = [plainText dataUsingEncoding:NSUTF8StringEncoding])) {
        ASSERT_TRUE_MSG(false, @"Could not encode UTF-8 string");
        return;
    }
    auto encodedTextResult = [data base64EncodedStringWithOptions:0];
    ASSERT_OBJCEQ(encodedTextResult, encodedText);
}

TEST(NSData, Base64DecodeWithPadding1) {
    auto encodedPadding1 = @"AoR=";
    std::vector<uint8_t> dataPadding1Bytes = { 0x02, 0x84 };
    NSData* dataPadding1 = [NSData dataWithBytes:dataPadding1Bytes.data() length:dataPadding1Bytes.size()];

    NSData* decodedPadding1;
    if (!(decodedPadding1 = [[[NSData alloc] initWithBase64EncodedString:encodedPadding1 options:0] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not Base-64 decode data");
        return;
    }
    ASSERT_TRUE([dataPadding1 isEqualToData:decodedPadding1]);
}

TEST(NSData, Base64DecodeWithPadding2) {
    auto encodedPadding2 = @"Ao==";
    std::vector<uint8_t> dataPadding2Bytes = { 0x02 };
    NSData* dataPadding2 = [NSData dataWithBytes:dataPadding2Bytes.data() length:dataPadding2Bytes.size()];

    NSData* decodedPadding2;
    if (!(decodedPadding2 = [[[NSData alloc] initWithBase64EncodedString:encodedPadding2 options:0] autorelease])) {
        ASSERT_TRUE_MSG(false, @"Could not Base-64 decode data");
        return;
    }
    ASSERT_TRUE([dataPadding2 isEqualToData:decodedPadding2]);
}

TEST(NSData, RangeOfData) {
    std::vector<uint8_t> baseData = { 0x00, 0x01, 0x02, 0x03, 0x04 };
    NSData* base = [NSData dataWithBytes:baseData.data() length:baseData.size()];
    NSRange baseFullRange = NSMakeRange(0, baseData.size());
    NSRange noPrefixRange = NSMakeRange(2, baseData.size() - 2);
    NSRange noSuffixRange = NSMakeRange(0, baseData.size() - 2);
    NSRange notFoundRange = NSMakeRange(NSNotFound, 0);

    std::vector<uint8_t> prefixData = { 0x00, 0x01 };
    NSData* prefix = [NSData dataWithBytes:prefixData.data() length:prefixData.size()];
    NSRange prefixRange = NSMakeRange(0, prefixData.size());

    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:0 range:baseFullRange], prefixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:NSDataSearchAnchored range:baseFullRange], prefixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:NSDataSearchBackwards range:baseFullRange], prefixRange));
    ASSERT_TRUE(
        NSEqualRanges([base rangeOfData:prefix options:NSDataSearchBackwards | NSDataSearchAnchored range:baseFullRange], notFoundRange));

    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:0 range:noPrefixRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:NSDataSearchBackwards range:noPrefixRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:0 range:noSuffixRange], prefixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:prefix options:NSDataSearchBackwards range:noSuffixRange], prefixRange));

    std::vector<uint8_t> suffixData = { 0x03, 0x04 };
    NSData* suffix = [NSData dataWithBytes:suffixData.data() length:suffixData.size()];
    NSRange suffixRange = NSMakeRange(3, suffixData.size());

    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:0 range:baseFullRange], suffixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:NSDataSearchAnchored range:baseFullRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:NSDataSearchBackwards range:baseFullRange], suffixRange));
    ASSERT_TRUE(
        NSEqualRanges([base rangeOfData:suffix options:NSDataSearchBackwards | NSDataSearchAnchored range:baseFullRange], suffixRange));

    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:0 range:noPrefixRange], suffixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:NSDataSearchBackwards range:noPrefixRange], suffixRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:0 range:noSuffixRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:suffix options:NSDataSearchBackwards range:noSuffixRange], notFoundRange));

    std::vector<uint8_t> sliceData = { 0x02, 0x03 };
    NSData* slice = [NSData dataWithBytes:sliceData.data() length:sliceData.size()];
    NSRange sliceRange = NSMakeRange(2, sliceData.size());

    ASSERT_TRUE(NSEqualRanges([base rangeOfData:slice options:0 range:baseFullRange], sliceRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:slice options:NSDataSearchAnchored range:baseFullRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:slice options:NSDataSearchBackwards range:baseFullRange], sliceRange));
    ASSERT_TRUE(
        NSEqualRanges([base rangeOfData:slice options:NSDataSearchBackwards | NSDataSearchAnchored range:baseFullRange], notFoundRange));

    NSData* empty = [NSData data];
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:empty options:0 range:baseFullRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:empty options:NSDataSearchAnchored range:baseFullRange], notFoundRange));
    ASSERT_TRUE(NSEqualRanges([base rangeOfData:empty options:NSDataSearchBackwards range:baseFullRange], notFoundRange));
    ASSERT_TRUE(
        NSEqualRanges([base rangeOfData:empty options:NSDataSearchBackwards | NSDataSearchAnchored range:baseFullRange], notFoundRange));
}
