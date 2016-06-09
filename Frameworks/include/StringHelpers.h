//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#pragma once

#include "Starboard.h"

#ifdef __OBJC__
#import <Foundation/NSString.h>
#include <COMIncludes.h>
#endif

#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>

#ifdef __OBJC__
#include <COMIncludes_End.h>
#endif

#include <string>
#include <sstream>
#include <vector>

namespace Strings {

namespace Private {

// Dispatcher class template declaration for generically working with string types
template <typename T>
struct StringTraits;

// Dispatcher class template for generically working with std::wstrings
template <>
struct StringTraits<std::wstring> {
    typedef std::wstring CreationType;

    // Performs a conversion from a raw string of known length to std::wstring using the specified code page
    static std::wstring NarrowToWide(const char* value, size_t valueLength, unsigned int codePage) {
        if ((valueLength == 0) || !value) {
            return std::wstring();
        }

        // First get the length
        int length = ::MultiByteToWideChar(codePage, 0, value, valueLength, nullptr, 0);
        THROW_LAST_ERROR_IF_FALSE(length > 0);

        // Allocate a string to receive the conversion
        std::wstring result(length, '\0');

        // Perform the conversion, writing directly into the std::wstring buffer
        length = ::MultiByteToWideChar(codePage, 0, value, valueLength, &result[0], length);
        THROW_LAST_ERROR_IF_FALSE(length > 0);

        return result;
    }

    // Performs a conversion from raw string to std::wstring using the specified code page
    static std::wstring NarrowToWide(const char* value, unsigned int codePage) {
        return NarrowToWide(value, value ? ::strlen(value) : 0, codePage);
    }

    // Performs a conversion from std::string to std::wstring using the specified code page
    static std::wstring NarrowToWide(const std::string& value, unsigned int codePage) {
        return NarrowToWide(value.c_str(), value.length(), codePage);
    }

#ifdef __OBJC__

    // Performs a conversion from NSString to std::wstring using the specified code page
    static CreationType NarrowToWide(NSString* objcString, unsigned int codePage) {
        const UniChar* rawString = CFStringGetCharactersPtr(static_cast<CFStringRef>(objcString));

        if (rawString) {
            return std::wstring(reinterpret_cast<const wchar_t*>(rawString), CFStringGetLength(static_cast<CFStringRef>(objcString)));
        } else {
            std::wstring characters;
            characters.resize([objcString length]);
            [objcString getCharacters:reinterpret_cast<unichar*>(&characters[0])];
            return characters;
        }
    }

#endif // __OBJC__

    // Returns a const pointer to the start of the buffer
    static const wchar_t* Data(const std::wstring& string) {
        return string.c_str();
    }

    // Returns the size of the string
    static size_t Size(const std::wstring& string) {
        return string.size();
    }

    // Returns whether or not the string is empty
    static bool IsEmpty(const std::wstring& string) {
        return string.empty();
    }
};

#ifdef __OBJC__

// Dispatcher class template for generically working with NSStrings
template <>
struct StringTraits<NSString*> {
    typedef NSString* CreationType;

    // Performs a conversion from std::string to NSString* using the specified code page
    static NSString* NarrowToWide(_In_reads_(length) const char* value, size_t, unsigned int codePage) {
        if (codePage == CP_UTF8) {
            return [NSString stringWithCString:value encoding:NSUTF8StringEncoding];
        } else {
            // TODO: support other encodings.
            assert(false);
            return nullptr;
        }
    }

    // Performs a conversion from raw string to NSString* using the specified code page
    static NSString* NarrowToWide(const char* value, unsigned int codePage) {
        return NarrowToWide(value, value ? ::strlen(value) : 0, codePage);
    }

    // Performs a conversion from std::string to NSString* using the specified code page
    static NSString* NarrowToWide(const std::string& value, unsigned int codePage) {
        return NarrowToWide(value.c_str(), value.length(), codePage);
    }

    // Returns a const pointer to the start of the buffer
    static const char* Data(NSString* string) {
        return [string UTF8String];
    }

    // Returns the size of the string
    static size_t Size(NSString* string) {
        return [string length];
    }

    // Returns whether or not the string is empty
    static bool IsEmpty(NSString* string) {
        return ([string length] == 0);
    }
};

#endif // __OBJC__

// Dispatcher class template for generically working with HSTRINGS
template <>
struct StringTraits<HSTRING> {
    typedef Microsoft::WRL::Wrappers::HString CreationType;

    // Performs a conversion from std::string to HSTRING using the specified code page
    static CreationType NarrowToWide(_In_reads_(length) const char* value, size_t valueLength, unsigned int codePage) {
        if ((valueLength == 0) || !value) {
            return Microsoft::WRL::Wrappers::HString();
        }

        // First get the length
        int length = ::MultiByteToWideChar(codePage, 0, value, valueLength, nullptr, 0);
        THROW_LAST_ERROR_IF_FALSE(length > 0);

        // Allocate a string to receive the conversion
        std::wstring wstringResult(length, '\0');

        // Perform the conversion, writing directly into the std::wstring buffer
        length = ::MultiByteToWideChar(codePage, 0, value, valueLength, &wstringResult[0], length);
        THROW_LAST_ERROR_IF_FALSE(length > 0);

        // Unfortunately, there is no way to "take ownership" or create an empty string for a given length
        // so another copy has to be made.
        Microsoft::WRL::Wrappers::HString result;
        result.Set(wstringResult.c_str());

        return result;
    }

