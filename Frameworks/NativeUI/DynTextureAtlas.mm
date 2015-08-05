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

#include <algorithm>

#include "CGImageInternal.h"
#include "Platform/EbrDirectX.h"
#include "NativeUI/DynTextureAtlas.h"

inline int NextPow2(int size, int& layerIdx)
{
    int layer = 0;
    int i = MIN_TEXTURE_SIZE;
    while(i < size) {
        i = i << 1;
        layer ++;
    }
    layerIdx = layer;
    return i;
}

DynTextureAtlas::Sheet::Sheet() :
    freeList(NULL),
    changed(true),
    tex(NULL)
{
    // Set up completely empty tree.
    for(int i = 0; i < NUM_LAYERS - 1; i ++) layers[i] = NULL;
    layers[NUM_LAYERS - 1] = &units[0];
    units[0].initRoot();

    // Set up list of Spaces.
    freeList = &units[1];
    for(int i = 1; i < MAX_ALLOC_UNITS; i ++) {
        units[i].reset((i < MAX_ALLOC_UNITS - 1) ? &units[i + 1] : NULL);
    }

    tex = new EbrTextureDynAtlas();
}

DynTextureAtlas::Sheet::~Sheet()
{
    disconnect();
}

bool DynTextureAtlas::Sheet::initTexture(ID3D11Device* device)
{
    if (tex->m_masterTexture.Get()) return true;

    if (!tex->Initialize(device, MAX_TEXTURE_ATLAS_SIZE, MAX_TEXTURE_ATLAS_SIZE)) {
        EbrDebugLog("DynTextureAtlas failed to initialize!\n");
        return false;
    }

    return true;
}

void DynTextureAtlas::Sheet::disconnect()
{
    if (tex) {
        tex->Disconnect();
        delete tex;
        tex = NULL;
    }

    alloced.clear();
    for(int i = 0; i < NUM_LAYERS; i ++) {
        layers[i] = NULL;
    }
}

void DynTextureAtlas::Sheet::expandNodes(int lowLayer, int highLayer)
{
    assert(layers[highLayer]);

    for(int i = highLayer - 1; i >= lowLayer; i --) {

        // Grab source node.
        Space* src = layers[i + 1];
        layers[i + 1] = src->next;

        // Split it into 4 child components.
        Space* dest[4];
        for(int j = 0; j < 4; j ++) {
            dest[j] = getNewUnit();
            if (!dest[j]) {
                for(int k = 0; k < j; k ++) {
                    dest[j]->next = freeList;
                    freeList = dest[j];
                }
            }
        }

        // Link it into the available layer.
        dest[0]->next = dest[1];
        dest[1]->next = dest[2];
        dest[2]->next = dest[3];
        dest[3]->next = layers[i];
        layers[i] = dest[0];

        // Position all child subnodes as follows.
        
        //
        // 0 | 1
        // -----
        // 2 | 3

        // Get new positions.
        int newSize = src->size >> 1;
        dest[0]->position(src->x, src->y, newSize);
        dest[1]->position(src->x + newSize, src->y, newSize);
        dest[2]->position(src->x, src->y + newSize, newSize);
        dest[3]->position(src->x + newSize, src->y + newSize, newSize);

        // Free up original node.
        src->reset(freeList);
        freeList = src;
    }
}

void DynTextureAtlas::Sheet::report()
{
#if DYN_TEXTURE_REPORTING
    // How close is the free list to being blown up?
    int nfree = 0;
    int nfreeLayered[NUM_LAYERS] = { 0 };
    for(Space* u = freeList; u; u = u->next) {
        nfree ++;
    }

    // How many available nodes do we have?
    int navailable = 0;
    int navailableLayered[NUM_LAYERS] = { 0 };
    
    for(int l = 0; l < NUM_LAYERS; l ++) {
        for(Space* u = layers[l]; u; u = u->next) {
            navailable ++;
            navailableLayered[l] ++;
        }
    }

    // Report results.
    EbrDebugLog("%d/%d Spaces available, %d used.\n", nfree, MAX_ALLOC_UNITS, MAX_ALLOC_UNITS - nfree);
    EbrDebugLog("%d nodes available, by layer:\n", navailable);
    for(int i = 0; i < NUM_LAYERS; i ++) {
        int count = 0;
        for(Space* u = layers[i]; u; u = u->next) {
            count ++;
        }
        EbrDebugLog("Layer %d (tile size %d) - %d available\n", i, 1 << (i + MIN_TEXTURE_POW2), count);
    }

    EbrDebugLog("%d textures cached.\n", alloced.size());
    int pixUsed = 0;
    int pixTotal = 0;
    int pixUsedLayer[NUM_LAYERS] = { 0 };
    int pixTotalLayer[NUM_LAYERS] = { 0 };
    for(AllocMap::iterator it = alloced.begin(); it != alloced.end(); ++it) {
        Space* u = it->second;
        pixUsed += u->pixelsUsed;
        pixTotal += (u->size * u->size);
        EbrDebugLog("  -- tex 0x%x size %d at %f efficiency\n", it->first, u->size, 100.f * ((float)u->pixelsUsed) / ((float)(u->size * u->size)));
    }
    EbrDebugLog("Total efficiency: %f\n", 100.f * (((float)pixUsed) / ((float)pixTotal)));
#endif 
}

EbrTexture *DynTextureAtlas::Sheet::lookup(EbrTexture *t, float* uvScales)
{
    AllocMap::iterator it = alloced.find((int)t);
    if (it == alloced.end()) return NULL;

    if (uvScales) {
        Space* u = it->second;
        memcpy(uvScales, u->uvScales, 4 * sizeof(float));
    }

    return tex;
}

