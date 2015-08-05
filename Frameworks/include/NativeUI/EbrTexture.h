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

#pragma once

#include "NativeUIBase.h"

struct ID3D11Device1;
struct ID3D11Device;
struct ID3D11Texture2D;
struct ID3D11DeviceContext;
struct ID3D11ShaderResourceView;
enum D3D11_MAP;

class EbrFastTexture;

// A texture uploaded to DirectX:
class EbrTexture
{
public:
    unsigned int _texNum;
    bool         _ownsTexture;
    bool _builtTexture;
    DisplayTextureType _type;
    CGImageRef _imageBacking;

#if USE_DYN_TEXTURE_ATLASING
    bool _atlased;
    bool _cannotAtlas;
#endif 
    
    DWORD _texWidth, _texHeight;
    DWORD _imageX, _imageY;
    DWORD _imageWidth, _imageHeight;

    DWORD _khrImage;
    EbrFastTexture *_khrBuffer;

    EbrComPtr<ID3D11ShaderResourceView> mOffscreenSRView;
    EbrComPtr<ID3D11Texture2D> m_masterTexture;

    virtual ID3D11ShaderResourceView *GetSRV(ID3D11Device1 *device);

    float xscale() const { return float(_imageWidth) / _texWidth; }
    float yscale() const { return float(_imageHeight) / _texHeight; }

    // Initialize from an existing texture:
    EbrTexture(DisplayTextureType type, int width, int height, DWORD texHandle, bool hasAlpha);
    EbrTexture(CGImageRef pContents);

    // Initialize our texture from a sub-image
    EbrTexture(CGImageRef pContents, int x, int y, int width, int height);

    virtual ~EbrTexture();

    void build(ID3D11Device1 *device);
    virtual void realize();
    virtual void Disconnect();
    virtual void AcquireDeviceLock(ID3D11Device1 *device);
    virtual void ReleaseDeviceLock(ID3D11Device1 *device);
};

class EbrTextureOpenGL : public EbrTexture
{
private:
    HANDLE m_hRenderTargetHandle;
    EbrComPtr<IDXGIKeyedMutex> m_renderTargetMutex;
    EbrComPtr<ID3D11Texture2D> m_sharedTargetTexture;
    EbrComPtr<IDXGIKeyedMutex> m_sharedTargetMutex;
    ID3D11Device1 *m_owningDevice;
    ID3D11Device1 *m_lockedDevice;

public:
    EbrTextureOpenGL(ID3D11Device1 *device, ID3D11Texture2D *renderbufferTexture, int width, int height);
    ~EbrTextureOpenGL();

    ID3D11ShaderResourceView *GetSRV(ID3D11Device1 *device);
    void AcquireDeviceLock(ID3D11Device1 *device);
    void ReleaseDeviceLock(ID3D11Device1 *device);
    void Disconnect();
};

class EbrTextureFontAtlas : public EbrTexture
{
private:

public:
    EbrTextureFontAtlas();
    ~EbrTextureFontAtlas();

    void Disconnect();
    void Initialize(ID3D11Device1 *device, int width, int height, void *imageData);
    void UpdateSubrect(ID3D11DeviceContext* context, int x, int y, int width, int height, void *imageData);
};

class EbrTextureDynAtlas : public EbrTexture
{
    D3D11_MAP lockType;

public:
    EbrTextureDynAtlas();
    virtual ~EbrTextureDynAtlas();

    bool Initialize(ID3D11Device* device, int width, int height);
    virtual void Disconnect();

    void* Lock(ID3D11DeviceContext* context, size_t& stride);
    void Unlock(ID3D11DeviceContext* context);
    void UpdateSubresource(ID3D11DeviceContext* context, int left, int top, int right, int bottom, void* src, int rowBytes);
};

void EbrTextureAcquireLock(ID3D11Device1 *device);
void EbrTextureReleaseLock(ID3D11Device1 *device);
void EbrTextureDisconnect();
