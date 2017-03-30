// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Animation {

template <typename D, typename ... Interfaces> struct ColorKeyFrameT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IColorKeyFrame>
{
    using composable = ColorKeyFrame;

protected:

    ColorKeyFrameT()
    {
        get_activation_factory<ColorKeyFrame, IColorKeyFrameFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DoubleKeyFrameT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IDoubleKeyFrame>
{
    using composable = DoubleKeyFrame;

protected:

    DoubleKeyFrameT()
    {
        get_activation_factory<DoubleKeyFrame, IDoubleKeyFrameFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct NavigationTransitionInfoT :
    overrides<D, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo>
{
    using composable = NavigationTransitionInfo;

protected:

    NavigationTransitionInfoT()
    {
        get_activation_factory<NavigationTransitionInfo, INavigationTransitionInfoFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ObjectKeyFrameT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IObjectKeyFrame>
{
    using composable = ObjectKeyFrame;

protected:

    ObjectKeyFrameT()
    {
        get_activation_factory<ObjectKeyFrame, IObjectKeyFrameFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PointKeyFrameT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::IPointKeyFrame>
{
    using composable = PointKeyFrame;

protected:

    PointKeyFrameT()
    {
        get_activation_factory<PointKeyFrame, IPointKeyFrameFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct TimelineT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Animation::ITimeline>
{
    using composable = Timeline;

protected:

    TimelineT()
    {
        get_activation_factory<Timeline, ITimelineFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
