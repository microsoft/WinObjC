// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Data.Xml.Dom.3.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IDtdEntity> : produce_base<D, Windows::Data::Xml::Dom::IDtdEntity>
{
    HRESULT __stdcall get_PublicId(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemId(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NotationName(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NotationName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IDtdNotation> : produce_base<D, Windows::Data::Xml::Dom::IDtdNotation>
{
    HRESULT __stdcall get_PublicId(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemId(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlAttribute> : produce_base<D, Windows::Data::Xml::Dom::IXmlAttribute>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Specified(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Specified());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlCDataSection> : produce_base<D, Windows::Data::Xml::Dom::IXmlCDataSection>
{};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlCharacterData> : produce_base<D, Windows::Data::Xml::Dom::IXmlCharacterData>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SubstringData(uint32_t offset, uint32_t count, impl::abi_arg_out<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *data = detach_abi(this->shim().SubstringData(offset, count));
            return S_OK;
        }
        catch (...)
        {
            *data = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendData(impl::abi_arg_in<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendData(*reinterpret_cast<const hstring *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertData(uint32_t offset, impl::abi_arg_in<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertData(offset, *reinterpret_cast<const hstring *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteData(uint32_t offset, uint32_t count) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteData(offset, count);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceData(uint32_t offset, uint32_t count, impl::abi_arg_in<hstring> data) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReplaceData(offset, count, *reinterpret_cast<const hstring *>(&data));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlComment> : produce_base<D, Windows::Data::Xml::Dom::IXmlComment>
{};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocument> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocument>
{
    HRESULT __stdcall get_Doctype(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocumentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Doctype());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Implementation(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDomImplementation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Implementation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentElement(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlElement> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentElement());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateElement(impl::abi_arg_in<hstring> tagName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlElement> newElement) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newElement = detach_abi(this->shim().CreateElement(*reinterpret_cast<const hstring *>(&tagName)));
            return S_OK;
        }
        catch (...)
        {
            *newElement = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDocumentFragment(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocumentFragment> newDocumentFragment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newDocumentFragment = detach_abi(this->shim().CreateDocumentFragment());
            return S_OK;
        }
        catch (...)
        {
            *newDocumentFragment = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTextNode(impl::abi_arg_in<hstring> data, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlText> newTextNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newTextNode = detach_abi(this->shim().CreateTextNode(*reinterpret_cast<const hstring *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *newTextNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateComment(impl::abi_arg_in<hstring> data, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlComment> newComment) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newComment = detach_abi(this->shim().CreateComment(*reinterpret_cast<const hstring *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *newComment = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateProcessingInstruction(impl::abi_arg_in<hstring> target, impl::abi_arg_in<hstring> data, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlProcessingInstruction> newProcessingInstruction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newProcessingInstruction = detach_abi(this->shim().CreateProcessingInstruction(*reinterpret_cast<const hstring *>(&target), *reinterpret_cast<const hstring *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *newProcessingInstruction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttribute(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> newAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newAttribute = detach_abi(this->shim().CreateAttribute(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *newAttribute = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateEntityReference(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlEntityReference> newEntityReference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newEntityReference = detach_abi(this->shim().CreateEntityReference(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *newEntityReference = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementsByTagName(impl::abi_arg_in<hstring> tagName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNodeList> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().GetElementsByTagName(*reinterpret_cast<const hstring *>(&tagName)));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCDataSection(impl::abi_arg_in<hstring> data, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlCDataSection> newCDataSection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newCDataSection = detach_abi(this->shim().CreateCDataSection(*reinterpret_cast<const hstring *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *newCDataSection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DocumentUri(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DocumentUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttributeNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> qualifiedName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> newAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newAttribute = detach_abi(this->shim().CreateAttributeNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&qualifiedName)));
            return S_OK;
        }
        catch (...)
        {
            *newAttribute = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateElementNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> qualifiedName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlElement> newElement) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newElement = detach_abi(this->shim().CreateElementNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&qualifiedName)));
            return S_OK;
        }
        catch (...)
        {
            *newElement = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementById(impl::abi_arg_in<hstring> elementId, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlElement> element) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *element = detach_abi(this->shim().GetElementById(*reinterpret_cast<const hstring *>(&elementId)));
            return S_OK;
        }
        catch (...)
        {
            *element = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportNode(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> node, bool deep, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> newNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newNode = detach_abi(this->shim().ImportNode(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&node), deep));
            return S_OK;
        }
        catch (...)
        {
            *newNode = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocumentFragment> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocumentFragment>
{};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocumentIO> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocumentIO>
{
    HRESULT __stdcall abi_LoadXml(impl::abi_arg_in<hstring> xml) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadXml(*reinterpret_cast<const hstring *>(&xml));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadXmlWithSettings(impl::abi_arg_in<hstring> xml, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlLoadSettings> loadSettings) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadXml(*reinterpret_cast<const hstring *>(&xml), *reinterpret_cast<const Windows::Data::Xml::Dom::XmlLoadSettings *>(&loadSettings));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveToFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SaveToFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocumentIO2> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocumentIO2>
{
    HRESULT __stdcall abi_LoadXmlFromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadXmlFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadXmlFromBufferWithSettings(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlLoadSettings> loadSettings) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadXmlFromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer), *reinterpret_cast<const Windows::Data::Xml::Dom::XmlLoadSettings *>(&loadSettings));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocumentStatics> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocumentStatics>
{
    HRESULT __stdcall abi_LoadFromUriAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromUriWithSettingsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlLoadSettings> loadSettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromUriAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri), *reinterpret_cast<const Windows::Data::Xml::Dom::XmlLoadSettings *>(&loadSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromFileWithSettingsAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlLoadSettings> loadSettings, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const Windows::Data::Xml::Dom::XmlLoadSettings *>(&loadSettings)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDocumentType> : produce_base<D, Windows::Data::Xml::Dom::IXmlDocumentType>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Entities(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNamedNodeMap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Entities());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Notations(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNamedNodeMap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Notations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlDomImplementation> : produce_base<D, Windows::Data::Xml::Dom::IXmlDomImplementation>
{
    HRESULT __stdcall abi_HasFeature(impl::abi_arg_in<hstring> feature, impl::abi_arg_in<Windows::Foundation::IInspectable> version, bool * featureSupported) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *featureSupported = detach_abi(this->shim().HasFeature(*reinterpret_cast<const hstring *>(&feature), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&version)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlElement> : produce_base<D, Windows::Data::Xml::Dom::IXmlElement>
{
    HRESULT __stdcall get_TagName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TagName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttribute(impl::abi_arg_in<hstring> attributeName, impl::abi_arg_out<hstring> attributeValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *attributeValue = detach_abi(this->shim().GetAttribute(*reinterpret_cast<const hstring *>(&attributeName)));
            return S_OK;
        }
        catch (...)
        {
            *attributeValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAttribute(impl::abi_arg_in<hstring> attributeName, impl::abi_arg_in<hstring> attributeValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAttribute(*reinterpret_cast<const hstring *>(&attributeName), *reinterpret_cast<const hstring *>(&attributeValue));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAttribute(impl::abi_arg_in<hstring> attributeName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAttribute(*reinterpret_cast<const hstring *>(&attributeName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttributeNode(impl::abi_arg_in<hstring> attributeName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> attributeNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *attributeNode = detach_abi(this->shim().GetAttributeNode(*reinterpret_cast<const hstring *>(&attributeName)));
            return S_OK;
        }
        catch (...)
        {
            *attributeNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAttributeNode(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlAttribute> newAttribute, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> previousAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousAttribute = detach_abi(this->shim().SetAttributeNode(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlAttribute *>(&newAttribute)));
            return S_OK;
        }
        catch (...)
        {
            *previousAttribute = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAttributeNode(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlAttribute> attributeNode, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> removedAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *removedAttribute = detach_abi(this->shim().RemoveAttributeNode(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlAttribute *>(&attributeNode)));
            return S_OK;
        }
        catch (...)
        {
            *removedAttribute = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementsByTagName(impl::abi_arg_in<hstring> tagName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNodeList> elements) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *elements = detach_abi(this->shim().GetElementsByTagName(*reinterpret_cast<const hstring *>(&tagName)));
            return S_OK;
        }
        catch (...)
        {
            *elements = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAttributeNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> qualifiedName, impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAttributeNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&qualifiedName), *reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttributeNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> localName, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAttributeNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&localName)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAttributeNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> localName) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAttributeNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&localName));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAttributeNodeNS(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlAttribute> newAttribute, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> previousAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousAttribute = detach_abi(this->shim().SetAttributeNodeNS(*reinterpret_cast<const Windows::Data::Xml::Dom::XmlAttribute *>(&newAttribute)));
            return S_OK;
        }
        catch (...)
        {
            *previousAttribute = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAttributeNodeNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> localName, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlAttribute> previousAttribute) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousAttribute = detach_abi(this->shim().GetAttributeNodeNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&localName)));
            return S_OK;
        }
        catch (...)
        {
            *previousAttribute = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlEntityReference> : produce_base<D, Windows::Data::Xml::Dom::IXmlEntityReference>
{};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlLoadSettings> : produce_base<D, Windows::Data::Xml::Dom::IXmlLoadSettings>
{
    HRESULT __stdcall get_MaxElementDepth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxElementDepth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxElementDepth(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxElementDepth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProhibitDtd(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProhibitDtd());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProhibitDtd(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProhibitDtd(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResolveExternals(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResolveExternals());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ResolveExternals(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResolveExternals(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ValidateOnParse(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ValidateOnParse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ValidateOnParse(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValidateOnParse(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ElementContentWhiteSpace(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ElementContentWhiteSpace());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ElementContentWhiteSpace(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ElementContentWhiteSpace(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlNamedNodeMap> : produce_base<D, Windows::Data::Xml::Dom::IXmlNamedNodeMap>
{
    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Item(uint32_t index, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().Item(index));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedItem(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().GetNamedItem(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNamedItem(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> node, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> previousNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousNode = detach_abi(this->shim().SetNamedItem(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&node)));
            return S_OK;
        }
        catch (...)
        {
            *previousNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveNamedItem(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> previousNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousNode = detach_abi(this->shim().RemoveNamedItem(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *previousNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNamedItemNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().GetNamedItemNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveNamedItemNS(impl::abi_arg_in<Windows::Foundation::IInspectable> namespaceUri, impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> previousNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousNode = detach_abi(this->shim().RemoveNamedItemNS(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaceUri), *reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *previousNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNamedItemNS(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> node, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> previousNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousNode = detach_abi(this->shim().SetNamedItemNS(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&node)));
            return S_OK;
        }
        catch (...)
        {
            *previousNode = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlNode> : produce_base<D, Windows::Data::Xml::Dom::IXmlNode>
{
    HRESULT __stdcall get_NodeValue(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeValue());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NodeValue(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NodeValue(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NodeType(Windows::Data::Xml::Dom::NodeType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NodeName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NodeName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ParentNode(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ParentNode());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChildNodes(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNodeList> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChildNodes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirstChild(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirstChild());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastChild(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastChild());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousSibling(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousSibling());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NextSibling(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NextSibling());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Attributes(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNamedNodeMap> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Attributes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasChildNodes(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasChildNodes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OwnerDocument(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OwnerDocument());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_InsertBefore(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> newChild, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> referenceChild, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> insertedChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *insertedChild = detach_abi(this->shim().InsertBefore(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&newChild), *reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&referenceChild)));
            return S_OK;
        }
        catch (...)
        {
            *insertedChild = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReplaceChild(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> newChild, impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> referenceChild, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> previousChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *previousChild = detach_abi(this->shim().ReplaceChild(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&newChild), *reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&referenceChild)));
            return S_OK;
        }
        catch (...)
        {
            *previousChild = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveChild(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> childNode, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> removedChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *removedChild = detach_abi(this->shim().RemoveChild(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&childNode)));
            return S_OK;
        }
        catch (...)
        {
            *removedChild = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AppendChild(impl::abi_arg_in<Windows::Data::Xml::Dom::IXmlNode> newChild, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> appendedChild) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *appendedChild = detach_abi(this->shim().AppendChild(*reinterpret_cast<const Windows::Data::Xml::Dom::IXmlNode *>(&newChild)));
            return S_OK;
        }
        catch (...)
        {
            *appendedChild = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloneNode(bool deep, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> newNode) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *newNode = detach_abi(this->shim().CloneNode(deep));
            return S_OK;
        }
        catch (...)
        {
            *newNode = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NamespaceUri(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NamespaceUri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalName(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Prefix(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Prefix());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Normalize() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Normalize();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Prefix(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Prefix(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlNodeList> : produce_base<D, Windows::Data::Xml::Dom::IXmlNodeList>
{
    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Item(uint32_t index, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().Item(index));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlNodeSelector> : produce_base<D, Windows::Data::Xml::Dom::IXmlNodeSelector>
{
    HRESULT __stdcall abi_SelectSingleNode(impl::abi_arg_in<hstring> xpath, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().SelectSingleNode(*reinterpret_cast<const hstring *>(&xpath)));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectNodes(impl::abi_arg_in<hstring> xpath, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNodeList> nodelist) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nodelist = detach_abi(this->shim().SelectNodes(*reinterpret_cast<const hstring *>(&xpath)));
            return S_OK;
        }
        catch (...)
        {
            *nodelist = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectSingleNodeNS(impl::abi_arg_in<hstring> xpath, impl::abi_arg_in<Windows::Foundation::IInspectable> namespaces, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNode> node) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *node = detach_abi(this->shim().SelectSingleNodeNS(*reinterpret_cast<const hstring *>(&xpath), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaces)));
            return S_OK;
        }
        catch (...)
        {
            *node = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SelectNodesNS(impl::abi_arg_in<hstring> xpath, impl::abi_arg_in<Windows::Foundation::IInspectable> namespaces, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlNodeList> nodelist) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nodelist = detach_abi(this->shim().SelectNodesNS(*reinterpret_cast<const hstring *>(&xpath), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&namespaces)));
            return S_OK;
        }
        catch (...)
        {
            *nodelist = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlNodeSerializer> : produce_base<D, Windows::Data::Xml::Dom::IXmlNodeSerializer>
{
    HRESULT __stdcall abi_GetXml(impl::abi_arg_out<hstring> outerXml) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outerXml = detach_abi(this->shim().GetXml());
            return S_OK;
        }
        catch (...)
        {
            *outerXml = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InnerText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InnerText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InnerText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlProcessingInstruction> : produce_base<D, Windows::Data::Xml::Dom::IXmlProcessingInstruction>
{
    HRESULT __stdcall get_Target(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Target());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Data(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Data(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Xml::Dom::IXmlText> : produce_base<D, Windows::Data::Xml::Dom::IXmlText>
{
    HRESULT __stdcall abi_SplitText(uint32_t offset, impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlText> secondPart) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *secondPart = detach_abi(this->shim().SplitText(offset));
            return S_OK;
        }
        catch (...)
        {
            *secondPart = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Xml::Dom {

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNodeSelector<D>::SelectSingleNode(hstring_view xpath) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNodeSelector)->abi_SelectSingleNode(get_abi(xpath), put_abi(node)));
    return node;
}

template <typename D> Windows::Data::Xml::Dom::XmlNodeList impl_IXmlNodeSelector<D>::SelectNodes(hstring_view xpath) const
{
    Windows::Data::Xml::Dom::XmlNodeList nodelist { nullptr };
    check_hresult(WINRT_SHIM(IXmlNodeSelector)->abi_SelectNodes(get_abi(xpath), put_abi(nodelist)));
    return nodelist;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNodeSelector<D>::SelectSingleNodeNS(hstring_view xpath, const Windows::Foundation::IInspectable & namespaces) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNodeSelector)->abi_SelectSingleNodeNS(get_abi(xpath), get_abi(namespaces), put_abi(node)));
    return node;
}

template <typename D> Windows::Data::Xml::Dom::XmlNodeList impl_IXmlNodeSelector<D>::SelectNodesNS(hstring_view xpath, const Windows::Foundation::IInspectable & namespaces) const
{
    Windows::Data::Xml::Dom::XmlNodeList nodelist { nullptr };
    check_hresult(WINRT_SHIM(IXmlNodeSelector)->abi_SelectNodesNS(get_abi(xpath), get_abi(namespaces), put_abi(nodelist)));
    return nodelist;
}

template <typename D> hstring impl_IXmlNodeSerializer<D>::GetXml() const
{
    hstring outerXml;
    check_hresult(WINRT_SHIM(IXmlNodeSerializer)->abi_GetXml(put_abi(outerXml)));
    return outerXml;
}

template <typename D> hstring impl_IXmlNodeSerializer<D>::InnerText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlNodeSerializer)->get_InnerText(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlNodeSerializer<D>::InnerText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXmlNodeSerializer)->put_InnerText(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IXmlNode<D>::NodeValue() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_NodeValue(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlNode<D>::NodeValue(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXmlNode)->put_NodeValue(get_abi(value)));
}

template <typename D> Windows::Data::Xml::Dom::NodeType impl_IXmlNode<D>::NodeType() const
{
    Windows::Data::Xml::Dom::NodeType value {};
    check_hresult(WINRT_SHIM(IXmlNode)->get_NodeType(&value));
    return value;
}

template <typename D> hstring impl_IXmlNode<D>::NodeName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_NodeName(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::ParentNode() const
{
    Windows::Data::Xml::Dom::IXmlNode value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_ParentNode(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlNodeList impl_IXmlNode<D>::ChildNodes() const
{
    Windows::Data::Xml::Dom::XmlNodeList value { nullptr };
    check_hresult(WINRT_SHIM(IXmlNode)->get_ChildNodes(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::FirstChild() const
{
    Windows::Data::Xml::Dom::IXmlNode value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_FirstChild(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::LastChild() const
{
    Windows::Data::Xml::Dom::IXmlNode value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_LastChild(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::PreviousSibling() const
{
    Windows::Data::Xml::Dom::IXmlNode value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_PreviousSibling(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::NextSibling() const
{
    Windows::Data::Xml::Dom::IXmlNode value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_NextSibling(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlNamedNodeMap impl_IXmlNode<D>::Attributes() const
{
    Windows::Data::Xml::Dom::XmlNamedNodeMap value { nullptr };
    check_hresult(WINRT_SHIM(IXmlNode)->get_Attributes(put_abi(value)));
    return value;
}

template <typename D> bool impl_IXmlNode<D>::HasChildNodes() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlNode)->abi_HasChildNodes(&value));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IXmlNode<D>::OwnerDocument() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IXmlNode)->get_OwnerDocument(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::InsertBefore(const Windows::Data::Xml::Dom::IXmlNode & newChild, const Windows::Data::Xml::Dom::IXmlNode & referenceChild) const
{
    Windows::Data::Xml::Dom::IXmlNode insertedChild;
    check_hresult(WINRT_SHIM(IXmlNode)->abi_InsertBefore(get_abi(newChild), get_abi(referenceChild), put_abi(insertedChild)));
    return insertedChild;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::ReplaceChild(const Windows::Data::Xml::Dom::IXmlNode & newChild, const Windows::Data::Xml::Dom::IXmlNode & referenceChild) const
{
    Windows::Data::Xml::Dom::IXmlNode previousChild;
    check_hresult(WINRT_SHIM(IXmlNode)->abi_ReplaceChild(get_abi(newChild), get_abi(referenceChild), put_abi(previousChild)));
    return previousChild;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::RemoveChild(const Windows::Data::Xml::Dom::IXmlNode & childNode) const
{
    Windows::Data::Xml::Dom::IXmlNode removedChild;
    check_hresult(WINRT_SHIM(IXmlNode)->abi_RemoveChild(get_abi(childNode), put_abi(removedChild)));
    return removedChild;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::AppendChild(const Windows::Data::Xml::Dom::IXmlNode & newChild) const
{
    Windows::Data::Xml::Dom::IXmlNode appendedChild;
    check_hresult(WINRT_SHIM(IXmlNode)->abi_AppendChild(get_abi(newChild), put_abi(appendedChild)));
    return appendedChild;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNode<D>::CloneNode(bool deep) const
{
    Windows::Data::Xml::Dom::IXmlNode newNode;
    check_hresult(WINRT_SHIM(IXmlNode)->abi_CloneNode(deep, put_abi(newNode)));
    return newNode;
}

template <typename D> Windows::Foundation::IInspectable impl_IXmlNode<D>::NamespaceUri() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_NamespaceUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IXmlNode<D>::LocalName() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_LocalName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IXmlNode<D>::Prefix() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IXmlNode)->get_Prefix(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlNode<D>::Normalize() const
{
    check_hresult(WINRT_SHIM(IXmlNode)->abi_Normalize());
}

template <typename D> void impl_IXmlNode<D>::Prefix(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IXmlNode)->put_Prefix(get_abi(value)));
}

template <typename D> bool impl_IXmlDomImplementation<D>::HasFeature(hstring_view feature, const Windows::Foundation::IInspectable & version) const
{
    bool featureSupported {};
    check_hresult(WINRT_SHIM(IXmlDomImplementation)->abi_HasFeature(get_abi(feature), get_abi(version), &featureSupported));
    return featureSupported;
}

template <typename D> hstring impl_IXmlDocumentType<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlDocumentType)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlNamedNodeMap impl_IXmlDocumentType<D>::Entities() const
{
    Windows::Data::Xml::Dom::XmlNamedNodeMap value { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocumentType)->get_Entities(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlNamedNodeMap impl_IXmlDocumentType<D>::Notations() const
{
    Windows::Data::Xml::Dom::XmlNamedNodeMap value { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocumentType)->get_Notations(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IXmlAttribute<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlAttribute)->get_Name(put_abi(value)));
    return value;
}

template <typename D> bool impl_IXmlAttribute<D>::Specified() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlAttribute)->get_Specified(&value));
    return value;
}

template <typename D> hstring impl_IXmlAttribute<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlAttribute)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlAttribute<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXmlAttribute)->put_Value(get_abi(value)));
}

template <typename D> hstring impl_IXmlElement<D>::TagName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlElement)->get_TagName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IXmlElement<D>::GetAttribute(hstring_view attributeName) const
{
    hstring attributeValue;
    check_hresult(WINRT_SHIM(IXmlElement)->abi_GetAttribute(get_abi(attributeName), put_abi(attributeValue)));
    return attributeValue;
}

template <typename D> void impl_IXmlElement<D>::SetAttribute(hstring_view attributeName, hstring_view attributeValue) const
{
    check_hresult(WINRT_SHIM(IXmlElement)->abi_SetAttribute(get_abi(attributeName), get_abi(attributeValue)));
}

template <typename D> void impl_IXmlElement<D>::RemoveAttribute(hstring_view attributeName) const
{
    check_hresult(WINRT_SHIM(IXmlElement)->abi_RemoveAttribute(get_abi(attributeName)));
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlElement<D>::GetAttributeNode(hstring_view attributeName) const
{
    Windows::Data::Xml::Dom::XmlAttribute attributeNode { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_GetAttributeNode(get_abi(attributeName), put_abi(attributeNode)));
    return attributeNode;
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlElement<D>::SetAttributeNode(const Windows::Data::Xml::Dom::XmlAttribute & newAttribute) const
{
    Windows::Data::Xml::Dom::XmlAttribute previousAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_SetAttributeNode(get_abi(newAttribute), put_abi(previousAttribute)));
    return previousAttribute;
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlElement<D>::RemoveAttributeNode(const Windows::Data::Xml::Dom::XmlAttribute & attributeNode) const
{
    Windows::Data::Xml::Dom::XmlAttribute removedAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_RemoveAttributeNode(get_abi(attributeNode), put_abi(removedAttribute)));
    return removedAttribute;
}

template <typename D> Windows::Data::Xml::Dom::XmlNodeList impl_IXmlElement<D>::GetElementsByTagName(hstring_view tagName) const
{
    Windows::Data::Xml::Dom::XmlNodeList elements { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_GetElementsByTagName(get_abi(tagName), put_abi(elements)));
    return elements;
}

template <typename D> void impl_IXmlElement<D>::SetAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName, hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXmlElement)->abi_SetAttributeNS(get_abi(namespaceUri), get_abi(qualifiedName), get_abi(value)));
}

template <typename D> hstring impl_IXmlElement<D>::GetAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlElement)->abi_GetAttributeNS(get_abi(namespaceUri), get_abi(localName), put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlElement<D>::RemoveAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const
{
    check_hresult(WINRT_SHIM(IXmlElement)->abi_RemoveAttributeNS(get_abi(namespaceUri), get_abi(localName)));
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlElement<D>::SetAttributeNodeNS(const Windows::Data::Xml::Dom::XmlAttribute & newAttribute) const
{
    Windows::Data::Xml::Dom::XmlAttribute previousAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_SetAttributeNodeNS(get_abi(newAttribute), put_abi(previousAttribute)));
    return previousAttribute;
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlElement<D>::GetAttributeNodeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view localName) const
{
    Windows::Data::Xml::Dom::XmlAttribute previousAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlElement)->abi_GetAttributeNodeNS(get_abi(namespaceUri), get_abi(localName), put_abi(previousAttribute)));
    return previousAttribute;
}

template <typename D> Windows::Foundation::IInspectable impl_IDtdNotation<D>::PublicId() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDtdNotation)->get_PublicId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDtdNotation<D>::SystemId() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDtdNotation)->get_SystemId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDtdEntity<D>::PublicId() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDtdEntity)->get_PublicId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDtdEntity<D>::SystemId() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDtdEntity)->get_SystemId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IDtdEntity<D>::NotationName() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IDtdEntity)->get_NotationName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IXmlProcessingInstruction<D>::Target() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlProcessingInstruction)->get_Target(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IXmlProcessingInstruction<D>::Data() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlProcessingInstruction)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlProcessingInstruction<D>::Data(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXmlProcessingInstruction)->put_Data(get_abi(value)));
}

template <typename D> hstring impl_IXmlCharacterData<D>::Data() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlCharacterData)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_IXmlCharacterData<D>::Data(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IXmlCharacterData)->put_Data(get_abi(value)));
}

template <typename D> uint32_t impl_IXmlCharacterData<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IXmlCharacterData)->get_Length(&value));
    return value;
}

template <typename D> hstring impl_IXmlCharacterData<D>::SubstringData(uint32_t offset, uint32_t count) const
{
    hstring data;
    check_hresult(WINRT_SHIM(IXmlCharacterData)->abi_SubstringData(offset, count, put_abi(data)));
    return data;
}

template <typename D> void impl_IXmlCharacterData<D>::AppendData(hstring_view data) const
{
    check_hresult(WINRT_SHIM(IXmlCharacterData)->abi_AppendData(get_abi(data)));
}

template <typename D> void impl_IXmlCharacterData<D>::InsertData(uint32_t offset, hstring_view data) const
{
    check_hresult(WINRT_SHIM(IXmlCharacterData)->abi_InsertData(offset, get_abi(data)));
}

template <typename D> void impl_IXmlCharacterData<D>::DeleteData(uint32_t offset, uint32_t count) const
{
    check_hresult(WINRT_SHIM(IXmlCharacterData)->abi_DeleteData(offset, count));
}

template <typename D> void impl_IXmlCharacterData<D>::ReplaceData(uint32_t offset, uint32_t count, hstring_view data) const
{
    check_hresult(WINRT_SHIM(IXmlCharacterData)->abi_ReplaceData(offset, count, get_abi(data)));
}

template <typename D> Windows::Data::Xml::Dom::IXmlText impl_IXmlText<D>::SplitText(uint32_t offset) const
{
    Windows::Data::Xml::Dom::IXmlText secondPart;
    check_hresult(WINRT_SHIM(IXmlText)->abi_SplitText(offset, put_abi(secondPart)));
    return secondPart;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocumentType impl_IXmlDocument<D>::Doctype() const
{
    Windows::Data::Xml::Dom::XmlDocumentType value { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->get_Doctype(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlDomImplementation impl_IXmlDocument<D>::Implementation() const
{
    Windows::Data::Xml::Dom::XmlDomImplementation value { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->get_Implementation(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlElement impl_IXmlDocument<D>::DocumentElement() const
{
    Windows::Data::Xml::Dom::XmlElement value { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->get_DocumentElement(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlElement impl_IXmlDocument<D>::CreateElement(hstring_view tagName) const
{
    Windows::Data::Xml::Dom::XmlElement newElement { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateElement(get_abi(tagName), put_abi(newElement)));
    return newElement;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocumentFragment impl_IXmlDocument<D>::CreateDocumentFragment() const
{
    Windows::Data::Xml::Dom::XmlDocumentFragment newDocumentFragment { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateDocumentFragment(put_abi(newDocumentFragment)));
    return newDocumentFragment;
}

template <typename D> Windows::Data::Xml::Dom::XmlText impl_IXmlDocument<D>::CreateTextNode(hstring_view data) const
{
    Windows::Data::Xml::Dom::XmlText newTextNode { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateTextNode(get_abi(data), put_abi(newTextNode)));
    return newTextNode;
}

template <typename D> Windows::Data::Xml::Dom::XmlComment impl_IXmlDocument<D>::CreateComment(hstring_view data) const
{
    Windows::Data::Xml::Dom::XmlComment newComment { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateComment(get_abi(data), put_abi(newComment)));
    return newComment;
}

template <typename D> Windows::Data::Xml::Dom::XmlProcessingInstruction impl_IXmlDocument<D>::CreateProcessingInstruction(hstring_view target, hstring_view data) const
{
    Windows::Data::Xml::Dom::XmlProcessingInstruction newProcessingInstruction { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateProcessingInstruction(get_abi(target), get_abi(data), put_abi(newProcessingInstruction)));
    return newProcessingInstruction;
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlDocument<D>::CreateAttribute(hstring_view name) const
{
    Windows::Data::Xml::Dom::XmlAttribute newAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateAttribute(get_abi(name), put_abi(newAttribute)));
    return newAttribute;
}

template <typename D> Windows::Data::Xml::Dom::XmlEntityReference impl_IXmlDocument<D>::CreateEntityReference(hstring_view name) const
{
    Windows::Data::Xml::Dom::XmlEntityReference newEntityReference { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateEntityReference(get_abi(name), put_abi(newEntityReference)));
    return newEntityReference;
}

template <typename D> Windows::Data::Xml::Dom::XmlNodeList impl_IXmlDocument<D>::GetElementsByTagName(hstring_view tagName) const
{
    Windows::Data::Xml::Dom::XmlNodeList elements { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_GetElementsByTagName(get_abi(tagName), put_abi(elements)));
    return elements;
}

template <typename D> Windows::Data::Xml::Dom::XmlCDataSection impl_IXmlDocument<D>::CreateCDataSection(hstring_view data) const
{
    Windows::Data::Xml::Dom::XmlCDataSection newCDataSection { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateCDataSection(get_abi(data), put_abi(newCDataSection)));
    return newCDataSection;
}

template <typename D> hstring impl_IXmlDocument<D>::DocumentUri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IXmlDocument)->get_DocumentUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlAttribute impl_IXmlDocument<D>::CreateAttributeNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName) const
{
    Windows::Data::Xml::Dom::XmlAttribute newAttribute { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateAttributeNS(get_abi(namespaceUri), get_abi(qualifiedName), put_abi(newAttribute)));
    return newAttribute;
}

template <typename D> Windows::Data::Xml::Dom::XmlElement impl_IXmlDocument<D>::CreateElementNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view qualifiedName) const
{
    Windows::Data::Xml::Dom::XmlElement newElement { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_CreateElementNS(get_abi(namespaceUri), get_abi(qualifiedName), put_abi(newElement)));
    return newElement;
}

template <typename D> Windows::Data::Xml::Dom::XmlElement impl_IXmlDocument<D>::GetElementById(hstring_view elementId) const
{
    Windows::Data::Xml::Dom::XmlElement element { nullptr };
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_GetElementById(get_abi(elementId), put_abi(element)));
    return element;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlDocument<D>::ImportNode(const Windows::Data::Xml::Dom::IXmlNode & node, bool deep) const
{
    Windows::Data::Xml::Dom::IXmlNode newNode;
    check_hresult(WINRT_SHIM(IXmlDocument)->abi_ImportNode(get_abi(node), deep, put_abi(newNode)));
    return newNode;
}

template <typename D> uint32_t impl_IXmlNamedNodeMap<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->get_Length(&value));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::Item(uint32_t index) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_Item(index, put_abi(node)));
    return node;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::GetNamedItem(hstring_view name) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_GetNamedItem(get_abi(name), put_abi(node)));
    return node;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::SetNamedItem(const Windows::Data::Xml::Dom::IXmlNode & node) const
{
    Windows::Data::Xml::Dom::IXmlNode previousNode;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_SetNamedItem(get_abi(node), put_abi(previousNode)));
    return previousNode;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::RemoveNamedItem(hstring_view name) const
{
    Windows::Data::Xml::Dom::IXmlNode previousNode;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_RemoveNamedItem(get_abi(name), put_abi(previousNode)));
    return previousNode;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::GetNamedItemNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view name) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_GetNamedItemNS(get_abi(namespaceUri), get_abi(name), put_abi(node)));
    return node;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::RemoveNamedItemNS(const Windows::Foundation::IInspectable & namespaceUri, hstring_view name) const
{
    Windows::Data::Xml::Dom::IXmlNode previousNode;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_RemoveNamedItemNS(get_abi(namespaceUri), get_abi(name), put_abi(previousNode)));
    return previousNode;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNamedNodeMap<D>::SetNamedItemNS(const Windows::Data::Xml::Dom::IXmlNode & node) const
{
    Windows::Data::Xml::Dom::IXmlNode previousNode;
    check_hresult(WINRT_SHIM(IXmlNamedNodeMap)->abi_SetNamedItemNS(get_abi(node), put_abi(previousNode)));
    return previousNode;
}

template <typename D> uint32_t impl_IXmlNodeList<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IXmlNodeList)->get_Length(&value));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::IXmlNode impl_IXmlNodeList<D>::Item(uint32_t index) const
{
    Windows::Data::Xml::Dom::IXmlNode node;
    check_hresult(WINRT_SHIM(IXmlNodeList)->abi_Item(index, put_abi(node)));
    return node;
}

template <typename D> uint32_t impl_IXmlLoadSettings<D>::MaxElementDepth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->get_MaxElementDepth(&value));
    return value;
}

template <typename D> void impl_IXmlLoadSettings<D>::MaxElementDepth(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->put_MaxElementDepth(value));
}

template <typename D> bool impl_IXmlLoadSettings<D>::ProhibitDtd() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->get_ProhibitDtd(&value));
    return value;
}

template <typename D> void impl_IXmlLoadSettings<D>::ProhibitDtd(bool value) const
{
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->put_ProhibitDtd(value));
}

template <typename D> bool impl_IXmlLoadSettings<D>::ResolveExternals() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->get_ResolveExternals(&value));
    return value;
}

template <typename D> void impl_IXmlLoadSettings<D>::ResolveExternals(bool value) const
{
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->put_ResolveExternals(value));
}

template <typename D> bool impl_IXmlLoadSettings<D>::ValidateOnParse() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->get_ValidateOnParse(&value));
    return value;
}

template <typename D> void impl_IXmlLoadSettings<D>::ValidateOnParse(bool value) const
{
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->put_ValidateOnParse(value));
}

template <typename D> bool impl_IXmlLoadSettings<D>::ElementContentWhiteSpace() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->get_ElementContentWhiteSpace(&value));
    return value;
}

template <typename D> void impl_IXmlLoadSettings<D>::ElementContentWhiteSpace(bool value) const
{
    check_hresult(WINRT_SHIM(IXmlLoadSettings)->put_ElementContentWhiteSpace(value));
}

template <typename D> void impl_IXmlDocumentIO<D>::LoadXml(hstring_view xml) const
{
    check_hresult(WINRT_SHIM(IXmlDocumentIO)->abi_LoadXml(get_abi(xml)));
}

template <typename D> void impl_IXmlDocumentIO<D>::LoadXml(hstring_view xml, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const
{
    check_hresult(WINRT_SHIM(IXmlDocumentIO)->abi_LoadXmlWithSettings(get_abi(xml), get_abi(loadSettings)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IXmlDocumentIO<D>::SaveToFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IXmlDocumentIO)->abi_SaveToFileAsync(get_abi(file), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IXmlDocumentIO2<D>::LoadXmlFromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IXmlDocumentIO2)->abi_LoadXmlFromBuffer(get_abi(buffer)));
}

template <typename D> void impl_IXmlDocumentIO2<D>::LoadXmlFromBuffer(const Windows::Storage::Streams::IBuffer & buffer, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const
{
    check_hresult(WINRT_SHIM(IXmlDocumentIO2)->abi_LoadXmlFromBufferWithSettings(get_abi(buffer), get_abi(loadSettings)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> impl_IXmlDocumentStatics<D>::LoadFromUriAsync(const Windows::Foundation::Uri & uri) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IXmlDocumentStatics)->abi_LoadFromUriAsync(get_abi(uri), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> impl_IXmlDocumentStatics<D>::LoadFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IXmlDocumentStatics)->abi_LoadFromUriWithSettingsAsync(get_abi(uri), get_abi(loadSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> impl_IXmlDocumentStatics<D>::LoadFromFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IXmlDocumentStatics)->abi_LoadFromFileAsync(get_abi(file), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> impl_IXmlDocumentStatics<D>::LoadFromFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IXmlDocumentStatics)->abi_LoadFromFileWithSettingsAsync(get_abi(file), get_abi(loadSettings), put_abi(asyncInfo)));
    return asyncInfo;
}

inline XmlDocument::XmlDocument() :
    XmlDocument(activate_instance<XmlDocument>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> XmlDocument::LoadFromUriAsync(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<XmlDocument, IXmlDocumentStatics>().LoadFromUriAsync(uri);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> XmlDocument::LoadFromUriAsync(const Windows::Foundation::Uri & uri, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings)
{
    return get_activation_factory<XmlDocument, IXmlDocumentStatics>().LoadFromUriAsync(uri, loadSettings);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> XmlDocument::LoadFromFileAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<XmlDocument, IXmlDocumentStatics>().LoadFromFileAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Xml::Dom::XmlDocument> XmlDocument::LoadFromFileAsync(const Windows::Storage::IStorageFile & file, const Windows::Data::Xml::Dom::XmlLoadSettings & loadSettings)
{
    return get_activation_factory<XmlDocument, IXmlDocumentStatics>().LoadFromFileAsync(file, loadSettings);
}

inline XmlLoadSettings::XmlLoadSettings() :
    XmlLoadSettings(activate_instance<XmlLoadSettings>())
{}

}

}
#pragma warning(pop)
