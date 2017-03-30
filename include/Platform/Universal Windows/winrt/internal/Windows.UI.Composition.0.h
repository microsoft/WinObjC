// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Composition {

struct IAmbientLight;
struct IColorKeyFrameAnimation;
struct ICompositionAnimation;
struct ICompositionAnimation2;
struct ICompositionAnimationBase;
struct ICompositionAnimationFactory;
struct ICompositionAnimationGroup;
struct ICompositionBackdropBrush;
struct ICompositionBatchCompletedEventArgs;
struct ICompositionBrush;
struct ICompositionBrushFactory;
struct ICompositionClip;
struct ICompositionClip2;
struct ICompositionClipFactory;
struct ICompositionColorBrush;
struct ICompositionCommitBatch;
struct ICompositionDrawingSurface;
struct ICompositionEasingFunction;
struct ICompositionEasingFunctionFactory;
struct ICompositionEffectBrush;
struct ICompositionEffectFactory;
struct ICompositionEffectSourceParameter;
struct ICompositionEffectSourceParameterFactory;
struct ICompositionGraphicsDevice;
struct ICompositionLight;
struct ICompositionLightFactory;
struct ICompositionMaskBrush;
struct ICompositionNineGridBrush;
struct ICompositionObject;
struct ICompositionObject2;
struct ICompositionObjectFactory;
struct ICompositionPropertySet;
struct ICompositionPropertySet2;
struct ICompositionScopedBatch;
struct ICompositionShadow;
struct ICompositionShadowFactory;
struct ICompositionSurface;
struct ICompositionSurfaceBrush;
struct ICompositionSurfaceBrush2;
struct ICompositionTarget;
struct ICompositor;
struct ICompositor2;
struct IContainerVisual;
struct IContainerVisualFactory;
struct ICubicBezierEasingFunction;
struct IDistantLight;
struct IDropShadow;
struct IExpressionAnimation;
struct IImplicitAnimationCollection;
struct IInsetClip;
struct IKeyFrameAnimation;
struct IKeyFrameAnimation2;
struct IKeyFrameAnimationFactory;
struct ILayerVisual;
struct ILinearEasingFunction;
struct IPointLight;
struct IQuaternionKeyFrameAnimation;
struct IRenderingDeviceReplacedEventArgs;
struct IScalarKeyFrameAnimation;
struct ISpotLight;
struct ISpriteVisual;
struct ISpriteVisual2;
struct IStepEasingFunction;
struct IVector2KeyFrameAnimation;
struct IVector3KeyFrameAnimation;
struct IVector4KeyFrameAnimation;
struct IVisual;
struct IVisualCollection;
struct IVisualFactory;
struct IVisualUnorderedCollection;
struct AmbientLight;
struct ColorKeyFrameAnimation;
struct CompositionAnimation;
struct CompositionAnimationGroup;
struct CompositionBackdropBrush;
struct CompositionBatchCompletedEventArgs;
struct CompositionBrush;
struct CompositionClip;
struct CompositionColorBrush;
struct CompositionCommitBatch;
struct CompositionDrawingSurface;
struct CompositionEasingFunction;
struct CompositionEffectBrush;
struct CompositionEffectFactory;
struct CompositionEffectSourceParameter;
struct CompositionGraphicsDevice;
struct CompositionLight;
struct CompositionMaskBrush;
struct CompositionNineGridBrush;
struct CompositionObject;
struct CompositionPropertySet;
struct CompositionScopedBatch;
struct CompositionShadow;
struct CompositionSurfaceBrush;
struct CompositionTarget;
struct Compositor;
struct ContainerVisual;
struct CubicBezierEasingFunction;
struct DistantLight;
struct DropShadow;
struct ExpressionAnimation;
struct ImplicitAnimationCollection;
struct InsetClip;
struct KeyFrameAnimation;
struct LayerVisual;
struct LinearEasingFunction;
struct PointLight;
struct QuaternionKeyFrameAnimation;
struct RenderingDeviceReplacedEventArgs;
struct ScalarKeyFrameAnimation;
struct SpotLight;
struct SpriteVisual;
struct StepEasingFunction;
struct Vector2KeyFrameAnimation;
struct Vector3KeyFrameAnimation;
struct Vector4KeyFrameAnimation;
struct Visual;
struct VisualCollection;
struct VisualUnorderedCollection;

}

