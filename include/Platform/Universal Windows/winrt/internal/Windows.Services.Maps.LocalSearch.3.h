// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Services.Maps.LocalSearch.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Services::Maps::LocalSearch {

struct LocalCategories
{
    LocalCategories() = delete;
    static hstring BankAndCreditUnions();
    static hstring EatDrink();
    static hstring Hospitals();
    static hstring HotelsAndMotels();
    static hstring All();
    static hstring Parking();
    static hstring SeeDo();
    static hstring Shop();
};

struct WINRT_EBO LocalLocation :
    Windows::Services::Maps::LocalSearch::ILocalLocation,
    impl::require<LocalLocation, Windows::Services::Maps::LocalSearch::ILocalLocation2>
{
    LocalLocation(std::nullptr_t) noexcept {}
};

struct LocalLocationFinder
{
    LocalLocationFinder() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> FindLocalLocationsAsync(hstring_view searchTerm, const Windows::Devices::Geolocation::Geocircle & searchArea, hstring_view localCategory, uint32_t maxResults);
};

struct WINRT_EBO LocalLocationFinderResult :
    Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult
{
    LocalLocationFinderResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LocalLocationHoursOfOperationItem :
    Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem
{
    LocalLocationHoursOfOperationItem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LocalLocationRatingInfo :
    Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo
{
    LocalLocationRatingInfo(std::nullptr_t) noexcept {}
};

}

}
