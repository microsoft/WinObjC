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
#import <CoreText/CoreText.h>

class FontCopyName : public ::testing::TestWithParam<::testing::tuple<CFStringRef, const NSString*>> {
public:
    FontCopyName() : _font(nullptr) {
    }

protected:
    virtual void SetUp() {
        const CFStringRef fontName = static_cast<CFStringRef>(@"Segoe UI");
        _font = CTFontCreateWithName(fontName, 0.0, NULL);
        EXPECT_TRUE_MSG(_font != nil, "Failed: Font is nil.");
    }

    virtual void TearDown() {
        if (_font) {
            CFRelease(_font);
        }
    }

    CTFontRef _font;
};

TEST_P(FontCopyName, VerifyProperties) {
    const CFStringRef propertyValue = CTFontCopyName(_font, ::testing::get<0>(GetParam()));
    EXPECT_OBJCEQ(static_cast<NSString*>(propertyValue), ::testing::get<1>(GetParam()));
    CFRelease(propertyValue);
}

const NSString* c_copyrightName = @"© 2015 Microsoft Corporation. All Rights Reserved.";
const NSString* c_familyName = @"Segoe UI";
const NSString* c_subFamilyName = @"Regular";
const NSString* c_styleName = @"Regular";
const NSString* c_uniqueName = @"Segoe UI Regular";
const NSString* c_fullName = @"Segoe UI";

// version name for Segoe UI font is different on ARM than on x86 platform, so we are using different version names for both platforms.
#ifdef _M_ARM
const NSString* c_versionName = @"Version 5.53; sf";
#else
const NSString* c_versionName = @"Version 5.53";
#endif

const NSString* c_postscriptName = @"SegoeUI";
const NSString* c_trademarkName = @"Segoe is a trademark of the Microsoft group of companies.";
const NSString* c_manufacturerName = @"Microsoft Corporation";
const NSString* c_designerName = nullptr;
const NSString* c_descriptionName = nullptr;
const NSString* c_vendorURLName = @"http://www.microsoft.com/typography/fonts/";
const NSString* c_designerURLName = nullptr;
const NSString* c_licenseURLName = @"http://www.microsoft.com/typography/fonts/";
const NSString* c_sampleTextName = nullptr;
const NSString* c_postscriptCIDName = nullptr;

INSTANTIATE_TEST_CASE_P(CTFont,
                        FontCopyName,
                        ::testing::Values(::testing::make_tuple(kCTFontCopyrightNameKey, c_copyrightName),
                                          ::testing::make_tuple(kCTFontFamilyNameKey, c_familyName),
                                          ::testing::make_tuple(kCTFontSubFamilyNameKey, c_subFamilyName),
                                          ::testing::make_tuple(kCTFontStyleNameKey, c_styleName),
                                          ::testing::make_tuple(kCTFontUniqueNameKey, c_uniqueName),
                                          ::testing::make_tuple(kCTFontFullNameKey, c_fullName),
                                          ::testing::make_tuple(kCTFontPostScriptNameKey, c_postscriptName),
                                          ::testing::make_tuple(kCTFontTrademarkNameKey, c_trademarkName),
                                          ::testing::make_tuple(kCTFontManufacturerNameKey, c_manufacturerName),
                                          ::testing::make_tuple(kCTFontDesignerNameKey, c_designerName),
                                          ::testing::make_tuple(kCTFontDescriptionNameKey, c_descriptionName),
                                          ::testing::make_tuple(kCTFontVendorURLNameKey, c_vendorURLName),
                                          ::testing::make_tuple(kCTFontDesignerURLNameKey, c_designerURLName),
                                          ::testing::make_tuple(kCTFontLicenseURLNameKey, c_licenseURLName),
                                          ::testing::make_tuple(kCTFontSampleTextNameKey, c_sampleTextName),
                                          ::testing::make_tuple(kCTFontVersionNameKey, c_versionName),
                                          ::testing::make_tuple(kCTFontPostScriptCIDNameKey, c_postscriptCIDName)));

TEST(CTFont, EqualHash) {
    CTFontRef font1 = CTFontCreateWithName(CFSTR("Times New Roman"), 12.0, NULL);
    CTFontRef font2 = CTFontCreateWithName(CFSTR("Times New Roman"), 12.0, NULL);
    CTFontRef font3 = CTFontCreateWithName(CFSTR("Times New Roman Bold"), 12.0, NULL);
    CTFontRef font4 = CTFontCreateWithName(CFSTR("Times New Roman"), 14.0, NULL);
    CFAutorelease(font1);
    CFAutorelease(font2);
    CFAutorelease(font3);
    CFAutorelease(font4);

    EXPECT_TRUE(CFEqual(font1, font2));
    EXPECT_FALSE(CFEqual(font1, font3));
    EXPECT_FALSE(CFEqual(font1, font4));

    EXPECT_EQ(CFHash(font1), CFHash(font2));
    EXPECT_NE(CFHash(font1), CFHash(font3));
    EXPECT_NE(CFHash(font1), CFHash(font4));
}

