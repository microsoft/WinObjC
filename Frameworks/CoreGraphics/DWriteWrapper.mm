//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// #1207: Do not move this block, it has to come first for some reason
#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>

#import <CoreGraphics/DWriteWrapper.h>

#import <unordered_map>
#import <vector>
#import <functional>
#import <mutex>
#import <type_traits>

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper";
static const wchar_t* c_defaultUserLanguage = L"en-us";

// Static collection which holds all fonts registered by user programatically, through plist, etc.
static ComPtr<IDWriteFontCollection> _userCreatedFontCollection;
static std::mutex _userCreatedFontCollectionMutex;

/**
 * Private helper method to return the user set default locale string.
 *
 * @return use set locale string as wstring.
 */
static wstring __GetUserDefaultLocaleName() {
    wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
    int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    return wstring(defaultLocaleSuccess ? localeName : c_defaultUserLanguage);
}

/**
 * Private helper that creates an uppercase copy of a CFString
 */
static CFStringRef __CFStringCreateUppercaseCopy(CFStringRef string, CFLocaleRef locale) {
    CFMutableStringRef ret = CFStringCreateMutableCopy(nullptr, CFStringGetLength(string), string);
    CFStringUppercase(ret, locale);
    return ret;
}

/**
 * Private helper that creates an array of CFString family names from a font collection
 */
CFArrayRef __DWriteCopyFontFamilyNamesFromCollection(IDWriteFontCollection* fontCollection) {
    // Get the number of font families in the collection.
    uint32_t count = fontCollection->GetFontFamilyCount();
    woc::unique_cf<CFMutableArrayRef> fontFamilyNames(CFArrayCreateMutable(kCFAllocatorSystemDefault, count, &kCFTypeArrayCallBacks));
    for (uint32_t i = 0; i < count; ++i) {
        // Get the font family.
        ComPtr<IDWriteFontFamily> fontFamily;
        RETURN_NULL_IF_FAILED(fontCollection->GetFontFamily(i, &fontFamily));

        // Get a list of localized strings for the family name.
        ComPtr<IDWriteLocalizedStrings> familyNames;
        RETURN_NULL_IF_FAILED(fontFamily->GetFamilyNames(&familyNames));

        CFStringRef name = _CFStringFromLocalizedString(familyNames.Get());
        if (CFStringGetLength(name) == 0) {
            TraceError(TAG, L"Failed to convert the localized string to wide string.");
            continue;
        }

        CFArrayAppendValue(fontFamilyNames.get(), name);
    }

    return fontFamilyNames.release();
}

/**
 * Private helper that creates the IDWriteFontList for a given font family name
 */
HRESULT __DWriteGetFontListForFamilyName(CFStringRef familyName, IDWriteFontCollection* fontCollection, IDWriteFontList** outFontList) {
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    // Get the font family.
    CFIndex familyNameLength = CFStringGetLength(familyName);
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    CFStringGetCharacters(familyName, CFRangeMake(0, familyNameLength), unicharFamilyName.data());

    size_t index = 0;
    BOOL exists = FALSE;

    RETURN_IF_FAILED(fontCollection->FindFamilyName(reinterpret_cast<wchar_t*>(unicharFamilyName.data()), &index, &exists));

    // Trying to create with a nonexistent font
    RETURN_HR_IF(E_INVALIDARG, !exists);

    ComPtr<IDWriteFontFamily> fontFamily;
    RETURN_IF_FAILED(fontCollection->GetFontFamily(index, &fontFamily));

    RETURN_IF_FAILED(
        fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STRETCH_NORMAL, DWRITE_FONT_STYLE_NORMAL, outFontList));

    return S_OK;
}

/**
 * Private struct that exposes CFHash and CFEqual to an STL container
 */
struct __CFStringHashEqual {
    std::size_t operator()(const woc::unique_cf<CFStringRef>& item) const {
        return CFHash(item.get());
    }

    bool operator()(const woc::unique_cf<CFStringRef>& item1, const woc::unique_cf<CFStringRef>& item2) const {
        return CFEqual(item1.get(), item2.get());
    }
};

/**
 * Local typedef for map from font name to font properties
 */
using __DWritePropertiesMap =
    std::unordered_map<woc::unique_cf<CFStringRef>, std::shared_ptr<_DWriteFontProperties>, __CFStringHashEqual, __CFStringHashEqual>;

/**
 * Private helper to create a map of font names to properties for all fonts in a collection
 */
