// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Deployment::Preview {

struct IClassicAppManagerStatics;
struct IInstalledClassicAppInfo;
struct InstalledClassicAppInfo;

}

namespace Windows::Management::Deployment::Preview {

struct IClassicAppManagerStatics;
struct IInstalledClassicAppInfo;
struct ClassicAppManager;
struct InstalledClassicAppInfo;

}

namespace Windows::Management::Deployment::Preview {

template <typename T> struct impl_IClassicAppManagerStatics;
template <typename T> struct impl_IInstalledClassicAppInfo;

}

}
