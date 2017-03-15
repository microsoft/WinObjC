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

#import "DWriteFontCollectionHelper.h"

#import <vector>

#import <StringHelpers.h>

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteFontCollectionHelper";

CFMutableArrayRef DWriteFontCollectionHelper::CopyFontFamilyNames() {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    ComPtr<IDWriteFontCollection> fontCollection = GetFontCollection();
    if (!fontCollection) {
        // Return empty array for an empty font collection
        return CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);
    }

    // Get the number of font families in the collection.
    uint32_t count = fontCollection->GetFontFamilyCount();
    CFMutableArrayRef ret = CFArrayCreateMutable(kCFAllocatorDefault, count, &kCFTypeArrayCallBacks);
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

        CFArrayAppendValue(ret, name);
    }

    return ret;
}

CFMutableArrayRef DWriteFontCollectionHelper::CopyFontNamesForFamilyName(CFStringRef familyName) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    CFMutableArrayRef ret = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);

    ComPtr<IDWriteFontList> fontList;
    if (FAILED(_GetFontListForFamilyName(familyName, &fontList))) {
        return ret;
    }

    size_t fontCount = fontList->GetFontCount();
    for (size_t i = 0; i < fontCount; i++) {
        ComPtr<IDWriteFont> font;
        if (FAILED(fontList->GetFont(i, &font))) {
            continue;
        }

        ComPtr<IDWriteLocalizedStrings> fullName;
        BOOL exists;
        if (FAILED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &fullName, &exists))) {
            continue;
        }

        if (exists) {
            CFStringRef name = _CFStringFromLocalizedString(fullName.Get());
            if (CFStringGetLength(name) == 0) {
                TraceError(TAG, L"Failed to convert the localized string to wide string.");
                continue;
            }

            CFArrayAppendValue(ret, name);
        }
    }

    return ret;
}

std::shared_ptr<const _DWriteFontProperties> DWriteFontCollectionHelper::GetFontPropertiesFromUppercaseFontName(
    const woc::unique_cf<CFStringRef>& upperFontName) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    if (!m_propertiesMap) {
        _InitializePropertiesMap();
    }

    const auto& info = m_propertiesMap->find(upperFontName);
    if (info != m_propertiesMap->end()) {
        return info->second;
    }

    return nullptr;
}

HRESULT DWriteFontCollectionHelper::CreateFontFamilyWithName(const wchar_t* unicharFamilyName, IDWriteFontFamily** outFontFamily) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    ComPtr<IDWriteFontCollection> fontCollection = GetFontCollection();

    // If no/empty font collection, say that the font family couldn't be found
    // Use S_FALSE to represent 'not found'
    RETURN_HR_IF_NULL(S_FALSE, fontCollection);

    size_t fontFamilyIndex;
    BOOL fontFamilyExists;

    RETURN_IF_FAILED(fontCollection->FindFamilyName(unicharFamilyName, &fontFamilyIndex, &fontFamilyExists));
    if (fontFamilyExists) {
        return fontCollection->GetFontFamily(fontFamilyIndex, outFontFamily);
    }

    return S_FALSE;
}

HRESULT DWriteFontCollectionHelper::GetAvailableFonts(std::vector<ComPtr<IDWriteFont>>& outFontList) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    ComPtr<IDWriteFontCollection> fontCollection = GetFontCollection();
    RETURN_HR_IF_NULL(S_OK, fontCollection);

    const uint32_t familyCount = fontCollection->GetFontFamilyCount();
    for (uint32_t i = 0; i < familyCount; ++i) {
        ComPtr<IDWriteFontFamily> fontFamily;
        RETURN_IF_FAILED(fontCollection->GetFontFamily(i, &fontFamily));
        ComPtr<IDWriteFontList> fontList;
        RETURN_IF_FAILED(
            fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STRETCH_NORMAL, DWRITE_FONT_STYLE_NORMAL, &fontList));
        const uint32_t fontCount = fontList->GetFontCount();
        for (size_t j = 0; j < fontCount; ++j) {
            ComPtr<IDWriteFont> font;
            RETURN_IF_FAILED(fontList->GetFont(j, &font));
            outFontList.emplace_back(std::move(font));
        }
    }

    return S_OK;
}