static __DWritePropertiesMap __CreatePropertiesMapForFontCollection(IDWriteFontCollection* fontCollection) {
    __DWritePropertiesMap ret;
    woc::unique_cf<CFLocaleRef> locale(CFLocaleCopyCurrent());
    woc::unique_cf<CFArrayRef> familyNames{ __DWriteCopyFontFamilyNamesFromCollection(fontCollection) };
    CFIndex familyCount = CFArrayGetCount(familyNames.get());
    for (size_t i = 0; i < familyCount; ++i) {
        CFStringRef familyName = static_cast<CFStringRef>(CFArrayGetValueAtIndex(familyNames.get(), i));
        ComPtr<IDWriteFontList> fontList;

        if (FAILED(__DWriteGetFontListForFamilyName(familyName, fontCollection, &fontList))) {
            continue;
        }

        size_t count = fontList->GetFontCount();

        for (size_t j = 0; j < count; j++) {
            ComPtr<IDWriteFont> font;
            if (FAILED(fontList->GetFont(j, &font))) {
                continue;
            }

            // For each font in that family, fill out a _DWriteFontProperties
            auto info = std::make_shared<_DWriteFontProperties>();
            ComPtr<IDWriteLocalizedStrings> displayName;
            ComPtr<IDWriteLocalizedStrings> postScriptName;
            BOOL exist;

            if (SUCCEEDED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &displayName, &exist)) && exist) {
                info->displayName.reset(__CFStringCreateUppercaseCopy(_CFStringFromLocalizedString(displayName.Get()), locale.get()));
                woc::unique_cf<CFStringRef> uppercaseNameKey(__CFStringCreateUppercaseCopy(info->displayName.get(), locale.get()));
                ret.emplace(std::move(uppercaseNameKey), info);
            }

            if (SUCCEEDED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME, &postScriptName, &exist)) && exist) {
                info->postScriptName.reset(static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(postScriptName.Get()))));
                woc::unique_cf<CFStringRef> uppercaseNameKey(__CFStringCreateUppercaseCopy(info->postScriptName.get(), locale.get()));
                ret.emplace(std::move(uppercaseNameKey), info);
            }

            info->familyName.reset(CFStringCreateCopy(nullptr, familyName));

            info->weight = font->GetWeight();
            info->stretch = font->GetStretch();
            info->style = font->GetStyle();
        }
    }

    return ret;
}

/**
 * Private static map, that maps display name and postscript name to a _DWriteFontProperties struct for the corresponding user defined font.
 */
static __DWritePropertiesMap s_userFontPropertiesMap;

/**
 * Helper method to convert IDWriteLocalizedStrings object to CFString object.
 *
 * @parameter localizedString IDWriteLocalizedStrings object to convert.
 *
 * @return CFString object.
 */
CFStringRef _CFStringFromLocalizedString(IDWriteLocalizedStrings* localizedString) {
    if (localizedString == NULL) {
        TraceError(TAG, L"The input parameter is invalid!");
        return nil;
    }

    // Get the default locale for this user.
    wstring localeName = __GetUserDefaultLocaleName();

    uint32_t index = 0;
    BOOL exists = FALSE;

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    RETURN_NULL_IF_FAILED(localizedString->FindLocaleName(localeName.c_str(), &index, &exists));
    if (!exists) {
        RETURN_NULL_IF_FAILED(localizedString->FindLocaleName(c_defaultUserLanguage, &index, &exists));
    }

    // If the specified locale doesn't exist, select the first on the list.
    if (!exists) {
        index = 0;
    }

    // Get the string length.
    uint32_t length = 0;
    RETURN_NULL_IF_FAILED(localizedString->GetStringLength(index, &length));

    // Get the string.
    vector<wchar_t> wcharString = std::vector<wchar_t>(length + 1, 0);
    RETURN_NULL_IF_FAILED(localizedString->GetString(index, wcharString.data(), length + 1));

    // Strip out unnecessary null terminator
    return (CFStringRef)CFAutorelease(
        CFStringCreateWithCharacters(kCFAllocatorSystemDefault, reinterpret_cast<UniChar*>(wcharString.data()), length));
}

/**
 * Helper method to retrieve font family names installed in the system.
 *
 * @return Immutable array of font family name strings that are installed in the system.
 */
CFArrayRef _DWriteCopyFontFamilyNames() {
    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_NULL_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    // Get the system font collection.
    ComPtr<IDWriteFontCollection> fontCollection;
    RETURN_NULL_IF_FAILED(dwriteFactory->GetSystemFontCollection(&fontCollection));
    woc::unique_cf<CFMutableArrayRef> systemFamilyNames{ (CFMutableArrayRef)__DWriteCopyFontFamilyNamesFromCollection(
        fontCollection.Get()) };
    std::lock_guard<std::mutex> guard(_userCreatedFontCollectionMutex);
    if (_userCreatedFontCollection) {
        woc::unique_cf<CFArrayRef> userFamilyNames{ __DWriteCopyFontFamilyNamesFromCollection(_userCreatedFontCollection.Get()) };
        CFArrayAppendArray(systemFamilyNames.get(), userFamilyNames.get(), { 0, CFArrayGetCount(userFamilyNames.get()) });
    }

    return systemFamilyNames.release();
}

