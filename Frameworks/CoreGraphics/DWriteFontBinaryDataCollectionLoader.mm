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
        RETURN_HR_IF_NULL(E_POINTER, fontFile);
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
        RETURN_HR_IF_NULL(E_POINTER, hasCurrentFile);
        *hasCurrentFile = ++m_location < CFArrayGetCount(m_fontDatas.get());
        return S_OK;
    }

private:
    int m_location = -1;

    woc::unique_cf<CFArrayRef> m_fontDatas;
    std::vector<ComPtr<IDWriteFontFile>>* m_previouslyCreatedFiles;
};

// DWriteFontBinaryDataCollectionLoader member functions

HRESULT DWriteFontBinaryDataCollectionLoader::DWriteFontBinaryDataCollectionLoader::RuntimeClassInitialize() {
    m_fontDatas.reset(CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks));
    m_fontDatasSet.reset(CFSetCreateMutable(nullptr, 0, &kCFTypeSetCallBacks));
    return S_OK;
}

HRESULT STDMETHODCALLTYPE DWriteFontBinaryDataCollectionLoader::CreateEnumeratorFromKey(_In_ IDWriteFactory* factory,
                                                                                        _In_ const void* collectionKey,
                                                                                        _In_ UINT32 collectionKeySize,
                                                                                        _Out_ IDWriteFontFileEnumerator** enumerator) {
    MakeAndInitialize<DWriteFontFileEnumerator>(enumerator, m_fontDatas.get(), &m_previouslyCreatedFiles);
    return S_OK;
}

HRESULT DWriteFontBinaryDataCollectionLoader::AddDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
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

HRESULT DWriteFontBinaryDataCollectionLoader::RemoveDatas(CFArrayRef fontDatas, CFArrayRef* errors) {
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