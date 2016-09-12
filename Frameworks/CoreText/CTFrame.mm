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
    [_frameSetter release];
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
        for (CFIndex i = 0; i < [framePtr->_lines count]; ++i) {
            // Lines are ordered vertically so we can stop once we find one outside of the frame
            _CTLine* line = framePtr->_lines[i];
            if (line->_lineOrigin.y >= 0) {
                count += line->_strRange.length;
            } else {
                break;
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
    return (CFArrayRef)(id)((_CTFrame*)frame)->_lines;
}

/**
 @Status Interoperable
*/
void CTFrameGetLineOrigins(CTFrameRef frame, CFRange range, CGPoint origins[]) {
    if (range.length == 0) {
        range.length = 0x7FFFFFF;
    }

    unsigned count = [((_CTFrame*)frame)->_lines count];
    int idx = 0;

    for (unsigned i = range.location; i < count && i < range.location + range.length; i++) {
        origins[idx] = ((_CTLine*)((_CTFrame*)frame)->_lines[idx])->_lineOrigin;
        idx++;
    }
}

/**
 @Status Interoperable
*/
void CTFrameDraw(CTFrameRef frame, CGContextRef ctx) {
    uint32_t count = [((_CTFrame*)frame)->_lines count];
    CGPoint curTextPos = CGContextGetTextPosition(ctx);

    for (uint32_t i = 0; i < count; i++) {
        _CTLine* curLine = [static_cast<_CTFrame*>(frame)->_lines objectAtIndex:i];
        CGPoint newPos = curTextPos + curLine->_lineOrigin;
        CGContextSetTextPosition(ctx, newPos.x, newPos.y);
        _CTLineDraw(static_cast<CTLineRef>(curLine), ctx, false);
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
