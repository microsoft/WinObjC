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
#pragma once

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTFontDescriptor.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFCharacterSet.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGPath.h>

typedef const struct __CTFont* CTFontRef;
typedef uint32_t CTFontUIFontType;
typedef uint32_t CTFontTableTag;
typedef uint32_t CTFontTableOptions;
typedef CFOptionFlags CTFontOptions;

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
enum {
    kCTFontTableBASE = 'BASE',
    kCTFontTableCFF = 'CFF ',
    kCTFontTableDSIG = 'DSIG',
    kCTFontTableEBDT = 'EBDT',
    kCTFontTableEBLC = 'EBLC',
    kCTFontTableEBSC = 'EBSC',
    kCTFontTableGDEF = 'GDEF',
    kCTFontTableGPOS = 'GPOS',
    kCTFontTableGSUB = 'GSUB',
    kCTFontTableJSTF = 'JSTF',
    kCTFontTableLTSH = 'LTSH',
    kCTFontTableOS2 = 'OS/2',
    kCTFontTablePCLT = 'PCLT',
    kCTFontTableVDMX = 'VDMX',
    kCTFontTableVORG = 'VORG',
    kCTFontTableZapf = 'Zapf',
    kCTFontTableAcnt = 'acnt',
    kCTFontTableAvar = 'avar',
    kCTFontTableBdat = 'bdat',
    kCTFontTableBhed = 'bhed',
    kCTFontTableBloc = 'bloc',
    kCTFontTableBsln = 'bsln',
    kCTFontTableCmap = 'cmap',
    kCTFontTableCvar = 'cvar',
    kCTFontTableCvt = 'cvt ',
    kCTFontTableFdsc = 'fdsc',
    kCTFontTableFeat = 'feat',
    kCTFontTableFmtx = 'fmtx',
    kCTFontTableFpgm = 'fpgm',
    kCTFontTableFvar = 'fvar',
    kCTFontTableGasp = 'gasp',
    kCTFontTableGlyf = 'glyf',
    kCTFontTableGvar = 'gvar',
    kCTFontTableHdmx = 'hdmx',
    kCTFontTableHead = 'head',
    kCTFontTableHhea = 'hhea',
    kCTFontTableHmtx = 'hmtx',
    kCTFontTableHsty = 'hsty',
    kCTFontTableJust = 'just',
    kCTFontTableKern = 'kern',
    kCTFontTableKerx = 'kerx',
    kCTFontTableLcar = 'lcar',
    kCTFontTableLoca = 'loca',
    kCTFontTableMaxp = 'maxp',
    kCTFontTableMort = 'mort',
    kCTFontTableMorx = 'morx',
    kCTFontTableName = 'name',
    kCTFontTableOpbd = 'opbd',
    kCTFontTablePost = 'post',
    kCTFontTablePrep = 'prep',
    kCTFontTableProp = 'prop',
    kCTFontTableSbit = 'sbit',
    kCTFontTableSbix = 'sbix',
    kCTFontTableTrak = 'trak',
    kCTFontTableVhea = 'vhea',
    kCTFontTableVmtx = 'vmtx'
};
enum { kCTFontTableOptionNoOptions = 0, kCTFontTableOptionExcludeSynthetic = (1 << 0) };
enum {
    kCTFontOptionsDefault = 0,
    kCTFontOptionsPreventAutoActivation = 1 << 0,
    kCTFontOptionsPreferSystemFont = 1 << 2,
};

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
CORETEXT_EXPORT const CFStringRef kCTFontVariationAxisIdentifierKey;
CORETEXT_EXPORT const CFStringRef kCTFontVariationAxisMinimumValueKey;
CORETEXT_EXPORT const CFStringRef kCTFontVariationAxisMaximumValueKey;
CORETEXT_EXPORT const CFStringRef kCTFontVariationAxisDefaultValueKey;
CORETEXT_EXPORT const CFStringRef kCTFontVariationAxisNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureTypeIdentifierKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureTypeNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureTypeExclusiveKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureTypeSelectorsKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureSelectorIdentifierKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureSelectorNameKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureSelectorDefaultKey;
CORETEXT_EXPORT const CFStringRef kCTFontFeatureSelectorSettingKey;

CORETEXT_EXPORT const CGFloat kCTFontLabelFontSize;
CORETEXT_EXPORT const CGFloat kCTFontButtonFontSize;
CORETEXT_EXPORT const CGFloat kCTFontSmallSystemFontSize;
CORETEXT_EXPORT const CGFloat kCTFontSystemFontSize;

CORETEXT_EXPORT const CGFloat kCTFontWeightUltraLight;
CORETEXT_EXPORT const CGFloat kCTFontWeightThin;
CORETEXT_EXPORT const CGFloat kCTFontWeightLight;
CORETEXT_EXPORT const CGFloat kCTFontWeightRegular;
CORETEXT_EXPORT const CGFloat kCTFontWeightMedium;
CORETEXT_EXPORT const CGFloat kCTFontWeightSemibold;
CORETEXT_EXPORT const CGFloat kCTFontWeightBold;
CORETEXT_EXPORT const CGFloat kCTFontWeightHeavy;
CORETEXT_EXPORT const CGFloat kCTFontWeightBlack;

CORETEXT_EXPORT const CFStringRef kCTFontDefaultFontName;
CORETEXT_EXPORT const CFStringRef kCTFontDefaultBoldFontName;
CORETEXT_EXPORT const CFStringRef kCTFontDefaultItalicFontName;
CORETEXT_EXPORT const CFStringRef kCTFontDefaultMonospacedFontName;

