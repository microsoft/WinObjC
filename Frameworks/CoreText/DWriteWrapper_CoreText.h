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

#pragma once

#import <CoreGraphics/DWriteWrapper.h>

#import <CoreFoundation/CoreFoundation.h>
#import <CoreText/CoreTextExport.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreTextInternal.h>

#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>
#import <vector>

// Based off DWRITE_GLYPH_RUN_DESCRIPTION structure
struct _DWriteGlyphRunDescription {
    uint32_t _stringLength;
    uint32_t _textPosition;
    std::vector<CFIndex> _clusterMap;
};

struct _DWriteGlyphRunDetails {
    std::vector<float> _baselineOriginX;
    std::vector<float> _baselineOriginY;
    std::vector<DWRITE_GLYPH_RUN> _dwriteGlyphRun;
    std::vector<_DWriteGlyphRunDescription> _glyphRunDescriptions;
};

bool _CloneDWriteGlyphRun(_In_ DWRITE_GLYPH_RUN const* src, _Outptr_ DWRITE_GLYPH_RUN* dest);

CGSize _DWriteGetFrameSize(CFAttributedStringRef string, CFRange range, CGSize maxSize, CFRange* fitRange);
CTFrameRef _DWriteGetFrame(CFAttributedStringRef string, CFRange range, CGRect frameSize);
CTLineRef _DWriteCreateLine(CFAttributedStringRef string);

// DWriteWrapper functions relating to CTFont, CTFontDescriptor
CFNumberRef _CFNumberCreateFromSymbolicTraits(CTFontSymbolicTraits symbolicTraits);
CTFontSymbolicTraits _CTFontSymbolicTraitsFromCFNumber(CFNumberRef num);

HRESULT _DWriteCreateFontFaceWithFontDescriptor(CTFontDescriptorRef fontDescriptor, IDWriteFontFace** fontFace);
HRESULT _DWriteCreateMatchingFontDescriptors(CFDictionaryRef attributes, CFSetRef mandatoryKeys, CFArrayRef* matchingNames);

CFDictionaryRef _DWriteFontCreateTraitsDict(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace);
CFStringRef _DWriteFontCopyName(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace,
                                CFStringRef nameKey,
                                CFStringRef* actualLanguage = nullptr);

// DWriteWrapper functions relating to CGPath
CGPathRef _DWriteFontCreatePathForGlyph(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace,
                                        CGFloat pointSize,
                                        CGGlyph glyph,
                                        const CGAffineTransform* transform);

CFArrayRef _DWriteCopyAvailableFontTables(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace);
