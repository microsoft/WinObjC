//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"
#include "CGContextInternal.h"
#include "NativeUI/NativeUI.h"
#include "NativeUI/EbrTexture.h"
#include "NativeUI/DrawingList.h"
#include "Platform/EbrDirectX.h"

#include <unordered_set>

namespace DX
{
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            // Set a breakpoint on this line to catch DX API errors.
            *((char *) 1) = 0;
        }
    }
}

extern int _totalDisplayTextures, _totalDisplayTexturesSize;
typedef std::unordered_set<EbrTexture *> TextureList;
TextureList _allTextures;
EbrLock _allTexturesLock = EBRLOCK_INITIALIZE;

//
// EbrTexture:
//

#define GL_BGRA_EXT 0x80E1

EbrTexture::EbrTexture(DisplayTextureType type, int width, int height, DWORD texHandle, bool hasAlpha)
    : _type(type), _imageBacking(0),
#if USE_DYN_TEXTURE_ATLASING
      _atlased(false), _cannotAtlas(false),
#endif 
      _khrImage(0), _khrBuffer(0),
      _imageX(0), _imageY(0),
      _imageWidth(width), _texWidth(width),
      _imageHeight(height), _texHeight(height)
{
    EbrLockEnter(_allTexturesLock);
    _allTextures.insert(this);
    EbrLockLeave(_allTexturesLock);

    if ( type != displayTextureNormal ) {
        _khrImage = texHandle;
        _builtTexture = false;
        _ownsTexture = false;
    } else {
        _texNum = texHandle;
        _builtTexture = true;
        _ownsTexture = true;
    }
}

EbrTexture::EbrTexture(CGImageRef pContents)
    : _type(displayTextureNormal), _imageBacking(pContents), _builtTexture(false), _ownsTexture(false),
#if USE_DYN_TEXTURE_ATLASING
      _atlased(false), _cannotAtlas(false),
#endif 
      _khrImage(0), _khrBuffer(0),
      _imageX(0), _imageY(0),
      _imageWidth(pContents->Backing()->Width()), _imageHeight(pContents->Backing()->Height())
{
    EbrLockEnter(_allTexturesLock);
    _allTextures.insert(this);
    EbrLockLeave(_allTexturesLock);

    CGImageRetain(_imageBacking);
}

EbrTexture::EbrTexture(CGImageRef pContents, int x, int y, int width, int height)
    : _imageBacking(pContents), _type(displayTextureNormal), _builtTexture(false), _ownsTexture(false),
#if USE_DYN_TEXTURE_ATLASING
      _atlased(false), _cannotAtlas(false),
#endif 
      _khrImage(0), _khrBuffer(0),
      _imageX(x), _imageY(y),
      _imageWidth(width), _imageHeight(height)
{
    EbrLockEnter(_allTexturesLock);
    _allTextures.insert(this);
    EbrLockLeave(_allTexturesLock);

    CGImageRetain(_imageBacking);
}

EbrTexture::~EbrTexture()
{
#if USE_DYN_TEXTURE_ATLASING
    DrawingListUnreferenceTexture(this);
#endif 
    
    EbrLockEnter(_allTexturesLock);
    _allTextures.erase(this);
    EbrLockLeave(_allTexturesLock);

    CGImageRelease(_imageBacking);
    if ( _builtTexture ) {
        _totalDisplayTextures --;
        _totalDisplayTexturesSize -= _texWidth * _texHeight * 4;
#ifdef LOG_OBJECT_COUNTS
        EbrDebugLog("Destroyed - total display textures: %d (size %dKB)\n", _totalDisplayTextures, _totalDisplayTexturesSize / 1024);
#endif
#if USE_GL
        glBindTexture(GL_TEXTURE_2D, 0);
        if ( _ownsTexture ) glDeleteTextures(1, &_texNum);
#endif

#if defined( USE_KHR_FASTTEXTURES )
        if ( _khrBuffer ) {
            EbrReleaseFastTexture(_khrBuffer);
            _khrBuffer = NULL;
        }
#endif
    }
    mOffscreenSRView = nullptr;
    m_masterTexture = nullptr;
}

void EbrTexture::realize()
{
    if ( _builtTexture ) {
        return;
    }

    _texWidth = _imageWidth;
    _texHeight = _imageHeight;
}

