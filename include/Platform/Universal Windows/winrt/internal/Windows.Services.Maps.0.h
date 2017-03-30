// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Services::Maps {

struct IMapAddress;
struct IMapAddress2;
struct IMapLocation;
struct IMapLocationFinderResult;
struct IMapLocationFinderStatics;
struct IMapLocationFinderStatics2;
struct IMapManagerStatics;
struct IMapRoute;
struct IMapRoute2;
struct IMapRouteDrivingOptions;
struct IMapRouteFinderResult;
struct IMapRouteFinderResult2;
struct IMapRouteFinderStatics;
struct IMapRouteFinderStatics2;
struct IMapRouteLeg;
struct IMapRouteManeuver;
struct IMapRouteManeuver2;
struct IMapServiceStatics;
struct IMapServiceStatics2;
struct IMapServiceStatics3;
struct MapAddress;
struct MapLocation;
struct MapLocationFinderResult;
struct MapRoute;
struct MapRouteDrivingOptions;
struct MapRouteFinderResult;
struct MapRouteLeg;
struct MapRouteManeuver;

}

namespace Windows::Services::Maps {

struct IMapAddress;
struct IMapAddress2;
struct IMapLocation;
struct IMapLocationFinderResult;
struct IMapLocationFinderStatics;
struct IMapLocationFinderStatics2;
struct IMapManagerStatics;
struct IMapRoute;
struct IMapRoute2;
struct IMapRouteDrivingOptions;
struct IMapRouteFinderResult;
struct IMapRouteFinderResult2;
struct IMapRouteFinderStatics;
struct IMapRouteFinderStatics2;
struct IMapRouteLeg;
struct IMapRouteManeuver;
struct IMapRouteManeuver2;
struct IMapServiceStatics;
struct IMapServiceStatics2;
struct IMapServiceStatics3;
struct MapAddress;
struct MapLocation;
struct MapLocationFinder;
struct MapLocationFinderResult;
struct MapManager;
struct MapRoute;
struct MapRouteDrivingOptions;
struct MapRouteFinder;
struct MapRouteFinderResult;
struct MapRouteLeg;
struct MapRouteManeuver;
struct MapService;

}

namespace Windows::Services::Maps {

template <typename T> struct impl_IMapAddress;
template <typename T> struct impl_IMapAddress2;
template <typename T> struct impl_IMapLocation;
template <typename T> struct impl_IMapLocationFinderResult;
template <typename T> struct impl_IMapLocationFinderStatics;
template <typename T> struct impl_IMapLocationFinderStatics2;
template <typename T> struct impl_IMapManagerStatics;
template <typename T> struct impl_IMapRoute;
template <typename T> struct impl_IMapRoute2;
template <typename T> struct impl_IMapRouteDrivingOptions;
template <typename T> struct impl_IMapRouteFinderResult;
template <typename T> struct impl_IMapRouteFinderResult2;
template <typename T> struct impl_IMapRouteFinderStatics;
template <typename T> struct impl_IMapRouteFinderStatics2;
template <typename T> struct impl_IMapRouteLeg;
template <typename T> struct impl_IMapRouteManeuver;
template <typename T> struct impl_IMapRouteManeuver2;
template <typename T> struct impl_IMapServiceStatics;
template <typename T> struct impl_IMapServiceStatics2;
template <typename T> struct impl_IMapServiceStatics3;

}

namespace Windows::Services::Maps {

enum class MapLocationDesiredAccuracy
{
    High = 0,
    Low = 1,
};

enum class MapLocationFinderStatus
{
    Success = 0,
    UnknownError = 1,
    InvalidCredentials = 2,
    BadLocation = 3,
    IndexFailure = 4,
    NetworkFailure = 5,
    NotSupported = 6,
};

enum class MapManeuverNotices : unsigned
{
    None = 0x0,
    Toll = 0x1,
    Unpaved = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(MapManeuverNotices)

enum class MapRouteFinderStatus
{
    Success = 0,
    UnknownError = 1,
    InvalidCredentials = 2,
    NoRouteFound = 3,
    NoRouteFoundWithGivenOptions = 4,
    StartPointNotFound = 5,
    EndPointNotFound = 6,
    NoPedestrianRouteFound = 7,
    NetworkFailure = 8,
    NotSupported = 9,
};

enum class MapRouteManeuverKind
{
    None = 0,
    Start = 1,
    Stopover = 2,
    StopoverResume = 3,
    End = 4,
    GoStraight = 5,
    UTurnLeft = 6,
    UTurnRight = 7,
    TurnKeepLeft = 8,
    TurnKeepRight = 9,
    TurnLightLeft = 10,
    TurnLightRight = 11,
    TurnLeft = 12,
    TurnRight = 13,
    TurnHardLeft = 14,
    TurnHardRight = 15,
    FreewayEnterLeft = 16,
    FreewayEnterRight = 17,
    FreewayLeaveLeft = 18,
    FreewayLeaveRight = 19,
    FreewayContinueLeft = 20,
    FreewayContinueRight = 21,
    TrafficCircleLeft = 22,
    TrafficCircleRight = 23,
    TakeFerry = 24,
};

enum class MapRouteOptimization
{
    Time = 0,
    Distance = 1,
    TimeWithTraffic = 2,
};

enum class MapRouteRestrictions : unsigned
{
    None = 0x0,
    Highways = 0x1,
    TollRoads = 0x2,
    Ferries = 0x4,
    Tunnels = 0x8,
    DirtRoads = 0x10,
    Motorail = 0x20,
};

DEFINE_ENUM_FLAG_OPERATORS(MapRouteRestrictions)

}

}
