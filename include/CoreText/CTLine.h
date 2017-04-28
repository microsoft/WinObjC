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

#import <CoreText/CoreTextExport.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFAttributedString.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>

typedef const struct __CTLine* CTLineRef;

typedef uint32_t CTLineTruncationType;
enum { kCTLineTruncationStart = 0, kCTLineTruncationEnd = 1, kCTLineTruncationMiddle = 2 };
typedef uint32_t CTLineBoundsOptions;
enum {
    kCTLineBoundsExcludeTypographicLeading = 0 << 1,
    kCTLineBoundsExcludeTypographicShifts = 1 << 1,
    kCTLineBoundsUseHangingPunctuation = 1 << 2,
    kCTLineBoundsUseGlyphPathBounds = 1 << 3,
    kCTLineBoundsUseOpticalBounds = 1 << 4,
    kCTLineBoundsIncludeLanguageExtents = 1 << 5
};

CORETEXT_EXPORT CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef attrString);
CORETEXT_EXPORT CTLineRef CTLineCreateTruncatedLine(CTLineRef line,
                                                    double width,
                                                    CTLineTruncationType truncationType,
                                                    CTLineRef truncationToken);
CORETEXT_EXPORT CTLineRef CTLineCreateJustifiedLine(CTLineRef line,
                                                    CGFloat justificationFactor,
                                                    double justificationWidth) NOTINPLAN_METHOD;
CORETEXT_EXPORT void CTLineDraw(CTLineRef line, CGContextRef context);
CORETEXT_EXPORT CFIndex CTLineGetGlyphCount(CTLineRef line);
CORETEXT_EXPORT CFArrayRef CTLineGetGlyphRuns(CTLineRef line);
CORETEXT_EXPORT CFRange CTLineGetStringRange(CTLineRef line);
CORETEXT_EXPORT double CTLineGetPenOffsetForFlush(CTLineRef line, CGFloat flushFactor, double flushWidth);
CORETEXT_EXPORT CGRect CTLineGetImageBounds(CTLineRef line, CGContextRef context);
CORETEXT_EXPORT CGRect CTLineGetBoundsWithOptions(CTLineRef line, CTLineBoundsOptions options) NOTINPLAN_METHOD;
CORETEXT_EXPORT double CTLineGetTypographicBounds(CTLineRef line, CGFloat* ascent, CGFloat* descent, CGFloat* leading);
CORETEXT_EXPORT double CTLineGetTrailingWhitespaceWidth(CTLineRef line) STUB_METHOD;
CORETEXT_EXPORT CFIndex CTLineGetStringIndexForPosition(CTLineRef line, CGPoint position);
CORETEXT_EXPORT CGFloat CTLineGetOffsetForStringIndex(CTLineRef line, CFIndex charIndex, CGFloat* secondaryOffset);
CORETEXT_EXPORT CFTypeID CTLineGetTypeID();
