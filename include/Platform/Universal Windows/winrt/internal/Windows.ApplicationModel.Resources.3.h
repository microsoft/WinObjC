// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Resources.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Resources {

struct WINRT_EBO ResourceLoader :
    Windows::ApplicationModel::Resources::IResourceLoader,
    impl::require<ResourceLoader, Windows::ApplicationModel::Resources::IResourceLoader2>
{
    ResourceLoader(std::nullptr_t) noexcept {}
    ResourceLoader();
    ResourceLoader(hstring_view name);
    [[deprecated("GetStringForReference may be altered or unavailable for releases after Windows Phone 'OSVersion' (TBD). Instead, use GetStringForUri.")]] static hstring GetStringForReference(const Windows::Foundation::Uri & uri);
    static Windows::ApplicationModel::Resources::ResourceLoader GetForCurrentView();
    static Windows::ApplicationModel::Resources::ResourceLoader GetForCurrentView(hstring_view name);
    static Windows::ApplicationModel::Resources::ResourceLoader GetForViewIndependentUse();
    static Windows::ApplicationModel::Resources::ResourceLoader GetForViewIndependentUse(hstring_view name);
};

}

}