    // Performs a conversion from raw string to HSTRING using the specified code page
    static CreationType NarrowToWide(const char* value, unsigned int codePage) {
        return NarrowToWide(value, value ? ::strlen(value) : 0, codePage);
    }

    // Performs a conversion from std::string to HSTRING using the specified code page
    static CreationType NarrowToWide(const std::string& value, unsigned int codePage) {
        return NarrowToWide(value.c_str(), value.length(), codePage);
    }

#ifdef __OBJC__

    // Performs a conversion from NSString to HSTRING using the specified code page
    static CreationType NarrowToWide(NSString* objcString, unsigned int codePage) {
        const UniChar* rawString = CFStringGetCharactersPtr(static_cast<CFStringRef>(objcString));

        Microsoft::WRL::Wrappers::HString result;
        if (rawString) {
            result.Set(reinterpret_cast<const wchar_t*>(rawString), CFStringGetLength(static_cast<CFStringRef>(objcString)));
        } else {
            unsigned int length = [objcString length];

            if (length > 0) {
                std::vector<unichar*> characters(length);
                [objcString getCharacters:reinterpret_cast<unichar*>(&characters[0])];
                result.Set(reinterpret_cast<const wchar_t*>(characters.data()));
            }
        }

        return result;
    }

#endif // __OBJC__

    // Returns a const pointer to the start of the buffer
    static const wchar_t* Data(HSTRING string) {
        return ::WindowsGetStringRawBuffer(string, nullptr);
    }

    // Returns the size of the string
    static size_t Size(HSTRING string) {
        return ::WindowsGetStringLen(string);
    }

    // Returns whether or not the string is empty
    static bool IsEmpty(HSTRING string) {
        return !!::WindowsIsStringEmpty(string);
    }
};

// Dispatcher class template for generically working with const wchar_t arrays
template <unsigned int Count>
struct StringTraits<const wchar_t[Count]> {
    // Returns a const pointer to the start of the buffer
    static const wchar_t* Data(const wchar_t(&string)[Count]) {
        static_assert(Count > 0, "StringTraits<wchar_t[]> does not support empty arrays.");
        return &string[0];
    }
};

// Dispatcher class template for generically working with wchar_t arrays
template <unsigned int Count>
struct StringTraits<wchar_t[Count]> {
    // Returns a const pointer to the start of the buffer
    static const wchar_t* Data(const wchar_t(&string)[Count]) {
        static_assert(Count > 0, "StringTraits<wchar_t[]> does not support empty arrays.");
        return &string[0];
    }
};

// Dispatcher class template for generically working with const wchar_t* strings
template <>
struct StringTraits<const wchar_t*> {
    // Returns a const pointer to the start of the buffer
    static const wchar_t* Data(const wchar_t* string) {
        return string;
    }

    // Returns the size of the string
    static size_t Size(const wchar_t* string) {
        return string ? ::wcslen(string) : 0;
    }

    // Returns whether or not the string is empty
    static bool IsEmpty(const wchar_t* string) {
        return (string == nullptr) || (string[0] == L'\0');
    }
};

// Dispatcher class template for generically working with const char*
template <>
struct StringTraits<const char*> {
    // Returns a const pointer to the start of the buffer
    static const char* Data(const char* string) {
        return string;
    }

    // Returns the size of the string
    static size_t Size(char* string) {
        return string ? ::strlen(string) : 0;
    }

