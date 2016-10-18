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
#import <algorithm>

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

    // Computed from the above at draw time
    ComPtr<ID2D1StrokeStyle> strokeStyle{ nullptr };

    CGFloat flatness = 0.0f;

    // Image Drawing
    D2D1_INTERPOLATION_MODE bitmapInterpolationMode = D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR;

    // Userspace Coordinate Transformation
    CGAffineTransform transform{ CGAffineTransformIdentity };
    CGAffineTransform textMatrix{ CGAffineTransformIdentity };

    // Alpha Blending
    CGFloat alpha = 1.0f;

    inline void ComputeStrokeStyle(ID2D1Factory* factory) {
        if (strokeStyle) {
            return;
        }

        std::vector<CGFloat> adjustedDashes(dashes.size());
        std::transform(dashes.cbegin(), dashes.cend(), adjustedDashes.begin(), [this](const float& f) -> CGFloat { return f / lineWidth; });
        FAIL_FAST_IF_FAILED(factory->CreateStrokeStyle(strokeProperties, adjustedDashes.data(), adjustedDashes.size(), &strokeStyle));
    }

    inline void ClearStrokeStyle() {
        strokeStyle.Reset();
    }
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

struct __CGContext : CoreFoundation::CppBase<__CGContext, __CGContextImpl> {
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

#define CGCONTEXT_CHECK_NULL(context)                                         \
    do {                                                                      \
        if (!context) {                                                       \
            TraceError(TAG, L"%hs(...): null context!", __PRETTY_FUNCTION__); \
            return StubReturn();                                              \
        }                                                                     \
    \
} while (0)

#define CGCONTEXT_CHECK_NULLV(context)                                        \
    do {                                                                      \
        if (!context) {                                                       \
            TraceError(TAG, L"%hs(...): null context!", __PRETTY_FUNCTION__); \
            return;                                                           \
        }                                                                     \
    \
} while (0)

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
    if (!context) {
        return nullptr;
    }

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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

CGBlendMode CGContextGetBlendMode(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextSetFillPattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetPatternPhase(CGContextRef context, CGSize phase) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

#pragma region Text Rendering - Parameters
/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef context, CGFloat spacing) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef context, CGTextDrawingMode mode) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef context, CGFontRef font) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSelectFont(CGContextRef context, const char* name, CGFloat size, CGTextEncoding encoding) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef context, CGFloat ptSize) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextMatrix(CGContextRef context, CGAffineTransform matrix) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef context, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion

#pragma region Text Rendering - Operations
/**
 @Status Interoperable
*/
void CGContextShowTextAtPoint(CGContextRef context, CGFloat x, CGFloat y, const char* str, size_t length) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsAtPoint(CGContextRef context, CGFloat x, CGFloat y, const CGGlyph* glyphs, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef context, const CGGlyph* glyphs, CGSize* advances, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef context, const CGGlyph* glyphs, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Userspace Coordinate Transformation
/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    auto& state = context->CurrentGState();
    return state.transform;
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef context, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextConcatCTM(context, CGAffineTransformMakeTranslation(x, y));
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef context, CGFloat sx, CGFloat sy) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextConcatCTM(context, CGAffineTransformMakeScale(sx, sy));
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef context, CGFloat angle) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextConcatCTM(context, CGAffineTransformMakeRotation(angle));
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef context, CGAffineTransform t) {
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.transform = CGAffineTransformConcat(state.transform, t);
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef context, CGAffineTransform transform) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef context, CGRect rect, CGImageRef image) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Clipping and Masking
/// TODO(DH): GH#future Clipping and Masking
/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextBeginPath(context);
    CGContextAddRect(context, rect);
    CGContextClip(context);
}

