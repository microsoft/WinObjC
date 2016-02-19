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

#include "CoreTextInternal.h"
#include "CGPathInternal.h"

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

    sizeOut->width = 0;
    sizeOut->height = 0;

    float y = frameSize.size.height; //[font ascender];
    CFIndex curIdx = 0;
    NSString* string = [frameSetter->_typesetter->_attributedString string];
    CFIndex stringRange = [string length];

    for (;;) {
        CFIndex pos = CTTypesetterSuggestLineBreakWithOffset((CTTypesetterRef)(_CTTypesetter*)frameSetter->_typesetter,
                                                             curIdx,
                                                             frameSize.size.width,
                                                             0.0f);
        if (pos == curIdx)
            break;

        CFRange lineRange;
        lineRange.location = curIdx;
        lineRange.length = pos - curIdx;

        CTLineRef line = CTTypesetterCreateLineWithOffset((CTTypesetterRef)(_CTTypesetter*)frameSetter->_typesetter, lineRange, 0.0f);

        float ascent = 0.0f, descent = 0.0f, leading = 0.0f;
        float width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
        float lineHeight = ascent - descent + leading;

        if (ret) {
            CGPoint lineOrigin;
            lineOrigin.x = 0.0f;
            lineOrigin.y = y - ascent;
            [ret->_lines addObject:(id)line];
            ret->_lineOrigins.push_back(lineOrigin);
        }
        [line release];

        curIdx = pos;
        if (width > sizeOut->width) {
            sizeOut->width = width;
        }

        sizeOut->height += lineHeight;

        y -= lineHeight;
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
    [path _getBoundingBox:&frameSize];

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
