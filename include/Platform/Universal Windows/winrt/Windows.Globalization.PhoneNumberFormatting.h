// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Globalization.PhoneNumberFormatting.3.h"
#include "Windows.Globalization.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> : produce_base<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>
{
    HRESULT __stdcall abi_Format(impl::abi_arg_in<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> number, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(*reinterpret_cast<const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatWithOutputFormat(impl::abi_arg_in<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> number, Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormat numberFormat, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Format(*reinterpret_cast<const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo *>(&number), numberFormat));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatPartialString(impl::abi_arg_in<hstring> number, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatPartialString(*reinterpret_cast<const hstring *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatString(impl::abi_arg_in<hstring> number, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatString(*reinterpret_cast<const hstring *>(&number)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FormatStringWithLeftToRightMarkers(impl::abi_arg_in<hstring> number, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FormatStringWithLeftToRightMarkers(*reinterpret_cast<const hstring *>(&number)));
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
struct produce<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics> : produce_base<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics>
{
    HRESULT __stdcall abi_TryCreate(impl::abi_arg_in<hstring> regionCode, impl::abi_arg_out<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> phoneNumber) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TryCreate(*reinterpret_cast<const hstring *>(&regionCode), *phoneNumber);
            return S_OK;
        }
        catch (...)
        {
            *phoneNumber = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCountryCodeForRegion(impl::abi_arg_in<hstring> regionCode, int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetCountryCodeForRegion(*reinterpret_cast<const hstring *>(&regionCode)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNationalDirectDialingPrefixForRegion(impl::abi_arg_in<hstring> regionCode, bool stripNonDigit, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNationalDirectDialingPrefixForRegion(*reinterpret_cast<const hstring *>(&regionCode), stripNonDigit));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WrapWithLeftToRightMarkers(impl::abi_arg_in<hstring> number, impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().WrapWithLeftToRightMarkers(*reinterpret_cast<const hstring *>(&number)));
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
struct produce<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> : produce_base<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>
{
    HRESULT __stdcall get_CountryCode(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CountryCode());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall abi_GetLengthOfGeographicalAreaCode(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetLengthOfGeographicalAreaCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNationalSignificantNumber(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNationalSignificantNumber());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLengthOfNationalDestinationCode(int32_t * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetLengthOfNationalDestinationCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PredictNumberKind(Windows::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().PredictNumberKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetGeographicRegionCode(impl::abi_arg_out<hstring> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetGeographicRegionCode());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckNumberMatch(impl::abi_arg_in<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> otherNumber, Windows::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckNumberMatch(*reinterpret_cast<const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo *>(&otherNumber)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory> : produce_base<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> number, impl::abi_arg_out<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&number)));
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
struct produce<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics> : produce_base<D, Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics>
{
    HRESULT __stdcall abi_TryParse(impl::abi_arg_in<hstring> input, impl::abi_arg_out<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> phoneNumber, Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *phoneNumber));
            return S_OK;
        }
        catch (...)
        {
            *phoneNumber = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryParseWithRegion(impl::abi_arg_in<hstring> input, impl::abi_arg_in<hstring> regionCode, impl::abi_arg_out<Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> phoneNumber, Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryParse(*reinterpret_cast<const hstring *>(&input), *reinterpret_cast<const hstring *>(&regionCode), *phoneNumber));
            return S_OK;
        }
        catch (...)
        {
            *phoneNumber = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Globalization::PhoneNumberFormatting {

template <typename D> int32_t impl_IPhoneNumberInfo<D>::CountryCode() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->get_CountryCode(&value));
    return value;
}

template <typename D> hstring impl_IPhoneNumberInfo<D>::PhoneNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->get_PhoneNumber(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IPhoneNumberInfo<D>::GetLengthOfGeographicalAreaCode() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_GetLengthOfGeographicalAreaCode(&result));
    return result;
}

template <typename D> hstring impl_IPhoneNumberInfo<D>::GetNationalSignificantNumber() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_GetNationalSignificantNumber(put_abi(result)));
    return result;
}

template <typename D> int32_t impl_IPhoneNumberInfo<D>::GetLengthOfNationalDestinationCode() const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_GetLengthOfNationalDestinationCode(&result));
    return result;
}

template <typename D> Windows::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind impl_IPhoneNumberInfo<D>::PredictNumberKind() const
{
    Windows::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_PredictNumberKind(&result));
    return result;
}

template <typename D> hstring impl_IPhoneNumberInfo<D>::GetGeographicRegionCode() const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_GetGeographicRegionCode(put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult impl_IPhoneNumberInfo<D>::CheckNumberMatch(const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & otherNumber) const
{
    Windows::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfo)->abi_CheckNumberMatch(get_abi(otherNumber), &result));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatter<D>::Format(const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & number) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatter)->abi_Format(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatter<D>::Format(const Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & number, Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormat numberFormat) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatter)->abi_FormatWithOutputFormat(get_abi(number), numberFormat, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatter<D>::FormatPartialString(hstring_view number) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatter)->abi_FormatPartialString(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatter<D>::FormatString(hstring_view number) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatter)->abi_FormatString(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatter<D>::FormatStringWithLeftToRightMarkers(hstring_view number) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatter)->abi_FormatStringWithLeftToRightMarkers(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo impl_IPhoneNumberInfoFactory<D>::Create(hstring_view number) const
{
    Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo result { nullptr };
    check_hresult(WINRT_SHIM(IPhoneNumberInfoFactory)->abi_Create(get_abi(number), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult impl_IPhoneNumberInfoStatics<D>::TryParse(hstring_view input, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber) const
{
    Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfoStatics)->abi_TryParse(get_abi(input), put_abi(phoneNumber), &result));
    return result;
}

template <typename D> Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult impl_IPhoneNumberInfoStatics<D>::TryParse(hstring_view input, hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber) const
{
    Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult result {};
    check_hresult(WINRT_SHIM(IPhoneNumberInfoStatics)->abi_TryParseWithRegion(get_abi(input), get_abi(regionCode), put_abi(phoneNumber), &result));
    return result;
}

template <typename D> void impl_IPhoneNumberFormatterStatics<D>::TryCreate(hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormatter & phoneNumber) const
{
    check_hresult(WINRT_SHIM(IPhoneNumberFormatterStatics)->abi_TryCreate(get_abi(regionCode), put_abi(phoneNumber)));
}

template <typename D> int32_t impl_IPhoneNumberFormatterStatics<D>::GetCountryCodeForRegion(hstring_view regionCode) const
{
    int32_t result {};
    check_hresult(WINRT_SHIM(IPhoneNumberFormatterStatics)->abi_GetCountryCodeForRegion(get_abi(regionCode), &result));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatterStatics<D>::GetNationalDirectDialingPrefixForRegion(hstring_view regionCode, bool stripNonDigit) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatterStatics)->abi_GetNationalDirectDialingPrefixForRegion(get_abi(regionCode), stripNonDigit, put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPhoneNumberFormatterStatics<D>::WrapWithLeftToRightMarkers(hstring_view number) const
{
    hstring result;
    check_hresult(WINRT_SHIM(IPhoneNumberFormatterStatics)->abi_WrapWithLeftToRightMarkers(get_abi(number), put_abi(result)));
    return result;
}

inline PhoneNumberFormatter::PhoneNumberFormatter() :
    PhoneNumberFormatter(activate_instance<PhoneNumberFormatter>())
{}

inline void PhoneNumberFormatter::TryCreate(hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormatter & phoneNumber)
{
    get_activation_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>().TryCreate(regionCode, phoneNumber);
}

inline int32_t PhoneNumberFormatter::GetCountryCodeForRegion(hstring_view regionCode)
{
    return get_activation_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>().GetCountryCodeForRegion(regionCode);
}

inline hstring PhoneNumberFormatter::GetNationalDirectDialingPrefixForRegion(hstring_view regionCode, bool stripNonDigit)
{
    return get_activation_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>().GetNationalDirectDialingPrefixForRegion(regionCode, stripNonDigit);
}

inline hstring PhoneNumberFormatter::WrapWithLeftToRightMarkers(hstring_view number)
{
    return get_activation_factory<PhoneNumberFormatter, IPhoneNumberFormatterStatics>().WrapWithLeftToRightMarkers(number);
}

inline PhoneNumberInfo::PhoneNumberInfo(hstring_view number) :
    PhoneNumberInfo(get_activation_factory<PhoneNumberInfo, IPhoneNumberInfoFactory>().Create(number))
{}

inline Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult PhoneNumberInfo::TryParse(hstring_view input, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber)
{
    return get_activation_factory<PhoneNumberInfo, IPhoneNumberInfoStatics>().TryParse(input, phoneNumber);
}

inline Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult PhoneNumberInfo::TryParse(hstring_view input, hstring_view regionCode, Windows::Globalization::PhoneNumberFormatting::PhoneNumberInfo & phoneNumber)
{
    return get_activation_factory<PhoneNumberInfo, IPhoneNumberInfoStatics>().TryParse(input, regionCode, phoneNumber);
}

}

}
#pragma warning(pop)
