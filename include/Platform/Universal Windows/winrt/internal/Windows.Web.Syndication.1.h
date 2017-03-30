// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Web.Syndication.0.h"
#include "Windows.Data.Xml.Dom.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Syndication {

struct RetrievalProgress
{
    uint32_t BytesRetrieved;
    uint32_t TotalBytesToRetrieve;
};

struct TransferProgress
{
    uint32_t BytesSent;
    uint32_t TotalBytesToSend;
    uint32_t BytesRetrieved;
    uint32_t TotalBytesToRetrieve;
};

}

namespace Windows::Web::Syndication {

using RetrievalProgress = ABI::Windows::Web::Syndication::RetrievalProgress;
using TransferProgress = ABI::Windows::Web::Syndication::TransferProgress;

}

namespace ABI::Windows::Web::Syndication {

struct __declspec(uuid("71e8f969-526e-4001-9a91-e84f83161ab1")) __declspec(novtable) ISyndicationAttribute : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Namespace(hstring * value) = 0;
    virtual HRESULT __stdcall put_Namespace(hstring value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("624f1599-ed3e-420f-be86-640414886e4b")) __declspec(novtable) ISyndicationAttributeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationAttribute(hstring attributeName, hstring attributeNamespace, hstring attributeValue, Windows::Web::Syndication::ISyndicationAttribute ** syndicationAttribute) = 0;
};

struct __declspec(uuid("8715626f-0cba-4a7f-89ff-ecb5281423b6")) __declspec(novtable) ISyndicationCategory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Scheme(hstring * value) = 0;
    virtual HRESULT __stdcall put_Scheme(hstring value) = 0;
    virtual HRESULT __stdcall get_Term(hstring * value) = 0;
    virtual HRESULT __stdcall put_Term(hstring value) = 0;
};

struct __declspec(uuid("ab42802f-49e0-4525-8ab2-ab45c02528ff")) __declspec(novtable) ISyndicationCategoryFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationCategory(hstring term, Windows::Web::Syndication::ISyndicationCategory ** category) = 0;
    virtual HRESULT __stdcall abi_CreateSyndicationCategoryEx(hstring term, hstring scheme, hstring label, Windows::Web::Syndication::ISyndicationCategory ** category) = 0;
};

struct __declspec(uuid("9e18a9b7-7249-4b45-b229-7df895a5a1f5")) __declspec(novtable) ISyndicationClient : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ServerCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_ProxyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_ProxyCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_MaxResponseBufferSize(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_MaxResponseBufferSize(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Timeout(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Timeout(uint32_t value) = 0;
    virtual HRESULT __stdcall get_BypassCacheOnRetrieve(bool * value) = 0;
    virtual HRESULT __stdcall put_BypassCacheOnRetrieve(bool value) = 0;
    virtual HRESULT __stdcall abi_SetRequestHeader(hstring name, hstring value) = 0;
    virtual HRESULT __stdcall abi_RetrieveFeedAsync(Windows::Foundation::IUriRuntimeClass * uri, Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress> ** operation) = 0;
};

struct __declspec(uuid("2ec4b32c-a79b-4114-b29a-05dffbafb9a4")) __declspec(novtable) ISyndicationClientFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationClient(Windows::Security::Credentials::IPasswordCredential * serverCredential, Windows::Web::Syndication::ISyndicationClient ** syndicationClient) = 0;
};

struct __declspec(uuid("4641fefe-0e55-40d0-b8d0-6a2ccba9fc7c")) __declspec(novtable) ISyndicationContent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_SourceUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("3d2fbb93-9520-4173-9388-7e2df324a8a0")) __declspec(novtable) ISyndicationContentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationContent(hstring text, winrt::Windows::Web::Syndication::SyndicationTextType type, Windows::Web::Syndication::ISyndicationContent ** content) = 0;
    virtual HRESULT __stdcall abi_CreateSyndicationContentWithSourceUri(Windows::Foundation::IUriRuntimeClass * sourceUri, Windows::Web::Syndication::ISyndicationContent ** content) = 0;
};

struct __declspec(uuid("1fbb2361-45c7-4833-8aa0-be5f3b58a7f4")) __declspec(novtable) ISyndicationErrorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetStatus(int32_t hresult, winrt::Windows::Web::Syndication::SyndicationErrorStatus * status) = 0;
};

