// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Data.Pdf.3.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Data::Pdf::IPdfDocument> : produce_base<D, Windows::Data::Pdf::IPdfDocument>
{
    HRESULT __stdcall abi_GetPage(uint32_t pageIndex, impl::abi_arg_out<Windows::Data::Pdf::IPdfPage> pdfPage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pdfPage = detach_abi(this->shim().GetPage(pageIndex));
            return S_OK;
        }
        catch (...)
        {
            *pdfPage = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PageCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PageCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPasswordProtected(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPasswordProtected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Pdf::IPdfDocumentStatics> : produce_base<D, Windows::Data::Pdf::IPdfDocumentStatics>
{
    HRESULT __stdcall abi_LoadFromFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromFileWithPasswordAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> password, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromFileAsync(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file), *reinterpret_cast<const hstring *>(&password)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> inputStream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&inputStream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadFromStreamWithPasswordAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> inputStream, impl::abi_arg_in<hstring> password, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().LoadFromStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&inputStream), *reinterpret_cast<const hstring *>(&password)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Pdf::IPdfPage> : produce_base<D, Windows::Data::Pdf::IPdfPage>
{
    HRESULT __stdcall abi_RenderToStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> outputStream, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RenderToStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&outputStream)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderWithOptionsToStreamAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> outputStream, impl::abi_arg_in<Windows::Data::Pdf::IPdfPageRenderOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RenderToStreamAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&outputStream), *reinterpret_cast<const Windows::Data::Pdf::PdfPageRenderOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PreparePageAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().PreparePageAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Index(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Index());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Size(impl::abi_arg_out<Windows::Foundation::Size> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Dimensions(impl::abi_arg_out<Windows::Data::Pdf::IPdfPageDimensions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Dimensions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Rotation(Windows::Data::Pdf::PdfPageRotation * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Rotation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreferredZoom(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreferredZoom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Pdf::IPdfPageDimensions> : produce_base<D, Windows::Data::Pdf::IPdfPageDimensions>
{
    HRESULT __stdcall get_MediaBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MediaBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CropBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CropBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BleedBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BleedBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrimBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrimBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ArtBox(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ArtBox());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Data::Pdf::IPdfPageRenderOptions> : produce_base<D, Windows::Data::Pdf::IPdfPageRenderOptions>
{
    HRESULT __stdcall get_SourceRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceRect(impl::abi_arg_in<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRect(*reinterpret_cast<const Windows::Foundation::Rect *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DestinationWidth(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DestinationWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DestinationWidth(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DestinationHeight(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DestinationHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DestinationHeight(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DestinationHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BackgroundColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BackgroundColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BackgroundColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsIgnoringHighContrast(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsIgnoringHighContrast());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsIgnoringHighContrast(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsIgnoringHighContrast(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BitmapEncoderId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BitmapEncoderId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BitmapEncoderId(GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapEncoderId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Data::Pdf {

template <typename D> Windows::Foundation::Rect impl_IPdfPageDimensions<D>::MediaBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageDimensions)->get_MediaBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPdfPageDimensions<D>::CropBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageDimensions)->get_CropBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPdfPageDimensions<D>::BleedBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageDimensions)->get_BleedBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPdfPageDimensions<D>::TrimBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageDimensions)->get_TrimBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPdfPageDimensions<D>::ArtBox() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageDimensions)->get_ArtBox(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Rect impl_IPdfPageRenderOptions<D>::SourceRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_SourceRect(put_abi(value)));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::SourceRect(const Windows::Foundation::Rect & value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_SourceRect(get_abi(value)));
}

template <typename D> uint32_t impl_IPdfPageRenderOptions<D>::DestinationWidth() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_DestinationWidth(&value));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::DestinationWidth(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_DestinationWidth(value));
}

template <typename D> uint32_t impl_IPdfPageRenderOptions<D>::DestinationHeight() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_DestinationHeight(&value));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::DestinationHeight(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_DestinationHeight(value));
}

template <typename D> Windows::UI::Color impl_IPdfPageRenderOptions<D>::BackgroundColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_BackgroundColor(put_abi(value)));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::BackgroundColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_BackgroundColor(get_abi(value)));
}

template <typename D> bool impl_IPdfPageRenderOptions<D>::IsIgnoringHighContrast() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_IsIgnoringHighContrast(&value));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::IsIgnoringHighContrast(bool value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_IsIgnoringHighContrast(value));
}

template <typename D> GUID impl_IPdfPageRenderOptions<D>::BitmapEncoderId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->get_BitmapEncoderId(&value));
    return value;
}

template <typename D> void impl_IPdfPageRenderOptions<D>::BitmapEncoderId(GUID value) const
{
    check_hresult(WINRT_SHIM(IPdfPageRenderOptions)->put_BitmapEncoderId(value));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPdfPage<D>::RenderToStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & outputStream) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IPdfPage)->abi_RenderToStreamAsync(get_abi(outputStream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPdfPage<D>::RenderToStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & outputStream, const Windows::Data::Pdf::PdfPageRenderOptions & options) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IPdfPage)->abi_RenderWithOptionsToStreamAsync(get_abi(outputStream), get_abi(options), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IPdfPage<D>::PreparePageAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IPdfPage)->abi_PreparePageAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> uint32_t impl_IPdfPage<D>::Index() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPdfPage)->get_Index(&value));
    return value;
}

