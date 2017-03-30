// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Globalization.Fonts.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Globalization::Fonts {

struct ILanguageFont :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageFont>
{
    ILanguageFont(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageFontGroup :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageFontGroup>
{
    ILanguageFontGroup(std::nullptr_t = nullptr) noexcept {}
};

struct ILanguageFontGroupFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILanguageFontGroupFactory>
{
    ILanguageFontGroupFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
