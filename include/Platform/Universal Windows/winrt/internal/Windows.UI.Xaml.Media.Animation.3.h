// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.Animation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Animation {

struct WINRT_EBO AddDeleteThemeTransition :
    Windows::UI::Xaml::Media::Animation::IAddDeleteThemeTransition,
    impl::bases<AddDeleteThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<AddDeleteThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    AddDeleteThemeTransition(std::nullptr_t) noexcept {}
    AddDeleteThemeTransition();
};

struct WINRT_EBO BackEase :
    Windows::UI::Xaml::Media::Animation::IBackEase,
    impl::bases<BackEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<BackEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    BackEase(std::nullptr_t) noexcept {}
    BackEase();
    static Windows::UI::Xaml::DependencyProperty AmplitudeProperty();
};

struct WINRT_EBO BeginStoryboard :
    Windows::UI::Xaml::Media::Animation::IBeginStoryboard,
    impl::bases<BeginStoryboard, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::TriggerAction>,
    impl::require<BeginStoryboard, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::ITriggerAction>
{
    BeginStoryboard(std::nullptr_t) noexcept {}
    BeginStoryboard();
    static Windows::UI::Xaml::DependencyProperty StoryboardProperty();
};

struct WINRT_EBO BounceEase :
    Windows::UI::Xaml::Media::Animation::IBounceEase,
    impl::bases<BounceEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<BounceEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    BounceEase(std::nullptr_t) noexcept {}
    BounceEase();
    static Windows::UI::Xaml::DependencyProperty BouncesProperty();
    static Windows::UI::Xaml::DependencyProperty BouncinessProperty();
};

struct WINRT_EBO CircleEase :
    Windows::UI::Xaml::Media::Animation::ICircleEase,
    impl::bases<CircleEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<CircleEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    CircleEase(std::nullptr_t) noexcept {}
    CircleEase();
};

struct WINRT_EBO ColorAnimation :
    Windows::UI::Xaml::Media::Animation::IColorAnimation,
    impl::bases<ColorAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<ColorAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    ColorAnimation(std::nullptr_t) noexcept {}
    ColorAnimation();
    static Windows::UI::Xaml::DependencyProperty FromProperty();
    static Windows::UI::Xaml::DependencyProperty ToProperty();
    static Windows::UI::Xaml::DependencyProperty ByProperty();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO ColorAnimationUsingKeyFrames :
    Windows::UI::Xaml::Media::Animation::IColorAnimationUsingKeyFrames,
    impl::bases<ColorAnimationUsingKeyFrames, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<ColorAnimationUsingKeyFrames, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    ColorAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
    ColorAnimationUsingKeyFrames();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO ColorKeyFrame :
    Windows::UI::Xaml::Media::Animation::IColorKeyFrame,
    impl::bases<ColorKeyFrame, Windows::UI::Xaml::DependencyObject>,
    impl::require<ColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ColorKeyFrame(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ValueProperty();
    static Windows::UI::Xaml::DependencyProperty KeyTimeProperty();
};

struct WINRT_EBO ColorKeyFrameCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::ColorKeyFrame>
{
    ColorKeyFrameCollection(std::nullptr_t) noexcept {}
    ColorKeyFrameCollection();
};

struct WINRT_EBO CommonNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::ICommonNavigationTransitionInfo,
    impl::bases<CommonNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<CommonNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    CommonNavigationTransitionInfo(std::nullptr_t) noexcept {}
    CommonNavigationTransitionInfo();
    static Windows::UI::Xaml::DependencyProperty IsStaggeringEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsStaggerElementProperty();
    static bool GetIsStaggerElement(const Windows::UI::Xaml::UIElement & element);
    static void SetIsStaggerElement(const Windows::UI::Xaml::UIElement & element, bool value);
};