void EbrTexture::build(ID3D11Device1 *device)
{
    if ( _builtTexture ) {
        return;
    }

    if ( !_imageBacking )
        return;

    if ( !_imageBacking->Backing() ) {
        return;
    }

    if ( _type != displayTextureNormal ) {
#if defined( USE_KHR_FASTTEXTURES )
        // commenting out -- slows things down a little.
        //EbrDebugLog("khr = %x, %x %x\n", _khrImage, glGetError(), eglGetError());

        glGenTextures(1, &_texNum);
        _ownsTexture = true;
        glBindTexture(GL_TEXTURE_2D, _texNum);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glEGLImageTargetTexture2DOES(GL_TEXTURE_2D, (EGLImageKHR) _khrImage);
        _builtTexture = TRUE;

        return _texNum;
#endif
    }

    _totalDisplayTextures ++;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Total display textures: %d\n", _totalDisplayTextures);
#endif

#if defined( USE_KHR_FASTTEXTURES )
    if ( _imageWidth == _imageBacking->Backing()->Width() && _imageHeight == _imageBacking->Backing()->Height() ) {
        if ( _imageBacking->Backing()->FastTexture() ) {
            _khrBuffer = _imageBacking->Backing()->FastTexture();
            EbrRetainFastTexture(_khrBuffer);

            _texNum = EbrGetFastTextureBindable(_khrBuffer);

            _builtTexture = TRUE;
            _texWidth = _imageWidth;
            _texHeight = _imageHeight;

            _totalDisplayTexturesSize += _texWidth * _texHeight * 4;
            EbrDebugLog("Using KHR: %dx%dx%d (%dKB)\n", _texWidth, _texHeight, 4, _texWidth * _texHeight * 4 / 1024);
            EbrDebugLog("Total display textures size: %dKB\n", _totalDisplayTexturesSize / 1024);

            _imageBacking->Backing()->DiscardIfPossible();

            CFRelease(H2E(_imageBacking));
            _imageBacking = NULL;
            return _texNum;
        }
    }
    if ( (_imageBacking->Backing()->Width() > 32 && _imageBacking->Backing()->Height() > 32) &&
        (_imageBacking->Backing()->SurfaceFormat() == _ColorARGB || _imageBacking->Backing()->SurfaceFormat() == _ColorRGBA ||
         _imageBacking->Backing()->SurfaceFormat() == _ColorRGB || _imageBacking->Backing()->SurfaceFormat() == _ColorRGB32) ) {
        {
            TimingFunction __texTiming("khrGetTexture");
            _khrBuffer = EbrCreateFastTexture(_imageX, _imageBacking->Backing()->Height() - _imageY - _imageHeight, _imageWidth, _imageHeight,
                _imageBacking->Backing()->BytesPerRow(), _imageBacking->Backing()->LockImageData(), _imageBacking->Backing()->SurfaceFormat());
            _imageBacking->Backing()->ReleaseImageData();
            if ( _khrBuffer != NULL ) {
                EbrRetainFastTexture(_khrBuffer);
                _texNum = EbrGetFastTextureBindable(_khrBuffer);

                _builtTexture = TRUE;
                _texWidth = _imageWidth;
                _texHeight = _imageHeight;

                EbrDebugLog("Creating KHR: %dx%dx%d (%dKB)\n", _texWidth, _texHeight, 4, _texWidth * _texHeight * 4 / 1024);
                EbrDebugLog("Total display textures size: %dKB\n", _totalDisplayTexturesSize / 1024);

                _imageBacking->Backing()->DiscardIfPossible();

                CFRelease(H2E(_imageBacking));
                _imageBacking = NULL;
                return _texNum;
            }
        }
    }
#endif

    {
    TimingFunction __texTiming("getTexture");

    _ownsTexture = true;

    // Round up to next power of two:
    _texWidth = _imageWidth;
    _texHeight = _imageHeight;

    DXGI_FORMAT format;

    CGImageRef pNewImage = 0;
    CGImageRef pTexImage = _imageBacking;

    EbrDebugLog("Creating DXGI image %d %d\n", _texWidth, _texHeight);

    bool matched = false;
    if ( _imageX == 0 && _imageY == 0 &&
         _imageWidth == _imageBacking->Backing()->Width() && _imageHeight == _imageBacking->Backing()->Height() ) {
        if ( _imageBacking->Backing()->SurfaceFormat() == _ColorRGBA ) {
            format = DXGI_FORMAT_R8G8B8A8_UNORM;
            matched = true;
        } else if ( _imageBacking->Backing()->SurfaceFormat() == _ColorARGB ) {
            format = DXGI_FORMAT_B8G8R8A8_UNORM;
            matched = true;
            /*
        } else if ( _imageBacking->Backing()->SurfaceFormat() == _ColorRGB ) {
            type = GL_RGB;
            internalformat = GL_RGB;
            format = GL_UNSIGNED_BYTE;
            matched = true;
        } else if ( _imageBacking->Backing()->SurfaceFormat() == _Color565 ) {
            type = GL_RGB;
            format = GL_RGB;
            type = GL_UNSIGNED_SHORT_5_6_5;
            */
            matched = true;
        } else if ( _imageBacking->Backing()->SurfaceFormat() == _ColorA8 ) {
            format = DXGI_FORMAT_A8_UNORM;
            matched = true;
        }
    }

    // Unrecognized, make 8888 RGBA:
    if ( !matched ) {
        format = DXGI_FORMAT_R8G8B8A8_UNORM;

        EbrDebugLog("Warning: unrecognized image format, going to slow path\n");

        CGContextRef ctx = CGBitmapContextCreate32(_texWidth, _texHeight);
        pNewImage = CGBitmapContextGetImage(ctx);
        CGImageRetain(pNewImage);

        pTexImage = pNewImage;

        CGRect rect, destRect;

        int w = min(_imageWidth, _texWidth), h = min(_imageHeight, _texHeight);

        rect.origin.x = float(_imageX);
        rect.origin.y = float(_imageY);
        rect.size.width = float(w);
        rect.size.height = float(h);

        destRect.origin.x = 0;
        destRect.origin.y = float(_texHeight - _imageHeight);
        destRect.size.width = float(w);
        destRect.size.height = float(h);

        CGContextDrawImageRect(ctx, _imageBacking, rect, destRect);
        CGContextRelease(ctx);
    }

    _totalDisplayTexturesSize += _texWidth * _texHeight * 4;
    EbrDebugLog("Creating glImage: %dx%dx%d (%dKB)\n", _texWidth, _texHeight, 4, _texWidth * _texHeight * 4 / 1024);
    EbrDebugLog("Total display textures size: %dKB\n", _totalDisplayTexturesSize / 1024);

    D3D11_TEXTURE2D_DESC desc;
    desc.Width = _texWidth;      // Compressed texture size constraints?
    desc.Height = _texHeight;
    desc.MipLevels = 1;

    desc.ArraySize = 1;
    desc.Format = format;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA subData;
    subData.pSysMem = (const void *) pTexImage->Backing()->LockImageData();
    subData.SysMemPitch = pTexImage->Backing()->BytesPerRow();
    subData.SysMemSlicePitch = 0;

    DX::ThrowIfFailed(((ID3D11Device *) device)->CreateTexture2D(&desc, &subData, m_masterTexture.ReleaseAndGetAddressOf()));
    DX::ThrowIfFailed(((ID3D11Device *) device)->CreateShaderResourceView(m_masterTexture.Get(), NULL, mOffscreenSRView.GetAddressOf()));
    pTexImage->Backing()->ReleaseImageData();

    _imageBacking->Backing()->DiscardIfPossible();

    CGImageRelease(pNewImage);
    /*
    CFRelease(H2E(_imageBacking));
    _imageBacking = 0;
    */
    }

    _builtTexture = true;

    return;
}

