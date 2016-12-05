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

#import "DWriteFontBinaryDataCollectionLoader.h"
#import "DWriteFontBinaryDataLoader.h"

#import <CoreFoundation/CFError.h>

using namespace Microsoft::WRL;

/**
 * Private helpers to append a CFErrorRef or nullptr to the end of a CFMutableArray if it exists
 */
static inline void __AppendErrorIfExists(CFMutableArrayRef errors, CFIndex errorCode) {
    if (errors) {
        woc::unique_cf<CFErrorRef> error{ CFErrorCreate(nullptr, kCFErrorDomainCocoa, errorCode, nullptr) };
        CFArrayAppendValue(errors, error.get());
    }
}

static inline void __AppendNullptrIfExists(CFMutableArrayRef errors) {
    if (errors) {
        CFArrayAppendValue(errors, nullptr);
    }
}

/**
 * Private class.
 * Custom implementation of IDWriteFontFileEnumerator, which enumerates over internal data and returns a font file
 */
class DWriteFontFileEnumerator : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontFileEnumerator> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite.DWriteFontFileEnumerator", TrustLevel::BaseTrust);

public:
    DWriteFontFileEnumerator(DWriteFontBinaryDataCollectionLoader* parent) {
        m_parent = parent;
    }

    HRESULT RuntimeClassInitialize() {
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetCurrentFontFile(_Out_ IDWriteFontFile** outFontFile) {
        return m_parent->GetFontFileAt(m_location, outFontFile);
    }

    HRESULT STDMETHODCALLTYPE MoveNext(_Out_ BOOL* hasCurrentFile) {
        RETURN_HR_IF_NULL(E_POINTER, hasCurrentFile);
        *hasCurrentFile = ++m_location < m_parent->GetFontFileCount();
        return S_OK;
    }

private:
    int m_location = -1;

    ComPtr<DWriteFontBinaryDataCollectionLoader> m_parent;
};

// DWriteFontBinaryDataCollectionLoader member functions

DWriteFontBinaryDataCollectionLoader::DWriteFontBinaryDataCollectionLoader() {
    m_fontDatasSet.reset(CFSetCreateMutable(nullptr, 0, &kCFTypeSetCallBacks));
}

HRESULT DWriteFontBinaryDataCollectionLoader::DWriteFontBinaryDataCollectionLoader::RuntimeClassInitialize() {
    return S_OK;
}

HRESULT STDMETHODCALLTYPE DWriteFontBinaryDataCollectionLoader::CreateEnumeratorFromKey(_In_ IDWriteFactory* factory,
                                                                                        _In_ const void* collectionKey,
                                                                                        _In_ UINT32 collectionKeySize,
                                                                                        _Out_ IDWriteFontFileEnumerator** enumerator) {
    *enumerator = Make<DWriteFontFileEnumerator>(this).Detach();
    return S_OK;
}

HRESULT DWriteFontBinaryDataCollectionLoader::AddDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
    // Don't bother creating this array if errors is null
    CFMutableArrayRef outErrors = errors ? CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks) : nil;
    HRESULT ret = S_OK;

    CFIndex count = CFArrayGetCount(fontDatas);
    for (CFIndex i = 0; i < count; ++i) {
        CFDataRef data = static_cast<CFDataRef>(CFArrayGetValueAtIndex(fontDatas, i));
        if (data) {
            if (CFSetContainsValue(m_fontDatasSet.get(), data)) {
                __AppendErrorIfExists(outErrors, kCTFontManagerErrorAlreadyRegistered);
                ret = S_FALSE;
            } else {
                m_fontDatas.push_back({});

                CFRetain(data);
                m_fontDatas.back().first.reset(data);

                CFSetAddValue(m_fontDatasSet.get(), data);
                __AppendNullptrIfExists(outErrors);
            }
        } else {
            __AppendErrorIfExists(outErrors, kCTFontManagerErrorInvalidFontData);
            ret = S_FALSE;
        }
    }

    if (errors) {
        *errors = outErrors;
    }

    return ret;
}

HRESULT DWriteFontBinaryDataCollectionLoader::RemoveDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
    // Don't bother creating this array if errors is null
    CFMutableArrayRef outErrors = errors ? CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks) : nil;
    HRESULT ret = S_OK;

    CFIndex count = CFArrayGetCount(fontDatas);
    for (CFIndex i = 0; i < count; ++i) {
        CFDataRef data = static_cast<CFDataRef>(CFArrayGetValueAtIndex(fontDatas, i));
        if (data) {
            if (CFSetContainsValue(m_fontDatasSet.get(), data)) {
                CFSetRemoveValue(m_fontDatasSet.get(), data);

                for (auto it = m_fontDatas.begin(); it != m_fontDatas.end(); ++it) {
                    if (CFEqual(it->first.get(), data)) {
                        m_fontDatas.erase(it);
                        break;
                    }
                }

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

    if (errors) {
        *errors = outErrors;
    }

    return ret;
}

HRESULT DWriteFontBinaryDataCollectionLoader::GetFontFileAt(int index, IDWriteFontFile** outFontFile) {
    RETURN_HR_IF_NULL(E_POINTER, outFontFile);
    RETURN_HR_IF(E_ILLEGAL_METHOD_CALL, index < 0 || index > m_fontDatas.size());

    auto& it = m_fontDatas.at(index);

    // Create the IDWriteFontFile in the cache, if it's not already cached
    if (!it.second) {
        ComPtr<IDWriteFactory> dwriteFactory;
        RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

        ComPtr<DWriteFontBinaryDataLoader> loader;
        RETURN_IF_FAILED(MakeAndInitialize<DWriteFontBinaryDataLoader>(&loader, it.first.get()));
        RETURN_IF_FAILED(dwriteFactory->RegisterFontFileLoader(loader.Get()));

        int unused;
        RETURN_IF_FAILED(dwriteFactory->CreateCustomFontFileReference(&unused, sizeof(unused), loader.Get(), &it.second));
    }

    return it.second.CopyTo(outFontFile);
}

size_t DWriteFontBinaryDataCollectionLoader::GetFontFileCount() {
    return m_fontDatas.size();
}