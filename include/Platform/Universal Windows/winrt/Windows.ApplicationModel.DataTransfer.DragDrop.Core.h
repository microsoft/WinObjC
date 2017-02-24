// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.DataTransfer.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.DragDrop.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.DragDrop.Core.3.h"
#include "Windows.ApplicationModel.DataTransfer.DragDrop.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager>
{
    HRESULT __stdcall add_TargetRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().TargetRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TargetRequested(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetRequested(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AreConcurrentOperationsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AreConcurrentOperationsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AreConcurrentOperationsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AreConcurrentOperationsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManagerStatics> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetForCurrentView());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackageView> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Modifiers(Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Modifiers());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Point> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2>
{
    HRESULT __stdcall get_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>
{
    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::IDataPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPointerId(uint32_t pointerId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointerId(pointerId);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDragUIContentFromSoftwareBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDragUIContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDragUIContentFromSoftwareBitmapWithAnchorPoint(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDragUIContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DragUIContentMode(Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DragUIContentMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DragUIContentMode(Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DragUIContentMode(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartAsync());
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
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2>
{
    HRESULT __stdcall get_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowedOperations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowedOperations(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>
{
    HRESULT __stdcall abi_SetContentFromSoftwareBitmap(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetContentFromSoftwareBitmapWithAnchorPoint(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap, impl::abi_arg_in<Windows::Foundation::Point> anchorPoint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetContentFromSoftwareBitmap(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap), *reinterpret_cast<const Windows::Foundation::Point *>(&anchorPoint));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsContentVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsContentVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsContentVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsContentVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Caption(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Caption());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Caption(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Caption(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCaptionVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCaptionVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCaptionVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCaptionVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsGlyphVisible(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsGlyphVisible());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsGlyphVisible(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsGlyphVisible(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>
{
    HRESULT __stdcall abi_EnterAsync(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> dragInfo, impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride> dragUIOverride, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().EnterAsync(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo *>(&dragInfo), *reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIOverride *>(&dragUIOverride)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OverAsync(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> dragInfo, impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride> dragUIOverride, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().OverAsync(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo *>(&dragInfo), *reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIOverride *>(&dragUIOverride)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LeaveAsync(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> dragInfo, impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().LeaveAsync(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo *>(&dragInfo)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DropAsync(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> dragInfo, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().DropAsync(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo *>(&dragInfo)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs> : produce_base<D, Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs>
{
    HRESULT __stdcall abi_SetTarget(impl::abi_arg_in<Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget> target) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTarget(*reinterpret_cast<const Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget *>(&target));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::DataTransfer::DragDrop::Core {

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageView impl_ICoreDragInfo<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageView value { nullptr };
    check_hresult(WINRT_SHIM(ICoreDragInfo)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers impl_ICoreDragInfo<D>::Modifiers() const
{
    Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers value {};
    check_hresult(WINRT_SHIM(ICoreDragInfo)->get_Modifiers(&value));
    return value;
}

template <typename D> Windows::Foundation::Point impl_ICoreDragInfo<D>::Position() const
{
    Windows::Foundation::Point value {};
    check_hresult(WINRT_SHIM(ICoreDragInfo)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_ICoreDragInfo2<D>::AllowedOperations() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(ICoreDragInfo2)->get_AllowedOperations(&value));
    return value;
}

template <typename D> void impl_ICoreDragUIOverride<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->abi_SetContentFromSoftwareBitmap(get_abi(softwareBitmap)));
}

template <typename D> void impl_ICoreDragUIOverride<D>::SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->abi_SetContentFromSoftwareBitmapWithAnchorPoint(get_abi(softwareBitmap), get_abi(anchorPoint)));
}

template <typename D> bool impl_ICoreDragUIOverride<D>::IsContentVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->get_IsContentVisible(&value));
    return value;
}

template <typename D> void impl_ICoreDragUIOverride<D>::IsContentVisible(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->put_IsContentVisible(value));
}

template <typename D> hstring impl_ICoreDragUIOverride<D>::Caption() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->get_Caption(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreDragUIOverride<D>::Caption(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->put_Caption(get_abi(value)));
}

template <typename D> bool impl_ICoreDragUIOverride<D>::IsCaptionVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->get_IsCaptionVisible(&value));
    return value;
}

template <typename D> void impl_ICoreDragUIOverride<D>::IsCaptionVisible(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->put_IsCaptionVisible(value));
}

template <typename D> bool impl_ICoreDragUIOverride<D>::IsGlyphVisible() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->get_IsGlyphVisible(&value));
    return value;
}

template <typename D> void impl_ICoreDragUIOverride<D>::IsGlyphVisible(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->put_IsGlyphVisible(value));
}

template <typename D> void impl_ICoreDragUIOverride<D>::Clear() const
{
    check_hresult(WINRT_SHIM(ICoreDragUIOverride)->abi_Clear());
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> impl_ICoreDropOperationTarget<D>::EnterAsync(const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo & dragInfo, const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIOverride & dragUIOverride) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> returnValue;
    check_hresult(WINRT_SHIM(ICoreDropOperationTarget)->abi_EnterAsync(get_abi(dragInfo), get_abi(dragUIOverride), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> impl_ICoreDropOperationTarget<D>::OverAsync(const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo & dragInfo, const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIOverride & dragUIOverride) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> returnValue;
    check_hresult(WINRT_SHIM(ICoreDropOperationTarget)->abi_OverAsync(get_abi(dragInfo), get_abi(dragUIOverride), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ICoreDropOperationTarget<D>::LeaveAsync(const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo & dragInfo) const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(ICoreDropOperationTarget)->abi_LeaveAsync(get_abi(dragInfo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> impl_ICoreDropOperationTarget<D>::DropAsync(const Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragInfo & dragInfo) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> returnValue;
    check_hresult(WINRT_SHIM(ICoreDropOperationTarget)->abi_DropAsync(get_abi(dragInfo), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackage impl_ICoreDragOperation<D>::Data() const
{
    Windows::ApplicationModel::DataTransfer::DataPackage value { nullptr };
    check_hresult(WINRT_SHIM(ICoreDragOperation)->get_Data(put_abi(value)));
    return value;
}

template <typename D> void impl_ICoreDragOperation<D>::SetPointerId(uint32_t pointerId) const
{
    check_hresult(WINRT_SHIM(ICoreDragOperation)->abi_SetPointerId(pointerId));
}

template <typename D> void impl_ICoreDragOperation<D>::SetDragUIContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const
{
    check_hresult(WINRT_SHIM(ICoreDragOperation)->abi_SetDragUIContentFromSoftwareBitmap(get_abi(softwareBitmap)));
}

template <typename D> void impl_ICoreDragOperation<D>::SetDragUIContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const
{
    check_hresult(WINRT_SHIM(ICoreDragOperation)->abi_SetDragUIContentFromSoftwareBitmapWithAnchorPoint(get_abi(softwareBitmap), get_abi(anchorPoint)));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode impl_ICoreDragOperation<D>::DragUIContentMode() const
{
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode value {};
    check_hresult(WINRT_SHIM(ICoreDragOperation)->get_DragUIContentMode(&value));
    return value;
}

template <typename D> void impl_ICoreDragOperation<D>::DragUIContentMode(Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode value) const
{
    check_hresult(WINRT_SHIM(ICoreDragOperation)->put_DragUIContentMode(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> impl_ICoreDragOperation<D>::StartAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> value;
    check_hresult(WINRT_SHIM(ICoreDragOperation)->abi_StartAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::DataPackageOperation impl_ICoreDragOperation2<D>::AllowedOperations() const
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation value {};
    check_hresult(WINRT_SHIM(ICoreDragOperation2)->get_AllowedOperations(&value));
    return value;
}

template <typename D> void impl_ICoreDragOperation2<D>::AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const
{
    check_hresult(WINRT_SHIM(ICoreDragOperation2)->put_AllowedOperations(value));
}

template <typename D> Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager impl_ICoreDragDropManagerStatics<D>::GetForCurrentView() const
{
    Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager value { nullptr };
    check_hresult(WINRT_SHIM(ICoreDragDropManagerStatics)->abi_GetForCurrentView(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ICoreDragDropManager<D>::TargetRequested(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(ICoreDragDropManager)->add_TargetRequested(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<ICoreDragDropManager> impl_ICoreDragDropManager<D>::TargetRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager, Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ICoreDragDropManager>(this, &ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager::remove_TargetRequested, TargetRequested(value));
}

template <typename D> void impl_ICoreDragDropManager<D>::TargetRequested(event_token value) const
{
    check_hresult(WINRT_SHIM(ICoreDragDropManager)->remove_TargetRequested(value));
}

template <typename D> bool impl_ICoreDragDropManager<D>::AreConcurrentOperationsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ICoreDragDropManager)->get_AreConcurrentOperationsEnabled(&value));
    return value;
}

template <typename D> void impl_ICoreDragDropManager<D>::AreConcurrentOperationsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ICoreDragDropManager)->put_AreConcurrentOperationsEnabled(value));
}

template <typename D> void impl_ICoreDropOperationTargetRequestedEventArgs<D>::SetTarget(const Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget & target) const
{
    check_hresult(WINRT_SHIM(ICoreDropOperationTargetRequestedEventArgs)->abi_SetTarget(get_abi(target)));
}

inline Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager CoreDragDropManager::GetForCurrentView()
{
    return get_activation_factory<CoreDragDropManager, ICoreDragDropManagerStatics>().GetForCurrentView();
}

inline CoreDragOperation::CoreDragOperation() :
    CoreDragOperation(activate_instance<CoreDragOperation>())
{}

}

}
#pragma warning(pop)