struct WINRT_EBO ConnectedAnimation :
    Windows::UI::Xaml::Media::Animation::IConnectedAnimation
{
    ConnectedAnimation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ConnectedAnimationService :
    Windows::UI::Xaml::Media::Animation::IConnectedAnimationService
{
    ConnectedAnimationService(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Animation::ConnectedAnimationService GetForCurrentView();
};

struct WINRT_EBO ContentThemeTransition :
    Windows::UI::Xaml::Media::Animation::IContentThemeTransition,
    impl::bases<ContentThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<ContentThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    ContentThemeTransition(std::nullptr_t) noexcept {}
    ContentThemeTransition();
    static Windows::UI::Xaml::DependencyProperty HorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalOffsetProperty();
};

struct WINRT_EBO ContinuumNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::IContinuumNavigationTransitionInfo,
    impl::bases<ContinuumNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<ContinuumNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    ContinuumNavigationTransitionInfo(std::nullptr_t) noexcept {}
    ContinuumNavigationTransitionInfo();
    static Windows::UI::Xaml::DependencyProperty ExitElementProperty();
    static Windows::UI::Xaml::DependencyProperty IsEntranceElementProperty();
    static bool GetIsEntranceElement(const Windows::UI::Xaml::UIElement & element);
    static void SetIsEntranceElement(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty IsExitElementProperty();
    static bool GetIsExitElement(const Windows::UI::Xaml::UIElement & element);
    static void SetIsExitElement(const Windows::UI::Xaml::UIElement & element, bool value);
    static Windows::UI::Xaml::DependencyProperty ExitElementContainerProperty();
    static bool GetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element);
    static void SetExitElementContainer(const Windows::UI::Xaml::Controls::ListViewBase & element, bool value);
};

struct WINRT_EBO CubicEase :
    Windows::UI::Xaml::Media::Animation::ICubicEase,
    impl::bases<CubicEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<CubicEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    CubicEase(std::nullptr_t) noexcept {}
    CubicEase();
};

struct WINRT_EBO DiscreteColorKeyFrame :
    Windows::UI::Xaml::Media::Animation::IDiscreteColorKeyFrame,
    impl::bases<DiscreteColorKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::ColorKeyFrame>,
    impl::require<DiscreteColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    DiscreteColorKeyFrame(std::nullptr_t) noexcept {}
    DiscreteColorKeyFrame();
};

struct WINRT_EBO DiscreteDoubleKeyFrame :
    Windows::UI::Xaml::Media::Animation::IDiscreteDoubleKeyFrame,
    impl::bases<DiscreteDoubleKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>,
    impl::require<DiscreteDoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    DiscreteDoubleKeyFrame(std::nullptr_t) noexcept {}
    DiscreteDoubleKeyFrame();
};

struct WINRT_EBO DiscreteObjectKeyFrame :
    Windows::UI::Xaml::Media::Animation::IDiscreteObjectKeyFrame,
    impl::bases<DiscreteObjectKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::ObjectKeyFrame>,
    impl::require<DiscreteObjectKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>
{
    DiscreteObjectKeyFrame(std::nullptr_t) noexcept {}
    DiscreteObjectKeyFrame();
};

struct WINRT_EBO DiscretePointKeyFrame :
    Windows::UI::Xaml::Media::Animation::IDiscretePointKeyFrame,
    impl::bases<DiscretePointKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::PointKeyFrame>,
    impl::require<DiscretePointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    DiscretePointKeyFrame(std::nullptr_t) noexcept {}
    DiscretePointKeyFrame();
};

struct WINRT_EBO DoubleAnimation :
    Windows::UI::Xaml::Media::Animation::IDoubleAnimation,
    impl::bases<DoubleAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DoubleAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DoubleAnimation(std::nullptr_t) noexcept {}
    DoubleAnimation();
    static Windows::UI::Xaml::DependencyProperty FromProperty();
    static Windows::UI::Xaml::DependencyProperty ToProperty();
    static Windows::UI::Xaml::DependencyProperty ByProperty();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO DoubleAnimationUsingKeyFrames :
    Windows::UI::Xaml::Media::Animation::IDoubleAnimationUsingKeyFrames,
    impl::bases<DoubleAnimationUsingKeyFrames, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DoubleAnimationUsingKeyFrames, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DoubleAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
    DoubleAnimationUsingKeyFrames();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO DoubleKeyFrame :
    Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame,
    impl::bases<DoubleKeyFrame, Windows::UI::Xaml::DependencyObject>,
    impl::require<DoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    DoubleKeyFrame(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ValueProperty();
    static Windows::UI::Xaml::DependencyProperty KeyTimeProperty();
};

struct WINRT_EBO DoubleKeyFrameCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>
{
    DoubleKeyFrameCollection(std::nullptr_t) noexcept {}
    DoubleKeyFrameCollection();
};

