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
#include "EbrOpenglIncludes.h"

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"

#include "ContextManager.h"

#include "QuartzCore/CALayer.h"
#include "QuartzCore/CAEAGLLayer.h"
#include "Foundation/NSRunLoop.h"
#include "Etc.h"
#include "CACompositor.h"
#include <d3d11_1.h>
#include <d3d11.h>
#include <Dxgi1_3.h>

#include "GLES1122/OpenGLES20/OpenGLES20Context.h"

__declspec(thread) threadGLContext *tlsCurContext;
ContextManager  ctxManager;

extern EbrComPtr<ID3D11Device1> m_AngleD3dDevice;
extern EbrComPtr<ID3D11DeviceContext1> m_AngleD3dContext;

class DisplayTextureD3D
{
private:
    ID3D11Device1 *_device;
    ID3D11DeviceContext1 *_context;
    int _width, _height;

    EbrComPtr<IDXGIAdapter> dxgiAdapter;
    EbrComPtr<IDXGIFactory2> dxgiFactory;
    EbrComPtr<ID3D11RenderTargetView> _renderTargetView;

    HANDLE m_hRenderTargetHandle;
    EbrComPtr<IDXGIKeyedMutex> m_renderTargetMutex;
    EbrComPtr<ID3D11Texture2D> m_sharedTargetTexture;
    EbrComPtr<ID3D11Texture2D> m_masterTexture;
    EbrComPtr<IDXGIKeyedMutex> m_sharedTargetMutex;
    bool locked;

public:
    EbrComPtr<IDXGISwapChain1>  m_swapChain;

    ~DisplayTextureD3D()
    {
        locked = false;
        _device->Release();
        _context->Release();
        m_renderTargetMutex->ReleaseSync(0);
    }

    DisplayTextureD3D(ID3D11Device1 *device, ID3D11DeviceContext1 *context, ID3D11Texture2D *tex, int width, int height)
    {
        _width = width;
        _height = height;
        _device = device;
        _device->AddRef();
        _context = context;
        _context->AddRef();

        m_masterTexture = tex;
        EbrComPtr<IDXGIResource1> sharePtr;
        m_masterTexture.As(&sharePtr);
        sharePtr->CreateSharedHandle(NULL, DXGI_SHARED_RESOURCE_READ, NULL, &m_hRenderTargetHandle);
        m_masterTexture.As(&m_renderTargetMutex);

        device->OpenSharedResource1(m_hRenderTargetHandle, __uuidof(ID3D11Texture2D), (void **) m_sharedTargetTexture.GetAddressOf());
        m_sharedTargetTexture.As(&m_sharedTargetMutex);

        // Otherwise, create a new one using the same adapter as the existing Direct3D device.
        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};

        swapChainDesc.Width = width;
        swapChainDesc.Height = height;
        swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // This is the most common swap chain format.
        swapChainDesc.Stereo = false;
        swapChainDesc.SampleDesc.Count = 1; // Don't use multi-sampling.
        swapChainDesc.SampleDesc.Quality = 0;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.BufferCount = 2; // Use double-buffering to minimize latency.
        swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; // All Windows Store apps must use this SwapEffect.
        swapChainDesc.Flags = 0;
        swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
        swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;

        EbrComPtr<ID3D11Device1> _d3dDevice;
        _d3dDevice = device;

        // This sequence obtains the DXGI factory that was used to create the Direct3D device above.
        EbrComPtr<IDXGIDevice> dxgiDevice;
        _d3dDevice.As(&dxgiDevice);

        dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf());
        dxgiAdapter->GetParent(IID_PPV_ARGS(dxgiFactory.GetAddressOf()));

        dxgiFactory->CreateSwapChainForComposition(
            _d3dDevice.Get(),
            &swapChainDesc,
            nullptr,
            m_swapChain.GetAddressOf()
            );

        DXGI_MATRIX_3X2_F mirror = { 0 };
        mirror._11 = 1.0f;
        mirror._22 = -1.0f;
        mirror._32 = height;
        EbrComPtr<IDXGISwapChain2> spSwapChain2;
        m_swapChain.As<IDXGISwapChain2>(&spSwapChain2);
        spSwapChain2->SetMatrixTransform(&mirror);

        // Create a render target view of the swap chain back buffer.
        EbrComPtr<ID3D11Texture2D> backBuffer;
        m_swapChain->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf()));

        _d3dDevice->CreateRenderTargetView(
            backBuffer.Get(),
            nullptr,
            _renderTargetView.GetAddressOf()
            );
        m_renderTargetMutex->AcquireSync(0, INFINITE);
    }

    void Update()
    {
        m_renderTargetMutex->ReleaseSync(0);
        m_sharedTargetMutex->AcquireSync(0, INFINITE);
        float color[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

        EbrComPtr<ID3D11Texture2D> backBuffer;
        m_swapChain->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf()));

        _context->ClearRenderTargetView(_renderTargetView.Get(), color);
        _context->CopySubresourceRegion1(backBuffer.Get(), 0, 0, 0, 0, m_sharedTargetTexture.Get(), 0, NULL, 0);
        m_swapChain->Present(1, 0);
        m_sharedTargetMutex->ReleaseSync(0);
        m_renderTargetMutex->AcquireSync(0, INFINITE);
    }
};

bool ContextManager::lockContext()
{
	return tlsCurContext != NULL;
}

void ContextManager::unlockContext()
{
}

EAGLContext *ContextManager::getEAGLContext()
{
    threadGLContext *curThreadCtx = tlsCurContext;

    return (EAGLContext *) curThreadCtx->curEAGLContext;
}

void ContextManager::setContext(id newCtx, bool doRef)
{
    threadGLContext *curThreadCtx = tlsCurContext;
    EAGLContext* curCtx = curThreadCtx->curEAGLContext;
    EAGLContext* ctx = newCtx;

    if ( curCtx == ctx ) return;

    if ( doRef ) [newCtx retain];

    if ( curCtx != 0 ) {
        EbrGLESSetContext(0);
        curThreadCtx->curEAGLContext = nil;
        if ( doRef ) [curCtx release];
    }

    if ( ctx == 0 ) {
        curThreadCtx->curEAGLContext = nil;
        return;
    } else {
        EbrGLESSetContext(ctx->eaglPriv->contextHandle);
        curThreadCtx->curEAGLContext = ctx;
    }
}