/**
 * Helper method to retrieve names of individual fonts under a font family.
 */
CFArrayRef _DWriteCopyFontNamesForFamilyName(CFStringRef familyName) {
    woc::unique_cf<CFMutableArrayRef> fontNames(CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks));

    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_NULL_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));
    ComPtr<IDWriteFontCollection> systemFontCollection;
    RETURN_NULL_IF_FAILED(dwriteFactory->GetSystemFontCollection(&systemFontCollection));

    ComPtr<IDWriteFontList> fontList;
    if (FAILED(__DWriteGetFontListForFamilyName(familyName, systemFontCollection.Get(), &fontList))) {
        std::lock_guard<std::mutex> guard(_userCreatedFontCollectionMutex);
        RETURN_NULL_IF_FAILED(__DWriteGetFontListForFamilyName(familyName, _userCreatedFontCollection.Get(), &fontList));
    }

    size_t count = fontList->GetFontCount();

    for (size_t i = 0; i < count; i++) {
        ComPtr<IDWriteFont> font;
        RETURN_NULL_IF_FAILED(fontList->GetFont(i, &font));

        ComPtr<IDWriteLocalizedStrings> fullName;
        BOOL exist = FALSE;
        RETURN_NULL_IF_FAILED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &fullName, &exist));

        if (exist) {
            CFStringRef name = _CFStringFromLocalizedString(fullName.Get());
            if (CFStringGetLength(name) == 0) {
                TraceError(TAG, L"Failed to convert the localized string to wide string.");
                continue;
            }

            CFArrayAppendValue(fontNames.get(), name);
        }
    }

    return fontNames.release();
}

/**
 * Helper method that maps a font name to the name of its family.
 *
 * Note: This function currently uses a cache, meaning that fonts installed during runtime will not be reflected
 */
CFStringRef _DWriteGetFamilyNameForFontName(CFStringRef fontName) {
    return _DWriteGetFontPropertiesFromName(fontName)->familyName.get();
}

/**
 * Helper that parses a font name, and returns appropriate weight, stretch, style, and family name values
 */
std::shared_ptr<_DWriteFontProperties> _DWriteGetFontPropertiesFromName(CFStringRef fontName) {
    woc::unique_cf<CFLocaleRef> locale(CFLocaleCopyCurrent());
    woc::unique_cf<CFStringRef> upperFontName(__CFStringCreateUppercaseCopy(fontName, locale.get()));

    static const __DWritePropertiesMap systemFontPropertiesMap = []() -> __DWritePropertiesMap {
        ComPtr<IDWriteFactory> dwriteFactory;
        if (SUCCEEDED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory))) {
            // Get the system font collection.
            ComPtr<IDWriteFontCollection> fontCollection;
            if (SUCCEEDED(dwriteFactory->GetSystemFontCollection(&fontCollection))) {
                return __CreatePropertiesMapForFontCollection(fontCollection.Get());
            }
        }

        return {};
    }();

    const auto& info = systemFontPropertiesMap.find(upperFontName);
    if (info != systemFontPropertiesMap.end()) {
        return info->second;
    }
    const auto& userFontInfo = s_userFontPropertiesMap.find(upperFontName);
    if (userFontInfo != s_userFontPropertiesMap.end()) {
        return userFontInfo->second;
    }

    return std::make_shared<_DWriteFontProperties>();
}

/**
 * Creates a DWrite text format object using the system font collection
 */
HRESULT _DWriteCreateTextFormat(const wchar_t* fontFamilyName,
                                DWRITE_FONT_WEIGHT weight,
                                DWRITE_FONT_STYLE style,
                                DWRITE_FONT_STRETCH stretch,
                                float fontSize,
                                IDWriteTextFormat** outTextFormat) {
    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    return dwriteFactory->CreateTextFormat(fontFamilyName,
                                           nullptr,
                                           weight,
                                           style,
                                           stretch,
                                           fontSize,
                                           __GetUserDefaultLocaleName().data(),
                                           outTextFormat); //
}

/**
 * Helper that creates a IDWriteFontFamily object for a given family name
 */
