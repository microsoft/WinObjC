// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Data.Xml.Dom.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Data::Xml::Dom {

struct __declspec(uuid("6a0b5ffc-63b4-480f-9e6a-8a92816aade4")) __declspec(novtable) IDtdEntity : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PublicId(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SystemId(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_NotationName(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("8cb4e04d-6d46-4edb-ab73-df83c51ad397")) __declspec(novtable) IDtdNotation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PublicId(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SystemId(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("ac144aa4-b4f1-4db6-b206-8a22c308db0a")) __declspec(novtable) IXmlAttribute : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Specified(bool * value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("4d04b46f-c8bd-45b4-8899-0400d7c2c60f")) __declspec(novtable) IXmlCDataSection : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("132e42ab-4e36-4df6-b1c8-0ce62fd88b26")) __declspec(novtable) IXmlCharacterData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Data(hstring * value) = 0;
    virtual HRESULT __stdcall put_Data(hstring value) = 0;
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_SubstringData(uint32_t offset, uint32_t count, hstring * data) = 0;
    virtual HRESULT __stdcall abi_AppendData(hstring data) = 0;
    virtual HRESULT __stdcall abi_InsertData(uint32_t offset, hstring data) = 0;
    virtual HRESULT __stdcall abi_DeleteData(uint32_t offset, uint32_t count) = 0;
    virtual HRESULT __stdcall abi_ReplaceData(uint32_t offset, uint32_t count, hstring data) = 0;
};

struct __declspec(uuid("bca474d5-b61f-4611-9cac-2e92e3476d47")) __declspec(novtable) IXmlComment : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f7f3a506-1e87-42d6-bcfb-b8c809fa5494")) __declspec(novtable) IXmlDocument : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Doctype(Windows::Data::Xml::Dom::IXmlDocumentType ** value) = 0;
    virtual HRESULT __stdcall get_Implementation(Windows::Data::Xml::Dom::IXmlDomImplementation ** value) = 0;
    virtual HRESULT __stdcall get_DocumentElement(Windows::Data::Xml::Dom::IXmlElement ** value) = 0;
    virtual HRESULT __stdcall abi_CreateElement(hstring tagName, Windows::Data::Xml::Dom::IXmlElement ** newElement) = 0;
    virtual HRESULT __stdcall abi_CreateDocumentFragment(Windows::Data::Xml::Dom::IXmlDocumentFragment ** newDocumentFragment) = 0;
    virtual HRESULT __stdcall abi_CreateTextNode(hstring data, Windows::Data::Xml::Dom::IXmlText ** newTextNode) = 0;
    virtual HRESULT __stdcall abi_CreateComment(hstring data, Windows::Data::Xml::Dom::IXmlComment ** newComment) = 0;
    virtual HRESULT __stdcall abi_CreateProcessingInstruction(hstring target, hstring data, Windows::Data::Xml::Dom::IXmlProcessingInstruction ** newProcessingInstruction) = 0;
    virtual HRESULT __stdcall abi_CreateAttribute(hstring name, Windows::Data::Xml::Dom::IXmlAttribute ** newAttribute) = 0;
    virtual HRESULT __stdcall abi_CreateEntityReference(hstring name, Windows::Data::Xml::Dom::IXmlEntityReference ** newEntityReference) = 0;
    virtual HRESULT __stdcall abi_GetElementsByTagName(hstring tagName, Windows::Data::Xml::Dom::IXmlNodeList ** elements) = 0;
    virtual HRESULT __stdcall abi_CreateCDataSection(hstring data, Windows::Data::Xml::Dom::IXmlCDataSection ** newCDataSection) = 0;
    virtual HRESULT __stdcall get_DocumentUri(hstring * value) = 0;
    virtual HRESULT __stdcall abi_CreateAttributeNS(Windows::Foundation::IInspectable * namespaceUri, hstring qualifiedName, Windows::Data::Xml::Dom::IXmlAttribute ** newAttribute) = 0;
    virtual HRESULT __stdcall abi_CreateElementNS(Windows::Foundation::IInspectable * namespaceUri, hstring qualifiedName, Windows::Data::Xml::Dom::IXmlElement ** newElement) = 0;
    virtual HRESULT __stdcall abi_GetElementById(hstring elementId, Windows::Data::Xml::Dom::IXmlElement ** element) = 0;
    virtual HRESULT __stdcall abi_ImportNode(Windows::Data::Xml::Dom::IXmlNode * node, bool deep, Windows::Data::Xml::Dom::IXmlNode ** newNode) = 0;
};

