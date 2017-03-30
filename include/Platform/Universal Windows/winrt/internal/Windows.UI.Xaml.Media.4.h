// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media {

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::IGeneralTransformOverrides>
class IGeneralTransformOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IGeneralTransformOverrides = winrt::Windows::UI::Xaml::Media::IGeneralTransformOverrides;

    Windows::UI::Xaml::Media::GeneralTransform InverseCore()
    {
        return shim().as<IGeneralTransformOverrides>().InverseCore();
    }

    bool TryTransformCore(const Windows::Foundation::Point & inPoint, Windows::Foundation::Point & outPoint)
    {
        return shim().as<IGeneralTransformOverrides>().TryTransformCore(inPoint, outPoint);
    }

    Windows::Foundation::Rect TransformBoundsCore(const Windows::Foundation::Rect & rect)
    {
        return shim().as<IGeneralTransformOverrides>().TransformBoundsCore(rect);
    }

    HRESULT __stdcall get_InverseCore(impl::abi_arg_out<Windows::UI::Xaml::Media::IGeneralTransform> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InverseCore());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryTransformCore(impl::abi_arg_in<Windows::Foundation::Point> inPoint, impl::abi_arg_out<Windows::Foundation::Point> outPoint, bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TryTransformCore(*reinterpret_cast<const Windows::Foundation::Point *>(&inPoint), *outPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TransformBoundsCore(impl::abi_arg_in<Windows::Foundation::Rect> rect, impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TransformBoundsCore(*reinterpret_cast<const Windows::Foundation::Rect *>(&rect)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

}
