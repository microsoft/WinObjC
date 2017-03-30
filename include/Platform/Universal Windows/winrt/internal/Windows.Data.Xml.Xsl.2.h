// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Xml.Xsl.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Xml::Xsl {

struct IXsltProcessor :
    Windows::Foundation::IInspectable,
    impl::consume<IXsltProcessor>
{
    IXsltProcessor(std::nullptr_t = nullptr) noexcept {}
};

struct IXsltProcessor2 :
    Windows::Foundation::IInspectable,
    impl::consume<IXsltProcessor2>
{
    IXsltProcessor2(std::nullptr_t = nullptr) noexcept {}
};

struct IXsltProcessorFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IXsltProcessorFactory>
{
    IXsltProcessorFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
