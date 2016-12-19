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

#import <StubReturn.h>
#import <Starboard.h>
#import <math.h>

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGPath.h>
#import <CoreGraphics/CGLayer.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGradient.h>
#import <LoggingNative.h>
#import <CoreGraphics/D2DWrapper.h>
#import "CGColorSpaceInternal.h"
#import "CGContextInternal.h"
#import "CGPathInternal.h"
#import "CGIWICBitmap.h"
#import "CGPatternInternal.h"

#import <CFCppBase.h>

#include <COMIncludes.h>
#import <d2d1.h>
#import <d2d1_1.h>
#import <d2d1effects_2.h>
#import <wrl/client.h>
#include <COMIncludes_end.h>

#import <list>
#import <vector>
#import <stack>
#import <algorithm>

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGContext";

enum _CGCoordinateMode : unsigned int { _kCGCoordinateModeDeviceSpace = 0, _kCGCoordinateModeUserSpace };

// A drawing context is represented by a number of layers, each with their own drawing state:
// Context
// +-- Layer (base layer)
//     +-- Drawing State (base drawing state)
//     +-- Drawing State
//     +-- Drawing State (3)
// +-- Layer (transparency layer)
//     +-- Drawing State (copied from (3) above, but stripped of composition controls)
//     +-- Drawing State

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

    // Per-Primitive Alpha
    CGFloat alpha = 1.0f;

    // Global Alpha (used when per-primitive cannot be used.)
    CGFloat globalAlpha = 1.0f;

    // Shadowing
    D2D1_VECTOR_4F shadowColor{ 0, 0, 0, 0 };
    CGSize shadowOffset{ 0, 0 };
    CGFloat shadowBlur{ 0 };

    // Clipping + Masking
    ComPtr<ID2D1Geometry> clippingGeometry;
    ComPtr<ID2D1BitmapBrush> opacityBrush;

    inline void ComputeStrokeStyle(ID2D1DeviceContext* deviceContext) {
        if (strokeStyle) {
            return;
        }

        if (std::fpclassify(lineWidth) == FP_ZERO) {
            // Set no stroke style.
            return;
        }

        ComPtr<ID2D1Factory> factory;
        deviceContext->GetFactory(&factory);

        std::vector<float> adjustedDashes(dashes.size());
        std::transform(dashes.cbegin(), dashes.cend(), adjustedDashes.begin(), [this](const CGFloat& f) -> float { return f / lineWidth; });
        FAIL_FAST_IF_FAILED(factory->CreateStrokeStyle(strokeProperties, adjustedDashes.data(), adjustedDashes.size(), &strokeStyle));
    }

    inline void ClearStrokeStyle() {
        strokeStyle.Reset();
    }

    inline bool HasShadow() {
        return std::fpclassify(shadowColor.w) != FP_ZERO;
    }

    inline bool ShouldDraw() {
        return std::fpclassify(alpha) != FP_ZERO && std::fpclassify(globalAlpha) != FP_ZERO;
    }

    inline HRESULT IntersectClippingGeometry(ID2D1Geometry* incomingGeometry, CGPathDrawingMode pathMode) {
        D2D1_FILL_MODE d2dFillMode = (pathMode & kCGPathEOFill) == kCGPathEOFill ? D2D1_FILL_MODE_ALTERNATE : D2D1_FILL_MODE_WINDING;

        if (!clippingGeometry) {
            // If we don't have a clipping geometry, we are free to take this one wholesale (after EO/Winding conversion.)
            return _CGConvertD2DGeometryToFillMode(incomingGeometry, d2dFillMode, &clippingGeometry);
        }

        ComPtr<ID2D1Factory> factory;
        clippingGeometry->GetFactory(&factory);

        // If we have a clipping geometry, we must intersect it with the new path.
        // To do so, we need to stream the combined geometry into a totally new geometry.
        ComPtr<ID2D1PathGeometry> newClippingPathGeometry;
        RETURN_IF_FAILED(factory->CreatePathGeometry(&newClippingPathGeometry));

        ComPtr<ID2D1GeometrySink> geometrySink;
        RETURN_IF_FAILED(newClippingPathGeometry->Open(&geometrySink));

        geometrySink->SetFillMode(d2dFillMode);

        RETURN_IF_FAILED(clippingGeometry->CombineWithGeometry(incomingGeometry, D2D1_COMBINE_MODE_INTERSECT, nullptr, geometrySink.Get()));

        RETURN_IF_FAILED(geometrySink->Close());

        clippingGeometry.Attach(newClippingPathGeometry.Detach());
        return S_OK;
    }

    inline D2D1_INTERPOLATION_MODE GetInterpolationModeForCGImage(CGImageRef image) {
        RETURN_RESULT_IF_NULL(image, D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR);
        return CGImageGetShouldInterpolate(image) ? bitmapInterpolationMode : D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR;
    }
};

class __CGContextLayer {
    std::stack<__CGContextDrawingState> _stateStack;
    ComPtr<ID2D1Image> _target;

public:
    __CGContextLayer(ID2D1Image* target, CGRect* region) : _target(target) {
        // Each newly-pushed default-constructed layer has an empty base state.
        _stateStack.emplace();
    }

    __CGContextLayer(ID2D1Image* target, CGRect* region, __CGContextLayer& parentLayer) : _target(target) {
        _stateStack.emplace(parentLayer.CurrentGState());
    }

    __CGContextDrawingState& CurrentGState() {
        return _stateStack.top();
    }

    // PushGState saves the provided Direct2D drawing state into the current rendering
    // configuration and creates a new empty one.
    inline HRESULT PushGState(ID2D1DrawingStateBlock* drawingState) {
        RETURN_HR_IF(E_INVALIDARG, !drawingState);

        auto& oldState = _stateStack.top();

        // Put a copy of the current drawing state at the top of the state stack.
        _stateStack.emplace(oldState);
        oldState.d2dState = drawingState;

        return S_OK;
    }

    // PopGState removes the topmost rendering configuration from the top of the drawing
    // state stack and returns the context's prior Direct2D drawing state.
    inline HRESULT PopGState(ID2D1DrawingStateBlock** pDrawingState) {
        RETURN_HR_IF(E_POINTER, !pDrawingState);
        RETURN_HR_IF(E_BOUNDS, _stateStack.size() == 1);

        _stateStack.pop();

        auto& returningState = _stateStack.top();
        *pDrawingState = returningState.d2dState.Detach();
        return S_OK;
    }

    inline HRESULT GetTarget(ID2D1Image** pTarget) {
        return _target.CopyTo(pTarget);
    }
};

struct __CGContext : CoreFoundation::CppBase<__CGContext> {
    ComPtr<ID2D1DeviceContext> deviceContext;

    // Calculated at creation time, this transform flips CG's drawing commands,
    // anchored in the bottom left, to D2D's top-left coordinate system.
    CGAffineTransform deviceTransform{ CGAffineTransformIdentity };

    // See the comments above _CGContextSetShadowProjectionTransform.
    CGAffineTransform shadowProjectionTransform{ CGAffineTransformIdentity };

    // TODO(DH) GH#1070 evaluate these defaults; they should be set by context creators.
    bool allowsAntialiasing = false;
    bool allowsFontSmoothing = false;
    bool allowsFontSubpixelPositioning = false;
    bool allowsFontSubpixelQuantization = false;

    CGAffineTransform textMatrix{ CGAffineTransformIdentity };

private:
    std::stack<__CGContextLayer> _layerStack{};
    woc::unique_cf<CGMutablePathRef> _currentPath{ nullptr };
    woc::unique_cf<CGColorSpaceRef> _fillColorSpace;
    woc::unique_cf<CGColorSpaceRef> _strokeColorSpace;

    inline HRESULT _SaveD2DDrawingState(ID2D1DrawingStateBlock** pDrawingState) {
        RETURN_HR_IF(E_POINTER, !pDrawingState);

        ComPtr<ID2D1DrawingStateBlock> drawingState;
        RETURN_IF_FAILED(Factory()->CreateDrawingStateBlock(&drawingState));

        deviceContext->SaveDrawingState(drawingState.Get());
        *pDrawingState = drawingState.Detach();
        return S_OK;
    }

    inline HRESULT _RestoreD2DDrawingState(ID2D1DrawingStateBlock* drawingState) {
        RETURN_HR_IF(E_INVALIDARG, !drawingState);

        deviceContext->RestoreDrawingState(drawingState);
        return S_OK;
    }

    HRESULT _CreateShadowEffect(ID2D1Image* inputImage, ID2D1Effect** outShadowEffect);

public:
    __CGContext(ID2D1RenderTarget* renderTarget) {
        FAIL_FAST_IF_FAILED(renderTarget->QueryInterface(IID_PPV_ARGS(&deviceContext)));

        // CG is a lower-left origin system (LLO), but D2D is upper left (ULO).
        // We have to translate the render area back onscreen and flip it up to ULO.
        D2D1_SIZE_F targetSize = deviceContext->GetSize();
        deviceTransform = CGAffineTransformMake(1.f, 0.f, 0.f, -1.f, 0.f, targetSize.height);

        ComPtr<ID2D1Image> baselineTarget;
        deviceContext->GetTarget(&baselineTarget);

        // Set up the default/baseline layer.
        _layerStack.emplace(baselineTarget.Get(), nullptr);
    }

    inline void SetFillColorSpace(CGColorSpaceRef colorspace) {
        _fillColorSpace.reset(CGColorSpaceRetain(colorspace));
    }

    inline CGColorSpaceRef FillColorSpace() {
        return _fillColorSpace.get();
    }

