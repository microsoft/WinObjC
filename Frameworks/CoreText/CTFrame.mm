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

#import <CoreText/CTFrame.h>
#import <StubReturn.h>

#import "CoreTextInternal.h"

const CFStringRef kCTFrameProgressionAttributeName = static_cast<CFStringRef>(@"kCTFrameProgressionAttributeName");
const CFStringRef kCTFramePathFillRuleAttributeName = static_cast<CFStringRef>(@"kCTFramePathFillRuleAttributeName");
const CFStringRef kCTFramePathWidthAttributeName = static_cast<CFStringRef>(@"kCTFramePathWidthAttributeName");
const CFStringRef kCTFrameClippingPathsAttributeName = static_cast<CFStringRef>(@"kCTFrameClippingPathsAttributeName");
const CFStringRef kCTFramePathClippingPathAttributeName = static_cast<CFStringRef>(@"kCTFramePathClippingPathAttributeName");

@implementation _CTFrame : NSObject
- (void)dealloc {
    _framesetter = nil;
    _lines = nil;
    [super dealloc];
}
@end

/**
 @Status Interoperable
 @Notes
*/
CFRange CTFrameGetStringRange(CTFrameRef frame) {
    _CTFrame* framePtr = static_cast<_CTFrame*>(frame);
    CFIndex count = 0;
    if (framePtr) {
        for (_CTLine* line in [framePtr->_lines objectEnumerator]) {
            count += line->_strRange.length;
        }
    }
    return CFRangeMake(0, count);
}

/**
 @Status Interoperable
 @Notes
*/
CFRange CTFrameGetVisibleStringRange(CTFrameRef frame) {
    _CTFrame* framePtr = static_cast<_CTFrame*>(frame);
    CFIndex count = 0;
    if (framePtr) {
        for (_CTLine* line in [framePtr->_lines objectEnumerator]) {
            if (line->_lineOrigin.y < framePtr->_frameRect.size.height && line->_lineOrigin.y > 0) {
                count += line->_strRange.length;
            }
        }
    }
    return CFRangeMake(0, count);
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CTFrameGetPath(CTFrameRef frame) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CTFrameGetFrameAttributes(CTFrameRef frame) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CFArrayRef CTFrameGetLines(CTFrameRef frame) {
    return frame ? static_cast<CFArrayRef>(static_cast<_CTFrame*>(frame)->_lines.get()) : nil;
}

/**
 @Status Interoperable
*/
void CTFrameGetLineOrigins(CTFrameRef frameRef, CFRange range, CGPoint origins[]) {
    _CTFrame* frame = static_cast<_CTFrame*>(frameRef);
    if (frame) {
        _boundedCopy(range, frame->_lineOrigins.size(), frame->_lineOrigins.data(), origins);
    }
}

/**
 @Status Interoperable
*/
void CTFrameDraw(CTFrameRef frame, CGContextRef ctx) {
    uint32_t count = [((_CTFrame*)frame)->_lines count];
    CGPoint curTextPos = CGContextGetTextPosition(ctx);
    if (frame && ctx) {
        CGPoint curTextPos = CGContextGetTextPosition(ctx);
        for (_CTLine* line in [static_cast<_CTFrame*>(frame)->_lines objectEnumerator]) {
            CGPoint newPos = curTextPos + line->_lineOrigin;
            CGContextSetTextPosition(ctx, newPos.x, newPos.y);
            _CTLineDraw(static_cast<CTLineRef>(line), ctx, false);
        }
    }
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTFrameGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}