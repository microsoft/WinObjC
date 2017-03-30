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

#import "DWriteWrapper_CoreText.h"
#import "CoreTextInternal.h"
#import "CGContextInternal.h"
#import "CGPathInternal.h"

const CFStringRef kCTFrameProgressionAttributeName = CFSTR("kCTFrameProgressionAttributeName");
const CFStringRef kCTFramePathFillRuleAttributeName = CFSTR("kCTFramePathFillRuleAttributeName");
const CFStringRef kCTFramePathWidthAttributeName = CFSTR("kCTFramePathWidthAttributeName");
const CFStringRef kCTFrameClippingPathsAttributeName = CFSTR("kCTFrameClippingPathsAttributeName");
const CFStringRef kCTFramePathClippingPathAttributeName = CFSTR("kCTFramePathClippingPathAttributeName");

@implementation _CTFrame : NSObject
- (instancetype)init {
    if ([super init]) {
        _lines.attach([NSMutableArray new]);
    }

    return self;
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
        for (_CTLine* line in static_cast<id<NSFastEnumeration>>(framePtr->_lines)) {
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
        for (size_t i = 0; i < framePtr->_lineOrigins.size(); ++i) {
            if (framePtr->_lineOrigins[i].y < framePtr->_frameRect.size.height) {
                _CTLine* line = static_cast<_CTLine*>([framePtr->_lines objectAtIndex:i]);
                count += line->_strRange.length;
            }
        }
    }
    return CFRangeMake(0, count);
}

/**
 @Status Interoperable
 @Notes
*/
CGPathRef CTFrameGetPath(CTFrameRef frame) {
    return frame ? static_cast<_CTFrame*>(frame)->_path.get() : nil;
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
void CTFrameDraw(CTFrameRef frameRef, CGContextRef ctx) {
    _CTFrame* frame = static_cast<_CTFrame*>(frameRef);
    if (frame && ctx) {
        std::vector<GlyphRunData> runs;

        for (size_t i = 0; i < frame->_lineOrigins.size() && (frame->_lineOrigins[i].y < frame->_frameRect.size.height); ++i) {
            _CTLine* line = static_cast<_CTLine*>([frame->_lines objectAtIndex:i]);
            CGPoint relativePosition = frame->_lineOrigins[i];
            for (size_t j = 0; j < [line->_runs count]; ++j) {
                _CTRun* curRun = [line->_runs objectAtIndex:j];
                if (j > 0) {
                    // Adjusts x position relative to the last run drawn
                    relativePosition.x += curRun->_relativeXOffset;
                }
                runs.emplace_back(GlyphRunData{ &curRun->_dwriteGlyphRun, relativePosition, (CFDictionaryRef)curRun->_attributes.get() });
            }
        }

        if (!runs.empty()) {
            // Need to invert and translate coordinates so frame draws from top-left
            CGRect boundingRect = CGPathGetBoundingBox(frame->_path.get());
            CGContextTranslateCTM(ctx, 0, boundingRect.size.height);

            // Invert Text Matrix and CTM so glyphs are drawn in correct orientation and position
            CGAffineTransform textMatrix = CGContextGetTextMatrix(ctx);
            CGContextSetTextMatrix(ctx, CGAffineTransformMake(textMatrix.a, -textMatrix.b, textMatrix.c, -textMatrix.d, 0, 0));
            CGContextScaleCTM(ctx, 1.0f, -1.0f);

            _CGContextPushBeginDraw(ctx);
            auto popEnd = wil::ScopeExit([&]() {
                // Restore CTM and Text Matrix to values before we modified them
                CGContextSetTextMatrix(ctx, textMatrix);
                CGContextScaleCTM(ctx, 1.0f, -1.0f);
                CGContextTranslateCTM(ctx, 0, -boundingRect.size.height);
                _CGContextPopEndDraw(ctx);
            });

            _CGContextDrawGlyphRuns(ctx, runs.data(), runs.size());
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

// Convenience private function for NSString+UIKitAdditions
CGSize _CTFrameGetSize(CTFrameRef frame) {
    return frame ? static_cast<_CTFrame*>(frame)->_frameRect.size : CGSize{};
}
