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

#import <StubReturn.h>
#import <Starboard.h>
#import <math.h>

#import "CGSurfaceInfoInternal.h" // TODO(DH) Evaluate the need for this header.

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGPath.h>
#import <CoreGraphics/CGLayer.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGradient.h>
#import "CGColorSpaceInternal.h"
#import "CGContextInternal.h"

#import <CFCppBase.h>

#include <COMIncludes.h>
#import <d2d1.h>
#import <d2d1_1.h>
#import <d2d1effects_2.h>
#import <wrl/client.h>
#include <COMIncludes_end.h>
#import <LoggingNative.h>

#import <list>
#import <vector>
#import <stack>

using namespace Microsoft::WRL;

static inline D2D_RECT_F __CGRectToD2D_F(CGRect rect) {
    return {
        rect.origin.x, rect.origin.y, rect.origin.x + rect.size.width, rect.origin.y + rect.size.height,
    };
}

struct __CGContextDrawingState {
    // This is populated when the state is saved, and contains the D2D parameters that CG does not know.
    ComPtr<ID2D1DrawingStateBlock> d2dState{ nullptr };

    // Fills
    ComPtr<ID2D1Brush> fillBrush{ nullptr };

    // Strokes
    ComPtr<ID2D1Brush> strokeBrush{ nullptr };
    ComPtr<ID2D1StrokeStyle> strokeStyle{ nullptr };
    D2D1_STROKE_STYLE_PROPERTIES strokeProperties{
        D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE_FLAT,
        D2D1_LINE_JOIN_MITER,
        10.f, // Default from Reference Docs
        D2D1_DASH_STYLE_SOLID,
        0.f,
    };
    std::vector<CGFloat> dashes{};

    CGFloat lineWidth = 1.0f;

    CGFloat flatness = 0.0f;

    // Image Drawing
    D2D1_INTERPOLATION_MODE bitmapInterpolationMode = D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR;

    // Userspace Coordinate Transformation
    CGAffineTransform transform{ CGAffineTransformIdentity };
    CGAffineTransform textMatrix{ CGAffineTransformIdentity };

    // Alpha Blending
    CGFloat alpha = 1.0f;
};

struct __CGContextImpl {
    ComPtr<ID2D1RenderTarget> renderTarget{ nullptr };

    // Calculated at creation time, this transform flips CG's drawing commands,
    // anchored in the bottom left, to D2D's top-left coordinate system.
    CGAffineTransform cgCompatibilityTransform{ CGAffineTransformIdentity };

    std::stack<__CGContextDrawingState> stateStack{};

    woc::unique_cf<CGMutablePathRef> currentPath{ nullptr };

    // TODO(DH) GH#1070 evaluate these defaults; they should be set by context creators.
    bool allowsAntialiasing = false;
    bool allowsFontSmoothing = false;
    bool allowsFontSubpixelPositioning = false;
    bool allowsFontSubpixelQuantization = false;

    __CGContextImpl() {
        // Set up a default/baseline state
        stateStack.emplace();
    }
};

struct __CGContext: CoreFoundation::CppBase<__CGContext, __CGContextImpl> {
    inline ComPtr<ID2D1RenderTarget>& RenderTarget() {
        return _impl.renderTarget;
    }

    inline std::stack<__CGContextDrawingState>& GStateStack() {
        return _impl.stateStack;
    }

    inline __CGContextDrawingState& CurrentGState() {
        return GStateStack().top();
    }

    inline void ClearPath() {
        _impl.currentPath.reset();
    }

    inline ComPtr<ID2D1Factory> Factory() {
        ComPtr<ID2D1Factory> factory;
        _impl.renderTarget->GetFactory(&factory);
        return factory;
    }
};

#pragma region CFRuntimeClass
/**
 @Status Interoperable
*/
CFTypeID CGContextGetTypeID() {
    return __CGContext::GetTypeID();
}
#pragma endregion

static const wchar_t* TAG = L"CGContext";

