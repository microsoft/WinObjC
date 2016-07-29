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

#import <windows.h>
#import <algorithm>

NSString* getPathToFile(char const* filePath) {
    size_t i = 0;
    char fullPath[_MAX_PATH];
    int len = GetModuleFileNameA(NULL, fullPath, _MAX_PATH);

// Path separator characters differ between platforms
#if TARGET_OS_WIN32
    const char slashChar = '\\';
#else
    const char slashChar = '/';
#endif

    char* ptrToLastEntry = strrchr(fullPath, slashChar);
    int lengthOfLastEntry = strlen(ptrToLastEntry);

    size_t destSize = _MAX_PATH - (len - lengthOfLastEntry);
    size_t srcSize = strlen(filePath) + 1;

// strncpy_s is a MSVC extension
#if TARGET_OS_WIN32
    strncpy_s(ptrToLastEntry, destSize, filePath, srcSize);
#else
    strncpy(ptrToLastEntry, filePath, std::min(destSize, srcSize));
#endif

    return [NSString stringWithFormat:@"%s", fullPath];
}

void createFileWithContentAndVerify(char const* filePath, NSString* content) {
    NSString* fullPath = getPathToFile(filePath);
    NSFileHandle* fh = [NSFileHandle fileHandleForWritingAtPath:fullPath];
    ASSERT_TRUE(fh != nil);

    if (content) {
        NSData* data = [content dataUsingEncoding:NSUTF8StringEncoding];
        [fh writeData:data];
    }

    [fh closeFile];

    // verify file exists.
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);
}

void deleteFile(char const* filePath) {
    NSError* error;
    ASSERT_TRUE_MSG([[NSFileManager defaultManager] removeItemAtPath:getPathToFile(filePath) error:&error],
                    "FAILED:Unable to delete the test file.");
    ASSERT_OBJCEQ(error, nil);
}

TEST(NSFileHandle, Init) {
    ASSERT_TRUE_MSG([[[NSFileHandle alloc] init] autorelease] != nil, "FAILED: alloc/init failed.");
}

TEST(NSFileHandle, ReadFile) {
    NSString* content = @"The Quick Brown Fox.";
    char const* fileName = "\\NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);

    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:fullPath];
    ASSERT_TRUE(fh != nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, content, "FAILED: Unable to read the file content.");

    [fh closeFile];

    deleteFile(fileName);
}

TEST(NSFileHandle, UpdateAndSeeks) {
    char const* fileName = "\\FileToDeleteUpdate.txt";
    createFileWithContentAndVerify(fileName, @"0001");
    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingAtPath:fullPath];
    ASSERT_TRUE(fh != nil);

    unsigned long long cursor = [fh seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh writeData:data];

    ASSERT_GT([fh offsetInFile], cursor);

    [fh closeFile];

    deleteFile(fileName);
}

TEST(NSFileHandle, Offsets) {
    char const* fileName = "\\FileToDeleteOffsets.txt";
    createFileWithContentAndVerify(fileName, @"Hello World, Hello Hello Hello Hello.");

    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    ASSERT_TRUE(fh != nil);

    ASSERT_EQ([fh offsetInFile], 0);

    // find the full offset
    unsigned long long endCursor = [fh seekToEndOfFile];
    [fh seekToFileOffset:0];

    [fh seekToFileOffset:5];

    ASSERT_EQ([fh offsetInFile], 5);

    ASSERT_GT(endCursor, [fh offsetInFile]);

    [fh seekToFileOffset:(endCursor - 5)];
    ASSERT_EQ([fh offsetInFile], (endCursor - 5));

    [fh closeFile];
    deleteFile(fileName);
}

TEST(NSFileHandle, WriteToNonExistentFileAndRead) {
    char const* fileName = "\\FileToDelete.txt";
    NSString* testStr = @"testString";
    createFileWithContentAndVerify(fileName, testStr);

    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    ASSERT_TRUE(fh != nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");

    [fh closeFile];

    // Delete the file
    deleteFile(fileName);
}

TEST(NSFileHandle, TruncateFileAtOffset) {
    char const* fileName = "\\FileToDeleteTruncateFileAtOffset.txt";
    NSString* testString = @"testString001";
    NSString* content = @" Hello.";
    createFileWithContentAndVerify(fileName, testString);

    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName)];
    ASSERT_TRUE(fh != nil);

    unsigned long long endCursor = [fh seekToEndOfFile];

    NSData* data = [content dataUsingEncoding:NSUTF8StringEncoding];
    [fh writeData:data];

    [fh closeFile];

    // Verify Update did happen.
    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    NSString* finalData = [NSString stringWithFormat:@"%@%@", testString, content];
    ASSERT_OBJCEQ_MSG(str, finalData, "FAILED: Unable to read the file content.");

    [fh closeFile];

    // Truncate to the original file bytes

    fh = [NSFileHandle fileHandleForUpdatingAtPath:getPathToFile(fileName)];
    [fh truncateFileAtOffset:endCursor];
    [fh closeFile];

    // Verify turncation.

    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testString, "FAILED: Unable to read the file content.");

    [fh closeFile];

    // Delete the file
    deleteFile(fileName);
}

