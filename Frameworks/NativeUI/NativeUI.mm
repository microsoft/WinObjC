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

#if defined( WIN32 ) || defined( QNX )
 #include <process.h>
#endif

#include <math.h>
#include <pthread.h>
#include <malloc.h>

#include <vector>
#include <algorithm>

#include "Starboard.h"
#include "Platform/EbrDirectX.h"

#include "NativeUI/NativeUI.h"
#include "CGContextInternal.h"
#include "QuartzCore/CALayer.h"
#include "NativeUI/DisplayNode.h"

#include "EbrGLES.h"
#include "Platform/EbrPlatform.h"
#include "NativeUI/EbrTexture.h"
#include "EbrShaderLib.h"

#include "Etc.h"
#include "FontAtlas.h"

#include "CACompositor.h"
#include "CACompositorClient.h"
#include "DXCompositor.h"

#define LOG_REFS(...)
//#define LOG_REFS(...) EbrDebugLog(__VA_ARGS__)
//#define LOG_OBJECT_COUNTS

#define FONT_DEBUG 0

extern bool dxLandscape;
extern int drawDeviceOrientation;
DisplayTextureTiled *g_cornerTex;

static DisplayTexture **g_DeadTextures;
static int g_NumDeadTextures, g_MaxDeadTextures;
EbrLock DisplayTexture::_displayTextureCacheLock;
HashMap<CGImageRef , DisplayTexture *> DisplayTexture::_displayTextureCache;
static pthread_t g_RenderThread;
static pthread_mutex_t g_DeadTexturesLock;

int  g_numFrames, g_numQuads, g_numVerts;
int g_maxTextureResolution = 4096;
int _totalDisplayTextures, _totalDisplayTexturesSize;
extern int display_width, display_height;

extern BOOL refreshPending;
float windowInsetLeft, windowInsetRight, windowInsetTop, windowInsetBottom;

bool dxLandscape = false;

float screenWidth = 320.0f;
float screenHeight = 480.0f;
float screenScale = 2.0f;

float windowWidth = screenWidth * screenScale;
float windowHeight = screenHeight * screenScale;

bool tabletMode = false;

float screenXDpi = 180, screenYDpi = 180;
int deviceWidth  = 640, deviceHeight = 1136;

bool _drawingAllowed = true;
bool g_directDraw;

static ID3D11Texture2D *_depthStencil = NULL;
static ID3D11DepthStencilView *_depthStencilView = NULL;

static IWLazyClassLookup _LazyCALayer("CALayer");
static IWLazyIvarLookup<CAPrivateInfo *> _LazyCAPrivInfo(_LazyCALayer, "priv");

//
// SubImage:
//

DisplayTextureTiled::SubImage::SubImage(CGImageRef pContents, int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height),
    _imageWidth(pContents->Backing()->Width()), _imageHeight(pContents->Backing()->Height())
{
    _tex = new EbrTexture(pContents, x, y, width, height);
}

DisplayTextureTiled::SubImage::~SubImage()
{
    delete _tex;
}

void DisplayTextureTiled::SubImage::realize()
{
    _tex->realize();
}

void DisplayTextureTiled::SubImage::addOperation(CAPoint3D baseQuad[], CGPoint baseUV[], bool hasAlpha, float alpha, float r, float g, float b, float a, DrawingObserver *observer)
{
    if ( baseUV[0].y == baseUV[1].y ) {
        float udir = baseUV[3].x - baseUV[0].x, vdir = baseUV[3].y - baseUV[0].y;
        float xdir = baseQuad[3].x - baseQuad[0].x, ydir = baseQuad[3].y - baseQuad[0].y;

        float left = xdir * float(_x) / _imageWidth, lower = ydir * float(_imageHeight - _y - _height) / _imageHeight;
        float right = left + xdir * float(_width) / _imageWidth, upper = lower + ydir * float(_height) / _imageHeight;

        float x = baseQuad[0].x, y = baseQuad[0].y;
        float u = baseUV[0].x, v = baseUV[0].y;

        CAPoint3D quad[] = {
            CAPoint3D(x + left,  y + upper, 0),
            CAPoint3D(x + right, y + upper, 0),
            CAPoint3D(x + left,  y + lower, 0),
            CAPoint3D(x + right, y + lower, 0),
        };

        float xs = _tex->xscale(), ys = _tex->yscale();
        static const float STEPBACK = .25f;
        float xoffs = STEPBACK / _tex->_texWidth, yoffs = STEPBACK / _tex->_texHeight;

        if ( u != 0.f ) {
            u += xoffs;
        }
        if ( v != 0.f ) {
            v += yoffs;
        }

        if ( xs != 1.f ) {
            xs -= 2.f * xoffs;
        }
        if ( ys != 1.f ) {
            ys -= 2.f * yoffs;
        }

        CGPoint uvs[] = {
            CGPoint::point(u * xs, (v + vdir) * ys),
            CGPoint::point((u + udir) * xs, (v + vdir) * ys),
            CGPoint::point(u * xs, v * ys),
            CGPoint::point((u + udir) * xs, v * ys)
        };

        _drawingList.AddOperation(quad, uvs, 1, _tex, alpha, hasAlpha ? ADM_ALPHA_BLEND : ADM_NO_ALPHA, r, g, b, a, observer);
    } else {
        //  Rotated
        float udir = baseUV[1].x - baseUV[2].x, vdir = baseUV[1].y - baseUV[2].y;
        float xdir = baseQuad[3].x - baseQuad[0].x, ydir = baseQuad[3].y - baseQuad[0].y;

        float left = xdir * float(_x) / _imageWidth, lower = ydir * float(_imageHeight - _y - _height) / _imageHeight;
        float right = left + xdir * float(_width) / _imageWidth, upper = lower + ydir * float(_height) / _imageHeight;

        float x = baseQuad[0].x, y = baseQuad[0].y;
        float u = baseUV[2].x, v = baseUV[2].y;

        CAPoint3D quad[] = {
            CAPoint3D(x + left,  y + upper, 0),
            CAPoint3D(x + right, y + upper, 0),
            CAPoint3D(x + left,  y + lower, 0),
            CAPoint3D(x + right, y + lower, 0),
        };

        float xs = _tex->xscale(), ys = _tex->yscale();
        static const float STEPBACK = .25f;
        float xoffs = STEPBACK / _tex->_texWidth, yoffs = STEPBACK / _tex->_texHeight;

        if ( u != 0.f ) {
            u += xoffs;
        }
        if ( v != 0.f ) {
            v += yoffs;
        }

        if ( xs != 1.f ) {
            xs -= 2.f * xoffs;
        }
        if ( ys != 1.f ) {
            ys -= 2.f * yoffs;
        }

        CGPoint uvs[] = {
            CGPoint::point(u * xs, (v + vdir) * ys),
            CGPoint::point((u + udir) * xs, (v + vdir) * ys),
            CGPoint::point(u * xs, v * ys),
            CGPoint::point((u + udir) * xs, v * ys)
        };

        CGPoint tmp;

        tmp = uvs[0];
        uvs[0] = uvs[2];
        uvs[2] = uvs[3];
        uvs[3] = uvs[1];
        uvs[1] = tmp;

        _drawingList.AddOperation(quad, uvs, 1, _tex, alpha, hasAlpha ? ADM_ALPHA_BLEND : ADM_NO_ALPHA, r, g, b, a, observer);
    }
}

//
// DisplayTexture:
//

DisplayTextureTiled::DisplayTextureTiled(CGImageRef image)
    : DisplayTexture(image->Backing()->Width(), image->Backing()->Height())
{
    LOG_REFS("DisplayTexture created\n");

    switch(image->Backing()->SurfaceFormat()) {
        case _ColorARGB:
        case _ColorRGBA:
            _hasAlpha = image->_has32BitAlpha;
            break;

        case _ColorRGB:
        case _Color565:
            _hasAlpha = false;
            break;

        default:
            _hasAlpha = false;
    }
    _cachedForImage = NULL;
    _realized = false;

    for ( int y = 0; y < _height; y += g_maxTextureResolution ) {
        for ( int x = 0; x < _width; x += g_maxTextureResolution ) {
            SubImage* backing = new SubImage(image, x, y, min(g_maxTextureResolution, _width - x), min(g_maxTextureResolution, _height - y));
            _subImages.add(backing);
        }
    }
}

bool DisplayTextureTiled::flipped() const
{
    return false;
}

bool DisplayTextureTiled::hasAlpha() const
{
    return _hasAlpha;
}

DisplayTexturePregen::DisplayTexturePregen(EbrTexture *tex, int width, int height, bool hasAlpha) :
    DisplayTexture(width, height), _tex(tex), _hasAlpha(hasAlpha), _flipped(false),
    _texWidth(width), _texHeight(height)
{
    LOG_REFS("DisplayTexture created\n");

    _totalDisplayTextures ++;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Total display textures: %d\n", _totalDisplayTextures);
#endif
}