    inline void SetStrokeColorSpace(CGColorSpaceRef colorspace) {
        _strokeColorSpace.reset(CGColorSpaceRetain(colorspace));
    }

    inline CGColorSpaceRef StrokeColorSpace() {
        return _strokeColorSpace.get();
    }

    inline ComPtr<ID2D1DeviceContext>& DeviceContext() {
        return deviceContext;
    }

    inline __CGContextDrawingState& CurrentGState() {
        return _layerStack.top().CurrentGState();
    }

    inline HRESULT PushGState() {
        auto& currentLayer = _layerStack.top();
        ComPtr<ID2D1DrawingStateBlock> d2dState;
        RETURN_IF_FAILED(_SaveD2DDrawingState(&d2dState));
        return currentLayer.PushGState(d2dState.Get());
    }

    inline HRESULT PopGState() {
        auto& currentLayer = _layerStack.top();
        ComPtr<ID2D1DrawingStateBlock> d2dState;
        HRESULT hr = currentLayer.PopGState(&d2dState);
        if (hr == E_BOUNDS) {
            // We want to handle E_BOUNDS separately from the general failure case.
            TraceError(TAG, L"Invalid attempt to pop last graphics state.");
            return E_BOUNDS;
        }

        RETURN_IF_FAILED(hr);

        return _RestoreD2DDrawingState(d2dState.Get());
    }

    inline bool HasPath() {
        return _currentPath != nullptr;
    }

    inline CGMutablePathRef Path() {
        if (!_currentPath) {
            _currentPath.reset(CGPathCreateMutable());
        }
        return _currentPath.get();
    }

    inline void SetPath(CGMutablePathRef path) {
        _currentPath.reset(CGPathRetain(path));
    }

    inline void ClearPath() {
        _currentPath.reset();
    }

    inline ComPtr<ID2D1Factory> Factory() {
        ComPtr<ID2D1Factory> factory;
        deviceContext->GetFactory(&factory);
        return factory;
    }

    inline bool ShouldDraw() {
        return CurrentGState().ShouldDraw();
    }

    HRESULT Clip(CGPathDrawingMode pathMode);

    HRESULT PushLayer(CGRect* rect = nullptr);
    HRESULT PopLayer();

    template <typename Lambda> // Lambda takes the form void(*)(CGContextRef, ID2D1DeviceContext*)
    HRESULT DrawToCommandList(_CGCoordinateMode coordinateMode,
                              CGAffineTransform* additionalTransform,
                              ID2D1CommandList** outCommandList,
                              Lambda&& drawLambda);
    HRESULT DrawGeometry(_CGCoordinateMode coordinateMode, ID2D1Geometry* pGeometry, CGPathDrawingMode drawMode);
    HRESULT DrawImage(ID2D1Image* image);
    HRESULT ClipToD2DMaskBitmap(ID2D1Bitmap* bitmap, CGRect rect, D2D1_INTERPOLATION_MODE interpolationMode);
    HRESULT ClipToCGImageMask(CGImageRef image, CGRect rect);
};

#define NOISY_RETURN_IF_NULL(param, ...)                                    \
    do {                                                                    \
        if (!param) {                                                       \
            TraceError(TAG, L"%hs: null " #param "!", __PRETTY_FUNCTION__); \
            return __VA_ARGS__;                                             \
        }                                                                   \
    } while (0)

#pragma region Global State - CFRuntimeClass
/**
 @Status Interoperable
*/
CFTypeID CGContextGetTypeID() {
    return __CGContext::GetTypeID();
}
#pragma endregion

#pragma region Global State - Lifetime
static HRESULT __CGContextPrepareDefaults(CGContextRef context) {
    // Reference platform defaults:
    // * Fill  : fully transparent black
    // * Stroke: fully opaque black
    // If a context does not support alpha, the default fill looks like fully opaque black.
    CGContextSetRGBFillColor(context, 0, 0, 0, 0);
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);
    return S_OK;
}

CGContextRef _CGContextCreateWithD2DRenderTarget(ID2D1RenderTarget* renderTarget) {
    FAIL_FAST_HR_IF_NULL(E_INVALIDARG, renderTarget);
    CGContextRef context = __CGContext::CreateInstance(kCFAllocatorDefault, renderTarget);
    __CGContextPrepareDefaults(context);
    return context;
}

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

#pragma region Global State - Graphics State Stack
/**
 @Status Interoperable
*/
void CGContextSaveGState(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    FAIL_FAST_IF_FAILED(context->PushGState());
}

/**
 @Status Interoperable
*/
void CGContextRestoreGState(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    FAIL_FAST_IF_FAILED(context->PopGState());
}
#pragma endregion