    // Returns whether or not the string is empty
    static bool IsEmpty(const char* string) {
        return (string == nullptr) || (string[0] == L'\0');
    }
};

// Dispatcher class template for generically working with char arrays
template <unsigned int Count>
struct StringTraits<char[Count]> {
    // Returns a const pointer to the start of the buffer
    static const char* Data(const char(&string)[Count]) {
        static_assert(Count > 0, "StringTraits<char[]> does not support empty arrays.");
        return &string[0];
    }
};

} /* Private */

// Helper function which converts a narrow string to a wide string.
template <typename TReturnType, unsigned int TCodePage = CP_UTF8, typename... TArgs>
typename Private::StringTraits<TReturnType>::CreationType NarrowToWide(TArgs... args) {
    try {
        return Private::StringTraits<TReturnType>::NarrowToWide(args..., TCodePage);
    }
    CATCH_THROW_NORMALIZED()
}

static std::string WideToNarrow(const wchar_t* string, size_t length, unsigned int codePage = CP_UTF8) {
    try {
        if (!length) {
            return std::string();
        }

        int resultLength = ::WideCharToMultiByte(codePage, 0, string, length, nullptr, 0, nullptr, nullptr);
        THROW_LAST_ERROR_IF_FALSE(resultLength > 0);

        // Allocate a string to receive the conversion
        std::string result(resultLength, '\0');

        // Perform the conversion, writing directly into the std::string buffer
        resultLength = ::WideCharToMultiByte(codePage, 0, string, length, &result[0], resultLength, nullptr, nullptr);
        THROW_LAST_ERROR_IF_FALSE(resultLength > 0);

        return result;
    }
    CATCH_THROW_NORMALIZED();
}

// Helper function which converts a wide string to a narrow string.
template <typename TString, unsigned int TCodePage = CP_UTF8>
std::string WideToNarrow(const TString& value) {
    using DecayedType = typename std::remove_reference<TString>::type;
    return WideToNarrow(Private::StringTraits<DecayedType>::Data(value), Private::StringTraits<DecayedType>::Size(value), TCodePage);
}

#ifdef __OBJC__

// Helper function which converts a wide string to an NSString.
template <typename TString, unsigned int TCodePage = CP_UTF8>
static NSString* WideToNSString(const TString& value) {
    return Private::StringTraits<NSString*>::NarrowToWide(WideToNarrow(value), TCodePage);
}

#endif

template <typename TString, typename... TArgs>
std::wstring Format(const TString& formatString, TArgs... args) {
    static const unsigned int c_maxStringLength = 4096;

    // Remove references from the passed-in type
    using DecayedType = typename std::remove_reference<TString>::type;

    wchar_t output[c_maxStringLength];
    int writeResult = std::swprintf(output, _countof(output), Private::StringTraits<DecayedType>::Data(formatString), args...);

    THROW_HR_IF_FALSE_MSG(HRESULT_FROM_WIN32(ERROR_BAD_CONFIGURATION), writeResult >= 0, "String could not be formatted properly.");

    return output;
}

template <typename TString, typename... TArgs>
std::string FormatNarrow(const TString& formatString, TArgs... args) {
    static const unsigned int c_maxStringLength = 4096;

    // Remove hats and references from the passed-in type
    typedef std::remove_reference<Client::Framework::TypeTraits::RemoveHat<TString>::type>::type DecayedType;

    char output[c_maxStringLength];
    int writeResult = std::snprintf(output, _countof(output), Private::StringTraits<DecayedType>::Data(formatString), args...);

    THROW_HR_IF_FALSE_MSG(HRESULT_FROM_WIN32(ERROR_BAD_CONFIGURATION), writeResult >= 0, "String could not be formatted properly.");

    return output;
}

// Splits a string based on the delimiter specified
inline std::vector<std::wstring> Split(const wchar_t* string, wchar_t delimiter) {
    std::vector<std::wstring> elements;
    std::wstringstream stringStream(string);
    std::wstring item;
    while (std::getline(stringStream, item, delimiter)) {
        elements.push_back(item);
    }

    return elements;
}

// Splits a string based on the delimiter specified
inline std::vector<std::wstring> Split(const std::wstring& string, wchar_t delimiter) {
    return Split(string.c_str(), delimiter);
}

// Returns the length of an std::wstring or similar
template <typename T>
size_t length(const T& string, decltype(string.length()) = 0) {
    return string.length();
}

// Returns the length of a raw string pointer
inline size_t length(const wchar_t* string) {
    return ::wcslen(string);
}

// Returns the length of a narrow raw string pointer
inline size_t length(const char* string) {
    return ::strlen(string);
}

// Checks if the string is empty
template <typename T>
bool IsEmpty(T& string) {
    return Private::StringTraits<T>::IsEmpty(string);
}

// Find and replace substrings in a string
template <typename TSource, typename TFind, typename TReplace>
void FindAndReplace(TSource& source, const TFind& find, const TReplace& replace) {
    size_t replaceLength = length(replace);
    size_t findLength = length(find);

    for (size_t pos = 0; (pos = source.find(find, pos)) != TSource::npos; pos += replaceLength) {
        source.replace(pos, findLength, replace);
    }
}

// Returns a container from a delimited string
template <typename TSource>
inline TSource ContainerFromDelimitedString(_In_ const std::wstring& delimitedString, _In_ wchar_t delimiter) {
    TSource result;
    auto stringEnd = delimitedString.cend();

    auto substringStart = delimitedString.cbegin();

    while (substringStart != stringEnd) {
        auto substringEnd = std::find(substringStart, stringEnd, delimiter);

        // Make sure the substring isn't zero-length before adding it
        if (substringStart != substringEnd) {
            result.emplace_back(substringStart, substringEnd);
        }

        substringStart = substringEnd;
        if (substringStart != stringEnd) {
            ++substringStart;
        }
    }

    return result;
}

// Returns a a vector from a delmited string
inline std::vector<std::wstring> VectorFromDelimitedString(_In_ const std::wstring& delimitedString, wchar_t delimiter) {
    return ContainerFromDelimitedString<std::vector<std::wstring>>(delimitedString, delimiter);
}

} // Strings
