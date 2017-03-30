// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Services::Maps::Guidance {

struct IGuidanceAudioNotificationRequestedEventArgs;
struct IGuidanceLaneInfo;
struct IGuidanceManeuver;
struct IGuidanceMapMatchedCoordinate;
struct IGuidanceNavigator;
struct IGuidanceNavigator2;
struct IGuidanceNavigatorStatics;
struct IGuidanceNavigatorStatics2;
struct IGuidanceReroutedEventArgs;
struct IGuidanceRoadSegment;
struct IGuidanceRoadSignpost;
struct IGuidanceRoute;
struct IGuidanceRouteStatics;
struct IGuidanceTelemetryCollector;
struct IGuidanceTelemetryCollectorStatics;
struct IGuidanceUpdatedEventArgs;
struct GuidanceAudioNotificationRequestedEventArgs;
struct GuidanceLaneInfo;
struct GuidanceManeuver;
struct GuidanceMapMatchedCoordinate;
struct GuidanceNavigator;
struct GuidanceReroutedEventArgs;
struct GuidanceRoadSegment;
struct GuidanceRoadSignpost;
struct GuidanceRoute;
struct GuidanceTelemetryCollector;
struct GuidanceUpdatedEventArgs;

}

namespace Windows::Services::Maps::Guidance {

struct IGuidanceAudioNotificationRequestedEventArgs;
struct IGuidanceLaneInfo;
struct IGuidanceManeuver;
struct IGuidanceMapMatchedCoordinate;
struct IGuidanceNavigator;
struct IGuidanceNavigator2;
struct IGuidanceNavigatorStatics;
struct IGuidanceNavigatorStatics2;
struct IGuidanceReroutedEventArgs;
struct IGuidanceRoadSegment;
struct IGuidanceRoadSignpost;
struct IGuidanceRoute;
struct IGuidanceRouteStatics;
struct IGuidanceTelemetryCollector;
struct IGuidanceTelemetryCollectorStatics;
struct IGuidanceUpdatedEventArgs;
struct GuidanceAudioNotificationRequestedEventArgs;
struct GuidanceLaneInfo;
struct GuidanceManeuver;
struct GuidanceMapMatchedCoordinate;
struct GuidanceNavigator;
struct GuidanceReroutedEventArgs;
struct GuidanceRoadSegment;
struct GuidanceRoadSignpost;
struct GuidanceRoute;
struct GuidanceTelemetryCollector;
struct GuidanceUpdatedEventArgs;

}

namespace Windows::Services::Maps::Guidance {

template <typename T> struct impl_IGuidanceAudioNotificationRequestedEventArgs;
template <typename T> struct impl_IGuidanceLaneInfo;
template <typename T> struct impl_IGuidanceManeuver;
template <typename T> struct impl_IGuidanceMapMatchedCoordinate;
template <typename T> struct impl_IGuidanceNavigator;
template <typename T> struct impl_IGuidanceNavigator2;
template <typename T> struct impl_IGuidanceNavigatorStatics;
template <typename T> struct impl_IGuidanceNavigatorStatics2;
template <typename T> struct impl_IGuidanceReroutedEventArgs;
template <typename T> struct impl_IGuidanceRoadSegment;
template <typename T> struct impl_IGuidanceRoadSignpost;
template <typename T> struct impl_IGuidanceRoute;
template <typename T> struct impl_IGuidanceRouteStatics;
template <typename T> struct impl_IGuidanceTelemetryCollector;
template <typename T> struct impl_IGuidanceTelemetryCollectorStatics;
template <typename T> struct impl_IGuidanceUpdatedEventArgs;

}

namespace Windows::Services::Maps::Guidance {

enum class GuidanceAudioMeasurementSystem
{
    Meters = 0,
    MilesAndYards = 1,
    MilesAndFeet = 2,
};

enum class GuidanceAudioNotificationKind
{
    Maneuver = 0,
    Route = 1,
    Gps = 2,
    SpeedLimit = 3,
    Traffic = 4,
    TrafficCamera = 5,
};

enum class GuidanceAudioNotifications : unsigned
{
    None = 0x0,
    Maneuver = 0x1,
    Route = 0x2,
    Gps = 0x4,
    SpeedLimit = 0x8,
    Traffic = 0x10,
    TrafficCamera = 0x20,
};

DEFINE_ENUM_FLAG_OPERATORS(GuidanceAudioNotifications)

enum class GuidanceLaneMarkers : unsigned
{
    None = 0x0,
    LightRight = 0x1,
    Right = 0x2,
    HardRight = 0x4,
    Straight = 0x8,
    UTurnLeft = 0x10,
    HardLeft = 0x20,
    Left = 0x40,
    LightLeft = 0x80,
    UTurnRight = 0x100,
    Unknown = 0xFFFFFFFF,
};

DEFINE_ENUM_FLAG_OPERATORS(GuidanceLaneMarkers)

enum class GuidanceManeuverKind
{
    None = 0,
    GoStraight = 1,
    UTurnRight = 2,
    UTurnLeft = 3,
    TurnKeepRight = 4,
    TurnLightRight = 5,
    TurnRight = 6,
    TurnHardRight = 7,
    KeepMiddle = 8,
    TurnKeepLeft = 9,
    TurnLightLeft = 10,
    TurnLeft = 11,
    TurnHardLeft = 12,
    FreewayEnterRight = 13,
    FreewayEnterLeft = 14,
    FreewayLeaveRight = 15,
    FreewayLeaveLeft = 16,
    FreewayKeepRight = 17,
    FreewayKeepLeft = 18,
    TrafficCircleRight1 = 19,
    TrafficCircleRight2 = 20,
    TrafficCircleRight3 = 21,
    TrafficCircleRight4 = 22,
    TrafficCircleRight5 = 23,
    TrafficCircleRight6 = 24,
    TrafficCircleRight7 = 25,
    TrafficCircleRight8 = 26,
    TrafficCircleRight9 = 27,
    TrafficCircleRight10 = 28,
    TrafficCircleRight11 = 29,
    TrafficCircleRight12 = 30,
    TrafficCircleLeft1 = 31,
    TrafficCircleLeft2 = 32,
    TrafficCircleLeft3 = 33,
    TrafficCircleLeft4 = 34,
    TrafficCircleLeft5 = 35,
    TrafficCircleLeft6 = 36,
    TrafficCircleLeft7 = 37,
    TrafficCircleLeft8 = 38,
    TrafficCircleLeft9 = 39,
    TrafficCircleLeft10 = 40,
    TrafficCircleLeft11 = 41,
    TrafficCircleLeft12 = 42,
    Start = 43,
    End = 44,
    TakeFerry = 45,
    PassTransitStation = 46,
    LeaveTransitStation = 47,
};

enum class GuidanceMode
{
    None = 0,
    Simulation = 1,
    Navigation = 2,
    Tracking = 3,
};

}

}
