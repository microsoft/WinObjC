// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Ocr.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Ocr {

struct WINRT_EBO OcrEngine :
    Windows::Media::Ocr::IOcrEngine
{
    OcrEngine(std::nullptr_t) noexcept {}
    static uint32_t MaxImageDimension();
    static Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> AvailableRecognizerLanguages();
    static bool IsLanguageSupported(const Windows::Globalization::Language & language);
    static Windows::Media::Ocr::OcrEngine TryCreateFromLanguage(const Windows::Globalization::Language & language);
    static Windows::Media::Ocr::OcrEngine TryCreateFromUserProfileLanguages();
};

struct WINRT_EBO OcrLine :
    Windows::Media::Ocr::IOcrLine
{
    OcrLine(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OcrResult :
    Windows::Media::Ocr::IOcrResult
{
    OcrResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OcrWord :
    Windows::Media::Ocr::IOcrWord
{
    OcrWord(std::nullptr_t) noexcept {}
};

}

}
