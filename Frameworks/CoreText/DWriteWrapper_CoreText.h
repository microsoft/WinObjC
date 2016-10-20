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

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSString.h>
#import <vector>

#define NSMakeRangeFromCF(cfr) NSMakeRange(cfr.location == kCFNotFound ? NSNotFound : cfr.location, cfr.length)

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

bool _CloneDWriteGlyphRun(_In_ DWRITE_GLYPH_RUN const* src, _Out_ DWRITE_GLYPH_RUN* dest);

_CTFrame* _DWriteGetFrame(CFAttributedStringRef string, CFRange range, CGRect frameSize);
_CTLine* _DWriteGetLine(CFAttributedStringRef string);

HRESULT _DWriteCreateFontFaceWithFontDescriptor(CTFontDescriptorRef fontDescriptor, IDWriteFontFace** outFontFace);

CFNumberRef _CFNumberCreateFromSymbolicTraits(CTFontSymbolicTraits symbolicTraits);
CTFontSymbolicTraits _CTFontSymbolicTraitsFromCFNumber(CFNumberRef num);

CFDictionaryRef _DWriteFontCreateTraitsDict(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace);
CFStringRef _DWriteFontCopyName(const Microsoft::WRL::ComPtr<IDWriteFontFace>& fontFace, CFStringRef nameKey);