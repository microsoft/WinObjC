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
#import <CoreGraphics/CoreGraphicsExport.h>

typedef enum { kCGEncodingFontSpecific, kCGEncodingMacRoman } CGTextEncoding;
typedef enum {
    kCGInterpolationDefault = 0,
    kCGInterpolationNone = 1,
    kCGInterpolationLow = 2,
    kCGInterpolationMedium = 4,
    kCGInterpolationHigh = 3
} CGInterpolationQuality;
typedef enum {
    kCGBlendModeNormal,
    kCGBlendModeMultiply,
    kCGBlendModeScreen,
    kCGBlendModeOverlay,
    kCGBlendModeDarken,
    kCGBlendModeLighten,
    kCGBlendModeColorDodge,
    kCGBlendModeColorBurn,
    kCGBlendModeSoftLight,
    kCGBlendModeHardLight,
    kCGBlendModeDifference,
    kCGBlendModeExclusion,
    kCGBlendModeHue,
    kCGBlendModeSaturation,
    kCGBlendModeColor,
    kCGBlendModeLuminosity,
    kCGBlendModeClear,
    kCGBlendModeCopy,
    kCGBlendModeSourceIn,
    kCGBlendModeSourceOut,
    kCGBlendModeSourceAtop,
    kCGBlendModeDestinationOver,
    kCGBlendModeDestinationIn,
    kCGBlendModeDestinationOut,
    kCGBlendModeDestinationAtop,
    kCGBlendModeXOR,
    kCGBlendModePlusDarker,
    kCGBlendModePlusLighter
} CGBlendMode;
typedef enum {
    kCGTextFill,
    kCGTextStroke,
    kCGTextFillStroke,
    kCGTextInvisible,
    kCGTextFillClip,
    kCGTextStrokeClip,
    kCGTextFillStrokeClip,
    kCGTextClip
} CGTextDrawingMode;

COREGRAPHICS_EXPORT void CGContextFlush(CGContextRef c) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGContextGetTypeID() STUB_METHOD;
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

COREGRAPHICS_EXPORT void CGContextSetShouldAntialias(CGContextRef c, bool shouldAntialias) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetStrokePattern(CGContextRef c, CGPatternRef pattern, const CGFloat* components) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetBlendMode(CGContextRef c, CGBlendMode mode);
COREGRAPHICS_EXPORT void CGContextSetAllowsAntialiasing(CGContextRef c, bool allowsAntialiasing) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSmoothing(CGContextRef c, bool allowsFontSmoothing) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetShouldSmoothFonts(CGContextRef c, bool shouldSmoothFonts) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSubpixelPositioning(CGContextRef c, bool allowsFontSubpixelPositioning) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetShouldSubpixelPositionFonts(CGContextRef c, bool shouldSubpixelPositionFonts) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetAllowsFontSubpixelQuantization(CGContextRef c, bool allowsFontSubpixelQuantization) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef c, bool shouldSubpixelQuantizeFonts) STUB_METHOD;

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

COREGRAPHICS_EXPORT void CGContextFillRects(CGContextRef c, const CGRect* rects, size_t count) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextFillEllipseInRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokePath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextStrokeRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokeRectWithWidth(CGContextRef c, CGRect rect, CGFloat width);
COREGRAPHICS_EXPORT void CGContextReplacePathWithStrokedPath(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextStrokeEllipseInRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextStrokeLineSegments(CGContextRef c, const CGPoint* points, size_t count);
COREGRAPHICS_EXPORT bool CGContextIsPathEmpty(CGContextRef c);

COREGRAPHICS_EXPORT CGPoint CGContextGetPathCurrentPoint(CGContextRef c) STUB_METHOD;

COREGRAPHICS_EXPORT CGRect CGContextGetPathBoundingBox(CGContextRef c);

COREGRAPHICS_EXPORT bool CGContextPathContainsPoint(CGContextRef c, CGPoint point, CGPathDrawingMode mode) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextClip(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextEOClip(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextClipToRect(CGContextRef c, CGRect rect);
COREGRAPHICS_EXPORT void CGContextClipToRects(CGContextRef c, const CGRect* rects, size_t count);
COREGRAPHICS_EXPORT CGRect CGContextGetClipBoundingBox(CGContextRef c);
COREGRAPHICS_EXPORT void CGContextClipToMask(CGContextRef c, CGRect rect, CGImageRef mask);
COREGRAPHICS_EXPORT void CGContextSetAlpha(CGContextRef c, CGFloat alpha);

COREGRAPHICS_EXPORT void CGContextSetCMYKFillColor(
    CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetFillColor(CGContextRef c, const CGFloat* components);
COREGRAPHICS_EXPORT void CGContextSetCMYKStrokeColor(
    CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextSetFillColorSpace(CGContextRef c, CGColorSpaceRef space) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextSetFillColorWithColor(CGContextRef c, CGColorRef color);
COREGRAPHICS_EXPORT void CGContextSetGrayFillColor(CGContextRef c, CGFloat gray, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetGrayStrokeColor(CGContextRef c, CGFloat gray, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetRGBFillColor(CGContextRef c, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha);
COREGRAPHICS_EXPORT void CGContextSetRGBStrokeColor(CGContextRef c, CGFloat red, CGFloat green, CGFloat blue, CGFloat alpha);

COREGRAPHICS_EXPORT void CGContextSetShadow(CGContextRef c, CGSize offset, CGFloat blur);
COREGRAPHICS_EXPORT void CGContextSetShadowWithColor(CGContextRef c, CGSize offset, CGFloat blur, CGColorRef color);

COREGRAPHICS_EXPORT void CGContextSetStrokeColor(CGContextRef c, const CGFloat* components);

COREGRAPHICS_EXPORT void CGContextSetStrokeColorSpace(CGContextRef c, CGColorSpaceRef space) STUB_METHOD;

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

COREGRAPHICS_EXPORT void CGContextShowGlyphsAtPositions(CGContextRef c, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count)
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
COREGRAPHICS_EXPORT void CGContextShowText(CGContextRef c, const char* string, size_t length) STUB_METHOD;

COREGRAPHICS_EXPORT void CGContextShowTextAtPoint(CGContextRef c, CGFloat x, CGFloat y, const char* string, size_t length);

COREGRAPHICS_EXPORT CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef c) STUB_METHOD;
COREGRAPHICS_EXPORT CGPoint CGContextConvertPointToDeviceSpace(CGContextRef c, CGPoint point) STUB_METHOD;
COREGRAPHICS_EXPORT CGPoint CGContextConvertPointToUserSpace(CGContextRef c, CGPoint point) STUB_METHOD;
COREGRAPHICS_EXPORT CGSize CGContextConvertSizeToDeviceSpace(CGContextRef c, CGSize size) STUB_METHOD;
COREGRAPHICS_EXPORT CGSize CGContextConvertSizeToUserSpace(CGContextRef c, CGSize size) STUB_METHOD;
COREGRAPHICS_EXPORT CGRect CGContextConvertRectToDeviceSpace(CGContextRef c, CGRect rect) STUB_METHOD;
COREGRAPHICS_EXPORT CGRect CGContextConvertRectToUserSpace(CGContextRef c, CGRect rect) STUB_METHOD;
