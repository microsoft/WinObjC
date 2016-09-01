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

@interface _CTFrame : NSObject {
@public
    _CTFrameSetter* _frameSetter;
    CGRect _frameRect;
    StrongId<NSMutableArray> _lines;

    // TODO::
    // Do we need these anymore?
    CGSize _totalSize;
    std::vector<CGPoint> _lineOrigins;
}
@end

@interface _CTLine : NSObject {
@public
    _CTTypesetter* _typeSetter;
    CFRange _strRange;
    CGPoint _lineOrigin;
    StrongId<NSMutableArray> _runs;

    // TODO::
    // Do we need these anymore?
    CGFloat _width;
    CGFloat _ascent, _descent, _leading;
}
@end

@interface _CTRun : NSObject {
@public
    StrongId<NSMutableDictionary> _attributes;
    CFRange _range;
    float _xPos;
    float _yPos;
    StrongId<NSString> _stringFragment;
    std::vector<CGSize> _glyphAdvances;

    // TODO::
    // Do we need these anymore?
    std::vector<CGPoint> _glyphOrigins;
    std::vector<WORD> _characters;
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