#pragma region Global State - Context Maintenance
/**
 @Status Stub
*/
void CGContextFlush(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSynchronize(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Global State - Transparency Layers
HRESULT __CGContext::PushLayer(CGRect* rect) {
    // Save our current D2D state block & drawing parameters.
    // We will take a new GState for composing the layer later in PopLayer(): ...
    RETURN_IF_FAILED(PushGState());

    // ... this one.
    auto& gStateForComposingLayer = CurrentGState();

    ComPtr<ID2D1CommandList> commandList;
    RETURN_IF_FAILED(deviceContext->CreateCommandList(&commandList));

    deviceContext->SetTarget(commandList.Get());

    // Copy the current layer's state to the new layer.
    auto& oldLayer = _layerStack.top();

    _layerStack.emplace(commandList.Get(), rect, oldLayer);
    auto& newLayer = _layerStack.top(); // C++17 makes .emplace return a stack<T>::reference; alas, we are C++14.

    // These properties are not to be preserved across transparency layers.
    // https://developer.apple.com/library/content/documentation/GraphicsImaging/Conceptual/drawingwithquartz2d/dq_trans_layers/dq_trans_layers.html#//apple_ref/doc/uid/TP30001066-CH210-SW1
    // Doing so would cause:
    // * Double shadows
    // * Double transparency
    // * Double blending
    // * Double clipping
    auto& newDrawingState = newLayer.CurrentGState();
    newDrawingState.alpha = 1.0;
    newDrawingState.shadowColor = { 0.f, 0.f, 0.f, 0.f };
    // newDrawingState.blendMode = kCGBlendModeNormal; // TODO GH#1389
    newDrawingState.clippingGeometry = nullptr;
    newDrawingState.opacityBrush = nullptr;
    if (rect) {
        CGRect transformedClippingRegion = CGContextConvertRectToDeviceSpace(this, *rect);

        if (gStateForComposingLayer.HasShadow()) {
            // The reference platform grows the layer's clipping region by the shadow's offset and its approximate width.
            CGFloat xdelta = fabsf(gStateForComposingLayer.shadowOffset.width);
            xdelta += gStateForComposingLayer.shadowBlur + 1;

            CGFloat ydelta = fabsf(gStateForComposingLayer.shadowOffset.height);
            ydelta += gStateForComposingLayer.shadowBlur + 1;

            transformedClippingRegion = CGRectInset(transformedClippingRegion, -xdelta, -ydelta);
        }

        ComPtr<ID2D1RectangleGeometry> rectGeometry;
        RETURN_IF_FAILED(Factory()->CreateRectangleGeometry(__CGRectToD2D_F(transformedClippingRegion), &rectGeometry));
        RETURN_IF_FAILED(newDrawingState.IntersectClippingGeometry(rectGeometry.Get(), kCGPathEOFill));
    }

    // A GState's global alpha is used when per-primitive drawing is not an option (such as when
    // composing down a full transparency layer.)
    gStateForComposingLayer.globalAlpha = gStateForComposingLayer.alpha;
    gStateForComposingLayer.alpha = 1.0;
    return S_OK;
}

HRESULT __CGContext::PopLayer() {
    if (_layerStack.size() <= 1) {
        TraceError(TAG, L"Invalid attempt to pop base layer.");
        return E_BOUNDS;
    }

    auto& outgoingLayer = _layerStack.top();

    ComPtr<ID2D1Image> outgoingImageTarget;
    RETURN_IF_FAILED(outgoingLayer.GetTarget(&outgoingImageTarget));

    ComPtr<ID2D1CommandList> outgoingCommandList;
    if (FAILED(outgoingImageTarget.As(&outgoingCommandList))) {
        TraceError(TAG, L"Popped a layer that was NOT a command list. PANIC!");
        return E_UNEXPECTED;
    }

    RETURN_IF_FAILED(outgoingCommandList->Close());

    // Destroy the top layer and all its state.
    _layerStack.pop();

    auto& incomingLayer = _layerStack.top();
    ComPtr<ID2D1Image> incomingImageTarget;
    RETURN_IF_FAILED(incomingLayer.GetTarget(&incomingImageTarget));

    deviceContext->SetTarget(incomingImageTarget.Get());

    RETURN_IF_FAILED(DrawImage(outgoingCommandList.Get()));

    // Restore the previous D2D state block & drawing parameters from the incoming layer.
    RETURN_IF_FAILED(PopGState());

    return S_OK;
}
/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayer(CGContextRef context, CFDictionaryRef auxInfo) {
    NOISY_RETURN_IF_NULL(context);
    FAIL_FAST_IF_FAILED(context->PushLayer());
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayerWithRect(CGContextRef context, CGRect rect, CFDictionaryRef auxInfo) {
    NOISY_RETURN_IF_NULL(context);
    FAIL_FAST_IF_FAILED(context->PushLayer(&rect));
}

/**
 @Status Interoperable
*/
void CGContextEndTransparencyLayer(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    FAIL_FAST_IF_FAILED(context->PopLayer()); // PopLayer takes care of drawing.
}
#pragma endregion

#pragma region Global State - Pagination
/**
 @Status Stub
 @Notes
*/
void CGContextBeginPage(CGContextRef context, const CGRect* mediaBox) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextEndPage(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Global State - Device Coordinate Queries
/**
 @Status Interoperable
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context, rect);
    // Invariant: The incoming measurement is in DEVICE space.
    return CGRectApplyAffineTransform(rect, CGAffineTransformInvert(CGContextGetUserSpaceToDeviceSpaceTransform(context)));
}

/**
 @Status Interoperable
*/
CGSize CGContextConvertSizeToUserSpace(CGContextRef context, CGSize size) {
    NOISY_RETURN_IF_NULL(context, size);
    // Invariant: The incoming measurement is in DEVICE space.
    return CGSizeApplyAffineTransform(size, CGAffineTransformInvert(CGContextGetUserSpaceToDeviceSpaceTransform(context)));
}

/**
 @Status Interoperable
*/
CGPoint CGContextConvertPointToUserSpace(CGContextRef context, CGPoint point) {
    NOISY_RETURN_IF_NULL(context, point);
    // Invariant: The incoming measurement is in DEVICE space.
    return CGPointApplyAffineTransform(point, CGAffineTransformInvert(CGContextGetUserSpaceToDeviceSpaceTransform(context)));
}

/**
 @Status Interoperable
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context, rect);
    // Invariant: The incoming measurement is in USER space.
    return CGRectApplyAffineTransform(rect, CGContextGetUserSpaceToDeviceSpaceTransform(context));
}

/**
 @Status Interoperable
*/
CGSize CGContextConvertSizeToDeviceSpace(CGContextRef context, CGSize size) {
    NOISY_RETURN_IF_NULL(context, size);
    // Invariant: The incoming measurement is in USER space.
    return CGSizeApplyAffineTransform(size, CGContextGetUserSpaceToDeviceSpaceTransform(context));
}

/**
 @Status Interoperable
*/
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef context, CGPoint point) {
    NOISY_RETURN_IF_NULL(context, point);
    // Invariant: The incoming measurement is in USER space.
    return CGPointApplyAffineTransform(point, CGContextGetUserSpaceToDeviceSpaceTransform(context));
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    return CGAffineTransformConcat(context->CurrentGState().transform, context->deviceTransform);
}
#pragma endregion

#pragma region Global State - CTM
/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    auto& state = context->CurrentGState();
    return state.transform;
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef context, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);
    CGContextConcatCTM(context, CGAffineTransformMakeTranslation(x, y));
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef context, CGFloat sx, CGFloat sy) {
    NOISY_RETURN_IF_NULL(context);
    CGContextConcatCTM(context, CGAffineTransformMakeScale(sx, sy));
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef context, CGFloat angle) {
    NOISY_RETURN_IF_NULL(context);
    CGContextConcatCTM(context, CGAffineTransformMakeRotation(angle));
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef context, CGAffineTransform t) {
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.transform = CGAffineTransformConcat(t, state.transform);
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef context, CGAffineTransform transform) {
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.transform = transform;
}
#pragma endregion

#pragma region Global State - Path Manipulation
/**
 @Status Interoperable
*/
void CGContextBeginPath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);

    // All subsequent path functions will create the new path as necessary.
    context->ClearPath();
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);

    CGPathCloseSubpath(context->Path());
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddRect(context->Path(), &userToDeviceTransform, rect);
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef context, const CGRect* rects, unsigned count) {
    NOISY_RETURN_IF_NULL(context);

    if (count == 0 || !rects) {
        return;
    }

// TODO GH#xxxx When CGPathAddRects is no longer stubbed, remove the diagnostic suppression.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddRects(context->Path(), &userToDeviceTransform, rects, count);

#pragma clang diagnostic pop
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddLineToPoint(context->Path(), &userToDeviceTransform, x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef context, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddCurveToPoint(context->Path(), &userToDeviceTransform, cp1x, cp1y, cp2x, cp2y, x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef context, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddQuadCurveToPoint(context->Path(), &userToDeviceTransform, cpx, cpy, x, y);
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef context, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathMoveToPoint(context->Path(), &userToDeviceTransform, x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef context, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddArc(context->Path(), &userToDeviceTransform, x, y, radius, startAngle, endAngle, clockwise);
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef context, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddArcToPoint(context->Path(), &userToDeviceTransform, x1, y1, x2, y2, radius);
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddEllipseInRect(context->Path(), &userToDeviceTransform, rect);
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef context, CGPathRef path) {
    NOISY_RETURN_IF_NULL(context);
    if (!path) {
        return;
    }

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);

    if (!context->HasPath()) {
        // If we don't curerntly have a path, take this one in as our own.
        woc::unique_cf<CGMutablePathRef> copiedPath{ CGPathCreateMutableCopyByTransformingPath(path, &userToDeviceTransform) };
        context->SetPath(copiedPath.get());
        return;
    }

    CGPathAddPath(context->Path(), &userToDeviceTransform, path);
}

/**
 @Status Stub
*/
void CGContextReplacePathWithStrokedPath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);

    if (!context->HasPath()) {
        return;
    }

    auto& state = context->CurrentGState();

// TODO GH#xxxx When CGPathCreateCopyByStrokingPath is no longer stubbed, remove the diagnostic suppression.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

    woc::unique_cf<CGPathRef> newPath{
        CGPathCreateCopyByStrokingPath(context->Path(),
                                       nullptr, // The points in the path are already transformed; do not transform again!
                                       state.lineWidth,
                                       (CGLineCap)state.strokeProperties.startCap,
                                       (CGLineJoin)state.strokeProperties.lineJoin,
                                       state.strokeProperties.miterLimit)
    };

#pragma clang diagnostic pop

    woc::unique_cf<CGMutablePathRef> newMutablePath{ CGPathCreateMutableCopy(newPath.get()) };
    context->SetPath(newMutablePath.get());
}

/**
 @Status Interoperable
*/
bool CGContextIsPathEmpty(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());

    return !context->HasPath() || CGPathIsEmpty(context->Path());
}

/**
 @Status Interoperable
*/
CGRect CGContextGetPathBoundingBox(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, CGRectNull);

    if (!context->HasPath()) {
        return CGRectNull;
    }

    // All queries take place on transformed paths, but return pre-CTM context units.
    return CGContextConvertRectToUserSpace(context, CGPathGetBoundingBox(context->Path()));
}

/**
 @Status Interoperable
*/
void CGContextAddLines(CGContextRef context, const CGPoint* points, unsigned count) {
    NOISY_RETURN_IF_NULL(context);

    if (!count || !points) {
        return;
    }

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    CGPathAddLines(context->Path(), &userToDeviceTransform, points, count);
}
#pragma endregion

#pragma region Global State - Path Queries
/**
 @Status Interoperable
 @Notes
*/
CGPathRef CGContextCopyPath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, nullptr);

    if (!context->HasPath()) {
        return nullptr;
    }

// TODO GH#xxxx When CGPathCreateCopyByTransformingPath is no longer stubbed, remove the diagnostic suppression.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

    // All queries take place on transformed paths, but return pre-CTM context units.
    // This means that the path the user gets back will be in units equivalent to
    // their inputs. We therefore must de-transform the path into which we inserted
    // transformed points.
    CGAffineTransform invertedDeviceSpaceTransform = CGAffineTransformInvert(CGContextGetUserSpaceToDeviceSpaceTransform(context));
    return CGPathCreateCopyByTransformingPath(context->Path(), &invertedDeviceSpaceTransform);

#pragma clang diagnostic pop
}

/**
 @Status Stub
 @Notes
*/
CGPoint CGContextGetPathCurrentPoint(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, CGPointZero);

    if (!context->HasPath()) {
        return CGPointZero;
    }

    // All queries take place on transformed paths, but return pre-CTM context units.
    return CGContextConvertPointToUserSpace(context, CGPathGetCurrentPoint(context->Path()));
}

/**
 @Status Stub
 @Notes
*/
bool CGContextPathContainsPoint(CGContextRef context, CGPoint point, CGPathDrawingMode mode) {
    NOISY_RETURN_IF_NULL(context, false);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(context);
    return context->HasPath() && CGPathContainsPoint(context->Path(), &userToDeviceTransform, point, (mode & kCGPathEOFill));
}
#pragma endregion

#pragma region Global State - Clipping and Masking
HRESULT __CGContext::Clip(CGPathDrawingMode pathMode) {
    if (!HasPath()) {
        // Clipping to nothing is okay.
        return S_OK;
    }

    ComPtr<ID2D1Geometry> additionalClippingGeometry;
    RETURN_IF_FAILED(_CGPathGetGeometry(Path(), &additionalClippingGeometry));
    ClearPath();

    auto& state = CurrentGState();
    return state.IntersectClippingGeometry(additionalClippingGeometry.Get(), pathMode);
}

/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    context->Clip(kCGPathFill);
}

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    context->Clip(kCGPathEOFill);
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    CGContextBeginPath(context);
    CGContextAddRect(context, rect);
    CGContextClip(context);
}

/**
 @Status Interoperable
*/
void CGContextClipToRects(CGContextRef context, const CGRect* rects, unsigned count) {
    NOISY_RETURN_IF_NULL(context);
    if (!rects || count == 0) {
        return;
    }

    CGContextBeginPath(context);
    CGContextAddRects(context, rects, count);
    CGContextClip(context);
}

