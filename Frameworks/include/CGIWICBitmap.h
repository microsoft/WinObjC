//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import "Starboard.h"
#import "CoreGraphicsInternal.h"
#import "CGImageInternal.h"
#import "CACompositor.h"

#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <Wincodec.h>
#import <D2d1.h>
#include <COMIncludes_End.h>

using namespace Microsoft::WRL;

class CGIWICBitmap;

class CGIWICBitmapLock : public RuntimeClass<RuntimeClassFlags<RuntimeClassType::ClassicCom>, IAgileObject, FtmBase, IWICBitmapLock> {
public:
    CGIWICBitmapLock(_In_ IDisplayTexture* texture, _In_ const WICRect* region, _In_ WICPixelFormatGUID pixelFormat)
        : m_texture(texture), m_pixelFormat(pixelFormat), m_locked_rect(region) {
        int bpr;
        m_dataBuffer = static_cast<BYTE*>(m_texture->Lock(&bpr));
        m_bytesPerRow = static_cast<size_t>(bpr);
    }

    ~CGIWICBitmapLock() {
        m_texture->Unlock();
    }

    HRESULT STDMETHODCALLTYPE GetSize(_Out_ UINT* width, _Out_ UINT* height) {
        RETURN_HR_IF_NULL(E_POINTER, width);
        RETURN_HR_IF_NULL(E_POINTER, height);

        *width = m_locked_rect->Width;
        *height = m_locked_rect->Height;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetStride(_Out_ UINT* stride) {
        RETURN_HR_IF_NULL(E_POINTER, stride);
        *stride = m_bytesPerRow;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetDataPointer(_Out_ UINT* bufferSize, _Outptr_ WICInProcPointer* data) {
        RETURN_HR_IF_NULL(E_POINTER, bufferSize);
        RETURN_HR_IF_NULL(E_POINTER, data);
        *bufferSize = m_locked_rect->Height * m_bytesPerRow;
        *data = m_dataBuffer;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetPixelFormat(_Out_ WICPixelFormatGUID* pixelFormat) {
        RETURN_HR_IF_NULL(E_POINTER, pixelFormat);
        *pixelFormat = m_pixelFormat;
        return S_OK;
    }

private:
    WICPixelFormatGUID m_pixelFormat;
    BYTE* m_dataBuffer;
    const WICRect* m_locked_rect;
    size_t m_bytesPerRow;
    IDisplayTexture* m_texture;
};

class CGIWICBitmap : public RuntimeClass<RuntimeClassFlags<RuntimeClassType::ClassicCom>, IAgileObject, FtmBase, IWICBitmap> {
public:
    CGIWICBitmap(_In_ IDisplayTexture* texture, _In_ WICPixelFormatGUID pixelFormat, _In_ UINT height, _In_ UINT width)
        : m_texture(texture), m_pixelFormat(pixelFormat), m_height(height), m_width(width) {
    }

    ~CGIWICBitmap() {
        if (m_texture) {
            delete m_texture;
        }
    }

    // IWICBitmap interface
    // TODO #1124: Today we do not support locking a region of the WIC bitmap for rendering. We only support locking the complete bitmap.
    // This
    // will
    // suffice CoreText requirement but needs to be revisted for CoreGraphics usage in future.

    HRESULT STDMETHODCALLTYPE Lock(_In_ const WICRect* region, _In_ DWORD flags, _COM_Outptr_ IWICBitmapLock** outLock) {
        // flags is ignored.
        RETURN_HR_IF_NULL(E_POINTER, outLock);

        if (region == nullptr) {
            WICRect rect = { 0, 0, m_width, m_height };
            region = &rect;
        } else {
            RETURN_HR_IF(E_INVALIDARG, (region->Width > m_width) || (region->Height > m_height));
        }

        ComPtr<IWICBitmapLock> lock = Make<CGIWICBitmapLock>(m_texture, region, m_pixelFormat);
        *outLock = lock.Detach();
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE SetPalette(_In_ IWICPalette* palette) {
        UNIMPLEMENTED();
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE SetResolution(_In_ double dpiX, _In_ double dpiY) {
        UNIMPLEMENTED();
        return E_NOTIMPL;
    }

    // IWICBitmapSource interface (that IWICBitmap inherits)
    HRESULT STDMETHODCALLTYPE GetSize(_Out_ UINT* width, _Out_ UINT* height) {
        RETURN_HR_IF_NULL(E_POINTER, width);
        RETURN_HR_IF_NULL(E_POINTER, height);

        *width = m_width;
        *height = m_height;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetPixelFormat(_Out_ WICPixelFormatGUID* pixelFormat) {
        RETURN_HR_IF_NULL(E_POINTER, pixelFormat);
        *pixelFormat = m_pixelFormat;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetResolution(_Out_ double* dpiX, _Out_ double* dpiY) {
        UNIMPLEMENTED();
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE CopyPalette(_In_ IWICPalette* palette) {
        UNIMPLEMENTED();
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE CopyPixels(_In_opt_ const WICRect* copyRect,
                                         _In_ UINT stride,
                                         _In_ UINT bufferSize,
                                         _Out_writes_all_(cbBufferSize) BYTE* buffer) {
        UNIMPLEMENTED();
        return E_NOTIMPL;
    }

    IDisplayTexture* GetDisplayTexture() {
        return m_texture;
    }

private:
    WICPixelFormatGUID m_pixelFormat;
    IDisplayTexture* m_texture;
    UINT m_height;
    UINT m_width;
};