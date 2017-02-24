// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Services.Maps.3.h"
#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.Services.Maps.LocalSearch.3.h"
#include "Windows.Services.Maps.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalCategoriesStatics>
{
    HRESULT __stdcall get_BankAndCreditUnions(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BankAndCreditUnions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EatDrink(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EatDrink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Hospitals(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hospitals());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HotelsAndMotels(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HotelsAndMotels());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_All(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().All());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parking(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parking());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SeeDo(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SeeDo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Shop(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Shop());
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
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocation> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocation>
{
    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::Services::Maps::IMapAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Identifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Identifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Description(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Description());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Point(impl::abi_arg_out<Windows::Devices::Geolocation::IGeopoint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Point());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhoneNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhoneNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataAttribution(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataAttribution());
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
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocation2> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocation2>
{
    HRESULT __stdcall get_Category(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Category());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RatingInfo(impl::abi_arg_out<Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RatingInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HoursOfOperation(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HoursOfOperation());
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
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocationFinderResult>
{
    HRESULT __stdcall get_LocalLocations(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalLocations());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocationFinderStatics>
{
    HRESULT __stdcall abi_FindLocalLocationsAsync(impl::abi_arg_in<hstring> searchTerm, impl::abi_arg_in<Windows::Devices::Geolocation::IGeocircle> searchArea, impl::abi_arg_in<hstring> localCategory, uint32_t maxResults, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindLocalLocationsAsync(*reinterpret_cast<const hstring *>(&searchTerm), *reinterpret_cast<const Windows::Devices::Geolocation::Geocircle *>(&searchArea), *reinterpret_cast<const hstring *>(&localCategory), maxResults));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocationHoursOfOperationItem>
{
    HRESULT __stdcall get_Day(Windows::Globalization::DayOfWeek * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Day());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Start(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Start());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Span(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Span());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo> : produce_base<D, Windows::Services::Maps::LocalSearch::ILocalLocationRatingInfo>
{
    HRESULT __stdcall get_AggregateRating(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AggregateRating());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RatingCount(impl::abi_arg_out<Windows::Foundation::IReference<int32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RatingCount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProviderIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProviderIdentifier());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Services::Maps::LocalSearch {

template <typename D> Windows::Services::Maps::MapAddress impl_ILocalLocation<D>::Address() const
{
    Windows::Services::Maps::MapAddress value { nullptr };
    check_hresult(WINRT_SHIM(ILocalLocation)->get_Address(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation<D>::Identifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation)->get_Identifier(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation<D>::Description() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation)->get_Description(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geopoint impl_ILocalLocation<D>::Point() const
{
    Windows::Devices::Geolocation::Geopoint value { nullptr };
    check_hresult(WINRT_SHIM(ILocalLocation)->get_Point(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation<D>::PhoneNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation)->get_PhoneNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation<D>::DataAttribution() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation)->get_DataAttribution(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> impl_ILocalLocationFinderResult<D>::LocalLocations() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocation> value;
    check_hresult(WINRT_SHIM(ILocalLocationFinderResult)->get_LocalLocations(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus impl_ILocalLocationFinderResult<D>::Status() const
{
    Windows::Services::Maps::LocalSearch::LocalLocationFinderStatus value {};
    check_hresult(WINRT_SHIM(ILocalLocationFinderResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> impl_ILocalLocationFinderStatics<D>::FindLocalLocationsAsync(hstring_view searchTerm, const Windows::Devices::Geolocation::Geocircle & searchArea, hstring_view localCategory, uint32_t maxResults) const
{
    Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> result;
    check_hresult(WINRT_SHIM(ILocalLocationFinderStatics)->abi_FindLocalLocationsAsync(get_abi(searchTerm), get_abi(searchArea), get_abi(localCategory), maxResults, put_abi(result)));
    return result;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::BankAndCreditUnions() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_BankAndCreditUnions(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::EatDrink() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_EatDrink(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::Hospitals() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_Hospitals(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::HotelsAndMotels() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_HotelsAndMotels(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::All() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_All(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::Parking() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_Parking(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::SeeDo() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_SeeDo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalCategoriesStatics<D>::Shop() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalCategoriesStatics)->get_Shop(put_abi(value)));
    return value;
}

template <typename D> Windows::Globalization::DayOfWeek impl_ILocalLocationHoursOfOperationItem<D>::Day() const
{
    Windows::Globalization::DayOfWeek value {};
    check_hresult(WINRT_SHIM(ILocalLocationHoursOfOperationItem)->get_Day(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ILocalLocationHoursOfOperationItem<D>::Start() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ILocalLocationHoursOfOperationItem)->get_Start(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ILocalLocationHoursOfOperationItem<D>::Span() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ILocalLocationHoursOfOperationItem)->get_Span(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ILocalLocationRatingInfo<D>::AggregateRating() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(ILocalLocationRatingInfo)->get_AggregateRating(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<int32_t> impl_ILocalLocationRatingInfo<D>::RatingCount() const
{
    Windows::Foundation::IReference<int32_t> value;
    check_hresult(WINRT_SHIM(ILocalLocationRatingInfo)->get_RatingCount(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocationRatingInfo<D>::ProviderIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocationRatingInfo)->get_ProviderIdentifier(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILocalLocation2<D>::Category() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILocalLocation2)->get_Category(put_abi(value)));
    return value;
}

template <typename D> Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo impl_ILocalLocation2<D>::RatingInfo() const
{
    Windows::Services::Maps::LocalSearch::LocalLocationRatingInfo value { nullptr };
    check_hresult(WINRT_SHIM(ILocalLocation2)->get_RatingInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> impl_ILocalLocation2<D>::HoursOfOperation() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Services::Maps::LocalSearch::LocalLocationHoursOfOperationItem> value;
    check_hresult(WINRT_SHIM(ILocalLocation2)->get_HoursOfOperation(put_abi(value)));
    return value;
}

inline hstring LocalCategories::BankAndCreditUnions()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().BankAndCreditUnions();
}

inline hstring LocalCategories::EatDrink()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().EatDrink();
}

inline hstring LocalCategories::Hospitals()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().Hospitals();
}

inline hstring LocalCategories::HotelsAndMotels()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().HotelsAndMotels();
}

inline hstring LocalCategories::All()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().All();
}

inline hstring LocalCategories::Parking()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().Parking();
}

inline hstring LocalCategories::SeeDo()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().SeeDo();
}

inline hstring LocalCategories::Shop()
{
    return get_activation_factory<LocalCategories, ILocalCategoriesStatics>().Shop();
}

inline Windows::Foundation::IAsyncOperation<Windows::Services::Maps::LocalSearch::LocalLocationFinderResult> LocalLocationFinder::FindLocalLocationsAsync(hstring_view searchTerm, const Windows::Devices::Geolocation::Geocircle & searchArea, hstring_view localCategory, uint32_t maxResults)
{
    return get_activation_factory<LocalLocationFinder, ILocalLocationFinderStatics>().FindLocalLocationsAsync(searchTerm, searchArea, localCategory, maxResults);
}

}

}
#pragma warning(pop)
