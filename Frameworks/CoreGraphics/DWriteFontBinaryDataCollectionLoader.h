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

#import <vector>

/**
 * Custom implementation of IDWriteFontCollectionLoader, which creates an IDWriteFontFileEnumerator to create font files
 * Which are used to create a font collection.  This is expected to be a singleton.
 */
class DWriteFontBinaryDataCollectionLoader
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                          IDWriteFontCollectionLoader> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataCollectionLoader() {
    }

    HRESULT RuntimeClassInitialize();

    HRESULT STDMETHODCALLTYPE CreateEnumeratorFromKey(_In_ IDWriteFactory* factory,
                                                      _In_ const void* collectionKey,
                                                      _In_ UINT32 collectionKeySize,
                                                      _Out_ IDWriteFontFileEnumerator** enumerator);

    // Adds/removes an array of font data from this collection loader's internal storage
    HRESULT AddDatas(CFArrayRef fontDatas, CFArrayRef* errors);
    HRESULT RemoveDatas(CFArrayRef fontDatas, CFArrayRef* errors);

private:
    // Array of CFDataRef containing data of fonts, in order of being added
    woc::unique_cf<CFMutableArrayRef> m_fontDatas;

    // Set of CFDataRef containing data of fonts, used to simplify checking if font has been added
    woc::unique_cf<CFMutableSetRef> m_fontDatasSet;

    // Array of previously created font files, which saves us from having to read a file multiple times
    std::vector<Microsoft::WRL::ComPtr<IDWriteFontFile>> m_previouslyCreatedFiles;
};