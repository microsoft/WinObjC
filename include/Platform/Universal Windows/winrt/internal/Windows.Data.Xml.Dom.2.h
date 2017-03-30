// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Data.Xml.Dom.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_139d959e_e7b5_5cb6_a596_4b544478da9b
#define WINRT_GENERIC_139d959e_e7b5_5cb6_a596_4b544478da9b
template <> struct __declspec(uuid("139d959e-e7b5-5cb6-a596-4b544478da9b")) __declspec(novtable) IVectorView<Windows::Data::Xml::Dom::IXmlNode> : impl_IVectorView<Windows::Data::Xml::Dom::IXmlNode> {};
#endif

#ifndef WINRT_GENERIC_f1146ffc_8c92_56e8_93f1_711f86722633
#define WINRT_GENERIC_f1146ffc_8c92_56e8_93f1_711f86722633
template <> struct __declspec(uuid("f1146ffc-8c92-56e8-93f1-711f86722633")) __declspec(novtable) IIterable<Windows::Data::Xml::Dom::IXmlNode> : impl_IIterable<Windows::Data::Xml::Dom::IXmlNode> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f858e239_1896_5982_8495_143168478eb8
#define WINRT_GENERIC_f858e239_1896_5982_8495_143168478eb8
template <> struct __declspec(uuid("f858e239-1896-5982-8495-143168478eb8")) __declspec(novtable) IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> : impl_IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3833a35e_2c61_56bd_b093_3694165f8898
#define WINRT_GENERIC_3833a35e_2c61_56bd_b093_3694165f8898
template <> struct __declspec(uuid("3833a35e-2c61-56bd-b093-3694165f8898")) __declspec(novtable) IIterator<Windows::Data::Xml::Dom::IXmlNode> : impl_IIterator<Windows::Data::Xml::Dom::IXmlNode> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5eef7817_93dd_5c0b_9e5a_eb490408f3a9
#define WINRT_GENERIC_5eef7817_93dd_5c0b_9e5a_eb490408f3a9
template <> struct __declspec(uuid("5eef7817-93dd-5c0b-9e5a-eb490408f3a9")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Data::Xml::Dom::XmlDocument> : impl_AsyncOperationCompletedHandler<Windows::Data::Xml::Dom::XmlDocument> {};
#endif


}

namespace Windows::Data::Xml::Dom {

struct IDtdEntity :
    Windows::Foundation::IInspectable,
    impl::consume<IDtdEntity>,
    impl::require<IDtdEntity, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IDtdEntity(std::nullptr_t = nullptr) noexcept {}
};

struct IDtdNotation :
    Windows::Foundation::IInspectable,
    impl::consume<IDtdNotation>,
    impl::require<IDtdNotation, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IDtdNotation(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlAttribute :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlAttribute>,
    impl::require<IXmlAttribute, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlAttribute(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlCDataSection :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlCDataSection>,
    impl::require<IXmlCDataSection, Windows::Data::Xml::Dom::IXmlCharacterData, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer, Windows::Data::Xml::Dom::IXmlText>
{
    IXmlCDataSection(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlCharacterData :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlCharacterData>,
    impl::require<IXmlCharacterData, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlCharacterData(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlComment :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlComment>,
    impl::require<IXmlComment, Windows::Data::Xml::Dom::IXmlCharacterData, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlComment(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocument :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocument>,
    impl::require<IXmlDocument, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlDocument(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocumentFragment :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocumentFragment>,
    impl::require<IXmlDocumentFragment, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlDocumentFragment(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocumentIO :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocumentIO>
{
    IXmlDocumentIO(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocumentIO2 :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocumentIO2>
{
    IXmlDocumentIO2(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocumentStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocumentStatics>
{
    IXmlDocumentStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDocumentType :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDocumentType>,
    impl::require<IXmlDocumentType, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlDocumentType(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlDomImplementation :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlDomImplementation>
{
    IXmlDomImplementation(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlElement :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlElement>,
    impl::require<IXmlElement, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlElement(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlEntityReference :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlEntityReference>,
    impl::require<IXmlEntityReference, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlEntityReference(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlLoadSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlLoadSettings>
{
    IXmlLoadSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlNamedNodeMap :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlNamedNodeMap>,
    impl::require<IXmlNamedNodeMap, Windows::Foundation::Collections::IIterable<Windows::Data::Xml::Dom::IXmlNode>, Windows::Foundation::Collections::IVectorView<Windows::Data::Xml::Dom::IXmlNode>>
{
    IXmlNamedNodeMap(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlNode :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlNode>,
    impl::require<IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlNode(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlNodeList :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlNodeList>,
    impl::require<IXmlNodeList, Windows::Foundation::Collections::IIterable<Windows::Data::Xml::Dom::IXmlNode>, Windows::Foundation::Collections::IVectorView<Windows::Data::Xml::Dom::IXmlNode>>
{
    IXmlNodeList(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlNodeSelector :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlNodeSelector>
{
    IXmlNodeSelector(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlNodeSerializer :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlNodeSerializer>
{
    IXmlNodeSerializer(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlProcessingInstruction :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlProcessingInstruction>,
    impl::require<IXmlProcessingInstruction, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlProcessingInstruction(std::nullptr_t = nullptr) noexcept {}
};

struct IXmlText :
    Windows::Foundation::IInspectable,
    impl::consume<IXmlText>,
    impl::require<IXmlText, Windows::Data::Xml::Dom::IXmlCharacterData, Windows::Data::Xml::Dom::IXmlNode, Windows::Data::Xml::Dom::IXmlNodeSelector, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    IXmlText(std::nullptr_t = nullptr) noexcept {}
};

}

}