HRESULT _DWriteCreateFontFamilyWithName(CFStringRef familyName, IDWriteFontFamily** outFontFamily) {
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    ComPtr<IDWriteFontCollection> systemFontCollection;
    RETURN_IF_FAILED(dwriteFactory->GetSystemFontCollection(&systemFontCollection));

    CFIndex familyNameLength = CFStringGetLength(familyName);
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    CFStringGetCharacters(familyName, CFRangeMake(0, familyNameLength), unicharFamilyName.data());

    size_t fontFamilyIndex;
    BOOL fontFamilyExists;

    RETURN_IF_FAILED(systemFontCollection->FindFamilyName(reinterpret_cast<const wchar_t*>(unicharFamilyName.data()),
                                                          &fontFamilyIndex,
                                                          &fontFamilyExists));

    if (fontFamilyExists) {
        return systemFontCollection->GetFontFamily(fontFamilyIndex, outFontFamily);
    }

    std::lock_guard<std::mutex> guard(_userCreatedFontCollectionMutex);
    RETURN_HR_IF(E_INVALIDARG, !_userCreatedFontCollection);
    RETURN_IF_FAILED(_userCreatedFontCollection->FindFamilyName(reinterpret_cast<const wchar_t*>(unicharFamilyName.data()),
                                                                &fontFamilyIndex,
                                                                &fontFamilyExists));

    RETURN_HR_IF(E_INVALIDARG, !fontFamilyExists);
    return _userCreatedFontCollection->GetFontFamily(fontFamilyIndex, outFontFamily);
}

/**
 * Helper function that creates an IDWriteFontFace object for a given font name.
 */
HRESULT _DWriteCreateFontFaceWithName(CFStringRef name, IDWriteFontFace** outFontFace) {
    // Parse the font name for font weight, stretch, and style
    // Eg: Bold, Condensed, Light, Italic
    std::shared_ptr<_DWriteFontProperties> properties = _DWriteGetFontPropertiesFromName(name);

    if (!properties->familyName.get()) {
        name = CFSTR("Segoe UI");
        properties = _DWriteGetFontPropertiesFromName(name);
    }

    RETURN_HR_IF_NULL(E_INVALIDARG, properties->familyName.get());

    ComPtr<IDWriteFontFamily> fontFamily;
    RETURN_IF_FAILED(_DWriteCreateFontFamilyWithName(properties->familyName.get(), &fontFamily));
    RETURN_HR_IF_NULL(E_INVALIDARG, fontFamily);

    ComPtr<IDWriteFont> font;
    RETURN_IF_FAILED(fontFamily->GetFirstMatchingFont(properties->weight, properties->stretch, properties->style, &font));

    return font->CreateFontFace(outFontFace);
}

/**
 * Gets an informational string as a CFString from a DWrite font face.
 */
CFStringRef _DWriteFontCopyInformationalString(const ComPtr<IDWriteFontFace>& fontFace,
                                               DWRITE_INFORMATIONAL_STRING_ID informationalStringId) {
    RETURN_NULL_IF(!fontFace);

    ComPtr<IDWriteFontFace3> dwriteFontFace3;
    RETURN_NULL_IF_FAILED(fontFace.As(&dwriteFontFace3));

    ComPtr<IDWriteLocalizedStrings> name;
    BOOL exists;

    RETURN_NULL_IF_FAILED(dwriteFontFace3->GetInformationalStrings(informationalStringId, &name, &exists));
    return exists ? static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get()))) : nullptr;
}

/**
 * Gets a font table as a CFDataRef from a DWrite font face
 */
CFDataRef _DWriteFontCopyTable(const ComPtr<IDWriteFontFace>& fontFace, uint32_t tag) {
    const void* tableData;
    uint32_t tableSize;
    void* tableContext;
    BOOL exists;

    RETURN_NULL_IF_FAILED(fontFace->TryGetFontTable(tag, &tableData, &tableSize, &tableContext, &exists));
    RETURN_NULL_IF(!exists);

    // Copy the font table's binary data to a CFDataRef
    woc::unique_cf<CFDataRef> ret(CFDataCreate(kCFAllocatorDefault, reinterpret_cast<const byte*>(tableData), tableSize));

    // As part of the contact for TryGetFontTable, tableContext must always be released via ReleaseFontTable
    if (tableContext) {
        fontFace->ReleaseFontTable(tableContext);
    }

    return ret.release();
}

/**
 * Helper function that gets the slant angle, in degrees, from a DWrite font face.
 */