static CGAffineTransform __BitmapBrushTransformation(CGContextRef context,
                                                     CGRect rectToDrawInto,
                                                     D2D1_SIZE_U bitmapSize,
                                                     CGAffineTransform matrix) {
    FAIL_FAST_IF(bitmapSize.width == 0);
    FAIL_FAST_IF(bitmapSize.height == 0);

    // |1  0 0| is the transformation matrix for flipping a rect about its Y midpoint m. (m = (y + h/2))
    // |0 -1 0|
    // |0 2m 1|
    //
    // Combined with [scale sx * sy] * [translate X, Y], that becomes:
    // |sx     0 0|
    // | 0   -sy 0|
    // | x -y+2m 0|
    // Or, the transformation matrix for drawing a flipped rect at a scale and offset.

    CGFloat sx = rectToDrawInto.size.width / bitmapSize.width;
    CGFloat sy = rectToDrawInto.size.height / bitmapSize.height;
    CGFloat m = rectToDrawInto.origin.y + (rectToDrawInto.size.height / 2.f);

    CGAffineTransform transform{ sx, 0, 0, -sy, rectToDrawInto.origin.x, (2 * m) - rectToDrawInto.origin.y };
    return CGAffineTransformConcat(transform, matrix);
}

HRESULT __CGContext::ClipToD2DMaskBitmap(ID2D1Bitmap* bitmap, CGRect rect, D2D1_INTERPOLATION_MODE interpolationMode) {
    RETURN_HR_IF_NULL(E_INVALIDARG, bitmap);

    D2D1_SIZE_U bitmapSize = bitmap->GetPixelSize();

    RETURN_HR_IF(E_INVALIDARG, bitmapSize.width == 0 || bitmapSize.height == 0);

    CGAffineTransform userToDeviceTransform = CGContextGetUserSpaceToDeviceSpaceTransform(this);
    CGAffineTransform transform = __BitmapBrushTransformation(this, rect, bitmapSize, userToDeviceTransform);

    auto& state = CurrentGState();

    ComPtr<ID2D1BitmapBrush1> newOpacityBrush;
    RETURN_IF_FAILED(
        deviceContext->CreateBitmapBrush(bitmap,
                                         D2D1::BitmapBrushProperties1(D2D1_EXTEND_MODE_CLAMP, D2D1_EXTEND_MODE_CLAMP, interpolationMode),
                                         D2D1::BrushProperties(1 /* the global alpha will be set during the draw sequence*/,
                                                               __CGAffineTransformToD2D_F(transform)),
                                         &newOpacityBrush));

    // Compliance with reference platform: D2D extends the last pixel of the opacity brush out to the
    // ends of the earth. The reference platform truncates the clipping region at the edge of the mask.
    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    ComPtr<ID2D1TransformedGeometry> transformedRectClippingGeometry;
    RETURN_IF_FAILED(Factory()->CreateRectangleGeometry(__CGRectToD2D_F(rect), &rectGeometry));
    RETURN_IF_FAILED(Factory()->CreateTransformedGeometry(rectGeometry.Get(),
                                                          __CGAffineTransformToD2D_F(userToDeviceTransform),
                                                          &transformedRectClippingGeometry));

    if (state.opacityBrush) {
        // If we already have an opacity brush, we have to go to great lengths to compose the two clipping images.
        // - Create a compatible render target with a backing bitmap
        // - Using two layers (reasons detailed below), fill a geometry with the intersection of the two
        //   masks.
        // - Use that bitmap (untransformed, as the render has resolved the global coordinate system conflict)
        //   as the opacity brush for future drawing.
        ComPtr<ID2D1BitmapRenderTarget> compatibleTarget;
        RETURN_IF_FAILED(deviceContext->CreateCompatibleRenderTarget(&compatibleTarget));
        ComPtr<ID2D1DeviceContext> compatibleContext;
        RETURN_IF_FAILED(compatibleTarget.As(&compatibleContext));

        compatibleContext->BeginDraw();
        compatibleContext->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(),
                                                           nullptr,
                                                           D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
                                                           D2D1::IdentityMatrix(),
                                                           1.0, // 1.0 global alpha for brush composition
                                                           state.opacityBrush.Get()),
                                     nullptr);
        compatibleContext->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(),
                                                           transformedRectClippingGeometry.Get(),
                                                           D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
                                                           D2D1::IdentityMatrix(),
                                                           1.0, // 1.0 global alpha for brush composition
                                                           newOpacityBrush.Get()),
                                     nullptr);

        ComPtr<ID2D1SolidColorBrush> brush;
        RETURN_IF_FAILED(compatibleContext->CreateSolidColorBrush({ 0, 0, 0, 1 }, &brush));
        // FillGeometry takes three parameters:
        // * geometry
        // * fill brush
        // * opacity brush
        //
        // It looks like the perfect candidate for creating a new final opacity brush --
        // one layer, one opacity-bound geometry fill! Except that for some reason,
        // Direct2D returns D2DERR_INCOMPATIBLE_BRUSH_TYPES if you try to opacify a
        // solid color brush with an opacity brush directly.
        // Drawing through two stacked layers (original opacity brush, new opacity brush)
        // however does work.
        compatibleContext->FillGeometry(transformedRectClippingGeometry.Get(), brush.Get());
        compatibleContext->PopLayer();
        compatibleContext->PopLayer();
        RETURN_IF_FAILED(compatibleContext->EndDraw());

        ComPtr<ID2D1Bitmap> mergedAlphaMask;
        RETURN_IF_FAILED(compatibleTarget->GetBitmap(&mergedAlphaMask));
        newOpacityBrush->SetBitmap(mergedAlphaMask.Get());

        // This brush is backed by a bitmap that is 1:1 scale/transform with the existing device context.
        // Since its boundaries match the context boundaries, we don't need to intersect another global clip.
        newOpacityBrush->SetTransform(D2D1::IdentityMatrix());
    } else {
        // Since we are not composing the opacity brushes, we have to clip the global region to the bounds of the opacity brush.
        RETURN_IF_FAILED(state.IntersectClippingGeometry(transformedRectClippingGeometry.Get(), kCGPathFill));
    }

    state.opacityBrush = std::move(newOpacityBrush);

    return S_OK;
}

HRESULT __CGContext::ClipToCGImageMask(CGImageRef image, CGRect rect) {
    ComPtr<IWICBitmap> maskWicBitmap;
    RETURN_IF_FAILED(_CGImageConvertToMaskCompatibleWICBitmap(image, &maskWicBitmap));

    ComPtr<ID2D1Bitmap> maskD2DBitmap;
    RETURN_IF_FAILED(deviceContext->CreateBitmapFromWicBitmap(maskWicBitmap.Get(), nullptr, &maskD2DBitmap));

    return ClipToD2DMaskBitmap(maskD2DBitmap.Get(), rect, this->CurrentGState().GetInterpolationModeForCGImage(image));
}

/**
 @Status Caveat
 @Notes Limited bitmap format support
*/
void CGContextClipToMask(CGContextRef context, CGRect rect, CGImageRef image) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(image);

    FAIL_FAST_IF_FAILED(context->ClipToCGImageMask(image, rect));
}

/**
 @Status Interoperable
*/
CGRect CGContextGetClipBoundingBox(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, CGRectNull);

    auto& state = context->CurrentGState();
    if (!state.clippingGeometry) {
        D2D1_SIZE_F targetSize = context->DeviceContext()->GetSize();
        return CGContextConvertRectToUserSpace(context, CGRect{ CGPointZero, { targetSize.width, targetSize.height } });
    }

    D2D1_RECT_F bounds;

    if (FAILED(state.clippingGeometry->GetBounds(nullptr, &bounds))) {
        TraceError(TAG, L"failed to get bounds for clipping geometry in context %p", context);
        return CGRectNull;
    }

    return CGContextConvertRectToUserSpace(context, _D2DRectToCGRect(bounds));
}
#pragma endregion

#pragma region Drawing Parameters - Text
/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef context, CGFloat spacing) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef context, CGTextDrawingMode mode) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef context, CGFontRef font) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSelectFont(CGContextRef context, const char* name, CGFloat size, CGTextEncoding encoding) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef context, CGFloat ptSize) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes Not part of the Graphics State Block.
*/
void CGContextSetTextMatrix(CGContextRef context, CGAffineTransform matrix) {
    NOISY_RETURN_IF_NULL(context);
    context->textMatrix = matrix;
}

/**
 @Status Interoperable
 @Notes Not part of the Graphics State Block.
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, CGAffineTransformIdentity);
    return context->textMatrix;
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef context, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context);
    context->textMatrix.tx = x;
    context->textMatrix.ty = y;
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    return {
        context->textMatrix.tx, context->textMatrix.ty,
    };
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSmoothing(CGContextRef context, bool allows) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSmoothFonts(CGContextRef context, bool shouldSmooth) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelPositioning(CGContextRef context, bool allows) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelPositionFonts(CGContextRef context, bool subpixel) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelQuantization(CGContextRef context, bool allows) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef context, bool subpixel) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Parameters - Generic
/**
 @Status Interoperable
*/
void CGContextSetBlendMode(CGContextRef context, CGBlendMode mode) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

