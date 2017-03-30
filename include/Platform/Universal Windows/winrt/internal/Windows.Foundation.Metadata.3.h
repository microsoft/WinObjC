// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Foundation.Metadata.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Foundation::Metadata {

struct ApiInformation
{
    ApiInformation() = delete;
    static bool IsTypePresent(hstring_view typeName);
    static bool IsMethodPresent(hstring_view typeName, hstring_view methodName);
    static bool IsMethodPresent(hstring_view typeName, hstring_view methodName, uint32_t inputParameterCount);
    static bool IsEventPresent(hstring_view typeName, hstring_view eventName);
    static bool IsPropertyPresent(hstring_view typeName, hstring_view propertyName);
    static bool IsReadOnlyPropertyPresent(hstring_view typeName, hstring_view propertyName);
    static bool IsWriteablePropertyPresent(hstring_view typeName, hstring_view propertyName);
    static bool IsEnumNamedValuePresent(hstring_view enumTypeName, hstring_view valueName);
    static bool IsApiContractPresent(hstring_view contractName, uint16_t majorVersion);
    static bool IsApiContractPresent(hstring_view contractName, uint16_t majorVersion, uint16_t minorVersion);
};

}

}
