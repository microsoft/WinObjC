// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.Collation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::Collation {

struct WINRT_EBO CharacterGrouping :
    Windows::Globalization::Collation::ICharacterGrouping
{
    CharacterGrouping(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CharacterGroupings :
    Windows::Globalization::Collation::ICharacterGroupings
{
    CharacterGroupings(std::nullptr_t) noexcept {}
    CharacterGroupings();
};

}

}