DisplayTexturePregen::~DisplayTexturePregen()
{
    delete _tex;
}

void DisplayTexturePregen::realize()
{
    _tex->realize();
}

bool DisplayTexturePregen::hasAlpha() const
{
    return _hasAlpha;
}

void DisplayTexturePregen::setOpaque(bool opaque)
{
    if ( opaque ) {
        _hasAlpha = false;
    } else {
        _hasAlpha = true;
    }
}

bool DisplayTexturePregen::flipped() const
{
    return _flipped;
}

void DisplayTexturePregen::addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer)
{
    float uscale = float(_texWidth) / _width, vscale = float(_texHeight) / _height;

    for ( int i = 0; i < numQuads * 4; ++i ) {
        texquad[i].x /= uscale;
        texquad[i].y /= vscale;
    }

    _drawingList.AddOperation(quad, texquad, numQuads, _tex, alpha, _hasAlpha ? ADM_ALPHA_BLEND : ADM_NO_ALPHA, r, g, b, a, observer);
}

EbrFastTexture *DisplayTexturePregen::khrBuffer() { 
    return _tex->_khrBuffer; 
}

DisplayTextureKHRDoubleBuffered::DisplayTextureKHRDoubleBuffered(EbrFastTexture *tex1, EbrFastTexture *tex2, int width, int height, int texWidth, int texHeight, bool hasAlpha)
    : DisplayTexture(width, height), _hasAlpha(hasAlpha), _tex1(tex1), _tex2(tex2), _flipped(true), _texWidth(texWidth), _texHeight(texHeight)
{
    LOG_REFS("DisplayTextureKHRDoubleBuffered created\n");

#if defined( USE_KHR_RENDERBUFFERS )
    EbrRetainFastTexture(tex1);
    EbrRetainFastTexture(tex2);
#endif
    _curDrawTex = tex1;

    _totalDisplayTextures ++;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Total display textures: %d\n", _totalDisplayTextures);
#endif
}

DisplayTextureKHRDoubleBuffered::~DisplayTextureKHRDoubleBuffered()
{
#if defined( USE_KHR_RENDERBUFFERS )
    _totalDisplayTextures --;
#ifdef LOG_OBJECT_COUNTS
    EbrDebugLog("Total display textures: %d\n", _totalDisplayTextures);
#endif
#endif
}

void DisplayTextureKHRDoubleBuffered::realize()
{
}

bool DisplayTextureKHRDoubleBuffered::hasAlpha() const
{
    return _hasAlpha;
}

void DisplayTextureKHRDoubleBuffered::setOpaque(bool opaque)
{
    if ( opaque ) {
        _hasAlpha = false;
    } else {
        _hasAlpha = true;
    }
}

bool DisplayTextureKHRDoubleBuffered::flipped() const
{
    return _flipped;
}

void DisplayTextureKHRDoubleBuffered::setActiveDrawTex(EbrFastTexture *tex)
{
    _curDrawTex = tex;
}

void DisplayTextureKHRDoubleBuffered::addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quad, CGPoint *texquad, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer)
{
    float uscale = float(_texWidth) / _width, vscale = float(_texHeight) / _height;

    for ( int i = 0; i < numQuads * 4; ++i ) {
        texquad[i].x /= uscale;
        texquad[i].y /= vscale;
    }

#ifdef USE_KHR_RENDERBUFFERS
    /*
    _drawingList.AddOperation(quad, texquad, numQuads, EbrGetFastTextureBindable(_curDrawTex), alpha,
                              _hasAlpha ? ADM_ALPHA_BLEND : ADM_NO_ALPHA, r, g, b, a, observer);
                              */
    assert(0);
#endif
}

DisplayTexture *DisplayTexture::CachedDisplayTextureForImage(CGImageRef img)
{
    DisplayTexture *ret = NULL;
    DisplayTexture **valPtr;
    EbrLockEnter(_displayTextureCacheLock);
    if ( _displayTextureCache.get(img, valPtr) ) {
        ret = *valPtr;
        ret->AddRef();
    }
    EbrLockLeave(_displayTextureCacheLock);

    return ret;
}

void DisplayTexture::SetCachedDisplayTextureForImage(CGImageRef img, DisplayTexture *texture)
{
    DisplayTexture **valPtr;
    EbrLockEnter(_displayTextureCacheLock);
    if ( texture ) {
        if ( _displayTextureCache.get(img, valPtr) ) {
            assert(0);
        }
        _displayTextureCache.insert(img, texture);
        texture->_cachedForImage = img;
    } else {
        if ( _displayTextureCache.get(img, valPtr) ) {
            (*valPtr)->_cachedForImage = NULL;
            _displayTextureCache.remove(img);
        }
    }
    EbrLockLeave(_displayTextureCacheLock);
}


void DisplayTexture::Release()
{
    EbrLockEnter(_displayTextureCacheLock);
    if ( EbrDecrement((int *) &refCount) == 0 ) {
        if ( _cachedForImage ) {
            _displayTextureCache.remove(_cachedForImage);
        }
        EbrLockLeave(_displayTextureCacheLock);

        if ( pthread_self() != g_RenderThread ) {
            //  Make sure DisplayTextures are destroyed by the thread that created it
            pthread_mutex_lock(&g_DeadTexturesLock);
            if ( g_NumDeadTextures + 1 > g_MaxDeadTextures ) {
                g_MaxDeadTextures += 32;
                g_DeadTextures = (DisplayTexture **) realloc(g_DeadTextures, g_MaxDeadTextures * sizeof(DisplayTexture *));
            }
            g_DeadTextures[g_NumDeadTextures ++] = this;
            pthread_mutex_unlock(&g_DeadTexturesLock);
            GetCACompositor()->RequestRedraw();
        } else {
            delete this;
        }
    } else {
        EbrLockLeave(_displayTextureCacheLock);
    }
}

void DisplayTexture::AddRef()
{
    EbrIncrement((int *) &refCount);
}

EbrTexture *DisplayTextureTiled::getTex()
{
    assert(_subImages.len() == 1);

    return _subImages[0]->_tex;
}

void DisplayTextureTiled::addOperation(CADisplayProperties *presentationProperties, CAPoint3D *quads, CGPoint *texquads, int numQuads, float alpha, float r, float g, float b, float a, DrawingObserver *observer)
{
    // This subdivision logic needs to be more complicated if we're going doing things that aren't axially aligned.
    for ( int i = 0; i < numQuads; ++i ) {
        for ( size_t n = 0; n < _subImages.len(); ++n ) {
            _subImages[n]->addOperation(quads + 4*i, texquads + 4*i, _hasAlpha, alpha, r, g, b, a, observer);
        }
    }
}

void DisplayTextureTiled::realize()
{
    if ( _realized ) return;
    _realized = true;
    for ( size_t i = 0; i < _subImages.len(); ++i ) {
        _subImages[i]->realize();
    }
}

DisplayTextureTiled::~DisplayTextureTiled()
{
    LOG_REFS("DisplayTexture destroyed\n");

    for ( size_t i = 0; i < _subImages.len(); ++i ) {
        delete _subImages[i];
    }

    delete _shapeRenderer;
}

EbrFastTexture *DisplayTextureTiled::khrBuffer() 
{ 
    if ( _subImages.len() > 0 ) 
        return _subImages[0]->_tex->_khrBuffer; 
    else 
        return 0; 
}
ClippingRegion::ClippingRegion()
{
    numClippingLayers = 0;
}

void ClippingRegion::Clear()
{
    numClippingLayers = 0;
}

void ClippingRegion::PushClippingLayer(DisplayNode *layer)
{
    return;
    assert(numClippingLayers < MAX_CLIP_REGION);
    EbrGLESGetTransform(clippingMatricies[numClippingLayers]);
    clippingLayers[numClippingLayers] = layer;
    numClippingLayers ++;

    layer->RenderStencil();
}

void ClippingRegion::PopClippingLayer()
{
    return;
    if ( numClippingLayers > 0 ) {
        clippingLayers[numClippingLayers - 1]->RenderStencil();
    }

    assert(numClippingLayers > 0);
    numClippingLayers --;
}

extern DWORD totalAlloced;
#define MAX_ROOTNODES   16

int g_lastFPSCount;

class DisplayList
{
public:
    DisplayNode *rootNodes[MAX_ROOTNODES];
    int          numRootNodes;

    DisplayList()
    {
        memset(rootNodes, 0, MAX_ROOTNODES * sizeof(DisplayNode *));
        numRootNodes = 0;
    }

    ~DisplayList()
    {
        ReleaseLayers();
    }