CGFloat _DWriteFontGetSlantDegrees(const ComPtr<IDWriteFontFace>& fontFace) {
    ComPtr<IDWriteFontFace1> fontFace1;
    if (FAILED(fontFace.As(&fontFace1))) {
        return 0;
    }

    DWRITE_CARET_METRICS caretMetrics;
    fontFace1->GetCaretMetrics(&caretMetrics);
    if (caretMetrics.slopeRun && caretMetrics.slopeRise) {
        CGFloat riseOverRun = static_cast<CGFloat>(caretMetrics.slopeRise) / static_cast<CGFloat>(caretMetrics.slopeRun);
        return (atan(riseOverRun) * 180 / M_PI) - 90.0f; // Degrees returned by this function must be negative
    } else {
        // Avoid dividing by 0, skip math for dividing with 0
        return -0.0f;
    }
}

/**
 * Gets the accumulated bounding box of all the glyphs in a DWrite font face, as a CGRect
 * Returns in terms of design units
 */
CGRect _DWriteFontGetBoundingBox(const ComPtr<IDWriteFontFace>& fontFace) {
    ComPtr<IDWriteFontFace1> fontFace1;
    if (FAILED(fontFace.As(&fontFace1))) {
        return {};
    }

    DWRITE_FONT_METRICS1 fontMetrics;
    fontFace1->GetMetrics(&fontMetrics);

    // Convert from DWrite font metrics, which is in terms of top, left, right, and bottom,
    // to CGRect, which is in terms of origin and size.
    CGRect ret;
    ret.origin.x = fontMetrics.glyphBoxLeft;
    ret.origin.y = fontMetrics.glyphBoxBottom;
    ret.size.width = fontMetrics.glyphBoxRight - fontMetrics.glyphBoxLeft;
    ret.size.height = fontMetrics.glyphBoxTop - fontMetrics.glyphBoxBottom;

    return ret;
}

/**
 * Gets individual bounding boxes for specific glyphs in a DWrite font face, as a CGRect
 * Returns in terms of design units
 */
HRESULT _DWriteFontGetBoundingBoxesForGlyphs(
    const ComPtr<IDWriteFontFace>& fontFace, const CGGlyph* glyphs, CGRect* boundingRects, size_t count, bool isSideways) {
    std::vector<DWRITE_GLYPH_METRICS> glyphMetrics(count);

    HRESULT ret = fontFace->GetDesignGlyphMetrics(glyphs, count, glyphMetrics.data(), isSideways);
    RETURN_IF_FAILED(ret);

    // Convert from DWRITE_GLYPH_METRICS to CGRect
    std::transform(glyphMetrics.begin(), glyphMetrics.end(), boundingRects, [](DWRITE_GLYPH_METRICS metrics) {
        CGRect rect;
        rect.origin.x = metrics.leftSideBearing;

        // generally cast the unsigned advance width/height to signed to avoid underflow issues
        rect.origin.y = metrics.verticalOriginY - static_cast<int32_t>(metrics.advanceHeight) + metrics.bottomSideBearing;
        rect.size.width = static_cast<int32_t>(metrics.advanceWidth) - (metrics.leftSideBearing + metrics.rightSideBearing);
        rect.size.height = static_cast<int32_t>(metrics.advanceHeight) - (metrics.bottomSideBearing + metrics.topSideBearing);

        return rect;
    });

    return ret;
}

/**
 * Custom implementation of IDWriteFontFileStream that implements Read in terms of an underlying CFDataRef
 *
 * While IDWriteFontFileStream normally frees its underlying data bit by bit through ReleaseFileFragment(),
 * for WinObjC purposes, it is easier to rely on existing mechanisms for CFData's destruction.
 * Thus, this class releases its CFData all at once, at the time of its destruction.
 */
