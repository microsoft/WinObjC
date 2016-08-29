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

#import <CoreText/CTFrameSetter.h>
#import <StubReturn.h>
#import "CoreTextInternal.h"
#import "CGPathInternal.h"

@implementation _CTFrameSetter : NSObject
- (void)dealloc {
    [super dealloc];
}
@end

static id _createFrame(_CTFrameSetter* frameSetter, CGRect frameSize, CGSize* sizeOut, bool createFrame) {
    _CTFrame* ret = nil;

    if (createFrame) {
        ret = [_CTFrame alloc];
        ret->_frameSetter = [frameSetter retain];
        ret->_frameRect = frameSize;

        ret->_lines.attach([NSMutableArray new]);
    }

    // Only fill in frame if there is text
    if (CFAttributedStringGetLength(static_cast<CFAttributedStringRef>(frameSetter->_typesetter->_attributedString))) {
        // Paragraph settings are expected at effective range 0
        NSDictionary* attributes = [frameSetter->_typesetter->_attributedString attributesAtIndex:0 effectiveRange:NULL];
        CTParagraphStyleRef style = reinterpret_cast<CTParagraphStyleRef>([attributes valueForKey:(id)kCTParagraphStyleAttributeName]);
        CTTextAlignment alignment = kCTLeftTextAlignment;
        if (style != nil) {
            if (!CTParagraphStyleGetValueForSpecifier(style, kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &alignment)) {
                // No alignment found, use default of left alignment
                alignment = kCTLeftTextAlignment;
            }
        }

        sizeOut->width = 0;
        sizeOut->height = 0;

        float y = frameSize.size.height; //[font ascender];
        CFIndex curIdx = 0;
        NSString* string = [frameSetter->_typesetter->_attributedString string];
        CFIndex stringRange = [string length];

        for (;;) {
            CFIndex pos =
                CTTypesetterSuggestLineBreak(static_cast<CTTypesetterRef>(frameSetter->_typesetter.get()), curIdx, frameSize.size.width);
            if (pos == curIdx) {
                break;
            }

            CFRange lineRange;
            lineRange.location = curIdx;
            lineRange.length = pos - curIdx;

            CTLineRef line = CTTypesetterCreateLine(static_cast<CTTypesetterRef>(frameSetter->_typesetter.get()), lineRange);

            float ascent = 0.0f, descent = 0.0f, leading = 0.0f;
            const float width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
            const float lineHeight = ascent - descent + leading;

            if (ret) {
                CGPoint lineOrigin;
                switch (alignment) {
                    case kCTRightTextAlignment:
                        lineOrigin.x = frameSize.size.width - width;
                        break;
                    case kCTCenterTextAlignment:
                        lineOrigin.x = (frameSize.size.width - width) / 2;
                        break;
                    default: // kCTLeftTextAlignment
                        lineOrigin.x = 0.0f;
                        break;
                }
                lineOrigin.y = y - ascent;
                [ret->_lines addObject:(id)line];
                ret->_lineOrigins.push_back(lineOrigin);
            }
            [static_cast<_CTLine*>(line) release];

            curIdx = pos;
            if (width > sizeOut->width) {
                sizeOut->width = width;
            }

            sizeOut->height += lineHeight;

            y -= lineHeight;
        }
    }

    if (ret) {
        ret->_totalSize = *sizeOut;
    }

    return ret;
}

/**
 @Status Interoperable
*/
CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTFrameSetter* ret = [_CTFrameSetter alloc];
    ret->_typesetter = (_CTTypesetter*)CTTypesetterCreateWithAttributedString(string);
    return (CTFramesetterRef)ret;
}

/**
 @Status Interoperable
*/
CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter, CFRange stringRange, CGPathRef path, CFDictionaryRef frameAttributes) {
    CGRect frameSize;
    _CGPathGetBoundingBoxInternal(path, &frameSize);

    CGSize sizeOut;
    id ret = _createFrame((_CTFrameSetter*)framesetter, frameSize, &sizeOut, true);

    return (CTFrameRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTTypesetterRef CTFramesetterGetTypesetter(CTFramesetterRef framesetter) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Always sets out parameter fitRange to stringRange value
*/
CGSize CTFramesetterSuggestFrameSizeWithConstraints(
    CTFramesetterRef framesetter, CFRange stringRange, CFDictionaryRef frameAttributes, CGSize constraints, CFRange* fitRange) {
    CGSize ret;
    if (fitRange)
        *fitRange = stringRange;

    CGRect frameSize = { 0, 0, 0, 0 };
    frameSize.size = constraints;

    _createFrame((_CTFrameSetter*)framesetter, frameSize, &ret, false);

    return ret;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTFramesetterGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
