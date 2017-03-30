// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Xml.Xsl.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Xml::Xsl {

struct WINRT_EBO XsltProcessor :
    Windows::Data::Xml::Xsl::IXsltProcessor,
    impl::require<XsltProcessor, Windows::Data::Xml::Xsl::IXsltProcessor2>
{
    XsltProcessor(std::nullptr_t) noexcept {}
    XsltProcessor(const Windows::Data::Xml::Dom::XmlDocument & document);
};

}

}
