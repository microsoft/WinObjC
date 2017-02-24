// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Graphics.Printing3D.3.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Printing3D {

template <typename L> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(L lambda) :
    Print3DTaskSourceRequestedHandler(impl::make_delegate<impl_Print3DTaskSourceRequestedHandler<L>, Print3DTaskSourceRequestedHandler>(std::forward<L>(lambda)))
{}

template <typename F> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(F * function) :
    Print3DTaskSourceRequestedHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> Print3DTaskSourceRequestedHandler::Print3DTaskSourceRequestedHandler(O * object, M method) :
    Print3DTaskSourceRequestedHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void Print3DTaskSourceRequestedHandler::operator()(const Windows::Graphics::Printing3D::Print3DTaskSourceRequestedArgs & args) const
{
    check_hresult((*(abi<Print3DTaskSourceRequestedHandler> **)this)->abi_Invoke(get_abi(args)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrint3DManager> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DManager>
{
    HRESULT __stdcall add_TaskRequested(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DManager, Windows::Graphics::Printing3D::Print3DTaskRequestedEventArgs>> eventHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().TaskRequested(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DManager, Windows::Graphics::Printing3D::Print3DTaskRequestedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_TaskRequested(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TaskRequested(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrint3DManagerStatics> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DManagerStatics>
{
    HRESULT __stdcall abi_GetForCurrentView(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrint3DManager> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForCurrentView());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowPrintUIAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowPrintUIAsync());
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
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTask> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTask>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3D3MFPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Submitting(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Foundation::IInspectable>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().Submitting(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Submitting(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Submitting(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskCompletedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskCompletedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SourceChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().SourceChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SourceChanged(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceChanged(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTaskCompletedEventArgs>
{
    HRESULT __stdcall get_Completion(Windows::Graphics::Printing3D::Print3DTaskCompletion * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Completion());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedStatus(Windows::Graphics::Printing3D::Print3DTaskDetail * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTaskRequest> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTaskRequest>
{
    HRESULT __stdcall abi_CreateTask(impl::abi_arg_in<hstring> title, impl::abi_arg_in<hstring> printerId, impl::abi_arg_in<Windows::Graphics::Printing3D::Print3DTaskSourceRequestedHandler> handler, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrint3DTask> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateTask(*reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const hstring *>(&printerId), *reinterpret_cast<const Windows::Graphics::Printing3D::Print3DTaskSourceRequestedHandler *>(&handler)));
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
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTaskRequestedEventArgs>
{
    HRESULT __stdcall get_Request(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrint3DTaskRequest> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Request());
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
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTaskSourceChangedEventArgs>
{
    HRESULT __stdcall get_Source(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3D3MFPackage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
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
struct produce<D, Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs> : produce_base<D, Windows::Graphics::Printing3D::IPrint3DTaskSourceRequestedArgs>
{
    HRESULT __stdcall abi_SetSource(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3D3MFPackage> source) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3D3MFPackage *>(&source));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3D3MFPackage> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3D3MFPackage>
{
    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrintTicket(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrintTicket());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrintTicket(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrintTicket(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ModelPart(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ModelPart());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ModelPart(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ModelPart(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DTextureResource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Textures(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTextureResource>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Textures());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadModelFromPackageAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DModel>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadModelFromPackageAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveModelToPackageAsync(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DModel> value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().SaveModelToPackageAsync(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DModel *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3D3MFPackageStatics> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3D3MFPackageStatics>
{
    HRESULT __stdcall abi_LoadAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3D3MFPackage>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterial>
{
    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DColorMaterial> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DColorMaterial> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DColorMaterial *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup>
{
    HRESULT __stdcall get_Bases(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterial>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bases());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroupFactory>
{
    HRESULT __stdcall abi_Create(uint32_t MaterialGroupId, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(MaterialGroupId));
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialStatics> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DBaseMaterialStatics>
{
    HRESULT __stdcall get_Abs(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Abs());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Pla(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Pla());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterial>
{
    HRESULT __stdcall get_Value(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterial2> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterial2>
{
    HRESULT __stdcall get_Color(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Color());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Color(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup>
{
    HRESULT __stdcall get_Colors(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterial>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Colors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroupFactory>
{
    HRESULT __stdcall abi_Create(uint32_t MaterialGroupId, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DColorMaterialGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(MaterialGroupId));
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DComponent> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DComponent>
{
    HRESULT __stdcall get_Mesh(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DMesh> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Mesh());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Mesh(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DMesh> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mesh(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DMesh *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Components(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponentWithMatrix>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Components());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Thumbnail(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Thumbnail());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Thumbnail(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Thumbnail(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DTextureResource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Graphics::Printing3D::Printing3DObjectType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Type(Windows::Graphics::Printing3D::Printing3DObjectType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PartNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PartNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PartNumber(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PartNumber(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DComponentWithMatrix>
{
    HRESULT __stdcall get_Component(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Component());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Component(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Component(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DComponent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Matrix(impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Matrix());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Matrix(impl::abi_arg_in<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Matrix(*reinterpret_cast<const Windows::Foundation::Numerics::float4x4 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterial>
{
    HRESULT __stdcall get_Values(impl::abi_arg_out<Windows::Foundation::Collections::IVector<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Values());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup>
{
    HRESULT __stdcall get_Composites(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterial>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Composites());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialIndices(impl::abi_arg_out<Windows::Foundation::Collections::IVector<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialIndices());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup2>
{
    HRESULT __stdcall get_BaseMaterialGroup(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseMaterialGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BaseMaterialGroup(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DBaseMaterialGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BaseMaterialGroup(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroupFactory>
{
    HRESULT __stdcall abi_Create(uint32_t MaterialGroupId, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DCompositeMaterialGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(MaterialGroupId));
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions>
{
    HRESULT __stdcall get_MaxReductionArea(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxReductionArea());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxReductionArea(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxReductionArea(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TargetTriangleCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TargetTriangleCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TargetTriangleCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TargetTriangleCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxEdgeLength(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxEdgeLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxEdgeLength(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxEdgeLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMaterial>
{
    HRESULT __stdcall get_BaseGroups(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BaseGroups());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ColorGroups(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterialGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ColorGroups());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Texture2CoordGroups(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Texture2CoordGroups());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CompositeGroups(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CompositeGroups());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MultiplePropertyGroups(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MultiplePropertyGroups());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMesh> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMesh>
{
    HRESULT __stdcall get_VertexCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VertexCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IndexCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IndexCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IndexCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndexCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexPositionsDescription(impl::abi_arg_out<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexPositionsDescription());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VertexPositionsDescription(impl::abi_arg_in<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexPositionsDescription(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DBufferDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VertexNormalsDescription(impl::abi_arg_out<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VertexNormalsDescription());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VertexNormalsDescription(impl::abi_arg_in<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VertexNormalsDescription(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DBufferDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriangleIndicesDescription(impl::abi_arg_out<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriangleIndicesDescription());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TriangleIndicesDescription(impl::abi_arg_in<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleIndicesDescription(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DBufferDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriangleMaterialIndicesDescription(impl::abi_arg_out<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriangleMaterialIndicesDescription());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TriangleMaterialIndicesDescription(impl::abi_arg_in<Windows::Graphics::Printing3D::Printing3DBufferDescription> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriangleMaterialIndicesDescription(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DBufferDescription *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVertexPositions(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().GetVertexPositions());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateVertexPositions(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateVertexPositions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVertexNormals(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().GetVertexNormals());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateVertexNormals(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateVertexNormals(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTriangleIndices(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().GetTriangleIndices());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTriangleIndices(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateTriangleIndices(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetTriangleMaterialIndices(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().GetTriangleMaterialIndices());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateTriangleMaterialIndices(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateTriangleMaterialIndices(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferDescriptionSet(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferDescriptionSet());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BufferSet(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BufferSet());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifyAsync(Windows::Graphics::Printing3D::Printing3DMeshVerificationMode value, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DMeshVerificationResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().VerifyAsync(value));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMeshVerificationResult>
{
    HRESULT __stdcall get_IsValid(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsValid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NonmanifoldTriangles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NonmanifoldTriangles());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReversedNormalTriangles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReversedNormalTriangles());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DModel> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DModel>
{
    HRESULT __stdcall get_Unit(Windows::Graphics::Printing3D::Printing3DModelUnit * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Unit(Windows::Graphics::Printing3D::Printing3DModelUnit value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Textures(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DModelTexture>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Textures());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Meshes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMesh>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Meshes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Components(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponent>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Components());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Material(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DMaterial> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Material());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Material(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DMaterial> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Material(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DMaterial *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Build(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Build());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Build(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DComponent> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Build(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DComponent *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Version(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Version());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Version(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Version(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequiredExtensions(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequiredExtensions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Metadata(impl::abi_arg_out<Windows::Foundation::Collections::IMap<hstring, hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Metadata());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RepairAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RepairAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clone(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DModel> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Clone());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DModel2> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DModel2>
{
    HRESULT __stdcall abi_TryPartialRepairAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryPartialRepairAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryPartialRepairWithTimeAsync(impl::abi_arg_in<Windows::Foundation::TimeSpan> maxWaitTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryPartialRepairAsync(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&maxWaitTime)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReduceFacesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<bool, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryReduceFacesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReduceFacesWithOptionsAsync(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions> printing3DFaceReductionOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<bool, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryReduceFacesAsync(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DFaceReductionOptions *>(&printing3DFaceReductionOptions)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryReduceFacesWithOptionsAndTimeAsync(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DFaceReductionOptions> printing3DFaceReductionOptions, impl::abi_arg_in<Windows::Foundation::TimeSpan> maxWait, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<bool, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryReduceFacesAsync(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DFaceReductionOptions *>(&printing3DFaceReductionOptions), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&maxWait)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RepairWithProgressAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<bool, double>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RepairWithProgressAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DModelTexture> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DModelTexture>
{
    HRESULT __stdcall get_TextureResource(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextureResource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextureResource(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DTextureResource> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextureResource(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DTextureResource *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileStyleU(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileStyleU());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TileStyleU(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileStyleU(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileStyleV(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileStyleV());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TileStyleV(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileStyleV(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterial>
{
    HRESULT __stdcall get_MaterialIndices(impl::abi_arg_out<Windows::Foundation::Collections::IVector<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialIndices());
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup>
{
    HRESULT __stdcall get_MultipleProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MultipleProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupIndices(impl::abi_arg_out<Windows::Foundation::Collections::IVector<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupIndices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroupFactory>
{
    HRESULT __stdcall abi_Create(uint32_t MaterialGroupId, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DMultiplePropertyMaterialGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(MaterialGroupId));
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterial>
{
    HRESULT __stdcall get_Texture(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DModelTexture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Texture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Texture(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DModelTexture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Texture(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DModelTexture *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_U(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().U());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_U(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().U(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_V(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().V());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_V(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().V(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup>
{
    HRESULT __stdcall get_Texture2Coords(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Texture2Coords());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaterialGroupId(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaterialGroupId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup2>
{
    HRESULT __stdcall get_Texture(impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DModelTexture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Texture());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Texture(impl::abi_arg_in<Windows::Graphics::Printing3D::IPrinting3DModelTexture> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Texture(*reinterpret_cast<const Windows::Graphics::Printing3D::Printing3DModelTexture *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroupFactory>
{
    HRESULT __stdcall abi_Create(uint32_t MaterialGroupId, impl::abi_arg_out<Windows::Graphics::Printing3D::IPrinting3DTexture2CoordMaterialGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(MaterialGroupId));
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
struct produce<D, Windows::Graphics::Printing3D::IPrinting3DTextureResource> : produce_base<D, Windows::Graphics::Printing3D::IPrinting3DTextureResource>
{
    HRESULT __stdcall get_TextureData(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamWithContentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextureData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TextureData(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStreamWithContentType> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextureData(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStreamWithContentType *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Name(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Graphics::Printing3D {

template <typename D> Windows::Graphics::Printing3D::Print3DTaskCompletion impl_IPrint3DTaskCompletedEventArgs<D>::Completion() const
{
    Windows::Graphics::Printing3D::Print3DTaskCompletion value {};
    check_hresult(WINRT_SHIM(IPrint3DTaskCompletedEventArgs)->get_Completion(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Print3DTaskDetail impl_IPrint3DTaskCompletedEventArgs<D>::ExtendedStatus() const
{
    Windows::Graphics::Printing3D::Print3DTaskDetail value {};
    check_hresult(WINRT_SHIM(IPrint3DTaskCompletedEventArgs)->get_ExtendedStatus(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3D3MFPackage impl_IPrint3DTaskSourceChangedEventArgs<D>::Source() const
{
    Windows::Graphics::Printing3D::Printing3D3MFPackage value { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DTaskSourceChangedEventArgs)->get_Source(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3D3MFPackage impl_IPrint3DTask<D>::Source() const
{
    Windows::Graphics::Printing3D::Printing3D3MFPackage value { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DTask)->get_Source(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IPrint3DTask<D>::Submitting(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DTask)->add_Submitting(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DTask> impl_IPrint3DTask<D>::Submitting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DTask>(this, &ABI::Windows::Graphics::Printing3D::IPrint3DTask::remove_Submitting, Submitting(eventHandler));
}

template <typename D> void impl_IPrint3DTask<D>::Submitting(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DTask)->remove_Submitting(eventCookie));
}

template <typename D> event_token impl_IPrint3DTask<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskCompletedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DTask)->add_Completed(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DTask> impl_IPrint3DTask<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskCompletedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DTask>(this, &ABI::Windows::Graphics::Printing3D::IPrint3DTask::remove_Completed, Completed(eventHandler));
}

template <typename D> void impl_IPrint3DTask<D>::Completed(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DTask)->remove_Completed(eventCookie));
}

template <typename D> event_token impl_IPrint3DTask<D>::SourceChanged(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IPrint3DTask)->add_SourceChanged(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IPrint3DTask> impl_IPrint3DTask<D>::SourceChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DTask, Windows::Graphics::Printing3D::Print3DTaskSourceChangedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DTask>(this, &ABI::Windows::Graphics::Printing3D::IPrint3DTask::remove_SourceChanged, SourceChanged(eventHandler));
}

template <typename D> void impl_IPrint3DTask<D>::SourceChanged(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IPrint3DTask)->remove_SourceChanged(eventCookie));
}

template <typename D> void impl_IPrint3DTaskSourceRequestedArgs<D>::SetSource(const Windows::Graphics::Printing3D::Printing3D3MFPackage & source) const
{
    check_hresult(WINRT_SHIM(IPrint3DTaskSourceRequestedArgs)->abi_SetSource(get_abi(source)));
}

template <typename D> Windows::Graphics::Printing3D::Print3DTask impl_IPrint3DTaskRequest<D>::CreateTask(hstring_view title, hstring_view printerId, const Windows::Graphics::Printing3D::Print3DTaskSourceRequestedHandler & handler) const
{
    Windows::Graphics::Printing3D::Print3DTask result { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DTaskRequest)->abi_CreateTask(get_abi(title), get_abi(printerId), get_abi(handler), put_abi(result)));
    return result;
}

template <typename D> Windows::Graphics::Printing3D::Print3DTaskRequest impl_IPrint3DTaskRequestedEventArgs<D>::Request() const
{
    Windows::Graphics::Printing3D::Print3DTaskRequest value { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DTaskRequestedEventArgs)->get_Request(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Print3DManager impl_IPrint3DManagerStatics<D>::GetForCurrentView() const
{
    Windows::Graphics::Printing3D::Print3DManager result { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DManagerStatics)->abi_GetForCurrentView(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPrint3DManagerStatics<D>::ShowPrintUIAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IPrint3DManagerStatics)->abi_ShowPrintUIAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IPrint3DManager<D>::TaskRequested(const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DManager, Windows::Graphics::Printing3D::Print3DTaskRequestedEventArgs> & eventHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IPrint3DManager)->add_TaskRequested(get_abi(eventHandler), &token));
    return token;
}

template <typename D> event_revoker<IPrint3DManager> impl_IPrint3DManager<D>::TaskRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Graphics::Printing3D::Print3DManager, Windows::Graphics::Printing3D::Print3DTaskRequestedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IPrint3DManager>(this, &ABI::Windows::Graphics::Printing3D::IPrint3DManager::remove_TaskRequested, TaskRequested(eventHandler));
}

template <typename D> void impl_IPrint3DManager<D>::TaskRequested(event_token token) const
{
    check_hresult(WINRT_SHIM(IPrint3DManager)->remove_TaskRequested(token));
}

template <typename D> uint32_t impl_IPrinting3DMesh<D>::VertexCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_VertexCount(&value));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::VertexCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_VertexCount(value));
}

template <typename D> uint32_t impl_IPrinting3DMesh<D>::IndexCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_IndexCount(&value));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::IndexCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_IndexCount(value));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBufferDescription impl_IPrinting3DMesh<D>::VertexPositionsDescription() const
{
    Windows::Graphics::Printing3D::Printing3DBufferDescription value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_VertexPositionsDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::VertexPositionsDescription(const Windows::Graphics::Printing3D::Printing3DBufferDescription & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_VertexPositionsDescription(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBufferDescription impl_IPrinting3DMesh<D>::VertexNormalsDescription() const
{
    Windows::Graphics::Printing3D::Printing3DBufferDescription value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_VertexNormalsDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::VertexNormalsDescription(const Windows::Graphics::Printing3D::Printing3DBufferDescription & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_VertexNormalsDescription(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBufferDescription impl_IPrinting3DMesh<D>::TriangleIndicesDescription() const
{
    Windows::Graphics::Printing3D::Printing3DBufferDescription value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_TriangleIndicesDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::TriangleIndicesDescription(const Windows::Graphics::Printing3D::Printing3DBufferDescription & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_TriangleIndicesDescription(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBufferDescription impl_IPrinting3DMesh<D>::TriangleMaterialIndicesDescription() const
{
    Windows::Graphics::Printing3D::Printing3DBufferDescription value {};
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_TriangleMaterialIndicesDescription(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DMesh<D>::TriangleMaterialIndicesDescription(const Windows::Graphics::Printing3D::Printing3DBufferDescription & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->put_TriangleMaterialIndicesDescription(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPrinting3DMesh<D>::GetVertexPositions() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_GetVertexPositions(put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_IPrinting3DMesh<D>::CreateVertexPositions(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_CreateVertexPositions(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPrinting3DMesh<D>::GetVertexNormals() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_GetVertexNormals(put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_IPrinting3DMesh<D>::CreateVertexNormals(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_CreateVertexNormals(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPrinting3DMesh<D>::GetTriangleIndices() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_GetTriangleIndices(put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_IPrinting3DMesh<D>::CreateTriangleIndices(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_CreateTriangleIndices(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IPrinting3DMesh<D>::GetTriangleMaterialIndices() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_GetTriangleMaterialIndices(put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_IPrinting3DMesh<D>::CreateTriangleMaterialIndices(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_CreateTriangleMaterialIndices(value));
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IPrinting3DMesh<D>::BufferDescriptionSet() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_BufferDescriptionSet(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IPropertySet impl_IPrinting3DMesh<D>::BufferSet() const
{
    Windows::Foundation::Collections::IPropertySet value;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->get_BufferSet(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DMeshVerificationResult> impl_IPrinting3DMesh<D>::VerifyAsync(Windows::Graphics::Printing3D::Printing3DMeshVerificationMode value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DMeshVerificationResult> operation;
    check_hresult(WINRT_SHIM(IPrinting3DMesh)->abi_VerifyAsync(value, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTextureResource impl_IPrinting3DModelTexture<D>::TextureResource() const
{
    Windows::Graphics::Printing3D::Printing3DTextureResource value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->get_TextureResource(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DModelTexture<D>::TextureResource(const Windows::Graphics::Printing3D::Printing3DTextureResource & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->put_TextureResource(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior impl_IPrinting3DModelTexture<D>::TileStyleU() const
{
    Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value {};
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->get_TileStyleU(&value));
    return value;
}

template <typename D> void impl_IPrinting3DModelTexture<D>::TileStyleU(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->put_TileStyleU(value));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior impl_IPrinting3DModelTexture<D>::TileStyleV() const
{
    Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value {};
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->get_TileStyleV(&value));
    return value;
}

template <typename D> void impl_IPrinting3DModelTexture<D>::TileStyleV(Windows::Graphics::Printing3D::Printing3DTextureEdgeBehavior value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModelTexture)->put_TileStyleV(value));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStreamWithContentType impl_IPrinting3DTextureResource<D>::TextureData() const
{
    Windows::Storage::Streams::IRandomAccessStreamWithContentType value;
    check_hresult(WINRT_SHIM(IPrinting3DTextureResource)->get_TextureData(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DTextureResource<D>::TextureData(const Windows::Storage::Streams::IRandomAccessStreamWithContentType & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTextureResource)->put_TextureData(get_abi(value)));
}

template <typename D> hstring impl_IPrinting3DTextureResource<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DTextureResource)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DTextureResource<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTextureResource)->put_Name(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DComponent impl_IPrinting3DComponentWithMatrix<D>::Component() const
{
    Windows::Graphics::Printing3D::Printing3DComponent value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DComponentWithMatrix)->get_Component(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponentWithMatrix<D>::Component(const Windows::Graphics::Printing3D::Printing3DComponent & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponentWithMatrix)->put_Component(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::float4x4 impl_IPrinting3DComponentWithMatrix<D>::Matrix() const
{
    Windows::Foundation::Numerics::float4x4 value {};
    check_hresult(WINRT_SHIM(IPrinting3DComponentWithMatrix)->get_Matrix(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponentWithMatrix<D>::Matrix(const Windows::Foundation::Numerics::float4x4 & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponentWithMatrix)->put_Matrix(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DMesh impl_IPrinting3DComponent<D>::Mesh() const
{
    Windows::Graphics::Printing3D::Printing3DMesh value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_Mesh(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponent<D>::Mesh(const Windows::Graphics::Printing3D::Printing3DMesh & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->put_Mesh(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponentWithMatrix> impl_IPrinting3DComponent<D>::Components() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponentWithMatrix> value;
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_Components(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTextureResource impl_IPrinting3DComponent<D>::Thumbnail() const
{
    Windows::Graphics::Printing3D::Printing3DTextureResource value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponent<D>::Thumbnail(const Windows::Graphics::Printing3D::Printing3DTextureResource & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DObjectType impl_IPrinting3DComponent<D>::Type() const
{
    Windows::Graphics::Printing3D::Printing3DObjectType value {};
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_Type(&value));
    return value;
}

template <typename D> void impl_IPrinting3DComponent<D>::Type(Windows::Graphics::Printing3D::Printing3DObjectType value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->put_Type(value));
}

template <typename D> hstring impl_IPrinting3DComponent<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponent<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->put_Name(get_abi(value)));
}

template <typename D> hstring impl_IPrinting3DComponent<D>::PartNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->get_PartNumber(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DComponent<D>::PartNumber(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DComponent)->put_PartNumber(get_abi(value)));
}

template <typename D> hstring impl_IPrinting3DBaseMaterialStatics<D>::Abs() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterialStatics)->get_Abs(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPrinting3DBaseMaterialStatics<D>::Pla() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterialStatics)->get_Pla(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPrinting3DBaseMaterial<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterial)->get_Name(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DBaseMaterial<D>::Name(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterial)->put_Name(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DColorMaterial impl_IPrinting3DBaseMaterial<D>::Color() const
{
    Windows::Graphics::Printing3D::Printing3DColorMaterial value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterial)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DBaseMaterial<D>::Color(const Windows::Graphics::Printing3D::Printing3DColorMaterial & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterial)->put_Color(get_abi(value)));
}

template <typename D> uint32_t impl_IPrinting3DColorMaterial<D>::Value() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterial)->get_Value(&value));
    return value;
}

template <typename D> void impl_IPrinting3DColorMaterial<D>::Value(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterial)->put_Value(value));
}

template <typename D> Windows::UI::Color impl_IPrinting3DColorMaterial2<D>::Color() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterial2)->get_Color(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DColorMaterial2<D>::Color(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterial2)->put_Color(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DModelTexture impl_IPrinting3DTexture2CoordMaterial<D>::Texture() const
{
    Windows::Graphics::Printing3D::Printing3DModelTexture value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->get_Texture(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DTexture2CoordMaterial<D>::Texture(const Windows::Graphics::Printing3D::Printing3DModelTexture & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->put_Texture(get_abi(value)));
}

template <typename D> double impl_IPrinting3DTexture2CoordMaterial<D>::U() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->get_U(&value));
    return value;
}

template <typename D> void impl_IPrinting3DTexture2CoordMaterial<D>::U(double value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->put_U(value));
}

template <typename D> double impl_IPrinting3DTexture2CoordMaterial<D>::V() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->get_V(&value));
    return value;
}

template <typename D> void impl_IPrinting3DTexture2CoordMaterial<D>::V(double value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterial)->put_V(value));
}

template <typename D> Windows::Foundation::Collections::IVector<double> impl_IPrinting3DCompositeMaterial<D>::Values() const
{
    Windows::Foundation::Collections::IVector<double> value;
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterial)->get_Values(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<uint32_t> impl_IPrinting3DMultiplePropertyMaterial<D>::MaterialIndices() const
{
    Windows::Foundation::Collections::IVector<uint32_t> value;
    check_hresult(WINRT_SHIM(IPrinting3DMultiplePropertyMaterial)->get_MaterialIndices(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup impl_IPrinting3DBaseMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
{
    Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterialGroupFactory)->abi_Create(MaterialGroupId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterial> impl_IPrinting3DBaseMaterialGroup<D>::Bases() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterial> value;
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterialGroup)->get_Bases(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPrinting3DBaseMaterialGroup<D>::MaterialGroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DBaseMaterialGroup)->get_MaterialGroupId(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DColorMaterialGroup impl_IPrinting3DColorMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
{
    Windows::Graphics::Printing3D::Printing3DColorMaterialGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterialGroupFactory)->abi_Create(MaterialGroupId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterial> impl_IPrinting3DColorMaterialGroup<D>::Colors() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterial> value;
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterialGroup)->get_Colors(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPrinting3DColorMaterialGroup<D>::MaterialGroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DColorMaterialGroup)->get_MaterialGroupId(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup impl_IPrinting3DTexture2CoordMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
{
    Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterialGroupFactory)->abi_Create(MaterialGroupId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial> impl_IPrinting3DTexture2CoordMaterialGroup<D>::Texture2Coords() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterial> value;
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterialGroup)->get_Texture2Coords(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPrinting3DTexture2CoordMaterialGroup<D>::MaterialGroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterialGroup)->get_MaterialGroupId(&value));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DModelTexture impl_IPrinting3DTexture2CoordMaterialGroup2<D>::Texture() const
{
    Windows::Graphics::Printing3D::Printing3DModelTexture value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterialGroup2)->get_Texture(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DTexture2CoordMaterialGroup2<D>::Texture(const Windows::Graphics::Printing3D::Printing3DModelTexture & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DTexture2CoordMaterialGroup2)->put_Texture(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup impl_IPrinting3DCompositeMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
{
    Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroupFactory)->abi_Create(MaterialGroupId, put_abi(result)));
    return result;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup impl_IPrinting3DCompositeMaterialGroup2<D>::BaseMaterialGroup() const
{
    Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroup2)->get_BaseMaterialGroup(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DCompositeMaterialGroup2<D>::BaseMaterialGroup(const Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroup2)->put_BaseMaterialGroup(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterial> impl_IPrinting3DCompositeMaterialGroup<D>::Composites() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterial> value;
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroup)->get_Composites(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPrinting3DCompositeMaterialGroup<D>::MaterialGroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroup)->get_MaterialGroupId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<uint32_t> impl_IPrinting3DCompositeMaterialGroup<D>::MaterialIndices() const
{
    Windows::Foundation::Collections::IVector<uint32_t> value;
    check_hresult(WINRT_SHIM(IPrinting3DCompositeMaterialGroup)->get_MaterialIndices(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup impl_IPrinting3DMultiplePropertyMaterialGroupFactory<D>::Create(uint32_t MaterialGroupId) const
{
    Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup result { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DMultiplePropertyMaterialGroupFactory)->abi_Create(MaterialGroupId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial> impl_IPrinting3DMultiplePropertyMaterialGroup<D>::MultipleProperties() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterial> value;
    check_hresult(WINRT_SHIM(IPrinting3DMultiplePropertyMaterialGroup)->get_MultipleProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<uint32_t> impl_IPrinting3DMultiplePropertyMaterialGroup<D>::MaterialGroupIndices() const
{
    Windows::Foundation::Collections::IVector<uint32_t> value;
    check_hresult(WINRT_SHIM(IPrinting3DMultiplePropertyMaterialGroup)->get_MaterialGroupIndices(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IPrinting3DMultiplePropertyMaterialGroup<D>::MaterialGroupId() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DMultiplePropertyMaterialGroup)->get_MaterialGroupId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup> impl_IPrinting3DMaterial<D>::BaseGroups() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DBaseMaterialGroup> value;
    check_hresult(WINRT_SHIM(IPrinting3DMaterial)->get_BaseGroups(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterialGroup> impl_IPrinting3DMaterial<D>::ColorGroups() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DColorMaterialGroup> value;
    check_hresult(WINRT_SHIM(IPrinting3DMaterial)->get_ColorGroups(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup> impl_IPrinting3DMaterial<D>::Texture2CoordGroups() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTexture2CoordMaterialGroup> value;
    check_hresult(WINRT_SHIM(IPrinting3DMaterial)->get_Texture2CoordGroups(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup> impl_IPrinting3DMaterial<D>::CompositeGroups() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DCompositeMaterialGroup> value;
    check_hresult(WINRT_SHIM(IPrinting3DMaterial)->get_CompositeGroups(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup> impl_IPrinting3DMaterial<D>::MultiplePropertyGroups() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMultiplePropertyMaterialGroup> value;
    check_hresult(WINRT_SHIM(IPrinting3DMaterial)->get_MultiplePropertyGroups(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPrinting3DMeshVerificationResult<D>::IsValid() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPrinting3DMeshVerificationResult)->get_IsValid(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IPrinting3DMeshVerificationResult<D>::NonmanifoldTriangles() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IPrinting3DMeshVerificationResult)->get_NonmanifoldTriangles(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IPrinting3DMeshVerificationResult<D>::ReversedNormalTriangles() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IPrinting3DMeshVerificationResult)->get_ReversedNormalTriangles(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DModelUnit impl_IPrinting3DModel<D>::Unit() const
{
    Windows::Graphics::Printing3D::Printing3DModelUnit value {};
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Unit(&value));
    return value;
}

template <typename D> void impl_IPrinting3DModel<D>::Unit(Windows::Graphics::Printing3D::Printing3DModelUnit value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModel)->put_Unit(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DModelTexture> impl_IPrinting3DModel<D>::Textures() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DModelTexture> value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Textures(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMesh> impl_IPrinting3DModel<D>::Meshes() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DMesh> value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Meshes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponent> impl_IPrinting3DModel<D>::Components() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DComponent> value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Components(put_abi(value)));
    return value;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DMaterial impl_IPrinting3DModel<D>::Material() const
{
    Windows::Graphics::Printing3D::Printing3DMaterial value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Material(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DModel<D>::Material(const Windows::Graphics::Printing3D::Printing3DMaterial & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModel)->put_Material(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DComponent impl_IPrinting3DModel<D>::Build() const
{
    Windows::Graphics::Printing3D::Printing3DComponent value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Build(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DModel<D>::Build(const Windows::Graphics::Printing3D::Printing3DComponent & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModel)->put_Build(get_abi(value)));
}

template <typename D> hstring impl_IPrinting3DModel<D>::Version() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Version(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3DModel<D>::Version(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DModel)->put_Version(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IPrinting3DModel<D>::RequiredExtensions() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_RequiredExtensions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMap<hstring, hstring> impl_IPrinting3DModel<D>::Metadata() const
{
    Windows::Foundation::Collections::IMap<hstring, hstring> value;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->get_Metadata(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPrinting3DModel<D>::RepairAsync() const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel)->abi_RepairAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Graphics::Printing3D::Printing3DModel impl_IPrinting3DModel<D>::Clone() const
{
    Windows::Graphics::Printing3D::Printing3DModel value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3DModel)->abi_Clone(put_abi(value)));
    return value;
}

template <typename D> double impl_IPrinting3DFaceReductionOptions<D>::MaxReductionArea() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->get_MaxReductionArea(&value));
    return value;
}

template <typename D> void impl_IPrinting3DFaceReductionOptions<D>::MaxReductionArea(double value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->put_MaxReductionArea(value));
}

template <typename D> uint32_t impl_IPrinting3DFaceReductionOptions<D>::TargetTriangleCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->get_TargetTriangleCount(&value));
    return value;
}

template <typename D> void impl_IPrinting3DFaceReductionOptions<D>::TargetTriangleCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->put_TargetTriangleCount(value));
}

template <typename D> double impl_IPrinting3DFaceReductionOptions<D>::MaxEdgeLength() const
{
    double value {};
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->get_MaxEdgeLength(&value));
    return value;
}

template <typename D> void impl_IPrinting3DFaceReductionOptions<D>::MaxEdgeLength(double value) const
{
    check_hresult(WINRT_SHIM(IPrinting3DFaceReductionOptions)->put_MaxEdgeLength(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPrinting3DModel2<D>::TryPartialRepairAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_TryPartialRepairAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IPrinting3DModel2<D>::TryPartialRepairAsync(const Windows::Foundation::TimeSpan & maxWaitTime) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_TryPartialRepairWithTimeAsync(get_abi(maxWaitTime), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<bool, double> impl_IPrinting3DModel2<D>::TryReduceFacesAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<bool, double> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_TryReduceFacesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<bool, double> impl_IPrinting3DModel2<D>::TryReduceFacesAsync(const Windows::Graphics::Printing3D::Printing3DFaceReductionOptions & printing3DFaceReductionOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<bool, double> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_TryReduceFacesWithOptionsAsync(get_abi(printing3DFaceReductionOptions), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<bool, double> impl_IPrinting3DModel2<D>::TryReduceFacesAsync(const Windows::Graphics::Printing3D::Printing3DFaceReductionOptions & printing3DFaceReductionOptions, const Windows::Foundation::TimeSpan & maxWait) const
{
    Windows::Foundation::IAsyncOperationWithProgress<bool, double> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_TryReduceFacesWithOptionsAndTimeAsync(get_abi(printing3DFaceReductionOptions), get_abi(maxWait), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<bool, double> impl_IPrinting3DModel2<D>::RepairWithProgressAsync() const
{
    Windows::Foundation::IAsyncOperationWithProgress<bool, double> operation;
    check_hresult(WINRT_SHIM(IPrinting3DModel2)->abi_RepairWithProgressAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3D3MFPackage> impl_IPrinting3D3MFPackageStatics<D>::LoadAsync(const Windows::Storage::Streams::IRandomAccessStream & value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3D3MFPackage> operation;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackageStatics)->abi_LoadAsync(get_abi(value), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> impl_IPrinting3D3MFPackage<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> operation;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->abi_SaveAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IPrinting3D3MFPackage<D>::PrintTicket() const
{
    Windows::Storage::Streams::IRandomAccessStream value;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->get_PrintTicket(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3D3MFPackage<D>::PrintTicket(const Windows::Storage::Streams::IRandomAccessStream & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->put_PrintTicket(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IPrinting3D3MFPackage<D>::ModelPart() const
{
    Windows::Storage::Streams::IRandomAccessStream value;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->get_ModelPart(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3D3MFPackage<D>::ModelPart(const Windows::Storage::Streams::IRandomAccessStream & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->put_ModelPart(get_abi(value)));
}

template <typename D> Windows::Graphics::Printing3D::Printing3DTextureResource impl_IPrinting3D3MFPackage<D>::Thumbnail() const
{
    Windows::Graphics::Printing3D::Printing3DTextureResource value { nullptr };
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->get_Thumbnail(put_abi(value)));
    return value;
}

template <typename D> void impl_IPrinting3D3MFPackage<D>::Thumbnail(const Windows::Graphics::Printing3D::Printing3DTextureResource & value) const
{
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->put_Thumbnail(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTextureResource> impl_IPrinting3D3MFPackage<D>::Textures() const
{
    Windows::Foundation::Collections::IVector<Windows::Graphics::Printing3D::Printing3DTextureResource> value;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->get_Textures(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DModel> impl_IPrinting3D3MFPackage<D>::LoadModelFromPackageAsync(const Windows::Storage::Streams::IRandomAccessStream & value) const
{
    Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3DModel> operation;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->abi_LoadModelFromPackageAsync(get_abi(value), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPrinting3D3MFPackage<D>::SaveModelToPackageAsync(const Windows::Graphics::Printing3D::Printing3DModel & value) const
{
    Windows::Foundation::IAsyncAction operation;
    check_hresult(WINRT_SHIM(IPrinting3D3MFPackage)->abi_SaveModelToPackageAsync(get_abi(value), put_abi(operation)));
    return operation;
}

inline Windows::Graphics::Printing3D::Print3DManager Print3DManager::GetForCurrentView()
{
    return get_activation_factory<Print3DManager, IPrint3DManagerStatics>().GetForCurrentView();
}

inline Windows::Foundation::IAsyncOperation<bool> Print3DManager::ShowPrintUIAsync()
{
    return get_activation_factory<Print3DManager, IPrint3DManagerStatics>().ShowPrintUIAsync();
}

inline Printing3D3MFPackage::Printing3D3MFPackage() :
    Printing3D3MFPackage(activate_instance<Printing3D3MFPackage>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Graphics::Printing3D::Printing3D3MFPackage> Printing3D3MFPackage::LoadAsync(const Windows::Storage::Streams::IRandomAccessStream & value)
{
    return get_activation_factory<Printing3D3MFPackage, IPrinting3D3MFPackageStatics>().LoadAsync(value);
}

inline Printing3DBaseMaterial::Printing3DBaseMaterial() :
    Printing3DBaseMaterial(activate_instance<Printing3DBaseMaterial>())
{}

inline hstring Printing3DBaseMaterial::Abs()
{
    return get_activation_factory<Printing3DBaseMaterial, IPrinting3DBaseMaterialStatics>().Abs();
}

inline hstring Printing3DBaseMaterial::Pla()
{
    return get_activation_factory<Printing3DBaseMaterial, IPrinting3DBaseMaterialStatics>().Pla();
}

inline Printing3DBaseMaterialGroup::Printing3DBaseMaterialGroup(uint32_t MaterialGroupId) :
    Printing3DBaseMaterialGroup(get_activation_factory<Printing3DBaseMaterialGroup, IPrinting3DBaseMaterialGroupFactory>().Create(MaterialGroupId))
{}

inline Printing3DColorMaterial::Printing3DColorMaterial() :
    Printing3DColorMaterial(activate_instance<Printing3DColorMaterial>())
{}

inline Printing3DColorMaterialGroup::Printing3DColorMaterialGroup(uint32_t MaterialGroupId) :
    Printing3DColorMaterialGroup(get_activation_factory<Printing3DColorMaterialGroup, IPrinting3DColorMaterialGroupFactory>().Create(MaterialGroupId))
{}

inline Printing3DComponent::Printing3DComponent() :
    Printing3DComponent(activate_instance<Printing3DComponent>())
{}

inline Printing3DComponentWithMatrix::Printing3DComponentWithMatrix() :
    Printing3DComponentWithMatrix(activate_instance<Printing3DComponentWithMatrix>())
{}

inline Printing3DCompositeMaterial::Printing3DCompositeMaterial() :
    Printing3DCompositeMaterial(activate_instance<Printing3DCompositeMaterial>())
{}

inline Printing3DCompositeMaterialGroup::Printing3DCompositeMaterialGroup(uint32_t MaterialGroupId) :
    Printing3DCompositeMaterialGroup(get_activation_factory<Printing3DCompositeMaterialGroup, IPrinting3DCompositeMaterialGroupFactory>().Create(MaterialGroupId))
{}

inline Printing3DFaceReductionOptions::Printing3DFaceReductionOptions() :
    Printing3DFaceReductionOptions(activate_instance<Printing3DFaceReductionOptions>())
{}

inline Printing3DMaterial::Printing3DMaterial() :
    Printing3DMaterial(activate_instance<Printing3DMaterial>())
{}

inline Printing3DMesh::Printing3DMesh() :
    Printing3DMesh(activate_instance<Printing3DMesh>())
{}

inline Printing3DModel::Printing3DModel() :
    Printing3DModel(activate_instance<Printing3DModel>())
{}

inline Printing3DModelTexture::Printing3DModelTexture() :
    Printing3DModelTexture(activate_instance<Printing3DModelTexture>())
{}

inline Printing3DMultiplePropertyMaterial::Printing3DMultiplePropertyMaterial() :
    Printing3DMultiplePropertyMaterial(activate_instance<Printing3DMultiplePropertyMaterial>())
{}

inline Printing3DMultiplePropertyMaterialGroup::Printing3DMultiplePropertyMaterialGroup(uint32_t MaterialGroupId) :
    Printing3DMultiplePropertyMaterialGroup(get_activation_factory<Printing3DMultiplePropertyMaterialGroup, IPrinting3DMultiplePropertyMaterialGroupFactory>().Create(MaterialGroupId))
{}

inline Printing3DTexture2CoordMaterial::Printing3DTexture2CoordMaterial() :
    Printing3DTexture2CoordMaterial(activate_instance<Printing3DTexture2CoordMaterial>())
{}

inline Printing3DTexture2CoordMaterialGroup::Printing3DTexture2CoordMaterialGroup(uint32_t MaterialGroupId) :
    Printing3DTexture2CoordMaterialGroup(get_activation_factory<Printing3DTexture2CoordMaterialGroup, IPrinting3DTexture2CoordMaterialGroupFactory>().Create(MaterialGroupId))
{}

inline Printing3DTextureResource::Printing3DTextureResource() :
    Printing3DTextureResource(activate_instance<Printing3DTextureResource>())
{}

}

}
#pragma warning(pop)
