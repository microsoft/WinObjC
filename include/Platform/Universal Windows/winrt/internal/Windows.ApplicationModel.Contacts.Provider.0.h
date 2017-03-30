// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Contacts::Provider {

struct IContactPickerUI;
struct IContactPickerUI2;
struct IContactRemovedEventArgs;
struct ContactPickerUI;
struct ContactRemovedEventArgs;

}

namespace Windows::ApplicationModel::Contacts::Provider {

struct IContactPickerUI;
struct IContactPickerUI2;
struct IContactRemovedEventArgs;
struct ContactPickerUI;
struct ContactRemovedEventArgs;

}

namespace Windows::ApplicationModel::Contacts::Provider {

template <typename T> struct impl_IContactPickerUI;
template <typename T> struct impl_IContactPickerUI2;
template <typename T> struct impl_IContactRemovedEventArgs;

}

namespace Windows::ApplicationModel::Contacts::Provider {

enum class AddContactResult
{
    Added = 0,
    AlreadyAdded = 1,
    Unavailable = 2,
};

}

}