struct WINRT_EBO DragItemThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IDragItemThemeAnimation,
    impl::bases<DragItemThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DragItemThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DragItemThemeAnimation(std::nullptr_t) noexcept {}
    DragItemThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO DragOverThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IDragOverThemeAnimation,
    impl::bases<DragOverThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DragOverThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DragOverThemeAnimation(std::nullptr_t) noexcept {}
    DragOverThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ToOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty DirectionProperty();
};

struct WINRT_EBO DrillInNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::IDrillInNavigationTransitionInfo,
    impl::bases<DrillInNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<DrillInNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    DrillInNavigationTransitionInfo(std::nullptr_t) noexcept {}
    DrillInNavigationTransitionInfo();
};

struct WINRT_EBO DrillInThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IDrillInThemeAnimation,
    impl::bases<DrillInThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DrillInThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DrillInThemeAnimation(std::nullptr_t) noexcept {}
    DrillInThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty EntranceTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty EntranceTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ExitTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ExitTargetProperty();
};

struct WINRT_EBO DrillOutThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IDrillOutThemeAnimation,
    impl::bases<DrillOutThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DrillOutThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DrillOutThemeAnimation(std::nullptr_t) noexcept {}
    DrillOutThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty EntranceTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty EntranceTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ExitTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ExitTargetProperty();
};

struct WINRT_EBO DropTargetItemThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IDropTargetItemThemeAnimation,
    impl::bases<DropTargetItemThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<DropTargetItemThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    DropTargetItemThemeAnimation(std::nullptr_t) noexcept {}
    DropTargetItemThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO EasingColorKeyFrame :
    Windows::UI::Xaml::Media::Animation::IEasingColorKeyFrame,
    impl::bases<EasingColorKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::ColorKeyFrame>,
    impl::require<EasingColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    EasingColorKeyFrame(std::nullptr_t) noexcept {}
    EasingColorKeyFrame();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
};

struct WINRT_EBO EasingDoubleKeyFrame :
    Windows::UI::Xaml::Media::Animation::IEasingDoubleKeyFrame,
    impl::bases<EasingDoubleKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>,
    impl::require<EasingDoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    EasingDoubleKeyFrame(std::nullptr_t) noexcept {}
    EasingDoubleKeyFrame();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
};

struct WINRT_EBO EasingFunctionBase :
    Windows::UI::Xaml::Media::Animation::IEasingFunctionBase,
    impl::bases<EasingFunctionBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<EasingFunctionBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    EasingFunctionBase(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty EasingModeProperty();
};

struct WINRT_EBO EasingPointKeyFrame :
    Windows::UI::Xaml::Media::Animation::IEasingPointKeyFrame,
    impl::bases<EasingPointKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::PointKeyFrame>,
    impl::require<EasingPointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    EasingPointKeyFrame(std::nullptr_t) noexcept {}
    EasingPointKeyFrame();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
};

struct WINRT_EBO EdgeUIThemeTransition :
    Windows::UI::Xaml::Media::Animation::IEdgeUIThemeTransition,
    impl::bases<EdgeUIThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<EdgeUIThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    EdgeUIThemeTransition(std::nullptr_t) noexcept {}
    EdgeUIThemeTransition();
    static Windows::UI::Xaml::DependencyProperty EdgeProperty();
};

struct WINRT_EBO ElasticEase :
    Windows::UI::Xaml::Media::Animation::IElasticEase,
    impl::bases<ElasticEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<ElasticEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    ElasticEase(std::nullptr_t) noexcept {}
    ElasticEase();
    static Windows::UI::Xaml::DependencyProperty OscillationsProperty();
    static Windows::UI::Xaml::DependencyProperty SpringinessProperty();
};

struct WINRT_EBO EntranceNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::IEntranceNavigationTransitionInfo,
    impl::bases<EntranceNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<EntranceNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    EntranceNavigationTransitionInfo(std::nullptr_t) noexcept {}
    EntranceNavigationTransitionInfo();
    static Windows::UI::Xaml::DependencyProperty IsTargetElementProperty();
    static bool GetIsTargetElement(const Windows::UI::Xaml::UIElement & element);
    static void SetIsTargetElement(const Windows::UI::Xaml::UIElement & element, bool value);
};