static void __CGContextInitWithRenderTarget(CGContextRef context, ID2D1RenderTarget* renderTarget) {
    context->_impl.renderTarget = renderTarget;

    // Reference platform defaults:
    // * Fill  : fully transparent black
    // * Stroke: fully opaque black
    // If a context does not support alpha, the default fill looks like fully opaque black.
    CGContextSetRGBFillColor(context, 0, 0, 0, 0);
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);
}

CGContextRef _CGContextCreateWithD2DRenderTarget(ID2D1RenderTarget* renderTarget) {
    FAIL_FAST_HR_IF_NULL(E_INVALIDARG, renderTarget);
    CGContextRef context = __CGContext::CreateInstance(kCFAllocatorDefault);
    __CGContextInitWithRenderTarget(context, renderTarget);
    return context;
}

#pragma region Lifetime
/**
 @Status Interoperable
*/
CGContextRef CGContextRetain(CGContextRef context) {
    CFRetain((CFTypeRef)context);
    return context;
}

/**
 @Status Interoperable
*/
void CGContextRelease(CGContextRef context) {
    if (!context) {
        return;
    }

    CFRelease((CFTypeRef)context);
}
#pragma endregion

#pragma region Drawing Parameters
/**
 @Status Interoperable
*/
void CGContextSetBlendMode(CGContextRef context, CGBlendMode mode) {
    UNIMPLEMENTED();
}

CGBlendMode CGContextGetBlendMode(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextSetFillPattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetPatternPhase(CGContextRef context, CGSize phase) {
    UNIMPLEMENTED();
}

#pragma region Text Rendering - Parameters
/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef context, CGFloat spacing) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef context, CGTextDrawingMode mode) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef context, CGFontRef font) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSelectFont(CGContextRef context, const char* name, CGFloat size, CGTextEncoding encoding) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef context, CGFloat ptSize) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextMatrix(CGContextRef context, CGAffineTransform matrix) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef context, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion

#pragma region Text Rendering - Operations
/**
 @Status Interoperable
*/
void CGContextShowTextAtPoint(CGContextRef pContext, CGFloat x, CGFloat y, const char* str, size_t length) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsAtPoint(CGContextRef context, CGFloat x, CGFloat y, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef context, const CGGlyph* glyphs, CGSize* advances, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef context, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Userspace Coordinate Transformation
/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef context) {
    auto& state = context->CurrentGState();
    return state.transform;
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef context, CGFloat x, CGFloat y) {
    CGContextConcatCTM(context, CGAffineTransformMakeTranslation(x, y));
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef context, CGFloat sx, CGFloat sy) {
    CGContextConcatCTM(context, CGAffineTransformMakeScale(sx, sy));
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef context, CGFloat angle) {
    CGContextConcatCTM(context, CGAffineTransformMakeRotation(angle));
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef context, CGAffineTransform t) {
    auto& state = context->CurrentGState();
    state.transform = CGAffineTransformConcat(state.transform, t);
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef context, CGAffineTransform transform) {
    auto& state = context->CurrentGState();
    state.transform = transform;
}
#pragma endregion

#pragma region Image Drawing - Operations
/// TODO(DH): GH#1078 Image Drawing
/**
 @Status Interoperable
*/
void CGContextDrawImage(CGContextRef context, CGRect rect, CGImageRef image) {
    if (!image) {
        TraceWarning(TAG, L"Img == nullptr!");
        return;
    }
    if (!context) {
        TraceWarning(TAG, L"CGContextDrawImage: context == nullptr!");
        return;
    }

    UNIMPLEMENTED();
}

void CGContextDrawImageRect(CGContextRef context, CGImageRef image, CGRect src, CGRect dst) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef context, CGRect rect, CGImageRef image) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Clipping and Masking
/// TODO(DH): GH#future Clipping and Masking
/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef context, CGRect rect) {
    CGContextBeginPath(context);
    CGContextAddRect(context, rect);
    CGContextClip(context);
}

/**
 @Status Interoperable
*/
void CGContextClipToRects(CGContextRef context, const CGRect* rects, unsigned count) {
    if (!rects || count == 0) {
        return;
    }

    CGContextBeginPath(context);
    CGContextAddRects(context, rects, count);
    CGContextClip(context);
}

