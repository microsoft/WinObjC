//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _CTLINE_H_
#define _CTLINE_H_

#import "CoreTextExport.h"
#import <CoreFoundation/CFAttributedString.h>
#import <CoreGraphics/CGContext.h>

ENABLE_IMPLICIT_BRIDGING

typedef struct __CTLine* CTLineRef;

enum {
    kCTLineTruncationStart = 0,
    kCTLineTruncationEnd = 1,
    kCTLineTruncationMiddle = 2,
};
typedef uint32_t CTLineTruncationType;

CORETEXT_EXPORT CFIndex CTLineGetStringIndexForPosition(CTLineRef line, CGPoint position);
CORETEXT_EXPORT double CTLineGetTypographicBounds(CTLineRef line, CGFloat* ascent, CGFloat* descent, CGFloat* leading);
CORETEXT_EXPORT CGFloat CTLineGetOffsetForStringIndex(CTLineRef line, CFIndex charIndex, CGFloat* secondaryOffset);
CORETEXT_EXPORT CFRange CTLineGetStringRange(CTLineRef line);
CORETEXT_EXPORT CFArrayRef CTLineGetGlyphRuns(CTLineRef line);
CORETEXT_EXPORT CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef string);
CORETEXT_EXPORT CTLineRef CTLineCreateTruncatedLine(CTLineRef line,
                                                    double width,
                                                    CTLineTruncationType truncationType,
                                                    CTLineRef truncationToken);
CORETEXT_EXPORT double CTLineGetPenOffsetForFlush(CTLineRef line, CGFloat flushFactor, double flushWidth);
CORETEXT_EXPORT void CTLineDraw(CTLineRef line, CGContextRef context);
CORETEXT_EXPORT CFIndex CTLineGetGlyphCount(CTLineRef line);

DISABLE_IMPLICIT_BRIDGING

#endif /* _CTLINE_H_ */