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

#include "EbrTexture.h"

#include <map>
#include <vector>

#define DYN_TEXTURE_REPORTING 0

#define MIN_TEXTURE_POW2 5
#define MIN_TEXTURE_SIZE 32
#define MAX_ATLASED_TEXTURE_SIZE 512
#define MAX_TEXTURE_ATLAS_SIZE 4096
#define ATLAS_UV_SCALE (1.f / ((float)MAX_TEXTURE_ATLAS_SIZE))
#define NUM_LAYERS 8 // 2^12 - 2^5 + 1 (use exponents of powers of two to figure out the # of layers)

#define MAX_ALLOC_UNITS 256

class DynTextureAtlas {
    class Sheet {
        class Space {
        public:
            EbrTexture* owner;
            Space*      next;

            size_t      x, y; // pos in atlas tex.
            size_t      size;
            
            float       uvScales[4];            // size of our subsection of the texture

            bool        changed;

#if DYN_TEXTURE_REPORTING
            size_t      pixelsUsed;
#endif

            inline Space() : owner(NULL), next(NULL), size(0), x(0), y(0), changed(false)
#if DYN_TEXTURE_REPORTING
                           , pixelsUsed(0)
#endif
            {
                memset(uvScales, 0, sizeof(float) * 4);
            }

            inline void initRoot()
            {
                x = 0;
                y = 0;
                size = MAX_TEXTURE_ATLAS_SIZE;
                uvScales[0] = 1.f;
                uvScales[1] = 1.f;
                uvScales[2] = 0.f;
                uvScales[3] = 0.f;
                
                owner = NULL;
                next = NULL;
                changed = false;

#if DYN_TEXTURE_REPORTING
                units[0].pixelsUsed = 0;
#endif
            }
            
            inline void position(int xpos, int ypos, int tileSize)
            {
                x = xpos;
                y = ypos;
                size = tileSize;

                // 0 and 1 set on alloc.
                uvScales[2] = ((float)x) / ((float)MAX_TEXTURE_ATLAS_SIZE);
                uvScales[3] = ((float)y) / ((float)MAX_TEXTURE_ATLAS_SIZE);
            }

            inline void reset(Space* n)
            {
                owner = NULL;
                next = n;
                size = 0;
                changed = false;

#if DYN_TEXTURE_REPORTING
                pixelsUsed = 0;
#endif
            }
            
            inline void alloc(int width, int height)
            {
                uvScales[0] = ((float)width) * ATLAS_UV_SCALE;
                uvScales[1] = ((float)height) * ATLAS_UV_SCALE;

#if DYN_TEXTURE_REPORTING
                pixelsUsed = width * height;
#endif                 
            }
        };

        typedef std::map<int, Space*> AllocMap;

        Space       units[MAX_ALLOC_UNITS];
        Space*      layers[NUM_LAYERS];
        Space*      freeList;

        AllocMap    alloced;

        bool        changed;
        
        EbrTextureDynAtlas* tex;

        void expandNodes(int lowLayer, int highLayer);
        inline Space* getNewUnit()
        {
            if (!freeList) return NULL;
    
            Space* res = freeList;
            freeList = res->next;
            return res;            
        }

    public:
        Sheet();
        ~Sheet();

        bool initTexture(ID3D11Device* device);
        void disconnect();
        
        void report();

        EbrTexture* lookup(EbrTexture* t, float* uvScales);
        EbrTexture* add(EbrTexture* t, float* uvScales);
        bool remove(EbrTexture* t);

        void update(ID3D11DeviceContext *context);

        inline bool isChanged() const { return changed; }
    };

    typedef std::vector<Sheet*> Sheets;
    typedef Sheets::iterator SheetsIt;

    Sheets atlases;

public:
    DynTextureAtlas();
    ~DynTextureAtlas();

    void disconnect();
    
    void report();

    EbrTexture* lookup(EbrTexture* t, float* uvScalesOut);
    EbrTexture* add(EbrTexture* t, float* uvScalesOut);
    bool remove(EbrTexture* t);

    void update(ID3D11Device* device, ID3D11DeviceContext *context);
};