CGBlendMode CGContextGetBlendMode(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef context, bool shouldAntialias) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsAntialiasing(CGContextRef context, bool allows) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes CGContext defaults to low-quality linear interpolation.
*/
void CGContextSetInterpolationQuality(CGContextRef context, CGInterpolationQuality quality) {
    NOISY_RETURN_IF_NULL(context);
    static D2D1_INTERPOLATION_MODE d2dModes[] = {
        /* Default */ D2D1_INTERPOLATION_MODE_LINEAR,
        /* None    */ D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
        /* Low     */ D2D1_INTERPOLATION_MODE_LINEAR,
        /* Medium  */ D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR,
        /* High    */ D2D1_INTERPOLATION_MODE_CUBIC,
    };

    quality = std::max(std::min(quality, kCGInterpolationHigh), kCGInterpolationDefault);

    auto& state = context->CurrentGState();
    state.bitmapInterpolationMode = d2dModes[quality];
}

/**
 @Status Interoperable
 @Notes Low-quality interpolation will be returned if the default interpolation is set.
*/
CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());

    auto& state = context->CurrentGState();
    switch (state.bitmapInterpolationMode) {
        case D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR:
            return kCGInterpolationNone;
        case D2D1_INTERPOLATION_MODE_LINEAR:
            return kCGInterpolationLow;
        case D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR:
            return kCGInterpolationMedium;
        case D2D1_INTERPOLATION_MODE_ANISOTROPIC:
        case D2D1_INTERPOLATION_MODE_CUBIC:
        case D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC:
            return kCGInterpolationHigh;
        default:
            return kCGInterpolationDefault;
    }
}

/**
 @Status Stub
*/
void CGContextSetRenderingIntent(CGContextRef context, CGColorRenderingIntent intent) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetAlpha(CGContextRef context, CGFloat alpha) {
    NOISY_RETURN_IF_NULL(context);
    context->CurrentGState().alpha = alpha;
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetFlatness(CGContextRef context, CGFloat flatness) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Parameters - Stroke Style
/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef context, CGFloat phase, const CGFloat* lengths, unsigned count) {
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();

    auto& dashes = state.dashes;

    if (count == 0 || !lengths) {
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
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.strokeProperties.miterLimit = limit;
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef context, CGLineJoin lineJoin) {
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.strokeProperties.lineJoin = (D2D1_LINE_JOIN)lineJoin;
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef context, CGLineCap lineCap) {
    NOISY_RETURN_IF_NULL(context);
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
    NOISY_RETURN_IF_NULL(context);
    auto& state = context->CurrentGState();
    state.ClearStrokeStyle();
    state.lineWidth = width;
}
#pragma endregion

#pragma region Drawing Parameters - Stroke Color
/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetStrokeColor(CGContextRef context, const CGFloat* components) {
    NOISY_RETURN_IF_NULL(context);
    // TODO: based on the color space, we should be setting the fill color componenets.
    // as color is not fully supported, assume RGBA for now.
    CGContextSetRGBFillColor(context, components[0], components[1], components[2], components[3]);
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetStrokeColorWithColor(CGContextRef context, CGColorRef color) {
    NOISY_RETURN_IF_NULL(context);
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBStrokeColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Interoperable
*/
void CGContextSetStrokeColorSpace(CGContextRef context, CGColorSpaceRef colorSpace) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(colorSpace);
    context->SetStrokeColorSpace(colorSpace);
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    NOISY_RETURN_IF_NULL(context);
    CGContextSetRGBStrokeColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    NOISY_RETURN_IF_NULL(context);
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->DeviceContext()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().strokeBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKStrokeColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    NOISY_RETURN_IF_NULL(context);
    CGContextSetRGBStrokeColor(context,
                               (1.0f - cyan) * (1.0f - black),
                               (1.0f - magenta) * (1.0f - black),
                               (1.0f - yellow) * (1.0f - black),
                               alpha);
}
#pragma endregion

#pragma region Drawing Parameters - Shadows
// On the reference platform, shadow projection changes based on the framework that provided the
// drawing context. A bitmap context created through CGBitmapContextCreate(...) will always project
// shadows to the top right, even if the CTM is scaled [1.0, -1.0]. A context retrieved from UIKit,
// however, will always (regardless of the scale factor) project its shadows to the bottom right.
//
// It is therefore determined that each framework is allowed to specify the shadow projection matrix,
// likely through a private interface.
//
// This is that private interface.
void _CGContextSetShadowProjectionTransform(CGContextRef context, CGAffineTransform transform) {
    NOISY_RETURN_IF_NULL(context);
    context->shadowProjectionTransform = transform;
}

/**
 @Status Interoperable
*/
void CGContextSetShadow(CGContextRef context, CGSize offset, CGFloat blur) {
    NOISY_RETURN_IF_NULL(context);

    auto& state = context->CurrentGState();
    // The default shadow colour on the reference platform is black at 33% alpha.
    state.shadowColor = { 0.f, 0.f, 0.f, 1.f / 3.f };
    state.shadowOffset = CGSizeApplyAffineTransform(offset, context->shadowProjectionTransform);
    state.shadowBlur = blur;
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetShadowWithColor(CGContextRef context, CGSize offset, CGFloat blur, CGColorRef color) {
    NOISY_RETURN_IF_NULL(context);

    auto& state = context->CurrentGState();
    if (color) {
        const CGFloat* comp = CGColorGetComponents(color);
        state.shadowColor = { comp[0], comp[1], comp[2], comp[3] };
    } else {
        // Setting the alpha (4th component) to 0 disables shadowing.
        // This is in line with the reference platform's shadowing specification.
        state.shadowColor = { 0.f, 0.f, 0.f, 0.f };
    }
    state.shadowOffset = CGSizeApplyAffineTransform(offset, context->shadowProjectionTransform);
    state.shadowBlur = blur;
}
#pragma endregion

#pragma region Drawing Parameters - Fill Color
/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetFillColor(CGContextRef context, const CGFloat* components) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(components);
    // TODO: based on the color space, we should be setting the fill color componenets.
    // as color is not fully supported, assume RGBA for now.
    CGContextSetRGBFillColor(context, components[0], components[1], components[2], components[3]);
}

/**
 @Status Caveat
 @Notes Interoperable only for RGB.
*/
void CGContextSetFillColorWithColor(CGContextRef context, CGColorRef color) {
    NOISY_RETURN_IF_NULL(context);
    const CGFloat* comp = CGColorGetComponents(color);
    CGContextSetRGBFillColor(context, comp[0], comp[1], comp[2], comp[3]);
}

/**
 @Status Interoperable
*/
void CGContextSetFillColorSpace(CGContextRef context, CGColorSpaceRef colorSpace) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(colorSpace);
    context->SetFillColorSpace(colorSpace);
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef context, CGFloat gray, CGFloat alpha) {
    NOISY_RETURN_IF_NULL(context);
    CGContextSetRGBFillColor(context, gray, gray, gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    NOISY_RETURN_IF_NULL(context);
    ComPtr<ID2D1SolidColorBrush> brush;
    FAIL_FAST_IF_FAILED(context->DeviceContext()->CreateSolidColorBrush({ r, g, b, a }, &brush));
    FAIL_FAST_IF_FAILED(brush.As(&context->CurrentGState().fillBrush));
}

/**
 @Status Caveat
 @Notes Manually converts CMYK to RGB, and does not involve the colorspace.
*/
void CGContextSetCMYKFillColor(CGContextRef context, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    NOISY_RETURN_IF_NULL(context);
    CGContextSetRGBFillColor(context,
                             (1.0f - cyan) * (1.0f - black),
                             (1.0f - magenta) * (1.0f - black),
                             (1.0f - yellow) * (1.0f - black),
                             alpha);
}
#pragma endregion

#pragma region Image Helpers - CGImage / Brush

static HRESULT __CreateD2DBitmapFromCGImage(CGContextRef context, CGImageRef image, ID2D1Bitmap** bitmap) {
    RETURN_HR_IF_NULL(E_INVALIDARG, context);
    RETURN_HR_IF_NULL(E_INVALIDARG, image);
    RETURN_HR_IF_NULL(E_POINTER, bitmap);

    ComPtr<IWICBitmap> bmap;
    RETURN_IF_FAILED(_CGImageGetWICImageSource(image, &bmap));

    ComPtr<ID2D1Bitmap> d2dBitmap;
    RETURN_IF_FAILED(context->DeviceContext()->CreateBitmapFromWicBitmap(bmap.Get(), nullptr, &d2dBitmap));
    *bitmap = d2dBitmap.Detach();
    return S_OK;
}

static CGImageRef __CGContextCreateRenderableImage(CGImageRef image) {
    RETURN_NULL_IF(!image);
    WICPixelFormatGUID imagePixelFormat = _CGImageGetWICPixelFormat(image);
    if (!_CGIsValidRenderTargetPixelFormat(imagePixelFormat)) {
        // convert it to a valid pixelformat
        return _CGImageCreateCopyWithPixelFormat(image, GUID_WICPixelFormat32bppPBGRA);
    }

    return CGImageRetain(image);
}

#pragma endregion

#pragma region Drawing Parameters - Stroke / Fill Patterns

static HRESULT _CreatePatternBrush(CGContextRef context, CGPatternRef pattern, const CGFloat* components, ID2D1BitmapBrush1** brush) {
    // TODO: change to support grayscale (masks) after dustins change.
    woc::unique_cf<CGColorSpaceRef> colorspace{ CGColorSpaceCreateDeviceRGB() };

    // We need to generate the pattern as an image (then tile it)
    CGRect tileSize = _CGPatternGetFinalPatternSize(pattern);
    size_t bitsPerComponent = 8;
    size_t bytesPerRow = 4 * tileSize.size.width;
    CGBitmapInfo bitmapInfo = kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Big;

    woc::unique_cf<CGContextRef> patternContext{ CGBitmapContextCreate(
        nullptr, tileSize.size.width, tileSize.size.height, bitsPerComponent, bytesPerRow, colorspace.get(), bitmapInfo) };
    RETURN_HR_IF_NULL(E_UNEXPECTED, patternContext);

    CGContextSetFillColorSpace(patternContext.get(), context->FillColorSpace());
    // set the fill color
    CGContextSetFillColor(patternContext.get(), components);

    // Now we ask the user to draw
    _CGPaternIssueCallBack(patternContext.get(), pattern);

    // Get the image out of it
    woc::unique_cf<CGImageRef> tileImage{ __CGContextCreateRenderableImage(CGBitmapContextCreateImage(patternContext.get())) };
    RETURN_HR_IF_NULL(E_UNEXPECTED, tileImage);

    ComPtr<ID2D1Bitmap> d2dBitmap;
    RETURN_IF_FAILED(__CreateD2DBitmapFromCGImage(context, tileImage.get(), &d2dBitmap));

    // Scale it by the inverted transform
    // TODO: We have an issue with rotation, the CTM rotation should not affect the brush
    CGSize size = CGSizeApplyAffineTransform(tileSize.size, CGAffineTransformInvert(context->CurrentGState().transform));

    CGAffineTransform transform = __BitmapBrushTransformation(context,
                                                              { { 0, 0 }, size.width, size.height },
                                                              d2dBitmap->GetPixelSize(),
                                                              _CGPatternGetTransformation(pattern));

    ComPtr<ID2D1BitmapBrush1> bitmapBrush;
    ComPtr<ID2D1DeviceContext> deviceContext = context->DeviceContext();
    RETURN_IF_FAILED(deviceContext->CreateBitmapBrush(d2dBitmap.Get(),
                                                      D2D1::BitmapBrushProperties1(D2D1_EXTEND_MODE_WRAP,
                                                                                   D2D1_EXTEND_MODE_WRAP,
                                                                                   context->CurrentGState().GetInterpolationModeForCGImage(
                                                                                       tileImage.get())),
                                                      D2D1::BrushProperties(1 /* the global alpha will be set during the draw sequence*/,
                                                                            __CGAffineTransformToD2D_F(transform)),
                                                      &bitmapBrush));

    *brush = bitmapBrush.Detach();
    return S_OK;
}

/**
 @Status Caveat
 @Notes only supports RGBA components (due to CGContextSetFillColor only supporting RGBA)
*/
void CGContextSetFillPattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(pattern);
    NOISY_RETURN_IF_NULL(components);

    ComPtr<ID2D1BitmapBrush1> bitmapBrush;
    FAIL_FAST_IF_FAILED(_CreatePatternBrush(context, pattern, components, &bitmapBrush));
    // set the fill brush
    FAIL_FAST_IF_FAILED(bitmapBrush.As(&context->CurrentGState().fillBrush));
}

/**
 @Status Caveat
 @Notes only supports RGBA components (due to CGContextSetFillColor only supporting RGBA)
*/
void CGContextSetStrokePattern(CGContextRef context, CGPatternRef pattern, const CGFloat* components) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(pattern);
    NOISY_RETURN_IF_NULL(components);

    ComPtr<ID2D1BitmapBrush1> bitmapBrush;
    FAIL_FAST_IF_FAILED(_CreatePatternBrush(context, pattern, components, &bitmapBrush));
    // set the stroke brush
    FAIL_FAST_IF_FAILED(bitmapBrush.As(&context->CurrentGState().strokeBrush));
}

