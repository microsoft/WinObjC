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
#import <Foundation/Foundation.h>
#import <windows.h>

// Needed for dirname outside of Windows
#if !TARGET_OS_WIN32
#import <libgen.h>
#endif

void testNSURLMethod(SEL selector, NSURL* input, id argument, NSURL* expected) {
    NSURL* actual = [input performSelector:selector withObject:argument];
    ASSERT_OBJCEQ_MSG(expected, actual, "FAILED: expected != actual");
}

TEST(NSURL, NSURLTests) {
    NSURL* testURL = [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"];
    NSURL* testURL2 = [[NSURL alloc] initWithString:@"http://www.test.com/"];
    NSURL* testURL3 = [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"];
    NSURL* testURL4 = [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html?Foo#24"];
    NSURL* testURL5 = [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"];
    NSURL* testURL6 = [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"];
    NSURL* testURL7 = [[NSURL alloc] initWithString:@"http://www.test.com/.foo"];

    // URLByDeletingPathExtension tests
    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    // URLByDeletingLastPathComponent
    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/../"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL5,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com../?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    // URLByStandardizingPath
    testNSURLMethod(@selector(URLByStandardizingPath), testURL4, nil, [[NSURL alloc] initWithString:@"file:///home/index.html"]);

    // URLByStandardizingPath should only work on URLs with the file: scheme - all other schemes should return a copy
    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL6, nil, [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/.foo"]);

    // URLByAppendingPathExtension
    NSString* extension = @"txt";
    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL2,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL3,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL4,
                    extension,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL5,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL6,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL7,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.foo.txt"]);

    [testURL release];
    [testURL2 release];
    [testURL3 release];
    [testURL4 release];
    [testURL5 release];
    [testURL6 release];
    [testURL7 release];
}

TEST(NSURL, StandardizedURL) {
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo"], nil, [NSURL URLWithString:@"/tmp/foo"]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/.."], nil, [NSURL URLWithString:@"/tmp"]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/../.."], nil, [NSURL URLWithString:@""]);
    testNSURLMethod(@selector(standardizedURL), [NSURL URLWithString:@"/tmp/foo/../../.."], nil, [NSURL URLWithString:@""]);
    testNSURLMethod(@selector(standardizedURL),
                    [NSURL URLWithString:@"file://~/home/../home/./index.txt?Foo#24"],
                    nil,
                    [NSURL URLWithString:@"file://~/home/index.txt?Foo#24"]);
}

TEST(NSURL, URLByAppendingPathComponent) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"."];
    NSURL* newFileURL = [fileURL URLByAppendingPathComponent:@"Hello.txt"];
    ASSERT_TRUE_MSG([newFileURL isFileURL], "The passed URL should be a file URL type");

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    fileURLString = [fileURLString stringByAppendingString:@"Hello.txt"];
    ASSERT_OBJCEQ_MSG(fileURLString, newFileURLString, "File URLs do not match!");
}

TEST(NSURL, URLByAppendingPathExtension) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"usr"];
    NSURL* newFileURL = [fileURL URLByAppendingPathExtension:@"World.txt"];
    ASSERT_TRUE_MSG([newFileURL isFileURL], "The passed URL should be a file URL type");

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    fileURLString = [fileURLString stringByAppendingString:@".World.txt"];
    ASSERT_OBJCEQ_MSG(fileURLString, newFileURLString, "File URLs do not match!");
}

TEST(NSURL, CheckResourceIsReachable) {
    // construct target URL using current directory and relative URL
    // get test startup full path
    wchar_t startUpPath[_MAX_PATH];
    GetModuleFileNameW(nullptr, startUpPath, _MAX_PATH);

// File systems differ between platforms - Windows needs separate handling for drive character, etc
#if TARGET_OS_WIN32
    // construct the start up dir
    wchar_t drive[_MAX_DRIVE];
    wchar_t dir[_MAX_DIR];
    ASSERT_TRUE(::_wsplitpath_s(startUpPath, drive, _countof(drive), dir, _countof(dir), nullptr, 0, nullptr, 0) == 0);
    ASSERT_TRUE(::_wmakepath_s(startUpPath, _countof(startUpPath), drive, dir, L"", L"") == 0);

    // change current dir to app start up path
    ASSERT_TRUE(SetCurrentDirectoryW(startUpPath) != 0);
#else
    char tempBuffer[_MAX_PATH];
    wcstombs(tempBuffer, startUpPath, _MAX_PATH);

    ASSERT_TRUE(chdir(dirname(tempBuffer)) == 0);
#endif

    NSFileManager* manager = [NSFileManager defaultManager];
    NSURL* baseURL = [NSURL fileURLWithPath:[manager currentDirectoryPath]];
    NSURL* targetURL = [NSURL URLWithString:@"data/NSFileManagerUT.txt" relativeToURL:baseURL];
    ASSERT_TRUE_MSG([targetURL checkResourceIsReachableAndReturnError:nullptr], "The target URL %@ exists", targetURL);

    NSURL* targetURLNonExist = [NSURL URLWithString:@"data/foo.txt" relativeToURL:baseURL];
    ASSERT_FALSE_MSG([targetURLNonExist checkResourceIsReachableAndReturnError:nullptr],
                     "The target %@URL does not exist",
                     targetURLNonExist);
}

TEST(NSURL, GetFileSystemRepresentation) {
    NSURL* url = [NSURL fileURLWithPath:@"Hello.txt"];
    ASSERT_OBJCNE(url, nil);

    size_t pathMax = 4096;

    char resultPath[pathMax];
    ASSERT_TRUE([url getFileSystemRepresentation:resultPath maxLength:pathMax]);

    char baseResultPath[pathMax];
    ASSERT_TRUE([url.baseURL getFileSystemRepresentation:baseResultPath maxLength:pathMax]);
    NSString* expectedPath = [NSString stringWithFormat:@"%s/Hello.txt", baseResultPath];
    NSString* nsResultPath = [NSString stringWithFormat:@"%s", resultPath];
    ASSERT_OBJCEQ(expectedPath, nsResultPath);
}

TEST(NSURL, Port) {
    ASSERT_OBJCEQ(nil, [NSURL URLWithString:@"http://www.foo.com"].port);
    ASSERT_OBJCEQ(@5500, [NSURL URLWithString:@"http://www.foo.com:5500"].port);
}

TEST(NSURL, Copy) {
    NSURL* url = [NSURL URLWithString:@"http://localhost/home/home/../index.txt?Foo#24"];
    NSURL* urlCopy = [[url copy] autorelease];

    ASSERT_OBJCEQ(url, urlCopy);
}

TEST(NSURL, BridgedCast) {
    {
        CFURLRef url = CFURLCreateWithString(kCFAllocatorDefault, CFSTR("http://www.foo.com/index.txt?Foo#24"), nullptr);
        ASSERT_OBJCEQ([NSURL URLWithString:@"http://www.foo.com/index.txt?Foo#24"], (__bridge NSURL*)url);
        CFRelease(url);
    }

    {
        NSURL* url = [NSURL fileURLWithPath:@"Hello.txt"];
        CFURLRef expected = CFURLCreateWithFileSystemPath(kCFAllocatorDefault, CFSTR("Hello.txt"), kCFURLWindowsPathStyle, false);
        ASSERT_EQ(kCFCompareEqualTo,
                  CFStringCompare(CFURLGetString(expected), CFURLGetString((__bridge CFURLRef)url), static_cast<CFStringCompareFlags>(0)));
        CFRelease(expected);
    }
}

TEST(NSURL, NonLatin) {
    NSString* pathAsString = @"/temp/hello/world/中文/你好.txt";
    NSURL* pathAsURL = [NSURL fileURLWithPath:pathAsString];
    ASSERT_OBJCEQ(pathAsString, pathAsURL.path);
}