HRESULT DWriteFontCollectionHelper::_GetFontListForFamilyName(CFStringRef familyName, IDWriteFontList** outFontList) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    ComPtr<IDWriteFontCollection> fontCollection = GetFontCollection();

    // If no/empty font collection, fail to return a font list
    // Use of E_FAIL rather than a more nuanced HRESULT is permissable due to this being a private function only used in
    // _InitializePropertiesMap()
    RETURN_HR_IF_NULL(E_FAIL, fontCollection);

    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    size_t index = 0;
    BOOL exists;

    const auto& unicharFamilyName = Strings::VectorFromCFString(familyName);
    const wchar_t* data = reinterpret_cast<const wchar_t*>(unicharFamilyName.data());
    RETURN_IF_FAILED(fontCollection->FindFamilyName(data, &index, &exists));

    // Trying to create with a nonexistent font
    RETURN_HR_IF(E_INVALIDARG, !exists);

    ComPtr<IDWriteFontFamily> fontFamily;
    RETURN_IF_FAILED(fontCollection->GetFontFamily(index, &fontFamily));

    RETURN_IF_FAILED(
        fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STRETCH_NORMAL, DWRITE_FONT_STYLE_NORMAL, outFontList));

    return S_OK;
}

void DWriteFontCollectionHelper::_InitializePropertiesMap() {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    // Initialize m_propertiesMap
    m_propertiesMap = std::make_shared<_DWriteFontPropertiesMap>();

    woc::unique_cf<CFArrayRef> familyNames{ CopyFontFamilyNames() };

    // Iterate over all the font families
    CFIndex familyCount = CFArrayGetCount(familyNames.get());
    for (size_t i = 0; i < familyCount; ++i) {
        CFStringRef familyName = static_cast<CFStringRef>(CFArrayGetValueAtIndex(familyNames.get(), i));

        ComPtr<IDWriteFontList> fontList;
        if (FAILED(_GetFontListForFamilyName(familyName, &fontList))) {
            continue;
        }

        // Iterate over each font in this family
        size_t fontCount = fontList->GetFontCount();
        for (size_t j = 0; j < fontCount; j++) {
            ComPtr<IDWriteFont> font;
            if (FAILED(fontList->GetFont(j, &font))) {
                continue;
            }

            // For each font, fill out a _DWriteFontProperties
            auto info = std::make_shared<_DWriteFontProperties>();
            ComPtr<IDWriteLocalizedStrings> displayName;
            ComPtr<IDWriteLocalizedStrings> postScriptName;
            BOOL exist;

            if (SUCCEEDED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &displayName, &exist)) && exist) {
                info->displayName.reset(_CFStringCreateUppercaseCopy(_CFStringFromLocalizedString(displayName.Get())));
                woc::unique_cf<CFStringRef> uppercaseNameKey(CFStringCreateCopy(kCFAllocatorDefault, info->displayName.get()));
                m_propertiesMap->emplace(std::move(uppercaseNameKey), info);
            }

            if (SUCCEEDED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME, &postScriptName, &exist)) && exist) {
                info->postScriptName.reset(static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(postScriptName.Get()))));
                woc::unique_cf<CFStringRef> uppercaseNameKey(_CFStringCreateUppercaseCopy(info->postScriptName.get()));
                m_propertiesMap->emplace(std::move(uppercaseNameKey), info);
            }

            info->familyName.reset(CFStringCreateCopy(nullptr, familyName));

            info->weight = font->GetWeight();
            info->stretch = font->GetStretch();
            info->style = font->GetStyle();
        }
    }
}
