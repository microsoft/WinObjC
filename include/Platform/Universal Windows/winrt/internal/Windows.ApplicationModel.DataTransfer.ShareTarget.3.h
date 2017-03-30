// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.DataTransfer.ShareTarget.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::DataTransfer::ShareTarget {

struct WINRT_EBO QuickLink :
    Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink
{
    QuickLink(std::nullptr_t) noexcept {}
    QuickLink();
};

struct WINRT_EBO ShareOperation :
    Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation,
    impl::require<ShareOperation, Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2>
{
    ShareOperation(std::nullptr_t) noexcept {}
};

}

}
