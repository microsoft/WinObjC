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

#import <CoreText/CoreTextExport.h>

#import <CoreFoundation/CFDictionary.h>

#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGGeometry.h>

typedef const struct __CTRun* CTRunRef;
typedef uint32_t CTRunStatus;
enum {
    kCTRunStatusNoStatus = 0,
    kCTRunStatusRightToLeft = (1 << 0),
    kCTRunStatusNonMonotonic = (1 << 1),
    kCTRunStatusHasNonIdentityMatrix = (1 << 2)
};

CORETEXT_EXPORT CFIndex CTRunGetGlyphCount(CTRunRef run);
CORETEXT_EXPORT CFDictionaryRef CTRunGetAttributes(CTRunRef run);
CORETEXT_EXPORT CTRunStatus CTRunGetStatus(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT const CGGlyph* CTRunGetGlyphsPtr(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]) STUB_METHOD;
CORETEXT_EXPORT const CGPoint* CTRunGetPositionsPtr(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT void CTRunGetPositions(CTRunRef run, CFRange range, CGPoint buffer[]);
CORETEXT_EXPORT const CGSize* CTRunGetAdvancesPtr(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT void CTRunGetAdvances(CTRunRef run, CFRange range, CGSize buffer[]);
CORETEXT_EXPORT const CFIndex* CTRunGetStringIndicesPtr(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT void CTRunGetStringIndices(CTRunRef run, CFRange range, CFIndex buffer[]) STUB_METHOD;
CORETEXT_EXPORT CFRange CTRunGetStringRange(CTRunRef run);
CORETEXT_EXPORT double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat* ascent, CGFloat* descent, CGFloat* leading);
CORETEXT_EXPORT CGRect CTRunGetImageBounds(CTRunRef run, CGContextRef context, CFRange range) STUB_METHOD;
CORETEXT_EXPORT void CTRunDraw(CTRunRef run, CGContextRef context, CFRange range);
CORETEXT_EXPORT CGAffineTransform CTRunGetTextMatrix(CTRunRef run) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTRunGetTypeID() STUB_METHOD;