namespace Windows::UI::Composition {

struct IAmbientLight;
struct IColorKeyFrameAnimation;
struct ICompositionAnimation;
struct ICompositionAnimation2;
struct ICompositionAnimationBase;
struct ICompositionAnimationFactory;
struct ICompositionAnimationGroup;
struct ICompositionBackdropBrush;
struct ICompositionBatchCompletedEventArgs;
struct ICompositionBrush;
struct ICompositionBrushFactory;
struct ICompositionClip;
struct ICompositionClip2;
struct ICompositionClipFactory;
struct ICompositionColorBrush;
struct ICompositionCommitBatch;
struct ICompositionDrawingSurface;
struct ICompositionEasingFunction;
struct ICompositionEasingFunctionFactory;
struct ICompositionEffectBrush;
struct ICompositionEffectFactory;
struct ICompositionEffectSourceParameter;
struct ICompositionEffectSourceParameterFactory;
struct ICompositionGraphicsDevice;
struct ICompositionLight;
struct ICompositionLightFactory;
struct ICompositionMaskBrush;
struct ICompositionNineGridBrush;
struct ICompositionObject;
struct ICompositionObject2;
struct ICompositionObjectFactory;
struct ICompositionPropertySet;
struct ICompositionPropertySet2;
struct ICompositionScopedBatch;
struct ICompositionShadow;
struct ICompositionShadowFactory;
struct ICompositionSurface;
struct ICompositionSurfaceBrush;
struct ICompositionSurfaceBrush2;
struct ICompositionTarget;
struct ICompositor;
struct ICompositor2;
struct IContainerVisual;
struct IContainerVisualFactory;
struct ICubicBezierEasingFunction;
struct IDistantLight;
struct IDropShadow;
struct IExpressionAnimation;
struct IImplicitAnimationCollection;
struct IInsetClip;
struct IKeyFrameAnimation;
struct IKeyFrameAnimation2;
struct IKeyFrameAnimationFactory;
struct ILayerVisual;
struct ILinearEasingFunction;
struct IPointLight;
struct IQuaternionKeyFrameAnimation;
struct IRenderingDeviceReplacedEventArgs;
struct IScalarKeyFrameAnimation;
struct ISpotLight;
struct ISpriteVisual;
struct ISpriteVisual2;
struct IStepEasingFunction;
struct IVector2KeyFrameAnimation;
struct IVector3KeyFrameAnimation;
struct IVector4KeyFrameAnimation;
struct IVisual;
struct IVisualCollection;
struct IVisualFactory;
struct IVisualUnorderedCollection;
struct AmbientLight;
struct ColorKeyFrameAnimation;
struct CompositionAnimation;
struct CompositionAnimationGroup;
struct CompositionBackdropBrush;
struct CompositionBatchCompletedEventArgs;
struct CompositionBrush;
struct CompositionClip;
struct CompositionColorBrush;
struct CompositionCommitBatch;
struct CompositionDrawingSurface;
struct CompositionEasingFunction;
struct CompositionEffectBrush;
struct CompositionEffectFactory;
struct CompositionEffectSourceParameter;
struct CompositionGraphicsDevice;
struct CompositionLight;
struct CompositionMaskBrush;
struct CompositionNineGridBrush;
struct CompositionObject;
struct CompositionPropertySet;
struct CompositionScopedBatch;
struct CompositionShadow;
struct CompositionSurfaceBrush;
struct CompositionTarget;
struct Compositor;
struct ContainerVisual;
struct CubicBezierEasingFunction;
struct DistantLight;
struct DropShadow;
struct ExpressionAnimation;
struct ImplicitAnimationCollection;
struct InsetClip;
struct KeyFrameAnimation;
struct LayerVisual;
struct LinearEasingFunction;
struct PointLight;
struct QuaternionKeyFrameAnimation;
struct RenderingDeviceReplacedEventArgs;
struct ScalarKeyFrameAnimation;
struct SpotLight;
struct SpriteVisual;
struct StepEasingFunction;
struct Vector2KeyFrameAnimation;
struct Vector3KeyFrameAnimation;
struct Vector4KeyFrameAnimation;
struct Visual;
struct VisualCollection;
struct VisualUnorderedCollection;

}