/**
 @Status Interoperable
*/
void CGContextSetPatternPhase(CGContextRef context, CGSize phase) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Operations - Text
/**
 @Status Stub
*/
void CGContextShowText(CGContextRef context, const char* str, unsigned count) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowTextAtPoint(CGContextRef context, CGFloat x, CGFloat y, const char* str, size_t length) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsAtPoint(CGContextRef context, CGFloat x, CGFloat y, const CGGlyph* glyphs, unsigned count) {
    NOISY_RETURN_IF_NULL(context);
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef context, const CGGlyph* glyphs, unsigned count) {
    NOISY_RETURN_IF_NULL(context);
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsAtPositions(CGContextRef context, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count) {
    NOISY_RETURN_IF_NULL(context);
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef context, const CGGlyph* glyphs, const CGSize* advances, size_t count) {
    NOISY_RETURN_IF_NULL(context);
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Operations - Basic Shapes
/**
 @Status Interoperable
*/
void CGContextClearRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    ComPtr<ID2D1DeviceContext> deviceContext = context->DeviceContext();
    deviceContext->PushAxisAlignedClip(__CGRectToD2D_F(rect), D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
    deviceContext->Clear(nullptr); // transparent black clear
    deviceContext->PopAxisAlignedClip();
}

HRESULT __CGContext::_CreateShadowEffect(ID2D1Image* inputImage, ID2D1Effect** outShadowEffect) {
    auto& state = CurrentGState();
    if (state.HasShadow()) {
        // The Shadow Effect takes an input image (or command list) and projects a shadow from
        // it with the specified parameters.
        //
        // INPUTS
        // 0: The input image/command list
        ComPtr<ID2D1Effect> shadowEffect;
        RETURN_IF_FAILED(deviceContext->CreateEffect(CLSID_D2D1Shadow, &shadowEffect));
        shadowEffect->SetInput(0, inputImage);
        RETURN_IF_FAILED(shadowEffect->SetValue(D2D1_SHADOW_PROP_COLOR, state.shadowColor));
        RETURN_IF_FAILED(shadowEffect->SetValue(D2D1_SHADOW_PROP_BLUR_STANDARD_DEVIATION, state.shadowBlur));

        // By default, the shadow projects straight down. Stacking it with an
        // Affine Transform effect allows us to change the shadow's projection.
        //
        // INPUTS
        // 0: The untransformed shadow
        ComPtr<ID2D1Effect> affineTransformEffect;
        RETURN_IF_FAILED(deviceContext->CreateEffect(CLSID_D2D12DAffineTransform, &affineTransformEffect));
        affineTransformEffect->SetInputEffect(0, shadowEffect.Get());

        CGSize deviceTransformedShadowOffset = CGSizeApplyAffineTransform(state.shadowOffset, deviceTransform);
        RETURN_IF_FAILED(affineTransformEffect->SetValue(D2D1_2DAFFINETRANSFORM_PROP_TRANSFORM_MATRIX,
                                                         D2D1::Matrix3x2F::Translation(deviceTransformedShadowOffset.width,
                                                                                       deviceTransformedShadowOffset.height)));

        // Drawing just a projected shadow is not terribly useful, so we composite the
        // shadow with the original input image (or command list) so that both get drawn.
        // The Composite Effect draws its inputs in ascending order.
        //
        // INPUTS
        // 0: The transformed shadow
        // 1: The input image/command list
        ComPtr<ID2D1Effect> compositeEffect;
        RETURN_IF_FAILED(deviceContext->CreateEffect(CLSID_D2D1Composite, &compositeEffect));
        compositeEffect->SetInputEffect(0, affineTransformEffect.Get());
        compositeEffect->SetInput(1, inputImage);

        *outShadowEffect = compositeEffect.Detach();
    } else {
        *outShadowEffect = nullptr;
    }

    return S_OK;
}

template <typename Lambda> // Lambda takes the form void(*)(CGContextRef, ID2D1DeviceContext*)
HRESULT __CGContext::DrawToCommandList(_CGCoordinateMode coordinateMode,
                                       CGAffineTransform* additionalTransform,
                                       ID2D1CommandList** outCommandList,
                                       Lambda&& drawLambda) {
    // Cache the original target to restore it later.
    ComPtr<ID2D1Image> originalTarget;
    deviceContext->GetTarget(&originalTarget);

    ComPtr<ID2D1CommandList> commandList;
    RETURN_IF_FAILED(deviceContext->CreateCommandList(&commandList));

    deviceContext->BeginDraw();
    deviceContext->SetTarget(commandList.Get());

    CGAffineTransform transform = CGAffineTransformIdentity;
    switch (coordinateMode) {
        case _kCGCoordinateModeUserSpace:
            transform = CGContextGetUserSpaceToDeviceSpaceTransform(this);
            break;
        case _kCGCoordinateModeDeviceSpace:
        default:
            // do nothing; base transform is identity.
            break;
    }

    if (additionalTransform) {
        transform = CGAffineTransformConcat(*additionalTransform, transform);
    }

    deviceContext->SetTransform(__CGAffineTransformToD2D_F(transform));

    RETURN_IF_FAILED(std::forward<Lambda>(drawLambda)(this, deviceContext.Get()));

    deviceContext->SetTransform(D2D1::IdentityMatrix());

    RETURN_IF_FAILED(deviceContext->EndDraw());
    RETURN_IF_FAILED(commandList->Close());

    deviceContext->SetTarget(originalTarget.Get());

    *outCommandList = commandList.Detach();
    return S_OK;
}

HRESULT __CGContext::DrawImage(ID2D1Image* image) {
    auto& state = CurrentGState();

    if (!image || !state.ShouldDraw()) {
        // Being asked to draw nothing is valid!
        return S_OK;
    }

    deviceContext->BeginDraw();

    bool layer = false;
    if (state.clippingGeometry || !IS_NEAR(state.globalAlpha, 1.0, .0001f) || state.opacityBrush) {
        layer = true;
        deviceContext->PushLayer(D2D1::LayerParameters(D2D1::InfiniteRect(),
                                                       state.clippingGeometry.Get(),
                                                       D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
                                                       D2D1::IdentityMatrix(),
                                                       state.globalAlpha,
                                                       state.opacityBrush.Get()),
                                 nullptr);
    }

    ComPtr<ID2D1Image> currentImage{ image };

    ComPtr<ID2D1Effect> shadowEffect;
    RETURN_IF_FAILED(_CreateShadowEffect(currentImage.Get(), &shadowEffect));
    if (shadowEffect) {
        RETURN_IF_FAILED(shadowEffect.As(&currentImage));
    }

    deviceContext->DrawImage(currentImage.Get());

    if (layer) {
        deviceContext->PopLayer();
    }

    // TODO GH#1194: We will need to re-evaluate Direct2D's D2DERR_RECREATE when we move to HW acceleration.
    RETURN_IF_FAILED(deviceContext->EndDraw());

    return S_OK;
}

HRESULT __CGContext::DrawGeometry(_CGCoordinateMode coordinateMode, ID2D1Geometry* pGeometry, CGPathDrawingMode drawMode) {
    ComPtr<ID2D1CommandList> commandList;
    ComPtr<ID2D1Geometry> geometry(pGeometry);
    HRESULT hr = DrawToCommandList(
        coordinateMode, nullptr, &commandList, [geometry, drawMode](CGContextRef context, ID2D1DeviceContext* deviceContext) {
            auto& state = context->CurrentGState();
            if (drawMode & kCGPathFill) {
                state.fillBrush->SetOpacity(state.alpha);

                ComPtr<ID2D1Geometry> geometryToFill;
                D2D1_FILL_MODE d2dFillMode =
                    (drawMode & kCGPathEOFill) == kCGPathEOFill ? D2D1_FILL_MODE_ALTERNATE : D2D1_FILL_MODE_WINDING;
                RETURN_IF_FAILED(_CGConvertD2DGeometryToFillMode(geometry.Get(), d2dFillMode, &geometryToFill));

                deviceContext->FillGeometry(geometryToFill.Get(), state.fillBrush.Get());
            }

            if (drawMode & kCGPathStroke && std::fpclassify(state.lineWidth) != FP_ZERO) {
                // This only computes the stroke style if its parameters have changed since the last draw.
                state.ComputeStrokeStyle(deviceContext);

                state.strokeBrush->SetOpacity(state.alpha);

                deviceContext->DrawGeometry(geometry.Get(), state.strokeBrush.Get(), state.lineWidth, state.strokeStyle.Get());
            }

            return S_OK;
        });

    RETURN_IF_FAILED(hr);

    return DrawImage(commandList.Get());
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextStrokeRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    auto factory = context->Factory();

    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    FAIL_FAST_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D_F(rect), &rectGeometry));

    FAIL_FAST_IF_FAILED(context->DrawGeometry(_kCGCoordinateModeUserSpace, rectGeometry.Get(), kCGPathStroke));

    context->ClearPath();
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextStrokeRectWithWidth(CGContextRef context, CGRect rect, CGFloat width) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    CGContextSaveGState(context);
    CGContextSetLineWidth(context, width);
    CGContextStrokeRect(context, rect);
    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextFillRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    auto factory = context->Factory();

    ComPtr<ID2D1RectangleGeometry> rectGeometry;
    FAIL_FAST_IF_FAILED(factory->CreateRectangleGeometry(__CGRectToD2D_F(rect), &rectGeometry));

    FAIL_FAST_IF_FAILED(context->DrawGeometry(_kCGCoordinateModeUserSpace, rectGeometry.Get(), kCGPathFill));

    context->ClearPath();
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextStrokeEllipseInRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    auto factory = context->Factory();

    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    FAIL_FAST_IF_FAILED(
        factory->CreateEllipseGeometry({ { CGRectGetMidX(rect), CGRectGetMidY(rect) }, rect.size.width / 2.f, rect.size.height / 2.f },
                                       &ellipseGeometry));

    FAIL_FAST_IF_FAILED(context->DrawGeometry(_kCGCoordinateModeUserSpace, ellipseGeometry.Get(), kCGPathStroke));

    context->ClearPath();
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextFillEllipseInRect(CGContextRef context, CGRect rect) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    auto factory = context->Factory();

    ComPtr<ID2D1EllipseGeometry> ellipseGeometry;
    FAIL_FAST_IF_FAILED(
        factory->CreateEllipseGeometry({ { CGRectGetMidX(rect), CGRectGetMidY(rect) }, rect.size.width / 2.f, rect.size.height / 2.f },
                                       &ellipseGeometry));

    FAIL_FAST_IF_FAILED(context->DrawGeometry(_kCGCoordinateModeUserSpace, ellipseGeometry.Get(), kCGPathFill));

    context->ClearPath();
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextStrokeLineSegments(CGContextRef context, const CGPoint* points, size_t count) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    if (!points || count == 0 || count % 2 != 0) {
        // On the reference platform, an uneven number of points results in a sizeof(CGPoint) read
        // beyond the end of the point buffer. Here we see fit to make that illegal.
        return;
    }

    CGContextBeginPath(context);
    for (unsigned k = 0; k < count; k += 2) {
        CGContextMoveToPoint(context, points[k].x, points[k].y);
        CGContextAddLineToPoint(context, points[k + 1].x, points[k + 1].y);
    }
    CGContextStrokePath(context);
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextFillRects(CGContextRef context, const CGRect* rects, size_t count) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    if (!rects || count == 0) {
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        CGContextFillRect(context, rects[i]);
    }
}
#pragma endregion