struct __declspec(uuid("e2ea6a96-0c21-44a5-8bc9-9e4a262708ec")) __declspec(novtable) IXmlDocumentFragment : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("6cd0e74e-ee65-4489-9ebf-ca43e87ba637")) __declspec(novtable) IXmlDocumentIO : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadXml(hstring xml) = 0;
    virtual HRESULT __stdcall abi_LoadXmlWithSettings(hstring xml, Windows::Data::Xml::Dom::IXmlLoadSettings * loadSettings) = 0;
    virtual HRESULT __stdcall abi_SaveToFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** asyncInfo) = 0;
};

struct __declspec(uuid("5d034661-7bd8-4ad5-9ebf-81e6347263b1")) __declspec(novtable) IXmlDocumentIO2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadXmlFromBuffer(Windows::Storage::Streams::IBuffer * buffer) = 0;
    virtual HRESULT __stdcall abi_LoadXmlFromBufferWithSettings(Windows::Storage::Streams::IBuffer * buffer, Windows::Data::Xml::Dom::IXmlLoadSettings * loadSettings) = 0;
};

struct __declspec(uuid("5543d254-d757-4b79-9539-232b18f50bf1")) __declspec(novtable) IXmlDocumentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadFromUriAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_LoadFromUriWithSettingsAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Data::Xml::Dom::IXmlLoadSettings * loadSettings, Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_LoadFromFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> ** asyncInfo) = 0;
    virtual HRESULT __stdcall abi_LoadFromFileWithSettingsAsync(Windows::Storage::IStorageFile * file, Windows::Data::Xml::Dom::IXmlLoadSettings * loadSettings, Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> ** asyncInfo) = 0;
};

struct __declspec(uuid("f7342425-9781-4964-8e94-9b1c6dfc9bc7")) __declspec(novtable) IXmlDocumentType : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Entities(Windows::Data::Xml::Dom::IXmlNamedNodeMap ** value) = 0;
    virtual HRESULT __stdcall get_Notations(Windows::Data::Xml::Dom::IXmlNamedNodeMap ** value) = 0;
};

struct __declspec(uuid("6de58132-f11d-4fbb-8cc6-583cba93112f")) __declspec(novtable) IXmlDomImplementation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_HasFeature(hstring feature, Windows::Foundation::IInspectable * version, bool * featureSupported) = 0;
};