struct WINRT_EBO EntranceThemeTransition :
    Windows::UI::Xaml::Media::Animation::IEntranceThemeTransition,
    impl::bases<EntranceThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<EntranceThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    EntranceThemeTransition(std::nullptr_t) noexcept {}
    EntranceThemeTransition();
    static Windows::UI::Xaml::DependencyProperty FromHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty FromVerticalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty IsStaggeringEnabledProperty();
};

struct WINRT_EBO ExponentialEase :
    Windows::UI::Xaml::Media::Animation::IExponentialEase,
    impl::bases<ExponentialEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<ExponentialEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    ExponentialEase(std::nullptr_t) noexcept {}
    ExponentialEase();
    static Windows::UI::Xaml::DependencyProperty ExponentProperty();
};

struct WINRT_EBO FadeInThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IFadeInThemeAnimation,
    impl::bases<FadeInThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<FadeInThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    FadeInThemeAnimation(std::nullptr_t) noexcept {}
    FadeInThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO FadeOutThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IFadeOutThemeAnimation,
    impl::bases<FadeOutThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<FadeOutThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    FadeOutThemeAnimation(std::nullptr_t) noexcept {}
    FadeOutThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO KeySpline :
    Windows::UI::Xaml::Media::Animation::IKeySpline,
    impl::bases<KeySpline, Windows::UI::Xaml::DependencyObject>,
    impl::require<KeySpline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    KeySpline(std::nullptr_t) noexcept {}
    KeySpline();
};

struct WINRT_EBO KeyTimeHelper :
    Windows::UI::Xaml::Media::Animation::IKeyTimeHelper
{
    KeyTimeHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Animation::KeyTime FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan);
};

struct WINRT_EBO LinearColorKeyFrame :
    Windows::UI::Xaml::Media::Animation::ILinearColorKeyFrame,
    impl::bases<LinearColorKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::ColorKeyFrame>,
    impl::require<LinearColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    LinearColorKeyFrame(std::nullptr_t) noexcept {}
    LinearColorKeyFrame();
};

struct WINRT_EBO LinearDoubleKeyFrame :
    Windows::UI::Xaml::Media::Animation::ILinearDoubleKeyFrame,
    impl::bases<LinearDoubleKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>,
    impl::require<LinearDoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    LinearDoubleKeyFrame(std::nullptr_t) noexcept {}
    LinearDoubleKeyFrame();
};

struct WINRT_EBO LinearPointKeyFrame :
    Windows::UI::Xaml::Media::Animation::ILinearPointKeyFrame,
    impl::bases<LinearPointKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::PointKeyFrame>,
    impl::require<LinearPointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    LinearPointKeyFrame(std::nullptr_t) noexcept {}
    LinearPointKeyFrame();
};

struct WINRT_EBO NavigationThemeTransition :
    Windows::UI::Xaml::Media::Animation::INavigationThemeTransition,
    impl::bases<NavigationThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<NavigationThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    NavigationThemeTransition(std::nullptr_t) noexcept {}
    NavigationThemeTransition();
    static Windows::UI::Xaml::DependencyProperty DefaultNavigationTransitionInfoProperty();
};

struct WINRT_EBO NavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo,
    impl::bases<NavigationTransitionInfo, Windows::UI::Xaml::DependencyObject>,
    impl::require<NavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    NavigationTransitionInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ObjectAnimationUsingKeyFrames :
    Windows::UI::Xaml::Media::Animation::IObjectAnimationUsingKeyFrames,
    impl::bases<ObjectAnimationUsingKeyFrames, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<ObjectAnimationUsingKeyFrames, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    ObjectAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
    ObjectAnimationUsingKeyFrames();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO ObjectKeyFrame :
    Windows::UI::Xaml::Media::Animation::IObjectKeyFrame,
    impl::bases<ObjectKeyFrame, Windows::UI::Xaml::DependencyObject>,
    impl::require<ObjectKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    ObjectKeyFrame(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ValueProperty();
    static Windows::UI::Xaml::DependencyProperty KeyTimeProperty();
};

struct WINRT_EBO ObjectKeyFrameCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::ObjectKeyFrame>
{
    ObjectKeyFrameCollection(std::nullptr_t) noexcept {}
    ObjectKeyFrameCollection();
};

