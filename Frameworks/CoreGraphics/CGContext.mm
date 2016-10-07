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

#import "CGSurfaceInfoInternal.h" //EVAL

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGPath.h>
#import <CoreGraphics/CGLayer.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGradient.h>
#import "CGColorSpaceInternal.h"
#import "CGContextInternal.h"

#import <CFRuntime.h>

#include <COMIncludes.h>
#import <d2d1.h>
#import <d2d1_1.h>
#import <wrl/client.h>
#include <COMIncludes_end.h>
#import <LoggingNative.h>

#import <list>
#import <vector>
#import <stack>

using namespace Microsoft::WRL;

static inline D2D_RECT_F __CGRectToD2D(CGRect rect) {
    return {
        rect.origin.x,
        rect.origin.y,
        rect.origin.x + rect.size.width,
        rect.origin.y + rect.size.height,
    };
}

struct __CGContextDrawingState {
    // Not populated by default.
    ComPtr<ID2D1DrawingStateBlock> d2dState;

    // Fills
    ComPtr<ID2D1Brush> fillBrush;

    // Strokes
    ComPtr<ID2D1Brush> strokeBrush;
    ComPtr<ID2D1StrokeStyle> strokeStyle;
    D2D1_STROKE_STYLE_PROPERTIES strokeProperties{
        D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE_FLAT,
        D2D1_LINE_JOIN_MITER,
        10.f, // Default from Reference Docs
        D2D1_DASH_STYLE_SOLID,
        0.f,
    };
    std::vector<CGFloat> dashes;

    CGFloat lineWidth = 1.0f;

    CGFloat flatness;

    // Clipping
    CGMutablePathRef currentClippingPath;

    // Image Drawing
    D2D1_INTERPOLATION_MODE bitmapInterpolationMode;

    // Userspace Coordinate Transformation
    CGAffineTransform transform = CGAffineTransformIdentity;
    CGAffineTransform textMatrix = CGAffineTransformIdentity;

    // Alpha Blending
    CGFloat alpha = 1.0f;
};

struct __CGContextImpl {
    ComPtr<ID2D1RenderTarget> _renderTarget;

    std::stack<__CGContextDrawingState> _stateStack;

    CGMutablePathRef _currentPath;

    bool _allowsAntialiasing;
    bool _allowsFontSmoothing;
    bool _allowsFontSubpixelPositioning;
    bool _allowsFontSubpixelQuantization;

    __CGContextImpl() : _stateStack() {
        _stateStack.emplace();
    }
};

struct __CGContext {
    CFRuntimeBase _base;

    // Use an inline impl struct so that we don't need to placement new each element.
    __CGContextImpl _impl;
    CGImageRef img;

    inline __CGContextImpl& Impl() {
        return _impl;
    }

    inline ID2D1RenderTarget* RenderTarget() {
        return _impl._renderTarget.Get();
    }

    inline std::stack<__CGContextDrawingState>& StateStack() {
        return _impl._stateStack;
    }

    inline __CGContextDrawingState& CurrentGState() {
        return StateStack().top();
    }

    inline void ClearPath() {
        CGPathRelease(_impl._currentPath);
        _impl._currentPath = nullptr;
    }
};

#pragma region CFRuntimeClass
static Boolean __CGContextEqual(CFTypeRef cf1, CFTypeRef cf2) {
    return FALSE;
}

static CFHashCode __CGContextHash(CFTypeRef cf) {
    return (CFHashCode)cf;
}

static CFStringRef __CGContextCopyDescription(CFTypeRef cf) {
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CGContext %p>"), cf);
}

static void __CGContextInit(CFTypeRef cf) {
    CGContextRef context = (CGContextRef)cf;
    struct __CGContext* mutableContext = const_cast<struct __CGContext*>(context);
    new (std::addressof(mutableContext->_impl)) __CGContextImpl();
}

static void __CGContextDeallocate(CFTypeRef cf) {
    CGContextRef context = (CGContextRef)cf;
    context->_impl.~__CGContextImpl();
    CGImageRelease(context->img);
}