TEST(CTFont, Description) {
    CTFontRef font1 = CTFontCreateWithName(CFSTR("Arial"), 10.0, NULL);
    CFAutorelease(font1);

    EXPECT_OBJCNE(nil, (id)CFAutorelease(CFCopyDescription(font1)));
}

TEST(CTFont, CopyNameHelpers) {
    CTFontRef font = CTFontCreateWithName(CFSTR("Arial Italic"), 15.0, NULL);
    CFAutorelease(font);

    EXPECT_OBJCEQ(@"Arial-ItalicMT", (id)CFAutorelease(CTFontCopyPostScriptName(font)));
    EXPECT_OBJCEQ(@"Arial", (id)CFAutorelease(CTFontCopyFamilyName(font)));
    EXPECT_OBJCEQ(@"Arial Italic", (id)CFAutorelease(CTFontCopyFullName(font)));
    EXPECT_OBJCEQ(@"Arial Italic", (id)CFAutorelease(CTFontCopyDisplayName(font)));

    font = CTFontCreateWithName(CFSTR("Arial Narrow"), 15.0, NULL);
    CFAutorelease(font);

    EXPECT_OBJCEQ(@"ArialNarrow", (id)CFAutorelease(CTFontCopyPostScriptName(font)));
    EXPECT_OBJCEQ(@"Arial Narrow", (id)CFAutorelease(CTFontCopyFamilyName(font)));
    EXPECT_OBJCEQ(@"Arial Narrow", (id)CFAutorelease(CTFontCopyFullName(font)));
    EXPECT_OBJCEQ(@"Arial Narrow", (id)CFAutorelease(CTFontCopyDisplayName(font)));
}

TEST(CTFont, Metrics) {
    CTFontRef font = CTFontCreateWithName(CFSTR("Courier New Bold Italic"), 15.0, NULL);
    CFAutorelease(font);

    EXPECT_OBJCEQ(@"Courier New Bold Italic", (id)CFAutorelease(CTFontCopyFullName(font)));

    EXPECT_NE(0, CTFontGetAscent(font));
    EXPECT_NE(0, CTFontGetDescent(font));
    EXPECT_NE(0, CTFontGetUnitsPerEm(font));
    EXPECT_NE(0, CTFontGetUnderlinePosition(font));
    EXPECT_NE(0, CTFontGetUnderlineThickness(font));
    EXPECT_NE(0, CTFontGetCapHeight(font));
    EXPECT_NE(0, CTFontGetXHeight(font));
}

TEST(CTFont, GlyphCount) {
    CTFontRef font = CTFontCreateWithName(CFSTR("Arial"), 15.0, NULL);
    CFAutorelease(font);
    // Test for reasonable bounds on number of unique glyphs in a font
    EXPECT_LE(3000, CTFontGetGlyphCount(font));
    EXPECT_GE(8000, CTFontGetGlyphCount(font));

    font = CTFontCreateWithName(CFSTR("Courier New"), 9.0, NULL);
    CFAutorelease(font);
    // Test for reasonable bounds on number of unique glyphs in a font
    EXPECT_LE(3000, CTFontGetGlyphCount(font));
    EXPECT_GE(8000, CTFontGetGlyphCount(font));
}

TEST(CTFont, UnknownName) {
    EXPECT_OBJCEQ(nil, (id)CFAutorelease(CTFontCreateWithName(CFSTR("DoesNotExistFont"), 12.0, NULL)));
}

TEST(CTFont, CaseInsensitive) {
    CTFontRef font1 = CTFontCreateWithName(CFSTR("Arial"), 12.0, NULL);
    CTFontRef font2 = CTFontCreateWithName(CFSTR("ARIAL"), 12.0, NULL);
    CTFontRef font3 = CTFontCreateWithName(CFSTR("arial"), 12.0, NULL);
    CTFontRef font4 = CTFontCreateWithName(CFSTR("aRiAL"), 12.0, NULL);
    CFAutorelease(font1);
    CFAutorelease(font2);
    CFAutorelease(font3);
    CFAutorelease(font4);

    EXPECT_TRUE(CFEqual(font1, font2));
    EXPECT_TRUE(CFEqual(font1, font3));
    EXPECT_TRUE(CFEqual(font1, font4));
}