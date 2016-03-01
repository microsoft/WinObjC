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

TEST(CoreText, FontCopyName) {
    const NSString* copyrightName = @"© 2015 Microsoft Corporation. All Rights Reserved.";
    const NSString* familyName = @"Segoe UI";
    const NSString* subFamilyName = @"Regular";
    const NSString* styleName = @"Regular";
    const NSString* uniqueName = @"Segoe UI Regular";
    const NSString* fullName = @"Segoe UI";
    const NSString* versionName = @"Version 5.53";
    const NSString* postscriptName = @"SegoeUI";
    const NSString* trademarkName = @"Segoe is a trademark of the Microsoft group of companies.";
    const NSString* manufacturerName = @"Microsoft Corporation";
    const NSString* designerName = nullptr;
    const NSString* descriptionName = nullptr;
    const NSString* vendorURLName = @"http://www.microsoft.com/typography/fonts/";
    const NSString* designerURLName = nullptr;
    const NSString* licenseURLName = @"http://www.microsoft.com/typography/fonts/";
    const NSString* sampleTextName = nullptr;
    const NSString* postscriptCIDName = nullptr;

    const CFStringRef fontName = static_cast<CFStringRef>(@"SegoeUI");
    const CTFontRef font = CTFontCreateWithName(fontName, 0.0, NULL);
    ASSERT_TRUE_MSG(font != nil, "Failed: Font is nil.");

    const CFStringRef fontCopyrightName = CTFontCopyName(font, kCTFontCopyrightNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontCopyrightName), copyrightName, "FAILED: Incorrect copyright name\n");
    CFRelease(fontCopyrightName);

    const CFStringRef fontFamilyName = CTFontCopyName(font, kCTFontFamilyNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontFamilyName), familyName, "FAILED: Incorrect family name\n");
    CFRelease(fontFamilyName);

    const CFStringRef fontSubFamilyName = CTFontCopyName(font, kCTFontSubFamilyNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontSubFamilyName), subFamilyName, "FAILED: Incorrect sub-family name\n");
    CFRelease(fontSubFamilyName);

    const CFStringRef fontStyleName = CTFontCopyName(font, kCTFontStyleNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontStyleName), styleName, "FAILED: Incorrect style name\n");
    CFRelease(fontStyleName);

    const CFStringRef fontUniqueName = CTFontCopyName(font, kCTFontUniqueNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontUniqueName), uniqueName, "FAILED: Incorrect unique name\n");
    CFRelease(fontUniqueName);

    const CFStringRef fontFullName = CTFontCopyName(font, kCTFontFullNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontFullName), fullName, "FAILED: Incorrect full name\n");
    CFRelease(fontFullName);

    // const CFStringRef fontVersionName = CTFontCopyName(font, kCTFontVersionNameKey);
    // ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontVersionName), versionName, "FAILED: Incorrect version name\n");
    // CFRelease(fontVersionName);

    const CFStringRef fontPostscriptName = CTFontCopyName(font, kCTFontPostScriptNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontPostscriptName), postscriptName, "FAILED: Incorrect postscript name\n");
    CFRelease(fontPostscriptName);

    const CFStringRef fontTrademarkName = CTFontCopyName(font, kCTFontTrademarkNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontTrademarkName), trademarkName, "FAILED: Incorrect trademark name\n");
    CFRelease(fontTrademarkName);

    const CFStringRef fontManufacturerName = CTFontCopyName(font, kCTFontManufacturerNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontManufacturerName), manufacturerName, "FAILED: Incorrect manufacturer name\n");
    CFRelease(fontManufacturerName);

    const CFStringRef fontDesignerName = CTFontCopyName(font, kCTFontDesignerNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontDesignerName), designerName, "FAILED: Incorrect designer name\n");
    CFRelease(fontDesignerName);

    const CFStringRef fontDescriptionName = CTFontCopyName(font, kCTFontDescriptionNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontDescriptionName), descriptionName, "FAILED: Incorrect descriptor name\n");
    CFRelease(fontDescriptionName);

    const CFStringRef fontVendorURLName = CTFontCopyName(font, kCTFontVendorURLNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontVendorURLName), vendorURLName, "FAILED: Incorrect vendor URL name\n");
    CFRelease(fontVendorURLName);

    const CFStringRef fontDesignerURLName = CTFontCopyName(font, kCTFontDesignerURLNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontDesignerURLName), designerURLName, "FAILED: Incorrect designer URL name\n");
    CFRelease(fontDesignerURLName);

    const CFStringRef fontLicenseURLName = CTFontCopyName(font, kCTFontLicenseURLNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontLicenseURLName), licenseURLName, "FAILED: Incorrect license URL name\n");
    CFRelease(fontLicenseURLName);

    const CFStringRef fontSampleTextName = CTFontCopyName(font, kCTFontSampleTextNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontSampleTextName), sampleTextName, "FAILED: Incorrect sample text name\n");
    CFRelease(fontSampleTextName);

    const CFStringRef fontPostscriptCIDName = CTFontCopyName(font, kCTFontPostScriptCIDNameKey);
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(fontPostscriptCIDName), postscriptCIDName, "FAILED: Incorrect postscript CID name\n");
    CFRelease(fontPostscriptCIDName);

    CFRelease(font);
}