ID3D11ShaderResourceView *EbrTexture::GetSRV(ID3D11Device1 *device)
{
    build(device);
    return mOffscreenSRView.Get();
}

void EbrTexture::Disconnect()
{
    mOffscreenSRView = nullptr;
    m_masterTexture = nullptr;
    _builtTexture = false;
}

void EbrTexture::AcquireDeviceLock(ID3D11Device1 *device)
{
}

void EbrTexture::ReleaseDeviceLock(ID3D11Device1 *device)
{
}

EbrTextureFontAtlas::EbrTextureFontAtlas() :
    EbrTexture(displayTextureFontAtlas, 0, 0, -1, false)
{
}

void EbrTextureFontAtlas::Initialize(ID3D11Device1 *device, int width, int height,
                                     void *imageData)
{
    _imageWidth = width;
    _imageHeight = height;
    _texWidth = width;
    _texHeight = height;

    D3D11_TEXTURE2D_DESC desc;
    desc.Width = width;      // Compressed texture size constraints?
    desc.Height = height;
    desc.MipLevels = 1;

    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    if (imageData) {
        D3D11_SUBRESOURCE_DATA subData;
        subData.pSysMem = (const void *) imageData;
        subData.SysMemPitch = width;
        subData.SysMemSlicePitch = 0;

        DX::ThrowIfFailed(((ID3D11Device *) device)->CreateTexture2D(&desc, &subData, m_masterTexture.ReleaseAndGetAddressOf()));
    } else {
        DX::ThrowIfFailed(((ID3D11Device *) device)->CreateTexture2D(&desc, NULL, m_masterTexture.ReleaseAndGetAddressOf()));
    }
    DX::ThrowIfFailed(((ID3D11Device *) device)->CreateShaderResourceView(m_masterTexture.Get(), NULL, mOffscreenSRView.GetAddressOf()));
    _builtTexture = true;
}

