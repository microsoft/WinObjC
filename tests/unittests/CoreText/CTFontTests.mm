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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

class FontCopyName : public ::testing::TestWithParam<::testing::tuple<CFStringRef, const NSString*>> {
public:
    FontCopyName() : _font(nullptr), public ::testing::TestWithParam<::testing::tuple<CFStringRef, const NSString*>>() {
    }

protected:
    virtual void SetUp() {
        const CFStringRef fontName = static_cast<CFStringRef>(@"SegoeUI");
        _font = CTFontCreateWithName(fontName, 0.0, NULL);
        ASSERT_TRUE_MSG(_font != nil, "Failed: Font is nil.");
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
    ASSERT_OBJCEQ(static_cast<NSString*>(propertyValue), ::testing::get<1>(GetParam()));
    CFRelease(propertyValue);
}

const NSString* c_copyrightName = @"© 2015 Microsoft Corporation. All Rights Reserved.";
const NSString* c_familyName = @"Segoe UI";
const NSString* c_subFamilyName = @"Regular";
const NSString* c_styleName = @"Regular";
const NSString* c_uniqueName = @"Segoe UI Regular";
const NSString* c_fullName = @"Segoe UI";
const NSString* c_versionName = @"Version 5.53";
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

ARM_DISABLED_INSTANTIATE_TEST_CASE_P(CoreText,
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
                                                       ::testing::make_tuple(kCTFontPostScriptCIDNameKey, c_postscriptCIDName)),
                                     // TODO 6697587: Re-enable this test once ARM version difference is understood.
                                     ::testing::Values(::testing::make_tuple(kCTFontVersionNameKey, c_versionName)));