template <typename D> Windows::Foundation::Size impl_IPdfPage<D>::Size() const
{
    Windows::Foundation::Size value {};
    check_hresult(WINRT_SHIM(IPdfPage)->get_Size(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Pdf::PdfPageDimensions impl_IPdfPage<D>::Dimensions() const
{
    Windows::Data::Pdf::PdfPageDimensions value { nullptr };
    check_hresult(WINRT_SHIM(IPdfPage)->get_Dimensions(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Pdf::PdfPageRotation impl_IPdfPage<D>::Rotation() const
{
    Windows::Data::Pdf::PdfPageRotation value {};
    check_hresult(WINRT_SHIM(IPdfPage)->get_Rotation(&value));
    return value;
}

template <typename D> float impl_IPdfPage<D>::PreferredZoom() const
{
    float value {};
    check_hresult(WINRT_SHIM(IPdfPage)->get_PreferredZoom(&value));
    return value;
}

template <typename D> Windows::Data::Pdf::PdfPage impl_IPdfDocument<D>::GetPage(uint32_t pageIndex) const
{
    Windows::Data::Pdf::PdfPage pdfPage { nullptr };
    check_hresult(WINRT_SHIM(IPdfDocument)->abi_GetPage(pageIndex, put_abi(pdfPage)));
    return pdfPage;
}

template <typename D> uint32_t impl_IPdfDocument<D>::PageCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IPdfDocument)->get_PageCount(&value));
    return value;
}

template <typename D> bool impl_IPdfDocument<D>::IsPasswordProtected() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPdfDocument)->get_IsPasswordProtected(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> impl_IPdfDocumentStatics<D>::LoadFromFileAsync(const Windows::Storage::IStorageFile & file) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IPdfDocumentStatics)->abi_LoadFromFileAsync(get_abi(file), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> impl_IPdfDocumentStatics<D>::LoadFromFileAsync(const Windows::Storage::IStorageFile & file, hstring_view password) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IPdfDocumentStatics)->abi_LoadFromFileWithPasswordAsync(get_abi(file), get_abi(password), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> impl_IPdfDocumentStatics<D>::LoadFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & inputStream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IPdfDocumentStatics)->abi_LoadFromStreamAsync(get_abi(inputStream), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> impl_IPdfDocumentStatics<D>::LoadFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & inputStream, hstring_view password) const
{
    Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> asyncInfo;
    check_hresult(WINRT_SHIM(IPdfDocumentStatics)->abi_LoadFromStreamWithPasswordAsync(get_abi(inputStream), get_abi(password), put_abi(asyncInfo)));
    return asyncInfo;
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> PdfDocument::LoadFromFileAsync(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<PdfDocument, IPdfDocumentStatics>().LoadFromFileAsync(file);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> PdfDocument::LoadFromFileAsync(const Windows::Storage::IStorageFile & file, hstring_view password)
{
    return get_activation_factory<PdfDocument, IPdfDocumentStatics>().LoadFromFileAsync(file, password);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> PdfDocument::LoadFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & inputStream)
{
    return get_activation_factory<PdfDocument, IPdfDocumentStatics>().LoadFromStreamAsync(inputStream);
}

inline Windows::Foundation::IAsyncOperation<Windows::Data::Pdf::PdfDocument> PdfDocument::LoadFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & inputStream, hstring_view password)
{
    return get_activation_factory<PdfDocument, IPdfDocumentStatics>().LoadFromStreamAsync(inputStream, password);
}

inline PdfPageRenderOptions::PdfPageRenderOptions() :
    PdfPageRenderOptions(activate_instance<PdfPageRenderOptions>())
{}

}

}
#pragma warning(pop)