    void RenderNodes(ClippingRegion *clip, ID3D11Device1 *device, ID3D11DeviceContext *context, 
                     ID3D11RenderTargetView *renderTarget, ID3D11DepthStencilView *depthTarget)
    {
        double curTime = EbrGetMediaTime();
        g_numQuads = 0;
        g_numVerts = 0;

        //float color[4] = { 1.0f, 0.5f, 0.0f, 1.0f }; // debug color
        float color[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; // not hideous color

        context->ClearRenderTargetView(renderTarget, color);
        if (depthTarget) context->ClearDepthStencilView(depthTarget, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);

#if !NATIVEUI_3D
        context->OMSetDepthStencilState(NULL, 0xFFFFFFFF);
#endif
        context->GSSetShader(NULL, NULL, 0);        

        CATransform3D trans;

        switch ( drawDeviceOrientation ) {
            case 0:
                trans = CATransform3DMakeOrtho(windowInsetLeft, screenWidth - windowInsetRight, screenHeight - windowInsetBottom, windowInsetTop, -100.0f, 100.0f);
                break;

            case 1:
                trans = CATransform3DMakeOrtho(windowInsetTop, screenHeight - windowInsetBottom, screenWidth - windowInsetRight, windowInsetLeft, -100.0f, 100.0f);
                trans = CATransform3DRotate(trans, DEG2RAD(90.0f), 0, 0, 1.0f);
                trans = CATransform3DTranslate(trans, 0, -screenHeight, 0.0f);
                break;

            case 2:
                trans = CATransform3DMakeOrtho(windowInsetLeft, screenWidth - windowInsetRight, screenHeight - windowInsetBottom, windowInsetTop, -100.0f, 100.0f);
                trans = CATransform3DRotate(trans, DEG2RAD(180.0f), 0, 0, 1.0f);
                trans = CATransform3DTranslate(trans, -screenWidth, -screenHeight, 0.0f);
                break;

            case 3:
                trans = CATransform3DMakeOrtho(windowInsetTop, screenHeight - windowInsetBottom, screenWidth - windowInsetRight, windowInsetLeft, -100.0f, 100.0f);
                trans = CATransform3DRotate(trans, DEG2RAD(-90.0f), 0, 0, 1.0f);
                trans = CATransform3DTranslate(trans, -screenWidth, 0.0f, 0.0f);
                break;

        }

        EbrGLESInitDraw();
        EbrGLESSetTransform(context, &trans.m11);

        clip->Clear();
        _drawingList.Reset();

        for ( int i = 0; i < numRootNodes; i ++ ) {
            rootNodes[i]->Reset();
        }
        _activeAnimations.ApplyAnimations(curTime);

        for ( int i = 0; i < numRootNodes; i ++ ) {
            if ( !rootNodes[i]->topMost ) {
                CGPoint origin = CGPoint::point(0.0f, 0.0f);

                rootNodes[i]->Render(clip, origin);
            }
        }

        for ( int i = 0; i < numRootNodes; i ++ ) {
            if ( rootNodes[i]->topMost ) {
                CGPoint origin = CGPoint::point(0.0f, 0.0f);

                rootNodes[i]->Render(clip, origin);
            }
        }

        _drawingList.SortOperations();
        _drawingList.DrawOperations(device, context, renderTarget, depthTarget);

        static int lastSecond = 0;
        int curSecond = (int) curTime;
        g_numFrames ++;
        if (curSecond != lastSecond ) {
            g_lastFPSCount = g_numFrames;
            EbrDebugLog("FPS: %d Active animations: %d Total Animation Objects: %d/%d\n", g_numFrames, g_numActiveAnimations, g_totalDisplayAnimations, g_totalCAAnimations);
            //EbrDebugLog("FPS: %d Quads: %d Verts:%d\n", g_numFrames, g_numQuads, g_numVerts);
            // char buf[512];
            // sprintf(buf, "FPS: %d Active animations: %d Total Animation Objects: %d/%d\n", g_numFrames, g_numActiveAnimations, g_totalDisplayAnimations, g_totalCAAnimations);
            // OutputDebugStringA(buf);
            lastSecond = curSecond;
            g_numFrames = 0;
        }
    }

    struct compareRootLevel
    {
        inline bool operator() (DisplayNode* a, DisplayNode* b)
        {
            return (a->topWindowLevel < b->topWindowLevel);
        }
    };
    
    void SortRootNodes()
    {
        std::sort(rootNodes, rootNodes + numRootNodes, compareRootLevel());
    }

    void AddRootNode(DisplayNode *node)
    {
        assert(numRootNodes < MAX_ROOTNODES);

        node->isRootNode = true;
        rootNodes[numRootNodes] = node;
        rootNodes[numRootNodes]->AddRef();

        numRootNodes ++;

        SortRootNodes();
    }

    void RemoveRootNode(DisplayNode *node)
    {
        for ( int i = 0; i < numRootNodes; i ++ ) {
            if ( rootNodes[i] == node ) {
                node->isRootNode = false;
                memcpy(&rootNodes[i], &rootNodes[i + 1], (numRootNodes - i) * sizeof(DisplayNode *));
                numRootNodes --;
                node->Release();
                return;
            }
        }

        assert(0);
    }

    void AddRootLayer(id layer)
    {
        assert(numRootNodes < MAX_ROOTNODES);

        rootNodes[numRootNodes] = (DisplayNode *) (DWORD) [layer _createDisplayNode];
        rootNodes[numRootNodes]->isRootNode = true;
        rootNodes[numRootNodes]->AddRef();
        [layer _applyAnimations];
        [layer _releaseOldDisplayNode];

        numRootNodes ++;
    }

    void ReleaseLayers()
    {
        for ( int i = 0; i < numRootNodes; i ++ ) {
            rootNodes[i]->Release();
            rootNodes[i] = NULL;
        }
    }

    void CreateDisplayList(id application)
    {
        //  Release all old layers
        ReleaseLayers();

        id windows = [application windows];
        int count = (int) [windows count];

        for ( int i = 0; i < count; i ++ ) {
            id curWindow = [windows objectAtIndex:i];

            id sourceLayer = [curWindow layer];

            if ( sourceLayer != nil ) {
                AddRootLayer(sourceLayer);
            }
        }

        id statusLayer = [[application _statusBarInternal] layer];
        if ( statusLayer != nil ) {
            //  Rebuild layers list
            AddRootLayer(statusLayer);
        }
    }
};

#define MAX_TRASACTION_LISTS 128
TransactionList *performTransactions[MAX_TRASACTION_LISTS];
int performTransactionsHead = 0, performTransactionsTail = 0;
DisplayList      renderTree;

id    mainWindow;

void CreateDisplayList()
{
    if ( !DisplayTransaction::_pendingTransactions ) return;

    if ( DisplayTransaction::_pendingTransactions->GetNumTransactions() > 0 ) {
        TransactionList *newTransactions = new TransactionList();

        while ( (performTransactionsHead + 1) % MAX_TRASACTION_LISTS == performTransactionsTail ) {
            EbrSleep(1000000);
        }
        while ( DisplayTransaction::_pendingTransactions->GetNumTransactions() > 0 ) {
            DisplayTransaction::_pendingTransactions->prepareAndAddToList(newTransactions);
        }

        performTransactions[performTransactionsHead] = newTransactions;
        performTransactionsHead = (performTransactionsHead + 1) % MAX_TRASACTION_LISTS;

        GetCACompositor()->RequestRedraw();
        //EbrDebugLog("Signalling\n");
    }

    _activeAnimations.ProcessAnimationEvents();
    GetCACompositor()->RequestRedraw();
}

EbrLock _compositorLock;

static std::vector<DrawingObserver *> _drawingObservers;

void EbrAddDrawingObserver(DrawingObserver *observer)
{
    _drawingObservers.push_back(observer);
}

void EbrRemoveDrawingObserver(DrawingObserver *observer)
{
    for ( std::vector<DrawingObserver *>::iterator cur = _drawingObservers.begin(); cur != _drawingObservers.end(); cur ++ ) {
        if ( *cur == observer ) {
            _drawingObservers.erase(cur);
            return;
        }
    }
}

extern pthread_t renderTid;

static EbrComPtr<ID3D11RasterizerState> _rasterState;

void EbrConnectCompositor(ID3D11Device1 *device)
{
    //Profiler::get()->start("", RT_LOGSPAM, true);
    
    EbrShaderInit((ID3D11Device *) device);
    CD3D11_RASTERIZER_DESC desc = CD3D11_RASTERIZER_DESC(CD3D11_DEFAULT());
    desc.CullMode = D3D11_CULL_NONE;
    desc.ScissorEnable = FALSE;

    (((ID3D11Device *) device)->CreateRasterizerState(&desc, _rasterState.ReleaseAndGetAddressOf()));

    InitDrawingList(device);

#if NATIVEUI_3D
    CD3D11_TEXTURE2D_DESC dtd(
        DXGI_FORMAT_D24_UNORM_S8_UINT,
        static_cast<UINT>(display_width),
        static_cast<UINT>(display_height),
        1, // This depth stencil view has only one texture.
        1, // Use a single mipmap level.
        D3D11_BIND_DEPTH_STENCIL);
    device->CreateTexture2D(&dtd, nullptr, &_depthStencil);

    CD3D11_DEPTH_STENCIL_VIEW_DESC dsvd(D3D11_DSV_DIMENSION_TEXTURE2DMS);
    device->CreateDepthStencilView(_depthStencil, &dsvd, &_depthStencilView);    
#endif
    EbrGLESInitShaders((ID3D11Device *) device);
}

void EbrDisconnectCompositor()
{
    //Profiler::get()->stop();
    if ( g_cornerTex ) {
        g_cornerTex->Release();
        g_cornerTex = NULL;
    }
    EbrGLESDestroyShaders();
#if NATIVEUI_3D
    if (_depthStencil) {
        _depthStencil->Release();
        _depthStencil = NULL;

        _depthStencilView->Release();
        _depthStencilView = NULL;
    }
#endif
    FontAtlasMan::get()->disconnect();
    EbrShaderDestroy();
    EbrTextureDisconnect();
    _rasterState = nullptr;

    TermDrawingList();
}

bool EbrComposite(ID3D11Device1 *device, ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget)
{
    renderTid = pthread_self();
    EbrLockEnter(_compositorLock);
    g_RenderThread = pthread_self();
    if ( g_NumDeadTextures != 0 ) {
        pthread_mutex_lock(&g_DeadTexturesLock);
        for ( int i = 0; i < g_NumDeadTextures; i ++ ) {
            delete g_DeadTextures[i];
        }
        g_NumDeadTextures = 0;
        pthread_mutex_unlock(&g_DeadTexturesLock);
    }

    while ( performTransactionsTail != performTransactionsHead ) {
        performTransactions[performTransactionsTail]->processTransactions(device);
        delete performTransactions[performTransactionsTail];
        performTransactionsTail = (performTransactionsTail + 1) % MAX_TRASACTION_LISTS;
    }
    FontAtlasMan::get()->process(device, context);

    if ( g_cornerTex == NULL ) {
        CGContextRef context = CGBitmapContextCreate32(64, 64);
        CGImageRef roundedImage = CGBitmapContextGetImage(context);
        CGImageRetain(roundedImage);

        CGRect rect = CGRectMake(0.0f, 0.0f, 64.0f, 64.0f);

        CGContextClearRect(context, rect);
        CGContextSetGrayFillColor(context, 1.0f, 1.0f);
        CGContextBeginPath(context);

        CGContextMoveToPoint(context, 0, 0);
        CGContextAddArc(context, 0.0f, 64.0f, 64.0f, float(M_PI + M_PI / 2.0), float(2 * M_PI), 0);
        CGContextAddLineToPoint(context, 0.0f, 64.0f);

        //CGContextAddLineToPoint(&context, rect.origin.x + rect.size.width, rect.origin.y + rect.size.height);
        CGContextClosePath(context);

        CGContextSetLineWidth(context, 0.0f);
        CGContextFillPath(context);

        CGContextRelease(context);

        g_cornerTex = (DisplayTextureTiled *) UIGetDisplayTextureForCGImage(roundedImage, true);
        g_cornerTex->realize();
    }

    //EbrDebugLog("Composite started\n");

    if ( CASignalDisplayLink() ) {
        GetCACompositor()->RequestRedraw();
    }

    static ClippingRegion clip;

    context->RSSetState(_rasterState.Get());

    float viewWidth = dxLandscape ? screenHeight : screenWidth;
    float viewHeight = dxLandscape ? screenWidth : screenHeight;

    float aspectX = (float) windowWidth / (float) (viewWidth - (windowInsetLeft + windowInsetRight));
    float aspectY = (float) windowHeight / (float) (viewHeight - (windowInsetTop + windowInsetBottom));

    float aspect = aspectX < aspectY ? aspectX : aspectY;

    float outWidth = (viewWidth - (windowInsetLeft + windowInsetRight)) * aspect;
    float outHeight = (viewHeight - (windowInsetTop + windowInsetBottom)) * aspect;

    float leftX = ((float) windowWidth - outWidth) / 2.0f;
    float topY = ((float) windowHeight - outHeight) / 2.0f;

    D3D11_VIEWPORT viewport;
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = windowWidth;
    viewport.Height = windowHeight;

    viewport.TopLeftX = leftX;
    viewport.TopLeftY = topY;
    viewport.Width = outWidth;
    viewport.Height = outHeight;
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    context->RSSetViewports(1, &viewport);

    clip.Clear();

    if (_drawingAllowed) {
        for ( std::vector<DrawingObserver *>::iterator cur = _drawingObservers.begin(); cur != _drawingObservers.end(); cur ++ ) {
            (*cur)->drawingBegan();
        }

        renderTree.RenderNodes(&clip, device, context, renderTarget, _depthStencilView);

        for ( std::vector<DrawingObserver *>::iterator cur = _drawingObservers.begin(); cur != _drawingObservers.end(); cur ++ ) {
            (*cur)->drawingEnded();
        }
    }
    
    EbrLockLeave(_compositorLock);
    
    return renderTree.numRootNodes > 0;
}

TransactionList *DisplayTransaction::_pendingTransactions;

void DisplayTransaction::addNode(DisplayNode *node, DisplayNode *superNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = addNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.addToNode = superNode;
    newTransaction->_params.addBefore = NULL;
    newTransaction->_params.addAfter = NULL;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::addNodeBefore(DisplayNode *node, DisplayNode *beforeNode, DisplayNode *superNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = addNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.addToNode = superNode;
    newTransaction->_params.addBefore = beforeNode;
    newTransaction->_params.addAfter = NULL;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::addNodeAfter(DisplayNode *node, DisplayNode *afterNode, DisplayNode *superNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = addNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.addToNode = superNode;
    newTransaction->_params.addBefore = NULL;
    newTransaction->_params.addAfter = afterNode;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::sortWindowLevels()
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = sortWindowLevelsTransaction;

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::moveNodeBefore(DisplayNode *node, DisplayNode *beforeNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = moveNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.addBefore = beforeNode;
    newTransaction->_params.addAfter = NULL;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::moveNodeAfter(DisplayNode *node, DisplayNode *afterNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = moveNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.addBefore = NULL;
    newTransaction->_params.addAfter = afterNode;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}


void DisplayTransaction::removeNode(DisplayNode *node)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = removeNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::setNewPatternBackground(DisplayNode *node, CGColorRef pattern)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = applyBackgroundPatternTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.newPatternBackground = pattern;

    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::setNodeTexture(DisplayNode *node, DisplayTexture *newTexture, CGSize contentSize, float contentsScale)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = applyDisplayTextureTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.contentSize = contentSize;
    newTransaction->_params.contentScale = contentsScale;
    newTransaction->_params.newDisplayTexture = newTexture;
    newTransaction->_params.maskNode = NULL;

    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::setNodeMaskNode(DisplayNode *node, DisplayNode *maskNode)
{
    DisplayTransaction *newTransaction = new DisplayTransaction;
    newTransaction->_transaction = applyMaskNodeTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.maskNode = maskNode;

    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::setNewProperty(DisplayNode *node, const char *name, NSObject *newValue)
{
    if ( strcmp(name, "backgroundColor") == 0) {
        if ( (int) [newValue _type] != solidBrush ) {
            DisplayTransaction::setNewPatternBackground(node, (CGColorRef) newValue);
            return;
        }
    }

    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = applyPropertiesTransaction;
    newTransaction->_params.node = node;
    newTransaction->_params.propertyName = name;
    newTransaction->_params.newPropertyValue = newValue;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::addAnimation(id layer, id animation, id forKey)
{
    CALayer* displayLayer = layer;

    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = addAnimationTransaction;
    newTransaction->_params.node = _LazyCAPrivInfo.member(displayLayer)->_presentationNode;
    newTransaction->_params.layer = layer;
    newTransaction->_params.animation = animation;
    newTransaction->_params.animationKey = forKey;
    newTransaction->_params.displayAnimation = NULL;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::addAnimationRaw(DisplayNode *pNode, DisplayAnimation *pAnim)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = addAnimationTransaction;
    newTransaction->_params.node = pNode;
    newTransaction->_params.layer = nil;
    newTransaction->_params.animation = nil;
    newTransaction->_params.displayAnimation = pAnim;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

void DisplayTransaction::removeAnimationRaw(DisplayNode *pNode, DisplayAnimation *pAnim)
{
    DisplayTransaction *newTransaction = new DisplayTransaction();
    newTransaction->_transaction = removeAnimationTransaction;
    newTransaction->_params.node = pNode;
    newTransaction->_params.layer = nil;
    newTransaction->_params.animation = nil;
    newTransaction->_params.displayAnimation = pAnim;
    newTransaction->RetainParams();

    if ( _pendingTransactions == NULL ) {
        _pendingTransactions = new TransactionList();
    }

    _pendingTransactions->AddTransaction(newTransaction, true);
}

TransactionList::TransactionList()
{
    _numTransactions = 0;
    _maxTransactions = 0;
    _transactions = NULL;
    EbrLockInit(&crit);
}

TransactionList::~TransactionList()
{
    EbrLockDestroy(crit);
    free(_transactions);
}

void TransactionList::Lock()
{
    EbrLockEnter(crit);
}

void TransactionList::Unlock()
{
    EbrLockLeave(crit);
}

void TransactionList::prepareAndAddToList(TransactionList *addToList)
{
    Lock();

    //  Copy out the transaction and clear it
    if ( _numTransactions == 0 ) {
        Unlock();
        return;
    }
    int numCopiedTransactions = _numTransactions;
    DisplayTransaction **pListCopy = (DisplayTransaction **) malloc(numCopiedTransactions * sizeof(DisplayTransaction *));
    memcpy(pListCopy, _transactions, numCopiedTransactions * sizeof(DisplayTransaction *));

    _numTransactions = 0;

    Unlock();

    //  Prepare transactions
    for ( int i = 0; i < numCopiedTransactions; i ++ ) {
        DisplayTransaction *cur = pListCopy[i];

        switch ( cur->_transaction ) {
            case DisplayTransaction::addAnimationTransaction:
            {
                if ( cur->_params.displayAnimation == NULL ) {
                    if ( ![cur->_params.animation wasRemoved] ) {
                        DisplayAnimation *newAnimation = (DisplayAnimation *) (DWORD) [cur->_params.animation _createAnimation:cur->_params.layer forKey:cur->_params.animationKey];
                        cur->_params.displayAnimation = newAnimation;
                        newAnimation->AddRef();

                        if ( [cur->_params.animation wasAborted] ) {
                            //  Abort the animation early
                            newAnimation->_abort = TRUE;
                        }
                    }
                }
            }
                break;

            case DisplayTransaction::applyMaskNodeTransaction: 
            case DisplayTransaction::applyDisplayTextureTransaction: 
            case DisplayTransaction::applyPropertiesTransaction:    //  fallthrough
                break;

            case DisplayTransaction::applyBackgroundPatternTransaction: {
                CGImageRef pImage = (CGImageRef ) [cur->_params.newPatternBackground _getPatternImage];
                cur->_params.newPatternTexture = UIGetDisplayTextureForCGImage(pImage, true);
                CGImageRelease((CGImageRef) pImage);
            }
                break;

            case DisplayTransaction::addNodeTransaction:
            case DisplayTransaction::removeNodeTransaction:
            case DisplayTransaction::removeAnimationTransaction:
            case DisplayTransaction::moveNodeTransaction:
                break;

            case DisplayTransaction::sortWindowLevelsTransaction:
                break;

            default:
                assert(0);
        }

        addToList->AddTransaction(cur);
    }

    free(pListCopy);
}

int TransactionList::GetNumTransactions()
{
    Lock();
    int ret = _numTransactions;
    Unlock();

    return ret;
}

DisplayTransaction::DisplayTransaction()
{
    memset(&_params, 0, sizeof(_params));
}

DisplayTransaction::~DisplayTransaction()
{
    if ( _params.node != NULL ) {
        _params.node->Release();
    }
    if ( _params.parentNode != NULL ) {
        _params.parentNode->Release();
    }
    if ( _params.addToNode != NULL ) {
        _params.addToNode->Release();
    }
    if ( _params.addBefore != NULL ) {
        _params.addBefore->Release();
    }
    if ( _params.addAfter != NULL ) {
        _params.addAfter->Release();
    }
    if ( _params.maskNode != NULL ) {
        _params.maskNode->Release();
    }
    if ( _params.newDisplayTexture != NULL ) {
        _params.newDisplayTexture->Release();
    }
    if ( _params.newPatternTexture != NULL ) {
        _params.newPatternTexture->Release();
    }
    if ( _params.displayAnimation != NULL ) {
        _params.displayAnimation->Release();
    }
    if ( _params.layer != nil ) {
        [_params.layer release];
    }
    if ( _params.animation != nil ) {
        [_params.animation release];
    }
    if ( _params.animationKey != nil ) {
        [_params.animationKey release];
    }
    [_params.newPatternBackground release];
    [_params.newPropertyValue release];
}

void DisplayTransaction::RetainParams()
{
    if ( _params.node != NULL ) {
        _params.node->AddRef();

        if ( _params.node->parentNode != NULL && _params.parentNode == NULL ) {
            //  To ensure that parent node doesn't get destroyed prematurely
            _params.parentNode = _params.node->parentNode;
        }
        if ( _params.parentNode != NULL ) {
            _params.parentNode->AddRef();
        }
    }
    if ( _params.addToNode != NULL ) {
        _params.addToNode->AddRef();
    }
    if ( _params.addBefore != NULL ) {
        _params.addBefore->AddRef();
    }
    if ( _params.addAfter != NULL ) {
        _params.addAfter->AddRef();
    }
    if ( _params.maskNode != NULL ) {
        _params.maskNode->AddRef();
    }
    if ( _params.newDisplayTexture != NULL ) {
        _params.newDisplayTexture->AddRef();
    }
    if ( _params.newPatternTexture != NULL ) {
        _params.newPatternTexture->AddRef();
    }
    if ( _params.displayAnimation != NULL ) {
        _params.displayAnimation->AddRef();
    }
    if ( _params.layer != nil ) {
        [_params.layer retain];
    }
    if ( _params.animation != nil ) {
        [_params.animation retain];
    }
    if ( _params.animationKey != nil ) {
        [_params.animationKey retain];
    }
    [_params.newPatternBackground retain];
    [_params.newPropertyValue retain];
}

void TransactionList::AddTransaction(DisplayTransaction *pTransaction, bool issueRefresh)
{
    Lock();

    if ( _numTransactions >= _maxTransactions ) {
        _maxTransactions += 64;

        _transactions = (DisplayTransaction **) realloc(_transactions, _maxTransactions * sizeof(DisplayTransaction *));
    }

    _transactions[_numTransactions ++] = pTransaction;

    Unlock();

    if ( issueRefresh ) {
        GetCACompositor()->DisplayTreeChanged();
    }
}

void ApplyNamedProperty(CADisplayProperties *props, const char *name, NSObject *newValue)
{
    if ( !name ) return;

    if ( strcmp(name, "contentsCenter") == 0 ) {
        props->contentsCenter = [(NSValue *) newValue CGRectValue];
    } else  if ( strcmp(name, "anchorPoint") == 0 ) {
        props->anchorPoint = [(NSValue *) newValue CGPointValue];
    } else if ( strcmp(name, "position") == 0 ) {
        props->position = [(NSValue *) newValue CGPointValue];
    } else if ( strcmp(name, "bounds.origin") == 0 ) {
        props->bounds.origin = [(NSValue *) newValue CGPointValue];
    } else if ( strcmp(name, "bounds.size") == 0 ) {
        props->bounds.size = [(NSValue *) newValue CGSizeValue];
    } else if ( strcmp(name, "opacity") == 0 ) {
        props->opacity = [(NSNumber *) newValue floatValue];
    } else if ( strcmp(name, "hidden") == 0 ) {
        props->hidden = [(NSNumber *) newValue intValue];
    } else if ( strcmp(name, "masksToBounds") == 0 ) {
        props->masksToBounds = [(NSNumber *) newValue boolValue];
    } else if ( strcmp(name, "transform") == 0 ) {
        props->transform = [(NSValue *) newValue CATransform3DValue];
    } else if ( strcmp(name, "overrideBounds") == 0 ) {
        props->overrideBounds = [(NSValue *) newValue CGRectValue];
        props->forceOverrideBounds = TRUE;
    } else if ( strcmp(name, "contentsScale") == 0 ) {
        props->contentsScale = [(NSNumber *) newValue floatValue];
    } else if ( strcmp(name, "contentsOrientation") == 0 ) {
        props->contentsOrientation = [(NSNumber *) newValue intValue];
    } else if ( strcmp(name, "gravity") == 0 ) {
        props->gravity = [(NSNumber *) newValue intValue];
    } else if ( strcmp(name, "zPosition") == 0 ) {
        props->zPosition = [(NSNumber *) newValue floatValue];
    } else if ( strcmp(name, "backgroundColor") == 0 ) {
        if ( newValue != nil ) {
            [(UIColor *) newValue getColors:&props->backgroundColor];
        } else {
            props->backgroundColor.r = 0;
            props->backgroundColor.g = 0;
            props->backgroundColor.b = 0;
            props->backgroundColor.a = 0;
        }
    } else if ( strcmp(name, "contentColor") == 0 ) {
        [(UIColor *) newValue getColors:&props->contentColor];
    } else if ( strcmp(name, "sublayerTransform") == 0 ) {
        props->sublayerTransform = [(NSValue *) newValue CATransform3DValue];
    } else {
        assert(0);
    }
}

void TransactionList::processTransactions(ID3D11Device1 *device)
{
    LOG_REFS("Processing new prepared transactions\n");

    //  Process view heirarchy update commands
    for ( int i = 0; i < _numTransactions; i ++ ) {
        DisplayTransaction *cur = _transactions[i];

        switch ( cur->_transaction ) {
            case DisplayTransaction::applyDisplayTextureTransaction:
            {
                if ( cur->_params.newDisplayTexture) {
                    cur->_params.newDisplayTexture->AddRef();
                }
                if ( cur->_params.node->pTexture != NULL ) {
                    cur->_params.node->pTexture->Release();
                }

                cur->_params.node->pTexture = cur->_params.newDisplayTexture;
                cur->_params.node->originalPresentationProperties.contentsSize = cur->_params.contentSize;
                cur->_params.node->originalPresentationProperties.contentsScale = cur->_params.contentScale;
                if ( cur->_params.node->pTexture != NULL ) cur->_params.node->pTexture->realize();
            }
                break;
                
            case DisplayTransaction::applyMaskNodeTransaction:
            {
                if ( cur->_params.node->maskNode != NULL ) {
                    cur->_params.node->maskNode->Release();
                }
                cur->_params.node->maskNode = cur->_params.maskNode;
                if ( cur->_params.node->maskNode != NULL ) cur->_params.node->maskNode->AddRef();
                break;
            }           

            case DisplayTransaction::applyBackgroundPatternTransaction:
            {
                if ( cur->_params.newPatternTexture) {
                    cur->_params.newPatternTexture->AddRef();
                }
                if ( cur->_params.node->pBackgroundTexture != NULL ) {
                    cur->_params.node->pBackgroundTexture->Release();
                }

                cur->_params.node->pBackgroundTexture = cur->_params.newPatternTexture;
                if ( cur->_params.node->pBackgroundTexture != NULL ) cur->_params.node->pBackgroundTexture->realize();
            }
                break;

            case DisplayTransaction::applyPropertiesTransaction:
            {
                ApplyNamedProperty(&cur->_params.node->originalPresentationProperties, cur->_params.propertyName, cur->_params.newPropertyValue);
            }
                break;

            case DisplayTransaction::addNodeTransaction:
                if ( cur->_params.addToNode != NULL ) {
                    if ( cur->_params.addBefore != NULL ) {
                        cur->_params.addToNode->AddSubnodeBefore(cur->_params.node, cur->_params.addBefore);
                    } else if ( cur->_params.addAfter != NULL ) {
                        cur->_params.addToNode->AddSubnodeAfter(cur->_params.node, cur->_params.addAfter);
                    } else {
                        cur->_params.addToNode->AddSubnode(cur->_params.node);
                    }
                } else {
                    renderTree.AddRootNode(cur->_params.node);
                }
                break;

            case DisplayTransaction::moveNodeTransaction:
                if ( cur->_params.addBefore != NULL ) {
                    assert(cur->_params.addBefore->parentNode != NULL);
                    cur->_params.addBefore->parentNode->MoveSubnodeBefore(cur->_params.node, cur->_params.addBefore);
                } else if ( cur->_params.addAfter != NULL ) {
                    assert(cur->_params.addAfter->parentNode != NULL);
                    cur->_params.addAfter->parentNode->MoveSubnodeAfter(cur->_params.node, cur->_params.addAfter);
                } else {
                    assert(0);
                }
                break;

            case DisplayTransaction::removeNodeTransaction:
                if ( cur->_params.node->GetParentNode() != NULL ) {
                    cur->_params.node->GetParentNode()->RemoveSubnode(cur->_params.node);
                } else {
                    renderTree.RemoveRootNode(cur->_params.node);
                }
                break;

            case DisplayTransaction::sortWindowLevelsTransaction:
                renderTree.SortRootNodes();
                break;
        }
    }

    //  Process animation commands
    for ( int i = 0; i < _numTransactions; i ++ ) {
        DisplayTransaction *cur = _transactions[i];

        switch ( cur->_transaction ) {
            case DisplayTransaction::removeAnimationTransaction:
            {
                cur->_params.node->RemoveAnimation(cur->_params.displayAnimation);
            }
                break;

            case DisplayTransaction::addAnimationTransaction:
            {
                if ( cur->_params.displayAnimation != NULL ) cur->_params.node->AddAnimation(cur->_params.displayAnimation);
            }
                break;
        }
    }

    for ( int i = 0; i < _numTransactions; i ++ ) {
        DisplayTransaction *cur = _transactions[i];
        delete cur;
    }
}

void DisplayShape::RenderShape(CADisplayProperties *properties)
{
}

DisplayShape::~DisplayShape()
{
}

int pthread_cond_wait_ms(pthread_cond_t *cond, pthread_mutex_t *mutex, unsigned int ms);
EbrComPtr<ID3D11Device1> m_AngleD3dDevice;

int drawDeviceOrientation = 0;
int curDeviceOrientation = 0;

pthread_t renderTid;

pthread_cond_t _openGLControlCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t _openGLControlMutex = PTHREAD_MUTEX_INITIALIZER;

extern int g_browsersVisible;

static volatile BOOL _openGLControlObtained = FALSE, _openGLControlReleased = FALSE, _openGLControlRequested = FALSE;
BOOL _appCrashed = FALSE;
static DWORD _glOwningThreadId;

void AcquireOpenGLControl()
{
    pthread_mutex_lock(&_openGLControlMutex);
    for ( ;; ) {
        if ( _openGLControlObtained ) {
            _openGLControlRequested = FALSE;
            _openGLControlReleased = FALSE;
            _glOwningThreadId = GetCurrentThreadId();
            pthread_mutex_unlock(&_openGLControlMutex);
            return;
        }

        _openGLControlRequested = TRUE;
        GetCACompositor()->RequestRedraw();
        pthread_cond_signal(&_openGLControlCond);
        pthread_cond_wait(&_openGLControlCond, &_openGLControlMutex);
    }
}

void ReleaseOpenGLControl()
{
    pthread_mutex_lock(&_openGLControlMutex);
    if ( !_openGLControlObtained ) {
        pthread_mutex_unlock(&_openGLControlMutex);
        return;
    }

    _openGLControlObtained = FALSE;
    _openGLControlReleased = TRUE;
    _glOwningThreadId = 0;

    pthread_cond_signal(&_openGLControlCond);
    pthread_mutex_unlock(&_openGLControlMutex);
}

void ProvideOpenGLControl()
{
    if ( _appCrashed ) return;

    pthread_mutex_lock(&_openGLControlMutex);

    for ( ;; ) {
        bool didProvide = false;

        //  OpenGL control has been requested
        if ( _openGLControlRequested ) {
            //  Provide OpenGL control
            _openGLControlObtained = TRUE;
            pthread_cond_signal(&_openGLControlCond);

            //  Wait for the client to finish with it
            for ( ;; ) {
                if ( _openGLControlReleased ) break;
                pthread_cond_wait(&_openGLControlCond, &_openGLControlMutex);
            }

            _openGLControlReleased = FALSE;
            didProvide = true;
        }

        if ( !g_directDraw || didProvide ) break;
        //  Wait for conrol to be requested
        int result = pthread_cond_wait_ms(&_openGLControlCond, &_openGLControlMutex, 100);
        if (result != 0){
            //  Timed out - go ahead and draw a frame
            break;
        }
    }

    //  We now have full OpenGL control
    _openGLControlObtained = FALSE;
    pthread_mutex_unlock(&_openGLControlMutex);
}

void ReleaseOpenGLControlAfterCrash()
{
    pthread_mutex_lock(&_openGLControlMutex);
    _appCrashed = TRUE;
    if ( !_openGLControlObtained || _glOwningThreadId != GetCurrentThreadId() ) {
        if ( _glOwningThreadId == 0 ) {
            pthread_cond_signal(&_openGLControlCond);
        }
        pthread_mutex_unlock(&_openGLControlMutex);
        return;
    }

    _openGLControlObtained = FALSE;
    _openGLControlReleased = TRUE;
    _glOwningThreadId = 0;

    pthread_cond_signal(&_openGLControlCond);
    pthread_mutex_unlock(&_openGLControlMutex);
}

UIApplicationState _applicationState;

void ProvideOpenGLControlAndWaitForBackground()
{
    for ( ;; ) {
        if ( _applicationState == 2 ) return;
        if ( _appCrashed ) return;

        pthread_mutex_lock(&_openGLControlMutex);

        //  OpenGL control has been requested
        if ( _openGLControlRequested ) {
            //  Provide OpenGL control
            _openGLControlObtained = TRUE;
            pthread_cond_signal(&_openGLControlCond);

            //  Wait for the client to finish with it
            for ( ;; ) {
                if ( _openGLControlReleased ) break;
                pthread_cond_wait(&_openGLControlCond, &_openGLControlMutex);
            }

            _openGLControlReleased = FALSE;
            _openGLControlObtained = FALSE;
        }

        //  We now have full OpenGL control
        pthread_mutex_unlock(&_openGLControlMutex);

        EbrSleep(50LL * 1000000LL);
    }
}

void RenderFrame(ID3D11Device1 *device, ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget)
{
    EbrTextureAcquireLock(m_AngleD3dDevice.Get());
    ProvideOpenGLControl();
    EbrTextureReleaseLock(m_AngleD3dDevice.Get());

    EbrComposite(device, context, renderTarget);
}

static CACompositorClientInterface *_client;

class DXCompositor : public CACompositorInterface
{
public:
    virtual void DisplayTreeChanged() 
    {
        _client->RequestTransactionProcessing();
    }
    virtual DisplayNode *CreateDisplayNode() 
    {
        DisplayNode *ret = new DisplayNode();
        ret->AddRef();

        return ret;
    }

    virtual void addNode(DisplayTransaction *transaction, DisplayNode *node, DisplayNode *superNode, DisplayNode *beforeNode, DisplayNode *afterNode) 
    {
        assert(!(beforeNode != NULL && afterNode != NULL));

        if ( beforeNode ) {
            DisplayTransaction::addNodeBefore(node, beforeNode, superNode);
        } else if ( afterNode ) {
            DisplayTransaction::addNodeAfter(node, afterNode, superNode);
        } else {
            DisplayTransaction::addNode(node, superNode);
        }
    }

    virtual void setNodeTopMost(DisplayNode *node, bool topMost) 
    {
        node->topMost = topMost;
    }

    virtual void setNodeTopWindowLevel(DisplayNode *node, float level) 
    {
        node->topWindowLevel = level;
    }

    virtual void sortWindowLevels() 
    {
        DisplayTransaction::sortWindowLevels();
    }

    DisplayTransaction *CreateDisplayTransaction() 
    {
        return NULL;
    }

    void CommitDisplayTransaction(DisplayTransaction *transaction) 
    {
    }

    void QueueDisplayTransaction(DisplayTransaction *transaction, DisplayTransaction *onTransaction) 
    {
    }

    virtual void moveNode(DisplayTransaction *transaction, DisplayNode *node, DisplayNode *beforeNode, DisplayNode *afterNode) 
    {
        assert(!(beforeNode != NULL && afterNode != NULL));

        if ( beforeNode ) {
            DisplayTransaction::moveNodeBefore(node, beforeNode);
        } else if ( afterNode ) {
            DisplayTransaction::moveNodeAfter(node, afterNode);
        } else {
            assert(0);
        }
    }

    virtual void removeNode(DisplayTransaction *transaction, DisplayNode *node)
    {
        DisplayTransaction::removeNode(node);
    }

    virtual void addAnimation(DisplayTransaction *transaction, id layer, id animation, id forKey) 
    {
        DisplayTransaction::addAnimation(layer, animation, forKey);
    }

    virtual void addAnimationRaw(DisplayTransaction *transaction, DisplayNode *pNode, DisplayAnimation *pAnimation) 
    {
        DisplayTransaction::addAnimationRaw(pNode, pAnimation);
    }

    virtual void removeAnimationRaw(DisplayTransaction *transaction, DisplayNode *pNode, DisplayAnimation *pAnimation) 
    {
        DisplayTransaction::removeAnimationRaw(pNode, pAnimation);
    }

    virtual void setNodeTexture(DisplayTransaction *transaction, DisplayNode *node, DisplayTexture *newTexture, CGSize contentSize, float contentsScale) 
    {   
        DisplayTransaction::setNodeTexture(node, newTexture, contentSize, contentsScale);
    }

    virtual void setNodeMaskNode(DisplayNode *node, DisplayNode *maskNode) 
    {
        DisplayTransaction::setNodeMaskNode(node, maskNode);
    }

    virtual void setDisplayProperty(DisplayTransaction *transaction, DisplayNode *node, const char *propertyName, NSObject *newValue)
    {
        DisplayTransaction::setNewProperty(node, propertyName, newValue);
    }

    virtual DisplayTexture * GetDisplayTextureForCGImage(CGImageRef img, bool create) 
    {
        return UIGetDisplayTextureForCGImage(img, create);
    }

    virtual DisplayTexture * CreateDisplayTextureForText() 
    {
        DisplayTexture *textLayer = new DisplayTextureFontAtlas();
        textLayer->AddRef();
        return textLayer;
    }

    virtual void SetTextDisplayTextureParams(DisplayTexture *texture, id font, id text, id color, UITextAlignment alignment, UILineBreakMode lineBreak, id shadowColor,
                            const CGSize &shadowOffset, int numLines, UIEdgeInsets edgeInsets, bool centerVertically) 
    {
        ((DisplayTextureFontAtlas*) texture)->SetParams(font, text, color, alignment, lineBreak, shadowColor, shadowOffset, numLines, edgeInsets, centerVertically);
    }

    virtual DisplayAnimation * GetBasicDisplayAnimation(id animobj, NSString *propertyName, NSObject *fromValue, NSObject *toValue, CAMediaTimingProperties *timingProperties) 
    {
        BasicAnimation *newAnim = new BasicAnimation(animobj);
        newAnim->AddRef();
        newAnim->timingProperties = *timingProperties;
        strcpy(newAnim->_propName, [propertyName UTF8String]);
        if ( strcmp(newAnim->_propName, "opacity") == 0 ||
             strcmp(newAnim->_propName, "position.x") == 0 ||
             strcmp(newAnim->_propName, "position.y") == 0 ||
             strcmp(newAnim->_propName, "transform.rotation") == 0 || 
             strcmp(newAnim->_propName, "transform.rotation.x") == 0 ||
             strcmp(newAnim->_propName, "transform.rotation.y") == 0 ||
             strcmp(newAnim->_propName, "transform.rotation.z") == 0 ||
             strcmp(newAnim->_propName, "transform.scale") == 0 )
        {
            newAnim->_floatFrom = [fromValue floatValue];
            newAnim->_floatTo = [toValue floatValue];
        } else if ( strcmp(newAnim->_propName, "position") == 0 ) {
            newAnim->_pointFrom = [fromValue CGPointValue];
            newAnim->_pointTo = [toValue CGPointValue];
        } else if ( strcmp(newAnim->_propName, "bounds") == 0 ) {
            newAnim->_rectFrom = [fromValue CGRectValue];
            newAnim->_rectTo = [toValue CGRectValue];
        } else if ( strcmp(newAnim->_propName, "bounds.origin") == 0 ) {
            newAnim->_pointFrom = [fromValue CGPointValue];
            newAnim->_pointTo = [toValue CGPointValue];
        } else if ( strcmp(newAnim->_propName, "bounds.size") == 0 ) {
            newAnim->_sizeFrom = [fromValue CGSizeValue];
            newAnim->_sizeTo = [toValue CGSizeValue];
        } else if ( strcmp(newAnim->_propName, "transform") == 0 ) {
            newAnim->_transformFrom = [fromValue CATransform3DValue];
            newAnim->_transformTo = [toValue CATransform3DValue];
        }

        return newAnim;
    }

    virtual DisplayAnimation * GetMoveDisplayAnimation(DisplayAnimation **secondAnimRet, id animobj, DisplayNode *animNode, NSString *typeStr, NSString *subtypeStr, CAMediaTimingProperties *timingProperties) 
    {
        DisplayAnimation *ret;
        MoveAnimation *anim1 = new MoveAnimation(animobj);
        ret = anim1;
        ret->AddRef();

        anim1->timingProperties = *timingProperties;

        char *pType = (char *) [typeStr UTF8String];
        char *pSubtype = (char *) [subtypeStr UTF8String];

        MoveAnimation::MoveType type;
        MoveAnimation::MoveSubType subtype;

        if ( pType == NULL || strcmp(pType, "kCATransitionFade") == 0 ) {
            type = MoveAnimation::fade;
        } else if ( strcmp(pType, "kCATransitionMoveIn") == 0 ) {
            type = MoveAnimation::moveIn;
        } else if ( strcmp(pType, "kCATransitionPush") == 0 ) {
            type = MoveAnimation::push;
        } else if ( strcmp(pType, "kCATransitionReveal") == 0 || strcmp(pType, "zoomyIn") == 0 ) {
            type = MoveAnimation::reveal;
        } else if ( strcmp(pType, "kCATransitionSqueeze") == 0 ) {
            type = MoveAnimation::squeeze;
        } else if ( strcmp(pType, "kCATransitionFlip") == 0 ) {
            type = MoveAnimation::squeeze;
        } else assert(0);

        if ( pSubtype ) {
            if ( strcmp(pSubtype, "kCATransitionFromRight") == 0 ) {
                subtype = MoveAnimation::fromRight;
            } else if ( strcmp(pSubtype, "kCATransitionFromTop") == 0 ) {
                subtype = MoveAnimation::fromTop;
            } else if ( strcmp(pSubtype, "kCATransitionFromBottom") == 0 ) {
                subtype = MoveAnimation::fromBottom;
            } else if ( strcmp(pSubtype, "kCATransitionFromLeft") == 0 || strcmp(pSubtype, "fromLeft") == 0 ) {
                subtype = MoveAnimation::fromLeft;
            } else assert(0);
        } else {
            subtype = MoveAnimation::fromLeft;
        }

        anim1->moveType = type;
        anim1->moveSubType = subtype;
        anim1->inverted = false;

        EbrLockEnter(_compositorLock);
        DisplayNode *node = animNode;
        *secondAnimRet = NULL;
        if ( node != NULL && node->GetParentNode() != NULL ) {
            DisplayNode *nodeCopy = node->Clone();

            switch ( type ) {
                case MoveAnimation::push:
                case MoveAnimation::moveIn:
                case MoveAnimation::fade:
                case MoveAnimation::squeeze:
                    DisplayTransaction::addNodeBefore(nodeCopy, node, node->GetParentNode());
                    break;

                case MoveAnimation::reveal:
                    DisplayTransaction::addNodeAfter(nodeCopy, node, node->GetParentNode());
                    break;
            }

            MoveAnimation *anim2 = new MoveAnimation(nil);
            anim2->timingProperties = *timingProperties;
            anim2->moveType = type;
            anim2->moveSubType = subtype;
            anim2->inverted = true;
            *secondAnimRet = anim2;
            (*secondAnimRet)->AddRef();

            DisplayTransaction::addAnimationRaw(nodeCopy, anim2);
        }
        EbrLockLeave(_compositorLock);

        return ret;
    }

    virtual void RetainAnimation(DisplayAnimation *animation) 
    {
        animation->AddRef();
    }

    virtual void ReleaseAnimation(DisplayAnimation *animation) 
    {
        animation->Release();
    }


    virtual void RetainNode(DisplayNode *node) 
    {
        node->AddRef();
    }

    virtual void ReleaseNode(DisplayNode *node) 
    {
        node->Release();
    }

    virtual void RetainDisplayTexture(DisplayTexture *tex) 
    {
        tex->AddRef();
    }

    virtual void ReleaseDisplayTexture(DisplayTexture *tex) 
    {
        tex->Release();
    }

    void LockD3DDisplayTexture(DisplayTexture *tex)
    {
        ::AcquireOpenGLControl();
    }
    void UnlockD3DDisplayTexture(DisplayTexture *tex)
    {
        ::ReleaseOpenGLControl();
    }

    DisplayTexture *GetDisplayTextureForD3D(ID3D11Device1 *device, ID3D11DeviceContext1 *context, ID3D11Texture2D *tex, int width, int height) 
    {
        m_AngleD3dDevice = device;
        EbrTextureOpenGL *glTex = new EbrTextureOpenGL(device, tex, width, height);
        DisplayTexturePregen *drawTex = new DisplayTexturePregen(glTex, width, height, false);
        drawTex->_flipped = true;

        return drawTex;
    }

    void SortWindowLevels()
    {
        DisplayTransaction::sortWindowLevels();
    }

    virtual bool isTablet() 
    {
        return tabletMode;
    }
    virtual float screenWidth() 
    {
        return ::screenWidth;
    }
    virtual float screenHeight() 
    {
        return ::screenHeight;
    }
    virtual float screenScale() 
    {
        return ::screenScale;
    }
    virtual int deviceWidth() 
    {
        return ::deviceWidth;
    }
    virtual int deviceHeight() 
    {
        return ::deviceHeight;
    }
    virtual float screenXDpi()
    {
        return ::screenXDpi;
    }
    virtual float screenYDpi() 
    {
        return ::screenYDpi;
    }

    virtual void ProcessTransactions()
    {
        CreateDisplayList();
    }

    virtual void RequestRedraw()
    {
        _client->RequestRedraw();
    }

    virtual void setScreenSize(float width, float height, float scale) {
        ::screenWidth = width;
        ::screenHeight = height;
        ::screenScale = scale;
    }

    virtual void setDeviceSize(int width, int height) 
    {
       ::deviceWidth = width;
       ::deviceHeight = height;
    }

    virtual void setScreenDpi(int xDpi, int yDpi) 
    {
      ::screenXDpi = xDpi;
      ::screenYDpi = yDpi;
    }

    virtual void setTablet(bool isTablet) 
    {
        ::tabletMode = isTablet;
    }

    DisplayTexture *CreateWritableBitmapTexture32(int width, int height) 
    {
        return NULL;
    }

    void *LockWritableBitmapTexture(DisplayTexture *tex, int *stride) 
    {
        return NULL;
    }

    void UnlockWritableBitmapTexture(DisplayTexture *tex) 
    {
    }

    void EnableDisplaySyncNotification()
    {
        CASignalDisplayLink();
        RequestRedraw();
    }

    void DisableDisplaySyncNotification() 
    {
    }

    WebViewControl * CreateWebViewDisplayTexture()
    {
        return NULL;
    }

    NSObject *getDisplayProperty(DisplayNode *node, const char *name)
    {
        CADisplayProperties *props = &node->originalPresentationProperties; 
        if ( node->visiblePresentationPropertiesSet ) {
            props = &node->visiblePresentationProperties;
        }

        NSObject *ret = nil;
        if ( strcmp(name, "position") == 0 ) {
            CGPoint pos;

            pos.x = props->position.x;
            pos.y = props->position.y;

            ret = [NSValue valueWithCGPoint: pos];
        } else if ( strcmp(name, "bounds.origin") == 0 ) {
            CGPoint pos;

            pos.x = props->bounds.origin.x;
            pos.y = props->bounds.origin.y;

            ret = [NSValue valueWithCGPoint: pos];
        } else if ( strcmp(name, "bounds.size") == 0 ) {
            CGSize size;

            size.width = props->bounds.size.width;
            size.height = props->bounds.size.height;

            ret = [NSValue valueWithCGSize: size];
        } else if ( strcmp(name, "bounds") == 0 ) {
            CGRect rect;

            rect.size.width = props->bounds.size.width;
            rect.size.height = props->bounds.size.height;
            rect.origin.x = props->bounds.origin.x;
            rect.origin.y = props->bounds.origin.y;

            ret = [NSValue valueWithCGRect: rect];
        } else if ( strcmp(name, "opacity") == 0 ) {
            float value = props->opacity;

            ret = [NSNumber numberWithFloat: value];
        } else if ( strcmp(name, "transform") == 0 ) {
            ret = [NSValue valueWithCATransform3D: props->transform];
        } else {
            assert(0);
        }

        return ret;
    }

    void IncrementCounter(const char *name)
    {
    }

    void DecrementCounter(const char *name)
    {
    }

    DisplayTexture *CreateDisplayTextureForElement(id xamlElement) 
    {
        return NULL;
    }
};

class DXQuartzCompositor : public DXCompositorInterface
{
public:
    EbrComPtr<ID3D11Device1> _device;
    virtual void ConnectDevice(ID3D11Device1 *device)
    {
        _device = device;
        ::EbrConnectCompositor(_device.Get());
    }

    virtual void SetRenderSize(int width, int height)
    {
        windowWidth = (float) width;
        windowHeight = (float) height;
    }

    virtual void SetLandscape(bool bLandscape)
    {
        dxLandscape = bLandscape;
    }

    virtual void RenderFrame(ID3D11DeviceContext *context, ID3D11RenderTargetView *renderTarget) 
    {
        ::RenderFrame(_device.Get(), context, renderTarget);
    }
};

void SetImageDestructionCallbacks();

__declspec(dllexport) DXCompositorInterface *CreateDXCompositor(CACompositorClientInterface *client)
{
    DXCompositor *compIntr = new DXCompositor();
    SetCACompositor(compIntr);
    SetImageDestructionCallbacks();
    EbrLockInit(&_compositorLock);
    EbrLockInit(&DisplayTexture::_displayTextureCacheLock);

    pthread_mutex_init(&g_DeadTexturesLock, NULL);
    DXCompositorInterface *ret = new DXQuartzCompositor();
    _client = client;
    return ret;
}