#pragma region Drawing Operations - Paths
/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextDrawPath(CGContextRef context, CGPathDrawingMode mode) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    if (context->HasPath()) {
        ComPtr<ID2D1Geometry> pGeometry;
        FAIL_FAST_IF_FAILED(_CGPathGetGeometry(context->Path(), &pGeometry));
        FAIL_FAST_IF_FAILED(context->DrawGeometry(_kCGCoordinateModeDeviceSpace, pGeometry.Get(), mode));
        context->ClearPath();
    }
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextStrokePath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    CGContextDrawPath(context, kCGPathStroke); // Clears path.
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextFillPath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    CGContextDrawPath(context, kCGPathFill); // Clears path.
}

/**
 @Status Interoperable
 @Notes The current path is cleared as a side effect of this function.
*/
void CGContextEOFillPath(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    CGContextDrawPath(context, kCGPathEOFill); // Clears path.
}
#pragma endregion

#pragma region Drawing Operations - CGImage

/**
 @Status Interoperable
*/
void CGContextDrawImage(CGContextRef context, CGRect rect, CGImageRef image) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(image);

    woc::unique_cf<CGImageRef> refImage{ __CGContextCreateRenderableImage(image) };

    ComPtr<ID2D1Bitmap> d2dBitmap;
    FAIL_FAST_IF_FAILED(__CreateD2DBitmapFromCGImage(context, refImage.get(), &d2dBitmap));

    // Flip the image to account for change in coordinate system origin.
    CGAffineTransform flipImage = CGAffineTransformMakeTranslation(rect.origin.x, rect.origin.y + (rect.size.height / 2.0));
    flipImage = CGAffineTransformScale(flipImage, 1.0, -1.0);
    flipImage = CGAffineTransformTranslate(flipImage, -rect.origin.x, -(rect.origin.y + (rect.size.height / 2.0)));

    ComPtr<ID2D1CommandList> commandList;
    HRESULT hr = context->DrawToCommandList(_kCGCoordinateModeUserSpace,
                                            &flipImage,
                                            &commandList,
                                            [&](CGContextRef context, ID2D1DeviceContext* deviceContext) {
                                                deviceContext->DrawBitmap(d2dBitmap.Get(), __CGRectToD2D_F(rect));
                                                return S_OK;
                                            });
    FAIL_FAST_IF_FAILED(hr);
    FAIL_FAST_IF_FAILED(context->DrawImage(commandList.Get()));
}

