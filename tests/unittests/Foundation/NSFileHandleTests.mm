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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>
#import <windows.h>
#import <algorithm>

static NSString* getModulePath() {
    char fullPath[_MAX_PATH];
    GetModuleFileNameA(NULL, fullPath, _MAX_PATH);
    return [@(fullPath) stringByDeletingLastPathComponent];
}

static NSString* getPathToFile(NSString* fileName) {
    static StrongId<NSString*> refPath = getModulePath();
    return [refPath stringByAppendingPathComponent:fileName];
}

static void createFileWithContentAndVerify(NSString* fileName, NSString* content) {
    NSString* fullPath = getPathToFile(fileName);
    NSError* error = nil;
    ASSERT_TRUE([content writeToFile:fullPath atomically:NO encoding:NSUTF8StringEncoding error:&error]);
    ASSERT_EQ(nil, error);
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);
}

static void deleteFile(NSString* name) {
    NSString* fullPath = getPathToFile(name);
    if ([[NSFileManager defaultManager] fileExistsAtPath:fullPath]) {
        [[NSFileManager defaultManager] removeItemAtPath:fullPath error:nil];
    }
};

static void closeFile(NSFileHandle* handle) {
    [handle closeFile];
};

using unique_fileDeleter = std::unique_ptr<NSString, decltype(&deleteFile)>;
using unique_fileHandleCloser = std::unique_ptr<NSFileHandle, decltype(&closeFile)>;

TEST(NSFileHandle, ReadFile) {
    NSString* content = @"The Quick Brown Fox.";
    unique_fileDeleter fileName(@"NSFileHandleTestFile.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), content);

    NSString* fullPath = getPathToFile(fileName.get());
    unique_fileHandleCloser fh([NSFileHandle fileHandleForReadingAtPath:fullPath], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    NSData* fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, content, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, UpdateAndSeeks) {
    unique_fileDeleter fileName(@"FileToDeleteUpdate.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), @"0001");

    NSString* fullPath = getPathToFile(fileName.get());
    unique_fileHandleCloser fh([NSFileHandle fileHandleForUpdatingAtPath:fullPath], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    unsigned long long cursor = [fh.get() seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh.get() writeData:data];

    ASSERT_GT([fh.get() offsetInFile], cursor);
}

TEST(NSFileHandle, Offsets) {
    unique_fileDeleter fileName(@"FileToDeleteOffsets.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), @"Hello World, Hello Hello Hello Hello.");

    unique_fileHandleCloser fh([NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName.get())], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    ASSERT_EQ([fh.get() offsetInFile], 0);

    // find the full offset
    unsigned long long endCursor = [fh.get() seekToEndOfFile];
    [fh.get() seekToFileOffset:0];

    [fh.get() seekToFileOffset:5];

    ASSERT_EQ([fh.get() offsetInFile], 5);

    ASSERT_GT(endCursor, [fh.get() offsetInFile]);

    [fh.get() seekToFileOffset:(endCursor - 5)];
    ASSERT_EQ([fh.get() offsetInFile], (endCursor - 5));
}

TEST(NSFileHandle, WriteToNonExistentFileAndRead) {
    unique_fileDeleter fileName(@"FileToDelete.txt", deleteFile);
    NSString* testStr = @"testString";
    createFileWithContentAndVerify(fileName.get(), testStr);

    unique_fileHandleCloser fh([NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName.get())], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    NSData* fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, TruncateFileAtOffset) {
    unique_fileDeleter fileName(@"FileToDeleteTruncateFileAtOffset.txt", deleteFile);
    NSString* testString = @"testString001";
    NSString* content = @" Hello.";
    createFileWithContentAndVerify(fileName.get(), testString);

    unique_fileHandleCloser fh([NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName.get())], closeFile);
    ASSERT_TRUE(fh != nil);

    unsigned long long endCursor = [fh.get() seekToEndOfFile];

    NSData* data = [content dataUsingEncoding:NSUTF8StringEncoding];
    [fh.get() writeData:data];

    [fh.get() closeFile];

    // Verify Update did happen.
    fh.reset([NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName.get())]);
    NSData* fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    NSString* finalData = [NSString stringWithFormat:@"%@%@", testString, content];
    ASSERT_OBJCEQ_MSG(str, finalData, "FAILED: Unable to read the file content.");

    [fh.get() closeFile];

    // Truncate to the original file bytes

    fh.reset([NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName.get())]);
    [fh.get() truncateFileAtOffset:endCursor];
    [fh.get() closeFile];

    // Verify turncation.

    fh.reset([NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName.get())]);
    fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testString, "FAILED: Unable to read the file content.");

    [fh.get() closeFile];
}