TEST(NSFileHandle, FileHandleWithNullDevice) {
    NSFileHandle* fh = [NSFileHandle fileHandleWithNullDevice];
    ASSERT_TRUE(fh != nil);

    // no-op
    [fh writeData:nil];
    ASSERT_EQ([fh seekToEndOfFile], 0);
    ASSERT_EQ([fh offsetInFile], 0);
    ASSERT_EQ([fh fileDescriptor], -1);

    NSData* data = [NSData data];

    ASSERT_OBJCEQ(data, [fh readDataOfLength:1000]);
    ASSERT_OBJCEQ(data, [fh readDataToEndOfFile]);
    ASSERT_OBJCEQ(data, [fh availableData]);

    [fh closeFile];
}

TEST(NSFileHandle, ReadDataOfLength) {
    NSString* content = @"The Quick Brown Fox.";
    char const* fileName = "\\NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);

    NSString* fullPath = getPathToFile(fileName);
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingAtPath:fullPath];
    ASSERT_TRUE(fh != nil);

    NSData* fileData = [fh readDataOfLength:9];
    ASSERT_TRUE(fileData != nil);

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick", "FAILED: Unable to read the file content.");

    // Try to read more than the max bytes.
    fileData = [fh readDataOfLength:30];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the file failed.");

    str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @" Brown Fox.", "FAILED: Unable to read the file content.");

    // Try to read again.
    fileData = [fh readDataOfLength:30000];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the file failed.");
    ASSERT_OBJCEQ(fileData, [NSData data]);

    [fh closeFile];
    deleteFile(fileName);
}

TEST(NSFileHandle, UpdatingURL) {
    char const* fileName = "\\FileToDeleteUpdateUrl.txt";
    createFileWithContentAndVerify(fileName, @"0001");
    NSString* fullPath = getPathToFile(fileName);
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForUpdatingURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_TRUE(fh != nil);

    unsigned long long cursor = [fh seekToEndOfFile];

    ASSERT_GT(cursor, 0);

    NSString* testStr = @"teststring";
    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];

    [fh writeData:data];

    ASSERT_GT([fh offsetInFile], cursor);

    [fh closeFile];

    deleteFile(fileName);
}

TEST(NSFileHandle, ReadingFromURL) {
    NSString* content = @"The Quick Brown Fox.";
    char const* fileName = "\\NSFileHandleTestFile.txt";
    createFileWithContentAndVerify(fileName, content);

    NSString* fullPath = getPathToFile(fileName);
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_TRUE(fh != nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, @"The Quick Brown Fox.", "FAILED: Unable to read the file content.");

    [fh closeFile];
    deleteFile(fileName);
}

TEST(NSFileHandle, WritingAtPath) {
    char const* fileName = "\\FileToDeleteWritingAtPath.txt";
    NSString* testStr = @"The Brown Fox.!";

    NSString* fullPath = getPathToFile(fileName);
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForWritingToURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_TRUE(fh != nil);

    NSData* data = [testStr dataUsingEncoding:NSUTF8StringEncoding];
    [fh writeData:data];

    [fh closeFile];

    // verify file exists.
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:fullPath]);

    fh = [NSFileHandle fileHandleForReadingAtPath:getPathToFile(fileName)];
    ASSERT_TRUE(fh != nil);

    NSData* fileData = [fh readDataToEndOfFile];
    ASSERT_TRUE_MSG(fileData != nil, "FAILED: reading the entire file failed.");

    NSString* str = [[[NSString alloc] initWithData:fileData encoding:NSUTF8StringEncoding] autorelease];
    ASSERT_OBJCEQ_MSG(str, testStr, "FAILED: Unable to read the file content.");

    [fh closeFile];

    // Delete the file
    deleteFile(fileName);
}

TEST(NSFileHandle, ReadingNonExistentFile) {
    NSString* fullPath = getPathToFile("\\nonexisting.txt");
    NSError* error;
    NSFileHandle* fh = [NSFileHandle fileHandleForReadingFromURL:[NSURL fileURLWithPath:fullPath] error:&error];
    ASSERT_TRUE(fh == nil);
    ASSERT_TRUE(error != nil);
}
