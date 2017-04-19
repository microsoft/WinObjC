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

#include <sys/types.h>
#include <sys/stat.h>
#include <TestFramework.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <Foundation/Foundation.h>
#include <stdlib.h>
#include <windows.h>
#include <Starboard/SmartTypes.h>
#include "TestUtils.h"

TEST(NSFileManager, GetAttributes) {
    NSString* testFileFullPath =
        [[NSString stringWithUTF8String:GetCurrentTestDirectory().c_str()] stringByAppendingPathComponent:@"/data/NSFileManagerUT.txt"];

    LOG_INFO("this test try to validate file creation date and modification date and size for %@", testFileFullPath);
    NSFileManager* manager = [NSFileManager defaultManager];
    ASSERT_TRUE_MSG([manager fileExistsAtPath:testFileFullPath], "Failed: file %@ does not exist", testFileFullPath);

    NSDictionary* attributes = [manager fileAttributesAtPath:testFileFullPath traverseLink:YES];
    ASSERT_TRUE_MSG(attributes != nil, "failed to get file attributes for %@", testFileFullPath);

// Get file attributes from OS-side
// _stat and _wstat are MS extensions
#if TARGET_OS_WIN32
    struct _stat fileStatus = { 0 };
    ASSERT_TRUE(::_stat([testFileFullPath UTF8String], &fileStatus) == 0);
#else
    struct stat fileStatus = { 0 };
    ASSERT_TRUE(stat([testFileFullPath UTF8String], &fileStatus) == 0);
#endif

    // check file creation date
    NSDate* expectedCreationDate = [NSDate dateWithTimeIntervalSince1970:(double)fileStatus.st_ctime];
    NSDate* creationDate = [attributes fileCreationDate];
    ASSERT_TRUE_MSG(creationDate != nil, "failed to get creation date for %@", testFileFullPath);
    ASSERT_OBJCEQ_MSG(expectedCreationDate, creationDate, "failed to check creation date for %@", testFileFullPath);

    // check file modification date
    NSDate* expectedModificationDate = [NSDate dateWithTimeIntervalSince1970:fileStatus.st_mtime];
    NSDate* modificationDate = [attributes fileModificationDate];
    ASSERT_TRUE_MSG(modificationDate != nil, "failed to get ModificationDate for %@", testFileFullPath);
    ASSERT_OBJCEQ_MSG(expectedModificationDate, modificationDate, "failed to check modification date for %@", testFileFullPath);

    // now check file size
    ASSERT_EQ_MSG(fileStatus.st_size, static_cast<long>([attributes fileSize]), "failed to check file size for %@", testFileFullPath);
}

TEST(NSFileManager, EnumateDirectoryUsingURL) {
    NSFileManager* manager = [NSFileManager defaultManager];
    NSString* originalPath = [manager currentDirectoryPath];

    // get test startup full path
    wchar_t startUpPath[_MAX_PATH];
    auto fullPath = GetCurrentTestDirectory();
    std::mbstowcs(startUpPath, fullPath.c_str(), _MAX_PATH);

    std::wstring startUpDir(startUpPath);
    ASSERT_TRUE(SetCurrentDirectoryW(startUpDir.c_str()) != 0);

    wchar_t currentDir[_MAX_PATH];
    DWORD ret = GetCurrentDirectoryW(_MAX_PATH, currentDir);
    ASSERT_TRUE(ret > 0 && ret < _MAX_PATH);

    // OSX wchar_t's are twice as wide
    LOG_INFO("Change current dir to:%@",
#if TARGET_OS_WIN32
             [NSString stringWithCharacters:(const unichar*)currentDir length:ret]);
#else
             [NSString stringWithBytes:currentDir length:sizeof(wchar_t) * ret encoding:WCHAR_ENCODING]);
#endif

    // construct target URL using current directory and relative URL
    NSURL* baseURL = [NSURL fileURLWithPath:[manager currentDirectoryPath]];
    NSURL* targetURL = [NSURL URLWithString:@"data/" relativeToURL:baseURL];

    // enumerate target URL
    NSArray* urlContents = [manager contentsOfDirectoryAtURL:targetURL
                                  includingPropertiesForKeys:[NSArray arrayWithObject:NSURLContentModificationDateKey]
                                                     options:(NSDirectoryEnumerationOptions)0
                                                       error:nullptr];

    ASSERT_NE(NSNotFound, [urlContents indexOfObjectPassingTest:^(NSURL* obj, NSUInteger idx, BOOL* stop) {
                  // break file URL into components, get last object of it - which is the file name, and verify name is the expected
                  return [[[obj pathComponents] lastObject] isEqualToString:@"NSFileManagerUT.txt"];
              }]);

    // construct file path for target file and get its attrbutes from windows side
    wchar_t targetFileFullPath[_MAX_PATH];

// wcscpy_s and wcscat_s are MSVC extensions
#if TARGET_OS_WIN32
    ASSERT_TRUE(wcscpy_s(targetFileFullPath, _countof(targetFileFullPath), currentDir) == 0);
    ASSERT_TRUE(wcscat_s(targetFileFullPath, _countof(targetFileFullPath), L"\\data\\NSFileManagerUT.txt") == 0);
