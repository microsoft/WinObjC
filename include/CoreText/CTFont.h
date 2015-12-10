/* Copyright (c) 2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#ifndef _CTFONT_H_
#define _CTFONT_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import "CoreTextExport.h"
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGPath.h>
#import <CoreText/CTFontDescriptor.h>
#import <CoreText/CTFontTraits.h>

ENABLE_IMPLICIT_BRIDGING

typedef struct __CTFont* CTFontRef;

enum {
    kCTFontNoFontType = -1,
    kCTFontUserFontType = 0,
    kCTFontUserFixedPitchFontType = 1,
    kCTFontSystemFontType = 2,
    kCTFontEmphasizedSystemFontType = 3,
    kCTFontSmallSystemFontType = 4,
    kCTFontSmallEmphasizedSystemFontType = 5,
    kCTFontMiniSystemFontType = 6,
    kCTFontMiniEmphasizedSystemFontType = 7,
    kCTFontViewsFontType = 8,
    kCTFontApplicationFontType = 9,
    kCTFontLabelFontType = 10,
    kCTFontMenuTitleFontType = 11,
    kCTFontMenuItemFontType = 12,
    kCTFontMenuItemMarkFontType = 13,
    kCTFontMenuItemCmdKeyFontType = 14,
    kCTFontWindowTitleFontType = 15,
    kCTFontPushButtonFontType = 16,
    kCTFontUtilityWindowTitleFontType = 17,
    kCTFontAlertHeaderFontType = 18,
    kCTFontSystemDetailFontType = 19,
    kCTFontEmphasizedSystemDetailFontType = 20,
    kCTFontToolbarFontType = 21,
    kCTFontSmallToolbarFontType = 22,
    kCTFontMessageFontType = 23,
    kCTFontPaletteFontType = 24,
    kCTFontToolTipFontType = 25,
    kCTFontControlContentFontType = 26
};
typedef uint32_t CTFontUIFontType;

CORETEXT_EXPORT const CFStringRef kCTFontCopyrightNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontFamilyNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontSubFamilyNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontStyleNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontUniqueNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontFullNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontVersionNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontPostScriptNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontTrademarkNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontManufacturerNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontDesignerNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontDescriptionNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontVendorURLNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontDesignerURLNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontLicenseNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontLicenseURLNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontSampleTextNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontPostScriptCIDNameKey;

CORETEXT_EXPORT CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont, CGFloat size, CGAffineTransform* xform, id attributes);
CORETEXT_EXPORT CTFontRef CTFontCreateUIFontForLanguage(CTFontUIFontType uiFontType, CGFloat size, NSString* language);
CORETEXT_EXPORT CFStringRef CTFontCopyFullName(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetSize(CTFontRef self);
CORETEXT_EXPORT size_t CTFontGetGlyphCount(CTFontRef self);
CORETEXT_EXPORT BOOL CTFontGetGlyphsForCharacters(CTFontRef self, const unichar* characters, CGGlyph* glyphs, size_t count);
CORETEXT_EXPORT CGRect CTFontGetBoundingBox(CTFontRef self);
CORETEXT_EXPORT double CTFontGetAdvancesForGlyphs(CTFontRef self, int orientation, const CGGlyph* glyphs, CGSize* advances, size_t count);
CORETEXT_EXPORT CGFloat CTFontGetUnderlinePosition(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetUnderlineThickness(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetAscent(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetDescent(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetLeading(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetSlantAngle(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetXHeight(CTFontRef self);
CORETEXT_EXPORT CGFloat CTFontGetCapHeight(CTFontRef self);
CORETEXT_EXPORT CGPathRef CTFontCreatePathForGlyph(CTFontRef self, CGGlyph glyph, CGAffineTransform* xform);

CORETEXT_EXPORT CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform* matrix);
CORETEXT_EXPORT CTFontSymbolicTraits CTFontGetSymbolicTraits(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyPostScriptName(CTFontRef font);
CORETEXT_EXPORT CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef font);
CORETEXT_EXPORT CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask);
CORETEXT_EXPORT CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey);

CORETEXT_EXPORT CFStringRef CTFontCopyDisplayName(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyFamilyName(CTFontRef font);
CORETEXT_EXPORT CTFontRef CTFontCreateCopyWithAttributes(CTFontRef font,
                                                         CGFloat size,
                                                         const CGAffineTransform* matrix,
                                                         CTFontDescriptorRef attributes);

DISABLE_IMPLICIT_BRIDGING

#endif /* _CTFONT_H_ */
