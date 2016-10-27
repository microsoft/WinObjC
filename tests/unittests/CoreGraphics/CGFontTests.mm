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
#import <CoreGraphics/CoreGraphics.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

// CTFont functionality is generally a superset of CGFont functionality, and hits the same code path
// Thus, CTFont unit tests can also be thought of as CGFont test coverage

static const CFStringRef c_arialBoldItalicName = CFSTR("Arial-BoldItalicMT");
static const CFStringRef c_arialItalicName = CFSTR("Arial-ItalicMT");
static const CFStringRef c_courierNewItalicName = CFSTR("CourierNewPS-ItalicMT");

TEST(CGFont, GetFontBBox) {
    // Windows font bounding boxes differ from ref plat's in 'interesting' but inconsistent ways
    // Best hypothesis: Windows has different versions of the same fonts
    CGFontRef font = CGFontCreateWithFontName(c_arialBoldItalicName);
    CFAutorelease(font);
    CGRect box = CGFontGetFontBBox(font);

    // Eg: for Arial Bold Italic, origin is correct, but width and height are slightly off from ref plat (but in the right neighborhood)
    EXPECT_EQ(-1146, box.origin.x);
    EXPECT_EQ(-771, box.origin.y);
#if TARGET_OS_WIN32
    EXPECT_EQ(3993, box.size.width);
    EXPECT_EQ(2855, box.size.height);
#else
    EXPECT_EQ(4196, box.size.width);
    EXPECT_EQ(2820, box.size.height);
#endif

    font = CGFontCreateWithFontName(c_arialItalicName);
    CFAutorelease(font);
    box = CGFontGetFontBBox(font);

    // For Arial Italic, only width is off from ref plat (but still in the right neighborhood)
    EXPECT_EQ(-1059, box.origin.x);
    EXPECT_EQ(-665, box.origin.y);
    EXPECT_EQ(2708, box.size.height);
#if TARGET_OS_WIN32
    EXPECT_EQ(3842, box.size.width);
#else
    EXPECT_EQ(3884, box.size.width);
#endif

    font = CGFontCreateWithFontName(c_courierNewItalicName);
    CFAutorelease(font);
    box = CGFontGetFontBBox(font);

// For Courier New Italic, both horizontal attributes are off by exactly 115, and both vertical attributes are off by exactly 9
#if TARGET_OS_WIN32
    EXPECT_EQ(-138, box.origin.x);
    EXPECT_EQ(-570, box.origin.y);
    EXPECT_EQ(1777, box.size.width);
    EXPECT_EQ(2619, box.size.height);
#else
    EXPECT_EQ(-253, box.origin.x);
    EXPECT_EQ(-561, box.origin.y);
    EXPECT_EQ(1892, box.size.width);
    EXPECT_EQ(2610, box.size.height);
#endif

    // To reiterate, best guess at an explanation is that Windows has a different version of the same fonts with minor adjustments
    // Eg: a few extra glyphs, a scale up/down
}

TEST(CGFont, GetBoundingBoxes) {
    CGFontRef font = CGFontCreateWithFontName(c_arialBoldItalicName);
    CFAutorelease(font);

    const size_t count = 6;
    CGGlyph glyphs[count] = { 68, 40, 22, 23, 7, 120 };

    CGRect expectedBoxes[count] = {
        { { 92, -25 }, { 1000, 1112 } }, { { 84, 0 }, { 1393, 1466 } },    { { 104, -25 }, { 1043, 1497 } },
        { { 56, 0 }, { 1091, 1466 } },   { { 90, -203 }, { 1090, 1780 } }, { { 86, 0 }, { 1125, 1455 } },
    };
    CGRect boxes[count];

    CGFontGetGlyphBBoxes(font, glyphs, count, boxes);

    for (size_t i = 0; i < count; ++i) {
        EXPECT_EQ(expectedBoxes[i].origin.x, boxes[i].origin.x);
        EXPECT_EQ(expectedBoxes[i].origin.y, boxes[i].origin.y);
        EXPECT_EQ(expectedBoxes[i].size.width, boxes[i].size.width);
        EXPECT_EQ(expectedBoxes[i].size.height, boxes[i].size.height);
    }
}

TEST(CGFont, CreateWithDataProvider) {
    // get test startup full path
    wchar_t fullPath[_MAX_PATH];
    size_t len = GetModuleFileNameW(NULL, fullPath, _MAX_PATH);

// Window needs extra handling for the drive character, OSX has twice-as-wide wchars
#if TARGET_OS_WIN32
    // split test startup full path into components like drive, directory, filename and ext etc.
    wchar_t drive[_MAX_DRIVE];
    wchar_t dir[_MAX_DIR];
    ASSERT_TRUE(::_wsplitpath_s(fullPath, drive, _countof(drive), dir, _countof(dir), NULL, 0, NULL, 0) == 0);

    // reconstruct fullpath for test artifact file. e.g., C:\WinObjc\WinObjC\build\Debug\data\NSFileManagerUT.txt
    ASSERT_TRUE(wcscat_s(dir, _countof(dir), L"\\data\\") == 0);
    ASSERT_TRUE(::_wmakepath_s(fullPath, _countof(fullPath), drive, dir, L"MSNeoGothic", L".ttf") == 0);

    NSString* testFileFullPath = [NSString stringWithCharacters:(const unichar*)fullPath length:len + 1];
#else
    NSString* testFileFullPath = [NSString stringWithBytes:fullPath length:sizeof(wchar_t) * len encoding:WCHAR_ENCODING];

    // reconstruct fullpath for test artifact file. e.g., /Volumes/WinObjC/build/Tests/UnitTests/Foundation/OSX/data/NSFileManagerUT.txt
    testFileFullPath = [[testFileFullPath stringByDeletingLastPathComponent] stringByAppendingString:@"/data/MSNeoGothic.ttf"];
#endif

    NSURL* testFileURL = [NSURL fileURLWithPath:testFileFullPath];

    CGDataProviderRef dataProvider = CGDataProviderCreateWithURL((__bridge CFURLRef)testFileURL);
    CFAutorelease(dataProvider);

    CGFontRef font = CGFontCreateWithDataProvider(dataProvider);
    CFAutorelease(font);

    // Check some very basic properties to make sure that the right font was loaded
    EXPECT_OBJCEQ((id)CFSTR("Microsoft NeoGothic"), (id)CFAutorelease(CGFontCopyFullName(font)));
    EXPECT_EQ(2210, CGFontGetAscent(font));
#if TARGET_OS_WIN32
    EXPECT_EQ(514, CGFontGetDescent(font));
#else
    EXPECT_EQ(-514, CGFontGetDescent(font));
#endif

    // Validate that creating a second time will still work (IDWriteFactory has some finnickiness regarding this)
    CGFontRef font2 = CGFontCreateWithDataProvider(dataProvider);
    CFAutorelease(font2);
    EXPECT_OBJCEQ((id)CFSTR("Microsoft NeoGothic"), (id)CFAutorelease(CGFontCopyFullName(font2)));
}
TEST(CGFont, GetDescent) {
    CGFontRef font = CGFontCreateWithFontName(c_arialBoldItalicName);
    CFAutorelease(font);
    EXPECT_EQ(-434, CGFontGetDescent(font));
}