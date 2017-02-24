// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.Media.Ocr.3.h"
#include "Windows.Media.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::Ocr::IOcrEngine> : produce_base<D, Windows::Media::Ocr::IOcrEngine>
{
    HRESULT __stdcall abi_RecognizeAsync(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> bitmap, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::Ocr::OcrResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RecognizeAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&bitmap)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecognizerLanguage(impl::abi_arg_out<Windows::Globalization::ILanguage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecognizerLanguage());
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
struct produce<D, Windows::Media::Ocr::IOcrEngineStatics> : produce_base<D, Windows::Media::Ocr::IOcrEngineStatics>
{
    HRESULT __stdcall get_MaxImageDimension(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxImageDimension());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AvailableRecognizerLanguages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AvailableRecognizerLanguages());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsLanguageSupported(impl::abi_arg_in<Windows::Globalization::ILanguage> language, bool * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().IsLanguageSupported(*reinterpret_cast<const Windows::Globalization::Language *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateFromLanguage(impl::abi_arg_in<Windows::Globalization::ILanguage> language, impl::abi_arg_out<Windows::Media::Ocr::IOcrEngine> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCreateFromLanguage(*reinterpret_cast<const Windows::Globalization::Language *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateFromUserProfileLanguages(impl::abi_arg_out<Windows::Media::Ocr::IOcrEngine> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCreateFromUserProfileLanguages());
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
struct produce<D, Windows::Media::Ocr::IOcrLine> : produce_base<D, Windows::Media::Ocr::IOcrLine>
{
    HRESULT __stdcall get_Words(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrWord>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Words());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::Media::Ocr::IOcrResult> : produce_base<D, Windows::Media::Ocr::IOcrResult>
{
    HRESULT __stdcall get_Lines(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrLine>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Lines());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TextAngle(impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TextAngle());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::Media::Ocr::IOcrWord> : produce_base<D, Windows::Media::Ocr::IOcrWord>
{
    HRESULT __stdcall get_BoundingRect(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BoundingRect());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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

namespace Windows::Media::Ocr {

template <typename D> Windows::Foundation::Rect impl_IOcrWord<D>::BoundingRect() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(IOcrWord)->get_BoundingRect(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IOcrWord<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IOcrWord)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrWord> impl_IOcrLine<D>::Words() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrWord> value;
    check_hresult(WINRT_SHIM(IOcrLine)->get_Words(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IOcrLine<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IOcrLine)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrLine> impl_IOcrResult<D>::Lines() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrLine> value;
    check_hresult(WINRT_SHIM(IOcrResult)->get_Lines(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_IOcrResult<D>::TextAngle() const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(IOcrResult)->get_TextAngle(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IOcrResult<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IOcrResult)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::Ocr::OcrResult> impl_IOcrEngine<D>::RecognizeAsync(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Ocr::OcrResult> result;
    check_hresult(WINRT_SHIM(IOcrEngine)->abi_RecognizeAsync(get_abi(bitmap), put_abi(result)));
    return result;
}

template <typename D> Windows::Globalization::Language impl_IOcrEngine<D>::RecognizerLanguage() const
{
    Windows::Globalization::Language value { nullptr };
    check_hresult(WINRT_SHIM(IOcrEngine)->get_RecognizerLanguage(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IOcrEngineStatics<D>::MaxImageDimension() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IOcrEngineStatics)->get_MaxImageDimension(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> impl_IOcrEngineStatics<D>::AvailableRecognizerLanguages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> value;
    check_hresult(WINRT_SHIM(IOcrEngineStatics)->get_AvailableRecognizerLanguages(put_abi(value)));
    return value;
}

template <typename D> bool impl_IOcrEngineStatics<D>::IsLanguageSupported(const Windows::Globalization::Language & language) const
{
    bool result {};
    check_hresult(WINRT_SHIM(IOcrEngineStatics)->abi_IsLanguageSupported(get_abi(language), &result));
    return result;
}

template <typename D> Windows::Media::Ocr::OcrEngine impl_IOcrEngineStatics<D>::TryCreateFromLanguage(const Windows::Globalization::Language & language) const
{
    Windows::Media::Ocr::OcrEngine result { nullptr };
    check_hresult(WINRT_SHIM(IOcrEngineStatics)->abi_TryCreateFromLanguage(get_abi(language), put_abi(result)));
    return result;
}

template <typename D> Windows::Media::Ocr::OcrEngine impl_IOcrEngineStatics<D>::TryCreateFromUserProfileLanguages() const
{
    Windows::Media::Ocr::OcrEngine result { nullptr };
    check_hresult(WINRT_SHIM(IOcrEngineStatics)->abi_TryCreateFromUserProfileLanguages(put_abi(result)));
    return result;
}

inline uint32_t OcrEngine::MaxImageDimension()
{
    return get_activation_factory<OcrEngine, IOcrEngineStatics>().MaxImageDimension();
}

inline Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> OcrEngine::AvailableRecognizerLanguages()
{
    return get_activation_factory<OcrEngine, IOcrEngineStatics>().AvailableRecognizerLanguages();
}

inline bool OcrEngine::IsLanguageSupported(const Windows::Globalization::Language & language)
{
    return get_activation_factory<OcrEngine, IOcrEngineStatics>().IsLanguageSupported(language);
}

inline Windows::Media::Ocr::OcrEngine OcrEngine::TryCreateFromLanguage(const Windows::Globalization::Language & language)
{
    return get_activation_factory<OcrEngine, IOcrEngineStatics>().TryCreateFromLanguage(language);
}

inline Windows::Media::Ocr::OcrEngine OcrEngine::TryCreateFromUserProfileLanguages()
{
    return get_activation_factory<OcrEngine, IOcrEngineStatics>().TryCreateFromUserProfileLanguages();
}

}

}
#pragma warning(pop)