void EbrTextureFontAtlas::UpdateSubrect(ID3D11DeviceContext* context, int x, int y,
                                        int width, int height, void *imageData)
{
    D3D11_BOX box;
    box.left = (UINT)x;
    box.top = (UINT)y;
    box.right = (UINT)(x + width);
    box.bottom = (UINT)(y + height);
    box.front = 0u;
    box.back = 1u;
 
    context->UpdateSubresource(m_masterTexture.Get(), 0, &box, imageData, width, 0);
}

EbrTextureFontAtlas::~EbrTextureFontAtlas()
{
}

void EbrTextureFontAtlas::Disconnect()
{
    m_masterTexture = nullptr;
    mOffscreenSRView = nullptr;
}

EbrTextureDynAtlas::EbrTextureDynAtlas() :
    EbrTexture(displayTextureNormal, 0, 0, -1, false),
    lockType(D3D11_MAP_WRITE_DISCARD)
{
}

EbrTextureDynAtlas::~EbrTextureDynAtlas()
{
}

bool EbrTextureDynAtlas::Initialize(ID3D11Device* device, int width, int height)
{
    _imageWidth = width;
    _imageHeight = height;
    _texWidth = width;
    _texHeight = height;

    D3D11_TEXTURE2D_DESC desc;
    desc.Width = width;      // Compressed texture size constraints?
    desc.Height = height;
    desc.MipLevels = 1;

    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    HRESULT r = device->CreateTexture2D(&desc, NULL, m_masterTexture.ReleaseAndGetAddressOf());
    if (FAILED(r)) return false;
    r = device->CreateShaderResourceView(m_masterTexture.Get(), NULL, mOffscreenSRView.GetAddressOf());
    if (FAILED(r)) return false;

    _builtTexture = true;

    return true;
}

void EbrTextureDynAtlas::Disconnect()
{
    m_masterTexture = nullptr;
    mOffscreenSRView = nullptr;
}

void* EbrTextureDynAtlas::Lock(ID3D11DeviceContext *ctx, size_t& stride)
{
    D3D11_MAPPED_SUBRESOURCE sr;
    HRESULT r = ctx->Map(m_masterTexture.Get(), 0, lockType, 0, &sr);
    //lockType = D3D11_MAP_WRITE_NO_OVERWRITE; // OH GOD I think we need this.
    if (FAILED(r)) return NULL;

    stride = sr.RowPitch;
    return sr.pData;
}

void EbrTextureDynAtlas::Unlock(ID3D11DeviceContext *ctx)
{
    ctx->Unmap(m_masterTexture.Get(), 0);
}

void EbrTextureDynAtlas::UpdateSubresource(ID3D11DeviceContext *ctx, int left, int top,
                                           int right, int bottom, void* src, int rowBytes)
{
    D3D11_BOX box;
    box.left = left;
    box.top = top;
    box.front = 0;
    box.right = right;
    box.bottom = bottom;
    box.back = 1;

    ctx->UpdateSubresource(m_masterTexture.Get(), 0, &box, src, rowBytes, 0);
}

EbrTextureOpenGL::EbrTextureOpenGL(ID3D11Device1 *device, ID3D11Texture2D *renderbufferTexture, int width, int height) :
    EbrTexture(displayTextureOpenGL, width, height, -1, false)
{
    m_masterTexture = renderbufferTexture;
    m_owningDevice = device;
    m_lockedDevice = NULL;
    m_hRenderTargetHandle = INVALID_HANDLE_VALUE;

    //  Create shared resources
    EbrComPtr<IDXGIResource1> sharePtr;
    DX::ThrowIfFailed(m_masterTexture.As(&sharePtr));
    DX::ThrowIfFailed(sharePtr->CreateSharedHandle(NULL, DXGI_SHARED_RESOURCE_READ, NULL, &m_hRenderTargetHandle));
    DX::ThrowIfFailed(m_masterTexture.As(&m_renderTargetMutex));
    _builtTexture = true;
}

