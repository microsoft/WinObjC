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

#import <CoreGraphics/CoreGraphicsExport.h>

typedef struct __CGContext* CGContextRef;

#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGColor.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGGradient.h>
#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CGPDFPage.h>
#import <CoreGraphics/CGPath.h>
#import <CoreGraphics/CGPattern.h>
#import <CoreGraphics/CGShading.h>

#import <CoreFoundation/CFBase.h>

// clang-format off
typedef CF_OPTIONS(CFIndex, CGPathDrawingMode) {
//  CG Drawing Bitfield   |STROKE|   |FILL  |   |EO    |
    kCGPathStroke =       (1 << 0),
    kCGPathFill =                    (1 << 1),
    kCGPathFillStroke =   (1 << 0) | (1 << 1),
    kCGPathEOFill =                  (1 << 1) | (1 << 2),
    kCGPathEOFillStroke = (1 << 0) | (1 << 1) | (1 << 2),
};
// clang-format on

typedef CF_ENUM(CFIndex, CGTextEncoding) { kCGEncodingFontSpecific, kCGEncodingMacRoman };

typedef CF_ENUM(CFIndex, CGInterpolationQuality) {
    kCGInterpolationDefault = 0,
    kCGInterpolationNone = 1,
    kCGInterpolationLow = 2,
    kCGInterpolationMedium = 4,
    kCGInterpolationHigh = 3
};

typedef CF_ENUM(CFIndex, CGBlendMode) {
    // Each of these constants has a Facility and a Facility Value, documented below.
    // 0xAABB
    //   ^  ^
    //   +--|---- Composition Facility (Primitive Composition, Direct2D Blend Effect, Special Operator)
    //      +---- Composition facility value (usually mapped directly from Direct2D):
    //            Blends: https://msdn.microsoft.com/en-us/library/windows/desktop/dn934217(v=vs.85).aspx
    //            Composition: https://msdn.microsoft.com/en-us/library/windows/desktop/hh446995(v=vs.85).aspx

    // D2D Blend Effect Modes
    kCGBlendModeMultiply = 0x0100,
    kCGBlendModeScreen = 0x0101,
    kCGBlendModeDarken = 0x0102,
    kCGBlendModeLighten = 0x0103,

    kCGBlendModeColorBurn = 0x0105,
    kCGBlendModeColorDodge = 0x0109,

    kCGBlendModeOverlay = 0x010B,
    kCGBlendModeSoftLight = 0x010C,
    kCGBlendModeHardLight = 0x010D,

    kCGBlendModeDifference = 0x0112,
    kCGBlendModeExclusion = 0x0113,

    kCGBlendModeHue = 0x0114,
    kCGBlendModeSaturation = 0x0115,
    kCGBlendModeColor = 0x0116,
    kCGBlendModeLuminosity = 0x0117,

    // D2D Composite Draw Modes
    kCGBlendModeSourceOver = 0x0200,
    kCGBlendModeDestinationOver = 0x0201,

    kCGBlendModeSourceIn = 0x0402,
    kCGBlendModeDestinationIn = 0x0403,

    kCGBlendModeSourceOut = 0x0404,
    kCGBlendModeDestinationOut = 0x0205,

    kCGBlendModeSourceAtop = 0x0206,
    kCGBlendModeDestinationAtop = 0x0407,

    kCGBlendModeXOR = 0x0208,
    kCGBlendModePlusLighter = 0x0209,

    kCGBlendModeCopy = 0x040A,

    kCGBlendModePlusDarker = kCGBlendModePlusLighter, // [Unsupported right now, maps to kCGBlendModePlusLighter with a warning.]

    // Special mode (clears the affected region)
    kCGBlendModeClear = 0x0800,

    kCGBlendModeNormal = kCGBlendModeSourceOver,
};

// clang-format off
typedef CF_OPTIONS(CFIndex, CGTextDrawingMode) {
//  CG Drawing Bitfield     |FILL  |   |STROKE|   |CLIP  |
    kCGTextInvisible = 0,
    kCGTextFill =           (1 << 0),
    kCGTextStroke =                    (1 << 1),
    kCGTextFillStroke =     (1 << 0) | (1 << 1),
    kCGTextClip =                                 (1 << 2),
    kCGTextFillClip =       (1 << 0) |            (1 << 2),
    kCGTextStrokeClip =                (1 << 1) | (1 << 2),
    kCGTextFillStrokeClip = (1 << 0) | (1 << 1) | (1 << 2)
};
// clang-format on

