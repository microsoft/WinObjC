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

#import <Foundation/NSString.h>
#import <Foundation/NSData.h>
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
    ASSERT_TRUE_MSG([expectedData writeToURL:fileURL options:0 error:nil], "NSDataWriteToURL should succeed");

    // second, read the file content back, compare with original content
    // ensure they are equal
    NSData* actualData = [NSData dataWithContentsOfFile:[fileURL path]];
    ASSERT_OBJCEQ_MSG(expectedData, actualData, "Data should be equal");
}
