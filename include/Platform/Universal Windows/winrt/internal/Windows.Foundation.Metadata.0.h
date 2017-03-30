// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Metadata {

struct IApiInformationStatics;

}

namespace Windows::Foundation::Metadata {

struct IApiInformationStatics;
struct ApiInformation;

}

namespace Windows::Foundation::Metadata {

template <typename T> struct impl_IApiInformationStatics;

}

namespace Windows::Foundation::Metadata {

enum class GCPressureAmount
{
    Low = 0,
    Medium = 1,
    High = 2,
};

}

}