struct __declspec(uuid("7ffe3cd2-5b66-4d62-8403-1bc10d910d6b")) __declspec(novtable) ISyndicationFeed : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Authors(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> ** value) = 0;
    virtual HRESULT __stdcall get_Categories(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> ** value) = 0;
    virtual HRESULT __stdcall get_Contributors(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> ** value) = 0;
    virtual HRESULT __stdcall get_Generator(Windows::Web::Syndication::ISyndicationGenerator ** value) = 0;
    virtual HRESULT __stdcall put_Generator(Windows::Web::Syndication::ISyndicationGenerator * value) = 0;
    virtual HRESULT __stdcall get_IconUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_IconUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_Items(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationItem> ** value) = 0;
    virtual HRESULT __stdcall get_LastUpdatedTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_LastUpdatedTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Links(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> ** value) = 0;
    virtual HRESULT __stdcall get_ImageUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_ImageUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_Rights(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Rights(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_Subtitle(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Subtitle(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_Title(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Title(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_FirstUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_LastUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_NextUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_PreviousUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_SourceFormat(winrt::Windows::Web::Syndication::SyndicationFormat * value) = 0;
    virtual HRESULT __stdcall abi_Load(hstring feed) = 0;
    virtual HRESULT __stdcall abi_LoadFromXml(Windows::Data::Xml::Dom::IXmlDocument * feedDocument) = 0;
};

struct __declspec(uuid("23472232-8be9-48b7-8934-6205131d9357")) __declspec(novtable) ISyndicationFeedFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationFeed(hstring title, hstring subtitle, Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Syndication::ISyndicationFeed ** feed) = 0;
};

struct __declspec(uuid("9768b379-fb2b-4f6d-b41c-088a5868825c")) __declspec(novtable) ISyndicationGenerator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_Version(hstring * value) = 0;
    virtual HRESULT __stdcall put_Version(hstring value) = 0;
};

struct __declspec(uuid("a34083e3-1e26-4dbc-ba9d-1ab84beff97b")) __declspec(novtable) ISyndicationGeneratorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationGenerator(hstring text, Windows::Web::Syndication::ISyndicationGenerator ** generator) = 0;
};

struct __declspec(uuid("548db883-c384-45c1-8ae8-a378c4ec486c")) __declspec(novtable) ISyndicationItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Authors(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> ** value) = 0;
    virtual HRESULT __stdcall get_Categories(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> ** value) = 0;
    virtual HRESULT __stdcall get_Contributors(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> ** value) = 0;
    virtual HRESULT __stdcall get_Content(Windows::Web::Syndication::ISyndicationContent ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::Web::Syndication::ISyndicationContent * value) = 0;
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_LastUpdatedTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_LastUpdatedTime(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Links(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> ** value) = 0;
    virtual HRESULT __stdcall get_PublishedDate(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall put_PublishedDate(Windows::Foundation::DateTime value) = 0;
    virtual HRESULT __stdcall get_Rights(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Rights(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Web::Syndication::ISyndicationFeed ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Web::Syndication::ISyndicationFeed * value) = 0;
    virtual HRESULT __stdcall get_Summary(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Summary(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_Title(Windows::Web::Syndication::ISyndicationText ** value) = 0;
    virtual HRESULT __stdcall put_Title(Windows::Web::Syndication::ISyndicationText * value) = 0;
    virtual HRESULT __stdcall get_CommentsUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_CommentsUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_EditUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_EditMediaUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_ETag(hstring * value) = 0;
    virtual HRESULT __stdcall get_ItemUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall abi_Load(hstring item) = 0;
    virtual HRESULT __stdcall abi_LoadFromXml(Windows::Data::Xml::Dom::IXmlDocument * itemDocument) = 0;
};

struct __declspec(uuid("251d434f-7db8-487a-85e4-10d191e66ebb")) __declspec(novtable) ISyndicationItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationItem(hstring title, Windows::Web::Syndication::ISyndicationContent * content, Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Syndication::ISyndicationItem ** item) = 0;
};

struct __declspec(uuid("27553abd-a10e-41b5-86bd-9759086eb0c5")) __declspec(novtable) ISyndicationLink : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Length(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MediaType(hstring * value) = 0;
    virtual HRESULT __stdcall put_MediaType(hstring value) = 0;
    virtual HRESULT __stdcall get_Relationship(hstring * value) = 0;
    virtual HRESULT __stdcall put_Relationship(hstring value) = 0;
    virtual HRESULT __stdcall get_Title(hstring * value) = 0;
    virtual HRESULT __stdcall put_Title(hstring value) = 0;
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ResourceLanguage(hstring * value) = 0;
    virtual HRESULT __stdcall put_ResourceLanguage(hstring value) = 0;
};

struct __declspec(uuid("5ed863d4-5535-48ac-98d4-c190995080b3")) __declspec(novtable) ISyndicationLinkFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationLink(Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Syndication::ISyndicationLink ** link) = 0;
    virtual HRESULT __stdcall abi_CreateSyndicationLinkEx(Windows::Foundation::IUriRuntimeClass * uri, hstring relationship, hstring title, hstring mediaType, uint32_t length, Windows::Web::Syndication::ISyndicationLink ** link) = 0;
};

struct __declspec(uuid("753cef78-51f8-45c0-a9f5-f1719dec3fb2")) __declspec(novtable) ISyndicationNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NodeName(hstring * value) = 0;
    virtual HRESULT __stdcall put_NodeName(hstring value) = 0;
    virtual HRESULT __stdcall get_NodeNamespace(hstring * value) = 0;
    virtual HRESULT __stdcall put_NodeNamespace(hstring value) = 0;
    virtual HRESULT __stdcall get_NodeValue(hstring * value) = 0;
    virtual HRESULT __stdcall put_NodeValue(hstring value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall put_Language(hstring value) = 0;
    virtual HRESULT __stdcall get_BaseUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_BaseUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_AttributeExtensions(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationAttribute> ** value) = 0;
    virtual HRESULT __stdcall get_ElementExtensions(Windows::Foundation::Collections::IVector<Windows::Web::Syndication::ISyndicationNode> ** value) = 0;
    virtual HRESULT __stdcall abi_GetXmlDocument(winrt::Windows::Web::Syndication::SyndicationFormat format, Windows::Data::Xml::Dom::IXmlDocument ** xmlDocument) = 0;
};

struct __declspec(uuid("12902188-4acb-49a8-b777-a5eb92e18a79")) __declspec(novtable) ISyndicationNodeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationNode(hstring nodeName, hstring nodeNamespace, hstring nodeValue, Windows::Web::Syndication::ISyndicationNode ** node) = 0;
};

struct __declspec(uuid("fa1ee5da-a7c6-4517-a096-0143faf29327")) __declspec(novtable) ISyndicationPerson : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Email(hstring * value) = 0;
    virtual HRESULT __stdcall put_Email(hstring value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Uri(Windows::Foundation::IUriRuntimeClass * value) = 0;
};

struct __declspec(uuid("dcf4886d-229d-4b58-a49b-f3d2f0f5c99f")) __declspec(novtable) ISyndicationPersonFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationPerson(hstring name, Windows::Web::Syndication::ISyndicationPerson ** person) = 0;
    virtual HRESULT __stdcall abi_CreateSyndicationPersonEx(hstring name, hstring email, Windows::Foundation::IUriRuntimeClass * uri, Windows::Web::Syndication::ISyndicationPerson ** person) = 0;
};

struct __declspec(uuid("b9cc5e80-313a-4091-a2a6-243e0ee923f9")) __declspec(novtable) ISyndicationText : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Type(hstring * value) = 0;
    virtual HRESULT __stdcall put_Type(hstring value) = 0;
    virtual HRESULT __stdcall get_Xml(Windows::Data::Xml::Dom::IXmlDocument ** value) = 0;
    virtual HRESULT __stdcall put_Xml(Windows::Data::Xml::Dom::IXmlDocument * value) = 0;
};

struct __declspec(uuid("ee7342f7-11c6-4b25-ab62-e596bd162946")) __declspec(novtable) ISyndicationTextFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateSyndicationText(hstring text, Windows::Web::Syndication::ISyndicationText ** syndicationText) = 0;
    virtual HRESULT __stdcall abi_CreateSyndicationTextEx(hstring text, winrt::Windows::Web::Syndication::SyndicationTextType type, Windows::Web::Syndication::ISyndicationText ** syndicationText) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Web::Syndication::SyndicationAttribute> { using default_interface = Windows::Web::Syndication::ISyndicationAttribute; };
template <> struct traits<Windows::Web::Syndication::SyndicationCategory> { using default_interface = Windows::Web::Syndication::ISyndicationCategory; };
template <> struct traits<Windows::Web::Syndication::SyndicationClient> { using default_interface = Windows::Web::Syndication::ISyndicationClient; };
template <> struct traits<Windows::Web::Syndication::SyndicationContent> { using default_interface = Windows::Web::Syndication::ISyndicationContent; };
template <> struct traits<Windows::Web::Syndication::SyndicationFeed> { using default_interface = Windows::Web::Syndication::ISyndicationFeed; };
template <> struct traits<Windows::Web::Syndication::SyndicationGenerator> { using default_interface = Windows::Web::Syndication::ISyndicationGenerator; };
template <> struct traits<Windows::Web::Syndication::SyndicationItem> { using default_interface = Windows::Web::Syndication::ISyndicationItem; };
template <> struct traits<Windows::Web::Syndication::SyndicationLink> { using default_interface = Windows::Web::Syndication::ISyndicationLink; };
template <> struct traits<Windows::Web::Syndication::SyndicationNode> { using default_interface = Windows::Web::Syndication::ISyndicationNode; };
template <> struct traits<Windows::Web::Syndication::SyndicationPerson> { using default_interface = Windows::Web::Syndication::ISyndicationPerson; };
template <> struct traits<Windows::Web::Syndication::SyndicationText> { using default_interface = Windows::Web::Syndication::ISyndicationText; };

}

