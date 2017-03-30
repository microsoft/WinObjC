// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Automation.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Provider {

struct WINRT_EBO IRawElementProviderSimple :
    Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple,
    impl::bases<IRawElementProviderSimple, Windows::UI::Xaml::DependencyObject>,
    impl::require<IRawElementProviderSimple, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    IRawElementProviderSimple(std::nullptr_t) noexcept {}
};

}

}
