// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::ContentRestrictions {

struct IContentRestrictionsBrowsePolicy;
struct IRatedContentDescription;
struct IRatedContentDescriptionFactory;
struct IRatedContentRestrictions;
struct IRatedContentRestrictionsFactory;
struct ContentRestrictionsBrowsePolicy;
struct RatedContentDescription;
struct RatedContentRestrictions;

}

namespace Windows::Media::ContentRestrictions {

struct IContentRestrictionsBrowsePolicy;
struct IRatedContentDescription;
struct IRatedContentDescriptionFactory;
struct IRatedContentRestrictions;
struct IRatedContentRestrictionsFactory;
struct ContentRestrictionsBrowsePolicy;
struct RatedContentDescription;
struct RatedContentRestrictions;

}

namespace Windows::Media::ContentRestrictions {

template <typename T> struct impl_IContentRestrictionsBrowsePolicy;
template <typename T> struct impl_IRatedContentDescription;
template <typename T> struct impl_IRatedContentDescriptionFactory;
template <typename T> struct impl_IRatedContentRestrictions;
template <typename T> struct impl_IRatedContentRestrictionsFactory;

}

namespace Windows::Media::ContentRestrictions {

enum class ContentAccessRestrictionLevel
{
    Allow = 0,
    Warn = 1,
    Block = 2,
    Hide = 3,
};

enum class RatedContentCategory
{
    General = 0,
    Application = 1,
    Game = 2,
    Movie = 3,
    Television = 4,
    Music = 5,
};

}

}
