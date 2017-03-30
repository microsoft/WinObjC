// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Calls.Provider.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Calls::Provider {

struct WINRT_EBO PhoneCallOrigin :
    Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin,
    impl::require<PhoneCallOrigin, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2, Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>
{
    PhoneCallOrigin(std::nullptr_t) noexcept {}
    PhoneCallOrigin();
};

struct PhoneCallOriginManager
{
    PhoneCallOriginManager() = delete;
    static bool IsCurrentAppActiveCallOriginApp();
    static void ShowPhoneCallOriginSettingsUI();
    static void SetCallOrigin(GUID requestId, const Windows::ApplicationModel::Calls::Provider::PhoneCallOrigin & callOrigin);
    static Windows::Foundation::IAsyncOperation<bool> RequestSetAsActiveCallOriginAppAsync();
};

}

}