TEST(NSFileHandle, FileHandleWithNullDevice) {
    unique_fileHandleCloser fh([NSFileHandle fileHandleWithNullDevice], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    // no-op
    [fh.get() writeData:nil];
    ASSERT_EQ([fh.get() seekToEndOfFile], 0);
    ASSERT_EQ([fh.get() offsetInFile], 0);
    ASSERT_EQ([fh.get() fileDescriptor], -1);

    NSData* data = [NSData data];

    ASSERT_OBJCEQ(data, [fh.get() readDataOfLength:1000]);
    ASSERT_OBJCEQ(data, [fh.get() readDataToEndOfFile]);
    ASSERT_OBJCEQ(data, [fh.get() availableData]);
}

TEST(NSFileHandle, ReadDataOfLength) {
    NSString* content = @"The Quick Brown Fox.";
    unique_fileDeleter fileName(@"NSFileHandleTestFile.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), content);

    NSString* fullPath = getPathToFile(fileName.get());
    unique_fileHandleCloser fh([NSFileHandle fileHandleForReadingAtPath:fullPath], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    NSData* fileData = [fh.get() readDataOfLength:9];
    ASSERT_TRUE(fileData != nil);

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick", "FAILED: Unable to read the file content.");

    // Try to read more than the max bytes.
    fileData = [fh.get() readDataOfLength:30];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @" Brown Fox.", "FAILED: Unable to read the file content.");

    // Try to read again.
    fileData = [fh.get() readDataOfLength:30000];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the file failed.");
    ASSERT_OBJCEQ(fileData, [NSData data]);
}

TEST(NSFileHandle, UpdatingURL) {
    unique_fileDeleter fileName(@"FileToDeleteUpdateUrl.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), @"0001");
    NSString* fullPath = getPathToFile(fileName.get());
    NSError* error;

    unique_fileHandleCloser fh([NSFileHandle fileHandleForUpdatingURL:[NSURL fileURLWithPath:fullPath] error:&error], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    unsigned long long cursor = [fh.get() seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh.get() writeData:data];

    ASSERT_GT([fh.get() offsetInFile], cursor);
}

TEST(NSFileHandle, ReadingFromURL) {
    NSString* content = @"The Quick Brown Fox.";
    unique_fileDeleter fileName(@"NSFileHandleTestFile.txt", deleteFile);
    createFileWithContentAndVerify(fileName.get(), content);

    NSString* fullPath = getPathToFile(fileName.get());
    NSError* error;
    unique_fileHandleCloser fh([NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error], closeFile);
    ASSERT_TRUE(fh.get() != nil);

    NSData* fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick Brown Fox.", "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, WritingAtPath) {
    unique_fileDeleter fileName(@"FileToDeleteWritingAtPath.txt", deleteFile);
    NSString* testStr = @"The Brown Fox.!";

    NSString* fullPath = getPathToFile(fileName.get());
    NSError* error;

    unique_fileHandleCloser fh([NSFileHandle fileHandleForWritingToURL:[NSURL fileURLWithPath:fullPath] error:&error], closeFile);

    ASSERT_TRUE(fh.get() != nil);

    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];
    [fh.get() writeData:data];

    [fh.get() closeFile];

    // verify file exists.
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);

    fh.reset([NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName.get())]);
    ASSERT_TRUE(fh.get() != nil);

    NSData* fileData = [fh.get() readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");
}

TEST(NSFileHandle, ReadingNonExistentFile) {
    NSString* fullPath = getPathToFile(@"nonexisting.txt");
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_TRUE(fh == nil);
    ASSERT_TRUE(error != nil);
}
