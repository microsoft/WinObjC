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

#include "Platform\EbrDirectX.h"

struct CAPoint3D;
struct CGPoint;
class EbrTexture;

struct FontAtlasOutputGlyph {
    CGPoint drawQuad[4];
    CGPoint uvQuad[4];
    EbrTexture* texture;
    CGSize glyphSize;
    WORD character;
    bool hasTexture;
    bool hasSize;
};

class FontAtlasMan {
protected:
    FontAtlasMan();
    virtual ~FontAtlasMan();

public:
    static FontAtlasMan* get();

    virtual bool addPermanent(id font) = 0; // make a font permanently cached.
    virtual bool addFontRef(id font) = 0; // add a font, refcount-based caching.
    virtual bool releaseFontRef(id font) = 0; // release a font reference.  cleared if # of references is 0.

    virtual void addStringToRender(id font, id string) = 0; // scan a string for new glyphs that must be rendered
    virtual void process(ID3D11Device1* device,
                         ID3D11DeviceContext* context) = 0; // renders any glyphs added by addStringToRender, removes dead sheets

    // get geometry glyphs to be rendered from string.
    virtual bool getDrawList(FontAtlasOutputGlyph* output, id font, id string, bool& sdfFont) = 0;

    virtual void disconnect() = 0;
    virtual int generationCount() = 0;
};