@implementation EAGLContext {
    bool _gles11EmulationMode;
}
    -(instancetype) initWithAPI:(NSUInteger)api {
        if ( api != 2 ) {
            EbrDebugLog("Using GLES 1.1 emulation\n");
            _gles11EmulationMode = true;
        } else {
            EbrDebugLog("Creating GLES 2 context\n");
        }
        if ( api == 2 && _gles11EmulationMode == true ) {
            return nil;
        }
        eaglPriv = (EAGLContextPrivateData *) calloc(1, sizeof(EAGLContextPrivateData));
        eaglPriv->contextHandle = EbrGLESCreateContext(0);

        eaglPriv->_ownedFramebuffers = new HashMap<DWORD, DWORD>();
        EbrLockInit(&eaglPriv->contextLock);

        if ( _gles11EmulationMode ) {
            id oldCtx = [EAGLContext currentContext];
            [EAGLContext setCurrentContext:self];
            eaglPriv->_gl11Ctx = new OpenGLES::OpenGLES2::OpenGLES20Context();
            [EAGLContext setCurrentContext:oldCtx];
        }
        return self;
    }

    -(instancetype) initWithAPI:(NSUInteger)api sharegroup:(EAGLContext*)sharegroup {
        if ( api != 1 ) {
            EbrDebugLog("initWithAPI: Only opengl es 1.1 is supported\n");
            return nil;
        }

        eaglPriv = (EAGLContextPrivateData *) calloc(1, sizeof(EAGLContextPrivateData));

        eaglPriv->contextHandle = EbrGLESCreateContext(sharegroup->eaglPriv->contextHandle);

        EbrLockInit(&eaglPriv->contextLock);

        eaglPriv->_ownedFramebuffers = new HashMap<DWORD, DWORD>();
        eaglPriv->_sharegroup = sharegroup;

        return self;
    }

    +(instancetype) currentContext {
        threadGLContext *curCtx = tlsCurContext;
        if ( !curCtx ) return 0;

        return curCtx->curEAGLContext;
    }

    -(NSUInteger) API {
        return 2;
    }

    -(instancetype) sharegroup {
        return self;
    }

    +(BOOL) setCurrentContext:(EAGLContext*)context {
        EAGLContext* ctx = context;
        if ( ctx != nil && ctx->eaglPriv->sharedContext != nil ) context = ctx->eaglPriv->sharedContext;

        threadGLContext *curCtx = tlsCurContext;
        if ( !curCtx ) {
            curCtx = new threadGLContext();
            memset(curCtx, 0, sizeof(threadGLContext));
            tlsCurContext = curCtx;
        }

        ctxManager.setContext(context);

        return TRUE;
    }

    -(BOOL) renderbufferStorage:(int)target fromDrawable:(CAEAGLLayer*)surface {
        CAEAGLLayer* drawableSurface = surface;
        GLint oldName;

        if ( drawableSurface == nil ) {
            EbrDebugLog("No surface!\n");
            return FALSE;
        }

        id format = [[drawableSurface drawableProperties] objectForKey:@"kEAGLDrawablePropertyColorFormat"];
        eaglPriv->_rbWidth = (int)[drawableSurface _pixelWidth];
        eaglPriv->_rbHeight = (int)[drawableSurface _pixelHeight];

        if ( eaglPriv->_rbWidth == 0 || eaglPriv->_rbHeight == 0 ) {
            eaglPriv->_rbWidth = 320;
            eaglPriv->_rbHeight = 480;
        }

        ANGLE_glRenderbufferStorage(target, GL_BGRA8_EXT, eaglPriv->_rbWidth, eaglPriv->_rbHeight);
        glCheckError();
        void *ptr = NULL;
        
        glGetRenderbufferStorageNATIVE(&ptr);
        eaglPriv->presentationLayer = drawableSurface;
		if ( eaglPriv->_d3dSurface ) delete eaglPriv->_d3dSurface;

		eaglPriv->_d3dSurface = new DisplayTextureD3D(m_AngleD3dDevice.Get(), m_AngleD3dContext.Get(), (ID3D11Texture2D *) ptr, eaglPriv->_rbWidth, eaglPriv->_rbHeight);
		[eaglPriv->presentationLayer _setSwapChainNative: eaglPriv->_d3dSurface->m_swapChain.Get()];

        eaglPriv->_opaque = [drawableSurface opaque] ? true : false;
        if ( [format isEqual:@"kEAGLColorFormatRGBA8"] || format == nil ) eaglPriv->_opaque = false;

        return TRUE;
    }

    -(BOOL) presentRenderbuffer:(int)target {
        bool isMainThread;
        id mainRunLoop = [NSRunLoop mainRunLoop];
        id currentRunLoop = [NSRunLoop currentRunLoop];
        if ( mainRunLoop != currentRunLoop ) {
            isMainThread = false;
        } else {
            isMainThread = true;
        }

        if (eaglPriv->presentationLayer == nil) {
            return FALSE;
        }

        glReleaseTargets();
		eaglPriv->_d3dSurface->Update();
        EbrSignalsUnsafe();

        return TRUE;
    }

    -(void) dealloc {
        threadGLContext *curCtx = tlsCurContext;

        if ( curCtx ) {
            ctxManager.setContext(self, false);
            EbrGLESDestroyContext(eaglPriv->contextHandle);

            if ( curCtx->curEAGLContext != self ) {
                ctxManager.setContext(curCtx->curEAGLContext, false);
            } else {
                ctxManager.setContext(nil, false);
            }
        }
        delete eaglPriv->_ownedFramebuffers;
        if ( eaglPriv ) free(eaglPriv);

        [super dealloc];
    }
@end

NSString * const kEAGLColorFormatRGBA8 = (NSString * const) @"kEAGLColorFormatRGBA8";
NSString * const kEAGLColorFormatRGB565 = (NSString * const) @"kEAGLColorFormatRGB565";
NSString * const kEAGLDrawablePropertyColorFormat = (NSString * const) @"kEAGLDrawablePropertyColorFormat";
NSString * const kEAGLDrawablePropertyRetainedBacking = (NSString * const) @"kEAGLDrawablePropertyRetainedBacking";
