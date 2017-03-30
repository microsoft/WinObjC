// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Services.Maps.LocalSearch.0.h"
#include "Windows.Devices.Geolocation.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Services.Maps.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Services::Maps::LocalSearch {

struct __declspec(uuid("f49399f5-8261-4321-9974-ef92d49a8dca")) __declspec(novtable) ILocalCategoriesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BankAndCreditUnions(hstring * value) = 0;
    virtual HRESULT __stdcall get_EatDrink(hstring * value) = 0;
    virtual HRESULT __stdcall get_Hospitals(hstring * value) = 0;
    virtual HRESULT __stdcall get_HotelsAndMotels(hstring * value) = 0;
    virtual HRESULT __stdcall get_All(hstring * value) = 0;
    virtual HRESULT __stdcall get_Parking(hstring * value) = 0;
    virtual HRESULT __stdcall get_SeeDo(hstring * value) = 0;
    virtual HRESULT __stdcall get_Shop(hstring * value) = 0;
};

struct __declspec(uuid("bb0fe9ab-4502-4f2c-94a9-0d60de0e2163")) __declspec(novtable) ILocalLocation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Address(Windows::Services::Maps::IMapAddress ** value) = 0;
    virtual HRESULT __stdcall get_Identifier(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Point(Windows::Devices::Geolocation::IGeopoint ** value) = 0;
    virtual HRESULT __stdcall get_PhoneNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_DataAttribution(hstring * value) = 0;
};

struct __declspec(uuid("6e9e307c-ecb5-4ffc-bb8c-ba50ba8c2dc6")) __declspec(novtable) ILocalLocation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Category(hstring * value) = 0;
    virtual HRESULT __stdcall get_RatingInfo(Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo ** value) = 0;
    virtual HRESULT __stdcall get_HoursOfOperation(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> ** value) = 0;
};

struct __declspec(uuid("d09b6cc6-f338-4191-9fd8-5440b9a68f52")) __declspec(novtable) ILocalLocationFinderResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LocalLocations(Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus * value) = 0;
};

struct __declspec(uuid("d2ef7344-a0de-48ca-81a8-07c7dcfd37ab")) __declspec(novtable) ILocalLocationFinderStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindLocalLocationsAsync(hstring searchTerm, Windows::Devices::Geolocation::IGeocircle * searchArea, hstring localCategory, uint32_t maxResults, Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> ** result) = 0;
};

struct __declspec(uuid("23548c72-a1c7-43f1-a4f0-1091c39ec640")) __declspec(novtable) ILocalLocationHoursOfOperationItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Day(winrt::Windows::Globalization::DayOfWeek * value) = 0;
    virtual HRESULT __stdcall get_Start(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Span(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("cb1dab56-3354-4311-8bc0-a2d4d5eb806e")) __declspec(novtable) ILocalLocationRatingInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AggregateRating(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_RatingCount(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall get_ProviderIdentifier(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocation> { using default_interface = Windows::Services::Maps::LocalSearch::ILocalLocation; };
template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> { using default_interface = Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult; };
template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> { using default_interface = Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem; };
template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo> { using default_interface = Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo; };

}

namespace Windows::Services::Maps::LocalSearch {

template <typename D>
struct WINRT_EBO impl_ILocalCategoriesStatics
{
    hstring BankAndCreditUnions() const;
    hstring EatDrink() const;
    hstring Hospitals() const;
    hstring HotelsAndMotels() const;
    hstring All() const;
    hstring Parking() const;
    hstring SeeDo() const;
    hstring Shop() const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocation
{
    Windows::Services::Maps::MapAddress Address() const;
    hstring Identifier() const;
    hstring Description() const;
    hstring DisplayName() const;
    Windows::Devices::Geolocation::Geopoint Point() const;
    hstring PhoneNumber() const;
    hstring DataAttribution() const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocation2
{
    hstring Category() const;
    Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo RatingInfo() const;
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> HoursOfOperation() const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocationFinderResult
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> LocalLocations() const;
    Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocationFinderStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> FindLocalLocationsAsync(hstring_view searchTerm, const Windows::Devices::Geolocation::Geocircle & searchArea, hstring_view localCategory, uint32_t maxResults) const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocationHoursOfOperationItem
{
    Windows::Globalization::DayOfWeek Day() const;
    Windows::Foundation::TimeSpan Start() const;
    Windows::Foundation::TimeSpan Span() const;
};

template <typename D>
struct WINRT_EBO impl_ILocalLocationRatingInfo
{
    Windows::Foundation::IReference<double> AggregateRating() const;
    Windows::Foundation::IReference<int32_t> RatingCount() const;
    hstring ProviderIdentifier() const;
};

}

namespace impl {

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalCategoriesStatics<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocation>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocation;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocation<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocation2>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocation2;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocation2<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocationFinderResult<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocationFinderStatics<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocationHoursOfOperationItem<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo;
    template <typename D> using consume = Windows::Services::Maps::LocalSearch::impl_ILocalLocationRatingInfo<D>;
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalCategories>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalCategories"; }
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocation>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::LocalLocation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalLocation"; }
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationFinder>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalLocationFinder"; }
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::LocalLocationFinderResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalLocationFinderResult"; }
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalLocationHoursOfOperationItem"; }
};

template <> struct traits<Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo>
{
    using abi = ABI::Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Services.Maps.LocalSearch.LocalLocationRatingInfo"; }
};

}

}