struct WINRT_EBO PaneThemeTransition :
    Windows::UI::Xaml::Media::Animation::IPaneThemeTransition,
    impl::bases<PaneThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<PaneThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    PaneThemeTransition(std::nullptr_t) noexcept {}
    PaneThemeTransition();
    static Windows::UI::Xaml::DependencyProperty EdgeProperty();
};

struct WINRT_EBO PointAnimation :
    Windows::UI::Xaml::Media::Animation::IPointAnimation,
    impl::bases<PointAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PointAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PointAnimation(std::nullptr_t) noexcept {}
    PointAnimation();
    static Windows::UI::Xaml::DependencyProperty FromProperty();
    static Windows::UI::Xaml::DependencyProperty ToProperty();
    static Windows::UI::Xaml::DependencyProperty ByProperty();
    static Windows::UI::Xaml::DependencyProperty EasingFunctionProperty();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO PointAnimationUsingKeyFrames :
    Windows::UI::Xaml::Media::Animation::IPointAnimationUsingKeyFrames,
    impl::bases<PointAnimationUsingKeyFrames, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PointAnimationUsingKeyFrames, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PointAnimationUsingKeyFrames(std::nullptr_t) noexcept {}
    PointAnimationUsingKeyFrames();
    static Windows::UI::Xaml::DependencyProperty EnableDependentAnimationProperty();
};

struct WINRT_EBO PointKeyFrame :
    Windows::UI::Xaml::Media::Animation::IPointKeyFrame,
    impl::bases<PointKeyFrame, Windows::UI::Xaml::DependencyObject>,
    impl::require<PointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PointKeyFrame(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty ValueProperty();
    static Windows::UI::Xaml::DependencyProperty KeyTimeProperty();
};

struct WINRT_EBO PointKeyFrameCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::PointKeyFrame>
{
    PointKeyFrameCollection(std::nullptr_t) noexcept {}
    PointKeyFrameCollection();
};

struct WINRT_EBO PointerDownThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IPointerDownThemeAnimation,
    impl::bases<PointerDownThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PointerDownThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PointerDownThemeAnimation(std::nullptr_t) noexcept {}
    PointerDownThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO PointerUpThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IPointerUpThemeAnimation,
    impl::bases<PointerUpThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PointerUpThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PointerUpThemeAnimation(std::nullptr_t) noexcept {}
    PointerUpThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO PopInThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IPopInThemeAnimation,
    impl::bases<PopInThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PopInThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PopInThemeAnimation(std::nullptr_t) noexcept {}
    PopInThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty FromHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty FromVerticalOffsetProperty();
};

struct WINRT_EBO PopOutThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IPopOutThemeAnimation,
    impl::bases<PopOutThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<PopOutThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    PopOutThemeAnimation(std::nullptr_t) noexcept {}
    PopOutThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
};

struct WINRT_EBO PopupThemeTransition :
    Windows::UI::Xaml::Media::Animation::IPopupThemeTransition,
    impl::bases<PopupThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<PopupThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    PopupThemeTransition(std::nullptr_t) noexcept {}
    PopupThemeTransition();
    static Windows::UI::Xaml::DependencyProperty FromHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty FromVerticalOffsetProperty();
};

struct WINRT_EBO PowerEase :
    Windows::UI::Xaml::Media::Animation::IPowerEase,
    impl::bases<PowerEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<PowerEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    PowerEase(std::nullptr_t) noexcept {}
    PowerEase();
    static Windows::UI::Xaml::DependencyProperty PowerProperty();
};

struct WINRT_EBO QuadraticEase :
    Windows::UI::Xaml::Media::Animation::IQuadraticEase,
    impl::bases<QuadraticEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<QuadraticEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    QuadraticEase(std::nullptr_t) noexcept {}
    QuadraticEase();
};

struct WINRT_EBO QuarticEase :
    Windows::UI::Xaml::Media::Animation::IQuarticEase,
    impl::bases<QuarticEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<QuarticEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    QuarticEase(std::nullptr_t) noexcept {}
    QuarticEase();
};

struct WINRT_EBO QuinticEase :
    Windows::UI::Xaml::Media::Animation::IQuinticEase,
    impl::bases<QuinticEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<QuinticEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    QuinticEase(std::nullptr_t) noexcept {}
    QuinticEase();
};