COREGRAPHICS_EXPORT void CGContextFlush(CGContextRef c);
COREGRAPHICS_EXPORT CFTypeID CGContextGetTypeID();
COREGRAPHICS_EXPORT void CGContextRelease(CGContextRef c);
COREGRAPHICS_EXPORT CGContextRef CGContextRetain(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextSynchronize(CGContextRef c) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSaveGState(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextRestoreGState(CGContextRef c);
COREGRAPHICS_EXPORT CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextSetFlatness(CGContextRef c, CGFloat flatness) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetInterpolationQuality(CGContextRef c, CGInterpolationQuality quality);
COREGRAPHICS_EXPORT void CGContextSetLineCap(CGContextRef c, CGLineCap cap);
COREGRAPHICS_EXPORT void CGContextSetLineDash(CGContextRef c, CGFloat phase, const CGFloat* lengths, size_t count);
COREGRAPHICS_EXPORT void CGContextSetLineJoin(CGContextRef c, CGLineJoin join);
COREGRAPHICS_EXPORT void CGContextSetLineWidth(CGContextRef c, CGFloat width);
COREGRAPHICS_EXPORT void CGContextSetMiterLimit(CGContextRef c, CGFloat limit);

COREGRAPHICS_EXPORT void CGContextSetPatternPhase(CGContextRef c, CGSize phase);
COREGRAPHICS_EXPORT void CGContextSetFillPattern(CGContextRef c, CGPatternRef pattern, const CGFloat* components);
COREGRAPHICS_EXPORT void CGContextSetRenderingIntent(CGContextRef c, CGColorRenderingIntent intent) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetShouldAntialias(CGContextRef c, bool shouldAntialias);
COREGRAPHICS_EXPORT void CGContextSetStrokePattern(CGContextRef c, CGPatternRef pattern, const CGFloat* components);

COREGRAPHICS_EXPORT void CGContextSetBlendMode(CGContextRef c, CGBlendMode mode);
COREGRAPHICS_EXPORT void CGContextSetAllowsAntialiasing(CGContextRef c, bool allowsAntialiasing);
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSmoothing(CGContextRef c, bool allowsFontSmoothing);
COREGRAPHICS_EXPORT void CGContextSetShouldSmoothFonts(CGContextRef c, bool shouldSmoothFonts);
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSubpixelPositioning(CGContextRef c, bool allowsFontSubpixelPositioning);
COREGRAPHICS_EXPORT void CGContextSetShouldSubpixelPositionFonts(CGContextRef c, bool shouldSubpixelPositionFonts);
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSubpixelQuantization(CGContextRef c, bool allowsFontSubpixelQuantization);
COREGRAPHICS_EXPORT void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef c, bool shouldSubpixelQuantizeFonts);

COREGRAPHICS_EXPORT void CGContextAddArc(
    CGContextRef c, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise);
COREGRAPHICS_EXPORT void CGContextAddArcToPoint(CGContextRef c, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius);
COREGRAPHICS_EXPORT void CGContextAddCurveToPoint(
    CGContextRef c, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGContextAddLines(CGContextRef c, const CGPoint* points, size_t count);
COREGRAPHICS_EXPORT void CGContextAddLineToPoint(CGContextRef c, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGContextAddPath(CGContextRef c, CGPathRef path);

COREGRAPHICS_EXPORT CGPathRef CGContextCopyPath(CGContextRef c);

COREGRAPHICS_EXPORT void CGContextAddQuadCurveToPoint(CGContextRef c, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGContextAddRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextAddRects(CGContextRef c, const CGRect* rects, size_t count);
COREGRAPHICS_EXPORT void CGContextBeginPath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextClosePath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextMoveToPoint(CGContextRef c, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGContextAddEllipseInRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextClearRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextDrawPath(CGContextRef c, CGPathDrawingMode mode);
COREGRAPHICS_EXPORT void CGContextEOFillPath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextFillPath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextFillRect(CGContextRef c, CGRect rect);

COREGRAPHICS_EXPORT void CGContextFillRects(CGContextRef c, const CGRect* rects, size_t count);

COREGRAPHICS_EXPORT void CGContextFillEllipseInRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokePath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextStrokeRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokeRectWithWidth(CGContextRef c, CGRect rect, CGFloat width);
COREGRAPHICS_EXPORT void CGContextReplacePathWithStrokedPath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextStrokeEllipseInRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokeLineSegments(CGContextRef c, const CGPoint* points, size_t count);
COREGRAPHICS_EXPORT bool CGContextIsPathEmpty(CGContextRef c);

COREGRAPHICS_EXPORT CGPoint CGContextGetPathCurrentPoint(CGContextRef c);

COREGRAPHICS_EXPORT CGRect CGContextGetPathBoundingBox(CGContextRef c);

COREGRAPHICS_EXPORT bool CGContextPathContainsPoint(CGContextRef c, CGPoint point, CGPathDrawingMode mode);

COREGRAPHICS_EXPORT void CGContextClip(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextEOClip(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextClipToRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextClipToRects(CGContextRef c, const CGRect* rects, size_t count);
COREGRAPHICS_EXPORT CGRect CGContextGetClipBoundingBox(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextClipToMask(CGContextRef c, CGRect rect, CGImageRef mask);
COREGRAPHICS_EXPORT void CGContextSetAlpha(CGContextRef c, CGFloat alpha);

COREGRAPHICS_EXPORT void CGContextSetCMYKFillColor(
    CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha);

COREGRAPHICS_EXPORT void CGContextSetFillColor(CGContextRef c, const CGFloat* components);
COREGRAPHICS_EXPORT void CGContextSetCMYKStrokeColor(
    CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetFillColorSpace(CGContextRef c, CGColorSpaceRef space);

COREGRAPHICS_EXPORT void CGContextSetFillColorWithColor(CGContextRef c, CGColorRef color);
COREGRAPHICS_EXPORT void CGContextSetGrayFillColor(CGContextRef c, CGFloat gray, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetGrayStrokeColor(CGContextRef c, CGFloat gray, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetRGBFillColor(CGContextRef c, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetRGBStrokeColor(CGContextRef c, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha);

COREGRAPHICS_EXPORT void CGContextSetShadow(CGContextRef c, CGSize offset, CGFloat blur);
COREGRAPHICS_EXPORT void CGContextSetShadowWithColor(CGContextRef c, CGSize offset, CGFloat blur, CGColorRef color);

COREGRAPHICS_EXPORT void CGContextSetStrokeColor(CGContextRef c, const CGFloat* components);

COREGRAPHICS_EXPORT void CGContextSetStrokeColorSpace(CGContextRef c, CGColorSpaceRef space);

COREGRAPHICS_EXPORT void CGContextSetStrokeColorWithColor(CGContextRef c, CGColorRef color);
COREGRAPHICS_EXPORT void CGContextConcatCTM(CGContextRef c, CGAffineTransform transform);
COREGRAPHICS_EXPORT CGAffineTransform CGContextGetCTM(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextRotateCTM(CGContextRef c, CGFloat angle);
COREGRAPHICS_EXPORT void CGContextScaleCTM(CGContextRef c, CGFloat sx, CGFloat sy);
COREGRAPHICS_EXPORT void CGContextTranslateCTM(CGContextRef c, CGFloat tx, CGFloat ty);

COREGRAPHICS_EXPORT void CGContextBeginTransparencyLayer(CGContextRef c, CFDictionaryRef auxiliaryInfo);
COREGRAPHICS_EXPORT void CGContextBeginTransparencyLayerWithRect(CGContextRef c, CGRect rect, CFDictionaryRef auxInfo);
COREGRAPHICS_EXPORT void CGContextEndTransparencyLayer(CGContextRef c);

COREGRAPHICS_EXPORT void CGContextDrawTiledImage(CGContextRef c, CGRect rect, CGImageRef image);
COREGRAPHICS_EXPORT void CGContextDrawImage(CGContextRef c, CGRect rect, CGImageRef image);

COREGRAPHICS_EXPORT void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextDrawLinearGradient(
    CGContextRef c, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options);
COREGRAPHICS_EXPORT void CGContextDrawRadialGradient(CGContextRef c,
                                                     CGGradientRef gradient,
                                                     CGPoint startCenter,
                                                     CGFloat startRadius,
                                                     CGPoint endCenter,
                                                     CGFloat endRadius,
                                                     CGGradientDrawingOptions options);

COREGRAPHICS_EXPORT void CGContextDrawShading(CGContextRef c, CGShadingRef shading) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextBeginPage(CGContextRef c, const CGRect* mediaBox) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextEndPage(CGContextRef c) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextShowGlyphs(CGContextRef c, const CGGlyph* g, size_t count);
COREGRAPHICS_EXPORT void CGContextShowGlyphsAtPoint(CGContextRef c, CGFloat x, CGFloat y, const CGGlyph* glyphs, size_t count);
COREGRAPHICS_EXPORT void CGContextShowGlyphsWithAdvances(CGContextRef c, const CGGlyph* glyphs, const CGSize* advances, size_t count);

COREGRAPHICS_EXPORT void CGContextShowGlyphsAtPositions(CGContextRef c, const CGGlyph* glyphs, const CGPoint* positions, size_t count)
    STUB_METHOD;

COREGRAPHICS_EXPORT CGAffineTransform CGContextGetTextMatrix(CGContextRef c);
COREGRAPHICS_EXPORT CGPoint CGContextGetTextPosition(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextSelectFont(CGContextRef c, const char* name, CGFloat size, CGTextEncoding textEncoding);

COREGRAPHICS_EXPORT void CGContextSetCharacterSpacing(CGContextRef c, CGFloat spacing) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetFont(CGContextRef c, CGFontRef font);
COREGRAPHICS_EXPORT void CGContextSetFontSize(CGContextRef c, CGFloat size);
COREGRAPHICS_EXPORT void CGContextSetTextDrawingMode(CGContextRef c, CGTextDrawingMode mode);
COREGRAPHICS_EXPORT void CGContextSetTextMatrix(CGContextRef c, CGAffineTransform t);
COREGRAPHICS_EXPORT void CGContextSetTextPosition(CGContextRef c, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGContextShowText(CGContextRef c, const char* string, size_t length);

COREGRAPHICS_EXPORT void CGContextShowTextAtPoint(CGContextRef c, CGFloat x, CGFloat y, const char* string, size_t length);

COREGRAPHICS_EXPORT CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef c);
COREGRAPHICS_EXPORT CGPoint CGContextConvertPointToDeviceSpace(CGContextRef c, CGPoint point);
COREGRAPHICS_EXPORT CGPoint CGContextConvertPointToUserSpace(CGContextRef c, CGPoint point);
COREGRAPHICS_EXPORT CGSize CGContextConvertSizeToDeviceSpace(CGContextRef c, CGSize size);
COREGRAPHICS_EXPORT CGSize CGContextConvertSizeToUserSpace(CGContextRef c, CGSize size);
COREGRAPHICS_EXPORT CGRect CGContextConvertRectToDeviceSpace(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT CGRect CGContextConvertRectToUserSpace(CGContextRef c, CGRect rect);

/*!
 @function CGContextIwEnableEnhancedErrorHandling
 [WinObjC Extension]
 Turns on enhanced error handling for a CoreGraphics context.
 A CGContext that encounters errors when rendering will, by default, assert and abort.
 Enhanced handling both silences asserts and enables an interested consumer to determine whether a
 context has encountered a fatal drawing error.
 A consumer using enhanced error handling MUST check the status of a completed set of drawing
 operations using CGContextIwGetError() and determine whether to redraw the frame.

 @param  context the context to enlighten
*/
COREGRAPHICS_EXPORT void CGContextIwEnableEnhancedErrorHandling(CGContextRef context);

COREGRAPHICS_EXPORT const CFStringRef kCGErrorDomainIslandwood;

typedef CF_ENUM(CFIndex, CGContextIwErrorCode) {
    kCGContextErrorDeviceReset = 0x01,
    kCGContextErrorInvalidParameter,
};

/*!
 @function CGContextIwGetError
 [WinObjC Extension]
 Returns the error state of an enlightened context.

 @param  context the enlightened context
 @param  error   an output pointer that, upon a true return, will hold a retained CFErrorRef
 @result A boolean summarizing whether the context had an error state. If true, and if error
         is provided, *error will be populated.
*/
COREGRAPHICS_EXPORT bool CGContextIwGetError(CGContextRef context, CFErrorRef* /* returns-retained */ error);