void _CGContextDrawImageRect(CGContextRef context, CGImageRef image, CGRect src, CGRect dst) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(image);

    if (CGRectEqualToRect(src, dst)) {
        CGContextDrawImage(context, dst, image);
        return;
    }

    RETURN_IF(CGRectGetHeight(src) == 0);
    RETURN_IF(CGRectGetWidth(src) == 0);

    // we want the source region to be drawn into the dest region (scaled)
    // The image needs to be scaled and translated for the destination.
    CGRect drawRect = CGRectMake(0, 0, CGImageGetWidth(image), CGImageGetHeight(image));
    // scale factor of the image
    float scaleX = CGRectGetWidth(dst) / CGRectGetWidth(src);
    float scaleY = CGRectGetHeight(dst) / CGRectGetHeight(src);
    // calculate he translation offset
    float deltaX = CGRectGetMinX(dst) - (CGRectGetMinX(src) * scaleX);
    float deltaY = CGRectGetMinY(dst) - (CGRectGetMinY(src) * scaleY);
    drawRect = CGRectMake(deltaX, deltaY, (float)CGImageGetWidth(image) * scaleX, (float)CGImageGetHeight(image) * scaleY);

    CGContextSaveGState(context);
    CGContextClipToRect(context, dst);
    CGContextDrawImage(context, drawRect, image);
    CGContextRestoreGState(context);
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef context, CGRect rect, CGImageRef image) {
    NOISY_RETURN_IF_NULL(context);
    NOISY_RETURN_IF_NULL(image);

    woc::unique_cf<CGImageRef> refImage{ __CGContextCreateRenderableImage(image) };

    ComPtr<ID2D1Bitmap> d2dBitmap;
    FAIL_FAST_IF_FAILED(__CreateD2DBitmapFromCGImage(context, refImage.get(), &d2dBitmap));

    CGAffineTransform transform =
        __BitmapBrushTransformation(context, rect, d2dBitmap->GetPixelSize(), CGContextGetUserSpaceToDeviceSpaceTransform(context));

    ComPtr<ID2D1BitmapBrush1> bitmapBrush;
    ComPtr<ID2D1DeviceContext> deviceContext = context->DeviceContext();
    FAIL_FAST_IF_FAILED(
        deviceContext->CreateBitmapBrush(d2dBitmap.Get(),
                                         D2D1::BitmapBrushProperties1(D2D1_EXTEND_MODE_WRAP,
                                                                      D2D1_EXTEND_MODE_WRAP,
                                                                      (CGImageGetShouldInterpolate(refImage.get()) ?
                                                                           context->CurrentGState().bitmapInterpolationMode :
                                                                           D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR)),
                                         D2D1::BrushProperties(context->CurrentGState().alpha, __CGAffineTransformToD2D_F(transform)),
                                         &bitmapBrush));

    // Area to fill
    D2D1_SIZE_F targetSize = deviceContext->GetSize();
    D2D1_RECT_F region = D2D1::RectF(0, 0, targetSize.width, targetSize.height);

    ComPtr<ID2D1CommandList> commandList;
    HRESULT hr = context->DrawToCommandList(_kCGCoordinateModeDeviceSpace,
                                            nullptr,
                                            &commandList,
                                            [&](CGContextRef context, ID2D1DeviceContext* deviceContext) {
                                                deviceContext->FillRectangle(&region, bitmapBrush.Get());
                                                return S_OK;
                                            });
    FAIL_FAST_IF_FAILED(hr);
    FAIL_FAST_IF_FAILED(context->DrawImage(commandList.Get()));
}

#pragma endregion

#pragma region Drawing Operations - Gradient + Shading
/**
 @Status Stub
*/
void CGContextDrawLinearGradient(
    CGContextRef context, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawRadialGradient(CGContextRef context,
                                 CGGradientRef gradient,
                                 CGPoint startCenter,
                                 CGFloat startRadius,
                                 CGPoint endCenter,
                                 CGFloat endRadius,
                                 CGGradientDrawingOptions options) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawShading(CGContextRef context, CGShadingRef shading) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Operations - CGLayer
/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef context, CGRect destRect, CGLayerRef layer) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint destPoint, CGLayerRef layer) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Drawing Operations - PDF
/**
 @Status Stub
 @Notes
*/
void CGContextDrawPDFPage(CGContextRef context, CGPDFPageRef page) {
    NOISY_RETURN_IF_NULL(context);
    RETURN_IF(!context->ShouldDraw());

    UNIMPLEMENTED();
}
#pragma endregion

#pragma region Internal Functions - To Be Removed
// TODO(DH) GH#1077 remove all of these internal functions.
// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
void CGContextClearToColor(CGContextRef context, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

bool CGContextIsDirty(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    return true;
}

void CGContextSetDirty(CGContextRef context, bool dirty) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

void CGContextReleaseLock(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context);
    UNIMPLEMENTED();
}

bool CGContextIsPointInPath(CGContextRef context, bool eoFill, CGFloat x, CGFloat y) {
    NOISY_RETURN_IF_NULL(context, StubReturn());
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextDrawGlyphRun(CGContextRef context, const DWRITE_GLYPH_RUN* glyphRun) {
    NOISY_RETURN_IF_NULL(context);
    // TODO(DH) GH#1070 Merge in CGContextCairo.mm's Glyph Run code.
}
#pragma endregion

#pragma region CGBitmapContext
struct __CGBitmapContext : CoreFoundation::CppBase<__CGBitmapContext, __CGContext> {
    woc::unique_cf<CGImageRef> _image;

    __CGBitmapContext(ID2D1RenderTarget* renderTarget, REFWICPixelFormatGUID outputPixelFormat)
        : Parent(renderTarget), _outputPixelFormat(outputPixelFormat) {
    }

    inline void SetImage(CGImageRef image) {
        _image.reset(CGImageRetain(image));
    }

    inline REFWICPixelFormatGUID GetOutputPixelFormat() const {
        return _outputPixelFormat;
    }

private:
    WICPixelFormatGUID _outputPixelFormat;
};

/**
 @Status Caveat
 We only support formats that are 32 bits per pixel, colorspace and bitmapinfo that are ARGB.
*/
CGContextRef CGBitmapContextCreate(void* data,
                                   size_t width,
                                   size_t height,
                                   size_t bitsPerComponent,
                                   size_t bytesPerRow,
                                   CGColorSpaceRef colorSpace,
                                   CGBitmapInfo bitmapInfo) {
    return CGBitmapContextCreateWithData(data, width, height, bitsPerComponent, bytesPerRow, colorSpace, bitmapInfo, nullptr, nullptr);
}

/**
 @Status Caveat
 @Notes releaseCallback and releaseInfo is ignored.
 We only support formats that are 32 bits per pixel, colorspace and bitmapinfo that are ARGB.
*/
CGContextRef CGBitmapContextCreateWithData(void* data,
                                           size_t width,
                                           size_t height,
                                           size_t bitsPerComponent,
                                           size_t bytesPerRow,
                                           CGColorSpaceRef space,
                                           uint32_t bitmapInfo,
                                           CGBitmapContextReleaseDataCallback releaseCallback,
                                           void* releaseInfo) {
    RETURN_NULL_IF(!width);
    RETURN_NULL_IF(!height);
    RETURN_NULL_IF(!space);

    // bitsperpixel = ((bytesPerRow/width) * 8bits/byte)
    size_t bitsPerPixel = ((bytesPerRow / width) << 3);
    REFWICPixelFormatGUID outputPixelFormat =
        _CGImageGetWICPixelFormatFromImageProperties(bitsPerComponent, bitsPerPixel, space, bitmapInfo);
    WICPixelFormatGUID pixelFormat = outputPixelFormat;

    if (!_CGIsValidRenderTargetPixelFormat(pixelFormat)) {
        if (data) {
            UNIMPLEMENTED_WITH_MSG(
                "CGBitmapContext does not currently support input conversion and can only render into 32bpp PRGBA buffers.");
            return nullptr;
        }
        pixelFormat = GUID_WICPixelFormat32bppPRGBA;
    }

    // if data is null, enough memory is allocated via CGIWICBitmap
    ComPtr<IWICBitmap> customBitmap = Make<CGIWICBitmap>(data, pixelFormat, height, width);
    RETURN_NULL_IF(!customBitmap);

    woc::unique_cf<CGImageRef> image(_CGImageCreateWithWICBitmap(customBitmap.Get()));
    RETURN_NULL_IF(!image);

    ComPtr<ID2D1Factory> factory;
    RETURN_NULL_IF_FAILED(_CGGetD2DFactory(&factory));

    ComPtr<ID2D1RenderTarget> renderTarget;
    RETURN_NULL_IF_FAILED(factory->CreateWicBitmapRenderTarget(customBitmap.Get(), D2D1::RenderTargetProperties(), &renderTarget));
    CGContextRef context = _CGBitmapContextCreateWithRenderTarget(renderTarget.Get(), image.get(), outputPixelFormat);
    return context;
}

/**
 @Status Interoperable
*/
CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, kCGBitmapByteOrderDefault);
    return CGImageGetBitmapInfo(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, kCGImageAlphaNone);
    return CGImageGetAlphaInfo(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBitsPerComponent(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, 0);
    return CGImageGetBitsPerComponent(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBitsPerPixel(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, 0);
    return CGImageGetBitsPerPixel(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, nullptr);
    return CGImageGetColorSpace(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, 0);
    return CGImageGetWidth(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, 0);
    return CGImageGetHeight(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, 0);
    return CGImageGetBytesPerRow(CGBitmapContextGetImage(context));
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, nullptr);
    return _CGImageGetRawBytes(CGBitmapContextGetImage(context));
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the copy of the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, nullptr);
    if (CFGetTypeID(context) != __CGBitmapContext::GetTypeID()) {
        TraceError(TAG, L"Image requested from non-bitmap CGContext.");
        return nullptr;
    }

    // This copy is a no-op if the output format requested matches the backing image format.
    __CGBitmapContext* bitmapContext = (__CGBitmapContext*)context;
    return _CGImageCreateCopyWithPixelFormat(bitmapContext->_image.get(), bitmapContext->GetOutputPixelFormat());
}

CGImageRef CGBitmapContextGetImage(CGContextRef context) {
    NOISY_RETURN_IF_NULL(context, nullptr);
    if (CFGetTypeID(context) != __CGBitmapContext::GetTypeID()) {
        TraceError(TAG, L"Image requested from non-bitmap CGContext.");
        return nullptr;
    }
    return ((__CGBitmapContext*)context)->_image.get();
}

CGContextRef _CGBitmapContextCreateWithRenderTarget(ID2D1RenderTarget* renderTarget, CGImageRef img, WICPixelFormatGUID outputPixelFormat) {
    RETURN_NULL_IF(!renderTarget);
    __CGBitmapContext* context = __CGBitmapContext::CreateInstance(kCFAllocatorDefault, renderTarget, outputPixelFormat);
    __CGContextPrepareDefaults(context);
    context->SetImage(img);
    return context;
}

CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt) {
    UNIMPLEMENTED();
    return StubReturn();
}
#pragma endregion
