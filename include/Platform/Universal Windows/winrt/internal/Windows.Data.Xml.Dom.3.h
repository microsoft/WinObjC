// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Xml.Dom.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Data::Xml::Dom {

struct WINRT_EBO DtdEntity :
    Windows::Data::Xml::Dom::IDtdEntity
{
    DtdEntity(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DtdNotation :
    Windows::Data::Xml::Dom::IDtdNotation
{
    DtdNotation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlAttribute :
    Windows::Data::Xml::Dom::IXmlAttribute
{
    XmlAttribute(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlCDataSection :
    Windows::Data::Xml::Dom::IXmlCDataSection
{
    XmlCDataSection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlComment :
    Windows::Data::Xml::Dom::IXmlComment
{
    XmlComment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlDocument :
    Windows::Data::Xml::Dom::IXmlDocument,
    impl::require<XmlDocument, Windows::Data::Xml::Dom::IXmlDocumentIO, Windows::Data::Xml::Dom::IXmlDocumentIO2>
{
    XmlDocument(std::nullptr_t) noexcept {}
    XmlDocument();
    static Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromUriAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings);
    static Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromFileAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings);
};

struct WINRT_EBO XmlDocumentFragment :
    Windows::Data::Xml::Dom::IXmlDocumentFragment
{
    XmlDocumentFragment(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlDocumentType :
    Windows::Data::Xml::Dom::IXmlDocumentType
{
    XmlDocumentType(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlDomImplementation :
    Windows::Data::Xml::Dom::IXmlDomImplementation
{
    XmlDomImplementation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlElement :
    Windows::Data::Xml::Dom::IXmlElement
{
    XmlElement(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlEntityReference :
    Windows::Data::Xml::Dom::IXmlEntityReference
{
    XmlEntityReference(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlLoadSettings :
    Windows::Data::Xml::Dom::IXmlLoadSettings
{
    XmlLoadSettings(std::nullptr_t) noexcept {}
    XmlLoadSettings();
};

struct WINRT_EBO XmlNamedNodeMap :
    Windows::Data::Xml::Dom::IXmlNamedNodeMap
{
    XmlNamedNodeMap(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlNodeList :
    Windows::Data::Xml::Dom::IXmlNodeList
{
    XmlNodeList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlProcessingInstruction :
    Windows::Data::Xml::Dom::IXmlProcessingInstruction
{
    XmlProcessingInstruction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO XmlText :
    Windows::Data::Xml::Dom::IXmlText
{
    XmlText(std::nullptr_t) noexcept {}
};

}

}
