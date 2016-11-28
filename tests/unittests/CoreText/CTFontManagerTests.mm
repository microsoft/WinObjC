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

#include <TestFramework.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <Starboard/SmartTypes.h>

NSURL* __GetRelativeURL(NSString* relativePath) {
    static char fullPath[_MAX_PATH];
    static int unused = [](char* path) { return GetModuleFileNameA(NULL, path, _MAX_PATH); }(fullPath);
    return [NSURL fileURLWithPath:[[@(fullPath) stringByDeletingLastPathComponent] stringByAppendingPathComponent:relativePath]];
}

TEST(CTFontManager, ShouldBeAbleToRegisterFontsForURL) {
    NSURL* testFileURL = __GetRelativeURL(@"/data/WinObjC.ttf");
    CFErrorRef error = nullptr;
    EXPECT_TRUE(CTFontManagerRegisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, &error));
    EXPECT_EQ(nullptr, error);
    woc::unique_cf<CTFontRef> font{ CTFontCreateWithName(CFSTR("WinObjC"), 20, nullptr) };
    EXPECT_NE(nullptr, font);

    StrongId<NSString> familyName = (NSString*)CTFontCopyFamilyName(font.get());
    EXPECT_OBJCEQ(@"WinObjC", familyName);

    EXPECT_TRUE(CTFontManagerUnregisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, &error));
    EXPECT_EQ(nullptr, error);

    woc::unique_cf<CTFontRef> failedFont{ CTFontCreateWithName(CFSTR("WinObjC"), 20, nullptr) };
    EXPECT_NE(nullptr, failedFont);

    familyName = (NSString*)CTFontCopyFullName(failedFont.get());
    EXPECT_OBJCEQ(@"Segoe UI", familyName);
}

TEST(CTFontManager, ShouldBeAbleToRegisterFontsForGraphicsFont) {
    NSURL* testFileURL = __GetRelativeURL(@"/data/WinObjC-Italic.ttf");
    woc::unique_cf<CGDataProviderRef> dataProvider{ CGDataProviderCreateWithURL((__bridge CFURLRef)testFileURL) };
    woc::unique_cf<CGFontRef> graphicsFont{ CGFontCreateWithDataProvider(dataProvider.get()) };
    EXPECT_NE(nullptr, graphicsFont);

    CFErrorRef error = nullptr;
    EXPECT_TRUE(CTFontManagerRegisterGraphicsFont(graphicsFont.get(), &error));
    EXPECT_EQ(nullptr, error);

    woc::unique_cf<CTFontRef> font{ CTFontCreateWithName(CFSTR("WinObjC-Italic"), 20, nullptr) };
    EXPECT_NE(nullptr, font);

    StrongId<NSString> familyName = (NSString*)CTFontCopyFullName(font.get());
    EXPECT_OBJCEQ(@"WinObjC Italic", familyName);

    EXPECT_TRUE(CTFontManagerUnregisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, &error));
    EXPECT_EQ(nullptr, error);

    woc::unique_cf<CTFontRef> failedFont{ CTFontCreateWithName(CFSTR("WinObjC-Italic"), 20, nullptr) };
    EXPECT_NE(nullptr, failedFont);

    StrongId<NSString> failedFamilyName = (NSString*)CTFontCopyFullName(failedFont.get());
    EXPECT_OBJCEQ(@"Segoe UI", failedFamilyName);
}

TEST(CTFontManager, ShouldFailToUnregisterNonregisteredFonts) {
    NSURL* testFileURL = __GetRelativeURL(@"/data/WinObjC.ttf");
    CFErrorRef error = nullptr;
    EXPECT_TRUE(CTFontManagerUnregisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, &error));
    EXPECT_NE(nullptr, error);
    EXPECT_EQ(kCTFontManagerErrorNotRegistered, CFErrorGetCode(error));
}