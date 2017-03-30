// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Resources.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Resources::Core {

struct WINRT_EBO NamedResource :
    Windows::ApplicationModel::Resources::Core::INamedResource
{
    NamedResource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceCandidate :
    Windows::ApplicationModel::Resources::Core::IResourceCandidate,
    impl::require<ResourceCandidate, Windows::ApplicationModel::Resources::Core::IResourceCandidate2>
{
    ResourceCandidate(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceCandidateVectorView :
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate>
{
    ResourceCandidateVectorView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceContext :
    Windows::ApplicationModel::Resources::Core::IResourceContext
{
    ResourceContext(std::nullptr_t) noexcept {}
    ResourceContext();
    [[deprecated("CreateMatchingContext may be altered or unavailable for releases after Windows 8.1. Instead, use ResourceContext.GetForCurrentView.OverrideToMatch.")]] static Windows::ApplicationModel::Resources::Core::ResourceContext CreateMatchingContext(iterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> result);
    static Windows::ApplicationModel::Resources::Core::ResourceContext GetForCurrentView();
    static void SetGlobalQualifierValue(hstring_view key, hstring_view value);
    static void ResetGlobalQualifierValues();
    static void ResetGlobalQualifierValues(iterable<hstring> qualifierNames);
    static Windows::ApplicationModel::Resources::Core::ResourceContext GetForViewIndependentUse();
    static void SetGlobalQualifierValue(hstring_view key, hstring_view value, Windows::ApplicationModel::Resources::Core::ResourceQualifierPersistence persistence);
};

struct WINRT_EBO ResourceContextLanguagesVectorView :
    Windows::Foundation::Collections::IVectorView<hstring>
{
    ResourceContextLanguagesVectorView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceManager :
    Windows::ApplicationModel::Resources::Core::IResourceManager,
    impl::require<ResourceManager, Windows::ApplicationModel::Resources::Core::IResourceManager2>
{
    ResourceManager(std::nullptr_t) noexcept {}
    static Windows::ApplicationModel::Resources::Core::ResourceManager Current();
    static bool IsResourceReference(hstring_view resourceReference);
};

struct WINRT_EBO ResourceMap :
    Windows::ApplicationModel::Resources::Core::IResourceMap
{
    ResourceMap(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceMapIterator :
    Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>>
{
    ResourceMapIterator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceMapMapView :
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>
{
    ResourceMapMapView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceMapMapViewIterator :
    Windows::Foundation::Collections::IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>>
{
    ResourceMapMapViewIterator(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceQualifier :
    Windows::ApplicationModel::Resources::Core::IResourceQualifier
{
    ResourceQualifier(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceQualifierMapView :
    Windows::Foundation::Collections::IMapView<hstring, hstring>
{
    ResourceQualifierMapView(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceQualifierObservableMap :
    Windows::Foundation::Collections::IObservableMap<hstring, hstring>
{
    ResourceQualifierObservableMap(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ResourceQualifierVectorView :
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier>
{
    ResourceQualifierVectorView(std::nullptr_t) noexcept {}
};

}

}
