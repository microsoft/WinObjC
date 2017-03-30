// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Composition.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Composition {

struct WINRT_EBO AmbientLight :
    Windows::UI::Composition::IAmbientLight,
    impl::bases<AmbientLight, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionLight>,
    impl::require<AmbientLight, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionLight, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    AmbientLight(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ColorKeyFrameAnimation :
    Windows::UI::Composition::IColorKeyFrameAnimation,
    impl::bases<ColorKeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<ColorKeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    ColorKeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionAnimation :
    Windows::UI::Composition::ICompositionAnimation,
    impl::bases<CompositionAnimation, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionAnimationGroup :
    Windows::UI::Composition::ICompositionAnimationGroup,
    impl::bases<CompositionAnimationGroup, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionAnimationGroup, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionAnimationGroup(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionBackdropBrush :
    Windows::UI::Composition::ICompositionBackdropBrush,
    impl::bases<CompositionBackdropBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionBackdropBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionBackdropBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionBatchCompletedEventArgs :
    Windows::UI::Composition::ICompositionBatchCompletedEventArgs,
    impl::bases<CompositionBatchCompletedEventArgs, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionBatchCompletedEventArgs, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionBatchCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionBrush :
    Windows::UI::Composition::ICompositionBrush,
    impl::bases<CompositionBrush, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionClip :
    Windows::UI::Composition::ICompositionClip,
    impl::bases<CompositionClip, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionClip, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionClip2, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionClip(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionColorBrush :
    Windows::UI::Composition::ICompositionColorBrush,
    impl::bases<CompositionColorBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionColorBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionColorBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionCommitBatch :
    Windows::UI::Composition::ICompositionCommitBatch,
    impl::bases<CompositionCommitBatch, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionCommitBatch, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionCommitBatch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionDrawingSurface :
    Windows::UI::Composition::ICompositionDrawingSurface,
    impl::bases<CompositionDrawingSurface, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionDrawingSurface, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::ICompositionSurface>
{
    CompositionDrawingSurface(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionEasingFunction :
    Windows::UI::Composition::ICompositionEasingFunction,
    impl::bases<CompositionEasingFunction, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionEasingFunction, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionEasingFunction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionEffectBrush :
    Windows::UI::Composition::ICompositionEffectBrush,
    impl::bases<CompositionEffectBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionEffectBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionEffectBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionEffectFactory :
    Windows::UI::Composition::ICompositionEffectFactory,
    impl::bases<CompositionEffectFactory, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionEffectFactory, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionEffectFactory(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionEffectSourceParameter :
    Windows::UI::Composition::ICompositionEffectSourceParameter
{
    CompositionEffectSourceParameter(std::nullptr_t) noexcept {}
    CompositionEffectSourceParameter(hstring_view name);
};

struct WINRT_EBO CompositionGraphicsDevice :
    Windows::UI::Composition::ICompositionGraphicsDevice,
    impl::bases<CompositionGraphicsDevice, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionGraphicsDevice, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionGraphicsDevice(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionLight :
    Windows::UI::Composition::ICompositionLight,
    impl::bases<CompositionLight, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionLight, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionLight(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionMaskBrush :
    Windows::UI::Composition::ICompositionMaskBrush,
    impl::bases<CompositionMaskBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionMaskBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionMaskBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionNineGridBrush :
    Windows::UI::Composition::ICompositionNineGridBrush,
    impl::bases<CompositionNineGridBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionNineGridBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionNineGridBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionObject :
    Windows::UI::Composition::ICompositionObject,
    impl::require<CompositionObject, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject2>
{
    CompositionObject(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionPropertySet :
    Windows::UI::Composition::ICompositionPropertySet,
    impl::bases<CompositionPropertySet, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionPropertySet, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::ICompositionPropertySet2>
{
    CompositionPropertySet(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionScopedBatch :
    Windows::UI::Composition::ICompositionScopedBatch,
    impl::bases<CompositionScopedBatch, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionScopedBatch, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionScopedBatch(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionShadow :
    Windows::UI::Composition::ICompositionShadow,
    impl::bases<CompositionShadow, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionShadow, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionShadow(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionSurfaceBrush :
    Windows::UI::Composition::ICompositionSurfaceBrush,
    impl::bases<CompositionSurfaceBrush, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionBrush>,
    impl::require<CompositionSurfaceBrush, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionBrush, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::ICompositionSurfaceBrush2>
{
    CompositionSurfaceBrush(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CompositionTarget :
    Windows::UI::Composition::ICompositionTarget,
    impl::bases<CompositionTarget, Windows::UI::Composition::CompositionObject>,
    impl::require<CompositionTarget, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CompositionTarget(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Compositor :
    Windows::UI::Composition::ICompositor,
    impl::require<Compositor, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositor2>
{
    Compositor(std::nullptr_t) noexcept {}
    Compositor();
};

struct WINRT_EBO ContainerVisual :
    Windows::UI::Composition::IContainerVisual,
    impl::bases<ContainerVisual, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::Visual>,
    impl::require<ContainerVisual, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IVisual>
{
    ContainerVisual(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CubicBezierEasingFunction :
    Windows::UI::Composition::ICubicBezierEasingFunction,
    impl::bases<CubicBezierEasingFunction, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionEasingFunction>,
    impl::require<CubicBezierEasingFunction, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionEasingFunction, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    CubicBezierEasingFunction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DistantLight :
    Windows::UI::Composition::IDistantLight,
    impl::bases<DistantLight, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionLight>,
    impl::require<DistantLight, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionLight, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    DistantLight(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DropShadow :
    Windows::UI::Composition::IDropShadow,
    impl::bases<DropShadow, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionShadow>,
    impl::require<DropShadow, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::ICompositionShadow>
{
    DropShadow(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ExpressionAnimation :
    Windows::UI::Composition::IExpressionAnimation,
    impl::bases<ExpressionAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation>,
    impl::require<ExpressionAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    ExpressionAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ImplicitAnimationCollection :
    Windows::UI::Composition::IImplicitAnimationCollection,
    impl::bases<ImplicitAnimationCollection, Windows::UI::Composition::CompositionObject>,
    impl::require<ImplicitAnimationCollection, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    ImplicitAnimationCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InsetClip :
    Windows::UI::Composition::IInsetClip,
    impl::bases<InsetClip, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionClip>,
    impl::require<InsetClip, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionClip, Windows::UI::Composition::ICompositionClip2, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    InsetClip(std::nullptr_t) noexcept {}
};

struct WINRT_EBO KeyFrameAnimation :
    Windows::UI::Composition::IKeyFrameAnimation,
    impl::bases<KeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation>,
    impl::require<KeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation2>
{
    KeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LayerVisual :
    Windows::UI::Composition::ILayerVisual,
    impl::bases<LayerVisual, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::Visual, Windows::UI::Composition::ContainerVisual>,
    impl::require<LayerVisual, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IContainerVisual, Windows::UI::Composition::IVisual>
{
    LayerVisual(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LinearEasingFunction :
    Windows::UI::Composition::ILinearEasingFunction,
    impl::bases<LinearEasingFunction, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionEasingFunction>,
    impl::require<LinearEasingFunction, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionEasingFunction, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    LinearEasingFunction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PointLight :
    Windows::UI::Composition::IPointLight,
    impl::bases<PointLight, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionLight>,
    impl::require<PointLight, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionLight, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    PointLight(std::nullptr_t) noexcept {}
};

struct WINRT_EBO QuaternionKeyFrameAnimation :
    Windows::UI::Composition::IQuaternionKeyFrameAnimation,
    impl::bases<QuaternionKeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<QuaternionKeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    QuaternionKeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RenderingDeviceReplacedEventArgs :
    Windows::UI::Composition::IRenderingDeviceReplacedEventArgs,
    impl::bases<RenderingDeviceReplacedEventArgs, Windows::UI::Composition::CompositionObject>,
    impl::require<RenderingDeviceReplacedEventArgs, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    RenderingDeviceReplacedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ScalarKeyFrameAnimation :
    Windows::UI::Composition::IScalarKeyFrameAnimation,
    impl::bases<ScalarKeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<ScalarKeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    ScalarKeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpotLight :
    Windows::UI::Composition::ISpotLight,
    impl::bases<SpotLight, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionLight>,
    impl::require<SpotLight, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionLight, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    SpotLight(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpriteVisual :
    Windows::UI::Composition::ISpriteVisual,
    impl::bases<SpriteVisual, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::Visual, Windows::UI::Composition::ContainerVisual>,
    impl::require<SpriteVisual, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IContainerVisual, Windows::UI::Composition::ISpriteVisual2, Windows::UI::Composition::IVisual>
{
    SpriteVisual(std::nullptr_t) noexcept {}
};

struct WINRT_EBO StepEasingFunction :
    Windows::UI::Composition::IStepEasingFunction,
    impl::bases<StepEasingFunction, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionEasingFunction>,
    impl::require<StepEasingFunction, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionEasingFunction, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    StepEasingFunction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Vector2KeyFrameAnimation :
    Windows::UI::Composition::IVector2KeyFrameAnimation,
    impl::bases<Vector2KeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<Vector2KeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    Vector2KeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Vector3KeyFrameAnimation :
    Windows::UI::Composition::IVector3KeyFrameAnimation,
    impl::bases<Vector3KeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<Vector3KeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    Vector3KeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Vector4KeyFrameAnimation :
    Windows::UI::Composition::IVector4KeyFrameAnimation,
    impl::bases<Vector4KeyFrameAnimation, Windows::UI::Composition::CompositionObject, Windows::UI::Composition::CompositionAnimation, Windows::UI::Composition::KeyFrameAnimation>,
    impl::require<Vector4KeyFrameAnimation, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionAnimation, Windows::UI::Composition::ICompositionAnimation2, Windows::UI::Composition::ICompositionAnimationBase, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2, Windows::UI::Composition::IKeyFrameAnimation, Windows::UI::Composition::IKeyFrameAnimation2>
{
    Vector4KeyFrameAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Visual :
    Windows::UI::Composition::IVisual,
    impl::bases<Visual, Windows::UI::Composition::CompositionObject>,
    impl::require<Visual, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    Visual(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VisualCollection :
    Windows::UI::Composition::IVisualCollection,
    impl::bases<VisualCollection, Windows::UI::Composition::CompositionObject>,
    impl::require<VisualCollection, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    VisualCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VisualUnorderedCollection :
    Windows::UI::Composition::IVisualUnorderedCollection,
    impl::bases<VisualUnorderedCollection, Windows::UI::Composition::CompositionObject>,
    impl::require<VisualUnorderedCollection, Windows::Foundation::IClosable, Windows::UI::Composition::ICompositionObject, Windows::UI::Composition::ICompositionObject2>
{
    VisualUnorderedCollection(std::nullptr_t) noexcept {}
};

}

}