class DWriteFontBinaryDataStream : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontFileStream> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataStream() {
    }

    HRESULT RuntimeClassInitialize(CFDataRef data) {
        CFRetain(data);
        _data.reset(data);

        // Just use current time for _lastWriteTime
        FILETIME fileTime;
        GetSystemTimeAsFileTime(&fileTime);

        // Concat filetime into a single uint64_t
        _lastWriteTime = 0;
        _lastWriteTime |= static_cast<uint64_t>(fileTime.dwLowDateTime);
        _lastWriteTime |= static_cast<uint64_t>(fileTime.dwHighDateTime) << 32;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetFileSize(_Out_ uint64_t* fileSize) {
        RETURN_HR_IF_NULL(E_INVALIDARG, fileSize);
        *fileSize = CFDataGetLength(_data.get());
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetLastWriteTime(_Out_ uint64_t* lastWriteTime) {
        RETURN_HR_IF_NULL(E_INVALIDARG, lastWriteTime);
        *lastWriteTime = _lastWriteTime;
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE ReadFileFragment(_Out_ const void** fragmentStart,
                                               uint64_t fileOffset,
                                               uint64_t fragmentSize,
                                               _Out_ void** fragmentContext) {
        if (fileOffset + fragmentSize > CFDataGetLength(_data.get())) {
            return E_INVALIDARG;
        }

        if (fragmentStart) {
            const uint8_t* underlyingBuffer = CFDataGetBytePtr(_data.get());
            *fragmentStart = reinterpret_cast<const void*>(&(underlyingBuffer[fileOffset]));
        }

        if (fragmentContext) {
            // Deliberately unused: this is meant to be passed to ReleaseFileFragment() below to free part of the data,
            // but this stream frees all the underlying CFData at once
            *fragmentContext = nullptr;
        }

        return S_OK;
    };

    void STDMETHODCALLTYPE ReleaseFileFragment(void* fragmentContext){
        // Deliberate no-op: data is released alongside the _data member with the destruction of this object
    };

private:
    woc::unique_cf<CFDataRef> _data;
    uint64_t _lastWriteTime;
};

/**
 * Custom implementation of IDWriteFontFileLoader that loads a CGDataProviderRef as its font file
 */
class DWriteFontBinaryDataLoader : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontFileLoader> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataLoader() {
    }

    HRESULT RuntimeClassInitialize(CFDataRef data) {
        CFRetain(data);
        _data.reset(data);
        return S_OK;
    }

    // Ignores first two params, just return the same kind of stream always
    // Stream returned is dictated by dataProvider passed in at initialization time
    HRESULT STDMETHODCALLTYPE CreateStreamFromKey(_In_ const void* fontFileReferenceKey,
                                                  uint32_t fontFileReferenceKeySize,
                                                  _Out_ IDWriteFontFileStream** fontFileStream) {
        RETURN_HR_IF_NULL(E_INVALIDARG, fontFileStream);

        ComPtr<DWriteFontBinaryDataStream> ret;
        RETURN_IF_FAILED(MakeAndInitialize<DWriteFontBinaryDataStream>(&ret, _data.get()));

        *fontFileStream = ret.Detach();
        return S_OK;
    }

private:
    woc::unique_cf<CFDataRef> _data;
};

// Implementation of IDwriteFontFileEnumerator, which enumerates over internal data and returns a font file
class DWriteFontFileEnumerator : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontFileEnumerator> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontFileEnumerator() {
    }

    HRESULT RuntimeClassInitialize(CFArrayRef fontDatas, std::vector<ComPtr<IDWriteFontFile>>* previouslyCreatedFiles) {
        CFRetain(fontDatas);
        m_fontDatas.reset(fontDatas);
        m_previouslyCreatedFiles = previouslyCreatedFiles;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetCurrentFontFile(_Out_ IDWriteFontFile** fontFile) {
        RETURN_HR_IF(E_ILLEGAL_METHOD_CALL, m_location < 0 || m_location > CFArrayGetCount(m_fontDatas.get()));

        if (0 <= m_location && m_location < m_previouslyCreatedFiles->size()) {
            m_previouslyCreatedFiles->at(m_location).CopyTo(fontFile);
        } else {
            ComPtr<IDWriteFactory> dwriteFactory;
            RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

            ComPtr<DWriteFontBinaryDataLoader> loader;
            RETURN_IF_FAILED(MakeAndInitialize<DWriteFontBinaryDataLoader>(&loader,
                                                                           static_cast<CFDataRef>(
                                                                               CFArrayGetValueAtIndex(m_fontDatas.get(), m_location))));
            RETURN_IF_FAILED(dwriteFactory->RegisterFontFileLoader(loader.Get()));

            int unused;
            RETURN_IF_FAILED(dwriteFactory->CreateCustomFontFileReference(&unused, sizeof(unused), loader.Get(), fontFile));
            m_previouslyCreatedFiles->emplace_back(*fontFile);
        }

        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE MoveNext(_Out_ BOOL* hasCurrentFile) {
        *hasCurrentFile = ++m_location < CFArrayGetCount(m_fontDatas.get());
        return S_OK;
    }

private:
    int m_location = -1;

    woc::unique_cf<CFArrayRef> m_fontDatas;
    std::vector<ComPtr<IDWriteFontFile>>* m_previouslyCreatedFiles;
};

/**
 * Implementation of IDWriteFontCollectionLoader, which creates an IDWriteFontFileEnumerator to create font files
 * Which are used to create a font collection.  This is expected to be a singleton
 */
class DWriteFontCollectionLoader : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontCollectionLoader> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontCollectionLoader() {
    }

    HRESULT RuntimeClassInitialize() {
        m_fontDatas.reset(CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks));
        m_fontDatasSet.reset(CFSetCreateMutable(nullptr, 0, &kCFTypeSetCallBacks));
        return S_OK;
    }

    HRESULT AddDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
        CFMutableArrayRef outErrors = nil;
        HRESULT ret = S_OK;
        if (errors) {
            outErrors = CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks);
            *errors = outErrors;
        }

        CFIndex count = CFArrayGetCount(fontDatas);
        for (CFIndex i = 0; i < count; ++i) {
            CFDataRef data = static_cast<CFDataRef>(CFArrayGetValueAtIndex(fontDatas, i));
            if (data) {
                if (CFSetContainsValue(m_fontDatasSet.get(), data)) {
                    __AppendErrorIfExists(outErrors, kCTFontManagerErrorAlreadyRegistered);
                    ret = S_FALSE;
                } else {
                    CFArrayAppendValue(m_fontDatas.get(), data);
                    CFSetAddValue(m_fontDatasSet.get(), data);
                    __AppendNullptrIfExists(outErrors);
                }
            } else {
                __AppendErrorIfExists(outErrors, kCTFontManagerErrorInvalidFontData);
                ret = S_FALSE;
            }
        }

        return ret;
    }

    HRESULT RemoveDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
        CFMutableArrayRef outErrors = nil;
        HRESULT ret = S_OK;
        if (errors) {
            outErrors = CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks);
            *errors = outErrors;
        }

        CFIndex count = CFArrayGetCount(fontDatas);
        for (CFIndex i = 0; i < count; ++i) {
            CFDataRef data = static_cast<CFDataRef>(CFArrayGetValueAtIndex(fontDatas, i));
            if (data) {
                if (CFSetContainsValue(m_fontDatasSet.get(), data)) {
                    CFSetRemoveValue(m_fontDatasSet.get(), data);
                    CFIndex index = CFArrayGetFirstIndexOfValue(m_fontDatas.get(), { 0, CFArrayGetCount(m_fontDatas.get()) }, data);
                    CFArrayRemoveValueAtIndex(m_fontDatas.get(), index);
                    m_previouslyCreatedFiles.erase(m_previouslyCreatedFiles.begin() + index);
                    __AppendNullptrIfExists(outErrors);
                } else {
                    __AppendErrorIfExists(outErrors, kCTFontManagerErrorNotRegistered);
                    ret = S_FALSE;
                }
            } else {
                __AppendErrorIfExists(outErrors, kCTFontManagerErrorInvalidFontData);
                ret = S_FALSE;
            }
        }

        return ret;
    }

    HRESULT STDMETHODCALLTYPE CreateEnumeratorFromKey(_In_ IDWriteFactory* factory,
                                                      _In_ const void* collectionKey,
                                                      _In_ UINT32 collectionKeySize,
                                                      _Out_ IDWriteFontFileEnumerator** enumerator) {
        MakeAndInitialize<DWriteFontFileEnumerator>(enumerator, m_fontDatas.get(), &m_previouslyCreatedFiles);
        return S_OK;
    }

