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
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import "TestUtils.h"

static NSString* createTestFile(NSString* path, NSData* contents) {
    auto fileNames = @[ [NSString stringWithFormat:@"/tmp/TestFoundation_Playground_%@/%@", [[NSUUID UUID] UUIDString], path] ];

    if (ensureFilesWithContents(fileNames, contents)) {
        return fileNames[0];
    } else {
        return nil;
    }
}

static void removeTestFile(NSString* location) {
    NSError* error;
    [[NSFileManager defaultManager] removeItemAtPath:location error:&error];
    ASSERT_OBJCEQ(nil, error);
}

TEST(NSStream, InputStreamWithData) {
    NSString* message = @"Hello, playground";
    NSData* messageData = [message dataUsingEncoding:NSUTF8StringEncoding];
    NSInputStream* dataStream = [NSInputStream inputStreamWithData:messageData];

    ASSERT_EQ(NSStreamStatusNotOpen, dataStream.streamStatus);
    [dataStream open];
    ASSERT_EQ(NSStreamStatusOpen, dataStream.streamStatus);
    uint8_t buffer[20] = {};
    if (dataStream.hasBytesAvailable) {
        NSInteger result = [dataStream read:buffer maxLength:_countof(buffer)];
        [dataStream close];
        ASSERT_EQ(NSStreamStatusClosed, dataStream.streamStatus);
        if (result > 0) {
            NSString* output = [[[NSString alloc] initWithBytes:buffer length:result encoding:NSUTF8StringEncoding] autorelease];
            ASSERT_OBJCEQ(message, output);
        }
    }
}

TEST(NSStream, InputStreamWithUrl) {
    NSString* message = @"Hello, playground";
    NSData* messageData = [message dataUsingEncoding:NSUTF8StringEncoding];
    // Initializer with url
    auto testFile = createTestFile(@"testFile_in.txt", messageData);
    if (testFile != nil) {
        auto url = [NSURL fileURLWithPath:testFile];
        NSInputStream* urlStream = [NSInputStream inputStreamWithURL:url];
        ASSERT_EQ(NSStreamStatusNotOpen, urlStream.streamStatus);
        [urlStream open];
        ASSERT_EQ(NSStreamStatusOpen, urlStream.streamStatus);
        uint8_t buffer[20] = {};
        if (urlStream.hasBytesAvailable) {
            NSInteger result = [urlStream read:buffer maxLength:_countof(buffer)];
            [urlStream close];
            ASSERT_EQ(NSStreamStatusClosed, urlStream.streamStatus);
            ASSERT_EQ(messageData.length, result);
            if (result > 0) {
                NSString* output = [[[NSString alloc] initWithBytes:buffer length:result encoding:NSUTF8StringEncoding] autorelease];
                ASSERT_OBJCEQ(message, output);
            }
        }
        removeTestFile(testFile);
    } else {
        ASSERT_TRUE_MSG(false, @"Unable to create temp file");
    }
}

TEST(NSStream, InputStreamWithFile) {
    NSString* message = @"Hello, playground";
    NSData* messageData = [message dataUsingEncoding:NSUTF8StringEncoding];
    // Initialiser with file
    auto testFile = createTestFile(@"testFile_in.txt", messageData);
    if (testFile != nil) {
        NSInputStream* fileStream = [NSInputStream inputStreamWithFileAtPath:testFile];
        ASSERT_EQ(NSStreamStatusNotOpen, fileStream.streamStatus);
        [fileStream open];
        ASSERT_EQ(NSStreamStatusOpen, fileStream.streamStatus);
        uint8_t buffer[20] = {};
        if (fileStream.hasBytesAvailable) {
            NSInteger result = [fileStream read:buffer maxLength:_countof(buffer)];
            [fileStream close];
            ASSERT_EQ(NSStreamStatusClosed, fileStream.streamStatus);
            ASSERT_EQ(messageData.length, result);
            if (result > 0) {
                NSString* output = [[[NSString alloc] initWithBytes:&buffer length:result encoding:NSUTF8StringEncoding] autorelease];
                ASSERT_OBJCEQ(message, output);
            }
        }
        removeTestFile(testFile);
    } else {
        ASSERT_TRUE_MSG(false, @"Unable to create temp file");
    }
}

TEST(NSStream, InputStreamHasBytesAvailable) {
    NSString* message = @"Hello, playground";
    NSData* messageData = [message dataUsingEncoding:NSUTF8StringEncoding];
    NSInputStream* stream = [NSInputStream inputStreamWithData:messageData];
    uint8_t buffer[20] = {};
    [stream open];
    ASSERT_TRUE(stream.hasBytesAvailable);
    NSInteger result = [stream read:buffer maxLength:_countof(buffer)];
    ASSERT_FALSE(stream.hasBytesAvailable);
}

TEST(NSStream, InputStreamInvalidPath) {
    NSInputStream* fileStream = [NSInputStream inputStreamWithFileAtPath:@"/tmp/file.txt"];
    ASSERT_EQ(NSStreamStatusNotOpen, fileStream.streamStatus);
    [fileStream open];
    ASSERT_EQ(NSStreamStatusError, fileStream.streamStatus);
}

