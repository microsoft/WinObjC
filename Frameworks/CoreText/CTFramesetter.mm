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

#import <CoreText/CTFramesetter.h>
#import <StubReturn.h>
#import <algorithm>
#import "CoreTextInternal.h"
#import "CGPathInternal.h"
#import <CoreText/DWriteWrapper.h>

using namespace std;

@implementation _CTFramesetter : NSObject
- (void)dealloc {
    _typesetter = nil;
    [super dealloc];
}
@end

static _CTFrame* _createFrame(_CTFramesetter* framesetter, CGRect frameSize, CGSize* sizeOut, bool createFrame) {
    _CTFrame* ret = nil;

    if (createFrame) {
        ret = [_CTFrame new];
        ret->_framesetter = framesetter;
        ret->_frameRect = frameSize;
    }

    // Call _DWriteWrapper to get _CTLine object list that makes up this frame
    _CTTypesetter* typesetter = static_cast<_CTTypesetter*>(framesetter->_typesetter);
    CFRange range = CFRangeMake(0, typesetter->_characters.size());
    NSArray<_CTLine*>* lines = _DWriteGetLines(typesetter, range, frameSize);
    if (createFrame) {
        ret->_lines = lines;
        for (_CTLine* line in static_cast<id<NSFastEnumeration>>(ret->_lines)) {
            ret->_lineOrigins.emplace_back(line->_lineOrigin);
        }
    }

    if (sizeOut && range.length != 0) {
        // TODO::
        // Is there a better way to do this - Investigate.
        // For now the below logic is used to calculate the frame size required to fit the text in -
        //     width = frame width as it is the constraint passed to DWrite to calculate renderable area width
        //     height = min(_lineOrigin.y of the last line in the frame + the _lineOrigin.y of the first line (so we atleast get the
        //              empty space that the first line got), frameSize.size.height)

        // Calculate width
        sizeOut->width = frameSize.size.width;

        // Calculate height
        _CTLine* firstLine = static_cast<_CTLine*>([lines objectAtIndex:0]);
        _CTLine* lastLine = static_cast<_CTLine*>([lines objectAtIndex:[lines count] - 1]);
        // TODO::
        // Modify this code once we move away from Cairo Freetype for rasterizing text.
        CGFloat originYFirstLine = frameSize.size.height - firstLine->_lineOrigin.y - frameSize.origin.y;
        CGFloat originYLastLine = frameSize.size.height - lastLine->_lineOrigin.y - frameSize.origin.y;
        sizeOut->height = min(originYLastLine + originYFirstLine, frameSize.size.height);
    }

    return ret;
}

/**
 @Status Interoperable
*/
CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTFramesetter* ret = [_CTFramesetter alloc];
    ret->_typesetter = static_cast<_CTTypesetter*>(CTTypesetterCreateWithAttributedString(string));
    return static_cast<CTFramesetterRef>(ret);
}

/**
 @Status Interoperable
*/
CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter, CFRange stringRange, CGPathRef path, CFDictionaryRef frameAttributes) {
    CGRect frameSize;
    _CGPathGetBoundingBoxInternal(path, &frameSize);

    CGSize sizeOut;
    _CTFrame* ret = _createFrame((_CTFramesetter*)framesetter, frameSize, &sizeOut, true);

    return static_cast<CTFrameRef>(ret);
}

/**
 @Status Stub
 @Notes
*/
CTTypesetterRef CTFramesetterGetTypesetter(CTFramesetterRef framesetter) {
    return framesetter ? static_cast<CTTypesetterRef>(static_cast<_CTFramesetter*>(framesetter)->_typesetter.get()) : nil;
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

    _createFrame(static_cast<_CTFramesetter*>(framesetter), frameSize, &ret, false);
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
