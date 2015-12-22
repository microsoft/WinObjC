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

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
#import <Foundation/NSMutableData.h>
#import <Foundation/NSURL.h>

TEST(Foundation, NSData_Base64EncodeDecode) {
    NSString* testString = @"SGVsbG8gV29ybGQh";
    NSData* decodedData = [[[NSData alloc] initWithBase64EncodedString:testString options:0] autorelease];
    NSString* encodedString = [decodedData base64EncodedStringWithOptions:0];
    ASSERT_TRUE_MSG([testString isEqualToString:encodedString],
                    "Failed: Base64 encoded testString: %@ decoded to: %@ does not equal re-encoded string:%@",
                    testString,
                    decodedData,
                    encodedString);
}

TEST(Foundation, NSDataWriteToURL) {
    // first, write the test string to NSURL which represents as a file
    // ensure it succeeds
    const char bytes[] = "Hello world";
    NSData* expectedData = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];
    NSURL* fileURL = [NSURL fileURLWithPath:@"./Library/Helloworld.txt"];
    ASSERT_TRUE_MSG([expectedData writeToURL:fileURL options:0 error:nullptr], "NSDataWriteToURL should succeed");

    // second, read the file content back, compare with original content
    // ensure they are equal
    NSData* actualData = [NSData dataWithContentsOfFile:[fileURL path]];
    ASSERT_OBJCEQ_MSG(expectedData, actualData, "Data should be equal");
}

TEST(Foundation, NSMutableDataBasicTests) {
    const char bytes[] = "Hello world";
    NSData* data = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];

    NSMutableData* mutableData = [NSMutableData dataWithLength:0];
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
    const char resettedBytes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    data = [NSData dataWithBytes:resettedBytes length:std::extent<decltype(resettedBytes)>::value];
    ASSERT_OBJCEQ_MSG(data, [mutableData subdataWithRange:newRange], "Data should be equal");

    // verify reset with invalid range location should throw
    EXPECT_ANY_THROW([mutableData replaceBytesInRange:inValidRange withBytes:newBytes]);
}

TEST(Foundation, NSMutableDataReplaceTests) {

    const char bytes[] = "Hello obj world";
    NSData* originalData = [NSData dataWithBytes:bytes length:std::extent<decltype(bytes)>::value];

    const char bytesTobeReplaced[] = "0123456789";
    NSData* data = [NSData dataWithBytes:bytesTobeReplaced length:std::extent<decltype(bytesTobeReplaced)>::value];
    NSMutableData* mutableData = [NSMutableData dataWithLength:0];
    [mutableData setData:data];

    // 1. replace used as insert, replace with zero range at starting location 0, essentially insert hello at front, thus have "hello\001234567890\0"
    const char HelloBytes[] = "Hello";
    unsigned len = std::extent<decltype(HelloBytes)>::value;
    [mutableData replaceBytesInRange:NSMakeRange(0, 0) withBytes:HelloBytes length:len];

    // 2. replace 0 with " obj",  with range (len-1, 1) thus have the results of "hello obj\0123456789\0", tail shifted
    const char objBytes[] = " obj";
    unsigned len2 = std::extent<decltype(objBytes)>::value;
    [mutableData replaceBytesInRange:NSMakeRange(len-1, 2) withBytes:objBytes length:len2];

    // 3. replace used as delete, replacing "789" with null (or length 0) string, effectively delete 789, thus have "hello obj\0123456"
    [mutableData replaceBytesInRange:NSMakeRange(15, 4) withBytes:NULL length:0];
    
    // 4. replacing ending "123456" with " world", thus have "Hello obj world", notice we used a big range in replacement
    // to prove it does not have to be the exact range of "123456\0" in order for replacement to succeed, now we should 
    // have "hello obj world\0"
    const char worldBytes[] = " world";
    [mutableData replaceBytesInRange:NSMakeRange(len + len2 - 2, 100) withBytes:worldBytes length:std::extent<decltype(worldBytes)>::value];

    // verify after all replacements, the data should be equal
    ASSERT_OBJCEQ_MSG(originalData, mutableData, "Data should be equal");
}
