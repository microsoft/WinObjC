// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Services.Maps.Guidance.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Services::Maps::Guidance {

struct WINRT_EBO GuidanceAudioNotificationRequestedEventArgs :
    Windows::Services::Maps::Guidance::IGuidanceAudioNotificationRequestedEventArgs
{
    GuidanceAudioNotificationRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceLaneInfo :
    Windows::Services::Maps::Guidance::IGuidanceLaneInfo
{
    GuidanceLaneInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceManeuver :
    Windows::Services::Maps::Guidance::IGuidanceManeuver
{
    GuidanceManeuver(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceMapMatchedCoordinate :
    Windows::Services::Maps::Guidance::IGuidanceMapMatchedCoordinate
{
    GuidanceMapMatchedCoordinate(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceNavigator :
    Windows::Services::Maps::Guidance::IGuidanceNavigator,
    impl::require<GuidanceNavigator, Windows::Services::Maps::Guidance::IGuidanceNavigator2>
{
    GuidanceNavigator(std::nullptr_t) noexcept {}
    static Windows::Services::Maps::Guidance::GuidanceNavigator GetCurrent();
    static bool UseAppProvidedVoice();
};

struct WINRT_EBO GuidanceReroutedEventArgs :
    Windows::Services::Maps::Guidance::IGuidanceReroutedEventArgs
{
    GuidanceReroutedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceRoadSegment :
    Windows::Services::Maps::Guidance::IGuidanceRoadSegment
{
    GuidanceRoadSegment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceRoadSignpost :
    Windows::Services::Maps::Guidance::IGuidanceRoadSignpost
{
    GuidanceRoadSignpost(std::nullptr_t) noexcept {}
};

struct WINRT_EBO GuidanceRoute :
    Windows::Services::Maps::Guidance::IGuidanceRoute
{
    GuidanceRoute(std::nullptr_t) noexcept {}
    static bool CanCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute);
    static Windows::Services::Maps::Guidance::GuidanceRoute TryCreateFromMapRoute(const Windows::Services::Maps::MapRoute & mapRoute);
};

struct WINRT_EBO GuidanceTelemetryCollector :
    Windows::Services::Maps::Guidance::IGuidanceTelemetryCollector
{
    GuidanceTelemetryCollector(std::nullptr_t) noexcept {}
    static Windows::Services::Maps::Guidance::GuidanceTelemetryCollector GetCurrent();
};

struct WINRT_EBO GuidanceUpdatedEventArgs :
    Windows::Services::Maps::Guidance::IGuidanceUpdatedEventArgs
{
    GuidanceUpdatedEventArgs(std::nullptr_t) noexcept {}
};

}

}
