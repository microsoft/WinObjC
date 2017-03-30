// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Phone::System::UserProfile::GameServices::Core {

struct IGameService;
struct IGameService2;
struct IGameServicePropertyCollection;
struct GameServicePropertyCollection;

}

namespace Windows::Phone::System::UserProfile::GameServices::Core {

struct IGameService;
struct IGameService2;
struct IGameServicePropertyCollection;
struct GameService;
struct GameServicePropertyCollection;

}

namespace Windows::Phone::System::UserProfile::GameServices::Core {

template <typename T> struct impl_IGameService;
template <typename T> struct impl_IGameService2;
template <typename T> struct impl_IGameServicePropertyCollection;

}

namespace Windows::Phone::System::UserProfile::GameServices::Core {

enum class GameServiceGameOutcome
{
    None = 0,
    Win = 1,
    Loss = 2,
    Tie = 3,
};

enum class GameServiceScoreKind
{
    Number = 0,
    Time = 1,
};

}

}