/**
 @Status Caveat
 @Notes Limited bitmap format support
*/
void CGContextClipToMask(CGContextRef context, CGRect dest, CGImageRef image) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Colors - Stroke
/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetStrokeColor(CGContextRef context, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetStrokeColorWithColor(CGContextRef context, CGColorRef color) {
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBStrokeColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetStrokeColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    CGContextSetRGBStrokeColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().strokeBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKStrokeColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    CGContextSetRGBStrokeColor(context,
                               (1.0f - cyan) * (1.0f - black),
                               (1.0f - magenta) * (1.0f - black),
                               (1.0f - yellow) * (1.0f - black),
                               alpha);
}
#pragma endregion

#pragma region Colors - Fill
/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetFillColor(CGContextRef context, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetFillColorWithColor(CGContextRef context, CGColorRef color) {
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBFillColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetFillColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    CGContextSetRGBFillColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().fillBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKFillColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    CGContextSetRGBFillColor(context,
                             (1.0f - cyan) * (1.0f - black),
                             (1.0f - magenta) * (1.0f - black),
                             (1.0f - yellow) * (1.0f - black),
                             alpha);
}
#pragma endregion

#pragma region Graphics States
/**
 @Status Interoperable
*/
void CGContextSaveGState(CGContextRef context) {
    auto& oldState = context->CurrentGState();

    // This uses the drawing state's copy constructor.
    context->GStateStack().emplace(oldState);

    auto factory = context->Factory();
    ComPtr<ID2D1DrawingStateBlock> drawingState;
    FAIL_FAST_IF_FAILED(factory->CreateDrawingStateBlock(&drawingState));

    context->RenderTarget()->SaveDrawingState(drawingState.Get());
    oldState.d2dState = drawingState;
}

/**
 @Status Interoperable
*/
void CGContextRestoreGState(CGContextRef context) {
    if (context->GStateStack().size() <= 1) {
        TraceError(TAG, L"Invalid attempt to pop last graphics state.");
        return;
    }

    context->GStateStack().pop();
    auto& newState = context->CurrentGState();
    context->RenderTarget()->RestoreDrawingState(newState.d2dState.Get());
    newState.d2dState = nullptr;
}
#pragma endregion

#pragma region Shape Drawing - Operations
/**
 @Status Interoperable
*/
void CGContextClearRect(CGContextRef context, CGRect rect) {
    ComPtr<ID2D1RenderTarget> renderTarget = context->RenderTarget();
    renderTarget->PushAxisAlignedClip(__CGRectToD2D_F(rect), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    renderTarget->Clear(nullptr); // transparent black clear
    renderTarget->PopAxisAlignedClip();
}

static void __CGContextDrawGeometry(CGContextRef context, ID2D1Geometry* geometry, CGPathDrawingMode drawMode) {
    ComPtr<ID2D1RenderTarget> renderTarget = context->RenderTarget();
    auto& currentState = context->CurrentGState();

    ComPtr<ID2D1DeviceContext> deviceContext;
    FAIL_FAST_IF_FAILED(renderTarget.As(&deviceContext));

    D2D1_SIZE_F targetSize = renderTarget->GetSize();
    ComPtr<ID2D1Image> originalTarget;
    deviceContext->GetTarget(&originalTarget);

    deviceContext->BeginDraw();

    ComPtr<ID2D1CommandList> commandList;
    FAIL_FAST_IF_FAILED(deviceContext->CreateCommandList(&commandList));
    deviceContext->SetTarget(commandList.Get());

    CGAffineTransform& currentTransform = currentState.transform;
    CGAffineTransform transform = CGAffineTransformScale(currentTransform, 1.0, -1.0);
    transform = CGAffineTransformTranslate(transform, 0., targetSize.height);
    deviceContext->SetTransform({ transform.a, transform.b, transform.c, transform.d, transform.tx, transform.ty });

    if (drawMode & kCGPathFill) {
        if (drawMode & kCGPathEOFill) {
            // TODO(DH): GH#1077 Regenerate geometry in Even/Odd fill mode.
        }
        deviceContext->FillGeometry(geometry, currentState.fillBrush.Get());
    }

    if (drawMode & kCGPathStroke) {
        ComPtr<ID2D1Factory> factory;
        deviceContext->GetFactory(&factory);

        // TODO(DH): GH#1077 Do not recreate for every drawing operation
        ComPtr<ID2D1StrokeStyle> strokeStyle;
        // dashes must be adjusted to be based on line width
        std::vector<CGFloat> adjustedDashes{ currentState.dashes };
        for (float& f : adjustedDashes) {
            f /= currentState.lineWidth;
        }
        FAIL_FAST_IF_FAILED(
            factory->CreateStrokeStyle(currentState.strokeProperties, adjustedDashes.data(), adjustedDashes.size(), &strokeStyle));

        deviceContext->DrawGeometry(geometry, currentState.strokeBrush.Get(), currentState.lineWidth, strokeStyle.Get());
    }

    deviceContext->EndDraw();
    commandList->Close();

    deviceContext->BeginDraw();
    deviceContext->SetTarget(originalTarget.Get());

    bool layer = false;
    if (currentState.alpha != 1.0f || false /* mask, clip, etc. */) {
        layer = true;
        renderTarget->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(),
                                                      nullptr,
                                                      D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
                                                      D2D1::IdentityMatrix(),
                                                      currentState.alpha),
                                nullptr);
    }

    deviceContext->DrawImage(commandList.Get());

    if (layer) {
        renderTarget->PopLayer();
    }

    FAIL_FAST_IF_FAILED(deviceContext->EndDraw());
}

/**
 @Status Interoperable
*/
void CGContextStrokeRect(CGContextRef context, CGRect rect) {
    auto factory = context->Factory();

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    FAIL_FAST_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D_F(rect), &rectGeometry));
    FAIL_FAST_IF_FAILED(rectGeometry.As(&geometry));

    __CGContextDrawGeometry(context, geometry.Get(), kCGPathStroke);

    context->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRectWithWidth(CGContextRef context, CGRect rect, CGFloat width) {
    CGContextSaveGState(context);
    CGContextSetLineWidth(context, width);
    CGContextStrokeRect(context, rect);
    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
*/
void CGContextFillRect(CGContextRef context, CGRect rect) {
    auto factory = context->Factory();

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    FAIL_FAST_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D_F(rect), &rectGeometry));
    FAIL_FAST_IF_FAILED(rectGeometry.As(&geometry));

    __CGContextDrawGeometry(context, geometry.Get(), kCGPathFill);

    context->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextStrokeEllipseInRect(CGContextRef context, CGRect rect) {
    auto factory = context->Factory();

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    FAIL_FAST_IF_FAILED(
        factory->CreateEllipseGeometry({ { CGRectGetMidX(rect), CGRectGetMidY(rect) }, rect.size.width / 2.f, rect.size.height / 2.f },
                                       &ellipseGeometry));
    FAIL_FAST_IF_FAILED(ellipseGeometry.As(&geometry));

    __CGContextDrawGeometry(context, geometry.Get(), kCGPathStroke);

    context->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextFillEllipseInRect(CGContextRef context, CGRect rect) {
    auto factory = context->Factory();

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    FAIL_FAST_IF_FAILED(
        factory->CreateEllipseGeometry({ { CGRectGetMidX(rect), CGRectGetMidY(rect) }, rect.size.width / 2.f, rect.size.height / 2.f },
                                       &ellipseGeometry));
    FAIL_FAST_IF_FAILED(ellipseGeometry.As(&geometry));

    __CGContextDrawGeometry(context, geometry.Get(), kCGPathFill);

    context->ClearPath();
}
#pragma endregion

#pragma region Path Manipulation
/**
 @Status Interoperable
*/
void CGContextBeginPath(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef context, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef context, const CGRect* rect, unsigned count) {
    for (unsigned i = 0; i < count; i++) {
        CGContextAddRect(context, rect[i]);
    }
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef context, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef context, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef context, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef context, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef context, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef context, CGPathRef path) {
    // The Apple SDK docs imply that passing a NULL path is valid.
    // So avoid calling into the backing if NULL.
    if (path) {
        UNIMPLEMENTED();
    }
}

/**
 @Status Interoperable
*/
bool CGContextIsPathEmpty(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CGContextReplacePathWithStrokedPath(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetPathBoundingBox(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextAddLines(CGContextRef pContext, const CGPoint* pt, unsigned count) {
    CGContextMoveToPoint(pContext, pt[0].x, pt[0].y);
    for (unsigned i = 1; i < count; i++) {
        CGContextAddLineToPoint(pContext, pt[i].x, pt[i].y);
    }
}

#pragma endregion

#pragma region Path Drawing - Operations
/**
 @Status Interoperable
*/
void CGContextDrawPath(CGContextRef context, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokePath(CGContextRef context) {
    CGContextDrawPath(context, kCGPathStroke);
}

/**
 @Status Interoperable
*/
void CGContextFillPath(CGContextRef context) {
    CGContextDrawPath(context, kCGPathFill);
}

/**
 @Status Interoperable
*/
void CGContextEOFillPath(CGContextRef context) {
    CGContextDrawPath(context, kCGPathEOFill);
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextFlush(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawLinearGradient(
    CGContextRef context, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawRadialGradient(CGContextRef context,
                                 CGGradientRef gradient,
                                 CGPoint startCenter,
                                 CGFloat startRadius,
                                 CGPoint endCenter,
                                 CGFloat endRadius,
                                 CGGradientDrawingOptions options) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawShading(CGContextRef context, CGShadingRef shading) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef context, CGRect destRect, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint destPoint, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/// STROKE STYLE
/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef context, CGFloat phase, const CGFloat* lengths, unsigned count) {
    auto& state = context->CurrentGState();
    auto& dashes = state.dashes;

    if (count == 0) {
        state.strokeProperties.dashOffset = 0;
        state.strokeProperties.dashStyle = D2D1_DASH_STYLE_SOLID;
        dashes.clear();
    } else {
        state.strokeProperties.dashOffset = phase;
        state.strokeProperties.dashStyle = D2D1_DASH_STYLE_CUSTOM;
        dashes.assign(lengths, lengths + count);
    }
}

/**
 @Status Interoperable
*/
void CGContextSetMiterLimit(CGContextRef context, CGFloat limit) {
    auto& state = context->CurrentGState();
    state.strokeProperties.miterLimit = limit;
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef context, CGLineJoin lineJoin) {
    auto& state = context->CurrentGState();
    state.strokeProperties.lineJoin = (D2D1_LINE_JOIN)lineJoin;
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef context, CGLineCap lineCap) {
    auto& state = context->CurrentGState();
    state.strokeProperties.startCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.endCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.dashCap = (D2D1_CAP_STYLE)lineCap;
}

/**
 @Status Interoperable
*/
void CGContextSetLineWidth(CGContextRef context, CGFloat width) {
    auto& state = context->CurrentGState();
    state.lineWidth = width;
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef context, bool shouldAntialias) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsAntialiasing(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSmoothing(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelPositioning(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelPositionFonts(CGContextRef context, bool subpixel) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelQuantization(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef context, bool subpixel) {
    UNIMPLEMENTED();
}

/**
 @Status interoperable
*/
void CGContextSetInterpolationQuality(CGContextRef context, CGInterpolationQuality quality) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSmoothFonts(CGContextRef context, bool shouldSmooth) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetRenderingIntent(CGContextRef context, CGColorRenderingIntent intent) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadow(CGContextRef context, CGSize offset, CGFloat blur) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetClipBoundingBox(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayer(CGContextRef context, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayerWithRect(CGContextRef context, CGRect rect, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEndTransparencyLayer(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeLineSegments(CGContextRef context, const CGPoint* segments, unsigned count) {
    CGContextBeginPath(context);
    for (unsigned k = 0; k < count; k += 2) {
        CGContextMoveToPoint(context, segments[k].x, segments[k].y);
        CGContextAddLineToPoint(context, segments[k + 1].x, segments[k + 1].y);
    }
    CGContextStrokePath(context);
}

/**
 @Status Interoperable
*/
CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetAlpha(CGContextRef context, CGFloat alpha) {
    context->CurrentGState().alpha = alpha;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef context, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef context, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToUserSpace(CGContextRef context, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToUserSpace(CGContextRef context, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToDeviceSpace(CGContextRef context, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef context, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
void CGContextShowText(CGContextRef context, const char* str, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadowWithColor(CGContextRef context, CGSize offset, CGFloat blur, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextBeginPage(CGContextRef context, const CGRect* mediaBox) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
CGPathRef CGContextCopyPath(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextDrawPDFPage(CGContextRef context, CGPDFPageRef page) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextEndPage(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillRects(CGContextRef context, const CGRect* rects, size_t count) {
    if (!rects || count == 0) {
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        CGContextFillRect(context, rects[i]);
    }
}

/**
 @Status Stub
 @Notes
*/
CGPoint CGContextGetPathCurrentPoint(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGContextPathContainsPoint(CGContextRef context, CGPoint point, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetFlatness(CGContextRef context, CGFloat flatness) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetStrokePattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsAtPositions(CGContextRef context, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsWithAdvances(CGContextRef context, const CGGlyph* glyphs, const CGSize* advances, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSynchronize(CGContextRef context) {
    UNIMPLEMENTED();
}

// TODO(DH) GH#1077 remove all of these internal functions.
// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
void CGContextClearToColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    UNIMPLEMENTED();
}

bool CGContextIsDirty(CGContextRef context) {
    return true;
}

void CGContextSetDirty(CGContextRef context, bool dirty) {
    UNIMPLEMENTED();
}

void CGContextReleaseLock(CGContextRef context) {
    UNIMPLEMENTED();
}

CGContextImpl* CGContextGetBacking(CGContextRef context) {
    UNIMPLEMENTED();
    return nullptr;
}

bool CGContextIsPointInPath(CGContextRef context, bool eoFill, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextDrawGlyphRun(CGContextRef context, const DWRITE_GLYPH_RUN* glyphRun) {
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
}

CGImageRef CGPNGImageCreateFromFile(NSString* path) {
    return new CGPNGDecoderImage([path UTF8String]);
}

CGImageRef CGPNGImageCreateFromData(NSData* data) {
    return new CGPNGDecoderImage(data);
}

CGImageRef CGJPEGImageCreateFromFile(NSString* path) {
    return new CGJPEGDecoderImage([path UTF8String]);
}

CGImageRef CGJPEGImageCreateFromData(NSData* data) {
    return new CGJPEGDecoderImage(data);
}

#pragma region CGBitmapContext
struct __CGBitmapContextImpl {
    woc::unique_cf<CGImageRef> image;
};

struct __CGBitmapContext : CoreFoundation::CppBase<__CGBitmapContext, __CGBitmapContextImpl, __CGContext> { };

/**
 @Status Caveat
 @Notes Limited bitmap formats available. Decode, shouldInterpolate, intent parameters
 and some byte orders ignored.
 */
CGContextRef CGBitmapContextCreate(void* data,
                                   size_t width,
                                   size_t height,
                                   size_t bitsPerComponent,
                                   size_t bytesPerRow,
                                   CGColorSpaceRef colorSpace,
                                   CGBitmapInfo bitmapInfo) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef context) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

CGImageRef CGBitmapContextGetImage(CGContextRef context) {
    if (CFGetTypeID(context) != __CGBitmapContext::GetTypeID()) {
        TraceError(TAG, L"Image requested from non-bitmap CGContext.");
        return nullptr;
    }
    return ((__CGBitmapContext*)context)->Impl().image.get();
}

CGContextRef _CGBitmapContextCreateWithTexture(int width, int height, DisplayTexture* texture, DisplayTextureLocking* locking) {
    CGImageRef newImage = nullptr;
    __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, _ColorARGB);
    newImage = new CGGraphicBufferImage(surfaceInfo, texture, locking);

    ComPtr<ID2D1RenderTarget> renderTarget = newImage->Backing()->GetRenderTarget();

    __CGBitmapContext* context = __CGBitmapContext::CreateInstance(kCFAllocatorDefault);
    __CGContextInitWithRenderTarget(context, renderTarget.Get());

    context->Impl().image.reset(newImage); // Consumes +1 reference.
    return context;
}

CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt) {
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion