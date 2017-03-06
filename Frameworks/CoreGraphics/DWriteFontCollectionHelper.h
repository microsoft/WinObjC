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

#pragma once

#import <CoreGraphics/DWriteWrapper.h>

#import <mutex>
#import <unordered_map>

/**
 * Struct that exposes CFHash and CFEqual to an STL container
 */
struct __CFStringHashEqual {
    std::size_t operator()(const woc::unique_cf<CFStringRef>& item) const {
        return CFHash(item.get());
    }

    bool operator()(const woc::unique_cf<CFStringRef>& item1, const woc::unique_cf<CFStringRef>& item2) const {
        return CFEqual(item1.get(), item2.get());
    }
};

using _DWriteFontPropertiesMap =
    std::unordered_map<woc::unique_cf<CFStringRef>, std::shared_ptr<const _DWriteFontProperties>, __CFStringHashEqual, __CFStringHashEqual>;

/**
 * A wrapper around an IDWriteFontCollection that provides mappings not directly available from the IDWriteFontCollection interface,
 * such as font name -> family name, postscript name -> font name, font name -> font weight, style,
 * by means of an internal cache.
 *
 * Concrete implementations must implement GetFontCollection(), which is expected to return an IDWriteFontCollection to work on.
 *
 * Thread-safe.
 */
class DWriteFontCollectionHelper {
public:
    DWriteFontCollectionHelper() {
    }

    CFMutableArrayRef CopyFontFamilyNames();
    CFMutableArrayRef CopyFontNamesForFamilyName(CFStringRef familyName);
    std::shared_ptr<const _DWriteFontProperties> GetFontPropertiesFromUppercaseFontName(const woc::unique_cf<CFStringRef>& upperFontName);
    HRESULT CreateFontFamilyWithName(const wchar_t* unicharFamilyName, IDWriteFontFamily** outFontFamily);
    HRESULT GetAvailableFonts(std::vector<Microsoft::WRL::ComPtr<IDWriteFont>>& outFontList);
    virtual Microsoft::WRL::ComPtr<IDWriteFontCollection> GetFontCollection() = 0;

protected:
    HRESULT _GetFontListForFamilyName(CFStringRef familyName, IDWriteFontList** outFontList);

    void _InitializePropertiesMap();
    std::shared_ptr<_DWriteFontPropertiesMap> m_propertiesMap;
    std::recursive_mutex m_lock;
};