namespace Windows::Web::Syndication {

template <typename D>
struct WINRT_EBO impl_ISyndicationAttribute
{
    hstring Name() const;
    void Name(hstring_view value) const;
    hstring Namespace() const;
    void Namespace(hstring_view value) const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationAttributeFactory
{
    Windows::Web::Syndication::SyndicationAttribute CreateSyndicationAttribute(hstring_view attributeName, hstring_view attributeNamespace, hstring_view attributeValue) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationCategory
{
    hstring Label() const;
    void Label(hstring_view value) const;
    hstring Scheme() const;
    void Scheme(hstring_view value) const;
    hstring Term() const;
    void Term(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationCategoryFactory
{
    Windows::Web::Syndication::SyndicationCategory CreateSyndicationCategory(hstring_view term) const;
    Windows::Web::Syndication::SyndicationCategory CreateSyndicationCategoryEx(hstring_view term, hstring_view scheme, hstring_view label) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationClient
{
    Windows::Security::Credentials::PasswordCredential ServerCredential() const;
    void ServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Security::Credentials::PasswordCredential ProxyCredential() const;
    void ProxyCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    uint32_t MaxResponseBufferSize() const;
    void MaxResponseBufferSize(uint32_t value) const;
    uint32_t Timeout() const;
    void Timeout(uint32_t value) const;
    bool BypassCacheOnRetrieve() const;
    void BypassCacheOnRetrieve(bool value) const;
    void SetRequestHeader(hstring_view name, hstring_view value) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationFeed, Windows::Web::Syndication::RetrievalProgress> RetrieveFeedAsync(const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationClientFactory
{
    Windows::Web::Syndication::SyndicationClient CreateSyndicationClient(const Windows::Security::Credentials::PasswordCredential & serverCredential) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationContent
{
    Windows::Foundation::Uri SourceUri() const;
    void SourceUri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationContentFactory
{
    Windows::Web::Syndication::SyndicationContent CreateSyndicationContent(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) const;
    Windows::Web::Syndication::SyndicationContent CreateSyndicationContentWithSourceUri(const Windows::Foundation::Uri & sourceUri) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationErrorStatics
{
    Windows::Web::Syndication::SyndicationErrorStatus GetStatus(int32_t hresult) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationFeed
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> Authors() const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> Categories() const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> Contributors() const;
    Windows::Web::Syndication::SyndicationGenerator Generator() const;
    void Generator(const Windows::Web::Syndication::SyndicationGenerator & value) const;
    Windows::Foundation::Uri IconUri() const;
    void IconUri(const Windows::Foundation::Uri & value) const;
    hstring Id() const;
    void Id(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationItem> Items() const;
    Windows::Foundation::DateTime LastUpdatedTime() const;
    void LastUpdatedTime(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> Links() const;
    Windows::Foundation::Uri ImageUri() const;
    void ImageUri(const Windows::Foundation::Uri & value) const;
    Windows::Web::Syndication::ISyndicationText Rights() const;
    void Rights(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Web::Syndication::ISyndicationText Subtitle() const;
    void Subtitle(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Web::Syndication::ISyndicationText Title() const;
    void Title(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Foundation::Uri FirstUri() const;
    Windows::Foundation::Uri LastUri() const;
    Windows::Foundation::Uri NextUri() const;
    Windows::Foundation::Uri PreviousUri() const;
    Windows::Web::Syndication::SyndicationFormat SourceFormat() const;
    void Load(hstring_view feed) const;
    void LoadFromXml(const Windows::Data::Xml::Dom::XmlDocument & feedDocument) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationFeedFactory
{
    Windows::Web::Syndication::SyndicationFeed CreateSyndicationFeed(hstring_view title, hstring_view subtitle, const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationGenerator
{
    hstring Text() const;
    void Text(hstring_view value) const;
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
    hstring Version() const;
    void Version(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationGeneratorFactory
{
    Windows::Web::Syndication::SyndicationGenerator CreateSyndicationGenerator(hstring_view text) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationItem
{
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> Authors() const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationCategory> Categories() const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationPerson> Contributors() const;
    Windows::Web::Syndication::SyndicationContent Content() const;
    void Content(const Windows::Web::Syndication::SyndicationContent & value) const;
    hstring Id() const;
    void Id(hstring_view value) const;
    Windows::Foundation::DateTime LastUpdatedTime() const;
    void LastUpdatedTime(const Windows::Foundation::DateTime & value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationLink> Links() const;
    Windows::Foundation::DateTime PublishedDate() const;
    void PublishedDate(const Windows::Foundation::DateTime & value) const;
    Windows::Web::Syndication::ISyndicationText Rights() const;
    void Rights(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Web::Syndication::SyndicationFeed Source() const;
    void Source(const Windows::Web::Syndication::SyndicationFeed & value) const;
    Windows::Web::Syndication::ISyndicationText Summary() const;
    void Summary(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Web::Syndication::ISyndicationText Title() const;
    void Title(const Windows::Web::Syndication::ISyndicationText & value) const;
    Windows::Foundation::Uri CommentsUri() const;
    void CommentsUri(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Uri EditUri() const;
    Windows::Foundation::Uri EditMediaUri() const;
    hstring ETag() const;
    Windows::Foundation::Uri ItemUri() const;
    void Load(hstring_view item) const;
    void LoadFromXml(const Windows::Data::Xml::Dom::XmlDocument & itemDocument) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationItemFactory
{
    Windows::Web::Syndication::SyndicationItem CreateSyndicationItem(hstring_view title, const Windows::Web::Syndication::SyndicationContent & content, const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationLink
{
    uint32_t Length() const;
    void Length(uint32_t value) const;
    hstring MediaType() const;
    void MediaType(hstring_view value) const;
    hstring Relationship() const;
    void Relationship(hstring_view value) const;
    hstring Title() const;
    void Title(hstring_view value) const;
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
    hstring ResourceLanguage() const;
    void ResourceLanguage(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationLinkFactory
{
    Windows::Web::Syndication::SyndicationLink CreateSyndicationLink(const Windows::Foundation::Uri & uri) const;
    Windows::Web::Syndication::SyndicationLink CreateSyndicationLinkEx(const Windows::Foundation::Uri & uri, hstring_view relationship, hstring_view title, hstring_view mediaType, uint32_t length) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationNode
{
    hstring NodeName() const;
    void NodeName(hstring_view value) const;
    hstring NodeNamespace() const;
    void NodeNamespace(hstring_view value) const;
    hstring NodeValue() const;
    void NodeValue(hstring_view value) const;
    hstring Language() const;
    void Language(hstring_view value) const;
    Windows::Foundation::Uri BaseUri() const;
    void BaseUri(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::SyndicationAttribute> AttributeExtensions() const;
    Windows::Foundation::Collections::IVector<Windows::Web::Syndication::ISyndicationNode> ElementExtensions() const;
    Windows::Data::Xml::Dom::XmlDocument GetXmlDocument(Windows::Web::Syndication::SyndicationFormat format) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationNodeFactory
{
    Windows::Web::Syndication::SyndicationNode CreateSyndicationNode(hstring_view nodeName, hstring_view nodeNamespace, hstring_view nodeValue) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationPerson
{
    hstring Email() const;
    void Email(hstring_view value) const;
    hstring Name() const;
    void Name(hstring_view value) const;
    Windows::Foundation::Uri Uri() const;
    void Uri(const Windows::Foundation::Uri & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationPersonFactory
{
    Windows::Web::Syndication::SyndicationPerson CreateSyndicationPerson(hstring_view name) const;
    Windows::Web::Syndication::SyndicationPerson CreateSyndicationPersonEx(hstring_view name, hstring_view email, const Windows::Foundation::Uri & uri) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationText
{
    hstring Text() const;
    void Text(hstring_view value) const;
    hstring Type() const;
    void Type(hstring_view value) const;
    Windows::Data::Xml::Dom::XmlDocument Xml() const;
    void Xml(const Windows::Data::Xml::Dom::XmlDocument & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISyndicationTextFactory
{
    Windows::Web::Syndication::SyndicationText CreateSyndicationText(hstring_view text) const;
    Windows::Web::Syndication::SyndicationText CreateSyndicationTextEx(hstring_view text, Windows::Web::Syndication::SyndicationTextType type) const;
};

}

namespace impl {

template <> struct traits<Windows::Web::Syndication::ISyndicationAttribute>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationAttribute;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationAttribute<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationAttributeFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationAttributeFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationAttributeFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationCategory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationCategory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationCategory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationCategoryFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationCategoryFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationCategoryFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationClient>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationClient;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationClient<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationClientFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationClientFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationClientFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationContent>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationContent;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationContent<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationContentFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationContentFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationContentFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationErrorStatics>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationErrorStatics;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationErrorStatics<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationFeed>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationFeed;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationFeed<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationFeedFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationFeedFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationFeedFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationGenerator>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationGenerator;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationGenerator<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationGeneratorFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationGeneratorFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationGeneratorFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationItem>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationItem;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationItem<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationItemFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationItemFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationItemFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationLink>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationLink;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationLink<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationLinkFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationLinkFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationLinkFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationNode>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationNode;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationNode<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationNodeFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationNodeFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationNodeFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationPerson>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationPerson;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationPerson<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationPersonFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationPersonFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationPersonFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationText>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationText;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationText<D>;
};

template <> struct traits<Windows::Web::Syndication::ISyndicationTextFactory>
{
    using abi = ABI::Windows::Web::Syndication::ISyndicationTextFactory;
    template <typename D> using consume = Windows::Web::Syndication::impl_ISyndicationTextFactory<D>;
};

template <> struct traits<Windows::Web::Syndication::SyndicationAttribute>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationAttribute;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationAttribute"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationCategory>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationCategory;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationCategory"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationClient>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationClient;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationClient"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationContent>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationContent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationContent"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationError>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationError"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationFeed>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationFeed;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationFeed"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationGenerator>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationGenerator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationGenerator"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationItem>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationItem"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationLink>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationLink;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationLink"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationNode>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationNode"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationPerson>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationPerson;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationPerson"; }
};

template <> struct traits<Windows::Web::Syndication::SyndicationText>
{
    using abi = ABI::Windows::Web::Syndication::SyndicationText;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Web.Syndication.SyndicationText"; }
};

}

}