static CFTypeID __kCGContextTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CGContextClass = { 0,
                                                 "CGContext",
                                                 __CGContextInit, // init
                                                 NULL,
                                                 __CGContextDeallocate, // deallocate
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 __CGContextCopyDescription };

template <typename T, typename B = decltype(std::declval<T>()->_base)>
static T _CFRuntimeCreateInstance(CFTypeID typeID, CFAllocatorRef allocator = kCFAllocatorDefault) {
    return static_cast<T>(const_cast<void*>(_CFRuntimeCreateInstance(allocator, typeID, sizeof(typename std::remove_pointer<T>::type) - sizeof(B), nullptr)));
}

/**
 @Status Interoperable
*/
CFTypeID CGContextGetTypeID() {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce, ^{
        __kCGContextTypeID = _CFRuntimeRegisterClass(&__CGContextClass);
    });
    return __kCGContextTypeID;
}
#pragma endregion

static const wchar_t* TAG = L"CGContext";

CGContextRef _CGContextCreateWithD2DRenderTarget(ID2D1RenderTarget* renderTarget, CGImageRef img) {
    THROW_HR_IF_NULL(E_INVALIDARG, renderTarget);
    CGContextRef context = _CFRuntimeCreateInstance<CGContextRef>(CGContextGetTypeID());
    context->_impl._renderTarget = renderTarget;
    context->img = CGImageRetain(img);
    CGContextSetRGBFillColor(context, 0, 0, 0, 0);
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);
    return context;
}

#pragma region Lifetime
/**
 @Status Interoperable
*/
CGContextRef CGContextRetain(CGContextRef ctx) {
    CFRetain((CFTypeRef)ctx);
    return ctx;
}

/**
 @Status Interoperable
*/
void CGContextRelease(CGContextRef ctx) {
    if (!ctx) {
        return;
    }

    CFRelease((CFTypeRef)ctx);
}
#pragma endregion

#pragma region Drawing Parameters
/**
 @Status Interoperable
*/
void CGContextSetBlendMode(CGContextRef ctx, CGBlendMode mode) {
    UNIMPLEMENTED();
}

CGBlendMode CGContextGetBlendMode(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextSetFillPattern(CGContextRef ctx, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetPatternPhase(CGContextRef ctx, CGSize phase) {
    UNIMPLEMENTED();
}

#pragma region Text Rendering - Parameters
/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef ctx, CGFloat spacing) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef ctx, CGTextDrawingMode mode) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef ctx, CGFontRef font) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSelectFont(CGContextRef ctx, const char* name, CGFloat size, CGTextEncoding encoding) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef ctx, CGFloat ptSize) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextMatrix(CGContextRef ctx, CGAffineTransform matrix) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef ctx) {
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
void CGContextShowGlyphsAtPoint(CGContextRef ctx, CGFloat x, CGFloat y, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef ctx, const CGGlyph* glyphs, CGSize* advances, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef ctx, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Userspace Coordinate Transformation
/// TODO(DH)
/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef ctx) {
    auto& state = ctx->CurrentGState();
    return state.transform;
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef ctx, CGFloat x, CGFloat y) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeTranslation(x, y));
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef ctx, CGFloat sx, CGFloat sy) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeScale(sx, sy));
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef ctx, CGFloat angle) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeRotation(angle));
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef ctx, CGAffineTransform t) {
    auto& state = ctx->CurrentGState();
    state.transform = CGAffineTransformConcat(state.transform, t);
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef ctx, CGAffineTransform transform) {
    auto& state = ctx->CurrentGState();
    state.transform = transform;
}
#pragma endregion

#pragma region Image Drawing - Operations
/// TODO(DH): IMAGE DRAWING
/**
 @Status Interoperable
*/
void CGContextDrawImage(CGContextRef ctx, CGRect rect, CGImageRef image) {
    if (!image) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }
    if (!ctx) {
        TraceWarning(TAG, L"CGContextDrawImage: ctx == NULL!");
        return;
    }

    { UNIMPLEMENTED(); }
}