struct WINRT_EBO ReorderThemeTransition :
    Windows::UI::Xaml::Media::Animation::IReorderThemeTransition,
    impl::bases<ReorderThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<ReorderThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition>
{
    ReorderThemeTransition(std::nullptr_t) noexcept {}
    ReorderThemeTransition();
};

struct WINRT_EBO RepeatBehaviorHelper :
    Windows::UI::Xaml::Media::Animation::IRepeatBehaviorHelper
{
    RepeatBehaviorHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Animation::RepeatBehavior Forever();
    static Windows::UI::Xaml::Media::Animation::RepeatBehavior FromCount(double count);
    static Windows::UI::Xaml::Media::Animation::RepeatBehavior FromDuration(const Windows::Foundation::TimeSpan & duration);
    static bool GetHasCount(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target);
    static bool GetHasDuration(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target);
    static bool Equals(const Windows::UI::Xaml::Media::Animation::RepeatBehavior & target, const Windows::UI::Xaml::Media::Animation::RepeatBehavior & value);
};

struct WINRT_EBO RepositionThemeAnimation :
    Windows::UI::Xaml::Media::Animation::IRepositionThemeAnimation,
    impl::bases<RepositionThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<RepositionThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    RepositionThemeAnimation(std::nullptr_t) noexcept {}
    RepositionThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty FromHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty FromVerticalOffsetProperty();
};

struct WINRT_EBO RepositionThemeTransition :
    Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition,
    impl::bases<RepositionThemeTransition, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Transition>,
    impl::require<RepositionThemeTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITransition, Windows::UI::Xaml::Media::Animation::IRepositionThemeTransition2>
{
    RepositionThemeTransition(std::nullptr_t) noexcept {}
    RepositionThemeTransition();
    static Windows::UI::Xaml::DependencyProperty IsStaggeringEnabledProperty();
};

struct WINRT_EBO SineEase :
    Windows::UI::Xaml::Media::Animation::ISineEase,
    impl::bases<SineEase, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::EasingFunctionBase>,
    impl::require<SineEase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IEasingFunctionBase>
{
    SineEase(std::nullptr_t) noexcept {}
    SineEase();
};

struct WINRT_EBO SlideNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::ISlideNavigationTransitionInfo,
    impl::bases<SlideNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<SlideNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    SlideNavigationTransitionInfo(std::nullptr_t) noexcept {}
    SlideNavigationTransitionInfo();
};

struct WINRT_EBO SplineColorKeyFrame :
    Windows::UI::Xaml::Media::Animation::ISplineColorKeyFrame,
    impl::bases<SplineColorKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::ColorKeyFrame>,
    impl::require<SplineColorKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    SplineColorKeyFrame(std::nullptr_t) noexcept {}
    SplineColorKeyFrame();
    static Windows::UI::Xaml::DependencyProperty KeySplineProperty();
};

struct WINRT_EBO SplineDoubleKeyFrame :
    Windows::UI::Xaml::Media::Animation::ISplineDoubleKeyFrame,
    impl::bases<SplineDoubleKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::DoubleKeyFrame>,
    impl::require<SplineDoubleKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    SplineDoubleKeyFrame(std::nullptr_t) noexcept {}
    SplineDoubleKeyFrame();
    static Windows::UI::Xaml::DependencyProperty KeySplineProperty();
};

struct WINRT_EBO SplinePointKeyFrame :
    Windows::UI::Xaml::Media::Animation::ISplinePointKeyFrame,
    impl::bases<SplinePointKeyFrame, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::PointKeyFrame>,
    impl::require<SplinePointKeyFrame, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    SplinePointKeyFrame(std::nullptr_t) noexcept {}
    SplinePointKeyFrame();
    static Windows::UI::Xaml::DependencyProperty KeySplineProperty();
};

struct WINRT_EBO SplitCloseThemeAnimation :
    Windows::UI::Xaml::Media::Animation::ISplitCloseThemeAnimation,
    impl::bases<SplitCloseThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<SplitCloseThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    SplitCloseThemeAnimation(std::nullptr_t) noexcept {}
    SplitCloseThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty OpenedTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty OpenedTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTargetProperty();
    static Windows::UI::Xaml::DependencyProperty OpenedLengthProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedLengthProperty();
    static Windows::UI::Xaml::DependencyProperty OffsetFromCenterProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTranslationDirectionProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTranslationOffsetProperty();
};

