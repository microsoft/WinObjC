// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Contacts.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Contacts::Provider {

struct WINRT_EBO ContactPickerUI :
    Windows::ApplicationModel::Contacts::Provider::IContactPickerUI,
    impl::require<ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2>
{
    ContactPickerUI(std::nullptr_t) noexcept {}
    using impl_IContactPickerUI::AddContact;
    using impl_IContactPickerUI2::AddContact;
};

struct WINRT_EBO ContactRemovedEventArgs :
    Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs
{
    ContactRemovedEventArgs(std::nullptr_t) noexcept {}
};

}

}