private:
    // Array of CFDataRef containing data of fonts, in order of being added
    woc::unique_cf<CFMutableArrayRef> m_fontDatas;

    // Set of CFDataRef containing data of fonts, used to simplify checking if font has been added
    woc::unique_cf<CFMutableSetRef> m_fontDatasSet;

    // Array of previously created font files, which saves us from having to read a file multiple times
    std::vector<ComPtr<IDWriteFontFile>> m_previouslyCreatedFiles;

    /**
     * Private helpers to append a CFErrorRef or nullptr to the end of a CFMutableArray if it exists
     */
    static void __AppendErrorIfExists(CFMutableArrayRef errors, CFIndex errorCode) {
        if (errors) {
            woc::unique_cf<CFErrorRef> error{ CFErrorCreate(nullptr, kCFErrorDomainCocoa, errorCode, nullptr) };
            CFArrayAppendValue(errors, error.get());
        }
    }

    static void __AppendNullptrIfExists(CFMutableArrayRef errors) {
        if (errors) {
            CFArrayAppendValue(errors, nullptr);
        }
    }
};

// TLambda is a member function of our FontCollectionLoader which updates the internal state of the loader
// TLambda :: (DWriteFontCollectionLoader -> CFArrayRef -> CFArrayRef*) -> HRESULT
template <typename TLambda>
static HRESULT __DWriteUpdateUserCreatedFontCollection(CFArrayRef datas, CFArrayRef* errors, TLambda&& func) {
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    // Create singleton Font Collection loader, which will be shared for registering/unregistering fonts
    static ComPtr<DWriteFontCollectionLoader> loader;
    static HRESULT createdLoader = [](DWriteFontCollectionLoader** collectionLoader) {
        ComPtr<IDWriteFactory> dwriteFactory;
        RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));
        RETURN_IF_FAILED(MakeAndInitialize<DWriteFontCollectionLoader>(collectionLoader));
        RETURN_IF_FAILED(dwriteFactory->RegisterFontCollectionLoader(*collectionLoader));
        return S_OK;
    }(&loader);
    RETURN_IF_FAILED(createdLoader);

    // Call member function to update loader's font data
    // Still want to update font collection with whatever fonts succeeded, so return ret at end
    HRESULT ret = func(loader.Get(), datas, errors);

    // DWrite won't create a new font collection unless we provide a new key each time
    // So every time we modify the font collection increment the key
    static size_t collectionKey = 0;
    std::lock_guard<std::mutex> guard(_userCreatedFontCollectionMutex);
    RETURN_IF_FAILED(
        dwriteFactory->CreateCustomFontCollection(loader.Get(), &(++collectionKey), sizeof(collectionKey), &_userCreatedFontCollection));

    // Update s_userFontPropertiesMap with new values
    s_userFontPropertiesMap = __CreatePropertiesMapForFontCollection(_userCreatedFontCollection.Get());

    return ret;
}

