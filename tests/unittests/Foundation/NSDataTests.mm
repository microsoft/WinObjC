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

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSMutableData.h>
#import <Foundation/NSURL.h>

// TODO: BUG 5403859: Enable ARC on this test file once load order issue is fixed

// Helper function for testing decoding of base64 encoded strings
void testDecode(NSString* base64String, NSString* expectedDecode, BOOL ignoreUnknownChars) {
    StrongId<NSData> decodedData =
        [[[NSData alloc] initWithBase64EncodedString:base64String
                                             options:(ignoreUnknownChars ? NSDataBase64DecodingIgnoreUnknownCharacters : 0)] autorelease];
    ASSERT_OBJCNE(nil, decodedData);

    StrongId<NSString> decodedString = [[[NSString alloc] initWithData:decodedData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ(expectedDecode, decodedString);
}

TEST(NSData, Base64EncodeWithOptions) {
    StrongId<NSData> testData0Chars = [@"" dataUsingEncoding:NSUTF8StringEncoding];
    StrongId<NSData> testData48Chars = [@"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" dataUsingEncoding:NSUTF8StringEncoding];
    StrongId<NSData> testData49Chars = [@"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" dataUsingEncoding:NSUTF8StringEncoding];
    StrongId<NSData> testData50Chars = [@"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" dataUsingEncoding:NSUTF8StringEncoding];
    StrongId<NSData> testData58Chars =
        [@"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" dataUsingEncoding:NSUTF8StringEncoding];

    // "QUFB" is the base64 encoded representation of "AAA"
    // For more information, please refer to https://en.wikipedia.org/wiki/Base64

    // Test = padding
    ASSERT_OBJCEQ(@"", [testData0Chars base64Encoding]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB", [testData48Chars base64Encoding]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQQ==", [testData49Chars base64Encoding]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUE=", [testData50Chars base64Encoding]);

    // Test newline 64 chars
    ASSERT_OBJCEQ(@"", [testData0Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
                  [testData48Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\r\nQQ==",
                  [testData49Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\r\nQUE=",
                  [testData50Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]);

    // Test newline 64 chars options
    ASSERT_OBJCEQ(@"",
                  [testData0Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength |
                                                                 NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
                  [testData48Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\rQQ==",
                  [testData49Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength |
                                                                  NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\nQUE=",
                  [testData50Chars
                      base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength | NSDataBase64EncodingEndLineWithLineFeed]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\r\nQUE=",
                  [testData50Chars base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength |
                                                                  NSDataBase64EncodingEndLineWithLineFeed |
                                                                  NSDataBase64EncodingEndLineWithCarriageReturn]);

    // Test newline 76 chars
    ASSERT_OBJCEQ(@"",
                  [testData0Chars base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength |
                                                                 NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
                  [testData48Chars base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQQ==",
                  [testData49Chars base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength |
                                                                  NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUE=",
                  [testData50Chars
                      base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength | NSDataBase64EncodingEndLineWithLineFeed]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUE=",
                  [testData50Chars base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength |
                                                                  NSDataBase64EncodingEndLineWithLineFeed |
                                                                  NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\nQQ==",
                  [testData58Chars
                      base64EncodedStringWithOptions:NSDataBase64Encoding76CharacterLineLength | NSDataBase64EncodingEndLineWithLineFeed]);
}

TEST(NSData, Base64DecodeWithOptions) {
    // Invalid input should return nil
    StrongId<NSData> invalidDecoded = [[[NSData alloc] initWithBase64Encoding:@"%"] autorelease];
    ASSERT_OBJCEQ(nil, invalidDecoded);

    // Basic testing
    testDecode(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
               @"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
               NO);
    testDecode(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
               @"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
               YES);

    // Test that newline chars are ignored, and =s are properly parsed
    testDecode(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\r\nQkI=",
               @"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB",
               YES);

    // Test line length 76
    testDecode(@"QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB\nQQ==",
               @"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
               YES);

    // Test that other invalid chars are ignored
    testDecode(@"QUFB%%QU^FB##(QUFBQUFBQUFBQUFBQ   UFBQUFBQUFBQUFBQUFBQUFBQU)]FBQ*UFBQUFBQUFB\rQkI=",
               @"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB",
               YES);

    // Test decoding an empty string
    testDecode(@"", @"", NO);
    testDecode(@"", @"", YES);

    // Test a string of only invalid chars
    testDecode(@" %", @"", YES);
}

TEST(NSData, Base64EncodeDecode) {
    StrongId<NSString> testString = @"SGVsbG8gV29ybGQh";
    StrongId<NSData> decodedData = [[[NSData alloc] initWithBase64EncodedString:testString options:0] autorelease];
    StrongId<NSString> encodedString = [decodedData base64EncodedStringWithOptions:0];
    ASSERT_TRUE_MSG([testString isEqualToString:encodedString],
                    "Failed: Base64 encoded testString: %@ decoded to: %@ does not equal re-encoded string:%@",
                    &*testString,
                    &*decodedData,
                    &*encodedString);
}

TEST(NSData, Base64EncodeDecodeWrappers) {
    // "Wlpa" is the base64 encoded representation of "ZZZ"
    // For more information, please refer to https://en.wikipedia.org/wiki/Base64

    // initWithBase64EncodedData
    StrongId<NSData> encodedDataUTF8 = [@"Wlpa" dataUsingEncoding:NSUTF8StringEncoding];
    StrongId<NSData> encodedDataASCII = [@"Wlpa" dataUsingEncoding:NSASCIIStringEncoding];

    StrongId<NSData> decodedDataUTF8 = [[[NSData alloc] initWithBase64EncodedData:encodedDataUTF8 options:0] autorelease];
    StrongId<NSData> decodedDataASCII = [[[NSData alloc] initWithBase64EncodedData:encodedDataASCII options:0] autorelease];

    StrongId<NSData> expectedDecodedData = [@"ZZZ" dataUsingEncoding:NSUTF8StringEncoding];
    ASSERT_OBJCEQ(expectedDecodedData, decodedDataUTF8);
    ASSERT_OBJCEQ(expectedDecodedData, decodedDataASCII);

    // initWithBase64Encoding
    StrongId<NSData> encodedDataInitWithString = [[[NSData alloc] initWithBase64Encoding:@"Wlpa"] autorelease];
    ASSERT_OBJCEQ([@"ZZZ" dataUsingEncoding:NSUTF8StringEncoding], encodedDataInitWithString);

    // base64Encoding
    ASSERT_OBJCEQ(@"Wlpa", [expectedDecodedData base64Encoding]);

    // base64EncodedDataWithOptions
    ASSERT_OBJCEQ([@"WlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpa\rWg==" dataUsingEncoding:NSUTF8StringEncoding],
                  [[@"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" dataUsingEncoding:NSUTF8StringEncoding]
                      base64EncodedDataWithOptions:NSDataBase64Encoding64CharacterLineLength |
                                                   NSDataBase64EncodingEndLineWithCarriageReturn]);
    ASSERT_OBJCEQ([@"WlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpaWlpa\r\nWlo="
                      dataUsingEncoding:NSUTF8StringEncoding],
                  [[@"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" dataUsingEncoding:NSUTF8StringEncoding]
                      base64EncodedDataWithOptions:NSDataBase64Encoding76CharacterLineLength]);
}

TEST(NSData, WriteToURL) {
    // first, write the test string to NSURL which represents as a file
    // ensure it succeeds
    const char bytes[] = "Hello world";
    StrongId<NSData> expectedData = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];
    StrongId<NSURL> fileURL = [NSURL fileURLWithPath:@"./Library/Helloworld.txt"];
    ASSERT_TRUE_MSG([expectedData writeToURL:fileURL options:0 error:nullptr], "NSDataWriteToURL should succeed");

    // second, read the file content back, compare with original content
    // ensure they are equal
    StrongId<NSData> actualData = [NSData dataWithContentsOfFile:[fileURL path]];
    ASSERT_OBJCEQ_MSG(expectedData, actualData, "Data should be equal");
}

TEST(NSData, MutableDataBasicTests) {
    const char bytes[] = "Hello world";
    StrongId<NSData> data = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];

    StrongId<NSMutableData> mutableData = [NSMutableData dataWithLength:0];
    [mutableData appendData:data];
    ASSERT_OBJCEQ_MSG(data, mutableData, "Data should be equal");

    // replaced content with valid range
    const char newBytes[] = "replaced";
    NSRange validRange = NSMakeRange(0, std::extent<decltype(bytes)>::value);
    [mutableData replaceBytesInRange:validRange withBytes:newBytes];

    // create expected data with new bytes
    NSRange newRange = NSMakeRange(0, std::extent<decltype(newBytes)>::value);
    data = [NSData dataWithBytes:newBytes length:std::extent<decltype(newBytes)>::value];

    // verify expected and replaced data is equal
    ASSERT_OBJCEQ_MSG(data, [mutableData subdataWithRange:newRange], "Data should be equal");

    // verify replace with invalid range location should throw
    NSRange inValidRange = NSMakeRange(100, 100);
    EXPECT_ANY_THROW([mutableData replaceBytesInRange:inValidRange withBytes:newBytes]);

    // reset the content
    validRange = NSMakeRange(0, std::extent<decltype(newBytes)>::value);
    [mutableData resetBytesInRange:validRange];

    // verify the content should be equal after reset
    const char resettedBytes[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    data = [NSData dataWithBytes:resettedBytes length:std::extent<decltype(resettedBytes)>::value];
    ASSERT_OBJCEQ_MSG(data, [mutableData subdataWithRange:newRange], "Data should be equal");

    // verify reset with invalid range location should throw
    EXPECT_ANY_THROW([mutableData replaceBytesInRange:inValidRange withBytes:newBytes]);
}

TEST(NSData, MutableDataReplaceTests) {
    const char bytes[] = "Hello obj world";
    StrongId<NSData> originalData = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];

    const char bytesTobeReplaced[] = "0123456789";
    StrongId<NSData> data = [NSData dataWithBytes:bytesTobeReplaced length:std::extent<decltype(bytesTobeReplaced)>::value];
    StrongId<NSMutableData> mutableData = [NSMutableData dataWithLength:0];
    [mutableData setData:data];

    // 1. replace used as insert, replace with zero range at starting location 0, essentially insert hello at front, thus have
    // "hello\001234567890\0"
    const char HelloBytes[] = "Hello";
    unsigned len = std::extent<decltype(HelloBytes)>::value;
    [mutableData replaceBytesInRange:NSMakeRange(0, 0) withBytes:HelloBytes length:len];

    // 2. replace 0 with " obj",  with range (len-1, 1) thus have the results of "hello obj\0123456789\0", tail shifted
    const char objBytes[] = " obj";
    unsigned len2 = std::extent<decltype(objBytes)>::value;
    [mutableData replaceBytesInRange:NSMakeRange(len - 1, 2) withBytes:objBytes length:len2];

    // 3. replace used as delete, replacing "789" with null (or length 0) string, effectively delete 789, thus have "hello obj\0123456"
    [mutableData replaceBytesInRange:NSMakeRange(15, 4) withBytes:NULL length:0];

    // 4. replace ending "123456" with " world", thus have "Hello obj world"
    const char worldBytes[] = " world";
    [mutableData replaceBytesInRange:NSMakeRange(len + len2 - 2, 7) withBytes:worldBytes length:std::extent<decltype(worldBytes)>::value];

    // verify after all replacements, the data should be equal
    ASSERT_OBJCEQ_MSG(originalData, mutableData, "Data should be equal");

    // verify descriptions are equal
    StrongId<NSString> expectedHex = @"<48656c6c 6f206f62 6a20776f 726c6400>";
    ASSERT_OBJCEQ_MSG(expectedHex, [originalData description], "Description must be equal");
    ASSERT_OBJCEQ_MSG(expectedHex, [mutableData description], "Description must be equal");
}

TEST(NSData, ExpandBeyondCapacity) {
    NSMutableData* data = [NSMutableData dataWithCapacity:1];
    std::string stringData = "winobjc";

    [data appendBytes:stringData.data() length:stringData.length()];
    ASSERT_EQ(stringData.length(), [data length]);
}