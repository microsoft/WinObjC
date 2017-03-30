// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Data.Xml.Xsl.0.h"
#include "Windows.Data.Xml.Dom.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Data::Xml::Xsl {

struct __declspec(uuid("7b64703f-550c-48c6-a90f-93a5b964518f")) __declspec(novtable) IXsltProcessor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TransformToString(Windows::Data::Xml::Dom::IXmlNode * inputNode, hstring * output) = 0;
};

struct __declspec(uuid("8da45c56-97a5-44cb-a8be-27d86280c70a")) __declspec(novtable) IXsltProcessor2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_TransformToDocument(Windows::Data::Xml::Dom::IXmlNode * inputNode, Windows::Data::Xml::Dom::IXmlDocument ** output) = 0;
};

struct __declspec(uuid("274146c0-9a51-4663-bf30-0ef742146f20")) __declspec(novtable) IXsltProcessorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Data::Xml::Dom::IXmlDocument * document, Windows::Data::Xml::Xsl::IXsltProcessor ** xsltProcessor) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Data::Xml::Xsl::XsltProcessor> { using default_interface = Windows::Data::Xml::Xsl::IXsltProcessor; };

}

namespace Windows::Data::Xml::Xsl {

template <typename D>
struct WINRT_EBO impl_IXsltProcessor
{
    hstring TransformToString(const Windows::Data::Xml::Dom::IXmlNode & inputNode) const;
};

template <typename D>
struct WINRT_EBO impl_IXsltProcessor2
{
    Windows::Data::Xml::Dom::XmlDocument TransformToDocument(const Windows::Data::Xml::Dom::IXmlNode & inputNode) const;
};

template <typename D>
struct WINRT_EBO impl_IXsltProcessorFactory
{
    Windows::Data::Xml::Xsl::XsltProcessor CreateInstance(const Windows::Data::Xml::Dom::XmlDocument & document) const;
};

}

namespace impl {

template <> struct traits<Windows::Data::Xml::Xsl::IXsltProcessor>
{
    using abi = ABI::Windows::Data::Xml::Xsl::IXsltProcessor;
    template <typename D> using consume = Windows::Data::Xml::Xsl::impl_IXsltProcessor<D>;
};

template <> struct traits<Windows::Data::Xml::Xsl::IXsltProcessor2>
{
    using abi = ABI::Windows::Data::Xml::Xsl::IXsltProcessor2;
    template <typename D> using consume = Windows::Data::Xml::Xsl::impl_IXsltProcessor2<D>;
};

template <> struct traits<Windows::Data::Xml::Xsl::IXsltProcessorFactory>
{
    using abi = ABI::Windows::Data::Xml::Xsl::IXsltProcessorFactory;
    template <typename D> using consume = Windows::Data::Xml::Xsl::impl_IXsltProcessorFactory<D>;
};

template <> struct traits<Windows::Data::Xml::Xsl::XsltProcessor>
{
    using abi = ABI::Windows::Data::Xml::Xsl::XsltProcessor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Xsl.XsltProcessor"; }
};

}

}