EbrTextureOpenGL::~EbrTextureOpenGL()
{
    //  Release existing resources
    if ( m_hRenderTargetHandle != INVALID_HANDLE_VALUE ) {
        CloseHandle(m_hRenderTargetHandle);
        m_hRenderTargetHandle = INVALID_HANDLE_VALUE;
    }
    m_renderTargetMutex = nullptr;
    m_sharedTargetTexture = nullptr;
    m_sharedTargetMutex = nullptr;
}

void EbrTextureOpenGL::Disconnect()
{
    mOffscreenSRView = nullptr;
    m_sharedTargetTexture = nullptr;
    m_sharedTargetMutex = nullptr;
}

ID3D11ShaderResourceView *EbrTextureOpenGL::GetSRV(ID3D11Device1 *device)
{
    if ( m_sharedTargetTexture == nullptr && m_hRenderTargetHandle != INVALID_HANDLE_VALUE ) {
        DX::ThrowIfFailed(device->OpenSharedResource1(m_hRenderTargetHandle, __uuidof(ID3D11Texture2D), (void **) m_sharedTargetTexture.GetAddressOf()));
        DX::ThrowIfFailed(m_sharedTargetTexture.As(&m_sharedTargetMutex));
        DX::ThrowIfFailed(device->CreateShaderResourceView(m_sharedTargetTexture.Get(), NULL, mOffscreenSRView.GetAddressOf()));
    }

    return mOffscreenSRView.Get();
}

void EbrTextureOpenGL::AcquireDeviceLock(ID3D11Device1 *device)
{
    if ( m_lockedDevice == device ) return;

    assert(m_lockedDevice == NULL);
    m_lockedDevice = device;
    if ( m_lockedDevice == m_owningDevice ) {
        m_renderTargetMutex->AcquireSync(0, INFINITE);
    } else {
        GetSRV(device);
        m_sharedTargetMutex->AcquireSync(0, INFINITE);
    }
}

void EbrTextureOpenGL::ReleaseDeviceLock(ID3D11Device1 *device)
{
    if ( m_lockedDevice == NULL ) {
        return;
    }

    assert(m_lockedDevice == device);
    if ( m_lockedDevice == m_owningDevice ) {
        m_renderTargetMutex->ReleaseSync(0);
    } else {
        m_sharedTargetMutex->ReleaseSync(0);
    }
    m_lockedDevice = NULL;
}

void EbrTextureAcquireLock(ID3D11Device1 *device)
{
    EbrLockEnter(_allTexturesLock);
    TextureList::iterator cur = _allTextures.begin();
    while ( cur != _allTextures.end() ) {
        (*cur)->AcquireDeviceLock(device);
        cur ++;
    }
    EbrLockLeave(_allTexturesLock);
}

void EbrTextureReleaseLock(ID3D11Device1 *device)
{
    EbrLockEnter(_allTexturesLock);
    TextureList::iterator cur = _allTextures.begin();
    while ( cur != _allTextures.end() ) {
        (*cur)->ReleaseDeviceLock(device);
        cur ++;
    }
    EbrLockLeave(_allTexturesLock);
}

void EbrTextureDisconnect()
{
    EbrLockEnter(_allTexturesLock);
    TextureList::iterator cur = _allTextures.begin();
    while ( cur != _allTextures.end() ) {
        (*cur)->Disconnect();
        cur ++;
    }
    EbrLockLeave(_allTexturesLock);
}

DisplayTexture * UIGetDisplayTextureForCGImage(CGImageRef img, bool create)
{
    DisplayTexture *ret = DisplayTexture::CachedDisplayTextureForImage(img);

    if ( !ret && create ) {
        ret = new DisplayTextureTiled(img);
        DisplayTexture::SetCachedDisplayTextureForImage(img, ret);
        ret->AddRef();
    }

    return ret;
}

void UIReleaseDisplayTextureForCGImage(CGImageRef img)
{
    DisplayTexture::SetCachedDisplayTextureForImage(img, NULL);
}

void SetImageDestructionCallbacks()
{
    CGImageAddDestructionListener(UIReleaseDisplayTextureForCGImage);
}