EbrTexture* DynTextureAtlas::Sheet::add(EbrTexture *t, float* uvScales)
{
    int layer;
    int size = NextPow2(std::max<int>(t->_texWidth, t->_texHeight), layer);
    assert(size <= MAX_ATLASED_TEXTURE_SIZE);

    // if this happens, MAX_ATLASED_TEXTURE_SIZE is bigger than the atlas size.
    if (layer >= NUM_LAYERS) EbrThrowFatal(0, "NUM_LAYERS exceeded.\n");
    
    if (layers[layer] == NULL) {

        // We must grab some other layer and break it down.
        int firstAvailable = -1;
        for(int i = layer + 1; i < NUM_LAYERS; i ++) {
            if (layers[i]) {
                firstAvailable = i;
                break;
            }
        }
        if (firstAvailable < 0) {
            EbrDebugLog("ERROR: We appear to be out of DynTextureAtlas space!\n");
            return NULL;
        }
        expandNodes(layer, firstAvailable);
    }

    assert(layers[layer]);
    Space* res = layers[layer];
    layers[layer] = res->next;

    res->owner = t;
#if DYN_TEXTURE_REPORTING
    res->pixelsUsed = t->_texWidth * t->_texHeight;
#endif
    res->changed = true;
    changed = true;
    if (uvScales) {
        res->alloc(t->_texWidth, t->_texHeight);
        memcpy(uvScales, res->uvScales, 4 * sizeof(float));
    }
    
    alloced[(int)t] = res;

#if USE_DYN_TEXTURE_ATLASING
    t->_atlased = true;
#endif

    return tex;
}

bool DynTextureAtlas::Sheet::remove(EbrTexture *t)
{
    //EbrAlwaysLog("!!! Removing Texture from DynTextureAtlas!\n");
    AllocMap::iterator it = alloced.find((int)t);
    if (it != alloced.end()) {

        // TODO: BK: there is not a good way to coalesce nodes right now.

        Space* u = it->second;
        alloced.erase(it);

        u->owner = NULL;

#if DYN_TEXTURE_REPORTING
        u->pixelsUsed = 0;
#endif 

        int layer;
        NextPow2(u->size, layer);
        assert(layer < NUM_LAYERS);
        u->next = layers[layer];
        layers[layer] = u;
        
        return true;
    } else {
        //EbrAlwaysLog("!!! Texture not found!\n");
    }

    return false;
}

void DynTextureAtlas::Sheet::update(ID3D11DeviceContext *context)
{
    if (!changed) return;

    changed = false;

    //EbrAlwaysLog("!!! Updating DynTextureAtlas (%d used)!\n", alloced.size());
    
    // Update the atlased texture.
    for(AllocMap::iterator it = alloced.begin(); it != alloced.end(); ++it) {
        Space* au = it->second;
        if (au->changed) {
            au->changed = false;

            // We will need to fill in the textures here.
            CGImageBacking* img = au->owner->_imageBacking->Backing();
            assert(img->BytesPerPixel() == sizeof(unsigned));
            int rowBytes = img->BytesPerRow();
            int imgH = img->Height();
            char* src = (char *)img->StaticImageData();

            tex->UpdateSubresource(context, au->x, au->y, au->x + img->Width(),
                                   au->y + img->Height(), src, rowBytes);
        }
    }
}

DynTextureAtlas::DynTextureAtlas()
{
}

DynTextureAtlas::~DynTextureAtlas()
{
    disconnect();
}

void DynTextureAtlas::disconnect()
{
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        (*it)->disconnect();
        delete (*it);
    }
    atlases.clear();
}

void DynTextureAtlas::report()
{
#if DYN_TEXTURE_REPORTING
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        it->report();
    }
#endif 
}

EbrTexture* DynTextureAtlas::lookup(EbrTexture* t, float* uvScales)
{
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        EbrTexture* res = (*it)->lookup(t, uvScales);
        if (res) return res;
    }

    return add(t, uvScales);
}

EbrTexture* DynTextureAtlas::add(EbrTexture* t, float* uvScalesOut)
{
    if (!t) return NULL;
    if (t->_type == displayTextureFontAtlas) return NULL;
#if USE_DYN_TEXTURE_ATLASING
    if (t->_cannotAtlas) return NULL;
#endif
    
    int layer;
    int size = NextPow2(std::max<int>(t->_texWidth, t->_texHeight), layer);

    if (size > MAX_ATLASED_TEXTURE_SIZE) {
#if USE_DYN_TEXTURE_ATLASING
        t->_cannotAtlas = true;
#endif 
        return NULL;
    }
    
    // Quandary:  is it better to add to the last allocated sheet, or the first?
    // in the interest of packing things better, we attempt to pack things onto the
    // first sheet first.
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        EbrTexture* res = (*it)->add(t, uvScalesOut);
        if (res) return res;
    }

    Sheet* s = new Sheet();
    EbrTexture* res = s->add(t, uvScalesOut);
    if (!res) {
        delete s;
        return NULL;
    }
    atlases.push_back(s);

    return res;
}

bool DynTextureAtlas::remove(EbrTexture* t)
{
#if USE_DYN_TEXTURE_ATLASING
    if (!t->_atlased || t->_cannotAtlas) return false;
#endif 
    
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        if ((*it)->remove(t)) return true;
    }
    return false;
}

void DynTextureAtlas::update(ID3D11Device* device, ID3D11DeviceContext *context)
{
    for(SheetsIt it = atlases.begin(); it != atlases.end(); ++it) {
        Sheet* s = *it;
        if (s->isChanged()) {
            s->initTexture(device);
            s->update(context);
        }
    }
}