struct __declspec(uuid("2dfb8a1f-6b10-4ef8-9f83-efcce8faec37")) __declspec(novtable) IXmlElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TagName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetAttribute(hstring attributeName, hstring * attributeValue) = 0;
    virtual HRESULT __stdcall abi_SetAttribute(hstring attributeName, hstring attributeValue) = 0;
    virtual HRESULT __stdcall abi_RemoveAttribute(hstring attributeName) = 0;
    virtual HRESULT __stdcall abi_GetAttributeNode(hstring attributeName, Windows::Data::Xml::Dom::IXmlAttribute ** attributeNode) = 0;
    virtual HRESULT __stdcall abi_SetAttributeNode(Windows::Data::Xml::Dom::IXmlAttribute * newAttribute, Windows::Data::Xml::Dom::IXmlAttribute ** previousAttribute) = 0;
    virtual HRESULT __stdcall abi_RemoveAttributeNode(Windows::Data::Xml::Dom::IXmlAttribute * attributeNode, Windows::Data::Xml::Dom::IXmlAttribute ** removedAttribute) = 0;
    virtual HRESULT __stdcall abi_GetElementsByTagName(hstring tagName, Windows::Data::Xml::Dom::IXmlNodeList ** elements) = 0;
    virtual HRESULT __stdcall abi_SetAttributeNS(Windows::Foundation::IInspectable * namespaceUri, hstring qualifiedName, hstring value) = 0;
    virtual HRESULT __stdcall abi_GetAttributeNS(Windows::Foundation::IInspectable * namespaceUri, hstring localName, hstring * value) = 0;
    virtual HRESULT __stdcall abi_RemoveAttributeNS(Windows::Foundation::IInspectable * namespaceUri, hstring localName) = 0;
    virtual HRESULT __stdcall abi_SetAttributeNodeNS(Windows::Data::Xml::Dom::IXmlAttribute * newAttribute, Windows::Data::Xml::Dom::IXmlAttribute ** previousAttribute) = 0;
    virtual HRESULT __stdcall abi_GetAttributeNodeNS(Windows::Foundation::IInspectable * namespaceUri, hstring localName, Windows::Data::Xml::Dom::IXmlAttribute ** previousAttribute) = 0;
};

