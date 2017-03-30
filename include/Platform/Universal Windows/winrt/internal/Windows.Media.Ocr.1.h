// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Ocr.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Globalization.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Ocr {

struct __declspec(uuid("5a14bc41-5b76-3140-b680-8825562683ac")) __declspec(novtable) IOcrEngine : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RecognizeAsync(Windows::Graphics::Imaging::ISoftwareBitmap * bitmap, Windows::Foundation::IAsyncOperation<Windows::Media::Ocr::OcrResult> ** result) = 0;
    virtual HRESULT __stdcall get_RecognizerLanguage(Windows::Globalization::ILanguage ** value) = 0;
};

struct __declspec(uuid("5bffa85a-3384-3540-9940-699120d428a8")) __declspec(novtable) IOcrEngineStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MaxImageDimension(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AvailableRecognizerLanguages(Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> ** value) = 0;
    virtual HRESULT __stdcall abi_IsLanguageSupported(Windows::Globalization::ILanguage * language, bool * result) = 0;
    virtual HRESULT __stdcall abi_TryCreateFromLanguage(Windows::Globalization::ILanguage * language, Windows::Media::Ocr::IOcrEngine ** result) = 0;
    virtual HRESULT __stdcall abi_TryCreateFromUserProfileLanguages(Windows::Media::Ocr::IOcrEngine ** result) = 0;
};

struct __declspec(uuid("0043a16f-e31f-3a24-899c-d444bd088124")) __declspec(novtable) IOcrLine : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Words(Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrWord> ** value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("9bd235b2-175b-3d6a-92e2-388c206e2f63")) __declspec(novtable) IOcrResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Lines(Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrLine> ** value) = 0;
    virtual HRESULT __stdcall get_TextAngle(Windows::Foundation::IReference<double> ** value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("3c2a477a-5cd9-3525-ba2a-23d1e0a68a1d")) __declspec(novtable) IOcrWord : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_BoundingRect(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Ocr::OcrEngine> { using default_interface = Windows::Media::Ocr::IOcrEngine; };
template <> struct traits<Windows::Media::Ocr::OcrLine> { using default_interface = Windows::Media::Ocr::IOcrLine; };
template <> struct traits<Windows::Media::Ocr::OcrResult> { using default_interface = Windows::Media::Ocr::IOcrResult; };
template <> struct traits<Windows::Media::Ocr::OcrWord> { using default_interface = Windows::Media::Ocr::IOcrWord; };

}

namespace Windows::Media::Ocr {

template <typename D>
struct WINRT_EBO impl_IOcrEngine
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Ocr::OcrResult> RecognizeAsync(const Windows::Graphics::Imaging::SoftwareBitmap & bitmap) const;
    Windows::Globalization::Language RecognizerLanguage() const;
};

template <typename D>
struct WINRT_EBO impl_IOcrEngineStatics
{
    uint32_t MaxImageDimension() const;
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> AvailableRecognizerLanguages() const;
    bool IsLanguageSupported(const Windows::Globalization::Language & language) const;
    Windows::Media::Ocr::OcrEngine TryCreateFromLanguage(const Windows::Globalization::Language & language) const;
    Windows::Media::Ocr::OcrEngine TryCreateFromUserProfileLanguages() const;
};

template <typename D>
struct WINRT_EBO impl_IOcrLine
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrWord> Words() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IOcrResult
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Ocr::OcrLine> Lines() const;
    Windows::Foundation::IReference<double> TextAngle() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IOcrWord
{
    Windows::Foundation::Rect BoundingRect() const;
    hstring Text() const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Ocr::IOcrEngine>
{
    using abi = ABI::Windows::Media::Ocr::IOcrEngine;
    template <typename D> using consume = Windows::Media::Ocr::impl_IOcrEngine<D>;
};

template <> struct traits<Windows::Media::Ocr::IOcrEngineStatics>
{
    using abi = ABI::Windows::Media::Ocr::IOcrEngineStatics;
    template <typename D> using consume = Windows::Media::Ocr::impl_IOcrEngineStatics<D>;
};

template <> struct traits<Windows::Media::Ocr::IOcrLine>
{
    using abi = ABI::Windows::Media::Ocr::IOcrLine;
    template <typename D> using consume = Windows::Media::Ocr::impl_IOcrLine<D>;
};

template <> struct traits<Windows::Media::Ocr::IOcrResult>
{
    using abi = ABI::Windows::Media::Ocr::IOcrResult;
    template <typename D> using consume = Windows::Media::Ocr::impl_IOcrResult<D>;
};

template <> struct traits<Windows::Media::Ocr::IOcrWord>
{
    using abi = ABI::Windows::Media::Ocr::IOcrWord;
    template <typename D> using consume = Windows::Media::Ocr::impl_IOcrWord<D>;
};

template <> struct traits<Windows::Media::Ocr::OcrEngine>
{
    using abi = ABI::Windows::Media::Ocr::OcrEngine;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Ocr.OcrEngine"; }
};

template <> struct traits<Windows::Media::Ocr::OcrLine>
{
    using abi = ABI::Windows::Media::Ocr::OcrLine;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Ocr.OcrLine"; }
};

template <> struct traits<Windows::Media::Ocr::OcrResult>
{
    using abi = ABI::Windows::Media::Ocr::OcrResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Ocr.OcrResult"; }
};

template <> struct traits<Windows::Media::Ocr::OcrWord>
{
    using abi = ABI::Windows::Media::Ocr::OcrWord;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Ocr.OcrWord"; }
};

}

}
