// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Store.LicenseManagement.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Store::LicenseManagement {

struct LicenseManager
{
    LicenseManager() = delete;
    static Windows::Foundation::IAsyncAction AddLicenseAsync(const Windows::Storage::Streams::IBuffer & license);
    static Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> GetSatisfactionInfosAsync(iterable<hstring> contentIds, iterable<hstring> keyIds);
};

struct WINRT_EBO LicenseSatisfactionInfo :
    Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo
{
    LicenseSatisfactionInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LicenseSatisfactionResult :
    Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult
{
    LicenseSatisfactionResult(std::nullptr_t) noexcept {}
};

}

}