struct __declspec(uuid("2e2f47bc-c3d0-4ccf-bb86-0ab8c36a61cf")) __declspec(novtable) IXmlEntityReference : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("58aa07a8-fed6-46f7-b4c5-fb1ba72108d6")) __declspec(novtable) IXmlLoadSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxElementDepth(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxElementDepth(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ProhibitDtd(bool * value) = 0;
    virtual HRESULT __stdcall put_ProhibitDtd(bool value) = 0;
    virtual HRESULT __stdcall get_ResolveExternals(bool * value) = 0;
    virtual HRESULT __stdcall put_ResolveExternals(bool value) = 0;
    virtual HRESULT __stdcall get_ValidateOnParse(bool * value) = 0;
    virtual HRESULT __stdcall put_ValidateOnParse(bool value) = 0;
    virtual HRESULT __stdcall get_ElementContentWhiteSpace(bool * value) = 0;
    virtual HRESULT __stdcall put_ElementContentWhiteSpace(bool value) = 0;
};

struct __declspec(uuid("b3a69eb0-aab0-4b82-a6fa-b1453f7c021b")) __declspec(novtable) IXmlNamedNodeMap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_Item(uint32_t index, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
    virtual HRESULT __stdcall abi_GetNamedItem(hstring name, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
    virtual HRESULT __stdcall abi_SetNamedItem(Windows::Data::Xml::Dom::IXmlNode * node, Windows::Data::Xml::Dom::IXmlNode ** previousNode) = 0;
    virtual HRESULT __stdcall abi_RemoveNamedItem(hstring name, Windows::Data::Xml::Dom::IXmlNode ** previousNode) = 0;
    virtual HRESULT __stdcall abi_GetNamedItemNS(Windows::Foundation::IInspectable * namespaceUri, hstring name, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
    virtual HRESULT __stdcall abi_RemoveNamedItemNS(Windows::Foundation::IInspectable * namespaceUri, hstring name, Windows::Data::Xml::Dom::IXmlNode ** previousNode) = 0;
    virtual HRESULT __stdcall abi_SetNamedItemNS(Windows::Data::Xml::Dom::IXmlNode * node, Windows::Data::Xml::Dom::IXmlNode ** previousNode) = 0;
};

struct __declspec(uuid("1c741d59-2122-47d5-a856-83f3d4214875")) __declspec(novtable) IXmlNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NodeValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_NodeValue(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_NodeType(winrt::Windows::Data::Xml::Dom::NodeType * value) = 0;
    virtual HRESULT __stdcall get_NodeName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ParentNode(Windows::Data::Xml::Dom::IXmlNode ** value) = 0;
    virtual HRESULT __stdcall get_ChildNodes(Windows::Data::Xml::Dom::IXmlNodeList ** value) = 0;
    virtual HRESULT __stdcall get_FirstChild(Windows::Data::Xml::Dom::IXmlNode ** value) = 0;
    virtual HRESULT __stdcall get_LastChild(Windows::Data::Xml::Dom::IXmlNode ** value) = 0;
    virtual HRESULT __stdcall get_PreviousSibling(Windows::Data::Xml::Dom::IXmlNode ** value) = 0;
    virtual HRESULT __stdcall get_NextSibling(Windows::Data::Xml::Dom::IXmlNode ** value) = 0;
    virtual HRESULT __stdcall get_Attributes(Windows::Data::Xml::Dom::IXmlNamedNodeMap ** value) = 0;
    virtual HRESULT __stdcall abi_HasChildNodes(bool * value) = 0;
    virtual HRESULT __stdcall get_OwnerDocument(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall abi_InsertBefore(Windows::Data::Xml::Dom::IXmlNode * newChild, Windows::Data::Xml::Dom::IXmlNode * referenceChild, Windows::Data::Xml::Dom::IXmlNode ** insertedChild) = 0;
    virtual HRESULT __stdcall abi_ReplaceChild(Windows::Data::Xml::Dom::IXmlNode * newChild, Windows::Data::Xml::Dom::IXmlNode * referenceChild, Windows::Data::Xml::Dom::IXmlNode ** previousChild) = 0;
    virtual HRESULT __stdcall abi_RemoveChild(Windows::Data::Xml::Dom::IXmlNode * childNode, Windows::Data::Xml::Dom::IXmlNode ** removedChild) = 0;
    virtual HRESULT __stdcall abi_AppendChild(Windows::Data::Xml::Dom::IXmlNode * newChild, Windows::Data::Xml::Dom::IXmlNode ** appendedChild) = 0;
    virtual HRESULT __stdcall abi_CloneNode(bool deep, Windows::Data::Xml::Dom::IXmlNode ** newNode) = 0;
    virtual HRESULT __stdcall get_NamespaceUri(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_LocalName(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Prefix(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_Normalize() = 0;
    virtual HRESULT __stdcall put_Prefix(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("8c60ad77-83a4-4ec1-9c54-7ba429e13da6")) __declspec(novtable) IXmlNodeList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_Item(uint32_t index, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
};

struct __declspec(uuid("63dbba8b-d0db-4fe1-b745-f9433afdc25b")) __declspec(novtable) IXmlNodeSelector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectSingleNode(hstring xpath, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
    virtual HRESULT __stdcall abi_SelectNodes(hstring xpath, Windows::Data::Xml::Dom::IXmlNodeList ** nodelist) = 0;
    virtual HRESULT __stdcall abi_SelectSingleNodeNS(hstring xpath, Windows::Foundation::IInspectable * namespaces, Windows::Data::Xml::Dom::IXmlNode ** node) = 0;
    virtual HRESULT __stdcall abi_SelectNodesNS(hstring xpath, Windows::Foundation::IInspectable * namespaces, Windows::Data::Xml::Dom::IXmlNodeList ** nodelist) = 0;
};

struct __declspec(uuid("5cc5b382-e6dd-4991-abef-06d8d2e7bd0c")) __declspec(novtable) IXmlNodeSerializer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetXml(hstring * outerXml) = 0;
    virtual HRESULT __stdcall get_InnerText(hstring * value) = 0;
    virtual HRESULT __stdcall put_InnerText(hstring value) = 0;
};

struct __declspec(uuid("2707fd1e-1e92-4ece-b6f4-26f069078ddc")) __declspec(novtable) IXmlProcessingInstruction : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Target(hstring * value) = 0;
    virtual HRESULT __stdcall get_Data(hstring * value) = 0;
    virtual HRESULT __stdcall put_Data(hstring value) = 0;
};

struct __declspec(uuid("f931a4cb-308d-4760-a1d5-43b67450ac7e")) __declspec(novtable) IXmlText : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SplitText(uint32_t offset, Windows::Data::Xml::Dom::IXmlText ** secondPart) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Data::Xml::Dom::DtdEntity> { using default_interface = Windows::Data::Xml::Dom::IDtdEntity; };
template <> struct traits<Windows::Data::Xml::Dom::DtdNotation> { using default_interface = Windows::Data::Xml::Dom::IDtdNotation; };
template <> struct traits<Windows::Data::Xml::Dom::XmlAttribute> { using default_interface = Windows::Data::Xml::Dom::IXmlAttribute; };
template <> struct traits<Windows::Data::Xml::Dom::XmlCDataSection> { using default_interface = Windows::Data::Xml::Dom::IXmlCDataSection; };
template <> struct traits<Windows::Data::Xml::Dom::XmlComment> { using default_interface = Windows::Data::Xml::Dom::IXmlComment; };
template <> struct traits<Windows::Data::Xml::Dom::XmlDocument> { using default_interface = Windows::Data::Xml::Dom::IXmlDocument; };
template <> struct traits<Windows::Data::Xml::Dom::XmlDocumentFragment> { using default_interface = Windows::Data::Xml::Dom::IXmlDocumentFragment; };
template <> struct traits<Windows::Data::Xml::Dom::XmlDocumentType> { using default_interface = Windows::Data::Xml::Dom::IXmlDocumentType; };
template <> struct traits<Windows::Data::Xml::Dom::XmlDomImplementation> { using default_interface = Windows::Data::Xml::Dom::IXmlDomImplementation; };
template <> struct traits<Windows::Data::Xml::Dom::XmlElement> { using default_interface = Windows::Data::Xml::Dom::IXmlElement; };
template <> struct traits<Windows::Data::Xml::Dom::XmlEntityReference> { using default_interface = Windows::Data::Xml::Dom::IXmlEntityReference; };
template <> struct traits<Windows::Data::Xml::Dom::XmlLoadSettings> { using default_interface = Windows::Data::Xml::Dom::IXmlLoadSettings; };
template <> struct traits<Windows::Data::Xml::Dom::XmlNamedNodeMap> { using default_interface = Windows::Data::Xml::Dom::IXmlNamedNodeMap; };
template <> struct traits<Windows::Data::Xml::Dom::XmlNodeList> { using default_interface = Windows::Data::Xml::Dom::IXmlNodeList; };
template <> struct traits<Windows::Data::Xml::Dom::XmlProcessingInstruction> { using default_interface = Windows::Data::Xml::Dom::IXmlProcessingInstruction; };
template <> struct traits<Windows::Data::Xml::Dom::XmlText> { using default_interface = Windows::Data::Xml::Dom::IXmlText; };

}

namespace Windows::Data::Xml::Dom {

template <typename D>
struct WINRT_EBO impl_IDtdEntity
{
    Windows::Foundation::IInspectable PublicId() const;
    Windows::Foundation::IInspectable SystemId() const;
    Windows::Foundation::IInspectable NotationName() const;
};

template <typename D>
struct WINRT_EBO impl_IDtdNotation
{
    Windows::Foundation::IInspectable PublicId() const;
    Windows::Foundation::IInspectable SystemId() const;
};

template <typename D>
struct WINRT_EBO impl_IXmlAttribute
{
    hstring Name() const;
    bool Specified() const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlCDataSection
{
};

template <typename D>
struct WINRT_EBO impl_IXmlCharacterData
{
    hstring Data() const;
    void Data(hstring_view value) const;
    uint32_t Length() const;
    hstring SubstringData(uint32_t offset, uint32_t count) const;
    void AppendData(hstring_view data) const;
    void InsertData(uint32_t offset, hstring_view data) const;
    void DeleteData(uint32_t offset, uint32_t count) const;
    void ReplaceData(uint32_t offset, uint32_t count, hstring_view data) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlComment
{
};

template <typename D>
struct WINRT_EBO impl_IXmlDocument
{
    Windows::Data::Xml::Dom::XmlDocumentType Doctype() const;
    Windows::Data::Xml::Dom::XmlDomImplementation Implementation() const;
    Windows::Data::Xml::Dom::XmlElement DocumentElement() const;
    Windows::Data::Xml::Dom::XmlElement CreateElement(hstring_view tagName) const;
    Windows::Data::Xml::Dom::XmlDocumentFragment CreateDocumentFragment() const;
    Windows::Data::Xml::Dom::XmlText CreateTextNode(hstring_view data) const;
    Windows::Data::Xml::Dom::XmlComment CreateComment(hstring_view data) const;
    Windows::Data::Xml::Dom::XmlProcessingInstruction CreateProcessingInstruction(hstring_view target, hstring_view data) const;
    Windows::Data::Xml::Dom::XmlAttribute CreateAttribute(hstring_view name) const;
    Windows::Data::Xml::Dom::XmlEntityReference CreateEntityReference(hstring_view name) const;
    Windows::Data::Xml::Dom::XmlNodeList GetElementsByTagName(hstring_view tagName) const;
    Windows::Data::Xml::Dom::XmlCDataSection CreateCDataSection(hstring_view data) const;
    hstring DocumentUri() const;
    Windows::Data::Xml::Dom::XmlAttribute CreateAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName) const;
    Windows::Data::Xml::Dom::XmlElement CreateElementNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName) const;
    Windows::Data::Xml::Dom::XmlElement GetElementById(hstring_view elementId) const;
    Windows::Data::Xml::Dom::IXmlNode ImportNode(const Windows::Data::Xml::Dom::IXmlNode & node, bool deep) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlDocumentFragment
{
};

template <typename D>
struct WINRT_EBO impl_IXmlDocumentIO
{
    void LoadXml(hstring_view xml) const;
    void LoadXml(hstring_view xml, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const;
    Windows::Foundation::IAsyncAction SaveToFileAsync(const Windows::Storage::IStorageFile & file) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlDocumentIO2
{
    void LoadXmlFromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const;
    void LoadXmlFromBuffer(const Windows::Storage::Streams::IBuffer & buffer, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlDocumentStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromUriAsync(const Windows::Foundation::Uri & uri) const;
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const;
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromFileAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> LoadFromFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlDocumentType
{
    hstring Name() const;
    Windows::Data::Xml::Dom::XmlNamedNodeMap Entities() const;
    Windows::Data::Xml::Dom::XmlNamedNodeMap Notations() const;
};

template <typename D>
struct WINRT_EBO impl_IXmlDomImplementation
{
    bool HasFeature(hstring_view feature, const Windows::Foundation::IInspectable & version) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlElement
{
    hstring TagName() const;
    hstring GetAttribute(hstring_view attributeName) const;
    void SetAttribute(hstring_view attributeName, hstring_view attributeValue) const;
    void RemoveAttribute(hstring_view attributeName) const;
    Windows::Data::Xml::Dom::XmlAttribute GetAttributeNode(hstring_view attributeName) const;
    Windows::Data::Xml::Dom::XmlAttribute SetAttributeNode(const Windows::Data::Xml::Dom::XmlAttribute & newAttribute) const;
    Windows::Data::Xml::Dom::XmlAttribute RemoveAttributeNode(const Windows::Data::Xml::Dom::XmlAttribute & attributeNode) const;
    Windows::Data::Xml::Dom::XmlNodeList GetElementsByTagName(hstring_view tagName) const;
    void SetAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName, hstring_view value) const;
    hstring GetAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const;
    void RemoveAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const;
    Windows::Data::Xml::Dom::XmlAttribute SetAttributeNodeNS(const Windows::Data::Xml::Dom::XmlAttribute & newAttribute) const;
    Windows::Data::Xml::Dom::XmlAttribute GetAttributeNodeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlEntityReference
{
};

template <typename D>
struct WINRT_EBO impl_IXmlLoadSettings
{
    uint32_t MaxElementDepth() const;
    void MaxElementDepth(uint32_t value) const;
    bool ProhibitDtd() const;
    void ProhibitDtd(bool value) const;
    bool ResolveExternals() const;
    void ResolveExternals(bool value) const;
    bool ValidateOnParse() const;
    void ValidateOnParse(bool value) const;
    bool ElementContentWhiteSpace() const;
    void ElementContentWhiteSpace(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlNamedNodeMap
{
    uint32_t Length() const;
    Windows::Data::Xml::Dom::IXmlNode Item(uint32_t index) const;
    Windows::Data::Xml::Dom::IXmlNode GetNamedItem(hstring_view name) const;
    Windows::Data::Xml::Dom::IXmlNode SetNamedItem(const Windows::Data::Xml::Dom::IXmlNode & node) const;
    Windows::Data::Xml::Dom::IXmlNode RemoveNamedItem(hstring_view name) const;
    Windows::Data::Xml::Dom::IXmlNode GetNamedItemNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view name) const;
    Windows::Data::Xml::Dom::IXmlNode RemoveNamedItemNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view name) const;
    Windows::Data::Xml::Dom::IXmlNode SetNamedItemNS(const Windows::Data::Xml::Dom::IXmlNode & node) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlNode
{
    Windows::Foundation::IInspectable NodeValue() const;
    void NodeValue(const Windows::Foundation::IInspectable & value) const;
    Windows::Data::Xml::Dom::NodeType NodeType() const;
    hstring NodeName() const;
    Windows::Data::Xml::Dom::IXmlNode ParentNode() const;
    Windows::Data::Xml::Dom::XmlNodeList ChildNodes() const;
    Windows::Data::Xml::Dom::IXmlNode FirstChild() const;
    Windows::Data::Xml::Dom::IXmlNode LastChild() const;
    Windows::Data::Xml::Dom::IXmlNode PreviousSibling() const;
    Windows::Data::Xml::Dom::IXmlNode NextSibling() const;
    Windows::Data::Xml::Dom::XmlNamedNodeMap Attributes() const;
    bool HasChildNodes() const;
    Windows::Data::Xml::Dom::XmlDocument OwnerDocument() const;
    Windows::Data::Xml::Dom::IXmlNode InsertBefore(const Windows::Data::Xml::Dom::IXmlNode & newChild, const Windows::Data::Xml::Dom::IXmlNode & referenceChild) const;
    Windows::Data::Xml::Dom::IXmlNode ReplaceChild(const Windows::Data::Xml::Dom::IXmlNode & newChild, const Windows::Data::Xml::Dom::IXmlNode & referenceChild) const;
    Windows::Data::Xml::Dom::IXmlNode RemoveChild(const Windows::Data::Xml::Dom::IXmlNode & childNode) const;
    Windows::Data::Xml::Dom::IXmlNode AppendChild(const Windows::Data::Xml::Dom::IXmlNode & newChild) const;
    Windows::Data::Xml::Dom::IXmlNode CloneNode(bool deep) const;
    Windows::Foundation::IInspectable NamespaceUri() const;
    Windows::Foundation::IInspectable LocalName() const;
    Windows::Foundation::IInspectable Prefix() const;
    void Normalize() const;
    void Prefix(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlNodeList
{
    uint32_t Length() const;
    Windows::Data::Xml::Dom::IXmlNode Item(uint32_t index) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlNodeSelector
{
    Windows::Data::Xml::Dom::IXmlNode SelectSingleNode(hstring_view xpath) const;
    Windows::Data::Xml::Dom::XmlNodeList SelectNodes(hstring_view xpath) const;
    Windows::Data::Xml::Dom::IXmlNode SelectSingleNodeNS(hstring_view xpath, const Windows::Foundation::IInspectable & namespaces) const;
    Windows::Data::Xml::Dom::XmlNodeList SelectNodesNS(hstring_view xpath, const Windows::Foundation::IInspectable & namespaces) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlNodeSerializer
{
    hstring GetXml() const;
    hstring InnerText() const;
    void InnerText(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlProcessingInstruction
{
    hstring Target() const;
    hstring Data() const;
    void Data(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IXmlText
{
    Windows::Data::Xml::Dom::IXmlText SplitText(uint32_t offset) const;
};

}

namespace impl {

template <> struct traits<Windows::Data::Xml::Dom::IDtdEntity>
{
    using abi = ABI::Windows::Data::Xml::Dom::IDtdEntity;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IDtdEntity<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IDtdNotation>
{
    using abi = ABI::Windows::Data::Xml::Dom::IDtdNotation;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IDtdNotation<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlAttribute>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlAttribute;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlAttribute<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlCDataSection>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlCDataSection;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlCDataSection<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlCharacterData>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlCharacterData;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlCharacterData<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlComment>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlComment;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlComment<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocument>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocument;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocument<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocumentFragment>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocumentFragment;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocumentFragment<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocumentIO>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocumentIO;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocumentIO<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocumentIO2>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocumentIO2;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocumentIO2<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocumentStatics>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocumentStatics;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocumentStatics<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDocumentType>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDocumentType;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDocumentType<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlDomImplementation>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlDomImplementation;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlDomImplementation<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlElement>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlElement;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlElement<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlEntityReference>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlEntityReference;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlEntityReference<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlLoadSettings>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlLoadSettings;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlLoadSettings<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlNamedNodeMap>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlNamedNodeMap;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlNamedNodeMap<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlNode>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlNode;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlNode<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlNodeList>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlNodeList;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlNodeList<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlNodeSelector>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlNodeSelector;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlNodeSelector<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlNodeSerializer;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlNodeSerializer<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlProcessingInstruction>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlProcessingInstruction;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlProcessingInstruction<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::IXmlText>
{
    using abi = ABI::Windows::Data::Xml::Dom::IXmlText;
    template <typename D> using consume = Windows::Data::Xml::Dom::impl_IXmlText<D>;
};

template <> struct traits<Windows::Data::Xml::Dom::DtdEntity>
{
    using abi = ABI::Windows::Data::Xml::Dom::DtdEntity;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.DtdEntity"; }
};

template <> struct traits<Windows::Data::Xml::Dom::DtdNotation>
{
    using abi = ABI::Windows::Data::Xml::Dom::DtdNotation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.DtdNotation"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlAttribute>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlAttribute;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlAttribute"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlCDataSection>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlCDataSection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlCDataSection"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlComment>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlComment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlComment"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlDocument>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlDocument;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlDocument"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlDocumentFragment>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlDocumentFragment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlDocumentFragment"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlDocumentType>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlDocumentType;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlDocumentType"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlDomImplementation>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlDomImplementation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlDomImplementation"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlElement>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlElement"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlEntityReference>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlEntityReference;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlEntityReference"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlLoadSettings>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlLoadSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlLoadSettings"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlNamedNodeMap>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlNamedNodeMap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlNamedNodeMap"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlNodeList>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlNodeList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlNodeList"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlProcessingInstruction>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlProcessingInstruction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlProcessingInstruction"; }
};

template <> struct traits<Windows::Data::Xml::Dom::XmlText>
{
    using abi = ABI::Windows::Data::Xml::Dom::XmlText;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Data.Xml.Dom.XmlText"; }
};

}

}
