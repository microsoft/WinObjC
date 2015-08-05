/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#ifndef _CTFONT_H_
#define _CTFONT_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <StarboardExport.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGPath.h>
#import <CoreText/CTFontDescriptor.h>
#import <CoreText/CTFontTraits.h>

ENABLE_IMPLICIT_BRIDGING

typedef struct __CTFont *CTFontRef;

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

SB_EXPORT const CFStringRef kCTFontCopyrightNameKey;
SB_EXPORT const CFStringRef kCTFontFamilyNameKey;
SB_EXPORT const CFStringRef kCTFontSubFamilyNameKey;
SB_EXPORT const CFStringRef kCTFontStyleNameKey;
SB_EXPORT const CFStringRef kCTFontUniqueNameKey;
SB_EXPORT const CFStringRef kCTFontFullNameKey;
SB_EXPORT const CFStringRef kCTFontVersionNameKey;
SB_EXPORT const CFStringRef kCTFontPostScriptNameKey;
SB_EXPORT const CFStringRef kCTFontTrademarkNameKey;
SB_EXPORT const CFStringRef kCTFontManufacturerNameKey;
SB_EXPORT const CFStringRef kCTFontDesignerNameKey;
SB_EXPORT const CFStringRef kCTFontDescriptionNameKey;
SB_EXPORT const CFStringRef kCTFontVendorURLNameKey;
SB_EXPORT const CFStringRef kCTFontDesignerURLNameKey;
SB_EXPORT const CFStringRef kCTFontLicenseNameKey;
SB_EXPORT const CFStringRef kCTFontLicenseURLNameKey;
SB_EXPORT const CFStringRef kCTFontSampleTextNameKey;
SB_EXPORT const CFStringRef kCTFontPostScriptCIDNameKey;

SB_EXPORT CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont,CGFloat size,CGAffineTransform *xform,id attributes);
SB_EXPORT CTFontRef CTFontCreateUIFontForLanguage(CTFontUIFontType uiFontType,CGFloat size,NSString *language);
SB_EXPORT CFStringRef CTFontCopyFullName(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetSize(CTFontRef self);
SB_EXPORT size_t    CTFontGetGlyphCount(CTFontRef self);
SB_EXPORT BOOL      CTFontGetGlyphsForCharacters(CTFontRef self,const unichar *characters,CGGlyph *glyphs,size_t count);
SB_EXPORT CGRect    CTFontGetBoundingBox(CTFontRef self);
SB_EXPORT double    CTFontGetAdvancesForGlyphs(CTFontRef self,int orientation,const CGGlyph *glyphs,CGSize *advances,size_t count);
SB_EXPORT CGFloat   CTFontGetUnderlinePosition(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetUnderlineThickness(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetAscent(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetDescent(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetLeading(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetSlantAngle(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetXHeight(CTFontRef self);
SB_EXPORT CGFloat   CTFontGetCapHeight(CTFontRef self);
SB_EXPORT CGPathRef CTFontCreatePathForGlyph(CTFontRef self,CGGlyph glyph,CGAffineTransform *xform);

SB_EXPORT CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform *matrix);
SB_EXPORT CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform *matrix);
SB_EXPORT CTFontSymbolicTraits CTFontGetSymbolicTraits(CTFontRef font);
SB_EXPORT CFStringRef CTFontCopyPostScriptName(CTFontRef font);
SB_EXPORT CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef font);
SB_EXPORT CTFontRef CTFontCreateCopyWithSymbolicTraits(CTFontRef font, CGFloat size, const CGAffineTransform *matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask);
SB_EXPORT CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey);

SB_EXPORT CFStringRef CTFontCopyDisplayName(CTFontRef font);
SB_EXPORT CFStringRef CTFontCopyFamilyName(CTFontRef font);
SB_EXPORT CTFontRef CTFontCreateCopyWithAttributes(CTFontRef font, CGFloat size, const CGAffineTransform *matrix, CTFontDescriptorRef attributes);

DISABLE_IMPLICIT_BRIDGING

#endif /* _CTFONT_H_ */
