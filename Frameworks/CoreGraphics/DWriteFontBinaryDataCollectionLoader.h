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

#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>

#import <Starboard.h>
#import <CoreGraphics/DWriteWrapper.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFData.h>

#import <unordered_map>

/**
 * Custom implementation of IDWriteFontCollectionLoader, which creates an IDWriteFontFileEnumerator to create font files
 * Which are used to create a font collection.  This is expected to be a singleton.
 */
class DWriteFontBinaryDataCollectionLoader
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                          IDWriteFontCollectionLoader> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite.DWriteFontBinaryDataCollectionLoader", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataCollectionLoader();

    HRESULT STDMETHODCALLTYPE CreateEnumeratorFromKey(_In_ IDWriteFactory* factory,
                                                      _In_ const void* collectionKey,
                                                      _In_ UINT32 collectionKeySize,
                                                      _Out_ IDWriteFontFileEnumerator** enumerator);

    // Adds/removes an array of font data from this collection loader's internal storage
    HRESULT AddDatas(CFArrayRef fontDatas, CFArrayRef* errors);
    HRESULT RemoveDatas(CFArrayRef fontDatas, CFArrayRef* errors);

private:
    struct __CFDataHashEqual {
        std::size_t operator()(const woc::unique_cf<CGDataProviderRef>& data) const {
            return CFHash(data.get());
        }

        bool operator()(const woc::unique_cf<CGDataProviderRef>& data1, const woc::unique_cf<CGDataProviderRef>& data2) const {
            return CFEqual(data1.get(), data2.get());
        }
    };

    // Hash set of CFDataRefs registered to this font collection loader through AddDatas(),
    // mapped to a IDWriteFontFile that was created using it
    // This latter element is lazily initialized when it is first requested, then cached in the map
    std::unordered_map<woc::unique_cf<CGDataProviderRef>, Microsoft::WRL::ComPtr<IDWriteFontFile>, __CFDataHashEqual, __CFDataHashEqual>
        m_fontDatas;

public:
    decltype(m_fontDatas)::iterator GetDataBegin();
    decltype(m_fontDatas)::iterator GetDataEnd();
    HRESULT GetFontFileAt(decltype(m_fontDatas)::iterator it, IDWriteFontFile** outFontFile);
};
