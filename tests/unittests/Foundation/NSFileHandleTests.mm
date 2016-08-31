//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <Foundation/Foundation.h>
#import <windows.h>
#import <algorithm>
#import "TestUtils.h"

TEST(NSFileHandle, ReadFile) {
    NSString* content = @"The Quick Brown Fox.";
    NSString* fileName = @"NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);
    SCOPE_DELETE_FILE(fileName);

    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:fullPath];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, content, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, UpdateAndSeeks) {
    NSString* fileName = @"FileToDeleteUpdate.txt";
    createFileWithContentAndVerify(fileName, @"0001");
    SCOPE_DELETE_FILE(fileName);

    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingAtPath:fullPath];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    unsigned long long cursor = [fh seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh writeData:data];

    ASSERT_GT([fh offsetInFile], cursor);
}

TEST(NSFileHandle, Offsets) {
    NSString* fileName = @"FileToDeleteOffsets.txt";
    createFileWithContentAndVerify(fileName, @"Hello World, Hello Hello Hello Hello.");
    SCOPE_DELETE_FILE(fileName);

    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);

    ASSERT_NE(fh, nil);

    ASSERT_EQ([fh offsetInFile], 0);

    // find the full offset
    unsigned long long endCursor = [fh seekToEndOfFile];
    [fh seekToFileOffset:0];

    [fh seekToFileOffset:5];

    ASSERT_EQ([fh offsetInFile], 5);

    ASSERT_GT(endCursor, [fh offsetInFile]);

    [fh seekToFileOffset:(endCursor - 5)];
    ASSERT_EQ([fh offsetInFile], (endCursor - 5));
}

TEST(NSFileHandle, WriteToNonExistentFileAndRead) {
    NSString* fileName = @"FileToDelete.txt";
    NSString* testStr = @"testString";
    createFileWithContentAndVerify(fileName, testStr);
    SCOPE_DELETE_FILE(fileName);

    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, TruncateFileAtOffset) {
    NSString* fileName = @"FileToDeleteTruncateFileAtOffset.txt";
    NSString* testString = @"testString001";
    NSString* content = @" Hello.";
    createFileWithContentAndVerify(fileName, testString);
    SCOPE_DELETE_FILE(fileName);

    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    unsigned long long endCursor = [fh seekToEndOfFile];

    NSData* data = [content dataUsingEncoding:NSUTF8StringEncoding];
    [fh writeData:data];

    [fh closeFile];

    // Verify Update did happen.
    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    NSString* finalData = [NSString stringWithFormat:@"%@%@", testString, content];
    ASSERT_OBJCEQ_MSG(str, finalData, "FAILED: Unable to read the file content.");

    [fh closeFile];

    // Truncate to the original file bytes

    fh = [NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    [fh truncateFileAtOffset:endCursor];
    [fh closeFile];

    // Verify turncation.

    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testString, "FAILED: Unable to read the file content.");

    [fh closeFile];
}

TEST(NSFileHandle, FileHandleWithNullDevice) {
    NSFileHandle* fh = [NSFileHandle fileHandleWithNullDevice];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    // no-op
    [fh writeData:nil];
    ASSERT_EQ([fh seekToEndOfFile], 0);
    ASSERT_EQ([fh offsetInFile], 0);
    ASSERT_EQ([fh fileDescriptor], -1);

    NSData* data = [NSData data];

    ASSERT_OBJCEQ(data, [fh readDataOfLength:1000]);
    ASSERT_OBJCEQ(data, [fh readDataToEndOfFile]);
    ASSERT_OBJCEQ(data, [fh availableData]);
}

TEST(NSFileHandle, ReadDataOfLength) {
    NSString* content = @"The Quick Brown Fox.";
    NSString* fileName = @"NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);
    SCOPE_DELETE_FILE(fileName);

    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:fullPath];
    SCOPE_CLOSE_HANDLE(fh);

    ASSERT_NE(fh, nil);

    NSData* fileData = [fh readDataOfLength:9];
    ASSERT_NE(fileData, nil);

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick", "FAILED: Unable to read the file content.");

    // Try to read more than the max bytes.
    fileData = [fh readDataOfLength:30];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @" Brown Fox.", "FAILED: Unable to read the file content.");

    // Try to read again.
    fileData = [fh readDataOfLength:30000];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the file failed.");
    ASSERT_OBJCEQ(fileData, [NSData data]);
}

TEST(NSFileHandle, UpdatingURL) {
    NSString* fileName = @"FileToDeleteUpdateUrl.txt";
    createFileWithContentAndVerify(fileName, @"0001");
    SCOPE_DELETE_FILE(fileName);
    NSString* fullPath = getPathToFile(fileName);
    NSError* error;

    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingURL:[NSURL fileURLWithPath:fullPath] error:&error];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    unsigned long long cursor = [fh seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh writeData:data];

    ASSERT_GT([fh offsetInFile], cursor);
}

TEST(NSFileHandle, ReadingFromURL) {
    NSString* content = @"The Quick Brown Fox.";
    NSString* fileName = @"NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);
    SCOPE_DELETE_FILE(fileName);

    NSString* fullPath = getPathToFile(fileName);
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick Brown Fox.", "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, WritingAtPath) {
    NSString* fileName = @"FileToDeleteWritingAtPath.txt";
    NSString* testStr = @"The Brown Fox.!";
    createFileWithContentAndVerify(fileName, @"");
    NSString* fullPath = getPathToFile(fileName);
    NSError* error;

    SCOPE_DELETE_FILE(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForWritingToURL:[NSURL fileURLWithPath:fullPath] error:&error];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];
    [fh writeData:data];

    [fh closeFile];

    // verify file exists.
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);

    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    SCOPE_CLOSE_HANDLE(fh);
    ASSERT_NE(fh, nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_NE_MSG(fileData, nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, ReadingNonExistentFile) {
    NSString* fullPath = getPathToFile(@"nonexisting.txt");
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_EQ(fh, nil);
    ASSERT_NE(error, nil);
}
