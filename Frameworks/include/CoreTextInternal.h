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

#import <CoreText/CoreText.h>
#import <CoreText/CTParagraphStyle.h>

#import "Starboard.h"
#include <COMIncludes.h>
#import <DWrite.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>
#import <vector>

template <typename T>
inline void _SafeRelease(T** p) {
    if ((*p) != nullptr) {
        (*p)->Release();
        *p = nullptr;
    }
}

@interface _CTTypesetter : NSObject {
@public
    NSAttributedString* _attributedString;
    NSString* _string;
    WORD* _characters;
    CFIndex _charactersLen;
}
@end

@interface _CTFrameSetter : NSObject {
@public
    StrongId<_CTTypesetter> _typesetter;
}
@end

@interface _CTRun : NSObject {
@public
    StrongId<NSMutableDictionary> _attributes;
    CFRange _range;
    StrongId<NSString> _stringFragment;
    DWRITE_GLYPH_RUN _dwriteGlyphRun;
    std::vector<CFIndex> _stringIndices;

    // TODO::
    // How do we get this data? DWrite does not seem to provide it to us directly today.
    std::vector<CGPoint> _glyphOrigins;
    CGFloat _relativeXOffset;
    CGFloat _relativeYOffset;
}
@end

@interface _CTLine : NSObject {
@public
    CFRange _strRange;
    CGPoint _lineOrigin;
    CGFloat _relativeXOffset;
    CGFloat _relativeYOffset;
    CGFloat _width;
    StrongId<NSMutableArray<_CTRun*>> _runs;

    // TODO::
    // Do we need these anymore?
    CGFloat _ascent, _descent, _leading;
}
@end

@interface _CTFrame : NSObject {
@public
    _CTFrameSetter* _frameSetter;
    CGRect _frameRect;
    std::vector<CGPoint> _lineOrigins;
    StrongId<NSMutableArray<_CTLine*>> _lines;

    // TODO::
    // Do we need these anymore?
    CGSize _totalSize;
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

typedef float (*WidthFinderFunc)(void* opaque, CFIndex idx, float offset, float height);

CORETEXT_EXPORT CFIndex _CTTypesetterSuggestLineBreakWithOffsetAndCallback(
    CTTypesetterRef ts, CFIndex index, double offset, WidthFinderFunc callback, void* opaque);

// Note: For some reason namemangling does not happen for these functions causing a linker error. Bug??
CORETEXT_EXTERNC_BEGIN
void _CTLineDraw(CTLineRef line, CGContextRef ctx, bool adjustTextPosition);
void _CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange, bool adjustTextPosition);
CORETEXT_EXTERNC_END