CORETEXT_EXPORT CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform* matrix);
CORETEXT_EXPORT CTFontRef CTFontCreateWithNameAndOptions(CFStringRef name,
                                                         CGFloat size,
                                                         const CGAffineTransform* matrix,
                                                         CTFontOptions options);
CORETEXT_EXPORT CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform* matrix);
CORETEXT_EXPORT CTFontRef CTFontCreateWithFontDescriptorAndOptions(CTFontDescriptorRef descriptor,
                                                                   CGFloat size,
                                                                   const CGAffineTransform* matrix,
                                                                   CTFontOptions options);
CORETEXT_EXPORT CTFontRef CTFontCreateUIFontForLanguage(CTFontUIFontType uiType, CGFloat size, CFStringRef language) STUB_METHOD;
CORETEXT_EXPORT CTFontRef CTFontCreateCopyWithAttributes(CTFontRef font,
                                                         CGFloat size,
                                                         const CGAffineTransform* matrix,
                                                         CTFontDescriptorRef attributes);
CORETEXT_EXPORT CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask);
CORETEXT_EXPORT CTFontRef CTFontCreateCopyWithFamily(CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CFStringRef family);
CORETEXT_EXPORT CTFontRef CTFontCreateForString(CTFontRef currentFont, CFStringRef string, CFRange range) STUB_METHOD;
CORETEXT_EXPORT CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef font);
CORETEXT_EXPORT CFTypeRef CTFontCopyAttribute(CTFontRef font, CFStringRef attribute);
CORETEXT_EXPORT CGFloat CTFontGetSize(CTFontRef font);
CORETEXT_EXPORT CGAffineTransform CTFontGetMatrix(CTFontRef font);
CORETEXT_EXPORT CTFontSymbolicTraits CTFontGetSymbolicTraits(CTFontRef font);
CORETEXT_EXPORT CFDictionaryRef CTFontCopyTraits(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyPostScriptName(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyFamilyName(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyFullName(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyDisplayName(CTFontRef font);
CORETEXT_EXPORT CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey);
CORETEXT_EXPORT CFStringRef CTFontCopyLocalizedName(CTFontRef font, CFStringRef nameKey, CFStringRef _Nullable* actualLanguage) STUB_METHOD;
CORETEXT_EXPORT CFCharacterSetRef CTFontCopyCharacterSet(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CFStringEncoding CTFontGetStringEncoding(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCopySupportedLanguages(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CGFloat CTFontGetAscent(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetDescent(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetLeading(CTFontRef font);
CORETEXT_EXPORT unsigned int CTFontGetUnitsPerEm(CTFontRef font);
CORETEXT_EXPORT CFIndex CTFontGetGlyphCount(CTFontRef font);
CORETEXT_EXPORT CGRect CTFontGetBoundingBox(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetUnderlinePosition(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetUnderlineThickness(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetSlantAngle(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetCapHeight(CTFontRef font);
CORETEXT_EXPORT CGFloat CTFontGetXHeight(CTFontRef font);
CORETEXT_EXPORT CGPathRef CTFontCreatePathForGlyph(CTFontRef font, CGGlyph glyph, const CGAffineTransform* matrix) STUB_METHOD;
CORETEXT_EXPORT CGGlyph CTFontGetGlyphWithName(CTFontRef font, CFStringRef glyphName) STUB_METHOD;
CORETEXT_EXPORT CGRect CTFontGetBoundingRectsForGlyphs(
    CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGRect* boundingRects, CFIndex count);
CORETEXT_EXPORT double CTFontGetAdvancesForGlyphs(
    CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGSize* advances, CFIndex count);
CORETEXT_EXPORT void CTFontGetVerticalTranslationsForGlyphs(CTFontRef font, const CGGlyph glyphs[], CGSize translations[], CFIndex count)
    STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCopyVariationAxes(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CFDictionaryRef CTFontCopyVariation(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCopyFeatures(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFontCopyFeatureSettings(CTFontRef font) STUB_METHOD;
CORETEXT_EXPORT bool CTFontGetGlyphsForCharacters(CTFontRef font, const UniChar characters[], CGGlyph glyphs[], CFIndex count);
CORETEXT_EXPORT void CTFontDrawGlyphs(CTFontRef font, const CGGlyph glyphs[], const CGPoint positions[], size_t count, CGContextRef context)
    STUB_METHOD;
CORETEXT_EXPORT CFIndex CTFontGetLigatureCaretPositions(CTFontRef font, CGGlyph glyph, CGFloat* positions, CFIndex maxPositions)
    STUB_METHOD;
CORETEXT_EXPORT CGFontRef CTFontCopyGraphicsFont(CTFontRef font, CTFontDescriptorRef _Nullable* attributes);
CORETEXT_EXPORT CTFontRef CTFontCreateWithGraphicsFont(CGFontRef graphicsFont,
                                                       CGFloat size,
                                                       const CGAffineTransform* matrix,
                                                       CTFontDescriptorRef attributes);
CORETEXT_EXPORT CFArrayRef CTFontCopyAvailableTables(CTFontRef font, CTFontTableOptions options) STUB_METHOD;
CORETEXT_EXPORT CFDataRef CTFontCopyTable(CTFontRef font, CTFontTableTag table, CTFontTableOptions options);
CORETEXT_EXPORT CFTypeID CTFontGetTypeID();
