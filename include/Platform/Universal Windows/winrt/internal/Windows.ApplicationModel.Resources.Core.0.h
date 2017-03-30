// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Resources::Core {

struct ResourceLayoutInfo;

}

namespace Windows::ApplicationModel::Resources::Core {

using ResourceLayoutInfo = ABI::Windows::ApplicationModel::Resources::Core::ResourceLayoutInfo;

}

namespace ABI::Windows::ApplicationModel::Resources::Core {

struct INamedResource;
struct IResourceCandidate;
struct IResourceCandidate2;
struct IResourceContext;
struct IResourceContextStatics;
struct IResourceContextStatics2;
struct IResourceContextStatics3;
struct IResourceManager;
struct IResourceManager2;
struct IResourceManagerStatics;
struct IResourceMap;
struct IResourceQualifier;
struct NamedResource;
struct ResourceCandidate;
struct ResourceCandidateVectorView;
struct ResourceContext;
struct ResourceContextLanguagesVectorView;
struct ResourceManager;
struct ResourceMap;
struct ResourceMapIterator;
struct ResourceMapMapView;
struct ResourceMapMapViewIterator;
struct ResourceQualifier;
struct ResourceQualifierMapView;
struct ResourceQualifierObservableMap;
struct ResourceQualifierVectorView;

}

namespace Windows::ApplicationModel::Resources::Core {

struct INamedResource;
struct IResourceCandidate;
struct IResourceCandidate2;
struct IResourceContext;
struct IResourceContextStatics;
struct IResourceContextStatics2;
struct IResourceContextStatics3;
struct IResourceManager;
struct IResourceManager2;
struct IResourceManagerStatics;
struct IResourceMap;
struct IResourceQualifier;
struct NamedResource;
struct ResourceCandidate;
struct ResourceCandidateVectorView;
struct ResourceContext;
struct ResourceContextLanguagesVectorView;
struct ResourceManager;
struct ResourceMap;
struct ResourceMapIterator;
struct ResourceMapMapView;
struct ResourceMapMapViewIterator;
struct ResourceQualifier;
struct ResourceQualifierMapView;
struct ResourceQualifierObservableMap;
struct ResourceQualifierVectorView;

}

namespace Windows::ApplicationModel::Resources::Core {

template <typename T> struct impl_INamedResource;
template <typename T> struct impl_IResourceCandidate;
template <typename T> struct impl_IResourceCandidate2;
template <typename T> struct impl_IResourceContext;
template <typename T> struct impl_IResourceContextStatics;
template <typename T> struct impl_IResourceContextStatics2;
template <typename T> struct impl_IResourceContextStatics3;
template <typename T> struct impl_IResourceManager;
template <typename T> struct impl_IResourceManager2;
template <typename T> struct impl_IResourceManagerStatics;
template <typename T> struct impl_IResourceMap;
template <typename T> struct impl_IResourceQualifier;

}

namespace Windows::ApplicationModel::Resources::Core {

enum class ResourceQualifierPersistence
{
    None = 0,
    LocalMachine = 1,
};

}

}
