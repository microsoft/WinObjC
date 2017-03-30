// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Web::Syndication {

struct RetrievalProgress;
struct TransferProgress;

}

namespace Windows::Web::Syndication {

using RetrievalProgress = ABI::Windows::Web::Syndication::RetrievalProgress;
using TransferProgress = ABI::Windows::Web::Syndication::TransferProgress;

}

namespace ABI::Windows::Web::Syndication {

struct ISyndicationAttribute;
struct ISyndicationAttributeFactory;
struct ISyndicationCategory;
struct ISyndicationCategoryFactory;
struct ISyndicationClient;
struct ISyndicationClientFactory;
struct ISyndicationContent;
struct ISyndicationContentFactory;
struct ISyndicationErrorStatics;
struct ISyndicationFeed;
struct ISyndicationFeedFactory;
struct ISyndicationGenerator;
struct ISyndicationGeneratorFactory;
struct ISyndicationItem;
struct ISyndicationItemFactory;
struct ISyndicationLink;
struct ISyndicationLinkFactory;
struct ISyndicationNode;
struct ISyndicationNodeFactory;
struct ISyndicationPerson;
struct ISyndicationPersonFactory;
struct ISyndicationText;
struct ISyndicationTextFactory;
struct SyndicationAttribute;
struct SyndicationCategory;
struct SyndicationClient;
struct SyndicationContent;
struct SyndicationFeed;
struct SyndicationGenerator;
struct SyndicationItem;
struct SyndicationLink;
struct SyndicationNode;
struct SyndicationPerson;
struct SyndicationText;

}

namespace Windows::Web::Syndication {

struct ISyndicationAttribute;
struct ISyndicationAttributeFactory;
struct ISyndicationCategory;
struct ISyndicationCategoryFactory;
struct ISyndicationClient;
struct ISyndicationClientFactory;
struct ISyndicationContent;
struct ISyndicationContentFactory;
struct ISyndicationErrorStatics;
struct ISyndicationFeed;
struct ISyndicationFeedFactory;
struct ISyndicationGenerator;
struct ISyndicationGeneratorFactory;
struct ISyndicationItem;
struct ISyndicationItemFactory;
struct ISyndicationLink;
struct ISyndicationLinkFactory;
struct ISyndicationNode;
struct ISyndicationNodeFactory;
struct ISyndicationPerson;
struct ISyndicationPersonFactory;
struct ISyndicationText;
struct ISyndicationTextFactory;
struct SyndicationAttribute;
struct SyndicationCategory;
struct SyndicationClient;
struct SyndicationContent;
struct SyndicationError;
struct SyndicationFeed;
struct SyndicationGenerator;
struct SyndicationItem;
struct SyndicationLink;
struct SyndicationNode;
struct SyndicationPerson;
struct SyndicationText;

}

namespace Windows::Web::Syndication {

template <typename T> struct impl_ISyndicationAttribute;
template <typename T> struct impl_ISyndicationAttributeFactory;
template <typename T> struct impl_ISyndicationCategory;
template <typename T> struct impl_ISyndicationCategoryFactory;
template <typename T> struct impl_ISyndicationClient;
template <typename T> struct impl_ISyndicationClientFactory;
template <typename T> struct impl_ISyndicationContent;
template <typename T> struct impl_ISyndicationContentFactory;
template <typename T> struct impl_ISyndicationErrorStatics;
template <typename T> struct impl_ISyndicationFeed;
template <typename T> struct impl_ISyndicationFeedFactory;
template <typename T> struct impl_ISyndicationGenerator;
template <typename T> struct impl_ISyndicationGeneratorFactory;
template <typename T> struct impl_ISyndicationItem;
template <typename T> struct impl_ISyndicationItemFactory;
template <typename T> struct impl_ISyndicationLink;
template <typename T> struct impl_ISyndicationLinkFactory;
template <typename T> struct impl_ISyndicationNode;
template <typename T> struct impl_ISyndicationNodeFactory;
template <typename T> struct impl_ISyndicationPerson;
template <typename T> struct impl_ISyndicationPersonFactory;
template <typename T> struct impl_ISyndicationText;
template <typename T> struct impl_ISyndicationTextFactory;

}

namespace Windows::Web::Syndication {

enum class SyndicationErrorStatus
{
    Unknown = 0,
    MissingRequiredElement = 1,
    MissingRequiredAttribute = 2,
    InvalidXml = 3,
    UnexpectedContent = 4,
    UnsupportedFormat = 5,
};

enum class SyndicationFormat
{
    Atom10 = 0,
    Rss20 = 1,
    Rss10 = 2,
    Rss092 = 3,
    Rss091 = 4,
    Atom03 = 5,
};

enum class SyndicationTextType
{
    Text = 0,
    Html = 1,
    Xhtml = 2,
};

}

}