struct WINRT_EBO SplitOpenThemeAnimation :
    Windows::UI::Xaml::Media::Animation::ISplitOpenThemeAnimation,
    impl::bases<SplitOpenThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<SplitOpenThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    SplitOpenThemeAnimation(std::nullptr_t) noexcept {}
    SplitOpenThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty OpenedTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty OpenedTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedTargetProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTargetProperty();
    static Windows::UI::Xaml::DependencyProperty OpenedLengthProperty();
    static Windows::UI::Xaml::DependencyProperty ClosedLengthProperty();
    static Windows::UI::Xaml::DependencyProperty OffsetFromCenterProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTranslationDirectionProperty();
    static Windows::UI::Xaml::DependencyProperty ContentTranslationOffsetProperty();
};

struct WINRT_EBO Storyboard :
    Windows::UI::Xaml::Media::Animation::IStoryboard,
    impl::bases<Storyboard, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<Storyboard, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    Storyboard(std::nullptr_t) noexcept {}
    Storyboard();
    static Windows::UI::Xaml::DependencyProperty TargetPropertyProperty();
    static hstring GetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element);
    static void SetTargetProperty(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view path);
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static hstring GetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element);
    static void SetTargetName(const Windows::UI::Xaml::Media::Animation::Timeline & element, hstring_view name);
    static void SetTarget(const Windows::UI::Xaml::Media::Animation::Timeline & timeline, const Windows::UI::Xaml::DependencyObject & target);
};

struct WINRT_EBO SuppressNavigationTransitionInfo :
    Windows::UI::Xaml::Media::Animation::ISuppressNavigationTransitionInfo,
    impl::bases<SuppressNavigationTransitionInfo, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo>,
    impl::require<SuppressNavigationTransitionInfo, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
{
    SuppressNavigationTransitionInfo(std::nullptr_t) noexcept {}
    SuppressNavigationTransitionInfo();
};

struct WINRT_EBO SwipeBackThemeAnimation :
    Windows::UI::Xaml::Media::Animation::ISwipeBackThemeAnimation,
    impl::bases<SwipeBackThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<SwipeBackThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    SwipeBackThemeAnimation(std::nullptr_t) noexcept {}
    SwipeBackThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty FromHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty FromVerticalOffsetProperty();
};

struct WINRT_EBO SwipeHintThemeAnimation :
    Windows::UI::Xaml::Media::Animation::ISwipeHintThemeAnimation,
    impl::bases<SwipeHintThemeAnimation, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Animation::Timeline>,
    impl::require<SwipeHintThemeAnimation, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    SwipeHintThemeAnimation(std::nullptr_t) noexcept {}
    SwipeHintThemeAnimation();
    static Windows::UI::Xaml::DependencyProperty TargetNameProperty();
    static Windows::UI::Xaml::DependencyProperty ToHorizontalOffsetProperty();
    static Windows::UI::Xaml::DependencyProperty ToVerticalOffsetProperty();
};

struct WINRT_EBO Timeline :
    Windows::UI::Xaml::Media::Animation::ITimeline,
    impl::bases<Timeline, Windows::UI::Xaml::DependencyObject>,
    impl::require<Timeline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Timeline(std::nullptr_t) noexcept {}
    static bool AllowDependentAnimations();
    static void AllowDependentAnimations(bool value);
    static Windows::UI::Xaml::DependencyProperty AutoReverseProperty();
    static Windows::UI::Xaml::DependencyProperty BeginTimeProperty();
    static Windows::UI::Xaml::DependencyProperty DurationProperty();
    static Windows::UI::Xaml::DependencyProperty SpeedRatioProperty();
    static Windows::UI::Xaml::DependencyProperty FillBehaviorProperty();
    static Windows::UI::Xaml::DependencyProperty RepeatBehaviorProperty();
};

struct WINRT_EBO TimelineCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Timeline>
{
    TimelineCollection(std::nullptr_t) noexcept {}
    TimelineCollection();
};

struct WINRT_EBO Transition :
    Windows::UI::Xaml::Media::Animation::ITransition,
    impl::bases<Transition, Windows::UI::Xaml::DependencyObject>,
    impl::require<Transition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Transition(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TransitionCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition>
{
    TransitionCollection(std::nullptr_t) noexcept {}
    TransitionCollection();
};

}

}
