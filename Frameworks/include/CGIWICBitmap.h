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
    CGIWICBitmapLock(_In_ CGImageBacking* imageBacking, _In_ WICPixelFormatGUID pixelFormat)
        : m_imageBacking(imageBacking), m_pixelFormat(pixelFormat) {
        m_dataBuffer = static_cast<BYTE*>(m_imageBacking->LockImageData());
    }

    ~CGIWICBitmapLock() {
        m_imageBacking->ReleaseImageData();
        m_imageBacking = nullptr;
    }

    HRESULT STDMETHODCALLTYPE GetSize(_Out_ UINT* width, _Out_ UINT* height) {
        *width = m_imageBacking->Width();
        *height = m_imageBacking->Height();
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetStride(_Out_ UINT* stride) {
        *stride = m_imageBacking->BytesPerRow();
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetDataPointer(_Out_ UINT* bufferSize, _Outptr_ WICInProcPointer* data) {
        *bufferSize = m_imageBacking->Height() * m_imageBacking->BytesPerRow();
        *data = m_dataBuffer;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetPixelFormat(_Out_ WICPixelFormatGUID* pixelFormat) {
        *pixelFormat = m_pixelFormat;
        return S_OK;
    }

private:
    CGImageBacking* m_imageBacking;
    WICPixelFormatGUID m_pixelFormat;
    BYTE* m_dataBuffer;
};

inline WICPixelFormatGUID SurfaceFormatToWICPixelFormat(__CGSurfaceFormat format) {
    switch (format) {
        case _ColorABGR:
        case _ColorXBGR:
            // XBGR is not supported by wic bitmap render target
            return GUID_WICPixelFormat32bppPRGBA;
        case _ColorARGB:
            return GUID_WICPixelFormat32bppPBGRA;
        case _ColorBGRX:
            return GUID_WICPixelFormat32bppBGR;
        case _ColorGrayscale:
        case _ColorA8:
            return GUID_WICPixelFormat8bppAlpha;
        case _ColorBGR:
        default:
            UNIMPLEMENTED_WITH_MSG("Unsupported pixel format (%d) used in CGIWICBitmap");
            break;
    }
    // our default format is alpha premultiplied BGRA
    return GUID_WICPixelFormat32bppPBGRA;
}

class CGIWICBitmap : public RuntimeClass<RuntimeClassFlags<RuntimeClassType::ClassicCom>, IAgileObject, FtmBase, IWICBitmap> {
public:
    CGIWICBitmap(_In_ CGImageBacking* imageBacking, _In_ __CGSurfaceFormat format)
        : m_imageBacking(imageBacking), m_pixelFormat(SurfaceFormatToWICPixelFormat(format)) {
    }

    // IWICBitmap interface
    // TODO::
    // Today we do not support locking a region of the WIC bitmap for rendering. We only support locking the complete bitmap. This will
    // suffice CoreText requirement but needs to be revisted for CoreGraphics usage in future.
    HRESULT STDMETHODCALLTYPE Lock(_In_ const WICRect* lockRect, _In_ DWORD flags, _COM_Outptr_ IWICBitmapLock** outLock) {
        ComPtr<IWICBitmapLock> lock = Make<CGIWICBitmapLock>(m_imageBacking, m_pixelFormat);
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
        *width = m_imageBacking->Width();
        *height = m_imageBacking->Height();
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetPixelFormat(_Out_ WICPixelFormatGUID* pixelFormat) {
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

private:
    CGImageBacking* m_imageBacking;
    WICPixelFormatGUID m_pixelFormat;
};