// Registers user defined fonts to a collection so they can be created later
// Expects datas to be array of CFDataRefs, errors to be out pointer to array of CFErrorRef
HRESULT _DWriteRegisterFontsWithDatas(CFArrayRef datas, CFArrayRef* errors) {
    return __DWriteUpdateUserCreatedFontCollection(datas, errors, std::mem_fn(&DWriteFontCollectionLoader::AddDatas));
}

// Unregisters user defined fonts to a collection so they can be created later
// Expects datas to be array of CFDataRefs, errors to be out pointer to array of CFErrorRef
HRESULT _DWriteUnregisterFontsWithDatas(CFArrayRef datas, CFArrayRef* errors) {
    return __DWriteUpdateUserCreatedFontCollection(datas, errors, std::mem_fn(&DWriteFontCollectionLoader::RemoveDatas));
}

/**
 * Creates an IDWriteFontFace by attempting to use a CGDataProviderRef as a font file
 */
HRESULT _DWriteCreateFontFaceWithData(CFDataRef data, IDWriteFontFace** outFontFace) {
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    ComPtr<IDWriteFontFileLoader> dwriteDataLoader;
    RETURN_IF_FAILED(MakeAndInitialize<DWriteFontBinaryDataLoader>(&dwriteDataLoader, data));

    RETURN_IF_FAILED(dwriteFactory->RegisterFontFileLoader(dwriteDataLoader.Get()));

    HRESULT createdFont = [&dwriteFactory, &dwriteDataLoader, outFontFace]() {
        ComPtr<IDWriteFontFile> fontFile;

        // First two params are not used (see DWriteFontBinaryDataLoader::CreateStreamFromKey())
        // However, CreateCustomFontFileReference throws E_INVALIDARG if null is passed for the first parameter
        // Pass in a pointer to an arbitrary, unused key, to get around this.
        int unusedKey;
        RETURN_IF_FAILED(dwriteFactory->CreateCustomFontFileReference(&unusedKey, sizeof(unusedKey), dwriteDataLoader.Get(), &fontFile));

        // Analyze the font file for creating a font face
        BOOL isSupportedFontType;
        DWRITE_FONT_FILE_TYPE fontFileType;
        DWRITE_FONT_FACE_TYPE fontFaceType;
        uint32_t numberOfFaces;
        RETURN_IF_FAILED(fontFile->Analyze(&isSupportedFontType, &fontFileType, &fontFaceType, &numberOfFaces));

        RETURN_HR_IF(E_INVALIDARG, !isSupportedFontType);
        RETURN_HR_IF(E_INVALIDARG, numberOfFaces == 0);

        IDWriteFontFile* fontFileArray[] = { fontFile.Get() };

        RETURN_IF_FAILED(dwriteFactory->CreateFontFace(fontFaceType,
                                                       1, // number of elements in fontFileArray
                                                       fontFileArray,
                                                       0, // Just use the first face
                                                       DWRITE_FONT_SIMULATIONS_NONE,
                                                       outFontFace));
        return S_OK;
    }();

    // Always try to unregister the font file loader, even if anything failed above
    // Just log the failure to unregister instead of failing the whole function, though -
    // Should be safe enough to continue even if this doesn't work out
    if (FAILED(dwriteFactory->UnregisterFontFileLoader(dwriteDataLoader.Get()))) {
        TraceError(TAG, L"Failed to unregister font file loader in _DWriteCreateFontFaceWithDataProvider");
    }

    RETURN_IF_FAILED(createdFont);

    return S_OK;
}