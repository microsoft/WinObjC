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

#import "Starboard.h"
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

@interface _CTTypesetter : NSObject {
@public
    StrongId<NSAttributedString> _attributedString;
    StrongId<NSString> _string;
    std::vector<WORD> _characters;
}
@end

@interface _CTFramesetter : NSObject {
@public
    StrongId<_CTTypesetter> _typesetter;
}
@end

@interface _CTRun : NSObject {
@public
    StrongId<NSMutableDictionary<NSString*, id>> _attributes;
    CFRange _range;
    StrongId<NSString> _stringFragment;
    DWRITE_GLYPH_RUN _dwriteGlyphRun;
    std::vector<CFIndex> _stringIndices;
    CGFloat _relativeXOffset;
    CGFloat _relativeYOffset;
    std::vector<CGSize> _glyphAdvances;
    std::vector<CGPoint> _glyphOrigins;
}
@end

@interface _CTLine : NSObject {
@public
    CFRange _strRange;
    CGPoint _lineOrigin;
    CGFloat _relativeXOffset;
    CGFloat _relativeYOffset;
    CGFloat _width;
    NSUInteger _glyphCount;
    StrongId<NSMutableArray<_CTRun*>> _runs;
    CGFloat _ascent, _descent, _leading;
}
@end

@interface _CTFrame : NSObject {
@public
    CGRect _frameRect;
    woc::unique_cf<CGPathRef> _path;
    std::vector<CGPoint> _lineOrigins;
    StrongId<NSMutableArray<_CTLine*>> _lines;
}
@end

struct _CTParagraphStyleFloatProperty {
    bool _isDefault = true;
    CGFloat _value = 0.0f;
};

struct _CTParagraphStyleCTTextAlignmentProperty {
    bool _isDefault = true;
    CTWritingDirection _value = kCTNaturalTextAlignment;
};

struct _CTParagraphStyleCTLineBreakModeProperty {
    bool _isDefault = true;
    CTLineBreakMode _value = kCTLineBreakByWordWrapping;
};

struct _CTParagraphStyleCTWritingDirectionProperty {
    bool _isDefault = true;
    CTWritingDirection _value = kCTWritingDirectionNatural;
};

struct _CTParagraphStyleProperties {
    _CTParagraphStyleCTTextAlignmentProperty _alignment;
    _CTParagraphStyleCTLineBreakModeProperty _lineBreakMode;
    _CTParagraphStyleCTWritingDirectionProperty _writingDirection;

    _CTParagraphStyleFloatProperty _firstLineHeadIndent;
    _CTParagraphStyleFloatProperty _headIndent;
    _CTParagraphStyleFloatProperty _tailIndent;
    _CTParagraphStyleFloatProperty _tabInterval;
    _CTParagraphStyleFloatProperty _lineHeightMultiple;
    _CTParagraphStyleFloatProperty _maximumLineHeight;
    _CTParagraphStyleFloatProperty _minimumLineHeight;
    _CTParagraphStyleFloatProperty _lineSpacing;
    _CTParagraphStyleFloatProperty _paragraphSpacing;
    _CTParagraphStyleFloatProperty _paragraphSpacingBefore;
    _CTParagraphStyleFloatProperty _lineSpacingAdjustment;
    _CTParagraphStyleFloatProperty _maximumLineSpacing;
    _CTParagraphStyleFloatProperty _minimumLineSpacing;
};

@interface _CTParagraphStyle : NSObject {
@public
    _CTParagraphStyleProperties _properties;
}
@end

// Private helper methods for UIKit
CORETEXT_EXPORT CGSize _CTFrameGetSize(CTFrameRef frame);
CORETEXT_EXPORT DWRITE_FONT_WEIGHT _CTFontGetDWriteWeight(CTFontRef font);
CORETEXT_EXPORT DWRITE_FONT_STRETCH _CTFontGetDWriteStretch(CTFontRef font);
CORETEXT_EXPORT DWRITE_FONT_STYLE _CTFontGetDWriteStyle(CTFontRef font);