#else
    ASSERT_NE(nullptr, wcscpy(targetFileFullPath, currentDir));
    ASSERT_NE(nullptr, wcscat(targetFileFullPath, L"/data/NSFileManagerUT.txt"));
#endif

// _stat and _wstat are MS extensions
#if TARGET_OS_WIN32
    struct _stat fileStatus = { 0 };
    ASSERT_TRUE(::_wstat(targetFileFullPath, &fileStatus) == 0);
#else
    struct stat fileStatus = { 0 };
    char narrowFullPath[_MAX_PATH];
    wcstombs(narrowFullPath, targetFileFullPath, _MAX_PATH);
    ASSERT_TRUE(stat(narrowFullPath, &fileStatus) == 0);
#endif

    // TODO: 7491194: Implement CFURL resourceValue APIs
    // check NSURL resourceValue of NSURLContentModificationDateKey is the same as file modification date
    // NSDate* expectedModificationDate = [NSDate dateWithTimeIntervalSince1970:fileStatus.st_mtime];
    // id value;
    // [targetFileURL getResourceValue:&value forKey:NSURLContentModificationDateKey error:nil];
    // NSDate* actualModificationDate = static_cast<NSDate*>(value);
    // ASSERT_TRUE_MSG(actualModificationDate != nil, "failed to get ModificationDate from %@", targetFileURL);
    // ASSERT_OBJCEQ_MSG(expectedModificationDate, actualModificationDate, "failed to check modification date for %@", targetFileURL);

    ASSERT_TRUE([manager changeCurrentDirectoryPath:originalPath]);
}

TEST(NSFileManager, ChangeDirectory) {
    NSFileManager* manager = [NSFileManager defaultManager];
    NSString* originalPath = [manager currentDirectoryPath];
    NSString* newPath = [originalPath stringByAppendingPathComponent:@"TestCWD"];

    [manager createDirectoryAtPath:newPath withIntermediateDirectories:NO attributes:nullptr error:nullptr];
    ASSERT_TRUE([manager changeCurrentDirectoryPath:newPath]);

    NSString* currentPath = [manager currentDirectoryPath];
    ASSERT_OBJCNE_MSG(originalPath, currentPath, "Expected change in current directory");
    ASSERT_OBJCEQ_MSG(newPath, currentPath, "Expected current directory to change to newPath");

    ASSERT_TRUE([manager changeCurrentDirectoryPath:originalPath]);
    [manager removeItemAtPath:newPath error:nullptr];
}

TEST(NSFileManager, MoveFileViaPath) {
    NSString* srcName = @"NSFileManagerMoveTestFilePath.txt";
    NSString* destName = @"MovedFilePath.txt";

    SCOPE_DELETE_FILE(srcName);
    SCOPE_DELETE_FILE(destName);

    NSString* content = @"The Quick Brown Fox.";
    createFileWithContentAndVerify(srcName, content);

    NSString* srcPath = getPathToFile(srcName);
    NSString* destPath = getPathToFile(destName);

    NSFileManager* manager = [NSFileManager defaultManager];

    NSError* error = nil;
    BOOL status = [manager moveItemAtPath:srcPath toPath:destPath error:&error];
    ASSERT_TRUE(status);
    EXPECT_EQ(nil, error);

    // Verify file exists.
    ASSERT_TRUE([manager fileExistsAtPath:destPath]);
    EXPECT_FALSE([manager fileExistsAtPath:srcPath]);

    // Verify data.
    ASSERT_OBJCEQ([content dataUsingEncoding:NSUTF8StringEncoding], [NSData dataWithContentsOfFile:destPath]);
}

TEST(NSFileManager, MoveFileViaURL) {
    NSString* srcName = @"NSFileManagerMoveTestFileURL.txt";
    NSString* destName = @"MovedFileURL.txt";
    SCOPE_DELETE_FILE(srcName);
    SCOPE_DELETE_FILE(destName);

    NSString* content = @"The Quick Brown Fox.";
    createFileWithContentAndVerify(srcName, content);

    NSURL* srcURL = [NSURL fileURLWithPath:getPathToFile(srcName)];
    NSURL* destURL = [NSURL fileURLWithPath:getPathToFile(destName)];

    NSFileManager* manager = [NSFileManager defaultManager];

    NSError* error = nil;
    BOOL status = [manager moveItemAtURL:srcURL toURL:destURL error:&error];
    ASSERT_TRUE(status);
    EXPECT_EQ(nil, error);

    // Verify file exists.
    ASSERT_TRUE([manager fileExistsAtPath:[destURL path]]);
    EXPECT_FALSE([manager fileExistsAtPath:[srcURL path]]);

    // Verify data.
    ASSERT_OBJCEQ([content dataUsingEncoding:NSUTF8StringEncoding], [NSData dataWithContentsOfURL:destURL]);
}

TEST(NSFileManager, DirectoryWithUTF16Chars) {
    NSString* directoryName = @"oÖo winobjc";
    NSString* testPath = getPathToFile(directoryName);

    EXPECT_TRUE([[NSFileManager defaultManager] createDirectoryAtPath:testPath attributes:nil]);
    EXPECT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:testPath]);
    EXPECT_TRUE([[NSFileManager defaultManager] removeItemAtPath:testPath error:nil]);
    EXPECT_FALSE([[NSFileManager defaultManager] fileExistsAtPath:testPath]);
}
