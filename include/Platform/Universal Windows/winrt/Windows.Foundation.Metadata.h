// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Metadata.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Foundation::Metadata::IApiInformationStatics> : produce_base<D, Windows::Foundation::Metadata::IApiInformationStatics>
{
    HRESULT __stdcall abi_IsTypePresent(impl::abi_arg_in<hstring> typeName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTypePresent(*reinterpret_cast<const hstring *>(&typeName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsMethodPresent(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> methodName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMethodPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&methodName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsMethodPresentWithArity(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> methodName, uint32_t inputParameterCount, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsMethodPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&methodName), inputParameterCount));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEventPresent(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> eventName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEventPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&eventName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPropertyPresent(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> propertyName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPropertyPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&propertyName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsReadOnlyPropertyPresent(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> propertyName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadOnlyPropertyPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&propertyName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsWriteablePropertyPresent(impl::abi_arg_in<hstring> typeName, impl::abi_arg_in<hstring> propertyName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsWriteablePropertyPresent(*reinterpret_cast<const hstring *>(&typeName), *reinterpret_cast<const hstring *>(&propertyName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnumNamedValuePresent(impl::abi_arg_in<hstring> enumTypeName, impl::abi_arg_in<hstring> valueName, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnumNamedValuePresent(*reinterpret_cast<const hstring *>(&enumTypeName), *reinterpret_cast<const hstring *>(&valueName)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsApiContractPresentByMajor(impl::abi_arg_in<hstring> contractName, uint16_t majorVersion, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsApiContractPresent(*reinterpret_cast<const hstring *>(&contractName), majorVersion));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsApiContractPresentByMajorAndMinor(impl::abi_arg_in<hstring> contractName, uint16_t majorVersion, uint16_t minorVersion, bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsApiContractPresent(*reinterpret_cast<const hstring *>(&contractName), majorVersion, minorVersion));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Foundation::Metadata {

template <typename D> bool impl_IApiInformationStatics<D>::IsTypePresent(hstring_view typeName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsTypePresent(get_abi(typeName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsMethodPresent(hstring_view typeName, hstring_view methodName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsMethodPresent(get_abi(typeName), get_abi(methodName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsMethodPresent(hstring_view typeName, hstring_view methodName, uint32_t inputParameterCount) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsMethodPresentWithArity(get_abi(typeName), get_abi(methodName), inputParameterCount, &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsEventPresent(hstring_view typeName, hstring_view eventName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsEventPresent(get_abi(typeName), get_abi(eventName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsPropertyPresent(hstring_view typeName, hstring_view propertyName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsPropertyPresent(get_abi(typeName), get_abi(propertyName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsReadOnlyPropertyPresent(hstring_view typeName, hstring_view propertyName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsReadOnlyPropertyPresent(get_abi(typeName), get_abi(propertyName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsWriteablePropertyPresent(hstring_view typeName, hstring_view propertyName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsWriteablePropertyPresent(get_abi(typeName), get_abi(propertyName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsEnumNamedValuePresent(hstring_view enumTypeName, hstring_view valueName) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsEnumNamedValuePresent(get_abi(enumTypeName), get_abi(valueName), &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsApiContractPresent(hstring_view contractName, uint16_t majorVersion) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsApiContractPresentByMajor(get_abi(contractName), majorVersion, &value));
    return value;
}

template <typename D> bool impl_IApiInformationStatics<D>::IsApiContractPresent(hstring_view contractName, uint16_t majorVersion, uint16_t minorVersion) const
{
    bool value {};
    check_hresult(WINRT_SHIM(IApiInformationStatics)->abi_IsApiContractPresentByMajorAndMinor(get_abi(contractName), majorVersion, minorVersion, &value));
    return value;
}

inline bool ApiInformation::IsTypePresent(hstring_view typeName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsTypePresent(typeName);
}

inline bool ApiInformation::IsMethodPresent(hstring_view typeName, hstring_view methodName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsMethodPresent(typeName, methodName);
}

inline bool ApiInformation::IsMethodPresent(hstring_view typeName, hstring_view methodName, uint32_t inputParameterCount)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsMethodPresent(typeName, methodName, inputParameterCount);
}

inline bool ApiInformation::IsEventPresent(hstring_view typeName, hstring_view eventName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsEventPresent(typeName, eventName);
}

inline bool ApiInformation::IsPropertyPresent(hstring_view typeName, hstring_view propertyName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsPropertyPresent(typeName, propertyName);
}

inline bool ApiInformation::IsReadOnlyPropertyPresent(hstring_view typeName, hstring_view propertyName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsReadOnlyPropertyPresent(typeName, propertyName);
}

inline bool ApiInformation::IsWriteablePropertyPresent(hstring_view typeName, hstring_view propertyName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsWriteablePropertyPresent(typeName, propertyName);
}

inline bool ApiInformation::IsEnumNamedValuePresent(hstring_view enumTypeName, hstring_view valueName)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsEnumNamedValuePresent(enumTypeName, valueName);
}

inline bool ApiInformation::IsApiContractPresent(hstring_view contractName, uint16_t majorVersion)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsApiContractPresent(contractName, majorVersion);
}

inline bool ApiInformation::IsApiContractPresent(hstring_view contractName, uint16_t majorVersion, uint16_t minorVersion)
{
    return get_activation_factory<ApiInformation, IApiInformationStatics>().IsApiContractPresent(contractName, majorVersion, minorVersion);
}

}

}
#pragma warning(pop)
