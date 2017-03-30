// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Core {

struct IApplicationDataManager;
struct IApplicationDataManagerStatics;
struct ApplicationDataManager;

}

namespace Windows::Management::Core {

struct IApplicationDataManager;
struct IApplicationDataManagerStatics;
struct ApplicationDataManager;

}

namespace Windows::Management::Core {

template <typename T> struct impl_IApplicationDataManager;
template <typename T> struct impl_IApplicationDataManagerStatics;

}

}