/**
 @Status Interoperable
*/
void CGContextClipToRects(CGContextRef context, const CGRect* rects, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Colors - Stroke
/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetStrokeColor(CGContextRef context, const CGFloat* components) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetStrokeColorWithColor(CGContextRef context, CGColorRef color) {
    CGCONTEXT_CHECK_NULLV(context);
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBStrokeColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetStrokeColorSpace(CGContextRef context, CGColorSpaceRef colorSpace) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextSetRGBStrokeColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    CGCONTEXT_CHECK_NULLV(context);
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().strokeBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKStrokeColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetFillColorWithColor(CGContextRef context, CGColorRef color) {
    CGCONTEXT_CHECK_NULLV(context);
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBFillColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Stub
 @Notes Since we are currently missing Color Space support, this will need to be implemented.
*/
void CGContextSetFillColorSpace(CGContextRef context, CGColorSpaceRef colorSpace) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextSetRGBFillColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    CGCONTEXT_CHECK_NULLV(context);
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->RenderTarget()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().fillBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKFillColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    ComPtr<ID2D1RenderTarget> renderTarget = context->RenderTarget();
    renderTarget->PushAxisAlignedClip(__CGRectToD2D_F(rect), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    renderTarget->Clear(nullptr); // transparent black clear
    renderTarget->PopAxisAlignedClip();
}

template <typename Lambda>
static void __CGContextRenderToCommandList(CGContextRef context, ID2D1CommandList** outCommandList, Lambda l) {
    ComPtr<ID2D1RenderTarget> renderTarget = context->RenderTarget();
    auto& state = context->CurrentGState();

    ComPtr<ID2D1DeviceContext> deviceContext;
    FAIL_FAST_IF_FAILED(renderTarget.As(&deviceContext));

    ComPtr<ID2D1Image> originalTarget;
    deviceContext->GetTarget(&originalTarget);

    deviceContext->BeginDraw();

    ComPtr<ID2D1CommandList> commandList;
    FAIL_FAST_IF_FAILED(deviceContext->CreateCommandList(&commandList));
    deviceContext->SetTarget(commandList.Get());

    l(context, renderTarget.Get());

    deviceContext->EndDraw();
    commandList->Close();

    deviceContext->SetTarget(originalTarget.Get());

    *outCommandList = commandList.Detach();
}

static void __CGContextRenderCommandList(CGContextRef context, ID2D1CommandList* commandList) {
    ComPtr<ID2D1RenderTarget> renderTarget = context->RenderTarget();
    auto& state = context->CurrentGState();

    ComPtr<ID2D1DeviceContext> deviceContext;
    FAIL_FAST_IF_FAILED(renderTarget.As(&deviceContext));

    D2D1_SIZE_F targetSize = renderTarget->GetSize();
    CGAffineTransform& currentTransform = state.transform;

    // CG is anchored in the bottom left, but D2D is anchored in the top left.
    // Flip the context.
    CGAffineTransform transform = CGAffineTransformScale(currentTransform, 1.0, -1.0);
    // Translate it back onscreen.
    transform = CGAffineTransformTranslate(transform, 0., targetSize.height);
    deviceContext->SetTransform({ transform.a, transform.b, transform.c, transform.d, transform.tx, transform.ty });

    deviceContext->BeginDraw();

    bool layer = false;
    if (state.alpha != 1.0f || false /* mask, clip, etc. */) {
        layer = true;
        renderTarget->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(),
                                                      nullptr,
                                                      D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
                                                      D2D1::IdentityMatrix(),
                                                      state.alpha),
                                nullptr);
    }

    deviceContext->DrawImage(commandList);

    if (layer) {
        renderTarget->PopLayer();
    }

    FAIL_FAST_IF_FAILED(deviceContext->EndDraw());

    deviceContext->SetTransform(D2D1::IdentityMatrix());
}

static void __CGContextDrawGeometry(CGContextRef context, ID2D1Geometry* geometry, CGPathDrawingMode drawMode) {
    ComPtr<ID2D1CommandList> commandList;
    __CGContextRenderToCommandList(context, &commandList, [geometry, drawMode](CGContextRef context, ID2D1RenderTarget* renderTarget) {
        auto& state = context->CurrentGState();
        if (drawMode & kCGPathFill) {
            if (drawMode & kCGPathEOFill) {
                // TODO(DH): GH#1077 Regenerate geometry in Even/Odd fill mode.
            }
            renderTarget->FillGeometry(geometry, state.fillBrush.Get());
        }

        if (drawMode & kCGPathStroke) {
            ComPtr<ID2D1Factory> factory;
            renderTarget->GetFactory(&factory);

            // This only computes the stroke style if its parameters have changed since the last draw.
            state.ComputeStrokeStyle(factory.Get());

            renderTarget->DrawGeometry(geometry, state.strokeBrush.Get(), state.lineWidth, state.strokeStyle.Get());
        }
    });

    __CGContextRenderCommandList(context, commandList.Get());
}

/**
 @Status Interoperable
*/
void CGContextStrokeRect(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    CGContextSaveGState(context);
    CGContextSetLineWidth(context, width);
    CGContextStrokeRect(context, rect);
    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
*/
void CGContextFillRect(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef context, const CGRect* rect, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    for (unsigned i = 0; i < count; i++) {
        CGContextAddRect(context, rect[i]);
    }
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef context, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef context, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef context, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef context, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef context, CGPathRef path) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CGContextReplacePathWithStrokedPath(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetPathBoundingBox(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextAddLines(CGContextRef context, const CGPoint* pt, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextMoveToPoint(context, pt[0].x, pt[0].y);
    for (unsigned i = 1; i < count; i++) {
        CGContextAddLineToPoint(context, pt[i].x, pt[i].y);
    }
}

#pragma endregion

#pragma region Path Drawing - Operations
/**
 @Status Interoperable
*/
void CGContextDrawPath(CGContextRef context, CGPathDrawingMode mode) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokePath(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextDrawPath(context, kCGPathStroke);
}

/**
 @Status Interoperable
*/
void CGContextFillPath(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextDrawPath(context, kCGPathFill);
}

/**
 @Status Interoperable
*/
void CGContextEOFillPath(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    CGContextDrawPath(context, kCGPathEOFill);
}
#pragma endregion

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextFlush(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawLinearGradient(
    CGContextRef context, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawShading(CGContextRef context, CGShadingRef shading) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef context, CGRect destRect, CGLayerRef layer) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint destPoint, CGLayerRef layer) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/// STROKE STYLE
/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef context, CGFloat phase, const CGFloat* lengths, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();

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
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.strokeProperties.miterLimit = limit;
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef context, CGLineJoin lineJoin) {
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.strokeProperties.lineJoin = (D2D1_LINE_JOIN)lineJoin;
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef context, CGLineCap lineCap) {
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.strokeProperties.startCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.endCap = (D2D1_CAP_STYLE)lineCap;
    state.strokeProperties.dashCap = (D2D1_CAP_STYLE)lineCap;
}

/**
 @Status Interoperable
*/
void CGContextSetLineWidth(CGContextRef context, CGFloat width) {
    CGCONTEXT_CHECK_NULLV(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.lineWidth = width;
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef context, bool shouldAntialias) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsAntialiasing(CGContextRef context, bool allows) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSmoothing(CGContextRef context, bool allows) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelPositioning(CGContextRef context, bool allows) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelPositionFonts(CGContextRef context, bool subpixel) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelQuantization(CGContextRef context, bool allows) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef context, bool subpixel) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes CGContext defaults to low-quality linear interpolation.
*/
void CGContextSetInterpolationQuality(CGContextRef context, CGInterpolationQuality quality) {
    CGCONTEXT_CHECK_NULLV(context);
    static D2D1_INTERPOLATION_MODE d2dModes[] = {
        /* Default */ D2D1_INTERPOLATION_MODE_LINEAR,
        /* None    */ D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
        /* Low     */ D2D1_INTERPOLATION_MODE_LINEAR,
        /* Medium  */ D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR,
        /* High    */ D2D1_INTERPOLATION_MODE_CUBIC,
    };

    if (quality < kCGInterpolationDefault) {
        quality = kCGInterpolationDefault;
    }

    if (quality > kCGInterpolationHigh) {
        quality = kCGInterpolationHigh;
    }

    auto& state = context->CurrentGState();
    state.bitmapInterpolationMode = d2dModes[quality];
}

/**
 @Status Interoperable
 @Notes Low-quality interpolation will be returned as default interpolation.
*/
CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    auto& state = context->CurrentGState();
    switch (state.bitmapInterpolationMode) {
        case D2D1_INTERPOLATION_MODE_LINEAR:
            return kCGInterpolationDefault;
        case D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR:
            return kCGInterpolationNone;
        case D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR:
            return kCGInterpolationMedium;
        case D2D1_INTERPOLATION_MODE_CUBIC:
            return kCGInterpolationHigh;
        default:
            return kCGInterpolationDefault;
    }
}

/**
 @Status Stub
*/
void CGContextSetShouldSmoothFonts(CGContextRef context, bool shouldSmooth) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetRenderingIntent(CGContextRef context, CGColorRenderingIntent intent) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadow(CGContextRef context, CGSize offset, CGFloat blur) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetClipBoundingBox(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayer(CGContextRef context, CFDictionaryRef auxInfo) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayerWithRect(CGContextRef context, CGRect rect, CFDictionaryRef auxInfo) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEndTransparencyLayer(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeLineSegments(CGContextRef context, const CGPoint* segments, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
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
void CGContextSetAlpha(CGContextRef context, CGFloat alpha) {
    CGCONTEXT_CHECK_NULLV(context);
    context->CurrentGState().alpha = alpha;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef context, CGRect rect) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToUserSpace(CGContextRef context, CGPoint pt) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToUserSpace(CGContextRef context, CGSize size) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToDeviceSpace(CGContextRef context, CGSize size) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef context, CGPoint pt) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
void CGContextShowText(CGContextRef context, const char* str, unsigned count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadowWithColor(CGContextRef context, CGSize offset, CGFloat blur, CGColorRef color) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextBeginPage(CGContextRef context, const CGRect* mediaBox) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
CGPathRef CGContextCopyPath(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextDrawPDFPage(CGContextRef context, CGPDFPageRef page) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextEndPage(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillRects(CGContextRef context, const CGRect* rects, size_t count) {
    CGCONTEXT_CHECK_NULLV(context);
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
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGContextPathContainsPoint(CGContextRef context, CGPoint point, CGPathDrawingMode mode) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetFlatness(CGContextRef context, CGFloat flatness) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetStrokePattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsAtPositions(CGContextRef context, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsWithAdvances(CGContextRef context, const CGGlyph* glyphs, const CGSize* advances, size_t count) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSynchronize(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

// TODO(DH) GH#1077 remove all of these internal functions.
// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
void CGContextClearToColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

bool CGContextIsDirty(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    return true;
}

void CGContextSetDirty(CGContextRef context, bool dirty) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

void CGContextReleaseLock(CGContextRef context) {
    CGCONTEXT_CHECK_NULLV(context);
    UNIMPLEMENTED();
}

CGContextImpl* CGContextGetBacking(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return nullptr;
}

bool CGContextIsPointInPath(CGContextRef context, bool eoFill, CGFloat x, CGFloat y) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextDrawGlyphRun(CGContextRef context, const DWRITE_GLYPH_RUN* glyphRun) {
    CGCONTEXT_CHECK_NULLV(context);
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

struct __CGBitmapContext : CoreFoundation::CppBase<__CGBitmapContext, __CGBitmapContextImpl, __CGContext> {};

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
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    UNIMPLEMENTED();
    return StubReturn();
}

CGImageRef CGBitmapContextGetImage(CGContextRef context) {
    CGCONTEXT_CHECK_NULL(context);
    if (CFGetTypeID(context) != __CGBitmapContext::GetTypeID()) {
        TraceError(TAG, L"Image requested from non-bitmap CGContext.");
        return nullptr;
    }
    return ((__CGBitmapContext*)context)->Impl().image.get();
}

CGContextRef _CGBitmapContextCreateWithTexture(
    int width, int height, float scale, DisplayTexture* texture, DisplayTextureLocking* locking) {
    CGImageRef newImage = nullptr;
    __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, _ColorARGB);
    newImage = new CGGraphicBufferImage(surfaceInfo, texture, locking);

    ComPtr<ID2D1RenderTarget> renderTarget = newImage->Backing()->GetRenderTarget();
    renderTarget->SetDpi(96 * scale, 96 * scale);

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
