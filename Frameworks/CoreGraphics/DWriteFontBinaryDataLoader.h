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
#import <CoreFoundation/CFData.h>

/**
 * Custom implementation of IDWriteFontFileLoader that loads a CFDataRef as its font file
 */
class DWriteFontBinaryDataLoader
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>, IDWriteFontFileLoader> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite.DWriteFontBinaryDataLoader", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataLoader() {
    }

    HRESULT RuntimeClassInitialize(CGDataProviderRef data);

    HRESULT STDMETHODCALLTYPE CreateStreamFromKey(_In_ const void* fontFileReferenceKey,
                                                  uint32_t fontFileReferenceKeySize,
                                                  _Out_ IDWriteFontFileStream** fontFileStream);

private:
    woc::unique_cf<CGDataProviderRef> m_data;
};
