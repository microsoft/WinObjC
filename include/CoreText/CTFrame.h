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

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGPath.h>

typedef const struct __CTFrame* CTFrameRef;
typedef uint32_t CTFramePathFillRule;
typedef uint32_t CTFrameProgression;

enum { kCTFramePathFillEvenOdd = 0, kCTFramePathFillWindingNumber = 1 };
enum { kCTFrameProgressionTopToBottom = 0, kCTFrameProgressionRightToLeft = 1 };

CORETEXT_EXPORT const CFStringRef kCTFrameProgressionAttributeName;
CORETEXT_EXPORT const CFStringRef kCTFramePathFillRuleAttributeName;
CORETEXT_EXPORT const CFStringRef kCTFramePathWidthAttributeName;
CORETEXT_EXPORT const CFStringRef kCTFrameClippingPathsAttributeName;
CORETEXT_EXPORT const CFStringRef kCTFramePathClippingPathAttributeName;

CORETEXT_EXPORT CFRange CTFrameGetStringRange(CTFrameRef frame);
CORETEXT_EXPORT CFRange CTFrameGetVisibleStringRange(CTFrameRef frame);
CORETEXT_EXPORT CGPathRef CTFrameGetPath(CTFrameRef frame);
CORETEXT_EXPORT CFDictionaryRef CTFrameGetFrameAttributes(CTFrameRef frame) STUB_METHOD;
CORETEXT_EXPORT CFArrayRef CTFrameGetLines(CTFrameRef frame);
CORETEXT_EXPORT void CTFrameGetLineOrigins(CTFrameRef frame, CFRange range, CGPoint origins[]);
CORETEXT_EXPORT void CTFrameDraw(CTFrameRef frame, CGContextRef context);
CORETEXT_EXPORT CFTypeID CTFrameGetTypeID() STUB_METHOD;
