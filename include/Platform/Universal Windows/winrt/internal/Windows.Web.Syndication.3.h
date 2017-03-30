// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.Syndication.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Web::Syndication {

struct WINRT_EBO SyndicationAttribute :
    Windows::Web::Syndication::ISyndicationAttribute
{
    SyndicationAttribute(std::nullptr_t) noexcept {}
    SyndicationAttribute();
    SyndicationAttribute(hstring_view attributeName, hstring_view attributeNamespace, hstring_view attributeValue);
};

struct WINRT_EBO SyndicationCategory :
    Windows::Web::Syndication::ISyndicationCategory
{
    SyndicationCategory(std::nullptr_t) noexcept {}
    SyndicationCategory();
    SyndicationCategory(hstring_view term);
    SyndicationCategory(hstring_view term, hstring_view scheme, hstring_view label);
};

struct WINRT_EBO SyndicationClient :
    Windows::Web::Syndication::ISyndicationClient
{
    SyndicationClient(std::nullptr_t) noexcept {}
    SyndicationClient();
    SyndicationClient(const Windows::Security::Credentials::PasswordCredential & serverCredential);
};

struct WINRT_EBO SyndicationContent :
    Windows::Web::Syndication::ISyndicationContent
{
    SyndicationContent(std::nullptr_t) noexcept {}
    SyndicationContent();
    SyndicationContent(hstring_view text, Windows::Web::Syndication::SyndicationTextType type);
    SyndicationContent(const Windows::Foundation::Uri & sourceUri);
};

struct SyndicationError
{
    SyndicationError() = delete;
    static Windows::Web::Syndication::SyndicationErrorStatus GetStatus(int32_t hresult);
};

struct WINRT_EBO SyndicationFeed :
    Windows::Web::Syndication::ISyndicationFeed
{
    SyndicationFeed(std::nullptr_t) noexcept {}
    SyndicationFeed();
    SyndicationFeed(hstring_view title, hstring_view subtitle, const Windows::Foundation::Uri & uri);
};

struct WINRT_EBO SyndicationGenerator :
    Windows::Web::Syndication::ISyndicationGenerator,
    impl::require<SyndicationGenerator, Windows::Web::Syndication::ISyndicationNode>
{
    SyndicationGenerator(std::nullptr_t) noexcept {}
    SyndicationGenerator();
    SyndicationGenerator(hstring_view text);
};

struct WINRT_EBO SyndicationItem :
    Windows::Web::Syndication::ISyndicationItem
{
    SyndicationItem(std::nullptr_t) noexcept {}
    SyndicationItem();
    SyndicationItem(hstring_view title, const Windows::Web::Syndication::SyndicationContent & content, const Windows::Foundation::Uri & uri);
};

struct WINRT_EBO SyndicationLink :
    Windows::Web::Syndication::ISyndicationLink
{
    SyndicationLink(std::nullptr_t) noexcept {}
    SyndicationLink();
    SyndicationLink(const Windows::Foundation::Uri & uri);
    SyndicationLink(const Windows::Foundation::Uri & uri, hstring_view relationship, hstring_view title, hstring_view mediaType, uint32_t length);
};

struct WINRT_EBO SyndicationNode :
    Windows::Web::Syndication::ISyndicationNode
{
    SyndicationNode(std::nullptr_t) noexcept {}
    SyndicationNode();
    SyndicationNode(hstring_view nodeName, hstring_view nodeNamespace, hstring_view nodeValue);
};

struct WINRT_EBO SyndicationPerson :
    Windows::Web::Syndication::ISyndicationPerson
{
    SyndicationPerson(std::nullptr_t) noexcept {}
    SyndicationPerson();
    SyndicationPerson(hstring_view name);
    SyndicationPerson(hstring_view name, hstring_view email, const Windows::Foundation::Uri & uri);
};

struct WINRT_EBO SyndicationText :
    Windows::Web::Syndication::ISyndicationText
{
    SyndicationText(std::nullptr_t) noexcept {}
    SyndicationText();
    SyndicationText(hstring_view text);
    SyndicationText(hstring_view text, Windows::Web::Syndication::SyndicationTextType type);
};

}

}
