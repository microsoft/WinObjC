// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Core::AnimationMetrics {

struct IAnimationDescription;
struct IAnimationDescriptionFactory;
struct IOpacityAnimation;
struct IPropertyAnimation;
struct IScaleAnimation;
struct AnimationDescription;
struct OpacityAnimation;
struct PropertyAnimation;
struct ScaleAnimation;
struct TranslationAnimation;

}

namespace Windows::UI::Core::AnimationMetrics {

struct IAnimationDescription;
struct IAnimationDescriptionFactory;
struct IOpacityAnimation;
struct IPropertyAnimation;
struct IScaleAnimation;
struct AnimationDescription;
struct OpacityAnimation;
struct PropertyAnimation;
struct ScaleAnimation;
struct TranslationAnimation;

}

namespace Windows::UI::Core::AnimationMetrics {

template <typename T> struct impl_IAnimationDescription;
template <typename T> struct impl_IAnimationDescriptionFactory;
template <typename T> struct impl_IOpacityAnimation;
template <typename T> struct impl_IPropertyAnimation;
template <typename T> struct impl_IScaleAnimation;

}

namespace Windows::UI::Core::AnimationMetrics {

enum class AnimationEffect
{
    Expand = 0,
    Collapse = 1,
    Reposition = 2,
    FadeIn = 3,
    FadeOut = 4,
    AddToList = 5,
    DeleteFromList = 6,
    AddToGrid = 7,
    DeleteFromGrid = 8,
    AddToSearchGrid = 9,
    DeleteFromSearchGrid = 10,
    AddToSearchList = 11,
    DeleteFromSearchList = 12,
    ShowEdgeUI = 13,
    ShowPanel = 14,
    HideEdgeUI = 15,
    HidePanel = 16,
    ShowPopup = 17,
    HidePopup = 18,
    PointerDown = 19,
    PointerUp = 20,
    DragSourceStart = 21,
    DragSourceEnd = 22,
    TransitionContent = 23,
    Reveal = 24,
    Hide = 25,
    DragBetweenEnter = 26,
    DragBetweenLeave = 27,
    SwipeSelect = 28,
    SwipeDeselect = 29,
    SwipeReveal = 30,
    EnterPage = 31,
    TransitionPage = 32,
    CrossFade = 33,
    Peek = 34,
    UpdateBadge = 35,
};

enum class AnimationEffectTarget
{
    Primary = 0,
    Added = 1,
    Affected = 2,
    Background = 3,
    Content = 4,
    Deleted = 5,
    Deselected = 6,
    DragSource = 7,
    Hidden = 8,
    Incoming = 9,
    Outgoing = 10,
    Outline = 11,
    Remaining = 12,
    Revealed = 13,
    RowIn = 14,
    RowOut = 15,
    Selected = 16,
    Selection = 17,
    Shown = 18,
    Tapped = 19,
};

enum class PropertyAnimationType
{
    Scale = 0,
    Translation = 1,
    Opacity = 2,
};

}

}