void CGContextDrawImageRect(CGContextRef ctx, CGImageRef image, CGRect src, CGRect dst) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef ctx, CGRect rect, CGImageRef image) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Clipping and Masking
/// TODO(DH): CLIPPING AND MASKING
/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef ctx, CGRect rect) {
    CGContextBeginPath(ctx);
    CGContextAddRect(ctx, rect);
    CGContextClip(ctx);
}

/**
 @Status Interoperable
*/
void CGContextClipToRects(CGContextRef ctx, const CGRect* rects, unsigned count) {
    CGContextBeginPath(ctx);
    CGContextAddRects(ctx, rects, count);
    CGContextClip(ctx);
}

/**
 @Status Caveat
 @Notes Limited bitmap format support
*/
void CGContextClipToMask(CGContextRef ctx, CGRect dest, CGImageRef image) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Colors - Stroke
/// TODO(DH): STROKE COLORS
/**
 @Status Interoperable
*/
void CGContextSetStrokeColor(CGContextRef ctx, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetStrokeColorWithColor(CGContextRef ctx, CGColorRef color) {
    // TODO(DH)
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBStrokeColor(ctx, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Stub
*/
void CGContextSetStrokeColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef ctx, CGFloat gray, CGFloat alpha) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    ComPtr<ID2D1SolidColorBrush> brush;
    THROW_IF_FAILED(ctx->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    THROW_IF_FAILED(brush.As(&ctx->CurrentGState().strokeBrush));
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetCMYKStrokeColor(CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Colors - Fill
/// TODO(DH): FILL COLORS
/**
 @Status Interoperable
*/
void CGContextSetFillColor(CGContextRef ctx, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFillColorWithColor(CGContextRef ctx, CGColorRef color) {
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBFillColor(ctx, comp[0], comp[1], comp[2], comp[3]);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetFillColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef ctx, CGFloat gray, CGFloat alpha) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    ComPtr<ID2D1SolidColorBrush> brush;
    THROW_IF_FAILED(ctx->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    THROW_IF_FAILED(brush.As(&ctx->CurrentGState().fillBrush));
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetCMYKFillColor(CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Graphics States
/**
 @Status Interoperable
*/
void CGContextSaveGState(CGContextRef ctx) {
    auto& oldState = ctx->CurrentGState();

    // This uses the drawing state's copy constructor.
    ctx->StateStack().emplace(oldState);

    ComPtr<ID2D1Factory> factory;
    ctx->RenderTarget()->GetFactory(&factory);

    ComPtr<ID2D1DrawingStateBlock> drawingState;
    THROW_IF_FAILED(factory->CreateDrawingStateBlock(&drawingState));
    ctx->RenderTarget()->SaveDrawingState(drawingState.Get());
    oldState.d2dState = drawingState;
}

/**
 @Status Interoperable
*/
void CGContextRestoreGState(CGContextRef ctx) {
    if (ctx->StateStack().size() <= 1) {
        TraceError(TAG, L"Attempted to pop last GState.");
        return;
    }

    ctx->StateStack().pop();
    auto& newState = ctx->CurrentGState();
    ctx->RenderTarget()->RestoreDrawingState(newState.d2dState.Get());
    newState.d2dState = nullptr;
}
#pragma endregion

#pragma region Shape Drawing - Operations
/**
 @Status Interoperable
*/
void CGContextClearRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

static void __CGContextDrawGeometry(CGContextRef ctx, ID2D1Geometry* geometry, CGPathDrawingMode drawMode) {
    auto renderTarget = ctx->RenderTarget();
    auto& currentState = ctx->CurrentGState();

    renderTarget->BeginDraw();

    CGAffineTransform& currentTransform = currentState.transform;
    CGAffineTransform transform = CGAffineTransformScale(currentTransform, 1.0, -1.0);
    D2D1_SIZE_F targetSize = renderTarget->GetSize();
    transform = CGAffineTransformTranslate(transform, 0., targetSize.height);
    renderTarget->SetTransform({transform.a, transform.b, transform.c, transform.d, transform.tx, transform.ty});

    ComPtr<ID2D1Layer> layer;
    if (currentState.alpha != 1.0f || false /* mask, clip, etc. */) {
        renderTarget->CreateLayer(&layer);
        renderTarget->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(), NULL, D2D1_ANTIALIAS_MODE_PER_PRIMITIVE, D2D1::IdentityMatrix(), currentState.alpha), layer.Get());
    }

    if (drawMode & kCGPathFill) {
        if (drawMode & kCGPathEOFill) {
            // TODO(DH): Regenerate geometry in Even/Odd fill mode.
        }
        renderTarget->FillGeometry(geometry, currentState.fillBrush.Get());
    }

    if (drawMode & kCGPathStroke) {
        ComPtr<ID2D1Factory> factory;
        renderTarget->GetFactory(&factory);

        /* TODO(DH): do not recreate for every drawing operation */
        ComPtr<ID2D1StrokeStyle> strokeStyle;
        // dashes must be adjusted to be based on line width
        std::vector<CGFloat> adjustedDashes{currentState.dashes};
        for (float& f: adjustedDashes) {
            f /= currentState.lineWidth;
        }
        THROW_IF_FAILED(factory->CreateStrokeStyle(currentState.strokeProperties, adjustedDashes.data(), adjustedDashes.size(), &strokeStyle));
        /* --- */

        renderTarget->DrawGeometry(geometry, currentState.strokeBrush.Get(), currentState.lineWidth, strokeStyle.Get());
    }

    if (layer) {
        renderTarget->PopLayer();
    }

    renderTarget->EndDraw();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRect(CGContextRef ctx, CGRect rect) {
    auto renderTarget = ctx->RenderTarget();

    ComPtr<ID2D1Factory> factory;
    renderTarget->GetFactory(&factory);

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    THROW_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D(rect), &rectGeometry));
    THROW_IF_FAILED(rectGeometry.As(&geometry));

    __CGContextDrawGeometry(ctx, geometry.Get(), kCGPathStroke);

    ctx->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRectWithWidth(CGContextRef ctx, CGRect rect, CGFloat width) {
    CGContextSaveGState(ctx);
    CGContextSetLineWidth(ctx, width);
    CGContextStrokeRect(ctx, rect);
    CGContextRestoreGState(ctx);
}

/**
 @Status Interoperable
*/
void CGContextFillRect(CGContextRef ctx, CGRect rect) {
    auto renderTarget = ctx->RenderTarget();

    ComPtr<ID2D1Factory> factory;
    renderTarget->GetFactory(&factory);

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    THROW_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D(rect), &rectGeometry));
    THROW_IF_FAILED(rectGeometry.As(&geometry));

    __CGContextDrawGeometry(ctx, geometry.Get(), kCGPathFill);

    ctx->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextStrokeEllipseInRect(CGContextRef ctx, CGRect rect) {
    auto renderTarget = ctx->RenderTarget();

    ComPtr<ID2D1Factory> factory;
    renderTarget->GetFactory(&factory);

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    THROW_IF_FAILED(factory->CreateEllipseGeometry({{CGRectGetMidX(rect), CGRectGetMidY(rect)}, rect.size.width / 2.f, rect.size.height / 2.f}, &ellipseGeometry));
    THROW_IF_FAILED(ellipseGeometry.As(&geometry));

    __CGContextDrawGeometry(ctx, geometry.Get(), kCGPathStroke);

    ctx->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextFillEllipseInRect(CGContextRef ctx, CGRect rect) {
    auto renderTarget = ctx->RenderTarget();

    ComPtr<ID2D1Factory> factory;
    renderTarget->GetFactory(&factory);

    ComPtr<ID2D1Geometry> geometry;
    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    THROW_IF_FAILED(factory->CreateEllipseGeometry({{CGRectGetMidX(rect), CGRectGetMidY(rect)}, rect.size.width / 2.f, rect.size.height / 2.f}, &ellipseGeometry));
    THROW_IF_FAILED(ellipseGeometry.As(&geometry));

    __CGContextDrawGeometry(ctx, geometry.Get(), kCGPathFill);

    ctx->ClearPath();
}
#pragma endregion

#pragma region Path Manipulation
/**
 @Status Interoperable
*/
void CGContextBeginPath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef ctx, const CGRect* rect, unsigned count) {
    for (unsigned i = 0; i < count; i++) {
        CGContextAddRect(ctx, rect[i]);
    }
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef ctx, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef ctx, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef ctx, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef ctx, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef ctx, CGPathRef path) {
    // The Apple SDK docs imply that passing a NULL path is valid.
    // So avoid calling into the backing if NULL.
    if (path) {
        UNIMPLEMENTED();
    }
}

/**
 @Status Interoperable
*/
bool CGContextIsPathEmpty(CGContextRef ctx) {
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
CGRect CGContextGetPathBoundingBox(CGContextRef ctx) {
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
void CGContextDrawPath(CGContextRef ctx, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokePath(CGContextRef ctx) {
    CGContextDrawPath(ctx, kCGPathStroke);
}

/**
 @Status Interoperable
*/
void CGContextFillPath(CGContextRef ctx) {
    CGContextDrawPath(ctx, kCGPathFill);
}

/**
 @Status Interoperable
*/
void CGContextEOFillPath(CGContextRef ctx) {
    CGContextDrawPath(ctx, kCGPathEOFill);
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextFlush(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawLinearGradient(
    CGContextRef ctx, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawRadialGradient(CGContextRef ctx,
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
void CGContextDrawShading(CGContextRef ctx, CGShadingRef shading) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef ctx, CGRect destRect, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef ctx, CGPoint destPoint, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/// STROKE STYLE
/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef ctx, CGFloat phase, const CGFloat* lengths, unsigned count) {
    auto& state = ctx->CurrentGState();
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
void CGContextSetMiterLimit(CGContextRef ctx, CGFloat limit) {
    auto& state = ctx->CurrentGState();
    state.strokeProperties.miterLimit = limit;
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef ctx, CGLineJoin lineJoin) {
    auto& state = ctx->CurrentGState();
    state.strokeProperties.lineJoin = (D2D1_LINE_JOIN)lineJoin;
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef ctx, CGLineCap lineCap) {
    auto& state = ctx->CurrentGState();
    state.strokeProperties.startCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.endCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.dashCap = (D2D1_CAP_STYLE)lineCap;
}

/**
 @Status Interoperable
*/
void CGContextSetLineWidth(CGContextRef ctx, CGFloat width) {
    auto& state = ctx->CurrentGState();
    state.lineWidth = width;
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef ctx, bool shouldAntialias) {
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
CGRect CGContextGetClipBoundingBox(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayer(CGContextRef ctx, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayerWithRect(CGContextRef ctx, CGRect rect, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEndTransparencyLayer(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeLineSegments(CGContextRef ctx, const CGPoint* segments, unsigned count) {
    CGContextBeginPath(ctx);
    for (unsigned k = 0; k < count; k += 2) {
        CGContextMoveToPoint(ctx, segments[k].x, segments[k].y);
        CGContextAddLineToPoint(ctx, segments[k + 1].x, segments[k + 1].y);
    }
    CGContextStrokePath(ctx);
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
void CGContextSetAlpha(CGContextRef ctx, CGFloat alpha) {
    ctx->CurrentGState().alpha = alpha;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToUserSpace(CGContextRef ctx, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToUserSpace(CGContextRef c, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToDeviceSpace(CGContextRef ctx, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef ctx, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
void CGContextShowText(CGContextRef ctx, const char* str, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadowWithColor(CGContextRef ctx, CGSize offset, CGFloat blur, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextBeginPage(CGContextRef c, const CGRect* mediaBox) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
CGPathRef CGContextCopyPath(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextEndPage(CGContextRef c) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillRects(CGContextRef ctx, const CGRect* rects, size_t count) {
    for(size_t i = 0; i < count; ++i) {
        CGContextFillRect(ctx, rects[i]);
    }
}

/**
 @Status Stub
 @Notes
*/
CGPoint CGContextGetPathCurrentPoint(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGContextPathContainsPoint(CGContextRef c, CGPoint point, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetFlatness(CGContextRef c, CGFloat flatness) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetStrokePattern(CGContextRef c, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsAtPositions(CGContextRef c, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsWithAdvances(CGContextRef c, const CGGlyph* glyphs, const CGSize* advances, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSynchronize(CGContextRef c) {
    UNIMPLEMENTED();
}

// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
void CGContextClearToColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    UNIMPLEMENTED();
}

bool CGContextIsDirty(CGContextRef ctx) {
    return true;
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextSetDirty(CGContextRef ctx, bool dirty) {
    UNIMPLEMENTED();
}

void CGContextReleaseLock(CGContextRef ctx) {
    UNIMPLEMENTED();
}

CGContextImpl* CGContextGetBacking(CGContextRef ctx) {
    UNIMPLEMENTED();
    return nullptr;
}

bool CGContextIsPointInPath(CGContextRef c, bool eoFill, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextDrawGlyphRun(CGContextRef ctx, const DWRITE_GLYPH_RUN* glyphRun) {
    // ctx->Backing()->CGContextDrawGlyphRun(glyphRun);
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

/**
 @Status Interoperable
*/
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef ctx) {
    // TODO: Consider caching colorspaceRef in CGImageRef
    return nullptr;
    // return (CGColorSpaceRef) new __CGColorSpace(ctx->Backing()->DestImage()->Backing()->ColorSpaceModel());
}

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
#if 0
    CGImageRef newImage = NULL;
    DWORD alphaType = bitmapInfo & kCGBitmapAlphaInfoMask;

    bool colorSpaceAllocated = false;

    if (!colorSpace) {
        if (bytesPerRow >= (width * 3)) {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming RGB based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceRGB();
        } else {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming Gray based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceGray();
        }

        colorSpaceAllocated = true;
    }

    const unsigned int numColorComponents = CGColorSpaceGetNumberOfComponents(colorSpace);
    const unsigned int numComponents = numColorComponents + ((alphaType == kCGImageAlphaNone) ? 0 : 1);
    const unsigned int bitsPerPixel = (bitsPerComponent == 5) ? 16 : numComponents * bitsPerComponent;

    __CGSurfaceFormat format = _CGImageGetFormat(bitsPerComponent, bitsPerPixel, colorSpace, bitmapInfo);

    __CGSurfaceInfo surfaceInfo = __CGSurfaceInfo(((__CGColorSpace*)colorSpace)->colorSpaceModel,
                                                  bitmapInfo,
                                                  bitsPerComponent,
                                                  bitsPerPixel >> 3,
                                                  width,
                                                  height,
                                                  bytesPerRow,
                                                  data,
                                                  format);

    newImage = new CGBitmapImage(surfaceInfo);

    CGContextRef ret = new __CGContext(newImage);
    CFRelease((id)newImage);

    if (colorSpaceAllocated == true) {
        CGColorSpaceRelease(colorSpace);
    }

    return ret;
#endif
    return nullptr;
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

CGImageRef CGBitmapContextGetImage(CGContextRef ctx) {
    return ctx->img;
    //UNIMPLEMENTED();
    //return StubReturn();
}

CGContextRef _CGBitmapContextCreateWithTexture(int width, int height, DisplayTexture* texture, DisplayTextureLocking* locking) {
    CGImageRef newImage = nullptr;
    __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, _ColorARGB);

    //if (texture) {
    newImage = new CGGraphicBufferImage(surfaceInfo, texture, locking);
    //} else {
        //newImage = new CGBitmapImage(surfaceInfo);
    //}

    //CGContextRef context = new __CGContext(newImage);
    ComPtr<ID2D1RenderTarget> renderTarget = newImage->Backing()->GetRenderTarget();
    return _CGContextCreateWithD2DRenderTarget(renderTarget.Get(), newImage);
    CGImageRelease(newImage);
}

CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt) {
    UNIMPLEMENTED();
    return StubReturn();
}