namespace Windows::UI::Composition {

template <typename T> struct impl_IAmbientLight;
template <typename T> struct impl_IColorKeyFrameAnimation;
template <typename T> struct impl_ICompositionAnimation;
template <typename T> struct impl_ICompositionAnimation2;
template <typename T> struct impl_ICompositionAnimationBase;
template <typename T> struct impl_ICompositionAnimationFactory;
template <typename T> struct impl_ICompositionAnimationGroup;
template <typename T> struct impl_ICompositionBackdropBrush;
template <typename T> struct impl_ICompositionBatchCompletedEventArgs;
template <typename T> struct impl_ICompositionBrush;
template <typename T> struct impl_ICompositionBrushFactory;
template <typename T> struct impl_ICompositionClip;
template <typename T> struct impl_ICompositionClip2;
template <typename T> struct impl_ICompositionClipFactory;
template <typename T> struct impl_ICompositionColorBrush;
template <typename T> struct impl_ICompositionCommitBatch;
template <typename T> struct impl_ICompositionDrawingSurface;
template <typename T> struct impl_ICompositionEasingFunction;
template <typename T> struct impl_ICompositionEasingFunctionFactory;
template <typename T> struct impl_ICompositionEffectBrush;
template <typename T> struct impl_ICompositionEffectFactory;
template <typename T> struct impl_ICompositionEffectSourceParameter;
template <typename T> struct impl_ICompositionEffectSourceParameterFactory;
template <typename T> struct impl_ICompositionGraphicsDevice;
template <typename T> struct impl_ICompositionLight;
template <typename T> struct impl_ICompositionLightFactory;
template <typename T> struct impl_ICompositionMaskBrush;
template <typename T> struct impl_ICompositionNineGridBrush;
template <typename T> struct impl_ICompositionObject;
template <typename T> struct impl_ICompositionObject2;
template <typename T> struct impl_ICompositionObjectFactory;
template <typename T> struct impl_ICompositionPropertySet;
template <typename T> struct impl_ICompositionPropertySet2;
template <typename T> struct impl_ICompositionScopedBatch;
template <typename T> struct impl_ICompositionShadow;
template <typename T> struct impl_ICompositionShadowFactory;
template <typename T> struct impl_ICompositionSurface;
template <typename T> struct impl_ICompositionSurfaceBrush;
template <typename T> struct impl_ICompositionSurfaceBrush2;
template <typename T> struct impl_ICompositionTarget;
template <typename T> struct impl_ICompositor;
template <typename T> struct impl_ICompositor2;
template <typename T> struct impl_IContainerVisual;
template <typename T> struct impl_IContainerVisualFactory;
template <typename T> struct impl_ICubicBezierEasingFunction;
template <typename T> struct impl_IDistantLight;
template <typename T> struct impl_IDropShadow;
template <typename T> struct impl_IExpressionAnimation;
template <typename T> struct impl_IImplicitAnimationCollection;
template <typename T> struct impl_IInsetClip;
template <typename T> struct impl_IKeyFrameAnimation;
template <typename T> struct impl_IKeyFrameAnimation2;
template <typename T> struct impl_IKeyFrameAnimationFactory;
template <typename T> struct impl_ILayerVisual;
template <typename T> struct impl_ILinearEasingFunction;
template <typename T> struct impl_IPointLight;
template <typename T> struct impl_IQuaternionKeyFrameAnimation;
template <typename T> struct impl_IRenderingDeviceReplacedEventArgs;
template <typename T> struct impl_IScalarKeyFrameAnimation;
template <typename T> struct impl_ISpotLight;
template <typename T> struct impl_ISpriteVisual;
template <typename T> struct impl_ISpriteVisual2;
template <typename T> struct impl_IStepEasingFunction;
template <typename T> struct impl_IVector2KeyFrameAnimation;
template <typename T> struct impl_IVector3KeyFrameAnimation;
template <typename T> struct impl_IVector4KeyFrameAnimation;
template <typename T> struct impl_IVisual;
template <typename T> struct impl_IVisualCollection;
template <typename T> struct impl_IVisualFactory;
template <typename T> struct impl_IVisualUnorderedCollection;

}

namespace Windows::UI::Composition {

enum class AnimationDirection
{
    Normal = 0,
    Reverse = 1,
    Alternate = 2,
    AlternateReverse = 3,
};

enum class AnimationIterationBehavior
{
    Count = 0,
    Forever = 1,
};

enum class AnimationStopBehavior
{
    LeaveCurrentValue = 0,
    SetToInitialValue = 1,
    SetToFinalValue = 2,
};

enum class CompositionBackfaceVisibility
{
    Inherit = 0,
    Visible = 1,
    Hidden = 2,
};

enum class CompositionBatchTypes : unsigned
{
    None = 0x0,
    Animation = 0x1,
    Effect = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(CompositionBatchTypes)

enum class CompositionBitmapInterpolationMode
{
    NearestNeighbor = 0,
    Linear = 1,
};

enum class CompositionBorderMode
{
    Inherit = 0,
    Soft = 1,
    Hard = 2,
};

enum class CompositionColorSpace
{
    Auto = 0,
    Hsl = 1,
    Rgb = 2,
};

enum class CompositionCompositeMode
{
    Inherit = 0,
    SourceOver = 1,
    DestinationInvert = 2,
    MinBlend = 3,
};

enum class CompositionEffectFactoryLoadStatus
{
    Success = 0,
    EffectTooComplex = 1,
    Pending = 2,
    Other = -1,
};

enum class CompositionGetValueStatus
{
    Succeeded = 0,
    TypeMismatch = 1,
    NotFound = 2,
};

enum class CompositionStretch
{
    None = 0,
    Fill = 1,
    Uniform = 2,
    UniformToFill = 3,
};

}

}