TEST(NSStream, OutputStreamCreationToFile) {
    auto filePath = createTestFile(@"TestFileOut.txt", nil);
    if (filePath != nil) {
        NSOutputStream* outputStream = [NSOutputStream outputStreamToFileAtPath:filePath append:NO];
        ASSERT_EQ(NSStreamStatusNotOpen, outputStream.streamStatus);
        auto myString = @"Hello world!";
        NSData* encodedData = [myString dataUsingEncoding:NSUTF8StringEncoding];
        [outputStream open];
        ASSERT_EQ(NSStreamStatusOpen, outputStream.streamStatus);
        auto result = [outputStream write:(const unsigned char*)encodedData.bytes maxLength:encodedData.length];
        [outputStream close];
        ASSERT_EQ(myString.length, result);
        ASSERT_EQ(NSStreamStatusClosed, outputStream.streamStatus);
        removeTestFile(filePath);
    } else {
        ASSERT_TRUE_MSG(false, @"Unable to create temp file");
    }
}

TEST(NSStream, OutputStreamCreationToBuffer) {
    uint8_t buffer[12] = {};
    auto myString = @"Hello world!";
    NSData* encodedData = [myString dataUsingEncoding:NSUTF8StringEncoding];

    NSOutputStream* outputStream = [NSOutputStream outputStreamToBuffer:buffer capacity:12];
    ASSERT_EQ(NSStreamStatusNotOpen, outputStream.streamStatus);
    [outputStream open];
    ASSERT_EQ(NSStreamStatusOpen, outputStream.streamStatus);
    auto result = [outputStream write:(const unsigned char*)encodedData.bytes maxLength:encodedData.length];
    [outputStream close];
    ASSERT_EQ(NSStreamStatusClosed, outputStream.streamStatus);
    ASSERT_EQ(myString.length, result);
    ASSERT_OBJCEQ([[[NSString alloc] initWithBytes:buffer length:_countof(buffer) encoding:NSUTF8StringEncoding] autorelease], myString);
}

TEST(NSStream, OutputStreamCreationWithUrl) {
    auto filePath = createTestFile(@"TestFileOut.txt", nil);
    if (filePath != nil) {
        NSOutputStream* outputStream = [NSOutputStream outputStreamWithURL:[NSURL fileURLWithPath:filePath] append:YES];
        ASSERT_EQ(NSStreamStatusNotOpen, outputStream.streamStatus);
        auto myString = @"Hello world!";
        NSData* encodedData = [myString dataUsingEncoding:NSUTF8StringEncoding];

        [outputStream open];
        ASSERT_EQ(NSStreamStatusOpen, outputStream.streamStatus);
        auto result = [outputStream write:(const unsigned char*)encodedData.bytes maxLength:encodedData.length];
        [outputStream close];
        ASSERT_EQ(myString.length, result);
        ASSERT_EQ(NSStreamStatusClosed, outputStream.streamStatus);
        removeTestFile(filePath);
    } else {
        ASSERT_TRUE_MSG(false, @"Unable to create temp file");
    }
}

TEST(NSStream, OutputStreamCreationToMemory) {
    uint8_t buffer[12] = {};
    auto myString = @"Hello world!";
    NSData* encodedData = [myString dataUsingEncoding:NSUTF8StringEncoding];

    auto outputStream = [NSOutputStream outputStreamToMemory];
    ASSERT_EQ(NSStreamStatusNotOpen, outputStream.streamStatus);
    [outputStream open];
    ASSERT_EQ(NSStreamStatusOpen, outputStream.streamStatus);
    auto result = [outputStream write:(const unsigned char*)encodedData.bytes maxLength:encodedData.length];
    ASSERT_EQ(myString.length, result);
    // verify the data written
    auto dataWritten = [outputStream propertyForKey:NSStreamDataWrittenToMemoryStreamKey];
    if (auto nsdataWritten = ([dataWritten isKindOfClass:[NSData class]] ? (NSData*)dataWritten : nil)) {
        [nsdataWritten getBytes:buffer length:result];
        ASSERT_OBJCEQ([[[NSString alloc] initWithBytes:buffer length:_countof(buffer) encoding:NSUTF8StringEncoding] autorelease],
                      myString);
        [outputStream close];
    } else {
        ASSERT_TRUE_MSG(false, @"Unable to get data from memeory.");
    }
}

TEST(NSStream, OutputStreamHasSpaceAvailable) {
    uint8_t buffer[12] = {};
    auto myString = @"Welcome To Hello world  !";
    NSData* encodedData = [myString dataUsingEncoding:NSUTF8StringEncoding];

    NSOutputStream* outputStream = [NSOutputStream outputStreamToBuffer:buffer capacity:12];
    [outputStream open];
    ASSERT_TRUE(outputStream.hasSpaceAvailable);
    auto result = [outputStream write:(const unsigned char*)encodedData.bytes maxLength:encodedData.length];
    ASSERT_FALSE(outputStream.hasSpaceAvailable);
}

TEST(NSStream, OuputStreamWithInvalidPath) {
    NSOutputStream* outputStream = [NSOutputStream outputStreamToFileAtPath:@"/home/sdsfsdfd" append:YES];
    ASSERT_EQ(NSStreamStatusNotOpen, outputStream.streamStatus);
    [outputStream open];
    ASSERT_EQ(NSStreamStatusError, outputStream.streamStatus);
}
