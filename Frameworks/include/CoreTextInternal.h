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

#import <CoreText/CoreText.h>
#import <CoreText/CTParagraphStyle.h>
#import <CFCppBase.h>
#import <Starboard.h>
#include <COMIncludes.h>
#import <DWrite.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>
#import <vector>
#import <algorithm>

// Helper method for validating range and copying internal data to given outData
template <typename T>
void _boundedCopy(CFRange range, CFIndex size, const T inData[], T outData[]) {
    if (inData && outData && range.location >= 0L && range.length >= 0L && range.location + range.length <= size) {
        if (range.length == 0L) {
            range.length = size - range.location;
        }

        memcpy(outData, inData + range.location, sizeof(T) * range.length);
    }
}

template <typename T>
inline void _SafeRelease(T** p) {
    if ((*p) != nullptr) {
        (*p)->Release();
        *p = nullptr;
    }
}

CFAttributedStringRef _CTTypesetterGetAttributedString(CTTypesetterRef typesetter);

#pragma region CTLine
struct __CTLine : CoreFoundation::CppBase<__CTLine> {
    __CTLine() : _runs(woc::TakeOwnership, CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks)) {
    }

    __CTLine(const __CTLine& other)
        : _strRange(other._strRange),
          _width(other._width),
          _ascent(other._ascent),
          _descent(other._descent),
          _leading(other._leading),
          _glyphCount(other._glyphCount),
          _relativeXOffset(other._relativeXOffset),
          _runs(woc::TakeOwnership, CFArrayCreateMutableCopy(kCFAllocatorDefault, 0, other._runs)) {
    }

    double GetTypographicBounds(CGFloat* ascent, CGFloat* descent, CGFloat* leading) const;

    CFRange _strRange;
    CGFloat _relativeXOffset;
    CGFloat _width;
    CFIndex _glyphCount;
    woc::StrongCF<CFMutableArrayRef> _runs;
    mutable CGFloat _ascent;
    mutable CGFloat _descent;
    mutable CGFloat _leading;
};

CTLineRef _CTLineCreate();

#pragma endregion CTLine

#pragma region CTFrame
struct __CTFrame : CoreFoundation::CppBase<__CTFrame> {
    __CTFrame() : _lines(woc::TakeOwnership, CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks)) {
    }

    CGRect _frameRect;
    woc::StrongCF<CGPathRef> _path;
    std::vector<CGPoint> _lineOrigins;
    // Hold CTLineRef
    woc::StrongCF<CFMutableArrayRef> _lines;
};

#pragma endregion CTFrame

#pragma region CTRun
struct __CTRun : CoreFoundation::CppBase<__CTRun> {
    __CTRun()
        : _attributes(woc::TakeOwnership,
                      CFDictionaryCreateMutable(kCFAllocatorSystemDefault,
                                                0,
                                                &kCFCopyStringDictionaryKeyCallBacks,
                                                &kCFTypeDictionaryValueCallBacks)),
          _textMatrix(CGAffineTransformIdentity) {
    }

    ~__CTRun() {
        _SafeRelease(&_dwriteGlyphRun.fontFace);
        delete[] _dwriteGlyphRun.glyphIndices;
        delete[] _dwriteGlyphRun.glyphAdvances;
        delete[] _dwriteGlyphRun.glyphOffsets;
    }

    woc::StrongCF<CFMutableDictionaryRef> _attributes;
    CFRange _range;
    woc::StrongCF<CFStringRef> _stringFragment;
    DWRITE_GLYPH_RUN _dwriteGlyphRun;
    std::vector<CFIndex> _stringIndices;
    CGFloat _relativeXOffset;
    CGFloat _relativeYOffset;
    std::vector<CGSize> _glyphAdvances;
    std::vector<CGPoint> _glyphOrigins;
    CGAffineTransform _textMatrix;
};

CTRunRef _CTRunCreate();

#pragma endregion CTRun

// Private helper methods for UIKit
CORETEXT_EXPORT CGSize _CTFrameGetSize(CTFrameRef frame);
CORETEXT_EXPORT DWRITE_FONT_WEIGHT _CTFontGetDWriteWeight(CTFontRef font);
CORETEXT_EXPORT DWRITE_FONT_STRETCH _CTFontGetDWriteStretch(CTFontRef font);
CORETEXT_EXPORT DWRITE_FONT_STYLE _CTFontGetDWriteStyle(CTFontRef font);
CORETEXT_EXPORT CFStringRef _CTFontGetXamlCompatibleFamilyName(CTFontRef font);